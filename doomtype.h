// Emacs style mode select   -*- C++ -*-
//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 1993-1996 by id Software, Inc.
//
// This source is available for distribution and/or modification
// only under the terms of the DOOM Source Code License as
// published by id Software. All rights reserved.
//
// The source is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// FITNESS FOR A PARTICULAR PURPOSE. See the DOOM Source Code License
// for more details.
//
// DESCRIPTION:
//	Simple basic typedefs, isolated here to make it easier
//	 separating modules.
//
//-----------------------------------------------------------------------------

#ifndef __DOOMTYPE__
#define __DOOMTYPE__

#ifndef CELLDOOM

#ifndef __BYTEBOOL__
#define __BYTEBOOL__
// Fixed to use builtin bool type with C++.
#ifdef __cplusplus
typedef bool boolean;
#else
typedef enum { false, true } boolean;
#endif
typedef unsigned char byte;
#endif

// Predefined with some OS.
#ifdef LINUX
#include <values.h>
#else
#define MAXCHAR ((char)0x7f)
#define MAXSHORT ((short)0x7fff)

// Max pos 32-bit int.
#define MAXINT ((int)0x7fffffff)
#define MAXLONG ((long)0x7fffffff)
#define MINCHAR ((char)0x80)
#define MINSHORT ((short)0x8000)

// Max negative 32-bit integer.
#define MININT ((int)0x80000000)
#define MINLONG ((long)0x80000000)
#endif

#else

// CELLDOOM
//  Use headers and limits provided by the SDK

#ifndef __BYTEBOOL__
#define __BYTEBOOL__

//#ifdef __cplusplus
#include <stdbool.h>
typedef bool boolean;
//#else
//typedef enum { false, true } boolean;
//#endif

// This comes from Chocolate DOOM. It's clever!
#include <inttypes.h>

typedef uint8_t byte;
typedef uint8_t pixel_t;
typedef int16_t dpixel_t;

#endif // __BYTEBOOL__

#include <limits.h>

#define MAXCHAR CHAR_MAX
#define MAXSHORT SHRT_MAX
#define MAXINT INT_MAX
#define MAXLONG LONG_MAX

#define MINCHAR CHAR_MIN
#define MINSHORT SHRT_MIN
#define MININT INT_MIN
#define MINLONG LONG_MIN

#endif

#endif
//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------
