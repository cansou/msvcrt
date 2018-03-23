/***
*ldiv.c - contains the ldiv routine
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Performs a signed divide on longs and returns quotient
*       and remainder.
*
*******************************************************************************/

#include <cruntime.h>
#include <stdlib.h>

/***
*ldiv_t div(long numer, long denom) - do signed divide
*
*Purpose:
*       This routine does an long divide and returns the results.
*
*Entry:
*       long numer - Numerator passed in on stack
*       long denom - Denominator passed in on stack
*
*Exit:
*       returns quotient and remainder in structure
*
*Exceptions:
*       No validation is done on [denom]* thus, if [denom] is 0,
*       this routine will trap.
*
*******************************************************************************/

ldiv_t __cdecl ldiv (
        long numer,
        long denom
        )
{
        ldiv_t result;

        result.quot = numer / denom;
        result.rem = numer % denom;

        return result;
}
