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
static int g_2 = 0x24A8C6A5L;
static int g_47 = 0xD53D2AE4L;
static unsigned short g_60 = 0x1B9BL;
static signed char g_118 = 0L;
static signed char g_143 = (-4L);
static int *g_149 = &g_2;
static int *g_153 = &g_2;
static signed char g_160 = 1L;
static int g_163 = 0x1E14FE22L;
static int g_168 = 1L;
static short g_169[9] = {0x8E0DL, 0x1F6BL, 0x8E0DL, 0x1F6BL, 0x8E0DL, 0x1F6BL, 0x8E0DL, 0x1F6BL, 0x8E0DL};
static int g_170 = 0xDB654FA8L;
static short g_171 = 3L;
static short g_180 = 0x4318L;
static short g_181[3] = {0x626EL, 0x626EL, 0x626EL};
static short g_182 = (-2L);
static signed char g_183 = (-1L);
static unsigned g_184 = 1UL;
static unsigned g_206[1][6] = {{4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL, 4294967295UL}};
static int **g_241 = &g_149;
static int ***g_240[6] = {&g_241, &g_241, &g_241, &g_241, &g_241, &g_241};
static unsigned char g_264[5][6] = {{0xE4L, 0UL, 0xE4L, 0UL, 0xE4L, 0UL}, {0xE4L, 0UL, 0xE4L, 0UL, 0xE4L, 0UL}, {0xE4L, 0UL, 0xE4L, 0UL, 0xE4L, 0UL}, {0xE4L, 0UL, 0xE4L, 0UL, 0xE4L, 0UL}, {0xE4L, 0UL, 0xE4L, 0UL, 0xE4L, 0UL}};
static unsigned short g_277 = 0xA542L;
static int **g_364[7] = {&g_149, &g_149, &g_149, &g_149, &g_149, &g_149, &g_149};
static short g_481 = 1L;
static short g_483 = 8L;
static int g_568 = (-1L);
static unsigned g_594 = 4294967295UL;
static short g_609[2][6] = {{0L, 0x7F01L, (-2L), (-2L), 0x7F01L, 0L}, {0L, 0x7F01L, (-2L), (-2L), 0x7F01L, 0L}};
static short g_622 = 0x51D2L;
static int *g_696 = (void*)0;
static unsigned g_789 = 4294967295UL;
static int *g_862 = (void*)0;
static unsigned g_877 = 5UL;
static short g_908 = 0x9487L;
static int g_1187 = 0xB5F68AEFL;
static unsigned short g_1219[3] = {65526UL, 65526UL, 65526UL};
static unsigned g_1510 = 0x795E7EECL;
static unsigned char g_1514 = 0x34L;
static short func_1(void);
static int func_5(unsigned char p_6, unsigned char p_7, unsigned p_8, signed char p_9, short p_10);
static int func_19(unsigned p_20, int p_21, unsigned char p_22, unsigned char p_23, signed char p_24);
static unsigned short func_27(unsigned short p_28, unsigned p_29, unsigned p_30);
static unsigned short func_36(unsigned p_37, unsigned p_38, unsigned char p_39, signed char p_40, signed char p_41);
static int * func_65(unsigned p_66, int * p_67, unsigned p_68, int p_69);
static signed char func_80(int * p_81, unsigned char p_82, short p_83, unsigned p_84, int p_85);
static int func_121(unsigned char p_122, short p_123);
static int * func_124(unsigned p_125, int * p_126);
static int func_127(int p_128, unsigned p_129, int * p_130, int * p_131, int * p_132);
static short func_1(void)
{
    unsigned short l_35[2][1];
    unsigned l_1425[7] = {1UL, 1UL, 0UL, 1UL, 1UL, 0UL, 1UL};
    int l_1458[2][2];
    int **l_1463 = (void*)0;
    int l_1515 = 0x3003920BL;
    unsigned l_1517 = 4294967295UL;
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 1; j++)
            l_35[i][j] = 0xF8B4L;
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
            l_1458[i][j] = 0xB16A6C64L;
    }
    step_hash(809);
    for (g_2 = 0; (g_2 == 7); g_2 += 8)
    {
        unsigned l_13 = 0x3EE32743L;
        int *l_1449 = &g_163;
        int **l_1462 = (void*)0;
        int l_1466[10][3] = {{0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}, {0xC02E53E6L, (-2L), 0x7C201188L}};
        int *l_1513 = &g_168;
        short l_1516 = (-9L);
        int i, j;
    }
    step_hash(810);
    l_1517++;
    step_hash(811);
    return g_481;
}
static int func_5(unsigned char p_6, unsigned char p_7, unsigned p_8, signed char p_9, short p_10)
{
    int l_1422 = 0xCD897E88L;
    step_hash(744);
    l_1422 = (l_1422 && (func_36((g_609[0][2] ^ 1L), g_1219[2], g_264[1][0], g_169[8], g_181[1]) > p_9));
    step_hash(745);
    return p_7;
}
static int func_19(unsigned p_20, int p_21, unsigned char p_22, unsigned char p_23, signed char p_24)
{
    unsigned short l_893 = 1UL;
    int *l_898 = &g_2;
    int l_909 = 0x5BA3F23DL;
    short l_911 = 0xA06BL;
    int l_912[2][1];
    signed char l_913 = 0xB6L;
    int l_946 = (-1L);
    int l_953[8] = {1L, 0L, 1L, 0L, 1L, 0L, 1L, 0L};
    int *l_1009 = &l_953[5];
    signed char l_1014 = 0x00L;
    int ***l_1054 = &g_241;
    int *l_1066 = &l_912[1][0];
    unsigned short l_1077 = 1UL;
    int *l_1133 = &l_953[5];
    signed char l_1140 = 0x1DL;
    short l_1148 = 0x0BA7L;
    int l_1149 = 0L;
    int *l_1174[2][3] = {{&g_47, &g_47, (void*)0}, {&g_47, &g_47, (void*)0}};
    short l_1254 = 0x1287L;
    short l_1321 = 1L;
    int *l_1417[5] = {&l_912[0][0], &l_912[1][0], &l_912[0][0], &l_912[1][0], &l_912[0][0]};
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 1; j++)
            l_912[i][j] = 0xC1DF05E8L;
    }
    step_hash(699);
    if ((*l_898))
    {
        unsigned l_899 = 0xE477032BL;
        int l_900 = 0x41CE44D2L;
        step_hash(457);
        l_900 = l_899;
        step_hash(458);
        l_900 = p_21;
        step_hash(459);
        return p_22;
    }
    else
    {
        int *l_905[10][4] = {{(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}, {(void*)0, &g_168, &g_47, &g_168}};
        int ***l_921 = &g_364[6];
        unsigned l_944 = 4294967295UL;
        unsigned char l_987[2][9] = {{1UL, 1UL, 0x70L, 246UL, 0xF6L, 246UL, 0x70L, 1UL, 1UL}, {1UL, 1UL, 0x70L, 246UL, 0xF6L, 246UL, 0x70L, 1UL, 1UL}};
        unsigned l_991 = 4294967295UL;
        int *l_992[3][3] = {{&g_168, &g_168, &l_953[3]}, {&g_168, &g_168, &l_953[3]}, {&g_168, &g_168, &l_953[3]}};
        int l_997 = (-1L);
        signed char l_1065 = 0x06L;
        int l_1073 = 1L;
        unsigned short l_1093 = 0x900EL;
        int l_1121 = 0L;
        int *l_1171 = &l_1121;
        int l_1244 = 0x098D35D0L;
        short l_1277 = (-10L);
        int *l_1322 = (void*)0;
        int *l_1336 = &l_1149;
        int i, j;
        step_hash(523);
        if ((((unsigned short)((unsigned short)0xA1A0L >> (unsigned short)13) + (unsigned short)(p_21 == func_80(l_905[9][1], g_143, func_27(g_182, p_21, p_21), p_23, g_789))) == 0xB1A7L))
        {
            short l_906[8] = {0x680DL, 0x5615L, 0x680DL, 0x5615L, 0x680DL, 0x5615L, 0x680DL, 0x5615L};
            int l_907 = 0x1E2BE269L;
            int l_910 = 0x51D8E82DL;
            int l_914[6][2] = {{(-1L), (-1L)}, {(-1L), (-1L)}, {(-1L), (-1L)}, {(-1L), (-1L)}, {(-1L), (-1L)}, {(-1L), (-1L)}};
            short l_915[3];
            unsigned l_916 = 7UL;
            int **l_926 = &l_898;
            short l_929 = (-1L);
            int i, j;
            for (i = 0; i < 3; i++)
                l_915[i] = 1L;
            step_hash(462);
            l_916--;
            step_hash(468);
            for (l_916 = 0; (l_916 < 35); ++l_916)
            {
                signed char l_930 = 0L;
                int l_931 = 0x21B3892EL;
                step_hash(466);
                p_21 = func_27((((void*)0 != l_921) & (p_24 & (!((signed char)0xF7L / (signed char)((unsigned char)(0xEFL || ((void*)0 == l_926)) % (unsigned char)((unsigned char)251UL + (unsigned char)((void*)0 != &l_898))))))), l_929, l_930);
                step_hash(467);
                l_931 = (**l_926);
            }
            step_hash(469);
            p_21 = p_22;
        }
        else
        {
            unsigned l_940 = 4294967294UL;
            int l_949 = 0x2BCA82F7L;
            int l_951 = 0x1130121FL;
            int l_952 = 0L;
            int l_959 = (-1L);
            int l_962 = 0x2CC8EA25L;
            signed char l_973 = 0L;
            int l_974 = 0L;
            int *l_986 = &l_953[7];
            int *l_1006[5][4] = {{&l_953[7], (void*)0, &l_997, &l_997}, {&l_953[7], (void*)0, &l_997, &l_997}, {&l_953[7], (void*)0, &l_997, &l_997}, {&l_953[7], (void*)0, &l_997, &l_997}, {&l_953[7], (void*)0, &l_997, &l_997}};
            unsigned char l_1067 = 0UL;
            int i, j;
            step_hash(499);
            for (p_24 = 0; (p_24 >= 0); p_24 -= 1)
            {
                short l_943 = 0L;
                int *l_945 = &g_47;
                int l_950 = 0xF2A1F318L;
                int l_954 = (-1L);
                int l_956 = 0xAA53A08EL;
                int l_958 = 4L;
                int l_960 = (-4L);
                int l_963 = (-4L);
                int l_964 = 0x09A47A30L;
                int l_965 = (-1L);
                int l_967 = 0x6EA205E6L;
                int l_970 = (-5L);
                int l_971 = 2L;
                int l_972 = (-1L);
                step_hash(474);
                (*g_241) = &p_21;
                step_hash(475);
                p_21 = (p_24 > (func_80(func_65((((unsigned short)(((**g_241) < p_21) ^ ((signed char)(((unsigned short)((unsigned short)l_940 - (unsigned short)(1UL < p_24)) * (unsigned short)func_36(((*g_153) <= 1L), ((int)((((~((0x775EBC43L > l_943) <= l_944)) || g_163) ^ 0x9965L) >= p_22) / (int)p_21), g_594, g_264[1][5], g_206[0][5])) ^ p_23) << (signed char)p_24)) - (unsigned short)0x95E4L) > (-9L)), l_945, p_22, l_940), l_946, g_143, g_171, p_21) == 0xE8L));
                step_hash(498);
                for (l_893 = 0; (l_893 <= 0); l_893 += 1)
                {
                    short l_947[10][2] = {{0x8813L, (-6L)}, {0x8813L, (-6L)}, {0x8813L, (-6L)}, {0x8813L, (-6L)}, {0x8813L, (-6L)}, {0x8813L, (-6L)}, {0x8813L, (-6L)}, {0x8813L, (-6L)}, {0x8813L, (-6L)}, {0x8813L, (-6L)}};
                    int l_948[5][6];
                    unsigned char l_975 = 1UL;
                    unsigned short l_978 = 0xEF91L;
                    int ***l_983 = &g_364[6];
                    int l_1000 = 0xD4449F1DL;
                    int i, j;
                    for (i = 0; i < 5; i++)
                    {
                        for (j = 0; j < 6; j++)
                            l_948[i][j] = 1L;
                    }
                    step_hash(486);
                    for (g_483 = 0; (g_483 <= 0); g_483 += 1)
                    {
                        int l_955 = 0L;
                        int l_957 = 0xC6F9D72DL;
                        int l_961 = 0x39950F4EL;
                        int l_966 = 0x3158F380L;
                        int l_968 = 0x14F9D0BFL;
                        int l_969[7];
                        int i, j;
                        for (i = 0; i < 7; i++)
                            l_969[i] = 0x0B9A8A53L;
                        step_hash(482);
                        l_975++;
                        step_hash(483);
                        (*l_945) ^= l_912[(g_483 + 1)][p_24];
                        step_hash(484);
                        (**l_921) = &p_21;
                        step_hash(485);
                        ++l_978;
                    }
                }
            }
            step_hash(500);
            (*l_1009) = ((((unsigned)((0L || func_80(l_1009, g_206[0][5], func_36(((unsigned short)((((signed char)func_27(((void*)0 == l_921), (*l_986), g_877) / (signed char)(-4L)) > p_24) != (*l_986)) - (unsigned short)1L), p_23, p_22, p_22, g_2), (*l_898), p_22)) <= p_22) % (unsigned)l_1014) | g_622) >= 1L);
            step_hash(501);
            (*l_1009) = ((short)(((unsigned char)((((unsigned char)((unsigned char)g_481 << (unsigned char)(g_609[1][0] <= p_21)) << (unsigned char)4) ^ ((unsigned short)((unsigned short)(p_23 == (*l_986)) % (unsigned short)((p_24 | ((unsigned short)0xD5E7L * (unsigned short)0xB63CL)) && (*l_898))) * (unsigned short)g_181[1])) != (*l_898)) + (unsigned char)g_181[0]) != 0xA90DL) >> (short)0);
            step_hash(522);
            for (g_622 = 1; (g_622 >= 0); g_622 -= 1)
            {
                int ***l_1033 = &g_364[1];
                int l_1068 = 0xA211296BL;
                int l_1071[3][2] = {{0x7485DD73L, 0x7485DD73L}, {0x7485DD73L, 0x7485DD73L}, {0x7485DD73L, 0x7485DD73L}};
                int i, j;
                step_hash(509);
                for (l_973 = 0; (l_973 <= 0); l_973 += 1)
                {
                    int i, j;
                    step_hash(508);
                    (*l_1009) &= (l_912[l_973][l_973] ^ (((unsigned char)l_987[l_973][(l_973 + 3)] % (unsigned char)((int)g_206[l_973][l_973] - (int)(g_264[0][0] < (-1L)))) ^ p_21));
                }
                step_hash(510);
                (*l_1009) = ((((short)(((int)p_20 - (int)(((short)((signed char)(((((unsigned char)((void*)0 == &g_241) * (unsigned char)(l_1054 != l_1054)) > ((short)((unsigned char)((unsigned short)(((short)g_168 << (short)((unsigned short)((((((((p_24 >= (g_908 || g_168)) && (*l_1009)) | p_20) == 0x5820L) <= 65535UL) | 0x0AL) ^ p_20) != 0xB0D3L) << (unsigned short)g_182)) ^ g_609[1][0]) >> (unsigned short)8) - (unsigned char)g_568) + (short)p_22)) & g_789) || l_1067) % (signed char)g_908) << (short)15) | 0xB9D6558CL)) >= g_180) << (short)1) > 255UL) == 0x8C61A88DL);
                step_hash(511);
                p_21 &= ((void*)0 == &p_21);
                step_hash(521);
                for (l_952 = 0; (l_952 >= 0); l_952 -= 1)
                {
                    short l_1070 = 0x4F35L;
                    int l_1072[10][1] = {{1L}, {1L}, {1L}, {1L}, {1L}, {1L}, {1L}, {1L}, {1L}, {1L}};
                    int i, j;
                    step_hash(520);
                    for (l_959 = 0; (l_959 >= 0); l_959 -= 1)
                    {
                        int l_1069 = 0xD387E225L;
                        unsigned l_1074 = 0xCD55DC8EL;
                        int i, j;
                        step_hash(518);
                        l_1074--;
                        step_hash(519);
                        p_21 &= func_36(l_912[l_959][l_959], l_912[(l_959 + 1)][l_959], l_987[l_952][(l_952 + 6)], g_2, p_22);
                    }
                }
            }
        }
        step_hash(572);
        for (g_160 = 6; (g_160 >= 0); g_160 -= 1)
        {
            int l_1082 = 0L;
            int *l_1083 = (void*)0;
            unsigned char l_1090 = 0xECL;
            step_hash(527);
            (*l_1009) ^= p_21;
            step_hash(528);
            (*g_241) = &p_21;
            step_hash(529);
            if ((*g_153))
                break;
            step_hash(565);
            if (((((void*)0 != (*l_1054)) && func_80(&p_21, (l_1077 == (p_20 >= p_23)), g_908, p_24, g_184)) & 0x96BEL))
            {
                step_hash(531);
                return p_22;
            }
            else
            {
                short l_1115 = 0xEDC8L;
                int *l_1116 = (void*)0;
                int l_1122[8] = {1L, 1L, 1L, 1L, 1L, 1L, 1L, 1L};
                int i;
                step_hash(563);
                if ((((short)g_622 * (short)((0x8FL | (+(0x02L & g_481))) & func_27(((unsigned short)(((void*)0 == &g_364[3]) < ((signed char)g_184 % (signed char)l_1090)) << (unsigned short)12), ((unsigned char)(((g_168 ^ p_24) <= 1L) && 0xD5A2L) >> (unsigned char)7), p_21))) | l_1093))
                {
                    unsigned l_1096[8] = {1UL, 0x4060C70EL, 1UL, 0x4060C70EL, 1UL, 0x4060C70EL, 1UL, 0x4060C70EL};
                    int l_1114 = 0x85F7C919L;
                    int i;
                    step_hash(534);
                    (*l_1009) = (p_23 | p_23);
                    step_hash(535);
                    (*g_241) = (**l_1054);
                    step_hash(540);
                    for (p_22 = 0; (p_22 <= 5); p_22 += 1)
                    {
                        step_hash(539);
                        (*l_1066) = ((short)0x2F66L >> (short)0);
                    }
                    step_hash(548);
                    for (g_171 = 0; (g_171 <= 1); g_171 += 1)
                    {
                        int i, j;
                        step_hash(544);
                        l_1096[7]--;
                        step_hash(545);
                        if (l_987[g_171][(g_171 + 7)])
                            continue;
                        step_hash(546);
                        l_1114 |= ((signed char)((short)(((short)((void*)0 != (*l_1054)) * (short)((unsigned short)(((int)p_21 - (int)(g_264[0][4] | (((l_1096[0] == ((short)((short)0xF2D3L << (short)func_80((**l_921), (g_568 && (-(unsigned short)(!0xA78FL))), g_568, g_60, g_568)) * (short)g_264[4][3])) && g_277) >= g_60))) >= 0xE2L) * (unsigned short)p_22)) & p_20) / (short)g_481) / (signed char)p_20);
                        step_hash(547);
                        return l_1115;
                    }
                }
                else
                {
                    int **l_1119 = (void*)0;
                    int *l_1120 = &l_997;
                    step_hash(556);
                    if (p_22)
                    {
                        step_hash(551);
                        (**l_921) = l_1083;
                    }
                    else
                    {
                        unsigned l_1123 = 4294967294UL;
                        int i;
                        step_hash(553);
                        l_1123++;
                        step_hash(554);
                        (**l_921) = &l_1122[4];
                        step_hash(555);
                        (**g_241) ^= 1L;
                    }
                    step_hash(561);
                    for (g_180 = 0; (g_180 <= 5); g_180 += 1)
                    {
                        short l_1128 = 1L;
                        step_hash(560);
                        (*l_1120) = (3UL == func_80(l_1120, ((short)l_1128 * (short)g_163), g_206[0][3], func_36(((unsigned char)((unsigned short)((&g_364[6] != (void*)0) || g_168) << (unsigned short)(&g_241 == &g_241)) >> (unsigned char)g_169[8]), p_24, g_206[0][0], g_184, (*l_1009)), g_47));
                    }
                    step_hash(562);
                    (**l_1054) = &p_21;
                }
                step_hash(564);
                (*l_1066) |= (p_21 <= (4294967291UL < ((g_594 == (((l_1133 == (void*)0) | (-4L)) != ((short)func_80(&p_21, (((int)p_22 % (int)(+p_23)) != p_20), g_264[0][5], p_22, p_23) << (short)6))) | 0L)));
            }
            step_hash(571);
            for (g_568 = 0; (g_568 <= 5); g_568 += 1)
            {
                int l_1141 = 0x9B094F94L;
                step_hash(569);
                l_1140 |= (((unsigned char)247UL / (unsigned char)(+p_23)) <= 0x84L);
                step_hash(570);
                if (l_1141)
                    continue;
            }
        }
        step_hash(573);
        (*g_241) = &p_21;
        step_hash(698);
        if (((~g_160) > (((unsigned char)func_80((**l_921), p_20, ((short)g_47 * (short)(***l_921)), func_36(g_609[1][0], ((unsigned)0x5DE6CA27L % (unsigned)l_1148), (*l_898), g_609[1][1], g_163), g_206[0][4]) * (unsigned char)l_1149) > p_20)))
        {
            unsigned char l_1156[10] = {255UL, 0x8DL, 0x62L, 0x62L, 0x8DL, 255UL, 0x8DL, 0x62L, 0x62L, 0x8DL};
            int l_1175 = 1L;
            int l_1185 = 9L;
            int l_1186[2][9] = {{(-8L), (-8L), 1L, (-8L), (-8L), 1L, (-8L), (-8L), 1L}, {(-8L), (-8L), 1L, (-8L), (-8L), 1L, (-8L), (-8L), 1L}};
            unsigned short l_1188 = 65530UL;
            unsigned l_1196[10][2] = {{0xB2840402L, 1UL}, {0xB2840402L, 1UL}, {0xB2840402L, 1UL}, {0xB2840402L, 1UL}, {0xB2840402L, 1UL}, {0xB2840402L, 1UL}, {0xB2840402L, 1UL}, {0xB2840402L, 1UL}, {0xB2840402L, 1UL}, {0xB2840402L, 1UL}};
            int i, j;
            step_hash(616);
            if (((signed char)((signed char)(***l_1054) >> (signed char)((*l_1054) == (*l_921))) - (signed char)func_36(g_877, ((signed char)(g_609[0][5] < ((((void*)0 == &p_21) >= 4294967286UL) & p_22)) - (signed char)l_1156[9]), g_789, (***l_1054), p_20)))
            {
                signed char l_1165 = 6L;
                int l_1181 = 0xF14441FDL;
                int l_1182 = 0L;
                int l_1183 = (-7L);
                int l_1184[8] = {6L, 2L, 6L, 2L, 6L, 2L, 6L, 2L};
                int **l_1202 = &g_862;
                int i;
                step_hash(591);
                if (((*g_149) & ((unsigned short)((*g_153) == ((unsigned char)p_23 - (unsigned char)(+0x4DL))) % (unsigned short)((unsigned short)((((void*)0 == &g_364[0]) & func_36(((*l_1133) ^ ((unsigned char)(p_24 ^ g_160) >> (unsigned char)l_1165)), l_1156[6], l_1165, p_24, p_23)) != p_22) % (unsigned short)p_21))))
                {
                    step_hash(581);
                    for (g_60 = 0; (g_60 <= 1); g_60 += 1)
                    {
                        int i;
                        step_hash(580);
                        return g_169[(g_60 + 7)];
                    }
                }
                else
                {
                    signed char l_1168 = 0x97L;
                    unsigned short l_1176[1][8] = {{0x7B16L, 0x6ED2L, 0x7B16L, 0x6ED2L, 0x7B16L, 0x6ED2L, 0x7B16L, 0x6ED2L}};
                    int i, j;
                    step_hash(583);
                    (*l_1133) &= (((unsigned char)func_121(((***l_1054) <= g_908), l_1168) * (unsigned char)(g_181[0] >= 4UL)) & ((unsigned short)g_877 / (unsigned short)(-1L)));
                    step_hash(584);
                    (**g_241) = (&p_21 != l_1171);
                    step_hash(589);
                    for (g_877 = 0; (g_877 > 13); g_877 += 1)
                    {
                        step_hash(588);
                        (**l_921) = (**l_921);
                    }
                    step_hash(590);
                    l_1176[0][7]--;
                }
                step_hash(597);
                for (g_183 = (-16); (g_183 >= 20); g_183 += 7)
                {
                    step_hash(595);
                    (*l_1133) &= 0xC2BE1739L;
                    step_hash(596);
                    return p_22;
                }
                step_hash(598);
                l_1188++;
                step_hash(613);
                for (g_170 = (-15); (g_170 > 25); g_170 += 6)
                {
                    int *l_1195 = &l_1121;
                    step_hash(602);
                    if ((**g_241))
                        break;
                    step_hash(611);
                    if ((l_1182 >= ((unsigned)(~(0x33L >= p_24)) - (unsigned)(*g_149))))
                    {
                        int *l_1197 = &l_1186[1][1];
                        step_hash(604);
                        p_21 = l_1182;
                        step_hash(605);
                        (**l_921) = &p_21;
                        step_hash(606);
                        (*l_1197) &= (((short)(*l_1133) >> (short)11) >= g_609[0][0]);
                        step_hash(607);
                        p_21 &= (((g_160 != (&p_21 == (*g_241))) >= ((((unsigned short)g_143 * (unsigned short)(l_1202 != &l_1195)) == g_483) <= g_594)) && (((short)((!((signed char)((g_789 >= l_1156[2]) | g_181[1]) - (signed char)1UL)) > 1L) / (short)9UL) != l_1185));
                    }
                    else
                    {
                        unsigned char l_1207[4][3] = {{0x18L, 0xA8L, 0x18L}, {0x18L, 0xA8L, 0x18L}, {0x18L, 0xA8L, 0x18L}, {0x18L, 0xA8L, 0x18L}};
                        int i, j;
                        step_hash(609);
                        ++l_1207[0][0];
                        step_hash(610);
                        p_21 |= (p_20 <= (l_921 == &g_364[6]));
                    }
                    step_hash(612);
                    return l_1188;
                }
            }
            else
            {
                step_hash(615);
                (*l_1133) ^= p_21;
            }
        }
        else
        {
            int *l_1214[5];
            unsigned char l_1248 = 0x6CL;
            unsigned short l_1251 = 0x9B75L;
            unsigned l_1256 = 0x6A7B2E7CL;
            int ***l_1263 = &g_241;
            int i;
            for (i = 0; i < 5; i++)
                l_1214[i] = (void*)0;
            step_hash(663);
            for (p_20 = 0; (p_20 <= 1); p_20 += 1)
            {
                int l_1231 = 0x67E08DB2L;
                unsigned l_1234 = 0x100EFEDDL;
                int l_1255[2][2];
                int ***l_1276[6] = {&g_241, &g_241, (void*)0, &g_241, &g_241, (void*)0};
                int i, j;
                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 2; j++)
                        l_1255[i][j] = 0x3B2DDD24L;
                }
            }
            step_hash(696);
            for (l_1248 = (-18); (l_1248 != 52); l_1248 += 4)
            {
                int l_1280[2];
                int *l_1296 = &g_163;
                int l_1297[8][6] = {{0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL}, {0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL}, {0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL}, {0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL}, {0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL}, {0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL}, {0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL}, {0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL, 0xF43FA6C4L, 0xD2FF1DCFL}};
                short l_1303 = 0x685CL;
                signed char l_1319 = 0xCDL;
                int i, j;
                for (i = 0; i < 2; i++)
                    l_1280[i] = 0x714C9F04L;
                step_hash(680);
                for (g_180 = 0; (g_180 <= 8); g_180 += 1)
                {
                    unsigned short l_1298 = 0xE5B4L;
                    step_hash(670);
                    p_21 = l_1280[0];
                }
                step_hash(695);
                for (g_168 = 0; (g_168 >= (-13)); g_168 -= 8)
                {
                    unsigned short l_1306 = 0xEB7EL;
                    unsigned l_1324 = 0UL;
                    step_hash(684);
                    (*l_1133) = (+(&p_21 == (**l_1263)));
                    step_hash(693);
                    if (func_80((**l_1263), (((&p_21 == &p_21) && (l_1303 == p_23)) >= p_20), ((signed char)((void*)0 != &g_241) >> (signed char)5), l_1306, p_24))
                    {
                        short l_1320[8][3] = {{0xFF61L, 0x5A70L, 0xFF61L}, {0xFF61L, 0x5A70L, 0xFF61L}, {0xFF61L, 0x5A70L, 0xFF61L}, {0xFF61L, 0x5A70L, 0xFF61L}, {0xFF61L, 0x5A70L, 0xFF61L}, {0xFF61L, 0x5A70L, 0xFF61L}, {0xFF61L, 0x5A70L, 0xFF61L}, {0xFF61L, 0x5A70L, 0xFF61L}};
                        int *l_1323 = (void*)0;
                        int i, j;
                        step_hash(686);
                        (*l_1066) = (((unsigned)0x4E8CC0BCL % (unsigned)(((((unsigned char)((short)0xE1DBL / (short)g_169[8]) << (unsigned char)3) & (***l_1054)) && l_1324) & (*l_1133))) != p_20);
                        step_hash(687);
                        (*l_1133) = (-6L);
                        step_hash(688);
                        (*l_1066) = (((signed char)(+(-(short)((unsigned)(((unsigned short)1UL + (unsigned short)0UL) | ((signed char)((((+g_182) || 1L) ^ (***l_1263)) ^ g_184) / (signed char)p_24)) / (unsigned)((unsigned short)g_163 - (unsigned short)(g_118 == p_22))))) + (signed char)g_168) | g_264[4][3]);
                        step_hash(689);
                        if (p_21)
                            break;
                    }
                    else
                    {
                        unsigned char l_1337 = 0x8DL;
                        step_hash(691);
                        (*l_1133) = ((p_20 != func_36((p_20 | (p_24 < p_23)), p_23, p_24, func_80(l_1336, g_180, g_184, g_609[1][0], g_1187), g_169[8])) || g_171);
                        step_hash(692);
                        if (l_1337)
                            break;
                    }
                    step_hash(694);
                    (*l_921) = (void*)0;
                }
            }
            step_hash(697);
            (**l_1263) = (**l_1263);
        }
    }
    step_hash(741);
    for (p_24 = 4; (p_24 >= 1); p_24 -= 1)
    {
        signed char l_1338[3];
        int *l_1355 = &l_1149;
        int l_1364 = 0xF86B0A32L;
        int l_1365 = 0xEAF68E67L;
        int l_1370 = 0x28A3F8DCL;
        int l_1371 = 0x76B49374L;
        int l_1373 = 1L;
        int l_1374 = 0x5E9E835CL;
        int l_1377[5] = {(-1L), (-9L), (-1L), (-9L), (-1L)};
        short l_1410 = (-2L);
        int *l_1418 = &l_909;
        short l_1419 = 0x0113L;
        int i;
        for (i = 0; i < 3; i++)
            l_1338[i] = 5L;
    }
    step_hash(742);
    return p_24;
}
static unsigned short func_27(unsigned short p_28, unsigned p_29, unsigned p_30)
{
    short l_76 = (-1L);
    int *l_77[9];
    signed char l_891 = 0xCBL;
    unsigned l_892[9][3] = {{0x5410DABFL, 0xAE168533L, 0x6EDE564AL}, {0x5410DABFL, 0xAE168533L, 0x6EDE564AL}, {0x5410DABFL, 0xAE168533L, 0x6EDE564AL}, {0x5410DABFL, 0xAE168533L, 0x6EDE564AL}, {0x5410DABFL, 0xAE168533L, 0x6EDE564AL}, {0x5410DABFL, 0xAE168533L, 0x6EDE564AL}, {0x5410DABFL, 0xAE168533L, 0x6EDE564AL}, {0x5410DABFL, 0xAE168533L, 0x6EDE564AL}, {0x5410DABFL, 0xAE168533L, 0x6EDE564AL}};
    int i, j;
    for (i = 0; i < 9; i++)
        l_77[i] = &g_2;
    step_hash(448);
    for (p_30 = 0; (p_30 > 40); p_30 += 1)
    {
        unsigned char l_72 = 0x5AL;
        int *l_86 = &g_47;
        int l_863 = 0x1C3A6D85L;
        int l_864 = 0x41A87B9FL;
        int l_865 = 0x60445050L;
        short l_866 = 9L;
        int l_867 = 0x6801D6FEL;
        int l_868 = 6L;
        int l_869 = 1L;
        int l_870 = 9L;
        int l_871 = 5L;
        int l_872 = 3L;
        int l_873[3][6] = {{5L, 5L, 0x08659854L, (-1L), 0L, (-1L)}, {5L, 5L, 0x08659854L, (-1L), 0L, (-1L)}, {5L, 5L, 0x08659854L, (-1L), 0L, (-1L)}};
        unsigned short l_874 = 0x697AL;
        int i, j;
    }
    step_hash(453);
    for (g_170 = 0; (g_170 >= (-9)); --g_170)
    {
        int *l_882 = (void*)0;
        step_hash(452);
        (*g_241) = l_882;
    }
    step_hash(454);
    return p_30;
}







