/***
*dbgsec.c - Debug CRT Security Check Helper
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Defines alternative version of _CrtSetCheckCount helper.
*
*******************************************************************************/

#ifdef _DEBUG

/***
*int _CrtSetCheckCount(int fCheckCount)
*       - Redefine import version of _CrtSetCheckCount
*
*Purpose:
*       Deliberately overwrite the default behavior of MSVCRXXD.DLL import
*       version of _CrtSetCheckCount. This file is linked into MSVCMXX.DLL and
*       MSVCPXX.DLL. The purpose is to allow backwards compatibility for apps
*       compiled with older CRT to be able to execute against newer CRT without
*       causing asserts. Without this change, a managed app can load up new
*       MSVCMXXD.DLL which sets the buffer checking flag in MSVCRXXD.DLL, and
*       triggers checkings inside the 'n'versions of the secure CRT.
*
*Entry:
*       int fCheckCount - not used
*
*Exit:
*       return 0
*
*******************************************************************************/

int _CrtSetCheckCount(int fCheckCount)
{
    return 0;
}

#ifdef _M_IX86
int (__cdecl * _imp___CrtSetCheckCount)(int) = &_CrtSetCheckCount;
#else  /* _M_IX86 */
int (__cdecl * __imp__CrtSetCheckCount)(int) = &_CrtSetCheckCount;
#endif  /* _M_IX86 */

#endif  /* _DEBUG */
