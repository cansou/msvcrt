/***
*crtassem.h - Libraries Assembly information
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This file has information about Libraries Assembly version.
*
*       [Public]
*
****/

#pragma once

#ifndef _VC_ASSEMBLY_PUBLICKEYTOKEN
#define _VC_ASSEMBLY_PUBLICKEYTOKEN "1fc8b3b9a1e18e3b"
#endif  /* _VC_ASSEMBLY_PUBLICKEYTOKEN */

#if !defined (_BIND_TO_CURRENT_VCLIBS_VERSION)
  #define _BIND_TO_CURRENT_VCLIBS_VERSION 1
#endif  /* !defined (_BIND_TO_CURRENT_VCLIBS_VERSION) */

#if !defined (_BIND_TO_CURRENT_CRT_VERSION)
#if _BIND_TO_CURRENT_VCLIBS_VERSION
    #define _BIND_TO_CURRENT_CRT_VERSION 1
#else  /* _BIND_TO_CURRENT_VCLIBS_VERSION */
    #define _BIND_TO_CURRENT_CRT_VERSION 0
#endif  /* _BIND_TO_CURRENT_VCLIBS_VERSION */
#endif  /* !defined (_BIND_TO_CURRENT_CRT_VERSION) */

#ifndef _CRT_ASSEMBLY_VERSION
#if _BIND_TO_CURRENT_CRT_VERSION
#define _CRT_ASSEMBLY_VERSION "9.0.30729.6161"
#else  /* _BIND_TO_CURRENT_CRT_VERSION */
#define _CRT_ASSEMBLY_VERSION "9.0.21022.8"
#endif  /* _BIND_TO_CURRENT_CRT_VERSION */
#endif  /* _CRT_ASSEMBLY_VERSION */

#ifndef __LIBRARIES_ASSEMBLY_NAME_PREFIX
#define __LIBRARIES_ASSEMBLY_NAME_PREFIX "Microsoft.VC90"
#endif  /* __LIBRARIES_ASSEMBLY_NAME_PREFIX */
