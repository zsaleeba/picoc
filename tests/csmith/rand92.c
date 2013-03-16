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
static int g_2 = 0x68EC0AE9L;
static int g_6 = 7L;
static int g_8 = 2L;
static unsigned char g_11 = 0x41L;
static int g_42 = (-1L);
static signed char g_45 = 0x7EL;
static short g_46 = 0L;
static unsigned short g_58 = 65535UL;
static int *g_82 = &g_6;
static int **g_81 = &g_82;
static unsigned short g_103 = 3UL;
static signed char g_149 = 0x45L;
static int g_210 = 0L;
static int g_303 = 0xE5B87094L;
static unsigned char g_305 = 0UL;
static signed char g_331[9][1] = {{(-3L)}, {(-3L)}, {(-3L)}, {(-3L)}, {(-3L)}, {(-3L)}, {(-3L)}, {(-3L)}, {(-3L)}};
static unsigned g_332 = 0xC584E066L;
static unsigned short g_340[9] = {0UL, 0x1407L, 0UL, 0x1407L, 0UL, 0x1407L, 0UL, 0x1407L, 0UL};
static unsigned short g_396 = 0x1A5CL;
static unsigned char g_412 = 0x38L;
static unsigned g_441 = 0x01594FE4L;
static unsigned char g_467[8] = {0xC1L, 0x71L, 0xC1L, 0x71L, 0xC1L, 0x71L, 0xC1L, 0x71L};
static unsigned g_474 = 0x2063382BL;
static int g_481 = 0x76F57C1EL;
static int g_482 = 0x669907E1L;
static short g_483 = 8L;
static unsigned g_484[10] = {0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL, 0UL};
static unsigned short g_518 = 0UL;
static signed char g_523 = 1L;
static unsigned g_545 = 0xD5BFFF3AL;
static int g_556[8] = {1L, 0x8AC4478BL, 1L, 0x8AC4478BL, 1L, 0x8AC4478BL, 1L, 0x8AC4478BL};
static int g_557 = 0x21D1FC7FL;
static unsigned short g_558 = 4UL;
static int **g_612 = &g_82;
static int g_620 = 0L;
static int g_621 = 0xA7EF65A4L;
static int *g_632[7] = {&g_6, &g_6, &g_210, &g_6, &g_6, &g_210, &g_6};
static int **g_755 = (void*)0;
static int *g_1172[3][1] = {{(void*)0}, {(void*)0}, {(void*)0}};
static unsigned short g_1201[1] = {65535UL};
static short func_1(void);
static int ** func_16(int ** p_17, signed char p_18, int * p_19, int * p_20, int ** p_21);
static int ** func_22(int * p_23, int ** p_24, int * p_25, int p_26, unsigned char p_27);
static int * func_28(int * p_29);
static int * func_30(int * p_31, short p_32, int ** p_33, int p_34, short p_35);
static int * func_36(int ** p_37, int ** p_38);
static unsigned char func_87(unsigned p_88);
static signed char func_110(unsigned p_111, int ** p_112, int * p_113, int * p_114, int ** p_115);
static unsigned func_116(unsigned short p_117, unsigned char p_118, short p_119, unsigned short p_120);
static short func_123(short p_124);
static short func_1(void)
{
    int *l_1042[2][7] = {{&g_210, &g_42, &g_210, &g_42, &g_210, &g_42, &g_210}, {&g_210, &g_42, &g_210, &g_42, &g_210, &g_42, &g_210}};
    int **l_1198 = &g_632[4];
    signed char l_1211 = 0xE0L;
    int i, j;
    step_hash(885);
    for (g_2 = 0; (g_2 < (-9)); g_2 -= 8)
    {
        signed char l_5[9];
        int **l_39[5];
        unsigned l_1199 = 4294967291UL;
        unsigned char l_1200 = 0xF1L;
        int l_1218[5] = {(-4L), 0xA44FD442L, (-4L), 0xA44FD442L, (-4L)};
        int i;
        for (i = 0; i < 9; i++)
            l_5[i] = 0x38L;
        for (i = 0; i < 5; i++)
            l_39[i] = (void*)0;
        step_hash(883);
        for (g_6 = 3; (g_6 <= 8); g_6 += 1)
        {
            int *l_7 = &g_8;
            int *l_9 = (void*)0;
            int *l_10[3];
            int ***l_1210 = &l_1198;
            int i;
            for (i = 0; i < 3; i++)
                l_10[i] = &g_8;
            step_hash(7);
            ++g_11;
        }
        step_hash(884);
        l_1218[1] |= ((g_340[7] >= 0L) >= (((((0x26C593DBL | g_441) ^ (**l_1198)) & (g_1201[0] ^ (**l_1198))) <= ((unsigned short)((((((int)(**g_81) - (int)func_116(func_116(g_484[5], g_149, g_518, g_481), g_305, g_484[4], g_46)) < (**l_1198)) && g_396) != 1L) | 0UL) + (unsigned short)(-7L))) & g_481));
    }
    step_hash(900);
    for (g_58 = 0; (g_58 >= 17); g_58 += 6)
    {
        unsigned char l_1223 = 0x31L;
        int **l_1228 = &l_1042[1][1];
        step_hash(893);
        for (g_42 = 0; (g_42 <= 6); g_42 += 1)
        {
            step_hash(892);
            return g_11;
        }
        step_hash(898);
        for (g_6 = 0; (g_6 <= (-2)); g_6--)
        {
            unsigned short l_1226 = 0x1A70L;
            int **l_1227 = &l_1042[0][5];
            int ***l_1229[4] = {&l_1227, &g_612, &l_1227, &g_612};
            int i;
            step_hash(897);
            g_755 = &g_1172[2][0];
        }
        step_hash(899);
        (*l_1228) = func_28(func_28((*l_1198)));
    }
    step_hash(901);
    return g_483;
}
static int ** func_16(int ** p_17, signed char p_18, int * p_19, int * p_20, int ** p_21)
{
    unsigned short l_1114[1][10];
    int **l_1136[10] = {&g_632[3], &g_632[3], &g_632[3], &g_632[3], &g_632[3], &g_632[3], &g_632[3], &g_632[3], &g_632[3], &g_632[3]};
    unsigned char l_1146 = 0UL;
    int **l_1151[1];
    unsigned short l_1174 = 65531UL;
    int **l_1193 = &g_82;
    int i, j;
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 10; j++)
            l_1114[i][j] = 0x87B6L;
    }
    for (i = 0; i < 1; i++)
        l_1151[i] = &g_632[3];
    step_hash(851);
    for (g_210 = 0; (g_210 >= 0); g_210 -= 1)
    {
        unsigned l_1112 = 0UL;
        signed char l_1113 = 0xA8L;
        unsigned char l_1135 = 0UL;
        int l_1147[6][7] = {{0x312BDF80L, 0x312BDF80L, 6L, 2L, 0x4D3BE362L, 1L, (-8L)}, {0x312BDF80L, 0x312BDF80L, 6L, 2L, 0x4D3BE362L, 1L, (-8L)}, {0x312BDF80L, 0x312BDF80L, 6L, 2L, 0x4D3BE362L, 1L, (-8L)}, {0x312BDF80L, 0x312BDF80L, 6L, 2L, 0x4D3BE362L, 1L, (-8L)}, {0x312BDF80L, 0x312BDF80L, 6L, 2L, 0x4D3BE362L, 1L, (-8L)}, {0x312BDF80L, 0x312BDF80L, 6L, 2L, 0x4D3BE362L, 1L, (-8L)}};
        int **l_1165 = (void*)0;
        int i, j;
        step_hash(773);
        for (g_523 = 0; (g_523 <= 8); g_523 += 1)
        {
            int i, j;
            step_hash(771);
            l_1112 = g_331[g_523][g_210];
            step_hash(772);
            l_1113 = g_331[g_523][g_210];
        }
        step_hash(774);
        if (l_1114[0][9])
            continue;
        step_hash(817);
        if (((signed char)((signed char)((unsigned char)((0x820E0D26L <= (((signed char)p_18 + (signed char)(((unsigned)p_18 / (unsigned)(((unsigned char)p_18 * (unsigned char)((p_18 > (p_18 > p_18)) ^ g_467[5])) ^ l_1113)) | l_1113)) || 0UL)) != g_6) / (unsigned char)l_1114[0][6]) << (signed char)l_1114[0][2]) + (signed char)l_1112))
        {
            int *l_1127 = &g_210;
            unsigned short l_1140 = 0xC40AL;
            step_hash(802);
            if ((l_1127 == p_20))
            {
                int **l_1132 = &g_632[3];
                int *l_1137 = &g_482;
                step_hash(785);
                for (g_620 = 0; (g_620 <= 0); g_620 += 1)
                {
                    step_hash(784);
                    if (((unsigned short)((unsigned)g_483 + (unsigned)1UL) * (unsigned short)p_18))
                    {
                        step_hash(781);
                        return l_1132;
                    }
                    else
                    {
                        int *l_1133 = &g_481;
                        step_hash(783);
                        (*l_1133) = l_1114[0][6];
                    }
                }
                step_hash(786);
                (*p_21) = l_1127;
                step_hash(799);
                for (g_332 = 0; (g_332 <= 0); g_332 += 1)
                {
                    int *l_1138 = (void*)0;
                    step_hash(795);
                    for (g_46 = 0; (g_46 <= 8); g_46 += 1)
                    {
                        int l_1134 = 4L;
                        step_hash(793);
                        l_1135 ^= l_1134;
                        step_hash(794);
                        (*l_1132) = l_1137;
                    }
                    step_hash(796);
                    if ((**p_21))
                        break;
                }
            }
            else
            {
                int l_1139 = 3L;
                step_hash(801);
                l_1139 |= l_1112;
            }
            step_hash(803);
            if (l_1112)
                continue;
            step_hash(804);
            l_1140--;
            step_hash(813);
            for (g_545 = 2; (g_545 <= 8); g_545 += 1)
            {
                step_hash(812);
                for (g_149 = 0; (g_149 >= 0); g_149 -= 1)
                {
                    unsigned char l_1143 = 0xAEL;
                    step_hash(811);
                    l_1143--;
                }
            }
        }
        else
        {
            int **l_1150 = &g_632[5];
            step_hash(815);
            l_1147[3][3] |= l_1146;
            step_hash(816);
            (*g_612) = &l_1147[5][4];
        }
        step_hash(818);
        l_1147[3][3] ^= (*p_19);
        step_hash(850);
        for (g_620 = 0; (g_620 <= 8); g_620 += 1)
        {
            unsigned short l_1166 = 65526UL;
            int l_1173 = 0L;
            unsigned short l_1187 = 1UL;
            step_hash(849);
            if ((l_1166 == l_1166))
            {
                int *l_1171[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_1171[i] = &g_621;
                step_hash(836);
                if ((!(((int)((short)8L * (short)((l_1171[2] != g_1172[2][0]) ^ p_18)) - (int)p_18) & g_11)))
                {
                    step_hash(829);
                    for (g_481 = 0; (g_481 >= 0); g_481 -= 1)
                    {
                        int i;
                        step_hash(827);
                        l_1173 = (~(&l_1151[g_210] == &p_21));
                        step_hash(828);
                        l_1174 |= ((void*)0 != &p_21);
                    }
                }
                else
                {
                    unsigned l_1176 = 1UL;
                    step_hash(835);
                    for (l_1173 = 0; (l_1173 <= 8); l_1173 += 1)
                    {
                        int l_1175 = 0x23AB39E0L;
                        step_hash(834);
                        l_1176++;
                    }
                }
            }
            else
            {
                signed char l_1188 = 0x22L;
                step_hash(838);
                (*p_17) = &l_1173;
                step_hash(843);
                for (g_45 = 0; (g_45 <= 8); g_45 += 1)
                {
                    unsigned char l_1189 = 246UL;
                    step_hash(842);
                    l_1189 = (((unsigned short)l_1173 << (unsigned short)(l_1173 || ((unsigned char)(0xCC172E96L >= (+((p_18 < ((((g_523 && (((unsigned)g_11 / (unsigned)(((0xB253L <= ((+(p_18 == l_1187)) >= l_1166)) <= g_332) ^ l_1188)) || p_18)) >= p_18) ^ 0xC140BEB8L) & 0x9CL)) >= g_523))) / (unsigned char)p_18))) == g_481);
                }
                step_hash(848);
                for (g_481 = 0; (g_481 <= 0); g_481 += 1)
                {
                    step_hash(847);
                    if (l_1188)
                        break;
                }
            }
        }
    }
    step_hash(858);
    for (g_481 = 5; (g_481 < (-7)); --g_481)
    {
        int *l_1192 = &g_210;
        step_hash(855);
        (*g_612) = p_19;
        step_hash(856);
        (*p_17) = l_1192;
        step_hash(857);
        if ((*p_20))
            continue;
    }
    step_hash(859);
    return l_1193;
}
static int ** func_22(int * p_23, int ** p_24, int * p_25, int p_26, unsigned char p_27)
{
    int *l_1047 = &g_482;
    unsigned short l_1052 = 0x4D61L;
    unsigned char l_1054 = 255UL;
    int l_1073 = 0L;
    int ***l_1082 = &g_81;
    int l_1101 = (-3L);
    int l_1103 = 1L;
    int l_1104 = (-1L);
    step_hash(760);
    if (((unsigned short)(g_481 != ((g_620 & (((((unsigned)(l_1047 == l_1047) % (unsigned)((signed char)(((short)(g_396 && p_27) << (short)2) && (-10L)) + (signed char)(*l_1047))) != p_26) ^ (*l_1047)) & l_1052)) && p_26)) * (unsigned short)p_27))
    {
        step_hash(716);
        return &g_632[0];
    }
    else
    {
        int *l_1053[2];
        int i;
        for (i = 0; i < 2; i++)
            l_1053[i] = &g_210;
        step_hash(718);
        ++l_1054;
        step_hash(759);
        if ((*l_1047))
        {
            int ***l_1061 = &g_755;
            int l_1064 = 0x2414C1E4L;
            step_hash(730);
            for (g_42 = 0; (g_42 > (-29)); g_42 -= 5)
            {
                step_hash(728);
                for (g_557 = 0; (g_557 != 12); g_557 += 6)
                {
                    step_hash(726);
                    l_1053[1] = func_36(&l_1053[1], &l_1047);
                    step_hash(727);
                    return &g_632[3];
                }
                step_hash(729);
                return &g_82;
            }
            step_hash(731);
            (*l_1061) = &p_25;
            step_hash(732);
            l_1064 ^= ((~((signed char)(~(-1L)) * (signed char)(&p_25 == &g_82))) && (*p_25));
        }
        else
        {
            unsigned l_1072 = 0xA0344524L;
            int l_1100[2];
            int *l_1110 = &g_6;
            int i;
            for (i = 0; i < 2; i++)
                l_1100[i] = 1L;
            step_hash(740);
            for (g_621 = 5; (g_621 >= 3); g_621 -= 1)
            {
                int *l_1065 = &g_303;
                int i;
                step_hash(737);
                (*p_24) = l_1065;
                step_hash(738);
                (*p_25) = (((unsigned short)g_340[(g_621 + 2)] / (unsigned short)65532UL) ^ (**p_24));
                step_hash(739);
                p_26 |= ((signed char)g_558 - (signed char)func_110((*l_1065), &g_632[3], (*p_24), (*g_612), &g_632[4]));
            }
            step_hash(741);
            l_1073 &= (g_46 < ((int)l_1072 / (int)(*p_25)));
            step_hash(757);
            for (g_474 = 2; (g_474 < 54); ++g_474)
            {
                unsigned l_1078 = 5UL;
                int l_1105 = (-3L);
                unsigned l_1107[9][4];
                int i, j;
                for (i = 0; i < 9; i++)
                {
                    for (j = 0; j < 4; j++)
                        l_1107[i][j] = 1UL;
                }
                step_hash(745);
                (*g_612) = &l_1073;
                step_hash(756);
                if ((((signed char)((l_1078 ^ (p_27 != ((-(unsigned short)((short)0xB2B5L * (short)l_1072)) & (&g_755 == &p_24)))) >= p_26) + (signed char)(l_1082 == &p_24)) & 4294967294UL))
                {
                    short l_1099 = 0x8583L;
                    int l_1106 = 0x2C6592A9L;
                    step_hash(747);
                    (*p_24) = func_30((**l_1082), ((signed char)((unsigned short)p_26 >> (unsigned short)9) << (signed char)g_523), &g_632[4], (*p_25), ((unsigned short)(((signed char)((void*)0 != &p_24) * (signed char)9L) > ((unsigned char)((unsigned char)l_1072 + (unsigned char)p_26) << (unsigned char)4)) >> (unsigned short)4));
                    step_hash(753);
                    for (g_545 = 0; (g_545 <= 7); g_545 += 1)
                    {
                        int l_1095 = (-2L);
                        int l_1096 = (-1L);
                        int l_1097 = 0x552B2F47L;
                        int l_1098 = (-1L);
                        int l_1102[4];
                        int i;
                        for (i = 0; i < 4; i++)
                            l_1102[i] = 1L;
                        step_hash(751);
                        if (g_556[g_545])
                            break;
                        step_hash(752);
                        ++l_1107[6][3];
                    }
                }
                else
                {
                    step_hash(755);
                    return &g_632[5];
                }
            }
            step_hash(758);
            (**l_1082) = func_28(l_1110);
        }
    }
    step_hash(761);
    (*p_25) ^= (-1L);
    step_hash(762);
    (*g_81) = func_36((*l_1082), (*l_1082));
    step_hash(763);
    return &g_632[1];
}
static int * func_28(int * p_29)
{
    unsigned short l_1036 = 65533UL;
    int l_1037 = 0xF7868DE4L;
    int *l_1038[3][3];
    unsigned l_1039 = 0x4BBC5A7EL;
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            l_1038[i][j] = &g_210;
    }
    step_hash(709);
    (*g_612) = p_29;
    step_hash(710);
    l_1036 &= (*g_82);
    step_hash(711);
    (*g_81) = (*g_612);
    step_hash(712);
    --l_1039;
    step_hash(713);
    return p_29;
}







