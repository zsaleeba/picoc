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
static int g_2 = (-4L);
static int *g_40 = &g_2;
static int **g_39 = &g_40;
static int g_63 = 0x7BDE5156L;
static int g_95 = 0xE1600452L;
static unsigned g_176 = 4294967295UL;
static unsigned g_221 = 0xAC3D2276L;
static unsigned char g_277 = 0xF2L;
static int g_300 = 0x6D31335AL;
static unsigned short g_359 = 0x618FL;
static int g_367 = 0xDD253935L;
static unsigned short g_374 = 0xDBE7L;
static int g_403 = (-10L);
static unsigned short g_449 = 0xDF23L;
static unsigned char g_507 = 0x61L;
static unsigned func_1(void);
static int func_7(int p_8, unsigned p_9, unsigned p_10, int p_11, unsigned p_12);
static int func_13(unsigned short p_14, unsigned short p_15, int p_16, int p_17, unsigned char p_18);
static signed char func_23(unsigned char p_24, int p_25);
static unsigned short func_31(int p_32, unsigned short p_33);
static int func_36(int p_37, int ** p_38);
static signed char func_41(int p_42, int p_43, unsigned char p_44, int ** p_45, short p_46);
static unsigned char func_55(int p_56, short p_57, short p_58, short p_59, int p_60);
static int * func_64(int ** p_65, int p_66, int p_67, int ** p_68, short p_69);
static int * func_75(int p_76, int ** p_77);
static unsigned func_1(void)
{
    unsigned l_6 = 7UL;
    unsigned char l_466 = 7UL;
    int *l_472 = &g_367;
    int ***l_479 = &g_39;
    int l_491 = 0x95FC5889L;
    step_hash(294);
    for (g_2 = 0; (g_2 > 24); g_2 += 1)
    {
        short l_28 = (-10L);
        int *l_431 = (void*)0;
        unsigned char l_456 = 0xD1L;
        int ***l_467 = &g_39;
        signed char l_511 = (-8L);
    }
    step_hash(295);
    (**g_39) ^= ((**l_479) != (**l_479));
    step_hash(296);
    return g_63;
}
static int func_7(int p_8, unsigned p_9, unsigned p_10, int p_11, unsigned p_12)
{
    int l_420 = 0x0AC639BBL;
    int ***l_425 = (void*)0;
    step_hash(232);
    if (p_8)
    {
        int *l_408 = &g_63;
        step_hash(223);
        (*l_408) &= 0x88A73BF4L;
        step_hash(228);
        for (g_277 = 0; (g_277 <= 5); ++g_277)
        {
            signed char l_411 = 0xC0L;
            step_hash(227);
            return l_411;
        }
    }
    else
    {
        unsigned char l_423 = 0UL;
        int ***l_424 = &g_39;
        int *l_428 = &g_367;
        step_hash(230);
        (*l_428) ^= ((signed char)p_12 / (signed char)((short)(((short)((signed char)l_420 / (signed char)(((short)l_423 * (short)p_11) | (l_423 | ((+(l_424 == l_425)) < ((((unsigned short)g_2 * (unsigned short)((void*)0 == &p_8)) & g_221) || p_9))))) << (short)3) == g_374) >> (short)15));
        step_hash(231);
        (*l_428) |= (((void*)0 == &g_40) || ((g_277 | p_10) > (((void*)0 == l_425) ^ p_9)));
    }
    step_hash(233);
    return g_367;
}
static int func_13(unsigned short p_14, unsigned short p_15, int p_16, int p_17, unsigned char p_18)
{
    signed char l_344 = 0x3FL;
    int *l_392 = &g_63;
    step_hash(219);
    for (p_14 = 0; (p_14 < 25); p_14++)
    {
        int **l_345 = &g_40;
        short l_346 = 0L;
        int *l_354 = &g_2;
        short l_400 = 0xE9ACL;
        step_hash(174);
        g_63 = (((signed char)(4294967295UL | (((short)(((unsigned)((short)((p_15 <= g_95) <= ((-8L) >= 0xAA05L)) - (short)l_344) - (unsigned)(*g_40)) == p_18) << (short)l_346) && 0x3855L)) * (signed char)(**l_345)) ^ l_344);
        step_hash(217);
        for (g_221 = 0; (g_221 >= 46); g_221++)
        {
            unsigned l_349 = 1UL;
            int **l_380 = (void*)0;
            int *l_393 = &g_95;
            step_hash(216);
            if (l_349)
            {
                step_hash(193);
                for (l_349 = 6; (l_349 <= 19); l_349 += 6)
                {
                    int l_365 = (-2L);
                    step_hash(186);
                    for (p_17 = 7; (p_17 == (-29)); p_17 -= 2)
                    {
                        step_hash(185);
                        (*l_345) = l_354;
                    }
                    step_hash(192);
                    for (g_277 = 0; (g_277 > 17); g_277++)
                    {
                        int *l_360 = &g_63;
                        int *l_366 = &g_367;
                        step_hash(190);
                        (*l_366) ^= ((g_359 & (((l_360 != (void*)0) >= func_23(l_349, ((signed char)p_18 * (signed char)g_300))) <= ((int)((l_349 || g_2) & g_2) + (int)0x1F6F16E7L))) != l_365);
                        step_hash(191);
                        if (p_15)
                            continue;
                    }
                }
            }
            else
            {
                step_hash(195);
                (*l_345) = &p_16;
                step_hash(215);
                for (p_17 = 0; (p_17 >= 11); p_17++)
                {
                    unsigned char l_372 = 0x82L;
                    int *l_383 = (void*)0;
                    step_hash(205);
                    for (g_367 = 0; (g_367 != 9); ++g_367)
                    {
                        unsigned l_381 = 0UL;
                        int l_382 = 0x43FA7BD6L;
                        step_hash(202);
                        l_382 = ((l_372 & 0xDDL) == (-(unsigned char)(g_63 >= 0x1894L)));
                        step_hash(203);
                        (**l_345) = (((func_55(g_2, g_367, g_300, l_344, g_300) || ((void*)0 != l_383)) != (((signed char)(p_15 ^ l_381) * (signed char)p_16) < 0xE245L)) >= p_16);
                        step_hash(204);
                        return l_344;
                    }
                    step_hash(206);
                    (*l_392) |= (((short)((unsigned char)((p_18 > ((short)(**l_345) - (short)g_221)) <= (l_392 == l_393)) + (unsigned char)g_367) + (short)((unsigned)((void*)0 != &p_16) - (unsigned)((signed char)p_18 / (signed char)1L))) != g_2);
                    step_hash(207);
                    (*l_345) = l_392;
                    step_hash(214);
                    if (g_403)
                    {
                        step_hash(209);
                        (*l_393) = (((unsigned char)(7L > ((int)(**l_345) / (int)(*l_392))) % (unsigned char)(*l_392)) && p_16);
                        step_hash(210);
                        (*l_393) = p_15;
                        step_hash(211);
                        (*l_345) = &p_16;
                    }
                    else
                    {
                        step_hash(213);
                        (*l_345) = &p_16;
                    }
                }
            }
        }
        step_hash(218);
        (*l_392) |= (-2L);
    }
    step_hash(220);
    return (*l_392);
}
static signed char func_23(unsigned char p_24, int p_25)
{
    int **l_313 = &g_40;
    int *l_329 = &g_63;
    step_hash(165);
    if ((*g_40))
    {
        unsigned l_316 = 7UL;
        int *l_317 = &g_63;
        step_hash(154);
        (*l_317) = ((unsigned char)l_316 >> (unsigned char)2);
    }
    else
    {
        int *l_318 = &g_63;
        unsigned char l_323 = 0x56L;
        step_hash(164);
        if ((&g_40 != (void*)0))
        {
            step_hash(157);
            (*l_313) = &g_63;
            step_hash(158);
            (*l_313) = l_318;
        }
        else
        {
            int l_319 = (-1L);
            int **l_328 = &l_318;
            step_hash(160);
            (*l_318) &= (p_24 < 65534UL);
            step_hash(161);
            (*l_313) = l_318;
            step_hash(162);
            (*l_318) = l_319;
            step_hash(163);
            (*l_328) = (*l_313);
        }
    }
    step_hash(166);
    (*l_313) = (*l_313);
    step_hash(167);
    (*l_329) &= 8L;
    step_hash(168);
    g_95 &= ((*l_329) || ((unsigned char)0xE9L << (unsigned char)(((*l_329) != p_24) != (g_63 | ((unsigned char)255UL >> (unsigned char)(&l_313 == (void*)0))))));
    step_hash(169);
    return g_63;
}
static unsigned short func_31(int p_32, unsigned short p_33)
{
    int *l_35 = (void*)0;
    int **l_34 = &l_35;
    unsigned l_226 = 0x5A92DE46L;
    signed char l_309 = 0L;
    int l_312 = 0xEA69420AL;
    step_hash(5);
    (*l_34) = (void*)0;
    step_hash(145);
    if (func_36(g_2, g_39))
    {
        unsigned char l_196 = 0x45L;
        step_hash(99);
        if (((unsigned char)(p_33 && g_95) / (unsigned char)l_196))
        {
            int l_199 = 0xB0BF173BL;
            step_hash(90);
            for (g_176 = 0; (g_176 >= 25); g_176 += 1)
            {
                step_hash(89);
                return l_199;
            }
            step_hash(91);
            (*l_34) = (void*)0;
        }
        else
        {
            int **l_209 = &g_40;
            step_hash(97);
            for (l_196 = 0; (l_196 > 51); ++l_196)
            {
                unsigned l_206 = 4294967295UL;
                int l_210 = (-4L);
                step_hash(96);
                l_210 = ((((unsigned short)g_176 / (unsigned short)(g_176 || (~((signed char)(l_206 || ((short)(-1L) >> (short)(&g_40 != l_209))) * (signed char)(l_209 == &l_35))))) ^ p_32) >= 0x12L);
            }
            step_hash(98);
            return g_95;
        }
    }
    else
    {
        int ***l_211 = &l_34;
        int *l_212 = &g_95;
        short l_220 = 1L;
        step_hash(101);
        (*l_211) = &l_35;
        step_hash(102);
        (*l_212) = 0x001B998DL;
        step_hash(144);
        for (g_95 = 0; (g_95 >= (-3)); g_95 -= 8)
        {
            int *l_215 = &g_63;
            step_hash(106);
            g_63 |= (&l_34 == &l_34);
            step_hash(107);
            (*l_215) &= (&g_39 != &g_39);
            step_hash(108);
            (*l_215) &= (g_2 < g_95);
        }
    }
    step_hash(150);
    if (p_33)
    {
        int l_305 = 0L;
        int **l_306 = &l_35;
        int l_310 = 0x284332C9L;
        step_hash(147);
        g_95 |= ((unsigned)((short)p_32 / (short)0xD74CL) / (unsigned)l_310);
    }
    else
    {
        unsigned l_311 = 2UL;
        step_hash(149);
        l_312 ^= (((((p_32 || ((((5L > l_311) || (&l_35 == &g_40)) >= l_311) & l_311)) && g_221) == l_311) | 0xBDD3L) < 1L);
    }
    step_hash(151);
    return p_33;
}
static int func_36(int p_37, int ** p_38)
{
    unsigned l_61 = 0UL;
    int *l_107 = &g_95;
    unsigned short l_167 = 0UL;
    int *l_177 = &g_95;
    unsigned l_185 = 4294967293UL;
    step_hash(81);
    if (((func_41((((signed char)((void*)0 != p_38) << (signed char)((unsigned short)((signed char)((unsigned char)func_55(g_2, p_37, l_61, p_37, (l_61 <= (0xC1C73B01L >= (0xF851L && l_61)))) >> (unsigned char)g_2) * (signed char)l_61) + (unsigned short)0x1C25L)) & l_61), g_2, g_2, &g_40, p_37) < 0x2FL) != l_61))
    {
        int **l_88 = &g_40;
        int *l_89 = &g_63;
        step_hash(25);
        for (p_37 = 0; (p_37 >= (-19)); p_37--)
        {
            step_hash(24);
            l_88 = p_38;
        }
        step_hash(26);
        (*l_89) = l_61;
    }
    else
    {
        signed char l_92 = 0xB2L;
        int **l_96 = &g_40;
        unsigned char l_113 = 0x49L;
        int *l_146 = &g_2;
        int l_148 = (-3L);
        int l_155 = 3L;
        step_hash(28);
        (*p_38) = (*g_39);
        step_hash(29);
        g_95 &= func_55((p_37 || func_41((**p_38), (((unsigned short)((p_37 >= l_92) || l_61) - (unsigned short)(0xF1L <= ((unsigned short)((-1L) & (&g_40 != (void*)0)) >> (unsigned short)g_2))) & (**p_38)), l_92, &g_40, p_37)), p_37, p_37, g_2, g_2);
        step_hash(80);
        if (((l_92 == ((g_63 & p_37) > l_61)) == g_63))
        {
            signed char l_116 = (-1L);
            int *l_133 = (void*)0;
            int l_156 = (-10L);
            unsigned l_172 = 4294967295UL;
            signed char l_175 = 0x41L;
            step_hash(68);
            if (((void*)0 == l_96))
            {
                unsigned char l_110 = 255UL;
                int l_118 = (-1L);
                int *l_126 = &g_63;
                int l_130 = 0x845370BFL;
                step_hash(62);
                if (((signed char)(-8L) - (signed char)((unsigned short)((l_61 >= g_95) == p_37) + (unsigned short)((unsigned short)((short)func_55((g_2 != ((unsigned)((void*)0 != l_107) / (unsigned)func_41((**p_38), func_55(((signed char)(0xECD02AC2L == 4294967295UL) << (signed char)3), p_37, p_37, p_37, (**l_96)), g_95, p_38, g_95))), g_2, g_2, p_37, l_110) % (short)5L) / (unsigned short)0x812EL))))
                {
                    unsigned l_117 = 0x86D35063L;
                    step_hash(33);
                    (*l_107) ^= (-1L);
                    step_hash(40);
                    if ((l_110 == ((**l_96) <= (l_113 != (!func_55(g_95, (func_55(func_55((**l_96), p_37, g_2, g_95, ((func_55((((*g_39) != (*g_39)) | 0UL), l_116, g_95, l_117, l_116) > g_95) > p_37)), g_95, (**l_96), g_2, l_118) >= (**p_38)), g_95, p_37, (**l_96)))))))
                    {
                        step_hash(35);
                        (*l_107) = (l_117 || (l_116 & (l_118 <= (func_41(l_117, ((short)((*g_39) == (void*)0) >> (short)(+p_37)), p_37, p_38, (**l_96)) || p_37))));
                    }
                    else
                    {
                        step_hash(37);
                        (*l_107) |= (*g_40);
                        step_hash(38);
                        (*g_39) = (*g_39);
                        step_hash(39);
                        (*l_107) = 0xB11E678BL;
                    }
                }
                else
                {
                    int *l_123 = &g_95;
                    unsigned short l_129 = 0x92F2L;
                    step_hash(42);
                    (*p_38) = func_75(func_41((**l_96), ((0x3AL ^ p_37) || (((short)func_55((*l_107), (l_123 != (*g_39)), ((short)(func_55(((l_126 == (void*)0) == ((unsigned short)(+(+func_55((*l_126), (*l_123), p_37, p_37, l_129))) + (unsigned short)g_95)), g_2, p_37, g_95, p_37) ^ 1UL) >> (short)p_37), l_116, g_2) % (short)p_37) || g_63)), l_130, p_38, g_2), g_39);
                    step_hash(49);
                    for (l_92 = (-4); (l_92 != (-13)); --l_92)
                    {
                    }
                    step_hash(55);
                    for (l_110 = (-10); (l_110 > 7); ++l_110)
                    {
                        step_hash(53);
                        (*l_123) |= (func_55((p_38 == (void*)0), (**l_96), p_37, p_37, g_2) & (((l_96 != l_96) | 65529UL) == 0xC8L));
                        step_hash(54);
                        if ((*l_123))
                            break;
                    }
                    step_hash(61);
                    for (g_95 = 24; (g_95 != 20); g_95 -= 9)
                    {
                        int **l_147 = (void*)0;
                        step_hash(59);
                        (*l_126) ^= l_148;
                        step_hash(60);
                        (*g_39) = func_64(&g_40, ((((((unsigned)p_37 - (unsigned)0xC86C8505L) == (p_37 | (g_95 >= (7UL != g_63)))) && ((signed char)0x13L / (signed char)(-1L))) != (*l_107)) ^ p_37), (**g_39), &g_40, (*l_123));
                    }
                }
                step_hash(63);
                (*l_107) |= (**g_39);
                step_hash(64);
                l_133 = func_75(p_37, &g_40);
                step_hash(65);
                l_156 |= func_55(func_55(g_95, g_2, (*l_126), (p_37 < ((signed char)(g_2 <= g_95) >> (signed char)(((void*)0 == &l_146) | (*l_133)))), g_95), p_37, l_155, p_37, p_37);
            }
            else
            {
                step_hash(67);
                (*l_107) = (((signed char)((**l_96) || ((short)0x2ABAL >> (short)14)) * (signed char)p_37) && (p_38 != &g_40));
            }
            step_hash(69);
            (*l_107) = (((short)p_37 * (short)((((signed char)(((int)l_167 - (int)(*l_107)) > (g_95 || ((unsigned char)(((int)(*g_40) - (int)(*g_40)) < g_63) * (unsigned char)((l_172 > ((signed char)(**l_96) % (signed char)0x6DL)) ^ l_175)))) << (signed char)g_2) >= g_176) || p_37)) && g_2);
            step_hash(70);
            (*l_107) = (p_37 ^ func_55(p_37, (*l_107), (*l_146), g_95, g_95));
        }
        else
        {
            step_hash(72);
            (*g_39) = l_177;
            step_hash(73);
            (*g_39) = (*l_96);
            step_hash(78);
            for (l_148 = 0; (l_148 < (-4)); l_148--)
            {
                int ***l_180 = &g_39;
                step_hash(77);
                (*l_180) = (void*)0;
            }
            step_hash(79);
            (*l_96) = (*p_38);
        }
    }
    step_hash(82);
    (*l_177) = (*g_40);
    step_hash(83);
    return (*g_40);
}
static signed char func_41(int p_42, int p_43, unsigned char p_44, int ** p_45, short p_46)
{
    int l_74 = 0x07675E6DL;
    int *l_85 = (void*)0;
    step_hash(18);
    l_85 = func_64(p_45, (*g_40), (((signed char)((void*)0 == p_45) + (signed char)(g_2 != ((unsigned char)g_2 / (unsigned char)func_55(p_42, p_43, g_2, l_74, p_44)))) >= (*g_40)), &g_40, p_42);
    step_hash(19);
    return g_2;
}
static unsigned char func_55(int p_56, short p_57, short p_58, short p_59, int p_60)
{
    int *l_62 = &g_63;
    step_hash(8);
    (*l_62) = 0x8592840CL;
    step_hash(9);
    return g_2;
}
static int * func_64(int ** p_65, int p_66, int p_67, int ** p_68, short p_69)
{
    step_hash(16);
    (*p_68) = func_75((((*p_65) != (void*)0) & 0x02L), p_68);
    step_hash(17);
    return (*p_68);
}
static int * func_75(int p_76, int ** p_77)
{
    unsigned l_82 = 4294967295UL;
    int **l_83 = &g_40;
    int *l_84 = &g_63;
    step_hash(13);
    (*l_84) |= (g_2 <= ((unsigned short)(p_76 && ((short)g_2 + (short)(l_82 | (((void*)0 != &g_40) != 0x3044B131L)))) % (unsigned short)((p_76 < (l_83 != l_83)) | (**l_83))));
    step_hash(14);
    p_77 = &l_84;
    step_hash(15);
    return (*g_39);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_63, "g_63", print_hash_value);
    transparent_crc(g_95, "g_95", print_hash_value);
    transparent_crc(g_176, "g_176", print_hash_value);
    transparent_crc(g_221, "g_221", print_hash_value);
    transparent_crc(g_277, "g_277", print_hash_value);
    transparent_crc(g_300, "g_300", print_hash_value);
    transparent_crc(g_359, "g_359", print_hash_value);
    transparent_crc(g_367, "g_367", print_hash_value);
    transparent_crc(g_374, "g_374", print_hash_value);
    transparent_crc(g_403, "g_403", print_hash_value);
    transparent_crc(g_449, "g_449", print_hash_value);
    transparent_crc(g_507, "g_507", print_hash_value);
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
