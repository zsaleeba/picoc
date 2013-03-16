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
static int g_3 = (-6L);
static int g_81 = 0x97D63F7CL;
static int g_83[9] = {0x2D86A023L, 0x2D86A023L, (-10L), 0x2D86A023L, 0x2D86A023L, (-10L), 0x2D86A023L, 0x2D86A023L, (-10L)};
static int g_86 = 0x3B76F056L;
static short g_91 = (-6L);
static short g_92[6] = {1L, 1L, 1L, 1L, 1L, 1L};
static unsigned g_94 = 4294967295UL;
static int *g_117 = &g_86;
static int **g_144[4] = {&g_117, &g_117, &g_117, &g_117};
static int ***g_143[3][7] = {{&g_144[3], (void*)0, (void*)0, (void*)0, &g_144[3], (void*)0, (void*)0}, {&g_144[3], (void*)0, (void*)0, (void*)0, &g_144[3], (void*)0, (void*)0}, {&g_144[3], (void*)0, (void*)0, (void*)0, &g_144[3], (void*)0, (void*)0}};
static unsigned char g_241 = 0x1FL;
static unsigned char g_475 = 0x9FL;
static short g_487 = 0x9293L;
static unsigned g_525 = 0x8D1CBB35L;
static short g_595[8][9] = {{1L, 0x6B4FL, 0xE47EL, (-1L), 0xE47EL, 0x6B4FL, 1L, 0L, 0xABF7L}, {1L, 0x6B4FL, 0xE47EL, (-1L), 0xE47EL, 0x6B4FL, 1L, 0L, 0xABF7L}, {1L, 0x6B4FL, 0xE47EL, (-1L), 0xE47EL, 0x6B4FL, 1L, 0L, 0xABF7L}, {1L, 0x6B4FL, 0xE47EL, (-1L), 0xE47EL, 0x6B4FL, 1L, 0L, 0xABF7L}, {1L, 0x6B4FL, 0xE47EL, (-1L), 0xE47EL, 0x6B4FL, 1L, 0L, 0xABF7L}, {1L, 0x6B4FL, 0xE47EL, (-1L), 0xE47EL, 0x6B4FL, 1L, 0L, 0xABF7L}, {1L, 0x6B4FL, 0xE47EL, (-1L), 0xE47EL, 0x6B4FL, 1L, 0L, 0xABF7L}, {1L, 0x6B4FL, 0xE47EL, (-1L), 0xE47EL, 0x6B4FL, 1L, 0L, 0xABF7L}};
static int ***g_910 = &g_144[3];
static int g_1070 = 0xB4BF964AL;
static short g_1122[4] = {0xC45DL, 1L, 0xC45DL, 1L};
static short g_1142 = (-3L);
static short g_1152[6][4] = {{0x57F9L, 0x4ECDL, 0x9FFAL, 0x3651L}, {0x57F9L, 0x4ECDL, 0x9FFAL, 0x3651L}, {0x57F9L, 0x4ECDL, 0x9FFAL, 0x3651L}, {0x57F9L, 0x4ECDL, 0x9FFAL, 0x3651L}, {0x57F9L, 0x4ECDL, 0x9FFAL, 0x3651L}, {0x57F9L, 0x4ECDL, 0x9FFAL, 0x3651L}};
static signed char g_1156 = 0x06L;
static int g_1262 = 0x32E19C82L;
static unsigned g_1359 = 0xABE466D4L;
static int g_1398 = 0x751E89CDL;
static signed char g_1585 = 0L;
static int **g_1646 = &g_117;
static signed char g_1703 = 0L;
static unsigned short func_1(void);
static int func_14(unsigned p_15, unsigned p_16, unsigned p_17, unsigned p_18);
static signed char func_21(int * p_22, unsigned p_23, unsigned p_24, unsigned p_25);
static unsigned func_26(short p_27, unsigned p_28, short p_29, unsigned short p_30, int p_31);
static unsigned char func_39(unsigned short p_40, int * p_41);
static signed char func_46(int * p_47, unsigned p_48, signed char p_49, int * p_50);
static int * func_54(unsigned p_55, int * p_56, int * p_57, unsigned p_58, short p_59);
static short func_62(int p_63, signed char p_64, short p_65);
static unsigned short func_71(short p_72, signed char p_73, int * p_74, int p_75);
static short func_78(int * p_79);
static unsigned short func_1(void)
{
    int *l_2 = &g_3;
    int *l_4 = &g_3;
    unsigned l_5[8] = {0x2D149FEBL, 1UL, 0x2D149FEBL, 1UL, 0x2D149FEBL, 1UL, 0x2D149FEBL, 1UL};
    unsigned l_8[8] = {0xD952EAA2L, 4294967295UL, 0xD952EAA2L, 4294967295UL, 0xD952EAA2L, 4294967295UL, 0xD952EAA2L, 4294967295UL};
    unsigned char l_1201 = 0x86L;
    int **l_1312 = &l_4;
    int *l_1318 = &g_83[5];
    int l_1345 = 0x91AF68CEL;
    unsigned char l_1350[8] = {255UL, 0x76L, 255UL, 0x76L, 255UL, 0x76L, 255UL, 0x76L};
    unsigned char l_1376 = 0xD5L;
    unsigned l_1417 = 0x87192689L;
    int *l_1427 = &g_83[7];
    int l_1442 = 0xF44A8193L;
    int *l_1615[7] = {&g_1398, &g_1398, (void*)0, &g_1398, &g_1398, (void*)0, &g_1398};
    unsigned l_1670 = 0x2CD22480L;
    unsigned short l_1675 = 0x9691L;
    int i;
    step_hash(1);
    l_5[3]++;
    step_hash(1076);
    if (l_8[1])
    {
        step_hash(3);
        g_3 = ((signed char)0x48L + (signed char)6UL);
    }
    else
    {
        unsigned char l_11 = 1UL;
        int l_38 = 0x826FBD10L;
        int ***l_1315 = &g_144[3];
        signed char l_1327 = (-4L);
        int l_1346 = 4L;
        int l_1349 = 0x2614F9E9L;
        signed char l_1373 = 0xA4L;
        int *l_1380 = (void*)0;
        int *l_1420 = &g_3;
        unsigned short l_1439 = 0x0565L;
        signed char l_1460[7][6] = {{0x8AL, 0x99L, 0x8AL, 0x99L, 0x8AL, 0x99L}, {0x8AL, 0x99L, 0x8AL, 0x99L, 0x8AL, 0x99L}, {0x8AL, 0x99L, 0x8AL, 0x99L, 0x8AL, 0x99L}, {0x8AL, 0x99L, 0x8AL, 0x99L, 0x8AL, 0x99L}, {0x8AL, 0x99L, 0x8AL, 0x99L, 0x8AL, 0x99L}, {0x8AL, 0x99L, 0x8AL, 0x99L, 0x8AL, 0x99L}, {0x8AL, 0x99L, 0x8AL, 0x99L, 0x8AL, 0x99L}};
        int l_1486 = 0L;
        unsigned l_1489 = 7UL;
        unsigned char l_1573 = 250UL;
        unsigned l_1621 = 0UL;
        int *l_1649 = &l_1349;
        int l_1677 = 0L;
        int l_1689 = 0xC0535174L;
        unsigned l_1762 = 4294967292UL;
        int *l_1763[5];
        int i, j;
        for (i = 0; i < 5; i++)
            l_1763[i] = &g_1398;
        step_hash(5);
        l_11++;
        step_hash(888);
        if (func_14(l_11, (((l_11 & (func_21(&g_3, (l_4 != &g_3), l_11, func_26((g_3 <= ((unsigned)(((short)((signed char)l_38 / (signed char)func_39(g_3, &g_3)) / (short)(*l_2)) <= g_1142) / (unsigned)l_11)), g_1122[2], g_92[1], (*l_4), l_1201)) != g_1156)) >= 0x1A128378L) < 0x5E9FL), g_1152[1][0], g_92[2]))
        {
            int l_1294[1];
            int *l_1314 = &g_83[6];
            unsigned l_1325 = 0x7C9151FCL;
            int *l_1336 = &g_83[8];
            int i;
            for (i = 0; i < 1; i++)
                l_1294[i] = 1L;
            step_hash(821);
            for (g_475 = 0; (g_475 < 55); ++g_475)
            {
                signed char l_1296 = (-8L);
                int **l_1329 = (void*)0;
                int *l_1337 = &g_3;
                step_hash(799);
                if ((*g_117))
                {
                    step_hash(788);
                    return l_1294[0];
                }
                else
                {
                    unsigned short l_1295[1][9] = {{0x49CDL, 0x49CDL, 0x93E2L, 0x49CDL, 0x49CDL, 0x93E2L, 0x49CDL, 0x49CDL, 0x93E2L}};
                    int l_1313 = 0xF053C390L;
                    int i, j;
                    step_hash(790);
                    (*g_117) &= 0x27A6EA42L;
                    step_hash(791);
                    if (l_1295[0][7])
                        break;
                    step_hash(798);
                    if (l_1296)
                    {
                        int **l_1311 = (void*)0;
                        step_hash(793);
                        l_1313 &= (((unsigned char)(((short)((short)0x7D23L * (short)((signed char)((unsigned short)(0xDE69B211L || (((unsigned char)g_81 >> (unsigned char)g_83[3]) < ((signed char)(g_1122[0] > g_1262) * (signed char)(((!(l_1311 != l_1312)) | 9UL) != 0x9256FED2L)))) >> (unsigned short)g_81) * (signed char)g_1156)) << (short)(*l_2)) | l_1296) << (unsigned char)g_1156) < g_1122[2]);
                    }
                    else
                    {
                        step_hash(795);
                        (*l_1312) = l_1314;
                        step_hash(796);
                        if (l_1296)
                            continue;
                        step_hash(797);
                        (*l_4) = (&g_144[3] == &g_144[3]);
                    }
                }
                step_hash(800);
                (*g_117) = (l_1315 != &g_144[3]);
                step_hash(808);
                for (g_241 = 2; (g_241 <= 30); g_241++)
                {
                    signed char l_1319 = 0x8EL;
                    int *l_1326 = &g_3;
                    int *l_1328 = &g_86;
                    step_hash(804);
                    (*g_117) = ((func_71(g_83[5], g_1070, l_1318, (*l_1318)) | l_1319) || func_26((func_14(l_1296, (-(int)(((short)(((unsigned short)g_1262 / (unsigned short)g_525) > 0x62L) / (short)g_94) == g_1122[2])), (*l_1314), g_1142) >= g_81), g_487, l_1325, g_1152[1][0], g_83[0]));
                    step_hash(805);
                    (*l_1328) |= (((g_1156 == func_71(g_475, (*l_4), l_1326, (*l_4))) && g_3) || l_1327);
                    step_hash(806);
                    (*g_910) = l_1329;
                    step_hash(807);
                    (*g_117) |= (-6L);
                }
                step_hash(820);
                for (g_86 = 0; (g_86 < (-23)); g_86 -= 2)
                {
                    unsigned l_1335 = 4294967292UL;
                    step_hash(817);
                    for (l_1201 = 20; (l_1201 >= 24); ++l_1201)
                    {
                        int l_1334[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_1334[i] = 0x7E990413L;
                        step_hash(815);
                        l_1334[0] = (*g_117);
                        step_hash(816);
                        return l_1335;
                    }
                    step_hash(818);
                    (*l_1312) = l_1336;
                    step_hash(819);
                    (*l_1312) = l_1337;
                }
            }
            step_hash(822);
            return (*l_1336);
        }
        else
        {
            signed char l_1347 = 0x3AL;
            int l_1348 = 0x79035617L;
            int **l_1362 = (void*)0;
            int l_1374 = 0xCF837CA7L;
            int **l_1423 = &l_2;
            signed char l_1428 = 0xC0L;
            signed char l_1444[2][5] = {{0xD7L, (-1L), 0xD7L, (-1L), 0xD7L}, {0xD7L, (-1L), 0xD7L, (-1L), 0xD7L}};
            short l_1445 = 2L;
            short l_1446 = 0xFB9EL;
            int i, j;
            step_hash(864);
            for (l_1327 = 2; (l_1327 >= 0); l_1327 -= 1)
            {
                int *l_1338 = &g_86;
                int *l_1339 = (void*)0;
                int *l_1340 = &g_83[(l_1327 + 2)];
                int *l_1341 = &g_86;
                int *l_1342 = &g_3;
                int *l_1343 = &g_3;
                int *l_1344[9][6] = {{&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}, {&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}, {&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}, {&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}, {&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}, {&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}, {&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}, {&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}, {&g_83[6], &g_83[(l_1327 + 2)], &g_83[l_1327], &g_83[l_1327], &g_83[(l_1327 + 2)], &g_83[6]}};
                int i, j;
                step_hash(831);
                for (g_475 = 0; (g_475 <= 5); g_475 += 1)
                {
                    int i;
                    step_hash(830);
                    return g_83[(g_475 + 3)];
                }
                step_hash(832);
                --l_1350[6];
                step_hash(833);
                l_1348 ^= ((signed char)(((signed char)g_83[(l_1327 + 1)] << (signed char)7) == g_92[(l_1327 + 3)]) * (signed char)(g_1070 & ((+((func_46((*l_1312), (((signed char)func_26((*l_2), g_595[5][4], g_1359, g_1142, ((((unsigned)((l_1362 != (void*)0) && (*g_117)) % (unsigned)(*l_1341)) != 4UL) ^ (*g_117))) / (signed char)0x38L) > 6UL), g_1122[3], &g_83[l_1327]) == 0x0E38L) == (*l_2))) | 5L)));
                step_hash(846);
                if (((short)g_1122[2] % (short)g_595[5][3]))
                {
                    short l_1372 = 4L;
                    step_hash(841);
                    for (g_91 = 2; (g_91 >= 0); g_91 -= 1)
                    {
                        unsigned char l_1369 = 1UL;
                        int l_1375 = 1L;
                        int *l_1379 = &l_1346;
                        int i, j;
                        step_hash(838);
                        (*g_117) = ((+(((((short)0xB6C5L + (short)func_78(&g_83[l_1327])) >= ((((((unsigned short)l_1369 << (unsigned short)((short)func_46((*l_1312), g_1142, l_1372, (*l_1312)) * (short)g_1152[3][1])) & l_1373) > 0L) != l_1374) >= g_1152[1][2])) && (*l_1343)) != 0x9AL)) & g_475);
                        step_hash(839);
                        --l_1376;
                        step_hash(840);
                        l_1380 = l_1379;
                    }
                    step_hash(842);
                    if (l_1372)
                        continue;
                }
                else
                {
                    short l_1381 = 0x4D3FL;
                    int *l_1382[4][2] = {{&l_1348, &l_1348}, {&l_1348, &l_1348}, {&l_1348, &l_1348}, {&l_1348, &l_1348}};
                    int i, j;
                    step_hash(844);
                    (*l_1312) = (*l_1312);
                    step_hash(845);
                    if ((*g_117))
                        break;
                }
                step_hash(863);
                for (l_1349 = 2; (l_1349 >= 0); l_1349 -= 1)
                {
                    int l_1394 = 0x572087E2L;
                    unsigned l_1397 = 1UL;
                    int i, j;
                    step_hash(850);
                    if ((*l_1340))
                        break;
                    step_hash(856);
                    if (((((-(unsigned char)g_86) < ((**l_1312) != (((0xC6L || ((unsigned char)((0xB081BBF4L < ((*l_4) != ((unsigned)l_1348 / (unsigned)((int)(*g_117) + (int)((unsigned short)((short)l_1394 + (short)((unsigned short)g_83[5] + (unsigned short)g_1262)) % (unsigned short)0x1122L))))) ^ 0L) >> (unsigned char)g_1142)) || g_595[0][6]) | 0xBC600954L))) ^ g_1152[1][0]) >= 7L))
                    {
                        step_hash(852);
                        (*l_1312) = (*l_1312);
                    }
                    else
                    {
                        step_hash(854);
                        if ((*g_117))
                            break;
                        step_hash(855);
                        (*l_1318) ^= l_1397;
                    }
                    step_hash(862);
                    if (g_1398)
                    {
                        step_hash(858);
                        return g_1142;
                    }
                    else
                    {
                        short l_1401 = 0xBA92L;
                        int *l_1404[7][1] = {{&g_83[(l_1327 + 2)]}, {&g_83[(l_1327 + 2)]}, {&g_83[(l_1327 + 2)]}, {&g_83[(l_1327 + 2)]}, {&g_83[(l_1327 + 2)]}, {&g_83[(l_1327 + 2)]}, {&g_83[(l_1327 + 2)]}};
                        int i, j;
                        step_hash(860);
                        (*l_1338) = ((short)l_1401 + (short)(((int)0xEEB3ED56L - (int)func_78((*l_1312))) | 4294967287UL));
                        step_hash(861);
                        if ((*l_4))
                            continue;
                    }
                }
            }
            step_hash(887);
            if ((((signed char)g_94 * (signed char)(((unsigned short)((short)0x84D3L % (short)((unsigned)((short)((signed char)0L * (signed char)g_1152[1][0]) + (short)((((+l_1417) != ((signed char)func_46(l_1420, g_83[5], ((unsigned)(l_1423 != &l_2) % (unsigned)(**l_1312)), (*l_1423)) % (signed char)0x14L)) & 65526UL) > g_487)) / (unsigned)g_94)) >> (unsigned short)15) || g_94)) ^ 0UL))
            {
                int *l_1429 = &g_86;
                unsigned l_1431 = 4294967292UL;
                step_hash(870);
                for (g_3 = (-15); (g_3 != 28); g_3 += 1)
                {
                    int **l_1426 = (void*)0;
                    int *l_1430 = (void*)0;
                    step_hash(869);
                    (*l_1312) = l_1429;
                }
                step_hash(871);
                (*l_4) = l_1431;
                step_hash(882);
                for (l_1346 = 0; (l_1346 >= 9); l_1346 += 1)
                {
                    int *l_1434 = (void*)0;
                    int *l_1435 = (void*)0;
                    unsigned l_1436 = 0x744CDC49L;
                    step_hash(875);
                    ++l_1436;
                    step_hash(876);
                    (**l_1423) &= l_1439;
                    step_hash(881);
                    if (((unsigned short)(g_1152[1][0] && 1UL) * (unsigned short)((*g_117) != 0x8D9C0E08L)))
                    {
                        step_hash(878);
                        return g_81;
                    }
                    else
                    {
                        step_hash(880);
                        return g_86;
                    }
                }
            }
            else
            {
                int *l_1443[7];
                unsigned l_1447 = 4294967295UL;
                int i;
                for (i = 0; i < 7; i++)
                    l_1443[i] = &l_1374;
                step_hash(884);
                l_1447++;
                step_hash(885);
                (*l_1420) = (((((unsigned short)((((short)((signed char)g_1142 - (signed char)(g_1359 || ((unsigned)g_241 + (unsigned)g_525))) / (short)((short)(8L >= l_1460[2][0]) + (short)((short)(0x4BAFL <= (((signed char)(g_1122[1] < (*l_1427)) >> (signed char)2) & (**l_1312))) - (short)1L))) >= (*l_1420)) | g_1359) * (unsigned short)(**l_1423)) <= g_475) || g_1122[2]) == g_595[5][4]);
                step_hash(886);
                (*l_4) |= 0xBD1A72E3L;
            }
        }
        step_hash(893);
        for (g_487 = 0; (g_487 <= 7); g_487 += 1)
        {
            int i;
            step_hash(892);
            if (l_8[g_487])
                break;
        }
        step_hash(1075);
        for (g_241 = 18; (g_241 < 44); g_241 += 9)
        {
            signed char l_1469 = 1L;
            int *l_1472[7][3] = {{(void*)0, &l_1346, (void*)0}, {(void*)0, &l_1346, (void*)0}, {(void*)0, &l_1346, (void*)0}, {(void*)0, &l_1346, (void*)0}, {(void*)0, &l_1346, (void*)0}, {(void*)0, &l_1346, (void*)0}, {(void*)0, &l_1346, (void*)0}};
            short l_1499 = 0x8BCAL;
            int *l_1524 = &l_1349;
            unsigned l_1531 = 4294967295UL;
            unsigned char l_1538 = 0x29L;
            int l_1551 = 0x16DA1726L;
            unsigned l_1560 = 0xD5040E44L;
            unsigned short l_1582 = 0UL;
            short l_1596 = 0xF822L;
            unsigned l_1612[3];
            int ***l_1636 = &g_144[3];
            int l_1647 = 0xA044B158L;
            int l_1761 = 0x2586556FL;
            int i, j;
            for (i = 0; i < 3; i++)
                l_1612[i] = 3UL;
            step_hash(897);
            (*l_1315) = (void*)0;
            step_hash(970);
            if ((((((unsigned char)(l_1469 >= (g_1152[1][3] == ((short)g_1398 % (short)g_1122[0]))) * (unsigned char)g_1152[0][3]) && 0x470E946DL) | 6UL) > g_1398))
            {
                unsigned char l_1481 = 0UL;
                int ***l_1485[10][2] = {{&g_144[3], (void*)0}, {&g_144[3], (void*)0}, {&g_144[3], (void*)0}, {&g_144[3], (void*)0}, {&g_144[3], (void*)0}, {&g_144[3], (void*)0}, {&g_144[3], (void*)0}, {&g_144[3], (void*)0}, {&g_144[3], (void*)0}, {&g_144[3], (void*)0}};
                short l_1488 = 0L;
                int i, j;
                step_hash(899);
                (*l_1312) = (*l_1312);
                step_hash(904);
                for (g_1142 = (-28); (g_1142 != (-16)); g_1142++)
                {
                    step_hash(903);
                    return g_1262;
                }
                step_hash(920);
                for (g_1142 = (-22); (g_1142 != 14); g_1142 += 3)
                {
                    unsigned l_1484 = 0xD256E1D0L;
                    int *l_1487 = &g_86;
                    step_hash(908);
                    (*l_4) = 0x02E7C6F8L;
                    step_hash(913);
                    for (g_1398 = (-3); (g_1398 < (-3)); g_1398 += 7)
                    {
                        step_hash(912);
                        return g_94;
                    }
                    step_hash(914);
                    l_1489 = (l_1481 || func_71(g_83[1], (((((unsigned short)((g_1152[1][0] < ((((l_1484 ^ (*l_4)) <= ((l_1485[8][0] == &g_144[3]) <= ((((*l_1420) >= func_46((*l_1312), g_241, l_1486, l_1487)) | g_1070) == l_1488))) <= g_595[3][6]) != (*l_1487))) || g_1152[2][2]) - (unsigned short)g_475) > g_1122[2]) == g_1156) != g_91), l_1487, (*l_1420)));
                    step_hash(919);
                    if ((((signed char)(&l_1318 == &l_4) << (signed char)5) && (g_1070 > g_1122[2])))
                    {
                        step_hash(916);
                        (*l_1487) ^= (-1L);
                    }
                    else
                    {
                        step_hash(918);
                        return (*l_2);
                    }
                }
                step_hash(936);
                for (l_1327 = 0; (l_1327 != (-4)); --l_1327)
                {
                    int **l_1496[9][6] = {{&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}, {&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}, {&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}, {&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}, {&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}, {&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}, {&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}, {&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}, {&l_1318, &g_117, &l_1427, &l_1427, &g_117, &l_1318}};
                    int i, j;
                    step_hash(930);
                    for (l_1442 = 7; (l_1442 >= 2); l_1442 -= 1)
                    {
                        int i, j;
                        step_hash(927);
                        (*l_4) |= ((unsigned char)(~((void*)0 != l_1496[0][1])) * (unsigned char)((short)((g_595[l_1442][(l_1442 + 1)] > g_595[l_1442][(l_1442 + 1)]) == (0x373EL < l_1350[l_1442])) + (short)l_1350[l_1442]));
                        step_hash(928);
                        if (l_1499)
                            break;
                        step_hash(929);
                        (*l_1318) &= (1UL > g_92[2]);
                    }
                    step_hash(935);
                    for (l_1373 = 0; (l_1373 == (-12)); --l_1373)
                    {
                        step_hash(934);
                        return g_1152[1][0];
                    }
                }
            }
            else
            {
                int *l_1504 = &g_83[8];
                unsigned l_1523 = 0xED7AC434L;
                int **l_1539 = &l_1524;
                step_hash(952);
                for (g_1156 = 0; (g_1156 != (-9)); --g_1156)
                {
                    unsigned char l_1507 = 0x86L;
                    int *l_1518 = &g_86;
                    int l_1519 = 0xB6C55F2EL;
                }
                step_hash(969);
                for (l_1499 = 0; (l_1499 <= (-11)); l_1499 -= 2)
                {
                    step_hash(961);
                    for (l_1376 = 3; (l_1376 >= 50); l_1376++)
                    {
                        int *l_1548 = &l_1442;
                        step_hash(959);
                        l_1551 ^= (l_1538 <= ((g_83[5] <= ((void*)0 == l_1539)) == ((+(g_1262 <= ((short)((unsigned short)((((short)g_86 << (short)((signed char)func_46(l_1548, ((unsigned)g_1262 / (unsigned)(*l_2)), g_1070, l_1524) / (signed char)0x49L)) && g_241) == g_475) >> (unsigned short)g_91) - (short)(*l_1427)))) == g_1152[1][0])));
                        step_hash(960);
                        return (*l_1504);
                    }
                    step_hash(968);
                    for (g_94 = 21; (g_94 > 2); g_94 -= 7)
                    {
                        unsigned l_1554 = 4294967292UL;
                        step_hash(965);
                        (*l_1420) = l_1554;
                        step_hash(966);
                        (*l_1504) = l_1554;
                        step_hash(967);
                        return g_241;
                    }
                }
            }
        }
    }
    step_hash(1077);
    return g_1359;
}
static int func_14(unsigned p_15, unsigned p_16, unsigned p_17, unsigned p_18)
{
    int **l_1240 = &g_117;
    int l_1250 = (-7L);
    step_hash(743);
    for (g_1156 = 0; (g_1156 > (-16)); g_1156--)
    {
        step_hash(736);
        (*g_117) = (p_17 || (l_1240 != (void*)0));
        step_hash(741);
        for (g_91 = 2; (g_91 >= 0); g_91 -= 1)
        {
            step_hash(740);
            return p_18;
        }
        step_hash(742);
        (**l_1240) = ((unsigned char)p_15 / (unsigned char)(**l_1240));
    }
    step_hash(744);
    (**l_1240) = func_46((*l_1240), ((((**l_1240) <= (&g_144[2] != (void*)0)) && ((**l_1240) < p_15)) || (((signed char)(g_1156 <= ((short)(**l_1240) >> (short)(-(unsigned short)(**l_1240)))) << (signed char)p_16) && 3L)), (**l_1240), (*l_1240));
    step_hash(745);
    l_1250 |= ((signed char)g_86 / (signed char)0xC9L);
    step_hash(781);
    for (g_525 = 23; (g_525 >= 38); g_525++)
    {
        short l_1263 = 0x626CL;
        int *l_1284 = &g_86;
        step_hash(780);
        for (l_1250 = (-13); (l_1250 < (-19)); l_1250--)
        {
            unsigned short l_1265 = 0xC10BL;
            int *l_1273 = &l_1250;
            int l_1274 = 0x8C551F7EL;
            step_hash(756);
            for (g_3 = 5; (g_3 > (-20)); g_3 -= 4)
            {
                step_hash(755);
                if (p_18)
                    break;
            }
            step_hash(777);
            for (p_17 = (-21); (p_17 <= 41); p_17++)
            {
                int *l_1261 = &g_3;
                int l_1277 = 0xEE951AAFL;
                int ***l_1283 = &g_144[3];
                step_hash(776);
                for (g_1142 = (-10); (g_1142 <= (-5)); g_1142++)
                {
                    int *l_1264 = &l_1250;
                    int *l_1275 = &g_83[2];
                    int *l_1276[10] = {(void*)0, (void*)0, &g_86, (void*)0, (void*)0, &g_86, (void*)0, (void*)0, &g_86, (void*)0};
                    unsigned char l_1278 = 252UL;
                    int l_1289[8][3];
                    int i, j;
                    for (i = 0; i < 8; i++)
                    {
                        for (j = 0; j < 3; j++)
                            l_1289[i][j] = 0x667AABB5L;
                    }
                }
            }
            step_hash(778);
            (*g_117) = (**l_1240);
            step_hash(779);
            l_1274 |= ((unsigned char)(*l_1284) * (unsigned char)7UL);
        }
    }
    step_hash(782);
    return (*g_117);
}
static signed char func_21(int * p_22, unsigned p_23, unsigned p_24, unsigned p_25)
{
    unsigned l_1231 = 0x6251A222L;
    int *l_1234[1];
    int i;
    for (i = 0; i < 1; i++)
        l_1234[i] = &g_3;
    step_hash(730);
    for (g_1070 = (-5); (g_1070 != 18); g_1070++)
    {
        int **l_1237 = (void*)0;
        step_hash(726);
        for (g_91 = 0; (g_91 >= (-29)); --g_91)
        {
            int **l_1236[3][5] = {{&l_1234[0], &l_1234[0], &l_1234[0], &l_1234[0], &l_1234[0]}, {&l_1234[0], &l_1234[0], &l_1234[0], &l_1234[0], &l_1234[0]}, {&l_1234[0], &l_1234[0], &l_1234[0], &l_1234[0], &l_1234[0]}};
            int i, j;
            step_hash(719);
            (*p_22) = l_1231;
            step_hash(724);
            for (g_3 = 27; (g_3 == (-26)); g_3 -= 8)
            {
                int **l_1235 = &l_1234[0];
                step_hash(723);
                (*l_1235) = l_1234[0];
            }
            step_hash(725);
            l_1234[0] = p_22;
        }
        step_hash(727);
        l_1234[0] = p_22;
        step_hash(728);
        (*p_22) &= ((void*)0 == &p_22);
        step_hash(729);
        return g_595[5][4];
    }
    step_hash(731);
    return g_1152[4][0];
}
static unsigned func_26(short p_27, unsigned p_28, short p_29, unsigned short p_30, int p_31)
{
    int l_1202[10] = {0x8B4350F3L, 0x8B4350F3L, 0xF8C64CB0L, 0x8B4350F3L, 0x8B4350F3L, 0xF8C64CB0L, 0x8B4350F3L, 0x8B4350F3L, 0xF8C64CB0L, 0x8B4350F3L};
    int *l_1203 = &g_83[0];
    int *l_1204 = (void*)0;
    int *l_1205 = &g_3;
    int *l_1206 = &g_86;
    int *l_1207 = &g_83[0];
    int *l_1208 = &g_86;
    int *l_1209 = &g_83[8];
    int *l_1210 = &g_83[1];
    int *l_1211 = &g_86;
    int *l_1212 = &g_86;
    int *l_1213 = &g_86;
    int *l_1214[6][2] = {{&g_3, &g_83[0]}, {&g_3, &g_83[0]}, {&g_3, &g_83[0]}, {&g_3, &g_83[0]}, {&g_3, &g_83[0]}, {&g_3, &g_83[0]}};
    unsigned char l_1215 = 0xD5L;
    int ***l_1218 = (void*)0;
    unsigned l_1224 = 0UL;
    int i, j;
    step_hash(708);
    ++l_1215;
    step_hash(709);
    (*l_1206) = (g_1122[2] && (*l_1208));
    step_hash(710);
    l_1224++;
    step_hash(711);
    return p_29;
}







static unsigned char func_39(unsigned short p_40, int * p_41)
{
    int *l_51 = &g_3;
    int l_1128 = 0x0321E436L;
    int l_1150 = 0x914A8D88L;
    int l_1151 = 0xBE36B82EL;
    int l_1154 = 0x1FE9416BL;
    short l_1155 = 0xC38BL;
    int l_1158 = 0xF9B6E23AL;
    int ***l_1168[8][10] = {{&g_144[3], &g_144[3], (void*)0, (void*)0, &g_144[3], &g_144[0], &g_144[1], &g_144[0], (void*)0, &g_144[0]}, {&g_144[3], &g_144[3], (void*)0, (void*)0, &g_144[3], &g_144[0], &g_144[1], &g_144[0], (void*)0, &g_144[0]}, {&g_144[3], &g_144[3], (void*)0, (void*)0, &g_144[3], &g_144[0], &g_144[1], &g_144[0], (void*)0, &g_144[0]}, {&g_144[3], &g_144[3], (void*)0, (void*)0, &g_144[3], &g_144[0], &g_144[1], &g_144[0], (void*)0, &g_144[0]}, {&g_144[3], &g_144[3], (void*)0, (void*)0, &g_144[3], &g_144[0], &g_144[1], &g_144[0], (void*)0, &g_144[0]}, {&g_144[3], &g_144[3], (void*)0, (void*)0, &g_144[3], &g_144[0], &g_144[1], &g_144[0], (void*)0, &g_144[0]}, {&g_144[3], &g_144[3], (void*)0, (void*)0, &g_144[3], &g_144[0], &g_144[1], &g_144[0], (void*)0, &g_144[0]}, {&g_144[3], &g_144[3], (void*)0, (void*)0, &g_144[3], &g_144[0], &g_144[1], &g_144[0], (void*)0, &g_144[0]}};
    unsigned char l_1198 = 0x69L;
    int i, j;
    step_hash(670);
    if (((unsigned char)((signed char)func_46(&g_3, p_40, p_40, l_51) - (signed char)(l_51 != p_41)) + (unsigned char)func_71(((*l_51) < (*l_51)), g_595[5][4], l_51, (*l_51))))
    {
        signed char l_1120 = 1L;
        unsigned l_1121 = 0x7AA989C0L;
        int *l_1125 = &g_83[5];
        int *l_1129 = (void*)0;
        int l_1147 = 0x7313C922L;
        int l_1149 = (-10L);
        int l_1159 = 0x3D064881L;
        int l_1160[7][3] = {{0xA7639A70L, (-8L), 0xE159FB6CL}, {0xA7639A70L, (-8L), 0xE159FB6CL}, {0xA7639A70L, (-8L), 0xE159FB6CL}, {0xA7639A70L, (-8L), 0xE159FB6CL}, {0xA7639A70L, (-8L), 0xE159FB6CL}, {0xA7639A70L, (-8L), 0xE159FB6CL}, {0xA7639A70L, (-8L), 0xE159FB6CL}};
        int i, j;
        step_hash(623);
        for (g_1070 = 0; (g_1070 <= 2); g_1070 += 1)
        {
            int i;
            step_hash(617);
            (***g_910) = g_92[(g_1070 + 3)];
            step_hash(622);
            for (g_91 = 2; (g_91 >= 0); g_91 -= 1)
            {
                int i, j;
                step_hash(621);
                p_41 = p_41;
            }
        }
        step_hash(661);
        for (g_94 = (-20); (g_94 != 4); ++g_94)
        {
            int ***l_1127 = &g_144[3];
            int l_1144[7][3] = {{1L, 0x1E92FABBL, 0xA5B70FB2L}, {1L, 0x1E92FABBL, 0xA5B70FB2L}, {1L, 0x1E92FABBL, 0xA5B70FB2L}, {1L, 0x1E92FABBL, 0xA5B70FB2L}, {1L, 0x1E92FABBL, 0xA5B70FB2L}, {1L, 0x1E92FABBL, 0xA5B70FB2L}, {1L, 0x1E92FABBL, 0xA5B70FB2L}};
            int i, j;
            step_hash(659);
            if (((0xE137L || p_40) && ((signed char)(((g_525 >= p_40) < g_1122[2]) <= g_94) - (signed char)g_94)))
            {
                step_hash(632);
                for (g_1070 = 0; (g_1070 <= (-24)); g_1070 -= 9)
                {
                    step_hash(631);
                    return p_40;
                }
                step_hash(633);
                (*g_117) = ((void*)0 != (**g_910));
            }
            else
            {
                signed char l_1126[4][5] = {{0xC7L, 0x31L, 0x5CL, 0x31L, 0xC7L}, {0xC7L, 0x31L, 0x5CL, 0x31L, 0xC7L}, {0xC7L, 0x31L, 0x5CL, 0x31L, 0xC7L}, {0xC7L, 0x31L, 0x5CL, 0x31L, 0xC7L}};
                int l_1133 = 0x307DB213L;
                int l_1143[3];
                int i, j;
                for (i = 0; i < 3; i++)
                    l_1143[i] = 0x50DA5453L;
                step_hash(658);
                for (g_81 = 0; (g_81 <= 2); g_81 += 1)
                {
                    unsigned l_1130 = 0UL;
                    int l_1135 = 0xA191AAA5L;
                    int l_1136 = (-1L);
                    int l_1145 = 1L;
                    int l_1146 = (-5L);
                    int l_1148[9][7] = {{0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}, {0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}, {0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}, {0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}, {0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}, {0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}, {0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}, {0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}, {0xF04A1E59L, (-10L), 1L, 5L, 0x33C32F5CL, 5L, 1L}};
                    int l_1153 = 0x1E374F75L;
                    int l_1157 = (-3L);
                    unsigned l_1161 = 0x6185CE33L;
                    int i, j;
                    step_hash(638);
                    (*g_910) = &p_41;
                    step_hash(639);
                    l_1125 = p_41;
                }
            }
            step_hash(660);
            (*g_117) &= 0x847C2D61L;
        }
    }
    else
    {
        int *l_1171 = &g_3;
        int l_1174 = 0x3956C3EBL;
        step_hash(668);
        if ((g_92[2] && ((unsigned)p_40 + (unsigned)((**g_910) == p_41))))
        {
            step_hash(664);
            (***g_910) &= (*p_41);
            step_hash(665);
            (**g_910) = l_1171;
        }
        else
        {
            step_hash(667);
            (*g_117) |= (*p_41);
        }
        step_hash(669);
        l_1174 = (g_1122[2] > ((*g_910) != &l_1171));
    }
    step_hash(696);
    for (g_1070 = (-2); (g_1070 >= (-17)); g_1070 -= 9)
    {
        int ***l_1179 = &g_144[3];
        int l_1184 = 0xF1F25141L;
        int l_1193 = 5L;
        step_hash(674);
        (**g_910) = p_41;
        step_hash(695);
        for (g_525 = (-20); (g_525 == 7); g_525 += 1)
        {
            short l_1180 = 0xC502L;
            int l_1191 = (-10L);
            int l_1192 = 1L;
            unsigned char l_1194[8][1] = {{1UL}, {1UL}, {1UL}, {1UL}, {1UL}, {1UL}, {1UL}, {1UL}};
            int i, j;
            step_hash(688);
            if ((*l_51))
            {
                signed char l_1183 = 0x6DL;
                step_hash(679);
                l_1180 ^= (&g_144[3] == l_1179);
                step_hash(685);
                for (g_241 = 0; (g_241 <= 3); g_241 += 1)
                {
                    int i, j;
                    step_hash(683);
                    l_1183 &= ((signed char)g_1152[(g_241 + 1)][g_241] + (signed char)((void*)0 != &g_144[0]));
                    step_hash(684);
                    l_1184 &= l_1180;
                }
            }
            else
            {
                int *l_1189 = &l_1150;
                step_hash(687);
                (*l_1189) = ((unsigned char)((unsigned char)func_78(l_1189) + (unsigned char)(-1L)) << (unsigned char)p_40);
            }
            step_hash(693);
            for (l_1151 = 0; (l_1151 <= 7); l_1151 += 1)
            {
                int l_1190[6][5] = {{0x660ED758L, (-1L), 0x660ED758L, (-1L), 0x660ED758L}, {0x660ED758L, (-1L), 0x660ED758L, (-1L), 0x660ED758L}, {0x660ED758L, (-1L), 0x660ED758L, (-1L), 0x660ED758L}, {0x660ED758L, (-1L), 0x660ED758L, (-1L), 0x660ED758L}, {0x660ED758L, (-1L), 0x660ED758L, (-1L), 0x660ED758L}, {0x660ED758L, (-1L), 0x660ED758L, (-1L), 0x660ED758L}};
                int i, j;
                step_hash(692);
                ++l_1194[6][0];
            }
            step_hash(694);
            if ((*p_41))
                break;
        }
    }
    step_hash(697);
    (**g_910) = (**g_910);
    step_hash(705);
    for (l_1150 = 0; (l_1150 <= 3); l_1150 += 1)
    {
        int l_1197 = (-4L);
        int i;
        step_hash(701);
        if (g_83[(l_1150 + 5)])
            break;
        step_hash(702);
        l_1197 |= func_71(func_78(p_41), p_40, p_41, p_40);
        step_hash(703);
        --l_1198;
        step_hash(704);
        p_41 = (**g_910);
    }
    step_hash(706);
    return g_91;
}







static signed char func_46(int * p_47, unsigned p_48, signed char p_49, int * p_50)
{
    signed char l_66 = 8L;
    int *l_80[9][7] = {{(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}, {(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}, {(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}, {(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}, {(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}, {(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}, {(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}, {(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}, {(void*)0, (void*)0, &g_3, &g_3, (void*)0, &g_3, &g_3}};
    unsigned short l_187 = 5UL;
    unsigned char l_1068 = 0x75L;
    int i, j;
    step_hash(611);
    for (p_49 = 0; (p_49 > (-16)); p_49 -= 2)
    {
        int *l_188[2][9] = {{&g_3, &g_3, &g_3, &g_3, &g_3, &g_3, &g_3, &g_3, &g_3}, {&g_3, &g_3, &g_3, &g_3, &g_3, &g_3, &g_3, &g_3, &g_3}};
        int **l_1026 = &l_80[0][3];
        signed char l_1055 = 7L;
        unsigned char l_1084[1][10] = {{1UL, 248UL, 1UL, 248UL, 1UL, 248UL, 1UL, 248UL, 1UL, 248UL}};
        int l_1085 = 0L;
        signed char l_1100 = 0xF9L;
        int i, j;
    }
    step_hash(612);
    return g_595[0][4];
}







static int * func_54(unsigned p_55, int * p_56, int * p_57, unsigned p_58, short p_59)
{
    int *l_447[4] = {&g_86, &g_86, &g_86, &g_86};
    signed char l_450 = 0x60L;
    unsigned l_451 = 4294967295UL;
    signed char l_601[4];
    unsigned l_647[9] = {7UL, 7UL, 4294967295UL, 7UL, 7UL, 4294967295UL, 7UL, 7UL, 4294967295UL};
    unsigned l_696 = 1UL;
    int ***l_798 = &g_144[2];
    int ***l_878 = &g_144[0];
    unsigned l_953 = 1UL;
    int ***l_978 = &g_144[3];
    unsigned char l_1010[1];
    int *l_1023 = &g_83[5];
    int i;
    for (i = 0; i < 4; i++)
        l_601[i] = (-1L);
    for (i = 0; i < 1; i++)
        l_1010[i] = 0xDCL;
    step_hash(270);
    for (p_59 = 0; (p_59 == 18); p_59 += 8)
    {
        int **l_448 = (void*)0;
        int **l_449 = &g_117;
        step_hash(269);
        (*l_449) = l_447[2];
    }
    step_hash(271);
    --l_451;
    step_hash(544);
    if (((signed char)0x88L % (signed char)0xD2L))
    {
        short l_456[4][1];
        int l_472 = 0L;
        int **l_555 = &l_447[2];
        signed char l_563 = 0L;
        int l_580 = 0L;
        int l_582 = 0L;
        int l_589 = 0x2395AA96L;
        int l_590 = 1L;
        int l_593 = (-1L);
        int l_597[9] = {1L, 1L, 0x2FAE3115L, 1L, 1L, 0x2FAE3115L, 1L, 1L, 0x2FAE3115L};
        unsigned char l_646 = 1UL;
        int ***l_681 = &l_555;
        unsigned l_795 = 4294967293UL;
        int **l_816 = &l_447[2];
        int l_818[2];
        int i, j;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 1; j++)
                l_456[i][j] = 0L;
        }
        for (i = 0; i < 2; i++)
            l_818[i] = 0L;
        step_hash(378);
        if ((0L ^ (4L > (~l_456[3][0]))))
        {
            signed char l_459 = 4L;
            int *l_470[7];
            int ***l_503 = &g_144[3];
            unsigned short l_584 = 65535UL;
            short l_596 = (-1L);
            unsigned char l_598 = 0UL;
            int l_672[9][8] = {{0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}, {0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}, {0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}, {0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}, {0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}, {0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}, {0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}, {0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}, {0xFCCC60D0L, 0x1F5A3AF7L, 0x1FD95619L, (-7L), (-1L), 9L, 0x1C3CC502L, (-1L)}};
            int i, j;
            for (i = 0; i < 7; i++)
                l_470[i] = &g_86;
            step_hash(283);
            for (l_451 = 0; (l_451 != 51); l_451++)
            {
                int *l_463 = &g_3;
                int *l_468 = &g_83[5];
                step_hash(281);
                if ((g_86 < ((((g_3 ^ (((p_57 == p_57) != func_71(g_241, (l_459 < (1L >= ((signed char)p_59 << (signed char)((-(int)func_71(g_241, g_241, p_57, (*p_57))) & p_55)))), l_463, l_456[3][0])) ^ 1L)) & g_241) ^ l_456[0][0]) != p_55)))
                {
                    int *l_469 = &g_83[5];
                    unsigned l_471 = 0x043BEBC2L;
                    step_hash(278);
                    l_471 &= (0xE91AL && (0L ^ ((g_83[5] > (0x1B54L | ((0x48L < ((g_86 | ((int)0xA66F6F8BL % (int)((short)g_81 + (short)(func_71((l_468 != l_469), g_241, l_470[2], (*p_56)) || 0xBAC5L)))) < 0UL)) != 0x9B7AL))) < 0xF4D5L)));
                }
                else
                {
                    step_hash(280);
                    return l_447[2];
                }
                step_hash(282);
                l_472 = 0L;
            }
            step_hash(356);
            if (((unsigned)g_83[2] % (unsigned)g_475))
            {
                int **l_476[10][3] = {{&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}, {&l_447[2], &l_470[2], &l_470[0]}};
                int i, j;
                step_hash(285);
                l_447[0] = p_56;
                step_hash(286);
                l_472 = ((signed char)p_58 << (signed char)0);
                step_hash(305);
                if (((unsigned)(65527UL >= (((unsigned short)(g_83[5] != g_83[3]) + (unsigned short)6UL) & ((unsigned char)5UL - (unsigned char)(&l_447[2] != (void*)0)))) / (unsigned)g_92[2]))
                {
                    signed char l_485 = 0L;
                    step_hash(288);
                    l_485 = (*p_56);
                }
                else
                {
                    signed char l_495 = (-3L);
                    int l_499 = 0xA1F61590L;
                    unsigned char l_518 = 5UL;
                    step_hash(295);
                    for (g_475 = 0; (g_475 <= 3); g_475 += 1)
                    {
                        int l_486 = 0xCE4011C5L;
                        int i;
                        step_hash(293);
                        l_486 = (&g_144[g_475] == &g_144[g_475]);
                        step_hash(294);
                        return p_56;
                    }
                    step_hash(296);
                    g_487 ^= 0L;
                    step_hash(303);
                    if (((unsigned short)p_58 / (unsigned short)((+(p_59 && 0x1FB7L)) | (l_447[0] == (void*)0))))
                    {
                        short l_494 = 3L;
                        step_hash(298);
                        l_472 &= (g_94 & ((signed char)((unsigned short)l_494 >> (unsigned short)3) + (signed char)g_86));
                    }
                    else
                    {
                        unsigned l_496 = 0x2FF40AB4L;
                        int l_500 = 0x55F6B382L;
                        step_hash(300);
                        l_496--;
                        step_hash(301);
                        l_499 &= (-1L);
                        step_hash(302);
                        l_500 &= (*p_56);
                    }
                    step_hash(304);
                    l_499 = ((unsigned char)(((void*)0 != l_503) >= func_71((((unsigned short)(func_78(p_57) < (-(unsigned)((+(~((-(unsigned short)(((signed char)((signed char)(p_55 > ((+(l_499 & ((unsigned short)1UL - (unsigned short)func_71((((unsigned short)((unsigned short)l_495 * (unsigned short)0x300AL) / (unsigned short)l_472) < g_92[2]), p_59, &l_472, l_499)))) > 0x9779181DL)) << (signed char)l_518) - (signed char)3L) || p_55)) != g_92[2]))) && p_59))) >> (unsigned short)4) & p_58), g_487, p_56, (*p_57))) % (unsigned char)0xC8L);
                }
            }
            else
            {
                int l_523 = 0L;
                int l_524[1];
                int l_637 = 0x42CF07C6L;
                unsigned char l_652 = 3UL;
                int i;
                for (i = 0; i < 1; i++)
                    l_524[i] = (-1L);
                step_hash(319);
                for (g_241 = 0; (g_241 <= 4); g_241 += 5)
                {
                    short l_521 = 0x6685L;
                    int l_550 = (-5L);
                    step_hash(317);
                    if (l_521)
                    {
                        int *l_522 = &g_83[5];
                        step_hash(311);
                        (**l_503) = l_522;
                        step_hash(312);
                        (*g_117) ^= (p_57 == (**l_503));
                        step_hash(313);
                        ++g_525;
                    }
                    else
                    {
                        int **l_545 = (void*)0;
                        step_hash(315);
                        l_472 ^= (g_525 | (l_524[0] == ((p_58 > ((unsigned char)(0x834CECF7L != ((unsigned)p_59 - (unsigned)(0xD39526B3L != ((unsigned short)((short)(-(signed char)0x4FL) - (short)(0L || p_59)) >> (unsigned short)p_59)))) << (unsigned char)l_456[3][0])) && g_86)));
                        step_hash(316);
                        l_550 |= ((((unsigned short)l_524[0] % (unsigned short)func_78(&l_472)) >= (((signed char)((unsigned short)0x0989L + (unsigned short)(&p_56 == l_545)) << (signed char)((void*)0 != l_545)) < (((unsigned short)((signed char)p_55 % (signed char)0x80L) - (unsigned short)1L) == p_59))) <= 0x135BL);
                    }
                    step_hash(318);
                    l_472 &= (func_78(p_57) & (((short)g_525 / (short)g_241) <= ((unsigned short)0x2A9CL << (unsigned short)(&p_57 == l_555))));
                }
                step_hash(336);
                if ((((unsigned char)0x21L + (unsigned char)(0x5DFC9776L && (((((signed char)p_58 + (signed char)(0x0853L < ((l_524[0] < 1L) >= (-(unsigned char)(((short)((g_487 && (g_83[5] || (l_563 ^ p_58))) >= p_55) - (short)p_58) > 0UL))))) != g_487) == 0L) && 0L))) ^ g_94))
                {
                    signed char l_578 = (-7L);
                    int l_581 = (-10L);
                    int l_583 = 0x392C0F20L;
                    int *l_587 = &l_524[0];
                    int *l_588[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_588[i] = &l_523;
                    step_hash(327);
                    if (((signed char)((short)((((short)g_94 << (short)12) != p_55) || ((short)p_59 << (short)(1L & (((((short)3L >> (short)7) >= ((unsigned short)(((int)(*p_57) - (int)g_83[4]) < p_58) << (unsigned short)(p_58 > p_55))) == p_55) && p_59)))) / (short)p_55) >> (signed char)7))
                    {
                        signed char l_579 = (-6L);
                        step_hash(322);
                        (**l_555) ^= (*p_56);
                        step_hash(323);
                        l_584--;
                    }
                    else
                    {
                        step_hash(325);
                        l_587 = l_447[2];
                        step_hash(326);
                        (*l_555) = l_588[1];
                    }
                    step_hash(332);
                    for (l_523 = 0; (l_523 <= 3); l_523 += 1)
                    {
                        int i;
                        step_hash(331);
                        l_447[l_523] = p_57;
                    }
                }
                else
                {
                    short l_591[3][8] = {{(-8L), 0x0F02L, (-8L), 0x0F02L, (-8L), 0x0F02L, (-8L), 0x0F02L}, {(-8L), 0x0F02L, (-8L), 0x0F02L, (-8L), 0x0F02L, (-8L), 0x0F02L}, {(-8L), 0x0F02L, (-8L), 0x0F02L, (-8L), 0x0F02L, (-8L), 0x0F02L}};
                    int l_592 = (-8L);
                    int l_594[1];
                    int i, j;
                    for (i = 0; i < 1; i++)
                        l_594[i] = 0x84839CD7L;
                    step_hash(334);
                    --l_598;
                    step_hash(335);
                    (**l_555) = l_601[0];
                }
                step_hash(355);
                if (((unsigned short)((((signed char)g_94 / (signed char)p_58) != (-10L)) <= (&g_144[3] != (void*)0)) - (unsigned short)g_525))
                {
                    short l_608 = 0x9B32L;
                    int l_609 = 0L;
                    int l_611[1][9];
                    unsigned l_614 = 4294967287UL;
                    int i, j;
                    for (i = 0; i < 1; i++)
                    {
                        for (j = 0; j < 9; j++)
                            l_611[i][j] = (-1L);
                    }
                    step_hash(343);
                    if ((*p_57))
                    {
                        int l_610 = (-9L);
                        int l_612 = 0L;
                        int l_613[6][5] = {{0x04127FDDL, 0x785FCC2DL, 0L, 0x785FCC2DL, 0x04127FDDL}, {0x04127FDDL, 0x785FCC2DL, 0L, 0x785FCC2DL, 0x04127FDDL}, {0x04127FDDL, 0x785FCC2DL, 0L, 0x785FCC2DL, 0x04127FDDL}, {0x04127FDDL, 0x785FCC2DL, 0L, 0x785FCC2DL, 0x04127FDDL}, {0x04127FDDL, 0x785FCC2DL, 0L, 0x785FCC2DL, 0x04127FDDL}, {0x04127FDDL, 0x785FCC2DL, 0L, 0x785FCC2DL, 0x04127FDDL}};
                        int i, j;
                        step_hash(339);
                        ++l_614;
                        step_hash(340);
                        l_611[0][1] ^= ((*p_57) && ((unsigned char)(((signed char)(-1L) % (signed char)9UL) < (&p_57 == (void*)0)) << (unsigned char)4));
                    }
                    else
                    {
                        int ***l_625[9][10] = {{&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}, {&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}, {&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}, {&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}, {&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}, {&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}, {&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}, {&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}, {&g_144[3], (void*)0, &g_144[3], (void*)0, (void*)0, &g_144[0], &l_555, &l_555, &g_144[3], &l_555}};
                        unsigned l_630 = 4294967295UL;
                        int i, j;
                        step_hash(342);
                        l_630 = (((unsigned)(0x0575L < g_595[7][1]) + (unsigned)((unsigned short)((0x2CAFL ^ ((l_625[6][8] == &g_144[0]) >= ((unsigned short)p_55 + (unsigned short)((unsigned)0xFC8ADAA9L + (unsigned)(p_59 >= (!g_595[2][1])))))) & 0x2FEFL) << (unsigned short)p_58)) > p_58);
                    }
                    step_hash(344);
                    l_611[0][1] = (func_78(&l_523) > 0UL);
                    step_hash(345);
                    l_647[3] = (((int)func_78(p_57) + (int)g_92[0]) | ((signed char)func_71((g_241 > ((int)l_637 + (int)((((unsigned char)(((short)((unsigned short)l_614 << (unsigned short)((unsigned short)l_614 >> (unsigned short)(0xA704AB6BL ^ p_59))) % (short)0x2DDCL) > 65535UL) - (unsigned char)g_91) && l_646) ^ p_58))), g_92[2], &l_611[0][1], (*p_56)) / (signed char)g_3));
                }
                else
                {
                    int l_649[10] = {(-1L), 0xC0E0B0CCL, (-1L), 0xC0E0B0CCL, (-1L), 0xC0E0B0CCL, (-1L), 0xC0E0B0CCL, (-1L), 0xC0E0B0CCL};
                    int l_658 = 0xB1E7AFEAL;
                    int i;
                    step_hash(347);
                    l_524[0] = (*p_57);
                    step_hash(354);
                    if ((-(unsigned char)(&l_524[0] != &l_524[0])))
                    {
                        short l_650 = 4L;
                        int l_651 = 0xC487ED9AL;
                        step_hash(349);
                        --l_652;
                    }
                    else
                    {
                        unsigned char l_655 = 9UL;
                        unsigned char l_659[3][1];
                        int i, j;
                        for (i = 0; i < 3; i++)
                        {
                            for (j = 0; j < 1; j++)
                                l_659[i][j] = 0xFFL;
                        }
                        step_hash(351);
                        l_655--;
                        step_hash(352);
                        l_658 &= (g_81 || g_92[2]);
                        step_hash(353);
                        --l_659[2][0];
                    }
                }
            }
            step_hash(368);
            for (l_646 = 0; (l_646 < 49); l_646 += 6)
            {
                unsigned l_674 = 0xB03BCA02L;
                int *l_675 = (void*)0;
                step_hash(360);
                l_597[3] &= ((unsigned short)l_589 - (unsigned short)65535UL);
                step_hash(367);
                for (l_584 = 1; (l_584 <= 5); l_584 += 1)
                {
                    int *l_673 = &l_472;
                    int i, j;
                    step_hash(364);
                    l_674 = func_71(g_595[l_584][(l_584 + 2)], ((unsigned char)((unsigned char)((signed char)func_71(func_78(p_57), l_672[5][0], p_57, (*p_57)) + (signed char)g_487) >> (unsigned char)((func_71(g_91, p_55, p_56, l_472) < 0xF0L) <= g_92[2])) >> (unsigned char)p_58), l_673, (*l_673));
                    step_hash(365);
                    (*l_555) = l_675;
                    step_hash(366);
                    (*l_555) = p_57;
                }
            }
        }
        else
        {
            int **l_678 = (void*)0;
            step_hash(377);
            for (g_91 = 0; (g_91 >= 2); g_91++)
            {
            }
        }
        step_hash(379);
        (*l_681) = &p_57;
        step_hash(468);
        if (((unsigned short)(((short)((-4L) <= (((signed char)((unsigned short)((short)((((((signed char)p_55 / (signed char)(0x79EEL ^ g_595[5][4])) <= (&l_555 == &l_555)) & p_55) > l_696) <= g_92[4]) % (short)p_58) << (unsigned short)10) / (signed char)g_86) > 1UL)) + (short)0x9ED6L) != g_595[0][4]) - (unsigned short)(-1L)))
        {
            unsigned l_713[9][6] = {{4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}, {4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}, {4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}, {4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}, {4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}, {4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}, {4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}, {4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}, {4294967295UL, 4294967295UL, 4294967286UL, 4294967295UL, 4294967295UL, 1UL}};
            int l_714 = 0x289C3B88L;
            int ***l_719 = (void*)0;
            int i, j;
            step_hash(392);
            for (l_593 = (-18); (l_593 != (-5)); ++l_593)
            {
                unsigned l_712 = 0x99DC1280L;
                step_hash(391);
                for (l_696 = (-20); (l_696 >= 24); l_696++)
                {
                    unsigned l_703 = 0UL;
                    int l_720[6][1] = {{2L}, {2L}, {2L}, {2L}, {2L}, {2L}};
                    int l_727 = (-7L);
                    int i, j;
                    step_hash(387);
                    l_714 = (((unsigned)4294967295UL + (unsigned)l_703) && (l_703 >= ((int)((!(0x18004B53L && 0x70D584F5L)) || (((signed char)((unsigned short)((short)(p_55 & (&g_144[3] != (void*)0)) + (short)p_59) >> (unsigned short)p_55) << (signed char)4) < l_703)) % (int)9L)));
                    step_hash(388);
                    l_720[2][0] &= ((signed char)((short)(l_713[1][5] ^ ((***l_681) > p_58)) % (short)0x95C0L) * (signed char)p_59);
                    step_hash(389);
                    l_714 |= (g_3 < g_86);
                    step_hash(390);
                    if ((*p_56))
                        continue;
                }
            }
            step_hash(410);
            if (((short)8L * (short)(((unsigned short)g_595[3][8] % (unsigned short)0x9971L) | p_59)))
            {
                int l_738 = 0x8B29A7AEL;
                step_hash(394);
                l_738 = ((((~(*p_56)) != ((((int)(*p_57) + (int)(((signed char)5L + (signed char)(g_595[5][5] & p_55)) != 0x1430CDE7L)) <= ((signed char)((((void*)0 != &p_56) ^ ((void*)0 == p_56)) & g_525) / (signed char)g_92[5])) <= 0x82L)) >= (-8L)) < p_55);
            }
            else
            {
                int *l_739 = &g_3;
                int ***l_753 = &g_144[3];
                int l_768 = (-1L);
                step_hash(408);
                if ((*p_57))
                {
                    step_hash(397);
                    (*l_555) = l_739;
                }
                else
                {
                    int ***l_754 = &l_555;
                    int l_771[3];
                    int i;
                    for (i = 0; i < 3; i++)
                        l_771[i] = 0x7283BB99L;
                    step_hash(399);
                    l_714 = (((unsigned)(((unsigned short)((unsigned short)((+((short)(**l_555) % (short)((short)((-(int)(((unsigned short)((l_753 != l_754) < (g_94 != 0xB527BB63L)) - (unsigned short)(((unsigned short)g_92[5] * (unsigned short)((unsigned short)(func_71(g_241, (((unsigned char)g_83[5] << (unsigned char)0) & (((int)(*p_56) % (int)(*p_56)) != p_55)), (**l_754), (*p_57)) | (**l_555)) * (unsigned short)1UL)) > g_94)) < (*p_56))) >= 0x4BL) << (short)8))) & p_55) >> (unsigned short)11) >> (unsigned short)p_58) && 0x855CC9AAL) % (unsigned)4294967288UL) < p_59);
                    step_hash(407);
                    if ((**l_555))
                    {
                        int l_763 = 0x049073F7L;
                        step_hash(401);
                        l_763 = (*p_57);
                    }
                    else
                    {
                        step_hash(403);
                        l_768 &= (((unsigned char)((signed char)p_58 / (signed char)0xE0L) % (unsigned char)(0L || g_595[5][4])) & (p_55 != (((*p_57) != (*l_739)) ^ 0x52L)));
                        step_hash(404);
                        l_771[2] = (p_58 == ((*l_753) == &p_56));
                        step_hash(405);
                        (**l_681) = p_56;
                        step_hash(406);
                        l_714 |= ((unsigned char)((unsigned char)(-(unsigned)((((signed char)(((void*)0 != l_753) != ((unsigned char)(**l_555) + (unsigned char)1L)) >> (signed char)0) <= (~0x4AL)) && func_78(p_57))) % (unsigned char)l_713[2][5]) % (unsigned char)((short)g_92[2] >> (short)1));
                    }
                }
                step_hash(409);
                l_768 = (-5L);
            }
            step_hash(411);
            l_597[8] |= ((signed char)0L * (signed char)0xFAL);
            step_hash(412);
            return p_57;
        }
        else
        {
            short l_792 = 0x70D0L;
            int l_793[7][9] = {{2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L}, {2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L}, {2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L}, {2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L}, {2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L}, {2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L}, {2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L, 2L, 2L, 0x7FE5F855L}};
            int l_800 = (-1L);
            int **l_877 = &g_117;
            int i, j;
            step_hash(421);
            for (g_81 = 1; (g_81 <= 5); g_81 += 1)
            {
                int ***l_789 = &g_144[3];
                int l_794 = 0x230A96D4L;
                int l_799 = (-1L);
                int i;
                step_hash(417);
                l_792 ^= (((unsigned char)g_92[g_81] - (unsigned char)((void*)0 == l_789)) <= ((-4L) == ((unsigned char)g_92[g_81] << (unsigned char)1)));
                step_hash(418);
                l_795++;
                step_hash(419);
                l_793[5][8] = (l_798 != l_798);
                step_hash(420);
                l_793[6][8] &= l_799;
            }
            step_hash(422);
            l_800 |= (l_793[3][7] && (+l_792));
            step_hash(466);
            if ((p_58 & ((int)(*p_57) - (int)5L)))
            {
                unsigned short l_817 = 0xE00AL;
                step_hash(424);
                (*l_555) = (*l_555);
                step_hash(430);
                for (l_590 = (-10); (l_590 >= 1); l_590 += 7)
                {
                    unsigned l_811 = 0x1B8C2E2BL;
                    step_hash(428);
                    l_817 |= ((short)((unsigned char)((unsigned char)((**l_681) != (void*)0) * (unsigned char)l_811) << (unsigned char)7) - (short)((((short)(p_56 != (void*)0) >> (short)(l_816 != &p_56)) && 0xD5055BA8L) <= ((+0xF30FE994L) & 0UL)));
                    step_hash(429);
                    l_818[1] &= (*p_57);
                }
                step_hash(431);
                (**l_681) = p_56;
                step_hash(432);
                (**l_681) = p_57;
            }
            else
            {
                int *l_821 = &l_793[5][8];
                int l_869 = 0x15A5C33CL;
                step_hash(441);
                for (l_593 = 27; (l_593 != 15); l_593 -= 7)
                {
                    unsigned short l_828 = 0xBCAEL;
                    step_hash(437);
                    (*l_555) = l_821;
                    step_hash(438);
                    (**l_798) = l_821;
                    step_hash(439);
                    if ((*p_56))
                        break;
                    step_hash(440);
                    (***l_681) = ((unsigned short)((unsigned)p_58 + (unsigned)(((int)(*p_56) / (int)l_828) != ((*g_117) < ((unsigned char)((l_800 >= p_55) > (((unsigned char)1UL - (unsigned char)(*l_821)) && ((-(signed char)(-(unsigned char)((unsigned short)((signed char)(p_55 <= 5UL) << (signed char)l_828) >> (unsigned short)7))) > g_91))) - (unsigned char)l_793[2][4])))) * (unsigned short)p_55);
                }
                step_hash(464);
                for (l_590 = 0; (l_590 > 15); l_590 += 1)
                {
                    unsigned short l_858 = 1UL;
                    int l_859 = 0xC80569BCL;
                    int l_868 = 8L;
                    int l_870 = 0L;
                    int l_871 = 1L;
                    unsigned l_879[9][7] = {{4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}, {4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}, {4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}, {4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}, {4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}, {4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}, {4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}, {4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}, {4294967292UL, 4294967291UL, 4294967295UL, 4294967295UL, 4294967291UL, 4294967292UL, 4294967291UL}};
                    int i, j;
                    step_hash(454);
                    if ((*p_56))
                    {
                        int *l_841[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_841[i] = &g_83[5];
                        step_hash(446);
                        (*l_821) |= ((void*)0 == l_841[0]);
                        step_hash(447);
                        l_859 |= ((***l_681) | (0x132D9B26L || (((short)g_525 << (short)((signed char)((unsigned)((unsigned char)((unsigned char)func_78(&l_793[2][2]) << (unsigned char)func_71((1UL ^ func_71(g_92[2], (8UL > func_71((((short)((short)((unsigned)0UL / (unsigned)(**l_555)) / (short)g_92[1]) - (short)g_475) != l_858), p_59, p_57, (*p_57))), p_56, (*p_57))), g_595[6][3], p_56, (*p_56))) * (unsigned char)p_59) % (unsigned)0xE7FA0FEEL) << (signed char)p_55)) ^ l_858)));
                        step_hash(448);
                        if ((*p_57))
                            break;
                        step_hash(449);
                        (*l_821) = (***l_681);
                    }
                    else
                    {
                        int *l_865 = &l_793[5][8];
                        step_hash(451);
                        (*l_821) |= (!((short)((void*)0 == p_57) >> (short)1));
                        step_hash(452);
                        (**l_681) = l_865;
                        step_hash(453);
                        (*p_57) = (*l_821);
                    }
                    step_hash(455);
                    if ((*p_57))
                        break;
                    step_hash(463);
                    if (((short)p_55 << (short)7))
                    {
                        unsigned short l_872 = 3UL;
                        step_hash(457);
                        l_872++;
                        step_hash(458);
                        l_870 = l_793[4][3];
                    }
                    else
                    {
                        int l_880[9] = {1L, 1L, 0x2D18D467L, 1L, 1L, 0x2D18D467L, 1L, 1L, 0x2D18D467L};
                        int i;
                        step_hash(460);
                        (*l_821) = ((int)((**l_555) ^ 0x70L) / (int)g_94);
                        step_hash(461);
                        l_880[8] &= (p_59 && func_71((((func_71(p_59, g_83[6], &l_869, (l_877 != &p_56)) & ((l_798 != l_878) & 0x3DEAL)) < 1UL) || g_94), p_58, p_57, l_879[8][4]));
                        step_hash(462);
                        (*l_821) &= ((signed char)p_58 * (signed char)p_59);
                    }
                }
                step_hash(465);
                (*l_821) |= 0x908D84FCL;
            }
            step_hash(467);
            (*l_816) = (void*)0;
        }
        step_hash(469);
        l_580 &= ((short)g_94 >> (short)8);
    }
    else
    {
        int *l_911 = &g_83[5];
        int l_912 = 0xDFDCF9DCL;
        unsigned l_913 = 0UL;
        int *l_949 = &g_83[7];
        int ***l_956 = &g_144[3];
        int *l_972 = &g_83[0];
        int l_1001 = 0x45EDF574L;
        step_hash(482);
        for (l_451 = 0; (l_451 > 52); l_451++)
        {
            int l_887[3];
            int ***l_909 = &g_144[3];
            int i;
            for (i = 0; i < 3; i++)
                l_887[i] = 8L;
            step_hash(474);
            l_887[2] |= ((void*)0 == p_56);
            step_hash(479);
            for (g_241 = 10; (g_241 <= 56); g_241++)
            {
                unsigned l_896 = 0x3DB98C9FL;
                step_hash(478);
                (*l_911) = ((unsigned short)(p_59 | ((int)(((signed char)l_896 % (signed char)0x11L) || ((signed char)((unsigned char)(((unsigned char)(((short)((unsigned short)func_71(func_71(l_896, ((unsigned char)((l_909 != g_910) <= p_59) + (unsigned char)(!(g_3 >= ((p_56 == (void*)0) && 0xD412L)))), l_911, (*p_57)), g_525, l_911, (*p_56)) + (unsigned short)0x2009L) / (short)p_58) >= 0xC5L) + (unsigned char)(-9L)) <= (*p_57)) / (unsigned char)0xDDL) + (signed char)p_58)) % (int)0x1AFE2176L)) >> (unsigned short)l_896);
            }
            step_hash(480);
            l_913++;
            step_hash(481);
            if (l_887[0])
                continue;
        }
        step_hash(542);
        for (g_81 = 0; (g_81 <= 5); g_81 += 1)
        {
            int l_927 = 0xEFC2EC47L;
            unsigned char l_991[4][5] = {{0x19L, 255UL, 9UL, 250UL, 0UL}, {0x19L, 255UL, 9UL, 250UL, 0UL}, {0x19L, 255UL, 9UL, 250UL, 0UL}, {0x19L, 255UL, 9UL, 250UL, 0UL}};
            signed char l_1011 = 4L;
            int i, j;
            step_hash(486);
            (*l_911) = ((unsigned char)((short)0L >> (short)g_92[g_81]) * (unsigned char)(p_59 == (((int)(*p_56) % (int)1L) || ((unsigned short)(-(signed char)p_58) + (unsigned short)p_58))));
            step_hash(487);
            l_927 = (0x97CA2F20L & ((signed char)0x5DL / (signed char)254UL));
            step_hash(523);
            if ((p_57 == (void*)0))
            {
                int l_932 = 0xF1D43EBDL;
                step_hash(489);
                (*l_911) |= l_927;
                step_hash(490);
                p_57 = p_56;
                step_hash(491);
                l_927 = ((short)(l_932 > (((0x2CL >= ((signed char)((int)(l_932 == 0xC6758475L) - (int)g_525) + (signed char)0xC8L)) < l_932) != (p_55 ^ 0x5FL))) << (short)g_487);
            }
            else
            {
                int l_938 = 4L;
                int l_939 = (-3L);
                int *l_952 = &l_912;
                step_hash(514);
                for (p_59 = 0; (p_59 <= 2); p_59 += 1)
                {
                    int i, j;
                    step_hash(500);
                    for (l_450 = 3; (l_450 >= 0); l_450 -= 1)
                    {
                        int l_937 = 0x61AAEA9DL;
                        int i, j;
                        step_hash(499);
                        l_937 |= (g_595[(p_59 + 1)][l_450] == 0x5AL);
                    }
                    step_hash(506);
                    for (g_475 = 0; (g_475 <= 3); g_475 += 1)
                    {
                        unsigned l_940 = 0UL;
                        int i, j;
                        step_hash(504);
                        ++l_940;
                        step_hash(505);
                        if (g_595[(p_59 + 4)][(p_59 + 3)])
                            continue;
                    }
                    step_hash(507);
                    (*l_911) |= (g_595[(p_59 + 2)][(g_81 + 2)] & (*p_57));
                    step_hash(513);
                    for (l_938 = 3; (l_938 >= 0); l_938 -= 1)
                    {
                        step_hash(511);
                        l_939 &= (((signed char)((short)(((int)(-5L) / (int)(*p_57)) != (&p_56 != (void*)0)) >> (short)((p_56 != l_949) & ((unsigned char)func_71(p_58, g_595[5][4], l_952, (*l_952)) << (unsigned char)l_927))) >> (signed char)g_83[5]) > l_953);
                        step_hash(512);
                        (*l_952) |= (((unsigned char)(&g_144[p_59] == l_956) % (unsigned char)((short)((-(signed char)((unsigned)(((*p_56) > (p_58 >= ((int)((short)p_59 - (short)(func_71(p_55, g_92[2], p_56, (*l_949)) || 0x52L)) - (int)g_92[g_81]))) > p_59) - (unsigned)4294967295UL)) > (-10L)) / (short)p_55)) <= g_92[g_81]);
                    }
                }
                step_hash(521);
                if (((p_56 == p_57) <= func_71(func_71((p_59 > p_55), ((unsigned char)g_94 << (unsigned char)(p_59 & ((void*)0 == p_57))), l_972, (*p_57)), (*l_952), &l_927, (*p_57))))
                {
                    int ***l_977[9][1] = {{&g_144[1]}, {&g_144[1]}, {&g_144[1]}, {&g_144[1]}, {&g_144[1]}, {&g_144[1]}, {&g_144[1]}, {&g_144[1]}, {&g_144[1]}};
                    int i, j;
                    step_hash(516);
                    (*l_952) &= (((unsigned short)(0L == (((signed char)g_241 - (signed char)(l_977[5][0] != l_978)) != func_71(((short)((short)(((short)((short)((unsigned)g_525 + (unsigned)((signed char)0x40L * (signed char)g_86)) + (short)l_991[2][3]) - (short)(((unsigned short)((short)(-1L) + (short)1UL) >> (unsigned short)3) || (-1L))) | g_92[4]) * (short)p_55) * (short)g_83[4]), g_525, p_56, (*p_56)))) * (unsigned short)p_59) == g_595[3][3]);
                }
                else
                {
                    unsigned short l_996 = 3UL;
                    step_hash(518);
                    l_1001 ^= ((((~l_996) <= ((func_71((g_81 & (g_487 | ((unsigned short)((unsigned)((0x7F7D7225L && 0x11417CE6L) <= g_81) - (unsigned)(*l_952)) * (unsigned short)l_927))), g_525, p_56, (*p_57)) || p_59) & 5L)) <= p_58) && (*l_972));
                    step_hash(519);
                    (**l_798) = p_57;
                    step_hash(520);
                    (*l_949) = ((unsigned char)((~0xA0L) || ((int)(*l_952) % (int)((unsigned char)((*p_56) && ((func_71(((g_595[3][1] | 0x5DB1L) & ((short)l_1010[0] / (short)p_58)), g_83[1], p_57, (***g_910)) != g_92[2]) > g_92[0])) % (unsigned char)g_525))) << (unsigned char)6);
                }
                step_hash(522);
                (**l_956) = p_56;
            }
            step_hash(541);
            for (g_91 = 0; (g_91 <= 3); g_91 += 1)
            {
                int l_1022[6][8] = {{1L, 1L, 0x75C6ED5DL, 1L, 1L, 4L, 1L, 1L}, {1L, 1L, 0x75C6ED5DL, 1L, 1L, 4L, 1L, 1L}, {1L, 1L, 0x75C6ED5DL, 1L, 1L, 4L, 1L, 1L}, {1L, 1L, 0x75C6ED5DL, 1L, 1L, 4L, 1L, 1L}, {1L, 1L, 0x75C6ED5DL, 1L, 1L, 4L, 1L, 1L}, {1L, 1L, 0x75C6ED5DL, 1L, 1L, 4L, 1L, 1L}};
                int i, j;
                step_hash(538);
                if (g_595[(g_91 + 1)][(g_91 + 2)])
                {
                    int l_1021 = 0x1BAF9776L;
                    step_hash(535);
                    if (((void*)0 != &p_56))
                    {
                        step_hash(529);
                        (*l_972) |= (*p_56);
                        step_hash(530);
                        (*l_949) = g_595[(g_91 + 1)][(g_91 + 2)];
                        step_hash(531);
                        if (l_1011)
                            break;
                    }
                    else
                    {
                        int l_1014 = 1L;
                        step_hash(533);
                        l_1022[0][2] = (((short)l_1014 + (short)p_59) && (((short)((unsigned short)(8UL <= 0x4B6471AAL) << (unsigned short)((int)l_1011 + (int)((g_487 < g_81) < (l_1014 & 0x34C2FBB4L)))) + (short)g_487) != l_1021));
                        step_hash(534);
                        return p_56;
                    }
                }
                else
                {
                    step_hash(537);
                    (*l_949) = g_595[(g_91 + 1)][(g_91 + 2)];
                }
                step_hash(539);
                if ((*p_56))
                    break;
                step_hash(540);
                (*l_949) = 1L;
            }
        }
        step_hash(543);
        (*l_949) = 4L;
    }
    step_hash(545);
    return l_1023;
}







static short func_62(int p_63, signed char p_64, short p_65)
{
    int *l_189 = (void*)0;
    int *l_190 = &g_86;
    int l_191 = 0xB8DD50FDL;
    int *l_192[6];
    unsigned char l_193 = 0x6CL;
    unsigned l_215 = 6UL;
    int ***l_325 = &g_144[0];
    int l_431[4] = {0x0616CA4FL, 0L, 0x0616CA4FL, 0L};
    int i;
    for (i = 0; i < 6; i++)
        l_192[i] = &g_83[6];
    step_hash(86);
    l_193--;
    step_hash(101);
    for (l_191 = 16; (l_191 < (-15)); l_191 -= 9)
    {
        unsigned char l_212 = 0xF8L;
        int *l_214 = &g_83[5];
        step_hash(94);
        for (g_91 = 8; (g_91 >= 3); g_91 -= 1)
        {
            int i;
            step_hash(93);
            return g_83[g_91];
        }
        step_hash(100);
        for (g_81 = 0; (g_81 > (-18)); --g_81)
        {
            signed char l_213 = 0x18L;
            int **l_216 = &l_189;
            step_hash(98);
            (*l_190) = ((signed char)((((unsigned short)6UL >> (unsigned short)5) == ((0xB1F4L ^ (*l_190)) >= ((int)(func_71(((7UL < g_83[1]) >= ((g_92[2] == (func_71(g_81, (((unsigned)(l_212 >= (-3L)) - (unsigned)l_212) >= l_213), l_214, (*l_214)) >= p_65)) < 0xA04E1165L)), g_83[5], &l_191, l_215) == g_83[0]) % (int)g_86))) || (*l_214)) - (signed char)g_91);
            step_hash(99);
            (*l_216) = (void*)0;
        }
    }
    step_hash(163);
    for (g_81 = 22; (g_81 <= (-29)); g_81 -= 4)
    {
        short l_223 = 0L;
        int **l_226 = (void*)0;
        int *l_229 = (void*)0;
        int l_236 = (-1L);
        int l_300 = 0xAA0C160EL;
        int l_301 = (-4L);
        int l_302 = 0L;
        int l_304 = 0x14E7BC7DL;
        int l_306 = (-1L);
        int l_308 = 0x3CE50976L;
        step_hash(105);
        (*g_117) = func_71(((signed char)g_92[2] % (signed char)((unsigned short)g_81 * (unsigned short)p_65)), ((void*)0 == &p_63), &l_191, p_64);
        step_hash(106);
        if ((*g_117))
            break;
        step_hash(162);
        if ((func_71((l_223 && (p_63 != (func_71(((signed char)((l_226 != &l_192[3]) && (((-1L) & ((unsigned short)(0x4ECCL > (func_71(g_92[1], p_64, &l_191, p_63) & g_83[5])) >> (unsigned short)p_65)) == 0L)) - (signed char)p_64), p_64, l_229, (*l_190)) | 3UL))), g_81, &l_191, p_65) & g_92[4]))
        {
            signed char l_240 = 0x61L;
            int l_245 = 1L;
            int *l_266 = (void*)0;
            unsigned char l_297 = 0x56L;
            int l_299[7];
            int l_305 = 0x5546EA2CL;
            int i;
            for (i = 0; i < 7; i++)
                l_299[i] = 0x47172757L;
            step_hash(157);
            for (p_65 = 5; (p_65 >= (-25)); p_65 -= 1)
            {
                unsigned char l_237[8] = {254UL, 254UL, 255UL, 254UL, 254UL, 255UL, 254UL, 254UL};
                int l_244[5][2] = {{1L, 0xA520F3B2L}, {1L, 0xA520F3B2L}, {1L, 0xA520F3B2L}, {1L, 0xA520F3B2L}, {1L, 0xA520F3B2L}};
                int **l_260 = &l_189;
                unsigned l_310 = 0UL;
                int i, j;
                step_hash(137);
                for (l_193 = 0; (l_193 != 25); l_193 += 8)
                {
                    unsigned l_246 = 1UL;
                    int *l_261 = &g_3;
                    step_hash(123);
                    if ((g_83[3] <= (0xAEC4BBD0L < (&g_144[0] != (void*)0))))
                    {
                        unsigned l_234 = 0x41DB001EL;
                        int l_235 = 0xE1C7F332L;
                        step_hash(115);
                        if (p_65)
                            break;
                        step_hash(116);
                        (*g_117) = l_234;
                        step_hash(117);
                        ++l_237[7];
                    }
                    else
                    {
                        step_hash(119);
                        p_63 &= l_240;
                        step_hash(120);
                        --g_241;
                        step_hash(121);
                        (*g_117) = 0xD45AA9D1L;
                        step_hash(122);
                        --l_246;
                    }
                    step_hash(128);
                    for (g_241 = 0; (g_241 <= 2); g_241 += 1)
                    {
                        step_hash(127);
                        return p_65;
                    }
                    step_hash(136);
                    if ((*g_117))
                    {
                        unsigned short l_249[7][8] = {{0x5D0AL, 0UL, 65535UL, 0xF6C5L, 0UL, 0x94ABL, 0UL, 0xF6C5L}, {0x5D0AL, 0UL, 65535UL, 0xF6C5L, 0UL, 0x94ABL, 0UL, 0xF6C5L}, {0x5D0AL, 0UL, 65535UL, 0xF6C5L, 0UL, 0x94ABL, 0UL, 0xF6C5L}, {0x5D0AL, 0UL, 65535UL, 0xF6C5L, 0UL, 0x94ABL, 0UL, 0xF6C5L}, {0x5D0AL, 0UL, 65535UL, 0xF6C5L, 0UL, 0x94ABL, 0UL, 0xF6C5L}, {0x5D0AL, 0UL, 65535UL, 0xF6C5L, 0UL, 0x94ABL, 0UL, 0xF6C5L}, {0x5D0AL, 0UL, 65535UL, 0xF6C5L, 0UL, 0x94ABL, 0UL, 0xF6C5L}};
                        int i, j;
                        step_hash(130);
                        (*g_117) = func_71(g_94, g_94, &l_244[2][1], p_63);
                        step_hash(131);
                        --l_249[0][1];
                        step_hash(132);
                        (*l_190) = ((5UL > ((((int)(-6L) + (int)((signed char)((signed char)((func_71(((((void*)0 != l_260) >= (l_261 != (void*)0)) > ((short)((((signed char)g_91 >> (signed char)2) == (((-5L) < ((g_83[5] >= g_92[2]) == 0xE13FBB33L)) == 0x77FB83B5L)) != (-2L)) / (short)(-4L))), g_81, &l_245, p_63) | (*l_261)) & p_63) * (signed char)8UL) << (signed char)3)) ^ p_65) || 0x2E4BL)) > 0L);
                    }
                    else
                    {
                        step_hash(134);
                        (*l_260) = &l_191;
                        step_hash(135);
                        l_266 = &p_63;
                    }
                }
                step_hash(150);
                for (l_236 = 0; (l_236 >= 17); l_236 += 8)
                {
                    int *l_269 = &l_244[4][1];
                    step_hash(146);
                    for (l_193 = 0; (l_193 <= 8); l_193 += 1)
                    {
                        step_hash(144);
                        (*l_260) = l_269;
                        step_hash(145);
                        (*l_260) = (*l_260);
                    }
                    step_hash(147);
                    (*l_260) = &p_63;
                    step_hash(148);
                    (*l_190) &= (func_71(p_63, (**l_260), &l_191, ((signed char)(g_81 ^ 0xE27EL) + (signed char)((signed char)((signed char)p_65 + (signed char)(!func_71(g_83[5], ((unsigned short)((*l_269) == (g_3 >= g_91)) * (unsigned short)p_65), &l_191, p_64))) << (signed char)g_94))) || p_63);
                    step_hash(149);
                    (**l_260) ^= (p_64 < (*l_269));
                }
                step_hash(156);
                for (g_241 = 0; (g_241 <= 3); g_241++)
                {
                    short l_296 = 1L;
                    int l_298 = 9L;
                    int l_303 = 0L;
                    int l_307 = 3L;
                    int l_309 = 0xBE4C5A7FL;
                    step_hash(154);
                    l_298 = ((unsigned char)((int)(g_94 & (((signed char)g_92[2] << (signed char)((unsigned char)((unsigned short)((unsigned char)func_71(g_241, p_64, &p_63, (+(~((short)((unsigned short)func_71(g_83[5], p_64, &p_63, l_296) - (unsigned short)(*l_190)) + (short)g_3)))) / (unsigned char)0x24L) / (unsigned short)0x10A6L) / (unsigned char)0xDBL)) == (*g_117))) - (int)p_65) - (unsigned char)l_297);
                    step_hash(155);
                    --l_310;
                }
            }
            step_hash(158);
            (*g_117) |= 0x63A026B2L;
            step_hash(159);
            (*l_190) = (g_91 >= ((unsigned short)(*l_190) >> (unsigned short)(((unsigned)((((p_63 || (*g_117)) >= p_65) <= ((((void*)0 == &l_266) >= ((((unsigned short)(((signed char)((unsigned char)(l_325 == &g_144[3]) - (unsigned char)p_64) >> (signed char)0) && 4294967292UL) + (unsigned short)p_64) == p_65) == (***l_325))) >= p_64)) >= 0x382C0D10L) % (unsigned)p_63) & 4294967286UL)));
        }
        else
        {
            int l_326 = 0x99902EABL;
            step_hash(161);
            return l_326;
        }
    }
    step_hash(263);
    for (g_81 = 0; (g_81 < (-19)); --g_81)
    {
        unsigned short l_333 = 1UL;
        int **l_334[7][8] = {{&g_117, &l_192[2], &l_192[3], &l_192[3], &l_192[2], &g_117, &l_192[2], &l_192[3]}, {&g_117, &l_192[2], &l_192[3], &l_192[3], &l_192[2], &g_117, &l_192[2], &l_192[3]}, {&g_117, &l_192[2], &l_192[3], &l_192[3], &l_192[2], &g_117, &l_192[2], &l_192[3]}, {&g_117, &l_192[2], &l_192[3], &l_192[3], &l_192[2], &g_117, &l_192[2], &l_192[3]}, {&g_117, &l_192[2], &l_192[3], &l_192[3], &l_192[2], &g_117, &l_192[2], &l_192[3]}, {&g_117, &l_192[2], &l_192[3], &l_192[3], &l_192[2], &g_117, &l_192[2], &l_192[3]}, {&g_117, &l_192[2], &l_192[3], &l_192[3], &l_192[2], &g_117, &l_192[2], &l_192[3]}};
        int *l_363 = &g_86;
        int ***l_374 = &l_334[5][0];
        int *l_399 = &g_83[5];
        signed char l_401 = 0x93L;
        short l_436 = 5L;
        int i, j;
        step_hash(262);
        if ((((unsigned char)(65531UL & (((short)l_333 << (short)12) ^ g_3)) << (unsigned char)0) ^ (l_334[5][0] == (void*)0)))
        {
            int *l_342 = &g_3;
            int l_346[1][9] = {{0x15E5B6B0L, 0x15E5B6B0L, 0xDB74E478L, 0x15E5B6B0L, 0x15E5B6B0L, 0xDB74E478L, 0x15E5B6B0L, 0x15E5B6B0L, 0xDB74E478L}};
            signed char l_348[4] = {6L, 0x93L, 6L, 0x93L};
            int *l_372 = &g_86;
            int ***l_373[1];
            int i, j;
            for (i = 0; i < 1; i++)
                l_373[i] = &g_144[3];
            step_hash(168);
            (*g_117) = p_63;
            step_hash(223);
            for (l_333 = 0; (l_333 <= 6); l_333 += 1)
            {
                int *l_339 = &g_83[6];
                int l_344 = 0x4F9FACA5L;
                int l_345 = 0L;
                int l_349 = 0x600C539AL;
                unsigned short l_351 = 65532UL;
                int *l_354 = &g_86;
                step_hash(190);
                if ((*g_117))
                {
                    step_hash(173);
                    (**l_325) = &p_63;
                }
                else
                {
                    unsigned l_341 = 4294967295UL;
                    step_hash(181);
                    for (g_91 = 0; (g_91 <= 6); g_91 += 1)
                    {
                        signed char l_340 = 3L;
                        step_hash(178);
                        (**l_325) = &p_63;
                        step_hash(179);
                        (*l_190) = (~0x69557001L);
                        step_hash(180);
                        p_63 = (((unsigned char)(1UL <= g_83[5]) + (unsigned char)((signed char)(func_71(g_83[5], (&g_144[3] == (void*)0), l_339, (*g_117)) ^ (0x343D5BD6L > l_340)) * (signed char)0xA9L)) | (*l_339));
                    }
                    step_hash(189);
                    for (l_215 = 0; (l_215 <= 5); l_215 += 1)
                    {
                        int i, j;
                        step_hash(185);
                        (**l_325) = &p_63;
                        step_hash(186);
                        if (g_92[l_215])
                            break;
                        step_hash(187);
                        (*l_190) = g_92[l_215];
                        step_hash(188);
                        l_341 = 0xD081BB5CL;
                    }
                }
                step_hash(202);
                for (p_64 = 6; (p_64 >= 0); p_64 -= 1)
                {
                    int l_343 = (-6L);
                    step_hash(194);
                    (**l_325) = l_342;
                    step_hash(201);
                    if (p_65)
                    {
                        step_hash(196);
                        if (l_343)
                            break;
                        step_hash(197);
                        (**l_325) = &p_63;
                        step_hash(198);
                        l_343 = p_63;
                    }
                    else
                    {
                        step_hash(200);
                        (**l_325) = &p_63;
                    }
                }
            }
            step_hash(246);
            if ((***l_325))
            {
                int l_402 = 6L;
                int l_403 = 1L;
                unsigned l_411 = 4294967288UL;
                int *l_420 = &l_403;
                step_hash(236);
                if ((((g_94 | l_401) || (p_65 || p_65)) > l_402))
                {
                    step_hash(226);
                    if (p_63)
                        break;
                }
                else
                {
                    int *l_410[1][8];
                    int i, j;
                    for (i = 0; i < 1; i++)
                    {
                        for (j = 0; j < 8; j++)
                            l_410[i][j] = &l_346[0][5];
                    }
                    step_hash(228);
                    p_63 = ((void*)0 == (**l_374));
                    step_hash(235);
                    if ((&p_63 != &p_63))
                    {
                        step_hash(230);
                        return g_81;
                    }
                    else
                    {
                        int l_412 = 6L;
                        step_hash(232);
                        (*l_190) = (p_63 || ((((g_83[3] != 0xDFL) & func_71(((l_403 >= p_65) <= 0x7DFC97EEL), ((unsigned char)((signed char)((unsigned short)(!p_64) * (unsigned short)p_65) + (signed char)0x32L) >> (unsigned char)p_65), l_410[0][6], l_411)) && g_3) < l_412));
                        step_hash(233);
                        l_402 = l_403;
                        step_hash(234);
                        p_63 = ((signed char)((void*)0 == l_410[0][3]) >> (signed char)p_65);
                    }
                }
                step_hash(242);
                if (((!g_241) && (!(+((void*)0 != (*l_374))))))
                {
                    step_hash(238);
                    p_63 |= (-1L);
                }
                else
                {
                    unsigned char l_419 = 0x02L;
                    step_hash(240);
                    (*l_420) = (((unsigned short)func_71(l_419, (*l_190), l_420, p_65) + (unsigned short)((unsigned short)((unsigned char)(((func_71((((short)g_241 * (short)func_71(((int)(((*l_342) && ((short)func_71(((((p_65 && func_71(func_71(g_91, p_65, (**l_374), (*l_190)), p_65, &l_403, l_431[2])) == p_63) && g_83[5]) > (*l_420)), g_94, (**l_325), p_64) + (short)p_63)) < (*l_420)) - (int)4294967295UL), g_3, (**l_325), p_64)) >= 249UL), g_241, &l_403, p_64) > l_419) < p_63) && (*l_420)) % (unsigned char)248UL) / (unsigned short)g_83[6])) > p_65);
                    step_hash(241);
                    (*l_363) = p_63;
                }
            }
            else
            {
                step_hash(244);
                (*l_399) = p_65;
                step_hash(245);
                for (p_63 = 0; p_63 < 4; p_63 += 1)
                {
                    l_431[p_63] = 0x5924FA6CL;
                }
            }
            step_hash(247);
            return p_64;
        }
        else
        {
            int l_443 = 0L;
            int *l_444 = &g_3;
            step_hash(249);
            (*l_399) |= ((signed char)g_81 / (signed char)(***l_325));
            step_hash(260);
            if ((*l_190))
            {
                step_hash(251);
                (*g_117) = 0x856B24E4L;
            }
            else
            {
                int ***l_437[8] = {&l_334[5][0], &l_334[6][0], &l_334[5][0], &l_334[6][0], &l_334[5][0], &l_334[6][0], &l_334[5][0], &l_334[6][0]};
                int i;
                step_hash(258);
                if (((func_71(g_241, (-(unsigned char)g_81), &p_63, (-(signed char)l_436)) | (-3L)) == (&g_144[3] == l_437[0])))
                {
                    step_hash(254);
                    p_63 = p_63;
                    step_hash(255);
                    (**l_374) = &p_63;
                }
                else
                {
                    signed char l_438 = 0x1BL;
                    step_hash(257);
                    (*l_363) ^= (((*l_374) != (*l_374)) | l_438);
                }
                step_hash(259);
                (*l_399) &= ((unsigned)(((unsigned)func_71(g_3, l_443, &p_63, p_63) % (unsigned)l_443) < func_71(p_63, g_92[4], l_444, (*g_117))) % (unsigned)(*l_444));
            }
            step_hash(261);
            return p_65;
        }
    }
    step_hash(264);
    return g_83[0];
}







static unsigned short func_71(short p_72, signed char p_73, int * p_74, int p_75)
{
    step_hash(84);
    return p_75;
}







static short func_78(int * p_79)
{
    unsigned l_82[6];
    int l_90 = 1L;
    int l_93 = 1L;
    short l_105 = 0L;
    unsigned l_131 = 0xA5AE12EAL;
    int i;
    for (i = 0; i < 6; i++)
        l_82[i] = 0UL;
    step_hash(12);
    g_81 = 8L;
    step_hash(81);
    for (g_81 = 1; (g_81 <= 5); g_81 += 1)
    {
        int l_87 = (-7L);
        int l_88 = 1L;
        int l_89[7] = {0x3BC0E3E0L, 0x3BC0E3E0L, (-6L), 0x3BC0E3E0L, 0x3BC0E3E0L, (-6L), 0x3BC0E3E0L};
        unsigned l_112 = 0UL;
        int l_127 = 0xDBB176A9L;
        int i;
        step_hash(21);
        for (g_83[5] = 0; (g_83[5] <= 5); g_83[5] += 1)
        {
            int *l_84 = (void*)0;
            int *l_85[6][6] = {{&g_86, (void*)0, &g_86, (void*)0, &g_86, (void*)0}, {&g_86, (void*)0, &g_86, (void*)0, &g_86, (void*)0}, {&g_86, (void*)0, &g_86, (void*)0, &g_86, (void*)0}, {&g_86, (void*)0, &g_86, (void*)0, &g_86, (void*)0}, {&g_86, (void*)0, &g_86, (void*)0, &g_86, (void*)0}, {&g_86, (void*)0, &g_86, (void*)0, &g_86, (void*)0}};
            int i, j;
            step_hash(19);
            g_86 = l_82[g_81];
            step_hash(20);
            g_94++;
        }
        step_hash(22);
        if (l_82[g_81])
            continue;
    }
    step_hash(82);
    return l_93;
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_81, "g_81", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_83[i], "g_83[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_86, "g_86", print_hash_value);
    transparent_crc(g_91, "g_91", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_92[i], "g_92[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_94, "g_94", print_hash_value);
    transparent_crc(g_241, "g_241", print_hash_value);
    transparent_crc(g_475, "g_475", print_hash_value);
    transparent_crc(g_487, "g_487", print_hash_value);
    transparent_crc(g_525, "g_525", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(g_595[i][j], "g_595[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_1070, "g_1070", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_1122[i], "g_1122[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_1142, "g_1142", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 4; j++)
        {
            transparent_crc(g_1152[i][j], "g_1152[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_1156, "g_1156", print_hash_value);
    transparent_crc(g_1262, "g_1262", print_hash_value);
    transparent_crc(g_1359, "g_1359", print_hash_value);
    transparent_crc(g_1398, "g_1398", print_hash_value);
    transparent_crc(g_1585, "g_1585", print_hash_value);
    transparent_crc(g_1703, "g_1703", print_hash_value);
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
