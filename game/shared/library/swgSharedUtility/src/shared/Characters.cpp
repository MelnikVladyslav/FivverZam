// ======================================================================
//
// Characters.cpp
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#include "swgSharedUtility/FirstSwgSharedUtility.h"
#include "swgSharedUtility/Characters.h"

#include "StringId.h"
#include "UnicodeUtils.h"

// ======================================================================

namespace
{
	const char *const cs_CharactersNames[] =
		{
			"health",
			"strength",
			"constitution",
			"action",
			"quickness",
			"stamina",
			"mind",
			"focus",
			"willpower"
		};

	const int cs_CharactersNamesCount = static_cast<int>(sizeof(cs_CharactersNames)/sizeof(cs_CharactersNames[0]));

	StringId cs_CharactersStringIds [cs_CharactersNamesCount];

	//----------------------------------------------------------------------

	bool s_installed = false;

	void install ()
	{
		if (s_installed)
			return;

		s_installed = true;

		static const std::string tableName = "Characters_n";

		for (int i = 0; i < cs_CharactersNamesCount; ++i)
		{
			cs_CharactersStringIds [i] = StringId (tableName, Unicode::toLower (cs_CharactersNames [i]));
		}
	}
}



const char *Characterss::getCharacterssName(Locomotions::Enumerator Characters)
{
	DEBUG_FATAL(cs_CharactersNamesCount != Locomotions::NumberOfCharacterss, ("Characters name table in Characters.cpp needs to be updated."));
	if ((Characters < 0) || (Characters >= cs_CharactersNamesCount))
		return "<Characters value out of range>";
	else
		return cs_CharactersNames[Characters];
}

//----------------------------------------------------------------------

const StringId & Characterss::getCharactersStringId (int Characters)
{
	if (!s_installed)
		install ();
	if ((Characters < 0) || (Characters >= cs_CharactersNamesCount))
	{
		static const StringId nullStringId;
		return nullStringId;
	}	
	else
		return cs_CharactersStringIds[Characters];
}

// ======================================================================
