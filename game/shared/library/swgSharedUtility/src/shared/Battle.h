// ======================================================================
//
// Battle.h
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#ifndef INCLUDED_Battle_H
#define INCLUDED_Battle_H

// ======================================================================

#include "swgSharedUtility/Battle.def"

class StringId;

// ======================================================================
/**
 * Support utilities for working with locomotions.
 */

namespace Battle
{
	const char *     getBattleName     (Battle::Enumerator  battle);
	const StringId & getBattletringId (int battle);
}

// ======================================================================

#endif