static unsigned short func_36(unsigned p_37, unsigned p_38, unsigned char p_39, signed char p_40, signed char p_41)
{
    int *l_46 = &g_47;
    int l_48 = 1L;
    int *l_49 = (void*)0;
    int *l_50 = &l_48;
    int *l_51 = &g_47;
    int *l_52 = &g_47;
    int *l_53 = &l_48;
    int l_54 = (-4L);
    int *l_55 = &g_47;
    int *l_56 = &l_54;
    int *l_57 = &g_47;
    int *l_58[5][2] = {{(void*)0, (void*)0}, {(void*)0, (void*)0}, {(void*)0, (void*)0}, {(void*)0, (void*)0}, {(void*)0, (void*)0}};
    int l_59 = 0x236511F0L;
    int i, j;
    step_hash(6);
    --g_60;
    step_hash(7);
    return (*l_57);
}







static int * func_65(unsigned p_66, int * p_67, unsigned p_68, int p_69)
{
    unsigned l_283 = 1UL;
    int *l_302 = &g_2;
    int l_334 = 1L;
    int l_343 = (-9L);
    int l_344 = 0xD1ED096BL;
    int l_347 = 0x8158996BL;
    int l_349 = 1L;
    int l_350 = 1L;
    int l_351 = 0x19A99B7AL;
    int l_352[10] = {0x358AF41BL, 0x358AF41BL, 0x033CB161L, 0x358AF41BL, 0x358AF41BL, 0x033CB161L, 0x358AF41BL, 0x358AF41BL, 0x033CB161L, 0x358AF41BL};
    int ***l_386 = &g_364[6];
    unsigned l_417 = 0xCA51754DL;
    short l_477 = (-1L);
    signed char l_544 = 0x64L;
    short l_545 = 0xF955L;
    unsigned char l_546 = 1UL;
    unsigned char l_570 = 0x51L;
    unsigned short l_636[7][2] = {{0UL, 5UL}, {0UL, 5UL}, {0UL, 5UL}, {0UL, 5UL}, {0UL, 5UL}, {0UL, 5UL}, {0UL, 5UL}};
    int *l_672 = &l_344;
    int l_713[7] = {0x0D93A79EL, 0x0D93A79EL, 0xD45FC68DL, 0x0D93A79EL, 0x0D93A79EL, 0xD45FC68DL, 0x0D93A79EL};
    signed char l_742 = 0xDEL;
    int l_823 = 0xBBF2409EL;
    unsigned short l_824 = 0x7FD5L;
    int l_841 = 1L;
    unsigned l_842 = 4294967286UL;
    int *l_845 = (void*)0;
    int i, j;
    step_hash(274);
    for (g_60 = 0; (g_60 != 21); g_60++)
    {
        int l_292 = 0x75F8133EL;
        int *l_305 = &g_163;
        int l_332 = 0x81374B14L;
        int l_335 = (-1L);
        int l_339 = 0x9B219FC2L;
        int l_340 = 0x3AF24F68L;
        int l_341 = 0x22182E24L;
        int l_342 = (-10L);
        int l_346 = 0x15A7122BL;
        int l_353 = 0x0B4E7AACL;
        int ***l_433 = &g_364[6];
        unsigned l_451[9] = {4294967294UL, 4294967288UL, 4294967294UL, 4294967288UL, 4294967294UL, 4294967288UL, 4294967294UL, 4294967288UL, 4294967294UL};
        int l_479 = 0xDACAA398L;
        int l_480 = 0L;
        int l_482[10][2];
        unsigned l_521[3];
        int *l_539 = &l_347;
        int *l_540 = &l_344;
        int *l_541 = &l_353;
        int *l_542 = &g_163;
        int *l_543[3];
        int i, j;
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 2; j++)
                l_482[i][j] = 0x0A20FAC9L;
        }
        for (i = 0; i < 3; i++)
            l_521[i] = 0x52AF3082L;
        for (i = 0; i < 3; i++)
            l_543[i] = &l_334;
    }
    step_hash(281);
    for (g_160 = 0; (g_160 == 19); g_160 += 1)
    {
        signed char l_553 = 0x2DL;
        int *l_556[6];
        int i;
        for (i = 0; i < 6; i++)
            l_556[i] = &l_350;
        step_hash(278);
        (*p_67) = (((short)l_553 * (short)g_182) <= ((short)0x722FL + (short)(~g_264[0][4])));
        step_hash(279);
        (*g_241) = l_556[0];
        step_hash(280);
        (*g_149) = (*p_67);
    }
    step_hash(415);
    for (p_69 = 0; (p_69 < 1); p_69++)
    {
        int *l_559 = &g_163;
        unsigned char l_560 = 0x33L;
        int l_567 = 9L;
        int l_569[3][5] = {{0xCC8681FCL, 0xD8455F49L, 0xCC8681FCL, 0xD8455F49L, 0xCC8681FCL}, {0xCC8681FCL, 0xD8455F49L, 0xCC8681FCL, 0xD8455F49L, 0xCC8681FCL}, {0xCC8681FCL, 0xD8455F49L, 0xCC8681FCL, 0xD8455F49L, 0xCC8681FCL}};
        int l_620 = 2L;
        unsigned l_658 = 8UL;
        int *l_661 = &l_347;
        int *l_671 = &l_349;
        unsigned l_714[1];
        unsigned l_764 = 4294967293UL;
        int i, j;
        for (i = 0; i < 1; i++)
            l_714[i] = 1UL;
    }
    step_hash(423);
    if ((*l_672))
    {
        int *l_818 = (void*)0;
        int *l_819 = &l_334;
        int *l_820 = &l_343;
        int *l_821 = &l_352[0];
        int *l_822[8][4] = {{&g_168, &l_713[6], &l_713[6], &g_170}, {&g_168, &l_713[6], &l_713[6], &g_170}, {&g_168, &l_713[6], &l_713[6], &g_170}, {&g_168, &l_713[6], &l_713[6], &g_170}, {&g_168, &l_713[6], &l_713[6], &g_170}, {&g_168, &l_713[6], &l_713[6], &g_170}, {&g_168, &l_713[6], &l_713[6], &g_170}, {&g_168, &l_713[6], &l_713[6], &g_170}};
        int i, j;
        step_hash(417);
        l_824++;
        step_hash(418);
        (*l_820) = func_36((~((unsigned short)(***l_386) << (unsigned short)8)), p_68, g_160, (~((((&g_364[0] != (void*)0) | ((*g_149) < ((unsigned char)func_36(((short)((short)(((signed char)(*l_821) % (signed char)p_66) != ((0x0DL & g_181[1]) == 1UL)) + (short)p_69) * (short)0xE0D7L), (*l_819), g_264[4][3], p_68, g_568) % (unsigned char)0xC1L))) > g_183) ^ 0xFEC8L)), p_66);
    }
    else
    {
        int *l_837 = (void*)0;
        int *l_838 = &l_344;
        int *l_839[6];
        signed char l_840 = 0xB3L;
        int i;
        for (i = 0; i < 6; i++)
            l_839[i] = &l_334;
        step_hash(420);
        (*l_672) &= ((void*)0 != l_837);
        step_hash(421);
        (*p_67) = (*p_67);
        step_hash(422);
        l_842++;
    }
    step_hash(424);
    return l_845;
}







