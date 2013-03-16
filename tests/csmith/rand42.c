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
static int g_70 = 0L;
static int g_114 = (-3L);
static short g_127 = 0x8F01L;
static int *g_190 = &g_70;
static int **g_189 = &g_190;
static short g_222 = 1L;
static short g_236 = 0x5D6AL;
static int g_255 = 0x459854DCL;
static int g_324 = 1L;
static int g_423 = 0x1AE0DA59L;
static int g_523 = 0xE8411E5FL;
static int g_611 = 0xA96E05F3L;
static int func_1(void);
static unsigned short func_8(unsigned p_9, unsigned p_10);
static int func_15(int p_16, unsigned p_17, short p_18);
static int * func_19(short p_20);
static short func_21(unsigned p_22, int * p_23, int * p_24, int * p_25);
static int * func_27(int * p_28, int * p_29, unsigned short p_30);
static int * func_32(unsigned p_33, int p_34);
static short func_37(unsigned p_38, unsigned short p_39);
static short func_42(int * p_43, int * p_44, int * p_45, short p_46);
static int * func_47(int * p_48, signed char p_49, int p_50, int * p_51, unsigned p_52);
static int func_1(void)
{
    unsigned short l_5 = 65533UL;
    int l_696 = 0L;
    step_hash(446);
    for (g_2 = 24; (g_2 != 2); --g_2)
    {
        int ***l_695 = (void*)0;
        int l_697 = 0x70686054L;
        int *l_701 = &g_70;
    }
    step_hash(447);
    return (**g_189);
}
static unsigned short func_8(unsigned p_9, unsigned p_10)
{
    int *l_698 = &g_70;
    step_hash(440);
    (*l_698) &= 1L;
    step_hash(441);
    (*l_698) = p_10;
    step_hash(442);
    g_255 |= ((unsigned char)func_37(g_423, (*l_698)) + (unsigned char)(g_127 < (l_698 != (void*)0)));
    step_hash(443);
    (*g_189) = (void*)0;
    step_hash(444);
    return (*l_698);
}
static int func_15(int p_16, unsigned p_17, short p_18)
{
    int l_26 = 0x6A056EBFL;
    int *l_31 = &l_26;
    int **l_692 = &l_31;
    step_hash(437);
    (*l_692) = func_19(func_21(l_26, func_27(l_31, func_32((p_18 & ((((((short)func_37(p_18, p_18) * (short)(func_42(&l_26, &l_26, func_47(&l_26, (*l_31), g_2, &g_2, g_2), p_18) >= g_2)) & 0x3EBFL) >= p_16) == p_16) || 0xC5L)), p_18), g_324), &l_26, &l_26));
    step_hash(438);
    return (*l_31);
}
static int * func_19(short p_20)
{
    int *l_539 = &g_523;
    int **l_540 = (void*)0;
    short l_560 = 0xD87FL;
    int *l_610 = &g_255;
    unsigned l_644 = 4294967295UL;
    signed char l_649 = 0xCDL;
    short l_671 = 1L;
    int *l_688 = (void*)0;
    int *l_691 = &g_70;
    step_hash(434);
    if ((-(unsigned short)((short)0xC308L << (short)3)))
    {
        unsigned l_502 = 0x615C0B61L;
        int l_536 = 0x11A5F4C0L;
        int **l_558 = &l_539;
        unsigned l_643 = 0x835232A8L;
        step_hash(362);
        if (l_502)
        {
            int l_505 = 1L;
            step_hash(293);
            for (g_70 = 0; (g_70 < (-30)); g_70--)
            {
                int *l_527 = &g_2;
                step_hash(279);
                if (p_20)
                {
                    int *l_522 = &g_523;
                    step_hash(274);
                    if (l_505)
                        break;
                    step_hash(275);
                    (*l_522) &= func_37(((short)((unsigned)(((unsigned short)func_37(g_2, func_37(((unsigned char)func_37((((unsigned char)((short)g_2 * (short)((unsigned)g_324 % (unsigned)(~((int)((void*)0 != &g_189) / (int)p_20)))) / (unsigned char)g_70) < ((&l_505 == (void*)0) > l_502)), p_20) << (unsigned char)3), g_255)) << (unsigned short)0) == 0x12F58740L) - (unsigned)p_20) % (short)p_20), l_505);
                    step_hash(276);
                    if (p_20)
                        continue;
                }
                else
                {
                    int *l_524 = &g_2;
                    step_hash(278);
                    (*g_189) = l_524;
                }
                step_hash(285);
                for (g_127 = 0; (g_127 < (-1)); g_127 -= 2)
                {
                    step_hash(283);
                    l_505 |= (((void*)0 == l_527) <= p_20);
                    step_hash(284);
                    l_536 &= ((unsigned char)((signed char)g_255 << (signed char)(func_37(g_127, g_222) | ((g_2 == 0xD3FC8E0EL) == ((((int)(p_20 == ((unsigned char)p_20 + (unsigned char)g_127)) - (int)0xB468D8FBL) <= 0UL) || g_2)))) * (unsigned char)0x57L);
                }
                step_hash(291);
                for (g_236 = 0; (g_236 >= (-1)); g_236--)
                {
                    step_hash(289);
                    (*g_189) = l_539;
                    step_hash(290);
                    (**g_189) |= (*l_527);
                }
                step_hash(292);
                if (p_20)
                    continue;
            }
        }
        else
        {
            signed char l_575 = 1L;
            int *l_578 = &l_536;
            int *l_603 = &g_255;
            step_hash(334);
            if ((!(l_536 == g_222)))
            {
                signed char l_550 = 0x00L;
                step_hash(296);
                (*l_539) |= (l_540 == &g_190);
                step_hash(320);
                if (((int)((((8L < 0x8551E7B2L) && g_523) != l_502) & func_37(g_70, g_2)) - (int)p_20))
                {
                    short l_551 = 0x9E22L;
                    step_hash(302);
                    for (g_222 = 0; (g_222 == 8); g_222++)
                    {
                        unsigned char l_545 = 0x6FL;
                        step_hash(301);
                        if (l_545)
                            break;
                    }
                    step_hash(307);
                    for (g_255 = 0; (g_255 == (-5)); g_255--)
                    {
                        step_hash(306);
                        g_189 = &g_190;
                    }
                    step_hash(308);
                    (*l_539) |= p_20;
                    step_hash(309);
                    l_551 ^= ((signed char)l_550 << (signed char)1);
                }
                else
                {
                    unsigned char l_553 = 0xCFL;
                    int *l_561 = &l_536;
                    step_hash(318);
                    if (l_536)
                    {
                        int **l_552 = &l_539;
                        step_hash(312);
                        (**l_552) |= (l_552 != &g_190);
                        step_hash(313);
                        (*g_189) = &g_255;
                        step_hash(314);
                        (**g_189) &= 0x172036FAL;
                        step_hash(315);
                        (*l_552) = (*g_189);
                    }
                    else
                    {
                        int *l_559 = &g_523;
                        step_hash(317);
                        l_561 = func_47(func_47(&l_536, (l_553 != (+g_324)), ((short)(g_255 < ((short)0x5ED9L / (short)func_37((p_20 && (l_558 != l_558)), (**l_558)))) >> (short)2), l_559, g_324), p_20, l_560, (*l_558), p_20);
                    }
                    step_hash(319);
                    (*l_558) = l_561;
                }
            }
            else
            {
                unsigned l_567 = 0xA64CBDEEL;
                int *l_579 = &l_536;
                step_hash(326);
                for (g_114 = 17; (g_114 == (-21)); --g_114)
                {
                    unsigned l_566 = 0xEEEE2712L;
                    int *l_574 = (void*)0;
                    step_hash(325);
                    l_575 = ((((int)(p_20 > (((0x44B3BA55L | (0UL & (l_566 == l_567))) & g_236) != (-3L))) - (int)0x4A0DFCC9L) && 0xEAL) & p_20);
                }
                step_hash(331);
                for (g_70 = 15; (g_70 != (-14)); g_70 -= 2)
                {
                    step_hash(330);
                    return &g_255;
                }
                step_hash(332);
                (*l_558) = l_579;
                step_hash(333);
                (*l_539) |= ((unsigned char)0UL % (unsigned char)p_20);
            }
            step_hash(356);
            for (g_423 = 6; (g_423 < 19); g_423 += 7)
            {
                int *l_591 = &g_523;
                step_hash(348);
                for (l_536 = 13; (l_536 <= (-23)); l_536 -= 2)
                {
                    int *l_602 = (void*)0;
                    step_hash(346);
                    if (func_37((&g_190 == &g_190), p_20))
                    {
                        int l_588 = 0x53571585L;
                        step_hash(342);
                        l_588 = ((unsigned char)((1UL == (p_20 == func_37(g_222, (l_588 ^ l_588)))) || (((unsigned char)2UL / (unsigned char)(+p_20)) <= g_114)) << (unsigned char)7);
                        step_hash(343);
                        l_578 = l_602;
                    }
                    else
                    {
                        step_hash(345);
                        (*l_558) = l_603;
                    }
                    step_hash(347);
                    if (p_20)
                        break;
                }
            }
            step_hash(361);
            for (p_20 = 0; (p_20 == 6); ++p_20)
            {
                step_hash(360);
                (*l_610) = (**l_558);
            }
        }
        step_hash(397);
        for (p_20 = (-18); (p_20 <= (-10)); p_20 += 6)
        {
            int *l_624 = (void*)0;
            int **l_631 = (void*)0;
            step_hash(395);
            for (g_324 = 0; (g_324 == 4); g_324 += 7)
            {
                int *l_630 = &g_2;
                int *l_645 = &g_523;
                step_hash(380);
                for (g_236 = 0; (g_236 >= (-3)); --g_236)
                {
                    int **l_629 = &l_539;
                    step_hash(376);
                    for (g_423 = (-7); (g_423 == (-28)); g_423 -= 8)
                    {
                        step_hash(375);
                        (*l_558) = l_624;
                    }
                    step_hash(377);
                    (*l_610) ^= ((signed char)0L << (signed char)6);
                    step_hash(378);
                    (*l_610) &= ((0xFBE3L == (((unsigned char)((l_629 == (void*)0) || p_20) << (unsigned char)g_70) && g_2)) != g_324);
                    step_hash(379);
                    l_631 = &l_610;
                }
                step_hash(392);
                for (g_127 = 0; (g_127 >= 15); g_127 += 8)
                {
                    unsigned short l_634 = 0x4870L;
                    step_hash(384);
                    (*l_610) &= 9L;
                    step_hash(385);
                    if (l_634)
                        break;
                    step_hash(391);
                    if (((unsigned short)(+(2UL >= ((signed char)func_37(((short)((void*)0 != l_630) >> (short)8), (p_20 < p_20)) << (signed char)g_127))) >> (unsigned short)((int)l_643 + (int)l_644)))
                    {
                        step_hash(387);
                        (*g_189) = l_645;
                    }
                    else
                    {
                        unsigned l_646 = 4294967295UL;
                        step_hash(389);
                        (*l_610) = 0x363AA618L;
                        step_hash(390);
                        l_646 = (*l_610);
                    }
                }
                step_hash(393);
                (*l_645) &= (&l_624 != &g_190);
                step_hash(394);
                if (g_236)
                    continue;
            }
            step_hash(396);
            if ((*l_610))
                break;
        }
        step_hash(398);
        g_70 ^= 0xFD87D1DAL;
    }
    else
    {
        int **l_654 = (void*)0;
        int *l_659 = &g_2;
        short l_689 = 0L;
        step_hash(432);
        if (((unsigned)g_523 + (unsigned)(~(l_649 != ((signed char)((unsigned char)(func_37((g_2 ^ ((void*)0 == l_654)), (+((p_20 || (-5L)) < p_20))) && p_20) / (unsigned char)p_20) << (signed char)p_20)))))
        {
            unsigned l_655 = 0xD482ACB0L;
            int *l_658 = &g_255;
            step_hash(401);
            l_655 ^= g_423;
            step_hash(402);
            (*l_539) = g_236;
            step_hash(408);
            if ((((unsigned short)(g_523 != (*l_659)) << (unsigned short)0) || (-6L)))
            {
                step_hash(404);
                (*g_189) = &g_2;
                step_hash(405);
                (*l_658) = ((p_20 == ((unsigned)g_127 / (unsigned)1UL)) <= g_70);
            }
            else
            {
                int *l_670 = &g_70;
                step_hash(407);
                return l_670;
            }
            step_hash(415);
            if ((**g_189))
            {
                step_hash(410);
                (*g_189) = func_47((*g_189), (&l_654 != &l_540), p_20, (*g_189), g_523);
            }
            else
            {
                step_hash(412);
                (*l_658) = p_20;
                step_hash(413);
                (*g_189) = (void*)0;
                step_hash(414);
                l_671 &= ((*l_658) & (*l_658));
            }
        }
        else
        {
            int *l_683 = &g_70;
            step_hash(430);
            for (g_423 = 11; (g_423 == (-3)); g_423 -= 1)
            {
                int *l_686 = &g_2;
                step_hash(426);
                for (p_20 = (-30); (p_20 <= 16); p_20++)
                {
                    int *l_687 = &g_2;
                    int ***l_690 = &l_654;
                    step_hash(423);
                    (*l_683) = ((short)((unsigned)(-(int)(3UL > ((signed char)(*l_610) % (signed char)((signed char)(*l_686) >> (signed char)l_689)))) % (unsigned)(*l_539)) - (short)(-2L));
                    step_hash(424);
                    (*l_683) = p_20;
                    step_hash(425);
                    g_523 &= ((l_690 != (void*)0) >= (*l_686));
                }
                step_hash(427);
                (*g_189) = l_659;
                step_hash(428);
                (*l_610) |= (*l_683);
                step_hash(429);
                if (p_20)
                    continue;
            }
            step_hash(431);
            return l_659;
        }
        step_hash(433);
        return l_691;
    }
    step_hash(435);
    (*l_610) = p_20;
    step_hash(436);
    return l_610;
}
static short func_21(unsigned p_22, int * p_23, int * p_24, int * p_25)
{
    int l_475 = 0x49BB3FBAL;
    int ***l_496 = &g_189;
    step_hash(259);
    for (p_22 = 23; (p_22 >= 44); p_22++)
    {
        step_hash(256);
        g_70 ^= g_114;
        step_hash(257);
        if ((*p_25))
            continue;
        step_hash(258);
        (*p_25) = (g_423 != l_475);
    }
    step_hash(265);
    if ((*p_25))
    {
        unsigned l_488 = 1UL;
        int ***l_495 = (void*)0;
        step_hash(261);
        l_475 = ((unsigned short)(!((short)(((short)(0x6FF82A61L == ((void*)0 == p_25)) >> (short)13) < ((signed char)((((((l_475 == l_475) ^ p_22) < l_475) != ((signed char)((unsigned short)0UL + (unsigned short)0UL) + (signed char)g_255)) >= g_2) <= 4294967294UL) * (signed char)p_22)) / (short)l_488)) + (unsigned short)p_22);
        step_hash(262);
        (*p_24) = (g_255 >= ((unsigned char)g_255 * (unsigned char)(((+(g_70 > ((short)0xB0FCL << (short)(l_495 != l_496)))) & (&g_190 != &p_23)) == ((unsigned char)l_488 >> (unsigned char)p_22))));
    }
    else
    {
        step_hash(264);
        (*g_189) = (void*)0;
    }
    step_hash(266);
    return p_22;
}
static int * func_27(int * p_28, int * p_29, unsigned short p_30)
{
    int *l_466 = &g_2;
    unsigned l_467 = 0xEA905F1CL;
    int *l_468 = &g_70;
    step_hash(242);
    (*l_468) = ((*p_28) <= (*p_29));
    step_hash(250);
    for (g_236 = (-25); (g_236 >= (-16)); g_236 += 1)
    {
        unsigned l_471 = 4294967291UL;
        int *l_472 = (void*)0;
        step_hash(246);
        (*l_468) = l_471;
        step_hash(247);
        if ((*l_468))
            break;
        step_hash(248);
        (*l_468) |= (g_114 ^ p_30);
        step_hash(249);
        return l_472;
    }
    step_hash(251);
    return l_468;
}
static int * func_32(unsigned p_33, int p_34)
{
    int *l_372 = &g_255;
    int l_383 = (-3L);
    int ***l_439 = &g_189;
    int ***l_453 = (void*)0;
    step_hash(238);
    for (p_33 = 0; (p_33 >= 28); p_33 += 1)
    {
        unsigned char l_373 = 3UL;
        int ***l_375 = &g_189;
        int *l_464 = &g_70;
        step_hash(232);
        for (g_70 = 0; (g_70 == 3); g_70++)
        {
            int ***l_374 = &g_189;
            unsigned char l_386 = 0xB8L;
            unsigned l_390 = 1UL;
            signed char l_436 = 1L;
            short l_437 = 0xF58FL;
            unsigned l_448 = 0xE52FAC2CL;
            step_hash(199);
            l_372 = &p_34;
            step_hash(231);
            if (l_373)
            {
                int **l_380 = &l_372;
                step_hash(201);
                l_383 |= ((l_374 != l_375) | (((signed char)(0xC744L & func_37((p_33 > ((int)(l_380 == (void*)0) / (int)p_34)), ((short)g_236 % (short)65535UL))) << (signed char)g_236) & 247UL));
            }
            else
            {
                unsigned l_389 = 4294967295UL;
                int *l_391 = &g_2;
                int ***l_415 = &g_189;
                int *l_438 = &g_255;
                step_hash(223);
                if (((&g_190 == &g_190) >= ((unsigned short)l_386 - (unsigned short)(((void*)0 == &g_190) ^ (((((-6L) ^ 0x05BA0CF0L) && (l_386 | (l_389 < 2UL))) | l_390) & g_2)))))
                {
                    step_hash(204);
                    return l_391;
                }
                else
                {
                    unsigned l_403 = 0x3491E8C4L;
                    int *l_418 = &g_255;
                    unsigned l_429 = 0UL;
                    step_hash(212);
                    for (p_34 = 0; (p_34 < 4); p_34 += 2)
                    {
                        int **l_396 = &g_190;
                        int *l_404 = &l_383;
                        step_hash(209);
                        (*g_189) = &p_34;
                        step_hash(210);
                        (*l_404) = ((signed char)(((((void*)0 != l_396) ^ ((int)func_37(((short)0x7E04L >> (short)5), p_33) / (int)g_2)) <= ((**g_189) & 0x32C8177FL)) && func_37(((unsigned char)p_34 >> (unsigned char)g_70), g_324)) + (signed char)l_403);
                        step_hash(211);
                        (**l_374) = func_47(func_47((*g_189), g_222, ((signed char)((signed char)((signed char)(1UL || (((signed char)(*l_372) - (signed char)(((unsigned char)((*l_372) <= ((void*)0 != l_415)) - (unsigned char)((short)l_403 / (short)func_37((**l_396), p_34))) > p_34)) <= (-1L))) * (signed char)g_114) * (signed char)3L) * (signed char)p_34), l_418, (***l_375)), (***l_375), g_114, (*g_189), p_33);
                    }
                    step_hash(213);
                    (*l_372) = ((signed char)(p_34 && ((short)p_33 % (short)65529UL)) >> (signed char)6);
                    step_hash(221);
                    if (p_33)
                    {
                        step_hash(215);
                        (*l_418) = (g_423 > (!g_423));
                        step_hash(216);
                        if (g_114)
                            continue;
                    }
                    else
                    {
                        unsigned char l_424 = 247UL;
                        step_hash(218);
                        (*l_372) &= l_424;
                        step_hash(219);
                        l_383 |= ((signed char)((short)g_222 >> (short)(g_324 > p_34)) >> (signed char)6);
                        step_hash(220);
                        (*l_418) = l_429;
                    }
                    step_hash(222);
                    (*l_418) &= (*l_372);
                }
                step_hash(229);
                for (g_423 = 0; (g_423 == 0); ++g_423)
                {
                    step_hash(227);
                    (**l_415) = func_47(func_47(&g_2, ((unsigned char)((*l_374) == &g_190) / (unsigned char)0x21L), p_33, func_47(&g_2, func_37(((unsigned char)func_37((((!(0xFBL || (!g_236))) || func_37(g_236, p_33)) | l_436), l_437) >> (unsigned char)4), g_70), (*l_372), &g_255, p_33), g_255), (*l_372), p_34, l_438, p_33);
                    step_hash(228);
                    if ((*g_190))
                        continue;
                }
                step_hash(230);
                (*l_438) = ((func_37((l_439 == (void*)0), p_34) || (l_373 < ((unsigned short)(!((~(((short)func_37((func_37((*l_391), ((((unsigned short)(((*l_415) == (void*)0) ^ ((unsigned short)func_37(p_34, (*l_372)) / (unsigned short)0x541BL)) << (unsigned short)p_34) | (*l_391)) | p_33)) ^ g_255), p_33) * (short)l_448) && (*l_438))) > g_2)) - (unsigned short)0x979EL))) ^ g_255);
            }
        }
        step_hash(237);
        if ((((signed char)g_114 >> (signed char)2) ^ func_37(func_37(p_34, ((signed char)((l_439 == l_453) || g_423) - (signed char)(l_453 == l_375))), ((((int)((signed char)g_255 >> (signed char)2) - (int)0x1952FADDL) ^ g_324) && g_114))))
        {
            step_hash(234);
            (*l_372) |= ((unsigned short)((short)(4294967295UL || g_236) - (short)g_2) << (unsigned short)14);
        }
        else
        {
            int *l_465 = &g_70;
            step_hash(236);
            (*l_465) = ((signed char)p_34 * (signed char)0x01L);
        }
    }
    step_hash(239);
    (*l_372) ^= g_222;
    step_hash(240);
    return &g_2;
}
static short func_37(unsigned p_38, unsigned short p_39)
{
    int l_40 = 0x1AA2910AL;
    int l_41 = 0x47030FC3L;
    step_hash(6);
    l_41 ^= l_40;
    step_hash(7);
    return p_39;
}
static short func_42(int * p_43, int * p_44, int * p_45, short p_46)
{
    unsigned char l_64 = 255UL;
    signed char l_98 = 0x7EL;
    int l_164 = 0xCA327EC8L;
    signed char l_235 = 0x15L;
    int **l_237 = &g_190;
    int l_276 = (-1L);
    int l_290 = 0L;
    unsigned l_349 = 0x68300D3CL;
    unsigned char l_352 = 0x1AL;
    int *l_353 = &g_255;
    unsigned short l_367 = 0x3511L;
    step_hash(180);
    if (g_2)
    {
        signed char l_65 = 5L;
        signed char l_68 = 0L;
        int *l_69 = &g_70;
        int *l_90 = (void*)0;
        step_hash(14);
        (*l_69) |= ((signed char)((short)((short)((int)((unsigned short)l_64 << (unsigned short)p_46) % (int)p_46) / (short)(+func_37(((-3L) < ((l_65 ^ 0x16FEL) != p_46)), (p_46 >= ((unsigned short)l_68 >> (unsigned short)4))))) + (short)g_2) / (signed char)l_65);
        step_hash(22);
        for (l_68 = (-24); (l_68 != (-28)); --l_68)
        {
            int **l_73 = &l_69;
            step_hash(18);
            (*l_73) = (void*)0;
            step_hash(19);
            if ((*p_44))
                break;
            step_hash(20);
            g_70 = (-1L);
            step_hash(21);
            g_70 = func_37(p_46, p_46);
        }
        step_hash(54);
        if (l_64)
        {
            int *l_74 = (void*)0;
            int *l_75 = &g_70;
            step_hash(24);
            (*l_75) = 0x3EA6DE45L;
        }
        else
        {
            int *l_79 = &g_2;
            int l_100 = (-4L);
            step_hash(53);
            if (func_37(func_37(g_2, g_2), p_46))
            {
                signed char l_76 = 7L;
                int *l_83 = &g_70;
                int **l_84 = &l_79;
                step_hash(27);
                (*l_83) ^= (((0x50E4L == (l_76 ^ (p_46 > (((signed char)(func_37(g_2, (l_79 == &g_70)) <= (((unsigned short)(*l_79) << (unsigned short)7) == (-(unsigned char)l_64))) * (signed char)0xFCL) != 4UL)))) & g_2) & (*l_79));
                step_hash(28);
                (*l_84) = func_47(p_44, l_64, (*l_79), p_45, g_2);
                step_hash(29);
                return g_2;
            }
            else
            {
                int *l_89 = &g_2;
                unsigned l_103 = 4294967289UL;
                signed char l_140 = 0xF2L;
                step_hash(31);
                g_70 = ((short)g_70 / (short)0x8DDFL);
                step_hash(38);
                for (p_46 = 13; (p_46 == 29); p_46 += 6)
                {
                    int *l_95 = &g_70;
                    int **l_99 = &l_69;
                    step_hash(35);
                    (*l_99) = func_47(l_89, p_46, ((void*)0 != l_90), func_47(func_47(&g_70, g_70, ((unsigned short)((((unsigned)((void*)0 == l_95) % (unsigned)(((int)func_37(g_70, (*l_79)) / (int)g_70) | p_46)) > (*l_79)) ^ g_70) / (unsigned short)l_98), &g_2, g_70), p_46, p_46, p_44, l_98), g_2);
                    step_hash(36);
                    l_103 ^= ((g_70 & ((((void*)0 == &g_70) || (0xDE23EDE1L > l_100)) != ((short)func_37((&g_2 != (*l_99)), (*l_69)) >> (short)p_46))) <= p_46);
                    step_hash(37);
                    (*l_95) |= (((short)(-1L) << (short)p_46) != ((l_89 == l_69) == (((signed char)func_37((*l_79), (**l_99)) << (signed char)5) <= p_46)));
                }
                step_hash(51);
                for (p_46 = 0; (p_46 <= 16); p_46++)
                {
                    unsigned l_125 = 0xEF93A2F2L;
                    step_hash(50);
                    if (((p_46 <= ((*l_79) > (&p_45 == &p_44))) & (l_89 != (void*)0)))
                    {
                        signed char l_112 = 0x48L;
                        int **l_113 = &l_69;
                        step_hash(43);
                        (*l_113) = func_47(func_47(p_43, g_2, p_46, l_89, ((void*)0 != p_44)), ((unsigned char)(0x5E00L ^ (l_112 != (*l_79))) % (unsigned char)p_46), g_70, &g_70, g_70);
                        step_hash(44);
                        g_114 ^= func_37(p_46, g_70);
                        step_hash(45);
                        return p_46;
                    }
                    else
                    {
                        signed char l_126 = 1L;
                        int *l_139 = &g_70;
                        step_hash(47);
                        g_127 ^= (g_114 && ((unsigned)((((void*)0 == p_43) && g_114) == g_114) % (unsigned)((unsigned)(func_37(((short)(func_37((((int)0x2C06FE3AL % (int)((int)0x2F63B645L - (int)((g_2 != g_114) == g_2))) || l_125), g_70) & g_2) * (short)65528UL), l_126) || 7L) - (unsigned)0xAC53A074L)));
                        step_hash(48);
                        (*l_139) = (((unsigned char)(p_46 && ((short)((signed char)(func_37(p_46, ((unsigned char)(-(int)(func_37((1L & 0xEBA2L), ((((signed char)1L / (signed char)g_2) <= g_70) >= (l_69 != (void*)0))) > 0x6C79135EL)) - (unsigned char)g_114)) & p_46) % (signed char)l_126) >> (short)9)) / (unsigned char)0x74L) >= g_70);
                        step_hash(49);
                        return g_127;
                    }
                }
                step_hash(52);
                l_140 = (*p_45);
            }
        }
    }
    else
    {
        unsigned l_141 = 0x97844A5BL;
        int *l_149 = (void*)0;
        int **l_148 = &l_149;
        signed char l_192 = 0x32L;
        signed char l_289 = 0x36L;
        unsigned l_301 = 0xA247C74DL;
        int l_320 = 0xCBF4361AL;
        unsigned char l_325 = 0xAEL;
        step_hash(146);
        if (l_141)
        {
            int l_147 = 0L;
            unsigned short l_178 = 0x5B4EL;
            int **l_191 = &l_149;
            step_hash(57);
            g_70 = (+((l_141 && g_114) > ((p_46 == (((int)(*p_43) % (int)g_114) || 0L)) ^ ((short)0x152AL + (short)((((-(unsigned)l_147) | (((&p_44 != l_148) == 1L) | 0x7DL)) > (*p_43)) >= l_64)))));
            step_hash(75);
            for (l_141 = 16; (l_141 >= 4); --l_141)
            {
                unsigned short l_152 = 1UL;
                unsigned short l_165 = 65526UL;
                unsigned l_172 = 0x5D02E7AFL;
                int *l_176 = &g_2;
                step_hash(74);
                if (l_152)
                {
                    unsigned short l_163 = 1UL;
                    unsigned l_169 = 4UL;
                    step_hash(68);
                    for (p_46 = 5; (p_46 == (-5)); p_46 -= 1)
                    {
                        int *l_166 = &g_70;
                        step_hash(65);
                        g_70 = ((short)g_2 * (short)((signed char)p_46 * (signed char)(((3L > (0x093C7B1CL | ((((unsigned)func_37(((l_147 != 0xCBL) != l_163), g_127) + (unsigned)4294967289UL) != l_164) > l_98))) || g_127) > l_165)));
                        step_hash(66);
                        (*l_166) = (*p_44);
                        step_hash(67);
                        (*l_148) = func_47(func_47((*l_148), g_70, ((unsigned)p_46 / (unsigned)(p_46 && l_169)), l_166, p_46), p_46, p_46, &g_70, l_98);
                    }
                    step_hash(69);
                    (*l_148) = func_47(&l_147, (g_114 ^ ((unsigned short)func_37(l_172, g_70) << (unsigned short)3)), (l_169 || 0x4516985CL), p_45, l_147);
                }
                else
                {
                    int *l_177 = (void*)0;
                    step_hash(71);
                    g_70 = func_37(g_70, g_127);
                    step_hash(72);
                    l_147 = (-(unsigned char)((unsigned short)((void*)0 == l_176) >> (unsigned short)((&g_70 == l_177) && (l_178 <= (0x1BL > ((((short)((signed char)p_46 - (signed char)((5L >= (((func_37(((((signed char)l_178 % (signed char)g_127) == 0x01L) < 7L), (*l_176)) | 0L) & 0UL) < g_2)) < (-10L))) % (short)0x00BEL) < g_127) != p_46))))));
                    step_hash(73);
                    (*g_190) = (&l_177 != g_189);
                }
            }
            step_hash(76);
            l_192 ^= (l_191 == (void*)0);
        }
        else
        {
            unsigned char l_196 = 254UL;
            int **l_227 = (void*)0;
            unsigned char l_228 = 0xBAL;
            step_hash(78);
            (*g_190) = (g_114 || ((-9L) & g_114));
            step_hash(96);
            if ((**g_189))
            {
                int **l_195 = &g_190;
                step_hash(80);
                l_196 &= ((unsigned)0x201DAD36L + (unsigned)(&g_190 == l_195));
            }
            else
            {
                unsigned char l_205 = 0xAAL;
                step_hash(82);
                (**g_189) = (**g_189);
                step_hash(83);
                (*g_189) = &l_164;
                step_hash(95);
                for (p_46 = 0; (p_46 > 17); p_46 += 1)
                {
                    unsigned l_213 = 4294967295UL;
                    step_hash(87);
                    (*g_190) ^= ((unsigned short)(((unsigned short)func_37(((short)0x5CEDL * (short)(l_205 >= g_114)), (-(unsigned)(!(0xFD4CL != p_46)))) / (unsigned short)0x7108L) || g_2) >> (unsigned short)(func_37(g_70, g_114) && g_70));
                    step_hash(88);
                    (**g_189) &= ((int)((unsigned char)l_196 * (unsigned char)253UL) % (int)(*p_43));
                    step_hash(89);
                    if ((*p_43))
                        continue;
                    step_hash(94);
                    for (l_141 = 1; (l_141 != 48); l_141 += 1)
                    {
                        step_hash(93);
                        return l_213;
                    }
                }
            }
            step_hash(145);
            if ((((unsigned short)(g_70 && func_37(func_37(((unsigned short)((~(((((int)(1UL && (1UL & ((((*g_190) | ((**g_189) == (((unsigned)(g_114 || ((((*l_148) != (*g_189)) == l_98) != 4294967294UL)) + (unsigned)l_196) == 0L))) | l_196) > g_2))) - (int)l_196) ^ 1L) && g_2) && (*p_43))) == 0xFE1FC20EL) >> (unsigned short)g_127), g_127), l_196)) << (unsigned short)g_222) <= (*g_190)))
            {
                unsigned l_229 = 4294967291UL;
                step_hash(98);
                (*g_189) = (*l_148);
                step_hash(99);
                l_228 |= ((short)(((func_37(((unsigned short)(1L && (func_37((func_37(g_114, ((g_70 <= 1UL) == 0x71L)) ^ 0xE5L), (l_196 ^ ((void*)0 != l_227))) & g_70)) >> (unsigned short)4), g_222) > g_2) != p_46) | 5UL) >> (short)8);
                step_hash(117);
                if (l_229)
                {
                    unsigned l_230 = 0x9EDA7472L;
                    step_hash(101);
                    l_230 = (*p_44);
                    step_hash(108);
                    for (g_222 = (-22); (g_222 >= (-10)); g_222 += 4)
                    {
                        int *l_233 = (void*)0;
                        int *l_234 = &l_164;
                        step_hash(105);
                        if (g_70)
                            break;
                        step_hash(106);
                        if (l_229)
                            continue;
                        step_hash(107);
                        (*l_234) = l_64;
                    }
                }
                else
                {
                    step_hash(110);
                    (*g_189) = p_45;
                    step_hash(116);
                    if (func_37(((g_222 ^ l_235) == 0L), p_46))
                    {
                        step_hash(112);
                        g_70 &= ((*g_189) != (void*)0);
                        step_hash(113);
                        g_236 = (0x36C7L && p_46);
                    }
                    else
                    {
                        int ***l_238 = &l_227;
                        step_hash(115);
                        (*l_238) = l_237;
                    }
                }
                step_hash(128);
                if (l_98)
                {
                    unsigned char l_241 = 0xB7L;
                    int l_250 = 0xDFA9741CL;
                    int l_251 = (-10L);
                    step_hash(123);
                    for (g_127 = (-20); (g_127 > (-7)); ++g_127)
                    {
                        step_hash(122);
                        return l_241;
                    }
                    step_hash(124);
                    (*g_189) = func_47(func_47((*g_189), g_114, ((short)(~((((unsigned short)p_46 / (unsigned short)((unsigned char)p_46 - (unsigned char)((short)p_46 - (short)(0L && ((l_229 <= (func_37(func_37(g_127, g_127), g_114) & l_229)) | l_229))))) != p_46) < l_250)) >> (short)p_46), p_45, g_127), g_114, l_250, (*l_237), l_251);
                    step_hash(125);
                    l_251 &= l_229;
                }
                else
                {
                    unsigned short l_252 = 0x2728L;
                    step_hash(127);
                    return l_252;
                }
            }
            else
            {
                unsigned l_253 = 0x7F2AF577L;
                int l_262 = 1L;
                step_hash(142);
                if ((*g_190))
                {
                    int *l_254 = &g_255;
                    step_hash(131);
                    (**g_189) = (g_2 & (-2L));
                    step_hash(132);
                    (**g_189) = l_253;
                    step_hash(133);
                    (*l_254) &= (**g_189);
                    step_hash(139);
                    if ((**g_189))
                    {
                        step_hash(135);
                        (*l_237) = func_47(p_45, p_46, g_255, (*g_189), p_46);
                    }
                    else
                    {
                        int ***l_256 = &l_237;
                        step_hash(137);
                        (*l_256) = &p_43;
                        step_hash(138);
                        (*l_237) = (void*)0;
                    }
                }
                else
                {
                    signed char l_259 = 0x1EL;
                    step_hash(141);
                    (*g_190) |= ((1UL && (p_46 > 0xFD68L)) == ((((unsigned short)g_2 >> (unsigned short)l_259) != ((short)(func_37(p_46, g_222) && (((0x870BL != p_46) & g_127) | 4L)) - (short)g_222)) && 0x5AEAL));
                }
                step_hash(143);
                l_262 &= (p_46 & g_114);
                step_hash(144);
                l_262 = ((unsigned short)((int)func_37(g_222, p_46) / (int)((signed char)((unsigned short)(&p_43 == &g_190) * (unsigned short)l_253) * (signed char)(((-(unsigned short)(((*p_44) & l_262) != l_262)) < p_46) || 0L))) >> (unsigned short)g_222);
            }
        }
        step_hash(147);
        (*l_148) = func_47((*l_237), ((unsigned short)(p_46 >= ((short)l_276 << (short)((((signed char)(p_46 < ((unsigned char)((unsigned short)((unsigned short)p_46 + (unsigned short)((short)p_46 / (short)((unsigned char)((((&l_237 == (void*)0) ^ 0x70L) || g_255) ^ p_46) / (unsigned char)(-4L)))) + (unsigned short)0xB961L) * (unsigned char)p_46)) + (signed char)g_114) <= p_46) ^ g_70))) + (unsigned short)0x57FCL), l_289, (*g_189), p_46);
        step_hash(148);
        (*l_237) = p_43;
        step_hash(179);
        if ((*p_45))
        {
            int *l_291 = (void*)0;
            int *l_292 = &g_70;
            step_hash(150);
            (*l_292) |= l_290;
        }
        else
        {
            signed char l_295 = (-1L);
            int *l_319 = &g_255;
            unsigned l_330 = 0xE2BE75F2L;
            step_hash(152);
            (*l_148) = (*g_189);
            step_hash(176);
            for (l_289 = 0; (l_289 == 4); l_289++)
            {
                signed char l_296 = (-5L);
                step_hash(156);
                (*g_189) = func_47(func_47((*g_189), ((g_114 > ((l_295 >= l_296) || ((void*)0 != (*g_189)))) ^ (~((unsigned char)0x2FL * (unsigned char)((((unsigned short)g_70 >> (unsigned short)14) >= ((l_301 ^ (*p_44)) == 1L)) < 7L)))), g_70, p_44, l_296), g_70, g_114, (*g_189), p_46);
                step_hash(173);
                for (l_290 = 0; (l_290 < 24); l_290 += 3)
                {
                    unsigned l_318 = 0xAFC33171L;
                    step_hash(166);
                    if ((*g_190))
                    {
                        step_hash(161);
                        l_319 = func_47((*g_189), p_46, ((unsigned char)((signed char)(((signed char)((int)1L + (int)0xBF95CD84L) << (signed char)(func_37((((signed char)((unsigned short)((unsigned short)l_318 * (unsigned short)((void*)0 != &g_190)) - (unsigned short)g_127) - (signed char)(((void*)0 == p_44) >= p_46)) && 8L), p_46) | 0xDF84B9FBL)) <= l_296) % (signed char)g_2) + (unsigned char)g_2), p_44, p_46);
                        step_hash(162);
                        return g_222;
                    }
                    else
                    {
                        step_hash(164);
                        l_320 = (&g_190 != &g_190);
                        step_hash(165);
                        (*l_319) = (-(unsigned short)65526UL);
                    }
                    step_hash(167);
                    (*l_319) = ((short)g_324 * (short)(!(p_46 ^ (l_325 == 7L))));
                    step_hash(172);
                    for (l_98 = (-23); (l_98 != (-10)); ++l_98)
                    {
                        step_hash(171);
                        l_330 = ((signed char)g_324 + (signed char)g_127);
                    }
                }
                step_hash(174);
                (*l_319) = (0xC0L < (((short)(0x92L >= ((short)((short)((unsigned short)l_296 * (unsigned short)g_114) + (short)((unsigned)((int)((unsigned char)((*g_189) != p_43) - (unsigned char)((short)((((signed char)(0x445BE591L <= p_46) * (signed char)0xE9L) > (*l_319)) < p_46) - (short)0x37B5L)) - (int)(**g_189)) / (unsigned)0x8C589242L)) + (short)0x46E4L)) << (short)6) | g_127));
                step_hash(175);
                (*l_319) = l_349;
            }
            step_hash(177);
            g_70 = ((unsigned char)g_114 + (unsigned char)(*l_319));
            step_hash(178);
            (*l_319) = (*p_45);
        }
    }
    step_hash(181);
    (*l_353) = l_352;
    step_hash(182);
    (*g_189) = (*g_189);
    step_hash(190);
    if ((((signed char)g_236 - (signed char)g_255) != (p_44 != (*g_189))))
    {
        unsigned char l_364 = 0xD0L;
        step_hash(184);
        (*l_353) &= func_37(((signed char)(0x90L || ((unsigned short)((unsigned short)((((signed char)((4294967293UL < g_236) ^ p_46) * (signed char)((*p_44) < l_364)) <= 1L) || ((func_37(g_127, func_37(g_222, l_364)) > g_70) || (*p_44))) << (unsigned short)2) >> (unsigned short)l_364)) + (signed char)1L), l_364);
        step_hash(185);
        l_367 ^= ((unsigned char)p_46 >> (unsigned char)5);
    }
    else
    {
        step_hash(187);
        (*l_237) = (*l_237);
        step_hash(188);
        (*l_353) ^= (-1L);
        step_hash(189);
        (*l_353) |= 0xF09B2C3DL;
    }
    step_hash(191);
    return (*l_353);
}
static int * func_47(int * p_48, signed char p_49, int p_50, int * p_51, unsigned p_52)
{
    unsigned l_53 = 1UL;
    step_hash(9);
    p_51 = &g_2;
    step_hash(10);
    l_53 &= func_37(p_49, g_2);
    step_hash(11);
    return p_51;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_70, "g_70", print_hash_value);
    transparent_crc(g_114, "g_114", print_hash_value);
    transparent_crc(g_127, "g_127", print_hash_value);
    transparent_crc(g_222, "g_222", print_hash_value);
    transparent_crc(g_236, "g_236", print_hash_value);
    transparent_crc(g_255, "g_255", print_hash_value);
    transparent_crc(g_324, "g_324", print_hash_value);
    transparent_crc(g_423, "g_423", print_hash_value);
    transparent_crc(g_523, "g_523", print_hash_value);
    transparent_crc(g_611, "g_611", print_hash_value);
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
