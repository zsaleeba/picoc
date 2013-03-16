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
static unsigned g_4 = 4294967295UL;
static int g_49[1][9] = {{0xDA7DA9FCL, (-1L), 0xDA7DA9FCL, (-1L), 0xDA7DA9FCL, (-1L), 0xDA7DA9FCL, (-1L), 0xDA7DA9FCL}};
static int g_74 = (-1L);
static int g_102 = 1L;
static unsigned char g_137 = 0UL;
static short g_152 = 0L;
static int g_175[9] = {0x2668A2AEL, 0x8BBEDE7EL, 0x2668A2AEL, 0x8BBEDE7EL, 0x2668A2AEL, 0x8BBEDE7EL, 0x2668A2AEL, 0x8BBEDE7EL, 0x2668A2AEL};
static int *g_205[9] = {&g_102, (void*)0, &g_102, (void*)0, &g_102, (void*)0, &g_102, (void*)0, &g_102};
static int **g_204 = &g_205[7];
static signed char g_274 = (-1L);
static short g_276 = 0x36D0L;
static unsigned char g_281 = 0xE4L;
static int g_371 = 1L;
static unsigned char g_426 = 0xF4L;
static int g_476 = 0xCD6301DFL;
static unsigned g_525 = 0x46235F77L;
static unsigned char g_722 = 0x6AL;
static signed char g_768 = 0xEAL;
static signed char g_817 = 1L;
static unsigned char g_881 = 1UL;
static short g_1035 = 1L;
static int g_1037 = 0L;
static unsigned g_1061 = 1UL;
static unsigned g_1164 = 0xDAE71126L;
static signed char g_1259 = 0x87L;
static int g_1283 = (-1L);
static unsigned g_1295 = 0x8B0FDABCL;
static int g_1307 = 0xDA66759FL;
static int g_1313 = (-8L);
static int func_1(void);
static unsigned func_5(unsigned p_6, unsigned p_7);
static unsigned short func_14(signed char p_15, unsigned p_16, unsigned p_17, unsigned p_18, unsigned p_19);
static unsigned char func_24(unsigned p_25);
static int func_31(short p_32);
static int * func_52(unsigned p_53, unsigned char p_54);
static int func_59(int * p_60, signed char p_61, unsigned short p_62, short p_63, int * p_64);
static short func_65(unsigned short p_66, short p_67, int * p_68, int p_69);
static int * func_70(int * p_71);
static int * func_77(unsigned p_78, int * p_79, unsigned p_80, int p_81);
static int func_1(void)
{
    short l_8 = 0x3E31L;
    unsigned l_9[10][2] = {{0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}, {0x23371247L, 0xDB2BC40EL}};
    int l_1286[2];
    short l_1312 = 0x64C7L;
    int i, j;
    for (i = 0; i < 2; i++)
        l_1286[i] = 8L;
    step_hash(758);
    if (((unsigned short)(0xBA394643L > (g_4 < (func_5(l_8, g_4) >= l_8))) << (unsigned short)4))
    {
        unsigned short l_26 = 1UL;
        int *l_1306 = &g_1307;
        step_hash(754);
        (*l_1306) |= (l_9[6][1] || (((((unsigned)((unsigned short)g_4 + (unsigned short)func_14(g_4, g_4, g_4, (((((signed char)((unsigned char)func_24(((l_26 & func_5((((signed char)(((unsigned short)0x4225L % (unsigned short)g_4) ^ ((g_4 > l_26) || g_4)) >> (signed char)g_4) && 0UL), l_8)) || 0xB45BEAC3L)) % (unsigned char)l_26) >> (signed char)5) & 65531UL) <= l_1286[1]) & l_1286[1]), g_881)) % (unsigned)l_1286[1]) | l_26) < g_4) >= (-1L)));
        step_hash(755);
        return (*l_1306);
    }
    else
    {
        unsigned short l_1308[7][3] = {{0xA6D6L, 65528UL, 0UL}, {0xA6D6L, 65528UL, 0UL}, {0xA6D6L, 65528UL, 0UL}, {0xA6D6L, 65528UL, 0UL}, {0xA6D6L, 65528UL, 0UL}, {0xA6D6L, 65528UL, 0UL}, {0xA6D6L, 65528UL, 0UL}};
        int *l_1309 = &g_1307;
        int i, j;
        step_hash(757);
        (*g_204) = (*g_204);
    }
    step_hash(759);
    return l_9[6][1];
}
static unsigned func_5(unsigned p_6, unsigned p_7)
{
    step_hash(2);
    return g_4;
}
static unsigned short func_14(signed char p_15, unsigned p_16, unsigned p_17, unsigned p_18, unsigned p_19)
{
    int ***l_1287 = &g_204;
    int *l_1288 = &g_175[7];
    int **l_1293 = &l_1288;
    int *l_1294[4][10] = {{&g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8]}, {&g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8]}, {&g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8]}, {&g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][8]}};
    int i, j;
    step_hash(744);
    (*l_1293) = l_1288;
    step_hash(745);
    g_1295 |= ((&l_1288 != (void*)0) && (**l_1293));
    step_hash(752);
    for (p_16 = 2; (p_16 <= 8); p_16 += 1)
    {
        short l_1303[4] = {0x746FL, 1L, 0x746FL, 1L};
        unsigned short l_1304 = 0UL;
        int l_1305 = 0x2B2A99B9L;
        int i;
        step_hash(749);
        (**l_1293) &= p_15;
        step_hash(750);
        g_205[p_16] = &g_476;
        step_hash(751);
        l_1305 ^= ((signed char)(g_281 != (((short)((signed char)p_19 - (signed char)((void*)0 != &l_1293)) >> (short)p_17) || ((0UL != (-(signed char)((l_1303[3] < p_15) <= func_5(l_1304, p_15)))) ^ g_525))) - (signed char)g_175[1]);
    }
    step_hash(753);
    return g_281;
}
static unsigned char func_24(unsigned p_25)
{
    unsigned l_45[2];
    int l_46 = 0x5296947AL;
    unsigned l_47 = 1UL;
    int *l_1282 = &g_1283;
    int **l_1284 = (void*)0;
    int **l_1285 = &l_1282;
    int i;
    for (i = 0; i < 2; i++)
        l_45[i] = 1UL;
    step_hash(739);
    (*l_1282) ^= func_31(((0xA34071E9L <= 0UL) <= ((int)((unsigned char)p_25 >> (unsigned char)(((unsigned)((((((short)((unsigned)(((short)func_5(g_4, g_4) * (short)func_5(l_45[0], p_25)) == l_46) - (unsigned)l_45[1]) >> (short)13) || p_25) != g_4) > l_47) != p_25) + (unsigned)p_25) != p_25)) + (int)0x26B4FF51L)));
    step_hash(740);
    (*l_1282) = (-3L);
    step_hash(741);
    (*l_1285) = &l_46;
    step_hash(742);
    return p_25;
}







