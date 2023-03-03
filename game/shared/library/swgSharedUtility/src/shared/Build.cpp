// ======================================================================
//
// Build.cpp
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#include "swgSharedUtility/FirstSwgSharedUtility.h"
#include "swgSharedUtility/Build.h"

#include "StringId.h"
#include "UnicodeUtils.h"

// ======================================================================

namespace
{
	const char *const cs_buildNames[] =
		{
		"turrel",
		"ppo",
		"wall",
		"rocketPpo",
		};

	const int cs_buildNamesCount = static_cast<int>(sizeof(cs_buildNames)/sizeof(cs_buildNames[0]));

	StringId cs_buildStringIds [cs_buildNamesCount];

	//----------------------------------------------------------------------

	bool s_installed = false;

	void install ()
	{
		if (s_installed)
			return;

		s_installed = true;

		static const std::string tableName = "build_n";

		for (int i = 0; i < cs_buildNamesCount; ++i)
		{
			cs_buildStringIds [i] = StringId (tableName, Unicode::toLower (cs_buildNames [i]));
		}
	}
}



const char *Builds::getBuildsName(Locomotions::Enumerator build)
{
	DEBUG_FATAL(cs_buildNamesCount != Locomotions::NumberOfbuilds, ("build name table in build.cpp needs to be updated."));
	if ((build < 0) || (build >= cs_buildNamesCount))
		return "<build value out of range>";
	else
		return cs_buildNames[build];
}

//----------------------------------------------------------------------

const StringId & Builds::getbuildStringId (int build)
{
	if (!s_installed)
		install ();
	if ((build < 0) || (build >= cs_buildNamesCount))
	{
		static const StringId nullStringId;
		return nullStringId;
	}	
	else
		return cs_buildStringIds[build];
}

// ======================================================================
