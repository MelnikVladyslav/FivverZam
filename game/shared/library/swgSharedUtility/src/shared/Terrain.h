// ======================================================================
//
// Terrains.h
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#ifndef INCLUDED_Terrains_H
#define INCLUDED_Terrains_H

// ======================================================================

#include "swgSharedUtility/Terrains.def"

class StringId;

// ======================================================================
/**
 * Support utilities for working with locomotions.
 */

namespace Terrains
{
	const char *     getTerrainName     (Terrains::Enumerator  terrain);
	const StringId & getTerrainStringId (int terrain);
}

// ======================================================================

#endif
