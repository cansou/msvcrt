/***
*calloc_impl.c - implementation of _calloc_impl
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Defines the _calloc_impl() function.
*
*******************************************************************************/

#ifdef WINHEAP

#include <malloc.h>
#include <string.h>
#include <winheap.h>
#include <windows.h>
#include <internal.h>
#include <mtdll.h>
#include <dbgint.h>
#include <rtcsup.h>

void * __cdecl _calloc_impl (size_t num, size_t size, int * errno_tmp)
{
        size_t  size_orig;
        void *  pvReturn;

        /* ensure that (size * num) does not overflow */
        if (num > 0)
        {
            _VALIDATE_RETURN((_HEAP_MAXREQ / num) >= size, ENOMEM, NULL);
        }
        size_orig = size = size * num;


        /* force nonzero size */
        if (size == 0)
            size = 1;

        for (;;)
        {
            pvReturn = NULL;

            if (size <= _HEAP_MAXREQ)
            {
#ifndef _WIN64
                if ( __active_heap == __V6_HEAP )
                {
                    /* round up to nearest paragraph */
                    if (size <= _HEAP_MAXREQ)
                        size = (size + BYTES_PER_PARA - 1) & ~(BYTES_PER_PARA - 1);

                    if ( size_orig <= __sbh_threshold )
                    {
                        //  Allocate the block from the small-block heap and
                        //  initialize it with zeros.
                        _mlock( _HEAP_LOCK );
                        __try {
                        pvReturn = __sbh_alloc_block((int)size_orig);
                        }
                        __finally {
                            _munlock( _HEAP_LOCK );
                        }

                        if (pvReturn != NULL)
                            memset(pvReturn, 0, size_orig);
                    }
                }
#ifdef CRTDLL
                else if ( __active_heap == __V5_HEAP )
                {
                    /* round up to nearest paragraph */
                    if (size <= _HEAP_MAXREQ)
                        size = (size + BYTES_PER_PARA - 1) & ~(BYTES_PER_PARA - 1);

                    if ( size <= __old_sbh_threshold )
                    {
                        //  Allocate the block from the small-block heap and
                        //  initialize it with zeros.
                        _mlock(_HEAP_LOCK);
                        __try {
                        pvReturn = __old_sbh_alloc_block(size >> _OLD_PARASHIFT);
                        }
                        __finally {
                            _munlock(_HEAP_LOCK);
                        }
                        if ( pvReturn != NULL )
                            memset(pvReturn, 0, size);
                    }
                }
#endif  /* CRTDLL */
#endif  /* _WIN64 */

                if (pvReturn == NULL)
                    pvReturn = HeapAlloc(_crtheap, HEAP_ZERO_MEMORY, size);
            }

            if (pvReturn || _newmode == 0)
            {
                RTCCALLBACK(_RTC_Allocate_hook, (pvReturn, size_orig, 0));
                if (pvReturn == NULL)
                {
                    if ( errno_tmp )
                        *errno_tmp = ENOMEM;
                }
                return pvReturn;
            }

            /* call installed new handler */
            if (!_callnewh(size))
            {
                if ( errno_tmp )
                    *errno_tmp = ENOMEM;
                return NULL;
            }

            /* new handler was successful -- try to allocate again */
        }

}
#endif  /* WINHEAP */
