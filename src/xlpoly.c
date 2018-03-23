/* _LPoly function */
#include "xmath.h"
_C_STD_BEGIN

_CRTIMP2_PURE long double __CLRCALL_PURE_OR_CDECL _LPoly(long double x,
	const long double *tab, int n)
	{	/* compute polynomial */
	long double y;

	for (y = *tab; 0 <= --n; )
		y = y * x + *++tab;
	return (y);
	}
_C_STD_END

/*
 * Copyright (c) 1992-2007 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V5.03:0009 */
