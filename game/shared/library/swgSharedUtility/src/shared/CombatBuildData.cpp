// ======================================================================
//
// CombatBuildData.cpp
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#include "swgSharedUtility/FirstSwgSharedUtility.h"
#include "swgSharedUtility/CombatBuildData.h"

#include "sharedObject/Object.h"

// ======================================================================

namespace
{
	const char *const cs_combatDefenseNames[CombatBuildData::CD_numCombatDefense] =
		{
			"miss",                   // CD_miss
			"hit",                    // CD_hit
			"block",                  // CD_block
			"evade",                  // CD_evade
			"redirect",               // CD_redirect
			"counterAttack",          // CD_counterAttack
			"lightsaberBlock"         // CD_lightsaberBlock
			"lightsaberCounter"       // CD_lightsaberCounter
			"lightsaberCounterTarget" // CD_lightsaberCounterTarget
		};

	const int cs_combatDefenseNameCount = CombatBuildData::CD_numCombatDefense;
}

// ======================================================================

const char *const CombatBuildData::getCombatDefenseName(CombatBuildData::CombatDefense combatDefense)
{
	if ((combatDefense < 0) || (combatDefense >= cs_combatDefenseNameCount))
		return "<CombatDefense value out of range>";
	else
		return cs_combatDefenseNames[combatDefense];
}

// ======================================================================
