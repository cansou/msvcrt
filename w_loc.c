/***
*w_loc.c - W version of GetLocaleInfo.
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Wrapper for GetLocaleInfoW.
*
*******************************************************************************/

#include <cruntime.h>
#include <internal.h>
#include <stdlib.h>
#include <awint.h>
#include <dbgint.h>
#include <malloc.h>
#include <locale.h>
#include <mtdll.h>
#include <setlocal.h>

/***
*int __cdecl __crtGetLocaleInfoW - Get locale info and return it as a wide
*       string
*
*Purpose:
*       Internal support function. Assumes info in wide string format. Tries
*       to use NLS API call GetLocaleInfoW if available (NT) and uses
*       GetLocaleInfoA if it must (Chicago). If neither are available it fails
*       and returns 0.
*
*Entry:
*       LCID     Locale      - locale context for the comparison.
*       LCTYPE   LCType      - see NT\Chicago docs
*       LPWSTR   lpLCData    - pointer to memory to return data
*       int      cchData     - wide char (word) count of buffer (including
*                              NULL) (if 0, lpLCData is not referenced, size
*                              needed is returned)
*       int      code_page   - for MB/WC conversion. If 0, use __lc_codepage
*
*Exit:
*       Success: the number of characters copied (including NULL).
*       Failure: 0
*
*Exceptions:
*
*******************************************************************************/

static int __cdecl __crtGetLocaleInfoW_stat(
        _locale_t plocinfo,
        LCID    Locale,
        LCTYPE  LCType,
        LPWSTR  lpLCData,
        int     cchData,
        int     code_page
        )
{
    return GetLocaleInfoW(Locale, LCType, lpLCData, cchData);
}

extern "C" int __cdecl __crtGetLocaleInfoW(
        _locale_t plocinfo,
        LCID    Locale,
        LCTYPE  LCType,
        LPWSTR  lpLCData,
        int     cchData,
        int     code_page
        )
{
    _LocaleUpdate _loc_update(plocinfo);

    return __crtGetLocaleInfoW_stat(
            _loc_update.GetLocaleT(),
            Locale,
            LCType,
            lpLCData,
            cchData,
            code_page
            );
}
