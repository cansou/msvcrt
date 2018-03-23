/***
*awint.h - internal definitions for A&W Win32 wrapper routines.
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Contains internal definitions/declarations for A&W wrapper functions.
*       Not included in internal.h since windows.h is required for these.
*
*       [Internal]
*
****/

#if _MSC_VER > 1000
#pragma once
#endif  /* _MSC_VER > 1000 */

#ifdef _WIN32

#ifndef _INC_AWINC
#define _INC_AWINC

#ifndef _CRTBLD
/*
 * This is an internal C runtime header file. It is used when building
 * the C runtimes only. It is not to be used as a public header file.
 */
#error ERROR: Use of C runtime library internal header file.
#endif  /* _CRTBLD */

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

#include <sal.h>
#include <windows.h>

/* internal A&W routines */
struct  threadlocaleinfostruct;
typedef struct threadlocaleinfostruct * pthreadlocinfo;

int __cdecl __crtCompareStringW
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID     _Locale,
    _In_ DWORD    _DwCmpFlags,
    _In_count_(_CchCount1) LPCWSTR  _LpString1,
    _In_ int      _CchCount1,
    _In_count_(_CchCount2) LPCWSTR  _LpString2,
    _In_ int      _CchCount2,
    _In_ int      _Code_page
);

int __cdecl __crtCompareStringA
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID     _Locale,
    _In_ DWORD    _DwCmpFlags,
    _In_count_(_CchCount1) LPCSTR   _LpString1,
    _In_ int      _CchCount1,
    _In_count_(_CchCount2) LPCSTR   _LpString2,
    _In_ int      _CchCount2,
    _In_ int      _Code_page
);

int __cdecl __crtGetLocaleInfoW
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID    _Locale,
    _In_ LCTYPE  _LCType,
    _Out_opt_cap_(_CchData) LPWSTR  _LpLCData,
    _In_ int     _CchData,
    _In_ int     _Code_page
);

int __cdecl __crtGetLocaleInfoA
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID    _Locale,
    _In_ LCTYPE  _LCType,
    _Out_opt_cap_(_CchData) LPSTR   _LpLCData,
    _In_ int     _CchData,
    _In_ int     _Code_page
);

int __cdecl __crtLCMapStringW
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID _Locale,
    _In_ DWORD _DWMapFlag,
    _In_count_(_CchSrc) LPCWSTR _LpSrcStr ,
    _In_ int _CchSrc,
    _Out_opt_cap_(_CchDest) LPWSTR _LpDestStr,
    _In_ int _CchDest,
    _In_ int _Code_page
);

int __cdecl __crtLCMapStringA
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID _Locale,
        _In_ DWORD _DwMapFlag,
    _In_count_(_CchSrc) LPCSTR _LpSrcStr,
    _In_ int _CchSrc,
    _Out_opt_cap_(_CchDest) LPSTR _LpDestStr,
    _In_ int _CchDest,
    _In_ int _Code_page,
    _In_ BOOL _BError
);

BOOL __cdecl __crtGetStringTypeW
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ DWORD _DWInfoType,
    _In_count_(_CchSrc) LPCWSTR _LpSrcStr,
    _In_ int _CchSrc,
    _Out_ LPWORD _LpCharType,
    _In_ int _Code_page,
    _In_ int _Lcid
);

BOOL __cdecl __crtGetStringTypeA
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ DWORD _DWInfoType,
    _In_ LPCSTR _LpSrcStr,
    _In_ int _CchSrc,
    _Out_ LPWORD _LpCharType,
    _In_ int _Code_page,
    _In_ int _Lcid,
    _In_ BOOL _BError
);

LPVOID __cdecl __crtGetEnvironmentStringsW(VOID);
LPVOID __cdecl __crtGetEnvironmentStringsA(VOID);

LPWSTR __cdecl __crtGetCommandLineW(VOID);

int __cdecl __crtMessageBoxA
(
    _In_ LPCSTR _LpText,
    _In_ LPCSTR _LpCaption,
    _In_ UINT _UType
);

int __cdecl __crtMessageBoxW
(
    _In_ LPCWSTR _LpText,
    _In_ LPCWSTR _LpCaption,
    _In_ UINT _UType
);


int __cdecl __crtCompareStringW_mt
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID     _Locale,
    _In_ DWORD    _DwCmpFlags,
    _In_count_(_CchCount1) LPCWSTR  _LpString1,
    _In_ int      _CchCount1,
    _In_count_(_CchCount2) LPCWSTR  _LpString2,
    _In_ int      _CchCount2,
    _In_ int      _Code_page
);

