/***
*dbgnew.cpp - defines C++ new() routines, debug version
*
*       Copyright (c) Microsoft Corporation.  All rights reserved.
*
*Purpose:
*       Defines C++ new() routines.
*
*******************************************************************************/

#ifdef _DEBUG

#include <cruntime.h>
#include <malloc.h>
#include <mtdll.h>
#include <dbgint.h>
#include <rtcsup.h>
#include <new>

/***
*void * operator new() - Get a block of memory from the debug heap
*
*Purpose:
*       Allocate of block of memory of at least size bytes from the heap and
*       return a pointer to it.
*
*       Allocates any type of supported memory block.
*
*Entry:
*       size_t          cb          - count of bytes requested
*       int             nBlockUse   - block type
*       char *          szFileName  - file name
*       int             nLine       - line number
*
*Exit:
*       Success:  Pointer to memory block
*       Failure:  throws std::bad_alloc
*
*Exceptions:
*       Failure:  throws std::bad_alloc
*
*******************************************************************************/
void *__CRTDECL operator new(
        size_t cb,
        int nBlockUse,
        const char * szFileName,
        int nLine
        )
        _THROW1(_STD bad_alloc)
{
    /* _nh_malloc_dbg already calls _heap_alloc_dbg in a loop and calls _callnewh
       if the allocation fails. If _callnewh returns (very likely because no
       new handlers have been installed by the user), _nh_malloc_dbg returns NULL.
     */
    void *res = _nh_malloc_dbg( cb, 1, nBlockUse, szFileName, nLine );

    RTCCALLBACK(_RTC_Allocate_hook, (res, cb, 0));

    /* if the allocation fails, we throw std::bad_alloc */
    if (res == 0)
    {
        static const std::bad_alloc nomem;
        _RAISE(nomem);
    }

    return res;
}

/***
*void * operator new() - Get a block of memory from the debug heap
*
*Purpose:
*       Allocate of block of memory of at least size bytes from the heap and
*       return a pointer to it.
*
*       Allocates any type of supported memory block.
*
*Entry:
*       size_t          cb          - count of bytes requested
*       int             nBlockUse   - block type
*       char *          szFileName  - file name
*       int             nLine       - line number
*
*Exit:
*       Success:  Pointer to memory block
*       Failure:  NULL (or some error value)
*
*Exceptions:
*
*******************************************************************************/
void *__CRTDECL operator new[](
        size_t cb,
        int nBlockUse,
        const char * szFileName,
        int nLine
        )
        _THROW1(_STD bad_alloc)
{
    void *res = operator new(cb, nBlockUse, szFileName, nLine );

    RTCCALLBACK(_RTC_Allocate_hook, (res, cb, 0));

    return res;
}

#else  /* _DEBUG */

#include <new>

/* Implement debug operator new and operator new[] in retail libraries as well,
 * simply calling the retail operator new.
 * These debug versions are declared only in crtdbg.h.
 * Implementing there operators in the CRT libraries makes it easier to override them
 * linking to nothrownew.obj.
 */

void *__CRTDECL operator new(
        size_t cb,
        int nBlockUse,
        const char * szFileName,
        int nLine
        )
        _THROW1(_STD bad_alloc)
{
    (nBlockUse);
    (szFileName);
    (nLine);
    return operator new(cb);
}

void *__CRTDECL operator new[](
        size_t cb,
        int nBlockUse,
        const char * szFileName,
        int nLine
        )
        _THROW1(_STD bad_alloc)
{
    (nBlockUse);
    (szFileName);
    (nLine);
    return operator new[](cb);
}

#endif  /* _DEBUG */