static int * func_30(int * p_31, short p_32, int ** p_33, int p_34, short p_35)
{
    unsigned l_762 = 0x3243E815L;
    int l_766 = 0xCB78B72FL;
    unsigned l_780 = 7UL;
    int l_804[10] = {0x89AAFC3BL, 0xC8EDC4B5L, 0x89AAFC3BL, 0xC8EDC4B5L, 0x89AAFC3BL, 0xC8EDC4B5L, 0x89AAFC3BL, 0xC8EDC4B5L, 0x89AAFC3BL, 0xC8EDC4B5L};
    unsigned l_809 = 0UL;
    int l_845[4];
    unsigned short l_873 = 0x4D9FL;
    unsigned char l_953[9][9] = {{0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}, {0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}, {0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}, {0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}, {0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}, {0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}, {0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}, {0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}, {0x5CL, 9UL, 251UL, 251UL, 9UL, 0x5CL, 1UL, 0x4AL, 255UL}};
    int i, j;
    for (i = 0; i < 4; i++)
        l_845[i] = 0x243A6AB7L;
    step_hash(700);
    for (g_412 = 0; (g_412 <= 7); g_412 += 1)
    {
        unsigned l_777 = 0xCAE93D8BL;
        int l_794 = 1L;
        int l_799 = 1L;
        int l_800[8][3] = {{(-1L), 9L, (-1L)}, {(-1L), 9L, (-1L)}, {(-1L), 9L, (-1L)}, {(-1L), 9L, (-1L)}, {(-1L), 9L, (-1L)}, {(-1L), 9L, (-1L)}, {(-1L), 9L, (-1L)}, {(-1L), 9L, (-1L)}};
        int l_815 = 0x96C6C66BL;
        int **l_821 = (void*)0;
        unsigned l_831 = 0x153F9D67L;
        int l_872[5][4] = {{0xCD0EA6B3L, (-2L), 8L, 8L}, {0xCD0EA6B3L, (-2L), 8L, 8L}, {0xCD0EA6B3L, (-2L), 8L, 8L}, {0xCD0EA6B3L, (-2L), 8L, 8L}, {0xCD0EA6B3L, (-2L), 8L, 8L}};
        int *l_952 = &g_557;
        unsigned short l_1021 = 0UL;
        int i, j;
        step_hash(534);
        if (l_762)
            break;
        step_hash(562);
        for (g_11 = 2; (g_11 <= 6); g_11 += 1)
        {
            int *l_779 = &g_621;
            int l_796 = 0L;
            int l_797 = 0x44223930L;
            int l_801 = 0xCFA3204CL;
            int l_806[2];
            int i;
            for (i = 0; i < 2; i++)
                l_806[i] = 0x535A12B9L;
            step_hash(542);
            for (g_46 = 6; (g_46 >= 0); g_46 -= 1)
            {
                int i;
                step_hash(541);
                if ((**g_612))
                    break;
            }
            step_hash(561);
            for (g_620 = 0; (g_620 <= 7); g_620 += 1)
            {
                int *l_765[1];
                signed char l_808 = (-1L);
                int i;
                for (i = 0; i < 1; i++)
                    l_765[i] = &g_210;
                step_hash(546);
                l_766 &= (((void*)0 == (*g_81)) & ((unsigned short)g_620 >> (unsigned short)p_34));
                step_hash(560);
                for (p_35 = 0; (p_35 <= 7); p_35 += 1)
                {
                    int **l_778 = (void*)0;
                    unsigned short l_793 = 65535UL;
                    int l_795[4][1] = {{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}};
                    int i, j;
                    step_hash(550);
                    (*l_779) &= l_780;
                    step_hash(551);
                    (*l_779) |= ((unsigned char)((signed char)g_331[5][0] << (signed char)5) << (unsigned char)((signed char)((signed char)p_35 + (signed char)((unsigned short)0xEC01L * (unsigned short)(!p_34))) - (signed char)(p_34 > ((unsigned short)g_396 + (unsigned short)p_35))));
                    step_hash(552);
                    g_632[g_11] = (*g_81);
                    step_hash(559);
                    if ((p_32 == l_793))
                    {
                        short l_798 = 0x3E61L;
                        int l_802 = 0x1BC74F75L;
                        int l_803 = (-1L);
                        int l_805 = 0xF2F451F0L;
                        int l_807[8][3] = {{(-1L), (-1L), 1L}, {(-1L), (-1L), 1L}, {(-1L), (-1L), 1L}, {(-1L), (-1L), 1L}, {(-1L), (-1L), 1L}, {(-1L), (-1L), 1L}, {(-1L), (-1L), 1L}, {(-1L), (-1L), 1L}};
                        int i, j;
                        step_hash(554);
                        ++l_809;
                        step_hash(555);
                        (*g_612) = (*g_612);
                        step_hash(556);
                        l_815 &= ((((-(unsigned)0xE5E1E1FBL) < 255UL) != ((-1L) || ((unsigned)(1L | (*l_779)) - (unsigned)5UL))) || 0x373DL);
                    }
                    else
                    {
                        int *l_816[4];
                        int i;
                        for (i = 0; i < 4; i++)
                            l_816[i] = &g_557;
                        step_hash(558);
                        return l_816[3];
                    }
                }
            }
        }
    }
    step_hash(706);
    for (p_32 = 23; (p_32 >= 15); p_32 -= 2)
    {
        signed char l_1026 = 1L;
        int l_1027 = 1L;
        int *l_1028 = &l_804[5];
        int *l_1029 = &g_557;
        int *l_1030 = &l_1027;
        int *l_1031[5];
        signed char l_1032 = (-1L);
        unsigned char l_1033 = 0UL;
        int i;
        for (i = 0; i < 5; i++)
            l_1031[i] = &l_804[1];
        step_hash(704);
        l_1027 = l_1026;
        step_hash(705);
        --l_1033;
    }
    step_hash(707);
    return (*g_81);
}







