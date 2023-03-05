// ======================================================================
//
// Bullets.h
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#ifndef INCLUDED_Bullets_H
#define INCLUDED_Bullets_H

// ======================================================================

#include "swgSharedUtility/Bullets.def"

class StringId;

// ======================================================================
/**
 * Support utilities for working with locomotions.
 */

namespace Bullets
{
	const char *     getBulletName     (Bullets::Enumerator  Bullet);
	const StringId & getBulletStringId (int Bullet);
}

// ======================================================================

#endif