static signed char func_80(int * p_81, unsigned char p_82, short p_83, unsigned p_84, int p_85)
{
    int *l_105 = &g_47;
    signed char l_117 = 6L;
    int l_272[8] = {0x56C0A20DL, 0x56C0A20DL, 0x732B217FL, 0x56C0A20DL, 0x56C0A20DL, 0x732B217FL, 0x56C0A20DL, 0x56C0A20DL};
    int *l_280 = &g_163;
    int i;
    step_hash(127);
    for (p_83 = 0; (p_83 <= (-23)); p_83 -= 4)
    {
        unsigned char l_108 = 0x9AL;
        unsigned l_120[7] = {0x58C9C965L, 0x58C9C965L, 4294967291UL, 0x58C9C965L, 0x58C9C965L, 4294967291UL, 0x58C9C965L};
        int l_267 = 0L;
        int *l_268 = &g_170;
        int *l_269 = &l_267;
        int *l_270 = &g_168;
        int *l_271 = &g_163;
        int *l_273 = (void*)0;
        int *l_274 = &g_168;
        int *l_275 = &g_163;
        int *l_276[8] = {&l_272[2], &g_168, &l_272[2], &g_168, &l_272[2], &g_168, &l_272[2], &g_168};
        int i;
        step_hash(26);
        if (((signed char)((signed char)((signed char)g_47 << (signed char)(((unsigned short)g_47 - (unsigned short)(l_105 == p_81)) ^ (l_108 > ((unsigned short)0UL % (unsigned short)(((unsigned short)((unsigned)((unsigned short)(p_83 >= (((void*)0 != p_81) > l_108)) >> (unsigned short)p_84) - (unsigned)g_60) - (unsigned short)p_83) | 0x18L))))) + (signed char)l_117) << (signed char)6))
        {
            unsigned l_119[1];
            int i;
            for (i = 0; i < 1; i++)
                l_119[i] = 0xC5CEC10CL;
            step_hash(17);
            if (l_108)
                break;
            step_hash(18);
            g_118 &= (7UL != (*l_105));
            step_hash(23);
            for (p_82 = 0; (p_82 <= 0); p_82 += 1)
            {
                int i;
                step_hash(22);
                if (l_119[p_82])
                    break;
            }
        }
        else
        {
            step_hash(25);
            return p_84;
        }
        step_hash(124);
        for (p_84 = 0; (p_84 <= 6); p_84 += 1)
        {
            int i;
        }
        step_hash(125);
        ++g_277;
        step_hash(126);
        return p_82;
    }
    step_hash(128);
    (*l_280) |= (&l_272[2] != l_280);
    step_hash(129);
    (*g_241) = p_81;
    step_hash(130);
    return (*l_280);
}







