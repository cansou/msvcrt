/***
*fltintrn.h - contains declarations of internal floating point types,
*             routines and variables
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Declares floating point types, routines and variables used
*       internally by the C run-time.
*
*       [Internal]
*
****/

#if _MSC_VER > 1000
#pragma once
#endif  /* _MSC_VER > 1000 */

#ifndef _INC_FLTINTRN
#define _INC_FLTINTRN

#include <crtdefs.h>

#ifdef _MSC_VER
#pragma pack(push,_CRT_PACKING)
#endif  /* _MSC_VER */

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*
 * For MS C for the x86 family, disable the annoying "long double is the
 * same precision as double" warning
 */

#ifdef _M_IX86
#pragma warning(disable:4069)
#endif  /* _M_IX86 */

/*
 * structs used to fool the compiler into not generating floating point
 * instructions when copying and pushing [long] double values
 */


#ifndef _CRT_DOUBLE_DEC

#ifndef _LDSUPPORT

#pragma pack(4)
typedef struct {
    unsigned char ld[10];
} _LDOUBLE;
#pragma pack()

#define _PTR_LD(x) ((unsigned char  *)(&(x)->ld))

#else  /* _LDSUPPORT */

typedef long double _LDOUBLE;

#define _PTR_LD(x) ((unsigned char  *)(x))

#endif  /* _LDSUPPORT */

typedef struct {
        double x;
} _CRT_DOUBLE;

typedef struct {
    float f;
} _CRT_FLOAT;

typedef struct {
        /*
         * Assume there is a long double type
         */
        long double x;
} _LONGDOUBLE;

#define _CRT_DOUBLE_COMPONENTS_MANTISSA_BITS 52
#define _CRT_DOUBLE_COMPONENTS_EXPONENT_BITS 11
#define _CRT_DOUBLE_COMPONENTS_SIGN_BITS 1

typedef union {
    double d;
    struct {
        unsigned __int64 mantissa: _CRT_DOUBLE_COMPONENTS_MANTISSA_BITS;    /* 52 */
        unsigned __int64 exponent: _CRT_DOUBLE_COMPONENTS_EXPONENT_BITS;    /* 11 */
        unsigned __int64 sign: _CRT_DOUBLE_COMPONENTS_SIGN_BITS;            /*  1 */
    };
} _CRT_DOUBLE_COMPONENTS;

#pragma pack(4)
typedef struct {
    unsigned char ld12[12];
} _LDBL12;
#pragma pack()

#define _CRT_DOUBLE_DEC
#endif  /* _CRT_DOUBLE_DEC */

/*
 * return values for conversion routines
 * (12-byte to long double, double, or float)
 */

typedef enum {
    INTRNCVT_OK,
    INTRNCVT_OVERFLOW,
    INTRNCVT_UNDERFLOW
} INTRNCVT_STATUS;

/*
 * return values for strgtold12 routine
 */

#define SLD_UNDERFLOW 1
#define SLD_OVERFLOW 2
#define SLD_NODIGITS 4

/*
 * debias values
 */

#define BIAS_64 1023

/*
 * typedef for _fltout
 */

typedef struct _strflt
{
        int sign;             /* zero if positive otherwise negative */
        int decpt;            /* exponent of floating point number */
        int flag;             /* zero if okay otherwise IEEE overflow */
        char *mantissa;       /* pointer to mantissa in string form */
}
        *STRFLT;


/*
 * typedef for _fltin
 */

typedef struct _flt
{
        int flags;
        int nbytes;          /* number of characters read */
        long lval;
        double dval;         /* the returned floating point number */
}
        *FLT;


/* floating point conversion routines, keep in sync with mrt32\include\convert.h */