static int func_31(short p_32)
{
    unsigned short l_953 = 65530UL;
    int l_977 = (-1L);
    unsigned l_978 = 0xE45E55B5L;
    int l_981 = 2L;
    int l_983 = 0x8AD69D4DL;
    int l_985 = 0xE3F3B9A0L;
    int l_986[9][6] = {{0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}, {0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}, {0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}, {0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}, {0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}, {0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}, {0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}, {0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}, {0xBB960DA5L, 0L, 0xE0C51D04L, (-5L), (-5L), 0xE0C51D04L}};
    unsigned short l_990 = 0xA4AFL;
    unsigned short l_1010 = 0xB3CEL;
    signed char l_1036 = 0xE3L;
    int l_1049[3];
    short l_1132 = 0xB773L;
    int ***l_1169 = &g_204;
    unsigned l_1176 = 0UL;
    unsigned short l_1205 = 9UL;
    int l_1249 = (-7L);
    unsigned l_1261 = 0UL;
    int *l_1281 = &g_175[6];
    int i, j;
    for (i = 0; i < 3; i++)
        l_1049[i] = 0x1D3028DEL;
    step_hash(737);
    if ((p_32 & (p_32 && g_4)))
    {
        int *l_48 = &g_49[0][8];
        step_hash(7);
        (*l_48) ^= 0x93C34F97L;
        step_hash(554);
        for (p_32 = 0; (p_32 == 17); p_32 += 1)
        {
            signed char l_55 = 0L;
            step_hash(552);
            (*g_204) = func_52(p_32, l_55);
            step_hash(553);
            l_953++;
        }
    }
    else
    {
        int l_958 = (-1L);
        int l_964 = (-1L);
        int l_975 = 0L;
        int l_976 = (-10L);
        short l_982 = (-1L);
        int l_984 = 0x2E36DFE0L;
        int l_987 = 0x4F0DEC1BL;
        int l_988 = 0x00CE6BF4L;
        int l_989[3][2] = {{(-10L), 7L}, {(-10L), 7L}, {(-10L), 7L}};
        int *l_999 = (void*)0;
        int l_1006 = 0xF4318063L;
        int **l_1055 = &g_205[5];
        short l_1060[6][6] = {{0x86D8L, 0x477AL, 0x86D8L, 0x477AL, 0x86D8L, 0x477AL}, {0x86D8L, 0x477AL, 0x86D8L, 0x477AL, 0x86D8L, 0x477AL}, {0x86D8L, 0x477AL, 0x86D8L, 0x477AL, 0x86D8L, 0x477AL}, {0x86D8L, 0x477AL, 0x86D8L, 0x477AL, 0x86D8L, 0x477AL}, {0x86D8L, 0x477AL, 0x86D8L, 0x477AL, 0x86D8L, 0x477AL}, {0x86D8L, 0x477AL, 0x86D8L, 0x477AL, 0x86D8L, 0x477AL}};
        int *l_1064[8];
        short l_1080 = 0x0AB7L;
        unsigned short l_1104 = 65535UL;
        int l_1122 = (-1L);
        unsigned l_1194[7] = {0UL, 4294967290UL, 0UL, 4294967290UL, 0UL, 4294967290UL, 0UL};
        int l_1234 = 0x35CF6B0FL;
        short l_1268 = (-1L);
        int i, j;
        for (i = 0; i < 8; i++)
            l_1064[i] = (void*)0;
        step_hash(586);
        for (g_371 = 0; (g_371 != (-17)); g_371--)
        {
            int *l_959 = &g_102;
            int *l_960 = &g_74;
            int *l_961 = &g_102;
            int *l_962 = &g_175[0];
            int *l_963 = &g_74;
            int *l_965 = (void*)0;
            int l_966 = 0x19642840L;
            int *l_967 = &g_102;
            int *l_968 = (void*)0;
            int *l_969 = &g_175[8];
            int *l_970 = &g_175[7];
            int *l_971 = &g_49[0][8];
            int *l_972 = &g_49[0][8];
            int *l_973 = (void*)0;
            int *l_974[2][7];
            int i, j;
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < 7; j++)
                    l_974[i][j] = &l_964;
            }
            step_hash(559);
            l_978--;
            step_hash(560);
            ++l_990;
            step_hash(585);
            for (l_988 = 5; (l_988 >= 0); l_988 -= 1)
            {
                unsigned char l_1007 = 246UL;
                int *l_1013 = &l_981;
                unsigned l_1018 = 0x154304B4L;
                unsigned l_1023 = 0x3D2A7710L;
                int i, j;
                step_hash(583);
                if ((((int)((unsigned)((((unsigned short)65535UL - (unsigned short)l_986[(l_988 + 1)][l_988]) ^ (p_32 ^ 0xDE89B7DFL)) > 0xA1L) - (unsigned)l_1007) % (int)l_986[(l_988 + 1)][l_988]) & g_276))
                {
                    unsigned l_1008 = 4294967295UL;
                    int l_1009 = 0x6724A2A5L;
                    step_hash(565);
                    for (l_1007 = 0; l_1007 < 2; l_1007 += 1)
                    {
                        for (g_137 = 0; g_137 < 7; g_137 += 1)
                        {
                            l_974[l_1007][g_137] = (void*)0;
                        }
                    }
                    step_hash(572);
                    if ((p_32 != (((&l_964 != (void*)0) > l_1008) == (*l_961))))
                    {
                        step_hash(567);
                        return (*l_969);
                    }
                    else
                    {
                        int i, j;
                        step_hash(569);
                        if (p_32)
                            break;
                        step_hash(570);
                        if (p_32)
                            break;
                        step_hash(571);
                        --l_1010;
                    }
                    step_hash(573);
                    l_1013 = (*g_204);
                }
                else
                {
                    int l_1022 = 0xB13A2D03L;
                    int **l_1034 = &l_972;
                    step_hash(575);
                    (*l_959) = ((unsigned char)func_5(func_5(((void*)0 != &l_986[8][3]), (((unsigned char)l_1018 * (unsigned char)0xEFL) & (*l_1013))), g_768) >> (unsigned char)2);
                    step_hash(581);
                    for (l_985 = 0; (l_985 > 11); l_985 += 9)
                    {
                        signed char l_1021 = 0x35L;
                        step_hash(579);
                        l_1023--;
                        step_hash(580);
                        g_1037 |= ((unsigned short)l_1022 + (unsigned short)func_65((((p_32 == (((((short)((signed char)1L + (signed char)(func_5((p_32 == (*l_1013)), ((unsigned short)(g_722 == (l_1034 != &l_999)) / (unsigned short)0xACC7L)) | l_986[0][3])) << (short)g_1035) >= g_175[7]) | 247UL) | 1UL)) >= g_137) != p_32), p_32, &l_976, l_1036));
                    }
                    step_hash(582);
                    (*l_967) = (g_371 == 0xB9L);
                }
                step_hash(584);
                return p_32;
            }
        }
        step_hash(736);
        if (p_32)
        {
            signed char l_1046 = 0x01L;
            int l_1047 = (-1L);
            int l_1048[4][7] = {{0x418AD974L, 4L, 0x8C773E95L, 7L, 7L, 0x8C773E95L, 4L}, {0x418AD974L, 4L, 0x8C773E95L, 7L, 7L, 0x8C773E95L, 4L}, {0x418AD974L, 4L, 0x8C773E95L, 7L, 7L, 0x8C773E95L, 4L}, {0x418AD974L, 4L, 0x8C773E95L, 7L, 7L, 0x8C773E95L, 4L}};
            unsigned char l_1050[9] = {0x0DL, 6UL, 0x0DL, 6UL, 0x0DL, 6UL, 0x0DL, 6UL, 0x0DL};
            int **l_1065[6][8] = {{&l_999, &l_999, (void*)0, &l_999, &l_999, (void*)0, &l_999, &l_999}, {&l_999, &l_999, (void*)0, &l_999, &l_999, (void*)0, &l_999, &l_999}, {&l_999, &l_999, (void*)0, &l_999, &l_999, (void*)0, &l_999, &l_999}, {&l_999, &l_999, (void*)0, &l_999, &l_999, (void*)0, &l_999, &l_999}, {&l_999, &l_999, (void*)0, &l_999, &l_999, (void*)0, &l_999, &l_999}, {&l_999, &l_999, (void*)0, &l_999, &l_999, (void*)0, &l_999, &l_999}};
            unsigned l_1079 = 0x706C4E9DL;
            int l_1083 = 0xB8F53A9BL;
            int l_1100 = 4L;
            int i, j;
            step_hash(633);
            if (p_32)
            {
                int l_1038 = (-1L);
                int *l_1039 = &g_49[0][8];
                int *l_1040 = &l_986[3][2];
                int *l_1041 = &g_1037;
                int *l_1042 = (void*)0;
                int *l_1043 = &l_989[1][0];
                int *l_1044 = &g_49[0][3];
                int *l_1045[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_1045[i] = &l_964;
                step_hash(589);
                l_1050[4]--;
                step_hash(590);
                (*l_1041) = ((unsigned char)253UL * (unsigned char)(((l_1045[5] == (void*)0) <= g_49[0][8]) >= ((l_1055 == &l_999) > l_953)));
                step_hash(597);
                for (l_1038 = 0; (l_1038 <= (-22)); l_1038--)
                {
                    int l_1058[3];
                    int l_1059[7] = {0x5860123AL, 0x5860123AL, 0x122B95B8L, 0x5860123AL, 0x5860123AL, 0x122B95B8L, 0x5860123AL};
                    int i;
                    for (i = 0; i < 3; i++)
                        l_1058[i] = 0x733EA963L;
                    step_hash(594);
                    --g_1061;
                    step_hash(595);
                    (*l_1044) = func_65((*l_1041), l_1050[4], func_70(l_1064[0]), (func_5(g_49[0][8], (l_1065[0][6] == &l_1039)) || (0x8D2CL == 65535UL)));
                    step_hash(596);
                    return p_32;
                }
            }
            else
            {
                int *l_1072 = &g_49[0][5];
                int ***l_1086 = (void*)0;
                unsigned l_1097 = 0UL;
                step_hash(599);
                l_1049[0] &= p_32;
                step_hash(600);
                g_1037 ^= (((int)((signed char)((unsigned)(func_59(l_1072, (&l_1064[6] == &l_1072), ((int)p_32 / (int)(-6L)), g_881, &l_1049[0]) && p_32) - (unsigned)p_32) * (signed char)g_175[5]) - (int)2L) == p_32);
                step_hash(616);
                if (((+((signed char)((((unsigned char)(l_1079 <= (func_5(g_152, p_32) == l_1080)) - (unsigned char)((((g_426 | ((short)0x4105L / (short)(g_1035 | (p_32 || p_32)))) >= l_1083) ^ p_32) != 0x3949326CL)) <= p_32) <= 0x6D60L) >> (signed char)p_32)) ^ 4L))
                {
                    step_hash(606);
                    for (l_1083 = 19; (l_1083 == 4); --l_1083)
                    {
                        step_hash(605);
                        return p_32;
                    }
                }
                else
                {
                    int *l_1096 = &l_1047;
                    step_hash(613);
                    if ((&l_1055 == l_1086))
                    {
                        step_hash(609);
                        return p_32;
                    }
                    else
                    {
                        int ***l_1091[7] = {&l_1065[0][6], &l_1065[0][6], &l_1065[0][6], &l_1065[0][6], &l_1065[0][6], &l_1065[0][6], &l_1065[0][6]};
                        int i;
                        step_hash(611);
                        l_986[0][1] &= p_32;
                        step_hash(612);
                        (*l_1096) ^= ((unsigned char)p_32 - (unsigned char)(((signed char)(((&g_204 != l_1091[0]) == ((short)((unsigned)(p_32 || p_32) - (unsigned)p_32) / (short)0x6A35L)) && l_977) / (signed char)p_32) < 6L));
                    }
                    step_hash(614);
                    ++l_1097;
                    step_hash(615);
                    return l_1100;
                }
                step_hash(632);
                for (l_985 = 5; (l_985 >= 0); l_985 -= 1)
                {
                    unsigned l_1103 = 0x6014BD46L;
                    step_hash(624);
                    for (l_988 = 0; (l_988 >= 0); l_988 -= 1)
                    {
                        int i, j;
                        step_hash(623);
                        g_49[l_988][(l_988 + 6)] &= p_32;
                    }
                    step_hash(631);
                    if (((unsigned)((*l_1072) > (g_102 < ((void*)0 == &l_999))) % (unsigned)g_768))
                    {
                        step_hash(626);
                        (*l_1055) = (*l_1055);
                        step_hash(627);
                        if (l_953)
                            break;
                        step_hash(628);
                        return p_32;
                    }
                    else
                    {
                        step_hash(630);
                        return p_32;
                    }
                }
            }
            step_hash(634);
            (*l_1055) = (*l_1055);
            step_hash(635);
            l_1049[0] = 0xDF5775CBL;
            step_hash(636);
            ++l_1104;
        }
        else
        {
            unsigned l_1111 = 0x472F4193L;
            int *l_1112 = &g_49[0][8];
            int l_1115[1][10] = {{0xC910B2FEL, (-1L), 0xC910B2FEL, (-1L), 0xC910B2FEL, (-1L), 0xC910B2FEL, (-1L), 0xC910B2FEL, (-1L)}};
            int l_1161 = 0x9DDDD402L;
            int l_1185 = 0x5375133AL;
            int *l_1204 = &l_986[0][1];
            int l_1269[1];
            unsigned short l_1270 = 0x730FL;
            int i, j;
            for (i = 0; i < 1; i++)
                l_1269[i] = 7L;
            step_hash(692);
            if ((!((unsigned short)((signed char)func_59(l_1112, l_981, (*l_1112), func_5(((g_276 > 0xD954L) || 0x44A40EC2L), l_1049[0]), l_1112) % (signed char)l_985) + (unsigned short)p_32)))
            {
                int l_1113 = (-8L);
                int l_1114 = 1L;
                int l_1116 = 0x683C7407L;
                int l_1117 = 1L;
                int l_1118 = 0xBF4173BDL;
                int l_1119 = 0xE817E0B2L;
                int l_1120 = 0x11206265L;
                int l_1121[6][1] = {{(-10L)}, {(-10L)}, {(-10L)}, {(-10L)}, {(-10L)}, {(-10L)}};
                unsigned l_1123 = 9UL;
                unsigned l_1141 = 1UL;
                int i, j;
                step_hash(639);
                --l_1123;
                step_hash(645);
                for (g_1035 = 0; (g_1035 <= 0); g_1035 += 1)
                {
                    unsigned short l_1135 = 65533UL;
                    signed char l_1136 = 1L;
                    int l_1137 = 7L;
                    step_hash(643);
                    l_1137 = ((int)0x5A3115DEL - (int)(l_1136 || l_1117));
                    step_hash(644);
                    return p_32;
                }
                step_hash(651);
                for (g_276 = (-5); (g_276 != (-2)); g_276 += 1)
                {
                    int **l_1140[3];
                    int i;
                    for (i = 0; i < 3; i++)
                        l_1140[i] = &g_205[4];
                    step_hash(649);
                    (*l_1112) &= l_1141;
                    step_hash(650);
                    (*l_1112) = ((g_276 == 2UL) && ((*l_1112) && p_32));
                }
                step_hash(669);
                for (l_977 = 0; (l_977 == (-17)); l_977 -= 5)
                {
                    int l_1148[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_1148[i] = (-1L);
                    step_hash(661);
                    for (l_958 = 0; (l_958 <= 2); l_958 += 1)
                    {
                        int i;
                        step_hash(658);
                        (*l_1112) |= (l_1049[l_958] | g_281);
                        step_hash(659);
                        (*l_1112) ^= l_1148[0];
                        step_hash(660);
                        return p_32;
                    }
                    step_hash(662);
                    (*l_1112) = 0xD4A795E8L;
                    step_hash(668);
                    for (l_1114 = 0; (l_1114 <= 0); l_1114 += 1)
                    {
                        int i, j;
                        step_hash(666);
                        g_205[l_1114] = &g_1037;
                        step_hash(667);
                        return p_32;
                    }
                }
            }
            else
            {
                unsigned char l_1152 = 0x6DL;
                int l_1177 = 0x8F290536L;
                step_hash(671);
                (*l_1112) = 0x1FCF356DL;
                step_hash(672);
                l_1152--;
                step_hash(690);
                for (g_722 = 0; (g_722 <= 8); g_722 += 1)
                {
                    int l_1182 = 0x34D1C211L;
                    int l_1186 = (-1L);
                    int l_1187 = 0x12F60873L;
                    unsigned l_1188 = 0UL;
                    int i;
                    step_hash(683);
                    if (((unsigned)((l_1152 == 1UL) == (&g_205[g_722] != &l_1112)) / (unsigned)((signed char)p_32 - (signed char)((unsigned short)g_817 + (unsigned short)0x4A0EL))))
                    {
                        int l_1167 = (-1L);
                        int l_1168 = 0xE25A87B6L;
                        int i;
                        step_hash(677);
                        (*l_1112) |= p_32;
                        step_hash(678);
                        l_1168 ^= ((int)l_1167 / (int)0x7C5E8B64L);
                        step_hash(679);
                        (*l_1112) = p_32;
                        step_hash(680);
                        g_205[g_722] = (void*)0;
                    }
                    else
                    {
                        int *l_1180 = (void*)0;
                        step_hash(682);
                        (*l_1112) = ((l_1169 != (void*)0) <= p_32);
                    }
                    step_hash(688);
                    for (g_74 = 5; (g_74 >= 0); g_74 -= 1)
                    {
                        int l_1181 = 7L;
                        int l_1183 = 0xCF08F72FL;
                        int l_1184[8];
                        int i, j;
                        for (i = 0; i < 8; i++)
                            l_1184[i] = 0x00E060AEL;
                        step_hash(687);
                        ++l_1188;
                    }
                    step_hash(689);
                    return (*l_1112);
                }
                step_hash(691);
                (*l_1055) = &g_175[7];
            }
            step_hash(734);
            for (l_987 = 0; (l_987 == 24); ++l_987)
            {
                int *l_1193 = (void*)0;
                int l_1232 = 0L;
                int l_1246 = 1L;
                int l_1248[10][5] = {{0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}, {0x687220D4L, 0x09D6B2C9L, 0x830F1D69L, 0L, (-3L)}};
                int l_1252 = (-4L);
                int i, j;
                step_hash(696);
                (*l_1055) = l_1193;
                step_hash(721);
                if ((((unsigned char)g_4 + (unsigned char)(p_32 < g_4)) <= ((unsigned char)((void*)0 == &l_1115[0][8]) % (unsigned char)(*l_1112))))
                {
                    int *l_1203 = &l_1049[0];
                    step_hash(698);
                    (*l_1112) &= p_32;
                    step_hash(699);
                    (*l_1204) = 0xB58E3E7CL;
                }
                else
                {
                    unsigned char l_1233 = 0xC7L;
                    int **l_1243 = (void*)0;
                    int l_1244 = 0x6D70BEB8L;
                    int l_1245 = 0x2D6F53B6L;
                    int l_1247 = 7L;
                    int l_1250 = 0x670A8041L;
                    int l_1251 = 0x52B4076AL;
                    int l_1253 = 0x87772AB4L;
                    int l_1254 = 0x41990D11L;
                    int l_1255 = 1L;
                    int l_1256 = 0xB15ECCAEL;
                    int l_1257 = 8L;
                    int l_1258[7][4] = {{5L, 5L, 0x5846B21DL, 0xA9F86872L}, {5L, 5L, 0x5846B21DL, 0xA9F86872L}, {5L, 5L, 0x5846B21DL, 0xA9F86872L}, {5L, 5L, 0x5846B21DL, 0xA9F86872L}, {5L, 5L, 0x5846B21DL, 0xA9F86872L}, {5L, 5L, 0x5846B21DL, 0xA9F86872L}, {5L, 5L, 0x5846B21DL, 0xA9F86872L}};
                    short l_1260 = (-9L);
                    int i, j;
                    step_hash(707);
                    for (l_975 = 0; (l_975 < 24); l_975 += 8)
                    {
                        int l_1212 = 0L;
                        step_hash(704);
                        if (p_32)
                            break;
                        step_hash(705);
                        (*l_1112) = (((unsigned char)(((short)l_1212 >> (short)14) != ((unsigned char)(0x931590E5L && (-(int)((int)(-3L) / (int)((unsigned short)((int)(((((short)(p_32 >= ((((((short)p_32 >> (short)8) < ((unsigned char)0xF0L - (unsigned char)((unsigned char)((l_1212 && (!(((int)(*l_1204) + (int)l_1212) && p_32))) >= p_32) >> (unsigned char)4))) ^ (-1L)) == l_1232) ^ p_32)) - (short)g_817) || p_32) < p_32) | g_476) % (int)l_1233) * (unsigned short)0x621AL)))) - (unsigned char)0L)) << (unsigned char)l_1234) > 1UL);
                        step_hash(706);
                        (*l_1055) = &l_1161;
                    }
                    step_hash(708);
                    l_1261--;
                    step_hash(714);
                    for (l_1250 = 4; (l_1250 > 28); ++l_1250)
                    {
                        signed char l_1266[9][3] = {{5L, 0x71L, (-1L)}, {5L, 0x71L, (-1L)}, {5L, 0x71L, (-1L)}, {5L, 0x71L, (-1L)}, {5L, 0x71L, (-1L)}, {5L, 0x71L, (-1L)}, {5L, 0x71L, (-1L)}, {5L, 0x71L, (-1L)}, {5L, 0x71L, (-1L)}};
                        int l_1267[6][3] = {{0L, 0x637279BAL, 0L}, {0L, 0x637279BAL, 0L}, {0L, 0x637279BAL, 0L}, {0L, 0x637279BAL, 0L}, {0L, 0x637279BAL, 0L}, {0L, 0x637279BAL, 0L}};
                        int i, j;
                        step_hash(712);
                        (*l_1204) |= p_32;
                        step_hash(713);
                        l_1270--;
                    }
                    step_hash(720);
                    for (l_978 = 6; (l_978 == 15); ++l_978)
                    {
                        step_hash(718);
                        if (p_32)
                            break;
                        step_hash(719);
                        g_205[8] = &g_49[0][6];
                    }
                }
                step_hash(722);
                if (l_990)
                    continue;
                step_hash(733);
                if (((int)((((unsigned char)((*l_1204) < p_32) / (unsigned char)g_1037) == p_32) && p_32) + (int)p_32))
                {
                    step_hash(724);
                    (*l_1055) = (*l_1055);
                }
                else
                {
                    step_hash(732);
                    for (l_1232 = 0; (l_1232 <= 0); l_1232 += 1)
                    {
                        int i, j;
                        step_hash(729);
                        g_49[l_1232][(l_1232 + 5)] = ((unsigned char)0x41L << (unsigned char)g_49[l_1232][(l_1232 + 2)]);
                        step_hash(730);
                        if (g_175[(l_1232 + 4)])
                            continue;
                        step_hash(731);
                        l_1281 = &g_175[(l_1232 + 7)];
                    }
                }
            }
            step_hash(735);
            return (*l_1281);
        }
    }
    step_hash(738);
    return p_32;
}







