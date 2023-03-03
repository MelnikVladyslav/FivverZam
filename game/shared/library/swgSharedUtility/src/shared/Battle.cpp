// ======================================================================
//
// Battle.cpp
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#include "swgSharedUtility/FirstSwgSharedUtility.h"
#include "swgSharedUtility/Battle.h"

#include "StringId.h"
#include "UnicodeUtils.h"

// ======================================================================

namespace
{
	const char *const cs_battleNames[] =
		{
		"speed",
		"power",
		"terrain",
		"build",
		};

	const int cs_battleNamesCount = static_cast<int>(sizeof(cs_battleNames)/sizeof(cs_battleNames[0]));

	StringId cs_battleStringIds [cs_battleNamesCount];

	//----------------------------------------------------------------------

	bool s_installed = false;

	void install ()
	{
		if (s_installed)
			return;

		s_installed = true;

		static const std::string tableName = "battle_n";

		for (int i = 0; i < cs_battleNamesCount; ++i)
		{
			cs_battleStringIds [i] = StringId (tableName, Unicode::toLower (cs_battleNames [i]));
		}
	}
}



const char *battles::getbattlesName(Locomotions::Enumerator battle)
{
	DEBUG_FATAL(cs_battleNamesCount != Locomotions::NumberOfbattles, ("battle name table in battle.cpp needs to be updated."));
	if ((battle < 0) || (battle >= cs_battleNamesCount))
		return "<battle value out of range>";
	else
		return cs_battleNames[battle];
}

//----------------------------------------------------------------------

const StringId & battles::getbattleStringId (int battle)
{
	if (!s_installed)
		install ();
	if ((battle < 0) || (battle >= cs_battleNamesCount))
	{
		static const StringId nullStringId;
		return nullStringId;
	}	
	else
		return cs_battleStringIds[battle];
}

// ======================================================================
