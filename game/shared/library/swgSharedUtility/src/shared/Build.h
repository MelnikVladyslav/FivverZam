// ======================================================================
//
// Builds.h
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#ifndef INCLUDED_Builds_H
#define INCLUDED_Builds_H

// ======================================================================

#include "swgSharedUtility/Builds.def"

class StringId;

// ======================================================================
/**
 * Support utilities for working with locomotions.
 */

namespace Builds
{
	const char *     getBuildName     (Builds::Enumerator  build);
	const StringId & getBuildStringId (int build);
}

// ======================================================================

#endif
