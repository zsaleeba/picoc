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
static int g_3 = 1L;
static int g_53 = 0xD3709E8EL;
static int g_83 = 5L;
static unsigned g_124 = 0xCD3E82D7L;
static int *g_133 = &g_83;
static int **g_194 = &g_133;
static int ***g_193 = &g_194;
static int *g_238 = (void*)0;
static int g_634 = 0xCF32BF1DL;
static int *g_652 = &g_3;
static int g_661 = (-1L);
static int *g_694 = (void*)0;
static unsigned short g_741 = 0x7AD6L;
static unsigned func_1(void);
static signed char func_8(int * p_9, unsigned p_10, int p_11, unsigned p_12);
static unsigned short func_15(short p_16, int * p_17);
static unsigned char func_18(signed char p_19);
static int * func_24(int p_25);
static short func_34(int * p_35, int p_36);
static short func_41(unsigned short p_42);
static short func_54(int * p_55);
static unsigned func_61(signed char p_62, int * p_63, int p_64, int * p_65, unsigned short p_66);
static int func_67(unsigned p_68, int p_69, int * p_70, int * p_71, unsigned char p_72);
static unsigned func_1(void)
{
    int *l_2 = &g_3;
    unsigned short l_742 = 65535UL;
    int *l_752 = &g_661;
    step_hash(1);
    (*l_2) = (-7L);
    step_hash(506);
    if ((((g_3 != g_3) && ((int)((unsigned short)(0xCDL && func_8(l_2, g_3, g_3, g_3)) << (unsigned short)7) - (int)((g_741 < g_741) & g_741))) == 0x5B947408L))
    {
        step_hash(502);
        l_742 &= (*l_2);
    }
    else
    {
        unsigned short l_751 = 0xBC5CL;
        unsigned l_753 = 0xB242BADEL;
        step_hash(504);
        (*l_752) = func_61(((short)0L * (short)g_83), l_2, (((signed char)g_741 * (signed char)(*l_2)) != (0x4268L ^ ((short)(g_3 > ((((unsigned char)252UL + (unsigned char)l_751) <= (*l_2)) < l_751)) % (short)(*l_2)))), l_752, l_753);
        step_hash(505);
        (*g_194) = l_752;
    }
    step_hash(507);
    (*l_752) &= (*l_2);
    step_hash(508);
    return (*l_2);
}
static signed char func_8(int * p_9, unsigned p_10, int p_11, unsigned p_12)
{
    int *l_633 = &g_634;
    unsigned l_646 = 0x29B64416L;
    int *l_664 = (void*)0;
    int *l_676 = &g_83;
    int l_692 = (-3L);
    unsigned short l_739 = 0x3A21L;
    step_hash(497);
    if (((unsigned short)func_15(g_3, p_9) * (unsigned short)(((void*)0 == l_633) != ((short)(((((unsigned short)((unsigned short)((func_54(&g_634) ^ (((signed char)1L % (signed char)g_634) || 0xA81BL)) < (*l_633)) - (unsigned short)g_634) >> (unsigned short)(*l_633)) < (*l_633)) != g_634) ^ 4L) % (short)g_634))))
    {
        int l_643 = 0x58FB8444L;
        int l_686 = 5L;
        unsigned char l_695 = 0UL;
        int l_732 = (-1L);
        step_hash(417);
        (*g_194) = (void*)0;
        step_hash(436);
        if (l_643)
        {
            int l_647 = 1L;
            int *l_662 = &g_661;
            step_hash(419);
            (**g_193) = l_633;
            step_hash(431);
            for (p_10 = 0; (p_10 > 15); p_10 += 1)
            {
                int *l_660 = &g_661;
                step_hash(428);
                for (l_647 = 0; (l_647 >= (-28)); l_647 -= 5)
                {
                    unsigned l_655 = 0xEE5FB410L;
                    step_hash(426);
                    (**g_193) = g_652;
                    step_hash(427);
                    (*g_133) = (((((signed char)g_634 / (signed char)g_53) > l_655) >= (p_9 != p_9)) | l_655);
                }
            }
            step_hash(432);
            p_9 = (**g_193);
            step_hash(433);
            (*l_662) &= (**g_194);
        }
        else
        {
            step_hash(435);
            (*g_652) = 0xA606B940L;
        }
        step_hash(475);
        if ((*p_9))
        {
            short l_663 = 0x85ECL;
            step_hash(438);
            (*l_633) |= ((void*)0 == &p_9);
            step_hash(439);
            (*g_194) = l_664;
            step_hash(440);
            return l_643;
        }
        else
        {
            unsigned char l_671 = 255UL;
            unsigned l_691 = 0UL;
            int l_705 = (-3L);
            step_hash(459);
            for (p_12 = 0; (p_12 < 23); ++p_12)
            {
                unsigned char l_683 = 0x35L;
                int l_684 = 0x565244B3L;
                step_hash(458);
                if (((signed char)(+((((short)l_671 / (short)0x425CL) > (((void*)0 == p_9) >= 0UL)) ^ ((int)(l_664 == (**g_193)) / (int)(((signed char)p_12 << (signed char)5) & g_53)))) >> (signed char)6))
                {
                    int l_685 = 0xC37D6EB4L;
                    step_hash(446);
                    (*g_194) = l_676;
                    step_hash(451);
                    for (g_3 = 0; (g_3 != (-10)); g_3 -= 8)
                    {
                        step_hash(450);
                        (*g_194) = p_9;
                    }
                    step_hash(452);
                    l_686 = ((signed char)((((signed char)(((l_683 != l_684) >= p_11) >= g_634) >> (signed char)(func_41(l_685) && (p_12 == l_685))) || g_124) <= l_643) * (signed char)g_661);
                    step_hash(453);
                    (**g_193) = func_24(p_12);
                }
                else
                {
                    int *l_693 = &g_634;
                    step_hash(455);
                    (*l_693) = ((signed char)((g_634 || (g_83 != ((*g_194) == (**g_193)))) < func_61(l_691, p_9, (!l_692), l_693, l_671)) / (signed char)g_83);
                    step_hash(456);
                    (*p_9) = func_61((*l_693), (**g_193), (((*l_633) | (g_3 >= func_54(g_694))) != l_695), p_9, p_10);
                    step_hash(457);
                    if ((*l_676))
                        break;
                }
            }
            step_hash(466);
            for (l_671 = (-11); (l_671 == 20); l_671++)
            {
                int *l_698 = (void*)0;
                step_hash(463);
                (*g_194) = l_698;
                step_hash(464);
                (*g_652) |= (&l_698 == (*g_193));
                step_hash(465);
                if ((*l_676))
                    break;
            }
            step_hash(467);
            (*g_652) |= 0xD0C9EE20L;
            step_hash(474);
            if (((unsigned char)(0xFA462446L >= (((unsigned char)((4294967289UL < (*l_633)) || ((short)0x351CL / (short)l_691)) / (unsigned char)(4294967288UL && ((void*)0 != p_9))) || p_12)) % (unsigned char)g_661))
            {
                step_hash(469);
                (*g_194) = &l_692;
                step_hash(470);
                l_705 &= func_18(g_53);
            }
            else
            {
                unsigned l_708 = 0x1C9458B4L;
                step_hash(472);
                (*l_676) ^= (((unsigned short)g_124 % (unsigned short)g_3) < (*l_633));
                step_hash(473);
                (*p_9) = l_708;
            }
        }
        step_hash(490);
        if (func_41(g_124))
        {
            signed char l_711 = 0x30L;
            int *l_712 = &g_3;
            step_hash(477);
            (*l_676) ^= (((((unsigned short)g_634 - (unsigned short)(l_711 && g_661)) > 1UL) <= l_643) && 0x77D33AFDL);
            step_hash(478);
            (*p_9) = (((unsigned)l_695 - (unsigned)(*l_712)) ^ ((*l_676) > ((((((unsigned char)((unsigned)g_83 - (unsigned)((&l_664 != (void*)0) >= g_634)) % (unsigned char)(*l_676)) | (*l_712)) != (*p_9)) >= 255UL) != g_124)));
        }
        else
        {
            step_hash(486);
            if ((*p_9))
            {
                step_hash(481);
                (**g_193) = (void*)0;
                step_hash(482);
                (*g_652) ^= l_695;
            }
            else
            {
                unsigned short l_723 = 65535UL;
                step_hash(484);
                (*l_676) = (*p_9);
                step_hash(485);
                (*l_633) = l_723;
            }
            step_hash(487);
            (*g_652) = ((g_53 ^ (&g_194 == (void*)0)) != 0x7EACL);
            step_hash(488);
            (*g_652) = ((unsigned char)l_732 << (unsigned char)5);
            step_hash(489);
            (*g_652) = (+(*p_9));
        }
    }
    else
    {
        int *l_737 = &g_3;
        unsigned l_738 = 7UL;
        step_hash(496);
        if (((+(((p_10 >= (((p_11 | (0xD6L && ((short)0xA820L * (short)((short)func_61(p_11, p_9, (*p_9), l_737, l_738) % (short)(*l_737))))) == 0xD2A164DEL) && p_10)) & g_53) || (*l_737))) & l_739))
        {
            step_hash(493);
            (*g_194) = l_737;
        }
        else
        {
            unsigned l_740 = 0UL;
            step_hash(495);
            return l_740;
        }
    }
    step_hash(498);
    (**g_193) = (*g_194);
    step_hash(499);
    (*p_9) = (*p_9);
    step_hash(500);
    return p_12;
}
static unsigned short func_15(short p_16, int * p_17)
{
    int l_20 = 0L;
    unsigned l_305 = 7UL;
    int l_347 = (-6L);
    int *l_433 = &g_3;
    unsigned l_452 = 0xD706E587L;
    int ***l_470 = &g_194;
    int l_485 = (-1L);
    unsigned short l_555 = 0xE4DAL;
    signed char l_614 = 0x0EL;
    step_hash(343);
    if ((func_18(l_20) || ((unsigned)l_20 % (unsigned)(2L ^ ((((~(((&p_17 == (void*)0) | (*p_17)) > p_16)) | ((((g_3 ^ p_16) & g_3) || g_83) && g_83)) ^ l_305) == l_305)))))
    {
        int **l_308 = &g_238;
        signed char l_336 = 0x37L;
        int *l_358 = &l_347;
        step_hash(226);
        for (l_20 = 17; (l_20 != (-8)); l_20--)
        {
            int *l_309 = (void*)0;
            step_hash(191);
            l_308 = (void*)0;
            step_hash(192);
            (**g_193) = l_309;
            step_hash(224);
            if (func_41(g_53))
            {
                unsigned short l_310 = 0x6A10L;
                int *l_334 = &g_53;
                step_hash(194);
                if (l_310)
                    break;
                step_hash(199);
                for (g_53 = (-14); (g_53 == 2); g_53 += 1)
                {
                    step_hash(198);
                    if ((*p_17))
                        break;
                }
                step_hash(218);
                if (((~g_83) <= (((int)((g_53 <= 0UL) >= ((short)((*g_193) == (void*)0) - (short)((!((int)(l_305 >= ((signed char)p_16 * (signed char)0x3EL)) % (int)p_16)) <= g_124))) / (int)0x8F1FB9C7L) > p_16)))
                {
                    unsigned l_330 = 4UL;
                    step_hash(201);
                    (*p_17) = ((signed char)g_3 * (signed char)p_16);
                    step_hash(208);
                    if ((*p_17))
                    {
                        step_hash(203);
                        (**g_193) = p_17;
                    }
                    else
                    {
                        int *l_327 = &g_83;
                        step_hash(205);
                        (*l_327) ^= ((0x60527778L <= ((*g_193) == (void*)0)) < ((signed char)g_3 >> (signed char)7));
                        step_hash(206);
                        (*l_327) |= (*p_17);
                        step_hash(207);
                        (*p_17) ^= ((unsigned char)248UL - (unsigned char)0L);
                    }
                    step_hash(209);
                    (*p_17) ^= l_330;
                }
                else
                {
                    short l_331 = 0x48D7L;
                    int l_332 = (-1L);
                    step_hash(211);
                    l_332 = (l_331 | func_41(l_310));
                    step_hash(217);
                    if ((0x50ECL && l_20))
                    {
                        int *l_333 = &g_53;
                        step_hash(213);
                        (**g_193) = p_17;
                        step_hash(214);
                        (*p_17) = func_54(l_333);
                    }
                    else
                    {
                        step_hash(216);
                        (*g_194) = l_334;
                    }
                }
            }
            else
            {
                step_hash(220);
                (*p_17) |= func_54((**g_193));
                step_hash(221);
                (*p_17) = l_305;
                step_hash(222);
                (*p_17) ^= (-(unsigned short)l_336);
                step_hash(223);
                (**g_193) = (*g_194);
            }
            step_hash(225);
            (*p_17) |= 0L;
        }
        step_hash(251);
        if (((((short)(((-4L) | ((unsigned short)((short)((unsigned short)((unsigned char)g_83 * (unsigned char)l_347) % (unsigned short)(+func_54(&l_20))) << (short)10) * (unsigned short)(l_305 != l_20))) > (((int)func_61(((1L != p_16) < 0L), p_17, (*p_17), (*g_194), g_3) % (int)g_83) == 1UL)) + (short)l_305) ^ g_53) && l_347))
        {
            unsigned char l_386 = 0xDCL;
            step_hash(228);
            (*p_17) ^= ((unsigned char)((signed char)((void*)0 != (**g_193)) << (signed char)7) << (unsigned char)4);
            step_hash(241);
            if (((unsigned char)((short)((**g_193) != l_358) >> (short)7) - (unsigned char)(!func_41(((short)(p_16 | ((*l_358) != (((unsigned short)((unsigned char)(((signed char)((unsigned short)(-(unsigned short)g_124) + (unsigned short)(g_83 & (*p_17))) * (signed char)((unsigned char)((short)((int)func_54((*g_194)) - (int)0L) << (short)14) + (unsigned char)g_124)) ^ 0L) / (unsigned char)0x5EL) * (unsigned short)g_3) <= p_16))) % (short)(-8L))))))
            {
                step_hash(230);
                (*p_17) &= ((((signed char)(&p_17 == (*g_193)) * (signed char)p_16) || ((signed char)((((((short)(0x18A5L != (*l_358)) * (short)g_53) > l_386) && (l_386 ^ ((int)((unsigned char)((unsigned char)p_16 / (unsigned char)g_53) * (unsigned char)0x84L) + (int)p_16))) < 0x6AL) != g_124) * (signed char)(*l_358))) ^ 0xDA77L);
            }
            else
            {
                int *l_395 = &g_83;
                step_hash(232);
                (*l_358) = (*p_17);
                step_hash(238);
                for (l_386 = (-21); (l_386 != 42); ++l_386)
                {
                    step_hash(236);
                    (*g_194) = l_395;
                    step_hash(237);
                    if ((*l_395))
                        break;
                }
                step_hash(239);
                (*p_17) = (((unsigned char)0x4EL * (unsigned char)((unsigned short)g_83 + (unsigned short)(func_61(func_54((**g_193)), (*g_194), (*p_17), p_17, func_61(p_16, l_395, (*p_17), p_17, g_124)) >= 1UL))) >= 0xC9A4L);
                step_hash(240);
                (*g_194) = (*g_194);
            }
            step_hash(242);
            (*l_358) &= ((*g_194) != (void*)0);
            step_hash(248);
            for (l_336 = (-4); (l_336 != 8); l_336 += 5)
            {
                step_hash(246);
                (**g_193) = (**g_193);
                step_hash(247);
                (*l_358) &= ((unsigned short)p_16 * (unsigned short)(((*p_17) < (4UL | ((short)((unsigned char)((unsigned char)(p_16 ^ ((signed char)p_16 << (signed char)0)) << (unsigned char)0) * (unsigned char)((((unsigned short)((short)0xB507L - (short)((signed char)((void*)0 != &l_308) / (signed char)g_83)) << (unsigned short)g_83) && g_53) & (*p_17))) << (short)6))) | (*p_17)));
            }
        }
        else
        {
            step_hash(250);
            (*l_358) &= (*p_17);
        }
        step_hash(252);
        (*p_17) = (*p_17);
    }
    else
    {
        int *l_422 = &l_347;
        int l_427 = 0x6EE753C9L;
        int ***l_471 = (void*)0;
        int l_521 = 0L;
        step_hash(335);
        if (((((unsigned char)func_41(p_16) + (unsigned char)p_16) & ((signed char)((func_54(l_422) & (((short)g_3 % (short)((signed char)func_54((**g_193)) + (signed char)((*p_17) <= 0x6D7F5B29L))) > 1UL)) && l_427) / (signed char)0x19L)) & l_347))
        {
            unsigned l_428 = 0x3D3AF03EL;
            step_hash(255);
            (*l_422) ^= (((~(p_16 < l_428)) > g_83) > g_124);
            step_hash(279);
            if (((unsigned char)(p_16 <= l_428) * (unsigned char)func_54(l_433)))
            {
                step_hash(257);
                (*g_193) = (*g_193);
                step_hash(258);
                (*l_422) = (*l_433);
                step_hash(264);
                for (l_305 = 0; (l_305 >= 7); l_305 += 4)
                {
                    unsigned char l_436 = 0x08L;
                    step_hash(262);
                    (*p_17) |= (-1L);
                    step_hash(263);
                    if (l_436)
                        continue;
                }
                step_hash(265);
                (*l_433) |= (((void*)0 == (**g_193)) <= 0UL);
            }
            else
            {
                step_hash(275);
                for (l_305 = (-7); (l_305 == 13); ++l_305)
                {
                    step_hash(274);
                    for (l_428 = 9; (l_428 != 32); l_428++)
                    {
                        step_hash(273);
                        return p_16;
                    }
                }
                step_hash(276);
                (*l_422) &= (1L & ((unsigned short)((*p_17) < ((short)0xF551L + (short)l_428)) << (unsigned short)15));
                step_hash(277);
                (*l_433) ^= (0x4C91L != l_428);
                step_hash(278);
                (*l_422) = (*p_17);
            }
            step_hash(280);
            (*g_194) = (**g_193);
        }
        else
        {
            unsigned short l_447 = 3UL;
            int ***l_462 = &g_194;
            int l_476 = 0x77425FA9L;
            step_hash(331);
            if ((l_447 & (*l_422)))
            {
                unsigned char l_469 = 0x51L;
                int ***l_474 = &g_194;
                int l_475 = 0xC5D40D41L;
                step_hash(297);
                for (g_53 = (-26); (g_53 != 6); g_53 += 8)
                {
                    unsigned char l_455 = 0x38L;
                    int *l_463 = (void*)0;
                    int l_464 = 0x7E35E3FCL;
                    step_hash(291);
                    for (l_20 = 0; (l_20 <= (-15)); --l_20)
                    {
                        step_hash(289);
                        (**g_193) = (**g_193);
                        step_hash(290);
                        l_452 ^= (*p_17);
                    }
                    step_hash(296);
                    if (((short)(l_455 | ((unsigned short)((unsigned)4294967295UL / (unsigned)(*l_433)) - (unsigned short)(*l_433))) / (short)(*l_433)))
                    {
                        step_hash(293);
                        return g_3;
                    }
                    else
                    {
                        step_hash(295);
                        return l_464;
                    }
                }
                step_hash(298);
                l_476 |= (((((unsigned short)0xD9B8L >> (unsigned short)((unsigned)l_469 / (unsigned)l_469)) > (((l_470 != l_471) && g_3) | ((short)p_16 >> (short)p_16))) & func_61((((&g_194 != l_474) & (-1L)) | l_469), (*g_194), (*l_433), p_17, l_475)) ^ p_16);
                step_hash(312);
                if (((signed char)func_41(((l_476 | 0xD7L) <= ((void*)0 == l_470))) << (signed char)2))
                {
                    int l_496 = (-1L);
                    step_hash(300);
                    (*p_17) = ((short)g_124 << (short)((short)p_16 * (short)(((short)l_485 >> (short)10) > (g_53 == 0x039EL))));
                    step_hash(301);
                    (*l_433) = (*p_17);
                    step_hash(302);
                    (*p_17) = ((*l_422) >= ((g_124 && ((l_471 != l_474) == 65528UL)) <= p_16));
                    step_hash(303);
                    (*l_433) = (*p_17);
                }
                else
                {
                    unsigned char l_505 = 254UL;
                    step_hash(311);
                    if ((*p_17))
                    {
                        step_hash(306);
                        p_17 = p_17;
                        step_hash(307);
                        (**g_193) = p_17;
                    }
                    else
                    {
                        unsigned short l_512 = 0UL;
                        step_hash(309);
                        g_83 ^= ((unsigned)((((p_16 & (((unsigned short)g_3 - (unsigned short)g_53) ^ ((unsigned short)p_16 - (unsigned short)func_54((**l_470))))) <= ((short)l_505 % (short)((short)(((short)0L << (short)((signed char)(p_16 || g_124) % (signed char)p_16)) <= g_124) * (short)p_16))) > g_3) <= l_512) % (unsigned)l_505);
                        step_hash(310);
                        (*l_433) = (((((signed char)((short)0xF6F1L << (short)15) << (signed char)p_16) || 0x03L) <= ((short)((unsigned char)(l_521 & p_16) / (unsigned char)(-6L)) << (short)p_16)) >= (*l_433));
                    }
                }
            }
            else
            {
                unsigned l_528 = 0x281D47B4L;
                int *l_529 = &g_83;
                step_hash(327);
                for (l_485 = 2; (l_485 <= 17); l_485++)
                {
                    int *l_524 = &g_3;
                    int ***l_527 = &g_194;
                    step_hash(317);
                    p_17 = (void*)0;
                    step_hash(318);
                    if (p_16)
                        break;
                    step_hash(326);
                    if (p_16)
                    {
                        step_hash(320);
                        (**l_462) = (*g_194);
                        step_hash(321);
                        (*l_433) = (l_527 != l_470);
                    }
                    else
                    {
                        step_hash(323);
                        (*l_422) |= p_16;
                        step_hash(324);
                        (*l_433) &= l_528;
                        step_hash(325);
                        (*l_433) = (p_16 <= 1UL);
                    }
                }
                step_hash(328);
                (**l_470) = l_529;
                step_hash(329);
                (**g_193) = (void*)0;
                step_hash(330);
                (*g_194) = p_17;
            }
            step_hash(332);
            (*g_194) = (**l_470);
            step_hash(333);
            (**l_470) = (*g_194);
            step_hash(334);
            (**l_462) = p_17;
        }
        step_hash(336);
        (*l_422) = (-(unsigned char)((short)((unsigned char)(&p_17 != (void*)0) / (unsigned char)(((unsigned short)0UL >> (unsigned short)(l_471 != (void*)0)) | p_16)) << (short)1));
        step_hash(337);
        (*l_433) = (*l_433);
        step_hash(342);
        for (l_452 = 15; (l_452 != 6); l_452 -= 1)
        {
            step_hash(341);
            (*l_433) = (*l_422);
        }
    }
    step_hash(344);
    (**l_470) = p_17;
    step_hash(413);
    for (g_83 = 0; (g_83 > (-26)); g_83 -= 8)
    {
        int *l_541 = &g_83;
        step_hash(348);
        (*g_194) = l_541;
        step_hash(412);
        for (l_347 = 0; (l_347 > (-7)); --l_347)
        {
            int l_556 = 0L;
            int *l_585 = (void*)0;
            unsigned short l_586 = 0x217CL;
            int ***l_593 = (void*)0;
            unsigned short l_627 = 0xEC1CL;
            int *l_632 = &l_347;
            step_hash(390);
            if (func_54((**l_470)))
            {
                unsigned l_569 = 0UL;
                step_hash(364);
                for (l_20 = 12; (l_20 >= 3); l_20 -= 8)
                {
                    int **l_552 = (void*)0;
                    step_hash(356);
                    (*l_433) = ((unsigned char)p_16 + (unsigned char)g_53);
                    step_hash(361);
                    for (g_3 = (-1); (g_3 != (-24)); --g_3)
                    {
                        step_hash(360);
                        g_53 = (p_16 ^ p_16);
                    }
                    step_hash(362);
                    (*l_433) = (**g_194);
                    step_hash(363);
                    (*l_433) &= ((((int)(l_552 != l_552) % (int)p_16) == ((unsigned short)2UL << (unsigned short)6)) <= l_555);
                }
                step_hash(365);
                (**g_193) = (**l_470);
                step_hash(371);
                if ((((252UL < 0L) ^ l_556) == ((-(unsigned)((unsigned short)((short)(***l_470) >> (short)4) * (unsigned short)((((func_54(&l_556) || ((unsigned char)(p_16 != ((unsigned short)((unsigned)0x33D65060L / (unsigned)(***g_193)) << (unsigned short)1)) >> (unsigned char)4)) != 2L) & (***g_193)) && (*l_541)))) >= 0xE431F0F9L)))
                {
                    unsigned short l_568 = 0xA9D6L;
                    step_hash(367);
                    (*l_433) = (***g_193);
                    step_hash(368);
                    (*l_433) &= l_568;
                }
                else
                {
                    step_hash(370);
                    l_569 ^= (-6L);
                }
                step_hash(372);
                (*l_433) = ((((0x8DA1DDBEL ^ ((int)func_61(((((short)func_61((~0x87L), (*g_194), (((unsigned short)((unsigned char)((int)((short)((g_3 <= 4UL) & (-(unsigned short)0x452EL)) * (short)p_16) - (int)(((signed char)(*l_541) % (signed char)(((*l_433) | 65535UL) ^ 4294967295UL)) & l_569)) % (unsigned char)g_83) % (unsigned short)0x1AA9L) < 0UL), l_541, p_16) % (short)4UL) > 0xC3D6L) >= g_53), l_585, p_16, l_541, g_124) + (int)(-1L))) == 9UL) | l_586) ^ 0xC72EL);
            }
            else
            {
                int *l_592 = &l_347;
                step_hash(389);
                for (l_556 = (-20); (l_556 != 5); ++l_556)
                {
                    short l_591 = 0x4FA7L;
                    int *l_610 = &l_556;
                    step_hash(381);
                    for (l_305 = (-28); (l_305 < 54); ++l_305)
                    {
                        step_hash(380);
                        l_591 ^= ((void*)0 == &p_17);
                    }
                    step_hash(382);
                    (**g_193) = l_592;
                    step_hash(388);
                    if ((((p_16 & ((((void*)0 != l_593) > (!(((unsigned char)(((unsigned char)((unsigned short)65535UL + (unsigned short)((unsigned short)(((void*)0 != (*g_194)) == (0x8737L >= (((signed char)((unsigned short)(p_16 && func_61(((signed char)(p_16 > 0xFCL) << (signed char)4), l_610, p_16, p_17, (*l_433))) % (unsigned short)p_16) * (signed char)g_124) != g_3))) + (unsigned short)p_16)) * (unsigned char)(*l_592)) > (*l_433)) << (unsigned char)(*l_610)) <= g_83))) >= (*l_541))) >= 250UL) || g_124))
                    {
                        int *l_611 = &l_20;
                        step_hash(384);
                        (*l_611) &= func_61((((***l_470) >= p_16) | func_54((**l_470))), (**l_470), (!(*l_541)), l_610, (*l_541));
                        step_hash(385);
                        (*l_433) = ((signed char)g_83 * (signed char)g_124);
                    }
                    else
                    {
                        step_hash(387);
                        return l_614;
                    }
                }
            }
            step_hash(409);
            if (func_61((***l_470), p_17, p_16, (**g_193), (-(unsigned)7UL)))
            {
                int *l_616 = &l_20;
                int ***l_617 = &g_194;
                unsigned char l_629 = 0x50L;
                step_hash(392);
                l_541 = l_616;
                step_hash(393);
                if ((*l_616))
                    break;
                step_hash(401);
                if ((0L >= ((void*)0 == l_617)))
                {
                    int ***l_622 = &g_194;
                    step_hash(395);
                    (*l_541) = ((((short)(((unsigned char)(l_622 == l_622) >> (unsigned char)((signed char)((*g_193) != &p_17) << (signed char)7)) & ((unsigned short)(l_627 != func_54(p_17)) + (unsigned short)(func_54((*g_194)) >= (***l_622)))) - (short)0xC4F2L) & p_16) < g_83);
                }
                else
                {
                    int *l_628 = &g_53;
                    step_hash(397);
                    (*g_194) = l_628;
                    step_hash(398);
                    if (l_629)
                        break;
                    step_hash(399);
                    (*l_433) = 0x21F01897L;
                    step_hash(400);
                    (**l_470) = (**g_193);
                }
            }
            else
            {
                step_hash(407);
                for (p_16 = 18; (p_16 == 18); ++p_16)
                {
                    step_hash(406);
                    g_53 = (((void*)0 != &p_17) >= (!0x57L));
                }
                step_hash(408);
                (**g_193) = l_632;
            }
            step_hash(410);
            (*l_433) = (*l_541);
            step_hash(411);
            return p_16;
        }
    }
    step_hash(414);
    (*g_194) = (**g_193);
    step_hash(415);
    return p_16;
}
static unsigned char func_18(signed char p_19)
{
    unsigned char l_23 = 0x58L;
    int l_26 = 1L;
    int **l_301 = &g_238;
    int *l_302 = &g_83;
    step_hash(9);
    for (g_3 = 12; (g_3 != 0); g_3--)
    {
        step_hash(8);
        if (l_23)
            break;
    }
    step_hash(183);
    (**g_193) = func_24(l_26);
    step_hash(184);
    (*l_302) = ((signed char)(l_301 != (void*)0) + (signed char)((p_19 | 4294967295UL) >= ((+g_3) >= p_19)));
    step_hash(185);
    (*l_302) = (~(+((**g_193) == (*l_301))));
    step_hash(186);
    return (*l_302);
}
static int * func_24(int p_25)
{
    unsigned char l_33 = 0x02L;
    int l_218 = (-1L);
    int ***l_225 = &g_194;
    unsigned char l_234 = 0x00L;
    int *l_297 = (void*)0;
    int *l_298 = &l_218;
    step_hash(180);
    if ((((unsigned char)(((short)p_25 << (short)12) != (+g_3)) % (unsigned char)((unsigned short)l_33 >> (unsigned short)func_34(&g_3, ((short)((short)0x4F4CL * (short)func_41((((g_3 & ((signed char)l_33 % (signed char)p_25)) ^ ((unsigned char)((unsigned short)(((-8L) != 0UL) == g_3) << (unsigned short)3) << (unsigned char)g_3)) == l_33))) / (short)p_25)))) < g_3))
    {
        int *l_214 = &g_53;
        int ***l_217 = &g_194;
        step_hash(110);
        (*l_214) = (((unsigned)(p_25 < p_25) + (unsigned)(65527UL <= l_33)) != ((signed char)((p_25 < (l_214 == (void*)0)) <= ((unsigned short)(l_217 != (void*)0) - (unsigned short)p_25)) * (signed char)p_25));
        step_hash(111);
        l_218 = ((**l_217) == (void*)0);
        step_hash(176);
        if (l_33)
        {
            int ***l_224 = (void*)0;
            step_hash(133);
            if (p_25)
            {
                int *l_219 = &l_218;
                step_hash(129);
                if ((&l_218 == l_219))
                {
                    int *l_235 = &g_53;
                    step_hash(123);
                    if (((((unsigned char)(((unsigned char)p_25 * (unsigned char)0x28L) | (p_25 == (((((6L && (p_25 > g_124)) <= ((**l_217) == (*g_194))) < ((l_224 != l_225) || 0L)) ^ g_83) > 0L))) / (unsigned char)g_83) || p_25) ^ g_3))
                    {
                        step_hash(116);
                        (*l_214) = (((unsigned short)p_25 - (unsigned short)((*l_225) != (*g_193))) <= (4294967295UL >= g_53));
                        step_hash(117);
                        (*l_214) ^= p_25;
                    }
                    else
                    {
                        step_hash(119);
                        (**l_217) = l_219;
                        step_hash(120);
                        (**g_194) = (*g_133);
                        step_hash(121);
                        (***l_217) = (***g_193);
                        step_hash(122);
                        (*g_133) = (func_61((((unsigned)p_25 + (unsigned)1L) >= (((short)((signed char)l_234 * (signed char)g_83) << (short)2) >= 0x115AL)), (*g_194), (***l_225), l_235, g_53) ^ (***l_225));
                    }
                    step_hash(124);
                    l_219 = l_235;
                    step_hash(125);
                    (*l_219) = ((unsigned short)((4294967295UL == p_25) && 0L) - (unsigned short)0x4BD2L);
                    step_hash(126);
                    (**g_193) = g_238;
                }
                else
                {
                    step_hash(128);
                    (*l_219) ^= ((unsigned char)(p_25 >= (-8L)) >> (unsigned char)2);
                }
                step_hash(130);
                g_83 &= ((*l_219) == g_124);
            }
            else
            {
                step_hash(132);
                return (*g_194);
            }
        }
        else
        {
            unsigned short l_243 = 9UL;
            int *l_244 = &g_53;
            unsigned l_283 = 0xFF36FFF5L;
            step_hash(175);
            if ((g_53 | (((short)l_243 % (short)65529UL) ^ (*l_214))))
            {
                int **l_268 = &l_244;
                step_hash(136);
                (*g_194) = l_244;
                step_hash(137);
                (***g_193) = ((***l_225) == 1UL);
                step_hash(156);
                if ((***g_193))
                {
                    int ***l_251 = &g_194;
                    step_hash(144);
                    for (g_124 = 0; (g_124 != 36); g_124++)
                    {
                        step_hash(142);
                        (**g_194) |= 0xEB8BAC61L;
                        step_hash(143);
                        (***l_217) = ((void*)0 != l_251);
                    }
                    step_hash(150);
                    for (l_218 = (-18); (l_218 == 25); l_218++)
                    {
                        step_hash(148);
                        (***g_193) = (-3L);
                        step_hash(149);
                        (**l_217) = (**l_225);
                    }
                    step_hash(151);
                    (**l_268) = ((short)0x68F2L * (short)((unsigned char)(0x59070625L ^ (g_83 | p_25)) - (unsigned char)((int)(-3L) - (int)((unsigned short)((short)g_3 << (short)g_53) % (unsigned short)((short)((short)(((void*)0 == l_268) != 0x86A66762L) - (short)(*l_244)) << (short)(***l_225))))));
                    step_hash(152);
                    (**l_217) = (*g_194);
                }
                else
                {
                    unsigned l_277 = 4UL;
                    step_hash(154);
                    (*l_214) = ((func_61(g_3, (**l_217), (g_53 < (p_25 ^ 0UL)), (**g_193), g_83) == g_53) != p_25);
                    step_hash(155);
                    (*l_244) &= ((signed char)p_25 + (signed char)((short)((signed char)((unsigned short)l_277 >> (unsigned short)3) << (signed char)3) >> (short)2));
                }
            }
            else
            {
                int ***l_280 = &g_194;
                int l_284 = 3L;
                step_hash(158);
                l_284 &= ((unsigned short)(((*l_225) != (*g_193)) || ((~((p_25 || ((void*)0 != l_280)) | func_61((p_25 ^ ((short)func_61(g_3, (**l_217), (l_283 <= g_3), (**l_280), p_25) >> (short)14)), (*g_194), (*l_244), (**g_193), (*l_244)))) != p_25)) % (unsigned short)(*l_214));
                step_hash(173);
                for (l_33 = (-16); (l_33 >= 8); l_33 += 6)
                {
                    step_hash(166);
                    for (g_3 = 0; (g_3 != (-13)); g_3--)
                    {
                        unsigned short l_289 = 8UL;
                        step_hash(165);
                        (*l_214) = l_289;
                    }
                    step_hash(172);
                    if (p_25)
                    {
                        step_hash(168);
                        (*l_214) = ((**l_280) == (*g_194));
                        step_hash(169);
                        (*l_214) &= 0xDA774B31L;
                    }
                    else
                    {
                        step_hash(171);
                        (**g_193) = (**l_280);
                    }
                }
                step_hash(174);
                (*l_244) ^= p_25;
            }
        }
        step_hash(177);
        (*l_214) ^= 1L;
    }
    else
    {
        step_hash(179);
        (**g_193) = (*g_194);
    }
    step_hash(181);
    (*l_298) = ((unsigned char)p_25 + (unsigned char)func_54((**g_193)));
    step_hash(182);
    return (**g_193);
}
static short func_34(int * p_35, int p_36)
{
    int l_88 = 0x09715B7DL;
    unsigned short l_93 = 0xF5EEL;
    int *l_102 = &g_83;
    signed char l_115 = 0xDCL;
    int *l_118 = &g_83;
    unsigned l_125 = 0x60C92991L;
    int *l_134 = &g_83;
    int **l_139 = &l_102;
    short l_156 = 1L;
    unsigned char l_190 = 0UL;
    step_hash(32);
    (*l_102) = ((unsigned char)((func_54(p_35) != l_88) ^ ((int)((unsigned char)l_93 << (unsigned char)((unsigned char)((((func_61(((unsigned char)((unsigned short)(~0x7968L) % (unsigned short)((unsigned short)g_83 << (unsigned short)1)) << (unsigned char)3), &g_83, l_88, p_35, l_93) != l_93) || 255UL) < p_36) ^ 0xCEL) / (unsigned char)0xB1L)) + (int)p_36)) >> (unsigned char)3);
    step_hash(73);
    if (g_83)
    {
        int **l_103 = &l_102;
        unsigned l_116 = 4294967291UL;
        int *l_123 = &g_3;
        int *l_128 = &l_88;
        step_hash(34);
        (*l_103) = &g_83;
        step_hash(42);
        if ((((signed char)(((&p_35 == l_103) & (*l_102)) & g_83) << (signed char)5) & func_61(((g_53 || ((short)(g_3 > (*l_102)) << (short)(**l_103))) < (5L && (*l_102))), &l_88, (*p_35), (*l_103), (**l_103))))
        {
            short l_108 = 0x85BBL;
            step_hash(36);
            (*l_103) = &l_88;
            step_hash(37);
            return l_108;
        }
        else
        {
            int *l_117 = &g_53;
            step_hash(39);
            (*l_102) = func_41((((int)((unsigned)(((unsigned char)g_53 * (unsigned char)6UL) || l_115) + (unsigned)(func_54(&l_88) != func_67((l_116 >= p_36), p_36, l_117, p_35, (**l_103)))) % (int)(-8L)) ^ g_3));
            step_hash(40);
            l_118 = p_35;
            step_hash(41);
            g_124 |= (((int)((*l_103) == l_123) % (int)g_3) > ((((((*l_117) < func_67(p_36, ((**l_103) & ((~func_54((*l_103))) & p_36)), p_35, &g_83, g_3)) ^ g_53) >= p_36) ^ (-8L)) == (*p_35)));
        }
        step_hash(68);
        if (l_125)
        {
            step_hash(48);
            for (l_116 = 0; (l_116 >= 38); l_116 += 2)
            {
                step_hash(47);
                (*l_102) ^= (l_128 == p_35);
            }
            step_hash(49);
            (*l_103) = &g_83;
            step_hash(58);
            for (g_124 = (-14); (g_124 > 7); ++g_124)
            {
                step_hash(57);
                for (l_116 = 22; (l_116 == 58); ++l_116)
                {
                    step_hash(56);
                    if ((*p_35))
                        break;
                }
            }
            step_hash(59);
            g_133 = (void*)0;
        }
        else
        {
            step_hash(66);
            if (((*l_103) != l_134))
            {
                int ***l_135 = &l_103;
                step_hash(62);
                p_35 = p_35;
                step_hash(63);
                (*l_135) = &g_133;
            }
            else
            {
                step_hash(65);
                (*l_103) = (void*)0;
            }
            step_hash(67);
            return (*l_134);
        }
    }
    else
    {
        int *l_138 = &g_53;
        step_hash(70);
        (*l_102) ^= ((unsigned short)(l_138 == (void*)0) % (unsigned short)p_36);
        step_hash(71);
        g_53 ^= (*g_133);
        step_hash(72);
        return g_124;
    }
    step_hash(74);
    (*l_139) = &l_88;
    step_hash(107);
    if ((*l_118))
    {
        int l_145 = 0xE211E8D5L;
        int l_171 = (-8L);
        int *l_192 = &l_171;
        int ***l_195 = &g_194;
        step_hash(91);
        for (p_36 = (-20); (p_36 == 28); p_36 += 3)
        {
            signed char l_153 = 0xC5L;
            int *l_157 = &g_53;
        }
        step_hash(92);
        (*l_139) = &g_3;
        step_hash(103);
        for (l_145 = 0; (l_145 <= (-15)); --l_145)
        {
            unsigned short l_191 = 0UL;
            int l_209 = 0x7FFFD43EL;
            step_hash(101);
            if (((+((unsigned char)((((unsigned char)(((unsigned short)(255UL || ((unsigned)(*l_118) - (unsigned)func_41((((((short)p_36 + (short)(~(((short)g_53 + (short)g_53) | g_53))) <= ((void*)0 == &g_133)) || ((unsigned)((unsigned char)g_3 - (unsigned char)p_36) / (unsigned)(*p_35))) && l_190)))) - (unsigned short)0x0311L) ^ l_145) / (unsigned char)0x08L) ^ l_191) & 9L) + (unsigned char)g_3)) | 0x91350E28L))
            {
                step_hash(97);
                l_192 = &g_53;
                step_hash(98);
                (*l_134) &= (g_193 != l_195);
            }
            else
            {
                unsigned l_208 = 4294967289UL;
                step_hash(100);
                l_209 = ((unsigned)0x2ACCF633L - (unsigned)(((p_36 <= ((short)0x4944L + (short)(((((unsigned char)(&g_194 == &l_139) * (unsigned char)((short)(-9L) % (short)p_36)) ^ (((short)((!(g_53 & ((short)(((g_124 >= (*p_35)) > p_36) != l_191) >> (short)8))) != p_36) + (short)p_36) & 4UL)) < l_208) >= (*l_192)))) ^ 0L) & l_208));
            }
            step_hash(102);
            (*l_139) = (*g_194);
        }
    }
    else
    {
        step_hash(105);
        (*l_134) ^= ((**l_139) ^ (*p_35));
        step_hash(106);
        (*l_102) &= (*p_35);
    }
    step_hash(108);
    return p_36;
}
static short func_41(unsigned short p_42)
{
    int *l_51 = (void*)0;
    int *l_52 = &g_53;
    step_hash(12);
    (*l_52) = 0x3BE41B0CL;
    step_hash(29);
    (*l_52) = (func_54(&g_3) | ((((g_53 != func_54(l_51)) >= ((*l_52) > ((unsigned short)((&g_53 == (void*)0) || ((unsigned)func_61((func_67((*l_52), g_3, l_52, l_52, (*l_52)) ^ g_53), &g_53, (*l_52), l_52, g_53) - (unsigned)g_53)) << (unsigned short)10))) > 0xE3L) & 4UL));
    step_hash(30);
    return p_42;
}
static short func_54(int * p_55)
{
    unsigned l_56 = 1UL;
    step_hash(14);
    return l_56;
}
static unsigned func_61(signed char p_62, int * p_63, int p_64, int * p_65, unsigned short p_66)
{
    int **l_85 = (void*)0;
    int ***l_84 = &l_85;
    step_hash(27);
    (*l_84) = (void*)0;
    step_hash(28);
    return g_3;
}
static int func_67(unsigned p_68, int p_69, int * p_70, int * p_71, unsigned char p_72)
{
    unsigned l_78 = 0x5E5AB8BFL;
    int *l_82 = &g_83;
    step_hash(23);
    for (p_68 = 0; (p_68 < 7); ++p_68)
    {
        int l_75 = 6L;
        int *l_79 = &l_75;
        step_hash(19);
        l_75 = ((&g_53 != &g_53) | 0L);
        step_hash(20);
        l_75 = ((g_3 & (l_75 <= p_72)) | l_78);
        step_hash(21);
        (*l_79) &= func_54(&l_75);
        step_hash(22);
        if ((*p_70))
            break;
    }
    step_hash(24);
    (*l_82) = ((signed char)l_78 + (signed char)l_78);
    step_hash(25);
    return (*p_71);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_53, "g_53", print_hash_value);
    transparent_crc(g_83, "g_83", print_hash_value);
    transparent_crc(g_124, "g_124", print_hash_value);
    transparent_crc(g_634, "g_634", print_hash_value);
    transparent_crc(g_661, "g_661", print_hash_value);
    transparent_crc(g_741, "g_741", print_hash_value);
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
