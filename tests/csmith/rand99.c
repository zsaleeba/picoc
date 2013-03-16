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
static int g_6 = 0x398070ADL;
static signed char g_14 = 0L;
static unsigned short g_17 = 0UL;
static int g_85[5] = {(-10L), (-10L), (-10L), (-10L), (-10L)};
static int *g_129 = &g_85[1];
static unsigned g_201[3] = {1UL, 1UL, 1UL};
static unsigned short g_451 = 1UL;
static unsigned g_470 = 0x50F2087BL;
static int g_557 = 0xA0172E6EL;
static unsigned short g_643[8][3] = {{0x4692L, 0x42ABL, 0x4692L}, {0x4692L, 0x42ABL, 0x4692L}, {0x4692L, 0x42ABL, 0x4692L}, {0x4692L, 0x42ABL, 0x4692L}, {0x4692L, 0x42ABL, 0x4692L}, {0x4692L, 0x42ABL, 0x4692L}, {0x4692L, 0x42ABL, 0x4692L}, {0x4692L, 0x42ABL, 0x4692L}};
static unsigned short g_651 = 0UL;
static int g_661[3] = {(-5L), (-5L), (-5L)};
static int **g_698 = &g_129;
static int ***g_697 = &g_698;
static int g_812 = 0xD28761F7L;
static short g_838 = 1L;
static int g_860[10][10] = {{0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}, {0x07B9BE07L, 1L, (-10L), 0x13DA5BC7L, 0xB7184757L, 0xCBA38D5AL, 0xB7184757L, 0x13DA5BC7L, (-10L), 1L}};
static int ***g_871 = &g_698;
static int g_912 = 0x1F364B07L;
static int g_949 = 0x875127CDL;
static unsigned func_1(void);
static int * func_31(unsigned p_32, unsigned char p_33, int * p_34, int * p_35, unsigned p_36);
static short func_39(int * p_40, int p_41, int * p_42, int * p_43, unsigned char p_44);
static int * func_45(int * p_46, int * p_47);
static int * func_48(unsigned p_49, int * p_50, short p_51);
static int * func_53(int * p_54, int * p_55);
static int * func_56(int * p_57, int * p_58, int * p_59, int * p_60);
static int * func_61(unsigned char p_62, int * p_63);
static unsigned func_64(int * p_65, int * p_66, int p_67);
static unsigned char func_74(int * p_75, unsigned short p_76);
static unsigned func_1(void)
{
    int *l_2 = (void*)0;
    int *l_3 = (void*)0;
    int *l_4 = (void*)0;
    int *l_5 = &g_6;
    int *l_7 = &g_6;
    int *l_8 = &g_6;
    int l_9[4][9] = {{0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL}, {0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL}, {0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL}, {0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL, 0L, 0x666A756AL}};
    int *l_10 = &l_9[1][8];
    int *l_11 = &l_9[1][8];
    int *l_12 = &l_9[1][8];
    int *l_13 = &l_9[1][8];
    int *l_15 = &g_6;
    int *l_16[8] = {&l_9[1][8], &l_9[1][8], &l_9[1][8], &l_9[1][8], &l_9[1][8], &l_9[1][8], &l_9[1][8], &l_9[1][8]};
    unsigned char l_20 = 0xB6L;
    short l_23[8][5] = {{0xF11BL, 0L, 0xF11BL, 0L, 0xF11BL}, {0xF11BL, 0L, 0xF11BL, 0L, 0xF11BL}, {0xF11BL, 0L, 0xF11BL, 0L, 0xF11BL}, {0xF11BL, 0L, 0xF11BL, 0L, 0xF11BL}, {0xF11BL, 0L, 0xF11BL, 0L, 0xF11BL}, {0xF11BL, 0L, 0xF11BL, 0L, 0xF11BL}, {0xF11BL, 0L, 0xF11BL, 0L, 0xF11BL}, {0xF11BL, 0L, 0xF11BL, 0L, 0xF11BL}};
    short l_589[7][7] = {{0L, 1L, 1L, (-4L), (-10L), 0x953AL, (-1L)}, {0L, 1L, 1L, (-4L), (-10L), 0x953AL, (-1L)}, {0L, 1L, 1L, (-4L), (-10L), 0x953AL, (-1L)}, {0L, 1L, 1L, (-4L), (-10L), 0x953AL, (-1L)}, {0L, 1L, 1L, (-4L), (-10L), 0x953AL, (-1L)}, {0L, 1L, 1L, (-4L), (-10L), 0x953AL, (-1L)}, {0L, 1L, 1L, (-4L), (-10L), 0x953AL, (-1L)}};
    unsigned char l_824 = 0xBCL;
    unsigned l_855 = 0xB672D4EBL;
    int ***l_872 = &g_698;
    int l_907 = 4L;
    short l_932 = (-5L);
    int l_933[2];
    int i, j;
    for (i = 0; i < 2; i++)
        l_933[i] = 1L;
    step_hash(1);
    --g_17;
    step_hash(673);
    if ((l_20 > ((((short)l_23[6][3] << (short)8) ^ g_14) && g_6)))
    {
        unsigned l_26 = 0UL;
        int *l_615 = (void*)0;
        unsigned l_806 = 0xBF119F23L;
        int l_822 = (-1L);
        int *l_827 = &g_812;
        short l_828 = 9L;
        int *l_859 = &g_6;
        signed char l_879 = 0L;
        int **l_938 = &l_827;
        int *l_948 = (void*)0;
        step_hash(664);
        for (g_6 = 0; (g_6 <= (-15)); g_6 -= 2)
        {
            int *l_77 = &g_6;
            int l_817 = (-10L);
            int l_819[8][5] = {{1L, 0x3F151C09L, (-1L), 0L, 0L}, {1L, 0x3F151C09L, (-1L), 0L, 0L}, {1L, 0x3F151C09L, (-1L), 0L, 0L}, {1L, 0x3F151C09L, (-1L), 0L, 0L}, {1L, 0x3F151C09L, (-1L), 0L, 0L}, {1L, 0x3F151C09L, (-1L), 0L, 0L}, {1L, 0x3F151C09L, (-1L), 0L, 0L}, {1L, 0x3F151C09L, (-1L), 0L, 0L}};
            short l_930 = 0x8F86L;
            int i, j;
        }
        step_hash(669);
        for (g_6 = (-12); (g_6 < 14); g_6 += 4)
        {
            step_hash(668);
            return (*l_827);
        }
        step_hash(670);
        (*l_11) |= (func_39(func_56((**g_697), (*g_698), (**l_872), (**l_872)), func_74((**g_697), g_860[5][2]), (**l_872), (*l_938), g_949) != (**l_938));
    }
    else
    {
        step_hash(672);
        (**g_697) = (*g_698);
    }
    step_hash(674);
    return g_949;
}
static int * func_31(unsigned p_32, unsigned char p_33, int * p_34, int * p_35, unsigned p_36)
{
    int l_808 = 0L;
    int *l_814 = &g_85[1];
    step_hash(580);
    if ((***g_697))
    {
        int *l_807 = (void*)0;
        int *l_811 = &g_812;
        step_hash(576);
        (*g_698) = l_807;
        step_hash(577);
        (*l_811) ^= func_39((*g_698), ((signed char)1L + (signed char)(g_661[1] > (6UL <= ((p_32 != 1UL) >= 8L)))), l_807, l_807, p_33);
    }
    else
    {
        int *l_813 = &g_85[0];
        step_hash(579);
        (**g_697) = l_813;
    }
    step_hash(581);
    return l_814;
}
static short func_39(int * p_40, int p_41, int * p_42, int * p_43, unsigned char p_44)
{
    int ***l_793 = &g_698;
    int *l_794 = (void*)0;
    int *l_795 = &g_661[1];
    int *l_796 = &g_661[1];
    int *l_797 = &g_661[0];
    int l_798 = 0x0569EFD0L;
    int *l_799 = &g_85[0];
    int *l_800 = &l_798;
    int *l_801 = &g_85[1];
    int *l_802[3][10] = {{&g_85[0], &g_557, (void*)0, (void*)0, (void*)0, &g_557, &g_85[0], &g_661[1], &g_85[1], &g_661[1]}, {&g_85[0], &g_557, (void*)0, (void*)0, (void*)0, &g_557, &g_85[0], &g_661[1], &g_85[1], &g_661[1]}, {&g_85[0], &g_557, (void*)0, (void*)0, (void*)0, &g_557, &g_85[0], &g_661[1], &g_85[1], &g_661[1]}};
    unsigned l_803 = 0xC69B6AE2L;
    int i, j;
    step_hash(571);
    for (g_557 = 2; (g_557 >= 0); g_557 -= 1)
    {
        int *l_791 = &g_661[1];
        step_hash(570);
        for (p_41 = 0; (p_41 <= 2); p_41 += 1)
        {
            int ***l_792[8];
            int i, j;
            for (i = 0; i < 8; i++)
                l_792[i] = &g_698;
            step_hash(567);
            g_661[g_557] = func_74(l_791, (l_792[1] == l_793));
            step_hash(568);
            g_85[(g_557 + 2)] = func_74(func_56((**l_793), (**l_793), func_56(&p_41, l_791, (*g_698), (**l_793)), &p_41), g_661[p_41]);
            step_hash(569);
            if (g_643[(g_557 + 4)][g_557])
                continue;
        }
    }
    step_hash(572);
    l_803--;
    step_hash(573);
    return g_85[1];
}
static int * func_45(int * p_46, int * p_47)
{
    unsigned char l_714 = 0xE9L;
    int l_732[10] = {0xFE724599L, 0x680FE581L, 0xFE724599L, 0x680FE581L, 0xFE724599L, 0x680FE581L, 0xFE724599L, 0x680FE581L, 0xFE724599L, 0x680FE581L};
    unsigned char l_753 = 1UL;
    int **l_778 = &g_129;
    int i;
    step_hash(492);
    for (g_651 = 13; (g_651 < 32); g_651++)
    {
        int *l_709 = &g_85[1];
        int *l_710 = &g_661[1];
        int *l_711 = (void*)0;
        int *l_712 = &g_557;
        int *l_713 = &g_557;
        step_hash(491);
        --l_714;
    }
    step_hash(551);
    for (l_714 = 12; (l_714 > 6); l_714 -= 5)
    {
        unsigned short l_724 = 65534UL;
        int l_731 = 0x1CC7F592L;
        int l_756 = 0xCC4C32D2L;
        unsigned l_775 = 0x24917C87L;
        unsigned char l_785 = 0x56L;
        step_hash(510);
        for (g_470 = 0; (g_470 < 41); g_470 += 2)
        {
            int *l_722 = &g_557;
            int *l_723[7] = {(void*)0, &g_85[1], (void*)0, &g_85[1], (void*)0, &g_85[1], (void*)0};
            int i;
            step_hash(508);
            for (g_451 = 0; (g_451 <= 2); g_451 += 1)
            {
                int *l_721[1];
                int i;
                for (i = 0; i < 1; i++)
                    l_721[i] = &g_85[2];
                step_hash(506);
                for (g_17 = 0; (g_17 <= 2); g_17 += 1)
                {
                    step_hash(505);
                    return l_721[0];
                }
                step_hash(507);
                (*p_46) = g_201[g_451];
            }
            step_hash(509);
            --l_724;
        }
        step_hash(550);
        for (g_14 = 0; (g_14 <= (-23)); g_14--)
        {
            int *l_729 = (void*)0;
            int *l_730[9][7] = {{&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}, {&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}, {&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}, {&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}, {&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}, {&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}, {&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}, {&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}, {&g_85[1], &g_557, &g_661[1], &g_557, &g_661[1], &g_661[1], &g_661[1]}};
            unsigned char l_733 = 1UL;
            unsigned l_761[2][6] = {{0x2507D538L, 0UL, 0x2507D538L, 0UL, 0x2507D538L, 0UL}, {0x2507D538L, 0UL, 0x2507D538L, 0UL, 0x2507D538L, 0UL}};
            int i, j;
            step_hash(514);
            l_733--;
            step_hash(515);
            (*g_129) = (*p_47);
            step_hash(549);
            if (((unsigned char)((+l_732[5]) == (0xDD0182C3L == l_724)) + (unsigned char)(((func_74(&l_731, g_14) < l_731) ^ ((signed char)((unsigned short)g_14 >> (unsigned short)l_724) + (signed char)l_732[9])) <= (-1L))))
            {
                int l_742 = 0x643BF55BL;
                int l_754 = 0x8EE163EAL;
                int l_758 = 9L;
                int l_760[2][1];
                int i, j;
                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 1; j++)
                        l_760[i][j] = 0x2AF04588L;
                }
                step_hash(517);
                l_742 ^= func_74(p_46, l_731);
                step_hash(518);
                (**g_697) = p_46;
                step_hash(533);
                if (((unsigned char)((*p_47) ^ (l_742 > l_732[7])) % (unsigned char)((short)func_74(&l_731, l_742) << (short)(-(unsigned short)(((((unsigned char)g_557 % (unsigned char)l_742) && ((short)g_557 - (short)g_451)) >= l_742) || l_714)))))
                {
                    unsigned short l_752 = 0xC4A7L;
                    int l_755 = 1L;
                    int l_757 = 9L;
                    int l_759[1][2];
                    int i, j;
                    for (i = 0; i < 1; i++)
                    {
                        for (j = 0; j < 2; j++)
                            l_759[i][j] = 0x555FD7F3L;
                    }
                    step_hash(520);
                    (**g_697) = func_56((**g_697), (**g_697), &l_731, func_61((!246UL), p_46));
                    step_hash(528);
                    for (g_557 = 2; (g_557 >= 0); g_557 -= 1)
                    {
                        int i, j;
                        step_hash(524);
                        l_752 ^= g_201[g_557];
                        step_hash(525);
                        l_753 |= l_724;
                        step_hash(526);
                        l_731 &= (l_742 < func_74((*g_698), g_201[2]));
                        step_hash(527);
                        l_731 &= 0x71248A86L;
                    }
                    step_hash(529);
                    --l_761[0][3];
                }
                else
                {
                    unsigned l_764 = 9UL;
                    step_hash(531);
                    ++l_764;
                    step_hash(532);
                    (*g_129) = l_731;
                }
                step_hash(534);
                (*g_698) = p_46;
            }
            else
            {
                step_hash(547);
                for (g_651 = (-20); (g_651 < 3); g_651 += 4)
                {
                    unsigned short l_786 = 0xAD64L;
                    unsigned l_787 = 0xDB5C09E6L;
                    step_hash(539);
                    (*p_46) = ((int)(((short)((short)l_775 >> (short)0) >> (short)((((g_651 || (((((signed char)1L * (signed char)((*g_697) == l_778)) || 65535UL) || 6UL) & g_85[3])) <= l_756) < 1L) <= 0xCCL)) | 0x39L) - (int)(-5L));
                    step_hash(545);
                    for (g_17 = 1; (g_17 <= 4); g_17 += 1)
                    {
                        int i;
                        step_hash(543);
                        g_85[g_17] = 0x920823ADL;
                        step_hash(544);
                        return p_46;
                    }
                    step_hash(546);
                    l_731 ^= ((signed char)(((signed char)(((l_756 && func_74((**g_697), g_6)) >= l_785) || l_786) << (signed char)7) || (((void*)0 != (**g_697)) <= g_643[5][1])) >> (signed char)l_787);
                }
                step_hash(548);
                if ((***g_697))
                    break;
            }
        }
    }
    step_hash(552);
    (*g_697) = l_778;
    step_hash(558);
    for (l_714 = (-19); (l_714 >= 2); l_714++)
    {
        step_hash(556);
        (**l_778) = 0x880B1029L;
        step_hash(557);
        return (*g_698);
    }
    step_hash(559);
    return p_47;
}







