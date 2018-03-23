/***
*dbgcalloc.c - Debug CRT Heap Function of calloc()
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Defines debug versions of heap functions calloc().
*
*******************************************************************************/

#ifdef _DEBUG

#include <windows.h>
#include <winheap.h>
#include <ctype.h>
#include <dbgint.h>
#include <crtdbg.h>
#include <rtcsup.h>
#include <internal.h>
#include <limits.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>
#include <mtdll.h>
#include <setlocal.h>

#pragma warning(disable:4390)

/***
*void * calloc() - Get a block of memory from the debug heap, init to 0
*
*Purpose:
*       Allocate of block of memory of at least size bytes from the debug
*       heap and return a pointer to it.
*
*       Allocates 'normal' memory block.
*
*Entry:
*       size_t nNum     - number of elements in the array
*       size_t nSize - size of each element
*
*Exit:
*       Success:  Pointer to (user portion of) memory block
*       Failure:  NULL
*
*Exceptions:
*
*******************************************************************************/
extern "C" _CRTIMP void * __cdecl calloc(
        size_t nNum,
        size_t nSize
        )
{
        void *res = _calloc_dbg(nNum, nSize, _NORMAL_BLOCK, NULL, 0);

        RTCCALLBACK(_RTC_Allocate_hook, (res, nNum * nSize, 0));

        return res;
}

#endif  /* _DEBUG */
