#include <stdio.h>
int print_hash_value = 1;
static void platform_main_begin(void)
{
}
static unsigned crc32_tab[256];
static unsigned crc32_context = 0xFFFFFFFFUL;
static void
crc32_gentab (void)
{
 unsigned crc;
 unsigned poly = 0xEDB88320UL;
 int i, j;
 for (i = 0; i < 256; i++) {
  crc = i;
  for (j = 8; j > 0; j--) {
   if (crc & 1) {
    crc = (crc >> 1) ^ poly;
   } else {
    crc >>= 1;
   }
  }
  crc32_tab[i] = crc;
 }
}
static void
crc32_byte (unsigned char b) {
 crc32_context =
  ((crc32_context >> 8) & 0x00FFFFFF) ^
  crc32_tab[(crc32_context ^ b) & 0xFF];
}
extern int strcmp ( char *, char *);
static void
crc32_8bytes (unsigned val)
{
 crc32_byte ((val>>0) & 0xff);
 crc32_byte ((val>>8) & 0xff);
 crc32_byte ((val>>16) & 0xff);
 crc32_byte ((val>>24) & 0xff);
}
static void
transparent_crc (unsigned val, char* vname, int flag)
{
 crc32_8bytes(val);
 if (flag) {
    printf("...checksum after hashing %s : %X\n", vname, crc32_context ^ 0xFFFFFFFFU);
 }
}
static void
platform_main_end (int x, int flag)
{
  if (!flag) printf ("checksum = %x\n", x);
}
static long __undefined;
void csmith_compute_hash(void);
void step_hash(int stmt_id);
static int g_3[10][3] = {{0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}, {0xFD5464B5L, 0L, 0xFD5464B5L}};
static unsigned g_7[3] = {1UL, 1UL, 1UL};
static int func_1(void);
static int func_1(void)
{
    int *l_2 = &g_3[4][2];
    int *l_4 = &g_3[4][2];
    int *l_5[6][6] = {{&g_3[8][1], &g_3[4][2], &g_3[0][1], &g_3[9][1], (void*)0, &g_3[9][1]}, {&g_3[8][1], &g_3[4][2], &g_3[0][1], &g_3[9][1], (void*)0, &g_3[9][1]}, {&g_3[8][1], &g_3[4][2], &g_3[0][1], &g_3[9][1], (void*)0, &g_3[9][1]}, {&g_3[8][1], &g_3[4][2], &g_3[0][1], &g_3[9][1], (void*)0, &g_3[9][1]}, {&g_3[8][1], &g_3[4][2], &g_3[0][1], &g_3[9][1], (void*)0, &g_3[9][1]}, {&g_3[8][1], &g_3[4][2], &g_3[0][1], &g_3[9][1], (void*)0, &g_3[9][1]}};
    int l_6 = 0x2B013A58L;
    int i, j;
    step_hash(1);
    g_7[1]++;
    step_hash(2);
    return (*l_4);
}
void csmith_compute_hash(void)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_3[i][j], "g_3[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_7[i], "g_7[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
}
void step_hash(int stmt_id)
{
    int i = 0;
    csmith_compute_hash();
    printf("before stmt(%d): checksum = %X\n", stmt_id, crc32_context ^ 0xFFFFFFFFUL);
    crc32_context = 0xFFFFFFFFUL;
    for (i = 0; i < 256; i++) {
        crc32_tab[i] = 0;
    }
    crc32_gentab();
}
int main (void)
{
    int i, j;
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    csmith_compute_hash();
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