static int * func_52(unsigned p_53, unsigned char p_54)
{
    int *l_58 = &g_49[0][6];
    int *l_929 = &g_49[0][8];
    int *l_930 = (void*)0;
    int *l_931 = &g_175[7];
    int *l_932 = (void*)0;
    int *l_933[10][8] = {{&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}, {&g_175[5], &g_49[0][8], &g_49[0][8], &g_49[0][8], &g_49[0][5], (void*)0, &g_102, &g_102}};
    unsigned char l_934 = 0UL;
    unsigned l_952[2][3];
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
            l_952[i][j] = 0x159386EFL;
    }
    step_hash(16);
    for (p_53 = 0; (p_53 <= 2); p_53 += 5)
    {
        step_hash(15);
        return l_58;
    }
    step_hash(548);
    for (p_53 = 0; (p_53 <= 0); p_53 += 1)
    {
        int *l_72 = (void*)0;
        short l_926 = (-4L);
        int l_928 = 0x22A56471L;
    }
    step_hash(549);
    ++l_934;
    step_hash(550);
    (*l_58) = (-(int)(((unsigned short)((unsigned)g_276 / (unsigned)(*l_931)) * (unsigned short)(*l_929)) && ((unsigned char)(((signed char)(((int)p_53 - (int)(g_137 > p_53)) | (((short)(p_53 | p_54) * (short)(((unsigned char)func_65((l_932 == (*g_204)), l_952[0][0], (*g_204), p_54) >> (unsigned char)2) | g_152)) && (*l_931))) * (signed char)(-1L)) && (*l_929)) / (unsigned char)(*l_931))));
    step_hash(551);
    return (*g_204);
}







static int func_59(int * p_60, signed char p_61, unsigned short p_62, short p_63, int * p_64)
{
    int *l_843[4][7] = {{(void*)0, &g_476, (void*)0, &g_476, (void*)0, &g_476, (void*)0}, {(void*)0, &g_476, (void*)0, &g_476, (void*)0, &g_476, (void*)0}, {(void*)0, &g_476, (void*)0, &g_476, (void*)0, &g_476, (void*)0}, {(void*)0, &g_476, (void*)0, &g_476, (void*)0, &g_476, (void*)0}};
    int ***l_850 = (void*)0;
    int i, j;
    step_hash(463);
    (*g_204) = l_843[0][4];
    step_hash(525);
    for (g_102 = 0; (g_102 > (-3)); g_102 -= 3)
    {
        int ***l_846[7] = {&g_204, &g_204, &g_204, &g_204, &g_204, &g_204, &g_204};
        unsigned l_862[10] = {0xA2DA5F1EL, 4294967288UL, 4294967295UL, 4294967295UL, 4294967288UL, 0xA2DA5F1EL, 4294967288UL, 4294967295UL, 4294967295UL, 4294967288UL};
        unsigned short l_868[10][6] = {{65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}, {65527UL, 0x2E06L, 0x229DL, 0x88D9L, 0x64A0L, 0xD69AL}};
        int l_880 = 0x0E15C5B8L;
        unsigned l_922 = 8UL;
        unsigned l_923 = 1UL;
        int i, j;
        step_hash(467);
        g_204 = &p_60;
        step_hash(523);
        for (p_62 = 0; (p_62 > 49); p_62 += 2)
        {
            int ***l_849 = &g_204;
            int l_853[7][10] = {{0x4A04B825L, 4L, 0x7FAE4EFDL, (-1L), 0x732BF405L, 1L, 1L, 0x732BF405L, (-1L), 0x7FAE4EFDL}, {0x4A04B825L, 4L, 0x7FAE4EFDL, (-1L), 0x732BF405L, 1L, 1L, 0x732BF405L, (-1L), 0x7FAE4EFDL}, {0x4A04B825L, 4L, 0x7FAE4EFDL, (-1L), 0x732BF405L, 1L, 1L, 0x732BF405L, (-1L), 0x7FAE4EFDL}, {0x4A04B825L, 4L, 0x7FAE4EFDL, (-1L), 0x732BF405L, 1L, 1L, 0x732BF405L, (-1L), 0x7FAE4EFDL}, {0x4A04B825L, 4L, 0x7FAE4EFDL, (-1L), 0x732BF405L, 1L, 1L, 0x732BF405L, (-1L), 0x7FAE4EFDL}, {0x4A04B825L, 4L, 0x7FAE4EFDL, (-1L), 0x732BF405L, 1L, 1L, 0x732BF405L, (-1L), 0x7FAE4EFDL}, {0x4A04B825L, 4L, 0x7FAE4EFDL, (-1L), 0x732BF405L, 1L, 1L, 0x732BF405L, (-1L), 0x7FAE4EFDL}};
            unsigned char l_865[5] = {255UL, 0x2AL, 255UL, 0x2AL, 255UL};
            unsigned l_899 = 4294967295UL;
            int i, j;
            step_hash(482);
            for (g_525 = 0; (g_525 <= 0); g_525 += 1)
            {
                int i, j;
                step_hash(478);
                for (p_63 = 0; (p_63 <= 6); p_63 += 1)
                {
                    int i, j;
                    step_hash(477);
                    g_49[g_525][(p_63 + 2)] = (((void*)0 == l_846[(g_525 + 2)]) & 0L);
                }
                step_hash(479);
                (**g_204) = func_5((l_849 == l_850), (func_5(g_49[g_525][(g_525 + 3)], p_61) != ((int)l_853[5][8] - (int)g_49[g_525][(g_525 + 3)])));
                step_hash(480);
                if ((*p_60))
                    break;
                step_hash(481);
                if ((**g_204))
                    break;
            }
            step_hash(520);
            for (g_476 = 8; (g_476 >= 0); g_476 -= 1)
            {
                int l_901 = (-1L);
                int i;
            }
            step_hash(521);
            (***l_849) = ((signed char)((unsigned char)p_63 * (unsigned char)((short)((unsigned short)((unsigned)((((signed char)func_5(p_62, g_881) * (signed char)246UL) == (g_768 || (((unsigned char)0x7DL >> (unsigned char)2) < ((short)(g_722 && ((unsigned short)p_63 << (unsigned short)l_922)) * (short)p_63)))) >= (-9L)) / (unsigned)(*p_60)) * (unsigned short)p_61) + (short)g_371)) << (signed char)7);
            step_hash(522);
            if ((***l_849))
                continue;
        }
        step_hash(524);
        return l_923;
    }
    step_hash(530);
    for (g_152 = 14; (g_152 > 17); g_152++)
    {
        step_hash(529);
        (*g_204) = &g_102;
    }
    step_hash(531);
    return (*p_60);
}







