// ======================================================================
//
// Terrain.cpp
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#include "swgSharedUtility/FirstSwgSharedUtility.h"
#include "swgSharedUtility/Terrain.h"

#include "StringId.h"
#include "UnicodeUtils.h"

// ======================================================================

namespace
{
	const char *const cs_terrainNames[] =
		{
		"forrest",
		"plane",
		"mountains",
		"desert",
		};

	const int cs_terrainNamesCount = static_cast<int>(sizeof(cs_terrainNames)/sizeof(cs_terrainNames[0]));

	StringId cs_terrainStringIds [cs_terrainNamesCount];

	//----------------------------------------------------------------------

	bool s_installed = false;

	void install ()
	{
		if (s_installed)
			return;

		s_installed = true;

		static const std::string tableName = "terrain_n";

		for (int i = 0; i < cs_terrainNamesCount; ++i)
		{
			cs_terrainStringIds [i] = StringId (tableName, Unicode::toLower (cs_terrainNames [i]));
		}
	}
}



const char *Terrains::getTerrainName(Locomotions::Enumerator terrain)
{
	DEBUG_FATAL(cs_terrainNamesCount != Locomotions::NumberOfTerrains, ("Terrain name table in Terrain.cpp needs to be updated."));
	if ((terrain < 0) || (terrain >= cs_terrainNamesCount))
		return "<terrain value out of range>";
	else
		return cs_terrainNames[terrain];
}

//----------------------------------------------------------------------

const StringId & Terrains::getTerrainStringId (int terrain)
{
	if (!s_installed)
		install ();
	if ((terrain < 0) || (terrain >= cs_terrainNamesCount))
	{
		static const StringId nullStringId;
		return nullStringId;
	}	
	else
		return cs_terrainStringIds[terrain];
}

// ======================================================================
