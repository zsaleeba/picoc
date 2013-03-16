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
static short g_2 = (-6L);
static int g_42 = 0x3E997306L;
static int g_69 = 0xCB0BE945L;
static int *g_80 = &g_69;
static unsigned g_113 = 4294967295UL;
static short g_121 = 0x8E28L;
static int g_138 = (-1L);
static int ***g_209 = (void*)0;
static unsigned g_373 = 0xC3130D0CL;
static int g_382 = 0L;
static unsigned short g_428 = 65528UL;
static int func_1(void);
static short func_6(signed char p_7, unsigned p_8, signed char p_9, int p_10, unsigned char p_11);
static unsigned func_14(signed char p_15, int p_16, unsigned char p_17, unsigned p_18, int p_19);
static unsigned func_22(unsigned char p_23);
static int func_28(short p_29, unsigned p_30, unsigned p_31, unsigned p_32, unsigned p_33);
static signed char func_36(signed char p_37, short p_38, unsigned p_39);
static int * func_45(int * p_46, unsigned p_47, short p_48, int * p_49, int * p_50);
static int * func_51(int p_52, unsigned short p_53);
static unsigned short func_55(int * p_56, signed char p_57);
static int * func_62(int * p_63);
static int func_1(void)
{
    unsigned l_3 = 9UL;
    unsigned l_323 = 4294967288UL;
    int l_623 = 0x083D2658L;
    int l_626 = 0xA52EACE0L;
    int **l_636 = &g_80;
    int ***l_635 = &l_636;
    unsigned char l_669 = 255UL;
    unsigned char l_670 = 255UL;
    signed char l_712 = 1L;
    signed char l_726 = 0x97L;
    step_hash(389);
    if ((g_2 | (l_3 & 0x5D09L)))
    {
        unsigned l_40 = 0xAE8B0121L;
        unsigned char l_639 = 248UL;
        short l_642 = 0x4475L;
        unsigned l_643 = 0x64BFA7E0L;
        step_hash(340);
        l_623 = ((short)func_6(g_2, (~(((short)(0xC7L ^ g_2) * (short)(g_2 >= func_14(((int)0L - (int)func_22((((unsigned short)0xC9FAL << (unsigned short)((int)func_28(g_2, ((signed char)func_36(l_40, l_40, g_2) - (signed char)l_40), l_3, g_2, g_2) + (int)l_3)) >= 1L))), g_69, g_121, g_138, l_323))) >= g_2)), g_2, g_2, g_382) << (short)g_2);
        step_hash(341);
        g_80 = func_62(&g_382);
        step_hash(342);
        (***l_635) &= (l_642 & g_69);
    }
    else
    {
        int l_648 = (-1L);
        int *l_690 = &g_138;
        step_hash(344);
        (**l_635) = (**l_635);
        step_hash(345);
        (*g_80) = (*g_80);
        step_hash(346);
        (*l_636) = &g_69;
        step_hash(388);
        if ((*g_80))
        {
            unsigned short l_661 = 6UL;
            int **l_691 = &g_80;
            step_hash(368);
            if ((*g_80))
            {
                unsigned short l_657 = 9UL;
                step_hash(362);
                for (g_2 = 0; (g_2 > 25); g_2 += 1)
                {
                    unsigned l_660 = 5UL;
                    step_hash(358);
                    if (((short)l_648 >> (short)4))
                    {
                        int *l_649 = &g_382;
                        step_hash(353);
                        (*l_649) |= (***l_635);
                        step_hash(354);
                        return (*l_649);
                    }
                    else
                    {
                        unsigned l_656 = 0xB949E8AFL;
                        step_hash(356);
                        l_660 &= (((unsigned short)g_138 + (unsigned short)((unsigned char)func_36(((unsigned)l_656 - (unsigned)(+l_657)), l_648, g_428) << (unsigned char)(**l_636))) || (((signed char)l_656 % (signed char)g_373) >= (-1L)));
                        step_hash(357);
                        (*g_80) = ((0L <= l_648) < (g_2 == g_113));
                    }
                    step_hash(359);
                    (**l_636) ^= func_36(l_661, (0xD8L & ((unsigned short)((void*)0 == (**l_635)) << (unsigned short)g_428)), g_428);
                    step_hash(360);
                    (**l_636) ^= ((~l_661) ^ 0xF27B2259L);
                    step_hash(361);
                    (*g_80) = ((func_28(g_121, g_42, func_28(l_661, ((((unsigned char)7UL - (unsigned char)((g_382 <= (-(short)(0xB4D5L < (((((short)(l_648 >= (0x1E2BL > l_648)) + (short)(-1L)) & g_42) & 0x0D8BF615L) < g_69)))) >= 0UL)) < (-2L)) >= l_669), g_121, l_670, g_121), l_661, g_2) > 0xB9B15962L) == 0x23L);
                }
                step_hash(363);
                (**l_636) = (***l_635);
                step_hash(364);
                (**l_636) = (-1L);
            }
            else
            {
                int l_687 = 0L;
                int *l_688 = (void*)0;
                int *l_689 = &l_623;
                step_hash(366);
                (*l_689) = ((signed char)((unsigned short)(~((signed char)((unsigned)(((-8L) == 0x093DL) >= ((int)((short)((int)(func_14(g_69, l_648, ((0x0C14L < g_121) >= ((**l_636) >= (g_69 || (((unsigned short)l_661 * (unsigned short)g_113) >= 0x36L)))), l_687, (***l_635)) < l_687) + (int)l_687) >> (short)9) % (int)g_2)) / (unsigned)l_661) + (signed char)0x46L)) << (unsigned short)11) << (signed char)g_2);
                step_hash(367);
                l_690 = &l_648;
            }
            step_hash(369);
            (*l_690) ^= 7L;
            step_hash(370);
            (*l_635) = l_691;
        }
        else
        {
            int l_701 = 0xB1E129D2L;
            step_hash(382);
            for (l_623 = (-15); (l_623 != (-6)); l_623 += 4)
            {
                unsigned l_700 = 4294967295UL;
                unsigned l_713 = 0x4B13D8B8L;
                unsigned l_714 = 0x72B9D6EFL;
                step_hash(380);
                for (l_3 = (-18); (l_3 >= 16); l_3 += 5)
                {
                    step_hash(378);
                    (***l_635) = (((short)((0x5EL ^ (~func_28((***l_635), g_373, (((int)0x03F6749BL / (int)l_700) < g_428), func_28(g_2, (***l_635), g_113, g_428, g_382), g_42))) != 0UL) + (short)0x13E5L) & l_700);
                    step_hash(379);
                    return l_701;
                }
                step_hash(381);
                (*l_636) = &g_382;
            }
            step_hash(387);
            for (g_2 = 0; (g_2 == (-13)); --g_2)
            {
                unsigned l_719 = 5UL;
            }
        }
    }
    step_hash(390);
    (*l_636) = func_62(&g_382);
    step_hash(391);
    (**l_635) = &g_69;
    step_hash(392);
    (*g_80) = (***l_635);
    step_hash(393);
    return (*g_80);
}
static short func_6(signed char p_7, unsigned p_8, signed char p_9, int p_10, unsigned char p_11)
{
    unsigned l_607 = 0UL;
    int l_608 = (-2L);
    int **l_622 = &g_80;
    step_hash(330);
    l_608 = l_607;
    step_hash(337);
    for (g_138 = 27; (g_138 > 12); g_138 -= 3)
    {
        int *l_611 = (void*)0;
        int *l_612 = &g_382;
        int **l_613 = &g_80;
        step_hash(334);
        (*l_612) = (func_22(p_11) & (l_611 == l_611));
        step_hash(335);
        l_608 = l_608;
        step_hash(336);
        (*l_613) = &l_608;
    }
    step_hash(338);
    (*l_622) = &l_608;
    step_hash(339);
    return g_138;
}
static unsigned func_14(signed char p_15, int p_16, unsigned char p_17, unsigned p_18, int p_19)
{
    int *l_324 = &g_42;
    int **l_325 = &l_324;
    int *l_471 = &g_138;
    int l_513 = 0x234A3B4DL;
    unsigned l_538 = 4294967291UL;
    short l_548 = (-1L);
    unsigned short l_573 = 5UL;
    short l_595 = 4L;
    int *l_606 = &l_513;
    step_hash(205);
    (*l_325) = l_324;
    step_hash(206);
    (*l_325) = func_62((*l_325));
    step_hash(326);
    if (p_17)
    {
        int *l_326 = &g_42;
        step_hash(208);
        (*l_325) = l_326;
    }
    else
    {
        unsigned char l_337 = 0x61L;
        int ***l_350 = &l_325;
        int l_404 = 0xC915508FL;
        int **l_421 = (void*)0;
        unsigned l_512 = 0x895EBCA2L;
        step_hash(324);
        if (((int)((func_28((0L > 0x8B248997L), ((-1L) && p_17), (((unsigned short)((((unsigned char)p_16 + (unsigned char)(((unsigned char)((signed char)l_337 + (signed char)g_121) * (unsigned char)((void*)0 != g_209)) > l_337)) > (*l_324)) != g_138) * (unsigned short)g_69) && (*l_324)), g_113, (*l_324)) == 0x34D4L) >= g_113) % (int)0xFB75AE65L))
        {
            unsigned l_346 = 0xACBDBD75L;
            int ***l_351 = &l_325;
            int l_356 = 0L;
            int l_383 = 1L;
            int ***l_399 = &l_325;
            step_hash(215);
            for (l_337 = 9; (l_337 >= 2); --l_337)
            {
                signed char l_347 = 0x5CL;
                step_hash(214);
                l_347 |= ((~((int)((((*l_324) == (&g_69 == &g_138)) || ((*l_324) != func_22(((signed char)(func_28((**l_325), g_69, ((l_346 | 255UL) || (65535UL < g_121)), g_2, p_18) & 4L) << (signed char)1)))) == p_19) % (int)p_17)) != p_16);
            }
            step_hash(216);
            l_356 &= (((p_19 < ((unsigned char)(l_350 != l_351) / (unsigned char)((int)(((signed char)(((func_36(p_18, g_121, ((**l_351) != (void*)0)) != g_138) > 0xA281A0A5L) | 0xF0L) * (signed char)p_17) <= (-6L)) % (int)p_16))) & 0xC3FCL) >= p_19);
            step_hash(217);
            (***l_350) = (((*l_324) ^ (((signed char)(***l_350) * (signed char)g_42) & g_113)) == (((short)func_28(((***l_350) & 4294967287UL), func_22(g_42), (p_16 || g_138), (***l_351), g_113) - (short)p_19) > 0x6B9E0243L));
            step_hash(276);
            if (((void*)0 != &g_69))
            {
                unsigned short l_381 = 0x7206L;
                int **l_388 = &g_80;
                int *l_441 = &g_138;
                step_hash(231);
                if ((((unsigned short)(~((unsigned short)(((int)((*l_325) != (void*)0) % (int)p_18) ^ ((void*)0 != g_209)) * (unsigned short)((void*)0 != &l_324))) % (unsigned short)g_113) >= ((signed char)((unsigned char)g_113 - (unsigned char)g_373) + (signed char)p_16)))
                {
                    short l_374 = 0x81CEL;
                    step_hash(220);
                    l_374 &= p_18;
                    step_hash(221);
                    (**l_325) = ((unsigned char)(((int)(***l_351) / (int)p_18) && ((((!(((*l_350) != (*l_351)) ^ (*g_80))) & 65535UL) < func_28(((unsigned)p_19 % (unsigned)l_381), g_382, l_383, g_113, g_121)) || g_138)) / (unsigned char)0xD1L);
                    step_hash(222);
                    (***l_350) = p_17;
                    step_hash(228);
                    if (p_16)
                    {
                        step_hash(224);
                        (***l_351) = (*g_80);
                        step_hash(225);
                        (*l_324) = (p_18 | g_2);
                    }
                    else
                    {
                        step_hash(227);
                        (***l_351) = ((unsigned)((unsigned)(l_388 == &g_80) + (unsigned)((int)((***l_350) && ((unsigned char)(((unsigned char)func_22(g_121) << (unsigned char)((short)(0xA330L | p_16) * (short)((unsigned char)(g_373 || p_15) + (unsigned char)g_2))) > g_69) % (unsigned char)g_113)) + (int)(*g_80))) / (unsigned)(*l_324));
                    }
                }
                else
                {
                    step_hash(230);
                    (**l_388) &= p_16;
                }
                step_hash(232);
                (*l_325) = func_51(func_55((*l_325), g_69), g_2);
                step_hash(233);
                (*l_324) = (((void*)0 == l_399) || ((unsigned short)(*l_324) >> (unsigned short)((unsigned char)255UL << (unsigned char)1)));
                step_hash(255);
                if (((**l_350) != (*l_325)))
                {
                    step_hash(235);
                    (*l_325) = (**l_350);
                    step_hash(236);
                    (*l_324) = g_121;
                    step_hash(237);
                    (*l_388) = (*l_325);
                }
                else
                {
                    int *l_468 = &g_69;
                    step_hash(239);
                    (***l_351) = func_22(((((l_381 ^ ((unsigned char)(((unsigned char)(((unsigned)((g_2 & ((!p_19) <= ((unsigned char)0x28L / (unsigned char)((signed char)((unsigned char)l_381 << (unsigned char)3) % (signed char)((unsigned short)(***l_399) / (unsigned short)((signed char)g_113 - (signed char)0xD9L)))))) < (l_421 != (void*)0)) - (unsigned)0x56AD2E30L) & g_69) + (unsigned char)9L) == p_17) + (unsigned char)0xF6L)) >= g_2) & 1UL) != p_19));
                    step_hash(240);
                    g_428 |= ((int)(+(p_15 >= g_382)) - (int)((unsigned short)65532UL + (unsigned short)((((**l_325) != p_17) < func_28(((short)6L << (short)15), (*l_324), (0x814FC1EBL ^ 0x2D3A3C20L), g_121, p_19)) >= (***l_350))));
                    step_hash(246);
                    if ((((unsigned char)p_16 << (unsigned char)(0xC6D1B6C7L | ((*l_324) || 4294967295UL))) == 0x33L))
                    {
                        step_hash(242);
                        (*l_324) |= (-3L);
                    }
                    else
                    {
                        short l_446 = (-1L);
                        unsigned l_465 = 0xF928766DL;
                        step_hash(244);
                        (**l_399) = (*l_325);
                        step_hash(245);
                        (***l_350) = ((unsigned char)(p_17 && ((unsigned short)((g_428 & (0L > (***l_350))) || func_36(((unsigned)((signed char)((unsigned)(***l_351) - (unsigned)((!g_113) && p_19)) / (signed char)p_16) + (unsigned)2UL), g_428, p_15)) >> (unsigned short)3)) << (unsigned char)l_465);
                    }
                    step_hash(254);
                    for (p_18 = (-17); (p_18 <= 20); ++p_18)
                    {
                        step_hash(250);
                        (*l_325) = (*l_325);
                        step_hash(251);
                        (*l_388) = l_468;
                        step_hash(252);
                        if ((**l_325))
                            continue;
                        step_hash(253);
                        (**l_325) = ((void*)0 != &l_421);
                    }
                }
            }
            else
            {
                unsigned l_469 = 1UL;
                int ***l_470 = &l_421;
                step_hash(272);
                if ((((g_121 == l_469) > 4294967286UL) & (((l_351 != l_470) <= func_55((*l_325), (***l_350))) & p_15)))
                {
                    step_hash(258);
                    (**l_350) = func_62(l_471);
                    step_hash(259);
                    (**l_399) = (*l_325);
                    step_hash(260);
                    (*g_80) = (*g_80);
                    step_hash(261);
                    (***l_399) = 0x2A5CB463L;
                }
                else
                {
                    unsigned l_501 = 0xCA6EFA3AL;
                    step_hash(268);
                    for (p_17 = 0; (p_17 < 47); p_17 += 1)
                    {
                        step_hash(266);
                        (**l_399) = (void*)0;
                        step_hash(267);
                        (*g_80) = ((unsigned short)p_18 / (unsigned short)(((short)(((int)((((signed char)(-(short)g_382) * (signed char)((unsigned char)0x7CL / (unsigned char)p_18)) > 0x8CL) || ((int)((p_15 ^ ((((unsigned)(~g_382) + (unsigned)g_138) < 0xAEF25888L) > 0xB22DE3F5L)) >= p_15) % (int)p_17)) + (int)0x8A12F214L) > g_373) % (short)p_15) | p_15));
                    }
                    step_hash(269);
                    (**l_351) = func_51(((unsigned char)((signed char)(((*l_351) == &g_80) >= 0L) - (signed char)p_16) >> (unsigned char)(g_382 <= ((unsigned char)((unsigned char)8UL >> (unsigned char)7) << (unsigned char)(0xAD775760L <= ((((((unsigned char)(&l_325 != (void*)0) >> (unsigned char)p_18) >= p_16) == g_69) != l_501) >= p_18))))), g_382);
                    step_hash(270);
                    (***l_399) = ((unsigned char)((unsigned)((*l_471) && (g_382 & g_121)) + (unsigned)1L) / (unsigned char)(((((unsigned short)(((unsigned short)p_18 >> (unsigned short)(4UL != (***l_350))) >= ((short)g_382 << (short)11)) >> (unsigned short)(g_69 && p_18)) && 9UL) >= 0x07D0L) && l_512));
                    step_hash(271);
                    (*l_471) ^= l_513;
                }
                step_hash(273);
                (**l_350) = (**l_350);
                step_hash(274);
                l_356 ^= ((***l_350) <= ((g_121 == ((unsigned short)(***l_399) * (unsigned short)(g_42 && (&g_80 == (void*)0)))) == 0xD6L));
                step_hash(275);
                (***l_351) &= p_16;
            }
        }
        else
        {
            unsigned char l_516 = 0xDAL;
            int l_556 = 0x293081E0L;
            int ***l_582 = &l_421;
            step_hash(322);
            if (l_516)
            {
                int **l_517 = &l_324;
                step_hash(279);
                (*l_325) = func_62((*l_325));
                step_hash(280);
                (**l_325) = (((l_517 != &l_324) ^ ((unsigned short)l_516 * (unsigned short)(((g_428 >= p_15) <= (-(unsigned char)(((void*)0 != g_209) > 0L))) > ((p_17 > p_16) <= (**l_517))))) || 0xA8BAL);
                step_hash(299);
                for (g_373 = 16; (g_373 > 38); ++g_373)
                {
                    step_hash(290);
                    for (l_337 = 0; (l_337 != 33); ++l_337)
                    {
                        int *l_533 = &l_404;
                        step_hash(287);
                        (*l_533) = ((signed char)(l_516 == ((int)(*g_80) + (int)p_17)) + (signed char)((int)(*g_80) - (int)((void*)0 != l_533)));
                        step_hash(288);
                        (*l_471) = (p_17 != (g_69 != ((*l_471) || ((short)((p_17 != ((int)0L + (int)p_15)) == (l_538 | 0x24L)) << (short)7))));
                        step_hash(289);
                        if ((*l_533))
                            continue;
                    }
                    step_hash(291);
                    if ((*g_80))
                        break;
                    step_hash(292);
                    (**l_325) = p_19;
                    step_hash(298);
                    for (g_138 = (-11); (g_138 <= (-26)); g_138--)
                    {
                        short l_541 = 0L;
                        step_hash(296);
                        l_541 |= l_516;
                        step_hash(297);
                        (**l_325) ^= ((short)0x8BAEL << (short)0);
                    }
                }
                step_hash(319);
                if (((func_28(g_113, ((unsigned short)((p_16 > ((unsigned char)(p_16 || (((*g_80) || ((0L != g_428) >= (func_28((g_113 | ((*l_325) != (*l_325))), p_19, g_113, g_42, l_548) | l_516))) >= g_428)) * (unsigned char)1L)) < g_428) >> (unsigned short)8), (*l_471), p_17, p_15) >= 8L) == (***l_350)))
                {
                    int *l_555 = &g_42;
                    step_hash(301);
                    (*g_80) |= (g_2 && (-(signed char)((unsigned short)0xAC75L - (unsigned short)((unsigned short)(func_28((func_22(l_516) ^ (*l_324)), p_16, (~0xD5DE0121L), (g_428 != ((l_516 && 0xA14F01B3L) >= 1L)), p_15) >= p_19) << (unsigned short)4))));
                    step_hash(309);
                    if ((*g_80))
                    {
                        int *l_554 = &g_382;
                        step_hash(303);
                        (*l_517) = l_554;
                    }
                    else
                    {
                        step_hash(305);
                        (*l_325) = (void*)0;
                        step_hash(306);
                        (*g_80) = (&g_382 != l_555);
                        step_hash(307);
                        l_556 ^= l_516;
                        step_hash(308);
                        (*l_555) = ((l_556 > ((unsigned char)((signed char)g_113 / (signed char)g_69) / (unsigned char)(~((((short)p_19 + (short)(((((signed char)(-1L) % (signed char)((((signed char)((unsigned)4294967290UL / (unsigned)(g_113 && ((p_16 != (((g_69 ^ g_121) == l_573) < 1L)) != g_428))) - (signed char)p_18) == p_17) || l_556)) > 0x31F5AF7DL) ^ g_2) & g_138)) | 0xC41BL) && g_428)))) != g_113);
                    }
                    step_hash(310);
                    (*l_471) ^= (*g_80);
                    step_hash(311);
                    (*g_80) = p_15;
                }
                else
                {
                    step_hash(318);
                    for (g_42 = 0; (g_42 >= (-26)); g_42 -= 2)
                    {
                        step_hash(316);
                        (*l_471) |= (*g_80);
                        step_hash(317);
                        (*l_517) = (*l_325);
                    }
                }
            }
            else
            {
                step_hash(321);
                (**l_350) = (*l_325);
            }
            step_hash(323);
            (*g_80) = (0x92931734L | (((signed char)func_22((0x8FL != (((((short)(l_582 != g_209) << (short)((7L <= ((signed char)((p_18 || p_19) != (((unsigned)g_138 + (unsigned)((signed char)(0x6E20L || g_2) * (signed char)g_428)) <= 0x996522A8L)) >> (signed char)p_19)) & g_373)) < g_69) | g_2) & g_373))) % (signed char)g_138) <= 1L));
        }
        step_hash(325);
        l_513 &= ((unsigned char)((unsigned char)((unsigned)l_595 - (unsigned)g_373) * (unsigned char)(*l_471)) * (unsigned char)((int)((unsigned)((g_209 == (void*)0) > (((signed char)p_17 / (signed char)func_28(((signed char)func_22(g_42) >> (signed char)5), ((signed char)l_337 << (signed char)(*l_471)), p_18, g_138, p_15)) < p_15)) - (unsigned)p_17) % (int)g_428));
    }
    step_hash(327);
    (*l_606) |= ((4294967286UL > g_2) && g_138);
    step_hash(328);
    return p_16;
}
static unsigned func_22(unsigned char p_23)
{
    int l_220 = 0L;
    int l_295 = 0xF0E4EAF2L;
    unsigned l_321 = 0x5C0CC7F1L;
    int l_322 = 0x068102F2L;
    step_hash(202);
    for (p_23 = 0; (p_23 < 41); ++p_23)
    {
        unsigned l_216 = 0x05AE8A67L;
        unsigned char l_225 = 8UL;
        int *l_226 = &l_220;
        int *l_294 = &g_138;
        unsigned l_296 = 3UL;
    }
    step_hash(203);
    return l_220;
}
static int func_28(short p_29, unsigned p_30, unsigned p_31, unsigned p_32, unsigned p_33)
{
    int l_54 = (-6L);
    int *l_208 = &l_54;
    int **l_207 = &l_208;
    int ***l_206 = &l_207;
    int *l_211 = &l_54;
    step_hash(155);
    for (p_29 = (-24); (p_29 == (-4)); p_29++)
    {
        short l_210 = 0xAC2EL;
        int *l_212 = &l_54;
    }
    step_hash(156);
    (*l_207) = (**l_206);
    step_hash(157);
    return p_30;
}
static signed char func_36(signed char p_37, short p_38, unsigned p_39)
{
    int *l_41 = &g_42;
    step_hash(3);
    (*l_41) |= g_2;
    step_hash(4);
    return g_2;
}
static int * func_45(int * p_46, unsigned p_47, short p_48, int * p_49, int * p_50)
{
    int *l_213 = &g_69;
    step_hash(151);
    l_213 = p_50;
    step_hash(152);
    return p_46;
}
static int * func_51(int p_52, unsigned short p_53)
{
    unsigned l_83 = 7UL;
    int **l_84 = &g_80;
    int ***l_85 = &l_84;
    unsigned l_118 = 0xF253ABC1L;
    step_hash(31);
    l_83 |= (*g_80);
    step_hash(32);
    (*l_85) = l_84;
    step_hash(148);
    if ((*g_80))
    {
        unsigned short l_96 = 0x5E6BL;
        step_hash(62);
        for (g_69 = 0; (g_69 < (-16)); g_69 -= 3)
        {
            unsigned char l_97 = 0xA4L;
            int **l_108 = (void*)0;
            int *l_140 = (void*)0;
            step_hash(61);
            if ((((+p_53) | g_69) > ((unsigned short)((unsigned char)((!((unsigned char)((unsigned short)(0xB133D7BFL <= (func_36(func_36(((void*)0 == (*l_85)), l_96, p_53), l_96, g_2) < l_97)) << (unsigned short)5) * (unsigned char)(-10L))) < p_52) - (unsigned char)p_52) / (unsigned short)6UL)))
            {
                int *l_98 = &g_42;
                step_hash(38);
                (**l_85) = func_62(l_98);
                step_hash(39);
                (*l_98) = (*g_80);
                step_hash(46);
                if ((&p_52 != (void*)0))
                {
                    int **l_99 = &l_98;
                    step_hash(41);
                    p_52 = ((*l_85) != l_99);
                    step_hash(42);
                    g_113 |= ((func_36(l_97, (0UL & ((signed char)((((unsigned char)((unsigned)(&g_80 == (void*)0) - (unsigned)0UL) + (unsigned char)((p_52 | ((unsigned short)((void*)0 != l_108) * (unsigned short)(((unsigned)(((unsigned char)(*l_98) + (unsigned char)g_69) & 0xBFL) / (unsigned)(**l_99)) & l_96))) ^ l_96)) < p_52) != 0x3FL) >> (signed char)(**l_99))), g_2) >= p_53) & 0x46L);
                    step_hash(43);
                    if (p_52)
                        continue;
                }
                else
                {
                    step_hash(45);
                    g_121 |= (func_36(g_69, g_2, g_69) != ((unsigned)((short)(&g_69 != (void*)0) * (short)(!l_118)) % (unsigned)((unsigned char)p_53 << (unsigned char)(p_52 <= p_52))));
                }
            }
            else
            {
                unsigned short l_134 = 0x4740L;
                step_hash(59);
                if (((**l_85) == &g_42))
                {
                    int *l_139 = &g_42;
                    step_hash(55);
                    for (p_53 = 0; (p_53 > 46); ++p_53)
                    {
                        int *l_135 = (void*)0;
                        int *l_136 = (void*)0;
                        int *l_137 = &g_138;
                    }
                }
                else
                {
                    step_hash(57);
                    (**l_85) = &g_138;
                    step_hash(58);
                    l_140 = &g_69;
                }
                step_hash(60);
                return &g_69;
            }
        }
        step_hash(63);
        (*l_84) = func_62(func_62(&p_52));
    }
    else
    {
        unsigned short l_158 = 65533UL;
        int ***l_201 = &l_84;
        step_hash(65);
        (***l_85) = ((unsigned short)((void*)0 == &g_138) << (unsigned short)12);
        step_hash(145);
        if ((***l_85))
        {
            unsigned char l_143 = 0x70L;
            int **l_144 = (void*)0;
            step_hash(138);
            if ((*g_80))
            {
                short l_163 = 0x98C0L;
                step_hash(99);
                if (func_36(l_143, (g_121 ^ (func_55(func_62(&g_42), p_53) ^ g_138)), (p_52 && (l_144 != l_144))))
                {
                    unsigned l_166 = 0x92CE2759L;
                    step_hash(74);
                    if (((short)func_36((**l_84), func_36((-(unsigned char)((short)g_2 * (short)(((signed char)func_36(((signed char)(p_53 && ((int)((unsigned short)(func_36((g_69 == (func_36(p_52, g_69, l_158) > ((unsigned char)3UL + (unsigned char)g_138))), g_138, l_158) < g_138) % (unsigned short)0x626FL) + (int)(-2L))) * (signed char)p_52), p_53, p_52) + (signed char)g_121) & 4294967293UL))), p_52, p_52), g_113) * (short)g_2))
                    {
                        step_hash(70);
                        (*l_84) = &p_52;
                    }
                    else
                    {
                        step_hash(72);
                        (**l_84) = ((-1L) >= 4UL);
                        step_hash(73);
                        (*g_80) ^= ((short)(l_163 | g_42) << (short)4);
                    }
                    step_hash(81);
                    for (l_158 = (-27); (l_158 > 42); l_158 += 7)
                    {
                        step_hash(78);
                        (***l_85) = p_53;
                        step_hash(79);
                        (**l_84) |= 0L;
                        step_hash(80);
                        l_166 &= (*g_80);
                    }
                    step_hash(82);
                    (*g_80) = (l_163 & (-(int)p_53));
                }
                else
                {
                    step_hash(90);
                    for (g_113 = 0; (g_113 == 20); g_113++)
                    {
                        int *l_174 = &g_138;
                        step_hash(87);
                        (*l_174) = func_36((func_55(&g_138, p_53) <= ((signed char)p_53 << (signed char)(!p_52))), p_52, ((unsigned short)65535UL >> (unsigned short)p_52));
                        step_hash(88);
                        (**l_85) = &p_52;
                        step_hash(89);
                        return &g_138;
                    }
                    step_hash(96);
                    for (l_143 = 1; (l_143 <= 60); l_143 += 6)
                    {
                        int *l_177 = &g_138;
                        step_hash(94);
                        (*l_177) ^= ((***l_85) >= g_121);
                        step_hash(95);
                        (**l_84) |= p_52;
                    }
                    step_hash(97);
                    p_52 = (g_69 & ((unsigned)0x60892C68L - (unsigned)g_138));
                    step_hash(98);
                    (*l_84) = func_62(&g_138);
                }
                step_hash(100);
                (*l_84) = (*l_84);
                step_hash(105);
                for (l_163 = 13; (l_163 <= 16); l_163 += 5)
                {
                    step_hash(104);
                    (**l_85) = func_62((**l_85));
                }
            }
            else
            {
                short l_184 = 1L;
                step_hash(115);
                if (((signed char)(!l_184) >> (signed char)l_158))
                {
                    step_hash(108);
                    (*g_80) = p_52;
                    step_hash(109);
                    (*g_80) ^= 0L;
                    step_hash(110);
                    (*l_84) = func_62(&g_69);
                }
                else
                {
                    int *l_185 = &g_69;
                    step_hash(112);
                    (*l_84) = &p_52;
                    step_hash(113);
                    (*l_84) = l_185;
                    step_hash(114);
                    return &g_69;
                }
                step_hash(120);
                for (g_42 = 0; (g_42 >= 16); g_42++)
                {
                    step_hash(119);
                    return &g_69;
                }
                step_hash(137);
                for (p_53 = 0; (p_53 <= 19); p_53 += 1)
                {
                    step_hash(124);
                    (***l_85) |= (&p_52 == &g_138);
                    step_hash(130);
                    for (l_158 = 0; (l_158 == 32); ++l_158)
                    {
                        step_hash(128);
                        (*g_80) = (*g_80);
                        step_hash(129);
                        return &g_42;
                    }
                    step_hash(136);
                    for (g_138 = 8; (g_138 >= (-13)); --g_138)
                    {
                        step_hash(134);
                        (**l_85) = &g_69;
                        step_hash(135);
                        (**l_84) = (((signed char)((((unsigned short)0UL << (unsigned short)11) || 0x7DBCL) & (+g_69)) << (signed char)6) || 0x3D9FL);
                    }
                }
            }
            step_hash(139);
            (**l_85) = &p_52;
            step_hash(140);
            g_80 = &p_52;
            step_hash(141);
            return &g_69;
        }
        else
        {
            unsigned l_200 = 0x55D9A899L;
            step_hash(143);
            (***l_85) = (((int)(-1L) + (int)((((*g_80) == p_52) & (p_53 ^ (g_121 & 1UL))) | g_113)) ^ (~(-7L)));
            step_hash(144);
            (***l_201) = (l_200 ^ ((l_201 != (void*)0) != p_52));
        }
        step_hash(146);
        (***l_85) &= p_53;
        step_hash(147);
        (***l_201) = 0x3F1312D1L;
    }
    step_hash(149);
    return &g_138;
}
static unsigned short func_55(int * p_56, signed char p_57)
{
    int l_72 = 0x4179B2C3L;
    int **l_81 = &g_80;
    signed char l_82 = 0L;
    step_hash(27);
    if (((int)g_2 % (int)((int)g_2 % (int)(*p_56))))
    {
        int *l_67 = (void*)0;
        int **l_66 = &l_67;
        int *l_68 = &g_69;
        step_hash(15);
        (*l_66) = func_62(&g_42);
        step_hash(16);
        (*l_68) ^= (*p_56);
        step_hash(17);
        (*l_66) = func_62(func_62((*l_66)));
        step_hash(18);
        (**l_66) &= 0xB3B3333DL;
    }
    else
    {
        int *l_75 = &g_69;
        int **l_76 = (void*)0;
        int **l_77 = &l_75;
        step_hash(20);
        (*l_75) |= ((unsigned char)(p_57 | func_36((l_72 & 0x8D11L), l_72, ((short)l_72 >> (short)3))) + (unsigned char)0x53L);
        step_hash(21);
        (*l_77) = func_62(p_56);
        step_hash(26);
        for (p_57 = 0; (p_57 < (-6)); p_57 -= 7)
        {
            step_hash(25);
            return g_69;
        }
    }
    step_hash(28);
    (*l_81) = g_80;
    step_hash(29);
    return l_82;
}
static int * func_62(int * p_63)
{
    step_hash(12);
    (*p_63) = (*p_63);
    step_hash(13);
    (*p_63) = ((int)(0x6FL == (0x74L != ((void*)0 != p_63))) / (int)0x29B4CCC4L);
    step_hash(14);
    return &g_42;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_42, "g_42", print_hash_value);
    transparent_crc(g_69, "g_69", print_hash_value);
    transparent_crc(g_113, "g_113", print_hash_value);
    transparent_crc(g_121, "g_121", print_hash_value);
    transparent_crc(g_138, "g_138", print_hash_value);
    transparent_crc(g_373, "g_373", print_hash_value);
    transparent_crc(g_382, "g_382", print_hash_value);
    transparent_crc(g_428, "g_428", print_hash_value);
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
