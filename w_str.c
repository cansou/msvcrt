/***
*w_str.c - W version of GetStringType.
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Wrapper for GetStringTypeW.
*
*******************************************************************************/

#include <cruntime.h>
#include <internal.h>
#include <stdlib.h>
#include <locale.h>
#include <awint.h>
#include <dbgint.h>
#include <malloc.h>
#include <mtdll.h>
#include <setlocal.h>
#include <sal.h>

/***
*int __cdecl __crtGetStringTypeW - Get type information about a wide string.
*
*Purpose:
*       Internal support function. Assumes info in wide string format. Tries
*       to use NLS API call GetStringTypeW if available and uses GetStringTypeA
*       if it must. If neither are available it fails and returns FALSE.
*
*Entry:
*       DWORD    dwInfoType  - see NT\Chicago docs
*       LPCWSTR  lpSrcStr    - wide string for which character types are
*                              requested
*       int      cchSrc      - wide char (word) count of lpSrcStr (including
*                              NULL if any)
*       LPWORD   lpCharType  - array to receive character type information
*                              (must be same size as lpSrcStr)
*       int      code_page   - for MB/WC conversion. If 0, use __lc_codepage
*       int      lcid        - for A call, specify LCID, If 0, use
*                              __lc_handle[LC_CTYPE].
*
*Exit:
*       Success: TRUE
*       Failure: FALSE
*
*Exceptions:
*
*******************************************************************************/

static BOOL __cdecl __crtGetStringTypeW_stat
(
    _In_opt_ _locale_t plocinfo,
    _In_ DWORD dwInfoType,
    _In_count_(_CchSrc) LPCWSTR lpSrcStr,
    _In_ int cchSrc,
    _Out_ LPWORD lpCharType,
    _In_ int code_page,
    _In_ int lcid
)
{
    if ( cchSrc < -1 )
        return FALSE;

    return GetStringTypeW(dwInfoType, lpSrcStr, cchSrc, lpCharType);
}

extern "C" BOOL __cdecl __crtGetStringTypeW(
        _locale_t plocinfo,
        DWORD    dwInfoType,
        LPCWSTR  lpSrcStr,
        int      cchSrc,
        LPWORD   lpCharType,
        int      code_page,
        int      lcid
        )
{
    _LocaleUpdate _loc_update(plocinfo);

    return __crtGetStringTypeW_stat(
            _loc_update.GetLocaleT(),
            dwInfoType,
            lpSrcStr,
            cchSrc,
            lpCharType,
            code_page,
            lcid
            );
}
