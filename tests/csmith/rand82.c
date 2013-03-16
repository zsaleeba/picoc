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
static int g_2 = 0x4FD3DF75L;
static int g_8 = (-1L);
static int *g_7 = &g_8;
static int g_76[6] = {(-1L), (-1L), (-2L), (-1L), (-1L), (-2L)};
static int g_85 = 0x669DD8B1L;
static unsigned short g_99 = 0xCCADL;
static short g_117 = 0x49DBL;
static int g_157 = 0x5C058660L;
static unsigned short g_163 = 0UL;
static signed char g_181 = 0xD2L;
static short g_188 = 0x93E9L;
static int *g_226 = (void*)0;
static int func_1(void);
static int * func_9(unsigned char p_10, unsigned p_11);
static unsigned short func_25(short p_26);
static short func_29(unsigned char p_30);
static unsigned char func_37(unsigned p_38, unsigned short p_39, unsigned char p_40, int * p_41, unsigned p_42);
static int func_43(short p_44, int * p_45, unsigned char p_46, signed char p_47);
static int func_48(int ** p_49, unsigned p_50, signed char p_51);
static int ** func_52(unsigned p_53, signed char p_54, unsigned char p_55);
static signed char func_57(int p_58, unsigned p_59, unsigned short p_60, int p_61, signed char p_62);
static unsigned func_63(int p_64);
static int func_1(void)
{
    int *l_14[3];
    int l_223 = 9L;
    int i;
    for (i = 0; i < 3; i++)
        l_14[i] = &g_2;
    step_hash(95);
    for (g_2 = 0; (g_2 == 2); ++g_2)
    {
        int *l_6[7][1] = {{&g_2}, {&g_2}, {&g_2}, {&g_2}, {&g_2}, {&g_2}, {&g_2}};
        int **l_5[6] = {&l_6[2][0], &l_6[6][0], &l_6[2][0], &l_6[6][0], &l_6[2][0], &l_6[6][0]};
        int i, j;
        step_hash(4);
        g_7 = &g_2;
        step_hash(94);
        g_226 = func_9(g_8, ((signed char)((((void*)0 != l_14[2]) < (((((0x7A8CL & (((signed char)((short)(((unsigned char)g_8 << (unsigned char)(1L <= ((signed char)1L << (signed char)((unsigned short)func_25(g_2) % (unsigned short)g_8)))) <= (-7L)) << (short)g_2) >> (signed char)g_8) && g_117)) <= g_8) & g_157) & g_157) > g_2)) | g_2) - (signed char)l_223));
    }
    step_hash(96);
    return g_76[5];
}
static int * func_9(unsigned char p_10, unsigned p_11)
{
    int *l_224 = (void*)0;
    int *l_225[5] = {&g_8, &g_76[5], &g_8, &g_76[5], &g_8};
    int i;
    step_hash(92);
    g_85 &= 0L;
    step_hash(93);
    return l_224;
}
static unsigned short func_25(short p_26)
{
    unsigned char l_31 = 0xEDL;
    int *l_198 = &g_2;
    unsigned l_199 = 0xAB6FC985L;
    int l_207[9];
    int ***l_213 = (void*)0;
    int l_217 = 0xCD1AA114L;
    int i;
    for (i = 0; i < 9; i++)
        l_207[i] = 0L;
    step_hash(89);
    if (((unsigned short)(p_26 & func_29(l_31)) << (unsigned short)((signed char)0xC9L * (signed char)(p_26 && (((unsigned)(~(g_188 > func_57(g_188, g_8, (l_198 == &g_8), p_26, l_199))) + (unsigned)(*l_198)) & g_157)))))
    {
        int *l_200 = (void*)0;
        int *l_201 = &g_76[4];
        int **l_202 = (void*)0;
        int **l_203 = &l_200;
        step_hash(70);
        (*l_201) &= (&g_8 != l_198);
        step_hash(71);
        (*l_203) = l_201;
    }
    else
    {
        int **l_204[8][4] = {{&l_198, &g_7, (void*)0, (void*)0}, {&l_198, &g_7, (void*)0, (void*)0}, {&l_198, &g_7, (void*)0, (void*)0}, {&l_198, &g_7, (void*)0, (void*)0}, {&l_198, &g_7, (void*)0, (void*)0}, {&l_198, &g_7, (void*)0, (void*)0}, {&l_198, &g_7, (void*)0, (void*)0}, {&l_198, &g_7, (void*)0, (void*)0}};
        int ***l_205 = (void*)0;
        int ***l_206 = &l_204[0][3];
        int i, j;
        step_hash(73);
        (*l_206) = l_204[6][1];
        step_hash(88);
        if (p_26)
        {
            unsigned char l_208 = 0x8BL;
            step_hash(75);
            l_207[4] = 0xCB467415L;
            step_hash(76);
            return l_208;
        }
        else
        {
            int ***l_214[2][5] = {{&l_204[1][0], &l_204[5][0], &l_204[1][0], &l_204[5][0], &l_204[1][0]}, {&l_204[1][0], &l_204[5][0], &l_204[1][0], &l_204[5][0], &l_204[1][0]}};
            int i, j;
            step_hash(78);
            g_76[5] ^= ((((unsigned char)((p_26 != ((void*)0 == &g_85)) != (0x37L <= p_26)) % (unsigned char)g_181) != 2UL) ^ (func_57((p_26 == ((signed char)(l_213 != l_214[1][3]) * (signed char)g_2)), g_85, p_26, (*l_198), g_117) || p_26));
            step_hash(85);
            if (p_26)
            {
                step_hash(80);
                for (l_31 = 0; l_31 < 2; l_31 += 1)
                {
                    for (g_188 = 0; g_188 < 5; g_188 += 1)
                    {
                        l_214[l_31][g_188] = &l_204[6][1];
                    }
                }
            }
            else
            {
                unsigned l_218 = 4294967293UL;
                step_hash(82);
                l_207[4] = ((-3L) <= 3UL);
                step_hash(83);
                g_85 = ((short)(l_217 != 7L) << (short)2);
                step_hash(84);
                --l_218;
            }
            step_hash(86);
            g_76[5] ^= ((unsigned short)g_85 / (unsigned short)65535UL);
            step_hash(87);
            g_76[5] = 0x3612B42AL;
        }
    }
    step_hash(90);
    return g_163;
}
static short func_29(unsigned char p_30)
{
    short l_36 = (-10L);
    int *l_100 = &g_2;
    int *l_104[7][5] = {{&g_76[3], &g_85, &g_76[3], &g_85, (void*)0}, {&g_76[3], &g_85, &g_76[3], &g_85, (void*)0}, {&g_76[3], &g_85, &g_76[3], &g_85, (void*)0}, {&g_76[3], &g_85, &g_76[3], &g_85, (void*)0}, {&g_76[3], &g_85, &g_76[3], &g_85, (void*)0}, {&g_76[3], &g_85, &g_76[3], &g_85, (void*)0}, {&g_76[3], &g_85, &g_76[3], &g_85, (void*)0}};
    int **l_193 = &g_7;
    int i, j;
    step_hash(25);
    g_76[5] = ((signed char)(((unsigned short)((((l_36 || g_8) & func_37(g_8, (func_43(p_30, &g_8, p_30, g_8) & (~p_30)), g_8, l_100, p_30)) ^ g_8) >= (*l_100)) + (unsigned short)p_30) && 0x2BBAL) % (signed char)g_8);
    step_hash(66);
    for (g_85 = 5; (g_85 >= 0); g_85 -= 1)
    {
        signed char l_108 = (-5L);
        int **l_116[10][4] = {{&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}, {&g_7, &l_104[1][0], &g_7, (void*)0}};
        int i, j;
        step_hash(64);
        for (l_36 = 5; (l_36 >= 0); l_36 -= 1)
        {
            int **l_105 = &l_104[1][0];
            int *l_142 = &g_76[5];
            int l_151[2];
            int l_161 = 0xAF25848BL;
            signed char l_186 = 0x43L;
            int l_187 = 0x6A6B90CAL;
            int l_189 = 0xB6B8FFD3L;
            int i;
            for (i = 0; i < 2; i++)
                l_151[i] = 0x385244D6L;
            step_hash(32);
            g_7 = &g_76[l_36];
            step_hash(62);
            if (((void*)0 != l_105))
            {
                unsigned short l_109 = 65530UL;
                int **l_129 = &l_104[1][0];
                int l_148[1][1];
                int l_154 = 9L;
                int i, j;
                for (i = 0; i < 1; i++)
                {
                    for (j = 0; j < 1; j++)
                        l_148[i][j] = (-9L);
                }
                step_hash(34);
                (*g_7) = p_30;
                step_hash(40);
                for (p_30 = 11; (p_30 == 34); ++p_30)
                {
                    step_hash(38);
                    l_109--;
                    step_hash(39);
                    g_117 |= ((unsigned short)((short)g_76[4] - (short)g_8) << (unsigned short)(l_116[1][1] != (void*)0));
                }
                step_hash(59);
                if (((unsigned char)((l_109 > g_2) & ((unsigned short)g_85 * (unsigned short)(&g_7 != (void*)0))) << (unsigned char)7))
                {
                    unsigned l_122 = 3UL;
                    int *l_141 = &g_85;
                    int l_150 = 0x1963C95DL;
                    int l_152 = 0L;
                    int l_155 = 0x9DC75A76L;
                    int l_156 = 0x4C5E673EL;
                    int l_158 = (-1L);
                    int l_159 = 7L;
                    int l_160 = 0x2510918FL;
                    int l_162 = 0x54D3D32AL;
                    step_hash(42);
                    --l_122;
                    step_hash(49);
                    if (((unsigned char)func_63(l_122) + (unsigned char)p_30))
                    {
                        unsigned l_132 = 0xF18C2A7CL;
                        step_hash(44);
                        (*g_7) = ((unsigned short)(((void*)0 != l_129) >= ((int)l_132 - (int)(((g_117 == p_30) <= (((short)((int)func_57(p_30, ((short)((signed char)p_30 >> (signed char)3) << (short)11), g_85, p_30, p_30) - (int)g_85) / (short)g_99) > g_8)) >= g_85))) % (unsigned short)p_30);
                    }
                    else
                    {
                        unsigned l_145[2][5];
                        int l_149 = 0x3CA084A1L;
                        int l_153[5];
                        int i, j;
                        for (i = 0; i < 2; i++)
                        {
                            for (j = 0; j < 5; j++)
                                l_145[i][j] = 0x7E6CEEB8L;
                        }
                        for (i = 0; i < 5; i++)
                            l_153[i] = 0x5DACF7CCL;
                        step_hash(46);
                        l_142 = l_141;
                        step_hash(47);
                        l_148[0][0] = ((((l_141 != (*l_105)) | func_57(p_30, ((unsigned char)(l_145[1][0] > l_145[1][0]) >> (unsigned char)0), l_145[0][2], (*g_7), (g_99 >= ((signed char)func_57(func_57(((*l_141) >= g_117), p_30, g_85, (*g_7), p_30), g_99, g_76[0], (*g_7), p_30) * (signed char)0x41L)))) & g_117) < g_85);
                        step_hash(48);
                        ++g_163;
                    }
                }
                else
                {
                    unsigned short l_180 = 65535UL;
                    int l_182 = 0x0DCFB84FL;
                    int l_183 = 1L;
                    int l_184 = (-1L);
                    int l_185[6] = {0L, 0L, (-8L), 0L, 0L, (-8L)};
                    unsigned l_190 = 0x6423F066L;
                    int i;
                    step_hash(56);
                    for (l_109 = 0; (l_109 >= 42); l_109 += 4)
                    {
                        int l_168 = 0x6BEFEFA7L;
                        step_hash(54);
                        (*g_7) = (*g_7);
                        step_hash(55);
                        g_181 &= (((*g_7) != (l_168 > (*g_7))) | (((unsigned char)((func_57((((short)(p_30 && ((unsigned)(p_30 == ((short)((((g_117 || g_99) | ((unsigned char)(l_168 != (-(unsigned)((65535UL < g_99) | 4UL))) + (unsigned char)1L)) <= p_30) && (-1L)) / (short)g_163)) + (unsigned)(*l_142))) / (short)p_30) || p_30), g_8, g_85, (*g_7), p_30) == p_30) < l_180) / (unsigned char)p_30) == l_180));
                    }
                    step_hash(57);
                    if ((*g_7))
                        continue;
                    step_hash(58);
                    l_190--;
                }
            }
            else
            {
                step_hash(61);
                return g_76[3];
            }
            step_hash(63);
            if (p_30)
                break;
        }
        step_hash(65);
        return g_157;
    }
    step_hash(67);
    (*l_193) = (void*)0;
    step_hash(68);
    return p_30;
}







