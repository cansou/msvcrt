/***
*w_cmp.c - W versions of CompareString.
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Wrapper for CompareStringW.
*
*******************************************************************************/

#include <cruntime.h>
#include <internal.h>
#include <dbgint.h>
#include <stdlib.h>
#include <locale.h>
#include <awint.h>
#include <dbgint.h>
#include <malloc.h>
#include <mtdll.h>
#include <setlocal.h>

/***
*int __cdecl wcsncnt - count wide characters in a string, up to n.
*
*Purpose:
*       Internal local support function. Counts characters in string before NULL.
*       If NULL not found in n chars, then return n.
*
*Entry:
*       const wchar_t *string   - start of string
*       int n                   - byte count
*
*Exit:
*       returns number of wide characaters from start of string to
*       NULL (exclusive), up to n.
*
*Exceptions:
*
*******************************************************************************/

static int __cdecl wcsncnt (
        const wchar_t *string,
        int cnt
        )
{
        int n = cnt;
        wchar_t *cp = (wchar_t *)string;

        while (n-- && *cp)
            cp++;

        return cnt - n - 1;
}

/***
*int __cdecl __crtCompareStringW - Get type information about a wide string.
*
*Purpose:
*  Internal support function. Assumes info in wide string format.
*
*Entry:
*  LCID     Locale      - locale context for the comparison.
*  DWORD    dwCmpFlags  - see NT\Chicago docs
*  LPCWSTR  lpStringn   - wide string to be compared
*  int      cchCountn   - wide char (word) count (NOT including NULL)
*                       (-1 if NULL terminated)
*  int      code_page   - for MB/WC conversion. If 0, use __lc_codepage
*
*Exit:
*  Success: 1 - if lpString1 <  lpString2
*           2 - if lpString1 == lpString2
*           3 - if lpString1 >  lpString2
*  Failure: 0
*
*Exceptions:
*
*******************************************************************************/

static int __cdecl __crtCompareStringW_stat(
        _locale_t plocinfo,
        LCID     Locale,
        DWORD    dwCmpFlags,
        LPCWSTR  lpString1,
        int      cchCount1,
        LPCWSTR  lpString2,
        int      cchCount2,
        int      code_page
        )
{
    /*
     * CompareString will compare past NULL. Must find NULL if in string
     * before cchCountn wide characters.
     */

    if (cchCount1 > 0)
        cchCount1= wcsncnt(lpString1, cchCount1);
    if (cchCount2 > 0)
        cchCount2= wcsncnt(lpString2, cchCount2);

    if (!cchCount1 || !cchCount2)
        return (cchCount1 - cchCount2 == 0) ? 2 :
               (cchCount1 - cchCount2 < 0) ? 1 : 3;

    return CompareStringW( Locale,
                           dwCmpFlags,
                           lpString1,
                           cchCount1,
                           lpString2,
                           cchCount2 );
}

extern "C" int __cdecl __crtCompareStringW(
        _locale_t plocinfo,
        LCID     Locale,
        DWORD    dwCmpFlags,
        LPCWSTR  lpString1,
        int      cchCount1,
        LPCWSTR  lpString2,
        int      cchCount2,
        int      code_page
        )
{
    _LocaleUpdate _loc_update(plocinfo);

    return __crtCompareStringW_stat(
            _loc_update.GetLocaleT(),
            Locale,
            dwCmpFlags,
            lpString1,
            cchCount1,
            lpString2,
            cchCount2,
            code_page
            );
}
