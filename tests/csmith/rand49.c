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
static int g_2 = 0xC03342EBL;
static int g_77 = (-1L);
static signed char g_82 = (-1L);
static int g_84 = 0xA7276463L;
static int g_103 = 0x168F1D39L;
static int *g_121 = &g_2;
static int **g_120 = &g_121;
static unsigned short g_209 = 0x8AF1L;
static unsigned char g_225 = 255UL;
static unsigned g_228 = 0x37CC862BL;
static int g_255 = 0xE45A5366L;
static signed char func_1(void);
static unsigned func_8(int p_9, unsigned p_10);
static unsigned short func_13(signed char p_14, short p_15, unsigned char p_16, short p_17);
static unsigned char func_19(int p_20, unsigned p_21);
static short func_24(unsigned char p_25, short p_26, int p_27, int p_28, unsigned char p_29);
static unsigned func_48(unsigned p_49, unsigned char p_50, unsigned p_51, int p_52);
static unsigned func_53(short p_54, unsigned p_55, int p_56);
static unsigned short func_59(int p_60, signed char p_61, unsigned p_62, int p_63);
static unsigned func_64(unsigned char p_65);
static int func_68(unsigned short p_69, int p_70, int p_71, unsigned char p_72);
static signed char func_1(void)
{
    unsigned l_18 = 0xBBD0A708L;
    int l_178 = 0x51062BF1L;
    int l_322 = 0x6DBBD370L;
    short l_323 = (-6L);
    step_hash(238);
    for (g_2 = 0; (g_2 <= 10); ++g_2)
    {
        signed char l_5 = (-9L);
        int **l_328 = &g_121;
        int *l_329 = &l_322;
    }
    step_hash(239);
    return l_323;
}
static unsigned func_8(int p_9, unsigned p_10)
{
    int l_316 = 0x993A821AL;
    unsigned short l_317 = 0UL;
    unsigned l_320 = 4294967286UL;
    int *l_321 = &g_255;
    step_hash(215);
    (*g_120) = &p_9;
    step_hash(225);
    for (g_82 = 0; (g_82 != 21); ++g_82)
    {
        step_hash(224);
        for (p_10 = (-14); (p_10 > 3); p_10 += 1)
        {
            step_hash(222);
            (*g_120) = &p_9;
            step_hash(223);
            return g_77;
        }
    }
    step_hash(226);
    (*l_321) = ((p_10 < l_316) ^ (func_13(l_316, g_82, l_317, (((((short)(p_10 ^ g_82) >> (short)5) > l_316) >= (p_9 && l_317)) <= p_10)) == l_320));
    step_hash(227);
    return g_77;
}
static unsigned short func_13(signed char p_14, short p_15, unsigned char p_16, short p_17)
{
    short l_210 = (-5L);
    int *l_211 = (void*)0;
    int *l_212 = &g_77;
    int ***l_309 = &g_120;
    step_hash(118);
    (*l_212) = (l_210 < p_14);
    step_hash(211);
    for (p_16 = 0; (p_16 <= 27); p_16 += 9)
    {
        int l_217 = 0x805B927CL;
        short l_233 = (-8L);
        int l_282 = (-5L);
        step_hash(166);
        if (p_17)
        {
            step_hash(123);
            l_217 &= ((signed char)p_16 * (signed char)g_77);
            step_hash(124);
            (*l_212) = (g_84 != p_14);
        }
        else
        {
            unsigned short l_222 = 0x4FC1L;
            int l_230 = 0L;
            int l_245 = (-1L);
            short l_265 = 0x163CL;
            step_hash(134);
            if (((unsigned char)p_17 % (unsigned char)((g_82 || (~((unsigned)(p_17 || l_222) + (unsigned)((void*)0 != &l_217)))) & func_64(p_14))))
            {
                int l_229 = 0L;
                step_hash(127);
                l_230 ^= (((unsigned short)func_24((g_225 || (0xF7L != ((unsigned char)p_17 + (unsigned char)func_59(g_77, g_228, (&l_217 != (void*)0), (*l_212))))), l_217, l_217, g_77, p_16) - (unsigned short)1L) == l_229);
                step_hash(128);
                (*g_120) = &l_217;
                step_hash(129);
                (*g_120) = l_211;
                step_hash(130);
                l_229 = (((unsigned)p_16 / (unsigned)p_17) >= l_233);
            }
            else
            {
                step_hash(132);
                if (l_217)
                    break;
                step_hash(133);
                return p_14;
            }
            step_hash(164);
            for (g_77 = (-23); (g_77 < 22); ++g_77)
            {
                unsigned short l_244 = 0x34F9L;
                int **l_280 = (void*)0;
                step_hash(138);
                l_217 = ((short)(((signed char)((((unsigned)((unsigned char)l_244 / (unsigned char)g_103) + (unsigned)l_245) == (*l_212)) && g_103) << (signed char)p_15) != ((int)((&g_121 == (void*)0) <= ((p_17 ^ 0x35L) >= g_77)) % (int)(-1L))) >> (short)1);
                step_hash(162);
                for (g_228 = 0; (g_228 > 32); g_228 += 7)
                {
                    int **l_261 = &l_211;
                    short l_262 = 0x2008L;
                    unsigned l_263 = 0x41802645L;
                    int l_264 = 0x1A2FFDF3L;
                    step_hash(146);
                    for (p_14 = 0; (p_14 == 20); p_14++)
                    {
                        step_hash(145);
                        (*g_120) = (*g_120);
                    }
                    step_hash(152);
                    for (p_14 = 10; (p_14 < (-28)); p_14--)
                    {
                        int *l_254 = &g_2;
                        int *l_256 = &g_84;
                        step_hash(150);
                        (*g_120) = l_254;
                        step_hash(151);
                        (*l_256) = (!(!g_255));
                    }
                    step_hash(153);
                    l_264 = ((func_64((*l_212)) <= g_84) || ((signed char)g_225 << (signed char)func_59((((int)(&l_217 != (void*)0) + (int)(l_261 == &l_212)) == (l_262 > 0xE5L)), g_77, g_82, l_263)));
                    step_hash(161);
                    if ((l_265 < ((+((((-(unsigned short)((unsigned short)((unsigned)(func_64(g_255) < ((unsigned char)((unsigned)0x1511DFD7L - (unsigned)p_14) << (unsigned char)((short)(g_209 < ((short)l_233 + (short)(&g_121 == &g_121))) << (short)g_2))) / (unsigned)l_217) - (unsigned short)p_14)) == (*l_212)) != 4294967290UL) | (-1L))) > 0x9590L)))
                    {
                        unsigned l_279 = 0xF72D5D3AL;
                        step_hash(155);
                        (*g_120) = (*g_120);
                        step_hash(156);
                        l_279 |= l_245;
                        step_hash(157);
                        return p_14;
                    }
                    else
                    {
                        int ***l_281 = &l_261;
                        step_hash(159);
                        (*l_281) = l_280;
                        step_hash(160);
                        return l_233;
                    }
                }
                step_hash(163);
                l_230 = l_282;
            }
            step_hash(165);
            return l_245;
        }
        step_hash(210);
        for (l_210 = 0; (l_210 == (-28)); l_210--)
        {
            short l_290 = 9L;
            int l_298 = 0x5D891B15L;
            step_hash(196);
            for (g_228 = 6; (g_228 > 14); g_228 += 7)
            {
                int *l_289 = &g_2;
                step_hash(173);
                (*g_120) = &l_217;
                step_hash(174);
                (*g_120) = (*g_120);
                step_hash(194);
                for (g_82 = 0; (g_82 < (-15)); g_82 -= 1)
                {
                    unsigned l_293 = 0x0E9AD63DL;
                    int *l_301 = &l_217;
                }
                step_hash(195);
                (**l_309) = (*g_120);
            }
            step_hash(202);
            for (g_84 = 0; (g_84 <= (-14)); g_84 -= 1)
            {
                step_hash(200);
                (*g_120) = &l_298;
                step_hash(201);
                if (p_14)
                    break;
            }
            step_hash(209);
            if (l_217)
            {
                step_hash(204);
                (*l_212) &= 0x74C5E4DCL;
                step_hash(205);
                return g_225;
            }
            else
            {
                step_hash(207);
                (**l_309) = &l_282;
                step_hash(208);
                (**l_309) = (**l_309);
            }
        }
    }
    step_hash(212);
    (*g_120) = l_212;
    step_hash(213);
    return g_2;
}
static unsigned char func_19(int p_20, unsigned p_21)
{
    int *l_208 = &g_84;
    step_hash(115);
    for (g_103 = 19; (g_103 <= 10); g_103 -= 7)
    {
        int *l_207 = &g_84;
        step_hash(113);
        l_208 = l_207;
        step_hash(114);
        (*g_120) = l_207;
    }
    step_hash(116);
    return g_209;
}
static short func_24(unsigned char p_25, short p_26, int p_27, int p_28, unsigned char p_29)
{
    unsigned l_193 = 0xF16E3D7EL;
    unsigned l_202 = 0x66428892L;
    int *l_203 = (void*)0;
    int *l_204 = &g_103;
    step_hash(106);
    (*l_204) &= (g_84 & ((unsigned short)((signed char)((unsigned char)g_77 + (unsigned char)g_2) + (signed char)(((((unsigned short)(((l_193 & ((g_82 <= p_25) >= p_27)) ^ p_28) != g_2) << (unsigned short)l_193) > g_2) == l_202) & 2UL)) << (unsigned short)l_193));
    step_hash(107);
    (*l_204) &= p_27;
    step_hash(108);
    return g_103;
}
static unsigned func_48(unsigned p_49, unsigned char p_50, unsigned p_51, int p_52)
{
    unsigned l_183 = 4294967291UL;
    unsigned short l_186 = 0xFCA4L;
    int *l_187 = &g_77;
    step_hash(102);
    if ((((unsigned short)((short)0xAC06L >> (short)3) / (unsigned short)(l_183 ^ p_49)) >= ((unsigned short)func_59(p_49, l_186, p_50, (p_50 <= ((func_68(l_186, g_103, l_183, l_186) | 0x0038BE24L) || p_52))) >> (unsigned short)p_50)))
    {
        step_hash(92);
        (*g_120) = l_187;
    }
    else
    {
        step_hash(98);
        for (p_51 = 0; (p_51 > 42); p_51++)
        {
            step_hash(97);
            return g_2;
        }
        step_hash(99);
        (*l_187) = p_52;
        step_hash(100);
        (*g_120) = &g_77;
        step_hash(101);
        (*g_121) = (*g_121);
    }
    step_hash(103);
    (*g_120) = (void*)0;
    step_hash(104);
    return g_2;
}
static unsigned func_53(short p_54, unsigned p_55, int p_56)
{
    int *l_119 = &g_77;
    int **l_118 = &l_119;
    signed char l_171 = (-7L);
    step_hash(37);
    (*l_118) = &g_84;
    step_hash(88);
    if (((0xE0L > p_55) && (func_68((g_120 != &l_119), func_68(((void*)0 == (*g_120)), p_54, (((unsigned short)((unsigned short)(((*l_119) < g_84) || g_82) * (unsigned short)g_2) << (unsigned short)g_77) != p_56), p_55), g_103, p_55) >= 0x94L)))
    {
        signed char l_147 = 0x73L;
        int *l_170 = (void*)0;
        step_hash(52);
        for (g_82 = 0; (g_82 < 7); g_82 += 6)
        {
            unsigned char l_128 = 6UL;
            step_hash(42);
            if (l_128)
                break;
            step_hash(51);
            for (p_55 = (-19); (p_55 <= 56); p_55 += 6)
            {
                step_hash(50);
                for (l_128 = 0; (l_128 >= 30); l_128 += 1)
                {
                    step_hash(49);
                    return g_103;
                }
            }
        }
        step_hash(77);
        for (g_103 = 9; (g_103 == 21); g_103 += 7)
        {
            short l_141 = (-1L);
            int l_142 = (-8L);
            step_hash(56);
            l_142 ^= ((((short)((short)((unsigned short)l_141 * (unsigned short)(((&l_119 != &l_119) && 2L) <= func_68((g_103 != 0xA75CL), p_54, p_54, p_56))) >> (short)p_56) << (short)15) >= 0x7660C929L) || p_54);
            step_hash(57);
            (*l_119) = p_56;
            step_hash(76);
            if (p_55)
            {
                int l_151 = 1L;
                unsigned short l_163 = 65535UL;
                int *l_164 = (void*)0;
                int *l_165 = &l_142;
                step_hash(71);
                for (p_54 = 19; (p_54 < 14); p_54--)
                {
                    unsigned l_154 = 0x171667F3L;
                    int *l_155 = &g_77;
                    int *l_156 = &l_142;
                    step_hash(67);
                    for (p_55 = (-3); (p_55 != 45); p_55 += 5)
                    {
                        int l_148 = 0x09E68FEEL;
                        step_hash(65);
                        p_56 ^= l_147;
                        step_hash(66);
                        return l_148;
                    }
                    step_hash(68);
                    p_56 = (((p_55 >= ((((g_82 && g_77) > g_84) || 0xCEF6A3D7L) && ((unsigned char)func_68(l_151, p_56, p_54, (0x52BCL < 0x8EE5L)) * (unsigned char)0x2AL))) <= (*g_121)) ^ g_2);
                    step_hash(69);
                    (*l_155) ^= ((unsigned short)(**l_118) << (unsigned short)(l_154 == g_2));
                    step_hash(70);
                    (*l_156) ^= (p_56 >= func_68(l_141, (p_55 | g_82), l_147, l_151));
                }
                step_hash(72);
                (*g_120) = &p_56;
                step_hash(73);
                (*l_165) &= ((short)func_68(((short)1L * (short)((short)(~g_2) * (short)p_54)), l_163, ((((l_147 <= (p_56 && func_68(p_54, p_55, p_54, g_2))) && 1L) & p_54) > 1UL), p_55) << (short)p_54);
            }
            else
            {
                step_hash(75);
                if (p_56)
                    break;
            }
        }
        step_hash(83);
        for (p_54 = 0; (p_54 != (-1)); p_54 -= 8)
        {
        }
        step_hash(84);
        (*g_120) = l_170;
    }
    else
    {
        short l_176 = (-9L);
        int l_177 = 0xDADA64CFL;
        step_hash(86);
        (*l_118) = (void*)0;
        step_hash(87);
        l_177 = (l_171 > ((g_84 | ((~p_56) < p_54)) < ((unsigned char)g_77 / (unsigned char)(func_64((+((((**g_120) <= ((unsigned char)g_77 % (unsigned char)func_64(l_176))) < p_55) != l_176))) && 0xA06A2A82L))));
    }
    step_hash(89);
    return p_55;
}
static unsigned short func_59(int p_60, signed char p_61, unsigned p_62, int p_63)
{
    unsigned short l_109 = 9UL;
    int *l_110 = &g_84;
    unsigned l_115 = 4294967295UL;
    int **l_117 = &l_110;
    step_hash(25);
    (*l_110) = (((signed char)0x68L * (signed char)p_61) & ((unsigned short)(p_62 && (l_109 != 255UL)) * (unsigned short)(((p_62 ^ func_64(g_103)) & 0xD3C1L) < l_109)));
    step_hash(33);
    for (g_84 = 27; (g_84 <= (-27)); g_84--)
    {
        unsigned l_113 = 4294967295UL;
        int *l_114 = &g_103;
        int **l_116 = &l_110;
        step_hash(29);
        (*l_114) = (~l_113);
        step_hash(30);
        if (p_62)
            continue;
        step_hash(31);
        if (l_115)
            break;
        step_hash(32);
        (*l_116) = &g_77;
    }
    step_hash(34);
    (*l_117) = &g_84;
    step_hash(35);
    return g_77;
}
static unsigned func_64(unsigned char p_65)
{
    signed char l_87 = 0x6FL;
    signed char l_90 = 0L;
    int l_91 = (-1L);
    int *l_102 = &g_103;
    step_hash(21);
    l_91 &= (((l_87 > p_65) < ((unsigned char)(+g_84) >> (unsigned char)4)) < (g_2 && (l_90 && 0UL)));
    step_hash(22);
    (*l_102) &= ((((&l_91 == (void*)0) <= l_87) & (((((unsigned)g_84 % (unsigned)((unsigned)0x57DCCC76L / (unsigned)((short)((signed char)(l_91 & (g_77 || l_91)) - (signed char)0xA1L) >> (short)5))) != 0UL) || p_65) ^ 0x5FL)) || l_90);
    step_hash(23);
    return p_65;
}
static int func_68(unsigned short p_69, int p_70, int p_71, unsigned char p_72)
{
    int *l_76 = &g_77;
    int l_86 = 1L;
    step_hash(17);
    for (p_69 = 0; (p_69 == 44); p_69 += 8)
    {
        unsigned short l_85 = 7UL;
        step_hash(9);
        l_76 = (void*)0;
        step_hash(15);
        for (g_77 = 0; (g_77 == (-3)); g_77--)
        {
            int *l_83 = &g_84;
            step_hash(13);
            g_82 |= ((int)p_69 - (int)g_77);
            step_hash(14);
            (*l_83) = g_2;
        }
        step_hash(16);
        if (l_85)
            continue;
    }
    step_hash(18);
    l_86 = l_86;
    step_hash(19);
    return g_82;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_77, "g_77", print_hash_value);
    transparent_crc(g_82, "g_82", print_hash_value);
    transparent_crc(g_84, "g_84", print_hash_value);
    transparent_crc(g_103, "g_103", print_hash_value);
    transparent_crc(g_209, "g_209", print_hash_value);
    transparent_crc(g_225, "g_225", print_hash_value);
    transparent_crc(g_228, "g_228", print_hash_value);
    transparent_crc(g_255, "g_255", print_hash_value);
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