static int * func_48(unsigned p_49, int * p_50, short p_51)
{
    int **l_621 = (void*)0;
    int **l_622[1];
    int l_625[5][7] = {{1L, 0x9FF9039AL, 0L, 0x0161932AL, 0x0161932AL, 0L, 0x9FF9039AL}, {1L, 0x9FF9039AL, 0L, 0x0161932AL, 0x0161932AL, 0L, 0x9FF9039AL}, {1L, 0x9FF9039AL, 0L, 0x0161932AL, 0x0161932AL, 0L, 0x9FF9039AL}, {1L, 0x9FF9039AL, 0L, 0x0161932AL, 0x0161932AL, 0L, 0x9FF9039AL}, {1L, 0x9FF9039AL, 0L, 0x0161932AL, 0x0161932AL, 0L, 0x9FF9039AL}};
    int l_684 = 0x1A97AF11L;
    int i, j;
    for (i = 0; i < 1; i++)
        l_622[i] = (void*)0;
    step_hash(430);
    g_129 = func_61(p_51, &g_85[1]);
    step_hash(431);
    (*p_50) = (p_51 != (p_51 >= ((((unsigned short)l_625[3][6] >> (unsigned short)0) <= ((int)func_74(p_50, p_51) - (int)p_49)) >= (+(p_50 != (void*)0)))));
    step_hash(432);
    g_129 = p_50;
    step_hash(485);
    for (g_451 = 0; (g_451 < 22); g_451 += 7)
    {
        short l_644 = 0xC3D7L;
        int l_648[7][1] = {{0x93B0BB7EL}, {0x93B0BB7EL}, {0x93B0BB7EL}, {0x93B0BB7EL}, {0x93B0BB7EL}, {0x93B0BB7EL}, {0x93B0BB7EL}};
        short l_650 = 8L;
        int i, j;
        step_hash(450);
        for (g_17 = 1; (g_17 <= 4); g_17 += 1)
        {
            int i, j;
            step_hash(443);
            for (g_470 = 0; (g_470 <= 0); g_470 += 1)
            {
                int l_632[6];
                int i, j;
                for (i = 0; i < 6; i++)
                    l_632[i] = (-3L);
                step_hash(442);
                l_632[4] &= ((signed char)l_625[g_17][(g_470 + 3)] * (signed char)g_85[(g_470 + 1)]);
            }
            step_hash(448);
            for (g_14 = 0; (g_14 <= 4); g_14 += 1)
            {
                int ***l_633 = &l_621;
                step_hash(447);
                (*l_633) = &p_50;
            }
            step_hash(449);
            l_625[g_17][g_17] = ((signed char)(((((void*)0 != &p_50) <= l_625[g_17][(g_17 + 1)]) < (-(short)g_85[g_17])) & (-5L)) / (signed char)((unsigned short)g_85[g_17] % (unsigned short)((unsigned char)(g_85[2] == ((unsigned short)(g_6 && ((g_201[2] >= g_85[g_17]) ^ 0L)) % (unsigned short)g_643[5][1])) >> (unsigned char)l_644)));
        }
        step_hash(451);
        g_557 &= (0x2A768312L == ((signed char)p_49 >> (signed char)((p_50 != p_50) < (*g_129))));
        step_hash(484);
        if ((*g_129))
        {
            signed char l_647 = 0xBBL;
            int l_649[9][1] = {{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}};
            short l_680 = (-9L);
            int i, j;
            step_hash(453);
            (*p_50) |= (&p_50 != &g_129);
            step_hash(454);
            ++g_651;
            step_hash(472);
            for (p_49 = (-11); (p_49 <= 19); p_49 += 8)
            {
                signed char l_656 = 0x30L;
                int l_657 = 0xD5A127C5L;
                unsigned short l_658 = 0x5D8DL;
                int l_662 = 6L;
                int l_673[2][2];
                int i, j;
                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 2; j++)
                        l_673[i][j] = 0x7B3202F8L;
                }
                step_hash(458);
                l_658++;
                step_hash(470);
                if (l_648[5][0])
                {
                    unsigned short l_663 = 65535UL;
                    step_hash(460);
                    if (l_644)
                        break;
                    step_hash(461);
                    ++l_663;
                }
                else
                {
                    unsigned l_666 = 4294967292UL;
                    int l_669 = (-1L);
                    int l_670 = 0L;
                    int l_671 = 0L;
                    int l_672 = 0xFD532E8AL;
                    int l_674 = 0xA05175F2L;
                    int l_675 = 0x14CF6733L;
                    int l_676 = 0L;
                    int l_677[1];
                    signed char l_678[6] = {0x3CL, 0x3CL, 0x1AL, 0x3CL, 0x3CL, 0x1AL};
                    int l_679 = 0x57E8D400L;
                    unsigned short l_681 = 0xBA8BL;
                    int i;
                    for (i = 0; i < 1; i++)
                        l_677[i] = 0L;
                    step_hash(467);
                    for (l_644 = 0; (l_644 <= 2); l_644 += 1)
                    {
                        step_hash(466);
                        ++l_666;
                    }
                    step_hash(468);
                    l_681--;
                    step_hash(469);
                    return &g_557;
                }
                step_hash(471);
                (*g_129) = 0x69CB4F15L;
            }
            step_hash(473);
            if (l_684)
                continue;
        }
        else
        {
            unsigned char l_699 = 2UL;
            int ***l_706 = &l_622[0];
            step_hash(475);
            l_648[5][0] ^= ((unsigned char)((short)((unsigned char)255UL >> (unsigned char)0) * (short)((p_49 < ((short)1L << (short)0)) & ((short)((void*)0 == &g_557) - (short)g_557))) << (unsigned char)(((short)(func_74(&l_648[4][0], (g_697 != (void*)0)) >= 4294967295UL) * (short)l_699) < p_49));
            step_hash(481);
            for (p_51 = 14; (p_51 >= (-2)); p_51 -= 5)
            {
                step_hash(479);
                (*g_698) = (*g_698);
                step_hash(480);
                return (*g_698);
            }
            step_hash(482);
            (*p_50) = (((short)p_49 << (short)(g_470 > (*p_50))) || ((func_74((*g_698), (g_85[0] | p_49)) == ((int)l_699 + (int)(&g_698 == l_706))) | p_49));
            step_hash(483);
            (**g_698) |= 0xF3FD9127L;
        }
    }
    step_hash(486);
    return p_50;
}