static short func_65(unsigned short p_66, short p_67, int * p_68, int p_69)
{
    unsigned short l_785 = 0xC1E0L;
    int l_795 = 0x9F0E0620L;
    int l_798 = 0x3BFEF334L;
    int l_799 = (-9L);
    int l_800 = 0x7DF590FBL;
    int l_801 = (-5L);
    int l_802 = (-1L);
    signed char l_803[9] = {(-1L), (-1L), 4L, (-1L), (-1L), 4L, (-1L), (-1L), 4L};
    int l_804 = (-6L);
    int l_805 = 4L;
    int l_806 = 4L;
    int l_807 = 0x051FD8FEL;
    unsigned l_808 = 0x30C24094L;
    short l_828 = 0L;
    int i;
    step_hash(460);
    for (p_66 = 0; (p_66 == 16); p_66 += 1)
    {
        unsigned char l_784 = 0xBEL;
        int l_796 = 0xF0D3C596L;
        int l_797[9] = {(-1L), (-1L), 3L, (-1L), (-1L), 3L, (-1L), (-1L), 3L};
        int i;
        step_hash(459);
        if (((signed char)(func_5(((p_66 == ((short)(((short)((int)((unsigned char)((unsigned char)func_5(g_102, p_66) + (unsigned char)g_276) - (unsigned char)p_66) / (int)l_784) << (short)13) >= func_5((g_49[0][1] >= g_102), l_785)) * (short)g_476)) >= g_49[0][8]), l_785) || 0x1DD158B9L) + (signed char)l_784))
        {
            int *l_788 = &g_102;
            int *l_789 = &g_175[3];
            int *l_790 = &g_49[0][8];
            int *l_791 = &g_175[7];
            int *l_792 = &g_49[0][8];
            int *l_793 = &g_74;
            int *l_794[2];
            int i;
            for (i = 0; i < 2; i++)
                l_794[i] = (void*)0;
            step_hash(429);
            (*l_788) = ((unsigned)l_785 / (unsigned)(-6L));
            step_hash(430);
            l_808++;
        }
        else
        {
            unsigned l_815 = 0x81B8F4E4L;
            unsigned l_816[2];
            int l_842 = 1L;
            int i;
            for (i = 0; i < 2; i++)
                l_816[i] = 0x5901B339L;
            step_hash(450);
            if ((func_5(l_796, ((l_799 ^ ((&p_68 != &g_205[7]) <= func_5(func_5(((((unsigned short)p_69 >> (unsigned short)((short)g_525 << (short)9)) | l_815) == l_816[1]), g_102), g_426))) == 0UL)) > g_476))
            {
                step_hash(433);
                if (p_69)
                    break;
                step_hash(445);
                if ((g_817 & (p_67 < ((int)((signed char)((signed char)((&p_68 == (void*)0) > ((signed char)(0UL >= p_66) - (signed char)0x40L)) >> (signed char)(((unsigned char)0x9FL / (unsigned char)g_274) || l_816[1])) * (signed char)l_815) % (int)l_828))))
                {
                    step_hash(435);
                    (*g_204) = &g_49[0][8];
                }
                else
                {
                    step_hash(444);
                    for (l_804 = 0; (l_804 <= (-4)); l_804--)
                    {
                        int *l_831 = &l_797[2];
                        step_hash(440);
                        (*l_831) = l_796;
                        step_hash(441);
                        l_798 ^= (((void*)0 != &p_68) >= (((unsigned char)p_67 >> (unsigned char)2) < ((unsigned short)((unsigned)g_74 + (unsigned)(g_817 != l_815)) * (unsigned short)g_49[0][8])));
                        step_hash(442);
                        if (l_816[0])
                            continue;
                        step_hash(443);
                        (*l_831) ^= 0L;
                    }
                }
            }
            else
            {
                int *l_838 = &g_49[0][0];
                step_hash(447);
                (*g_204) = p_68;
                step_hash(448);
                (*l_838) = ((g_152 | (func_5(g_476, p_67) || p_66)) != (p_67 >= 1L));
                step_hash(449);
                (*l_838) |= (-3L);
            }
            step_hash(456);
            for (p_69 = 0; (p_69 > 12); p_69 += 5)
            {
                int *l_841 = (void*)0;
                step_hash(454);
                l_842 &= (g_525 == p_69);
                step_hash(455);
                (*g_204) = p_68;
            }
            step_hash(457);
            (*g_204) = p_68;
            step_hash(458);
            if (l_805)
                break;
        }
    }
    step_hash(461);
    return p_69;
}







