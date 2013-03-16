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
static int g_2 = 0xAC64A684L;
static int *g_84 = &g_2;
static int **g_83 = &g_84;
static short g_106 = 1L;
static short g_121 = (-1L);
static int g_149 = 0xDBDFE5E7L;
static int g_152 = (-6L);
static unsigned g_153 = 1UL;
static short g_159 = 4L;
static int g_160 = 0xE9BBC179L;
static int g_194 = 0x7ECFBF85L;
static int g_385 = 1L;
static int func_1(void);
static int * func_7(int * p_8, short p_9, int * p_10, int * p_11);
static int * func_13(signed char p_14, int * p_15, int p_16, unsigned p_17);
static int * func_19(signed char p_20, int * p_21, unsigned short p_22);
static int * func_23(int * p_24, unsigned p_25, unsigned short p_26, signed char p_27, int * p_28);
static signed char func_31(int * p_32);
static int * func_33(int * p_34, short p_35, short p_36, unsigned p_37, unsigned p_38);
static int * func_40(unsigned p_41, int p_42, int p_43, signed char p_44);
static unsigned char func_48(int p_49, int p_50);
static unsigned func_55(int p_56, unsigned p_57, int p_58);
static int func_1(void)
{
    unsigned l_18 = 0xB72B21A3L;
    int *l_39 = (void*)0;
    int l_482 = 1L;
    step_hash(5);
    for (g_2 = 0; (g_2 >= 23); g_2 += 1)
    {
        step_hash(4);
        return g_2;
    }
    step_hash(405);
    for (g_2 = 16; (g_2 > (-6)); g_2 -= 4)
    {
        int *l_12 = &g_2;
        int **l_473 = (void*)0;
        int **l_474 = &l_39;
        unsigned short l_483 = 0UL;
    }
    step_hash(406);
    return g_385;
}
static int * func_7(int * p_8, short p_9, int * p_10, int * p_11)
{
    int ***l_459 = (void*)0;
    int **l_463 = &g_84;
    step_hash(388);
    for (p_9 = 0; (p_9 <= (-1)); p_9 -= 5)
    {
        int ***l_460 = &g_83;
        step_hash(385);
        (*p_11) &= ((0xEFBCL != p_9) && 0x8FL);
        step_hash(386);
        (*p_11) = (*p_11);
        step_hash(387);
        (*p_11) ^= (l_459 != l_460);
    }
    step_hash(389);
    (*l_463) = func_19(((int)(&g_84 == l_463) + (int)(*p_8)), &g_385, (((((void*)0 != l_463) > p_9) != (&g_83 == (void*)0)) && g_153));
    step_hash(395);
    for (p_9 = 18; (p_9 <= (-23)); --p_9)
    {
        int *l_466 = &g_194;
        step_hash(393);
        (*p_11) = ((((g_106 || p_9) ^ 65535UL) && 0xDDC4F765L) > p_9);
        step_hash(394);
        (*l_466) = (*p_11);
    }
    step_hash(396);
    return p_10;
}
static int * func_13(signed char p_14, int * p_15, int p_16, unsigned p_17)
{
    int *l_456 = &g_385;
    step_hash(380);
    return l_456;
}
static int * func_19(signed char p_20, int * p_21, unsigned short p_22)
{
    int *l_455 = &g_194;
    step_hash(377);
    l_455 = l_455;
    step_hash(378);
    return &g_2;
}
static int * func_23(int * p_24, unsigned p_25, unsigned short p_26, signed char p_27, int * p_28)
{
    int l_323 = (-1L);
    int *l_344 = &g_194;
    int ***l_388 = &g_83;
    int l_397 = 5L;
    int ***l_415 = (void*)0;
    int *l_454 = &g_385;
    step_hash(324);
    if ((p_26 || (((((unsigned char)func_48(l_323, ((short)g_160 * (short)g_194)) >> (unsigned char)6) & g_149) | (g_160 ^ ((signed char)g_160 + (signed char)g_160))) > l_323)))
    {
        int *l_328 = &g_194;
        int ***l_329 = (void*)0;
        int ***l_330 = (void*)0;
        int l_331 = 6L;
        unsigned l_341 = 0x533FD097L;
        short l_373 = 0x9551L;
        step_hash(237);
        (*l_328) &= (*p_24);
        step_hash(238);
        g_83 = &p_28;
        step_hash(297);
        if ((*p_28))
        {
            unsigned short l_338 = 0UL;
            step_hash(240);
            (*g_83) = func_33((*g_83), l_331, g_149, (((int)(((int)(((unsigned short)(((((l_338 | (l_323 || ((unsigned short)p_26 + (unsigned short)(l_323 && (*l_328))))) != (((void*)0 == p_28) > g_121)) == p_27) < 0x322C7234L) && l_341) >> (unsigned short)p_27) > 0x7B33L) / (int)l_338) <= p_26) + (int)p_26) > 0UL), g_2);
            step_hash(245);
            for (l_323 = 6; (l_323 == 4); l_323 -= 1)
            {
                step_hash(244);
                return l_344;
            }
            step_hash(246);
            (*l_344) = (-1L);
            step_hash(247);
            (*l_344) = (*l_344);
        }
        else
        {
            int *l_350 = &g_194;
            step_hash(296);
            for (g_159 = (-15); (g_159 >= (-23)); --g_159)
            {
                int ***l_354 = &g_83;
                step_hash(289);
                for (p_25 = 0; (p_25 != 60); p_25++)
                {
                    int *l_349 = &g_194;
                    int ***l_357 = &g_83;
                    int l_362 = 0x00DD4813L;
                }
                step_hash(295);
                if ((*p_24))
                {
                    int *l_384 = &g_385;
                    step_hash(291);
                    (*l_384) &= ((short)(func_48((*g_84), ((!func_31(p_24)) >= (*p_24))) > ((short)p_25 / (short)((((0x83L <= p_26) & (*l_344)) & p_27) && (***l_354)))) * (short)0xDB12L);
                    step_hash(292);
                    (**l_354) = l_344;
                }
                else
                {
                    step_hash(294);
                    (*l_354) = &p_28;
                }
            }
        }
        step_hash(298);
        (*l_344) = (*p_24);
    }
    else
    {
        int l_405 = 9L;
        step_hash(315);
        if ((*g_84))
        {
            signed char l_400 = 2L;
            step_hash(312);
            if ((p_25 >= p_27))
            {
                int *l_401 = (void*)0;
                step_hash(302);
                (**l_388) = l_401;
                step_hash(307);
                for (p_27 = 0; (p_27 > (-2)); --p_27)
                {
                    step_hash(306);
                    return p_24;
                }
                step_hash(308);
                return (**l_388);
            }
            else
            {
                int *l_404 = &g_2;
                step_hash(310);
                (**l_388) = p_24;
                step_hash(311);
                (*g_83) = l_404;
            }
        }
        else
        {
            step_hash(314);
            return p_24;
        }
        step_hash(316);
        (*l_344) = l_405;
        step_hash(323);
        for (g_121 = 12; (g_121 >= 28); ++g_121)
        {
            int l_408 = (-1L);
            int **l_413 = &l_344;
            step_hash(320);
            l_408 |= (*l_344);
            step_hash(321);
            l_408 &= ((unsigned short)((~((g_121 && (!p_25)) < 0xD8C2L)) | (((int)(((&g_84 == l_413) <= (((void*)0 == (*g_83)) <= (-(unsigned short)((void*)0 == l_415)))) || 0x3F51L) % (int)l_405) >= g_194)) >> (unsigned short)p_26);
            step_hash(322);
            return (*g_83);
        }
    }
    step_hash(373);
    if ((p_26 != g_2))
    {
        step_hash(326);
        return p_28;
    }
    else
    {
        short l_443 = 0x4421L;
        int **l_444 = &l_344;
        step_hash(372);
        for (p_26 = 4; (p_26 != 49); p_26 += 3)
        {
            step_hash(348);
            for (g_153 = 12; (g_153 > 16); g_153++)
            {
                step_hash(347);
                for (g_121 = 24; (g_121 != (-5)); --g_121)
                {
                    unsigned l_426 = 0x1E380211L;
                    step_hash(345);
                    if (((unsigned)(&g_83 == (void*)0) % (unsigned)(*p_28)))
                    {
                        int *l_424 = &g_2;
                        step_hash(338);
                        (**l_388) = l_424;
                        step_hash(339);
                        if ((*g_84))
                            break;
                    }
                    else
                    {
                        int *l_425 = &g_385;
                        step_hash(341);
                        (*g_83) = l_425;
                        step_hash(342);
                        l_426 ^= (((***l_388) || (*p_28)) > (*g_84));
                        step_hash(343);
                        p_24 = p_28;
                        step_hash(344);
                        (*g_83) = (*g_83);
                    }
                    step_hash(346);
                    return p_28;
                }
            }
            step_hash(366);
            if ((p_25 == (-4L)))
            {
                step_hash(350);
                return p_28;
            }
            else
            {
                unsigned char l_433 = 6UL;
                step_hash(359);
                for (g_160 = 0; (g_160 < 9); g_160 += 1)
                {
                    short l_429 = 0xDBBFL;
                    int l_432 = 1L;
                    step_hash(355);
                    (*l_344) = l_429;
                    step_hash(356);
                    l_432 = ((short)p_25 + (short)(g_149 <= 0x8BL));
                }
                step_hash(364);
                for (g_159 = (-14); (g_159 <= (-16)); g_159 -= 6)
                {
                    int l_442 = 0x337ED4D8L;
                    int l_445 = 0x9D4DC154L;
                    step_hash(363);
                    l_445 |= (g_153 < (((((void*)0 != &g_83) & (l_442 == ((l_443 && (&p_24 != (*l_388))) | ((l_444 == &p_28) <= g_2)))) | (*l_344)) == (**l_444)));
                }
                step_hash(365);
                (**l_444) &= (((unsigned short)g_121 * (unsigned short)g_149) & p_25);
            }
            step_hash(371);
            for (p_25 = 0; (p_25 <= 12); p_25 += 4)
            {
                step_hash(370);
                return p_28;
            }
        }
    }
    step_hash(374);
    (*l_344) = ((unsigned char)g_159 << (unsigned char)((signed char)g_153 / (signed char)func_31(p_28)));
    step_hash(375);
    return l_454;
}
static signed char func_31(int * p_32)
{
    unsigned char l_310 = 0x09L;
    int ***l_313 = &g_83;
    int l_320 = 4L;
    step_hash(233);
    l_320 ^= ((signed char)((((signed char)l_310 / (signed char)((signed char)(l_313 == l_313) % (signed char)(***l_313))) & (((((unsigned char)((((~(***l_313)) && ((signed char)func_48(((void*)0 != (*l_313)), ((int)(***l_313) + (int)(***l_313))) >> (signed char)1)) & (***l_313)) == (***l_313)) - (unsigned char)(-7L)) >= 0x0F07L) && (*g_84)) == g_149)) && (***l_313)) + (signed char)g_153);
    step_hash(234);
    return (***l_313);
}
static int * func_33(int * p_34, short p_35, short p_36, unsigned p_37, unsigned p_38)
{
    short l_47 = 0x38F7L;
    step_hash(230);
    (*g_83) = func_40((((unsigned char)(g_2 >= l_47) * (unsigned char)func_48(l_47, l_47)) || l_47), func_48((((unsigned short)g_121 >> (unsigned short)1) >= ((unsigned short)l_47 * (unsigned short)l_47)), g_106), l_47, l_47);
    step_hash(231);
    return p_34;
}
static int * func_40(unsigned p_41, int p_42, int p_43, signed char p_44)
{
    int l_303 = (-1L);
    step_hash(228);
    for (g_106 = (-12); (g_106 <= (-23)); g_106 -= 9)
    {
        step_hash(225);
        if ((*g_84))
            break;
        step_hash(226);
        l_303 ^= p_41;
        step_hash(227);
        (*g_83) = (*g_83);
    }
    step_hash(229);
    return (*g_83);
}
static unsigned char func_48(int p_49, int p_50)
{
    int l_59 = (-1L);
    int **l_179 = &g_84;
    int *l_181 = &g_2;
    int l_235 = 0x7E4DE94CL;
    int *l_236 = &l_235;
    unsigned l_287 = 0UL;
    step_hash(174);
    for (p_49 = 0; (p_49 != 16); p_49 += 6)
    {
        int l_66 = 0xE1552B9CL;
        int **l_207 = &g_84;
    }
    step_hash(175);
    (*l_236) &= ((**g_83) != p_49);
    step_hash(219);
    for (l_235 = 0; (l_235 >= 28); ++l_235)
    {
        int l_239 = 0xA1477951L;
        unsigned l_244 = 4294967295UL;
        int ***l_260 = &g_83;
        int l_293 = 0xC2EF21BAL;
    }
    step_hash(220);
    return p_49;
}
static unsigned func_55(int p_56, unsigned p_57, int p_58)
{
    unsigned char l_69 = 0x06L;
    int l_76 = 0x21817887L;
    int **l_105 = &g_84;
    unsigned l_158 = 0xBBF80E55L;
    int l_178 = (-7L);
    step_hash(127);
    if (l_69)
    {
        int **l_70 = (void*)0;
        int ***l_71 = &l_70;
        step_hash(16);
        (*l_71) = l_70;
        step_hash(17);
        l_76 &= ((unsigned char)((unsigned char)l_69 >> (unsigned char)3) / (unsigned char)p_58);
    }
    else
    {
        int *l_78 = &g_2;
        int **l_77 = &l_78;
        signed char l_99 = (-1L);
        int l_101 = 0xB22F2C88L;
        step_hash(19);
        (*l_77) = &g_2;
        step_hash(20);
        p_58 = p_56;
        step_hash(125);
        if (p_58)
        {
            int *l_79 = (void*)0;
            step_hash(22);
            l_79 = &l_76;
        }
        else
        {
            int l_82 = 0x6066FA41L;
            int ***l_100 = &g_83;
            unsigned l_146 = 0UL;
            step_hash(101);
            if (((short)l_82 - (short)((g_2 & (4294967293UL == ((void*)0 != g_83))) >= 9L)))
            {
                unsigned l_87 = 0x40C50340L;
                step_hash(25);
                (*g_83) = &p_58;
                step_hash(40);
                for (p_58 = 0; (p_58 != 3); p_58 += 8)
                {
                    int *l_88 = (void*)0;
                    int *l_89 = &l_76;
                    step_hash(37);
                    if ((g_2 != 1UL))
                    {
                        step_hash(30);
                        p_56 = l_87;
                        step_hash(31);
                        (*l_77) = (void*)0;
                        step_hash(32);
                        (*l_77) = &p_56;
                        step_hash(33);
                        (**l_77) = 0x86219E20L;
                    }
                    else
                    {
                        step_hash(35);
                        (*g_83) = (void*)0;
                        step_hash(36);
                        if (p_56)
                            continue;
                    }
                    step_hash(38);
                    (*l_89) |= (l_88 != (*g_83));
                    step_hash(39);
                    (*l_89) = l_82;
                }
            }
            else
            {
                unsigned short l_96 = 65526UL;
                int **l_104 = &l_78;
                int l_124 = 0L;
                unsigned l_128 = 0x38C19694L;
                step_hash(77);
                if ((p_56 ^ (((signed char)(((&g_83 == &g_83) && (p_56 > ((void*)0 == &g_83))) != p_58) % (signed char)0xE7L) >= ((((unsigned char)l_82 >> (unsigned char)p_58) == l_96) & g_2))))
                {
                    step_hash(43);
                    (*g_83) = (*g_83);
                    step_hash(50);
                    for (p_57 = 7; (p_57 >= 33); p_57 += 6)
                    {
                        step_hash(47);
                        if ((**g_83))
                            break;
                        step_hash(48);
                        (*g_83) = (*g_83);
                        step_hash(49);
                        l_99 = (*g_84);
                    }
                }
                else
                {
                    step_hash(60);
                    if ((l_100 != (void*)0))
                    {
                        int *l_102 = &l_101;
                        step_hash(53);
                        l_101 = (&g_84 == (*l_100));
                        step_hash(54);
                        p_58 = (**g_83);
                        step_hash(55);
                        (*l_102) ^= p_56;
                    }
                    else
                    {
                        step_hash(57);
                        (*g_83) = (*l_77);
                        step_hash(58);
                        (*g_83) = &p_58;
                        step_hash(59);
                        (**l_100) = (*g_83);
                    }
                    step_hash(61);
                    g_106 &= (-(int)(l_104 == l_105));
                    step_hash(68);
                    for (p_57 = 0; (p_57 == 58); p_57 += 2)
                    {
                        int *l_111 = (void*)0;
                        int *l_112 = &l_82;
                        step_hash(65);
                        (*l_112) |= ((unsigned)p_56 % (unsigned)(**g_83));
                        step_hash(66);
                        (*l_77) = &p_56;
                        step_hash(67);
                        return p_58;
                    }
                    step_hash(76);
                    if (((((unsigned char)p_57 * (unsigned char)((unsigned char)g_2 << (unsigned char)((**l_104) ^ p_56))) || ((+((unsigned char)p_57 / (unsigned char)(+p_57))) > ((unsigned char)p_57 + (unsigned char)p_57))) <= (&g_84 != (void*)0)))
                    {
                        step_hash(70);
                        g_121 |= (*g_84);
                    }
                    else
                    {
                        step_hash(72);
                        (*l_104) = (void*)0;
                        step_hash(73);
                        (**l_100) = (*g_83);
                        step_hash(74);
                        (*l_77) = (void*)0;
                        step_hash(75);
                        p_58 = 0x6C9F35CDL;
                    }
                }
                step_hash(78);
                p_56 = ((p_58 != ((**l_105) ^ ((p_56 != 4294967295UL) <= (((((-1L) & ((unsigned char)(***l_100) + (unsigned char)1UL)) == p_57) <= g_2) < l_124)))) == p_56);
                step_hash(99);
                if (p_56)
                {
                    signed char l_138 = 0x6EL;
                    int *l_154 = (void*)0;
                    int *l_155 = &l_76;
                    step_hash(88);
                    if ((**g_83))
                    {
                        int *l_125 = &l_82;
                        step_hash(81);
                        (*l_125) = (***l_100);
                        step_hash(82);
                        p_56 |= (!(((short)(l_128 != (&l_125 == l_105)) + (short)0xCA51L) != g_121));
                        step_hash(83);
                        (*l_105) = (*g_83);
                    }
                    else
                    {
                        unsigned char l_133 = 249UL;
                        int *l_141 = &l_82;
                        step_hash(85);
                        (*l_141) = (g_121 <= (((unsigned short)g_2 * (unsigned short)g_2) > (g_121 <= ((((unsigned short)(***l_100) + (unsigned short)l_133) || ((signed char)((short)l_138 >> (short)(((((short)p_56 % (short)(p_57 || (**l_105))) == p_56) || 3UL) <= 0xE9E5L)) * (signed char)0xE4L)) >= 0xC0L))));
                        step_hash(86);
                        (*l_141) = ((*g_83) != (void*)0);
                        step_hash(87);
                        return p_56;
                    }
                    step_hash(89);
                    p_58 = ((unsigned char)p_56 << (unsigned char)(~((unsigned short)((l_146 >= p_56) | ((unsigned char)g_121 >> (unsigned char)6)) * (unsigned short)g_149)));
                    step_hash(95);
                    for (l_99 = 0; (l_99 <= (-14)); l_99 -= 2)
                    {
                        step_hash(93);
                        g_152 = (**g_83);
                        step_hash(94);
                        g_153 = p_57;
                    }
                    step_hash(96);
                    (*l_155) |= p_58;
                }
                else
                {
                    step_hash(98);
                    (*l_77) = (**l_100);
                }
                step_hash(100);
                (*l_105) = (*l_105);
            }
            step_hash(102);
            g_159 &= ((-7L) | (l_76 && (((g_152 && ((unsigned)(0xFAL | g_149) - (unsigned)(&g_84 == l_105))) & (0L == ((p_56 | g_152) | l_158))) == 0xE0F15406L)));
            step_hash(123);
            if ((g_153 < 0xBFC5L))
            {
                int *l_161 = &l_76;
                step_hash(104);
                (*l_161) = g_160;
                step_hash(120);
                if (p_56)
                {
                    unsigned l_162 = 0xD81DF02EL;
                    int **l_166 = &g_84;
                    step_hash(114);
                    if (l_162)
                    {
                        unsigned l_163 = 0xB9073E8DL;
                        step_hash(107);
                        l_163 = (g_2 < (g_149 <= 0x376BL));
                        step_hash(108);
                        p_58 = 0x74B8878BL;
                        step_hash(109);
                        (*l_161) &= l_162;
                    }
                    else
                    {
                        step_hash(111);
                        (**l_100) = (void*)0;
                        step_hash(112);
                        l_76 |= ((p_58 & (&l_77 == &g_83)) ^ (g_149 < p_56));
                        step_hash(113);
                        return g_121;
                    }
                    step_hash(115);
                    (*l_161) = 1L;
                    step_hash(116);
                    (*l_161) = ((short)((void*)0 == l_166) / (short)g_160);
                }
                else
                {
                    step_hash(118);
                    (*l_77) = (void*)0;
                    step_hash(119);
                    p_56 = ((unsigned)g_159 + (unsigned)(g_149 > 0UL));
                }
            }
            else
            {
                step_hash(122);
                return g_2;
            }
            step_hash(124);
            p_58 = ((unsigned char)251UL * (unsigned char)(g_160 ^ p_57));
        }
        step_hash(126);
        (*g_83) = (*g_83);
    }
    step_hash(128);
    l_178 |= (l_158 >= (((int)((short)(-1L) - (short)0xC43AL) % (int)(((p_56 | (p_57 || ((!((unsigned char)(l_105 != l_105) / (unsigned char)p_58)) & (-(unsigned)g_160)))) <= 0xC57F21A0L) & g_106)) | l_76));
    step_hash(129);
    return g_2;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_106, "g_106", print_hash_value);
    transparent_crc(g_121, "g_121", print_hash_value);
    transparent_crc(g_149, "g_149", print_hash_value);
    transparent_crc(g_152, "g_152", print_hash_value);
    transparent_crc(g_153, "g_153", print_hash_value);
    transparent_crc(g_159, "g_159", print_hash_value);
    transparent_crc(g_160, "g_160", print_hash_value);
    transparent_crc(g_194, "g_194", print_hash_value);
    transparent_crc(g_385, "g_385", print_hash_value);
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
