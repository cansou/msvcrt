/* xlocinfo.h internal header for Microsoft C */
#pragma once
#ifndef _XLOCINFO
#define _XLOCINFO
#include <ctype.h>
#include <locale.h>
#include <wchar.h>
#ifndef _YVALS
 #include <yvals.h>
#endif

#ifdef  _MSC_VER
#pragma pack(push,_CRT_PACKING)
#endif  /* _MSC_VER */

_C_STD_BEGIN
#ifndef MRTDLL
#ifndef _M_CEE_PURE
_C_LIB_DECL
#endif
#endif

		/* SUPPLEMENTAL CTYPE MACROS & DECLARATIONS */
#define _XA		0x100		/* extra alphabetic */
#define _XS		0x000		/* extra space */
#define _BB		_CONTROL	/* BEL, BS, etc. */
#define _CN		_SPACE		/* CR, FF, HT, NL, VT */
#define _DI		_DIGIT		/* '0'-'9' */
#define _LO		_LOWER		/* 'a'-'z' */
#define _PU		_PUNCT		/* punctuation */
#define _SP		_BLANK		/* space */
#define _UP		_UPPER		/* 'A'-'Z' */
#define _XD		_HEX		/* '0'-'9', 'A'-'F', 'a'-'f' */

		/* SUPPLEMENTAL LOCALE MACROS AND DECLARATIONS */
#define _X_ALL			LC_ALL
#define _X_COLLATE		LC_COLLATE
#define _X_CTYPE		LC_CTYPE
#define _X_MONETARY		LC_MONETARY
#define _X_NUMERIC		LC_NUMERIC
#define _X_TIME 		LC_TIME
#define _X_MAX			LC_MAX
#define _X_MESSAGES		6
#define _NCAT			7

#define _CATMASK(n)	((1 << (n)) >> 1)
#define _M_COLLATE	_CATMASK(_X_COLLATE)
#define _M_CTYPE	_CATMASK(_X_CTYPE)
#define _M_MONETARY	_CATMASK(_X_MONETARY)
#define _M_NUMERIC	_CATMASK(_X_NUMERIC)
#define _M_TIME		_CATMASK(_X_TIME)
#define _M_MESSAGES	_CATMASK(_X_MESSAGES)
#define _M_ALL		(_CATMASK(_NCAT) - 1)

typedef struct _Collvec
	{	/* stuff needed by _Strcoll, etc. */
	unsigned long _Hand;	// LCID
	unsigned int _Page;		// UINT
	} _Collvec;

typedef struct _Ctypevec
	{	/* stuff needed by _Tolower, etc. */
	unsigned long _Hand;	// LCID
	unsigned int _Page;		// UINT
	const short *_Table;
	int _Delfl;
	} _Ctypevec;

typedef struct _Cvtvec
	{	/* stuff needed by _Mbrtowc, etc. */
	unsigned long _Hand;	// LCID
	unsigned int _Page;		// UINT
	} _Cvtvec;

		/* FUNCTION DECLARATIONS */
_CRTIMP2_PURE _Collvec __CLRCALL_PURE_OR_CDECL _Getcoll();
_CRTIMP2_PURE _Ctypevec __CLRCALL_PURE_OR_CDECL _Getctype();
_MRTIMP2 _Cvtvec __cdecl _Getcvt();

_CRTIMP2_PURE int __CLRCALL_PURE_OR_CDECL _Getdateorder();

_MRTIMP2 int __cdecl _Mbrtowc(_Out_opt_ wchar_t *, const char *, size_t,
	mbstate_t *, const _Cvtvec *);
_CRTIMP2_PURE float __CLRCALL_PURE_OR_CDECL _Stof(const char *, _Out_opt_ _Deref_post_opt_valid_ char **, long);
_CRTIMP2_PURE double __CLRCALL_PURE_OR_CDECL _Stod(const char *, _Out_opt_ _Deref_post_opt_valid_ char **, long);
_CRTIMP2_PURE long double __CLRCALL_PURE_OR_CDECL _Stold(const char *, _Out_opt_ _Deref_post_opt_valid_ char **, 
  long);
_CRTIMP2_PURE int __CLRCALL_PURE_OR_CDECL _Strcoll(const char *, const char *,
	const char *, const char *, const _Collvec *);
_CRTIMP2_PURE size_t __CLRCALL_PURE_OR_CDECL _Strxfrm(
  _Out_cap_x_(_End1-_String1) _Post_count_( return) char * _String1, 
  _In_z_ char * _End1, const char *, const char *, const _Collvec *);
_CRTIMP2_PURE int __CLRCALL_PURE_OR_CDECL _Tolower(int, const _Ctypevec *);
_CRTIMP2_PURE int __CLRCALL_PURE_OR_CDECL _Toupper(int, const _Ctypevec *);
_MRTIMP2 int __cdecl _Wcrtomb(_Out_ char *, wchar_t, mbstate_t *,
	const _Cvtvec *);
_CRTIMP2_PURE int __CLRCALL_PURE_OR_CDECL _Wcscoll(const wchar_t *, const wchar_t *,
	const wchar_t *, const wchar_t *, const _Collvec *);
_CRTIMP2_PURE size_t __CLRCALL_PURE_OR_CDECL _Wcsxfrm(
  _Out_cap_x_(_End1-_String1) _Post_count_( return) wchar_t *_String1, 
  _In_z_ wchar_t *_End1, const wchar_t *, const wchar_t *, const _Collvec *);

_CRTIMP2_PURE short __CLRCALL_PURE_OR_CDECL _Getwctype(wchar_t, const _Ctypevec *);
_CRTIMP2_PURE const wchar_t * __CLRCALL_PURE_OR_CDECL _Getwctypes(const wchar_t *, const wchar_t *,
	short*, const _Ctypevec*);
_CRTIMP2_PURE wchar_t __CLRCALL_PURE_OR_CDECL _Towlower(wchar_t, const _Ctypevec *);
_CRTIMP2_PURE wchar_t __CLRCALL_PURE_OR_CDECL _Towupper(wchar_t, const _Ctypevec *);
#ifndef MRTDLL
#ifndef _M_CEE_PURE
_END_C_LIB_DECL
#endif
#endif
_C_STD_END

_C_LIB_DECL
_CRTIMP void *__cdecl _Gettnames();
_CRTIMP char *__cdecl _Getdays();
_CRTIMP char *__cdecl _Getmonths();
_CRTIMP size_t __cdecl _Strftime(
  _Out_cap_(_Maxsize) char *, _In_ size_t _Maxsize, 
  _In_z_ __format_string const char *, _In_ const struct tm *, void *);
_END_C_LIB_DECL

_C_LIB_DECL
_locale_t __cdecl _GetLocaleForCP(unsigned int);
_END_C_LIB_DECL

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif /* _XLOCINFO */

/*
 * Copyright (c) 1992-2006 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V5.02:0009 */
