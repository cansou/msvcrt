// regex: various utilities needed by basic_regex
#include <new>

 #if _HAS_EXCEPTIONS
 #include <regex>

_STD_BEGIN
namespace tr1 {	// TR1 additions

	// EXCEPTIONS
void __CLRCALL_PURE_OR_CDECL _Xmem()
	{	// throw bad_alloc exception
	_THROW_NCEE(_XSTD bad_alloc,);
	}

void __CLRCALL_PURE_OR_CDECL _Xbad(regex_constants::error_type error)
	{	// throw regex_error exception
	_THROW_NCEE(_STD tr1::regex_error, error);
	}
	}	// namespace tr1
_STD_END
 #else
 #endif /* _HAS_EXCEPTIONS */

/*
 * Copyright (c) 1992-2008 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.05:0009 */
