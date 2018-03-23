/***
*initcrit.c - CRT wrapper for InitializeCriticalSectionAndSpinCount
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Contains __crtInitCritSecAndSpinCount, a wrapper for
*       the Win32 API InitializeCriticalSectionAndSpinCount which is only
*       available on NT4SP3 or better.
*
*       *** For internal use only ***
*
*******************************************************************************/


#include <cruntime.h>
#include <windows.h>
#include <internal.h>
#include <rterr.h>
#include <stdlib.h>

typedef
BOOL
(WINAPI * PFN_INIT_CRITSEC_AND_SPIN_COUNT) (
    PCRITICAL_SECTION lpCriticalSection,
    DWORD dwSpinCount
);

static PFN_INIT_CRITSEC_AND_SPIN_COUNT __pfnInitCritSecAndSpinCount;

/***
*void _initp_misc_initcrit(void*)
*
*Purpose:
*       Initialize static pointer to function
*
*Entry:
*       The per-process encoded value for the NULL pointer.
*
*Exit:
*
*Exceptions:
*
*******************************************************************************/

void __cdecl _initp_misc_initcrit(void* enull)
{
    __pfnInitCritSecAndSpinCount = (PFN_INIT_CRITSEC_AND_SPIN_COUNT) enull;
}

/***
*int __crtInitCritSecAndSpinCount() - initialize critical section
*
*Purpose:
*       Calls InitializeCriticalSectionAndSpinCount, if available, otherwise
*       InitializeCriticalSection.  On multiprocessor systems, a spin count
*       should be used with critical sections, but the appropriate APIs are
*       only available on NT4SP3 or later.
*
*       Also handles the out of memory condition which is possible with
*       InitializeCriticalSection[AndSpinCount].
*
*Entry:
*       PCRITICAL_SECTION lpCriticalSection - ptr to critical section
*       DWORD dwSpinCount - initial spin count setting
*
*Exit:
*       Returns FALSE and sets Win32 last-error code to ERROR_NOT_ENOUGH_MEMORY
*       if InitializeCriticalSection[AndSpinCount] fails.
*
*Exceptions:
*
*******************************************************************************/

int __cdecl __crtInitCritSecAndSpinCount (
    PCRITICAL_SECTION lpCriticalSection,
    DWORD dwSpinCount
    )
{
    int ret;

    __try {
        /*
         * Call the real InitializeCriticalSectionAndSpinCount
         */
        ret = InitializeCriticalSectionAndSpinCount(lpCriticalSection, dwSpinCount);
    }
    __except (_exception_code()== STATUS_NO_MEMORY ? EXCEPTION_EXECUTE_HANDLER:EXCEPTION_CONTINUE_SEARCH) {
        /*
         * Initialization failed by raising an exception, which is probably
         * STATUS_NO_MEMORY.  It is not safe to set the CRT errno to ENOMEM,
         * since the per-thread data may not yet exist.  Instead, set the Win32
         * error which can be mapped to ENOMEM later.
         */
        if (GetExceptionCode() == STATUS_NO_MEMORY) {
            SetLastError(ERROR_NOT_ENOUGH_MEMORY);
        }
        ret = FALSE;
    }

    return ret;
}

