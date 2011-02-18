#ifndef PICOC_H
#define PICOC_H

/* picoc version number */
#ifdef VER
#define PICOC_VERSION "v2.1 beta r" VER         /* VER is the subversion version number, obtained via the Makefile */
#else
#define PICOC_VERSION "v2.1 beta"
#endif

/* handy definitions */
#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif


#ifdef UNIX_HOST
#include <setjmp.h>

/* mark where to end the program for platforms which require this */
extern jmp_buf PicocExitBuf;

/* this has to be a macro, otherwise errors will occur due to the stack being corrupt */
#define PicocPlatformSetExitPoint() setjmp(PicocExitBuf)
#endif


/* parse.c */
void PicocParse(const char *FileName, const char *Source, int SourceLen, int RunIt, int CleanupNow, int CleanupSource);
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
