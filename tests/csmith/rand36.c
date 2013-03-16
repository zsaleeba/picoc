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
static int g_2 = 1L;
static int g_81 = (-1L);
static int g_84 = (-5L);
static int g_90 = (-1L);
static int **g_99 = (void*)0;
static unsigned g_135 = 3UL;
static unsigned short g_148 = 65534UL;
static int g_350 = 0x03ED47F7L;
static int g_491 = 5L;
static unsigned char g_515 = 0x49L;
static int *g_552 = &g_84;
static int **g_551 = &g_552;
static int *g_626 = &g_84;
static signed char g_636 = (-9L);
static short func_1(void);
static unsigned func_12(int p_13, int p_14);
static signed char func_22(int p_23, int p_24, int p_25, int ** p_26);
static int func_27(unsigned p_28);
static short func_35(int p_36);
static int * func_37(unsigned p_38, unsigned char p_39, int p_40, int * p_41, unsigned char p_42);
static unsigned func_43(int * p_44, unsigned short p_45, int p_46);
static signed char func_64(int * p_65, int * p_66);
static int * func_67(unsigned p_68, short p_69, unsigned char p_70, int p_71, int p_72);
static unsigned char func_77(int ** p_78);
static short func_1(void)
{
    signed char l_19 = (-1L);
    signed char l_29 = 0x7FL;
    int l_559 = 0L;
    int *l_573 = &l_559;
    int *l_574 = &g_2;
    unsigned l_582 = 0xAF454D57L;
    unsigned l_598 = 4294967295UL;
    unsigned char l_602 = 1UL;
    unsigned short l_607 = 1UL;
    int l_649 = (-1L);
    step_hash(330);
    for (g_2 = 0; (g_2 <= (-9)); g_2 -= 2)
    {
        int *l_6 = (void*)0;
        int **l_5 = &l_6;
        int *l_567 = &g_81;
        signed char l_575 = (-1L);
        step_hash(4);
        (*l_5) = &g_2;
    }
    step_hash(384);
    for (l_559 = 1; (l_559 > 18); l_559 += 1)
    {
        int *l_588 = &g_2;
        unsigned char l_590 = 1UL;
        int ***l_624 = &g_551;
    }
    step_hash(385);
    l_573 = &l_559;
    step_hash(386);
    (*g_551) = func_67(g_90, ((short)g_90 << (short)8), (*l_573), (*l_574), g_2);
    step_hash(387);
    return g_135;
}
static unsigned func_12(int p_13, int p_14)
{
    step_hash(300);
    (**g_551) = (((unsigned char)p_14 * (unsigned char)4L) || g_491);
    step_hash(306);
    for (g_84 = (-15); (g_84 < 13); g_84 += 4)
    {
        int *l_564 = (void*)0;
        int *l_565 = (void*)0;
        int *l_566 = &g_81;
        step_hash(304);
        (*l_566) &= 0x63194C8EL;
        step_hash(305);
        (*g_551) = &p_14;
    }
    step_hash(307);
    return g_350;
}
static signed char func_22(int p_23, int p_24, int p_25, int ** p_26)
{
    unsigned char l_529 = 255UL;
    int *l_530 = &g_81;
    int l_553 = (-1L);
    step_hash(259);
    (*l_530) = ((unsigned short)65527UL << (unsigned short)((unsigned char)((unsigned char)p_25 >> (unsigned char)l_529) << (unsigned char)(!g_135)));
    step_hash(297);
    if ((l_530 != (void*)0))
    {
        unsigned short l_535 = 0x6D27L;
        int l_536 = 0L;
        step_hash(261);
        p_23 ^= ((int)((unsigned short)l_535 >> (unsigned short)g_84) + (int)(*l_530));
        step_hash(262);
        l_536 = 0x8102B237L;
    }
    else
    {
        unsigned short l_539 = 6UL;
        int *l_554 = &g_491;
        step_hash(288);
        if (((unsigned)g_90 / (unsigned)g_2))
        {
            step_hash(265);
            return l_539;
        }
        else
        {
            int *l_549 = &g_2;
            step_hash(287);
            for (p_24 = 14; (p_24 <= 25); p_24++)
            {
                int **l_542 = &l_530;
                int ***l_543 = (void*)0;
                int ***l_544 = &l_542;
                step_hash(270);
                (*l_544) = l_542;
                step_hash(271);
                (*l_542) = l_530;
                step_hash(285);
                for (p_25 = 19; (p_25 > 29); p_25 += 6)
                {
                    int **l_550 = (void*)0;
                    step_hash(282);
                    for (g_148 = 0; (g_148 == 3); g_148 += 6)
                    {
                        step_hash(278);
                        (**l_544) = l_549;
                        step_hash(279);
                        if ((**p_26))
                            break;
                        step_hash(280);
                        (*g_552) |= (l_550 == g_551);
                        step_hash(281);
                        p_23 ^= (&g_552 == (void*)0);
                    }
                    step_hash(283);
                    l_553 = (*l_549);
                    step_hash(284);
                    (*g_552) ^= (**p_26);
                }
                step_hash(286);
                (**l_544) = l_554;
            }
        }
        step_hash(289);
        (**g_551) ^= (*l_530);
        step_hash(295);
        for (g_135 = 20; (g_135 < 26); ++g_135)
        {
            step_hash(293);
            (*p_26) = (*g_551);
            step_hash(294);
            (*g_551) = (*p_26);
        }
        step_hash(296);
        (*l_554) = (*l_530);
    }
    step_hash(298);
    return g_84;
}
static int func_27(unsigned p_28)
{
    int l_30 = (-1L);
    int *l_517 = &g_81;
    int **l_516 = &l_517;
    step_hash(256);
    if (l_30)
    {
        unsigned l_489 = 5UL;
        int *l_490 = &g_491;
        unsigned short l_495 = 0UL;
        signed char l_506 = (-1L);
        int *l_511 = (void*)0;
        int l_512 = (-8L);
        step_hash(244);
        (*l_490) ^= (((signed char)(((short)func_35(p_28) * (short)((8UL <= (-1L)) == l_30)) != ((short)(((short)(-10L) - (short)(((unsigned short)((((l_30 < ((unsigned short)(1UL > ((1UL == l_489) | p_28)) << (unsigned short)6)) > g_2) && 0UL) || 0x9FB52959L) / (unsigned short)p_28) | p_28)) <= l_30) * (short)l_30)) / (signed char)g_2) & 1UL);
        step_hash(251);
        for (g_491 = (-10); (g_491 <= (-27)); g_491 -= 5)
        {
            int *l_494 = &l_30;
            step_hash(248);
            (*l_494) |= p_28;
            step_hash(249);
            if (p_28)
                break;
            step_hash(250);
            if (l_495)
                break;
        }
        step_hash(252);
        l_512 ^= ((unsigned char)((unsigned short)((int)p_28 % (int)((unsigned short)((unsigned)l_506 + (unsigned)((unsigned short)(g_350 <= l_30) * (unsigned short)(-1L))) * (unsigned short)((g_491 > ((*l_490) >= ((short)p_28 % (short)g_81))) ^ p_28))) - (unsigned short)3UL) << (unsigned char)5);
        step_hash(253);
        (*l_490) &= (((~(&l_512 != &l_512)) | (((((((unsigned short)(p_28 ^ p_28) >> (unsigned short)8) <= p_28) == (g_2 ^ func_64(&g_90, func_37(p_28, l_30, p_28, &l_30, p_28)))) == p_28) || g_515) ^ p_28)) <= 0x60L);
    }
    else
    {
        int ***l_518 = &l_516;
        step_hash(255);
        (*l_518) = l_516;
    }
    step_hash(257);
    return (**l_516);
}
static short func_35(int p_36)
{
    short l_462 = 1L;
    int *l_463 = (void*)0;
    unsigned l_464 = 0xFC0DC315L;
    int **l_475 = &l_463;
    int *l_478 = &g_90;
    step_hash(241);
    (*l_475) = func_37(func_43(&g_2, g_2, g_2), l_462, l_462, l_463, l_464);
    step_hash(242);
    (*l_478) = ((unsigned short)65535UL >> (unsigned short)func_77(&l_463));
    step_hash(243);
    return g_90;
}
static int * func_37(unsigned p_38, unsigned char p_39, int p_40, int * p_41, unsigned char p_42)
{
    int l_469 = 0xF47E50A9L;
    int l_470 = (-2L);
    step_hash(233);
    l_470 ^= ((unsigned char)g_81 + (unsigned char)(p_42 | ((signed char)p_42 << (signed char)l_469)));
    step_hash(239);
    for (g_81 = 15; (g_81 < 15); g_81 += 1)
    {
        int *l_473 = (void*)0;
        int *l_474 = &g_84;
        step_hash(237);
        (*l_474) = 0xA357E05EL;
        step_hash(238);
        if (g_135)
            break;
    }
    step_hash(240);
    return &g_90;
}
static unsigned func_43(int * p_44, unsigned short p_45, int p_46)
{
    short l_104 = 0xA5B8L;
    int l_159 = 0L;
    int *l_189 = (void*)0;
    int **l_188 = &l_189;
    int *l_192 = (void*)0;
    unsigned l_213 = 8UL;
    signed char l_240 = (-1L);
    int *l_241 = &l_159;
    signed char l_242 = 0x67L;
    unsigned l_246 = 4294967295UL;
    unsigned l_321 = 0x9AC3D867L;
    unsigned short l_329 = 0x9F58L;
    signed char l_440 = 5L;
    step_hash(114);
    for (p_46 = 21; (p_46 == (-5)); p_46 -= 3)
    {
        signed char l_55 = (-1L);
        int *l_141 = &g_2;
        int **l_140 = &l_141;
        int **l_174 = &l_141;
        unsigned short l_212 = 5UL;
        unsigned char l_227 = 0x57L;
        int l_239 = 1L;
        step_hash(112);
        if ((*p_44))
        {
            int *l_80 = &g_2;
            int **l_79 = &l_80;
            unsigned char l_103 = 253UL;
            signed char l_207 = 0L;
            signed char l_214 = 0x8AL;
            int *l_223 = &g_84;
            step_hash(95);
            if (g_2)
            {
                int *l_60 = (void*)0;
                int l_61 = 0L;
                step_hash(14);
                l_61 = (+((0xD50FA8FAL & ((unsigned short)g_2 % (unsigned short)((short)(~((unsigned short)0xC4B0L / (unsigned short)(l_55 && (((signed char)g_2 * (signed char)(g_2 <= 6L)) | (0xB3L | ((unsigned char)((void*)0 == &p_46) - (unsigned char)g_2)))))) + (short)0x079DL))) & p_46));
                step_hash(53);
                g_135 |= (((unsigned short)((4294967295UL < (func_64(func_67(((unsigned short)(((signed char)g_2 % (signed char)func_77(l_79)) ^ ((unsigned char)(!((&l_60 != g_99) || (-(int)(65528UL | p_45)))) >> (unsigned char)((short)(g_2 >= l_103) * (short)g_2))) * (unsigned short)l_55), l_55, g_2, l_104, p_46), &g_2) == p_46)) & p_46) * (unsigned short)l_55) && 0xA18A5C64L);
                step_hash(54);
                g_148 |= ((int)((unsigned)0UL / (unsigned)func_77(l_140)) - (int)(g_2 > ((int)(!((((unsigned)g_135 % (unsigned)(p_46 & g_135)) <= l_103) | ((((unsigned)4294967295UL - (unsigned)(*p_44)) == 0x9F135B39L) > 1L))) - (int)p_46)));
                step_hash(55);
                return g_148;
            }
            else
            {
                int **l_149 = &l_80;
                int l_197 = (-1L);
                step_hash(73);
                if (g_81)
                {
                    int *l_150 = (void*)0;
                    int *l_151 = &g_81;
                    int *l_158 = (void*)0;
                    step_hash(58);
                    (*l_151) = (&p_44 == l_149);
                    step_hash(59);
                    l_159 = (((void*)0 == &l_150) == (((short)g_148 - (short)((unsigned char)((unsigned short)((void*)0 == l_158) / (unsigned short)0xD275L) - (unsigned char)(((&p_44 == g_99) | (**l_149)) == g_84))) == g_81));
                    step_hash(60);
                    (*l_151) ^= ((signed char)((unsigned char)((void*)0 == &l_150) % (unsigned char)9L) - (signed char)(((void*)0 == &p_46) == (&l_141 != g_99)));
                }
                else
                {
                    int l_175 = 0xD4A5CD31L;
                    step_hash(69);
                    if (((((0x67L <= l_159) | (((signed char)((unsigned char)1UL % (unsigned char)((signed char)(((int)0xCA1BE135L / (int)((int)0xBB088A05L - (int)p_45)) < (*l_141)) % (signed char)l_175)) << (signed char)5) > 1L)) && g_148) > 1UL))
                    {
                        step_hash(63);
                        if ((*p_44))
                            break;
                        step_hash(64);
                        (*l_149) = (void*)0;
                        step_hash(65);
                        (*l_140) = (void*)0;
                    }
                    else
                    {
                        int l_182 = 0xB87C57D7L;
                        int ***l_183 = &g_99;
                        step_hash(67);
                        l_182 ^= ((short)(((*l_80) || ((unsigned char)((unsigned short)65526UL >> (unsigned short)10) / (unsigned char)247UL)) == 0x2B13B08BL) * (short)p_45);
                        step_hash(68);
                        (*l_183) = &p_44;
                    }
                    step_hash(70);
                    g_84 = (((unsigned char)(~l_175) / (unsigned char)l_175) && (l_188 == g_99));
                    step_hash(71);
                    (*l_174) = func_67((func_77(&l_80) >= ((signed char)(l_192 != &p_46) / (signed char)g_148)), (~g_135), (&g_2 != (*l_188)), g_2, l_175);
                    step_hash(72);
                    (*l_140) = &p_46;
                }
                step_hash(94);
                for (g_135 = 0; (g_135 >= 5); ++g_135)
                {
                    int l_215 = 0xBB184844L;
                    step_hash(83);
                    for (l_55 = 0; (l_55 >= (-27)); l_55--)
                    {
                        int *l_198 = &l_159;
                        step_hash(80);
                        l_197 &= 4L;
                        step_hash(81);
                        (*l_198) = (-1L);
                        step_hash(82);
                        l_215 = ((int)(g_90 ^ 0x477EL) - (int)(*p_44));
                    }
                }
            }
            step_hash(103);
            if (l_227)
            {
                step_hash(97);
                (*l_223) = (*p_44);
                step_hash(98);
                if ((*p_44))
                    continue;
                step_hash(99);
                (*l_188) = &p_46;
                step_hash(100);
                (*l_140) = (void*)0;
            }
            else
            {
                step_hash(102);
                return p_45;
            }
        }
        else
        {
            short l_232 = 1L;
            int *l_238 = &l_159;
            step_hash(109);
            if ((((((!(0x2AD3L <= ((((signed char)((short)l_232 % (short)p_45) >> (signed char)((0xDBL <= (*l_141)) <= ((p_45 || (((((signed char)((unsigned char)((p_46 == p_45) || g_2) / (unsigned char)0xFFL) >> (signed char)(**l_174)) > 6L) > p_46) && 0xDEL)) >= l_232))) <= (*p_44)) != g_2))) > p_45) < p_46) == g_81) | p_46))
            {
                step_hash(106);
                return g_81;
            }
            else
            {
                int *l_237 = &g_84;
                step_hash(108);
                (*l_237) = (**l_140);
            }
            step_hash(110);
            (*l_238) |= 0xF0672DA4L;
            step_hash(111);
            l_240 &= l_239;
        }
        step_hash(113);
        if ((*p_44))
            break;
    }
    step_hash(115);
    (*l_241) &= (*p_44);
    step_hash(230);
    if (((func_77(&l_241) | (&l_188 == (void*)0)) || l_242))
    {
        int ***l_243 = &g_99;
        int *l_249 = &g_90;
        step_hash(117);
        (*l_243) = &p_44;
        step_hash(118);
        p_46 = 0xD7AE1D0CL;
        step_hash(119);
        (*l_249) = (0xDAL | ((unsigned short)func_64(&p_46, func_67(p_46, g_81, g_90, l_246, ((int)(**g_99) % (int)0x185DD034L))) * (unsigned short)(***l_243)));
        step_hash(149);
        if (((short)((unsigned char)0x2EL >> (unsigned char)((int)(6UL & ((&p_44 != &p_44) | ((unsigned char)p_45 * (unsigned char)((((void*)0 == l_243) != (**g_99)) && ((short)(func_64(func_67((((***l_243) || (*l_249)) >= p_45), p_46, (***l_243), p_46, p_46), (*g_99)) & g_2) * (short)0xCB06L))))) % (int)g_148)) >> (short)14))
        {
            unsigned short l_274 = 0x0E7BL;
            int **l_275 = &l_241;
            step_hash(121);
            (**l_243) = func_67(g_148, ((unsigned short)p_45 % (unsigned short)g_135), ((short)((signed char)p_46 / (signed char)((unsigned short)((+255UL) | ((***l_243) != ((short)(((short)(g_84 && ((***l_243) && (((signed char)(g_2 < 0UL) / (signed char)l_274) & (*p_44)))) + (short)g_81) != p_46) + (short)g_90))) >> (unsigned short)g_81)) - (short)g_81), p_45, g_2);
            step_hash(145);
            if (((g_135 >= func_77(l_275)) && (*p_44)))
            {
                step_hash(123);
                (**g_99) = (func_77(l_275) && p_45);
            }
            else
            {
                step_hash(129);
                for (g_84 = 0; (g_84 <= 7); ++g_84)
                {
                    step_hash(128);
                    (*l_249) = (*l_249);
                }
                step_hash(130);
                (*p_44) = (*p_44);
                step_hash(131);
                (*l_249) = (-1L);
                step_hash(144);
                for (g_148 = (-1); (g_148 > 36); g_148 += 3)
                {
                    unsigned l_280 = 4294967294UL;
                    step_hash(135);
                    (*l_249) ^= ((((*p_44) ^ (*p_44)) > p_46) ^ p_46);
                    step_hash(136);
                    (*p_44) = l_280;
                    step_hash(137);
                    (**g_99) ^= ((((void*)0 == (**l_243)) > (!g_135)) | p_45);
                    step_hash(143);
                    for (l_159 = (-30); (l_159 == 11); ++l_159)
                    {
                        int *l_285 = (void*)0;
                    }
                }
            }
        }
        else
        {
            int l_286 = 1L;
            step_hash(147);
            l_286 = (*l_249);
            step_hash(148);
            (**l_243) = (*l_188);
        }
    }
    else
    {
        int ***l_307 = &g_99;
        int ***l_308 = &g_99;
        int *l_316 = (void*)0;
        int *l_317 = (void*)0;
        int *l_318 = &g_84;
        unsigned l_346 = 0x5093E27FL;
        signed char l_354 = (-8L);
        int l_385 = 8L;
        step_hash(157);
        if (((short)p_45 - (short)g_148))
        {
            signed char l_297 = 1L;
            signed char l_298 = (-3L);
            int *l_311 = &g_81;
            unsigned short l_312 = 65526UL;
            step_hash(152);
            l_312 &= ((p_46 ^ g_148) == ((signed char)(((((signed char)((signed char)(!((short)l_297 + (short)l_298)) + (signed char)((signed char)((signed char)((signed char)p_46 * (signed char)((((unsigned)(l_307 != l_308) - (unsigned)((short)p_45 >> (short)5)) || (+func_64(l_311, l_311))) | g_135)) * (signed char)g_84) * (signed char)0UL)) >> (signed char)p_46) & g_148) > p_46) == 0x61L) >> (signed char)p_45));
            step_hash(153);
            (*l_311) = (*p_44);
            step_hash(154);
            p_46 = (p_45 < ((&g_99 != (void*)0) <= ((short)func_77(&p_44) >> (short)p_46)));
        }
        else
        {
            int *l_315 = &g_81;
            step_hash(156);
            (*l_188) = func_67((p_46 >= 0x30L), p_46, g_2, p_46, func_64(l_315, &g_81));
        }
        step_hash(158);
        (*l_318) ^= g_148;
        step_hash(229);
        if (((unsigned char)((&p_46 == (void*)0) ^ (l_321 > (*l_318))) << (unsigned char)p_46))
        {
            int **l_322 = &l_241;
            unsigned short l_342 = 65532UL;
            int **l_409 = &l_317;
            step_hash(160);
            (*l_322) = func_67(g_135, (func_77(l_322) != g_2), g_148, (g_99 == (void*)0), g_148);
            step_hash(216);
            if ((p_45 && (0L <= func_77(&p_44))))
            {
                unsigned l_332 = 0x13221460L;
                step_hash(162);
                (*l_188) = func_67(((short)0x5A51L >> (short)p_45), p_45, (*l_241), g_84, (**l_322));
                step_hash(169);
                for (l_104 = 0; (l_104 > 5); l_104 += 7)
                {
                    int l_339 = (-7L);
                    step_hash(166);
                    (*l_188) = func_67(((void*)0 == l_307), (g_135 >= ((short)((unsigned char)p_45 >> (unsigned char)(+l_339)) >> (short)1)), ((short)p_46 / (short)g_90), (l_339 && l_342), g_135);
                    step_hash(167);
                    (*l_189) &= ((void*)0 == (*l_188));
                    step_hash(168);
                    return l_332;
                }
                step_hash(170);
                return p_46;
            }
            else
            {
                int *l_345 = &g_81;
                int ***l_349 = &l_322;
                unsigned l_366 = 0xA46068BCL;
                unsigned short l_384 = 0x0369L;
                step_hash(177);
                for (l_242 = (-3); (l_242 >= (-24)); l_242--)
                {
                    step_hash(175);
                    p_44 = l_345;
                    step_hash(176);
                    return l_346;
                }
                step_hash(178);
                (*l_322) = (void*)0;
                step_hash(214);
                if ((((unsigned short)(((*l_345) | (!(*l_345))) < ((*l_188) == (void*)0)) * (unsigned short)(&g_99 != l_349)) & ((p_45 >= (!g_81)) ^ g_350)))
                {
                    int **l_351 = &l_192;
                    int *l_388 = &l_159;
                    step_hash(186);
                    if ((g_99 != l_351))
                    {
                        unsigned l_352 = 0x1642C3FEL;
                        step_hash(181);
                        (*l_345) ^= l_352;
                    }
                    else
                    {
                        int l_353 = 0x2D6E2AB5L;
                        step_hash(183);
                        l_353 = 0L;
                        step_hash(184);
                        (*l_188) = func_67((0x63L || (func_77(l_322) < 0x43L)), g_135, p_45, ((void*)0 != l_322), (g_2 || 0x38A7L));
                        step_hash(185);
                        return p_45;
                    }
                    step_hash(193);
                    if (g_350)
                    {
                        unsigned l_357 = 3UL;
                        int l_367 = 1L;
                        step_hash(188);
                        (*l_318) = ((l_354 | ((short)(p_45 <= (&p_44 != &p_44)) / (short)l_357)) == ((unsigned char)func_77(&p_44) << (unsigned char)g_350));
                        step_hash(189);
                        l_366 ^= ((signed char)(p_46 ^ ((unsigned char)p_46 + (unsigned char)((&p_44 != &p_44) <= 0x26L))) * (signed char)((unsigned short)g_84 * (unsigned short)((void*)0 != &p_46)));
                        step_hash(190);
                        (*l_318) = l_367;
                    }
                    else
                    {
                        step_hash(192);
                        (*l_345) = (((((short)((0x7AL != ((unsigned char)((((void*)0 != g_99) ^ ((unsigned short)((unsigned char)((signed char)g_81 >> (signed char)((unsigned char)g_81 + (unsigned char)g_84)) + (unsigned char)0xCFL) / (unsigned short)((short)(((signed char)p_46 << (signed char)g_90) || g_350) >> (short)l_384))) == g_350) + (unsigned char)g_84)) != 0x2EE7L) >> (short)4) > p_45) || l_385) > p_46);
                    }
                    step_hash(200);
                    if (g_90)
                    {
                        int l_399 = (-4L);
                        int *l_402 = (void*)0;
                        step_hash(195);
                        l_402 = func_67(((unsigned short)(func_64(l_388, func_67((((unsigned short)(((short)(((unsigned short)(((unsigned char)((*l_351) == (void*)0) * (unsigned char)(((short)(!l_399) * (short)(*l_345)) | p_46)) != (l_399 <= (((void*)0 == (**l_349)) >= 1UL))) << (unsigned short)p_45) && 0xF9L) - (short)g_90) >= (*l_345)) - (unsigned short)p_46) | p_45), p_46, (*l_318), g_148, p_46)) | g_350) % (unsigned short)g_2), p_45, g_350, g_148, g_148);
                    }
                    else
                    {
                        step_hash(197);
                        (*l_318) = ((signed char)((signed char)(l_307 != (void*)0) / (signed char)p_46) / (signed char)((((unsigned short)1UL * (unsigned short)(!g_135)) >= (l_409 == &p_44)) || ((short)g_2 * (short)(p_45 >= 0xC9L))));
                        step_hash(198);
                        (*l_388) = g_135;
                        step_hash(199);
                        (*l_409) = func_67(g_148, (*l_388), g_2, g_90, (*l_345));
                    }
                    step_hash(201);
                    (*l_388) ^= (&l_351 == &l_322);
                }
                else
                {
                    signed char l_419 = 0x3CL;
                    int l_420 = 6L;
                    step_hash(210);
                    for (g_350 = 0; (g_350 == (-14)); g_350--)
                    {
                        int ***l_416 = &l_409;
                        step_hash(206);
                        if (g_148)
                            break;
                        step_hash(207);
                        (*l_188) = (void*)0;
                        step_hash(208);
                        (**l_416) = func_67(p_45, ((signed char)p_46 * (signed char)g_90), g_350, (0UL > (((void*)0 != l_416) & ((unsigned char)((((*l_318) & 0x28L) | g_350) == 249UL) >> (unsigned char)3))), l_419);
                        step_hash(209);
                        l_420 |= (***l_416);
                    }
                    step_hash(211);
                    g_90 = (((unsigned)p_46 - (unsigned)p_45) || (g_2 & ((g_90 | ((-(unsigned short)((unsigned char)(g_350 | (((short)p_46 * (short)((void*)0 != &p_44)) >= p_46)) >> (unsigned char)g_90)) && g_135)) & p_46)));
                    step_hash(212);
                    p_46 |= ((g_99 == (*l_349)) < ((p_45 == (&g_99 == l_349)) ^ (((0UL && (-1L)) != ((signed char)g_2 - (signed char)func_77(&p_44))) || (*l_318))));
                    step_hash(213);
                    (*l_318) &= ((int)g_148 - (int)(*l_345));
                }
                step_hash(215);
                (*l_322) = func_67(g_2, (p_45 <= ((unsigned short)((short)p_45 / (short)func_77(&p_44)) << (unsigned short)4)), ((unsigned)3UL + (unsigned)0xFEA2F73BL), g_148, p_46);
            }
            step_hash(217);
            l_440 &= (**l_322);
        }
        else
        {
            unsigned l_444 = 0xF325F3E0L;
            step_hash(226);
            if ((+p_46))
            {
                signed char l_441 = 9L;
                step_hash(220);
                (*l_188) = func_67(l_441, (((+g_81) < g_84) | (1UL == (((((unsigned short)(&p_46 != &p_46) << (unsigned short)8) ^ g_350) > (g_148 | (0x010AL | l_444))) > 0xFEAAL))), l_441, g_350, l_441);
                step_hash(221);
                (*l_318) = g_84;
            }
            else
            {
                int *l_453 = (void*)0;
                step_hash(223);
                (*l_318) ^= ((short)(-5L) << (short)((void*)0 == &p_44));
                step_hash(224);
                (*l_318) = (((unsigned short)((unsigned short)(((unsigned short)(g_90 && l_444) + (unsigned short)0x1FB6L) <= g_90) >> (unsigned short)5) * (unsigned short)1UL) || g_81);
                step_hash(225);
                p_44 = &p_46;
            }
            step_hash(227);
            g_81 ^= ((signed char)((((unsigned short)g_148 >> (unsigned short)((unsigned)4294967293UL + (unsigned)g_350)) ^ 7UL) || (g_2 > g_2)) >> (signed char)4);
            step_hash(228);
            (*l_188) = &p_46;
        }
    }
    step_hash(231);
    return g_2;
}
static signed char func_64(int * p_65, int * p_66)
{
    int *l_122 = &g_90;
    step_hash(48);
    l_122 = l_122;
    step_hash(49);
    (*l_122) = (((signed char)g_2 * (signed char)(*l_122)) & ((((signed char)(*l_122) >> (signed char)g_81) > ((short)g_2 / (short)((unsigned short)((((signed char)((l_122 == (void*)0) & 0xBD1CL) / (signed char)(-5L)) ^ (*p_65)) != (*l_122)) * (unsigned short)(*l_122)))) >= g_81));
    step_hash(50);
    l_122 = p_65;
    step_hash(51);
    (*l_122) = (*p_66);
    step_hash(52);
    return g_81;
}
static int * func_67(unsigned p_68, short p_69, unsigned char p_70, int p_71, int p_72)
{
    unsigned char l_107 = 1UL;
    int *l_115 = (void*)0;
    int **l_114 = &l_115;
    int *l_116 = &g_81;
    int l_121 = 0L;
    step_hash(43);
    for (p_68 = 0; (p_68 == 41); p_68 += 4)
    {
        int *l_108 = &g_81;
        step_hash(41);
        (*l_108) |= l_107;
        step_hash(42);
        if (l_107)
            break;
    }
    step_hash(44);
    (*l_116) = (((unsigned short)p_71 - (unsigned short)(((-(signed char)(0x5961L >= 1UL)) & ((p_69 <= (l_107 > ((short)l_107 % (short)func_77(l_114)))) < g_2)) >= 7UL)) | p_69);
    step_hash(45);
    (*l_116) = (g_84 || (((&l_115 == &l_115) | ((unsigned short)(g_2 == (+((&l_116 != &l_115) >= 0xE342BA51L))) * (unsigned short)(((unsigned)0xA3AFD543L - (unsigned)p_71) == (*l_116)))) < l_121));
    step_hash(46);
    return &g_84;
}
static unsigned char func_77(int ** p_78)
{
    int l_96 = 0x0E43DA7DL;
    step_hash(34);
    for (g_81 = (-15); (g_81 < 8); ++g_81)
    {
        int l_87 = (-2L);
        step_hash(26);
        for (g_84 = 0; (g_84 > (-18)); g_84 -= 1)
        {
            int *l_88 = (void*)0;
            int *l_89 = &g_90;
            step_hash(22);
            (*p_78) = &g_84;
            step_hash(23);
            (*p_78) = (void*)0;
            step_hash(24);
            (*l_89) &= (!l_87);
            step_hash(25);
            (*l_89) = ((*l_89) <= (((unsigned char)(*l_89) << (unsigned char)0) < l_87));
        }
        step_hash(27);
        if (g_84)
            break;
        step_hash(32);
        for (g_84 = (-23); (g_84 < 1); g_84 += 6)
        {
            int *l_95 = &g_90;
            step_hash(31);
            (*l_95) = l_87;
        }
        step_hash(33);
        (*p_78) = (*p_78);
    }
    step_hash(35);
    (*p_78) = (*p_78);
    step_hash(36);
    return l_96;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_81, "g_81", print_hash_value);
    transparent_crc(g_84, "g_84", print_hash_value);
    transparent_crc(g_90, "g_90", print_hash_value);
    transparent_crc(g_135, "g_135", print_hash_value);
    transparent_crc(g_148, "g_148", print_hash_value);
    transparent_crc(g_350, "g_350", print_hash_value);
    transparent_crc(g_491, "g_491", print_hash_value);
    transparent_crc(g_515, "g_515", print_hash_value);
    transparent_crc(g_636, "g_636", print_hash_value);
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
