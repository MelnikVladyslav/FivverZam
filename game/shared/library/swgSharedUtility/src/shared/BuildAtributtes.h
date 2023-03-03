// ======================================================================
//
// BuildAtributtes.h
// Copyright 2002 Sony Online Entertainment, Inc.
// All Rights Reserved.
//
// ======================================================================

#ifndef INCLUDED_BuildAtributtes_H
#define INCLUDED_BuildAtributtes_H

// ======================================================================

#include "swgSharedUtility/BuildAtributtes.def"

class StringId;

// ======================================================================
/**
 * Support utilities for working with locomotions.
 */

namespace BuildAtributtes
{
	const char *     getBuildAtributteName     (BuildAtributtes::Enumerator  buildAtributte);
	const StringId & getBuildAtributteStringId (int buildAtributte);
}

// ======================================================================

#endif
