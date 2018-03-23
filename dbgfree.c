/***
*dbgfree.c - Debug CRT Heap Function of free()
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Defines debug versions of heap functions free().
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
*void free() - free a block in the debug heap
*
*Purpose:
*       Frees a 'normal' memory block.
*
*Entry:
*       void * pUserData -  pointer to a (user portion) of memory block in the
*                       debug heap
*
*Return:
*       <void>
*
*******************************************************************************/
extern "C" _CRTIMP void __cdecl free(
        void * pUserData
        )
{
        _free_dbg(pUserData, _NORMAL_BLOCK);
}

#endif  /* _DEBUG */
