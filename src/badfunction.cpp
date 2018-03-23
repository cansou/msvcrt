// _Xfunc -- exception for tr1 function template
#include <yvals.h>

 #if _HAS_TR1
#include <functional>

_STD_BEGIN
	namespace tr1 {	// TR1 additions

void __CLRCALL_PURE_OR_CDECL _Xfunc()
	{	// throw bad_function_call object
	_THROW_NCEE(bad_function_call, 0);
	}

	}	// namespace tr1
_STD_END
 #endif /* _HAS_TR1 */

/*
 * Copyright (c) 1992-2008 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.05:0009 */
