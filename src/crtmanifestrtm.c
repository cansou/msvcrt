/***  
*crtmanifestrtm.c - CRT DLL manifest - current version  
*  
*       Copyright (c) Microsoft Corporation. All rights reserved.  
*  
*Purpose:  
*       This module contains the manifest snippet that has to be added  
*       to the application. Manifest version refers to the RTM version  
*  
*******************************************************************************/   
   
#define _DLL   
#define _USE_RTM_VERSION   
#undef _CRT_NOFORCE_MANIFEST   
#undef _VC_NODEFAULTLIB   
#include <crtdefs.h>   
   
int _forceCRTManifestRTM=1;   
 