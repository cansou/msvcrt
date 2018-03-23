/***
*dbgrecalloc.c - Debug CRT Heap Function of recalloc()
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Defines debug versions of heap functions recalloc().
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
*void * realloc() - reallocate a block of memory in the heap
*
*Purpose:
*       Re-allocates a block in the heap to nNewSize bytes. nNewSize may be
*       either greater or less than the original size of the block. The
*       re-allocation may result in moving the block as well as changing
*       the size. If the block is moved, the contents of the original block
*       are copied over.
*
*       Re-allocates 'normal' memory block.
*
*Entry:
*       void *          pUserData   - pointer to previously allocated block
*       size_t          nNewSize    - requested size for the re-allocated block
*
*Exit:
*       Success:  Pointer to (user portion of) memory block
*       Failure:  NULL
*
*Exceptions:
*
*******************************************************************************/

extern "C" _CRTIMP void * __cdecl realloc(
        void * pUserData,
        size_t nNewSize
        )
{
        void *res = _realloc_dbg(pUserData, nNewSize, _NORMAL_BLOCK, NULL, 0);

        return res;
}

#endif  /* _DEBUG */
