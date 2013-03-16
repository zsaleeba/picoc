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
static int g_2 = 0x31713B91L;
static int g_5 = 0xD4E7937DL;
static unsigned short g_9 = 65530UL;
static int g_84 = 0xE1947684L;
static int g_111 = 0x6E61A645L;
static int *g_112 = (void*)0;
static int **g_239 = &g_112;
static int ***g_238 = &g_239;
static unsigned char g_261 = 0x10L;
static signed char g_270 = 0x8AL;
static unsigned char g_292 = 0x30L;
static int g_326 = 0xA7B0075AL;
static int g_438 = 0L;
static unsigned short g_644 = 0x59A5L;
static unsigned func_1(void);
static int func_12(unsigned char p_13, unsigned p_14, unsigned p_15);
static signed char func_19(short p_20, unsigned p_21, short p_22, unsigned p_23);
static unsigned char func_26(unsigned short p_27, signed char p_28, int p_29, short p_30, int p_31);
static int func_40(int p_41, short p_42, int p_43);
static int func_44(unsigned short p_45, signed char p_46, short p_47);
static int func_51(unsigned p_52, unsigned p_53, unsigned p_54, int p_55, unsigned short p_56);
static signed char func_63(short p_64, unsigned p_65);
static int func_68(int p_69, int p_70, unsigned p_71, unsigned short p_72);
static unsigned char func_77(unsigned p_78, unsigned short p_79, unsigned short p_80);
static unsigned func_1(void)
{
    unsigned char l_8 = 0x59L;
    int l_615 = (-8L);
    int *l_622 = &g_438;
    step_hash(358);
    for (g_2 = 0; (g_2 == 20); g_2 += 5)
    {
        int ***l_614 = (void*)0;
        step_hash(4);
        if (g_2)
            break;
        step_hash(357);
        for (g_5 = 0; (g_5 == (-24)); g_5 -= 8)
        {
            step_hash(8);
            g_9 = l_8;
        }
    }
    step_hash(359);
    (*l_622) &= ((short)((g_84 | l_615) & g_5) * (short)((((unsigned short)0x4B3BL << (unsigned short)5) & (func_26(g_2, l_615, l_615, ((l_615 >= (!(((unsigned short)l_615 >> (unsigned short)g_9) || (-1L)))) > 0x5440E119L), g_111) ^ 0xB3FBB834L)) == l_615));
    step_hash(367);
    for (g_261 = 0; (g_261 >= 27); ++g_261)
    {
        unsigned l_630 = 0x1B430333L;
        int l_637 = 4L;
        step_hash(363);
        l_637 = ((signed char)((-(unsigned)(((short)((*l_622) & (0UL <= 0x0B7B73DEL)) % (short)func_51((g_111 | (g_5 ^ func_26(l_630, ((unsigned char)(l_630 & ((short)func_44(((unsigned char)(&l_615 == (**g_238)) + (unsigned char)g_2), g_326, g_438) / (short)(*l_622))) << (unsigned char)6), l_630, (*l_622), g_261))), (*l_622), g_438, (*l_622), (*l_622))) || (***g_238))) > 0xDFC9L) / (signed char)0x04L);
        step_hash(364);
        (**g_239) ^= (((int)(~((*l_622) || (((l_637 > ((*g_239) == (*g_239))) < (0L || g_84)) ^ (0xD1L < ((~((unsigned short)((unsigned short)g_644 - (unsigned short)((unsigned char)((unsigned char)0x3AL * (unsigned char)g_292) + (unsigned char)0xBBL)) * (unsigned short)g_292)) != 1UL))))) - (int)4294967295UL) != g_261);
        step_hash(365);
        if ((*l_622))
            continue;
        step_hash(366);
        (**g_239) = (*l_622);
    }
    step_hash(368);
    return (*l_622);
}
static int func_12(unsigned char p_13, unsigned p_14, unsigned p_15)
{
    signed char l_18 = (-3L);
    unsigned short l_376 = 1UL;
    signed char l_377 = 0xB1L;
    int l_417 = 0xFF7F0D00L;
    int *l_463 = &g_5;
    int ***l_517 = &g_239;
    step_hash(175);
    for (g_9 = (-26); (g_9 < 4); g_9 += 4)
    {
        short l_48 = 0x7163L;
        int l_302 = (-1L);
        int *l_349 = &g_326;
        unsigned l_356 = 0xFAC3CD31L;
        int l_360 = 0x59EE195EL;
        step_hash(171);
        (*l_349) = (((l_18 | func_19(((unsigned char)func_26(l_18, (((short)(l_18 <= 65526UL) << (short)7) || ((short)(-8L) / (short)((short)p_13 % (short)((int)func_40(func_44(((l_48 == (((int)func_51((~(((signed char)((unsigned short)(l_18 | (((signed char)func_63(g_9, l_18) % (signed char)l_48) > 0xE3D1283DL)) >> (unsigned short)6) * (signed char)p_14) | 0L)), g_9, l_48, g_5, g_261) % (int)g_270) < l_18)) != l_18), g_261, g_9), p_14, l_48) / (int)p_14)))), l_302, g_2, g_2) * (unsigned char)p_15), g_9, p_13, l_18)) && 4294967295UL) != (-1L));
        step_hash(172);
        (**g_238) = l_349;
        step_hash(173);
        (**g_238) = (**g_238);
        step_hash(174);
        l_360 &= (func_63(((signed char)((signed char)(((void*)0 == &l_349) ^ (l_349 == l_349)) - (signed char)((short)(l_356 >= ((short)(-(unsigned)func_26((l_18 && p_15), g_292, l_18, (*l_349), g_270)) >> (short)l_18)) + (short)g_261)) + (signed char)l_48), g_292) == p_13);
    }
    step_hash(315);
    for (p_13 = 0; (p_13 > 40); p_13 += 8)
    {
        unsigned short l_365 = 1UL;
        int l_382 = 0x0D4FEF44L;
        int **l_427 = &g_112;
        unsigned l_470 = 0UL;
        signed char l_486 = 0x3FL;
        unsigned l_535 = 0UL;
        step_hash(235);
        for (g_292 = 18; (g_292 != 18); g_292 += 4)
        {
            int l_366 = 0x06FBFCB9L;
            int ***l_374 = &g_239;
            unsigned short l_375 = 0x2548L;
            int *l_378 = &g_111;
            int *l_383 = &g_5;
            unsigned char l_416 = 0xC4L;
            int *l_429 = &g_5;
            step_hash(182);
            (*l_378) = ((((!(l_365 && (((l_366 & (-(int)p_14)) < (&l_366 == (**g_238))) < (((unsigned char)(func_26(((short)((signed char)func_26(((g_84 != (&g_239 == l_374)) && ((((0xD7B21091L ^ 0L) > 0xAF886D76L) || p_14) || l_375)), p_14, l_18, p_14, l_18) * (signed char)(-1L)) * (short)0x242CL), g_84, l_376, p_14, p_14) >= l_18) + (unsigned char)l_365) > g_261)))) | l_377) | g_9) ^ l_365);
            step_hash(183);
            (*g_239) = (**l_374);
            step_hash(233);
            for (g_261 = 0; (g_261 >= 14); ++g_261)
            {
                int *l_418 = &g_111;
                step_hash(199);
                if (p_14)
                {
                    short l_381 = 0L;
                    unsigned l_388 = 8UL;
                    unsigned l_397 = 0xA45CF1C7L;
                    step_hash(188);
                    l_382 ^= ((g_270 != l_365) | l_381);
                    step_hash(189);
                    (**g_238) = l_383;
                    step_hash(190);
                    if ((***g_238))
                        continue;
                    step_hash(196);
                    if (((short)((~((short)((((~(l_388 >= g_111)) != (((unsigned short)g_84 << (unsigned short)((signed char)p_13 % (signed char)g_292)) | l_382)) && (((unsigned short)(((unsigned char)255UL * (unsigned char)0UL) && g_111) - (unsigned short)g_292) == 0x86L)) == g_9) << (short)10)) < 0UL) << (short)9))
                    {
                        step_hash(192);
                        l_382 = func_63(p_13, l_397);
                        step_hash(193);
                        if (p_13)
                            continue;
                    }
                    else
                    {
                        step_hash(195);
                        l_417 &= ((0L || ((+((0x3F3E99A6L == func_26(((unsigned char)p_15 % (unsigned char)g_270), ((unsigned short)65535UL * (unsigned short)((unsigned short)((signed char)(((short)((unsigned)1UL - (unsigned)func_44(l_381, ((signed char)((unsigned)((short)0x4357L << (short)(l_416 || 0xCDB3L)) / (unsigned)(*l_383)) % (signed char)(-1L)), g_9)) << (short)7) | g_111) / (signed char)(-10L)) * (unsigned short)l_365)), l_376, p_15, p_14)) > g_261)) != p_14)) == l_376);
                    }
                }
                else
                {
                    step_hash(198);
                    (**g_238) = l_418;
                }
                step_hash(225);
                if (((unsigned short)((unsigned short)((unsigned short)(((((((***l_374) > ((unsigned char)(func_26(p_15, ((***g_238) && ((func_26(g_111, (g_9 == (l_427 != (*l_374))), (g_111 >= p_14), p_13, g_292) != 0x25F0558DL) > p_14)), p_15, p_14, g_84) < 0x9E638077L) << (unsigned char)0)) == 0x2FB5L) || 1UL) | (*l_418)) != p_15) <= g_111) + (unsigned short)g_5) << (unsigned short)g_261) >> (unsigned short)g_2))
                {
                    short l_433 = 0x0DB7L;
                    step_hash(208);
                    if ((***g_238))
                    {
                        int l_428 = 0x8300414EL;
                        step_hash(202);
                        if (l_428)
                            break;
                        step_hash(203);
                        return (*g_112);
                    }
                    else
                    {
                        unsigned l_430 = 0x3B34546DL;
                        step_hash(205);
                        (*g_239) = l_429;
                        step_hash(206);
                        (*l_418) &= (!l_430);
                        step_hash(207);
                        g_438 = ((unsigned short)(func_68((*l_383), ((((l_433 ^ 0xFB50L) != ((unsigned)(+8UL) / (unsigned)(((((signed char)(((*l_418) && 0x9BL) ^ p_15) * (signed char)g_261) <= ((void*)0 != (*g_238))) != (**l_427)) | g_326))) ^ g_270) ^ l_376), p_14, p_15) <= p_14) + (unsigned short)g_326);
                    }
                    step_hash(209);
                    (*l_378) = (**g_239);
                    step_hash(216);
                    if (p_15)
                    {
                        short l_439 = 0x4ABBL;
                        step_hash(211);
                        l_439 = p_13;
                    }
                    else
                    {
                        unsigned char l_446 = 249UL;
                        int *l_449 = (void*)0;
                        step_hash(213);
                        g_326 ^= (4294967295UL >= ((*g_112) > (0xB6L ^ ((((signed char)(((short)((!(-1L)) || ((unsigned char)(l_446 < ((unsigned short)65528UL * (unsigned short)(***l_374))) - (unsigned char)l_18)) >> (short)12) & 0x1EL) - (signed char)p_14) != 0xB819CB91L) <= g_2))));
                        step_hash(214);
                        (**g_238) = (*g_239);
                        step_hash(215);
                        return (**l_427);
                    }
                }
                else
                {
                    int l_452 = 0xC51E9E2BL;
                    step_hash(224);
                    if ((func_51(func_63(p_13, (*l_418)), g_2, ((unsigned char)(g_292 < ((void*)0 == (*g_238))) << (unsigned char)1), l_452, p_15) == 0xE282847CL))
                    {
                        int *l_453 = &l_366;
                        step_hash(219);
                        (*l_453) &= (*g_112);
                        step_hash(220);
                        (*l_418) = l_452;
                        step_hash(221);
                        (*l_427) = (*g_239);
                    }
                    else
                    {
                        step_hash(223);
                        (**l_374) = (**g_238);
                    }
                }
                step_hash(226);
                (**l_374) = l_418;
                step_hash(232);
                if (((((unsigned short)((int)(+(**g_239)) - (int)(((void*)0 != (**l_374)) < (((short)(+(p_13 < ((short)g_2 * (short)p_15))) >> (short)8) ^ ((*l_418) != ((-(unsigned)(&l_427 == l_374)) > g_326))))) << (unsigned short)14) >= g_2) == (**l_427)))
                {
                    step_hash(228);
                    (**g_239) = (1L && ((void*)0 == l_427));
                    step_hash(229);
                    (*g_238) = (*l_374);
                }
                else
                {
                    step_hash(231);
                    return (**g_239);
                }
            }
            step_hash(234);
            (*l_427) = (**l_374);
        }
        step_hash(314);
        if ((((void*)0 == l_463) >= (p_13 == ((short)((unsigned short)((p_14 != func_26(g_261, func_77(((signed char)((l_470 ^ (((((signed char)1L << (signed char)0) || g_5) != 0x1777L) ^ 1UL)) ^ g_292) - (signed char)0xE4L), p_15, g_292), (*l_463), l_365, g_5)) == g_270) / (unsigned short)1UL) * (short)g_270))))
        {
            int l_473 = (-2L);
            unsigned short l_495 = 65535UL;
            int **l_534 = &g_112;
            step_hash(237);
            l_473 = p_14;
            step_hash(280);
            for (l_470 = 11; (l_470 >= 36); l_470++)
            {
                step_hash(256);
                for (g_84 = (-18); (g_84 != (-22)); g_84 -= 9)
                {
                    int *l_483 = &g_111;
                    step_hash(249);
                    for (g_111 = 0; (g_111 < (-12)); g_111--)
                    {
                        step_hash(247);
                        if (p_14)
                            break;
                        step_hash(248);
                        (*l_427) = &l_473;
                    }
                    step_hash(254);
                    if ((g_326 | ((65534UL || (g_326 && g_5)) & ((((unsigned short)p_13 << (unsigned short)4) ^ (*l_463)) == (-6L)))))
                    {
                        int *l_482 = &l_382;
                        step_hash(251);
                        (*l_482) ^= g_438;
                    }
                    else
                    {
                        step_hash(253);
                        (*g_239) = (*g_239);
                    }
                    step_hash(255);
                    (*l_483) = p_13;
                }
                step_hash(257);
                (**g_238) = &l_417;
                step_hash(269);
                for (g_292 = (-26); (g_292 == 24); ++g_292)
                {
                }
                step_hash(279);
                for (g_111 = 0; (g_111 <= (-17)); --g_111)
                {
                    step_hash(278);
                    for (p_15 = 0; (p_15 >= 41); p_15 += 6)
                    {
                    }
                }
            }
            step_hash(307);
            if ((((((unsigned short)((unsigned short)(!(p_14 | (l_495 && p_15))) >> (unsigned short)15) << (unsigned short)1) == ((func_26(p_15, (*l_463), ((((unsigned short)65529UL % (unsigned short)g_84) == ((int)p_15 / (int)l_473)) || 0x62L), (*l_463), p_13) & 0x018AF709L) & 0L)) & p_15) && p_15))
            {
                unsigned l_502 = 4294967294UL;
                int *l_514 = (void*)0;
                step_hash(288);
                for (l_377 = 0; (l_377 > (-9)); l_377 -= 2)
                {
                    int *l_503 = &g_438;
                    step_hash(285);
                    (*l_503) = l_502;
                    step_hash(286);
                    (*l_503) = ((func_40(func_51((((((signed char)g_5 >> (signed char)3) == func_40(p_14, g_84, p_15)) >= ((p_13 ^ (((signed char)(((unsigned short)(p_13 ^ g_9) * (unsigned short)((signed char)((*l_463) ^ p_15) * (signed char)p_14)) & p_15) >> (signed char)l_502) ^ g_292)) != 0xF3194B1DL)) != 0UL), g_326, g_326, g_438, (*l_503)), l_502, l_473) || (**l_427)) || p_13);
                    step_hash(287);
                    return (*l_463);
                }
                step_hash(289);
                l_514 = &l_417;
                step_hash(304);
                for (g_111 = (-3); (g_111 > 25); g_111 += 1)
                {
                    int l_518 = 1L;
                    step_hash(293);
                    l_518 = (1L > (l_517 != &g_239));
                    step_hash(302);
                    if (((int)(~((*l_514) ^ ((short)(*l_463) % (short)func_44((*l_463), func_40(l_473, ((l_518 == ((signed char)((short)(func_26(p_13, (p_15 <= g_261), l_473, g_84, l_495) && g_438) << (short)3) * (signed char)l_518)) ^ 0x1DAAL), g_5), g_5)))) + (int)(*l_514)))
                    {
                        step_hash(295);
                        (*l_514) = p_13;
                        step_hash(296);
                        l_473 = func_44(g_292, ((p_14 < ((unsigned short)(*l_514) << (unsigned short)5)) & 0x59FE014BL), ((void*)0 != (*g_238)));
                        step_hash(297);
                        (*g_239) = l_514;
                    }
                    else
                    {
                        step_hash(299);
                        if (l_518)
                            break;
                        step_hash(300);
                        (*l_514) = (-7L);
                        step_hash(301);
                        l_382 |= func_40(((*l_514) > (((0x88811302L < (!(((unsigned short)(**l_427) * (unsigned short)3UL) <= (-2L)))) > (***l_517)) <= p_15)), (*l_514), g_261);
                    }
                    step_hash(303);
                    (*l_514) = (***g_238);
                }
            }
            else
            {
                step_hash(306);
                l_535 ^= (-(short)((unsigned short)g_84 * (unsigned short)((g_2 || (l_534 != (*g_238))) != p_13)));
            }
            step_hash(308);
            return p_14;
        }
        else
        {
            unsigned l_538 = 4294967295UL;
            int *l_539 = (void*)0;
            int *l_540 = &l_417;
            step_hash(310);
            (*l_540) = ((unsigned short)l_538 * (unsigned short)0x4D10L);
            step_hash(311);
            (*l_540) = 3L;
            step_hash(312);
            (*l_540) = ((short)0L + (short)p_14);
            step_hash(313);
            return p_14;
        }
    }
    step_hash(323);
    for (g_326 = 16; (g_326 >= 10); g_326 -= 8)
    {
        int l_545 = (-1L);
        step_hash(319);
        l_545 ^= (p_14 ^ 5L);
    }
    step_hash(354);
    if ((8UL < g_326))
    {
        step_hash(325);
        g_326 = p_13;
    }
    else
    {
        int *l_565 = &g_326;
        int l_593 = 0L;
        step_hash(350);
        for (g_9 = (-22); (g_9 == 26); g_9 += 8)
        {
            unsigned short l_575 = 65535UL;
            unsigned l_587 = 0x6BA929C3L;
            step_hash(337);
            for (l_377 = 12; (l_377 >= (-9)); --l_377)
            {
                int ***l_563 = (void*)0;
                int *l_564 = &g_111;
                step_hash(333);
                (*l_564) = ((l_563 != (void*)0) | (-2L));
                step_hash(334);
                (*l_564) = p_15;
                step_hash(335);
                (*g_239) = l_565;
                step_hash(336);
                if ((**g_239))
                    break;
            }
            step_hash(338);
            (**l_517) = (*g_239);
            step_hash(348);
            for (l_377 = 0; (l_377 >= 2); l_377 += 8)
            {
                unsigned short l_584 = 0x8482L;
                step_hash(347);
                for (g_270 = 8; (g_270 < (-25)); g_270 -= 6)
                {
                    int *l_570 = (void*)0;
                    unsigned short l_588 = 0x7F8FL;
                    step_hash(345);
                    (*g_239) = l_570;
                    step_hash(346);
                    (*l_565) = (((int)((unsigned)(l_575 != func_63(g_438, (+(g_111 != ((int)func_26((p_15 != (((unsigned)((short)((-1L) < func_26(l_584, g_438, ((signed char)(((void*)0 == &l_565) | l_584) >> (signed char)1), p_13, g_2)) % (short)0xA6E9L) - (unsigned)(-8L)) < g_9)), g_111, g_261, g_84, l_587) + (int)p_14))))) - (unsigned)l_588) % (int)0x3880585DL) < g_438);
                }
            }
            step_hash(349);
            if (p_15)
                break;
        }
        step_hash(351);
        (*l_565) = ((**g_238) == (void*)0);
        step_hash(352);
        (*l_565) = (!(*l_565));
        step_hash(353);
        (*l_565) = ((signed char)(-10L) + (signed char)((signed char)((l_593 > (~(!(1L >= ((signed char)(!((unsigned short)p_14 + (unsigned short)((p_14 || 0xF5L) & ((unsigned short)g_326 / (unsigned short)((short)((g_111 ^ ((unsigned char)((short)(((unsigned char)((unsigned short)((unsigned char)g_2 - (unsigned char)p_13) * (unsigned short)(*l_565)) + (unsigned char)0UL) >= p_14) * (short)g_2) % (unsigned char)g_261)) >= g_5) >> (short)3))))) << (signed char)5))))) & p_15) << (signed char)(*l_565)));
    }
    step_hash(355);
    return (*l_463);
}
static signed char func_19(short p_20, unsigned p_21, short p_22, unsigned p_23)
{
    int *l_331 = &g_111;
    int ***l_347 = &g_239;
    unsigned short l_348 = 6UL;
    step_hash(169);
    (*l_331) = ((short)(((signed char)g_9 >> (signed char)((((void*)0 == l_331) <= p_20) | ((unsigned short)((short)func_40((((unsigned short)((-(unsigned char)0xA9L) || (((((signed char)func_51(g_326, g_270, ((unsigned)((unsigned short)((void*)0 == l_347) + (unsigned short)1UL) / (unsigned)l_348), (*l_331), (*l_331)) << (signed char)0) == l_348) | g_5) >= p_21)) - (unsigned short)0x40EEL) >= g_2), g_326, p_23) + (short)p_21) << (unsigned short)g_5))) != 1UL) << (short)15);
    step_hash(170);
    return (*l_331);
}
static unsigned char func_26(unsigned short p_27, signed char p_28, int p_29, short p_30, int p_31)
{
    unsigned l_303 = 1UL;
    int l_304 = (-5L);
    int *l_305 = &g_84;
    short l_314 = (-7L);
    int *l_325 = &g_326;
    step_hash(164);
    l_304 = l_303;
    step_hash(165);
    l_305 = (**g_238);
    step_hash(166);
    (*l_325) &= ((unsigned char)p_28 - (unsigned char)((((unsigned short)g_84 >> (unsigned short)((int)(p_28 > l_314) + (int)l_304)) < p_31) ^ ((int)(g_261 == ((unsigned short)((unsigned char)((unsigned char)((unsigned)((void*)0 != &l_304) - (unsigned)p_31) << (unsigned char)4) - (unsigned char)g_111) << (unsigned short)11)) % (int)(-1L))));
    step_hash(167);
    return (*l_325);
}
static int func_40(int p_41, short p_42, int p_43)
{
    int *l_296 = &g_84;
    step_hash(148);
    (*g_239) = (void*)0;
    step_hash(149);
    (**g_238) = l_296;
    step_hash(161);
    for (g_261 = (-12); (g_261 != 9); g_261 += 1)
    {
        unsigned char l_301 = 0x31L;
        step_hash(158);
        for (p_43 = 0; (p_43 >= (-18)); p_43--)
        {
            step_hash(156);
            (**g_239) = (p_43 || l_301);
            step_hash(157);
            (*g_239) = (**g_238);
        }
        step_hash(159);
        (*l_296) = (l_296 == (void*)0);
        step_hash(160);
        (**g_238) = l_296;
    }
    step_hash(162);
    return p_41;
}
static int func_44(unsigned short p_45, signed char p_46, short p_47)
{
    int *l_287 = &g_111;
    int **l_293 = &g_112;
    int *l_294 = (void*)0;
    int *l_295 = &g_84;
    step_hash(143);
    (**g_238) = l_287;
    step_hash(144);
    g_84 |= (*l_287);
    step_hash(145);
    (*l_295) ^= ((unsigned)((*l_287) && ((*g_238) == (void*)0)) % (unsigned)((int)g_292 * (int)(l_293 == (*g_238))));
    step_hash(146);
    return p_47;
}
static int func_51(unsigned p_52, unsigned p_53, unsigned p_54, int p_55, unsigned short p_56)
{
    int l_272 = (-9L);
    short l_281 = 1L;
    unsigned l_285 = 4294967295UL;
    int l_286 = 1L;
    step_hash(140);
    if ((g_5 != ((unsigned short)func_63((((unsigned short)((unsigned char)0x62L >> (unsigned char)((((short)g_111 / (short)g_270) < (((-(short)l_272) != ((unsigned short)((signed char)p_53 / (signed char)((short)(l_272 >= 0x137C4823L) * (short)(((signed char)l_272 % (signed char)p_53) >= l_281))) / (unsigned short)0x49EFL)) ^ l_281)) < p_56)) / (unsigned short)65535UL) >= g_2), l_281) >> (unsigned short)g_5)))
    {
        int *l_282 = &g_2;
        step_hash(136);
        (*g_239) = l_282;
        step_hash(137);
        l_286 ^= ((short)((!func_63(g_261, func_77(g_5, l_285, p_56))) & (0xC228L && g_270)) >> (short)4);
    }
    else
    {
        step_hash(139);
        (**g_238) = (*g_239);
    }
    step_hash(141);
    return l_281;
}
static signed char func_63(short p_64, unsigned p_65)
{
    unsigned char l_81 = 0x69L;
    int l_127 = 0x5DE23EDEL;
    int *l_128 = (void*)0;
    int l_249 = 0xBF8092ABL;
    int *l_260 = &l_127;
    step_hash(110);
    for (p_65 = 0; (p_65 != 43); p_65 += 5)
    {
        unsigned char l_75 = 255UL;
        int *l_126 = &g_84;
        short l_135 = 1L;
        int l_173 = 0x14048F23L;
        int **l_182 = &g_112;
        short l_198 = 0x77E6L;
        step_hash(50);
        (*l_126) = (func_68(g_2, g_5, (((int)((((l_75 > p_64) > (-(short)6L)) < func_77((1L > (l_81 <= l_81)), (g_2 | l_75), g_5)) != g_9) / (int)0x9A115EA9L) | 6L), l_81) & 0L);
        step_hash(51);
        l_127 = p_64;
        step_hash(52);
        l_128 = &g_5;
        step_hash(109);
        if ((*l_126))
        {
            unsigned l_137 = 7UL;
            short l_167 = 0xF393L;
            int l_211 = 0x4AB74D0FL;
            int *l_212 = &g_5;
            step_hash(102);
            for (g_84 = (-17); (g_84 > 17); g_84++)
            {
                unsigned l_136 = 0xE4845943L;
                int *l_148 = &g_5;
                int l_189 = 0x05F3852FL;
                step_hash(79);
                if ((*l_128))
                {
                    int l_143 = (-5L);
                    step_hash(65);
                    if (((int)(p_64 != ((unsigned short)((l_135 || (((l_136 || ((void*)0 != &l_128)) || g_9) | (p_65 ^ (-7L)))) > g_2) / (unsigned short)p_65)) / (int)(*l_126)))
                    {
                        int *l_138 = &g_111;
                        step_hash(59);
                        (*l_138) &= l_137;
                        step_hash(60);
                        l_143 = ((0xA0L != g_2) && ((signed char)((-9L) < ((void*)0 != &l_138)) << (signed char)l_136));
                        step_hash(61);
                        (*l_138) &= (p_64 & p_64);
                    }
                    else
                    {
                        int *l_146 = &g_111;
                        step_hash(63);
                        (*l_146) = ((unsigned char)l_143 << (unsigned char)3);
                        step_hash(64);
                        (*l_146) = (&g_111 == l_126);
                    }
                    step_hash(66);
                    l_127 ^= (-6L);
                    step_hash(67);
                    l_127 = (-1L);
                }
                else
                {
                    short l_147 = 0L;
                    int l_150 = 4L;
                    int *l_170 = (void*)0;
                    int *l_171 = (void*)0;
                    int *l_172 = &l_150;
                    step_hash(75);
                    if (l_147)
                    {
                        int **l_149 = &l_128;
                        step_hash(70);
                        (*l_149) = l_148;
                        step_hash(71);
                        return (*l_148);
                    }
                    else
                    {
                        unsigned l_155 = 0x0CDDE2BAL;
                        int *l_166 = &l_127;
                        step_hash(73);
                        l_150 = ((l_147 & g_84) <= g_111);
                        step_hash(74);
                        (*l_166) = (0x75E4EBAAL <= ((((unsigned)((unsigned)l_155 - (unsigned)(((unsigned char)(p_64 == (p_65 & ((int)((int)p_65 / (int)((unsigned char)0x41L * (unsigned char)((short)g_111 * (short)g_2))) + (int)(p_65 & g_111)))) - (unsigned char)(-10L)) || 1UL)) / (unsigned)g_84) != 65533UL) || (*l_126)));
                    }
                    step_hash(76);
                    l_167 = (p_65 && g_5);
                    step_hash(77);
                    l_127 &= (p_65 || p_64);
                    step_hash(78);
                    (*l_172) &= ((signed char)(4294967295UL < l_137) % (signed char)p_64);
                }
                step_hash(80);
                l_173 = (!(g_5 | p_64));
                step_hash(101);
                if (((~p_65) < (((unsigned short)g_9 >> (unsigned short)g_9) & ((unsigned char)((signed char)(*l_126) * (signed char)((short)(g_84 >= l_137) - (short)(((void*)0 == l_182) && (((signed char)g_84 % (signed char)0xA8L) ^ g_9)))) + (unsigned char)(*l_148)))))
                {
                    int l_202 = (-3L);
                    int ***l_208 = &l_182;
                    step_hash(82);
                    l_189 = ((unsigned char)((signed char)p_64 * (signed char)(*l_128)) >> (unsigned char)7);
                    step_hash(88);
                    for (p_64 = 3; (p_64 <= 15); p_64++)
                    {
                        step_hash(86);
                        g_111 ^= (((short)(((short)((short)g_5 / (short)g_2) * (short)0x6328L) ^ g_2) * (short)(&g_2 == &l_189)) < (g_84 | l_198));
                        step_hash(87);
                        g_111 = p_64;
                    }
                    step_hash(97);
                    if (((signed char)0x40L >> (signed char)p_65))
                    {
                        unsigned char l_201 = 0UL;
                        int *l_205 = (void*)0;
                        int *l_206 = &l_173;
                        step_hash(90);
                        l_202 = l_201;
                        step_hash(91);
                        (*l_206) = ((unsigned short)l_137 >> (unsigned short)12);
                        step_hash(92);
                        (*l_206) ^= (*l_128);
                        step_hash(93);
                        (*l_206) = ((3L ^ l_167) <= (p_65 && g_2));
                    }
                    else
                    {
                        int *l_207 = &g_5;
                        step_hash(95);
                        if (g_84)
                            break;
                        step_hash(96);
                        (*l_182) = l_207;
                    }
                    step_hash(98);
                    (*l_208) = &l_126;
                }
                else
                {
                    step_hash(100);
                    l_189 ^= ((unsigned short)g_5 / (unsigned short)1UL);
                }
            }
            step_hash(103);
            l_211 = (*l_128);
            step_hash(104);
            (*l_182) = l_212;
        }
        else
        {
            int l_213 = 3L;
            step_hash(106);
            (*l_126) |= l_213;
            step_hash(107);
            (*l_126) = (((((unsigned)(*l_128) - (unsigned)p_65) & 253UL) | (*l_128)) & (-(unsigned char)l_213));
            step_hash(108);
            (*l_126) = ((short)(&l_127 == &g_5) + (short)((*l_126) != (*l_128)));
        }
    }
    step_hash(131);
    for (p_64 = 0; (p_64 <= 12); p_64 += 2)
    {
        int *l_223 = &l_127;
        short l_240 = (-1L);
        step_hash(114);
        (*l_223) ^= ((unsigned char)g_111 << (unsigned char)6);
        step_hash(115);
        (*l_223) |= g_2;
        step_hash(116);
        g_112 = &g_2;
        step_hash(130);
        if (((unsigned short)((unsigned short)(~0xDE8CL) / (unsigned short)((1UL | (((short)p_65 * (short)((signed char)(l_81 && p_65) << (signed char)0)) > (&l_128 != &g_112))) ^ func_68((((short)((unsigned)(*l_223) / (unsigned)((short)((void*)0 == g_238) + (short)g_9)) + (short)7UL) | l_240), (*g_112), p_64, g_5))) * (unsigned short)g_5))
        {
            int ***l_250 = (void*)0;
            step_hash(118);
            l_249 ^= (p_65 ^ ((unsigned char)((unsigned char)((signed char)p_64 / (signed char)(*l_223)) % (unsigned char)p_65) / (unsigned char)(((void*)0 != l_223) & func_77(((signed char)(-6L) + (signed char)p_64), g_2, p_64))));
            step_hash(119);
            (*l_223) &= (0x26L >= (l_250 != (void*)0));
            step_hash(120);
            (*l_223) = func_77(p_65, g_111, ((short)g_5 >> (short)((unsigned short)(g_9 && p_65) - (unsigned short)(-1L))));
            step_hash(125);
            for (p_65 = 0; (p_65 > 43); p_65 += 9)
            {
                step_hash(124);
                (*l_223) ^= (**g_239);
            }
        }
        else
        {
            int *l_257 = &l_249;
            step_hash(127);
            (*l_223) ^= (+func_77((5L && g_5), ((*g_238) != (*g_238)), g_111));
            step_hash(128);
            (*l_223) = func_77(g_111, p_65, g_5);
            step_hash(129);
            l_257 = &l_127;
        }
    }
    step_hash(132);
    (*l_260) &= ((func_77(g_84, p_65, l_249) == (p_65 ^ ((short)g_9 / (short)g_2))) && 0x54D5C3D9L);
    step_hash(133);
    return p_65;
}
static int func_68(int p_69, int p_70, unsigned p_71, unsigned short p_72)
{
    int l_119 = 5L;
    int *l_122 = &g_84;
    unsigned l_123 = 0x7833775BL;
    int *l_124 = (void*)0;
    int *l_125 = &g_111;
    step_hash(45);
    (*l_122) = (((signed char)((int)((unsigned short)(p_71 | g_5) >> (unsigned short)13) - (int)func_77(g_111, (g_111 <= l_119), g_84)) % (signed char)((short)l_119 >> (short)5)) | p_72);
    step_hash(46);
    (*l_122) = func_77((+(*l_122)), g_2, (l_123 ^ (((void*)0 != &p_70) | 0xE9983536L)));
    step_hash(47);
    l_122 = l_122;
    step_hash(48);
    (*l_125) &= ((*l_122) > (*l_122));
    step_hash(49);
    return p_70;
}
static unsigned char func_77(unsigned p_78, unsigned short p_79, unsigned short p_80)
{
    unsigned char l_82 = 0UL;
    int *l_88 = &g_2;
    int *l_104 = &g_84;
    step_hash(24);
    if ((1UL && l_82))
    {
        int *l_83 = &g_84;
        step_hash(19);
        (*l_83) = g_9;
    }
    else
    {
        int *l_85 = &g_84;
        int **l_89 = &l_88;
        step_hash(21);
        (*l_85) |= l_82;
        step_hash(22);
        (*l_85) = ((unsigned)p_79 + (unsigned)g_2);
        step_hash(23);
        (*l_89) = l_88;
    }
    step_hash(25);
    (*l_104) &= ((unsigned short)((g_9 <= (((short)p_78 % (short)((signed char)(*l_88) * (signed char)p_79)) && g_5)) < ((int)0x036B6A42L / (int)(*l_88))) >> (unsigned short)((short)((unsigned char)(+p_78) / (unsigned char)((short)g_2 * (short)g_5)) % (short)p_79));
    step_hash(42);
    if (g_84)
    {
        step_hash(27);
        return g_84;
    }
    else
    {
        step_hash(40);
        for (p_80 = 16; (p_80 < 44); p_80++)
        {
            step_hash(32);
            if ((*l_104))
                break;
            step_hash(33);
            (*l_104) = (p_79 <= (-(int)0L));
            step_hash(39);
            for (g_84 = (-12); (g_84 <= 10); g_84 += 4)
            {
                int *l_110 = &g_111;
                step_hash(37);
                (*l_110) ^= (*l_88);
                step_hash(38);
                g_112 = &g_111;
            }
        }
        step_hash(41);
        l_104 = l_104;
    }
    step_hash(43);
    return (*l_88);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_5, "g_5", print_hash_value);
    transparent_crc(g_9, "g_9", print_hash_value);
    transparent_crc(g_84, "g_84", print_hash_value);
    transparent_crc(g_111, "g_111", print_hash_value);
    transparent_crc(g_261, "g_261", print_hash_value);
    transparent_crc(g_270, "g_270", print_hash_value);
    transparent_crc(g_292, "g_292", print_hash_value);
    transparent_crc(g_326, "g_326", print_hash_value);
    transparent_crc(g_438, "g_438", print_hash_value);
    transparent_crc(g_644, "g_644", print_hash_value);
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
