// ======================================================================
//
// buildAtributtes.cpp
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#include "swgSharedUtility/FirstSwgSharedUtility.h"
#include "swgSharedUtility/buildAtributtes.h"

#include "StringId.h"
#include "UnicodeUtils.h"

// ======================================================================

namespace
{
	const char *const cs_buildAtributtesNames[] =
		{
		"health",
		"damage",
		"diapazon",
		"defend",
		"bullet",
		};

	const int cs_buildAtributtesNamesCount = static_cast<int>(sizeof(cs_buildAtributtesNames)/sizeof(cs_buildAtributtesNames[0]));

	StringId cs_buildAtributtesStringIds [cs_buildAtributtesNamesCount];

	//----------------------------------------------------------------------

	bool s_installed = false;

	void install ()
	{
		if (s_installed)
			return;

		s_installed = true;

		static const std::string tableName = "buildAtributtes_n";

		for (int i = 0; i < cs_buildAtributtesNamesCount; ++i)
		{
			cs_buildAtributtesStringIds [i] = StringId (tableName, Unicode::toLower (cs_buildAtributtesNames [i]));
		}
	}
}



const char *buildAtributtess::getbuildAtributtessName(Locomotions::Enumerator buildAtributtes)
{
	DEBUG_FATAL(cs_buildAtributtesNamesCount != Locomotions::NumberOfbuildAtributtess, ("buildAtributtes name table in buildAtributtes.cpp needs to be updated."));
	if ((buildAtributtes < 0) || (buildAtributtes >= cs_buildAtributtesNamesCount))
		return "<buildAtributtes value out of range>";
	else
		return cs_buildAtributtesNames[buildAtributtes];
}

//----------------------------------------------------------------------

const StringId & buildAtributtess::getbuildAtributtesStringId (int buildAtributtes)
{
	if (!s_installed)
		install ();
	if ((buildAtributtes < 0) || (buildAtributtes >= cs_buildAtributtesNamesCount))
	{
		static const StringId nullStringId;
		return nullStringId;
	}	
	else
		return cs_buildAtributtesStringIds[buildAtributtes];
}

// ======================================================================