errno_t _cftoe(_In_ double * _Value, _Out_z_bytecap_(3 + _Dec + 5 + 1) char * _Buf, _In_ size_t _SizeInBytes, _In_ int _Dec, _In_ int _Caps);
errno_t _cftoa(_In_ double * _Value, _Out_z_bytecap_(1 + 4 + _Dec + 6) char * _Buf, _In_ size_t _SizeInBytes, _In_ int _Dec, _In_ int _Caps);
errno_t _cftof(_In_ double * _Value, _Out_z_bytecap_(_SizeInBytes) char * _Buf, _In_ size_t _SizeInBytes, _In_ int _Dec);
errno_t __cdecl _fptostr(_Out_z_bytecap_(_SizeInBytes) char * _Buf, _In_ size_t _SizeInBytes, _In_ int _Digits, _Inout_ STRFLT _PtFlt);
_Check_return_ _CRTIMP int __cdecl _atodbl(_Out_ _CRT_DOUBLE * _Result, _In_z_ char * _Str);
_Check_return_ _CRTIMP int __cdecl _atoldbl(_Out_ _LDOUBLE * _Result, _In_z_ char * _Str);
_Check_return_ _CRTIMP int __cdecl _atoflt(_Out_ _CRT_FLOAT * _Result, _In_z_ char * _Str);
_Check_return_ _CRTIMP int __cdecl _atodbl_l(_Out_ _CRT_DOUBLE * _Result, _In_z_ char * _Str, _In_opt_ _locale_t _Locale);
_Check_return_ _CRTIMP int __cdecl _atoldbl_l(_Out_ _LDOUBLE * _Result, _In_z_ char * _Str, _In_opt_ _locale_t _Locale);
_Check_return_ _CRTIMP int __cdecl _atoflt_l(_Out_ _CRT_FLOAT * _Result, _In_z_ char * _Str,_In_opt_ _locale_t _Locale);


STRFLT  __cdecl _fltout2( _In_ _CRT_DOUBLE _Dbl, _Out_ STRFLT _Flt, _Out_z_bytecap_(_SizeInBytes) char * _ResultStr, _In_ size_t _SizeInBytes);
FLT     __cdecl _fltin2( _Out_ FLT _Flt, _In_z_ const char * _Str, _In_ int _LenIgnore, _In_ int _ScaleIgnore, _In_ int _RadixIgnore, _In_ _locale_t _Locale );
FLT     __cdecl _wfltin2( _Out_ FLT _Fit, _In_z_ const wchar_t * _Str, _In_ int _LenIgnore, _In_ int _ScaleIgnore, _In_ int _RadixIgnore, _In_ _locale_t _Locale );

INTRNCVT_STATUS _ld12tod(_In_ _LDBL12 *_Ifp, _Out_ _CRT_DOUBLE *_D);
INTRNCVT_STATUS _ld12tof(_In_ _LDBL12 *_Ifp, _Out_ _CRT_FLOAT *_F);
INTRNCVT_STATUS _ld12told(_In_ _LDBL12 *_Ifp, _Out_ _LDOUBLE *_Ld);

/*
 * floating point helper routines
 *
 * In the non-CRTDLL builds, these prototypes are immediately replaced by
 * macros which replace them with calls through elements of the _cfltcvt_tab
 * array, so we only pull them into a static-link build if floating point
 * code is needed.
 */

errno_t __cdecl _cfltcvt(double *arg, char *buffer, size_t sizeInBytes,
                         int format, int precision,
                         int caps);
errno_t __cdecl _cfltcvt_l(double *arg, char *buffer, size_t sizeInBytes,
                         int format, int precision,
                         int caps, _locale_t plocinfo);

void __cdecl _cropzeros(char *_Buf);
void __cdecl _cropzeros_l(char *_Buf, _locale_t _Locale);
void __cdecl _fassign(int flag, char  *argument, char *number);
void __cdecl _fassign_l(int flag, char  *argument, char *number, _locale_t);
void __cdecl _forcdecpt(char *_Buf);
void __cdecl _forcdecpt_l(char *_Buf, _locale_t _Locale);
int __cdecl _positive(double *arg);

/*
 * table of pointers to floating point helper routines
 *
 * We can't specify the prototypes for the entries of the table accurately,
 * since different functions in the table have different arglists.
 * So we declare the functions to take and return void (which is the
 * correct prototype for _fptrap(), which is what the entries are all
 * initialized to if no floating point is loaded) and cast appropriately
 * on every usage.
 */

#ifndef CRTDLL

typedef void (* PFV)(void);
extern PFV _cfltcvt_tab[10];
#define _CFLTCVT_TAB(i)       (_decode_pointer(_cfltcvt_tab[i]))

typedef void (* PF0)(double*, char*, size_t, int, int, int);
#define _cfltcvt(a,b,c,d,e,f) (*((PF0)_CFLTCVT_TAB(0)))(a,b,c,d,e,f)

typedef void (* PF1)(char*);
#define _cropzeros(a)         (*((PF1)_CFLTCVT_TAB(1)))(a)

