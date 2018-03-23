/***
*aw_com.c - W version of GetCommandLine.
*
*       Copyright (c) Microsoft Corporation.  All rights reserved.
*
*Purpose:
*       Wrapper for GetCommandLineW
*
*******************************************************************************/

#include <cruntime.h>
#include <internal.h>
#include <stdlib.h>
#include <setlocal.h>
#include <awint.h>
#include <dbgint.h>

/***
*LPWSTR __cdecl __crtGetCommandLineW - Get wide command line.
*
*Purpose:
*       Internal support function.
*
*Entry:
*       VOID
*
*Exit:
*       LPWSTR - pointer to environment block
*
*Exceptions:
*
*******************************************************************************/

LPWSTR __cdecl __crtGetCommandLineW(
        VOID
        )
{
    return GetCommandLineW();
}
