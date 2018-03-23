/***
*w_env.c - W version of GetEnvironmentStrings.
*
*       Copyright (c) Microsoft Corporation.  All rights reserved.
*
*Purpose:
*       Wrapper for GetEnvironmentStringsW.
*
*******************************************************************************/

#include <cruntime.h>
#include <internal.h>
#include <stdlib.h>
#include <setlocal.h>
#include <awint.h>
#include <dbgint.h>

/***
*LPVOID __cdecl __crtGetEnvironmentStringsW - Get wide environment.
*
*Purpose:
*       Internal support function.
*
*Entry:
*       VOID
*
*Exit:
*       LPVOID - pointer to environment block
*
*Exceptions:
*
*******************************************************************************/

LPVOID __cdecl __crtGetEnvironmentStringsW(
        VOID
        )
{
    void *penv;
    wchar_t *pwch;
    wchar_t *wbuffer;
    int total_size;

    if ( NULL == (penv = GetEnvironmentStringsW()) )
        return NULL;

    /* find out how big a buffer is needed */

    pwch = penv;
    while ( *pwch != L'\0' ) {
        if ( *++pwch == L'\0' )
            pwch++;
    }

    total_size = (int)((char *)pwch - (char *)penv) +
                 (int)sizeof( wchar_t );

    /* allocate the buffer */

    if ( NULL == (wbuffer = _malloc_crt( total_size )) ) {
        FreeEnvironmentStringsW( penv );
        return NULL;
    }

    /* copy environment strings to buffer */

    memcpy( wbuffer, penv, total_size );

    FreeEnvironmentStringsW( penv );

    return (LPVOID)wbuffer;
}
