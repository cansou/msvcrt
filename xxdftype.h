/* xxdftype.h -- parameters for double floating-point type */
#include <yvals.h>
#include <float.h>

#define FTYPE	double
#define FCTYPE	_Dcomplex
#define FBITS	DBL_MANT_DIG
#define FEPS	DBL_EPSILON
#define FMAXEXP	DBL_MAX_EXP
#define FFUN(fun)	fun
#define FMACRO(x)	x
#define FNAME(fun)	_##fun
#define FCONST(obj)	_##obj._Double
#define FLIT(lit)	lit
#define FISNEG(exp)	DSIGN(exp)
#define FCPTYPE	complex<double>

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V5.03:0009 */