static int * func_53(int * p_54, int * p_55)
{
    unsigned char l_616 = 1UL;
    int *l_617 = &g_6;
    int **l_618 = &l_617;
    int *l_619 = &g_85[3];
    step_hash(427);
    (*l_618) = func_61(l_616, l_617);
    step_hash(428);
    return l_619;
}







static int * func_56(int * p_57, int * p_58, int * p_59, int * p_60)
{
    unsigned l_614 = 0UL;
    step_hash(424);
    l_614 = g_6;
    step_hash(425);
    return &g_557;
}







static int * func_61(unsigned char p_62, int * p_63)
{
    unsigned char l_590[8][6] = {{1UL, 0xA1L, 255UL, 0xA1L, 1UL, 1UL}, {1UL, 0xA1L, 255UL, 0xA1L, 1UL, 1UL}, {1UL, 0xA1L, 255UL, 0xA1L, 1UL, 1UL}, {1UL, 0xA1L, 255UL, 0xA1L, 1UL, 1UL}, {1UL, 0xA1L, 255UL, 0xA1L, 1UL, 1UL}, {1UL, 0xA1L, 255UL, 0xA1L, 1UL, 1UL}, {1UL, 0xA1L, 255UL, 0xA1L, 1UL, 1UL}, {1UL, 0xA1L, 255UL, 0xA1L, 1UL, 1UL}};
    int *l_591[6][3] = {{&g_85[1], &g_85[1], &g_6}, {&g_85[1], &g_85[1], &g_6}, {&g_85[1], &g_85[1], &g_6}, {&g_85[1], &g_85[1], &g_6}, {&g_85[1], &g_85[1], &g_6}, {&g_85[1], &g_85[1], &g_6}};
    unsigned l_592[3];
    signed char l_613 = 0x65L;
    int i, j;
    for (i = 0; i < 3; i++)
        l_592[i] = 1UL;
    step_hash(402);
    g_85[1] ^= l_590[3][3];
    step_hash(403);
    l_592[2]--;
    step_hash(421);
    if (((unsigned char)((g_201[2] != (((void*)0 != &g_85[3]) && 4L)) != 0x3DL) - (unsigned char)g_201[2]))
    {
        unsigned l_599[10][9] = {{1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}, {1UL, 0x8FA0CE26L, 0x8C594E2CL, 0x8FA0CE26L, 1UL, 0x363F3F98L, 1UL, 0x8FA0CE26L, 0x8C594E2CL}};
        int l_600 = 6L;
        int l_604 = 1L;
        int l_605[10];
        unsigned short l_606[4][5] = {{65530UL, 4UL, 2UL, 2UL, 4UL}, {65530UL, 4UL, 2UL, 2UL, 4UL}, {65530UL, 4UL, 2UL, 2UL, 4UL}, {65530UL, 4UL, 2UL, 2UL, 4UL}};
        int i, j;
        for (i = 0; i < 10; i++)
            l_605[i] = 0x3E6D9348L;
        step_hash(411);
        for (p_62 = 0; (p_62 > 32); p_62++)
        {
            short l_601 = 2L;
            int l_602 = 0xAB720FC4L;
            int l_603 = (-1L);
            step_hash(408);
            l_599[8][1] = (*p_63);
            step_hash(409);
            if ((*p_63))
                break;
            step_hash(410);
            l_606[2][2]--;
        }
    }
    else
    {
        int l_609 = 0xF07253B9L;
        int **l_610 = &l_591[5][1];
        step_hash(413);
        l_609 = (((g_470 ^ l_609) != (&g_129 == (void*)0)) <= p_62);
        step_hash(414);
        (*l_610) = p_63;
        step_hash(420);
        for (g_557 = (-23); (g_557 == 4); g_557++)
        {
            step_hash(418);
            (*l_610) = p_63;
            step_hash(419);
            if (l_613)
                continue;
        }
    }
    step_hash(422);
    return l_591[5][1];
}