static int * func_36(int ** p_37, int ** p_38)
{
    unsigned short l_40[10][7] = {{65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}, {65535UL, 0x3E5EL, 0xF8B2L, 1UL, 1UL, 0xF8B2L, 0x3E5EL}};
    int l_47[7];
    int l_56[5];
    int l_57 = 0L;
    int *l_754[1][10];
    int i, j;
    for (i = 0; i < 7; i++)
        l_47[i] = (-1L);
    for (i = 0; i < 5; i++)
        l_56[i] = 0x8BA832A4L;
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 10; j++)
            l_754[i][j] = &g_42;
    }
    step_hash(528);
    for (g_11 = 0; (g_11 <= 6); g_11 += 1)
    {
        unsigned short l_48 = 65530UL;
        int *l_51 = &g_42;
        int *l_52 = &g_8;
        int *l_53 = (void*)0;
        int *l_54 = (void*)0;
        int *l_55[3][2];
        int **l_61[10][8] = {{&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}, {&l_54, &l_55[0][1], (void*)0, &l_55[0][1], &l_51, &l_53, &l_54, &l_55[0][1]}};
        int *l_62[10][5];
        unsigned l_751[10][2] = {{0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}, {0x0B60085EL, 0xD350C211L}};
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
                l_55[i][j] = &l_47[5];
        }
        for (i = 0; i < 10; i++)
        {
            for (j = 0; j < 5; j++)
                l_62[i][j] = &l_47[1];
        }
        step_hash(17);
        for (g_8 = 0; (g_8 <= 6); g_8 += 1)
        {
            int *l_41 = &g_42;
            int *l_43 = (void*)0;
            int *l_44[10][2] = {{(void*)0, &g_6}, {(void*)0, &g_6}, {(void*)0, &g_6}, {(void*)0, &g_6}, {(void*)0, &g_6}, {(void*)0, &g_6}, {(void*)0, &g_6}, {(void*)0, &g_6}, {(void*)0, &g_6}, {(void*)0, &g_6}};
            int i, j;
            step_hash(16);
            l_48--;
        }
        step_hash(18);
        g_58--;
        step_hash(19);
        l_62[0][1] = &g_2;
        step_hash(513);
        (*l_52) = (g_58 ^ ((short)((signed char)((unsigned char)((short)(~((unsigned short)((unsigned short)((g_11 != (&l_57 == (void*)0)) < ((((unsigned char)(((unsigned short)(p_38 == g_81) * (unsigned short)(-1L)) != ((unsigned short)((unsigned char)func_87(g_11) << (unsigned char)g_11) % (unsigned short)(-1L))) >> (unsigned char)3) < l_47[5]) != 0xB542L)) % (unsigned short)l_57) / (unsigned short)l_56[1])) * (short)l_751[9][0]) * (unsigned char)251UL) << (signed char)g_467[5]) << (short)g_620));
        step_hash(527);
        for (g_103 = 1; (g_103 <= 6); g_103 += 1)
        {
            step_hash(526);
            for (g_558 = 2; (g_558 <= 8); g_558 += 1)
            {
                unsigned l_752 = 1UL;
                step_hash(525);
                for (g_481 = 1; (g_481 <= 6); g_481 += 1)
                {
                    int *l_753 = (void*)0;
                    int i;
                    step_hash(523);
                    l_752 = g_340[(g_481 + 1)];
                    step_hash(524);
                    return l_753;
                }
            }
        }
    }
    step_hash(529);
    return l_754[0][2];
}