typedef void (* PF2)(int, char*, char*);
#define _fassign(a,b,c)       (*((PF2)_CFLTCVT_TAB(2)))(a,b,c)

typedef void (* PF3)(char*);
#define _forcdecpt(a)         (*((PF3)_CFLTCVT_TAB(3)))(a)

typedef int (* PF4)(double*);
#define _positive(a)          (*((PF4)_CFLTCVT_TAB(4)))(a)

typedef void (* PF5)(_LONGDOUBLE*, char*, size_t, int, int, int);
#define _cldcvt(a,b,c,d,e,f)  (*((PF5)_CFLTCVT_TAB(5)))(a,b,c,d,e,f)

typedef void (* PF6)(double*, char*, size_t, int, int, int, _locale_t);
#define _cfltcvt_l(a,b,c,d,e,f,g) (*((PF6)_CFLTCVT_TAB(6)))(a,b,c,d,e,f,g)

typedef void (* PF7)(int, char*, char*, _locale_t);
#define _fassign_l(a,b,c,d)       (*((PF7)_CFLTCVT_TAB(7)))(a,b,c,d)

typedef void (* PF8)(char*, _locale_t);
#define _cropzeros_l(a,b)         (*((PF8)_CFLTCVT_TAB(8)))(a,b)

typedef void (* PF9)(char*, _locale_t);
#define _forcdecpt_l(a,b)         (*((PF9)_CFLTCVT_TAB(9)))(a,b)

#endif  /* CRTDLL */

unsigned int __strgtold12_l
(
    _Out_ _LDBL12 *pld12,
    _Pre_notnull_ _Post_z_ const char * *p_end_ptr,
    _In_z_ const char * str,
    _In_ int mult12,
    _In_ int scale,
    _In_ int decpt,
    _In_ int implicit_E,
#ifdef _SAFECRT_IMPL
    _In_ char dec_point
#else  /* _SAFECRT_IMPL */
    _In_ _locale_t _Locale
#endif  /* _SAFECRT_IMPL */
);

unsigned int __strgtold12
(
    _Out_ _LDBL12 *pld12,
    _Pre_notnull_ _Post_z_ const char * *p_end_ptr,
    _In_z_ const char * str,
    _In_ int mult12,
    _In_ int scale,
    _In_ int decpt,
    _In_ int implicit_E
);

unsigned int __wstrgtold12_l
(
    _Out_ _LDBL12 *pld12,
    _Pre_notnull_ _Post_z_ const wchar_t * *p_end_ptr,
    _In_z_ const wchar_t * str,
    _In_ int mult12,
    _In_ int scale,
    _In_ int decpt,
    _In_ int implicit_E,
    _In_ _locale_t _Locale
);

unsigned int __wstrgtold12
(
    _Out_ _LDBL12 *pld12,
    _Pre_notnull_ _Post_z_ const wchar_t * *p_end_ptr,
    _In_z_ const wchar_t * str,
    _In_ int mult12,
    _In_ int scale,
    _In_ int decpt,
    _In_ int implicit_E
);

unsigned __STRINGTOLD
(
        _Out_ _LDOUBLE *pld,
        _Pre_notnull_ _Post_z_ const char  * *p_end_ptr,
        _In_z_ const char  *str,
        _In_ int mult12
);

unsigned __STRINGTOLD_L
(
        _Out_ _LDOUBLE *pld,
        _Pre_notnull_ _Post_z_ const char  * *p_end_ptr,
        _In_z_ const char  *str,
        _In_ int mult12,
    _In_ _locale_t _Locale
);

unsigned __WSTRINGTOLD
(
        _Out_ _LDOUBLE *pld,
    _Pre_notnull_ _Post_z_ const wchar_t  * *p_end_ptr,
    _In_z_ const wchar_t  *str,
    _In_ int mult12
);

unsigned __WSTRINGTOLD_L
(
        _Out_ _LDOUBLE *pld,
    _Pre_notnull_ _Post_z_ const wchar_t  * *p_end_ptr,
    _In_z_ const wchar_t  *str,
    _In_ int mult12,
    _In_ _locale_t _Locale
);

FLT __cdecl _fltinf_l
(
        _In_count_(len) const char *str,
        _In_ int len,
        _In_ int scale,
        _In_ int decpt,
        _In_ _locale_t _Locale
);

#ifdef _M_IX86
#pragma warning(default:4069)
#endif  /* _M_IX86 */

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#ifdef _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif  /* _INC_FLTINTRN */