static unsigned func_64(int * p_65, int * p_66, int p_67)
{
    unsigned char l_86 = 0UL;
    int l_94 = 3L;
    int l_95 = (-1L);
    int l_103 = (-4L);
    int l_105 = 6L;
    unsigned short l_106 = 0UL;
    unsigned short l_123[2][10];
    unsigned short l_252[4][8] = {{65527UL, 0x2812L, 65527UL, 0x6F82L, 0xC98EL, 1UL, 65528UL, 65528UL}, {65527UL, 0x2812L, 65527UL, 0x6F82L, 0xC98EL, 1UL, 65528UL, 65528UL}, {65527UL, 0x2812L, 65527UL, 0x6F82L, 0xC98EL, 1UL, 65528UL, 65528UL}, {65527UL, 0x2812L, 65527UL, 0x6F82L, 0xC98EL, 1UL, 65528UL, 65528UL}};
    int l_307[4];
    int **l_397[9] = {&g_129, &g_129, &g_129, &g_129, &g_129, &g_129, &g_129, &g_129, &g_129};
    int l_415 = 0xDDAF827EL;
    unsigned short l_463 = 0x126FL;
    unsigned l_480[8] = {4294967295UL, 0xA103C6BBL, 4294967295UL, 0xA103C6BBL, 4294967295UL, 0xA103C6BBL, 4294967295UL, 0xA103C6BBL};
    int l_531 = (-6L);
    int l_563 = 1L;
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 10; j++)
            l_123[i][j] = 1UL;
    }
    for (i = 0; i < 4; i++)
        l_307[i] = 0x824BA821L;
    step_hash(136);
    if (l_86)
    {
        int *l_87 = &g_85[1];
        int l_90 = 0xE6E27DFDL;
        int l_96 = (-1L);
        int l_97 = 5L;
        int l_98 = 0x5FFFC42EL;
        int l_100 = (-8L);
        int l_101 = 0xB503A71BL;
        int l_102 = 0L;
        int l_104[6] = {0L, 0L, 0x6993EB33L, 0L, 0L, 0x6993EB33L};
        int l_200[6][7] = {{0xF0944A39L, 7L, 0xF0944A39L, (-1L), (-1L), 1L, 0xDCD2CF26L}, {0xF0944A39L, 7L, 0xF0944A39L, (-1L), (-1L), 1L, 0xDCD2CF26L}, {0xF0944A39L, 7L, 0xF0944A39L, (-1L), (-1L), 1L, 0xDCD2CF26L}, {0xF0944A39L, 7L, 0xF0944A39L, (-1L), (-1L), 1L, 0xDCD2CF26L}, {0xF0944A39L, 7L, 0xF0944A39L, (-1L), (-1L), 1L, 0xDCD2CF26L}, {0xF0944A39L, 7L, 0xF0944A39L, (-1L), (-1L), 1L, 0xDCD2CF26L}};
        int l_250[2][8];
        int i, j;
        for (i = 0; i < 2; i++)
        {
            for (j = 0; j < 8; j++)
                l_250[i][j] = 7L;
        }
        step_hash(22);
        if ((*p_66))
        {
            step_hash(19);
            l_87 = &g_6;
        }
        else
        {
            step_hash(21);
            (*p_65) ^= (((void*)0 != &g_85[2]) >= g_6);
        }
        step_hash(29);
        for (p_67 = 0; (p_67 != (-8)); p_67 -= 6)
        {
            int *l_91 = &l_90;
            int *l_92 = &g_85[1];
            int *l_93[2];
            short l_99 = 0xDAE5L;
            int i;
            for (i = 0; i < 2; i++)
                l_93[i] = &g_85[1];
            step_hash(26);
            if (l_86)
                break;
            step_hash(27);
            ++l_106;
            step_hash(28);
            (*l_91) &= g_85[1];
        }
        step_hash(72);
        if ((-(unsigned)((short)(-(unsigned short)((((unsigned short)((unsigned)(*l_87) / (unsigned)p_67) * (unsigned short)l_106) <= (((unsigned short)((void*)0 != &l_98) * (unsigned short)65532UL) | (&g_6 != (void*)0))) == 0xBA4768E4L)) >> (short)1)))
        {
            int l_121 = 0xE71BBE26L;
            int **l_135 = &l_87;
            step_hash(47);
            for (l_103 = 3; (l_103 >= 1); l_103 -= 1)
            {
                step_hash(46);
                for (l_90 = 5; (l_90 >= 1); l_90 -= 1)
                {
                    int **l_119 = &l_87;
                    int *l_122[9];
                    int i;
                    for (i = 0; i < 9; i++)
                        l_122[i] = &l_102;
                    step_hash(37);
                    (*l_119) = &l_104[(l_103 + 2)];
                    step_hash(44);
                    for (l_95 = 4; (l_95 >= 1); l_95 -= 1)
                    {
                        int **l_120 = &l_87;
                        int i;
                        step_hash(41);
                        l_104[l_90] = 0xEF1402E7L;
                        step_hash(42);
                        g_85[l_95] = (g_85[l_103] && ((p_65 == (void*)0) > ((((0UL ^ ((void*)0 != l_120)) | ((-1L) > (**l_119))) >= 0x88L) && (-2L))));
                        step_hash(43);
                        g_85[l_95] = (*p_66);
                    }
                    step_hash(45);
                    ++l_123[1][3];
                }
            }
            step_hash(59);
            for (g_17 = 0; (g_17 >= 50); g_17 += 7)
            {
                int **l_128[10][7] = {{&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}, {&l_87, (void*)0, &l_87, &l_87, (void*)0, &l_87, &l_87}};
                int i, j;
                step_hash(51);
                g_129 = p_65;
                step_hash(52);
                (*p_65) ^= func_74(&g_6, ((signed char)(0xF5L & g_85[0]) / (signed char)g_17));
                step_hash(58);
                for (l_98 = 0; (l_98 >= 3); ++l_98)
                {
                    unsigned l_134[1][5];
                    int i, j;
                    for (i = 0; i < 1; i++)
                    {
                        for (j = 0; j < 5; j++)
                            l_134[i][j] = 0xE3D09CE0L;
                    }
                    step_hash(56);
                    (*p_65) = l_134[0][1];
                    step_hash(57);
                    (*p_65) ^= (~func_74(&g_85[1], (*l_87)));
                }
            }
            step_hash(60);
            (*l_135) = p_65;
        }
        else
        {
            unsigned char l_149 = 1UL;
            step_hash(66);
            for (l_97 = 0; (l_97 >= (-4)); --l_97)
            {
                unsigned l_138[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_138[i] = 0x9EBF9289L;
                step_hash(65);
                ++l_138[2];
            }
            step_hash(71);
            for (l_94 = 0; (l_94 < (-20)); l_94--)
            {
                int *l_143 = &l_102;
                int *l_144 = &l_98;
                int l_145 = (-4L);
                int *l_146 = &l_97;
                int *l_147 = &g_85[3];
                int *l_148[9] = {&l_103, (void*)0, &l_103, (void*)0, &l_103, (void*)0, &l_103, (void*)0, &l_103};
                int i;
                step_hash(70);
                ++l_149;
            }
        }
        step_hash(120);
        if (func_74(&l_103, p_67))
        {
            step_hash(83);
            if ((&g_129 != (void*)0))
            {
                int l_157[10][7] = {{0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}, {0xE1307C17L, 0xBB96E4AEL, 0xBB96E4AEL, 0xE1307C17L, 7L, 1L, 0x2C2F114CL}};
                int i, j;
                step_hash(79);
                for (l_94 = 0; (l_94 != 2); ++l_94)
                {
                    int **l_154[4] = {(void*)0, &l_87, (void*)0, &l_87};
                    int i;
                    step_hash(78);
                    l_87 = p_65;
                }
                step_hash(80);
                (*p_65) = ((*g_129) | ((unsigned short)0UL * (unsigned short)l_157[5][0]));
            }
            else
            {
                int **l_158 = &l_87;
                step_hash(82);
                (*l_158) = p_65;
            }
        }
        else
        {
            unsigned l_163 = 0x06447CF2L;
            int *l_166 = &l_94;
            unsigned l_179 = 2UL;
            int l_187 = 1L;
            int l_188 = 6L;
            int l_189 = 0L;
            int l_242 = 0L;
            step_hash(118);
            if (((signed char)p_67 * (signed char)g_85[0]))
            {
                signed char l_186 = 1L;
                step_hash(96);
                for (g_17 = (-24); (g_17 > 56); g_17 += 3)
                {
                    unsigned char l_180 = 0x42L;
                    int l_190 = 0x11735A46L;
                    unsigned l_191 = 5UL;
                    step_hash(95);
                    if (l_163)
                    {
                        int **l_164 = &l_87;
                        unsigned l_165 = 4294967295UL;
                        signed char l_181[6];
                        int i;
                        for (i = 0; i < 6; i++)
                            l_181[i] = 0x05L;
                        step_hash(90);
                        (*l_164) = p_65;
                        step_hash(91);
                        l_165 = (-3L);
                        step_hash(92);
                        l_181[3] ^= (func_74(l_166, ((short)((unsigned char)(0L > ((signed char)(((*l_166) | (((signed char)0x36L << (signed char)(((void*)0 != l_164) > ((*g_129) != ((unsigned char)((unsigned short)((void*)0 == &p_66) << (unsigned short)l_179) * (unsigned char)g_85[1])))) >= (*g_129))) != 0x7270L) % (signed char)p_67)) << (unsigned char)l_86) * (short)l_180)) || p_67);
                    }
                    else
                    {
                        int *l_182 = &l_103;
                        int *l_183 = &l_102;
                        int *l_184 = &l_102;
                        int *l_185[3][2] = {{&l_101, &l_104[0]}, {&l_101, &l_104[0]}, {&l_101, &l_104[0]}};
                        int i, j;
                        step_hash(94);
                        --l_191;
                    }
                }
                step_hash(97);
                (*g_129) = ((int)(*g_129) / (int)p_67);
            }
            else
            {
                int l_202 = 0L;
                int l_237 = 0x4C6D56EDL;
                int l_238 = 2L;
                int l_244[1][8];
                short l_251 = 0xC65BL;
                int i, j;
                for (i = 0; i < 1; i++)
                {
                    for (j = 0; j < 8; j++)
                        l_244[i][j] = 0xD06CCA62L;
                }
                step_hash(99);
                (*g_129) = (l_105 == 0UL);
                step_hash(115);
                for (l_163 = 20; (l_163 == 46); l_163 += 5)
                {
                    signed char l_230 = 0x66L;
                    int *l_231 = &g_85[1];
                    int l_239 = 0xD871682DL;
                    int l_240 = 0xD00192FCL;
                    int l_241 = 7L;
                    int l_243 = 0xB1182683L;
                    int l_245 = 3L;
                    unsigned char l_246 = 0x27L;
                    int *l_249[2][9] = {{&l_202, &l_101, &l_202, &l_101, &l_202, &l_101, &l_202, &l_101, &l_202}, {&l_202, &l_101, &l_202, &l_101, &l_202, &l_101, &l_202, &l_101, &l_202}};
                    int i, j;
                    step_hash(103);
                    (*l_166) &= ((1L == func_74(p_65, (*l_87))) || ((void*)0 == &p_65));
                    step_hash(104);
                    l_103 |= ((unsigned char)l_200[0][5] >> (unsigned char)((g_201[2] & (0xADL > ((-5L) != func_74(p_65, l_202)))) > (((unsigned short)g_17 << (unsigned short)15) ^ ((int)l_86 / (int)0x38762AC0L))));
                    step_hash(113);
                    if (((g_6 && (p_67 || ((signed char)((unsigned char)g_85[3] - (unsigned char)0x6CL) + (signed char)((~p_67) && ((unsigned short)(p_67 & ((void*)0 == &l_87)) + (unsigned short)(((6L > (*g_129)) > 0xD2L) ^ 0x485C87E2L)))))) < p_67))
                    {
                        int **l_213 = (void*)0;
                        int **l_214[4];
                        int i;
                        for (i = 0; i < 4; i++)
                            l_214[i] = &l_166;
                        step_hash(106);
                        g_129 = &l_202;
                        step_hash(107);
                        return p_67;
                    }
                    else
                    {
                        int **l_215 = &l_87;
                        int *l_234 = (void*)0;
                        int *l_235 = &l_102;
                        int *l_236[1][7];
                        int i, j;
                        for (i = 0; i < 1; i++)
                        {
                            for (j = 0; j < 7; j++)
                                l_236[i][j] = (void*)0;
                        }
                        step_hash(109);
                        (*l_215) = p_65;
                        step_hash(110);
                        (*p_65) = (((((signed char)(!p_67) + (signed char)(((unsigned short)((*p_66) & ((short)((unsigned short)func_74(p_65, (**l_215)) / (unsigned short)(**l_215)) - (short)((short)((short)p_67 / (short)((signed char)(g_201[0] <= 0x9E74L) % (signed char)p_67)) - (short)p_67))) << (unsigned short)14) > l_230)) | l_202) & 0x3ED3L) > g_6);
                        step_hash(111);
                        (*l_166) = (((*p_66) >= ((l_231 != &l_105) > ((signed char)func_74(p_66, ((void*)0 == p_66)) * (signed char)g_201[2]))) < g_14);
                        step_hash(112);
                        l_246++;
                    }
                    step_hash(114);
                    --l_252[1][4];
                }
                step_hash(116);
                l_94 = (p_67 >= (((~g_85[1]) || l_86) == ((unsigned short)p_67 - (unsigned short)(((l_103 ^ (&g_6 == &g_6)) > (0x9F68L == ((unsigned short)g_17 * (unsigned short)3UL))) || 0xF5L))));
                step_hash(117);
                return l_251;
            }
            step_hash(119);
            (*g_129) = (*p_66);
        }
    }
    else
    {
        unsigned l_263 = 0x4AD94989L;
        int **l_266 = &g_129;
        step_hash(134);
        for (p_67 = 0; (p_67 <= 4); p_67 += 1)
        {
            int **l_259 = &g_129;
            int i;
            step_hash(125);
            (*l_259) = &g_85[p_67];
            step_hash(126);
            l_259 = &p_65;
            step_hash(132);
            if (((short)g_17 / (short)func_74(p_65, p_67)))
            {
                step_hash(128);
                (*l_259) = (*l_259);
            }
            else
            {
                int *l_262[6][3] = {{&l_94, &l_94, &g_85[p_67]}, {&l_94, &l_94, &g_85[p_67]}, {&l_94, &l_94, &g_85[p_67]}, {&l_94, &l_94, &g_85[p_67]}, {&l_94, &l_94, &g_85[p_67]}, {&l_94, &l_94, &g_85[p_67]}};
                int i, j;
                step_hash(130);
                l_263++;
                step_hash(131);
                (*p_65) = (&g_85[1] == &g_85[4]);
            }
            step_hash(133);
            return p_67;
        }
        step_hash(135);
        (*l_266) = p_65;
    }
    step_hash(398);
    if (func_74(&l_103, (p_67 && (+func_74(&g_6, g_85[1])))))
    {
        short l_285 = (-6L);
        int l_287[7][4] = {{(-1L), (-1L), 0x5ADCCE1AL, (-1L)}, {(-1L), (-1L), 0x5ADCCE1AL, (-1L)}, {(-1L), (-1L), 0x5ADCCE1AL, (-1L)}, {(-1L), (-1L), 0x5ADCCE1AL, (-1L)}, {(-1L), (-1L), 0x5ADCCE1AL, (-1L)}, {(-1L), (-1L), 0x5ADCCE1AL, (-1L)}, {(-1L), (-1L), 0x5ADCCE1AL, (-1L)}};
        int l_344 = 1L;
        int **l_394 = (void*)0;
        short l_396 = 0L;
        int *l_402 = &l_287[5][3];
        int l_414 = 0x6F42F22EL;
        int i, j;
        step_hash(284);
        if ((((unsigned short)g_201[0] * (unsigned short)(&g_129 != &p_66)) & g_85[1]))
        {
            int l_271 = 0L;
            int **l_393[10] = {&g_129, (void*)0, &g_129, (void*)0, &g_129, (void*)0, &g_129, (void*)0, &g_129, (void*)0};
            int l_435[7][1] = {{1L}, {1L}, {1L}, {1L}, {1L}, {1L}, {1L}};
            int i, j;
            step_hash(212);
            if ((((int)(l_271 < ((void*)0 == &p_66)) + (int)g_85[1]) ^ (((unsigned short)((&p_65 != (void*)0) != (((unsigned short)(g_17 > (((short)(!(((l_106 & 0xBACDL) > l_252[1][4]) != l_103)) * (short)65535UL) == g_201[1])) - (unsigned short)0UL) <= p_67)) + (unsigned short)p_67) >= l_95)))
            {
                unsigned l_278[8] = {8UL, 8UL, 0x4E592116L, 8UL, 8UL, 0x4E592116L, 8UL, 8UL};
                int l_284 = 0x76AEA6EAL;
                int l_286[9][4] = {{1L, 1L, 5L, 0xB7B0CE8AL}, {1L, 1L, 5L, 0xB7B0CE8AL}, {1L, 1L, 5L, 0xB7B0CE8AL}, {1L, 1L, 5L, 0xB7B0CE8AL}, {1L, 1L, 5L, 0xB7B0CE8AL}, {1L, 1L, 5L, 0xB7B0CE8AL}, {1L, 1L, 5L, 0xB7B0CE8AL}, {1L, 1L, 5L, 0xB7B0CE8AL}, {1L, 1L, 5L, 0xB7B0CE8AL}};
                unsigned short l_288 = 0x4845L;
                unsigned l_291 = 0x12271815L;
                signed char l_324 = 7L;
                int i, j;
                step_hash(144);
                if (l_278[7])
                {
                    unsigned l_279 = 4294967293UL;
                    step_hash(141);
                    l_279++;
                }
                else
                {
                    step_hash(143);
                    return p_67;
                }
                step_hash(172);
                if ((func_74(p_66, g_201[2]) <= l_271))
                {
                    int l_282[4][3] = {{1L, 0x5E0FD3B0L, 0x33A1D277L}, {1L, 0x5E0FD3B0L, 0x33A1D277L}, {1L, 0x5E0FD3B0L, 0x33A1D277L}, {1L, 0x5E0FD3B0L, 0x33A1D277L}};
                    int *l_283[9] = {(void*)0, &l_103, (void*)0, &l_103, (void*)0, &l_103, (void*)0, &l_103, (void*)0};
                    int i, j;
                    step_hash(151);
                    for (g_17 = 0; (g_17 <= 2); g_17 += 1)
                    {
                        int i;
                        step_hash(149);
                        l_282[2][0] = func_74(p_66, g_201[g_17]);
                        step_hash(150);
                        (*g_129) = (*p_65);
                    }
                    step_hash(152);
                    --l_288;
                }
                else
                {
                    unsigned l_294 = 0x9CD487A2L;
                    int *l_330 = (void*)0;
                    step_hash(154);
                    l_271 = l_291;
                    step_hash(162);
                    if (((signed char)l_294 - (signed char)((unsigned)((int)(0x43E5D3A1L | ((((unsigned char)0UL % (unsigned char)((signed char)g_14 << (signed char)l_271)) != (g_85[2] >= ((signed char)((unsigned char)l_307[0] % (unsigned char)l_286[6][2]) >> (signed char)((signed char)((~((unsigned)(&g_85[1] != p_66) + (unsigned)1L)) && l_294) >> (signed char)0)))) & 5UL)) % (int)l_294) % (unsigned)(*g_129))))
                    {
                        unsigned l_325 = 1UL;
                        step_hash(156);
                        (*p_65) |= (+((func_74(&l_271, p_67) == ((signed char)(-5L) + (signed char)((int)l_288 / (int)((unsigned)p_67 + (unsigned)(((short)(((short)((unsigned short)((p_67 != p_67) > l_284) + (unsigned short)p_67) >> (short)l_324) && l_286[6][2]) - (short)p_67) ^ l_94))))) > g_17));
                        step_hash(157);
                        (*p_65) = func_74(&g_85[1], g_201[1]);
                        step_hash(158);
                        (*p_65) |= (0x60L >= (l_325 | (((&p_66 != (void*)0) != l_123[0][5]) < ((short)((unsigned char)(l_271 >= (p_67 > func_74(l_330, l_286[5][3]))) >> (unsigned char)5) % (short)2L))));
                    }
                    else
                    {
                        int **l_331 = &g_129;
                        step_hash(160);
                        (*g_129) &= ((void*)0 == &p_66);
                        step_hash(161);
                        (*l_331) = &l_103;
                    }
                    step_hash(163);
                    (*p_65) &= ((unsigned char)(g_85[1] | (4294967295UL & (p_67 != 65532UL))) - (unsigned char)p_67);
                    step_hash(171);
                    for (p_67 = (-23); (p_67 >= (-9)); ++p_67)
                    {
                        step_hash(167);
                        (*p_65) |= l_307[1];
                        step_hash(168);
                        p_65 = &g_85[1];
                        step_hash(169);
                        if ((*p_66))
                            break;
                        step_hash(170);
                        (*g_129) ^= 0xF1477639L;
                    }
                }
                step_hash(186);
                for (l_86 = 0; (l_86 != 40); l_86++)
                {
                    unsigned l_352 = 0x9C06BD83L;
                }
            }
            else
            {
                int *l_360[6] = {&g_85[1], &g_85[1], &l_103, &g_85[1], &g_85[1], &l_103};
                int i;
                step_hash(209);
                if (func_74(&g_85[4], ((short)((unsigned char)g_14 * (unsigned char)((&g_129 != &p_65) && (func_74(p_65, g_85[1]) & p_67))) << (short)13)))
                {
                    unsigned short l_363[8][4] = {{0xB063L, 0x930AL, 0xB063L, 0x930AL}, {0xB063L, 0x930AL, 0xB063L, 0x930AL}, {0xB063L, 0x930AL, 0xB063L, 0x930AL}, {0xB063L, 0x930AL, 0xB063L, 0x930AL}, {0xB063L, 0x930AL, 0xB063L, 0x930AL}, {0xB063L, 0x930AL, 0xB063L, 0x930AL}, {0xB063L, 0x930AL, 0xB063L, 0x930AL}, {0xB063L, 0x930AL, 0xB063L, 0x930AL}};
                    int l_372 = 0x98F1B2D3L;
                    int i, j;
                    step_hash(189);
                    (*g_129) = ((-(signed char)(l_360[4] == (void*)0)) || 0x95DFL);
                    step_hash(197);
                    for (l_94 = 12; (l_94 == (-17)); l_94--)
                    {
                        signed char l_387 = 1L;
                        step_hash(193);
                        (*p_65) &= (!(0UL >= func_74(&g_6, p_67)));
                        step_hash(194);
                        l_363[4][3]++;
                        step_hash(195);
                        l_372 &= (l_363[4][3] < (((+((*p_65) > func_74(p_65, func_74(&g_6, ((unsigned)((unsigned char)g_85[0] * (unsigned char)(((short)g_201[2] - (short)1UL) ^ (g_14 | (g_85[0] | g_14)))) / (unsigned)0x51DFCB4BL))))) ^ (*p_66)) > 0x304AL));
                        step_hash(196);
                        (*g_129) = (((short)l_271 - (short)((unsigned char)((int)(l_95 <= (((g_85[1] >= ((unsigned short)p_67 / (unsigned short)((unsigned short)g_85[4] * (unsigned short)0xD4D5L))) >= (((unsigned)((int)0xF00F302BL + (int)g_17) - (unsigned)l_387) != (*p_65))) & l_86)) - (int)p_67) - (unsigned char)(-6L))) || (-3L));
                    }
                    step_hash(198);
                    (*g_129) = ((*g_129) || (*p_65));
                    step_hash(206);
                    for (p_67 = 0; (p_67 <= 3); p_67 += 1)
                    {
                        unsigned l_390 = 0x15303D7FL;
                        int l_395 = 4L;
                        int i;
                        step_hash(202);
                        if (l_103)
                            break;
                        step_hash(203);
                        l_95 |= (g_14 & (((short)((l_390 != p_67) != (((0x04L > (((void*)0 != &g_6) >= (((short)(0x5C87L ^ g_6) - (short)(0xC31B24D9L > (*p_65))) >= g_85[1]))) >= g_6) < (-4L))) / (short)0xBAB7L) <= (*p_66)));
                        step_hash(204);
                        (*p_65) &= (l_393[9] != l_394);
                        step_hash(205);
                        l_395 ^= (*g_129);
                    }
                }
                else
                {
                    step_hash(208);
                    return g_6;
                }
                step_hash(210);
                (*p_65) ^= l_396;
                step_hash(211);
                g_129 = p_66;
            }
            step_hash(231);
            if (((l_397[3] == &g_129) <= ((unsigned short)g_201[2] >> (unsigned short)7)))
            {
                unsigned char l_400 = 253UL;
                step_hash(214);
                (*p_65) |= (l_400 != (-(signed char)0x6FL));
                step_hash(215);
                l_402 = p_66;
            }
            else
            {
                unsigned l_403 = 0UL;
                step_hash(229);
                for (l_103 = 3; (l_103 >= 0); l_103 -= 1)
                {
                    int i;
                    step_hash(220);
                    (*l_402) = l_307[l_103];
                    step_hash(228);
                    for (l_396 = 0; (l_396 <= 3); l_396 += 1)
                    {
                        int i, j;
                        step_hash(224);
                        l_287[(l_103 + 1)][l_396] = l_403;
                        step_hash(225);
                        l_287[(l_103 + 2)][l_396] |= (+(+func_74(&l_287[(l_103 + 1)][l_396], g_17)));
                        step_hash(226);
                        (*p_65) &= ((void*)0 == p_65);
                        step_hash(227);
                        if (l_307[l_103])
                            continue;
                    }
                }
                step_hash(230);
                l_415 = (((short)(((unsigned char)((((p_67 ^ p_67) != 0UL) >= ((+((unsigned char)l_403 + (unsigned char)((unsigned short)g_14 << (unsigned short)(g_85[2] < ((unsigned char)(~(l_403 == g_201[0])) << (unsigned char)(g_17 == 1UL)))))) && 1L)) <= 0UL) * (unsigned char)l_414) | g_14) >> (short)l_403) <= p_67);
            }
            step_hash(255);
            for (g_14 = 1; (g_14 >= 0); g_14 -= 1)
            {
                unsigned short l_421 = 65531UL;
                unsigned l_422 = 0x7866A51FL;
                step_hash(252);
                for (l_285 = 0; (l_285 <= 1); l_285 += 1)
                {
                    unsigned l_418 = 4294967291UL;
                    step_hash(245);
                    for (g_17 = 0; (g_17 <= 8); g_17 += 1)
                    {
                        int i, j;
                        step_hash(241);
                        g_85[1] ^= ((int)((void*)0 == &g_85[(l_285 + 3)]) + (int)4UL);
                        step_hash(242);
                        l_418--;
                        step_hash(243);
                        g_85[1] = (func_74(&g_6, (l_123[l_285][(l_285 + 6)] >= func_74(p_65, ((g_201[(g_14 + 1)] > l_421) & g_6)))) >= (~(l_422 | p_67)));
                        step_hash(244);
                        if ((*g_129))
                            break;
                    }
                    step_hash(251);
                    for (l_106 = 0; (l_106 <= 2); l_106 += 1)
                    {
                        step_hash(249);
                        l_287[0][0] |= (((unsigned char)(((*g_129) <= l_421) & l_421) << (unsigned char)1) || 0xF4E64863L);
                        step_hash(250);
                        return g_85[3];
                    }
                }
                step_hash(253);
                p_66 = p_65;
                step_hash(254);
                return g_201[2];
            }
            step_hash(281);
            if ((l_393[9] != (void*)0))
            {
                int **l_428 = (void*)0;
                step_hash(269);
                for (l_396 = (-26); (l_396 <= (-5)); ++l_396)
                {
                    int *l_427[4];
                    int i;
                    for (i = 0; i < 4; i++)
                        l_427[i] = &l_271;
                    step_hash(266);
                    for (p_67 = 0; (p_67 <= 3); p_67 += 1)
                    {
                        step_hash(263);
                        g_129 = (void*)0;
                        step_hash(264);
                        (*p_65) = (!((void*)0 != l_393[9]));
                        step_hash(265);
                        l_427[1] = &g_85[2];
                    }
                    step_hash(267);
                    (*p_65) ^= (*p_66);
                    step_hash(268);
                    (*p_65) &= ((void*)0 != l_428);
                }
            }
            else
            {
                unsigned l_450[9][4] = {{4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}, {4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}, {4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}, {4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}, {4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}, {4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}, {4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}, {4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}, {4294967290UL, 0x1A1E9AEDL, 2UL, 0xB62B6FBFL}};
                short l_452 = 1L;
                int l_453[7] = {0x51D2ECACL, 0xA998834DL, 0x51D2ECACL, 0xA998834DL, 0x51D2ECACL, 0xA998834DL, 0x51D2ECACL};
                unsigned l_454 = 4294967290UL;
                int i, j;
                step_hash(278);
                if (((short)(p_67 || func_74(&g_85[0], (0UL && ((unsigned char)func_74(&g_6, ((short)l_435[5][0] << (short)14)) % (unsigned char)g_201[2])))) + (short)((unsigned char)(((int)7L + (int)0xE86B153DL) || g_201[0]) / (unsigned char)0x12L)))
                {
                    short l_442 = 0xACC0L;
                    step_hash(272);
                    g_85[4] = ((unsigned char)p_67 % (unsigned char)0x66L);
                    step_hash(273);
                    l_442 ^= (*g_129);
                    step_hash(274);
                    (*p_65) = (p_67 & 0UL);
                    step_hash(275);
                    g_85[2] = ((short)(-(unsigned)((2L ^ (+(0xECL <= (p_67 ^ ((func_74(&g_85[3], (p_67 & g_201[2])) && 1L) == ((*l_402) | l_442)))))) > g_201[1])) >> (short)1);
                }
                else
                {
                    step_hash(277);
                    g_129 = p_65;
                }
                step_hash(279);
                g_451 |= (~((int)(*g_129) + (int)l_450[3][3]));
                step_hash(280);
                ++l_454;
            }
        }
        else
        {
            step_hash(283);
            return p_67;
        }
        step_hash(285);
        g_470 |= (((unsigned char)((((unsigned)g_17 + (unsigned)(&g_129 == &p_65)) | (((unsigned char)254UL - (unsigned char)l_463) && ((short)g_85[3] % (short)((unsigned)p_67 + (unsigned)(*p_66))))) != ((unsigned char)0x3CL % (unsigned char)g_85[0])) - (unsigned char)6UL) & g_201[1]);
        step_hash(294);
        for (g_451 = 0; (g_451 <= 15); g_451 += 5)
        {
            unsigned l_475 = 0UL;
            step_hash(293);
            for (l_106 = (-4); (l_106 < 7); l_106 += 1)
            {
                step_hash(292);
                l_475--;
            }
        }
        step_hash(304);
        for (l_86 = (-16); (l_86 == 2); l_86++)
        {
            step_hash(298);
            l_480[2] = 0x1F418CDAL;
            step_hash(303);
            for (l_94 = (-14); (l_94 > (-28)); --l_94)
            {
                int *l_483 = &l_287[0][2];
                step_hash(302);
                l_483 = (void*)0;
            }
        }
    }
    else
    {
        unsigned l_484 = 8UL;
        int *l_519 = &l_105;
        int l_525 = 1L;
        int l_537 = 0x6FFD2F16L;
        int l_540 = 0L;
        int l_544 = 0x5B8B17ABL;
        signed char l_547 = 1L;
        unsigned char l_548 = 250UL;
        unsigned short l_564 = 1UL;
        step_hash(379);
        if (l_484)
        {
            int *l_489 = &l_103;
            int *l_503 = &g_85[1];
            int l_521 = 0L;
            int l_523 = 0x9AEC4979L;
            unsigned short l_526 = 1UL;
            short l_530 = 0xF7BDL;
            int l_539 = 1L;
            int l_541 = (-2L);
            int l_542 = 0xF0BB177EL;
            int l_543 = (-1L);
            int l_545 = 1L;
            int l_546 = 0x8401FAB9L;
            step_hash(352);
            if (((signed char)((int)(((0x45CDBFF9L == func_74(l_489, g_201[0])) > (0x14C0L && ((g_201[2] && ((((((unsigned short)((unsigned char)((-9L) || p_67) >> (unsigned char)1) << (unsigned short)1) & ((void*)0 == &g_6)) || g_14) && g_6) | 0xC523L)) && p_67))) != p_67) / (int)(*l_489)) >> (signed char)7))
            {
                unsigned l_500 = 4294967295UL;
                int l_524[3][2] = {{1L, 0xC9036A03L}, {1L, 0xC9036A03L}, {1L, 0xC9036A03L}};
                unsigned l_552 = 4294967288UL;
                int i, j;
                step_hash(308);
                (*l_489) = ((unsigned short)(((signed char)g_17 >> (signed char)p_67) && g_85[1]) + (unsigned short)(((((signed char)p_67 % (signed char)l_500) == (*l_489)) > g_85[0]) < g_201[1]));
                step_hash(313);
                for (l_500 = 0; (l_500 >= 4); ++l_500)
                {
                    step_hash(312);
                    (*l_489) = func_74(l_503, func_74(l_503, g_201[2]));
                }
                step_hash(321);
                for (l_95 = 0; (l_95 != 8); l_95 += 4)
                {
                    unsigned char l_512 = 0x18L;
                    int l_520 = (-9L);
                    int l_522 = 0x854D8CF6L;
                    step_hash(317);
                    if ((*g_129))
                        break;
                    step_hash(318);
                    (*l_519) &= ((int)(*g_129) / (int)(((unsigned char)(l_512 | (((unsigned short)g_85[1] * (unsigned short)g_201[1]) <= (g_17 & (((unsigned char)2UL << (unsigned char)g_17) >= (&g_6 != l_519))))) << (unsigned char)2) & g_451));
                    step_hash(319);
                    --l_526;
                    step_hash(320);
                    p_65 = &g_85[1];
                }
                step_hash(349);
                for (l_105 = 0; (l_105 <= 1); l_105 += 1)
                {
                    int l_533 = (-8L);
                    int l_534 = 0x12D26980L;
                    int l_536[7] = {(-1L), 0x5EB85CDDL, (-1L), 0x5EB85CDDL, (-1L), 0x5EB85CDDL, (-1L)};
                    short l_538[10][6] = {{0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}, {0x6F76L, 0L, 8L, 0x4E49L, 0x4E49L, 8L}};
                    int l_567 = 0x599A88A0L;
                    int i, j;
                    step_hash(332);
                    for (l_484 = 0; (l_484 <= 2); l_484 += 1)
                    {
                        int *l_529 = &l_524[1][1];
                        int l_532[5] = {0x20CAC603L, 0xD2894843L, 0x20CAC603L, 0xD2894843L, 0x20CAC603L};
                        int l_535 = 0x38B08613L;
                        int l_551 = 0xE44E8891L;
                        int i, j;
                        step_hash(328);
                        l_529 = p_65;
                        step_hash(329);
                        l_548--;
                        step_hash(330);
                        l_552--;
                        step_hash(331);
                        if (l_123[l_105][(l_105 + 2)])
                            continue;
                    }
                    step_hash(339);
                    if ((+((unsigned short)p_67 * (unsigned short)g_17)))
                    {
                        step_hash(334);
                        (*g_129) = (&g_129 == &p_65);
                        step_hash(335);
                        return p_67;
                    }
                    else
                    {
                        step_hash(337);
                        (*l_489) ^= (*l_519);
                        step_hash(338);
                        (*g_129) &= (-9L);
                    }
                    step_hash(340);
                    if ((*p_65))
                        continue;
                    step_hash(341);
                    g_129 = &l_539;
                    step_hash(348);
                    for (l_521 = 1; (l_521 >= 0); l_521 -= 1)
                    {
                        int l_562 = (-9L);
                        int i, j;
                        step_hash(345);
                        (*l_503) = ((l_123[l_105][(l_521 + 7)] ^ func_74(&g_85[1], g_557)) == (((signed char)l_524[1][0] / (signed char)((unsigned short)(0x06C6L || (8L == g_14)) * (unsigned short)l_562)) ^ 0x3129L));
                        step_hash(346);
                        ++l_564;
                        step_hash(347);
                        l_567 ^= (-1L);
                    }
                }
            }
            else
            {
                step_hash(351);
                (*g_129) = (*g_129);
            }
            step_hash(353);
            p_66 = p_65;
        }
        else
        {
            int **l_570 = &l_519;
            step_hash(355);
            (*g_129) = (((((g_201[2] ^ (!((signed char)(l_570 == (void*)0) << (signed char)6))) == (((int)((0xD7BEL != (((short)((short)g_470 % (short)g_17) + (short)(l_397[3] == &g_129)) ^ ((short)func_74(&l_544, g_6) - (short)g_14))) != 0xF6DDA1FEL) % (int)(*l_519)) || g_17)) & p_67) > (*l_519)) > (*l_519));
            step_hash(378);
            for (l_547 = 3; (l_547 >= 0); l_547 -= 1)
            {
                int i;
                step_hash(359);
                (**l_570) &= l_307[l_547];
                step_hash(365);
                for (l_531 = 1; (l_531 >= 0); l_531 -= 1)
                {
                    int i, j;
                    step_hash(363);
                    (*p_65) &= (((unsigned char)g_201[l_531] * (unsigned char)func_74(&l_525, (l_123[l_531][(l_531 + 2)] != (-1L)))) | (l_123[l_531][(l_531 + 2)] != (~(*l_519))));
                    step_hash(364);
                    if ((*g_129))
                        break;
                }
                step_hash(377);
                for (g_14 = 0; (g_14 <= 3); g_14 += 1)
                {
                    step_hash(375);
                    for (g_470 = 0; (g_470 <= 3); g_470 += 1)
                    {
                        step_hash(372);
                        (*l_570) = p_65;
                        step_hash(373);
                        (**l_570) ^= func_74(p_65, (g_557 == g_85[1]));
                        step_hash(374);
                        if ((*g_129))
                            break;
                    }
                    step_hash(376);
                    return p_67;
                }
            }
        }
        step_hash(380);
        (*p_65) &= (*l_519);
        step_hash(391);
        for (g_451 = 22; (g_451 >= 40); ++g_451)
        {
            unsigned char l_584 = 0x27L;
        }
        step_hash(397);
        for (l_95 = 5; (l_95 <= 4); --l_95)
        {
            step_hash(395);
            l_519 = (void*)0;
            step_hash(396);
            if ((*p_66))
                break;
        }
    }
    step_hash(399);
    p_66 = p_66;
    step_hash(400);
    return p_67;
}







