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
static int g_2 = 0L;
static int g_5[6][7] = {{0x19AC196AL, 7L, 0xA12B57E8L, 7L, 0x19AC196AL, 7L, 0xA12B57E8L}, {0x19AC196AL, 7L, 0xA12B57E8L, 7L, 0x19AC196AL, 7L, 0xA12B57E8L}, {0x19AC196AL, 7L, 0xA12B57E8L, 7L, 0x19AC196AL, 7L, 0xA12B57E8L}, {0x19AC196AL, 7L, 0xA12B57E8L, 7L, 0x19AC196AL, 7L, 0xA12B57E8L}, {0x19AC196AL, 7L, 0xA12B57E8L, 7L, 0x19AC196AL, 7L, 0xA12B57E8L}, {0x19AC196AL, 7L, 0xA12B57E8L, 7L, 0x19AC196AL, 7L, 0xA12B57E8L}};
static int g_11 = 0xF0B101AAL;
static unsigned short func_1(void);
static unsigned short func_1(void)
{
    signed char l_12 = 0x33L;
    step_hash(9);
    for (g_2 = 16; (g_2 <= (-11)); g_2--)
    {
        step_hash(8);
        for (g_5[0][1] = 0; (g_5[0][1] == 18); g_5[0][1] += 4)
        {
            int *l_10 = &g_11;
            step_hash(7);
            (*l_10) = ((signed char)g_5[0][1] << (signed char)7);
        }
    }
    step_hash(10);
    return l_12;
}
void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_2, "g_2", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            transparent_crc(g_5[i][j], "g_5[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);
        }
    }
    transparent_crc(g_11, "g_11", print_hash_value);
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