static int * func_70(int * p_71)
{
    unsigned char l_73[8] = {0x5FL, 0x5FL, 0xCCL, 0x5FL, 0x5FL, 0xCCL, 0x5FL, 0x5FL};
    int l_552[1];
    unsigned char l_633 = 0UL;
    int **l_647[10] = {&g_205[7], &g_205[7], &g_205[7], &g_205[7], &g_205[7], &g_205[7], &g_205[7], &g_205[7], &g_205[7], &g_205[7]};
    int ***l_655 = (void*)0;
    short l_660 = 0xEDF0L;
    short l_664 = (-1L);
    unsigned short l_701 = 0xA532L;
    unsigned l_706 = 0UL;
    int i;
    for (i = 0; i < 1; i++)
        l_552[i] = 0xF814E8C0L;
    step_hash(421);
    for (g_74 = 7; (g_74 >= 0); g_74 -= 1)
    {
        unsigned l_464 = 0x1A8B8813L;
        unsigned l_467[2][6] = {{4294967295UL, 2UL, 4294967295UL, 2UL, 4294967295UL, 2UL}, {4294967295UL, 2UL, 4294967295UL, 2UL, 4294967295UL, 2UL}};
        int *l_549[6];
        unsigned l_555 = 0xB77D671DL;
        unsigned short l_646 = 1UL;
        int ***l_704 = &l_647[6];
        unsigned l_749 = 0x7BF2DA4FL;
        int i, j;
        for (i = 0; i < 6; i++)
            l_549[i] = &g_175[8];
        step_hash(268);
        if (((signed char)l_73[2] - (signed char)((void*)0 != p_71)))
        {
            unsigned short l_82 = 0x2859L;
            int *l_83 = &g_49[0][2];
            int *l_477 = &g_175[6];
            step_hash(263);
            (*g_204) = func_77(l_82, l_83, ((void*)0 != &g_49[0][2]), l_73[4]);
            step_hash(264);
            (*l_477) = func_5(((unsigned short)((signed char)(l_464 | (&g_205[7] != (void*)0)) << (signed char)(!(0x9952L | (func_5(l_467[1][2], l_73[3]) >= (func_5((+(((unsigned short)((unsigned short)l_464 >> (unsigned short)(((((unsigned short)((short)((&p_71 == &p_71) & 0x04L) - (short)l_464) >> (unsigned short)8) != 0xC100CEB9L) > 1UL) && (*l_83))) << (unsigned short)l_73[7]) > l_464)), (*l_83)) ^ l_467[0][3]))))) << (unsigned short)(*l_83)), g_476);
            step_hash(265);
            return l_83;
        }
        else
        {
            int l_478 = (-1L);
            step_hash(267);
            l_478 = l_478;
        }
        step_hash(420);
        if (l_467[1][4])
        {
            int l_482 = (-4L);
            int l_489 = 4L;
            int l_498 = 6L;
            unsigned l_542 = 4294967286UL;
            int l_587[4][1] = {{1L}, {1L}, {1L}, {1L}};
            int **l_628 = (void*)0;
            int i, j;
            step_hash(284);
            for (g_476 = 7; (g_476 >= 2); g_476 -= 1)
            {
                short l_485 = (-7L);
                step_hash(283);
                if (((l_464 | ((unsigned char)l_73[5] * (unsigned char)0x36L)) <= l_73[4]))
                {
                    int *l_481 = &g_102;
                    step_hash(274);
                    return l_481;
                }
                else
                {
                    step_hash(281);
                    for (g_274 = 7; (g_274 >= 0); g_274 -= 1)
                    {
                        unsigned l_488 = 1UL;
                        step_hash(279);
                        (*g_204) = (*g_204);
                        step_hash(280);
                        l_489 = (l_482 > (0x70A5548BL && ((int)(g_102 || func_5(l_485, ((void*)0 != (*g_204)))) / (int)((unsigned char)l_488 * (unsigned char)(l_485 != 0L)))));
                    }
                    step_hash(282);
                    return (*g_204);
                }
            }
            step_hash(318);
            for (g_426 = 2; (g_426 <= 8); g_426 += 1)
            {
                unsigned l_507 = 0x6838FC12L;
                int l_551[7] = {0x2C148369L, 0x988396F2L, 0x2C148369L, 0x988396F2L, 0x2C148369L, 0x988396F2L, 0x2C148369L};
                int i;
                step_hash(305);
                for (g_152 = 1; (g_152 >= 0); g_152 -= 1)
                {
                    int l_492 = 0L;
                    int l_553 = 0xCB230E7AL;
                    int l_554 = 0xF0FC990BL;
                    int i, j;
                    step_hash(298);
                    for (g_276 = 0; (g_276 <= 8); g_276 += 1)
                    {
                        int *l_490 = &l_489;
                        int *l_491 = &l_489;
                        int *l_493 = &g_476;
                        int *l_494 = &l_489;
                        int *l_495 = &l_489;
                        int *l_496 = &g_175[g_276];
                        int *l_497 = &g_175[g_276];
                        int *l_499 = &l_489;
                        int *l_500 = &l_489;
                        int *l_501 = &g_175[7];
                        int *l_502 = (void*)0;
                        int *l_503 = &g_175[g_276];
                        int *l_504 = &g_175[g_276];
                        int *l_505 = &g_175[0];
                        int *l_506 = (void*)0;
                        int i, j;
                        step_hash(294);
                        --l_507;
                        step_hash(295);
                        (*l_497) = (l_467[g_152][g_152] > (((unsigned char)g_175[(g_152 + 6)] - (unsigned char)g_175[g_426]) <= ((unsigned short)((unsigned char)g_175[(g_152 + 1)] + (unsigned char)((unsigned short)g_175[g_276] >> (unsigned short)(!((signed char)((signed char)(*l_501) * (signed char)(-(signed char)(l_507 == ((unsigned char)l_492 / (unsigned char)func_5(g_4, l_492))))) << (signed char)g_152)))) / (unsigned short)l_489)));
                        step_hash(296);
                        (*l_491) = (g_525 ^ func_5(l_73[5], l_492));
                        step_hash(297);
                        (*l_497) = ((!((((short)0x4E43L - (short)l_467[1][2]) & g_49[0][8]) <= ((unsigned short)((signed char)((*g_204) != (void*)0) % (signed char)l_73[0]) << (unsigned short)2))) <= ((signed char)g_4 << (signed char)6));
                    }
                    step_hash(304);
                    if (((g_205[g_74] != &l_498) ^ ((1UL > (((((short)func_5(((short)0xF9B0L * (short)l_467[g_152][g_152]), ((func_5(l_467[1][2], (((unsigned char)((short)((&p_71 != (void*)0) ^ (-1L)) / (short)l_464) * (unsigned char)(-2L)) ^ l_507)) != g_137) >= l_498)) >> (short)9) < l_467[1][2]) && 0L) ^ l_467[1][1])) ^ l_542)))
                    {
                        int l_547 = (-1L);
                        int l_548 = 0xC0A71CE0L;
                        step_hash(300);
                        l_548 &= (func_5(l_467[1][2], l_467[1][2]) != func_5(g_274, ((signed char)(((unsigned short)(l_73[5] ^ 0x6BA9E9AEL) % (unsigned short)g_102) | ((((l_507 == l_73[1]) >= l_547) ^ g_276) > 0x1E08L)) * (signed char)l_547)));
                        step_hash(301);
                        return l_549[4];
                    }
                    else
                    {
                        int l_550[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_550[i] = 0xE1015C25L;
                        step_hash(303);
                        --l_555;
                    }
                }
                step_hash(317);
                for (l_542 = 0; (l_542 <= 8); l_542 += 1)
                {
                    int l_570 = (-10L);
                    int i;
                    step_hash(309);
                    l_570 &= ((unsigned short)4UL << (unsigned short)(((short)0L / (short)((unsigned char)(g_205[l_542] == &g_175[g_426]) * (unsigned char)g_175[g_426])) & (g_175[g_426] != ((short)l_507 * (short)(l_498 <= (((unsigned char)func_5(func_5(((unsigned char)g_476 + (unsigned char)l_73[3]), l_552[0]), g_49[0][8]) * (unsigned char)l_552[0]) != 0x9AL))))));
                    step_hash(310);
                    l_498 |= (((unsigned char)((signed char)((short)((unsigned short)((signed char)((signed char)g_152 + (signed char)(((signed char)func_5(g_102, (((unsigned short)((func_5(l_551[3], g_152) | ((void*)0 == (*g_204))) | l_551[1]) << (unsigned short)10) == (g_4 < l_482))) / (signed char)l_552[0]) <= 253UL)) - (signed char)0L) % (unsigned short)0x801CL) / (short)l_552[0]) >> (signed char)l_587[2][0]) >> (unsigned char)4) <= g_102);
                    step_hash(311);
                    l_551[3] = 0x50DD6A42L;
                    step_hash(316);
                    for (g_274 = 7; (g_274 >= 0); g_274 -= 1)
                    {
                        int l_613 = (-10L);
                        step_hash(315);
                        l_551[4] &= ((-(signed char)((short)((unsigned short)((short)(((unsigned short)0xE91DL << (unsigned short)9) == 0x31EBL) / (short)(~((signed char)((signed char)(0x0A21L <= (g_49[0][8] >= ((signed char)((unsigned)((unsigned short)g_281 - (unsigned short)(1L > ((signed char)l_73[5] - (signed char)0x8EL))) - (unsigned)((short)((unsigned short)((g_175[7] ^ 255UL) >= l_613) % (unsigned short)0xA56FL) - (short)0x106BL)) + (signed char)(-6L)))) << (signed char)l_542) + (signed char)(-1L)))) % (unsigned short)l_613) + (short)1UL)) <= (-1L));
                    }
                }
            }
            step_hash(353);
            for (l_498 = 0; (l_498 <= 7); l_498 += 1)
            {
                int *l_616 = &g_175[0];
                int l_649 = 0x68A8D662L;
                int i;
                step_hash(350);
                if (((signed char)func_5(l_73[l_498], l_73[0]) + (signed char)0x91L))
                {
                    int l_623 = 1L;
                    step_hash(323);
                    (*g_204) = l_616;
                    step_hash(330);
                    if ((((signed char)((short)(func_5(g_137, ((unsigned char)l_623 * (unsigned char)(l_623 ^ ((((((int)l_623 - (int)(-1L)) && (l_628 != &p_71)) ^ (((unsigned short)((unsigned short)l_623 - (unsigned short)(func_5((*l_616), l_623) != g_426)) + (unsigned short)g_4) >= l_623)) && g_476) != g_137)))) & l_633) + (short)l_73[2]) % (signed char)1UL) && l_623))
                    {
                        step_hash(325);
                        l_552[0] |= 1L;
                        step_hash(326);
                        return (*g_204);
                    }
                    else
                    {
                        int l_640 = (-6L);
                        step_hash(328);
                        (*l_616) = ((short)l_552[0] * (short)(((short)0x5B2CL >> (short)7) <= (l_73[5] == (l_640 || g_4))));
                        step_hash(329);
                        (*g_204) = p_71;
                    }
                    step_hash(338);
                    for (g_371 = 7; (g_371 >= 1); g_371 -= 1)
                    {
                        short l_641[1][7] = {{0x30DDL, 1L, 0x30DDL, 1L, 0x30DDL, 1L, 0x30DDL}};
                        int i, j;
                        step_hash(334);
                        (*l_616) = l_552[0];
                        step_hash(335);
                        (*g_204) = l_616;
                        step_hash(336);
                        (*l_616) = (p_71 != (*g_204));
                        step_hash(337);
                        (*l_616) = (l_641[0][6] <= ((l_641[0][1] >= func_5(g_4, ((unsigned char)g_74 << (unsigned char)((unsigned char)func_5(((l_623 < (0x5398601FL != l_633)) == (l_73[3] < l_646)), l_641[0][1]) - (unsigned char)g_476)))) > 0xC6C4L));
                    }
                }
                else
                {
                    unsigned char l_650 = 0x31L;
                    step_hash(349);
                    if ((&g_205[3] != l_647[6]))
                    {
                        int ***l_648 = &l_647[6];
                        step_hash(341);
                        (*l_648) = &g_205[7];
                        step_hash(342);
                        p_71 = (*g_204);
                        step_hash(343);
                        l_650++;
                    }
                    else
                    {
                        short l_661[5] = {0xD094L, 1L, 0xD094L, 1L, 0xD094L};
                        int i;
                        step_hash(345);
                        l_661[2] |= ((int)(((g_102 | (l_655 == (void*)0)) <= (((unsigned short)(*l_616) * (unsigned short)0xC48EL) <= ((short)g_49[0][8] * (short)l_660))) <= (*l_616)) % (int)func_5((*l_616), g_152));
                        step_hash(346);
                        (*l_616) = (*l_616);
                        step_hash(347);
                        (*l_616) = l_661[2];
                        step_hash(348);
                        if ((*l_616))
                            continue;
                    }
                }
                step_hash(351);
                for (l_555 = 0; l_555 < 9; l_555 += 1)
                {
                    g_205[l_555] = &g_175[6];
                }
                step_hash(352);
                return (*g_204);
            }
            step_hash(376);
            for (g_137 = 0; (g_137 <= 7); g_137 += 1)
            {
                int l_667 = (-9L);
                int **l_674 = &l_549[4];
                step_hash(373);
                if (((unsigned char)l_664 >> (unsigned char)1))
                {
                    int l_665 = 0xCB319FA1L;
                    step_hash(364);
                    if (l_665)
                    {
                        int l_666 = 8L;
                        step_hash(359);
                        (*g_204) = (*g_204);
                        step_hash(360);
                        l_665 = l_666;
                    }
                    else
                    {
                        int l_670 = 0L;
                        step_hash(362);
                        l_489 = (l_667 <= (g_281 || (65535UL < l_670)));
                        step_hash(363);
                        if (l_498)
                            continue;
                    }
                    step_hash(365);
                    if (l_665)
                        break;
                }
                else
                {
                    short l_679 = 0x07F3L;
                    short l_709 = 0x03F9L;
                    step_hash(372);
                    if ((4294967293UL <= ((unsigned short)(-(unsigned char)(((l_674 != &g_205[0]) != 0UL) >= ((((short)g_274 << (short)g_426) ^ ((unsigned char)(((((**l_674) >= 0x35B07568L) > 4294967292UL) && l_679) & g_49[0][8]) / (unsigned char)0xA0L)) > 1L))) << (unsigned short)0)))
                    {
                        signed char l_684[1];
                        int i;
                        for (i = 0; i < 1; i++)
                            l_684[i] = 1L;
                        step_hash(368);
                        (**l_674) = ((unsigned)((signed char)l_684[0] << (signed char)5) + (unsigned)func_5(((((unsigned short)((signed char)g_175[5] / (signed char)((unsigned char)g_137 - (unsigned char)249UL)) >> (unsigned short)((unsigned char)((signed char)((signed char)((unsigned char)g_152 * (unsigned char)((unsigned)(p_71 != (void*)0) - (unsigned)g_274)) * (signed char)func_5((**l_674), l_684[0])) * (signed char)g_426) % (unsigned char)0xDDL)) < g_49[0][6]) > 0x00L), (**l_674)));
                        step_hash(369);
                        (**l_674) = l_701;
                    }
                    else
                    {
                        short l_705 = (-1L);
                        int l_710 = 3L;
                        step_hash(371);
                        l_710 &= (g_4 == ((((short)((void*)0 != l_704) << (short)(func_5(l_705, g_175[7]) <= l_679)) ^ l_706) ^ ((((((int)l_709 % (int)l_679) < (**l_674)) >= (-1L)) >= 0x94D027EEL) || g_102)));
                    }
                }
                step_hash(374);
                (*g_204) = (*l_674);
                step_hash(375);
                (**l_674) = ((unsigned short)g_4 + (unsigned short)((*g_204) != (void*)0));
            }
        }
        else
        {
            int l_721 = 0xA63D87FCL;
            int ***l_734 = &g_204;
            int l_752 = 0xDB6A5336L;
            step_hash(396);
            for (l_633 = 1; (l_633 <= 7); l_633 += 1)
            {
                int l_731 = 7L;
                signed char l_741 = 0x76L;
                int l_744 = 0xB4172AF5L;
                int l_745[6] = {9L, 9L, 0xD42503CBL, 9L, 9L, 0xD42503CBL};
                int i;
                step_hash(394);
                if (((void*)0 != &g_205[2]))
                {
                    step_hash(382);
                    g_722 = ((unsigned short)(1L && ((-1L) == (-1L))) / (unsigned short)((short)l_721 / (short)0x1D2AL));
                    step_hash(383);
                    if (l_721)
                        break;
                }
                else
                {
                    unsigned short l_743[4][6];
                    int l_746 = 0xD2AE76E6L;
                    int l_748[9][4] = {{2L, 0x06811A1FL, (-5L), 3L}, {2L, 0x06811A1FL, (-5L), 3L}, {2L, 0x06811A1FL, (-5L), 3L}, {2L, 0x06811A1FL, (-5L), 3L}, {2L, 0x06811A1FL, (-5L), 3L}, {2L, 0x06811A1FL, (-5L), 3L}, {2L, 0x06811A1FL, (-5L), 3L}, {2L, 0x06811A1FL, (-5L), 3L}, {2L, 0x06811A1FL, (-5L), 3L}};
                    int i, j;
                    for (i = 0; i < 4; i++)
                    {
                        for (j = 0; j < 6; j++)
                            l_743[i][j] = 0x9B49L;
                    }
                    step_hash(393);
                    if (((unsigned)((l_721 ^ (func_5(g_281, ((short)func_5(l_721, (&g_204 == &l_647[6])) >> (short)func_5(g_175[7], ((signed char)g_274 * (signed char)((signed char)(0x948E1FD1L <= l_731) - (signed char)g_152))))) <= g_281)) > 0x81L) - (unsigned)l_721))
                    {
                        short l_742 = 0x1E8BL;
                        int l_747 = (-7L);
                        step_hash(386);
                        if (l_721)
                            break;
                        step_hash(387);
                        (**l_734) = (*g_204);
                        step_hash(388);
                        l_749--;
                    }
                    else
                    {
                        step_hash(390);
                        if (l_721)
                            break;
                        step_hash(391);
                        l_748[7][2] &= 5L;
                        step_hash(392);
                        (**l_734) = (void*)0;
                    }
                }
                step_hash(395);
                return (*g_204);
            }
            step_hash(418);
            if (((void*)0 == &g_205[7]))
            {
                step_hash(402);
                for (g_371 = 0; (g_371 <= 7); g_371 += 1)
                {
                    step_hash(401);
                    l_752 = ((void*)0 != &l_647[7]);
                }
            }
            else
            {
                unsigned l_753 = 0UL;
                step_hash(417);
                for (l_749 = 0; (l_749 <= 7); l_749 += 1)
                {
                    int l_754[1][8] = {{0L, 0L, 0L, 0L, 0L, 0L, 0L, 0L}};
                    int l_755 = 0L;
                    int l_769 = 0L;
                    int i, j;
                    step_hash(414);
                    for (g_281 = 0; (g_281 <= 5); g_281 += 1)
                    {
                        int i;
                        step_hash(410);
                        g_175[g_281] ^= func_5(((l_549[g_281] == &g_175[g_74]) != (&p_71 == (void*)0)), l_753);
                        step_hash(411);
                        l_549[g_281] = (*g_204);
                        step_hash(412);
                        if (l_753)
                            continue;
                        step_hash(413);
                        l_755 &= l_754[0][3];
                    }
                    step_hash(415);
                    l_769 |= (((short)((unsigned short)((void*)0 != &g_204) / (unsigned short)g_4) << (short)((unsigned short)((int)(g_152 | ((signed char)(-1L) % (signed char)(((unsigned char)0UL * (unsigned char)func_5(l_754[0][1], g_768)) | l_755))) / (int)g_476) / (unsigned short)g_371)) >= g_768);
                    step_hash(416);
                    if (l_753)
                        continue;
                }
            }
            step_hash(419);
            return (*g_204);
        }
    }
    step_hash(422);
    for (g_525 = 0; g_525 < 10; g_525 += 1)
    {
        l_647[g_525] = &g_205[3];
    }
    step_hash(423);
    return (*g_204);
}







static int * func_77(unsigned p_78, int * p_79, unsigned p_80, int p_81)
{
    unsigned char l_84 = 0x8BL;
    int *l_126 = &g_49[0][1];
    int l_150[8][10] = {{0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL, 0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL}, {0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL, 0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL}, {0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL, 0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL}, {0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL, 0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL}, {0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL, 0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL}, {0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL, 0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL}, {0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL, 0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL}, {0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL, 0x6B0EF2B8L, 0xA65C328AL, 0x86F5F88DL, 0x86F5F88DL, 0xA65C328AL}};
    unsigned char l_182 = 0xFFL;
    unsigned l_259 = 1UL;
    int l_278 = (-8L);
    short l_368 = 0x3573L;
    signed char l_380 = 0xFAL;
    short l_383 = 0xA039L;
    int *l_456[6][2] = {{&g_102, (void*)0}, {&g_102, (void*)0}, {&g_102, (void*)0}, {&g_102, (void*)0}, {&g_102, (void*)0}, {&g_102, (void*)0}};
    int l_457 = (-1L);
    int i, j;
    step_hash(260);
    if (((l_84 | (-1L)) | ((-(int)((short)(-8L) >> (short)10)) ^ ((unsigned char)((short)((unsigned short)65535UL % (unsigned short)(l_84 && (0x84D1L < 0x3B75L))) << (short)10) >> (unsigned char)func_5(((void*)0 != p_79), l_84)))))
    {
        unsigned l_100 = 1UL;
        int *l_101 = &g_102;
        step_hash(27);
        (*l_101) = func_5(((unsigned short)g_74 * (unsigned short)(((short)p_80 / (short)(-1L)) ^ p_80)), (0xB2L >= ((unsigned char)((0xB764FAD6L == (*p_79)) && l_100) << (unsigned char)2)));
    }
    else
    {
        short l_105 = 0x06CDL;
        int l_170 = 0L;
        unsigned short l_226 = 0x16AAL;
        int l_233 = 1L;
        int l_234 = 0L;
        int l_235 = (-8L);
        int *l_241[9][2] = {{&l_150[2][6], &l_235}, {&l_150[2][6], &l_235}, {&l_150[2][6], &l_235}, {&l_150[2][6], &l_235}, {&l_150[2][6], &l_235}, {&l_150[2][6], &l_235}, {&l_150[2][6], &l_235}, {&l_150[2][6], &l_235}, {&l_150[2][6], &l_235}};
        int l_280[7][5] = {{0L, 1L, 0xDDF0E5C4L, 0xDDF0E5C4L, 1L}, {0L, 1L, 0xDDF0E5C4L, 0xDDF0E5C4L, 1L}, {0L, 1L, 0xDDF0E5C4L, 0xDDF0E5C4L, 1L}, {0L, 1L, 0xDDF0E5C4L, 0xDDF0E5C4L, 1L}, {0L, 1L, 0xDDF0E5C4L, 0xDDF0E5C4L, 1L}, {0L, 1L, 0xDDF0E5C4L, 0xDDF0E5C4L, 1L}, {0L, 1L, 0xDDF0E5C4L, 0xDDF0E5C4L, 1L}};
        int l_338 = 0L;
        unsigned short l_359 = 65535UL;
        int l_370 = 1L;
        short l_374 = 5L;
        unsigned short l_384[7];
        signed char l_393 = 4L;
        int l_398[6] = {0L, 0L, 0x90A3DE15L, 0L, 0L, 0x90A3DE15L};
        int l_441 = (-4L);
        int i, j;
        for (i = 0; i < 7; i++)
            l_384[i] = 0xF3B5L;
        step_hash(161);
        if (g_49[0][8])
        {
            int l_112 = 1L;
            short l_119 = 0xF228L;
            int l_151[5][7] = {{0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L}, {0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L}, {0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L}, {0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L}, {0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L, 0xD1920081L, 0x8DB39B42L, 0xD1920081L}};
            int i, j;
            step_hash(92);
            if ((((unsigned short)l_105 * (unsigned short)((unsigned char)((short)((unsigned short)p_81 * (unsigned short)l_112) + (short)(((unsigned)(((signed char)g_4 + (signed char)0x16L) || (((g_49[0][8] == g_4) && (((((unsigned)(!l_84) % (unsigned)(*p_79)) && (*p_79)) != 0x80F98811L) ^ l_84)) <= l_112)) + (unsigned)0x999AA20CL) ^ l_105)) - (unsigned char)l_112)) ^ g_49[0][8]))
            {
                int *l_121[8][6] = {{&g_49[0][8], &g_49[0][2], &g_49[0][7], &g_74, &g_49[0][2], (void*)0}, {&g_49[0][8], &g_49[0][2], &g_49[0][7], &g_74, &g_49[0][2], (void*)0}, {&g_49[0][8], &g_49[0][2], &g_49[0][7], &g_74, &g_49[0][2], (void*)0}, {&g_49[0][8], &g_49[0][2], &g_49[0][7], &g_74, &g_49[0][2], (void*)0}, {&g_49[0][8], &g_49[0][2], &g_49[0][7], &g_74, &g_49[0][2], (void*)0}, {&g_49[0][8], &g_49[0][2], &g_49[0][7], &g_74, &g_49[0][2], (void*)0}, {&g_49[0][8], &g_49[0][2], &g_49[0][7], &g_74, &g_49[0][2], (void*)0}, {&g_49[0][8], &g_49[0][2], &g_49[0][7], &g_74, &g_49[0][2], (void*)0}};
                int **l_120 = &l_121[2][3];
                int i, j;
                step_hash(31);
                l_119 ^= g_49[0][8];
                step_hash(32);
                (*l_120) = &g_102;
                step_hash(56);
                for (l_112 = 5; (l_112 >= 0); l_112 -= 1)
                {
                    int *l_138 = &g_49[0][4];
                    int l_139 = 0xF4BB62B1L;
                    step_hash(36);
                    g_102 &= ((unsigned short)(&g_49[0][7] != &g_49[0][2]) << (unsigned short)p_80);
                    step_hash(37);
                    (*l_120) = &g_49[0][8];
                    step_hash(46);
                    if (((int)(l_126 != (void*)0) + (int)l_112))
                    {
                        step_hash(39);
                        if ((*p_79))
                            break;
                        step_hash(40);
                        if ((*p_79))
                            break;
                        step_hash(41);
                        if (g_74)
                            break;
                    }
                    else
                    {
                        step_hash(43);
                        g_102 = (((signed char)func_5(((signed char)((p_81 && l_105) | g_74) / (signed char)(((signed char)(func_5((((unsigned)((p_78 | (*l_126)) == (0UL & ((signed char)p_80 << (signed char)p_78))) + (unsigned)(((p_80 || g_49[0][8]) | 0xA50BL) >= 0UL)) == 1UL), p_78) < p_81) - (signed char)6L) || 0x3044D688L)), g_49[0][4]) >> (signed char)l_105) | g_137);
                        step_hash(44);
                        l_139 = (l_138 != p_79);
                        step_hash(45);
                        (*l_120) = p_79;
                    }
                    step_hash(47);
                    if ((*p_79))
                        break;
                    step_hash(55);
                    for (p_81 = 5; (p_81 >= 0); p_81 -= 1)
                    {
                        int i, j;
                        step_hash(51);
                        (*l_120) = l_121[(l_112 + 2)][p_81];
                        step_hash(52);
                        g_102 ^= 0x11C87380L;
                        step_hash(53);
                        g_102 = ((unsigned short)l_105 - (unsigned short)((int)l_112 - (int)l_112));
                        step_hash(54);
                        g_102 |= (g_74 < (((func_5(((unsigned)g_49[0][8] % (unsigned)func_5((func_5(l_119, ((signed char)l_112 + (signed char)((p_78 ^ p_81) == l_119))) >= ((unsigned char)(*l_138) << (unsigned char)7)), l_105)), g_49[0][8]) | g_49[0][8]) <= g_4) >= p_81));
                    }
                }
                step_hash(69);
                for (p_78 = 0; (p_78 <= 5); p_78 += 1)
                {
                    step_hash(67);
                    for (l_84 = 0; (l_84 <= 5); l_84 += 1)
                    {
                        int i, j;
                        step_hash(63);
                        l_150[2][6] ^= (*p_79);
                        step_hash(64);
                        l_151[3][4] ^= (p_79 != &g_49[0][8]);
                        step_hash(65);
                        g_152 ^= g_102;
                        step_hash(66);
                        l_151[0][6] = func_5(g_49[0][8], g_152);
                    }
                    step_hash(68);
                    return p_79;
                }
            }
            else
            {
                int **l_159 = &l_126;
                signed char l_210 = 0x5CL;
                step_hash(71);
                l_126 = p_79;
                step_hash(72);
                l_170 |= ((int)(0x73A5L > (4294967292UL >= g_152)) / (int)((unsigned)(((((unsigned short)g_152 * (unsigned short)((&p_79 == l_159) || p_81)) ^ ((short)((signed char)((unsigned char)g_49[0][7] * (unsigned char)((unsigned short)func_5(((short)(-1L) * (short)l_151[3][4]), p_81) % (unsigned short)(**l_159))) % (signed char)p_78) % (short)p_80)) > 4UL) > 0x79L) + (unsigned)l_119));
                step_hash(91);
                for (g_102 = (-15); (g_102 < (-7)); g_102 += 2)
                {
                    int *l_176 = &l_150[1][3];
                    int *l_177 = &l_150[2][6];
                    int *l_178 = &l_150[2][6];
                    int *l_179 = &l_151[3][4];
                    int *l_180 = (void*)0;
                    int *l_181 = (void*)0;
                    step_hash(81);
                    for (p_81 = 7; (p_81 >= 1); p_81 -= 1)
                    {
                        int i, j;
                        step_hash(79);
                        l_150[p_81][(p_81 + 1)] = ((unsigned short)(l_150[p_81][p_81] && l_150[p_81][(p_81 + 2)]) << (unsigned short)l_150[p_81][(p_81 + 2)]);
                        step_hash(80);
                        l_150[p_81][p_81] &= (l_151[1][1] == g_152);
                    }
                    step_hash(82);
                    l_182++;
                    step_hash(89);
                    if ((0L || (+0x7DAE833BL)))
                    {
                        step_hash(84);
                        g_175[7] = (*p_79);
                        step_hash(85);
                        return &g_74;
                    }
                    else
                    {
                        int **l_185 = &l_176;
                        step_hash(87);
                        (**l_185) = ((void*)0 == l_185);
                        step_hash(88);
                        (*l_178) = ((short)((~65535UL) & ((((short)(((void*)0 == &l_126) > (*p_79)) % (short)l_112) & (+(((((~((short)(0xC9L == ((int)0L - (int)g_4)) << (short)6)) & (0x8482C93BL == 1L)) < (-6L)) | (**l_159)) < (*p_79)))) & l_105)) - (short)0UL);
                    }
                    step_hash(90);
                    (*l_176) |= ((signed char)func_5((*l_126), ((unsigned char)(0xF3F7L && ((int)g_102 % (int)func_5(((unsigned char)(0xD8L == ((((g_102 | ((signed char)(g_204 == (void*)0) << (signed char)7)) <= func_5(((unsigned short)((unsigned char)((void*)0 == &l_170) << (unsigned char)1) >> (unsigned short)7), g_175[4])) != l_210) | g_74)) * (unsigned char)g_4), p_81))) >> (unsigned char)(**l_159))) >> (signed char)5);
                }
            }
        }
        else
        {
            int *l_211 = &l_150[2][0];
            int l_215 = 0x64C33588L;
            int l_232[6][1] = {{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}};
            short l_314[3][7] = {{0L, 0x513DL, 0L, 0x513DL, 0L, 0x513DL, 0L}, {0L, 0x513DL, 0L, 0x513DL, 0L, 0x513DL, 0L}, {0L, 0x513DL, 0L, 0x513DL, 0L, 0x513DL, 0L}};
            unsigned char l_323 = 255UL;
            unsigned l_342[4][4] = {{4294967295UL, 0UL, 0x1BA29303L, 0UL}, {4294967295UL, 0UL, 0x1BA29303L, 0UL}, {4294967295UL, 0UL, 0x1BA29303L, 0UL}, {4294967295UL, 0UL, 0x1BA29303L, 0UL}};
            unsigned l_345[2];
            int i, j;
            for (i = 0; i < 2; i++)
                l_345[i] = 0UL;
            step_hash(94);
            (*l_211) = (1UL | 65531UL);
            step_hash(99);
            for (g_102 = 7; (g_102 >= 1); g_102 -= 1)
            {
                int i;
                step_hash(98);
                return g_205[(g_102 + 1)];
            }
            step_hash(160);
            if ((func_5((!g_4), p_78) & (*l_211)))
            {
                unsigned short l_216 = 0x851AL;
                int l_229[4][10];
                signed char l_244 = 0x09L;
                signed char l_249 = 0x66L;
                unsigned l_251 = 0x6E68A10EL;
                signed char l_305 = 1L;
                signed char l_319 = 0L;
                int i, j;
                for (i = 0; i < 4; i++)
                {
                    for (j = 0; j < 10; j++)
                        l_229[i][j] = 0xBB092B10L;
                }
                step_hash(111);
                for (g_152 = 0; (g_152 >= 13); g_152 += 1)
                {
                    int *l_214[9];
                    int i;
                    for (i = 0; i < 9; i++)
                        l_214[i] = &g_175[7];
                    step_hash(104);
                    l_216--;
                    step_hash(110);
                    if ((&l_215 != (void*)0))
                    {
                        step_hash(106);
                        return p_79;
                    }
                    else
                    {
                        step_hash(108);
                        (*l_211) &= (*p_79);
                        step_hash(109);
                        return (*g_204);
                    }
                }
                step_hash(116);
                for (l_170 = 0; (l_170 >= 7); ++l_170)
                {
                    step_hash(115);
                    return p_79;
                }
                step_hash(137);
                if (((short)func_5(func_5((*l_126), ((short)(p_80 < l_170) + (short)(0x5A989734L < ((~0xE0L) != (func_5(p_80, g_102) != ((void*)0 != &l_215)))))), l_105) * (short)(-5L)))
                {
                    unsigned char l_225 = 255UL;
                    step_hash(123);
                    for (p_81 = 2; (p_81 <= 8); p_81 += 1)
                    {
                        int i;
                        step_hash(121);
                        (*l_211) = func_5(g_49[0][1], g_49[0][8]);
                        step_hash(122);
                        (*l_211) = l_225;
                    }
                }
                else
                {
                    int l_227 = 0L;
                    int *l_228 = &l_227;
                    int *l_230 = &g_102;
                    int *l_231[4][8] = {{&l_150[2][6], &l_150[2][6], (void*)0, &l_150[2][6], &l_150[2][6], (void*)0, &l_150[2][6], &l_150[2][6]}, {&l_150[2][6], &l_150[2][6], (void*)0, &l_150[2][6], &l_150[2][6], (void*)0, &l_150[2][6], &l_150[2][6]}, {&l_150[2][6], &l_150[2][6], (void*)0, &l_150[2][6], &l_150[2][6], (void*)0, &l_150[2][6], &l_150[2][6]}, {&l_150[2][6], &l_150[2][6], (void*)0, &l_150[2][6], &l_150[2][6], (void*)0, &l_150[2][6], &l_150[2][6]}};
                    unsigned l_236 = 4294967289UL;
                    short l_250[8][1] = {{0x20AEL}, {0x20AEL}, {0x20AEL}, {0x20AEL}, {0x20AEL}, {0x20AEL}, {0x20AEL}, {0x20AEL}};
                    unsigned l_268 = 0x40DFEE72L;
                    int i, j;
                    step_hash(125);
                    (*l_211) = l_226;
                    step_hash(126);
                    l_236--;
                    step_hash(136);
                    if ((+((unsigned short)((&l_227 != l_241[4][1]) == (func_5(func_5(g_102, ((4294967287UL != ((*l_211) == ((unsigned)((*l_228) <= func_5(g_4, (*l_228))) - (unsigned)l_229[1][6]))) | p_78)), g_49[0][7]) | l_244)) << (unsigned short)p_80)))
                    {
                        step_hash(128);
                        l_229[0][1] ^= ((((signed char)((((unsigned short)g_152 >> (unsigned short)1) == (g_49[0][8] <= (p_79 != (void*)0))) <= func_5(l_249, ((0UL || l_250[3][0]) >= ((0xFD22L < ((*l_126) != l_251)) & 4L)))) * (signed char)p_78) <= 0x29L) & 4294967295UL);
                        step_hash(129);
                        (*l_211) = (&g_205[0] != (void*)0);
                        step_hash(130);
                        (*l_228) |= (*p_79);
                    }
                    else
                    {
                        unsigned char l_258[6] = {0xC1L, 0xC1L, 255UL, 0xC1L, 0xC1L, 255UL};
                        int l_273 = 0x5576E561L;
                        int l_275 = 0x5BEE3EABL;
                        int l_277 = 0xC4DEAE77L;
                        int l_279[7] = {0L, 0L, 0x5434C744L, 0L, 0L, 0x5434C744L, 0L};
                        int i;
                        step_hash(132);
                        (*l_230) = ((unsigned)(&l_234 == (*g_204)) / (unsigned)(*l_126));
                        step_hash(133);
                        (*l_228) ^= ((int)1L - (int)((unsigned char)func_5((((0UL > (*p_79)) >= ((func_5(l_258[4], g_137) != 0x78100EF0L) != (*p_79))) <= (*p_79)), l_259) / (unsigned char)0x62L));
                        step_hash(134);
                        l_273 ^= ((signed char)((+((unsigned short)(((void*)0 != p_79) <= ((signed char)(((short)(((*p_79) && (l_268 ^ 0UL)) | ((unsigned char)(g_4 & (((signed char)g_175[7] >> (signed char)(p_79 == p_79)) | g_74)) * (unsigned char)l_229[0][3])) - (short)p_78) >= 0x8284AA03L) << (signed char)7)) * (unsigned short)g_175[5])) ^ p_78) << (signed char)7);
                        step_hash(135);
                        g_281++;
                    }
                }
                step_hash(157);
                if (l_229[0][1])
                {
                    unsigned short l_302 = 0xD42BL;
                    int l_309 = 0xF09C6116L;
                    int l_310 = 0xAAFCCFCCL;
                    int l_311[9] = {0L, 0L, 0xB900E7DEL, 0L, 0L, 0xB900E7DEL, 0L, 0L, 0xB900E7DEL};
                    int l_321 = 1L;
                    int i;
                    step_hash(144);
                    for (l_259 = 16; (l_259 < 47); l_259 += 1)
                    {
                        signed char l_297 = 0L;
                        step_hash(142);
                        (*l_211) = ((signed char)(((&l_211 == (void*)0) ^ ((unsigned short)(((unsigned)((short)(g_152 >= ((unsigned short)p_78 - (unsigned short)(-(unsigned)l_297))) + (short)((unsigned short)(((signed char)func_5(l_302, ((signed char)((((void*)0 == (*g_204)) & p_78) != 5L) + (signed char)p_81)) + (signed char)g_74) <= 0UL) >> (unsigned short)10)) / (unsigned)l_302) == l_305) - (unsigned short)p_80)) == 0UL) * (signed char)0x41L);
                        step_hash(143);
                        l_229[0][1] = l_305;
                    }
                    step_hash(151);
                    if (func_5(g_152, (func_5(((unsigned)0xA07E1623L % (unsigned)(*l_126)), (*l_126)) == (g_49[0][4] > 4L))))
                    {
                        signed char l_308 = 0x92L;
                        int l_312 = 0x80934606L;
                        int l_313 = 0x73DFDAE5L;
                        int l_315 = (-10L);
                        int l_316 = 1L;
                        int l_317 = 0x026B42F2L;
                        int l_318 = 0L;
                        int l_320 = 0x37A764B2L;
                        int l_322 = 0xDFBD8FCFL;
                        step_hash(146);
                        ++l_323;
                    }
                    else
                    {
                        short l_336[4][4] = {{5L, 5L, 3L, (-7L)}, {5L, 5L, 3L, (-7L)}, {5L, 5L, 3L, (-7L)}, {5L, 5L, 3L, (-7L)}};
                        int l_337 = 9L;
                        int l_339 = 0xF92FA34FL;
                        int l_340 = (-1L);
                        int l_341[1][10] = {{5L, (-4L), 5L, (-4L), 5L, (-4L), 5L, (-4L), 5L, (-4L)}};
                        int i, j;
                        step_hash(148);
                        p_79 = p_79;
                        step_hash(149);
                        (*l_211) &= (l_302 >= ((signed char)(((short)(g_137 != func_5(func_5(p_81, ((unsigned short)(func_5(((int)(p_79 != &l_229[0][1]) + (int)((~(p_80 <= (0x3642L <= g_152))) || (p_79 == (void*)0))), g_49[0][2]) != 0UL) + (unsigned short)0x85F9L)), g_274)) * (short)7UL) > l_305) << (signed char)p_78));
                        step_hash(150);
                        l_342[3][2]--;
                    }
                    step_hash(152);
                    return p_79;
                }
                else
                {
                    int *l_358[6][6] = {{&l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4]}, {&l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4]}, {&l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4]}, {&l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4]}, {&l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4]}, {&l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4], &l_229[0][1], &l_150[0][4]}};
                    int i, j;
                    step_hash(154);
                    ++l_345[1];
                    step_hash(155);
                    (*l_211) = (0x6862L > ((~((int)(*l_126) / (int)(g_274 | ((0x0AL != (((unsigned)func_5(g_175[7], ((signed char)g_49[0][5] << (signed char)((unsigned short)((unsigned)((*l_211) <= (p_78 <= 5L)) / (unsigned)g_175[7]) - (unsigned short)0x7AB5L))) - (unsigned)(*l_211)) >= g_175[7])) >= 4UL)))) & g_152));
                    step_hash(156);
                    l_358[0][4] = (*g_204);
                }
            }
            else
            {
                step_hash(159);
                (*g_204) = (*g_204);
            }
        }
        step_hash(186);
        for (l_226 = 1; (l_226 <= 8); l_226 += 1)
        {
            int l_372 = 2L;
            int l_373[10] = {(-1L), 0x6A351DA5L, (-1L), 0x6A351DA5L, (-1L), 0x6A351DA5L, (-1L), 0x6A351DA5L, (-1L), 0x6A351DA5L};
            int i;
            step_hash(165);
            l_359 = (+g_175[l_226]);
            step_hash(166);
            for (l_234 = 0; l_234 < 9; l_234 += 1)
            {
                g_205[l_234] = &g_49[0][8];
            }
            step_hash(167);
            g_175[l_226] = (((func_5(g_175[l_226], ((signed char)0xADL - (signed char)p_81)) != ((signed char)func_5(g_281, func_5((0xA6L < ((unsigned short)(((void*)0 == (*g_204)) & (p_78 < 9UL)) + (unsigned short)g_74)), g_102)) + (signed char)g_281)) | g_74) <= l_368);
            step_hash(185);
            for (l_182 = 0; (l_182 <= 1); l_182 += 1)
            {
                int l_369[4] = {0L, 1L, 0L, 1L};
                unsigned char l_375 = 0UL;
                int i, j;
                step_hash(171);
                l_241[l_226][l_182] = l_241[l_226][l_182];
                step_hash(172);
                l_150[1][9] = (*p_79);
                step_hash(173);
                ++l_375;
                step_hash(184);
                if ((*p_79))
                {
                    step_hash(175);
                    (*g_204) = p_79;
                    step_hash(180);
                    for (g_276 = (-27); (g_276 <= 12); g_276++)
                    {
                        step_hash(179);
                        g_175[l_226] = (*p_79);
                    }
                }
                else
                {
                    int l_381 = (-2L);
                    int l_382[5][4] = {{(-5L), (-7L), 0x92619201L, (-7L)}, {(-5L), (-7L), 0x92619201L, (-7L)}, {(-5L), (-7L), 0x92619201L, (-7L)}, {(-5L), (-7L), 0x92619201L, (-7L)}, {(-5L), (-7L), 0x92619201L, (-7L)}};
                    int i, j;
                    step_hash(182);
                    (*g_204) = p_79;
                    step_hash(183);
                    --l_384[6];
                }
            }
        }
        step_hash(259);
        if ((+func_5(p_81, g_74)))
        {
            short l_419 = 0x9D62L;
            int l_423 = (-2L);
            step_hash(223);
            if ((g_74 >= ((((((signed char)((short)(0xD3L | 252UL) - (short)(((int)(*p_79) + (int)g_49[0][8]) || (func_5(g_175[7], (*l_126)) && l_393))) - (signed char)(*l_126)) && 0x50L) && 4294967286UL) <= 7L) <= 0x8CEB4637L)))
            {
                unsigned l_401 = 4294967287UL;
                unsigned short l_404[3][5] = {{0x811AL, 0xB77DL, 0x811AL, 0xB77DL, 0x811AL}, {0x811AL, 0xB77DL, 0x811AL, 0xB77DL, 0x811AL}, {0x811AL, 0xB77DL, 0x811AL, 0xB77DL, 0x811AL}};
                int l_420 = 7L;
                int i, j;
                step_hash(208);
                if (((unsigned short)((signed char)((p_79 != (*g_204)) <= l_398[4]) >> (signed char)1) << (unsigned short)((unsigned short)l_401 / (unsigned short)((unsigned short)l_404[2][2] * (unsigned short)0x3A50L))))
                {
                    step_hash(190);
                    (*g_204) = (*g_204);
                    step_hash(191);
                    (*g_204) = (*g_204);
                    step_hash(192);
                    (*g_204) = (*g_204);
                    step_hash(193);
                    (*g_204) = &l_170;
                }
                else
                {
                    short l_418 = (-7L);
                    int l_421 = 0x53750595L;
                    short l_422 = 0L;
                    step_hash(195);
                    l_420 |= ((short)((unsigned short)(-(signed char)(*l_126)) * (unsigned short)(((unsigned short)((unsigned short)(p_79 == (void*)0) + (unsigned short)((((short)((((int)l_418 - (int)(5L == ((g_152 ^ (0xCEL > p_80)) > (*l_126)))) && 0x33B4C881L) == 0x67E3055AL) << (short)1) < 0xBD53L) & (*p_79))) * (unsigned short)p_80) && 1L)) >> (short)l_419);
                    step_hash(196);
                    l_421 = (*p_79);
                    step_hash(202);
                    if ((p_79 == &l_421))
                    {
                        step_hash(198);
                        return (*g_204);
                    }
                    else
                    {
                        step_hash(200);
                        l_423 = (+l_422);
                        step_hash(201);
                        (*g_204) = (*g_204);
                    }
                    step_hash(207);
                    for (g_274 = 2; (g_274 >= 0); g_274 -= 1)
                    {
                        int i;
                        step_hash(206);
                        g_175[(g_274 + 2)] = l_398[(g_274 + 1)];
                    }
                }
                step_hash(209);
                (*g_204) = &l_423;
            }
            else
            {
                short l_428 = 0xB9A0L;
                int l_429 = 0xB3EB2CECL;
                step_hash(221);
                for (l_383 = 0; (l_383 == 13); l_383 += 2)
                {
                    signed char l_427 = 0x91L;
                    step_hash(220);
                    for (g_152 = 1; (g_152 >= 0); g_152 -= 1)
                    {
                        int i, j;
                        step_hash(217);
                        l_423 &= g_426;
                        step_hash(218);
                        l_429 |= (l_427 <= l_428);
                        step_hash(219);
                        if (l_419)
                            continue;
                    }
                }
                step_hash(222);
                return p_79;
            }
        }
        else
        {
            unsigned l_434 = 0x0D8E497EL;
            int l_442 = 9L;
            step_hash(225);
            l_442 = ((*l_126) || (((*g_204) != (void*)0) != func_5(((signed char)(((unsigned)func_5(l_434, ((((short)func_5(g_175[7], p_80) - (short)func_5(g_175[7], ((((unsigned char)((int)((func_5((0L > g_102), l_434) == (*l_126)) & 0L) - (int)p_80) / (unsigned char)p_80) >= p_80) > p_78))) ^ l_441) != g_102)) - (unsigned)0xB6C6D5C3L) > p_80) / (signed char)p_80), g_426)));
            step_hash(258);
            if (((unsigned char)g_274 << (unsigned char)4))
            {
                step_hash(227);
                l_442 = (*p_79);
                step_hash(232);
                for (p_81 = 0; (p_81 >= (-3)); p_81 -= 9)
                {
                    step_hash(231);
                    return p_79;
                }
                step_hash(238);
                for (p_80 = 0; (p_80 <= 4); p_80 += 1)
                {
                    step_hash(236);
                    (*g_204) = (*g_204);
                    step_hash(237);
                    return p_79;
                }
                step_hash(239);
                for (l_259 = 0; l_259 < 7; l_259 += 1)
                {
                    for (l_368 = 0; l_368 < 5; l_368 += 1)
                    {
                        l_280[l_259][l_368] = 0xA5BAB5D3L;
                    }
                }
            }
            else
            {
                short l_447 = (-2L);
                int *l_452 = &l_234;
                unsigned l_453 = 7UL;
                step_hash(241);
                l_442 = l_447;
                step_hash(256);
                for (l_370 = 0; (l_370 == 8); l_370 += 6)
                {
                    step_hash(249);
                    for (l_234 = 0; (l_234 <= (-21)); l_234 -= 3)
                    {
                        step_hash(248);
                        return (*g_204);
                    }
                    step_hash(250);
                    (*g_204) = (*g_204);
                    step_hash(255);
                    for (l_278 = 0; (l_278 <= 5); l_278 += 1)
                    {
                        step_hash(254);
                        return (*g_204);
                    }
                }
                step_hash(257);
                --l_453;
            }
        }
    }
    step_hash(261);
    l_457 ^= 0x2D5F306DL;
    step_hash(262);
    return p_79;
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_4, "g_4", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(g_49[i][j], "g_49[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_74, "g_74", print_hash_value);
    transparent_crc(g_102, "g_102", print_hash_value);
    transparent_crc(g_137, "g_137", print_hash_value);
    transparent_crc(g_152, "g_152", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_175[i], "g_175[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_274, "g_274", print_hash_value);
    transparent_crc(g_276, "g_276", print_hash_value);
    transparent_crc(g_281, "g_281", print_hash_value);
    transparent_crc(g_371, "g_371", print_hash_value);
    transparent_crc(g_426, "g_426", print_hash_value);
    transparent_crc(g_476, "g_476", print_hash_value);
    transparent_crc(g_525, "g_525", print_hash_value);
    transparent_crc(g_722, "g_722", print_hash_value);
    transparent_crc(g_768, "g_768", print_hash_value);
    transparent_crc(g_817, "g_817", print_hash_value);
    transparent_crc(g_881, "g_881", print_hash_value);
    transparent_crc(g_1035, "g_1035", print_hash_value);
    transparent_crc(g_1037, "g_1037", print_hash_value);
    transparent_crc(g_1061, "g_1061", print_hash_value);
    transparent_crc(g_1164, "g_1164", print_hash_value);
    transparent_crc(g_1259, "g_1259", print_hash_value);
    transparent_crc(g_1283, "g_1283", print_hash_value);
    transparent_crc(g_1295, "g_1295", print_hash_value);
    transparent_crc(g_1307, "g_1307", print_hash_value);
    transparent_crc(g_1313, "g_1313", print_hash_value);
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