static unsigned char func_74(int * p_75, unsigned short p_76)
{
    unsigned l_82[7][8] = {{0x456014EFL, 0xECA6696BL, 1UL, 0UL, 4294967288UL, 5UL, 0x71010F19L, 0x4264A3A2L}, {0x456014EFL, 0xECA6696BL, 1UL, 0UL, 4294967288UL, 5UL, 0x71010F19L, 0x4264A3A2L}, {0x456014EFL, 0xECA6696BL, 1UL, 0UL, 4294967288UL, 5UL, 0x71010F19L, 0x4264A3A2L}, {0x456014EFL, 0xECA6696BL, 1UL, 0UL, 4294967288UL, 5UL, 0x71010F19L, 0x4264A3A2L}, {0x456014EFL, 0xECA6696BL, 1UL, 0UL, 4294967288UL, 5UL, 0x71010F19L, 0x4264A3A2L}, {0x456014EFL, 0xECA6696BL, 1UL, 0UL, 4294967288UL, 5UL, 0x71010F19L, 0x4264A3A2L}, {0x456014EFL, 0xECA6696BL, 1UL, 0UL, 4294967288UL, 5UL, 0x71010F19L, 0x4264A3A2L}};
    int *l_83 = (void*)0;
    int *l_84 = &g_85[1];
    int i, j;
    step_hash(14);
    (*l_84) |= ((unsigned)(g_6 <= 0xCAL) + (unsigned)((unsigned)p_76 + (unsigned)l_82[6][7]));
    step_hash(15);
    return g_14;
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_6, "g_6", print_hash_value);
    transparent_crc(g_14, "g_14", print_hash_value);
    transparent_crc(g_17, "g_17", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_85[i], "g_85[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_201[i], "g_201[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_451, "g_451", print_hash_value);
    transparent_crc(g_470, "g_470", print_hash_value);
    transparent_crc(g_557, "g_557", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_643[i][j], "g_643[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_651, "g_651", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_661[i], "g_661[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_812, "g_812", print_hash_value);
    transparent_crc(g_838, "g_838", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_860[i][j], "g_860[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_912, "g_912", print_hash_value);
    transparent_crc(g_949, "g_949", print_hash_value);
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
    int i, j;
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    csmith_compute_hash();
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