static int func_121(unsigned char p_122, short p_123)
{
    int l_135[10][6];
    int *l_152 = &g_47;
    int ***l_262 = (void*)0;
    int *l_263[5];
    short l_265 = 0x96ABL;
    int l_266 = 0xE223FE2AL;
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 6; j++)
            l_135[i][j] = 8L;
    }
    for (i = 0; i < 5; i++)
        l_263[i] = &g_170;
    step_hash(118);
    l_152 = func_124((func_127((((unsigned char)((l_135[4][1] != (1L || ((l_135[4][1] && g_118) || (+((void*)0 == &g_2))))) ^ ((!(0xF5L == ((signed char)((unsigned char)((signed char)(0xD522L ^ 0x96F1L) / (signed char)g_118) >> (unsigned char)p_122) % (signed char)4UL))) >= g_118)) >> (unsigned char)6) == 9L), p_122, &l_135[2][4], &l_135[4][1], &l_135[4][1]) >= p_122), l_152);
    step_hash(119);
    g_264[4][3] = ((unsigned char)(((&l_152 == &l_152) == ((*l_152) == g_180)) >= ((short)((unsigned)((int)p_123 % (int)p_123) - (unsigned)(&g_241 != l_262)) >> (short)8)) % (unsigned char)func_127(((*g_149) != 0L), g_2, &l_135[7][2], &l_135[5][2], &l_135[9][5]));
    step_hash(120);
    l_265 = ((void*)0 != (*g_241));
    step_hash(121);
    l_266 = (0xC0L == 0xEFL);
    step_hash(122);
    return p_122;
}







