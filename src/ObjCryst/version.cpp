/*****************************************************************************
*
* libobjcryst       Complex Modeling Initiative
*                   (c) 2015 Brookhaven Science Associates,
*                   Brookhaven National Laboratory.
*                   All rights reserved.
*
* File coded by:    Pavol Juhas
*
* See AUTHORS.txt for a list of people who contributed.
* See LICENSE.txt for license information.
*
******************************************************************************
*
* Definitions for the libobjcryst_version_info constants.
*
*****************************************************************************/

#include "version.h"

const double libobjcryst_version_info::version = LIBOBJCRYST_VERSION;
const char* libobjcryst_version_info::version_str = LIBOBJCRYST_VERSION_STR;
const int libobjcryst_version_info::major = LIBOBJCRYST_VERSION_MAJOR;
const int libobjcryst_version_info::minor = LIBOBJCRYST_VERSION_MINOR;
const int libobjcryst_version_info::micro = LIBOBJCRYST_VERSION_MICRO;
const char* libobjcryst_version_info::date = LIBOBJCRYST_VERSION_DATE;
const char* libobjcryst_version_info::git_sha = LIBOBJCRYST_GIT_SHA;

// End of file
