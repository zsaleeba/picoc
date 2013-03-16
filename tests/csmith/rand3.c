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
static int g_7 = 0x386CCE57L;
static int *g_6 = &g_7;
static unsigned g_28 = 4294967290UL;
static int g_70 = 0x6A74B4FBL;
static int *g_104 = &g_7;
static int **g_204 = &g_104;
static int ***g_203 = &g_204;
static unsigned short g_248 = 0x570AL;
static int g_271 = 1L;
static int g_312 = 0x0E0531CCL;
static int *g_329 = &g_7;
static signed char func_1(void);
static int * func_2(int * p_3, unsigned short p_4, unsigned p_5);
static signed char func_8(int * p_9, signed char p_10);
static int * func_11(int * p_12);
static int * func_13(int * p_14, int p_15);
static int * func_16(unsigned p_17, short p_18);
static int * func_21(signed char p_22);
static int * func_33(unsigned p_34, int p_35, unsigned p_36, int p_37, int ** p_38);
static unsigned char func_41(short p_42, int * p_43, int * p_44, int * p_45, int ** p_46);
static short func_47(int * p_48);
static signed char func_1(void)
{
    signed char l_330 = 0L;
    int **l_506 = (void*)0;
    int **l_507 = &g_6;
    step_hash(335);
    (*l_507) = func_2(g_6, (func_8(func_11(func_13(func_16(g_7, g_7), l_330)), g_248) ^ g_248), g_248);
    step_hash(336);
    (**l_507) = (-5L);
    step_hash(337);
    return (**l_507);
}
static int * func_2(int * p_3, unsigned short p_4, unsigned p_5)
{
    int l_504 = 0x44675D09L;
    int **l_505 = &g_329;
    step_hash(332);
    (**g_203) = func_33(((unsigned char)(p_5 ^ (*p_3)) * (unsigned char)((((unsigned)(((((short)((void*)0 == &g_204) * (short)(((void*)0 == &p_3) == l_504)) <= (~((&l_504 == (void*)0) & g_70))) && l_504) ^ 0UL) % (unsigned)0x16825E04L) != l_504) & (*g_6))), l_504, l_504, l_504, l_505);
    step_hash(333);
    (*g_104) = (*p_3);
    step_hash(334);
    return (*g_204);
}
static signed char func_8(int * p_9, signed char p_10)
{
    int ***l_353 = &g_204;
    int *l_358 = &g_312;
    int *l_365 = &g_312;
    unsigned l_401 = 0x9AA9D4D8L;
    signed char l_414 = 0x8EL;
    int l_439 = 0L;
    step_hash(245);
    (*l_358) |= (((unsigned char)(((signed char)((signed char)(((signed char)(+(((signed char)((int)p_10 + (int)(l_353 != &g_204)) << (signed char)7) || (((0UL >= ((signed char)g_7 + (signed char)g_248)) && (0x5DL == (l_353 == (void*)0))) > p_10))) - (signed char)1L) || g_7) % (signed char)g_28) << (signed char)g_70) | g_271) * (unsigned char)0UL) == 5L);
    step_hash(313);
    if ((((short)((*l_358) && ((**l_353) != (**g_203))) * (short)(*l_358)) != (((unsigned short)((unsigned)((*l_358) >= p_10) + (unsigned)((*l_353) != (void*)0)) << (unsigned short)10) ^ ((void*)0 != l_353))))
    {
        int *l_366 = &g_312;
        int l_369 = 0L;
        step_hash(247);
        (*g_329) ^= (*l_366);
        step_hash(248);
        (*l_365) &= ((unsigned short)l_369 - (unsigned short)p_10);
    }
    else
    {
        short l_374 = 0x101EL;
        int *l_377 = (void*)0;
        int *l_420 = &g_7;
        int *l_430 = &g_312;
        int l_456 = 1L;
        unsigned short l_462 = 0x80F5L;
        step_hash(266);
        if (((short)((signed char)(!l_374) << (signed char)(g_248 | g_312)) * (short)7UL))
        {
            int *l_378 = (void*)0;
            step_hash(251);
            (*g_204) = l_377;
            step_hash(252);
            (*g_329) |= (g_271 & (((p_10 <= (((short)0x2AB5L << (short)((void*)0 == (*g_203))) & g_271)) || (((unsigned)((unsigned short)(g_248 != (g_248 || g_271)) / (unsigned short)g_312) / (unsigned)0x4928AC87L) ^ 0xDBL)) < p_10));
        }
        else
        {
            step_hash(263);
            for (g_70 = (-17); (g_70 < 21); g_70 += 7)
            {
                step_hash(261);
                for (g_7 = 0; (g_7 < 29); ++g_7)
                {
                    step_hash(260);
                    (**l_353) = func_21(g_271);
                }
                step_hash(262);
                (*g_6) = ((g_271 | (g_248 == ((unsigned char)((unsigned)4294967295UL % (unsigned)((short)g_312 << (short)(&p_9 != (*g_203)))) / (unsigned char)((unsigned short)p_10 << (unsigned short)9)))) >= p_10);
            }
            step_hash(264);
            (**g_203) = func_21(p_10);
            step_hash(265);
            (*g_329) &= (((*g_203) != (*g_203)) != (0x33CBL & g_312));
        }
        step_hash(267);
        (*g_6) ^= ((unsigned char)p_10 - (unsigned char)(*l_365));
        step_hash(311);
        if (((0x3EL ^ (0x7861L != (*l_365))) || (*l_358)))
        {
            unsigned l_413 = 4294967289UL;
            int *l_419 = &g_312;
            step_hash(269);
            (*l_365) = ((unsigned)((unsigned char)0UL - (unsigned char)g_271) % (unsigned)(-(int)(((int)func_41(g_28, l_419, l_420, l_420, &l_419) / (int)l_413) < 4294967288UL)));
        }
        else
        {
            int *l_427 = (void*)0;
            int l_428 = (-1L);
            unsigned l_429 = 0x62E70A77L;
            step_hash(271);
            (*g_329) = ((short)((((unsigned char)(p_10 || ((signed char)(0x15214DAFL == g_271) << (signed char)6)) >> (unsigned char)((*l_365) | p_10)) < l_428) | l_429) + (short)l_428);
            step_hash(272);
            (*g_203) = (*g_203);
            step_hash(309);
            if (p_10)
            {
                int **l_435 = &l_377;
                step_hash(274);
                (*g_6) = ((signed char)g_248 * (signed char)((*g_203) != l_435));
                step_hash(275);
                l_439 ^= (((((0xC75A7728L | (-(unsigned short)((((*l_358) && ((*l_358) ^ g_7)) != ((short)p_10 >> (short)9)) < (g_28 != ((&g_204 != (void*)0) || 0x9597B686L))))) == p_10) > g_7) != g_312) || g_248);
            }
            else
            {
                unsigned char l_444 = 1UL;
                int *l_476 = &g_7;
                step_hash(287);
                if (((unsigned short)((*g_204) != p_9) % (unsigned short)g_271))
                {
                    step_hash(278);
                    (*g_204) = (*g_204);
                }
                else
                {
                    step_hash(285);
                    for (l_439 = 0; (l_439 > (-6)); l_439 -= 4)
                    {
                        step_hash(283);
                        (*l_358) = (3L >= (l_444 < ((signed char)(-(int)(*g_329)) / (signed char)5L)));
                        step_hash(284);
                        if (p_10)
                            break;
                    }
                    step_hash(286);
                    (*g_204) = (*g_204);
                }
                step_hash(288);
                (*l_430) |= ((unsigned char)(~(((unsigned short)l_444 << (unsigned short)1) & 0x83L)) + (unsigned char)p_10);
                step_hash(307);
                for (l_374 = 0; (l_374 <= 26); l_374 += 1)
                {
                    int l_454 = 3L;
                    int *l_455 = (void*)0;
                    int **l_457 = (void*)0;
                    int l_475 = 0x3296AF75L;
                }
                step_hash(308);
                (*g_6) = (*l_365);
            }
            step_hash(310);
            (*l_358) = (*g_329);
        }
        step_hash(312);
        (**l_353) = (*g_204);
    }
    step_hash(314);
    (*l_358) = ((short)p_10 - (short)(g_271 <= ((unsigned short)((*l_358) || 1L) * (unsigned short)0x4600L)));
    step_hash(329);
    if ((((signed char)((void*)0 == &g_204) * (signed char)(*l_365)) && (*l_358)))
    {
        step_hash(322);
        for (g_70 = 0; (g_70 < 27); ++g_70)
        {
            int l_492 = 9L;
            step_hash(319);
            p_9 = (**l_353);
            step_hash(320);
            l_492 = ((signed char)(((0x40L & ((l_492 > g_7) <= p_10)) ^ (((short)p_10 >> (short)(0xC281L == ((void*)0 == (*l_353)))) == (-1L))) > p_10) >> (signed char)g_271);
            step_hash(321);
            (*l_358) = 0xF185857AL;
        }
    }
    else
    {
        step_hash(328);
        for (l_414 = 0; (l_414 >= 1); l_414 += 1)
        {
            int *l_497 = &g_7;
            step_hash(327);
            l_497 = func_11(p_9);
        }
    }
    step_hash(330);
    return p_10;
}
static int * func_11(int * p_12)
{
    unsigned char l_339 = 0x1BL;
    int l_340 = 0x343EB088L;
    step_hash(240);
    (*g_329) ^= 0xCA18A4ECL;
    step_hash(241);
    l_340 = ((l_339 <= l_339) ^ g_271);
    step_hash(242);
    (*g_203) = &g_104;
    step_hash(243);
    return (**g_203);
}
static int * func_13(int * p_14, int p_15)
{
    unsigned char l_335 = 0x35L;
    int *l_338 = (void*)0;
    step_hash(236);
    (*p_14) = (*p_14);
    step_hash(237);
    p_14 = &p_15;
    step_hash(238);
    return l_338;
}
static int * func_16(unsigned p_17, short p_18)
{
    int *l_20 = &g_7;
    int **l_19 = &l_20;
    step_hash(2);
    (*l_19) = &g_7;
    step_hash(6);
    (*l_19) = func_21(p_17);
    step_hash(233);
    if ((((0x7C629C4DL >= g_7) && ((signed char)((&l_20 != (void*)0) >= (*l_20)) << (signed char)7)) && (*l_20)))
    {
        step_hash(13);
        for (p_18 = 26; (p_18 == (-23)); p_18 -= 1)
        {
            step_hash(11);
            (*g_6) = (-1L);
            step_hash(12);
            (*g_6) &= 0x8BC698DCL;
        }
    }
    else
    {
        int l_39 = 1L;
        int **l_272 = &g_6;
        step_hash(231);
        g_329 = func_33(l_39, (-(int)(func_41(func_47(func_21(((short)l_39 >> (short)(g_28 > g_28)))), (*l_19), &l_39, (*l_19), l_272) | g_248)), g_248, g_248, &l_20);
        step_hash(232);
        (*l_19) = func_21(p_17);
    }
    step_hash(234);
    return &g_7;
}
static int * func_21(signed char p_22)
{
    signed char l_27 = 0x0EL;
    step_hash(4);
    g_28 ^= (0x6EEAL | (((signed char)p_22 * (signed char)(0xDACDL <= (((signed char)g_7 >> (signed char)7) | g_7))) | (+l_27)));
    step_hash(5);
    return &g_7;
}
static int * func_33(unsigned p_34, int p_35, unsigned p_36, int p_37, int ** p_38)
{
    int *l_296 = &g_7;
    step_hash(216);
    for (p_36 = 0; (p_36 > 59); p_36 += 2)
    {
        int *l_297 = &g_70;
        step_hash(187);
        (*g_6) = (p_34 > g_271);
        step_hash(215);
        for (g_70 = 0; (g_70 >= 4); ++g_70)
        {
            int *l_278 = &g_7;
            step_hash(191);
            l_278 = (*p_38);
            step_hash(213);
            for (g_28 = 0; (g_28 != 7); g_28 += 6)
            {
                short l_284 = 0L;
                int *l_313 = &g_70;
            }
            step_hash(214);
            return l_296;
        }
    }
    step_hash(229);
    if (((unsigned short)func_41((g_312 > ((*p_38) != (void*)0)), (*p_38), (*p_38), (*p_38), p_38) + (unsigned short)0x89B6L))
    {
        int *l_320 = (void*)0;
        step_hash(218);
        (*p_38) = func_21((*l_296));
        step_hash(219);
        (**p_38) = (((unsigned short)((int)(*l_296) + (int)(((unsigned short)((unsigned char)p_35 + (unsigned char)g_70) + (unsigned short)(+p_35)) < p_37)) * (unsigned short)g_7) || p_36);
        step_hash(220);
        (**p_38) &= (-(unsigned char)255UL);
    }
    else
    {
        step_hash(228);
        for (p_34 = 0; (p_34 > 19); ++p_34)
        {
            int *l_328 = &g_70;
            step_hash(225);
            (*p_38) = (*p_38);
            step_hash(226);
            (**p_38) = (*l_296);
            step_hash(227);
            return l_328;
        }
    }
    step_hash(230);
    return l_296;
}
static unsigned char func_41(short p_42, int * p_43, int * p_44, int * p_45, int ** p_46)
{
    int *l_273 = (void*)0;
    step_hash(178);
    (**p_46) = 0x1734EC99L;
    step_hash(179);
    (*p_45) = 0x222683E6L;
    step_hash(180);
    l_273 = (*p_46);
    step_hash(181);
    (*g_6) = (*p_43);
    step_hash(182);
    return (*l_273);
}
static short func_47(int * p_48)
{
    int **l_53 = &g_6;
    unsigned char l_54 = 9UL;
    unsigned l_127 = 0UL;
    unsigned char l_199 = 0xEDL;
    int l_249 = 0L;
    step_hash(175);
    if (((short)(+(4294967290UL ^ (l_53 != (void*)0))) - (short)l_54))
    {
        signed char l_57 = 0xFDL;
        step_hash(17);
        (*p_48) = ((unsigned char)l_57 * (unsigned char)(**l_53));
        step_hash(18);
        (*p_48) = ((unsigned char)((l_57 == 0x9FL) < ((unsigned char)l_57 / (unsigned char)l_57)) * (unsigned char)0x49L);
    }
    else
    {
        int l_67 = 1L;
        int **l_77 = &g_6;
        int l_82 = 0L;
        unsigned l_103 = 0xBB1179EFL;
        int l_166 = (-6L);
        step_hash(172);
        if ((*p_48))
        {
            unsigned short l_88 = 0xA040L;
            int *l_107 = &l_82;
            int ***l_182 = &l_77;
            unsigned l_197 = 0x6AE705E6L;
            step_hash(21);
            (*p_48) = (((void*)0 != &g_7) || (&p_48 != l_53));
            step_hash(84);
            if ((**l_53))
            {
                unsigned short l_66 = 65535UL;
                step_hash(36);
                for (g_7 = 0; (g_7 != (-16)); g_7 -= 3)
                {
                    unsigned l_87 = 0UL;
                    step_hash(26);
                    l_66 = (g_7 == ((unsigned short)g_28 - (unsigned short)g_7));
                    step_hash(34);
                    if (l_67)
                    {
                        int *l_68 = (void*)0;
                        int *l_69 = &g_70;
                        step_hash(28);
                        (*l_69) = (*g_6);
                    }
                    else
                    {
                        short l_71 = 0x0716L;
                        int **l_72 = (void*)0;
                        int *l_74 = &g_7;
                        int **l_73 = &l_74;
                        step_hash(30);
                        (*l_73) = func_21(l_71);
                        step_hash(31);
                        if ((*g_6))
                            continue;
                        step_hash(32);
                        l_82 ^= (((unsigned short)((l_77 == l_53) >= ((unsigned short)((*g_6) == ((unsigned short)(((*p_48) && g_28) != (&p_48 != &p_48)) >> (unsigned short)12)) * (unsigned short)(**l_77))) - (unsigned short)(g_7 & g_70)) ^ (-1L));
                        step_hash(33);
                        (*l_73) = func_21(g_28);
                    }
                    step_hash(35);
                    l_88 = ((unsigned)((unsigned short)(**l_53) / (unsigned short)l_87) + (unsigned)l_66);
                }
                step_hash(53);
                if ((((&g_6 != (void*)0) <= (0x5C30L | ((g_7 & ((**l_53) > ((+8L) & ((((**l_77) != 0x4896B3C8L) && (0UL & (**l_53))) > 246UL)))) || g_7))) && 4294967286UL))
                {
                    unsigned l_94 = 4294967292UL;
                    step_hash(43);
                    for (l_66 = 0; (l_66 < 34); l_66 += 5)
                    {
                        int *l_93 = &l_82;
                        step_hash(41);
                        (*l_93) |= (*p_48);
                        step_hash(42);
                        (*g_6) = (l_94 && (0x7B54C1CEL || ((signed char)(((((*l_93) & g_28) ^ (**l_77)) | ((0xA6L == (**l_53)) & g_28)) >= (+((unsigned short)((l_88 | l_94) != g_28) << (unsigned short)8))) - (signed char)1UL)));
                    }
                    step_hash(48);
                    for (g_28 = (-27); (g_28 != 29); g_28 += 6)
                    {
                        step_hash(47);
                        return g_7;
                    }
                }
                else
                {
                    short l_120 = 0x31D7L;
                    int l_128 = (-3L);
                    step_hash(50);
                    g_104 = func_21((g_7 <= ((unsigned short)l_66 / (unsigned short)l_103)));
                    step_hash(51);
                    (*g_104) &= (((unsigned)(l_107 != &g_70) - (unsigned)0UL) == 0x34387970L);
                    step_hash(52);
                    l_128 |= (g_28 && (((**l_77) ^ (((unsigned char)((short)((int)((unsigned short)(((unsigned short)(l_120 ^ (((unsigned short)l_66 * (unsigned short)((((signed char)g_28 * (signed char)((signed char)0x42L * (signed char)((**l_77) < (**l_53)))) && ((&g_70 != p_48) | l_120)) & 0xAD9A11D3L)) ^ g_7)) / (unsigned short)g_7) <= (**l_77)) + (unsigned short)l_127) - (int)(-8L)) - (short)(**l_77)) % (unsigned char)g_70) != 0xF8L)) != (*g_104)));
                }
                step_hash(54);
                (**l_53) &= l_66;
            }
            else
            {
                short l_133 = (-7L);
                int *l_136 = &g_70;
                step_hash(56);
                (*p_48) = ((unsigned short)g_70 << (unsigned short)2);
                step_hash(57);
                g_104 = func_21((*l_107));
                step_hash(82);
                if (((signed char)l_133 >> (signed char)((signed char)(l_136 != (void*)0) << (signed char)5)))
                {
                    unsigned char l_147 = 0x6DL;
                    int ***l_174 = &l_53;
                    step_hash(65);
                    for (l_103 = (-2); (l_103 <= 34); ++l_103)
                    {
                        int **l_152 = &l_136;
                        step_hash(62);
                        (*l_107) ^= (((short)1L << (short)((unsigned char)((unsigned short)((**l_53) ^ (((((signed char)l_147 % (signed char)0x77L) <= g_70) > ((void*)0 != &p_48)) < g_28)) * (unsigned short)(((unsigned char)(((unsigned char)g_28 >> (unsigned char)g_28) & g_28) - (unsigned char)(*l_136)) && g_70)) << (unsigned char)g_28)) > 0xDFL);
                        step_hash(63);
                        (*l_152) = func_21((**l_53));
                        step_hash(64);
                        g_104 = (void*)0;
                    }
                    step_hash(76);
                    if ((*g_6))
                    {
                        unsigned short l_159 = 0UL;
                        step_hash(67);
                        (*l_107) ^= ((short)g_70 << (short)11);
                        step_hash(68);
                        p_48 = func_21(((signed char)(**l_53) + (signed char)(*l_107)));
                        step_hash(69);
                        (*l_136) = ((unsigned short)(((void*)0 != l_107) >= (**l_53)) % (unsigned short)(**l_77));
                        step_hash(70);
                        (*l_136) = (((l_159 < g_28) <= (g_70 ^ (((unsigned char)l_147 * (unsigned char)((unsigned)((signed char)g_70 << (signed char)3) + (unsigned)(l_166 != (251UL ^ (**l_53))))) <= l_159))) < l_159);
                    }
                    else
                    {
                        int *l_169 = &g_70;
                        int **l_170 = (void*)0;
                        int **l_171 = &g_104;
                        step_hash(72);
                        p_48 = func_21(((short)0x1A9CL << (short)7));
                        step_hash(73);
                        (*l_171) = l_169;
                        step_hash(74);
                        (*l_171) = &g_70;
                        step_hash(75);
                        (*l_136) = (g_7 & (((signed char)(**l_53) >> (signed char)(*l_136)) & (*l_136)));
                    }
                    step_hash(77);
                    (*l_174) = &l_136;
                }
                else
                {
                    unsigned l_179 = 0x8C224E53L;
                    int *l_183 = &l_166;
                    step_hash(79);
                    p_48 = &g_70;
                    step_hash(80);
                    (*g_104) &= 0x4CD87840L;
                    step_hash(81);
                    (*l_183) ^= ((short)((((unsigned short)l_179 % (unsigned short)(((signed char)(*l_107) * (signed char)(**l_53)) && (*p_48))) && 0xF9L) & ((void*)0 == l_182)) << (short)0);
                }
                step_hash(83);
                p_48 = p_48;
            }
            step_hash(85);
            (*g_6) = (-9L);
            step_hash(93);
            if (((signed char)(***l_182) % (signed char)(~0x4CL)))
            {
                unsigned short l_186 = 0x9C59L;
                step_hash(87);
                (*l_107) &= (*p_48);
                step_hash(88);
                g_70 ^= ((((**l_77) | ((***l_182) | l_186)) < ((short)1L >> (short)g_7)) == (0xE5D6L < ((***l_182) != ((unsigned short)(((unsigned short)(((signed char)((*g_6) && ((unsigned)l_186 + (unsigned)g_28)) / (signed char)(***l_182)) || 0xFCL) * (unsigned short)l_197) != (**l_77)) << (unsigned short)12))));
            }
            else
            {
                step_hash(90);
                (*l_107) |= (*g_6);
                step_hash(91);
                (*l_107) = (*p_48);
                step_hash(92);
                l_199 ^= (g_28 & (-(int)(***l_182)));
            }
        }
        else
        {
            int **l_200 = &g_104;
            int l_213 = 0x7B67C161L;
            int *l_251 = &g_70;
            step_hash(95);
            (*l_200) = p_48;
            step_hash(96);
            (**l_77) = ((short)g_7 >> (short)6);
            step_hash(171);
            if (((void*)0 != p_48))
            {
                int l_207 = 1L;
                int l_232 = 3L;
                step_hash(98);
                (*g_204) = func_21((g_203 == &g_204));
                step_hash(103);
                for (l_54 = 18; (l_54 == 29); l_54 += 1)
                {
                    step_hash(102);
                    return l_207;
                }
                step_hash(136);
                if ((**l_200))
                {
                    int *l_212 = (void*)0;
                    step_hash(112);
                    if ((g_7 ^ ((**l_53) | ((unsigned short)g_70 - (unsigned short)((int)(*p_48) + (int)(**l_77))))))
                    {
                        step_hash(106);
                        (*l_200) = l_212;
                        step_hash(107);
                        (*g_203) = &p_48;
                        step_hash(108);
                        l_212 = (void*)0;
                    }
                    else
                    {
                        step_hash(110);
                        (***g_203) = (**l_77);
                        step_hash(111);
                        return (**l_77);
                    }
                    step_hash(113);
                    (**g_204) = (**g_204);
                    step_hash(114);
                    (**g_203) = func_21(g_28);
                    step_hash(122);
                    if ((((void*)0 != &g_204) && g_28))
                    {
                        unsigned l_214 = 0UL;
                        unsigned short l_221 = 0xE24DL;
                        step_hash(116);
                        l_213 &= (*g_6);
                        step_hash(117);
                        l_214 &= (**l_77);
                        step_hash(118);
                        (***g_203) &= (p_48 == l_212);
                        step_hash(119);
                        (*p_48) = (g_7 && ((((unsigned short)((((unsigned short)(((g_70 == l_207) > ((unsigned short)((p_48 == p_48) == ((l_207 > 0x346EL) & l_207)) + (unsigned short)l_221)) != 0xEBL) >> (unsigned short)g_7) || 4UL) ^ (**l_53)) - (unsigned short)l_221) == g_70) > g_7));
                    }
                    else
                    {
                        step_hash(121);
                        (**l_53) = (&g_204 == (void*)0);
                    }
                }
                else
                {
                    step_hash(128);
                    for (g_70 = 0; (g_70 <= 4); g_70 += 2)
                    {
                        step_hash(127);
                        (*l_200) = func_21(g_70);
                    }
                    step_hash(129);
                    (***g_203) = (**l_200);
                    step_hash(135);
                    for (l_166 = 29; (l_166 > (-11)); l_166--)
                    {
                        unsigned l_230 = 4294967292UL;
                        int *l_231 = &l_213;
                        step_hash(133);
                        (*l_231) &= ((int)((short)l_230 >> (short)((*p_48) & 0x11894CECL)) / (int)0xAF6FDADEL);
                        step_hash(134);
                        (*l_231) &= (**g_204);
                    }
                }
                step_hash(137);
                l_232 ^= 0x9798A6DBL;
            }
            else
            {
                unsigned short l_235 = 0x387BL;
                int ***l_250 = &l_200;
                step_hash(143);
                for (l_166 = 0; (l_166 == 12); l_166 += 5)
                {
                    step_hash(142);
                    return l_235;
                }
                step_hash(154);
                for (g_28 = (-6); (g_28 == 54); g_28 += 4)
                {
                    step_hash(151);
                    for (l_54 = (-19); (l_54 < 7); l_54++)
                    {
                        step_hash(150);
                        (**g_203) = (*g_204);
                    }
                    step_hash(152);
                    (**g_204) = (*g_104);
                    step_hash(153);
                    return g_28;
                }
                step_hash(159);
                for (g_7 = (-24); (g_7 >= 17); g_7++)
                {
                    step_hash(158);
                    l_249 = ((unsigned short)((signed char)(((short)(**l_200) * (short)g_248) ^ g_7) << (signed char)0) >> (unsigned short)7);
                }
                step_hash(170);
                if (((void*)0 != l_250))
                {
                    step_hash(167);
                    if ((*p_48))
                    {
                        step_hash(162);
                        (*g_6) = (!(*g_104));
                    }
                    else
                    {
                        step_hash(164);
                        (***l_250) = 0L;
                        step_hash(165);
                        (*g_6) = (**l_77);
                        step_hash(166);
                        l_251 = func_21((***l_250));
                    }
                }
                else
                {
                    unsigned char l_258 = 0x66L;
                    step_hash(169);
                    (*g_104) = ((unsigned char)((**l_77) < (p_48 == p_48)) * (unsigned char)((*p_48) == ((signed char)g_70 + (signed char)(((short)((**l_77) && l_258) + (short)g_28) > ((signed char)((((g_70 | 0x60L) > (*p_48)) | (*p_48)) | (**l_53)) + (signed char)0x22L)))));
                }
            }
        }
        step_hash(173);
        l_249 ^= ((((unsigned short)((*g_203) != l_77) % (unsigned short)((short)((int)((*p_48) < ((*p_48) || 7L)) - (int)(g_248 <= (0L && ((unsigned char)(p_48 == p_48) >> (unsigned char)g_7)))) / (short)(**l_77))) ^ (*g_6)) > (**l_77));
        step_hash(174);
        g_271 &= (!(*p_48));
    }
    step_hash(176);
    return l_249;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_7, "g_7", print_hash_value);
    transparent_crc(g_28, "g_28", print_hash_value);
    transparent_crc(g_70, "g_70", print_hash_value);
    transparent_crc(g_248, "g_248", print_hash_value);
    transparent_crc(g_271, "g_271", print_hash_value);
    transparent_crc(g_312, "g_312", print_hash_value);
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
