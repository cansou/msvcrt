/***
*div.c - contains the div routine
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Performs a signed divide and returns quotient
*       and remainder.
*
*******************************************************************************/

#include <cruntime.h>
#include <stdlib.h>

/***
*div_t div(int numer, int denom) - do signed divide
*
*Purpose:
*       This routine does an divide and returns the results.
*
*Entry:
*       int numer - Numerator passed in on stack
*       int denom - Denominator passed in on stack
*
*Exit:
*       returns quotient and remainder in structure
*
*Exceptions:
*       No validation is done on [denom]* thus, if [denom] is 0,
*       this routine will trap.
*
*******************************************************************************/

div_t __cdecl div (
        int numer,
        int denom
        )
{
        div_t result;

        result.quot = numer / denom;
        result.rem = numer % denom;

        return result;
}