static unsigned char func_37(unsigned p_38, unsigned short p_39, unsigned char p_40, int * p_41, unsigned p_42)
{
    int **l_101 = (void*)0;
    int **l_102 = &g_7;
    int l_103 = 0x61520CADL;
    step_hash(23);
    (*l_102) = &g_76[5];
    step_hash(24);
    return l_103;
}







static int func_43(short p_44, int * p_45, unsigned char p_46, signed char p_47)
{
    unsigned l_56 = 3UL;
    int *l_98 = (void*)0;
    step_hash(20);
    g_99 |= func_48(func_52((l_56 < (func_57(l_56, func_63(((unsigned short)(((((l_56 < ((signed char)((signed char)(((unsigned short)(l_56 | (p_46 <= p_47)) * (unsigned short)p_46) | ((void*)0 != p_45)) >> (signed char)6) >> (signed char)l_56)) && p_47) || l_56) | g_8) | l_56) / (unsigned short)p_47)), l_56, l_56, g_2) != 3L)), l_56, g_8), p_46, l_56);
    step_hash(21);
    return (*g_7);
}







static int func_48(int ** p_49, unsigned p_50, signed char p_51)
{
    unsigned short l_97 = 4UL;
    step_hash(18);
    g_76[5] = (~(**p_49));
    step_hash(19);
    return l_97;
}







