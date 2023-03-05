// ======================================================================
//
// Bullet.cpp
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#include "swgSharedUtility/FirstSwgSharedUtility.h"
#include "swgSharedUtility/Bullet.h"

#include "StringId.h"
#include "UnicodeUtils.h"

// ======================================================================

namespace
{
	const char *const cs_BulletNames[] =
		{
		"power",
		"range",
		"breakingThrough"
		};

	const int cs_BulletNamesCount = static_cast<int>(sizeof(cs_BulletNames)/sizeof(cs_BulletNames[0]));

	StringId cs_BulletStringIds [cs_BulletNamesCount];

	//----------------------------------------------------------------------

	bool s_installed = false;

	void install ()
	{
		if (s_installed)
			return;

		s_installed = true;

		static const std::string tableName = "Bullet_n";

		for (int i = 0; i < cs_BulletNamesCount; ++i)
		{
			cs_BulletStringIds [i] = StringId (tableName, Unicode::toLower (cs_BulletNames [i]));
		}
	}
}



const char *Bullets::getBulletsName(Locomotions::Enumerator Bullet)
{
	DEBUG_FATAL(cs_BulletNamesCount != Locomotions::NumberOfBullets, ("Bullet name table in Bullet.cpp needs to be updated."));
	if ((Bullet < 0) || (Bullet >= cs_BulletNamesCount))
		return "<Bullet value out of range>";
	else
		return cs_BulletNames[Bullet];
}

//----------------------------------------------------------------------

const StringId & Bullets::getBulletStringId (int Bullet)
{
	if (!s_installed)
		install ();
	if ((Bullet < 0) || (Bullet >= cs_BulletNamesCount))
	{
		static const StringId nullStringId;
		return nullStringId;
	}	
	else
		return cs_BulletStringIds[Bullet];
}

// ======================================================================
