#include <stdio.h>

typedef char    int8_t;
typedef short   int16_t;
typedef int     int32_t;
typedef long    int64_t;

typedef unsigned char   uint8_t;
typedef unsigned short  uint16_t;
typedef unsigned int    uint32_t;
typedef unsigned long   uint64_t;

typedef struct _point
{
    int x;
    int y;
} point;


void main()
{
    int8_t  x8  = 0xFEDCBA98;
    int16_t x16 = 0xFEDCBA98;
    int32_t x32 = 0xFEDCBA98;
    int64_t x64 = 0xFFFFFEDCBA98FFFF;

    uint8_t  u8  = 0xFEDCBA98;
    uint16_t u16 = 0xFEDCBA98;
    uint32_t u32 = 0xFEDCBA98;
    uint64_t u64 = 0xFEDCBA98FFFF;

    char* y = (char*) &x32;
    
    printf("%d<%ld>\n", x8, sizeof(x8));
    printf("%d<%ld>\n", x16, sizeof(x16));
    printf("%d<%ld>\n", x32, sizeof(x32));
    printf("%ld<%ld>\n", x64, sizeof(x64));
    

    printf("%u<%ld>\n", u8, sizeof(x8));
    printf("%u<%ld>\n", u16, sizeof(x16));
    printf("%u<%ld>\n", u32, sizeof(x32));
    printf("%lu<%ld>\n", u64, sizeof(x64));

    printf("%d\n", *(int32_t*)y);
    
    point pt;
    pt.x = 1;
    pt.y = 2;
    
    point pts[2];
    pts[0] = pt;
    pts[1] = pt;
    
    pt.y = 3;
    
    point* ptp = (point*) &pts[0];

    printf("(%d, %d)\n", pt.x, pt.y);
    printf("(%d, %d)\n", ptp->x, ptp->y);
}