static int * func_124(unsigned p_125, int * p_126)
{
    int *l_154 = (void*)0;
    int l_155 = 0L;
    int l_176[9][1] = {{0x9491B29FL}, {0x9491B29FL}, {0x9491B29FL}, {0x9491B29FL}, {0x9491B29FL}, {0x9491B29FL}, {0x9491B29FL}, {0x9491B29FL}, {0x9491B29FL}};
    int l_190[6] = {(-5L), (-5L), 0xC775878EL, (-5L), (-5L), 0xC775878EL};
    int *l_219 = &l_176[6][0];
    int *l_252 = &l_176[6][0];
    int *l_253[1][5] = {{&g_168, &g_168, &g_168, &g_168, &g_168}};
    int i, j;
    step_hash(115);
    if ((g_143 || (g_47 != g_143)))
    {
        step_hash(47);
        return &g_47;
    }
    else
    {
        int l_172 = 0L;
        int l_174 = 0xE64C0ED6L;
        int l_177[4];
        int i;
        for (i = 0; i < 4; i++)
            l_177[i] = 0x2EC8A694L;
        step_hash(64);
        for (g_118 = (-14); (g_118 < 16); g_118 += 9)
        {
            unsigned char l_161 = 253UL;
            int l_175 = (-7L);
            int l_178 = (-6L);
            int *l_191 = &g_163;
            step_hash(62);
            for (l_155 = (-30); (l_155 <= 21); l_155++)
            {
                int l_166 = 7L;
                int l_167 = 0x37D4A057L;
                int l_173 = 5L;
                int l_179 = 0L;
                int *l_187 = &g_170;
                step_hash(55);
                g_160 = (*g_153);
                step_hash(60);
                if (l_161)
                {
                    int *l_162 = &g_163;
                    int *l_164 = (void*)0;
                    int *l_165[8] = {&g_47, &g_47, &g_163, &g_47, &g_47, &g_163, &g_47, &g_47};
                    int i;
                    step_hash(57);
                    g_184++;
                }
                else
                {
                    step_hash(59);
                    return l_187;
                }
                step_hash(61);
                if ((*g_153))
                    break;
            }
            step_hash(63);
            (*l_191) = ((signed char)0xAAL - (signed char)(l_190[5] < (p_125 == p_125)));
        }
        step_hash(114);
        if ((g_163 & (g_118 & ((((unsigned char)(g_169[6] < (!l_172)) + (unsigned char)((unsigned short)0UL - (unsigned short)((4294967295UL | (*p_126)) >= (((unsigned short)(((g_168 != l_174) <= p_125) ^ 0x9566L) >> (unsigned short)g_168) == l_177[2])))) <= g_60) != l_177[2]))))
        {
            int *l_198 = &g_168;
            int l_199 = (-4L);
            int l_200 = 0x3571D3B0L;
            int *l_201 = (void*)0;
            int *l_202 = &l_174;
            int *l_203 = &l_200;
            int *l_204 = &l_155;
            int *l_205[5];
            int i;
            for (i = 0; i < 5; i++)
                l_205[i] = &l_174;
            step_hash(66);
            ++g_206[0][5];
            step_hash(74);
            for (g_182 = 0; (g_182 <= 3); g_182 += 1)
            {
                int i;
                step_hash(70);
                l_177[g_182] ^= (*g_153);
                step_hash(71);
                if (l_177[1])
                    break;
                step_hash(72);
                (*l_198) ^= ((((unsigned short)p_125 - (unsigned short)(((unsigned short)(l_177[1] == (*p_126)) << (unsigned short)1) & p_125)) > ((~((p_125 || g_180) || l_177[3])) == 0UL)) & p_125);
                step_hash(73);
                if (l_172)
                    break;
            }
            step_hash(75);
            (*l_202) ^= (*l_204);
        }
        else
        {
            int **l_220[3][10] = {{&l_219, &l_219, &g_153, &l_219, &l_219, &g_153, &l_219, &l_219, &g_153, &l_219}, {&l_219, &l_219, &g_153, &l_219, &l_219, &g_153, &l_219, &l_219, &g_153, &l_219}, {&l_219, &l_219, &g_153, &l_219, &l_219, &g_153, &l_219, &l_219, &g_153, &l_219}};
            int i, j;
            step_hash(77);
            p_126 = &l_177[2];
            step_hash(112);
            for (l_174 = 0; (l_174 <= 5); l_174 += 1)
            {
                int *l_244 = &g_168;
                unsigned char l_249 = 255UL;
                int i;
                step_hash(81);
                p_126 = &l_177[3];
                step_hash(82);
                if (l_190[l_174])
                    break;
                step_hash(110);
                for (g_118 = 3; (g_118 >= 0); g_118 -= 1)
                {
                    int **l_221 = &l_154;
                    step_hash(93);
                    for (g_163 = 1; (g_163 <= 5); g_163 += 1)
                    {
                        int ***l_222 = (void*)0;
                        int ***l_223 = &l_221;
                        int i;
                        step_hash(89);
                        l_219 = &l_177[g_118];
                        step_hash(90);
                        (*l_223) = l_221;
                        step_hash(91);
                        l_177[g_118] = (*g_153);
                        step_hash(92);
                        if ((*g_149))
                            continue;
                    }
                    step_hash(100);
                    for (g_183 = 0; (g_183 <= 0); g_183 += 1)
                    {
                        int i, j;
                        step_hash(97);
                        (*p_126) = g_169[(g_183 + 5)];
                        step_hash(98);
                        (*l_219) = g_206[g_183][g_118];
                        step_hash(99);
                        return &g_168;
                    }
                    step_hash(109);
                    if ((*p_126))
                    {
                        int *l_226 = (void*)0;
                        step_hash(102);
                        (*l_221) = l_226;
                        step_hash(103);
                        (*l_244) &= (((((unsigned short)func_127(l_190[l_174], ((short)((unsigned char)(-(unsigned short)((&g_149 != l_220[2][0]) ^ ((g_160 == (*p_126)) >= p_125))) >> (unsigned char)p_125) >> (short)7), (*g_241), p_126, p_126) >> (unsigned short)l_174) <= g_206[0][5]) & g_206[0][5]) & p_125);
                        step_hash(104);
                        (*p_126) = (*l_244);
                    }
                    else
                    {
                        step_hash(106);
                        (*l_244) |= (*l_219);
                        step_hash(107);
                        (*l_219) = ((unsigned short)((unsigned)2UL + (unsigned)0x29A21605L) >> (unsigned short)10);
                        step_hash(108);
                        (*p_126) &= l_249;
                    }
                }
                step_hash(111);
                (*p_126) = ((1L < (((signed char)((**g_241) > (g_181[0] || (0x49L != 251UL))) % (signed char)8L) && (((&g_241 == (void*)0) && ((void*)0 == &p_126)) & p_125))) == p_125);
            }
            step_hash(113);
            l_252 = p_126;
        }
    }
    step_hash(116);
    (*g_241) = l_253[0][3];
    step_hash(117);
    return (*g_241);
}