static unsigned char func_87(unsigned p_88)
{
    unsigned l_89[9] = {4294967295UL, 4294967294UL, 4294967295UL, 4294967294UL, 4294967295UL, 4294967294UL, 4294967295UL, 4294967294UL, 4294967295UL};
    int l_100 = 0x03BE979EL;
    int l_102 = (-8L);
    int **l_667 = &g_632[3];
    int l_670 = 7L;
    int l_716[9];
    int l_741 = 0x29F899CCL;
    int l_742 = 0L;
    int l_743 = 0x77AAE354L;
    int l_744[1];
    int i;
    for (i = 0; i < 9; i++)
        l_716[i] = (-2L);
    for (i = 0; i < 1; i++)
        l_744[i] = 0L;
    step_hash(482);
    for (g_45 = 8; (g_45 >= 3); g_45 -= 1)
    {
        int l_99 = 0xA8980DF3L;
        int *l_562[7];
        int **l_561[8][4] = {{&l_562[6], &l_562[4], &l_562[4], &l_562[4]}, {&l_562[6], &l_562[4], &l_562[4], &l_562[4]}, {&l_562[6], &l_562[4], &l_562[4], &l_562[4]}, {&l_562[6], &l_562[4], &l_562[4], &l_562[4]}, {&l_562[6], &l_562[4], &l_562[4], &l_562[4]}, {&l_562[6], &l_562[4], &l_562[4], &l_562[4]}, {&l_562[6], &l_562[4], &l_562[4], &l_562[4]}, {&l_562[6], &l_562[4], &l_562[4], &l_562[4]}};
        unsigned char l_685 = 1UL;
        signed char l_697 = 1L;
        int *l_699 = &g_210;
        int i, j;
        for (i = 0; i < 7; i++)
            l_562[i] = (void*)0;
    }
    step_hash(483);
    (*g_612) = (*g_612);
    step_hash(511);
    for (g_149 = 0; (g_149 <= 7); g_149 += 1)
    {
        int **l_724 = &g_632[4];
        short l_738 = 0xD4A6L;
        int *l_739 = &g_481;
        int *l_740[5][6] = {{&g_303, (void*)0, &g_303, (void*)0, &g_303, (void*)0}, {&g_303, (void*)0, &g_303, (void*)0, &g_303, (void*)0}, {&g_303, (void*)0, &g_303, (void*)0, &g_303, (void*)0}, {&g_303, (void*)0, &g_303, (void*)0, &g_303, (void*)0}, {&g_303, (void*)0, &g_303, (void*)0, &g_303, (void*)0}};
        short l_745 = 0x4ED9L;
        int l_746 = 1L;
        signed char l_747 = (-6L);
        unsigned l_748[9][2] = {{0xD4E66103L, 0xACBE97B3L}, {0xD4E66103L, 0xACBE97B3L}, {0xD4E66103L, 0xACBE97B3L}, {0xD4E66103L, 0xACBE97B3L}, {0xD4E66103L, 0xACBE97B3L}, {0xD4E66103L, 0xACBE97B3L}, {0xD4E66103L, 0xACBE97B3L}, {0xD4E66103L, 0xACBE97B3L}, {0xD4E66103L, 0xACBE97B3L}};
        int i, j;
        step_hash(509);
        if (g_467[g_149])
        {
            unsigned char l_726 = 1UL;
            step_hash(495);
            for (g_303 = 0; (g_303 > 2); ++g_303)
            {
                unsigned char l_723 = 2UL;
                int ***l_725[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_725[i] = (void*)0;
                step_hash(491);
                if (p_88)
                    break;
                step_hash(492);
                if (l_723)
                    continue;
                step_hash(493);
                l_724 = l_724;
                step_hash(494);
                l_726 = (**l_667);
            }
            step_hash(496);
            (*g_81) = (*l_667);
        }
        else
        {
            unsigned short l_730[10] = {0x19AFL, 0x19AFL, 0x49F5L, 0x19AFL, 0x19AFL, 0x49F5L, 0x19AFL, 0x19AFL, 0x49F5L, 0x19AFL};
            int **l_733 = &g_632[6];
            int i;
            step_hash(508);
            if ((**l_724))
            {
                step_hash(503);
                for (g_103 = 26; (g_103 == 26); ++g_103)
                {
                    int *l_729 = &l_100;
                    step_hash(502);
                    (*l_729) = p_88;
                }
            }
            else
            {
                int l_734 = 0xBD011F0EL;
                int *l_737[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_737[i] = &l_670;
                step_hash(505);
                l_730[1]++;
                step_hash(506);
                l_738 = (((&g_632[0] != l_733) < l_734) & ((short)0L << (short)12));
                step_hash(507);
                (*l_733) = (*l_667);
            }
        }
        step_hash(510);
        l_748[7][0]++;
    }
    step_hash(512);
    return p_88;
}







static signed char func_110(unsigned p_111, int ** p_112, int * p_113, int * p_114, int ** p_115)
{
    int ***l_569 = &g_81;
    int l_583 = 1L;
    unsigned l_584[5];
    int **l_616 = &g_82;
    int i;
    for (i = 0; i < 5; i++)
        l_584[i] = 6UL;
    step_hash(423);
    for (g_545 = 0; (g_545 <= 7); g_545 += 1)
    {
        int l_578[7] = {0x739154E5L, (-1L), 0x739154E5L, (-1L), 0x739154E5L, (-1L), 0x739154E5L};
        unsigned short l_579 = 0xFC0DL;
        int **l_599 = &g_82;
        int i;
        step_hash(413);
        for (g_557 = 8; (g_557 >= 0); g_557 -= 1)
        {
            int l_617 = (-9L);
            int i;
            step_hash(411);
            if ((((unsigned char)((short)(((unsigned short)(l_569 != (void*)0) * (unsigned short)((short)(((short)g_340[g_557] << (short)g_556[g_545]) >= (0x04L < ((unsigned char)(p_111 == (((unsigned short)g_303 - (unsigned short)func_116((((((g_305 ^ ((func_116(g_149, p_111, g_441, p_111) == g_58) ^ l_578[2])) > g_523) && 0x7DB9L) & 0x77L) > g_556[0]), g_340[g_557], l_579, p_111)) != g_556[0])) / (unsigned char)(-10L)))) * (short)65527UL)) >= p_111) - (short)0xF37BL) / (unsigned char)g_481) < l_578[2]))
            {
                int *l_580 = &g_482;
                int *l_581 = &g_482;
                int *l_582[10][7] = {{&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}, {&l_578[0], (void*)0, &g_8, (void*)0, &l_578[0], &l_578[3], &g_8}};
                int ***l_602 = &g_81;
                short l_609 = 0x9BE4L;
                unsigned l_627 = 0x516C6685L;
                int i, j;
                step_hash(385);
                --l_584[2];
                step_hash(406);
                if ((p_111 & ((unsigned char)(((unsigned char)p_111 - (unsigned char)(5UL != (((unsigned char)p_111 << (unsigned char)((unsigned short)((short)g_103 - (short)((unsigned char)((l_599 == (void*)0) & (((unsigned)((void*)0 == l_602) - (unsigned)g_396) ^ g_6)) - (unsigned char)p_111)) * (unsigned short)g_556[g_545])) ^ p_111))) || 3UL) * (unsigned char)g_441)))
                {
                    unsigned short l_610 = 65534UL;
                    step_hash(394);
                    if ((+g_556[g_545]))
                    {
                        unsigned l_603 = 1UL;
                        int ***l_611[4][4] = {{&g_81, (void*)0, &l_599, (void*)0}, {&g_81, (void*)0, &l_599, (void*)0}, {&g_81, (void*)0, &l_599, (void*)0}, {&g_81, (void*)0, &l_599, (void*)0}};
                        int i, j;
                        step_hash(388);
                        (*p_114) = l_603;
                        step_hash(389);
                        l_610 ^= (((short)(p_111 || g_331[5][0]) % (short)(-(unsigned short)func_116(l_578[5], p_111, p_111, ((((short)(g_441 | (l_603 | (*p_114))) * (short)(p_111 || 3L)) >= (*l_581)) && l_609)))) >= 3UL);
                        step_hash(390);
                        g_612 = &g_82;
                    }
                    else
                    {
                        step_hash(392);
                        (**l_569) = &g_8;
                        step_hash(393);
                        (**g_612) = l_610;
                    }
                }
                else
                {
                    unsigned l_615 = 4294967295UL;
                    int l_618 = 0x38508EE6L;
                    int l_619 = 0L;
                    step_hash(405);
                    if (func_116(((func_116(((int)0L - (int)(((+p_111) && ((void*)0 != &p_113)) >= l_615)), (&p_113 == (void*)0), (g_340[g_557] <= ((*l_602) == l_616)), p_111) && p_111) | g_45), p_111, p_111, g_481))
                    {
                        unsigned char l_622 = 0xD4L;
                        int **l_625 = &l_580;
                        step_hash(397);
                        l_622--;
                        step_hash(398);
                        if (g_556[g_545])
                            break;
                        step_hash(399);
                        l_619 = (g_396 & func_116(g_396, p_111, func_116(l_622, p_111, g_305, p_111), ((((&g_82 == l_625) || p_111) ^ g_2) | g_11)));
                        step_hash(400);
                        (*g_612) = &l_617;
                    }
                    else
                    {
                        int l_626[5][2];
                        int i, j;
                        for (i = 0; i < 5; i++)
                        {
                            for (j = 0; j < 2; j++)
                                l_626[i][j] = 0x839E23DCL;
                        }
                        step_hash(402);
                        if (l_615)
                            break;
                        step_hash(403);
                        l_627++;
                        step_hash(404);
                        return g_518;
                    }
                }
            }
            else
            {
                step_hash(408);
                (*p_113) &= g_305;
                step_hash(409);
                (*p_113) = 0xDE0A621BL;
                step_hash(410);
                (*g_612) = &l_578[5];
            }
            step_hash(412);
            (*p_114) ^= 0xF312E88FL;
        }
        step_hash(414);
        if (g_340[g_545])
            continue;
        step_hash(422);
        for (g_441 = 0; (g_441 <= 7); g_441 += 1)
        {
            int *l_637 = (void*)0;
            int l_638[9][7] = {{4L, (-1L), 6L, (-1L), 4L, 4L, 4L}, {4L, (-1L), 6L, (-1L), 4L, 4L, 4L}, {4L, (-1L), 6L, (-1L), 4L, 4L, 4L}, {4L, (-1L), 6L, (-1L), 4L, 4L, 4L}, {4L, (-1L), 6L, (-1L), 4L, 4L, 4L}, {4L, (-1L), 6L, (-1L), 4L, 4L, 4L}, {4L, (-1L), 6L, (-1L), 4L, 4L, 4L}, {4L, (-1L), 6L, (-1L), 4L, 4L, 4L}, {4L, (-1L), 6L, (-1L), 4L, 4L, 4L}};
            int *l_639 = &g_8;
            int *l_640 = &g_557;
            int *l_641 = &g_621;
            int *l_642 = (void*)0;
            unsigned short l_643[1];
            int i, j;
            for (i = 0; i < 1; i++)
                l_643[i] = 0xFB00L;
            step_hash(418);
            (*p_113) |= (((signed char)(-1L) + (signed char)g_556[g_545]) <= (func_116(g_556[g_441], (p_113 != g_632[3]), ((((signed char)(+(g_556[g_441] && ((unsigned char)p_111 + (unsigned char)(l_637 != l_637)))) << (signed char)0) | p_111) ^ g_545), p_111) | g_483));
            step_hash(419);
            ++l_643[0];
            step_hash(420);
            (*p_113) = (0xDCB6L || ((short)(*l_641) + (short)g_518));
            step_hash(421);
            return p_111;
        }
    }
    step_hash(424);
    (**l_569) = &g_482;
    step_hash(425);
    (*l_616) = (*g_612);
    step_hash(426);
    return g_467[5];
}







static unsigned func_116(unsigned short p_117, unsigned char p_118, short p_119, unsigned short p_120)
{
    step_hash(376);
    return p_117;
}







static short func_123(short p_124)
{
    int *l_129 = &g_8;
    short l_144 = 1L;
    unsigned l_284 = 0x772E67D2L;
    int l_291 = (-9L);
    int l_293 = 2L;
    int l_294 = (-7L);
    unsigned char l_324 = 0x28L;
    unsigned l_378 = 1UL;
    int l_436 = 0xEEC116A2L;
    int l_437 = 0x60C62E70L;
    int l_439 = 0xF5582DE0L;
    int l_465 = 0x9778E438L;
    int l_470 = 0x6E7E9149L;
    step_hash(45);
    for (g_8 = 0; (g_8 <= (-15)); g_8 -= 6)
    {
        unsigned char l_130 = 0xE8L;
        step_hash(43);
        (*g_81) = l_129;
        step_hash(44);
        l_130 = 1L;
    }
    step_hash(373);
    if (p_124)
    {
        unsigned short l_131[9];
        int *l_143 = &g_42;
        unsigned l_186 = 0x6D32158AL;
        int i;
        for (i = 0; i < 9; i++)
            l_131[i] = 1UL;
        step_hash(51);
        for (g_46 = 6; (g_46 >= 0); g_46 -= 1)
        {
            int i;
            step_hash(50);
            (*l_129) |= l_131[(g_46 + 2)];
        }
        step_hash(107);
        for (g_42 = 7; (g_42 >= 0); g_42 -= 1)
        {
            unsigned char l_154 = 249UL;
            int *l_169 = &g_8;
            int i;
            step_hash(105);
            if ((0x52ABL == (l_131[(g_42 + 1)] > l_131[g_42])))
            {
                signed char l_142 = (-2L);
                int l_168[10][8] = {{0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}, {0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L, 0L, 0x186BA227L}};
                int i, j;
                step_hash(79);
                for (g_46 = 0; (g_46 <= 8); g_46 += 1)
                {
                    unsigned char l_137 = 246UL;
                    step_hash(66);
                    for (p_124 = 8; (p_124 >= 1); p_124 -= 1)
                    {
                        step_hash(62);
                        (*l_129) |= 0x4CB4AB47L;
                        step_hash(63);
                        (*l_129) = ((short)(((signed char)((!0x3CL) | (&g_82 == (void*)0)) + (signed char)(-(int)l_137)) == ((unsigned short)65528UL >> (unsigned short)((*g_81) == (void*)0))) << (short)((unsigned char)(g_42 == l_131[4]) - (unsigned char)0x61L));
                        step_hash(64);
                        l_142 = (*g_82);
                        step_hash(65);
                        (*g_81) = (*g_81);
                    }
                    step_hash(71);
                    if (p_124)
                    {
                        step_hash(68);
                        return l_142;
                    }
                    else
                    {
                        step_hash(70);
                        (*g_81) = l_143;
                    }
                    step_hash(72);
                    l_144 = 0x897B4F3EL;
                    step_hash(78);
                    if ((**g_81))
                    {
                        unsigned short l_155 = 0x0ECFL;
                        step_hash(74);
                        (*l_129) |= ((short)(((p_124 == ((int)l_137 / (int)(-1L))) && p_124) >= ((0x1430L || g_149) || ((((unsigned)((short)0xBC95L << (short)9) % (unsigned)(g_45 ^ l_154)) & p_124) >= l_155))) * (short)(-1L));
                    }
                    else
                    {
                        step_hash(76);
                        (*l_129) = ((g_58 >= (0x5A6FL < ((l_142 ^ (0xE9L >= ((p_124 < (*l_129)) > g_8))) || (-2L)))) > p_124);
                        step_hash(77);
                        l_168[2][6] |= (p_124 || ((unsigned char)((short)((unsigned short)p_124 << (unsigned short)1) >> (short)((int)(((signed char)((int)(*l_143) + (int)g_42) >> (signed char)0) <= l_137) - (int)(&l_143 != (void*)0))) + (unsigned char)(0x1AL | g_8)));
                    }
                }
                step_hash(80);
                l_169 = (*g_81);
            }
            else
            {
                int **l_201 = &l_129;
                step_hash(104);
                if (((unsigned char)p_124 * (unsigned char)((signed char)((signed char)((void*)0 == l_169) << (signed char)(((unsigned char)0x57L >> (unsigned char)(((unsigned short)g_45 << (unsigned short)((short)(l_129 != (*g_81)) + (short)((*l_129) > (((unsigned)((unsigned char)(*l_129) / (unsigned char)g_42) - (unsigned)0UL) > 4294967294UL)))) & 0x3CL)) == g_6)) >> (signed char)5)))
                {
                    unsigned l_189[8] = {0x1F00607BL, 0x1F00607BL, 7UL, 0x1F00607BL, 0x1F00607BL, 7UL, 0x1F00607BL, 0x1F00607BL};
                    int l_192 = 0x7C884FDEL;
                    int *l_197 = &g_42;
                    int i;
                    step_hash(83);
                    if (l_186)
                        break;
                    step_hash(89);
                    if (((short)p_124 - (short)((l_189[5] == ((int)p_124 / (int)(0xF75C71E7L || ((*l_143) & 0x925CL)))) | (l_192 && ((short)(((signed char)(((void*)0 != l_129) == p_124) / (signed char)g_149) != p_124) + (short)0xC222L)))))
                    {
                        int l_198[9];
                        int i;
                        for (i = 0; i < 9; i++)
                            l_198[i] = 7L;
                        step_hash(85);
                        (*g_81) = l_197;
                        step_hash(86);
                        if (l_198[4])
                            break;
                    }
                    else
                    {
                        step_hash(88);
                        return (*l_169);
                    }
                }
                else
                {
                    unsigned l_202[10][9] = {{0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}, {0x1C342DABL, 0x27B7FBD4L, 0x0575CF62L, 0x63847764L, 4294967295UL, 0x86C0DB86L, 1UL, 1UL, 0x0575CF62L}};
                    int i, j;
                    step_hash(91);
                    (*l_129) &= ((signed char)(((p_124 != ((((&g_82 != l_201) <= ((p_124 & (l_202[4][4] ^ ((unsigned char)g_103 * (unsigned char)(((p_124 > g_45) <= ((signed char)((short)g_103 * (short)p_124) * (signed char)g_45)) > 8UL)))) || g_2)) ^ 2L) || p_124)) | 0xC670BDA2L) || g_6) >> (signed char)3);
                    step_hash(96);
                    for (g_8 = 0; (g_8 <= 8); g_8 += 1)
                    {
                        int *l_209 = &g_210;
                        step_hash(95);
                        (*l_209) = (**g_81);
                    }
                    step_hash(103);
                    for (g_8 = 2; (g_8 <= 8); g_8 += 1)
                    {
                        int *l_211 = (void*)0;
                        int *l_212 = &g_210;
                        step_hash(100);
                        (*g_81) = (*l_201);
                        step_hash(101);
                        (*l_212) |= (g_103 > 0xADBACC00L);
                        step_hash(102);
                        (*l_212) &= (*g_82);
                    }
                }
            }
            step_hash(106);
            return g_11;
        }
    }
    else
    {
        int l_213 = 0x3A24A825L;
        int l_224 = (-9L);
        int *l_230 = &g_210;
        int l_290 = 0x8BB7738AL;
        int l_292 = (-10L);
        signed char l_295 = (-1L);
        int l_297 = (-1L);
        int l_300 = (-5L);
        int l_302 = (-1L);
        unsigned l_316[3];
        unsigned short l_363[3];
        unsigned char l_488[8] = {0xB9L, 0x8EL, 0xB9L, 0x8EL, 0xB9L, 0x8EL, 0xB9L, 0x8EL};
        int l_522 = 0x2E96E14CL;
        int i;
        for (i = 0; i < 3; i++)
            l_316[i] = 0xC6F64A7FL;
        for (i = 0; i < 3; i++)
            l_363[i] = 5UL;
        step_hash(196);
        if (l_213)
        {
            unsigned l_234 = 0UL;
            int *l_262 = &g_8;
            step_hash(110);
            (*l_129) = (((short)p_124 * (short)(((((short)g_6 * (short)((void*)0 == &g_82)) == ((unsigned char)(p_124 ^ (p_124 & (*l_129))) + (unsigned char)(~l_213))) & p_124) == 0xBAF6L)) == (*l_129));
            step_hash(152);
            for (l_213 = 0; (l_213 > (-26)); --l_213)
            {
                signed char l_241 = (-1L);
                int **l_248 = &l_230;
                step_hash(134);
                if (((unsigned short)((*l_129) >= (-9L)) * (unsigned short)(0xAA7906B7L || p_124)))
                {
                    unsigned char l_225 = 0UL;
                    int *l_231 = &g_42;
                    int *l_232 = &g_8;
                    int *l_233[9][1] = {{(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}};
                    int i, j;
                    step_hash(124);
                    if (p_124)
                    {
                        step_hash(116);
                        (*l_129) = l_224;
                        step_hash(117);
                        (*l_129) &= (-1L);
                        step_hash(118);
                        (*l_129) = (*l_129);
                        step_hash(119);
                        l_225++;
                    }
                    else
                    {
                        int *l_228 = (void*)0;
                        step_hash(121);
                        if ((**g_81))
                            break;
                        step_hash(122);
                        (*g_81) = l_228;
                        step_hash(123);
                        (*l_129) |= l_225;
                    }
                    step_hash(129);
                    if (l_213)
                    {
                        unsigned l_229[7][9] = {{0xF6FDADEBL, 0xF6FDADEBL, 0x5B8B4CAAL, 0xAC24F387L, 0x8B46DE65L, 0x68103C05L, 0xD797C3EEL, 0xF6FDADEBL, 4294967286UL}, {0xF6FDADEBL, 0xF6FDADEBL, 0x5B8B4CAAL, 0xAC24F387L, 0x8B46DE65L, 0x68103C05L, 0xD797C3EEL, 0xF6FDADEBL, 4294967286UL}, {0xF6FDADEBL, 0xF6FDADEBL, 0x5B8B4CAAL, 0xAC24F387L, 0x8B46DE65L, 0x68103C05L, 0xD797C3EEL, 0xF6FDADEBL, 4294967286UL}, {0xF6FDADEBL, 0xF6FDADEBL, 0x5B8B4CAAL, 0xAC24F387L, 0x8B46DE65L, 0x68103C05L, 0xD797C3EEL, 0xF6FDADEBL, 4294967286UL}, {0xF6FDADEBL, 0xF6FDADEBL, 0x5B8B4CAAL, 0xAC24F387L, 0x8B46DE65L, 0x68103C05L, 0xD797C3EEL, 0xF6FDADEBL, 4294967286UL}, {0xF6FDADEBL, 0xF6FDADEBL, 0x5B8B4CAAL, 0xAC24F387L, 0x8B46DE65L, 0x68103C05L, 0xD797C3EEL, 0xF6FDADEBL, 4294967286UL}, {0xF6FDADEBL, 0xF6FDADEBL, 0x5B8B4CAAL, 0xAC24F387L, 0x8B46DE65L, 0x68103C05L, 0xD797C3EEL, 0xF6FDADEBL, 4294967286UL}};
                        int i, j;
                        step_hash(126);
                        return l_229[1][1];
                    }
                    else
                    {
                        step_hash(128);
                        (*g_81) = l_230;
                    }
                    step_hash(130);
                    (*l_129) = (**g_81);
                    step_hash(131);
                    l_234++;
                }
                else
                {
                    step_hash(133);
                    return g_210;
                }
                step_hash(135);
                if ((**g_81))
                    break;
                step_hash(151);
                for (g_8 = (-3); (g_8 != 27); g_8++)
                {
                    unsigned char l_258 = 255UL;
                }
            }
        }
        else
        {
            short l_270[4];
            int l_298 = 0xEF448E64L;
            int l_299 = 0xD3C6A0BBL;
            int l_301 = 0x7A19EBCAL;
            int l_304 = 7L;
            unsigned short l_329 = 0x13C4L;
            int *l_330[10][2] = {{(void*)0, &l_302}, {(void*)0, &l_302}, {(void*)0, &l_302}, {(void*)0, &l_302}, {(void*)0, &l_302}, {(void*)0, &l_302}, {(void*)0, &l_302}, {(void*)0, &l_302}, {(void*)0, &l_302}, {(void*)0, &l_302}};
            int i, j;
            for (i = 0; i < 4; i++)
                l_270[i] = (-5L);
            step_hash(188);
            for (l_213 = 0; (l_213 != (-5)); l_213 -= 1)
            {
                int *l_275 = &g_42;
                int l_296 = 2L;
            }
            step_hash(189);
            g_332--;
            step_hash(195);
            for (p_124 = 0; (p_124 <= (-5)); --p_124)
            {
                int l_337 = (-10L);
                int l_338 = 1L;
                int l_339[2][1];
                int i, j;
                for (i = 0; i < 2; i++)
                {
                    for (j = 0; j < 1; j++)
                        l_339[i][j] = 0x5E9CBFC7L;
                }
                step_hash(193);
                ++g_340[7];
                step_hash(194);
                if ((*l_129))
                    continue;
            }
        }
        step_hash(226);
        for (l_291 = 0; (l_291 < 29); l_291++)
        {
            int *l_345 = &g_303;
            int *l_346 = &l_293;
            int *l_347 = (void*)0;
            int *l_348 = &g_210;
            int *l_349 = &g_210;
            int *l_350 = &l_293;
            int *l_351[3][10] = {{&g_8, (void*)0, &l_297, (void*)0, &g_8, (void*)0, &l_297, (void*)0, &g_8, (void*)0}, {&g_8, (void*)0, &l_297, (void*)0, &g_8, (void*)0, &l_297, (void*)0, &g_8, (void*)0}, {&g_8, (void*)0, &l_297, (void*)0, &g_8, (void*)0, &l_297, (void*)0, &g_8, (void*)0}};
            unsigned l_352 = 0x604F5D17L;
            int i, j;
            step_hash(200);
            --l_352;
        }
        step_hash(367);
        if ((*l_230))
        {
            unsigned l_379 = 4294967295UL;
            int l_438 = 0x325822FEL;
            int l_440 = 1L;
            step_hash(234);
            for (l_294 = 4; (l_294 >= (-8)); l_294--)
            {
                int *l_384 = &l_291;
                step_hash(231);
                (*l_230) = (((l_378 & ((((&l_294 == (void*)0) && l_379) > 0xC1L) && 247UL)) == ((signed char)((signed char)g_331[5][0] * (signed char)0x14L) << (signed char)(&g_82 == &g_82))) > g_210);
            }
            step_hash(267);
            for (g_46 = (-7); (g_46 != (-28)); g_46 -= 3)
            {
                unsigned char l_395 = 0x1FL;
                int *l_409 = &g_6;
                int l_435 = (-1L);
                step_hash(263);
                if (((p_124 < (((signed char)(((*l_230) == p_124) == ((*g_81) != (*g_81))) / (signed char)6L) == ((p_124 | ((short)((signed char)((((signed char)l_395 * (signed char)(g_8 != (*l_230))) > g_396) >= 0UL) % (signed char)0xC4L) % (short)g_45)) > p_124))) | g_340[7]))
                {
                    int l_411 = 0x56A399DBL;
                    step_hash(239);
                    (*l_129) = ((*g_82) ^ (*l_230));
                    step_hash(246);
                    if ((*g_82))
                    {
                        int *l_410[1][8] = {{&g_210, &g_210, &l_292, &g_210, &g_210, &l_292, &g_210, &g_210}};
                        int i, j;
                        step_hash(241);
                        g_42 |= (((0x28L >= (((unsigned short)g_103 / (unsigned short)((unsigned)(g_45 && (*l_129)) / (unsigned)((unsigned char)g_331[5][0] >> (unsigned char)6))) | ((unsigned short)(((8L | (((signed char)l_379 % (signed char)((unsigned char)g_58 * (unsigned char)(l_409 != (void*)0))) ^ p_124)) | (**g_81)) | 0x4CEEL) - (unsigned short)g_8))) == 0x8FL) > 0x31L);
                        step_hash(242);
                        ++g_412;
                    }
                    else
                    {
                        int l_427 = 0x7ECD8F6BL;
                        step_hash(244);
                        (*l_129) = (((unsigned char)0x47L * (unsigned char)((unsigned char)((unsigned char)((unsigned short)(((short)(*l_129) - (short)(*l_409)) <= (2UL != l_427)) << (unsigned short)l_411) / (unsigned char)((unsigned char)g_58 + (unsigned char)((1L ^ l_379) < p_124))) * (unsigned char)(*l_129))) ^ 0x0FL);
                        step_hash(245);
                        (*g_81) = &l_293;
                    }
                }
                else
                {
                    int *l_430 = (void*)0;
                    int *l_431 = (void*)0;
                    int *l_432 = &l_302;
                    int *l_433 = (void*)0;
                    int *l_434[5];
                    int i;
                    for (i = 0; i < 5; i++)
                        l_434[i] = &l_291;
                    step_hash(248);
                    --g_441;
                    step_hash(256);
                    for (l_291 = 0; (l_291 >= (-26)); --l_291)
                    {
                        step_hash(252);
                        (*g_81) = &l_291;
                        step_hash(253);
                        (*l_230) ^= (*g_82);
                        step_hash(254);
                        (*g_81) = &l_435;
                        step_hash(255);
                        if ((**g_81))
                            break;
                    }
                    step_hash(262);
                    for (l_293 = 8; (l_293 >= 1); l_293 -= 1)
                    {
                        int i;
                        step_hash(260);
                        (*l_432) = ((signed char)((!(-(unsigned)(((void*)0 == &g_82) > g_340[l_293]))) >= g_340[l_293]) >> (signed char)((g_340[l_293] < (((p_124 < p_124) > ((&l_300 == l_431) | g_441)) && (*l_129))) ^ p_124));
                        step_hash(261);
                        (*l_432) ^= p_124;
                    }
                }
                step_hash(264);
                (*l_129) = p_124;
                step_hash(265);
                (*l_129) = (*g_82);
                step_hash(266);
                return g_11;
            }
            step_hash(268);
            (*l_230) |= ((*l_129) | 0xDA27BD15L);
        }
        else
        {
            unsigned short l_455 = 0x20F7L;
            int l_460[2];
            int *l_487 = &l_300;
            int ***l_497 = &g_81;
            int i;
            for (i = 0; i < 2; i++)
                l_460[i] = 0L;
            step_hash(279);
            for (g_412 = 6; (g_412 < 13); g_412 += 5)
            {
                int **l_459 = &l_129;
                int ***l_458 = &l_459;
                step_hash(277);
                for (l_378 = 0; (l_378 < 43); l_378 += 7)
                {
                    int *l_453 = &g_8;
                    int *l_454[5][8] = {{&l_294, &l_294, &g_303, &l_300, &l_302, &l_300, &g_303, &l_294}, {&l_294, &l_294, &g_303, &l_300, &l_302, &l_300, &g_303, &l_294}, {&l_294, &l_294, &g_303, &l_300, &l_302, &l_300, &g_303, &l_294}, {&l_294, &l_294, &g_303, &l_300, &l_302, &l_300, &g_303, &l_294}, {&l_294, &l_294, &g_303, &l_300, &l_302, &l_300, &g_303, &l_294}};
                    int i, j;
                    step_hash(276);
                    l_455++;
                }
                step_hash(278);
                (*l_458) = &l_230;
            }
            step_hash(328);
            for (l_224 = 2; (l_224 >= 0); l_224 -= 1)
            {
                int l_463 = 8L;
                int l_464 = 6L;
                int l_466[2][5] = {{0xA86D853BL, 0x53D0AA9BL, 0L, 0L, 0x53D0AA9BL}, {0xA86D853BL, 0x53D0AA9BL, 0L, 0L, 0x53D0AA9BL}};
                int i, j;
            }
            step_hash(329);
            l_488[3]++;
            step_hash(366);
            if (((((((void*)0 == &g_81) >= (((unsigned short)((short)p_124 >> (short)g_474) * (unsigned short)(((void*)0 == l_497) || (((unsigned)4294967295UL / (unsigned)((signed char)(~p_124) * (signed char)(((signed char)((void*)0 == &g_81) % (signed char)255UL) < 0x6E3E5089L))) || p_124))) ^ p_124)) == 0UL) >= p_124) < g_332))
            {
                int *l_505 = (void*)0;
                int l_508 = (-4L);
                step_hash(352);
                if (p_124)
                {
                    int *l_504 = &l_290;
                    step_hash(332);
                    l_505 = l_504;
                }
                else
                {
                    unsigned short l_514 = 0xCA62L;
                    int l_517 = 1L;
                    int l_521[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_521[i] = 1L;
                    step_hash(334);
                    (**l_497) = &l_302;
                    step_hash(335);
                    (*g_81) = (**l_497);
                    step_hash(343);
                    for (l_465 = 17; (l_465 == (-25)); --l_465)
                    {
                        int *l_509 = &g_42;
                        int *l_510 = &l_302;
                        int *l_511 = (void*)0;
                        int *l_512 = &l_292;
                        int *l_513[6] = {&l_291, &l_291, &l_294, &l_291, &l_291, &l_294};
                        unsigned l_524 = 0UL;
                        int i;
                        step_hash(339);
                        l_514--;
                        step_hash(340);
                        if ((**g_81))
                            continue;
                        step_hash(341);
                        g_518--;
                        step_hash(342);
                        l_524++;
                    }
                    step_hash(351);
                    if (p_124)
                    {
                        step_hash(345);
                        (*g_81) = &l_290;
                    }
                    else
                    {
                        step_hash(347);
                        (**l_497) = (*g_81);
                        step_hash(348);
                        (**g_81) = (**g_81);
                        step_hash(349);
                        (*g_81) = &l_294;
                        step_hash(350);
                        (**l_497) = (void*)0;
                    }
                }
            }
            else
            {
                unsigned char l_529 = 0UL;
                int l_541 = 1L;
                int l_542 = 0x63D1E85AL;
                step_hash(365);
                for (l_290 = 2; (l_290 >= 0); l_290 -= 1)
                {
                    int l_543 = 0L;
                    int l_544 = 1L;
                    int i;
                    step_hash(357);
                    if (l_363[l_290])
                        break;
                    step_hash(364);
                    for (l_300 = 0; (l_300 <= 9); l_300 += 1)
                    {
                        int *l_538 = &g_8;
                        int *l_539 = &g_210;
                        int *l_540[7] = {&l_470, &l_470, &l_470, &l_470, &l_470, &l_470, &l_470};
                        int i;
                        step_hash(361);
                        (*l_129) = ((((((g_484[l_300] != ((((int)g_467[(l_290 + 5)] % (int)l_529) <= ((signed char)g_11 % (signed char)l_363[l_290])) || ((unsigned char)(***l_497) + (unsigned char)((int)p_124 + (int)(0xDBF5441CL < ((signed char)g_467[(l_290 + 5)] << (signed char)g_46)))))) ^ 2L) || 249UL) <= g_331[5][0]) & 4294967287UL) | (-2L));
                        step_hash(362);
                        ++g_545;
                        step_hash(363);
                        return g_331[5][0];
                    }
                }
            }
        }
        step_hash(372);
        for (p_124 = (-15); (p_124 == 15); ++p_124)
        {
            int *l_550 = (void*)0;
            int *l_551 = &l_292;
            int *l_552 = &l_291;
            int *l_553 = &l_292;
            int *l_554 = &g_42;
            int *l_555[5];
            int i;
            for (i = 0; i < 5; i++)
                l_555[i] = &l_300;
            step_hash(371);
            ++g_558;
        }
    }
    step_hash(374);
    return p_124;
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_6, "g_6", print_hash_value);
    transparent_crc(g_8, "g_8", print_hash_value);
    transparent_crc(g_11, "g_11", print_hash_value);
    transparent_crc(g_42, "g_42", print_hash_value);
    transparent_crc(g_45, "g_45", print_hash_value);
    transparent_crc(g_46, "g_46", print_hash_value);
    transparent_crc(g_58, "g_58", print_hash_value);
    transparent_crc(g_103, "g_103", print_hash_value);
    transparent_crc(g_149, "g_149", print_hash_value);
    transparent_crc(g_210, "g_210", print_hash_value);
    transparent_crc(g_303, "g_303", print_hash_value);
    transparent_crc(g_305, "g_305", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 1; j++)
        {
            transparent_crc(g_331[i][j], "g_331[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_332, "g_332", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_340[i], "g_340[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_396, "g_396", print_hash_value);
    transparent_crc(g_412, "g_412", print_hash_value);
    transparent_crc(g_441, "g_441", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_467[i], "g_467[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_474, "g_474", print_hash_value);
    transparent_crc(g_481, "g_481", print_hash_value);
    transparent_crc(g_482, "g_482", print_hash_value);
    transparent_crc(g_483, "g_483", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        transparent_crc(g_484[i], "g_484[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_518, "g_518", print_hash_value);
    transparent_crc(g_523, "g_523", print_hash_value);
    transparent_crc(g_545, "g_545", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_556[i], "g_556[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_557, "g_557", print_hash_value);
    transparent_crc(g_558, "g_558", print_hash_value);
    transparent_crc(g_620, "g_620", print_hash_value);
    transparent_crc(g_621, "g_621", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_1201[i], "g_1201[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
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