int __cdecl __crtCompareStringA_mt
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID     _Locale,
    _In_ DWORD    _DwCmpFlags,
    _In_count_(_CchCount1) LPCSTR   _LpString1,
    _In_ int      _CchCount1,
    _In_count_(_CchCount2) LPCSTR   _LpString2,
    _In_ int      _CchCount2,
    _In_ int      _Code_page
);

int __cdecl __crtLCMapStringW_mt
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID _Locale,
    _In_ DWORD _DWMapFlag,
    _In_count_(_CchSrc) LPCWSTR _LpSrcStr ,
    _In_ int _CchSrc,
    _Out_opt_cap_(_CchDest) LPWSTR _LpDestStr,
    _In_ int _CchDest,
    _In_ int _Code_page
);

int __cdecl __crtLCMapStringA_mt
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ LCID _Locale,
        _In_ DWORD _DwMapFlag,
    _In_count_(_CchSrc) LPCSTR _LpSrcStr,
    _In_ int _CchSrc,
    _Out_opt_cap_(_CchDest) LPSTR _LpDestStr,
    _In_ int _CchDest,
    _In_ int _Code_page,
    _In_ BOOL _BError
);

BOOL __cdecl __crtGetStringTypeW_mt
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ DWORD _DWInfoType,
    _In_count_(_CchSrc) LPCWSTR _LpSrcStr,
    _In_ int _CchSrc,
    _Out_ LPWORD _LpCharType,
    _In_ int _Code_page,
    _In_ int _Lcid
);

BOOL __cdecl __crtGetStringTypeA_mt
(
    _In_opt_ _locale_t _Plocinfo,
    _In_ DWORD _DWInfoType,
    _In_ LPCSTR _LpSrcStr,
    _In_ int _CchSrc,
    _Out_ LPWORD _LpCharType,
    _In_ int _Code_page,
    _In_ int _Lcid,
    _In_ BOOL _BError
);

/* internal routines for supporting A&W routines */

int __cdecl __ansicp(_In_ int _Lcid);
char * __cdecl __convertcp
(
    _In_ int _FromCp,
    _In_ int _ToCp,
    _In_count_(_PCchSrc) _Pre_z_ const char * _LpSrcStr,
    _Inout_ int * _PCchSrc,
    _Out_opt_z_cap_(_CchDest) char * _LpDestStr,
    _In_ int _CchDest
);


#define __CRTCOMPARESTRINGW_MT(ploci, Locale, dwCmpFlags,                       \
        lpString1, cchCount1, lpString2, cchCount2, code_page)                  \
    __crtCompareStringW_mt(ploci, Locale, dwCmpFlags,                           \
        lpString1, cchCount1, lpString2, cchCount2, code_page)

#define __CRTCOMPARESTRINGA_MT(ploci, Locale, dwCmpFlags,                       \
        lpString1, cchCount1, lpString2, cchCount2, code_page)                  \
    __crtCompareStringA_mt(ploci, Locale, dwCmpFlags,                           \
        lpString1, cchCount1, lpString2, cchCount2, code_page)


#define __CRTLCMAPSTRINGW_MT(ploci, Locale, dwCmpFlags,                         \
        lpString1, cchCount1, lpString2, cchCount2, code_page)                  \
    __crtLCMapStringW_mt(ploci, Locale, dwCmpFlags,                             \
        lpString1, cchCount1, lpString2, cchCount2, code_page)

#define __CRTLCMAPSTRINGA_MT(ploci, Locale, dwCmpFlags,                         \
        lpString1, cchCount1,lpString2,cchCount2, code_page, bError)            \
    __crtLCMapStringA_mt(ploci, Locale, dwCmpFlags,                             \
        lpString1, cchCount1, lpString2, cchCount2, code_page, bError)


#define __CRTGETSTRINGTYPEW_MT(ploci, dwInfoType, lpSrcStr,                     \
        cchSrc, lpCharType, code_page, lcid)                                    \
    __crtGetStringTypeW_mt(ploci, dwInfoType, lpSrcStr,                         \
        cchSrc, lpCharType, code_page, lcid)

#define __CRTGETSTRINGTYPEA_MT(ploci, dwInfoType, lpSrcStr,                     \
        cchSrc, lpCharType, code_page, lcid, bError)                            \
    __crtGetStringTypeA_mt(ploci, dwInfoType, lpSrcStr,                         \
        cchSrc, lpCharType, code_page, lcid, bError)




#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif  /* _INC_AWINC */

#endif  /* _WIN32 */