static int func_127(int p_128, unsigned p_129, int * p_130, int * p_131, int * p_132)
{
    int l_142 = 0x4B622C33L;
    int l_151[1][1];
    int i, j;
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 1; j++)
            l_151[i][j] = (-6L);
    }
    step_hash(32);
    (*p_132) = (l_142 >= g_143);
    step_hash(38);
    for (l_142 = 0; (l_142 < (-19)); l_142 -= 2)
    {
        unsigned l_148 = 0x50633388L;
        int **l_150 = &g_149;
        step_hash(36);
        (*p_131) &= ((signed char)7L * (signed char)l_148);
        step_hash(37);
        (*l_150) = g_149;
    }
    step_hash(43);
    for (g_143 = 0; (g_143 <= 0); g_143 += 1)
    {
        step_hash(42);
        return (*p_132);
    }
    step_hash(44);
    return (*g_149);
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_47, "g_47", print_hash_value);
    transparent_crc(g_60, "g_60", print_hash_value);
    transparent_crc(g_118, "g_118", print_hash_value);
    transparent_crc(g_143, "g_143", print_hash_value);
    transparent_crc(g_160, "g_160", print_hash_value);
    transparent_crc(g_163, "g_163", print_hash_value);
    transparent_crc(g_168, "g_168", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_169[i], "g_169[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_170, "g_170", print_hash_value);
    transparent_crc(g_171, "g_171", print_hash_value);
    transparent_crc(g_180, "g_180", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_181[i], "g_181[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_182, "g_182", print_hash_value);
    transparent_crc(g_183, "g_183", print_hash_value);
    transparent_crc(g_184, "g_184", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_206[i][j], "g_206[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_264[i][j], "g_264[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_277, "g_277", print_hash_value);
    transparent_crc(g_481, "g_481", print_hash_value);
    transparent_crc(g_483, "g_483", print_hash_value);
    transparent_crc(g_568, "g_568", print_hash_value);
    transparent_crc(g_594, "g_594", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_609[i][j], "g_609[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_622, "g_622", print_hash_value);
    transparent_crc(g_789, "g_789", print_hash_value);
    transparent_crc(g_877, "g_877", print_hash_value);
    transparent_crc(g_908, "g_908", print_hash_value);
    transparent_crc(g_1187, "g_1187", print_hash_value);
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_1219[i], "g_1219[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1510, "g_1510", print_hash_value);
    transparent_crc(g_1514, "g_1514", print_hash_value);
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
