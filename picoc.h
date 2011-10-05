/* picoc external interface. This should be the only header you need to use if
 * you're using picoc as a library. Internal details are in interpreter.h */
#ifndef PICOC_H
#define PICOC_H

/* picoc version number */
#ifdef VER
#define PICOC_VERSION "v2.2 beta r" VER         /* VER is the subversion version number, obtained via the Makefile */
#else
#define PICOC_VERSION "v2.2"
#endif

/* handy definitions */
#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif


#if defined(UNIX_HOST) || defined(WIN32)
#include <setjmp.h>

/* mark where to end the program for platforms which require this */
extern jmp_buf PicocExitBuf;

/* this has to be a macro, otherwise errors will occur due to the stack being corrupt */
#define PicocPlatformSetExitPoint() setjmp(PicocExitBuf)
#endif

#ifdef SURVEYOR_HOST
/* mark where to end the program for platforms which require this */
extern int PicocExitBuf[];

#define PicocPlatformSetExitPoint() setjmp(PicocExitBuf)
#endif

/* parse.c */
void PicocParse(const char *FileName, const char *Source, int SourceLen, int RunIt, int CleanupNow, int CleanupSource, int EnableDebugger);
void PicocParseInteractive();

/* platform.c */
void PicocCallMain(int argc, char **argv);
void PicocInitialise(int StackSize);
void PicocCleanup();
void PicocPlatformScanFile(const char *FileName);

extern int PicocExitValue;

/* include.c */
void PicocIncludeAllSystemHeaders();

#endif /* PICOC_H */
