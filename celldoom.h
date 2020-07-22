/*
 * celldoom.h
 * PlayStation(R)3 SDK Compatibility Definitions
 * Copyright (C) 2020 Jacopo Maltagliati
 * Released under the MIT License
 */

#ifndef __CELLDOOM__
#define __CELLDOOM__

///////////////////////////////////////////////////////////////////////////////
// CD_Include

//#include "doomdef.h"
//#include "doomtype.h"
//#include <alloca.h>

#include <cell/cell_fs.h>
#include <cell/sysmodule.h>
//#include <sys/memory.h>
#include <sys/paths.h>
#include <sys/process.h>
#include <sys/time.h>
#include <sys/timer.h>
#include <sys/spu_initialize.h>
#include <sysutil/sysutil_sysparam.h>
#include <PSGL/psgl.h>

///////////////////////////////////////////////////////////////////////////////
// CD_DevFlags

#define CELLDOOM __PS3__
#define NORMALUNIX CELLDOOM
#define SNDSRV 1 // hack till sound is fixed (it's gonna be a lot of work)

///////////////////////////////////////////////////////////////////////////////
// CD_PosixCompat

#include "doomtype.h"

// Directly "stolen" from unistd.h
#define R_OK 4 // Test for read permission.
#define W_OK 2 // Test for write permission.
#define X_OK 1 // Test for execute permission.
#define F_OK 0 // Test for existence.

char *getenv(char *env_id);
int access(const char *pathname, int mode);
//#undef alloca
//void* alloca(size_t size);
//void free(void* p);
//realloc()
//alloca()

///////////////////////////////////////////////////////////////////////////////
// CD_Logic

void CD_DoomMain();

///////////////////////////////////////////////////////////////////////////////
// CD_Timing

typedef system_time_t cd_systime;
inline cd_systime CD_GetSysTime();
inline void CD_USleep(unsigned long long amount);

///////////////////////////////////////////////////////////////////////////////
// CD_FS

void CD_FSLoadModule();
int CD_FSTestAccess(const char *fname, CellFsStat *status);

///////////////////////////////////////////////////////////////////////////////
// CD_Memory

//void* CD_MemoryAllocate(size_t size);

///////////////////////////////////////////////////////////////////////////////
// CD_Video

void CD_VideoLoadModule();
void CD_VideoInit();

///////////////////////////////////////////////////////////////////////////////
// CD_PSGL

void CD_PSGLInit();
void CD_PSGLDestroy();

typedef struct devinfo_t {
  GLuint width;
  GLuint height;
  GLfloat aspectRatio;
  GLenum colorFormat;
  GLenum depthFormat;
  GLenum multisamplingMode;
} devinfo_t;

PSGLinitOptions CD_PSGLOptions;

devinfo_t CD_PSGLDeviceInfo;
PSGLdevice* CD_PSGLDevice;

PSGLcontext* CD_PSGLMainContext;

///////////////////////////////////////////////////////////////////////////////
// CD_Audio

#endif // __CELLDOOM__
