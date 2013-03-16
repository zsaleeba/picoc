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
static int g_3 = 0xD06CE125L;
static int *g_2 = &g_3;
static int g_38 = 0xF1BD53D2L;
static int g_86 = 0x3070B7B2L;
static unsigned g_98 = 0x95FF7D1DL;
static int **g_156 = (void*)0;
static unsigned short g_425 = 0xE9ACL;
static unsigned short g_523 = 1UL;
static short g_538 = (-1L);
static unsigned g_734 = 0x13C2BE4AL;
static int g_745 = 1L;
static unsigned g_821 = 0x7DC50229L;
static unsigned g_856 = 4294967294UL;
static int g_881 = 0x3A18B297L;
static unsigned char g_913 = 0xE8L;
static int g_993 = 0x880C4392L;
static short func_1(void);
static unsigned func_12(unsigned short p_13);
static short func_16(int * p_17, unsigned p_18, short p_19, int ** p_20);
static unsigned func_33(short p_34);
static int func_39(int p_40, unsigned p_41, int * p_42, int * p_43);
static int func_44(unsigned char p_45, int p_46, unsigned char p_47);
static unsigned short func_50(int p_51, int p_52);
static short func_56(unsigned p_57, int ** p_58, int * p_59);
static int ** func_60(int * p_61, short p_62, unsigned short p_63, int p_64);
static int * func_65(unsigned short p_66, int ** p_67, int p_68, unsigned p_69);
static short func_1(void)
{
    int **l_4 = (void*)0;
    step_hash(1);
    g_2 = g_2;
    step_hash(604);
    for (g_3 = 0; (g_3 <= (-20)); g_3--)
    {
        int *l_11 = &g_3;
        int *l_991 = (void*)0;
        int *l_992 = &g_993;
    }
    step_hash(605);
    return g_856;
}
static unsigned func_12(unsigned short p_13)
{
    unsigned short l_21 = 0x6CD3L;
    int *l_24 = (void*)0;
    unsigned l_733 = 0x16980C13L;
    int l_751 = 1L;
    int l_784 = 0x746624E7L;
    int ***l_882 = &g_156;
    int *l_934 = (void*)0;
    int *l_982 = (void*)0;
    int l_988 = 0x50850311L;
    step_hash(588);
    if ((((signed char)(func_16(&g_3, g_3, ((l_21 == ((signed char)g_3 << (signed char)((((l_24 == &g_3) >= (g_3 || ((unsigned char)((unsigned short)p_13 / (unsigned short)9UL) / (unsigned char)g_3))) ^ 5L) == g_3))) == g_3), &g_2) && (-1L)) >> (signed char)g_538) && 0L))
    {
        unsigned l_735 = 1UL;
        int l_743 = 7L;
        int l_766 = 7L;
        int **l_768 = &l_24;
        int ***l_769 = &g_156;
        short l_927 = 0x12A5L;
        int l_965 = 0x6B36D099L;
        step_hash(461);
        if (((&g_2 != &l_24) == ((int)g_538 / (int)((unsigned short)((unsigned char)(l_24 != &g_86) >> (unsigned char)2) - (unsigned short)(-(unsigned)p_13)))))
        {
            short l_742 = 6L;
            step_hash(436);
            if (((short)l_733 - (short)g_734))
            {
                int l_744 = 1L;
                step_hash(432);
                l_735 = (0x6308L <= (g_38 == ((void*)0 != l_24)));
                step_hash(433);
                l_744 ^= ((unsigned char)p_13 - (unsigned char)((0xCFL > ((signed char)((unsigned char)((((l_735 | g_86) && p_13) > l_742) | (p_13 & p_13)) % (unsigned char)l_743) * (signed char)0L)) < p_13));
            }
            else
            {
                step_hash(435);
                l_743 = p_13;
            }
            step_hash(437);
            g_38 &= l_743;
        }
        else
        {
            int l_757 = (-1L);
            int *l_767 = &g_86;
            int ***l_770 = &l_768;
            step_hash(458);
            for (g_745 = 15; (g_745 != 28); ++g_745)
            {
                step_hash(454);
                for (g_86 = 0; (g_86 >= 6); ++g_86)
                {
                    int l_750 = 0xEBCB6B0AL;
                    int l_752 = 9L;
                    step_hash(445);
                    l_751 &= l_750;
                    step_hash(446);
                    l_752 = p_13;
                    step_hash(453);
                    for (l_743 = (-30); (l_743 == (-21)); ++l_743)
                    {
                        int *l_755 = &g_38;
                        int *l_756 = &l_752;
                        step_hash(450);
                        l_755 = (void*)0;
                        step_hash(451);
                        (*l_756) = (~p_13);
                        step_hash(452);
                        if (p_13)
                            continue;
                    }
                }
                step_hash(455);
                g_86 ^= l_735;
                step_hash(456);
                l_743 = l_757;
                step_hash(457);
                if (p_13)
                    continue;
            }
            step_hash(459);
            (*l_767) &= ((signed char)((l_735 == (p_13 > (g_425 == (((signed char)p_13 % (signed char)(((unsigned char)p_13 >> (unsigned char)l_735) ^ (p_13 == p_13))) & l_743)))) & p_13) >> (signed char)l_766);
            step_hash(460);
            (**l_770) = func_65(p_13, &g_2, (l_769 == l_770), (1UL <= (g_425 & p_13)));
        }
        step_hash(462);
        l_24 = &l_751;
        step_hash(506);
        for (p_13 = (-19); (p_13 != 30); p_13 += 7)
        {
            int *l_775 = &l_743;
            int l_786 = 0x1B94D879L;
            int **l_832 = (void*)0;
            int *l_846 = &l_743;
        }
        step_hash(579);
        if (p_13)
        {
            int **l_857 = &g_2;
            unsigned l_898 = 9UL;
            int l_919 = 1L;
            step_hash(527);
            for (g_523 = 8; (g_523 >= 44); ++g_523)
            {
                int ***l_852 = &g_156;
                step_hash(526);
                for (g_538 = 0; (g_538 != (-2)); --g_538)
                {
                    int *l_853 = (void*)0;
                }
            }
            step_hash(553);
            if (p_13)
            {
                step_hash(529);
                (**l_768) = (-(int)(p_13 != p_13));
                step_hash(530);
                (*l_24) = (((!(*l_24)) ^ g_881) && (l_882 != &g_156));
            }
            else
            {
                int *l_897 = &g_3;
                step_hash(532);
                (*l_768) = (*l_768);
                step_hash(533);
                (**l_768) = 0L;
                step_hash(538);
                if (((signed char)((+p_13) == ((unsigned char)(((((unsigned short)0UL >> (unsigned short)12) <= (&g_86 != (void*)0)) ^ ((unsigned)(func_39((p_13 == ((short)p_13 % (short)((signed char)((((l_857 != (*l_769)) & ((**l_768) && g_881)) < 4UL) > p_13) << (signed char)(**l_768)))), p_13, &g_3, l_897) == g_745) / (unsigned)0x798682BBL)) ^ g_538) * (unsigned char)g_881)) * (signed char)g_856))
                {
                    step_hash(535);
                    (**l_768) &= ((g_821 >= (*l_897)) >= l_898);
                }
                else
                {
                    step_hash(537);
                    return g_734;
                }
                step_hash(552);
                if (((p_13 >= p_13) | p_13))
                {
                    int *l_918 = &l_751;
                    int *l_920 = &l_743;
                    step_hash(540);
                    (*l_920) |= ((short)((unsigned short)((short)((unsigned char)g_821 << (unsigned char)(((int)(((g_913 != ((int)((int)func_39((0x35L > p_13), p_13, (*l_768), l_918) / (int)9L) % (int)g_745)) < l_919) || g_523) + (int)p_13) != g_881)) * (short)0UL) << (unsigned short)g_734) >> (short)p_13);
                    step_hash(541);
                    (*l_920) ^= (*l_24);
                }
                else
                {
                    step_hash(543);
                    (*l_24) = (**l_768);
                    step_hash(549);
                    if ((*l_897))
                    {
                        step_hash(545);
                        return (*l_897);
                    }
                    else
                    {
                        unsigned l_925 = 0UL;
                        int *l_926 = (void*)0;
                        step_hash(547);
                        (**l_768) = l_925;
                        step_hash(548);
                        (*l_857) = l_926;
                    }
                    step_hash(550);
                    (**l_768) |= p_13;
                    step_hash(551);
                    (**l_768) = p_13;
                }
            }
        }
        else
        {
            int *l_929 = &g_86;
            int *l_938 = &l_784;
            int ***l_944 = &g_156;
            step_hash(555);
            l_927 ^= p_13;
            step_hash(571);
            if (p_13)
            {
                int l_928 = (-3L);
                int **l_937 = &l_934;
                step_hash(567);
                if (((~((p_13 < (~l_928)) != ((l_929 == &g_38) || ((short)(((unsigned)0UL * (unsigned)(func_39(p_13, (g_98 > g_913), l_938, (*l_937)) > g_425)) || 2L) << (short)2)))) && 6L))
                {
                    step_hash(562);
                    for (g_98 = 0; (g_98 > 38); ++g_98)
                    {
                        step_hash(561);
                        return g_425;
                    }
                    step_hash(563);
                    (**l_768) ^= ((signed char)g_425 + (signed char)p_13);
                }
                else
                {
                    int ***l_943 = &l_937;
                    int l_945 = (-1L);
                    step_hash(565);
                    (*l_24) = ((*l_24) | (((l_943 == l_944) > l_945) ^ ((unsigned char)((unsigned)0UL + (unsigned)(((short)p_13 + (short)(*l_938)) >= ((g_86 & p_13) == g_881))) - (unsigned char)(*l_24))));
                    step_hash(566);
                    (*l_938) = (*l_938);
                }
            }
            else
            {
                step_hash(569);
                (*l_24) &= (g_856 >= g_734);
                step_hash(570);
                return g_734;
            }
            step_hash(578);
            if ((((short)g_881 * (short)p_13) <= g_856))
            {
                int *l_958 = &l_743;
                step_hash(573);
                (*l_929) = (p_13 >= (-7L));
                step_hash(574);
                (**l_768) = (func_39(((short)(((&g_2 != (*l_944)) < (+(*l_958))) < (+((unsigned short)(0x82L >= ((signed char)l_965 << (signed char)p_13)) * (unsigned short)(g_856 == ((((((*l_929) ^ (-2L)) != p_13) >= p_13) == p_13) || 0x43L))))) >> (short)p_13), g_98, l_958, l_958) ^ g_856);
                step_hash(575);
                return p_13;
            }
            else
            {
                step_hash(577);
                g_38 &= func_39(g_734, (**l_768), (*l_768), &g_3);
            }
        }
    }
    else
    {
        int ***l_968 = &g_156;
        int l_976 = 0x04754667L;
        int *l_977 = &g_86;
        step_hash(581);
        (*l_977) = (p_13 | ((short)((g_538 | (l_882 != l_968)) == ((g_3 && ((unsigned)((g_98 >= ((signed char)((-(unsigned char)((signed char)((void*)0 != l_882) * (signed char)g_881)) ^ 0L) + (signed char)l_976)) > p_13) + (unsigned)p_13)) >= p_13)) << (short)12));
        step_hash(582);
        (*l_882) = (*l_882);
        step_hash(587);
        for (g_821 = (-25); (g_821 == 5); g_821 += 4)
        {
            step_hash(586);
            l_751 = g_881;
        }
    }
    step_hash(589);
    g_2 = &g_86;
    step_hash(590);
    l_751 ^= (*g_2);
    step_hash(601);
    for (g_38 = 28; (g_38 > 0); g_38--)
    {
        int l_987 = 4L;
        step_hash(594);
        (*l_882) = func_60(&l_987, p_13, (+g_821), l_988);
        step_hash(595);
        (*g_2) = 0xF91D216FL;
        step_hash(600);
        for (g_856 = 0; (g_856 > 11); g_856 += 6)
        {
            step_hash(599);
            l_987 = p_13;
        }
    }
    step_hash(602);
    return p_13;
}
static short func_16(int * p_17, unsigned p_18, short p_19, int ** p_20)
{
    unsigned char l_35 = 1UL;
    int **l_379 = (void*)0;
    int *l_380 = &g_38;
    signed char l_396 = 0xE3L;
    short l_414 = 0x82E2L;
    unsigned char l_461 = 0xB8L;
    int *l_484 = &g_86;
    int l_508 = 0xE1AC01B0L;
    int l_578 = 1L;
    unsigned short l_597 = 0x878AL;
    unsigned char l_638 = 0x70L;
    int ***l_643 = &g_156;
    int l_680 = 0L;
    int *l_695 = &g_3;
    signed char l_698 = 0x66L;
    unsigned l_709 = 0UL;
    unsigned l_714 = 0UL;
    int **l_718 = (void*)0;
    step_hash(209);
    (*l_380) = ((short)((unsigned)func_33((0x23L | l_35)) / (unsigned)(g_3 || ((l_379 == &p_17) <= (-1L)))) << (short)g_3);
    step_hash(221);
    if (func_39(((*l_380) != func_39(g_86, g_98, &g_3, &g_38)), ((p_18 < (&l_380 == &p_17)) == g_98), l_380, l_380))
    {
        step_hash(217);
        for (p_19 = (-4); (p_19 >= 22); p_19 += 5)
        {
            unsigned l_387 = 0UL;
            step_hash(214);
            (*l_380) = ((unsigned char)((*l_380) ^ 0xCCF848ACL) + (unsigned char)0x6EL);
            step_hash(215);
            (*l_380) = l_387;
            step_hash(216);
            return g_86;
        }
    }
    else
    {
        step_hash(219);
        (*p_20) = func_65(g_86, &p_17, (((*p_17) <= (((short)((short)((unsigned char)func_56(p_19, &l_380, &g_38) * (unsigned char)0x87L) - (short)(g_86 < p_18)) >> (short)13) != (*p_17))) | g_3), p_19);
        step_hash(220);
        (*p_20) = func_65((((short)(&l_379 == (void*)0) << (short)(g_38 <= p_18)) & (((!p_19) ^ 0x7B48L) | (g_3 ^ p_18))), func_60((*p_20), g_98, p_18, p_18), l_396, (*l_380));
    }
    step_hash(405);
    if (((unsigned char)g_38 * (unsigned char)(65526UL && func_39(((short)(((unsigned short)((*p_17) != func_39(g_86, p_19, p_17, l_380)) / (unsigned short)(*l_380)) < (*l_380)) % (short)p_18), (*l_380), p_17, p_17))))
    {
        unsigned l_413 = 1UL;
        int l_435 = 0xE4F0868AL;
        unsigned char l_517 = 2UL;
        step_hash(295);
        if ((((short)((unsigned short)(((unsigned short)g_3 * (unsigned short)((int)(-1L) % (int)(~(((void*)0 != &l_380) == ((+0xB1F27604L) < (g_38 && g_98)))))) | 7UL) << (unsigned short)g_38) >> (short)l_413) || l_413))
        {
            unsigned short l_419 = 0xB5DCL;
            int *l_424 = &g_3;
            step_hash(224);
            g_425 &= (0x7F213C8FL & (((short)((unsigned short)l_413 >> (unsigned short)(l_419 == ((int)((&g_2 != &p_17) ^ ((unsigned short)func_39((*l_380), g_98, l_424, &g_38) >> (unsigned short)1)) + (int)(*p_17)))) - (short)p_19) && p_19));
            step_hash(238);
            for (p_19 = 25; (p_19 < 15); p_19 -= 5)
            {
                signed char l_436 = 0L;
                int l_437 = 0L;
                step_hash(228);
                if ((*l_424))
                    break;
                step_hash(237);
                if ((*p_17))
                {
                    int l_432 = 0xB34B1CFBL;
                    step_hash(230);
                    l_432 = (((unsigned short)g_3 * (unsigned short)9UL) != ((((signed char)(g_425 ^ g_38) / (signed char)((p_18 < p_19) ^ ((*l_424) & l_432))) < ((unsigned)g_3 - (unsigned)0x47465895L)) || 0x7293L));
                    step_hash(231);
                    (*l_380) = (*p_17);
                    step_hash(232);
                    (*l_380) &= l_432;
                }
                else
                {
                    step_hash(234);
                    (*l_380) ^= 0x540DDE23L;
                    step_hash(235);
                    l_435 &= (*l_380);
                    step_hash(236);
                    l_437 = l_436;
                }
            }
            step_hash(239);
            return p_18;
        }
        else
        {
            unsigned short l_448 = 8UL;
            int *l_454 = &l_435;
            int l_462 = 0x403AEF32L;
            int l_464 = 0x08B37DB9L;
            step_hash(272);
            for (g_425 = (-2); (g_425 == 26); g_425 += 6)
            {
                int **l_442 = &g_2;
                step_hash(244);
                (*l_380) = (g_86 || p_18);
                step_hash(270);
                if (((unsigned char)(l_442 != (void*)0) >> (unsigned char)((unsigned short)(-(int)(*p_17)) / (unsigned short)((signed char)l_448 % (signed char)((signed char)1L >> (signed char)6)))))
                {
                    unsigned l_453 = 0x2CAB4327L;
                    int *l_463 = &g_3;
                    step_hash(253);
                    if (((signed char)p_18 * (signed char)(g_425 ^ l_453)))
                    {
                        step_hash(247);
                        (*l_380) = (*p_17);
                        step_hash(248);
                        (*l_442) = l_454;
                        step_hash(249);
                        (*g_2) = ((void*)0 == &p_17);
                        step_hash(250);
                        l_464 |= (g_425 == (func_56(((unsigned short)g_425 + (unsigned short)(((signed char)func_39((((short)(**l_442) * (short)p_19) == g_38), (l_461 > 1UL), (*p_20), (*p_20)) / (signed char)p_18) == l_462)), l_442, l_463) || l_413));
                    }
                    else
                    {
                        step_hash(252);
                        (*p_20) = func_65((*l_454), &g_2, (*p_17), ((signed char)l_413 / (signed char)((signed char)((-1L) | (~((unsigned)p_18 - (unsigned)0x334A0F4AL))) >> (signed char)0)));
                    }
                    step_hash(259);
                    for (l_448 = 28; (l_448 >= 18); l_448 -= 2)
                    {
                        int l_473 = 0xC80864EDL;
                        step_hash(257);
                        (*p_20) = (*p_20);
                        step_hash(258);
                        if (l_473)
                            break;
                    }
                    step_hash(265);
                    for (g_98 = 0; (g_98 > 11); g_98++)
                    {
                        step_hash(263);
                        (*l_454) = ((+((short)p_19 - (short)g_38)) != (((void*)0 == &p_20) ^ (**l_442)));
                        step_hash(264);
                        l_464 ^= (**p_20);
                    }
                    step_hash(266);
                    (*g_2) = (~((void*)0 == &l_464));
                }
                else
                {
                    unsigned l_483 = 1UL;
                    step_hash(268);
                    l_483 ^= (-(int)((unsigned char)p_18 + (unsigned char)((0x403EL <= ((short)p_18 << (short)2)) < l_435)));
                    step_hash(269);
                    (*l_454) = ((&l_435 != l_484) | 0UL);
                }
                step_hash(271);
                (*l_454) = (*p_17);
            }
            step_hash(277);
            if (((short)l_435 * (short)((void*)0 != &g_2)))
            {
                step_hash(274);
                (*l_484) &= (*l_380);
            }
            else
            {
                int **l_487 = (void*)0;
                step_hash(276);
                (*l_454) ^= (p_18 < ((&p_17 == l_487) != ((void*)0 != &p_20)));
            }
            step_hash(278);
            (*l_380) ^= 0xDB40869AL;
            step_hash(294);
            if (((short)p_19 >> (short)(*l_454)))
            {
                int l_492 = 0x9F55045BL;
                step_hash(280);
                (*l_484) = ((signed char)((p_19 && (-7L)) ^ l_492) * (signed char)p_18);
            }
            else
            {
                unsigned short l_495 = 1UL;
                step_hash(293);
                for (g_38 = (-14); (g_38 < 10); g_38++)
                {
                    step_hash(285);
                    l_495 &= 0x0654CC57L;
                    step_hash(286);
                    (*l_484) = ((short)p_18 << (short)3);
                    step_hash(287);
                    (*l_454) = l_435;
                    step_hash(292);
                    for (g_86 = (-14); (g_86 <= 23); g_86 += 5)
                    {
                        step_hash(291);
                        (*l_454) |= (-7L);
                    }
                }
            }
        }
        step_hash(296);
        (*p_20) = func_65(l_435, func_60(p_17, l_413, g_86, (l_484 == &g_86)), (((unsigned char)(((short)0x3DE3L + (short)((unsigned short)1UL + (unsigned short)0x2EB6L)) != p_18) >> (unsigned char)2) <= 7L), g_98);
        step_hash(340);
        for (g_86 = 23; (g_86 == 4); --g_86)
        {
            int l_526 = (-6L);
            unsigned short l_556 = 65535UL;
            int **l_564 = &l_484;
            step_hash(300);
            (**p_20) |= (((p_18 ^ p_19) >= g_86) >= g_425);
            step_hash(301);
            (*p_20) = (*p_20);
            step_hash(302);
            (*g_2) ^= ((-1L) != (l_508 ^ 0x480A30C7L));
            step_hash(339);
            for (p_18 = 0; (p_18 <= 21); p_18 += 3)
            {
                int l_522 = (-6L);
                int *l_546 = (void*)0;
                int *l_565 = &l_435;
            }
        }
    }
    else
    {
        unsigned char l_570 = 4UL;
        int *l_581 = &g_38;
        unsigned char l_592 = 0x6BL;
        unsigned l_621 = 9UL;
        unsigned l_666 = 1UL;
        step_hash(342);
        (*l_380) = (*l_380);
        step_hash(365);
        if ((*l_484))
        {
            step_hash(344);
            (*p_20) = &g_86;
            step_hash(345);
            (*l_484) = (((short)(-7L) * (short)(0xB7725D2CL == (*p_17))) || (0xC6L ^ g_425));
            step_hash(346);
            (*l_380) = ((((unsigned short)g_538 + (unsigned short)g_3) <= func_33((0x48001EC9L != l_570))) < g_538);
        }
        else
        {
            short l_571 = 0x78A1L;
            int *l_582 = &g_3;
            int l_618 = 0x74680034L;
            step_hash(348);
            (*l_484) = l_571;
            step_hash(363);
            if (func_39((0x808EL <= p_19), ((unsigned char)((unsigned char)((unsigned)l_578 + (unsigned)((*p_17) ^ (*l_380))) / (unsigned char)p_19) << (unsigned char)func_39((l_570 | ((*l_484) != (((short)p_18 / (short)(*l_380)) == (*l_380)))), l_571, l_581, &g_3)), &g_3, l_582))
            {
                int l_589 = 0xE61D6F7EL;
                int l_598 = (-3L);
                step_hash(350);
                (*p_20) = func_65(p_19, &g_2, ((short)(&g_156 == &p_20) + (short)((((signed char)(~((*p_17) && (-1L))) + (signed char)((unsigned short)(p_18 | ((((p_18 < p_19) ^ 0xF98FL) & l_589) <= g_3)) * (unsigned short)p_19)) >= 2UL) & g_425)), g_538);
                step_hash(351);
                l_598 ^= (p_19 & (func_33(l_589) == ((unsigned char)l_592 * (unsigned char)((short)g_425 + (short)((p_18 & ((((void*)0 != &g_3) > ((unsigned short)g_523 % (unsigned short)l_597)) != p_18)) >= 0xECF334D7L)))));
                step_hash(352);
                (*l_380) = ((short)(0L <= (!g_523)) % (short)((l_598 != ((unsigned short)(*l_581) >> (unsigned short)2)) | ((short)(~g_3) - (short)(p_19 != (((8L && 0x2914B7B7L) && 0xCBL) != 1UL)))));
            }
            else
            {
                int *l_605 = (void*)0;
                step_hash(360);
                if ((l_605 != (void*)0))
                {
                    signed char l_613 = 3L;
                    step_hash(355);
                    (*l_484) = ((-(short)(&p_20 == &p_20)) < ((unsigned short)(p_19 & l_618) - (unsigned short)0UL));
                    step_hash(356);
                    (*l_581) = ((unsigned char)g_523 + (unsigned char)(&g_86 != &g_38));
                    step_hash(357);
                    l_621 = (&l_582 != (void*)0);
                }
                else
                {
                    int *l_622 = &l_618;
                    step_hash(359);
                    (*p_20) = l_622;
                }
                step_hash(361);
                (*l_380) ^= (*p_17);
                step_hash(362);
                (*l_484) ^= (*l_581);
            }
            step_hash(364);
            (*l_484) |= ((unsigned char)0xBFL >> (unsigned char)((-10L) || p_18));
        }
        step_hash(404);
        for (p_19 = 0; (p_19 != (-13)); p_19--)
        {
            unsigned l_631 = 0xB7781D03L;
            int *l_632 = &g_3;
            unsigned l_633 = 0x9A701622L;
            unsigned l_644 = 0xC9DFD282L;
            step_hash(385);
            if (((unsigned char)(*l_581) - (unsigned char)((signed char)((void*)0 != p_17) << (signed char)((func_39(func_39(l_631, g_3, l_632, func_65((*l_484), &p_17, (*l_632), (*l_632))), p_18, l_581, l_632) >= l_633) && g_98))))
            {
                int l_642 = 0xE8C3C605L;
                step_hash(382);
                if (((0L && ((**p_20) && (p_18 ^ (g_523 == func_33(p_19))))) ^ g_538))
                {
                    unsigned l_641 = 0x1585EEB9L;
                    step_hash(371);
                    (*l_581) ^= (((void*)0 == &p_17) < ((unsigned char)g_523 >> (unsigned char)g_3));
                    step_hash(376);
                    for (l_396 = (-10); (l_396 != 21); ++l_396)
                    {
                        unsigned l_649 = 6UL;
                        step_hash(375);
                        (*l_380) |= (+(((signed char)(l_641 | (*l_632)) % (signed char)l_649) >= (((unsigned short)((~((short)(p_18 == (!(-1L))) % (short)p_18)) & (*l_632)) - (unsigned short)(~l_641)) != ((unsigned short)((((short)g_86 + (short)0UL) & 8UL) || 0xCEL) + (unsigned short)p_18))));
                    }
                    step_hash(377);
                    (*l_581) = (((short)((unsigned char)0x9AL / (unsigned char)(-3L)) * (short)g_98) > ((&g_156 == (void*)0) > ((((unsigned char)((short)(&g_156 == (void*)0) % (short)func_39(g_98, p_19, l_581, &g_86)) % (unsigned char)0x72L) < l_666) && 0x04A5L)));
                    step_hash(378);
                    (*p_20) = &g_3;
                }
                else
                {
                    int **l_667 = &l_484;
                    step_hash(380);
                    (*p_20) = func_65(p_19, l_667, (*p_17), ((int)(((int)(**l_667) - (int)((short)p_18 << (short)(p_19 <= ((unsigned char)(!((unsigned short)(*l_581) / (unsigned short)(p_19 & (&g_38 != &l_642)))) << (unsigned char)l_642)))) <= (**l_667)) / (int)1UL));
                    step_hash(381);
                    if ((*g_2))
                        continue;
                }
            }
            else
            {
                step_hash(384);
                (*l_484) = (**p_20);
            }
            step_hash(386);
            (*l_484) |= 0x190E59D4L;
            step_hash(403);
            if ((g_98 > (*l_380)))
            {
                int *l_678 = &g_3;
                int *l_679 = &g_86;
                step_hash(388);
                g_2 = (*p_20);
                step_hash(389);
                if ((*g_2))
                    continue;
                step_hash(390);
                l_679 = l_678;
            }
            else
            {
                unsigned l_691 = 0xA227C0C2L;
                short l_694 = 1L;
                step_hash(402);
                if (((l_680 == func_39(((unsigned char)(*l_484) * (unsigned char)((((int)(*l_581) + (int)((*p_20) == l_632)) >= (**p_20)) ^ (((unsigned short)((unsigned char)((unsigned)g_425 % (unsigned)(((void*)0 == &p_20) || g_86)) % (unsigned char)0x80L) + (unsigned short)(*l_581)) <= 0xBA1A62BAL))), g_3, (*p_20), (*p_20))) >= l_691))
                {
                    step_hash(393);
                    if ((*g_2))
                        break;
                }
                else
                {
                    step_hash(401);
                    for (l_35 = 4; (l_35 <= 53); l_35 += 5)
                    {
                        step_hash(398);
                        (*l_581) ^= ((-1L) | p_18);
                        step_hash(399);
                        (*p_20) = (*p_20);
                        step_hash(400);
                        return l_694;
                    }
                }
            }
        }
    }
    step_hash(427);
    if (((~func_39(g_425, (*l_484), l_695, p_17)) >= 0xE6F3L))
    {
        unsigned short l_708 = 0x14C5L;
        int l_719 = 0xBBFDEA44L;
        step_hash(414);
        if ((*p_17))
        {
            step_hash(408);
            l_698 = (0xBD081EE4L || (((&p_20 == &p_20) == ((&g_156 == &p_20) == 0L)) <= p_18));
            step_hash(409);
            (*l_484) ^= ((unsigned short)((void*)0 == &g_2) << (unsigned short)3);
        }
        else
        {
            int *l_705 = (void*)0;
            int l_710 = 0x38DC6A6FL;
            step_hash(411);
            (*l_380) = ((unsigned short)l_708 % (unsigned short)p_19);
            step_hash(412);
            l_710 = (*p_17);
            step_hash(413);
            return p_19;
        }
        step_hash(415);
        l_719 |= (-(unsigned char)((&g_2 == (void*)0) && ((unsigned)l_714 - (unsigned)(g_86 ^ g_425))));
    }
    else
    {
        unsigned l_720 = 4294967295UL;
        int l_723 = 0x934DF2BEL;
        step_hash(417);
        (*l_484) = (*p_17);
        step_hash(424);
        for (l_461 = 21; (l_461 <= 15); l_461 -= 2)
        {
            step_hash(421);
            (*p_20) = (void*)0;
            step_hash(422);
            (*l_380) = (((p_18 & (&l_718 == &p_20)) || g_538) >= 0x085AL);
            step_hash(423);
            (*l_380) = (*l_695);
        }
        step_hash(425);
        l_723 = (0L | p_18);
        step_hash(426);
        return p_18;
    }
    step_hash(428);
    return (*l_380);
}
static unsigned func_33(short p_34)
{
    unsigned char l_36 = 1UL;
    int *l_37 = &g_38;
    step_hash(8);
    (*l_37) &= l_36;
    step_hash(207);
    (*l_37) = func_39(func_44((!((short)0x9459L >> (short)func_50((*l_37), (*l_37)))), l_36, g_3), ((((void*)0 == &l_37) | 0x27E4D43CL) && g_3), &g_3, &g_3);
    step_hash(208);
    return g_86;
}
static int func_39(int p_40, unsigned p_41, int * p_42, int * p_43)
{
    int l_376 = 0xE75B7F2AL;
    int *l_377 = (void*)0;
    int **l_378 = &l_377;
    step_hash(203);
    for (g_86 = 0; (g_86 <= 14); ++g_86)
    {
        int **l_375 = &g_2;
        step_hash(202);
        (*l_375) = p_42;
    }
    step_hash(204);
    l_376 |= g_3;
    step_hash(205);
    (*l_378) = l_377;
    step_hash(206);
    return (*p_42);
}
static int func_44(unsigned char p_45, int p_46, unsigned char p_47)
{
    int *l_100 = &g_38;
    short l_117 = 0x03E5L;
    short l_171 = 9L;
    int l_172 = 0x459814C7L;
    int l_178 = (-1L);
    int *l_200 = &g_3;
    int ***l_251 = &g_156;
    int l_270 = 0xE4269A64L;
    unsigned char l_274 = 0xE2L;
    step_hash(136);
    if ((g_3 >= ((((l_100 == l_100) | (((*l_100) < (((signed char)p_47 - (signed char)((*l_100) | p_47)) ^ ((-(unsigned char)(g_86 ^ ((*g_2) > p_46))) || (*l_100)))) <= 3UL)) & p_46) & (*l_100))))
    {
        signed char l_118 = 1L;
        int **l_136 = &l_100;
        int **l_187 = &l_100;
        step_hash(121);
        if (((short)((g_38 | (2UL < ((unsigned char)p_45 >> (unsigned char)7))) || ((((unsigned)((short)((func_50(((unsigned char)(-(short)(*l_100)) >> (unsigned char)7), p_46) & (((unsigned)l_117 / (unsigned)g_3) >= p_45)) & g_3) << (short)p_46) % (unsigned)l_118) < g_3) < (-2L))) * (short)0x8A88L))
        {
            unsigned l_125 = 0UL;
            int **l_148 = &l_100;
            step_hash(59);
            if ((p_45 > ((unsigned short)((unsigned short)g_98 * (unsigned short)(((short)l_125 * (short)l_118) ^ (*l_100))) << (unsigned short)((g_3 > l_118) >= ((signed char)(((unsigned short)(7UL || (*l_100)) << (unsigned short)2) || 0x1B770899L) << (signed char)(*l_100))))))
            {
                int **l_130 = &l_100;
                step_hash(35);
                (*l_130) = &g_38;
            }
            else
            {
                int *l_154 = &g_86;
                signed char l_155 = (-1L);
                step_hash(57);
                if (func_50(p_47, (0L < g_98)))
                {
                    unsigned char l_133 = 255UL;
                    int *l_157 = &g_3;
                    step_hash(38);
                    (*l_100) = (*g_2);
                    step_hash(45);
                    if ((*l_100))
                    {
                        int **l_137 = &l_100;
                        int ***l_138 = &l_136;
                        step_hash(40);
                        (*l_138) = func_60(&g_38, func_50((*g_2), (*l_100)), (((int)(&g_3 != (void*)0) - (int)g_3) ^ l_133), (((unsigned char)(l_136 == l_137) % (unsigned char)p_46) <= g_3));
                    }
                    else
                    {
                        unsigned short l_141 = 65533UL;
                        int **l_153 = &g_2;
                        step_hash(42);
                        (*l_100) ^= (-5L);
                        step_hash(43);
                        (*l_136) = (*l_136);
                        step_hash(44);
                        (*l_154) = ((short)((l_141 != ((g_38 != 8UL) >= (**l_136))) > g_98) % (short)1UL);
                    }
                }
                else
                {
                    unsigned short l_168 = 0xB5CBL;
                    step_hash(47);
                    (*l_148) = func_65(p_47, l_148, (*l_100), ((unsigned)(((int)p_46 - (int)((unsigned short)g_3 - (unsigned short)((signed char)g_86 << (signed char)4))) && 0UL) % (unsigned)(p_45 | (((signed char)p_45 >> (signed char)g_3) && 0x32L))));
                    step_hash(48);
                    l_168 ^= ((*g_2) >= g_98);
                    step_hash(55);
                    for (g_38 = 19; (g_38 == 7); g_38 -= 6)
                    {
                        step_hash(52);
                        if (l_171)
                            break;
                        step_hash(53);
                        (*l_154) ^= (*g_2);
                        step_hash(54);
                        l_172 = ((**l_148) > p_46);
                    }
                    step_hash(56);
                    g_2 = &l_172;
                }
                step_hash(58);
                return p_46;
            }
            step_hash(60);
            return p_46;
        }
        else
        {
            unsigned short l_177 = 3UL;
            int l_208 = 0x6C9C1765L;
            int **l_229 = &l_100;
            unsigned short l_240 = 0x4B32L;
            step_hash(120);
            if ((((signed char)((!func_56(((short)func_56(l_177, &g_2, &g_3) >> (short)10), &l_100, (*l_136))) && (&l_172 == (void*)0)) % (signed char)l_178) <= 0x3A083379L))
            {
                int *l_184 = &g_3;
                unsigned short l_202 = 65528UL;
                unsigned l_253 = 1UL;
                step_hash(98);
                if (((int)0xD04037D6L - (int)p_46))
                {
                    short l_188 = (-1L);
                    int **l_195 = &l_184;
                    int l_201 = 0xAA1BD0BAL;
                    step_hash(64);
                    (*g_2) = (((int)0xEE3E29BDL + (int)(-(unsigned char)(l_184 != l_184))) >= g_86);
                    step_hash(73);
                    if ((*l_184))
                    {
                        step_hash(66);
                        (*g_2) = ((g_86 > (*l_100)) < (**l_187));
                        step_hash(67);
                        (**l_187) ^= l_177;
                        step_hash(68);
                        l_201 &= (**l_187);
                        step_hash(69);
                        (*g_2) &= p_45;
                    }
                    else
                    {
                        int **l_207 = &g_2;
                        step_hash(71);
                        (**l_136) = l_202;
                        step_hash(72);
                        (**l_187) = (((short)(*l_184) / (short)(-10L)) < (((void*)0 != &g_2) > ((short)(*l_100) * (short)g_38)));
                    }
                    step_hash(74);
                    (*l_187) = (*l_195);
                    step_hash(83);
                    if ((*g_2))
                    {
                        int *l_213 = &l_172;
                        step_hash(76);
                        (*g_2) = (*l_200);
                        step_hash(77);
                        l_208 = 0x6410FA4CL;
                        step_hash(78);
                        (*g_2) = (((signed char)((65535UL != 65535UL) & (*l_184)) >> (signed char)g_3) | (-6L));
                        step_hash(79);
                        (*g_2) &= (*l_213);
                    }
                    else
                    {
                        int ***l_228 = &l_195;
                        step_hash(81);
                        (*l_187) = func_65(((unsigned char)((unsigned short)(((unsigned short)1UL / (unsigned short)((unsigned short)g_38 << (unsigned short)((unsigned char)g_3 - (unsigned char)((signed char)(((short)((void*)0 == l_228) + (short)((*l_136) != (void*)0)) > ((void*)0 != (*l_228))) + (signed char)0x66L)))) <= g_3) * (unsigned short)g_3) >> (unsigned char)4), l_229, (*g_2), p_46);
                        step_hash(82);
                        (*g_2) |= (&l_187 == (void*)0);
                    }
                }
                else
                {
                    short l_237 = 0L;
                    int l_241 = 0x120FEED5L;
                    step_hash(90);
                    for (l_117 = (-17); (l_117 > 27); l_117 += 2)
                    {
                        int *l_234 = &l_208;
                        step_hash(88);
                        (*l_100) &= (+p_46);
                        step_hash(89);
                        (*l_234) ^= func_56(((*l_184) && ((short)p_47 >> (short)10)), &g_2, l_184);
                    }
                    step_hash(95);
                    if (p_47)
                    {
                        step_hash(92);
                        (**l_187) = ((short)func_56(p_47, func_60((*l_229), (**l_187), l_237, (*l_100)), func_65(g_98, &g_2, ((unsigned)(0L || (*g_2)) % (unsigned)1UL), g_3)) + (short)0x8686L);
                    }
                    else
                    {
                        step_hash(94);
                        (**l_229) &= p_46;
                    }
                    step_hash(96);
                    l_241 = l_240;
                    step_hash(97);
                    (**l_229) = (((signed char)(0L > 0x3C60L) % (signed char)(*l_184)) >= g_38);
                }
                step_hash(117);
                for (l_118 = (-13); (l_118 <= (-4)); l_118 += 8)
                {
                    int ***l_248 = (void*)0;
                    int l_257 = 0xEEB13F11L;
                    step_hash(102);
                    if (p_46)
                        break;
                    step_hash(107);
                    for (p_45 = 0; (p_45 >= 23); ++p_45)
                    {
                        step_hash(106);
                        (*g_2) |= ((void*)0 != l_248);
                    }
                    step_hash(108);
                    (*g_2) = (0x42L != 253UL);
                    step_hash(116);
                    for (l_208 = 0; (l_208 > (-19)); l_208--)
                    {
                        unsigned l_252 = 5UL;
                        step_hash(112);
                        (*g_2) = p_47;
                        step_hash(113);
                        l_252 |= ((&g_156 != l_251) || g_3);
                        step_hash(114);
                        (*l_187) = func_65(((!(l_253 < 0xD6L)) ^ l_252), l_229, (*g_2), (p_46 <= 0L));
                        step_hash(115);
                        (*g_2) = (-(unsigned char)((unsigned)l_257 + (unsigned)((-1L) ^ p_45)));
                    }
                }
            }
            else
            {
                step_hash(119);
                (**l_187) ^= (1UL && ((*l_229) == (void*)0));
            }
        }
    }
    else
    {
        unsigned short l_260 = 0x648DL;
        int l_261 = 0L;
        int **l_265 = &g_2;
        step_hash(129);
        if (func_50(l_260, p_47))
        {
            step_hash(124);
            return g_98;
        }
        else
        {
            int **l_262 = &l_200;
            step_hash(126);
            l_261 |= (*g_2);
            step_hash(127);
            (*l_262) = &l_261;
            step_hash(128);
            (*l_262) = &l_261;
        }
        step_hash(135);
        for (g_38 = 6; (g_38 > (-14)); g_38 -= 2)
        {
            step_hash(133);
            (*l_200) = (((void*)0 != l_265) && p_47);
            step_hash(134);
            (*l_200) = ((signed char)p_46 << (signed char)4);
        }
    }
    step_hash(187);
    if ((((0xBEL > p_45) != ((short)func_50((*l_100), (((p_46 || (l_270 < g_38)) <= (((signed char)((((void*)0 == &g_3) >= (-(unsigned short)(&g_86 != &l_172))) == g_98) << (signed char)3) < (*l_100))) & g_98)) - (short)g_3)) >= l_274))
    {
        signed char l_284 = 0xE7L;
        int *l_292 = &g_86;
        signed char l_297 = 8L;
        unsigned l_304 = 4294967293UL;
        step_hash(159);
        for (l_274 = 24; (l_274 <= 3); l_274 -= 6)
        {
            unsigned l_283 = 4294967295UL;
            int **l_293 = &g_2;
            int l_301 = 0xD5A7869CL;
            step_hash(147);
            for (p_46 = (-28); (p_46 > (-8)); p_46++)
            {
                step_hash(144);
                (*g_2) &= p_46;
                step_hash(145);
                l_284 = ((((int)p_45 - (int)(3L || ((signed char)l_283 / (signed char)g_98))) != g_38) == g_98);
                step_hash(146);
                if (p_47)
                    break;
            }
            step_hash(152);
            for (l_171 = (-6); (l_171 >= 29); l_171 += 4)
            {
                int *l_291 = (void*)0;
                step_hash(151);
                (*l_293) = func_65((((unsigned short)((unsigned short)0xF89DL << (unsigned short)14) - (unsigned short)func_56(g_86, func_60(l_291, l_284, func_56((*l_100), &g_2, l_292), (*l_292)), l_291)) && g_98), l_293, p_47, g_3);
            }
            step_hash(157);
            if ((+(g_98 & p_46)))
            {
                step_hash(154);
                (*l_292) = func_50(p_47, g_86);
            }
            else
            {
                int **l_294 = &l_200;
                int *l_298 = &l_270;
                step_hash(156);
                (*l_294) = func_65(((+(0UL || (func_56(p_47, func_60(&l_270, (((void*)0 != l_294) ^ g_38), ((int)(((void*)0 != &g_156) < l_297) - (int)g_3), (**l_293)), l_298) > p_46))) <= 0xB6D0L), l_293, p_47, p_45);
            }
            step_hash(158);
            (*g_2) = ((**l_293) > 0x74A1L);
        }
        step_hash(184);
        if (((unsigned char)0x65L % (unsigned char)l_304))
        {
            int l_307 = (-8L);
            int **l_308 = &g_2;
            step_hash(161);
            (*g_2) = func_56(g_86, &g_2, &g_3);
            step_hash(166);
            if (func_56((((unsigned short)9UL >> (unsigned short)g_38) != l_307), l_308, l_292))
            {
                step_hash(163);
                (*l_308) = &g_3;
            }
            else
            {
                step_hash(165);
                (*l_308) = &g_86;
            }
            step_hash(167);
            (*l_292) ^= 1L;
        }
        else
        {
            int *l_317 = &l_270;
            int l_356 = 0L;
            step_hash(175);
            if (((short)(&l_292 == &l_292) >> (short)func_56(((signed char)g_98 - (signed char)((signed char)p_46 * (signed char)((0xF631L >= ((short)((void*)0 == &g_2) >> (short)8)) || p_45))), func_60(l_317, g_38, (*l_100), p_47), l_317)))
            {
                int l_326 = (-1L);
                step_hash(170);
                (*l_317) = (((unsigned short)((unsigned char)(0xEE44L ^ (((short)(p_47 > ((void*)0 == &l_292)) - (short)((signed char)l_326 - (signed char)((g_86 < ((*l_251) != (void*)0)) > g_86))) & 65535UL)) >> (unsigned char)7) - (unsigned short)p_45) & p_47);
            }
            else
            {
                int **l_327 = &l_292;
                step_hash(172);
                (*l_292) = (*g_2);
                step_hash(173);
                (*g_2) |= (g_3 <= g_86);
                step_hash(174);
                (*l_292) = ((unsigned char)((*g_2) | 0x0656D313L) >> (unsigned char)p_45);
            }
            step_hash(176);
            (*l_292) ^= ((0x1CE679D6L != ((unsigned char)(((((unsigned short)g_38 + (unsigned short)(*l_317)) < p_46) | 0L) == ((unsigned short)((signed char)((signed char)(g_98 > 0x2074L) + (signed char)((unsigned char)252UL % (unsigned char)p_47)) % (signed char)p_47) + (unsigned short)1UL)) + (unsigned char)0x43L)) | p_46);
            step_hash(177);
            g_156 = func_60(func_65((~g_86), &g_2, (*l_292), (*l_317)), g_98, ((unsigned short)((*l_251) != g_156) << (unsigned short)12), ((unsigned short)(g_98 <= p_47) * (unsigned short)0x87B8L));
            step_hash(183);
            if (((((short)p_46 << (short)8) <= ((0L & 0xCBL) && (***l_251))) > ((g_38 | g_3) ^ p_45)))
            {
                step_hash(179);
                return g_3;
            }
            else
            {
                step_hash(181);
                (*g_2) = p_46;
                step_hash(182);
                l_356 &= ((signed char)0x42L * (signed char)((unsigned char)((short)(((signed char)((*l_317) == (*g_2)) + (signed char)p_45) | ((void*)0 == (*g_156))) >> (short)g_98) << (unsigned char)1));
            }
        }
    }
    else
    {
        int l_357 = 0x0922B4A9L;
        int **l_358 = &g_2;
        step_hash(186);
        (*l_358) = func_65(l_357, &g_2, p_46, (*l_100));
    }
    step_hash(195);
    if ((*g_2))
    {
        step_hash(189);
        g_2 = (void*)0;
        step_hash(190);
        return p_47;
    }
    else
    {
        int *l_359 = &g_38;
        int **l_371 = (void*)0;
        int **l_372 = &l_100;
        step_hash(192);
        (*l_359) = p_45;
        step_hash(193);
        (*l_372) = func_65(g_98, &g_2, p_45, g_38);
        step_hash(194);
        (*g_2) = p_46;
    }
    step_hash(196);
    (*g_2) |= (-1L);
    step_hash(197);
    return g_86;
}
static unsigned short func_50(int p_51, int p_52)
{
    int *l_53 = &g_38;
    int **l_99 = &g_2;
    step_hash(10);
    (*l_53) = (*g_2);
    step_hash(21);
    (*l_53) = (((short)func_56((*l_53), func_60(func_65((p_52 && (p_51 >= ((((unsigned char)(+g_3) * (unsigned char)((unsigned)((short)((int)p_52 + (int)((void*)0 == &g_2)) % (short)(p_51 && 8L)) / (unsigned)(*g_2))) | (*l_53)) < g_38))), &l_53, (*g_2), g_38), (*l_53), (*l_53), g_38), &g_3) * (short)p_52) <= g_3);
    step_hash(28);
    if (((unsigned short)0xCE30L * (unsigned short)((unsigned char)g_38 - (unsigned char)g_3)))
    {
        int *l_91 = &g_38;
        int **l_92 = &g_2;
        step_hash(23);
        (*l_92) = l_91;
    }
    else
    {
        int **l_93 = (void*)0;
        int **l_94 = &g_2;
        step_hash(25);
        (*g_2) = (*g_2);
        step_hash(26);
        (*l_94) = l_53;
        step_hash(27);
        g_98 ^= ((0UL ^ (!func_56(((unsigned short)(-(signed char)(*l_53)) % (unsigned short)p_52), func_60((*l_94), g_3, g_3, g_38), l_53))) != 0x15L);
    }
    step_hash(29);
    (*l_99) = l_53;
    step_hash(30);
    return p_51;
}
static short func_56(unsigned p_57, int ** p_58, int * p_59)
{
    step_hash(19);
    (**p_58) = ((void*)0 != &g_3);
    step_hash(20);
    return g_86;
}
static int ** func_60(int * p_61, short p_62, unsigned short p_63, int p_64)
{
    step_hash(17);
    return &g_2;
}
static int * func_65(unsigned short p_66, int ** p_67, int p_68, unsigned p_69)
{
    int *l_80 = (void*)0;
    int *l_85 = &g_86;
    step_hash(12);
    g_2 = &g_38;
    step_hash(13);
    l_80 = &g_38;
    step_hash(14);
    (*l_85) = ((unsigned char)((signed char)p_69 - (signed char)1L) << (unsigned char)6);
    step_hash(15);
    return (*p_67);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_38, "g_38", print_hash_value);
    transparent_crc(g_86, "g_86", print_hash_value);
    transparent_crc(g_98, "g_98", print_hash_value);
    transparent_crc(g_425, "g_425", print_hash_value);
    transparent_crc(g_523, "g_523", print_hash_value);
    transparent_crc(g_538, "g_538", print_hash_value);
    transparent_crc(g_734, "g_734", print_hash_value);
    transparent_crc(g_745, "g_745", print_hash_value);
    transparent_crc(g_821, "g_821", print_hash_value);
    transparent_crc(g_856, "g_856", print_hash_value);
    transparent_crc(g_881, "g_881", print_hash_value);
    transparent_crc(g_913, "g_913", print_hash_value);
    transparent_crc(g_993, "g_993", print_hash_value);
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