static int ** func_52(unsigned p_53, signed char p_54, unsigned char p_55)
{
    int *l_81 = (void*)0;
    int *l_84 = &g_85;
    int *l_86 = &g_76[3];
    int *l_87 = &g_85;
    int l_88 = 0x2EA6DA23L;
    int *l_89 = &g_76[1];
    int *l_90 = &g_76[5];
    int *l_91 = (void*)0;
    int *l_92[7];
    int l_93 = (-1L);
    unsigned l_94[3][3] = {{0UL, 0UL, 0x97F7BC9CL}, {0UL, 0UL, 0x97F7BC9CL}, {0UL, 0UL, 0x97F7BC9CL}};
    int i, j;
    for (i = 0; i < 7; i++)
        l_92[i] = &l_88;
    step_hash(14);
    (*l_84) |= func_57((*g_7), ((func_63(((&g_76[3] == (void*)0) ^ (g_2 >= (0x25L | ((unsigned char)((((void*)0 != l_81) ^ (((short)(g_2 == g_76[4]) << (short)10) ^ p_54)) >= p_54) % (unsigned char)g_76[1]))))) && 0x03A8461AL) | 1L), g_8, p_53, p_53);
    step_hash(15);
    l_94[1][1]++;
    step_hash(16);
    return &g_7;
}







static signed char func_57(int p_58, unsigned p_59, unsigned short p_60, int p_61, signed char p_62)
{
    step_hash(12);
    return p_58;
}







static unsigned func_63(int p_64)
{
    int *l_75[9] = {(void*)0, (void*)0, &g_76[5], (void*)0, (void*)0, &g_76[5], (void*)0, (void*)0, &g_76[5]};
    int i;
    step_hash(9);
    g_76[2] ^= ((p_64 & g_2) && (0x6E9B1CC8L ^ 8UL));
    step_hash(10);
    return g_8;
}


void csmith_compute_hash(void)
{
    int i;
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_8, "g_8", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_76[i], "g_76[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_85, "g_85", print_hash_value);
    transparent_crc(g_99, "g_99", print_hash_value);
    transparent_crc(g_117, "g_117", print_hash_value);
    transparent_crc(g_157, "g_157", print_hash_value);
    transparent_crc(g_163, "g_163", print_hash_value);
    transparent_crc(g_181, "g_181", print_hash_value);
    transparent_crc(g_188, "g_188", print_hash_value);
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
    int i;
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    csmith_compute_hash();
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
