// xrngdev: random device for TR1 random number generators
#define _CRT_RAND_S
#include <stdexcept>

 #if _HAS_TR1
//  #include <random>
_STD_BEGIN
	namespace tr1 {	// TR1 additions

_CRTIMP2_PURE unsigned int __CLRCALL_PURE_OR_CDECL _Random_device();

unsigned int __CLRCALL_PURE_OR_CDECL _Random_device()
	{	// return a random value
	unsigned int ans;
	if (::rand_s(&ans) != 0)
		_THROW_NCEE(out_of_range, "invalid random_device value");
	return (ans);
	}

	}	// namespace tr1
_STD_END
 #endif /* _HAS_TR1 */

/*
 * Copyright (c) 1992-2008 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
V5.05:0009 */
