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
static short g_23 = 0x1A9CL;
static int g_41 = (-7L);
static int g_56 = 0xEE3E4F6FL;
static int *g_62 = &g_56;
static int **g_61 = &g_62;
static int *g_83 = &g_41;
static int **g_82 = &g_83;
static int g_85 = 1L;
static int g_249 = 5L;
static unsigned short g_292 = 0xA7A5L;
static unsigned short g_533 = 0x35D4L;
static unsigned char g_574 = 0x42L;
static signed char g_805 = (-1L);
static unsigned g_862 = 0x1B116697L;
static unsigned short func_1(void);
static int func_2(unsigned short p_3, short p_4, signed char p_5);
static signed char func_8(unsigned p_9, int p_10, unsigned p_11, unsigned short p_12, unsigned short p_13);
static signed char func_24(unsigned p_25);
static short func_28(signed char p_29);
static short func_42(unsigned p_43);
static int func_47(int p_48);
static short func_57(unsigned p_58, unsigned short p_59, int ** p_60);
static unsigned short func_65(unsigned short p_66, int ** p_67, int * p_68, unsigned char p_69);
static int ** func_70(unsigned short p_71);
static unsigned short func_1(void)
{
    unsigned l_14 = 0x82FF40FCL;
    int *l_584 = &g_85;
    int ***l_596 = &g_61;
    signed char l_691 = 0x58L;
    int ***l_712 = &g_61;
    signed char l_740 = 1L;
    unsigned l_837 = 0x9D91B77DL;
    unsigned short l_899 = 0x57ABL;
    int l_900 = (-7L);
    step_hash(597);
    if (func_2(((signed char)func_8(l_14, ((unsigned short)((((signed char)((short)(((int)g_23 + (int)1UL) > g_23) + (short)g_23) * (signed char)func_24(((short)func_28(((((int)((unsigned char)(((signed char)l_14 * (signed char)g_23) < ((unsigned char)((signed char)0xC6L % (signed char)0xB2L) >> (unsigned char)5)) * (unsigned char)g_23) % (int)g_23) <= 0x52B4L) || 248UL)) * (short)1L))) <= g_23) || l_14) % (unsigned short)g_23), l_14, g_23, g_23) >> (signed char)g_574), g_574, g_574))
    {
        signed char l_576 = 0x5DL;
        int ***l_580 = &g_61;
        int l_595 = (-1L);
        unsigned l_610 = 4294967295UL;
        unsigned short l_731 = 0xAD6EL;
        short l_808 = 0L;
        step_hash(493);
        if (l_576)
        {
            int *l_583 = &g_56;
            short l_592 = 9L;
            int ***l_624 = &g_82;
            int ***l_668 = &g_82;
            unsigned l_670 = 4294967295UL;
            step_hash(433);
            for (g_574 = 0; (g_574 >= 29); ++g_574)
            {
                int ***l_579 = &g_82;
                int *l_589 = &g_85;
                step_hash(429);
                if ((l_579 == l_580))
                {
                    step_hash(424);
                    for (l_14 = (-14); (l_14 > 20); l_14++)
                    {
                        step_hash(421);
                        (**g_61) = (*g_62);
                        step_hash(422);
                        (**l_580) = (*g_61);
                        step_hash(423);
                        (**g_61) ^= 1L;
                    }
                    step_hash(425);
                    if ((**g_61))
                        break;
                }
                else
                {
                    step_hash(427);
                    l_584 = l_583;
                    step_hash(428);
                    if ((***l_580))
                        continue;
                }
                step_hash(430);
                (*l_589) ^= (((int)(*l_583) / (int)(((short)2L * (short)func_2((***l_580), g_533, g_533)) | g_574)) || ((g_574 & g_574) || g_574));
                step_hash(431);
                (**l_579) = (*g_61);
                step_hash(432);
                return (*l_583);
            }
            step_hash(480);
            if ((1UL | (*l_584)))
            {
                unsigned char l_600 = 0xC7L;
                step_hash(455);
                for (g_23 = (-26); (g_23 < 18); g_23 += 8)
                {
                    unsigned l_607 = 0x845D9B98L;
                    unsigned char l_611 = 0x3FL;
                    int *l_612 = (void*)0;
                    step_hash(446);
                    if ((g_292 <= g_23))
                    {
                        step_hash(439);
                        (**l_580) = l_583;
                        step_hash(440);
                        return g_292;
                    }
                    else
                    {
                        step_hash(442);
                        (**g_61) = 1L;
                        step_hash(443);
                        (*l_584) &= ((l_595 && (l_596 == (void*)0)) && g_23);
                        step_hash(444);
                        g_249 |= (***l_580);
                        step_hash(445);
                        (*g_62) = (((***l_580) ^ func_47((-(int)((*g_62) & (*g_62))))) != 4UL);
                    }
                    step_hash(454);
                    if ((((int)l_600 / (int)((unsigned char)((unsigned short)(0xEDB5A356L >= ((unsigned char)((((l_607 > (***l_596)) >= (*l_584)) >= (g_574 ^ (((short)l_610 >> (short)14) | ((l_611 <= (+g_249)) <= g_574)))) == 0xE024L) << (unsigned char)g_56)) * (unsigned short)0xED9CL) + (unsigned char)g_56)) < 4294967293UL))
                    {
                        step_hash(448);
                        (*g_82) = l_612;
                        step_hash(449);
                        (**l_580) = (*g_61);
                        step_hash(450);
                        return (*l_583);
                    }
                    else
                    {
                        int *l_613 = &g_56;
                        step_hash(452);
                        (*g_61) = l_613;
                        step_hash(453);
                        (*l_584) = l_600;
                    }
                }
                step_hash(460);
                for (g_292 = 24; (g_292 != 42); ++g_292)
                {
                    unsigned char l_629 = 0xCFL;
                    step_hash(459);
                    (*g_62) = ((unsigned short)((unsigned)((short)(g_85 | ((short)0x45E1L >> (short)(((void*)0 != l_624) || ((signed char)((unsigned short)g_292 * (unsigned short)l_629) / (signed char)0xB1L)))) % (short)(***l_580)) - (unsigned)0x58163E35L) % (unsigned short)g_23);
                }
            }
            else
            {
                int **l_636 = (void*)0;
                int l_669 = 9L;
                int l_671 = 0L;
                step_hash(466);
                for (g_574 = 0; (g_574 < 32); g_574 += 5)
                {
                    step_hash(465);
                    return g_41;
                }
                step_hash(477);
                if (((unsigned char)(*l_584) << (unsigned char)(((unsigned)((&g_62 == l_636) == g_85) % (unsigned)((short)7L * (short)((unsigned short)((unsigned char)1UL / (unsigned char)((signed char)((void*)0 == &g_82) >> (signed char)((unsigned short)(~g_574) * (unsigned short)65535UL))) << (unsigned short)10))) <= 0xA8DDL)))
                {
                    step_hash(468);
                    (*g_62) |= ((**l_596) == (void*)0);
                }
                else
                {
                    step_hash(475);
                    for (l_592 = 13; (l_592 >= (-28)); --l_592)
                    {
                        int l_651 = 0x8266FC1BL;
                        step_hash(473);
                        if ((**g_61))
                            break;
                        step_hash(474);
                        l_671 &= ((unsigned char)l_651 << (unsigned char)((g_41 ^ (((short)(((*l_584) >= ((signed char)(-9L) << (signed char)(*l_584))) && ((unsigned char)(((int)0x97E5E5FEL + (int)(((unsigned char)((unsigned short)((((unsigned)((unsigned char)g_41 * (unsigned char)(&g_82 == l_668)) + (unsigned)(*g_62)) == g_292) >= 1UL) * (unsigned short)0x7148L) - (unsigned char)l_669) == g_249)) || g_574) + (unsigned char)g_249)) % (short)(***l_596)) != l_670)) >= g_85));
                    }
                    step_hash(476);
                    (**l_580) = (*g_61);
                }
                step_hash(478);
                (*g_62) |= 0L;
                step_hash(479);
                (**l_596) = (*g_61);
            }
            step_hash(481);
            (**l_596) = (*g_61);
        }
        else
        {
            int l_682 = 0xF1CA09A8L;
            int **l_683 = &l_584;
            step_hash(490);
            for (g_292 = (-3); (g_292 > 57); g_292 += 4)
            {
                unsigned l_680 = 0x8FD928D2L;
                int *l_681 = &g_249;
                step_hash(486);
                (***l_596) ^= 1L;
                step_hash(487);
                (*g_62) = 4L;
                step_hash(488);
                (*l_584) &= ((unsigned char)(((((unsigned)g_249 % (unsigned)((short)(***l_580) * (short)0x9EBBL)) != l_680) & (((&g_61 != &g_82) <= g_533) | 0x8A6CL)) < (***l_580)) * (unsigned char)g_292);
                step_hash(489);
                (*l_681) |= ((***l_580) != (*l_584));
            }
            step_hash(491);
            (***l_580) ^= (l_682 ^ g_292);
            step_hash(492);
            (*l_596) = l_683;
        }
        step_hash(494);
        (**l_580) = (**l_580);
        step_hash(591);
        for (g_41 = (-26); (g_41 >= 8); g_41 += 3)
        {
            signed char l_690 = 2L;
            int l_715 = 0L;
            int l_794 = 1L;
            int l_807 = (-1L);
            step_hash(498);
            if ((*l_584))
                break;
            step_hash(499);
            (***l_596) = ((((unsigned char)((signed char)((*g_61) == (**l_580)) << (signed char)l_690) >> (unsigned char)g_249) > l_690) ^ g_85);
            step_hash(542);
            for (l_610 = 28; (l_610 > 14); l_610 -= 9)
            {
                unsigned l_702 = 0x533DD5F4L;
                int ***l_741 = &g_61;
                step_hash(503);
                (*g_82) = (**l_580);
                step_hash(517);
                if (((unsigned char)(((signed char)func_2(g_41, l_690, g_56) >> (signed char)((signed char)((((short)g_85 - (short)(l_702 | func_47((l_691 > l_690)))) || l_690) >= g_292) << (signed char)3)) | g_249) << (unsigned char)5))
                {
                    unsigned l_705 = 0x1FE613C0L;
                    step_hash(511);
                    if ((~((unsigned char)((l_702 != (l_705 | 0x22416BF5L)) <= (!((unsigned char)func_24((***l_596)) - (unsigned char)((short)((signed char)((void*)0 == l_712) - (signed char)((unsigned)g_41 % (unsigned)g_23)) + (short)g_292)))) * (unsigned char)g_23)))
                    {
                        step_hash(506);
                        l_715 |= (*g_62);
                        step_hash(507);
                        g_85 ^= (g_56 <= 0x5E89L);
                        step_hash(508);
                        return g_249;
                    }
                    else
                    {
                        step_hash(510);
                        (*g_82) = (**l_596);
                    }
                }
                else
                {
                    short l_716 = (-3L);
                    int *l_717 = (void*)0;
                    int *l_718 = &g_249;
                    step_hash(513);
                    (*l_584) = func_47((0x9972L != l_702));
                    step_hash(514);
                    (*l_718) |= (func_24(g_574) < l_716);
                    step_hash(515);
                    (***l_712) = ((unsigned short)((***l_596) <= (~func_47((((*l_580) != (void*)0) != (((0L & (&g_62 != &l_717)) > (0xFEL & ((short)l_715 << (short)((((((unsigned char)((short)((unsigned char)((int)0x663B5B55L - (int)(*l_584)) - (unsigned char)l_731) >> (short)8) + (unsigned char)g_85) && l_690) >= 7UL) == 0x16L) > 0xBEL)))) == g_56))))) * (unsigned short)g_533);
                    step_hash(516);
                    (**g_61) = 0x8CC47B6DL;
                }
                step_hash(518);
                (*l_584) |= l_702;
                step_hash(541);
                if ((*l_584))
                {
                    unsigned l_744 = 0xB85332B2L;
                    step_hash(524);
                    for (g_533 = 0; (g_533 == 5); ++g_533)
                    {
                        step_hash(523);
                        return g_249;
                    }
                    step_hash(525);
                    (**g_61) = ((unsigned char)((signed char)((((unsigned short)((*g_62) & l_740) << (unsigned short)14) <= (g_533 || (l_741 != &g_82))) == g_41) << (signed char)g_574) * (unsigned char)(***l_596));
                    step_hash(531);
                    for (g_292 = 0; (g_292 == 11); g_292++)
                    {
                        unsigned char l_749 = 255UL;
                        step_hash(529);
                        (***l_596) = (l_744 != ((unsigned short)l_715 + (unsigned short)((250UL & (((unsigned char)g_574 - (unsigned char)(***l_712)) | (0x31L & 0xBAL))) < g_41)));
                        step_hash(530);
                        return l_749;
                    }
                }
                else
                {
                    int l_764 = 0x4BBAFEEAL;
                    int l_765 = 2L;
                    step_hash(533);
                    (*l_584) = (**g_61);
                    step_hash(539);
                    for (l_595 = 27; (l_595 > 15); l_595 -= 1)
                    {
                        step_hash(537);
                        if ((***l_741))
                            break;
                        step_hash(538);
                        (***l_712) = ((unsigned char)l_690 + (unsigned char)((***l_596) >= g_533));
                    }
                    step_hash(540);
                    l_765 = (func_24(g_23) == ((unsigned short)((signed char)g_533 << (signed char)4) - (unsigned short)(((unsigned short)g_292 << (unsigned short)((((((int)((unsigned char)(l_715 & ((g_85 >= 0x08F8L) | g_85)) * (unsigned char)(((void*)0 == &g_82) && g_249)) + (int)l_690) && g_574) >= g_85) != g_574) < g_249)) | l_764)));
                }
            }
            step_hash(590);
            for (l_715 = (-28); (l_715 < (-12)); l_715++)
            {
                unsigned char l_792 = 0x62L;
                int l_809 = 0x5F1FD7BDL;
                step_hash(563);
                for (l_576 = 0; (l_576 <= (-12)); l_576--)
                {
                    int *l_770 = (void*)0;
                }
            }
        }
        step_hash(592);
        (***l_712) = (*g_62);
    }
    else
    {
        unsigned char l_828 = 0x93L;
        step_hash(594);
        (*l_584) &= (**g_61);
        step_hash(595);
        (*g_82) = (*g_61);
        step_hash(596);
        (*l_584) = l_828;
    }
    step_hash(642);
    for (g_56 = 0; (g_56 == (-7)); g_56 -= 6)
    {
        int *l_831 = (void*)0;
        int l_832 = 0x077F80CCL;
        int **l_848 = &l_584;
        unsigned short l_891 = 0UL;
        int l_901 = 1L;
        step_hash(601);
        (**l_712) = l_831;
        step_hash(602);
        g_41 = l_832;
        step_hash(641);
        for (g_574 = 21; (g_574 >= 28); g_574++)
        {
            signed char l_835 = 0x81L;
            int *l_836 = &g_41;
            int ***l_838 = &g_82;
            int l_890 = (-8L);
            int *l_894 = &l_890;
            unsigned l_902 = 0xFF75ECFCL;
            step_hash(606);
            (*l_836) = (func_24(g_574) >= (l_835 >= (5UL & (g_292 && l_832))));
            step_hash(607);
            (*l_836) = (*l_836);
            step_hash(639);
            if (l_837)
            {
                unsigned short l_841 = 0x0E4EL;
                int **l_849 = &l_584;
                step_hash(609);
                (*l_836) = (((l_838 == &g_82) != ((signed char)l_841 >> (signed char)(((unsigned)(((unsigned char)g_41 << (unsigned char)g_249) | ((unsigned)((((void*)0 == &l_832) <= (l_848 == l_849)) == 9L) - (unsigned)(*l_836))) - (unsigned)0UL) & (*l_836)))) && g_23);
                step_hash(610);
                (**l_712) = (*l_848);
            }
            else
            {
                int *l_850 = &g_41;
                int l_889 = 1L;
                step_hash(612);
                l_850 = (void*)0;
                step_hash(637);
                if (l_832)
                {
                    unsigned l_866 = 0x0FD79D07L;
                    int *l_867 = &g_85;
                    step_hash(614);
                    if (g_249)
                        break;
                    step_hash(622);
                    for (g_23 = 7; (g_23 == 8); g_23 += 1)
                    {
                        unsigned short l_855 = 65532UL;
                        step_hash(618);
                        (*l_836) = (((9UL == ((0x41C28DB2L && ((signed char)g_533 + (signed char)(l_855 & 0xD1AAL))) > (((unsigned char)((void*)0 != &g_62) + (unsigned char)((signed char)(-3L) % (signed char)((signed char)g_862 * (signed char)0x4EL))) | 0x3B297379L))) != 0x2AE69BD7L) != 2L);
                        step_hash(619);
                        (*l_836) |= l_855;
                        step_hash(620);
                        l_866 = ((signed char)(-(short)g_533) << (signed char)7);
                        step_hash(621);
                        (**l_596) = l_867;
                    }
                    step_hash(628);
                    for (l_837 = 0; (l_837 > 25); l_837++)
                    {
                        step_hash(626);
                        (*l_867) &= 0L;
                        step_hash(627);
                        (*l_836) &= 1L;
                    }
                }
                else
                {
                    int l_882 = (-8L);
                    step_hash(634);
                    for (g_533 = 0; (g_533 >= 36); g_533 += 8)
                    {
                        step_hash(633);
                        l_882 = ((short)((unsigned char)g_56 << (unsigned char)l_882) + (short)0x7743L);
                    }
                    step_hash(635);
                    (**l_596) = (void*)0;
                    step_hash(636);
                    (*g_61) = (*l_848);
                }
                step_hash(638);
                (*l_836) ^= l_889;
            }
            step_hash(640);
            (*l_894) = func_47(((*l_894) == g_41));
        }
    }
    step_hash(643);
    return g_249;
}
static int func_2(unsigned short p_3, short p_4, signed char p_5)
{
    int *l_575 = &g_56;
    step_hash(410);
    (*g_61) = l_575;
    step_hash(411);
    return (*l_575);
}
static signed char func_8(unsigned p_9, int p_10, unsigned p_11, unsigned short p_12, unsigned short p_13)
{
    int ***l_560 = &g_82;
    int l_565 = 7L;
    int *l_566 = &g_249;
    step_hash(391);
    (*g_62) = ((-5L) > (((l_560 != &g_82) != ((unsigned)((&g_62 != &g_83) <= (((0x9750183FL <= 0x84AF7124L) >= 0xBB52L) > ((((((unsigned short)(p_13 == 0xF8BDCD6BL) * (unsigned short)p_12) ^ p_10) && p_11) | g_85) <= 2L))) + (unsigned)l_565)) < p_11));
    step_hash(392);
    (*l_566) &= (**g_61);
    step_hash(407);
    for (p_10 = 2; (p_10 == 27); p_10 += 7)
    {
        step_hash(400);
        for (g_23 = 0; (g_23 >= 4); ++g_23)
        {
            unsigned l_571 = 0xBD989012L;
            step_hash(399);
            l_571 &= 0xBE916A31L;
        }
        step_hash(406);
        for (g_41 = (-12); (g_41 != (-16)); g_41 -= 3)
        {
            step_hash(404);
            (*l_566) |= 1L;
            step_hash(405);
            return p_13;
        }
    }
    step_hash(408);
    return p_12;
}
static signed char func_24(unsigned p_25)
{
    int *l_559 = &g_85;
    step_hash(387);
    (*g_61) = l_559;
    step_hash(388);
    (*g_82) = (*g_61);
    step_hash(389);
    return p_25;
}
static short func_28(signed char p_29)
{
    int ***l_370 = (void*)0;
    unsigned char l_393 = 255UL;
    int **l_431 = &g_83;
    unsigned char l_518 = 0x57L;
    int ***l_557 = (void*)0;
    int ***l_558 = &l_431;
    step_hash(382);
    if (p_29)
    {
        int *l_40 = &g_41;
        step_hash(3);
        (*l_40) = 1L;
    }
    else
    {
        int ***l_369 = &g_82;
        unsigned char l_375 = 0x66L;
        short l_384 = 4L;
        int *l_426 = &g_56;
        unsigned l_513 = 4294967286UL;
        step_hash(381);
        if (((func_42(p_29) <= (l_369 != l_370)) > g_23))
        {
            int *l_371 = &g_56;
            unsigned char l_404 = 1UL;
            unsigned char l_413 = 0xFCL;
            int ***l_419 = (void*)0;
            step_hash(267);
            (*l_371) = p_29;
            step_hash(274);
            if (p_29)
            {
                int *l_372 = &g_41;
                step_hash(269);
                l_372 = l_372;
            }
            else
            {
                step_hash(271);
                (*l_371) = ((signed char)l_375 << (signed char)g_56);
                step_hash(272);
                (*l_371) = (((unsigned short)0x9792L / (unsigned short)((short)((unsigned char)((unsigned short)(*l_371) << (unsigned short)g_249) << (unsigned char)6) - (short)(p_29 && l_384))) ^ ((signed char)g_85 - (signed char)((signed char)7L * (signed char)g_23)));
                step_hash(273);
                (*g_82) = l_371;
            }
            step_hash(275);
            (*l_371) = p_29;
            step_hash(317);
            if ((*l_371))
            {
                unsigned char l_394 = 0xBBL;
                int *l_417 = &g_85;
                int ***l_418 = (void*)0;
                step_hash(286);
                for (g_85 = (-9); (g_85 >= (-30)); g_85 -= 1)
                {
                    step_hash(280);
                    (*l_369) = func_70(p_29);
                    step_hash(285);
                    for (g_292 = (-19); (g_292 > 51); g_292++)
                    {
                        step_hash(284);
                        l_394 |= (l_393 != ((*l_371) | p_29));
                    }
                }
                step_hash(294);
                if (((((unsigned char)(-(unsigned short)((unsigned short)(((((unsigned)p_29 - (unsigned)(((short)((l_394 & 1L) < l_404) >> (short)func_47(p_29)) <= ((int)((((signed char)((!(-8L)) && (func_47(func_47((*l_371))) < p_29)) << (signed char)g_249) || g_85) || 1UL) + (int)(*l_371)))) | g_56) == 0UL) != (-3L)) + (unsigned short)p_29)) / (unsigned char)0x9DL) || g_292) > l_394))
                {
                    step_hash(288);
                    (*g_82) = l_371;
                    step_hash(289);
                    (*l_369) = &g_62;
                    step_hash(290);
                    return g_85;
                }
                else
                {
                    int **l_416 = &g_62;
                    step_hash(292);
                    (*l_417) = ((int)((unsigned)l_413 + (unsigned)((unsigned short)((*l_371) ^ (!g_249)) * (unsigned short)(-10L))) - (int)g_85);
                    step_hash(293);
                    (*l_371) = 0x01EA184CL;
                }
                step_hash(299);
                for (g_41 = 0; (g_41 < (-11)); --g_41)
                {
                    step_hash(298);
                    (*l_426) = ((unsigned short)((signed char)((void*)0 != l_426) << (signed char)(p_29 ^ l_393)) << (unsigned short)11);
                }
            }
            else
            {
                unsigned char l_452 = 0UL;
                int *l_453 = &g_85;
                unsigned l_464 = 0xAA4A6445L;
                step_hash(306);
                for (g_292 = (-29); (g_292 == 33); ++g_292)
                {
                    int l_440 = 0xC09D12EAL;
                    int **l_451 = &g_83;
                    step_hash(304);
                    l_452 |= ((&g_62 != l_431) >= (((unsigned short)(((((short)((int)(((unsigned char)g_56 * (unsigned char)l_440) & g_249) / (int)((signed char)((signed char)((unsigned short)((short)g_292 << (short)9) * (unsigned short)((int)((void*)0 != l_451) + (int)(p_29 ^ 0x800EBDDEL))) - (signed char)p_29) * (signed char)1UL)) * (short)0xF012L) < g_56) ^ p_29) | 4294967295UL) >> (unsigned short)14) > 1UL));
                    step_hash(305);
                    (*l_451) = l_453;
                }
                step_hash(316);
                for (g_249 = 4; (g_249 < 22); g_249 += 2)
                {
                    int *l_468 = &g_56;
                    step_hash(314);
                    if ((g_41 > (func_47(p_29) == ((((short)((unsigned short)0x6E4FL * (unsigned short)(((unsigned)g_85 - (unsigned)(l_464 <= p_29)) && 0L)) << (short)(*l_453)) || g_41) < p_29))))
                    {
                        step_hash(311);
                        (*l_453) = ((int)(*l_371) % (int)g_56);
                    }
                    else
                    {
                        signed char l_467 = 0x3AL;
                        step_hash(313);
                        (*l_426) = l_467;
                    }
                    step_hash(315);
                    (**l_369) = l_468;
                }
            }
        }
        else
        {
            unsigned char l_473 = 0xA2L;
            int *l_476 = &g_249;
            unsigned char l_477 = 7UL;
            int *l_478 = (void*)0;
            int ***l_498 = &g_82;
            int l_503 = 0xC781FFB4L;
            int l_509 = 7L;
            int **l_510 = &l_426;
            int l_532 = (-1L);
            int *l_554 = &g_41;
            step_hash(319);
            (*l_476) |= ((int)(((((&g_62 != (void*)0) > g_23) || l_473) | (0x03L == ((unsigned)(*l_426) * (unsigned)((&g_62 == (void*)0) <= (*l_426))))) <= g_41) % (int)0x790F0472L);
            step_hash(326);
            if (p_29)
            {
                step_hash(321);
                (*l_476) &= ((0x864FAA03L >= 0x2BE1988FL) || 0x8D945039L);
                step_hash(322);
                (*g_61) = l_478;
                step_hash(323);
                (*l_476) |= p_29;
            }
            else
            {
                step_hash(325);
                return p_29;
            }
            step_hash(380);
            if ((!p_29))
            {
                unsigned short l_491 = 65526UL;
                int ***l_499 = &g_61;
                unsigned short l_505 = 0x52B8L;
                int **l_506 = &l_478;
                step_hash(344);
                if (((short)((*g_61) != (*g_61)) + (short)(~0x9C31L)))
                {
                    unsigned char l_487 = 0x54L;
                    int *l_504 = (void*)0;
                    step_hash(333);
                    for (p_29 = 0; (p_29 != 9); p_29 += 8)
                    {
                        int *l_488 = (void*)0;
                        int *l_489 = (void*)0;
                        int *l_490 = &g_41;
                        step_hash(332);
                        (*l_490) ^= (0x13A0L && ((signed char)(g_85 | ((unsigned char)((*l_426) >= l_487) * (unsigned char)(((p_29 == p_29) == 0UL) <= g_249))) >> (signed char)4));
                    }
                    step_hash(340);
                    if (p_29)
                    {
                        step_hash(335);
                        (*l_476) ^= p_29;
                        step_hash(336);
                        (**l_499) = (*g_61);
                    }
                    else
                    {
                        short l_511 = 0x0B17L;
                        step_hash(338);
                        (**l_510) |= (func_65(p_29, func_70(((0x7607ED46L == func_65(((unsigned short)(~l_509) - (unsigned short)(p_29 & g_292)), l_510, (*g_61), l_511)) <= g_41)), (*g_61), p_29) <= g_292);
                        step_hash(339);
                        (*l_506) = (*l_510);
                    }
                }
                else
                {
                    int *l_512 = (void*)0;
                    step_hash(342);
                    l_512 = (*l_506);
                    step_hash(343);
                    (**l_510) = p_29;
                }
                step_hash(366);
                if ((+(*l_476)))
                {
                    unsigned short l_519 = 0xDEE0L;
                    int l_520 = 1L;
                    step_hash(346);
                    (**l_510) &= l_513;
                    step_hash(347);
                    (*l_476) ^= p_29;
                    step_hash(356);
                    if ((0x35289A4EL && (*l_476)))
                    {
                        unsigned l_514 = 0x3E8D4C09L;
                        int **l_515 = &l_478;
                        int l_521 = 0x64E5E474L;
                        step_hash(349);
                        l_520 = (l_514 == ((&g_83 == l_515) != (((func_47((0x0BEA343EL <= ((((&g_82 != &l_506) > (l_518 <= (p_29 >= g_85))) ^ 0x1050L) & 0x701A0D4FL))) != l_519) <= (*l_476)) >= (-3L))));
                        step_hash(350);
                        l_521 = g_292;
                        step_hash(351);
                        g_533 |= (((((short)(0x54458521L & g_249) - (short)((*l_426) || ((unsigned)((unsigned char)(g_85 >= ((p_29 < g_56) && (~p_29))) >> (unsigned char)g_41) / (unsigned)p_29))) || p_29) > p_29) ^ l_532);
                    }
                    else
                    {
                        step_hash(353);
                        (*l_426) ^= p_29;
                        step_hash(354);
                        (*l_426) |= ((unsigned short)(g_533 <= (((unsigned char)((signed char)(p_29 || ((unsigned char)((unsigned short)((p_29 ^ (func_47(p_29) != 0x31C8532FL)) ^ 0L) % (unsigned short)(((unsigned char)0xE9L << (unsigned char)(((signed char)g_41 >> (signed char)g_41) >= 0x91L)) ^ 0xE6533EEAL)) / (unsigned char)0x77L)) / (signed char)0x83L) >> (unsigned char)2) >= 0xAB29B716L)) << (unsigned short)7);
                        step_hash(355);
                        (*g_82) = (void*)0;
                    }
                }
                else
                {
                    int *l_551 = (void*)0;
                    step_hash(365);
                    for (l_532 = 18; (l_532 < 26); l_532 += 5)
                    {
                        int *l_550 = &g_41;
                        step_hash(361);
                        (*l_476) = (*l_426);
                        step_hash(362);
                        l_550 = (void*)0;
                        step_hash(363);
                        (*l_506) = l_551;
                        step_hash(364);
                        return p_29;
                    }
                }
            }
            else
            {
                step_hash(379);
                for (l_518 = 0; (l_518 <= 14); l_518 += 7)
                {
                    step_hash(371);
                    (**l_369) = (*g_61);
                    step_hash(372);
                    (**l_498) = l_554;
                    step_hash(378);
                    for (g_249 = 0; (g_249 >= (-20)); g_249 -= 1)
                    {
                        step_hash(376);
                        if (p_29)
                            break;
                        step_hash(377);
                        (***l_498) &= ((-8L) >= (p_29 <= (*l_426)));
                    }
                }
            }
        }
    }
    step_hash(383);
    (*l_558) = func_70((7L || g_292));
    step_hash(384);
    (*l_431) = &g_85;
    step_hash(385);
    return p_29;
}
static short func_42(unsigned p_43)
{
    int *l_46 = &g_41;
    int *l_55 = &g_56;
    signed char l_311 = 0xF8L;
    int *l_338 = &g_56;
    step_hash(9);
    (*l_55) |= (((((signed char)p_43 - (signed char)p_43) && ((((void*)0 == l_46) == func_47((*l_46))) != ((unsigned char)((unsigned char)0x20L + (unsigned char)((&l_46 == (void*)0) && 4UL)) >> (unsigned char)g_23))) ^ g_41) > p_43);
    step_hash(263);
    if (g_56)
    {
        int *l_302 = &g_85;
        int **l_317 = &l_46;
        int l_323 = (-4L);
        int l_341 = 0x2BC84132L;
        step_hash(213);
        (*l_46) = (func_57(g_23, (*l_46), g_61) == func_47(g_292));
        step_hash(214);
        (*g_61) = l_302;
        step_hash(254);
        if (((unsigned char)((signed char)(((unsigned char)((short)g_85 * (short)(func_47((**g_82)) && g_85)) / (unsigned char)1UL) < (*l_55)) * (signed char)g_23) << (unsigned char)(*l_302)))
        {
            step_hash(220);
            for (g_56 = 0; (g_56 <= 29); g_56 += 5)
            {
                step_hash(219);
                (*g_82) = (*g_82);
            }
        }
        else
        {
            unsigned l_331 = 4294967288UL;
            unsigned l_332 = 0x0A378391L;
            int l_335 = 0xB1705E1AL;
            int **l_357 = (void*)0;
            step_hash(253);
            for (g_56 = (-26); (g_56 <= (-20)); g_56++)
            {
                int ***l_316 = (void*)0;
                int l_330 = 0x0F2C8688L;
                step_hash(225);
                l_317 = func_70(p_43);
                step_hash(238);
                if (func_65(p_43, &l_302, l_46, g_249))
                {
                    int **l_322 = &l_46;
                    int *l_326 = (void*)0;
                    int *l_327 = &g_249;
                    step_hash(227);
                    (*l_327) ^= ((unsigned short)(((((unsigned short)func_65(((*g_82) != l_46), l_322, (*g_82), (((**l_322) || ((+(((func_47(l_323) == 1L) != ((short)(*l_46) * (short)(-1L))) == g_41)) != p_43)) && (**l_322))) * (unsigned short)g_23) <= (*l_302)) > (*l_302)) || 2L) / (unsigned short)0x9F01L);
                    step_hash(228);
                    l_335 = ((unsigned short)((l_330 > ((~(g_85 | p_43)) >= l_331)) | l_332) - (unsigned short)(((void*)0 == &g_61) != ((signed char)(*l_302) * (signed char)(func_47((*g_62)) > g_56))));
                    step_hash(229);
                    (*g_82) = l_55;
                }
                else
                {
                    step_hash(235);
                    for (g_292 = 0; (g_292 <= 1); g_292 += 2)
                    {
                        step_hash(234);
                        (**g_61) = (1L != func_47((**g_82)));
                    }
                    step_hash(236);
                    (**g_82) |= l_331;
                    step_hash(237);
                    (*g_61) = &l_335;
                }
                step_hash(252);
                if (((l_338 != &l_335) && (((unsigned short)((l_341 == ((*l_302) < (-1L))) || g_56) % (unsigned short)(-6L)) == ((short)func_47((+p_43)) >> (short)g_85))))
                {
                    step_hash(240);
                    (*l_46) = (g_292 < (&g_83 != (void*)0));
                }
                else
                {
                    int *l_344 = &l_323;
                    step_hash(242);
                    (*l_317) = l_344;
                    step_hash(249);
                    if ((**g_82))
                    {
                        step_hash(244);
                        (*g_62) |= ((unsigned short)(((((short)((short)((short)g_23 >> (short)((unsigned short)((&g_62 == &l_344) == (p_43 >= ((p_43 ^ ((signed char)p_43 << (signed char)func_47((*g_83)))) > ((void*)0 != l_357)))) << (unsigned short)p_43)) * (short)0L) << (short)g_41) & (**l_317)) >= g_23) != 4294967292UL) >> (unsigned short)(*l_344));
                    }
                    else
                    {
                        int *l_364 = &g_56;
                        step_hash(246);
                        (*l_317) = (*l_317);
                        step_hash(247);
                        (*g_82) = l_46;
                        step_hash(248);
                        (*l_344) &= (((unsigned short)0x4A37L - (unsigned short)func_47((255UL & ((unsigned short)((((unsigned char)(p_43 != (0xD21DL & ((((*g_82) != l_364) && (0x6BL && (((short)0x858BL << (short)8) < (*l_302)))) == p_43))) << (unsigned char)1) >= (**g_61)) != 65533UL) << (unsigned short)(*l_364))))) < (*l_55));
                    }
                    step_hash(250);
                    (**l_317) = ((*l_317) != l_46);
                    step_hash(251);
                    l_344 = (void*)0;
                }
            }
        }
    }
    else
    {
        step_hash(256);
        (*l_55) ^= (*l_46);
        step_hash(261);
        for (g_249 = (-24); (g_249 <= 21); g_249 += 4)
        {
            step_hash(260);
            (*g_61) = (*g_82);
        }
        step_hash(262);
        return p_43;
    }
    step_hash(264);
    g_41 &= (*l_55);
    step_hash(265);
    return g_292;
}
static int func_47(int p_48)
{
    int *l_50 = &g_41;
    int **l_49 = &l_50;
    step_hash(7);
    (*l_49) = &p_48;
    step_hash(8);
    return p_48;
}
static short func_57(unsigned p_58, unsigned short p_59, int ** p_60)
{
    signed char l_271 = (-1L);
    int **l_272 = &g_62;
    step_hash(199);
    if (func_47((**p_60)))
    {
        step_hash(184);
        (*g_62) = (((unsigned short)func_47((**p_60)) + (unsigned short)(7L | func_65((g_41 == ((void*)0 != (*g_61))), func_70(g_23), (*g_61), g_56))) | p_59);
    }
    else
    {
        int l_273 = 0x87AE2D5EL;
        step_hash(191);
        if (func_47((g_56 <= ((signed char)((signed char)(((unsigned short)(0x3143DF59L != ((**p_60) < (p_58 != 0x210DL))) * (unsigned short)((int)(**p_60) - (int)((0xFA0A2640L && func_65(l_271, l_272, (*g_61), l_273)) & g_23))) > 0xD5L) << (signed char)4) << (signed char)5))))
        {
            step_hash(187);
            (*p_60) = (*l_272);
            step_hash(188);
            (**g_61) |= 0L;
        }
        else
        {
            step_hash(190);
            return g_23;
        }
        step_hash(197);
        for (g_41 = (-14); (g_41 > (-26)); g_41 -= 7)
        {
            int ***l_276 = (void*)0;
            int ***l_277 = &g_61;
            step_hash(195);
            (**p_60) = (*g_62);
            step_hash(196);
            (*l_277) = &g_62;
        }
        step_hash(198);
        return p_58;
    }
    step_hash(211);
    if ((*g_83))
    {
        step_hash(201);
        (*l_272) = (*g_61);
    }
    else
    {
        step_hash(203);
        (*g_82) = (*g_82);
        step_hash(208);
        for (p_59 = 0; (p_59 > 52); ++p_59)
        {
            unsigned short l_293 = 65535UL;
            step_hash(207);
            (**l_272) = ((short)((signed char)((**l_272) < ((signed char)((signed char)(**l_272) << (signed char)3) + (signed char)p_59)) >> (signed char)7) * (short)(((((unsigned char)((unsigned short)((func_65(((-1L) < ((void*)0 != (*p_60))), func_70(g_85), (*p_60), g_292) || 4294967295UL) && 0xE1FB2BD5L) + (unsigned short)g_249) - (unsigned char)(-1L)) && (**l_272)) & l_293) && g_41));
        }
        step_hash(209);
        (*g_82) = (*l_272);
        step_hash(210);
        (**g_61) = ((0UL || ((signed char)((p_59 || g_292) && 0x782E8E32L) + (signed char)255UL)) || ((0x99E0L >= ((unsigned)4294967293UL / (unsigned)(p_59 ^ ((unsigned short)((short)((&g_62 != (void*)0) && g_56) / (short)g_85) * (unsigned short)p_59)))) < (**g_61)));
    }
    step_hash(212);
    return g_56;
}
static unsigned short func_65(unsigned short p_66, int ** p_67, int * p_68, unsigned char p_69)
{
    step_hash(181);
    (*g_82) = (*p_67);
    step_hash(182);
    (*g_82) = (*p_67);
    step_hash(183);
    return p_66;
}
static int ** func_70(unsigned short p_71)
{
    unsigned l_77 = 4294967287UL;
    int *l_84 = &g_85;
    int l_179 = 0xBAF4236FL;
    int *l_233 = &l_179;
    int **l_262 = (void*)0;
    step_hash(177);
    for (p_71 = 6; (p_71 == 29); ++p_71)
    {
        int l_76 = 8L;
        int *l_90 = &g_85;
        unsigned l_152 = 0UL;
        unsigned char l_153 = 0xA6L;
        int *l_174 = &l_76;
        unsigned l_201 = 4294967295UL;
    }
    step_hash(178);
    (*l_233) |= ((unsigned short)g_41 + (unsigned short)func_47((l_262 == &l_84)));
    step_hash(179);
    return &g_83;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_23, "g_23", print_hash_value);
    transparent_crc(g_41, "g_41", print_hash_value);
    transparent_crc(g_56, "g_56", print_hash_value);
    transparent_crc(g_85, "g_85", print_hash_value);
    transparent_crc(g_249, "g_249", print_hash_value);
    transparent_crc(g_292, "g_292", print_hash_value);
    transparent_crc(g_533, "g_533", print_hash_value);
    transparent_crc(g_574, "g_574", print_hash_value);
    transparent_crc(g_805, "g_805", print_hash_value);
    transparent_crc(g_862, "g_862", print_hash_value);
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
