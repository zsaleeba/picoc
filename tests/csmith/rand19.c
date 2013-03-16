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
static unsigned g_2 = 1UL;
static signed char g_3 = 0xDBL;
static int g_6 = (-1L);
static int g_13 = 4L;
static int g_16 = 0x7E813A3DL;
static int g_75 = 0x8177C418L;
static unsigned g_76 = 0x34605DD8L;
static int g_80 = 0L;
static int *g_156 = &g_75;
static int **g_155 = &g_156;
static int g_202 = 9L;
static int g_211 = (-2L);
static unsigned g_369 = 0UL;
static unsigned short g_463 = 1UL;
static int *g_468 = &g_202;
static unsigned short func_1(void);
static int func_17(unsigned p_18, int * p_19, int * p_20);
static short func_25(int p_26, int * p_27, int * p_28, int * p_29);
static int func_30(int * p_31, int * p_32, unsigned p_33, int * p_34);
static int * func_35(unsigned p_36, unsigned p_37, int * p_38, int * p_39, short p_40);
static unsigned func_43(unsigned short p_44, short p_45);
static unsigned short func_46(int * p_47, unsigned p_48, unsigned p_49, int * p_50, int * p_51);
static int * func_52(int * p_53, unsigned p_54, unsigned short p_55);
static int * func_56(int * p_57, int * p_58);
static int * func_59(signed char p_60, short p_61, unsigned p_62);
static unsigned short func_1(void)
{
    int *l_4 = (void*)0;
    int *l_5 = &g_6;
    step_hash(1);
    g_3 = g_2;
    step_hash(2);
    (*l_5) = 4L;
    step_hash(387);
    for (g_3 = (-4); (g_3 > 18); g_3++)
    {
        int *l_21 = (void*)0;
        step_hash(385);
        for (g_6 = 28; (g_6 != (-7)); g_6--)
        {
            step_hash(384);
            for (g_2 = 0; (g_2 <= 33); ++g_2)
            {
                int *l_678 = &g_13;
                step_hash(382);
                for (g_13 = 0; (g_13 != 29); ++g_13)
                {
                    step_hash(380);
                    if ((&g_6 == &g_6))
                    {
                        unsigned char l_677 = 0UL;
                        step_hash(16);
                        g_16 = (-4L);
                        step_hash(376);
                        l_677 = func_17((&g_13 != l_21), &g_13, &g_13);
                    }
                    else
                    {
                        step_hash(378);
                        (*g_155) = l_678;
                        step_hash(379);
                        (*g_155) = (*g_155);
                    }
                    step_hash(381);
                    return g_6;
                }
                step_hash(383);
                (*g_156) = ((signed char)g_369 >> (signed char)2);
            }
        }
        step_hash(386);
        (*g_468) &= (g_75 && (-1L));
    }
    step_hash(388);
    return g_76;
}
static int func_17(unsigned p_18, int * p_19, int * p_20)
{
    unsigned char l_24 = 9UL;
    int *l_370 = &g_13;
    int ***l_560 = (void*)0;
    int *l_579 = (void*)0;
    int l_580 = 1L;
    int l_675 = 0x54F31D19L;
    step_hash(373);
    if ((((short)(l_24 == func_25(func_30(func_35((((short)(-5L) << (short)13) != func_43(func_46(func_52(func_56(p_20, func_59(((void*)0 == p_20), ((unsigned char)1UL >> (unsigned char)2), ((((short)((short)((int)(((signed char)l_24 << (signed char)l_24) >= g_6) / (int)l_24) << (short)p_18) * (short)g_2) < l_24) & 0x05CE4EC6L))), g_202, g_202), p_18, l_24, p_20, &g_6), l_24)), g_3, l_370, p_20, g_6), p_20, p_18, p_19), l_370, p_19, &g_6)) << (short)(*l_370)) ^ 0x9FB1L))
    {
        int *l_433 = (void*)0;
        short l_444 = 0x7E55L;
        signed char l_470 = (-4L);
        int l_502 = (-1L);
        unsigned short l_542 = 0xCCAEL;
        int ***l_588 = (void*)0;
        int *l_649 = (void*)0;
        step_hash(326);
        if ((p_18 || (p_18 | ((&g_156 == (void*)0) > p_18))))
        {
            int l_460 = 0L;
            int *l_469 = &g_202;
            signed char l_471 = 0xD6L;
            step_hash(245);
            for (g_80 = 0; (g_80 == 21); g_80++)
            {
                unsigned char l_445 = 7UL;
                int l_462 = (-1L);
                step_hash(244);
                if (((unsigned char)((signed char)((unsigned short)func_43(func_46(func_35(func_46((*g_155), p_18, (p_18 <= (l_444 < 0x05L)), func_35(g_202, g_2, l_433, l_370, p_18), p_20), p_18, p_19, p_19, l_445), p_18, g_80, &g_6, p_20), g_16) / (unsigned short)l_445) - (signed char)1L) * (unsigned char)p_18))
                {
                    short l_454 = (-1L);
                    int *l_461 = (void*)0;
                    step_hash(237);
                    g_463 = (((signed char)(((signed char)g_13 * (signed char)((+(+((func_30(func_35(g_369, g_13, func_35((((int)(1UL != 0UL) + (int)((unsigned char)l_454 + (unsigned char)((**g_155) && ((int)((~(g_2 | (((signed char)(-(int)func_46((*g_155), g_3, l_454, (*g_155), p_20)) % (signed char)g_211) > p_18))) | 0xC1L) - (int)l_460)))) < 6UL), p_18, p_19, p_19, g_13), &g_202, g_2), l_461, p_18, &g_13) || l_460) <= 0x6FF626B8L))) || 0xBD86L)) < l_462) % (signed char)g_76) || 0xC0L);
                    step_hash(238);
                    return (**g_155);
                }
                else
                {
                    step_hash(240);
                    (*g_156) &= (&l_433 == &g_156);
                    step_hash(241);
                    if (l_460)
                        break;
                    step_hash(242);
                    (*g_156) = (*g_156);
                    step_hash(243);
                    if (l_462)
                        continue;
                }
            }
            step_hash(273);
            if (((unsigned short)((g_211 > (((p_18 ^ g_202) != func_46(func_35((*l_370), ((-2L) || ((p_18 != ((unsigned short)(0xF20776D3L != (+func_46(g_468, (((((+0x7CFBFAACL) > (*l_370)) == 4294967295UL) && p_18) <= g_211), p_18, p_20, p_19))) * (unsigned short)1UL)) ^ g_3)), l_469, p_20, p_18), g_369, p_18, p_20, l_469)) < l_470)) & g_6) + (unsigned short)1L))
            {
                step_hash(247);
                (**g_155) = (*l_469);
                step_hash(248);
                l_471 &= (func_43(p_18, ((**g_155) > (*l_469))) >= (~g_463));
                step_hash(249);
                return (*p_20);
            }
            else
            {
                int *l_472 = &g_6;
                step_hash(251);
                (*g_468) |= (g_369 & ((((+g_75) <= p_18) == p_18) > (g_211 != 65535UL)));
                step_hash(252);
                (*g_155) = p_20;
                step_hash(253);
                (*g_155) = l_472;
                step_hash(272);
                if ((g_6 > g_202))
                {
                    int *l_473 = &g_6;
                    int ***l_494 = &g_155;
                    step_hash(255);
                    (*g_155) = l_473;
                    step_hash(262);
                    if ((((short)(-4L) * (short)((unsigned)((((((unsigned short)g_202 * (unsigned short)(6L | (l_473 == (void*)0))) || (((unsigned short)((short)((int)((*l_370) | (((unsigned short)((&g_156 != &g_468) <= ((p_18 ^ 0xDCL) <= (*l_473))) >> (unsigned short)6) || (*l_473))) - (int)0x4172FA32L) - (short)(*l_473)) / (unsigned short)g_16) | g_2)) || 0x3C011F43L) ^ p_18) <= g_76) + (unsigned)(*g_156))) | g_2))
                    {
                        int *l_495 = &g_202;
                        step_hash(257);
                        (*l_469) = (~((short)g_202 % (short)(((signed char)((signed char)(func_46(l_469, func_46(l_469, p_18, g_75, (*g_155), (*g_155)), (l_494 == (void*)0), p_19, l_469) && g_211) + (signed char)0L) / (signed char)p_18) ^ 0x8D2DL)));
                        step_hash(258);
                        (*l_495) = ((g_3 && 65529UL) == func_25(p_18, l_495, p_20, l_370));
                        step_hash(259);
                        (*g_468) |= ((unsigned char)0x01L >> (unsigned char)(***l_494));
                    }
                    else
                    {
                        step_hash(261);
                        return (*l_472);
                    }
                    step_hash(263);
                    return (*l_469);
                }
                else
                {
                    unsigned short l_509 = 65532UL;
                    int *l_510 = &l_502;
                    step_hash(265);
                    (*g_155) = (*g_155);
                    step_hash(270);
                    for (g_202 = 6; (g_202 == (-25)); g_202 -= 4)
                    {
                        step_hash(269);
                        l_502 = (g_75 ^ g_3);
                    }
                    step_hash(271);
                    (*l_510) ^= ((*l_472) <= (((signed char)((unsigned)func_43(p_18, ((func_46(p_19, (*l_472), ((unsigned short)func_30(p_20, p_19, (g_369 >= (*l_370)), l_472) << (unsigned short)6), &l_502, l_469) && (*l_370)) | l_509)) - (unsigned)l_509) + (signed char)g_369) && 0UL));
                }
            }
        }
        else
        {
            unsigned l_513 = 0x2F1BECB8L;
            int ***l_525 = &g_155;
            step_hash(279);
            for (g_75 = 0; (g_75 < 17); g_75++)
            {
                step_hash(278);
                l_513 = (*p_19);
            }
            step_hash(284);
            for (g_463 = (-22); (g_463 == 36); g_463 += 1)
            {
                unsigned short l_520 = 65535UL;
                step_hash(283);
                (***l_525) = ((unsigned)(p_19 != p_19) % (unsigned)((unsigned)(((p_18 || (l_520 != ((short)(*l_370) / (short)((unsigned short)(l_525 != (void*)0) + (unsigned short)((*g_155) == (void*)0))))) > 0xAFL) ^ p_18) + (unsigned)0x4915FEB5L));
            }
            step_hash(285);
            (**g_155) = (**g_155);
            step_hash(325);
            for (g_76 = 0; (g_76 == 56); g_76 += 9)
            {
                unsigned l_530 = 4294967295UL;
                int **l_538 = &l_370;
                short l_562 = (-6L);
                step_hash(289);
                (**l_525) = (*g_155);
                step_hash(300);
                for (g_16 = 0; (g_16 <= 29); g_16 += 1)
                {
                    int ***l_535 = &g_155;
                    step_hash(293);
                    (*g_156) &= ((*l_370) == g_2);
                    step_hash(294);
                    if ((**g_155))
                        continue;
                    step_hash(299);
                    if ((4294967292UL && (l_530 || ((***l_525) < (p_18 == (***l_525))))))
                    {
                        step_hash(296);
                        (**l_535) = func_35(((short)g_369 * (short)g_463), ((signed char)p_18 - (signed char)(l_535 == &g_155)), (**l_535), (*g_155), g_13);
                    }
                    else
                    {
                        step_hash(298);
                        (***l_535) = (*p_19);
                    }
                }
                step_hash(323);
                for (g_16 = 24; (g_16 >= (-12)); g_16--)
                {
                    int l_549 = 0xEEA455B8L;
                    step_hash(310);
                    if (((void*)0 == l_538))
                    {
                        int l_539 = (-1L);
                        int *l_543 = &l_502;
                        step_hash(305);
                        (*l_543) ^= (func_30(p_20, func_35(g_6, l_539, p_20, (*g_155), ((unsigned char)g_2 << (unsigned char)6)), g_202, func_35(l_542, p_18, p_20, &l_502, g_76)) ^ 0xE2E7167FL);
                    }
                    else
                    {
                        step_hash(307);
                        (*g_155) = (*g_155);
                        step_hash(308);
                        if ((*p_20))
                            continue;
                        step_hash(309);
                        (*g_468) &= (*g_156);
                    }
                }
                step_hash(324);
                l_562 = (((*g_155) == (*g_155)) && g_202);
            }
        }
        step_hash(367);
        for (g_369 = 0; (g_369 <= 21); g_369 += 1)
        {
            unsigned char l_565 = 0UL;
            signed char l_576 = 1L;
            int ***l_587 = &g_155;
            int l_641 = 0L;
            step_hash(330);
            if (l_565)
                break;
            step_hash(331);
            (*g_468) = func_43(l_444, (p_18 && (((signed char)0x26L << (signed char)4) & ((unsigned)p_18 % (unsigned)(((short)((unsigned char)func_30((*g_155), func_59(l_565, ((unsigned short)l_576 / (unsigned short)((short)0x6319L << (short)g_80)), g_202), p_18, l_579) / (unsigned char)l_576) >> (short)10) & l_580)))));
            step_hash(332);
            if ((*g_156))
                break;
            step_hash(366);
            if (((unsigned short)g_80 * (unsigned short)((((unsigned short)65535UL - (unsigned short)(p_18 || (l_587 == &g_155))) < (&g_155 != l_588)) == (-9L))))
            {
                unsigned l_595 = 0x2E711793L;
                step_hash(334);
                (*g_468) = (((((unsigned char)(((int)((void*)0 == &g_155) - (int)((unsigned char)p_18 / (unsigned char)4UL)) > ((-5L) && (l_560 != &g_155))) / (unsigned char)(***l_587)) <= (((p_18 && 0xC5C3L) ^ g_369) >= (***l_587))) <= p_18) ^ l_595);
                step_hash(335);
                (**l_587) = (*g_155);
            }
            else
            {
                unsigned short l_602 = 0xD097L;
                int *l_624 = &l_502;
                int ***l_633 = &g_155;
                step_hash(363);
                if (((short)g_369 + (short)(g_369 == ((signed char)(func_46(func_35((g_3 > (~((!g_3) < p_18))), ((short)(&g_468 == &p_20) / (short)((-1L) ^ g_3)), p_20, (*g_155), p_18), g_80, l_602, (*g_155), (*g_155)) | p_18) / (signed char)g_463))))
                {
                    int *l_617 = &g_13;
                    step_hash(345);
                    if (((unsigned)((int)(((*g_468) ^ (((void*)0 != (*g_155)) > (g_202 > ((signed char)p_18 + (signed char)((unsigned char)g_80 >> (unsigned char)7))))) & ((((void*)0 != p_19) | (((short)(l_602 == p_18) % (short)1UL) <= 0xEFAEA218L)) >= 4294967294UL)) + (int)g_211) / (unsigned)g_2))
                    {
                        step_hash(339);
                        (*g_155) = func_35((((unsigned short)((((((signed char)(func_30((**l_587), func_35(p_18, p_18, l_617, p_20, ((unsigned char)((int)(((~((p_19 == p_20) < 1UL)) < (((unsigned short)(***l_587) * (unsigned short)g_211) || 3UL)) & p_18) % (int)0xC8C507F8L) << (unsigned char)1)), g_13, p_19) >= g_13) << (signed char)g_6) < (*p_20)) & 7L) != p_18) >= g_369) - (unsigned short)1UL) != g_369), g_13, l_624, p_19, (*l_617));
                        step_hash(340);
                        l_641 |= ((unsigned char)((unsigned short)(*l_370) >> (unsigned short)11) - (unsigned char)((signed char)(((void*)0 == l_633) | (65535UL != ((signed char)(((unsigned short)g_80 % (unsigned short)((unsigned char)(***l_587) >> (unsigned char)7)) | ((-(signed char)(*l_370)) == ((*g_155) != p_20))) - (signed char)1L))) + (signed char)p_18));
                        step_hash(341);
                        (***l_633) = (**g_155);
                        step_hash(342);
                        return (*p_19);
                    }
                    else
                    {
                        step_hash(344);
                        if ((*l_617))
                            break;
                    }
                    step_hash(346);
                    (*g_155) = (*g_155);
                    step_hash(351);
                    for (l_580 = 0; (l_580 < 2); l_580 += 1)
                    {
                        step_hash(350);
                        return (*p_20);
                    }
                }
                else
                {
                    int ***l_646 = &g_155;
                    step_hash(353);
                    (*l_624) ^= (**g_155);
                    step_hash(354);
                    (*g_468) |= (*p_20);
                    step_hash(361);
                    for (p_18 = 0; (p_18 != 40); ++p_18)
                    {
                        step_hash(358);
                        (**l_633) = (*g_155);
                        step_hash(359);
                        (*g_468) = (((void*)0 != (*l_646)) > (+p_18));
                        step_hash(360);
                        (**l_646) = l_649;
                    }
                    step_hash(362);
                    (*g_468) = ((int)(*p_19) / (int)0x1F95334AL);
                }
                step_hash(364);
                (**l_633) = p_19;
                step_hash(365);
                (*l_624) = (g_13 || ((((unsigned char)((unsigned short)(!(***l_587)) >> (unsigned short)(((unsigned char)g_6 * (unsigned char)(&p_19 == &g_156)) >= (((int)(***l_587) + (int)(((signed char)((p_18 <= (!(g_13 == (((signed char)p_18 % (signed char)p_18) < 0UL)))) ^ (*g_156)) / (signed char)p_18) && (***l_633))) <= (-1L)))) % (unsigned char)0x39L) > g_463) < g_6));
            }
        }
    }
    else
    {
        unsigned l_674 = 1UL;
        int l_676 = 0x3066CB41L;
        step_hash(369);
        l_675 = (((unsigned char)func_43((((-9L) <= (0x4AL != g_211)) || ((short)(((signed char)0L >> (signed char)func_30(p_19, func_59(p_18, (((unsigned char)((signed char)p_18 + (signed char)(p_18 >= g_6)) << (unsigned char)7) <= p_18), g_6), l_674, (*g_155))) && g_76) << (short)l_674)), p_18) - (unsigned char)g_6) ^ l_674);
        step_hash(370);
        (*g_155) = func_52((*g_155), g_75, p_18);
        step_hash(371);
        (*g_468) = (0L > ((*g_155) == (*g_155)));
        step_hash(372);
        l_676 = ((void*)0 == &g_156);
    }
    step_hash(374);
    (*g_155) = (*g_155);
    step_hash(375);
    return (*g_468);
}
static short func_25(int p_26, int * p_27, int * p_28, int * p_29)
{
    int **l_409 = &g_156;
    int *l_410 = &g_6;
    int *l_431 = (void*)0;
    int *l_432 = &g_211;
    step_hash(227);
    for (g_80 = 0; (g_80 == (-13)); g_80--)
    {
        int *l_411 = &g_202;
        int *l_412 = &g_202;
        step_hash(219);
        (*l_411) = ((func_30(p_29, p_27, func_46(func_35(p_26, (p_26 || ((((int)((short)((signed char)g_202 << (signed char)((short)((short)(-3L) + (short)1UL) >> (short)(l_409 == &g_156))) + (short)g_13) + (int)p_26) != g_3) >= 0UL)), l_410, l_411, g_13), p_26, g_3, l_412, l_411), p_28) & p_26) != p_26);
        step_hash(226);
        for (g_202 = (-19); (g_202 == 27); ++g_202)
        {
            int *l_415 = &g_75;
            step_hash(223);
            g_211 = (*l_410);
            step_hash(224);
            if ((*p_29))
                continue;
            step_hash(225);
            (*l_415) |= (*p_28);
        }
    }
    step_hash(228);
    (*l_409) = &g_75;
    step_hash(229);
    (*l_432) = ((unsigned char)(((((signed char)(-(unsigned short)(((unsigned char)((signed char)func_43(g_2, g_3) << (signed char)7) << (unsigned char)2) <= (0L != p_26))) % (signed char)0x2AL) == ((unsigned short)((int)((unsigned short)g_2 / (unsigned short)0x5BCDL) / (int)p_26) << (unsigned short)1)) == g_16) & 0L) * (unsigned char)(*l_410));
    step_hash(230);
    return g_80;
}
static int func_30(int * p_31, int * p_32, unsigned p_33, int * p_34)
{
    int l_377 = 0x6AA6A8A0L;
    int *l_396 = &g_202;
    step_hash(213);
    (*l_396) = ((signed char)((unsigned short)(l_377 == (((unsigned)(((short)((g_13 <= func_43((+((short)g_76 - (short)((unsigned short)((unsigned short)(p_33 < ((unsigned short)(((short)(((unsigned short)((int)(*p_31) + (int)(+((*p_31) ^ l_377))) % (unsigned short)(p_33 & l_377)) & g_13) << (short)l_377) && l_377) - (unsigned short)65535UL)) >> (unsigned short)0) / (unsigned short)g_2))), p_33)) == l_377) << (short)p_33) <= p_33) / (unsigned)g_16) >= 0L)) - (unsigned short)l_377) / (signed char)0xAFL);
    step_hash(214);
    return g_16;
}
static int * func_35(unsigned p_36, unsigned p_37, int * p_38, int * p_39, short p_40)
{
    step_hash(211);
    return p_38;
}
static unsigned func_43(unsigned short p_44, short p_45)
{
    int *l_360 = &g_75;
    int *l_363 = &g_202;
    int ***l_366 = &g_155;
    step_hash(206);
    (*l_363) &= ((unsigned short)((short)((((unsigned short)g_2 % (unsigned short)(g_76 || ((unsigned short)((-4L) ^ (p_45 && (((((((short)((func_46(l_360, ((unsigned short)((*l_360) && (&l_360 == (void*)0)) << (unsigned short)p_44), g_2, l_360, l_360) <= g_3) < p_45) / (short)(-1L)) | 0x6AFEL) < 0xE676L) && p_44) <= 0xF3L) > p_44))) >> (unsigned short)5))) || (*l_360)) | p_44) % (short)0xE91EL) * (unsigned short)g_76);
    step_hash(207);
    (*l_360) = ((signed char)g_211 * (signed char)(g_80 && ((l_366 == (void*)0) >= (-1L))));
    step_hash(208);
    (*l_360) ^= (0xD6L > ((*l_363) <= 65531UL));
    step_hash(209);
    return g_369;
}
static unsigned short func_46(int * p_47, unsigned p_48, unsigned p_49, int * p_50, int * p_51)
{
    unsigned l_344 = 1UL;
    int *l_345 = &g_75;
    step_hash(196);
    (*l_345) &= l_344;
    step_hash(201);
    for (l_344 = 0; (l_344 != 13); ++l_344)
    {
        step_hash(200);
        return g_16;
    }
    step_hash(202);
    (*g_155) = l_345;
    step_hash(203);
    (*g_156) = ((signed char)p_48 << (signed char)g_80);
    step_hash(204);
    return p_49;
}
static int * func_52(int * p_53, unsigned p_54, unsigned short p_55)
{
    unsigned char l_222 = 0x73L;
    int ***l_226 = &g_155;
    signed char l_233 = 1L;
    unsigned char l_237 = 0x81L;
    int *l_258 = (void*)0;
    int l_291 = 0x252602BCL;
    step_hash(185);
    if ((**g_155))
    {
        int ***l_225 = &g_155;
        int *l_229 = (void*)0;
        int *l_230 = &g_211;
        int *l_238 = (void*)0;
        step_hash(105);
        for (g_202 = 21; (g_202 < (-13)); g_202 -= 2)
        {
            step_hash(104);
            (*g_155) = func_59(l_222, l_222, (p_54 > ((signed char)0x8DL >> (signed char)3)));
        }
        step_hash(106);
        (*l_230) = ((-4L) || ((l_225 != l_226) ^ ((unsigned char)p_54 >> (unsigned char)g_3)));
        step_hash(112);
        for (g_76 = 0; (g_76 != 10); g_76 += 9)
        {
            step_hash(110);
            if ((*p_53))
                break;
            step_hash(111);
            (*l_230) |= 0xCD7A3E1DL;
        }
        step_hash(134);
        if ((*g_156))
        {
            unsigned char l_234 = 255UL;
            step_hash(114);
            (*l_230) = 0L;
            step_hash(115);
            (**l_225) = func_59(l_233, (l_234 >= (*p_53)), l_234);
            step_hash(116);
            (*l_230) |= (**g_155);
            step_hash(128);
            for (g_202 = 0; (g_202 < (-21)); g_202 -= 9)
            {
                unsigned char l_245 = 0xD4L;
                step_hash(120);
                (*l_230) = l_237;
                step_hash(121);
                (*l_230) &= ((void*)0 != (*g_155));
                step_hash(122);
                (*g_155) = (*g_155);
                step_hash(127);
                if (((unsigned char)((unsigned short)((unsigned)(l_245 <= 0x75L) / (unsigned)((int)(0xF07E3ED9L < ((short)p_55 >> (short)6)) - (int)(1UL && ((0L <= ((g_202 < l_245) == (*p_53))) <= (-1L))))) << (unsigned short)15) << (unsigned char)p_54))
                {
                    step_hash(124);
                    return (*g_155);
                }
                else
                {
                    step_hash(126);
                    (*l_230) = 0L;
                }
            }
        }
        else
        {
            step_hash(130);
            (**l_226) = (*g_155);
            step_hash(131);
            (*l_230) &= ((unsigned char)p_54 / (unsigned char)p_55);
            step_hash(132);
            g_80 = ((***l_225) ^ 0L);
            step_hash(133);
            (*l_230) = (**g_155);
        }
    }
    else
    {
        int l_256 = 0xDEFA42DBL;
        int **l_257 = &g_156;
        signed char l_285 = (-1L);
        int *l_330 = &l_256;
        step_hash(136);
        (*g_156) = ((((*g_155) != (*g_155)) && (255UL | g_6)) | ((((signed char)(((***l_226) || (g_13 ^ (0xF8BBF318L < g_13))) <= 0L) + (signed char)g_16) || l_256) >= 0x9B1839ECL));
        step_hash(183);
        if ((l_257 != (void*)0))
        {
            int *l_259 = &g_211;
            step_hash(138);
            (**l_226) = l_258;
            step_hash(139);
            return l_259;
        }
        else
        {
            int l_262 = (-2L);
            int l_293 = (-4L);
            step_hash(141);
            (**l_257) = (*p_53);
            step_hash(170);
            for (g_80 = 0; (g_80 <= (-19)); g_80 -= 1)
            {
                unsigned char l_263 = 1UL;
                int l_312 = 0L;
            }
            step_hash(181);
            if (((*l_257) != &l_293))
            {
                short l_315 = 0xA142L;
                unsigned l_320 = 0xA7CE9A38L;
                step_hash(172);
                (***l_226) = ((int)l_315 % (int)((unsigned short)p_55 + (unsigned short)p_54));
                step_hash(173);
                (**g_155) &= 0x1F6031B5L;
                step_hash(174);
                (**l_257) = (g_202 > (((((int)(*g_156) / (int)l_293) <= 249UL) == (g_80 == l_320)) <= ((unsigned)g_75 - (unsigned)0x3DB380C5L)));
                step_hash(175);
                (*l_257) = (*g_155);
            }
            else
            {
                int l_327 = (-3L);
                step_hash(177);
                (**l_257) = ((l_262 < (p_54 & p_54)) | (-1L));
                step_hash(178);
                (**l_226) = (**l_226);
                step_hash(179);
                (*g_156) |= (((unsigned char)g_80 / (unsigned char)((unsigned short)(7L || l_327) + (unsigned short)p_54)) >= g_76);
                step_hash(180);
                (*l_257) = &l_293;
            }
            step_hash(182);
            g_202 ^= (**g_155);
        }
        step_hash(184);
        (*l_330) = (0x6CE235BBL < (((signed char)0x7BL << (signed char)4) ^ g_202));
    }
    step_hash(193);
    if ((((0L & ((unsigned short)p_54 << (unsigned short)7)) != (((signed char)(&g_155 == l_226) + (signed char)p_54) ^ (0xC489A983L & p_55))) || p_55))
    {
        int **l_339 = &l_258;
        signed char l_340 = 0x35L;
        int *l_341 = (void*)0;
        int *l_342 = &g_80;
        step_hash(187);
        l_340 &= (((unsigned short)g_3 + (unsigned short)g_202) || (l_339 != l_339));
        step_hash(188);
        (*l_342) = 0xAC64C0F7L;
        step_hash(189);
        return p_53;
    }
    else
    {
        int *l_343 = &g_75;
        step_hash(191);
        (*l_343) &= (l_343 == l_343);
        step_hash(192);
        (**l_226) = &g_6;
    }
    step_hash(194);
    return p_53;
}
static int * func_56(int * p_57, int * p_58)
{
    short l_88 = 0x90AEL;
    int *l_91 = &g_75;
    signed char l_195 = (-1L);
    int **l_214 = &l_91;
    step_hash(95);
    if (g_3)
    {
        unsigned char l_84 = 0x82L;
        int *l_85 = &g_80;
        int *l_144 = &g_80;
        short l_157 = 0xEE03L;
        step_hash(30);
        (*l_85) = l_84;
        step_hash(58);
        if (((short)l_88 * (short)((short)(l_91 != (void*)0) >> (short)(&g_6 != (void*)0))))
        {
            int l_106 = 0xBB87E338L;
            step_hash(32);
            (*l_91) = (((signed char)((int)((signed char)((unsigned char)((signed char)((signed char)((unsigned short)(p_57 == (void*)0) * (unsigned short)2UL) % (signed char)l_106) + (signed char)g_13) - (unsigned char)(g_2 != l_106)) >> (signed char)((*l_85) >= ((unsigned short)0xF7FCL + (unsigned short)l_106))) - (int)0x628D16E9L) >> (signed char)g_76) < 0x27A4L);
        }
        else
        {
            unsigned char l_109 = 8UL;
            unsigned l_118 = 1UL;
            int **l_139 = (void*)0;
            step_hash(34);
            (*l_91) = ((p_57 == &g_75) == (((g_76 <= g_13) ^ l_109) || (((unsigned short)g_6 * (unsigned short)(((short)(4L | ((signed char)((((unsigned short)((*p_57) >= g_16) * (unsigned short)g_3) & (*l_91)) && g_80) - (signed char)0xCBL)) >> (short)0) || (*l_91))) && l_118)));
            step_hash(39);
            if ((((signed char)(((short)l_109 << (short)9) ^ ((short)(((l_109 > (l_109 >= (*l_91))) == (*l_85)) == ((int)(&p_57 != &p_57) + (int)((unsigned char)((unsigned short)(l_118 != (((*l_91) & l_109) || 4UL)) << (unsigned short)11) * (unsigned char)0x4CL))) >> (short)(*l_91))) + (signed char)l_109) & (*l_91)))
            {
                step_hash(36);
                (*l_85) = (-1L);
            }
            else
            {
                int **l_131 = &l_91;
                step_hash(38);
                (*l_131) = p_58;
            }
            step_hash(57);
            for (g_76 = 0; (g_76 < 16); g_76 += 5)
            {
                int **l_134 = &l_85;
                step_hash(43);
                (*l_134) = &g_13;
                step_hash(55);
                for (l_88 = 0; (l_88 != 6); l_88++)
                {
                    step_hash(53);
                    for (g_75 = 4; (g_75 >= (-3)); g_75 -= 4)
                    {
                        step_hash(50);
                        if ((*p_58))
                            break;
                        step_hash(51);
                        (*l_134) = p_57;
                        step_hash(52);
                        g_80 &= (*p_57);
                    }
                    step_hash(54);
                    (*l_134) = p_58;
                }
                step_hash(56);
                g_75 ^= ((**l_134) < (l_139 == (void*)0));
            }
        }
        step_hash(59);
        (*l_144) = (((unsigned char)(*l_91) * (unsigned char)(*l_91)) <= ((((~((g_76 && ((unsigned)(((*p_58) ^ ((*l_91) && g_6)) != (*l_91)) % (unsigned)(+(&g_6 != (void*)0)))) | 0x14738E28L)) < (*l_85)) ^ (*l_85)) ^ (*l_85)));
        step_hash(60);
        (*g_156) = ((short)((unsigned short)((unsigned short)(((signed char)(-1L) / (signed char)(*l_91)) ^ ((unsigned char)(g_6 ^ (*l_91)) * (unsigned char)((g_75 <= ((*l_91) & ((*l_91) < (g_155 == &g_156)))) ^ (*l_85)))) + (unsigned short)l_157) + (unsigned short)0x6D70L) / (short)65530UL);
    }
    else
    {
        unsigned l_169 = 0x679535C3L;
        int *l_188 = &g_75;
        step_hash(85);
        for (g_80 = 3; (g_80 >= (-15)); g_80 -= 1)
        {
            short l_164 = 0x69B9L;
            short l_174 = 0xCF24L;
            int *l_203 = &g_6;
            int *l_210 = &g_211;
            step_hash(65);
            (**g_155) = ((short)((unsigned)(l_164 || (((*l_91) > ((*l_91) > ((*g_156) == (((short)((signed char)l_169 / (signed char)0xF4L) - (short)((short)((unsigned char)l_164 >> (unsigned char)4) % (short)l_174)) <= ((short)(((g_3 && 0xF0L) == l_174) < (*l_91)) << (short)7))))) || l_174)) / (unsigned)l_174) - (short)l_169);
            step_hash(82);
            if ((*g_156))
            {
                int *l_179 = &g_13;
                int l_186 = 0xBB3B7CC6L;
                step_hash(77);
                for (l_88 = 0; (l_88 != 15); l_88 += 6)
                {
                    signed char l_187 = 0x40L;
                    int *l_197 = &g_80;
                    signed char l_198 = (-3L);
                    int *l_201 = &g_202;
                    step_hash(70);
                    p_58 = l_179;
                }
                step_hash(78);
                if ((*p_58))
                    continue;
                step_hash(79);
                if ((**g_155))
                    break;
            }
            else
            {
                step_hash(81);
                return l_203;
            }
            step_hash(83);
            if ((**g_155))
                continue;
            step_hash(84);
            (*l_210) ^= ((7L <= 9UL) > (g_2 == ((unsigned short)65535UL - (unsigned short)((unsigned short)(((((unsigned)(p_57 == (void*)0) - (unsigned)((*l_91) | g_2)) == (((*l_91) ^ g_202) > (*l_203))) != 0x8CAFD7A6L) | (*l_203)) << (unsigned short)g_3))));
        }
        step_hash(92);
        for (g_80 = (-8); (g_80 > 18); ++g_80)
        {
            int ***l_215 = &l_214;
            step_hash(89);
            (*l_215) = l_214;
            step_hash(90);
            (*l_215) = &l_91;
            step_hash(91);
            (*l_91) |= (*p_57);
        }
        step_hash(93);
        (*l_214) = func_59((((short)(&p_58 == &p_58) >> (short)0) == (**g_155)), (**l_214), (*l_188));
        step_hash(94);
        return (*g_155);
    }
    step_hash(96);
    (*l_214) = func_59(g_16, (*l_91), ((**l_214) ^ ((unsigned char)0xF3L >> (unsigned char)3)));
    step_hash(97);
    p_57 = (void*)0;
    step_hash(98);
    return (*g_155);
}
static int * func_59(signed char p_60, short p_61, unsigned p_62)
{
    int l_73 = 1L;
    int *l_74 = &g_75;
    int *l_77 = (void*)0;
    int *l_78 = (void*)0;
    int *l_79 = &g_80;
    step_hash(19);
    (*l_74) = l_73;
    step_hash(20);
    g_76 |= (*l_74);
    step_hash(21);
    (*l_79) &= (*l_74);
    step_hash(26);
    for (g_16 = 2; (g_16 > 28); g_16 += 7)
    {
        int **l_83 = &l_77;
        step_hash(25);
        (*l_83) = l_78;
    }
    step_hash(27);
    return &g_13;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_6, "g_6", print_hash_value);
    transparent_crc(g_13, "g_13", print_hash_value);
    transparent_crc(g_16, "g_16", print_hash_value);
    transparent_crc(g_75, "g_75", print_hash_value);
    transparent_crc(g_76, "g_76", print_hash_value);
    transparent_crc(g_80, "g_80", print_hash_value);
    transparent_crc(g_202, "g_202", print_hash_value);
    transparent_crc(g_211, "g_211", print_hash_value);
    transparent_crc(g_369, "g_369", print_hash_value);
    transparent_crc(g_463, "g_463", print_hash_value);
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
