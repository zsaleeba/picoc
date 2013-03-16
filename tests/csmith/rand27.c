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
static unsigned char g_9 = 0xAAL;
static int g_63 = 0x8400B8F3L;
static int *g_62 = &g_63;
static int **g_154 = &g_62;
static int ***g_153 = &g_154;
static int g_232 = 0x812E1121L;
static short func_1(void);
static short func_4(unsigned char p_5, short p_6, signed char p_7, int p_8);
static signed char func_12(unsigned p_13, unsigned short p_14, int p_15);
static unsigned func_20(unsigned char p_21, unsigned char p_22, int p_23, unsigned char p_24);
static unsigned func_25(unsigned short p_26, signed char p_27, unsigned p_28, unsigned p_29);
static unsigned short func_32(unsigned short p_33);
static unsigned short func_38(unsigned short p_39, unsigned p_40, unsigned p_41, int p_42);
static int func_45(int p_46, int p_47, unsigned p_48, unsigned p_49);
static unsigned func_51(short p_52, short p_53);
static short func_56(int p_57, unsigned short p_58);
static short func_1(void)
{
    unsigned char l_16 = 0x7CL;
    int ***l_227 = &g_154;
    unsigned l_228 = 4UL;
    unsigned char l_229 = 0UL;
    short l_230 = 0xDE1BL;
    int *l_231 = &g_232;
    step_hash(113);
    l_229 &= ((0UL && ((((signed char)(func_4(g_9, ((signed char)func_12(g_9, l_16, g_9) * (signed char)g_9), ((((void*)0 != l_227) <= l_16) != l_16), l_228) & g_9) << (signed char)g_9) | 0xADL) >= 0xB327L)) < l_228);
    step_hash(114);
    (*l_231) ^= (((((g_63 >= g_63) & 0x74C3L) >= ((((void*)0 == (*g_154)) >= func_32(func_20(g_63, func_32(g_9), l_230, g_9))) < (-1L))) & (***l_227)) > 9UL);
    step_hash(115);
    return g_232;
}
static short func_4(unsigned char p_5, short p_6, signed char p_7, int p_8)
{
    step_hash(110);
    (*g_154) = (**g_153);
    step_hash(111);
    (***g_153) &= 0xB0F42965L;
    step_hash(112);
    return g_9;
}
static signed char func_12(unsigned p_13, unsigned short p_14, int p_15)
{
    signed char l_17 = 0x6EL;
    int *l_207 = &g_63;
    step_hash(107);
    if (((l_17 < ((int)0x3051EBF0L % (int)func_20((func_25(((unsigned short)func_32(g_9) + (unsigned short)((short)(~((((unsigned char)(func_38(p_15, ((short)g_9 >> (short)(l_17 & 0x1718BC69L)), g_9, l_17) ^ p_13) / (unsigned char)0xA5L) && l_17) <= 0x74ABL)) * (short)0x1B3DL)), l_17, p_13, l_17) < 0x7F559297L), g_9, l_17, p_13))) < p_15))
    {
        int ***l_205 = &g_154;
        int l_206 = 4L;
        step_hash(95);
        (**g_154) = p_14;
        step_hash(96);
        l_206 &= (((short)0L % (short)g_63) != ((void*)0 == l_205));
        step_hash(97);
        l_207 = (**g_153);
        step_hash(98);
        (*l_207) = (p_13 >= ((unsigned short)p_13 + (unsigned short)((*l_207) == ((unsigned short)((int)((short)((unsigned short)(((-1L) && (*l_207)) && 1UL) << (unsigned short)((((unsigned char)((int)(((0x53C7L == 0xA15FL) != ((signed char)0x1AL - (signed char)(***l_205))) && (***l_205)) - (int)0L) * (unsigned char)8L) & 0UL) | g_63)) % (short)p_14) - (int)g_9) / (unsigned short)g_9))));
    }
    else
    {
        int l_224 = 3L;
        int l_225 = 0x5B180E96L;
        step_hash(100);
        l_225 = (l_224 || p_13);
        step_hash(106);
        if (l_224)
        {
            short l_226 = (-1L);
            step_hash(102);
            (*l_207) = l_226;
        }
        else
        {
            step_hash(104);
            (*g_62) = (p_15 & p_15);
            step_hash(105);
            return g_9;
        }
    }
    step_hash(108);
    return (*l_207);
}
static unsigned func_20(unsigned char p_21, unsigned char p_22, int p_23, unsigned char p_24)
{
    int l_98 = 0x56207CCBL;
    step_hash(92);
    for (p_24 = (-10); (p_24 <= 50); p_24 += 9)
    {
        unsigned short l_97 = 4UL;
        int **l_102 = &g_62;
        int ***l_101 = &l_102;
        unsigned short l_141 = 0x77CCL;
        int l_155 = 0x3AF947C6L;
    }
    step_hash(93);
    return l_98;
}
static unsigned func_25(unsigned short p_26, signed char p_27, unsigned p_28, unsigned p_29)
{
    int *l_86 = &g_63;
    int **l_88 = &l_86;
    int ***l_87 = &l_88;
    step_hash(23);
    l_86 = &g_63;
    step_hash(24);
    (*l_87) = &l_86;
    step_hash(25);
    return (*l_86);
}
static unsigned short func_32(unsigned short p_33)
{
    step_hash(3);
    return g_9;
}
static unsigned short func_38(unsigned short p_39, unsigned p_40, unsigned p_41, int p_42)
{
    short l_50 = (-7L);
    unsigned l_61 = 0x4F509E13L;
    int l_82 = 0x75E0AD58L;
    int **l_83 = (void*)0;
    int **l_84 = (void*)0;
    int *l_85 = &g_63;
    step_hash(18);
    l_82 &= func_45(func_32(l_50), l_50, l_50, func_51(p_39, ((signed char)(0x8FC7L <= func_56(g_9, ((g_9 | ((unsigned short)p_41 / (unsigned short)l_61)) < g_9))) / (signed char)(-5L))));
    step_hash(19);
    l_85 = &l_82;
    step_hash(20);
    (*l_85) &= (*g_62);
    step_hash(21);
    return p_39;
}
static int func_45(int p_46, int p_47, unsigned p_48, unsigned p_49)
{
    int **l_76 = &g_62;
    short l_79 = (-2L);
    step_hash(14);
    (*l_76) = &g_63;
    step_hash(15);
    (*l_76) = &g_63;
    step_hash(16);
    (**l_76) = ((signed char)l_79 * (signed char)(+((short)(**l_76) << (short)10)));
    step_hash(17);
    return p_46;
}
static unsigned func_51(short p_52, short p_53)
{
    int *l_65 = (void*)0;
    int l_75 = 0x07F7A796L;
    step_hash(9);
    l_65 = &g_63;
    step_hash(10);
    (*l_65) ^= p_53;
    step_hash(11);
    l_75 &= ((-(signed char)((signed char)((unsigned char)func_32(p_52) + (unsigned char)((((unsigned)0xBA832A49L % (unsigned)0x64ADB5D2L) > ((unsigned short)((&g_63 == l_65) < ((0x2A1DD6B9L <= (*g_62)) ^ func_32(p_52))) % (unsigned short)(*l_65))) & p_53)) << (signed char)g_63)) < (*l_65));
    step_hash(12);
    return g_63;
}
static short func_56(int p_57, unsigned short p_58)
{
    int **l_64 = &g_62;
    step_hash(6);
    (*l_64) = g_62;
    step_hash(7);
    return g_63;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_9, "g_9", print_hash_value);
    transparent_crc(g_63, "g_63", print_hash_value);
    transparent_crc(g_232, "g_232", print_hash_value);
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
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    csmith_compute_hash();
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
