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
static int g_10 = 0x147B80BEL;
static int g_12 = 0xCFD1F2E9L;
static int g_92 = 3L;
static int *g_98 = (void*)0;
static int **g_97 = &g_98;
static int g_101 = 1L;
static unsigned g_106 = 0UL;
static unsigned short g_260 = 0xAD4DL;
static signed char g_448 = 0x03L;
static unsigned g_722 = 0UL;
static int g_837 = (-10L);
static int *g_849 = &g_92;
static unsigned func_1(void);
static short func_4(short p_5);
static int func_16(int p_17);
static int func_18(short p_19, int p_20, int * p_21, int * p_22);
static int func_24(short p_25, unsigned short p_26, unsigned short p_27, int * p_28);
static int * func_31(unsigned char p_32, short p_33, int * p_34, int * p_35);
static int func_47(signed char p_48, unsigned p_49, unsigned short p_50, unsigned p_51, unsigned short p_52);
static int * func_54(int * p_55, signed char p_56, unsigned p_57, int * p_58);
static int * func_60(unsigned char p_61, unsigned short p_62, int * p_63, unsigned char p_64, int * p_65);
static short func_66(unsigned short p_67, unsigned p_68);
static unsigned func_1(void)
{
    int l_6 = 0x961C0F80L;
    int *l_816 = &g_10;
    unsigned short l_822 = 0xECFCL;
    int *l_872 = (void*)0;
    int ***l_873 = &g_97;
    unsigned char l_874 = 0x76L;
    step_hash(468);
    (*l_816) = ((0x0BB743D8L | (+((short)func_4(l_6) * (short)((l_6 | g_722) | (&g_97 != &g_97))))) || l_6);
    step_hash(522);
    for (g_10 = 0; (g_10 > (-8)); g_10 -= 3)
    {
        int l_856 = 0x5C93BEA6L;
        step_hash(472);
        (*g_97) = (void*)0;
        step_hash(520);
        for (g_722 = 0; (g_722 >= 1); ++g_722)
        {
            unsigned char l_821 = 0x44L;
            int **l_823 = &g_98;
            unsigned l_870 = 5UL;
            step_hash(476);
            g_12 &= l_821;
            step_hash(477);
            l_822 &= (0xB683L >= (-6L));
            step_hash(519);
            if ((*l_816))
            {
                int *l_824 = &g_92;
                int l_838 = 0xCF1E05A3L;
                step_hash(479);
                (*l_824) |= (l_823 == (void*)0);
                step_hash(484);
                for (g_92 = 0; (g_92 != (-9)); g_92--)
                {
                    step_hash(483);
                    return g_260;
                }
                step_hash(492);
                if ((*l_824))
                {
                    int *l_835 = (void*)0;
                    int *l_836 = &g_837;
                    step_hash(486);
                    (*l_836) ^= (~(((signed char)func_18(g_106, func_24(((short)(((*l_824) & (*l_824)) | ((signed char)(func_18(g_10, (*l_824), (*g_97), l_816) <= 0x535DL) % (signed char)1L)) >> (short)0), g_101, g_10, &g_101), l_835, l_816) + (signed char)g_10) ^ 0UL));
                    step_hash(487);
                    if ((**g_97))
                        continue;
                    step_hash(488);
                    l_838 |= (**g_97);
                    step_hash(489);
                    (*l_836) = (*l_816);
                }
                else
                {
                    unsigned char l_841 = 0x2BL;
                    int *l_842 = &l_838;
                    step_hash(491);
                    (*l_842) &= ((short)(*l_816) / (short)func_16(func_18(g_260, (func_66(l_841, (*l_824)) && 0xE1F8L), l_816, l_816)));
                }
                step_hash(493);
                return g_106;
            }
            else
            {
                int l_848 = 3L;
                int *l_850 = &g_12;
                step_hash(495);
                (*l_823) = func_60((((-(signed char)(((unsigned char)((unsigned)0UL % (unsigned)(*l_816)) >> (unsigned char)(&l_816 != l_823)) ^ (0x80B5L & (!5L)))) >= (func_18(g_106, l_848, g_849, (*g_97)) | (-1L))) || (*l_816)), g_448, l_850, g_448, l_850);
                step_hash(517);
                for (l_822 = 0; (l_822 >= 7); ++l_822)
                {
                    int *l_854 = (void*)0;
                    int *l_871 = &g_12;
                }
                step_hash(518);
                (*g_849) = (g_837 & ((**g_97) < 0L));
            }
        }
        step_hash(521);
        (*g_849) |= l_856;
    }
    step_hash(523);
    (*g_97) = (*g_97);
    step_hash(524);
    l_874 &= ((*l_816) ^ (g_448 == (l_873 != &g_97)));
    step_hash(525);
    return g_92;
}
static short func_4(short p_5)
{
    int **l_800 = &g_98;
    int l_807 = 0x86715221L;
    int *l_813 = (void*)0;
    int *l_814 = (void*)0;
    int *l_815 = &g_101;
    step_hash(8);
    for (p_5 = 0; (p_5 > (-3)); p_5 -= 3)
    {
        int *l_9 = &g_10;
        int *l_11 = &g_12;
        step_hash(5);
        (*l_9) ^= 0L;
        step_hash(6);
        (*l_11) ^= g_10;
        step_hash(7);
        (*l_9) |= 0xE7ED6F18L;
    }
    step_hash(465);
    for (g_10 = 0; (g_10 == 7); g_10++)
    {
        int l_15 = 1L;
        step_hash(457);
        l_15 = (g_10 < ((l_15 && 0xF7L) && func_16(g_12)));
        step_hash(464);
        for (g_12 = (-29); (g_12 >= 13); g_12 += 1)
        {
            int *l_808 = &l_15;
            int *l_812 = &l_807;
            step_hash(461);
            (*l_808) = (((void*)0 == l_800) ^ ((1L <= (((unsigned char)g_101 * (unsigned char)(((short)((unsigned char)((0x0CL && ((+(l_807 >= 0x7EF004AEL)) <= p_5)) ^ (g_12 > g_92)) << (unsigned char)g_101) * (short)g_722) <= 0x43DC0BA7L)) < 0x8DL)) >= g_12));
            step_hash(462);
            (*l_812) &= (((-(unsigned)(3L < 0x34L)) || ((*l_808) || (p_5 ^ g_106))) <= (func_24(((unsigned)((*l_808) != (&l_800 == &l_800)) % (unsigned)0x7C744603L), g_10, g_101, (*l_800)) > 0x30B2E415L));
            step_hash(463);
            if (p_5)
                continue;
        }
    }
    step_hash(466);
    (*l_815) |= p_5;
    step_hash(467);
    return (*l_815);
}
static int func_16(int p_17)
{
    int *l_23 = &g_12;
    int ***l_796 = &g_97;
    step_hash(454);
    (*l_23) = (func_18((~(((((void*)0 == l_23) > func_24((*l_23), p_17, p_17, &g_12)) ^ ((void*)0 != l_796)) | p_17)), p_17, (**l_796), (**l_796)) || p_17);
    step_hash(455);
    (*l_23) = (*l_23);
    step_hash(456);
    return p_17;
}
static int func_18(short p_19, int p_20, int * p_21, int * p_22)
{
    int *l_797 = &g_92;
    step_hash(452);
    (*g_97) = l_797;
    step_hash(453);
    return (*g_98);
}
static int func_24(short p_25, unsigned short p_26, unsigned short p_27, int * p_28)
{
    unsigned l_46 = 4294967293UL;
    int *l_783 = &g_92;
    int *l_792 = &g_101;
    step_hash(14);
    p_28 = &g_12;
    step_hash(442);
    for (p_25 = 0; (p_25 != (-28)); p_25 -= 6)
    {
    }
    step_hash(443);
    (*l_792) |= (((*l_783) <= g_12) | ((signed char)(p_26 != ((unsigned char)p_26 >> (unsigned char)5)) << (signed char)(p_27 | (0xCF70L <= ((unsigned)p_26 % (unsigned)((short)(&l_783 != &g_98) << (short)(*l_783)))))));
    step_hash(449);
    for (g_101 = 10; (g_101 <= 5); g_101 -= 7)
    {
        unsigned char l_795 = 0x5CL;
        step_hash(447);
        (*l_783) = 0L;
        step_hash(448);
        if (l_795)
            continue;
    }
    step_hash(450);
    return g_106;
}
static int * func_31(unsigned char p_32, short p_33, int * p_34, int * p_35)
{
    unsigned l_53 = 0x6845925FL;
    int l_548 = 0x9638552AL;
    int l_555 = 0x3E3091CEL;
    int ***l_565 = (void*)0;
    int l_585 = 0L;
    signed char l_636 = 0x59L;
    int *l_640 = (void*)0;
    int l_657 = (-10L);
    unsigned l_664 = 0x8321351DL;
    short l_683 = 0x5D4EL;
    int *l_693 = &l_585;
    signed char l_736 = (-9L);
    int *l_756 = &g_12;
    step_hash(357);
    if (func_47(g_10, p_32, l_53, g_10, l_53))
    {
        int l_538 = 1L;
        int l_574 = 0L;
        int **l_600 = &g_98;
        step_hash(337);
        for (g_448 = 0; (g_448 <= 6); ++g_448)
        {
            short l_560 = 0xDB41L;
            int *l_588 = &g_101;
            step_hash(293);
            (*p_35) = ((signed char)((unsigned short)0xC3AAL / (unsigned short)((unsigned short)((~(l_538 == g_10)) == ((unsigned)(p_33 | (((unsigned short)g_101 * (unsigned short)p_32) == (~l_53))) - (unsigned)0x6A687C36L)) << (unsigned short)8)) >> (signed char)l_538);
            step_hash(294);
            (*p_34) = l_538;
            step_hash(295);
            if ((*p_34))
                continue;
            step_hash(336);
            if (l_53)
            {
                unsigned char l_547 = 250UL;
                int *l_550 = &l_548;
                unsigned l_564 = 0UL;
                step_hash(310);
                for (p_33 = 0; (p_33 > 22); ++p_33)
                {
                    int *l_549 = &g_101;
                    step_hash(307);
                    for (g_92 = 0; (g_92 > 10); g_92 += 6)
                    {
                        step_hash(303);
                        l_548 &= (~(((void*)0 == &g_98) > (4L & l_547)));
                        step_hash(304);
                        (*p_34) |= (p_33 == g_260);
                        step_hash(305);
                        (*g_97) = l_549;
                        step_hash(306);
                        p_35 = l_550;
                    }
                    step_hash(308);
                    (*p_34) = (*p_35);
                    step_hash(309);
                    return &g_12;
                }
                step_hash(315);
                if (((unsigned char)((((int)l_555 % (int)((short)g_106 / (short)((*l_550) ^ ((unsigned char)l_560 + (unsigned char)l_538)))) || 1UL) & (-1L)) >> (unsigned char)0))
                {
                    unsigned l_563 = 4294967288UL;
                    unsigned l_568 = 0x74B69C44L;
                    step_hash(312);
                    l_568 |= ((signed char)(l_560 || (l_564 >= (((l_565 == &g_97) == ((short)p_33 % (short)65535UL)) == g_10))) + (signed char)0xC7L);
                }
                else
                {
                    short l_573 = 0x6153L;
                    step_hash(314);
                    (*g_97) = func_60((((unsigned char)p_33 + (unsigned char)((short)l_573 + (short)((unsigned)g_12 - (unsigned)(!((unsigned short)(p_32 || 0xFDL) >> (unsigned short)g_106))))) < 0UL), p_32, p_34, l_573, l_550);
                }
                step_hash(325);
                if (((g_448 <= 0L) < g_448))
                {
                    step_hash(321);
                    for (g_12 = 0; (g_12 > (-9)); --g_12)
                    {
                        step_hash(320);
                        (*l_550) &= (*p_35);
                    }
                    step_hash(322);
                    (*p_34) ^= (+(9L && ((*l_550) >= 250UL)));
                }
                else
                {
                    step_hash(324);
                    (*g_97) = p_35;
                }
                step_hash(326);
                l_585 &= (*l_550);
            }
            else
            {
                signed char l_589 = 0xD1L;
                step_hash(328);
                if (l_560)
                    break;
                step_hash(333);
                for (g_101 = 9; (g_101 <= 2); --g_101)
                {
                    step_hash(332);
                    (*g_97) = l_588;
                }
                step_hash(334);
                (*l_588) = 0x78CCDA2DL;
                step_hash(335);
                (*p_35) = l_589;
            }
        }
        step_hash(350);
        for (p_32 = 0; (p_32 == 7); ++p_32)
        {
            int l_592 = (-5L);
            int ***l_599 = &g_97;
            step_hash(341);
            (*g_97) = p_35;
            step_hash(342);
            l_592 = func_47(g_12, l_538, g_448, p_33, (l_565 == &g_97));
            step_hash(348);
            for (l_538 = 0; (l_538 <= (-9)); --l_538)
            {
                unsigned l_615 = 0x6CF255FBL;
                int *l_616 = (void*)0;
                int *l_617 = &l_592;
                step_hash(346);
                (*l_617) |= (((short)((p_32 == (l_599 == &g_97)) > (l_600 != &g_98)) + (short)(((signed char)(~(((((unsigned char)((int)1L + (int)(((signed char)p_33 * (signed char)(-1L)) != ((unsigned short)((signed char)g_448 >> (signed char)g_12) * (unsigned short)(-2L)))) + (unsigned char)g_101) & 0L) != p_32) <= p_32)) >> (signed char)g_106) == (-3L))) || g_448);
                step_hash(347);
                (*p_34) = ((unsigned char)g_106 - (unsigned char)5L);
            }
            step_hash(349);
            (*p_35) = ((+(g_92 && g_260)) & (-1L));
        }
        step_hash(351);
        (*l_600) = p_34;
        step_hash(352);
        (*p_35) = (**g_97);
    }
    else
    {
        int *l_622 = &g_10;
        int l_627 = 0L;
        int *l_637 = &l_548;
        int ***l_638 = (void*)0;
        int ***l_639 = &g_97;
        step_hash(354);
        (*g_97) = func_60(((int)g_101 + (int)0x4D55F47BL), p_32, l_622, ((int)0x35040A48L + (int)((1UL & p_33) ^ (l_627 < g_92))), p_35);
        step_hash(355);
        (*l_637) |= ((signed char)g_448 * (signed char)func_66(((p_32 && ((unsigned short)(!((unsigned)4294967289UL / (unsigned)l_585)) << (unsigned short)10)) != ((short)p_33 * (short)l_636)), (p_34 == (void*)0)));
        step_hash(356);
        (*l_639) = &l_637;
    }
    step_hash(358);
    l_640 = &l_548;
    step_hash(367);
    if ((*p_35))
    {
        step_hash(364);
        for (l_555 = 20; (l_555 != 2); l_555--)
        {
            step_hash(363);
            return &g_10;
        }
    }
    else
    {
        step_hash(366);
        (*l_640) ^= (*p_35);
    }
    step_hash(439);
    for (p_33 = (-23); (p_33 != 19); p_33 += 5)
    {
        unsigned l_645 = 0UL;
        unsigned l_648 = 6UL;
        unsigned char l_665 = 255UL;
        int **l_682 = (void*)0;
        int *l_779 = &g_101;
    }
    step_hash(440);
    return p_35;
}
static int func_47(signed char p_48, unsigned p_49, unsigned short p_50, unsigned p_51, unsigned short p_52)
{
    int *l_59 = &g_12;
    signed char l_79 = 0x2AL;
    unsigned char l_80 = 0xD0L;
    int **l_528 = &l_59;
    int *l_529 = &g_101;
    step_hash(284);
    (*l_528) = func_54(l_59, g_12, p_51, func_60((func_66((((p_49 | 1UL) <= (*l_59)) <= (((signed char)g_12 % (signed char)((int)(((unsigned short)((unsigned short)(*l_59) - (unsigned short)(((unsigned char)(g_12 == (*l_59)) >> (unsigned char)(*l_59)) == (*l_59))) / (unsigned short)l_79) <= g_10) + (int)4294967287UL)) && g_10)), l_80) <= (*l_59)), p_48, l_59, p_50, l_59));
    step_hash(285);
    g_12 = p_50;
    step_hash(286);
    (*l_529) = p_48;
    step_hash(287);
    (*l_528) = &g_101;
    step_hash(288);
    return (*l_529);
}
static int * func_54(int * p_55, signed char p_56, unsigned p_57, int * p_58)
{
    unsigned char l_368 = 0x83L;
    int *l_401 = &g_10;
    int ***l_453 = &g_97;
    int l_526 = 3L;
    step_hash(275);
    if ((l_368 >= (+((unsigned char)((((short)g_101 >> (short)g_260) != l_368) || p_57) << (unsigned char)g_12))))
    {
        step_hash(206);
        return (*g_97);
    }
    else
    {
        int l_392 = 0x746557D3L;
        short l_397 = 1L;
        signed char l_403 = (-1L);
        unsigned l_407 = 0x3CB08594L;
        unsigned short l_447 = 0x7DF8L;
        step_hash(274);
        if ((*p_55))
        {
            unsigned short l_391 = 0x56FBL;
            int l_393 = 0L;
            int *l_394 = &l_392;
            step_hash(209);
            l_394 = func_60(((unsigned short)0x5DAAL * (unsigned short)((p_57 || (l_391 ^ func_66(l_392, g_260))) <= p_57)), l_391, p_55, l_393, p_58);
            step_hash(210);
            l_392 ^= func_66((((signed char)p_57 - (signed char)l_397) >= 65535UL), l_397);
            step_hash(211);
            (*p_55) |= 0x06B0F98DL;
        }
        else
        {
            signed char l_402 = (-1L);
            int ***l_416 = &g_97;
            unsigned l_520 = 0x1980AD38L;
            step_hash(235);
            for (p_57 = 28; (p_57 > 24); p_57 -= 4)
            {
                unsigned char l_400 = 0xE3L;
                int *l_404 = (void*)0;
                unsigned l_437 = 0x315FED4AL;
                signed char l_446 = 0x2CL;
                step_hash(216);
                (*g_97) = func_60(func_66(g_106, l_392), (l_400 >= ((-7L) <= (*p_55))), &g_12, p_57, l_401);
                step_hash(217);
                (*g_97) = func_60(l_402, l_403, &l_392, g_92, l_404);
                step_hash(233);
                for (l_368 = 0; (l_368 != 26); ++l_368)
                {
                    int *l_419 = (void*)0;
                }
                step_hash(234);
                (**l_416) = func_60(((unsigned)(***l_416) % (unsigned)p_56), (+((g_448 > ((!0x1AD9B4CEL) < ((unsigned short)p_56 - (unsigned short)(0xF9C83682L && (*p_55))))) == (&g_98 == (void*)0))), p_58, p_57, (*g_97));
            }
            step_hash(236);
            (*p_55) = ((void*)0 != l_453);
            step_hash(272);
            if ((p_57 & ((signed char)g_448 % (signed char)((0xFB8EL || p_56) || ((g_12 != (((+((short)((signed char)p_56 - (signed char)((unsigned char)(0x7331L && ((0xE307C46FL & 0L) | p_56)) << (unsigned char)p_56)) % (short)0x858AL)) < 4294967291UL) <= p_56)) <= g_448)))))
            {
                int ***l_466 = &g_97;
                step_hash(238);
                (*p_55) &= ((unsigned short)(((signed char)(l_466 == l_453) >> (signed char)1) < l_397) - (unsigned short)0xB0D3L);
                step_hash(239);
                (*p_55) = (((0UL <= ((unsigned char)((&g_97 == (void*)0) | g_92) - (unsigned char)p_56)) == p_57) < 0x8BAE48ADL);
            }
            else
            {
                short l_479 = 0x4B0BL;
                step_hash(241);
                (*p_55) = (!(*p_55));
                step_hash(247);
                for (g_12 = 0; (g_12 <= 16); g_12++)
                {
                    int *l_492 = (void*)0;
                    int *l_493 = &l_392;
                    step_hash(245);
                    (*l_493) = (((short)(g_10 < (l_397 >= p_56)) >> (short)p_57) == (*p_55));
                    step_hash(246);
                    if (l_397)
                        continue;
                }
                step_hash(259);
                for (l_368 = 23; (l_368 == 28); l_368++)
                {
                    int **l_502 = &l_401;
                    int *l_505 = &g_101;
                    step_hash(251);
                    (*p_55) = ((signed char)g_260 + (signed char)(((signed char)func_66(p_57, l_447) - (signed char)(p_57 == ((unsigned)(g_97 == l_502) + (unsigned)p_57))) && (((((p_58 != (void*)0) & g_10) <= l_407) & 0xF3D125E4L) == p_57)));
                    step_hash(252);
                    (**l_453) = (void*)0;
                    step_hash(253);
                    if (l_479)
                        break;
                    step_hash(258);
                    for (g_448 = 0; (g_448 >= 14); g_448++)
                    {
                        step_hash(257);
                        return l_505;
                    }
                }
                step_hash(271);
                if (((signed char)p_56 / (signed char)((p_56 == (0xD115L < (g_448 ^ p_57))) && (&g_97 != l_416))))
                {
                    int *l_512 = &l_392;
                    step_hash(265);
                    for (p_57 = 29; (p_57 >= 46); ++p_57)
                    {
                        step_hash(264);
                        (*p_55) = (*p_55);
                    }
                    step_hash(266);
                    (*l_512) |= func_66((*l_401), p_57);
                    step_hash(267);
                    (*l_512) = (g_448 ^ ((unsigned)(-(unsigned)p_56) % (unsigned)g_12));
                }
                else
                {
                    unsigned char l_521 = 0x70L;
                    int *l_522 = &g_92;
                    step_hash(269);
                    (*l_522) |= ((unsigned short)g_448 + (unsigned short)((short)(((*p_55) != (((g_101 < l_520) | l_397) | l_521)) && 255UL) >> (short)14));
                    step_hash(270);
                    (**l_453) = p_55;
                }
            }
            step_hash(273);
            (**l_416) = (void*)0;
        }
    }
    step_hash(282);
    if ((*l_401))
    {
        int l_525 = 5L;
        step_hash(277);
        l_526 |= ((unsigned char)g_260 * (unsigned char)l_525);
    }
    else
    {
        int *l_527 = &g_12;
        step_hash(279);
        (*g_97) = l_527;
        step_hash(280);
        g_97 = &g_98;
        step_hash(281);
        (*g_97) = l_527;
    }
    step_hash(283);
    return p_55;
}
static int * func_60(unsigned char p_61, unsigned short p_62, int * p_63, unsigned char p_64, int * p_65)
{
    int *l_363 = (void*)0;
    int *l_367 = &g_10;
    step_hash(196);
    (*g_97) = (void*)0;
    step_hash(197);
    (*g_97) = l_363;
    step_hash(202);
    for (g_101 = 0; (g_101 >= 14); g_101++)
    {
        int *l_366 = &g_92;
        step_hash(201);
        (*l_366) |= (*p_63);
    }
    step_hash(203);
    return l_367;
}
static short func_66(unsigned short p_67, unsigned p_68)
{
    unsigned char l_83 = 8UL;
    int *l_90 = &g_12;
    unsigned l_132 = 4294967295UL;
    unsigned short l_189 = 65534UL;
    int l_231 = 0x8C644E42L;
    signed char l_279 = (-1L);
    short l_306 = 1L;
    int ***l_320 = &g_97;
    short l_336 = 0xB2CFL;
    signed char l_337 = 0x3DL;
    int *l_340 = &g_92;
    step_hash(174);
    if ((0xBFL & (p_68 & ((unsigned)1UL % (unsigned)l_83))))
    {
        int *l_91 = &g_92;
        int l_115 = 0L;
        step_hash(31);
        if (g_12)
        {
            int **l_84 = (void*)0;
            int *l_86 = (void*)0;
            int **l_85 = &l_86;
            int l_87 = (-1L);
            step_hash(23);
            (*l_85) = &g_10;
            step_hash(24);
            l_87 = g_12;
        }
        else
        {
            step_hash(30);
            for (p_68 = 0; (p_68 <= 48); p_68++)
            {
                step_hash(29);
                l_91 = l_90;
            }
        }
        step_hash(56);
        if ((*l_91))
        {
            int **l_99 = &l_91;
            int *l_100 = &g_101;
            step_hash(33);
            (*l_100) ^= (g_10 == (((short)((unsigned)((*l_90) < ((((((void*)0 != g_97) && (g_10 != g_92)) != ((&g_98 == l_99) == ((*g_97) != (*g_97)))) | 4294967288UL) == g_92)) + (unsigned)p_67) / (short)g_92) && g_10));
            step_hash(40);
            for (p_67 = 21; (p_67 >= 32); p_67 += 9)
            {
                step_hash(37);
                g_106 = ((6UL < 0xFD67D06FL) >= (p_68 != (p_67 >= (*l_90))));
                step_hash(38);
                (*l_100) = (*l_91);
                step_hash(39);
                (*l_100) ^= (*l_91);
            }
            step_hash(46);
            for (g_92 = 7; (g_92 <= (-6)); --g_92)
            {
                unsigned l_110 = 4294967288UL;
                int l_111 = 0xB120DA2EL;
                step_hash(44);
                l_111 |= (((-(int)l_110) != g_101) > g_10);
                step_hash(45);
                (*g_97) = (*g_97);
            }
            step_hash(52);
            for (g_92 = (-22); (g_92 < (-5)); g_92++)
            {
                step_hash(50);
                (*l_99) = (*g_97);
                step_hash(51);
                (*l_100) = p_68;
            }
        }
        else
        {
            int *l_114 = &g_92;
            step_hash(54);
            (*l_114) = p_67;
            step_hash(55);
            (*g_97) = (*g_97);
        }
        step_hash(57);
        l_115 ^= p_67;
    }
    else
    {
        int l_142 = 1L;
        unsigned short l_169 = 0x6E22L;
        int l_170 = 0x4F6C7F95L;
        int **l_214 = &l_90;
        step_hash(173);
        if (p_68)
        {
            int *l_118 = &g_92;
            unsigned char l_150 = 0x78L;
            step_hash(76);
            if (((unsigned short)(0xB263C45FL >= (~g_101)) >> (unsigned short)0))
            {
                int *l_119 = &g_101;
                step_hash(61);
                l_119 = l_118;
                step_hash(62);
                (*l_119) = (p_67 ^ ((unsigned short)(0xDB05L > (g_106 > (((int)(-1L) / (int)((signed char)((((unsigned short)g_92 * (unsigned short)((unsigned char)(!(*l_118)) % (unsigned char)((signed char)(*l_119) >> (signed char)5))) == l_132) < (0xC8546551L >= (-1L))) * (signed char)(-1L))) && 0x0DD4D5FFL))) >> (unsigned short)g_92));
            }
            else
            {
                unsigned l_135 = 0x7241B9ADL;
                int l_141 = 0x01DBA863L;
                int **l_143 = &g_98;
                step_hash(75);
                for (g_92 = 1; (g_92 != 0); g_92 -= 1)
                {
                    short l_140 = 0x48D5L;
                    int *l_153 = &l_141;
                    step_hash(67);
                    if (l_135)
                        break;
                    step_hash(72);
                    for (p_67 = 0; (p_67 != 38); p_67 += 1)
                    {
                        step_hash(71);
                        l_141 = (((unsigned short)l_140 >> (unsigned short)g_12) & (0xB7A0L & l_135));
                    }
                    step_hash(73);
                    (*l_153) &= (((!(l_142 & ((*l_118) == (&g_98 == l_143)))) > g_12) && ((unsigned char)(!((unsigned)p_67 - (unsigned)((signed char)l_142 << (signed char)l_150))) % (unsigned char)(((short)((void*)0 == (*l_143)) % (short)g_92) ^ g_101)));
                    step_hash(74);
                    (*l_153) = (p_68 && ((unsigned short)(l_90 == (*g_97)) * (unsigned short)0x0808L));
                }
            }
            step_hash(77);
            (*l_118) = 0xBB3B6D22L;
            step_hash(78);
            l_170 |= ((short)(((unsigned char)(p_68 ^ (-(unsigned)0UL)) << (unsigned char)7) <= (((unsigned short)(*l_118) * (unsigned short)((l_142 || (&g_98 == &l_90)) != ((&l_90 != &l_90) != ((((~((int)((unsigned short)p_68 << (unsigned short)1) + (int)(*l_90))) & p_67) || l_169) ^ l_169)))) & g_10)) / (short)0xD9D7L);
        }
        else
        {
            int **l_180 = &g_98;
            int l_255 = (-1L);
            step_hash(114);
            for (g_101 = 0; (g_101 < (-18)); g_101--)
            {
                int l_179 = 0L;
                int l_213 = 0xA3BE24AFL;
                unsigned char l_221 = 0xEDL;
                int *l_222 = &l_213;
            }
            step_hash(134);
            if (((((((unsigned char)(g_101 | ((**l_214) > g_10)) >> (unsigned char)(**l_214)) < p_68) | ((0xC4768125L && 1L) < g_10)) != g_101) < g_92))
            {
                int *l_226 = (void*)0;
                int *l_227 = (void*)0;
                int *l_228 = &g_101;
                step_hash(116);
                (*l_180) = (*g_97);
                step_hash(117);
                (*l_228) |= (-(int)p_67);
                step_hash(127);
                for (l_170 = 16; (l_170 >= 17); l_170++)
                {
                    step_hash(121);
                    l_231 = (&l_228 != (void*)0);
                    step_hash(126);
                    for (p_68 = 0; (p_68 <= 24); p_68++)
                    {
                        unsigned l_246 = 4294967286UL;
                        step_hash(125);
                        (*l_228) = ((signed char)((signed char)(((unsigned char)((((short)((short)g_10 / (short)g_106) >> (short)((((int)((l_246 >= (((unsigned short)((unsigned short)(p_67 ^ (((unsigned char)g_106 / (unsigned char)((unsigned)(g_10 <= ((g_92 == g_12) || ((g_10 <= g_92) | (-8L)))) % (unsigned)0x29605C3BL)) & g_101)) / (unsigned short)0xACE6L) * (unsigned short)p_68) != 0xBE11L)) && g_106) - (int)(-5L)) & (**l_214)) == 0xFCC5AF58L)) ^ p_68) || (**l_214)) << (unsigned char)1) | g_10) >> (signed char)g_101) / (signed char)p_68);
                    }
                }
                step_hash(128);
                l_255 = p_68;
            }
            else
            {
                short l_256 = 0x6979L;
                int *l_257 = &l_170;
                step_hash(130);
                (*l_257) |= l_256;
                step_hash(131);
                (*l_257) ^= ((((void*)0 != (*g_97)) | 1L) >= ((unsigned short)(g_10 >= p_68) >> (unsigned short)p_67));
                step_hash(132);
                (*l_257) |= g_260;
                step_hash(133);
                (*l_257) |= (p_68 <= 0xA116L);
            }
            step_hash(172);
            if (((signed char)(**l_214) << (signed char)(0xDDL | g_260)))
            {
                int ***l_278 = &l_180;
                short l_282 = 0x134AL;
                int l_287 = 0xF1F42B0BL;
                int *l_331 = &g_92;
                step_hash(166);
                if (g_106)
                {
                    int l_271 = 0L;
                    int **l_289 = (void*)0;
                    step_hash(144);
                    if (((unsigned char)g_106 * (unsigned char)((unsigned)((((int)0x4CD6723AL - (int)0xEB08BFD2L) ^ (((unsigned char)(0x37L > (**l_214)) << (unsigned char)1) != ((l_271 > ((signed char)(4UL <= (255UL && ((unsigned)((((((short)(((((void*)0 != l_278) || g_92) || 4294967295UL) <= p_67) / (short)0xC91FL) > 1L) >= p_67) >= p_68) ^ (-10L)) - (unsigned)(-8L)))) / (signed char)l_279)) > 0x276FL))) | l_271) % (unsigned)g_101)))
                    {
                        step_hash(138);
                        l_255 = p_67;
                    }
                    else
                    {
                        int *l_288 = &l_170;
                        step_hash(140);
                        l_287 &= ((g_260 && (l_282 >= ((short)((unsigned short)g_101 << (unsigned short)g_10) >> (short)4))) <= p_67);
                        step_hash(141);
                        (*l_288) = p_67;
                        step_hash(142);
                        (*l_278) = l_289;
                        step_hash(143);
                        (*g_97) = &l_231;
                    }
                    step_hash(151);
                    if ((!(g_260 | g_12)))
                    {
                        int l_300 = (-9L);
                        int *l_301 = (void*)0;
                        int *l_302 = (void*)0;
                        int *l_303 = &g_101;
                        step_hash(146);
                        (*l_303) = ((signed char)(g_12 <= (~g_92)) >> (signed char)((((((short)(&g_98 == (void*)0) >> (short)5) >= (g_92 <= (0x8BA5L || p_68))) || ((int)((unsigned char)((signed char)0xD7L + (signed char)(**l_214)) - (unsigned char)g_12) + (int)l_300)) || p_67) < g_106));
                        step_hash(147);
                        (*l_303) ^= ((unsigned char)0UL >> (unsigned char)0);
                        step_hash(148);
                        (*l_214) = (*g_97);
                    }
                    else
                    {
                        step_hash(150);
                        return (**l_214);
                    }
                    step_hash(152);
                    return p_67;
                }
                else
                {
                    unsigned short l_307 = 0x49B1L;
                    int ***l_319 = &g_97;
                    int l_326 = 0x1953DAA2L;
                    step_hash(163);
                    if ((*l_90))
                    {
                        short l_314 = (-1L);
                        int l_321 = 0xE188A6EBL;
                        step_hash(155);
                        l_231 ^= l_306;
                        step_hash(156);
                        (*l_214) = (*l_180);
                        step_hash(157);
                        l_307 = p_67;
                        step_hash(158);
                        l_321 = ((((signed char)((signed char)(p_68 & 2UL) + (signed char)((unsigned short)((void*)0 == &g_97) << (unsigned short)8)) >> (signed char)((l_314 >= (((signed char)p_67 % (signed char)g_260) == p_68)) != ((signed char)(l_319 != l_320) / (signed char)1L))) > g_106) ^ 0xE0L);
                    }
                    else
                    {
                        short l_322 = 0xE4FAL;
                        int l_323 = 1L;
                        step_hash(160);
                        l_322 = p_67;
                        step_hash(161);
                        l_255 = (g_92 || (&l_214 != (void*)0));
                        step_hash(162);
                        l_323 = (**l_214);
                    }
                    step_hash(164);
                    l_255 = (g_101 != 0xF21FL);
                    step_hash(165);
                    l_326 ^= (((-1L) & (g_12 >= ((unsigned char)250UL + (unsigned char)(&g_97 == &g_97)))) <= p_68);
                }
                step_hash(167);
                l_255 &= g_12;
                step_hash(168);
                (*l_331) = (((short)p_67 >> (short)g_10) & (g_12 ^ ((unsigned char)g_10 - (unsigned char)g_12)));
                step_hash(169);
                (*l_331) = 0xABE08972L;
            }
            else
            {
                step_hash(171);
                g_101 = (p_67 < (p_68 > p_68));
            }
        }
    }
    step_hash(175);
    (*l_340) = (4UL ^ ((signed char)((*l_320) != (void*)0) << (signed char)((short)l_336 * (short)(l_337 | (g_10 > (((signed char)4L >> (signed char)4) < g_101))))));
    step_hash(193);
    if (((short)(((unsigned char)((unsigned char)(g_10 <= g_260) - (unsigned char)(((unsigned short)(*l_340) - (unsigned short)((short)(1L | 3L) + (short)0L)) ^ g_260)) % (unsigned char)p_68) <= g_260) << (short)p_68))
    {
        unsigned char l_362 = 0xC1L;
        step_hash(188);
        for (g_106 = 0; (g_106 != 33); g_106 += 1)
        {
            int *l_353 = &g_101;
            step_hash(180);
            (*g_97) = l_353;
            step_hash(181);
            (***l_320) = ((p_68 ^ ((unsigned short)((unsigned char)0x64L % (unsigned char)g_101) << (unsigned short)5)) & (-(unsigned short)g_106));
            step_hash(187);
            if (((unsigned char)p_67 >> (unsigned char)3))
            {
                int l_361 = 1L;
                step_hash(183);
                l_361 = 0x391B31A1L;
                step_hash(184);
                if ((*g_98))
                    break;
            }
            else
            {
                step_hash(186);
                (*g_97) = (*g_97);
            }
        }
        step_hash(189);
        l_362 ^= (-1L);
        step_hash(190);
        (**l_320) = (*g_97);
    }
    else
    {
        step_hash(192);
        (*l_340) = p_68;
    }
    step_hash(194);
    return g_10;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_10, "g_10", print_hash_value);
    transparent_crc(g_12, "g_12", print_hash_value);
    transparent_crc(g_92, "g_92", print_hash_value);
    transparent_crc(g_101, "g_101", print_hash_value);
    transparent_crc(g_106, "g_106", print_hash_value);
    transparent_crc(g_260, "g_260", print_hash_value);
    transparent_crc(g_448, "g_448", print_hash_value);
    transparent_crc(g_722, "g_722", print_hash_value);
    transparent_crc(g_837, "g_837", print_hash_value);
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
