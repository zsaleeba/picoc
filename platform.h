/* all platform-specific includes and defines go in this file */
#ifndef PLATFORM_H
#define PLATFORM_H

/* configurable options */
/* select your host type (or do it in the Makefile):
 * #define  UNIX_HOST
 * #define  FLYINGFOX_HOST
 * #define  SURVEYOR_HOST
 * #define  UMON_HOST
 */

#define LARGE_INT_POWER_OF_TEN 1000000000   /* the largest power of ten which fits in an int on this architecture */
#ifdef __hppa__
#define ALIGN_TYPE double                   /* the data type to use for alignment */
#else
#define ALIGN_TYPE void *                   /* the data type to use for alignment */
#endif

#define GLOBAL_TABLE_SIZE 97                /* global variable table */
#define STRING_TABLE_SIZE 97                /* shared string table size */
#define STRING_LITERAL_TABLE_SIZE 97        /* string literal table size */
#define PARAMETER_MAX 16                    /* maximum number of parameters to a function */
#define LINEBUFFER_MAX 256                  /* maximum number of characters on a line */
#define LOCAL_TABLE_SIZE 11                 /* size of local variable table (can expand) */
#define STRUCT_TABLE_SIZE 11                /* size of struct/union member table (can expand) */

#define FANCY_ERROR_REPORTING               /* optional feature - gives more detailed error messages but uses more memory */

#define INTERACTIVE_PROMPT_START "starting picoc\n"
#define INTERACTIVE_PROMPT_STATEMENT "picoc> "
#define INTERACTIVE_PROMPT_LINE "     > "

#define PlatformSetExitPoint() setjmp(ExitBuf)

/* defines for the optional "fdlibm" maths library */
#define _IEEE_LIBM

/* host platform includes */
#ifdef UNIX_HOST
# define HEAP_SIZE (128*1024)               /* space for the heap and the stack */
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <assert.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdarg.h>
# include <setjmp.h>
# ifndef NO_FP
# include <math.h>
# define PICOC_MATH_LIBRARY
# define NEED_MATH_LIBRARY
#endif

extern jmp_buf ExitBuf;

#else
# ifdef FLYINGFOX_HOST
#  define HEAP_SIZE (16*1024)               /* space for the heap and the stack */
#  define NO_HASH_INCLUDE
#  include <stdlib.h>
#  include <ctype.h>
#  include <string.h>
#  include <sys/types.h>
#  include <stdarg.h>
#  include <setjmp.h>
#  include <math.h>
#  define assert(x)
#  undef BIG_ENDIAN
#  undef FANCY_ERROR_REPORTING

# else
#  ifdef SURVEYOR_HOST
#   define NO_FP
#   define NO_CTYPE
#   define NO_HASH_INCLUDE
#   define NO_MODULUS
#   include <cdefBF537.h>
#   include "../string.h"
#   include "../print.h"
#   include "../srv.h"
#   include "../setjmp.h"
#   include "../stdarg.h"
#   include "../colors.h"
#   include "../neural.h"
#   include "../gps.h"
#   include "../i2c.h"
#   include "../jpeg.h"
#   define assert(x)
#   undef INTERACTIVE_PROMPT_STATEMENT
#   undef INTERACTIVE_PROMPT_LINE
#   define INTERACTIVE_PROMPT_STATEMENT "> "
#   define INTERACTIVE_PROMPT_LINE "- "
#   undef BIG_ENDIAN
#  else
#   ifdef UMON_HOST
#    define HEAP_SIZE (128*1024)               /* space for the heap and the stack */
#    define NO_FP
#    include <stdlib.h>
#    include <string.h>
#    include <ctype.h>
#    include <sys/types.h>
#    include <stdarg.h>
#    include <math.h>
#    include "monlib.h"
#    define assert(x)
#    undef PlatformSetExitPoint
#    define PlatformSetExitPoint()
#   endif
#  endif
# endif

extern int ExitBuf[];

#endif

#define math_abs(x) (((x) < 0) ? (-(x)) : (x))
#ifdef NEED_MATH_LIBRARY
extern double math_sin(double x);
extern double math_cos(double x);
extern double math_tan(double x);
extern double math_asin(double x);
extern double math_acos(double x);
extern double math_atan(double x);
extern double math_sinh(double x);
extern double math_cosh(double x);
extern double math_tanh(double x);
extern double math_asinh(double x);
extern double math_acosh(double x);
extern double math_atanh(double x);
extern double math_exp(double x);
extern double math_fabs(double x);
extern double math_log(double x);
extern double math_log10(double x);
extern double math_pow(double x, double y);
extern double math_sqrt(double x);
extern double math_floor(double x);
extern double math_ceil(double x);
#else /* NEED_MATH_LIBRARY */
#define math_sin(x) sin(x)
#define math_cos(x) cos(x)
#define math_tan(x) tan(x)
#define math_asin(x) asin(x)
#define math_acos(x) acos(x)
#define math_atan(x) atan(x)
#define math_sinh(x) sinh(x)
#define math_cosh(x) cosh(x)
#define math_tanh(x) tanh(x)
#define math_asinh(x) asinh(x)
#define math_acosh(x) acosh(x)
#define math_atanh(x) atanh(x)
#define math_exp(x) exp(x)
#define math_fabs(x) fabs(x)
#define math_log(x) log(x)
#define math_log10(x) log10(x)
#define math_pow(x,y) pow(x,y)
#define math_sqrt(x) sqrt(x)
#define math_floor(x) floor(x)
#define math_ceil(x) ceil(x)
#endif /* NEED_MATH_LIBRARY */

#endif /* PLATFORM_H */
