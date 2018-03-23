/***
*crt0init.c - Initialization segment declarations.
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Do initialization segment declarations.
*
*Notes:
*       In the 16-bit C world, the X*B and X*E segments were empty except for
*       a label.  This will not work with COFF since COFF throws out empty
*       sections.  Therefore we must put a zero value in them.  (Zero because
*       the routine to traverse the initializers will skip over zero entries.)
*
*******************************************************************************/

#include <sect_attribs.h>
#include <stdio.h>
#include <internal.h>

_CRTALLOC(".CRT$XIA") _PIFV __xi_a[] = { NULL };

_CRTALLOC(".CRT$XIZ") _PIFV __xi_z[] = { NULL };

_CRTALLOC(".CRT$XCA") _PVFV __xc_a[] = { NULL };

_CRTALLOC(".CRT$XCZ") _PVFV __xc_z[] = { NULL };

_CRTALLOC(".CRT$XPA") _PVFV __xp_a[] = { NULL };

_CRTALLOC(".CRT$XPZ") _PVFV __xp_z[] = { NULL };

_CRTALLOC(".CRT$XTA") _PVFV __xt_a[] = { NULL };

_CRTALLOC(".CRT$XTZ") _PVFV __xt_z[] = { NULL };

#pragma comment(linker, "/merge:.CRT=.rdata")

#pragma comment(linker, "/defaultlib:kernel32.lib")

#pragma comment(linker, "/disallowlib:libc.lib")
#pragma comment(linker, "/disallowlib:libcd.lib")
#if !(!defined (_DEBUG))
#pragma comment(linker, "/disallowlib:libcmt.lib")
#endif  /* !(!defined (_DEBUG)) */
#if !(defined (_DEBUG))
#pragma comment(linker, "/disallowlib:libcmtd.lib")
#endif  /* !(defined (_DEBUG)) */
#pragma comment(linker, "/disallowlib:msvcrt.lib")
#pragma comment(linker, "/disallowlib:msvcrtd.lib")
