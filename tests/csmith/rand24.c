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
static signed char g_4 = 0x4FL;
static int g_22 = (-6L);
static int g_43 = (-1L);
static int *g_84 = &g_22;
static int **g_83 = &g_84;
static int g_105 = 0x228C8C4EL;
static int **g_111 = (void*)0;
static int **g_139 = &g_84;
static int g_210 = 1L;
static int g_308 = 1L;
static int *g_320 = &g_43;
static unsigned g_446 = 0x5E74854BL;
static int *g_462 = &g_22;
static int *g_506 = &g_105;
static short g_752 = 0x68D4L;
static int ***g_879 = &g_111;
static short g_936 = 6L;
static int *g_937 = &g_105;
static short g_1133 = (-9L);
static signed char g_1153 = 1L;
static int g_1160 = 9L;
static unsigned func_1(void);
static int func_5(short p_6, unsigned p_7, short p_8, unsigned p_9);
static short func_13(int p_14, signed char p_15, int p_16);
static short func_30(unsigned p_31);
static short func_47(int ** p_48, signed char p_49, int ** p_50, short p_51);
static int ** func_54(int ** p_55, int * p_56, unsigned char p_57, int p_58, int p_59);
static int ** func_60(int * p_61, int ** p_62, unsigned short p_63, int * p_64, unsigned short p_65);
static int * func_66(signed char p_67, int ** p_68, int ** p_69);
static unsigned char func_74(int ** p_75, unsigned char p_76, int *** p_77);
static int ** func_78(int ** p_79, short p_80, int *** p_81, unsigned p_82);
static unsigned func_1(void)
{
    unsigned short l_10 = 0x6E7FL;
    int *l_1159 = &g_1160;
    step_hash(654);
    (*l_1159) ^= ((signed char)g_4 / (signed char)(g_4 ^ ((-1L) >= (func_5(l_10, ((short)func_13(g_4, g_4, g_4) << (short)((void*)0 == &g_139)), l_10, l_10) < 4294967295UL))));
    step_hash(655);
    return g_43;
}
static int func_5(short p_6, unsigned p_7, short p_8, unsigned p_9)
{
    int *l_1158 = &g_22;
    step_hash(652);
    (*g_83) = l_1158;
    step_hash(653);
    return p_8;
}
static short func_13(int p_14, signed char p_15, int p_16)
{
    unsigned l_20 = 0x6AB2AEE5L;
    int *l_21 = &g_22;
    int **l_913 = (void*)0;
    int l_931 = 9L;
    int *l_950 = &g_210;
    unsigned l_970 = 0x775A189CL;
    int *l_1043 = &l_931;
    int ***l_1049 = (void*)0;
    step_hash(6);
    for (p_14 = 14; (p_14 >= (-9)); p_14 -= 3)
    {
        unsigned char l_19 = 7UL;
        step_hash(5);
        return l_19;
    }
    step_hash(7);
    (*l_21) ^= l_20;
    step_hash(8);
    (*l_21) = (*l_21);
    step_hash(649);
    if (((-(unsigned short)(((unsigned short)((short)((unsigned short)(l_21 == (void*)0) * (unsigned short)(func_30((p_14 >= p_16)) & (((((0x4BEE6A9DL != p_16) > g_752) >= (l_20 == g_4)) == p_15) >= 0L))) << (short)1) - (unsigned short)p_14) <= p_16)) >= p_15))
    {
        int *l_838 = &g_22;
        unsigned l_873 = 0x44F583B3L;
        step_hash(517);
        if (p_16)
        {
            int **l_848 = &l_838;
            int *l_874 = &g_22;
            signed char l_883 = 0L;
            int *l_898 = &g_210;
            step_hash(463);
            for (l_20 = 0; (l_20 < 50); l_20++)
            {
                int l_837 = 0x260BA5A2L;
                step_hash(460);
                (*l_21) = l_837;
                step_hash(461);
                (*g_462) &= (g_308 > ((1L ^ g_4) >= g_446));
                step_hash(462);
                (*g_83) = l_838;
            }
            step_hash(514);
            if (((unsigned short)g_752 * (unsigned short)(&g_320 != (void*)0)))
            {
                int **l_845 = &g_320;
                int *l_849 = &g_43;
                step_hash(465);
                (*l_849) ^= ((signed char)p_15 << (signed char)((((g_105 < (*g_462)) == ((signed char)((void*)0 == l_845) / (signed char)1L)) > 0x5305L) & ((unsigned short)(0L == (l_845 == l_848)) / (unsigned short)p_15)));
                step_hash(466);
                (*l_849) |= ((**l_848) ^ ((p_14 > 0x1EL) && (((int)p_15 % (int)p_16) & ((unsigned char)(!(*l_838)) << (unsigned char)2))));
                step_hash(467);
                (*l_838) = p_16;
                step_hash(491);
                for (p_14 = 0; (p_14 < 10); p_14 += 1)
                {
                    int l_864 = 0xB6BDF3CAL;
                    int **l_880 = &g_320;
                    short l_890 = 0L;
                    step_hash(471);
                    (*l_845) = (void*)0;
                    step_hash(478);
                    if (((~(p_14 < ((*l_21) ^ 0xE7A5L))) ^ (*l_21)))
                    {
                        unsigned l_865 = 4294967288UL;
                        step_hash(473);
                        p_16 = ((int)((signed char)(((signed char)((unsigned)(!(0xD6L == (l_864 & l_865))) / (unsigned)(**l_848)) - (signed char)(&g_462 == (void*)0)) > (**l_848)) / (signed char)p_15) - (int)0xDEC67F50L);
                        step_hash(474);
                        if (l_865)
                            continue;
                        step_hash(475);
                        if (p_15)
                            continue;
                    }
                    else
                    {
                        unsigned l_866 = 0x68482710L;
                        step_hash(477);
                        if (l_866)
                            break;
                    }
                    step_hash(489);
                    if (((int)((signed char)0x7DL << (signed char)0) + (int)(**l_848)))
                    {
                        unsigned short l_881 = 1UL;
                        int l_882 = 0x2E96267DL;
                        step_hash(480);
                        l_882 |= ((unsigned char)(&g_462 == (void*)0) - (unsigned char)((p_14 || (*l_21)) > (*l_838)));
                        step_hash(481);
                        if (p_15)
                            break;
                        step_hash(482);
                        (*g_139) = &p_14;
                        step_hash(483);
                        return g_43;
                    }
                    else
                    {
                        short l_897 = 0x19A3L;
                        step_hash(485);
                        (*l_849) ^= 0L;
                        step_hash(486);
                        p_16 ^= (l_883 && (&l_845 != &l_848));
                        step_hash(487);
                        (*g_139) = l_838;
                        step_hash(488);
                        (*l_838) = (*g_84);
                    }
                    step_hash(490);
                    (**l_848) = p_16;
                }
            }
            else
            {
                int *l_899 = &g_105;
                int ***l_906 = &g_111;
                step_hash(493);
                l_899 = l_898;
                step_hash(494);
                (*l_848) = l_838;
                step_hash(512);
                for (l_20 = 15; (l_20 <= 30); l_20 += 1)
                {
                    int **l_912 = &l_874;
                    step_hash(498);
                    if ((*l_899))
                        break;
                    step_hash(499);
                    (*l_838) |= 0x1978A630L;
                    step_hash(506);
                    for (p_15 = 0; (p_15 <= (-13)); --p_15)
                    {
                        unsigned char l_907 = 0xB3L;
                        step_hash(503);
                        (*l_899) &= ((l_907 & (**l_848)) == g_446);
                        step_hash(504);
                        (*l_848) = &p_16;
                        step_hash(505);
                        (*g_462) &= (*l_838);
                    }
                    step_hash(511);
                    for (l_883 = 0; (l_883 <= 26); l_883 += 1)
                    {
                        int *l_926 = &g_105;
                        step_hash(510);
                        p_14 = ((short)((short)p_14 * (short)(((short)p_16 - (short)((*l_899) != (p_15 || ((p_14 ^ (((void*)0 == l_21) || (~((unsigned short)(p_15 | p_16) + (unsigned short)0x1ECBL)))) > (*l_21))))) < 0xE5L)) * (short)65535UL);
                    }
                }
                step_hash(513);
                (*l_848) = (void*)0;
            }
        }
        else
        {
            step_hash(516);
            (*g_462) = ((+(0xE2L < (+p_14))) | ((*l_838) <= 1UL));
        }
        step_hash(522);
        for (p_15 = 0; (p_15 >= 3); p_15 += 7)
        {
            step_hash(521);
            p_14 |= ((signed char)(p_15 | p_15) % (signed char)(~l_931));
        }
        step_hash(523);
        (*g_139) = l_838;
        step_hash(524);
        (*g_83) = g_937;
    }
    else
    {
        unsigned l_938 = 0xA6DF25F7L;
        int ***l_940 = &g_83;
        int *l_967 = &g_210;
        signed char l_986 = 8L;
        int l_1002 = 0x4DF677A3L;
        unsigned l_1005 = 4294967295UL;
        signed char l_1022 = 0x9AL;
        unsigned l_1045 = 1UL;
        int **l_1105 = &g_84;
        int **l_1130 = &l_1043;
        short l_1147 = (-1L);
        step_hash(572);
        if (l_938)
        {
            int **l_939 = &g_84;
            int l_949 = 0L;
            step_hash(527);
            (*l_21) = p_16;
            step_hash(557);
            if (p_15)
            {
                int *l_943 = &g_105;
                step_hash(533);
                for (p_15 = 0; (p_15 >= (-13)); p_15--)
                {
                    step_hash(532);
                    l_939 = (void*)0;
                }
                step_hash(534);
                (*g_83) = l_943;
                step_hash(547);
                for (g_308 = 0; (g_308 >= 28); g_308 += 1)
                {
                    int *l_948 = &l_931;
                    step_hash(538);
                    (**l_940) = &p_16;
                    step_hash(546);
                    for (p_15 = 0; (p_15 == (-19)); p_15 -= 1)
                    {
                        step_hash(542);
                        (*g_462) ^= p_16;
                        step_hash(543);
                        (*g_83) = l_948;
                        step_hash(544);
                        (*g_139) = &p_14;
                        step_hash(545);
                        (*g_139) = (void*)0;
                    }
                }
            }
            else
            {
                short l_955 = 0x2641L;
                step_hash(549);
                (*l_21) = (~(*g_937));
                step_hash(550);
                (*l_950) ^= p_14;
                step_hash(551);
                (*l_21) &= ((p_16 && (((signed char)g_105 * (signed char)0UL) ^ ((unsigned)((unsigned char)l_955 + (unsigned char)p_14) / (unsigned)((signed char)g_210 + (signed char)g_446)))) > p_15);
                step_hash(556);
                for (g_22 = 20; (g_22 > (-28)); g_22--)
                {
                    int **l_966 = (void*)0;
                    step_hash(555);
                    l_966 = l_939;
                }
            }
            step_hash(558);
            (*l_21) ^= (*l_950);
            step_hash(559);
            (*g_83) = (void*)0;
        }
        else
        {
            int ***l_989 = &l_913;
            step_hash(561);
            (*g_139) = l_967;
            step_hash(569);
            if ((g_446 | ((-3L) ^ 0UL)))
            {
                int l_971 = 0x6445514DL;
                int **l_974 = &g_84;
                step_hash(563);
                (*g_462) = ((l_971 || ((g_210 | l_971) == (*l_967))) ^ ((unsigned short)g_4 % (unsigned short)func_74(l_974, ((void*)0 != &p_16), &l_974)));
                step_hash(564);
                (*g_462) &= ((short)((unsigned short)p_15 >> (unsigned short)2) >> (short)13);
            }
            else
            {
                int l_981 = 7L;
                unsigned char l_990 = 0UL;
                int ***l_995 = &g_139;
                step_hash(566);
                (***l_940) ^= (((int)p_16 % (int)l_981) ^ ((int)((unsigned char)((g_105 & l_986) && ((0UL & p_16) | ((unsigned char)g_22 - (unsigned char)(l_989 != l_989)))) * (unsigned char)l_990) - (int)0x019B49C3L));
                step_hash(567);
                (*g_937) = 0x8FE6FA11L;
                step_hash(568);
                (*g_937) = ((unsigned char)(p_16 != ((short)(g_4 && (&g_111 == (void*)0)) - (short)1L)) << (unsigned char)func_74((*l_989), g_210, l_995));
            }
            step_hash(570);
            (*g_83) = (*g_83);
            step_hash(571);
            (*l_21) = ((int)p_14 + (int)p_14);
        }
        step_hash(643);
        for (l_938 = 0; (l_938 != 33); l_938 += 3)
        {
            unsigned short l_1037 = 65528UL;
            int **l_1046 = &l_950;
            short l_1091 = 1L;
        }
        step_hash(648);
        for (p_14 = 0; (p_14 == 14); ++p_14)
        {
            unsigned short l_1157 = 3UL;
            step_hash(647);
            return l_1157;
        }
    }
    step_hash(650);
    return g_4;
}
static short func_30(unsigned p_31)
{
    unsigned l_44 = 0x19C2B2E5L;
    int *l_203 = (void*)0;
    int ***l_265 = &g_83;
    int l_266 = (-1L);
    int l_275 = 0xC5E8B852L;
    signed char l_330 = 0xECL;
    int **l_337 = &l_203;
    int *l_366 = &l_266;
    int **l_430 = &l_366;
    int **l_532 = &g_320;
    unsigned char l_637 = 0UL;
    unsigned char l_686 = 1UL;
    unsigned char l_696 = 255UL;
    step_hash(239);
    if (((int)g_4 + (int)((short)0x32E2L % (short)(g_4 || (p_31 & p_31)))))
    {
        step_hash(21);
        for (g_22 = 0; (g_22 == 15); g_22 += 2)
        {
            int *l_41 = (void*)0;
            int **l_40 = &l_41;
            step_hash(19);
            for (p_31 = (-9); (p_31 >= 18); p_31 += 8)
            {
                int ***l_42 = &l_40;
                step_hash(17);
                (*l_42) = l_40;
                step_hash(18);
                g_43 |= g_4;
            }
            step_hash(20);
            l_44 = g_43;
        }
        step_hash(22);
        return l_44;
    }
    else
    {
        unsigned l_53 = 0x359A7032L;
        int *l_96 = &g_22;
        int **l_95 = &l_96;
        int ***l_94 = &l_95;
        int l_231 = 0x082C358FL;
        unsigned char l_234 = 0x84L;
        unsigned l_245 = 1UL;
        unsigned l_298 = 0xD62F63DBL;
        unsigned short l_304 = 1UL;
        step_hash(238);
        for (g_22 = (-14); (g_22 >= 2); g_22 += 3)
        {
            int **l_52 = (void*)0;
            short l_200 = 0x97FDL;
            int *l_272 = (void*)0;
            unsigned l_300 = 4294967295UL;
            int *l_316 = (void*)0;
            int *l_317 = &l_275;
            unsigned l_331 = 0x68BDD198L;
        }
    }
    step_hash(240);
    (*l_366) &= ((signed char)(p_31 ^ p_31) - (signed char)((***l_265) != ((signed char)((unsigned char)(((***l_265) && (g_43 ^ ((unsigned char)p_31 / (unsigned char)(((unsigned short)p_31 >> (unsigned short)((short)((unsigned)(((unsigned short)(g_43 < g_105) + (unsigned short)p_31) > 0x2750865FL) % (unsigned)p_31) + (short)g_308)) | 0x2741L)))) < g_43) / (unsigned char)255UL) << (signed char)3)));
    step_hash(336);
    if (((unsigned short)(0x995FL | g_105) * (unsigned short)(((signed char)0x2FL - (signed char)g_210) != g_43)))
    {
        step_hash(242);
        (*g_83) = (**l_265);
    }
    else
    {
        int *l_371 = &g_22;
        short l_435 = 0x1B91L;
        int ***l_449 = &g_139;
        step_hash(275);
        if (((*l_265) == (void*)0))
        {
            int l_390 = 0x48FA1405L;
            signed char l_391 = (-1L);
            step_hash(245);
            (**l_265) = (*g_139);
            step_hash(246);
            l_371 = func_66(g_4, &g_320, (*l_265));
            step_hash(247);
            (*g_83) = (*g_83);
        }
        else
        {
            unsigned char l_404 = 250UL;
            int **l_407 = &l_203;
            int **l_423 = (void*)0;
            int *l_454 = &l_266;
            step_hash(267);
            if (((*l_371) && (((*l_371) < (&g_320 == (void*)0)) != p_31)))
            {
                unsigned char l_406 = 5UL;
                int l_414 = 1L;
                int ***l_440 = &l_423;
                step_hash(256);
                for (l_266 = 0; (l_266 == 2); l_266++)
                {
                    int l_405 = 1L;
                    step_hash(253);
                    (**l_265) = (*g_139);
                }
                step_hash(257);
                (*g_320) = ((signed char)((p_31 > ((short)(&g_111 == &l_407) / (short)p_31)) >= g_105) + (signed char)p_31);
                step_hash(258);
                (*g_320) = (((65535UL & (~((unsigned)(~((unsigned char)((int)func_47(&g_320, p_31, l_430, g_308) * (int)(&l_414 == (void*)0)) * (unsigned char)(((*l_371) < (*l_371)) > p_31))) + (unsigned)3L))) & p_31) >= 1L);
                step_hash(259);
                l_414 = func_47(l_407, ((p_31 > ((0x96A58D8CL || ((short)func_47(&g_320, (((short)((*l_371) | p_31) + (short)((l_435 > g_43) != 0xC6L)) != p_31), &g_320, g_210) >> (short)g_308)) ^ 2UL)) < g_22), &l_371, g_308);
            }
            else
            {
                int **l_445 = &l_203;
                step_hash(265);
                for (l_266 = 0; (l_266 < 24); l_266++)
                {
                    step_hash(264);
                    (**g_83) = ((unsigned char)((l_445 != (void*)0) > (1UL & g_446)) / (unsigned char)0x9CL);
                }
                step_hash(266);
                (**g_83) = ((unsigned)0x95DDFB32L - (unsigned)((l_449 == (void*)0) < g_22));
            }
            step_hash(268);
            (**l_449) = (*l_430);
            step_hash(273);
            for (l_435 = 0; (l_435 <= (-22)); --l_435)
            {
                int *l_452 = (void*)0;
                int *l_453 = &g_210;
                step_hash(272);
                (*l_453) ^= (*l_366);
            }
            step_hash(274);
            (*l_454) |= (*g_320);
        }
        step_hash(334);
        if ((p_31 | p_31))
        {
            signed char l_457 = (-1L);
            int l_479 = (-1L);
            int l_490 = 0x6BD2E50EL;
            short l_491 = 0x67CBL;
            int **l_502 = &l_366;
            step_hash(307);
            for (l_275 = 0; (l_275 <= (-9)); --l_275)
            {
                unsigned l_458 = 4UL;
                int **l_461 = &l_203;
                short l_478 = 0x00F8L;
                step_hash(280);
                if (l_457)
                    break;
            }
            step_hash(308);
            l_479 = ((int)((void*)0 == (*l_265)) % (int)4294967294UL);
            step_hash(309);
            (*g_462) ^= func_47(func_54(&g_84, (*l_337), p_31, ((short)((*l_449) != (*l_265)) >> (short)p_31), p_31), g_446, l_502, g_308);
        }
        else
        {
            int **l_505 = &l_371;
            int l_550 = 0x114C46B2L;
            step_hash(332);
            if (((int)(l_505 == &g_462) - (int)(4L < (g_308 ^ 0UL))))
            {
                signed char l_522 = 0x57L;
                int l_525 = 7L;
                int ***l_531 = &l_337;
                step_hash(312);
                g_506 = (*g_139);
                step_hash(325);
                for (g_43 = 0; (g_43 < 5); g_43 += 5)
                {
                    int **l_509 = &g_84;
                    step_hash(324);
                    if (func_47(l_509, (~(-1L)), l_509, ((signed char)p_31 << (signed char)0)))
                    {
                        step_hash(317);
                        if (p_31)
                            break;
                        step_hash(318);
                        l_525 |= ((**l_505) <= (((unsigned)((unsigned)p_31 + (unsigned)((signed char)((unsigned char)((((signed char)p_31 >> (signed char)6) < p_31) | (-6L)) / (unsigned char)l_522) >> (signed char)0)) - (unsigned)0L) > ((signed char)p_31 << (signed char)1)));
                    }
                    else
                    {
                        int l_526 = (-1L);
                        step_hash(320);
                        (*g_462) = l_526;
                        step_hash(321);
                        if ((**l_505))
                            break;
                        step_hash(322);
                        (*l_366) &= ((unsigned char)1UL / (unsigned char)(0x06F7L & ((+g_446) && ((&g_506 != (void*)0) || (+((*l_430) != (*l_337)))))));
                        step_hash(323);
                        (*l_337) = (*g_83);
                    }
                }
                step_hash(326);
                (**l_430) = (((short)((g_43 || ((!p_31) < (0x2CL < g_105))) > g_22) + (short)1UL) | p_31);
                step_hash(327);
                (*l_337) = (**l_449);
            }
            else
            {
                short l_539 = 0L;
                int **l_549 = &g_462;
                step_hash(329);
                l_550 &= ((signed char)((short)((short)l_539 - (short)((short)((-(short)((short)(1UL != ((0x85L >= ((unsigned char)((unsigned short)(**l_532) << (unsigned short)(*l_366)) - (unsigned char)g_446)) >= p_31)) >> (short)0)) == g_4) - (short)p_31)) >> (short)6) << (signed char)p_31);
                step_hash(330);
                (*g_506) |= (*g_462);
                step_hash(331);
                return p_31;
            }
            step_hash(333);
            l_550 &= ((signed char)((signed char)((unsigned char)((signed char)(!(p_31 | ((p_31 && func_47((*l_265), p_31, &g_506, ((unsigned char)((unsigned char)((((signed char)0x0BL >> (signed char)6) == (((*g_83) == (*l_505)) | ((-(int)(((p_31 & 248UL) > 8UL) <= (**l_532))) >= (**l_505)))) & 0x01C2B71EL) * (unsigned char)0x14L) >> (unsigned char)g_308))) >= 6UL))) * (signed char)p_31) % (unsigned char)g_43) >> (signed char)g_22) << (signed char)g_446);
        }
        step_hash(335);
        (*g_462) ^= ((int)((unsigned)0UL % (unsigned)((unsigned)(func_47(&g_320, ((g_105 > p_31) ^ (((short)p_31 >> (short)11) != ((*g_83) == (**l_449)))), (*l_265), g_210) > 0UL) % (unsigned)p_31)) % (int)g_446);
    }
    step_hash(453);
    if (((&g_139 != (void*)0) <= (((short)((+(((0x7E00L >= ((&l_532 != (void*)0) | (((g_210 != p_31) <= g_446) || 0x908CFF1AL))) & 0x4AF7L) > 0xDEL)) || p_31) / (short)(**l_532)) <= g_308)))
    {
        int l_580 = 8L;
        int **l_585 = &g_506;
        short l_588 = 6L;
        int l_638 = 8L;
        int l_710 = 0xFC046B83L;
        step_hash(338);
        l_580 &= ((signed char)(!p_31) << (signed char)(((void*)0 == &g_462) > (!(**l_532))));
        step_hash(403);
        if (((unsigned)l_580 % (unsigned)((short)func_47((*l_265), p_31, func_60((*l_337), l_585, ((((**l_532) ^ ((0xC2L || g_446) < (((g_210 == 246UL) <= g_105) ^ 0L))) >= p_31) ^ l_588), (*l_337), g_210), g_105) << (short)10)))
        {
            int l_589 = 0xE6702D9FL;
            int l_590 = 9L;
            int ***l_601 = (void*)0;
            step_hash(340);
            l_590 |= l_589;
            step_hash(349);
            for (g_308 = 21; (g_308 >= (-1)); g_308--)
            {
                step_hash(348);
                for (g_210 = 0; (g_210 != (-8)); g_210 -= 1)
                {
                    int ***l_602 = &l_337;
                    step_hash(347);
                    (*g_462) = ((~((short)(p_31 != p_31) >> (short)10)) > ((*g_462) ^ ((unsigned)(((((unsigned char)(p_31 || ((l_601 != l_602) == 0x2C0FL)) << (unsigned char)g_4) >= p_31) < 0x9D9F0F6EL) <= 0x68L) / (unsigned)p_31)));
                }
            }
            step_hash(350);
            return g_22;
        }
        else
        {
            unsigned l_609 = 0x2C7CA220L;
            int **l_616 = &g_320;
            step_hash(401);
            if (((p_31 != ((signed char)(p_31 <= (((signed char)(g_43 && (3L || (p_31 < g_210))) - (signed char)l_609) == ((unsigned)((p_31 <= ((short)(((short)(g_105 | 0L) - (short)1L) ^ (**l_616)) % (short)p_31)) == g_105) - (unsigned)p_31))) * (signed char)0x61L)) != g_210))
            {
                int ***l_630 = &l_585;
                step_hash(373);
                if (p_31)
                {
                    int **l_636 = (void*)0;
                    step_hash(354);
                    (*g_320) = ((signed char)p_31 * (signed char)(0x29C4L & p_31));
                    step_hash(361);
                    if ((**l_616))
                    {
                        step_hash(356);
                        (*g_320) = (**l_616);
                        step_hash(357);
                        (*g_462) = (((((signed char)func_47((*l_265), g_308, l_616, (-(unsigned char)((unsigned short)((signed char)p_31 << (signed char)1) % (unsigned short)((signed char)(&l_430 != &g_83) + (signed char)(&l_616 != l_630))))) - (signed char)p_31) | 0x8C98L) || g_446) == p_31);
                    }
                    else
                    {
                        int *l_631 = &g_105;
                        step_hash(359);
                        (*l_532) = l_631;
                        step_hash(360);
                        (**l_532) ^= (g_446 || ((int)(+((void*)0 != (*l_630))) / (int)((short)g_308 << (short)((*l_265) == &g_320))));
                    }
                    step_hash(368);
                    if (p_31)
                    {
                        step_hash(363);
                        (*l_616) = (*g_139);
                    }
                    else
                    {
                        int **l_647 = &g_462;
                        int l_648 = 0xF871930BL;
                        step_hash(365);
                        (**l_630) = (*g_139);
                        step_hash(366);
                        (**l_265) = (*l_585);
                        step_hash(367);
                        l_648 &= func_47(l_636, g_308, func_54((*l_265), (**l_630), ((unsigned short)((short)g_22 << (short)4) * (unsigned short)((signed char)p_31 + (signed char)((unsigned char)(((g_4 > 0x5092AF5EL) > (**l_647)) != p_31) << (unsigned char)g_308))), p_31, p_31), (**l_647));
                    }
                }
                else
                {
                    signed char l_649 = 0xF9L;
                    step_hash(370);
                    (*g_139) = (**l_630);
                    step_hash(371);
                    l_649 = (&g_320 != (void*)0);
                    step_hash(372);
                    (*l_337) = (*g_139);
                }
                step_hash(380);
                for (l_44 = 0; (l_44 >= 55); ++l_44)
                {
                    int *l_652 = &g_210;
                    step_hash(377);
                    (**l_630) = l_652;
                    step_hash(378);
                    (**l_585) = (-(unsigned char)p_31);
                    step_hash(379);
                    if ((***l_630))
                        break;
                }
            }
            else
            {
                unsigned short l_666 = 0x0190L;
                int **l_695 = (void*)0;
                step_hash(398);
                for (l_266 = 0; (l_266 == (-6)); --l_266)
                {
                    int l_697 = 0xA2A8F651L;
                }
                step_hash(399);
                l_710 ^= ((4294967295UL && ((unsigned char)(p_31 ^ p_31) + (unsigned char)((unsigned short)((unsigned short)((signed char)p_31 << (signed char)5) >> (unsigned short)(((signed char)((-10L) != l_588) / (signed char)((signed char)g_446 >> (signed char)2)) | ((((*g_139) == (void*)0) != 0x8E0AA272L) == 0x8364L))) - (unsigned short)g_43))) || g_308);
                step_hash(400);
                (*g_320) = (p_31 | ((void*)0 != l_585));
            }
            step_hash(402);
            return g_43;
        }
    }
    else
    {
        int *l_711 = &g_22;
        int ***l_718 = &g_111;
        unsigned l_719 = 0x8713BA92L;
        int l_800 = 0L;
        step_hash(405);
        (*l_430) = l_711;
        step_hash(406);
        (*g_139) = (*g_83);
        step_hash(407);
        (*g_462) |= ((!((unsigned short)((unsigned short)p_31 * (unsigned short)g_210) * (unsigned short)((+(((unsigned short)((&g_111 == l_718) != ((void*)0 != &g_83)) + (unsigned short)0x3BBEL) > (-5L))) != p_31))) ^ l_719);
        step_hash(452);
        for (g_210 = 0; (g_210 > (-13)); g_210 -= 7)
        {
            int l_749 = 1L;
            int *l_765 = &l_275;
            short l_818 = 0x2A4EL;
            int ***l_833 = &g_139;
            step_hash(451);
            for (l_637 = 0; (l_637 < 24); l_637 += 5)
            {
                unsigned l_750 = 0x383A0A6AL;
                int ***l_751 = &l_532;
                unsigned l_753 = 2UL;
                unsigned short l_762 = 4UL;
                step_hash(448);
                if (((signed char)((signed char)((unsigned)((unsigned short)((unsigned short)p_31 * (unsigned short)((*l_265) != (*l_265))) << (unsigned short)1) - (unsigned)((unsigned short)0xF0DAL + (unsigned short)0x965DL)) * (signed char)0x09L) << (signed char)0))
                {
                    int **l_748 = (void*)0;
                    int *l_756 = &g_22;
                    step_hash(423);
                    if (((int)((short)(((int)0L - (int)((g_308 != (247UL & ((((signed char)p_31 + (signed char)p_31) == p_31) >= p_31))) >= 1L)) != g_752) / (short)9L) + (int)l_753))
                    {
                        int l_759 = 0x362D7EC4L;
                        step_hash(416);
                        (*l_337) = (*g_139);
                        step_hash(417);
                        (*g_83) = (*g_139);
                        step_hash(418);
                        (**l_532) = (*l_366);
                    }
                    else
                    {
                        unsigned l_766 = 4UL;
                        step_hash(420);
                        (*g_139) = (*g_139);
                        step_hash(421);
                        (*l_756) = (*g_320);
                        step_hash(422);
                        (*g_320) ^= (7UL != (+(((signed char)g_210 + (signed char)(0xAC429852L > p_31)) ^ p_31)));
                    }
                    step_hash(424);
                    (*g_83) = (void*)0;
                }
                else
                {
                    short l_780 = (-2L);
                    int **l_801 = &g_320;
                    int l_816 = 1L;
                    unsigned char l_834 = 0xFBL;
                    step_hash(431);
                    if (p_31)
                    {
                        int ***l_779 = &g_111;
                        step_hash(427);
                        (*g_320) = ((unsigned short)p_31 + (unsigned short)(((((*g_462) | (**l_430)) != (g_308 < ((*l_711) > p_31))) && l_780) > 1UL));
                        step_hash(428);
                        return g_105;
                    }
                    else
                    {
                        unsigned l_781 = 0UL;
                        step_hash(430);
                        (**l_430) &= l_781;
                    }
                    step_hash(440);
                    if (((((unsigned)(((unsigned char)(((int)(~(-1L)) % (int)(**l_430)) || ((unsigned short)((signed char)((unsigned char)((signed char)((l_718 == (void*)0) | (((short)0x8A04L % (short)((*l_711) | 7L)) == 3L)) * (signed char)0xCEL) - (unsigned char)(-1L)) * (signed char)g_308) >> (unsigned short)(*l_765))) * (unsigned char)g_22) <= (***l_751)) / (unsigned)g_22) != (*l_765)) ^ p_31))
                    {
                        int **l_804 = (void*)0;
                        step_hash(433);
                        (*l_430) = (**l_751);
                        step_hash(434);
                        if (p_31)
                            continue;
                        step_hash(435);
                        (**l_801) = ((unsigned short)((void*)0 != l_804) << (unsigned short)(**l_430));
                    }
                    else
                    {
                        short l_807 = (-4L);
                        int ***l_817 = &g_83;
                        step_hash(437);
                        (*g_320) = ((unsigned short)(l_807 < (~p_31)) / (unsigned short)((short)(p_31 > (0x6537L > (((unsigned short)((+(((***l_751) || p_31) > ((unsigned short)l_816 >> (unsigned short)g_105))) < (l_817 != &l_801)) % (unsigned short)l_818) || 0L))) % (short)(*l_711)));
                        step_hash(438);
                        if (p_31)
                            break;
                        step_hash(439);
                        return p_31;
                    }
                    step_hash(441);
                    (*l_751) = &g_462;
                    step_hash(447);
                    for (l_44 = 0; (l_44 != 59); l_44++)
                    {
                        step_hash(445);
                        l_834 |= ((signed char)((unsigned char)(((short)p_31 * (short)(+((*l_765) <= ((g_22 <= ((unsigned char)((void*)0 == &g_84) << (unsigned char)0)) != (p_31 > (((unsigned char)((g_43 >= (-1L)) ^ g_105) - (unsigned char)(-1L)) && p_31)))))) | p_31) % (unsigned char)p_31) << (signed char)4);
                        step_hash(446);
                        (**l_833) = (*g_83);
                    }
                }
                step_hash(449);
                if (p_31)
                    continue;
                step_hash(450);
                return (***l_751);
            }
        }
    }
    step_hash(454);
    return g_22;
}
static short func_47(int ** p_48, signed char p_49, int ** p_50, short p_51)
{
    int **l_211 = &g_84;
    unsigned short l_212 = 0x423DL;
    int l_221 = 9L;
    step_hash(146);
    (*p_50) = (*g_139);
    step_hash(147);
    l_221 ^= (l_212 != p_51);
    step_hash(162);
    for (g_210 = (-15); (g_210 >= (-14)); g_210 += 5)
    {
        short l_229 = (-10L);
        int l_230 = 0xB9702AB0L;
        step_hash(161);
        for (p_51 = 0; (p_51 == (-14)); --p_51)
        {
            unsigned char l_228 = 255UL;
            step_hash(158);
            for (g_105 = 17; (g_105 < 9); g_105 -= 5)
            {
                step_hash(157);
                (*l_211) = (*p_50);
            }
            step_hash(159);
            l_230 = (((1UL == (!l_228)) ^ l_229) >= 0xE3192B74L);
            step_hash(160);
            l_221 = (((&p_48 != (void*)0) >= ((g_210 >= p_49) && l_228)) ^ l_229);
        }
    }
    step_hash(163);
    (*l_211) = (*l_211);
    step_hash(164);
    return g_4;
}
static int ** func_54(int ** p_55, int * p_56, unsigned char p_57, int p_58, int p_59)
{
    step_hash(142);
    for (g_105 = 0; (g_105 >= (-17)); --g_105)
    {
        step_hash(141);
        for (p_58 = 10; (p_58 == (-7)); --p_58)
        {
            int *l_208 = &g_43;
            int *l_209 = &g_210;
            step_hash(139);
            (*p_55) = l_208;
            step_hash(140);
            (*l_209) &= (*g_84);
        }
    }
    step_hash(143);
    (*g_139) = (*p_55);
    step_hash(144);
    return &g_84;
}
static int ** func_60(int * p_61, int ** p_62, unsigned short p_63, int * p_64, unsigned short p_65)
{
    int **l_201 = (void*)0;
    int **l_202 = &g_84;
    step_hash(130);
    (*p_62) = (*p_62);
    step_hash(131);
    return l_202;
}
static int * func_66(signed char p_67, int ** p_68, int ** p_69)
{
    int l_112 = 0xADFF6575L;
    int l_113 = 0xE7F8E482L;
    int ***l_122 = &g_111;
    short l_179 = 0xE59AL;
    int *l_199 = &g_105;
    step_hash(60);
    l_113 |= (!l_112);
    step_hash(127);
    for (p_67 = 10; (p_67 > 29); ++p_67)
    {
        int l_116 = 0xC3E4F79CL;
        int **l_121 = &g_84;
        int l_123 = 0L;
        int **l_160 = (void*)0;
        step_hash(126);
        if (((l_112 <= (l_116 == 7L)) > ((p_69 == (void*)0) && ((unsigned short)(((unsigned short)(**l_121) + (unsigned short)p_67) >= 1L) << (unsigned short)g_4))))
        {
            int *l_124 = &g_22;
            step_hash(65);
            l_123 |= ((*g_84) & (**l_121));
            step_hash(66);
            (*l_121) = l_124;
        }
        else
        {
            int l_127 = (-5L);
            int *l_133 = &g_105;
            int ***l_165 = (void*)0;
            short l_196 = 0xF759L;
            step_hash(113);
            if (((short)(((*l_121) == &g_43) && 0x1765L) * (short)((((*l_121) != &g_22) == p_67) >= (**l_121))))
            {
                int l_134 = 2L;
                step_hash(69);
                l_127 ^= 1L;
                step_hash(80);
                for (l_127 = 0; (l_127 > (-22)); --l_127)
                {
                    step_hash(78);
                    if ((((signed char)(-1L) / (signed char)0x0AL) != (-(unsigned)p_67)))
                    {
                        step_hash(74);
                        return l_133;
                    }
                    else
                    {
                        step_hash(76);
                        (*l_133) = (g_4 > (*l_133));
                        step_hash(77);
                        (*l_121) = (void*)0;
                    }
                    step_hash(79);
                    (*l_133) = ((p_67 != 65528UL) != l_134);
                }
                step_hash(81);
                (*l_133) &= 0x87D55B84L;
            }
            else
            {
                unsigned short l_153 = 0x0210L;
                int **l_178 = &l_133;
                step_hash(88);
                for (g_43 = 9; (g_43 != (-10)); --g_43)
                {
                    signed char l_140 = 6L;
                    int l_141 = 4L;
                    step_hash(86);
                    l_141 &= (0x2FL < (((unsigned short)65531UL + (unsigned short)p_67) == func_74(g_139, l_140, &g_139)));
                    step_hash(87);
                    if ((*l_133))
                        break;
                }
                step_hash(112);
                if (((signed char)((0xCB140037L > (*g_84)) <= ((unsigned char)((unsigned short)((unsigned char)(~((signed char)(((**l_121) > (((-(unsigned short)(l_153 != (*l_133))) & ((((((short)(**l_121) + (short)((signed char)g_22 % (signed char)p_67)) & (&p_68 == &g_83)) & 0xE8F3L) < p_67) == (*g_84))) == p_67)) <= p_67) >> (signed char)0)) / (unsigned char)g_43) * (unsigned short)p_67) + (unsigned char)g_4)) + (signed char)250UL))
                {
                    unsigned char l_177 = 255UL;
                    step_hash(96);
                    if (((int)p_67 % (int)2L))
                    {
                        step_hash(91);
                        (*l_133) ^= ((&g_84 == (void*)0) ^ ((void*)0 == &g_84));
                    }
                    else
                    {
                        step_hash(93);
                        (*l_122) = l_178;
                        step_hash(94);
                        l_179 = (!0x1F273F2FL);
                        step_hash(95);
                        (**g_111) |= (-2L);
                    }
                    step_hash(97);
                    (*l_133) = ((int)((short)((*g_139) == (*l_178)) * (short)(((signed char)(p_67 ^ g_105) << (signed char)5) & p_67)) * (int)(((unsigned)(p_67 | ((short)(**l_178) / (short)(**l_121))) / (unsigned)(-2L)) == (*l_133)));
                }
                else
                {
                    short l_195 = 0x316CL;
                    step_hash(106);
                    for (g_105 = 15; (g_105 < 12); --g_105)
                    {
                        unsigned short l_192 = 0x843EL;
                        int *l_193 = &l_112;
                        step_hash(102);
                        l_192 = (**g_139);
                        step_hash(103);
                        (*l_193) &= (**l_121);
                        step_hash(104);
                        (*l_193) = (*l_133);
                        step_hash(105);
                        (*l_122) = (void*)0;
                    }
                    step_hash(111);
                    if ((**g_139))
                    {
                        int *l_194 = &g_43;
                        step_hash(108);
                        l_195 = ((void*)0 == l_194);
                    }
                    else
                    {
                        step_hash(110);
                        (*l_133) = (**l_178);
                    }
                }
            }
            step_hash(114);
            l_196 = l_179;
            step_hash(124);
            if ((&g_111 == l_165))
            {
                short l_197 = 3L;
                step_hash(116);
                if (l_179)
                    break;
                step_hash(121);
                if ((!l_197))
                {
                    step_hash(118);
                    (*l_121) = (*l_121);
                }
                else
                {
                    step_hash(120);
                    if (p_67)
                        break;
                }
            }
            else
            {
                unsigned short l_198 = 1UL;
                step_hash(123);
                if (l_198)
                    break;
            }
            step_hash(125);
            (*l_121) = l_133;
        }
    }
    step_hash(128);
    return l_199;
}
static unsigned char func_74(int ** p_75, unsigned char p_76, int *** p_77)
{
    unsigned l_100 = 9UL;
    int l_101 = 0x17EDEBCDL;
    int *l_108 = (void*)0;
    int *l_109 = &g_105;
    unsigned short l_110 = 65535UL;
    step_hash(55);
    if ((*g_84))
    {
        step_hash(45);
        for (p_76 = 17; (p_76 == 2); p_76 -= 8)
        {
            int *l_99 = &g_22;
            step_hash(42);
            (**p_77) = l_99;
            step_hash(43);
            l_101 = l_100;
            step_hash(44);
            if ((*g_84))
                break;
        }
        step_hash(46);
        (**p_77) = (**p_77);
        step_hash(47);
        (**p_77) = &g_43;
    }
    else
    {
        step_hash(53);
        for (l_101 = 0; (l_101 > 11); l_101 += 7)
        {
            int *l_104 = &g_105;
            step_hash(52);
            (*l_104) |= 0xD5260469L;
        }
        step_hash(54);
        l_101 = ((unsigned char)g_4 * (unsigned char)p_76);
    }
    step_hash(56);
    (*l_109) = ((l_100 <= (((void*)0 != &p_75) || 0x647B0CB4L)) < g_22);
    step_hash(57);
    (*l_109) = (*l_109);
    step_hash(58);
    return l_110;
}
static int ** func_78(int ** p_79, short p_80, int *** p_81, unsigned p_82)
{
    int **l_87 = (void*)0;
    signed char l_88 = 1L;
    unsigned l_90 = 0x4C0DD78FL;
    int l_91 = 0L;
    int l_92 = (-1L);
    int *l_93 = &l_91;
    step_hash(33);
    for (p_80 = 14; (p_80 >= (-8)); --p_80)
    {
        step_hash(31);
        (*p_81) = l_87;
        step_hash(32);
        (*p_79) = &g_22;
    }
    step_hash(34);
    l_91 ^= ((l_88 && ((((void*)0 != &g_84) < (-6L)) && p_80)) >= (-(unsigned char)l_90));
    step_hash(35);
    (*l_93) = l_92;
    step_hash(36);
    return (*p_81);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_22, "g_22", print_hash_value);
    transparent_crc(g_43, "g_43", print_hash_value);
    transparent_crc(g_105, "g_105", print_hash_value);
    transparent_crc(g_210, "g_210", print_hash_value);
    transparent_crc(g_308, "g_308", print_hash_value);
    transparent_crc(g_446, "g_446", print_hash_value);
    transparent_crc(g_752, "g_752", print_hash_value);
    transparent_crc(g_936, "g_936", print_hash_value);
    transparent_crc(g_1133, "g_1133", print_hash_value);
    transparent_crc(g_1153, "g_1153", print_hash_value);
    transparent_crc(g_1160, "g_1160", print_hash_value);
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
