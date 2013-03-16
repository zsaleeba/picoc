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
static int g_2 = (-9L);
static int g_98 = 0xCAD959FCL;
static short g_130 = 0xC386L;
static int *g_143 = &g_98;
static int **g_142 = &g_143;
static int g_208 = 0x3B782AFEL;
static int **g_258 = &g_143;
static int g_272 = (-1L);
static unsigned short g_295 = 65534UL;
static int g_316 = 0L;
static unsigned short g_321 = 0xFED3L;
static int g_464 = 0x371B4ADBL;
static int g_503 = 0L;
static unsigned short g_532 = 0x2DD5L;
static int **g_540 = (void*)0;
static int *g_560 = &g_503;
static int g_634 = 0L;
static int *g_641 = &g_634;
static int func_1(void);
static signed char func_5(unsigned p_6, int p_7, unsigned short p_8, unsigned short p_9, unsigned short p_10);
static short func_18(short p_19, int p_20, int p_21, unsigned p_22, int p_23);
static unsigned func_39(int * p_40, unsigned char p_41);
static int * func_42(int p_43, int * p_44, short p_45, int * p_46);
static int * func_59(int * p_60, unsigned char p_61, short p_62);
static int * func_63(int * p_64, unsigned short p_65, int * p_66, unsigned short p_67);
static int * func_68(int * p_69, int * p_70, unsigned p_71, unsigned p_72);
static unsigned func_73(unsigned p_74, int * p_75);
static unsigned func_78(unsigned p_79, int p_80, int * p_81);
static int func_1(void)
{
    unsigned short l_24 = 9UL;
    int ***l_561 = &g_540;
    int l_570 = (-1L);
    unsigned l_594 = 0x1B8BC197L;
    unsigned l_623 = 1UL;
    unsigned short l_624 = 1UL;
    unsigned l_627 = 3UL;
    int *l_628 = &g_316;
    int *l_643 = (void*)0;
    step_hash(392);
    for (g_2 = 0; (g_2 < (-6)); --g_2)
    {
        unsigned short l_11 = 2UL;
        int l_34 = (-5L);
        int *l_562 = &g_503;
        int ***l_569 = &g_258;
        int *l_593 = &g_503;
        short l_595 = (-5L);
        int l_608 = 0L;
    }
    step_hash(393);
    (*g_142) = (*g_258);
    step_hash(423);
    if ((func_5(g_321, (&g_142 == l_561), func_18(l_24, (((func_5(g_532, l_623, g_503, l_624, ((signed char)g_532 - (signed char)g_321)) == g_98) != 1UL) <= 0xFAL), g_532, g_464, l_627), l_570, g_464) & 0L))
    {
        int *l_629 = &g_98;
        int l_630 = (-8L);
        step_hash(395);
        (**g_258) = (*g_143);
        step_hash(396);
        (*g_258) = func_68(func_68(l_628, (*g_142), (*l_628), g_272), l_629, g_532, g_98);
        step_hash(397);
        return l_630;
    }
    else
    {
        unsigned l_638 = 1UL;
        int *l_640 = (void*)0;
        signed char l_642 = 0xCDL;
        step_hash(419);
        if ((+(*l_628)))
        {
            int *l_631 = &g_272;
            step_hash(400);
            (**g_258) |= (func_39(l_631, g_130) ^ ((&g_142 == (void*)0) != (((unsigned char)(!(g_634 || (0L || (0x1A553514L || (*l_631))))) * (unsigned char)g_503) > 65535UL)));
            step_hash(401);
            (*g_143) = (**g_142);
        }
        else
        {
            unsigned char l_635 = 253UL;
            step_hash(417);
            if ((g_272 >= l_635))
            {
                step_hash(404);
                return l_635;
            }
            else
            {
                step_hash(416);
                if ((*g_560))
                {
                    step_hash(407);
                    (*g_142) = (*g_258);
                }
                else
                {
                    step_hash(415);
                    for (l_627 = (-1); (l_627 == 33); ++l_627)
                    {
                        int *l_639 = &g_316;
                        step_hash(412);
                        (*g_560) &= l_638;
                        step_hash(413);
                        (*g_560) = (*g_560);
                        step_hash(414);
                        (*g_258) = l_639;
                    }
                }
            }
            step_hash(418);
            (*l_561) = &g_143;
        }
        step_hash(420);
        g_641 = l_640;
        step_hash(421);
        (*g_258) = l_640;
        step_hash(422);
        (*g_142) = (*g_258);
    }
    step_hash(424);
    return (*l_628);
}
static signed char func_5(unsigned p_6, int p_7, unsigned short p_8, unsigned short p_9, unsigned short p_10)
{
    signed char l_55 = 0x63L;
    int *l_56 = &g_2;
    step_hash(350);
    for (p_6 = 0; (p_6 == 11); p_6++)
    {
        unsigned l_47 = 4294967295UL;
        int *l_50 = &g_2;
        int l_559 = (-1L);
    }
    step_hash(351);
    return g_464;
}
static short func_18(short p_19, int p_20, int p_21, unsigned p_22, int p_23)
{
    int *l_33 = &g_2;
    step_hash(5);
    l_33 = l_33;
    step_hash(6);
    return g_2;
}
static unsigned func_39(int * p_40, unsigned char p_41)
{
    short l_558 = 9L;
    step_hash(346);
    for (g_464 = 19; (g_464 <= (-12)); g_464 -= 9)
    {
        int l_557 = 0xBD2DCFC4L;
        step_hash(345);
        return l_557;
    }
    step_hash(347);
    return l_558;
}
static int * func_42(int p_43, int * p_44, short p_45, int * p_46)
{
    int *l_281 = &g_2;
    short l_507 = 1L;
    int l_513 = 0L;
    int l_530 = 0L;
    int ***l_552 = &g_540;
    step_hash(306);
    for (p_45 = 0; (p_45 == (-2)); p_45--)
    {
        int *l_466 = &g_2;
    }
    step_hash(313);
    for (g_295 = 0; (g_295 > 48); ++g_295)
    {
        int *l_510 = &g_464;
        step_hash(310);
        (*g_142) = (void*)0;
        step_hash(311);
        (*l_510) = (~((*l_281) > ((-9L) <= ((unsigned)0x83769389L - (unsigned)p_45))));
        step_hash(312);
        (*l_510) ^= ((unsigned)0xFDEF52C4L - (unsigned)g_208);
    }
    step_hash(314);
    l_513 &= (*l_281);
    step_hash(339);
    if ((*p_44))
    {
        short l_516 = (-1L);
        int ***l_529 = &g_142;
        unsigned char l_531 = 0UL;
        int l_539 = 0x4A4D87DEL;
        short l_546 = 1L;
        step_hash(316);
        l_513 ^= ((unsigned)l_516 - (unsigned)((unsigned short)(0x7797L | ((short)((g_98 | g_316) ^ (func_18(((unsigned)((int)0x36D6C550L / (int)(((g_272 && ((signed char)((unsigned short)(l_529 != l_529) * (unsigned short)p_45) - (signed char)g_130)) != 0x00L) ^ l_530)) + (unsigned)1UL), (*l_281), p_45, g_503, l_531) || g_532)) / (short)0x2A97L)) >> (unsigned short)2));
        step_hash(317);
        l_513 = (g_208 <= (0x56L != (*l_281)));
        step_hash(328);
        for (p_45 = (-30); (p_45 == 9); ++p_45)
        {
            step_hash(327);
            for (g_464 = 0; (g_464 >= 20); ++g_464)
            {
                signed char l_545 = 1L;
                int *l_547 = &g_208;
                step_hash(324);
                (*g_142) = &l_513;
                step_hash(325);
                (*g_258) = p_44;
                step_hash(326);
                (*l_547) = ((((((short)0xC692L / (short)l_539) == (((g_540 == &g_143) <= (*p_46)) && (((!((unsigned)((((signed char)(0x5D0BEA25L | ((((p_46 != p_46) == (((&g_540 == (void*)0) | p_45) > g_316)) && p_43) && 0x42L)) * (signed char)l_545) && p_43) && (*p_44)) % (unsigned)l_546)) == p_43) | 0xFDB945C7L))) == 0L) < g_532) | 0xFFL);
            }
        }
        step_hash(329);
        return p_46;
    }
    else
    {
        int *l_548 = &g_208;
        step_hash(331);
        (*g_258) = func_59(l_548, p_45, (*l_548));
        step_hash(338);
        for (g_208 = 28; (g_208 > (-21)); g_208 -= 3)
        {
            int ***l_551 = &g_142;
            step_hash(335);
            (*g_143) = (*p_46);
            step_hash(336);
            if ((*p_44))
                break;
            step_hash(337);
            (*g_142) = func_59(func_59(p_44, p_45, (((l_551 != l_552) & ((short)p_43 * (short)g_130)) > p_45)), g_272, p_45);
        }
    }
    step_hash(340);
    return p_46;
}
static int * func_59(int * p_60, unsigned char p_61, short p_62)
{
    int *l_504 = &g_316;
    step_hash(302);
    (*g_142) = (*g_258);
    step_hash(303);
    return l_504;
}
static int * func_63(int * p_64, unsigned short p_65, int * p_66, unsigned short p_67)
{
    int *l_467 = &g_208;
    int ***l_487 = &g_142;
    step_hash(265);
    (*l_467) = (*p_66);
    step_hash(299);
    for (g_208 = 0; (g_208 == (-11)); g_208--)
    {
        int *l_472 = &g_272;
        int l_473 = 8L;
    }
    step_hash(300);
    return (*g_258);
}
static int * func_68(int * p_69, int * p_70, unsigned p_71, unsigned p_72)
{
    int *l_463 = &g_2;
    int l_465 = (-4L);
    step_hash(260);
    g_464 ^= ((signed char)0L * (signed char)func_73((-(signed char)g_208), l_463));
    step_hash(261);
    l_465 = ((void*)0 == &g_143);
    step_hash(262);
    (*g_142) = p_69;
    step_hash(263);
    return l_463;
}
static unsigned func_73(unsigned p_74, int * p_75)
{
    unsigned l_283 = 0xEDBE4E10L;
    int l_294 = 0x8A34B86BL;
    short l_302 = 0L;
    unsigned char l_367 = 0xA5L;
    int *l_370 = (void*)0;
    int *l_380 = (void*)0;
    int *l_381 = &g_316;
    int l_388 = 0x101206E4L;
    int l_438 = 0xCA283457L;
    unsigned l_459 = 3UL;
    step_hash(216);
    if ((*p_75))
    {
        unsigned char l_303 = 0UL;
        int **l_326 = &g_143;
        signed char l_354 = (-5L);
        step_hash(196);
        if ((0UL | (p_74 | ((unsigned short)((unsigned short)(func_18(g_98, g_2, (((unsigned)(+(((void*)0 != &l_294) < 0x47A8L)) / (unsigned)p_74) > l_302), l_303, (*p_75)) > l_303) / (unsigned short)p_74) - (unsigned short)p_74))))
        {
            int *l_313 = (void*)0;
            step_hash(156);
            for (l_303 = (-16); (l_303 == 35); l_303 += 9)
            {
                int *l_306 = (void*)0;
                int *l_307 = (void*)0;
                int *l_308 = &g_208;
                step_hash(149);
                (*l_308) = (*p_75);
                step_hash(150);
                (*l_308) |= g_98;
                step_hash(155);
                for (g_208 = 0; (g_208 != 24); g_208 += 8)
                {
                    step_hash(154);
                    (*g_142) = p_75;
                }
            }
        }
        else
        {
            unsigned short l_322 = 9UL;
            step_hash(177);
            for (g_316 = (-13); (g_316 != 6); g_316 += 6)
            {
                int *l_325 = &g_272;
                int **l_336 = &l_325;
                step_hash(161);
                g_321 ^= l_303;
                step_hash(176);
                if (l_322)
                {
                    int *l_323 = (void*)0;
                    int *l_324 = &g_272;
                    step_hash(163);
                    l_294 = (*p_75);
                    step_hash(164);
                    (*l_324) = (*p_75);
                    step_hash(165);
                    (*g_142) = l_325;
                }
                else
                {
                    step_hash(167);
                    g_142 = l_326;
                    step_hash(175);
                    if ((((signed char)((&g_143 == &p_75) > g_98) * (signed char)l_322) != (l_302 || (*p_75))))
                    {
                        unsigned l_331 = 8UL;
                        int *l_343 = (void*)0;
                        step_hash(169);
                        (*l_325) = (*p_75);
                        step_hash(170);
                        l_294 ^= 6L;
                        step_hash(171);
                        (*l_325) = (((unsigned char)l_331 - (unsigned char)((short)((signed char)g_295 / (signed char)g_316) << (short)((&p_75 == l_336) < (~((unsigned short)((signed char)func_18((+g_316), (g_98 < ((unsigned char)(l_343 == (void*)0) >> (unsigned char)g_130)), g_321, g_272, l_302) << (signed char)7) >> (unsigned short)p_74))))) != l_283);
                    }
                    else
                    {
                        step_hash(173);
                        (*l_336) = p_75;
                        step_hash(174);
                        if ((*p_75))
                            break;
                    }
                }
            }
            step_hash(178);
            l_354 = (func_18(l_322, (((unsigned short)p_74 - (unsigned short)p_74) && ((unsigned short)((((p_74 && (((((signed char)((g_2 < p_74) == 1UL) * (signed char)((unsigned char)((unsigned)g_272 + (unsigned)((0L ^ g_98) > 0x62L)) >> (unsigned char)g_130)) & l_322) <= l_283) == g_98)) && l_294) != 0xF62EL) == (*p_75)) >> (unsigned short)l_294)), p_74, p_74, (*p_75)) == l_302);
            step_hash(195);
            for (g_272 = 0; (g_272 != (-10)); g_272 -= 6)
            {
                int *l_359 = (void*)0;
                int *l_360 = &g_316;
                step_hash(182);
                if ((*p_75))
                    break;
                step_hash(183);
                l_294 ^= 0L;
                step_hash(184);
                (*l_360) = (((short)p_74 * (short)0x57AAL) | l_294);
                step_hash(194);
                for (l_303 = 0; (l_303 != 31); l_303 += 6)
                {
                    step_hash(193);
                    for (l_354 = 0; (l_354 > (-14)); --l_354)
                    {
                        step_hash(191);
                        (*l_360) ^= (p_75 != p_75);
                        step_hash(192);
                        (*l_326) = p_75;
                    }
                }
            }
        }
        step_hash(203);
        for (g_130 = 3; (g_130 > 29); g_130 += 3)
        {
            short l_368 = 0x0AF9L;
            int ***l_369 = &l_326;
            step_hash(200);
            l_294 &= func_18(g_2, g_2, (&p_75 != &p_75), l_367, (*p_75));
            step_hash(201);
            l_368 &= (*p_75);
            step_hash(202);
            (*l_369) = &p_75;
        }
        step_hash(204);
        (*g_258) = l_370;
        step_hash(205);
        (*l_326) = p_75;
    }
    else
    {
        int *l_371 = &l_294;
        step_hash(207);
        (*l_371) = (0x08FE410DL > g_98);
        step_hash(214);
        for (g_321 = 0; (g_321 != 4); ++g_321)
        {
            unsigned short l_378 = 65534UL;
            int ***l_379 = (void*)0;
            step_hash(211);
            (*l_371) = ((~(((((short)((((short)l_378 % (short)g_272) <= (((void*)0 == l_379) == ((*p_75) && 0xE4177E30L))) >= (p_74 && (*l_371))) >> (short)14) & p_74) == p_74) || p_74)) | 0xE166L);
            step_hash(212);
            (*l_371) &= 0x9EFFC97FL;
            step_hash(213);
            return p_74;
        }
        step_hash(215);
        p_75 = l_371;
    }
    step_hash(217);
    (*l_381) &= (*p_75);
    step_hash(256);
    if ((((unsigned)(p_75 != &l_294) / (unsigned)g_130) && 0x948DL))
    {
        int **l_394 = &l_370;
        unsigned l_452 = 0xA5CA3130L;
        step_hash(252);
        if (((g_295 == p_74) != (g_208 == 0xC7D3L)))
        {
            int **l_395 = &l_380;
            int l_453 = 0x505894CCL;
            step_hash(226);
            for (p_74 = (-3); (p_74 > 15); p_74 += 9)
            {
                unsigned char l_391 = 0x47L;
                short l_396 = 0xFD82L;
                step_hash(223);
                (*l_381) &= l_396;
                step_hash(224);
                if ((*p_75))
                    break;
                step_hash(225);
                return g_295;
            }
            step_hash(249);
            for (g_130 = 0; (g_130 == (-22)); g_130 -= 2)
            {
                signed char l_415 = (-10L);
                int l_426 = 0x696564DBL;
                unsigned l_437 = 6UL;
                step_hash(234);
                for (g_208 = 0; (g_208 >= (-16)); g_208--)
                {
                    step_hash(233);
                    return p_74;
                }
                step_hash(247);
                for (g_208 = 0; (g_208 != 9); g_208 += 1)
                {
                    int **l_409 = &l_381;
                    step_hash(244);
                    for (g_295 = 0; (g_295 == 51); g_295++)
                    {
                        int ***l_414 = &l_395;
                        step_hash(241);
                        (*l_381) |= (*p_75);
                        step_hash(242);
                        (*l_381) = (((0xA4F5L >= g_316) == (((unsigned short)0xD928L << (unsigned short)2) > (func_18(p_74, ((short)(((void*)0 == l_409) != (((short)((signed char)(l_414 == &l_395) * (signed char)p_74) >> (short)p_74) && g_321)) - (short)g_2), p_74, p_74, l_415) && 0x7C60L))) && p_74);
                        step_hash(243);
                        (*l_381) = (-1L);
                    }
                    step_hash(245);
                    l_438 ^= ((short)(((unsigned char)(!(func_18(g_272, g_295, g_98, ((unsigned char)((unsigned short)(0x06L > ((((unsigned char)l_426 << (unsigned char)((((((short)((unsigned short)(((short)(((void*)0 != p_75) >= 0UL) + (short)(func_18((~((short)((signed char)((void*)0 == p_75) << (signed char)3) << (short)9)), (**l_409), g_2, g_208, (*p_75)) <= (*p_75))) ^ l_437) / (unsigned short)(*l_381)) << (short)g_295) || 0xA8B326D2L) >= (-7L)) <= g_272) == p_74)) && p_74) ^ g_295)) * (unsigned short)0L) >> (unsigned char)g_321), (*l_381)) != 0xEE4BL)) % (unsigned char)p_74) < (*l_381)) + (short)(*l_381));
                    step_hash(246);
                    (*l_381) = (**l_409);
                }
                step_hash(248);
                (*l_381) = ((signed char)((*p_75) < func_18(p_74, ((short)((signed char)(p_74 | g_98) * (signed char)(func_18(((signed char)g_2 >> (signed char)((unsigned char)(-(unsigned)g_208) % (unsigned char)(1L ^ ((((unsigned char)p_74 % (unsigned char)func_18(p_74, p_74, g_98, p_74, l_452)) ^ 1L) ^ 65532UL)))), p_74, g_130, p_74, l_453) | 0xDF6AL)) % (short)(-1L)), g_316, p_74, l_415)) * (signed char)g_208);
            }
        }
        else
        {
            int ***l_454 = &g_142;
            step_hash(251);
            (*l_381) = (l_454 != &g_258);
        }
        step_hash(253);
        return p_74;
    }
    else
    {
        step_hash(255);
        (*l_381) ^= (*p_75);
    }
    step_hash(257);
    (*l_381) = ((((p_74 ^ (&l_438 == &l_294)) <= 0UL) || ((((unsigned char)(((unsigned short)(((&l_294 != (void*)0) || 0xACD0L) != ((p_74 < ((p_74 || g_321) | 1UL)) || 1UL)) * (unsigned short)p_74) < 2UL) + (unsigned char)0x53L) != 1UL) > 0x8A50L)) != l_459);
    step_hash(258);
    return p_74;
}
static unsigned func_78(unsigned p_79, int p_80, int * p_81)
{
    signed char l_82 = 0x71L;
    int *l_96 = (void*)0;
    int l_237 = 1L;
    unsigned l_240 = 0x7D8C89FAL;
    short l_247 = (-9L);
    int *l_249 = &g_98;
    unsigned l_270 = 3UL;
    unsigned char l_279 = 0UL;
    unsigned short l_280 = 1UL;
    step_hash(132);
    if ((l_82 && (l_82 && func_18(((unsigned short)(p_79 > ((unsigned short)p_79 << (unsigned short)p_79)) + (unsigned short)((short)((-(signed char)(g_2 <= ((+(((unsigned short)(l_82 == ((short)(func_18(((unsigned char)l_82 / (unsigned char)(((&g_2 == l_96) >= p_79) | l_82)), g_2, p_79, g_2, g_2) == p_79) + (short)g_2)) / (unsigned short)l_82) || g_2)) <= (*p_81)))) < l_82) + (short)g_2)), p_79, g_2, l_82, g_2))))
    {
        int *l_97 = &g_98;
        unsigned char l_108 = 7UL;
        step_hash(17);
        (*l_97) &= (*p_81);
        step_hash(84);
        if ((((signed char)g_2 + (signed char)((short)0xDA12L * (short)1UL)) == func_18(((unsigned)p_79 / (unsigned)(func_18((p_80 | func_18((0xDE40C593L <= ((unsigned short)(-(unsigned)(l_96 != p_81)) << (unsigned short)12)), p_79, (*l_97), (*l_97), (*p_81))), g_2, p_80, l_108, (*l_97)) & (*l_97))), g_98, g_98, g_2, g_98)))
        {
            int **l_109 = &l_97;
            step_hash(19);
            (*l_109) = l_96;
        }
        else
        {
            unsigned short l_129 = 0xC734L;
            int l_155 = 0xE556C3ABL;
            short l_156 = 9L;
            step_hash(21);
            g_98 = ((-(unsigned short)func_18((1L & func_18(g_2, p_80, (0x1E10L || p_80), (*l_97), g_98)), (*l_97), (*l_97), p_79, g_2)) == 65533UL);
            step_hash(53);
            if ((func_18(p_79, g_2, (~g_98), g_98, (*p_81)) != p_80))
            {
                int **l_111 = &l_96;
                unsigned char l_154 = 8UL;
                step_hash(23);
                (*l_97) = g_2;
                step_hash(24);
                (*l_111) = (void*)0;
                step_hash(50);
                if (g_2)
                {
                    int l_128 = (-1L);
                    step_hash(26);
                    (*l_97) = ((int)(&g_98 != (void*)0) / (int)p_79);
                    step_hash(34);
                    for (p_80 = 0; (p_80 <= (-28)); p_80 -= 6)
                    {
                        step_hash(30);
                        (*l_111) = p_81;
                        step_hash(31);
                        (*l_97) = func_18((((signed char)0xB8L / (signed char)((signed char)((unsigned char)p_80 << (unsigned char)(g_2 | (((void*)0 == &p_81) || g_98))) << (signed char)6)) || ((unsigned char)func_18(((void*)0 != &l_97), g_98, p_80, g_2, (*p_81)) - (unsigned char)(*l_96))), p_80, (**l_111), p_80, g_98);
                        step_hash(32);
                        if ((*l_96))
                            continue;
                        step_hash(33);
                        p_81 = l_96;
                    }
                    step_hash(35);
                    g_130 ^= func_18(p_80, func_18(((unsigned short)(0x3626L < p_79) % (unsigned short)((unsigned short)func_18((0x42L >= l_128), (func_18(((*p_81) | (&g_2 == (void*)0)), p_79, l_128, l_129, (*p_81)) == 0xF828L), g_98, p_80, g_2) << (unsigned short)12)), p_79, g_98, l_129, g_2), p_80, g_2, (*p_81));
                }
                else
                {
                    step_hash(37);
                    (*l_97) |= g_130;
                    step_hash(43);
                    for (p_80 = 0; (p_80 < (-19)); p_80--)
                    {
                        short l_135 = 0xB0D1L;
                        step_hash(41);
                        (*l_97) = ((unsigned char)(l_135 > p_80) >> (unsigned char)6);
                        step_hash(42);
                        (*l_111) = &g_98;
                    }
                    step_hash(48);
                    for (p_79 = 0; (p_79 < 11); ++p_79)
                    {
                        step_hash(47);
                        (*g_143) &= (g_130 > ((unsigned char)(g_2 | ((void*)0 == g_142)) << (unsigned char)l_129));
                    }
                    step_hash(49);
                    l_155 = (p_79 < (((unsigned short)1UL >> (unsigned short)p_79) <= (((signed char)0x21L - (signed char)((unsigned)(p_79 < func_18((~((void*)0 != p_81)), ((signed char)(-4L) % (signed char)func_18(g_2, g_130, p_79, p_79, l_154)), g_2, p_80, (*p_81))) / (unsigned)0xB083140AL)) != (**g_142))));
                }
            }
            else
            {
                step_hash(52);
                (*g_142) = l_96;
            }
            step_hash(83);
            if (l_156)
            {
                step_hash(55);
                (*g_142) = l_97;
                step_hash(56);
                l_155 ^= func_18(g_130, p_79, p_79, (p_80 && (g_130 != p_79)), ((short)0x874AL << (short)((+g_98) ^ ((*g_143) & 1L))));
                step_hash(65);
                if ((p_80 == ((unsigned short)(((unsigned short)g_130 * (unsigned short)g_2) < (*p_81)) - (unsigned short)(0xE3L < g_98))))
                {
                    int *l_163 = &l_155;
                    step_hash(58);
                    (*g_143) = ((void*)0 == (*g_142));
                    step_hash(59);
                    (*l_163) &= (*g_143);
                    step_hash(60);
                    (*g_142) = p_81;
                }
                else
                {
                    int *l_164 = &l_155;
                    step_hash(62);
                    (*l_164) |= (**g_142);
                    step_hash(63);
                    (*g_142) = (*g_142);
                    step_hash(64);
                    return p_79;
                }
            }
            else
            {
                int *l_189 = &l_155;
                step_hash(67);
                (*l_97) ^= ((int)(g_130 ^ p_79) - (int)0x466F024EL);
                step_hash(68);
                l_155 = ((signed char)0L >> (signed char)p_79);
                step_hash(82);
                if ((*p_81))
                {
                    step_hash(70);
                    (*l_97) = 0x5938EECFL;
                    step_hash(71);
                    (*g_142) = (*g_142);
                }
                else
                {
                    int *l_169 = (void*)0;
                    step_hash(73);
                    (*g_142) = l_169;
                    step_hash(81);
                    for (l_108 = 0; (l_108 != 56); ++l_108)
                    {
                        int *l_172 = &g_98;
                        int l_190 = (-10L);
                        step_hash(77);
                        (*g_142) = l_172;
                        step_hash(78);
                        l_190 &= ((&g_143 != &g_143) | ((unsigned short)((signed char)(((func_18(g_130, g_130, ((short)((signed char)0x99L * (signed char)246UL) + (short)((int)(*g_143) / (int)(((short)(((unsigned char)255UL - (unsigned char)(((short)((void*)0 != l_189) << (short)(*l_97)) ^ (*l_172))) && 0x40L) % (short)0x4892L) | p_80))), (*l_189), (*l_97)) < 1L) != g_130) < p_80) >> (signed char)p_79) - (unsigned short)g_98));
                        step_hash(79);
                        (*l_189) ^= func_18((g_2 <= g_98), ((int)func_18(p_80, ((short)0xA9D0L / (short)p_79), g_2, g_2, ((*p_81) == (((unsigned short)(p_80 != 0x3979L) * (unsigned short)0x5CF5L) && (-6L)))) % (int)(*p_81)), p_80, p_79, (*l_172));
                        step_hash(80);
                        (*g_142) = p_81;
                    }
                }
            }
        }
    }
    else
    {
        int l_226 = 1L;
        step_hash(92);
        if ((**g_142))
        {
            unsigned l_197 = 7UL;
            step_hash(87);
            (*g_142) = (*g_142);
            step_hash(88);
            return l_197;
        }
        else
        {
            int *l_198 = &g_98;
            step_hash(90);
            (*g_142) = l_96;
            step_hash(91);
            (*l_198) |= (-6L);
        }
        step_hash(131);
        for (l_82 = 10; (l_82 < (-22)); l_82--)
        {
            unsigned char l_235 = 255UL;
            int l_248 = 0x1267525AL;
            step_hash(110);
            for (g_98 = 6; (g_98 >= (-12)); --g_98)
            {
                step_hash(103);
                for (p_79 = 4; (p_79 == 7); p_79++)
                {
                    int *l_207 = &g_208;
                    step_hash(102);
                    (*l_207) &= ((unsigned)p_79 / (unsigned)1L);
                }
                step_hash(109);
                for (p_80 = 0; (p_80 >= (-10)); p_80 -= 9)
                {
                    step_hash(107);
                    (*g_142) = (*g_142);
                    step_hash(108);
                    (*g_142) = (*g_142);
                }
            }
            step_hash(128);
            for (p_80 = 0; (p_80 < (-8)); --p_80)
            {
                int *l_213 = &g_208;
                int *l_236 = &g_2;
                step_hash(114);
                (*g_142) = (void*)0;
                step_hash(115);
                (*l_213) &= 0x22FE7AF7L;
                step_hash(126);
                for (p_79 = 1; (p_79 > 46); p_79++)
                {
                    step_hash(125);
                    if ((0x96L != p_80))
                    {
                        step_hash(120);
                        (*l_213) = (((((signed char)((((unsigned char)(g_2 > (0x5CEDL > p_79)) - (unsigned char)(((unsigned short)p_79 << (unsigned short)11) && g_2)) ^ g_98) || ((signed char)p_79 / (signed char)(+p_79))) * (signed char)((unsigned char)(p_81 == l_213) << (unsigned char)l_226)) > (*l_213)) && g_130) > p_79);
                        step_hash(121);
                        (*g_142) = (*g_142);
                        step_hash(122);
                        return g_98;
                    }
                    else
                    {
                        step_hash(124);
                        return p_80;
                    }
                }
                step_hash(127);
                l_237 = ((short)((signed char)((~(((unsigned short)func_18(g_208, g_208, ((signed char)func_18(p_80, g_2, l_235, (+((g_208 < 0UL) | (l_236 == p_81))), (*l_213)) << (signed char)4), (*l_213), (*l_213)) << (unsigned short)0) == g_130)) >= g_130) + (signed char)(*l_213)) - (short)p_80);
            }
            step_hash(129);
            l_226 = ((g_130 | g_98) || ((unsigned char)l_240 << (unsigned char)g_98));
            step_hash(130);
            l_248 = ((unsigned)(0x76L && ((int)l_235 - (int)func_18(p_80, p_80, l_235, func_18(l_235, ((((unsigned short)((func_18(l_226, func_18(l_235, l_247, p_79, g_208, (*p_81)), p_79, l_235, (*p_81)) || g_2) | 0xE22B5BEAL) % (unsigned short)p_80) <= l_226) && g_98), p_80, p_79, (*p_81)), (*p_81)))) % (unsigned)0x8C5722BDL);
        }
    }
    step_hash(133);
    (*l_249) = (&l_96 == &g_143);
    step_hash(134);
    (*g_142) = &l_237;
    step_hash(141);
    if ((0xBB3DL ^ func_18(((((unsigned short)((unsigned short)(p_79 != (0x74175C3EL >= (&l_237 == (void*)0))) * (unsigned short)(*l_249)) + (unsigned short)func_18(p_80, ((unsigned short)((&p_81 == g_258) < 0UL) - (unsigned short)p_79), p_80, p_79, (**g_258))) || (*l_249)) == 0x43L), (*l_249), p_80, (*l_249), (*p_81))))
    {
        step_hash(136);
        (*g_142) = (void*)0;
        step_hash(137);
        (*g_258) = (*g_258);
    }
    else
    {
        int l_263 = 0x40654149L;
        int *l_271 = &g_272;
        step_hash(139);
        (*l_271) &= ((signed char)((unsigned short)(func_18((l_263 || (-5L)), (((unsigned short)((unsigned)(((signed char)(~(65535UL != l_263)) % (signed char)func_18(((*g_142) != (*g_258)), g_98, (*l_249), g_208, l_263)) != g_98) + (unsigned)l_263) * (unsigned short)l_270) || g_2), p_79, g_2, (**g_258)) && 255UL) >> (unsigned short)l_263) << (signed char)p_79);
        step_hash(140);
        l_280 ^= ((~((((unsigned)func_18((g_98 <= g_130), (*l_249), g_208, ((*l_249) >= ((*l_249) & ((unsigned)g_208 % (unsigned)g_272))), (((short)(-1L) / (short)l_279) && p_79)) + (unsigned)0xF5E0A40FL) == (-4L)) < g_208)) | (**g_258));
    }
    step_hash(142);
    return p_80;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_98, "g_98", print_hash_value);
    transparent_crc(g_130, "g_130", print_hash_value);
    transparent_crc(g_208, "g_208", print_hash_value);
    transparent_crc(g_272, "g_272", print_hash_value);
    transparent_crc(g_295, "g_295", print_hash_value);
    transparent_crc(g_316, "g_316", print_hash_value);
    transparent_crc(g_321, "g_321", print_hash_value);
    transparent_crc(g_464, "g_464", print_hash_value);
    transparent_crc(g_503, "g_503", print_hash_value);
    transparent_crc(g_532, "g_532", print_hash_value);
    transparent_crc(g_634, "g_634", print_hash_value);
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
