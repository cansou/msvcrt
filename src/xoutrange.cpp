// xrange: throw out_of_range object for TR1 array template
#include <stdexcept>

 #if _IS_EMBEDDED
 #else /* _IS_EMBEDDED */
  #include <array>

_STD_BEGIN
	namespace tr1 {	// TR1 additions

void __CLRCALL_PURE_OR_CDECL _Xoutrange()
	{	// report an out_of_range error
	_THROW_NCEE(out_of_range, "invalid array<T> subscript");
	}

	}	// namespace tr1
_STD_END
 #endif /* _IS_EMBEDDED */

/*
 * Copyright (c) 1992-2008 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.05:0009 */
