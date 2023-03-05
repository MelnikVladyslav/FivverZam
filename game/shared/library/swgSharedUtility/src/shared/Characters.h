// ======================================================================
//
// Characters.h
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#ifndef INCLUDED_Characters_H
#define INCLUDED_Characters_H

// ======================================================================

#include "swgSharedUtility/Characters.def"

class StringId;

// ======================================================================
/**
 * Support utilities for working with locomotions.
 */

namespace Characters
{
	const char *     getCharactersName     (Characters::Enumerator  Character);
	const StringId & getCharactersStringId (int Character);
}

// ======================================================================

#endif
