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
// $Log:$
//
// DESCRIPTION:
//	DOOM graphics stuff for X11, UNIX.
//
//-----------------------------------------------------------------------------

static const char rcsid[] = "$Id: i_x.c,v 1.6 1997/02/03 22:45:10 b1 Exp $";

// CELLDOOM_HOOK
#include "celldoom.h"

#include <stdlib.h>
#include <unistd.h>

#include <stdarg.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>

//#include <netinet/in.h>

#include "d_main.h"
#include "doomstat.h"
#include "i_system.h"
#include "m_argv.h"
#include "v_video.h"

#include "doomdef.h"

void I_StartFrame(void) {
  // TODO: patch
}

void I_UpdateNoBlit(void) {
  // TODO: patch
}

void I_FinishUpdate(void) {
  // TODO: patch
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  psglSwap();
}

void I_ReadScreen(byte *scr) {
  memcpy(scr, screens[0], SCREENWIDTH * SCREENHEIGHT);
}

void I_SetPalette(byte *palette) {
  // TODO: patch
}

void I_InitGraphics(void) {
  printf("I_InitGraphics: Initializing PSGL...\n");
  CD_PSGLInit();

  // get render target buffer dimensions and set viewport
  GLuint renderWidth, renderHeight;
  psglGetRenderBufferDimensions(CD_PSGLDevice, &renderWidth, &renderHeight);

  glViewport(0, 0, renderWidth, renderHeight);

  // get display aspect ratio (width / height) and set projection
  // (it is important to use this value and NOT renderWidth/renderHeight since
  // pixel ratios do not necessarily match the 16/9 or 4/3 display aspect
  // ratios)

  float l = CD_PSGLDeviceInfo.aspectRatio, r = -l, b = -1, t = 1;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrthof(l, r, b, t, 0, 1);

  glClearColor(0.3f, 0.3f, 0.7f, 0.0f);
  glClearDepthf(1.0f);
  glDisable(GL_CULL_FACE);

  // PSGL doesn't clear the screen on startup, so let's do that here.
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
  psglSwap();
}

void I_ShutdownGraphics(void) {
  printf("I_ShutdownGraphics: Destroying PSGL...\n");
  CD_PSGLDestroy();
}

void I_StartTic(void) {
  // TODO: decide if we want network to work or not (probably the latter)
}
