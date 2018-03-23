// xinvalid: throw exception from TR1 random number generators
#include <stdexcept>

 #if _HAS_TR1
//  #include <random>
_STD_BEGIN
	namespace tr1 {	// TR1 additions

_CRTIMP2_PURE __declspec(noreturn) void __CLRCALL_PURE_OR_CDECL
	_Xinvalid(_In_z_ const char *_Msg = "");

void __CLRCALL_PURE_OR_CDECL _Xinvalid(const char *msg)
	{	// throw invalid_argument exception
	_THROW_NCEE(invalid_argument, msg);
	}

	}	// namespace tr1
_STD_END
 #endif /* _HAS_TR1 */

/*
 * Copyright (c) 1992-2008 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.05:0009 */
