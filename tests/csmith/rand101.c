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
static int g_2[1] = {0x97F6AF11L};
static int g_7 = 0x12491E29L;
static int *g_64 = &g_7;
static int **g_63 = &g_64;
static signed char g_77 = 0xD6L;
static unsigned g_78 = 2UL;
static int g_82 = 1L;
static unsigned g_83 = 0x328171C6L;
static unsigned g_121 = 4294967295UL;
static unsigned g_162 = 0x363A23D7L;
static signed char g_232 = (-10L);
static unsigned g_234 = 6UL;
static int g_237 = 0xABEF08A7L;
static unsigned short g_238 = 1UL;
static unsigned g_250 = 0xD3086A74L;
static unsigned g_269 = 4294967295UL;
static unsigned g_274 = 0x8970AAFFL;
static short g_289[7] = {1L, 1L, 0L, 1L, 1L, 0L, 1L};
static unsigned char g_293 = 0x28L;
static short g_315 = 0xF8D8L;
static unsigned char g_369 = 1UL;
static unsigned short g_375 = 0UL;
static int g_378 = 0L;
static unsigned short g_379 = 65535UL;
static int g_386[8] = {5L, 0x05298B28L, 5L, 0x05298B28L, 5L, 0x05298B28L, 5L, 0x05298B28L};
static unsigned g_387[8][4] = {{0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL}, {0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL}, {0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL}, {0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL}, {0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL}, {0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL}, {0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL}, {0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL, 0x4127F8BDL}};
static int g_401 = 0x3580D728L;
static signed char g_448 = (-1L);
static unsigned g_452[4] = {0UL, 4294967289UL, 0UL, 4294967289UL};
static short g_498[9][10] = {{(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}, {(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}, {(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}, {(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}, {(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}, {(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}, {(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}, {(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}, {(-4L), (-1L), 0x592FL, 1L, 0x04E0L, (-6L), 0x548BL, 5L, (-1L), (-1L)}};
static int g_499 = 0xF89BA971L;
static unsigned short g_500 = 0x398AL;
static int *g_518 = (void*)0;
static int **g_517[5] = {(void*)0, &g_518, (void*)0, &g_518, (void*)0};
static int ***g_516 = &g_517[3];
static int g_520 = 0x2BF3D018L;
static unsigned short func_1(void);
static short func_14(unsigned short p_15);
static unsigned char func_19(short p_20, signed char p_21, unsigned char p_22);
static int * func_25(int p_26, unsigned short p_27);
static unsigned short func_38(int p_39, unsigned p_40, int * p_41);
static unsigned short func_43(int * p_44, unsigned char p_45, unsigned char p_46, int * p_47, int * p_48);
static int * func_49(unsigned char p_50, unsigned p_51, int * p_52, int * p_53);
static unsigned func_70(int * p_71);
static unsigned short func_88(int * p_89, short p_90, unsigned short p_91);
static int * func_92(unsigned p_93, unsigned short p_94, int p_95, int *** p_96, int ** p_97);
static unsigned short func_1(void)
{
    signed char l_5 = 0xDDL;
    step_hash(284);
    for (g_2[0] = 3; (g_2[0] < 2); --g_2[0])
    {
        int *l_6 = &g_7;
        int *l_519 = &g_520;
        step_hash(4);
        (*l_6) = (l_5 < l_5);
        step_hash(5);
        g_7 = 0x49C9FB37L;
        step_hash(283);
        (*l_519) |= (g_2[0] >= (((((l_5 && (&g_7 != &g_7)) < ((short)((short)(((short)func_14(((void*)0 != l_6)) + (short)(((signed char)(((void*)0 != g_516) < (-4L)) + (signed char)g_2[0]) ^ g_448)) || l_5) >> (short)l_5) + (short)1L)) || g_500) & g_386[2]) == g_386[6]));
    }
    step_hash(285);
    return l_5;
}
static short func_14(unsigned short p_15)
{
    unsigned l_16[6][2] = {{4294967287UL, 4294967287UL}, {4294967287UL, 4294967287UL}, {4294967287UL, 4294967287UL}, {4294967287UL, 4294967287UL}, {4294967287UL, 4294967287UL}, {4294967287UL, 4294967287UL}};
    int l_23 = 0xE607D19FL;
    int *l_512 = (void*)0;
    int *l_513[9][6] = {{(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}, {(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}, {(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}, {(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}, {(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}, {(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}, {(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}, {(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}, {(void*)0, &g_2[0], &g_82, &g_82, &g_2[0], (void*)0}};
    int i, j;
    step_hash(7);
    for (g_7 = 0; g_7 < 6; g_7 += 1)
    {
        for (p_15 = 0; p_15 < 2; p_15 += 1)
        {
            l_16[g_7][p_15] = 0x8D8EF068L;
        }
    }
    step_hash(280);
    l_23 = ((unsigned char)func_19(l_23, g_2[0], l_23) << (unsigned char)g_499);
    step_hash(281);
    g_7 ^= ((short)(p_15 < (((unsigned short)l_23 - (unsigned short)(g_2[0] || g_448)) > (p_15 && p_15))) * (short)(p_15 >= ((int)((p_15 >= (((short)((l_16[1][1] ^ 4294967295UL) == p_15) + (short)l_23) == l_16[4][0])) < (-4L)) / (int)g_379)));
    step_hash(282);
    return g_121;
}
static unsigned char func_19(short p_20, signed char p_21, unsigned char p_22)
{
    int *l_24 = &g_7;
    int *l_28 = &g_7;
    int **l_503 = &g_64;
    step_hash(9);
    (*l_24) |= (8UL == (p_22 >= 0xFBFCC013L));
    step_hash(278);
    (*l_503) = func_25((l_28 == l_24), p_21);
    step_hash(279);
    return p_22;
}
static int * func_25(int p_26, unsigned short p_27)
{
    short l_35 = 9L;
    int *l_42[2];
    signed char l_65 = 0L;
    int *l_106[2];
    unsigned char l_167 = 9UL;
    int ***l_183[9] = {&g_63, &g_63, &g_63, &g_63, &g_63, &g_63, &g_63, &g_63, &g_63};
    unsigned short l_196 = 0x9717L;
    int *l_199 = (void*)0;
    int **l_203 = &g_64;
    int ***l_202 = &l_203;
    unsigned l_204 = 4294967295UL;
    unsigned short l_241[6];
    unsigned short l_287 = 65532UL;
    int l_348 = 8L;
    int **l_382 = &l_106[1];
    unsigned char l_425 = 0x29L;
    int *l_491 = &g_2[0];
    int i;
    for (i = 0; i < 2; i++)
        l_42[i] = &g_2[0];
    for (i = 0; i < 2; i++)
        l_106[i] = &g_2[0];
    for (i = 0; i < 6; i++)
        l_241[i] = 0xCC2EL;
    step_hash(223);
    if (((signed char)0x9EL >> (signed char)((unsigned short)((((signed char)1L / (signed char)(65535UL | l_35)) || ((unsigned short)(&g_2[0] != (void*)0) * (unsigned short)func_38((((void*)0 != l_42[0]) != func_43(func_49(((int)((short)((unsigned char)p_26 / (unsigned char)g_2[0]) * (short)p_27) + (int)g_2[0]), p_26, l_42[0], l_42[0]), g_7, l_65, l_42[0], l_42[1])), g_77, l_106[1]))) ^ p_27) << (unsigned short)p_26)))
    {
        int *l_152[9] = {&g_2[0], &g_7, &g_2[0], &g_7, &g_2[0], &g_7, &g_2[0], &g_7, &g_2[0]};
        unsigned l_184 = 0xE0279960L;
        int l_197 = (-10L);
        int ***l_198[2][2];
        int i, j;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 2; j++)
                l_198[i][j] = &g_63;
        }
        step_hash(103);
        for (g_121 = 0; (g_121 <= 1); g_121 += 1)
        {
            int l_158 = 0xCA579871L;
            int ***l_188 = &g_63;
            int ***l_209[3][4] = {{&l_203, &l_203, (void*)0, &l_203}, {&l_203, &l_203, (void*)0, &l_203}, {&l_203, &l_203, (void*)0, &l_203}};
            int l_216 = 0x0D2993C0L;
            int i, j;
            step_hash(57);
            g_82 |= (-4L);
            step_hash(100);
            for (p_27 = 0; (p_27 <= 1); p_27 += 1)
            {
                unsigned l_151[9][8] = {{0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}, {0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}, {0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}, {0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}, {0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}, {0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}, {0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}, {0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}, {0x39DC62CBL, 1UL, 0xE9327043L, 9UL, 9UL, 0xE9327043L, 1UL, 0x39DC62CBL}};
                int l_157 = 0x31699C01L;
                int l_160[3];
                signed char l_201 = 0xD0L;
                int ***l_227[10][5] = {{&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}, {&g_63, &g_63, &g_63, &l_203, &g_63}};
                int i, j;
                for (i = 0; i < 3; i++)
                    l_160[i] = 0x758F72B2L;
                step_hash(61);
                g_82 &= ((unsigned)((unsigned char)(0xDBL >= g_78) + (unsigned char)(((l_151[5][7] && (g_2[0] < (l_106[p_27] == l_152[2]))) == (((unsigned short)((unsigned char)g_78 + (unsigned char)p_27) >> (unsigned short)14) & p_26)) <= g_2[0])) - (unsigned)l_157);
                step_hash(91);
                if ((g_78 && p_27))
                {
                    int l_159 = 1L;
                    int l_161 = 0L;
                    int *l_170 = &l_160[1];
                    int **l_171 = &l_170;
                    step_hash(63);
                    --g_162;
                    step_hash(64);
                    (*l_171) = func_49((((signed char)0xF4L % (signed char)g_7) & (!l_167)), p_27, func_49(l_159, ((!((unsigned short)(func_88(l_170, (*l_170), p_27) <= (*l_170)) * (unsigned short)g_121)) > 249UL), l_170, l_42[0]), &l_160[0]);
                    step_hash(65);
                    (*l_170) = (-1L);
                    step_hash(74);
                    if ((p_26 >= (func_88(&l_160[1], (*l_170), g_2[0]) != func_88(&g_7, g_77, g_162))))
                    {
                        step_hash(67);
                        (**l_171) &= 0x44FC8F34L;
                        step_hash(68);
                        if (p_26)
                            break;
                    }
                    else
                    {
                        short l_176 = 0x2F43L;
                        int l_185 = 0x42C4FA89L;
                        int ***l_191 = &g_63;
                        step_hash(70);
                        l_176 = ((unsigned char)0x54L - (unsigned char)((unsigned short)p_26 << (unsigned short)9));
                        step_hash(71);
                        l_185 &= ((unsigned)func_43(func_49((((((p_27 && (l_176 >= 0x482281F5L)) == 0x0C0EL) >= (&g_82 == (void*)0)) < ((((int)((&l_42[g_121] != (void*)0) < ((void*)0 == l_183[4])) + (int)p_26) != l_184) ^ l_176)) >= g_78), l_176, &l_160[1], (*l_171)), g_162, (**l_171), &g_2[0], &g_2[0]) - (unsigned)0UL);
                        step_hash(72);
                        g_82 &= (p_27 ^ ((unsigned)g_7 + (unsigned)(l_183[6] == l_188)));
                        step_hash(73);
                        l_197 |= (((int)((l_191 != &l_171) > (!(((((p_27 | g_7) | 0L) | p_26) <= (1L > ((short)p_27 << (short)((((unsigned short)(((void*)0 != (*l_171)) == 0UL) + (unsigned short)l_196) <= g_77) > 1UL)))) | p_27))) + (int)g_162) ^ 4294967290UL);
                    }
                }
                else
                {
                    unsigned short l_229 = 6UL;
                    int *l_230[3][3] = {{&l_216, &l_216, &l_216}, {&l_216, &l_216, &l_216}, {&l_216, &l_216, &l_216}};
                    int i, j;
                    step_hash(83);
                    if ((func_43(func_49(p_26, (l_198[0][1] == l_183[8]), &l_158, l_199), (func_70(func_92(g_2[0], (-(signed char)0x63L), (((g_7 || p_26) >= g_77) && l_201), l_202, &g_64)) < 0xCA3EL), l_204, &g_2[0], &g_2[0]) | p_27))
                    {
                        int **l_228 = &l_106[1];
                        step_hash(77);
                        (*l_203) = func_49(((signed char)(((unsigned)(&g_64 == &l_106[p_27]) % (unsigned)(p_27 & 1UL)) || (&g_63 == l_209[2][1])) * (signed char)((unsigned short)(+((p_26 ^ (g_121 & ((unsigned)((unsigned short)p_27 * (unsigned short)(-5L)) + (unsigned)0L))) <= 0xD09CL)) << (unsigned short)p_27)), l_216, &g_82, &g_82);
                        step_hash(78);
                        g_82 &= func_88(func_92(p_26, ((unsigned short)(((unsigned short)1UL >> (unsigned short)8) & g_121) << (unsigned short)(((((unsigned short)(g_2[0] >= ((signed char)g_121 / (signed char)p_27)) - (unsigned short)4L) | ((unsigned char)func_70(&g_7) << (unsigned char)p_27)) <= 0xD5EEL) | 255UL)), g_77, l_227[9][1], l_228), g_162, g_121);
                        step_hash(79);
                        (*l_228) = &g_2[0];
                        step_hash(80);
                        (*g_64) = l_229;
                    }
                    else
                    {
                        int *l_231 = &l_197;
                        step_hash(82);
                        return &g_82;
                    }
                    step_hash(90);
                    for (l_197 = 5; (l_197 >= 0); l_197 -= 1)
                    {
                        int l_233 = (-1L);
                        step_hash(87);
                        l_230[2][2] = l_230[2][2];
                        step_hash(88);
                        g_234++;
                        step_hash(89);
                        ++g_238;
                    }
                }
                step_hash(92);
                if (l_241[0])
                    break;
                step_hash(99);
                for (l_65 = 0; (l_65 < 21); l_65 += 1)
                {
                    signed char l_246 = (-9L);
                    int l_247 = 0xC9AB741BL;
                    int l_248 = 0x42A48A9BL;
                    int l_249 = (-8L);
                    step_hash(96);
                    g_82 &= ((unsigned short)func_70(func_92(g_78, (4294967295UL | 0x9E74196FL), p_27, l_227[5][0], (*l_188))) * (unsigned short)g_77);
                    step_hash(97);
                    --g_250;
                    step_hash(98);
                    (*g_64) = (((((unsigned char)((short)func_70((*l_203)) >> (short)12) * (unsigned char)(p_26 & g_77)) & p_26) <= 4UL) && p_27);
                }
            }
            step_hash(101);
            g_82 &= (l_198[0][1] != l_209[1][3]);
            step_hash(102);
            (**l_202) = &g_2[0];
        }
    }
    else
    {
        short l_257 = 0xBCE2L;
        int l_265[6][9] = {{1L, 0x4D64D8A8L, 0x37457197L, 6L, 0xB7164813L, (-1L), 0xB7164813L, 6L, 0x37457197L}, {1L, 0x4D64D8A8L, 0x37457197L, 6L, 0xB7164813L, (-1L), 0xB7164813L, 6L, 0x37457197L}, {1L, 0x4D64D8A8L, 0x37457197L, 6L, 0xB7164813L, (-1L), 0xB7164813L, 6L, 0x37457197L}, {1L, 0x4D64D8A8L, 0x37457197L, 6L, 0xB7164813L, (-1L), 0xB7164813L, 6L, 0x37457197L}, {1L, 0x4D64D8A8L, 0x37457197L, 6L, 0xB7164813L, (-1L), 0xB7164813L, 6L, 0x37457197L}, {1L, 0x4D64D8A8L, 0x37457197L, 6L, 0xB7164813L, (-1L), 0xB7164813L, 6L, 0x37457197L}};
        unsigned l_266 = 0x23968A6BL;
        int *l_286[5][8] = {{&l_265[3][6], &g_82, &g_82, &g_82, &g_82, &g_82, &l_265[3][6], &l_265[3][6]}, {&l_265[3][6], &g_82, &g_82, &g_82, &g_82, &g_82, &l_265[3][6], &l_265[3][6]}, {&l_265[3][6], &g_82, &g_82, &g_82, &g_82, &g_82, &l_265[3][6], &l_265[3][6]}, {&l_265[3][6], &g_82, &g_82, &g_82, &g_82, &g_82, &l_265[3][6], &l_265[3][6]}, {&l_265[3][6], &g_82, &g_82, &g_82, &g_82, &g_82, &l_265[3][6], &l_265[3][6]}};
        int *l_288[10][4] = {{&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}, {&g_2[0], (void*)0, &g_2[0], &g_2[0]}};
        int i, j;
        step_hash(114);
        if ((p_27 | p_27))
        {
            step_hash(111);
            for (p_26 = 0; (p_26 <= 1); p_26 += 1)
            {
                int i;
                step_hash(109);
                l_257 = p_27;
                step_hash(110);
                l_106[p_26] = l_42[p_26];
            }
        }
        else
        {
            int l_264 = (-1L);
            step_hash(113);
            l_265[3][6] &= ((unsigned)((((unsigned)0xE0769A12L + (unsigned)((signed char)g_234 - (signed char)((&g_64 == (void*)0) ^ l_264))) >= func_88(&g_2[0], p_26, g_234)) > g_232) % (unsigned)g_77);
        }
        step_hash(115);
        --l_266;
        step_hash(222);
        if ((0x9820A3ECL < p_26))
        {
            int *l_273 = (void*)0;
            step_hash(117);
            l_265[5][6] |= (p_27 >= g_269);
            step_hash(136);
            if (p_27)
            {
                int *l_272 = &l_265[1][6];
                step_hash(119);
                g_82 &= p_27;
                step_hash(130);
                for (p_26 = 0; (p_26 != (-4)); p_26--)
                {
                    step_hash(127);
                    for (g_232 = 8; (g_232 >= 0); g_232 -= 1)
                    {
                        step_hash(126);
                        return l_273;
                    }
                    step_hash(128);
                    ++g_274;
                    step_hash(129);
                    if (g_83)
                        continue;
                }
            }
            else
            {
                int l_279 = (-4L);
                unsigned short l_290 = 1UL;
                step_hash(132);
                l_287 = ((~(l_279 <= (func_88(&l_279, l_279, (l_266 <= ((unsigned short)((unsigned short)((((unsigned)g_121 + (unsigned)(p_26 && g_269)) == l_265[3][6]) < (l_286[4][3] == (void*)0)) / (unsigned short)g_237) * (unsigned short)g_83))) != p_27))) == g_234);
                step_hash(133);
                l_288[3][1] = l_273;
                step_hash(134);
                l_290--;
                step_hash(135);
                l_279 = (p_27 >= g_269);
            }
        }
        else
        {
            unsigned l_312 = 3UL;
            int l_323 = (-1L);
            int **l_333 = (void*)0;
            int l_347 = 1L;
            int l_349 = 0xE44B9215L;
            int l_373[5][10] = {{0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L, 0x181DDB77L, (-5L), 0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L}, {0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L, 0x181DDB77L, (-5L), 0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L}, {0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L, 0x181DDB77L, (-5L), 0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L}, {0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L, 0x181DDB77L, (-5L), 0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L}, {0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L, 0x181DDB77L, (-5L), 0x181DDB77L, 0x625F9D78L, 0x51F476ADL, 0x625F9D78L}};
            short l_396 = 0x3246L;
            int *l_424 = (void*)0;
            int i, j;
            step_hash(194);
            for (g_7 = 5; (g_7 >= 0); g_7 -= 1)
            {
                unsigned short l_298 = 2UL;
                signed char l_304 = 0L;
                int *l_307 = &g_7;
                int i;
                step_hash(151);
                for (g_78 = 0; (g_78 <= 5); g_78 += 1)
                {
                    int *l_296 = &g_7;
                    int l_297 = 0x89A85860L;
                    int i;
                    step_hash(144);
                    --g_293;
                    step_hash(149);
                    for (g_162 = 1; (g_162 <= 5); g_162 += 1)
                    {
                        int i;
                        step_hash(148);
                        l_297 = func_88(l_296, (0L != l_241[g_78]), g_289[(g_78 + 1)]);
                    }
                    step_hash(150);
                    if (l_241[g_7])
                        continue;
                }
                step_hash(152);
                l_298++;
                step_hash(180);
                if (((short)(g_289[(g_7 + 1)] != g_289[(g_7 + 1)]) >> (short)g_289[1]))
                {
                    int *l_303 = &g_7;
                    int l_330 = 0L;
                    step_hash(163);
                    if (func_88(func_49(p_26, g_289[(g_7 + 1)], &g_2[0], l_303), p_26, l_304))
                    {
                        int *l_316 = &l_265[3][6];
                        step_hash(155);
                        g_315 = ((signed char)func_88(l_307, g_83, (p_26 && (&g_64 == &g_64))) % (signed char)((unsigned char)((((((unsigned short)(func_88(l_303, (((l_312 || ((unsigned char)251UL / (unsigned char)0xC8L)) != g_234) | g_83), p_26) >= 7UL) >> (unsigned short)l_312) & 2UL) | g_232) ^ p_26) != g_82) + (unsigned char)0xADL));
                        step_hash(156);
                        l_330 &= func_88(l_316, func_88(l_316, ((signed char)((unsigned short)(((short)p_27 << (short)2) >= (l_323 < g_289[3])) >> (unsigned short)((unsigned short)func_88(&l_265[3][6], ((short)(-6L) + (short)((short)(p_26 || 7L) >> (short)p_26)), p_27) >> (unsigned short)p_27)) % (signed char)g_7), (*l_303)), g_234);
                        step_hash(157);
                        (*l_203) = &l_265[1][6];
                    }
                    else
                    {
                        int *l_346[9][5] = {{&g_2[0], &g_7, &g_82, &g_82, &g_7}, {&g_2[0], &g_7, &g_82, &g_82, &g_7}, {&g_2[0], &g_7, &g_82, &g_82, &g_7}, {&g_2[0], &g_7, &g_82, &g_82, &g_7}, {&g_2[0], &g_7, &g_82, &g_82, &g_7}, {&g_2[0], &g_7, &g_82, &g_82, &g_7}, {&g_2[0], &g_7, &g_82, &g_82, &g_7}, {&g_2[0], &g_7, &g_82, &g_82, &g_7}, {&g_2[0], &g_7, &g_82, &g_82, &g_7}};
                        int i, j;
                        step_hash(159);
                        l_330 &= func_88(func_49(g_274, (((unsigned short)(((void*)0 == l_333) != (0x15073BADL <= (((((int)(((unsigned short)p_26 - (unsigned short)(g_238 | ((unsigned char)(((unsigned short)(((unsigned)(p_26 >= (((((short)0L + (short)(func_88(l_346[2][0], (*l_303), g_289[1]) != 0x811DE73CL)) == g_78) != 0xBF8CL) | g_7)) - (unsigned)0xCCC2363EL) || 0xA22DL) >> (unsigned short)12) > g_293) - (unsigned char)(*l_307)))) >= p_26) % (int)p_27) < p_26) || (-3L)) >= (-1L)))) + (unsigned short)p_26) > l_347), &l_323, &g_2[0]), g_83, p_26);
                        step_hash(160);
                        l_348 = p_27;
                        step_hash(161);
                        l_349 = (func_88(l_307, g_234, g_293) & (!p_27));
                        step_hash(162);
                        g_82 = ((void*)0 != &g_64);
                    }
                    step_hash(171);
                    for (l_312 = 0; (l_312 <= 6); l_312 += 1)
                    {
                        int *l_360 = (void*)0;
                        int i;
                        step_hash(167);
                        (*l_203) = &g_2[0];
                        step_hash(168);
                        (**l_202) = func_49(((func_88(&g_82, (~(l_241[g_7] || ((((int)((signed char)func_88(func_49((*l_303), ((unsigned short)((unsigned)func_88(func_49(p_27, g_77, func_49(((unsigned short)p_26 >> (unsigned short)2), p_27, l_360, &l_330), &l_330), p_27, g_293) / (unsigned)(*g_64)) - (unsigned short)g_82), l_307, &l_265[3][6]), (*l_303), g_77) * (signed char)g_121) - (int)p_27) || g_83) && 246UL))), g_232) || g_238) > g_289[1]), l_241[g_7], &g_2[0], &g_2[0]);
                        step_hash(169);
                        l_333 = &g_64;
                        step_hash(170);
                        l_323 ^= p_27;
                    }
                }
                else
                {
                    int *l_366 = &l_323;
                    step_hash(179);
                    for (l_349 = 5; (l_349 >= 0); l_349 -= 1)
                    {
                        int *l_365 = &l_323;
                        step_hash(176);
                        (**l_202) = func_49(((((unsigned char)((*l_307) <= (+p_27)) << (unsigned char)6) || 1UL) ^ g_2[0]), g_238, &l_265[2][2], &g_82);
                        step_hash(177);
                        (**l_202) = func_49(p_26, (((int)p_26 + (int)(&g_64 == &l_286[4][3])) >= 4294967295UL), l_365, l_365);
                        step_hash(178);
                        l_365 = func_49(p_26, p_26, l_366, func_49(((short)(~g_315) - (short)0x176BL), (*l_365), l_365, l_366));
                    }
                }
                step_hash(193);
                if (g_369)
                {
                    int *l_371 = &g_2[0];
                    int l_374 = 0xE3E680F1L;
                    step_hash(188);
                    if (p_27)
                    {
                        int l_370 = 0x79373D42L;
                        int l_372 = 0L;
                        step_hash(183);
                        l_370 |= (0x2B54E87AL >= (!(func_88(&l_323, p_27, (*l_307)) == (g_232 != 0x3AL))));
                        step_hash(184);
                        l_372 |= (((void*)0 != l_371) || 0x6D1124C2L);
                        step_hash(185);
                        --g_375;
                    }
                    else
                    {
                        step_hash(187);
                        --g_379;
                    }
                }
                else
                {
                    unsigned short l_385 = 0x1FE0L;
                    step_hash(190);
                    g_82 = (((void*)0 != l_382) < p_27);
                    step_hash(191);
                    l_385 = ((unsigned char)g_82 + (unsigned char)p_26);
                    step_hash(192);
                    return l_307;
                }
            }
            step_hash(220);
            for (g_378 = 3; (g_378 >= 0); g_378 -= 1)
            {
                int *l_421 = &g_2[0];
                int l_422 = 0x2C34738FL;
                int i;
                step_hash(198);
                ++g_387[3][0];
                step_hash(199);
                g_82 &= (((unsigned char)(g_289[(g_378 + 2)] | (((short)((g_289[(g_378 + 1)] >= l_241[(g_378 + 1)]) && ((unsigned short)g_386[2] - (unsigned short)l_396)) << (short)9) < (+((signed char)(((signed char)(g_289[(g_378 + 1)] < 0x020F51BEL) << (signed char)g_375) && g_7) + (signed char)p_27)))) - (unsigned char)g_401) == g_369);
                step_hash(219);
                for (g_83 = 1; (g_83 <= 5); g_83 += 1)
                {
                    int l_402[7] = {0x29363A9BL, 0x29363A9BL, 0xD3290A70L, 0x29363A9BL, 0x29363A9BL, 0xD3290A70L, 0x29363A9BL};
                    unsigned char l_403 = 0xC6L;
                    int i, j;
                    step_hash(203);
                    l_403 = l_402[0];
                    step_hash(211);
                    if (((signed char)0x01L + (signed char)(((unsigned short)g_2[0] * (unsigned short)(&g_64 != (void*)0)) | p_26)))
                    {
                        int *l_410 = &l_323;
                        step_hash(205);
                        (*l_410) = ((((((unsigned char)((-1L) | ((void*)0 == l_410)) - (unsigned char)((unsigned short)((&l_333 != (void*)0) <= (l_410 != (void*)0)) << (unsigned short)15)) >= func_88(&g_2[0], ((unsigned)(((unsigned short)((!p_27) & 6L) >> (unsigned short)g_78) & p_27) - (unsigned)g_289[1]), g_238)) && p_26) && p_26) || g_375);
                        step_hash(206);
                        if (g_289[(g_378 + 2)])
                            continue;
                    }
                    else
                    {
                        unsigned char l_417[8][7] = {{0xEDL, 0xD1L, 252UL, 0xD1L, 0xEDL, 250UL, 0xEDL}, {0xEDL, 0xD1L, 252UL, 0xD1L, 0xEDL, 250UL, 0xEDL}, {0xEDL, 0xD1L, 252UL, 0xD1L, 0xEDL, 250UL, 0xEDL}, {0xEDL, 0xD1L, 252UL, 0xD1L, 0xEDL, 250UL, 0xEDL}, {0xEDL, 0xD1L, 252UL, 0xD1L, 0xEDL, 250UL, 0xEDL}, {0xEDL, 0xD1L, 252UL, 0xD1L, 0xEDL, 250UL, 0xEDL}, {0xEDL, 0xD1L, 252UL, 0xD1L, 0xEDL, 250UL, 0xEDL}, {0xEDL, 0xD1L, 252UL, 0xD1L, 0xEDL, 250UL, 0xEDL}};
                        int *l_420 = (void*)0;
                        int i, j;
                        step_hash(208);
                        l_417[7][3]++;
                        step_hash(209);
                        (*l_203) = l_420;
                        step_hash(210);
                        return l_421;
                    }
                    step_hash(218);
                    for (l_266 = 0; (l_266 <= 5); l_266 += 1)
                    {
                        int *l_423 = &l_265[4][4];
                        int i;
                        step_hash(215);
                        l_422 ^= ((&g_64 != (void*)0) <= (0L || g_289[g_378]));
                        step_hash(216);
                        l_286[4][3] = &l_422;
                        step_hash(217);
                        return l_424;
                    }
                }
            }
            step_hash(221);
            (**l_202) = &l_265[3][6];
        }
    }
    step_hash(224);
    g_7 = l_425;
    step_hash(276);
    for (g_378 = 18; (g_378 != (-16)); g_378--)
    {
        int *l_437[7] = {(void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0};
        signed char l_446 = 0x1EL;
        unsigned l_471[2][9] = {{0xA9BEC898L, 0xA9BEC898L, 4294967290UL, 0x1F6FDC5FL, 1UL, 0x1F6FDC5FL, 4294967290UL, 0xA9BEC898L, 0xA9BEC898L}, {0xA9BEC898L, 0xA9BEC898L, 4294967290UL, 0x1F6FDC5FL, 1UL, 0x1F6FDC5FL, 4294967290UL, 0xA9BEC898L, 0xA9BEC898L}};
        short l_476 = 1L;
        unsigned l_495 = 4294967294UL;
        int i, j;
        step_hash(232);
        for (g_401 = (-23); (g_401 == 1); g_401 += 7)
        {
            int l_430 = 0x1B0D18BCL;
            step_hash(231);
            l_430 ^= ((&g_64 == (void*)0) | 0UL);
        }
        step_hash(275);
        for (p_26 = (-18); (p_26 <= 5); p_26 += 1)
        {
            short l_433 = 0x9B08L;
            int l_434[6];
            signed char l_440 = 7L;
            int i;
            for (i = 0; i < 6; i++)
                l_434[i] = 0L;
            step_hash(236);
            l_433 = 0x507DCFA4L;
            step_hash(272);
            if (l_433)
            {
                signed char l_441 = 0xA0L;
                int l_449 = 0xE7DD9E9FL;
                int l_451[7] = {0x39DFA018L, 0x39DFA018L, 0xD5BABE37L, 0x39DFA018L, 0x39DFA018L, 0xD5BABE37L, 0x39DFA018L};
                int l_455 = 0xE6E5E341L;
                int *l_492 = (void*)0;
                int i;
                step_hash(238);
                l_434[1] &= (!l_433);
                step_hash(244);
                for (g_7 = (-29); (g_7 > (-11)); g_7++)
                {
                    step_hash(242);
                    (*l_382) = l_437[2];
                    step_hash(243);
                    if (p_27)
                        continue;
                }
                step_hash(267);
                if (((((signed char)l_440 << (signed char)2) ^ (~l_441)) | l_440))
                {
                    int *l_447[10];
                    int *l_481 = &l_449;
                    int i;
                    for (i = 0; i < 10; i++)
                        l_447[i] = (void*)0;
                    step_hash(255);
                    if (((func_38(p_26, l_441, func_49(p_27, (((unsigned char)0x03L - (unsigned char)g_379) >= ((p_26 > (+((p_27 <= ((short)(((p_27 >= ((g_401 != p_27) == g_2[0])) | l_446) || l_433) % (short)(-1L))) || 9UL))) <= 1UL)), l_447[2], &g_401)) <= g_274) > 0xE4BCL))
                    {
                        int l_450[5];
                        int ***l_456 = &l_382;
                        int i;
                        for (i = 0; i < 5; i++)
                            l_450[i] = (-2L);
                        step_hash(247);
                        --g_452[0];
                        step_hash(248);
                        l_434[3] = p_26;
                        step_hash(249);
                        (**l_202) = func_92(p_26, g_452[1], l_455, l_456, &l_447[2]);
                        step_hash(250);
                        l_471[1][0] = (((short)((unsigned char)p_26 + (unsigned char)(((signed char)p_27 * (signed char)((signed char)(((unsigned short)(l_447[2] != (**l_456)) % (unsigned short)(p_26 && 0x4CA0E249L)) && 249UL) / (signed char)p_27)) > ((signed char)((unsigned)0UL / (unsigned)g_2[0]) >> (signed char)g_289[1]))) / (short)l_451[0]) > 4294967286UL);
                    }
                    else
                    {
                        int *l_472 = &l_434[1];
                        step_hash(252);
                        (*l_382) = l_447[5];
                        step_hash(253);
                        if (p_26)
                            continue;
                        step_hash(254);
                        g_82 |= ((6L | (func_70(l_472) < ((((short)((((-(signed char)(((l_476 < ((g_401 || 65530UL) < ((signed char)g_237 % (signed char)(((unsigned short)p_27 / (unsigned short)l_434[3]) | 0xA740L)))) <= l_434[5]) ^ p_27)) | l_455) ^ p_27) != 0L) >> (short)2) > p_26) | (-1L)))) > p_26);
                    }
                    step_hash(256);
                    return l_437[1];
                }
                else
                {
                    int *l_484[1];
                    int i;
                    for (i = 0; i < 1; i++)
                        l_484[i] = (void*)0;
                    step_hash(263);
                    for (g_369 = 0; (g_369 <= 1); g_369 += 1)
                    {
                        int i;
                        step_hash(261);
                        (*l_202) = &l_106[g_369];
                        step_hash(262);
                        return l_106[g_369];
                    }
                    step_hash(264);
                    g_401 = (~(g_387[3][0] ^ (l_484[0] != &g_401)));
                    step_hash(265);
                    l_451[3] = ((signed char)0x2EL << (signed char)((l_434[5] && p_26) || l_455));
                    step_hash(266);
                    l_492 = func_49((p_26 && ((signed char)(!(g_378 ^ l_434[3])) + (signed char)(((short)func_43(&l_451[0], (p_26 && g_238), p_26, l_491, &l_434[1]) * (short)0L) ^ (-8L)))), p_26, l_484[0], &l_434[0]);
                }
            }
            else
            {
                short l_493 = 4L;
                int l_494[5] = {(-1L), 0xBFFF465AL, (-1L), 0xBFFF465AL, (-1L)};
                int i;
                step_hash(269);
                if (p_26)
                    break;
                step_hash(270);
                for (l_425 = 0; l_425 < 7; l_425 += 1)
                {
                    l_437[l_425] = &g_2[0];
                }
                step_hash(271);
                --l_495;
            }
            step_hash(273);
            g_500++;
            step_hash(274);
            if (p_26)
                continue;
        }
    }
    step_hash(277);
    return &g_401;
}







static unsigned short func_38(int p_39, unsigned p_40, int * p_41)
{
    int l_113 = 5L;
    step_hash(43);
    for (p_40 = 0; (p_40 <= 24); ++p_40)
    {
        int l_120 = (-9L);
        step_hash(42);
        for (g_78 = 0; (g_78 == 2); g_78 += 8)
        {
            int *l_111 = (void*)0;
            int *l_112 = &g_7;
            int *l_114 = &l_113;
            int *l_115 = (void*)0;
            int *l_116 = (void*)0;
            int *l_117 = &g_7;
            int *l_118 = (void*)0;
            int *l_119[4][9] = {{&g_2[0], &g_2[0], &g_7, &l_113, &l_113, &g_7, &g_2[0], &g_2[0], &g_7}, {&g_2[0], &g_2[0], &g_7, &l_113, &l_113, &g_7, &g_2[0], &g_2[0], &g_7}, {&g_2[0], &g_2[0], &g_7, &l_113, &l_113, &g_7, &g_2[0], &g_2[0], &g_7}, {&g_2[0], &g_2[0], &g_7, &l_113, &l_113, &g_7, &g_2[0], &g_2[0], &g_7}};
            int i, j;
            step_hash(41);
            g_121++;
        }
    }
    step_hash(51);
    for (g_83 = 0; (g_83 >= 29); g_83 += 6)
    {
        int **l_126 = &g_64;
        int *l_127 = &g_7;
        int *l_132 = &g_82;
        step_hash(47);
        (*l_126) = &l_113;
        step_hash(48);
        (*l_127) &= (**l_126);
        step_hash(49);
        (*l_132) |= ((unsigned char)(((0UL > (((*l_126) == (void*)0) && (p_39 < ((&p_39 != (void*)0) <= (((int)0L - (int)((&p_39 != &p_39) | p_39)) && (*l_127)))))) != p_39) | g_2[0]) * (unsigned char)l_113);
        step_hash(50);
        (*l_132) = ((signed char)(func_88(func_49((0UL <= ((p_39 & ((unsigned char)p_40 >> (unsigned char)((signed char)0x48L + (signed char)0x7FL))) != ((unsigned char)g_78 - (unsigned char)(((unsigned char)((unsigned short)l_113 >> (unsigned short)0) << (unsigned char)g_82) == ((**l_126) < (*g_64)))))), g_7, &g_7, &g_7), p_39, p_40) != (*g_64)) << (signed char)7);
    }
    step_hash(52);
    return g_2[0];
}







static unsigned short func_43(int * p_44, unsigned char p_45, unsigned char p_46, int * p_47, int * p_48)
{
    short l_98 = 0x957BL;
    int ***l_99 = &g_63;
    int **l_105 = &g_64;
    step_hash(31);
    (*l_105) = func_49((((*p_47) <= ((short)(((unsigned)func_70(p_47) / (unsigned)p_45) && ((unsigned short)func_88(func_92(g_7, p_45, l_98, l_99, (*l_99)), g_77, g_77) << (unsigned short)g_77)) % (short)g_2[0])) != 0x6D66C253L), g_2[0], p_48, p_44);
    step_hash(32);
    (**l_105) = (*p_47);
    step_hash(33);
    return p_46;
}







static int * func_49(unsigned char p_50, unsigned p_51, int * p_52, int * p_53)
{
    int *l_62[2][6] = {{&g_2[0], &g_2[0], (void*)0, &g_2[0], &g_2[0], (void*)0}, {&g_2[0], &g_2[0], (void*)0, &g_2[0], &g_2[0], (void*)0}};
    int **l_61 = &l_62[1][4];
    int ***l_60[2][1];
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 1; j++)
            l_60[i][j] = &l_61;
    }
    step_hash(12);
    g_63 = (void*)0;
    step_hash(13);
    return &g_7;
}







static unsigned func_70(int * p_71)
{
    int *l_74 = &g_7;
    int *l_75 = &g_7;
    int *l_76[8] = {(void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0};
    int l_81 = 0x5AE7BE98L;
    int i;
    step_hash(20);
    for (g_7 = (-29); (g_7 >= 28); g_7 += 8)
    {
        step_hash(19);
        if ((*p_71))
            break;
    }
    step_hash(21);
    g_78--;
    step_hash(22);
    --g_83;
    step_hash(23);
    return g_7;
}







static unsigned short func_88(int * p_89, short p_90, unsigned short p_91)
{
    step_hash(29);
    p_89 = p_89;
    step_hash(30);
    return g_7;
}







static int * func_92(unsigned p_93, unsigned short p_94, int p_95, int *** p_96, int ** p_97)
{
    int *l_100 = &g_2[0];
    int l_101 = 0x643A5642L;
    int **l_102[2][5] = {{&g_64, (void*)0, &g_64, (void*)0, &g_64}, {&g_64, (void*)0, &g_64, (void*)0, &g_64}};
    int *l_103[8][10] = {{&g_2[0], &g_2[0], &l_101, (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &l_101, &g_2[0]}, {&g_2[0], &g_2[0], &l_101, (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &l_101, &g_2[0]}, {&g_2[0], &g_2[0], &l_101, (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &l_101, &g_2[0]}, {&g_2[0], &g_2[0], &l_101, (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &l_101, &g_2[0]}, {&g_2[0], &g_2[0], &l_101, (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &l_101, &g_2[0]}, {&g_2[0], &g_2[0], &l_101, (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &l_101, &g_2[0]}, {&g_2[0], &g_2[0], &l_101, (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &l_101, &g_2[0]}, {&g_2[0], &g_2[0], &l_101, (void*)0, &g_2[0], (void*)0, &g_2[0], (void*)0, &l_101, &g_2[0]}};
    int *l_104[9] = {&g_7, &g_2[0], &g_7, &g_2[0], &g_7, &g_2[0], &g_7, &g_2[0], &g_7};
    int i, j;
    step_hash(25);
    l_101 |= (0xFB31L <= (func_70(l_100) != ((void*)0 == l_100)));
    step_hash(26);
    g_64 = &g_7;
    step_hash(27);
    return l_104[7];
}


void csmith_compute_hash(void)
{
    int i, j;
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_2[i], "g_2[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_7, "g_7", print_hash_value);
    transparent_crc(g_77, "g_77", print_hash_value);
    transparent_crc(g_78, "g_78", print_hash_value);
    transparent_crc(g_82, "g_82", print_hash_value);
    transparent_crc(g_83, "g_83", print_hash_value);
    transparent_crc(g_121, "g_121", print_hash_value);
    transparent_crc(g_162, "g_162", print_hash_value);
    transparent_crc(g_232, "g_232", print_hash_value);
    transparent_crc(g_234, "g_234", print_hash_value);
    transparent_crc(g_237, "g_237", print_hash_value);
    transparent_crc(g_238, "g_238", print_hash_value);
    transparent_crc(g_250, "g_250", print_hash_value);
    transparent_crc(g_269, "g_269", print_hash_value);
    transparent_crc(g_274, "g_274", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_289[i], "g_289[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_293, "g_293", print_hash_value);
    transparent_crc(g_315, "g_315", print_hash_value);
    transparent_crc(g_369, "g_369", print_hash_value);
    transparent_crc(g_375, "g_375", print_hash_value);
    transparent_crc(g_378, "g_378", print_hash_value);
    transparent_crc(g_379, "g_379", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_386[i], "g_386[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 4; j++)
        {
            transparent_crc(g_387[i][j], "g_387[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_401, "g_401", print_hash_value);
    transparent_crc(g_448, "g_448", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_452[i], "g_452[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_498[i][j], "g_498[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_499, "g_499", print_hash_value);
    transparent_crc(g_500, "g_500", print_hash_value);
    transparent_crc(g_520, "g_520", print_hash_value);
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
