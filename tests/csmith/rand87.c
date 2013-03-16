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
static int g_2 = 0xFE0A8EACL;
static int g_129 = 0x22D1E25FL;
static int *g_131 = &g_129;
static unsigned char g_161 = 255UL;
static unsigned g_176 = 0xE138955FL;
static unsigned g_180 = 0x834275C0L;
static unsigned short g_188[5][6] = {{3UL, 1UL, 0x6CB0L, 0UL, 0xC73BL, 0UL}, {3UL, 1UL, 0x6CB0L, 0UL, 0xC73BL, 0UL}, {3UL, 1UL, 0x6CB0L, 0UL, 0xC73BL, 0UL}, {3UL, 1UL, 0x6CB0L, 0UL, 0xC73BL, 0UL}, {3UL, 1UL, 0x6CB0L, 0UL, 0xC73BL, 0UL}};
static unsigned char g_254 = 0x05L;
static int g_274 = 0x630A5C78L;
static unsigned char g_286 = 0x10L;
static unsigned g_307 = 0x468E9773L;
static signed char g_314 = (-1L);
static unsigned g_316 = 0xCA451F2BL;
static unsigned g_336[9][2] = {{0x71822003L, 0xCEE99220L}, {0x71822003L, 0xCEE99220L}, {0x71822003L, 0xCEE99220L}, {0x71822003L, 0xCEE99220L}, {0x71822003L, 0xCEE99220L}, {0x71822003L, 0xCEE99220L}, {0x71822003L, 0xCEE99220L}, {0x71822003L, 0xCEE99220L}, {0x71822003L, 0xCEE99220L}};
static unsigned g_344 = 4294967287UL;
static int g_347[8][9] = {{1L, 1L, 0xDDB92C3FL, 1L, 0xBCAEF4B9L, 0x8183C4D5L, 0xBCAEF4B9L, 1L, 0xDDB92C3FL}, {1L, 1L, 0xDDB92C3FL, 1L, 0xBCAEF4B9L, 0x8183C4D5L, 0xBCAEF4B9L, 1L, 0xDDB92C3FL}, {1L, 1L, 0xDDB92C3FL, 1L, 0xBCAEF4B9L, 0x8183C4D5L, 0xBCAEF4B9L, 1L, 0xDDB92C3FL}, {1L, 1L, 0xDDB92C3FL, 1L, 0xBCAEF4B9L, 0x8183C4D5L, 0xBCAEF4B9L, 1L, 0xDDB92C3FL}, {1L, 1L, 0xDDB92C3FL, 1L, 0xBCAEF4B9L, 0x8183C4D5L, 0xBCAEF4B9L, 1L, 0xDDB92C3FL}, {1L, 1L, 0xDDB92C3FL, 1L, 0xBCAEF4B9L, 0x8183C4D5L, 0xBCAEF4B9L, 1L, 0xDDB92C3FL}, {1L, 1L, 0xDDB92C3FL, 1L, 0xBCAEF4B9L, 0x8183C4D5L, 0xBCAEF4B9L, 1L, 0xDDB92C3FL}, {1L, 1L, 0xDDB92C3FL, 1L, 0xBCAEF4B9L, 0x8183C4D5L, 0xBCAEF4B9L, 1L, 0xDDB92C3FL}};
static signed char g_349 = 0x79L;
static int g_350 = (-6L);
static unsigned g_353 = 0x498343F8L;
static signed char g_358 = 7L;
static unsigned g_359 = 7UL;
static short g_387 = 0L;
static unsigned short g_391 = 7UL;
static short g_404 = 0x2666L;
static unsigned char g_405[2][6] = {{0x0BL, 0x0BL, 0x18L, 0x0BL, 0x0BL, 0x18L}, {0x0BL, 0x0BL, 0x18L, 0x0BL, 0x0BL, 0x18L}};
static unsigned char g_433 = 0xF8L;
static int **g_448 = &g_131;
static int ***g_447 = &g_448;
static int g_474 = 1L;
static unsigned g_540 = 0x16993E9DL;
static signed char g_554 = 0x78L;
static unsigned char g_562 = 0x4BL;
static unsigned g_580 = 4294967291UL;
static int g_619 = 7L;
static short g_633 = 1L;
static unsigned char g_635[2][5] = {{255UL, 255UL, 255UL, 255UL, 255UL}, {255UL, 255UL, 255UL, 255UL, 255UL}};
static int g_754[7][9] = {{0xF4D29B33L, 0x049066CDL, 0x83334F85L, 1L, 2L, (-9L), (-9L), 2L, 1L}, {0xF4D29B33L, 0x049066CDL, 0x83334F85L, 1L, 2L, (-9L), (-9L), 2L, 1L}, {0xF4D29B33L, 0x049066CDL, 0x83334F85L, 1L, 2L, (-9L), (-9L), 2L, 1L}, {0xF4D29B33L, 0x049066CDL, 0x83334F85L, 1L, 2L, (-9L), (-9L), 2L, 1L}, {0xF4D29B33L, 0x049066CDL, 0x83334F85L, 1L, 2L, (-9L), (-9L), 2L, 1L}, {0xF4D29B33L, 0x049066CDL, 0x83334F85L, 1L, 2L, (-9L), (-9L), 2L, 1L}, {0xF4D29B33L, 0x049066CDL, 0x83334F85L, 1L, 2L, (-9L), (-9L), 2L, 1L}};
static int g_768 = 0xCE5A8A68L;
static int *g_809 = &g_274;
static int g_1005[2] = {0x26863B4FL, 0x26863B4FL};
static unsigned func_1(void);
static int func_5(signed char p_6, unsigned short p_7, unsigned short p_8);
static signed char func_14(unsigned short p_15, short p_16, unsigned p_17, int p_18, unsigned p_19);
static unsigned func_24(unsigned char p_25);
static unsigned char func_26(unsigned char p_27, int p_28, unsigned char p_29);
static int func_35(int p_36, unsigned p_37, unsigned short p_38);
static short func_42(unsigned char p_43, unsigned char p_44);
static unsigned char func_57(signed char p_58, short p_59, unsigned char p_60, signed char p_61, short p_62);
static signed char func_63(unsigned char p_64, unsigned char p_65, short p_66, unsigned short p_67);
static unsigned char func_74(unsigned p_75, unsigned p_76, short p_77, int p_78);
static unsigned func_1(void)
{
    int l_9[8];
    int l_988 = (-1L);
    int *l_1008 = &g_274;
    int l_1011 = 0x97938E3BL;
    int l_1018 = 0xD277BE45L;
    int l_1019[2];
    int l_1024 = 0xC271A075L;
    unsigned char l_1025 = 0xD6L;
    int i;
    for (i = 0; i < 8; i++)
        l_9[i] = 0x942A1E94L;
    for (i = 0; i < 2; i++)
        l_1019[i] = 0L;
    step_hash(663);
    for (g_2 = 25; (g_2 <= (-5)); --g_2)
    {
        int l_769 = (-7L);
        unsigned l_770 = 0x14CFEE24L;
    }
    step_hash(664);
    (***g_447) = ((((signed char)(g_359 || ((int)l_9[0] / (int)l_9[0])) >> (signed char)4) ^ ((signed char)l_9[2] >> (signed char)4)) ^ (~(((short)2L >> (short)12) == (g_180 <= (((unsigned short)((signed char)0xB4L << (signed char)0) + (unsigned short)(l_9[5] & (g_353 == l_9[0]))) <= g_754[4][8])))));
    step_hash(676);
    for (g_316 = (-14); (g_316 > 55); ++g_316)
    {
        step_hash(668);
        if (g_1005[1])
            break;
        step_hash(673);
        for (g_314 = 0; (g_314 >= 9); g_314++)
        {
            step_hash(672);
            (*g_809) = (*g_809);
        }
        step_hash(674);
        if ((***g_447))
            continue;
        step_hash(675);
        l_1008 = &l_988;
    }
    step_hash(682);
    for (g_633 = 6; (g_633 == 17); ++g_633)
    {
        int *l_1012 = &g_2;
        int *l_1013 = (void*)0;
        int *l_1014 = &g_754[5][3];
        int *l_1015 = &g_619;
        int *l_1016 = &g_2;
        int *l_1017[3];
        signed char l_1020[5][10] = {{8L, 0x0CL, (-7L), (-2L), 0x0CL, (-1L), 0x0CL, (-2L), (-7L), 0x0CL}, {8L, 0x0CL, (-7L), (-2L), 0x0CL, (-1L), 0x0CL, (-2L), (-7L), 0x0CL}, {8L, 0x0CL, (-7L), (-2L), 0x0CL, (-1L), 0x0CL, (-2L), (-7L), 0x0CL}, {8L, 0x0CL, (-7L), (-2L), 0x0CL, (-1L), 0x0CL, (-2L), (-7L), 0x0CL}, {8L, 0x0CL, (-7L), (-2L), 0x0CL, (-1L), 0x0CL, (-2L), (-7L), 0x0CL}};
        unsigned l_1021 = 1UL;
        int i, j;
        for (i = 0; i < 3; i++)
            l_1017[i] = &g_274;
        step_hash(680);
        --l_1021;
        step_hash(681);
        (*l_1015) &= ((((l_1024 & (-1L)) != 0x6C63L) < (((l_1025 <= (1UL < (g_336[1][0] & (*l_1008)))) < func_63(((unsigned char)((short)((unsigned char)(((unsigned char)(&g_448 != &g_448) + (unsigned char)(*l_1008)) >= g_635[1][0]) >> (unsigned char)g_387) << (short)g_633) % (unsigned char)255UL), g_635[1][0], (*l_1008), g_358)) <= 0x37L)) == g_316);
    }
    step_hash(683);
    return g_274;
}
static int func_5(signed char p_6, unsigned short p_7, unsigned short p_8)
{
    int ***l_777 = &g_448;
    int l_787[2][5];
    short l_867 = (-7L);
    int l_899 = 0xEA9D2EA7L;
    short l_914 = 0xEE49L;
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
            l_787[i][j] = (-3L);
    }
    step_hash(499);
    for (p_7 = 0; (p_7 <= 1); p_7 += 1)
    {
        unsigned char l_778 = 0xA1L;
        int l_786 = 0x70BA411CL;
        int l_788 = 0x8D1C6474L;
        step_hash(478);
        (***l_777) = l_778;
        step_hash(498);
        for (g_180 = 0; (g_180 <= 4); g_180 += 1)
        {
            unsigned l_779 = 0x01D16C35L;
            unsigned l_780 = 0x938BC10CL;
            step_hash(497);
            for (g_316 = 0; (g_316 <= 1); g_316 += 1)
            {
                int i, j;
                step_hash(491);
                if ((func_74(g_188[(p_7 + 1)][g_180], g_635[g_316][(g_316 + 3)], p_7, (func_24(l_779) == func_74(g_554, (p_8 < 6L), func_74(l_779, p_6, p_6, l_779), l_778))) || l_780))
                {
                    int l_785 = 8L;
                    int *l_789 = &l_788;
                    int *l_790[8][7] = {{&g_754[5][3], &g_129, (void*)0, (void*)0, &g_754[3][4], (void*)0, (void*)0}, {&g_754[5][3], &g_129, (void*)0, (void*)0, &g_754[3][4], (void*)0, (void*)0}, {&g_754[5][3], &g_129, (void*)0, (void*)0, &g_754[3][4], (void*)0, (void*)0}, {&g_754[5][3], &g_129, (void*)0, (void*)0, &g_754[3][4], (void*)0, (void*)0}, {&g_754[5][3], &g_129, (void*)0, (void*)0, &g_754[3][4], (void*)0, (void*)0}, {&g_754[5][3], &g_129, (void*)0, (void*)0, &g_754[3][4], (void*)0, (void*)0}, {&g_754[5][3], &g_129, (void*)0, (void*)0, &g_754[3][4], (void*)0, (void*)0}, {&g_754[5][3], &g_129, (void*)0, (void*)0, &g_754[3][4], (void*)0, (void*)0}};
                    unsigned short l_791 = 65535UL;
                    int i, j;
                    step_hash(486);
                    l_785 = (((short)(!(p_6 >= p_7)) << (short)((signed char)0L >> (signed char)1)) ^ func_24(l_778));
                    step_hash(487);
                    --l_791;
                }
                else
                {
                    unsigned char l_798 = 0UL;
                    step_hash(489);
                    (**g_448) = ((signed char)((signed char)l_798 % (signed char)func_74(g_188[3][2], p_7, g_554, (**g_448))) * (signed char)func_74((0xF5L && (g_635[g_316][(g_316 + 3)] <= g_359)), p_6, g_405[1][1], (***g_447)));
                    step_hash(490);
                    if (p_8)
                        break;
                }
                step_hash(496);
                for (l_778 = 0; (l_778 <= 1); l_778 += 1)
                {
                    step_hash(495);
                    return p_8;
                }
            }
        }
    }
    step_hash(500);
    (**l_777) = (void*)0;
    step_hash(660);
    for (g_161 = 0; (g_161 <= 1); g_161 += 1)
    {
        unsigned l_804 = 4294967295UL;
        int l_807 = (-1L);
        int *l_810 = &l_787[0][2];
        int l_811 = 0xA90C624DL;
        int l_815[8] = {(-6L), (-1L), (-6L), (-1L), (-6L), (-1L), (-6L), (-1L)};
        unsigned l_866[9][9] = {{0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}, {0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}, {0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}, {0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}, {0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}, {0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}, {0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}, {0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}, {0UL, 4294967289UL, 0x83AC71D7L, 0UL, 0x83AC71D7L, 4294967289UL, 0UL, 1UL, 4294967295UL}};
        int i, j;
        step_hash(514);
        for (g_433 = 0; (g_433 <= 1); g_433 += 1)
        {
            int *l_801 = &g_474;
            int *l_802 = &g_129;
            int *l_803[9];
            int i, j;
            for (i = 0; i < 9; i++)
                l_803[i] = &g_754[5][3];
            step_hash(507);
            l_804--;
            step_hash(513);
            for (g_768 = 0; (g_768 <= 1); g_768 += 1)
            {
                step_hash(511);
                (*g_447) = &l_801;
                step_hash(512);
                (*g_448) = (void*)0;
            }
        }
        step_hash(515);
        l_807 |= 1L;
        step_hash(516);
        l_787[0][1] = p_6;
        step_hash(659);
        for (g_350 = 1; (g_350 >= 0); g_350 -= 1)
        {
            int l_816 = 0L;
            int l_822 = (-2L);
            int l_823 = 0L;
            int *l_841 = &l_815[4];
            int l_895[5][2] = {{1L, 0xB2608B29L}, {1L, 0xB2608B29L}, {1L, 0xB2608B29L}, {1L, 0xB2608B29L}, {1L, 0xB2608B29L}};
            unsigned l_932 = 0xA0417D87L;
            unsigned short l_944[5][7] = {{0xF392L, 65535UL, 65535UL, 0x29D0L, 0x9855L, 0x29D0L, 65535UL}, {0xF392L, 65535UL, 65535UL, 0x29D0L, 0x9855L, 0x29D0L, 65535UL}, {0xF392L, 65535UL, 65535UL, 0x29D0L, 0x9855L, 0x29D0L, 65535UL}, {0xF392L, 65535UL, 65535UL, 0x29D0L, 0x9855L, 0x29D0L, 65535UL}, {0xF392L, 65535UL, 65535UL, 0x29D0L, 0x9855L, 0x29D0L, 65535UL}};
            unsigned l_956 = 1UL;
            unsigned l_981[10][5] = {{4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}, {4294967293UL, 1UL, 4294967293UL, 0x3DD37B07L, 0xEC396901L}};
            int i, j;
            step_hash(560);
            for (l_807 = 1; (l_807 >= 0); l_807 -= 1)
            {
                int l_820 = (-6L);
                int l_821[2][9] = {{1L, 0xE40357A5L, 1L, 0xE40357A5L, 1L, 0xE40357A5L, 1L, 0xE40357A5L, 1L}, {1L, 0xE40357A5L, 1L, 0xE40357A5L, 1L, 0xE40357A5L, 1L, 0xE40357A5L, 1L}};
                int i, j;
                step_hash(540);
                for (p_6 = 0; (p_6 <= 1); p_6 += 1)
                {
                    int l_817 = 0x597D154FL;
                    int l_818 = 0x424F2709L;
                    int l_819[2];
                    unsigned l_824 = 4294967288UL;
                    int i, j;
                    for (i = 0; i < 2; i++)
                        l_819[i] = 0xA59C1508L;
                    step_hash(526);
                    if (g_405[g_161][(g_350 + 3)])
                        break;
                    step_hash(532);
                    for (g_391 = 0; (g_391 <= 1); g_391 += 1)
                    {
                        int **l_808[10] = {&g_131, &g_131, &g_131, &g_131, &g_131, &g_131, &g_131, &g_131, &g_131, &g_131};
                        int i, j;
                        step_hash(530);
                        g_809 = &l_787[l_807][(g_350 + 2)];
                        step_hash(531);
                        return g_635[g_161][(g_350 + 3)];
                    }
                    step_hash(539);
                    for (g_768 = 0; (g_768 <= 1); g_768 += 1)
                    {
                        int *l_812 = &g_754[5][3];
                        int *l_813 = &g_619;
                        int *l_814[5][9] = {{&g_619, &g_2, &g_474, &g_2, &g_619, &g_2, &g_474, &g_2, &g_619}, {&g_619, &g_2, &g_474, &g_2, &g_619, &g_2, &g_474, &g_2, &g_619}, {&g_619, &g_2, &g_474, &g_2, &g_619, &g_2, &g_474, &g_2, &g_619}, {&g_619, &g_2, &g_474, &g_2, &g_619, &g_2, &g_474, &g_2, &g_619}, {&g_619, &g_2, &g_474, &g_2, &g_619, &g_2, &g_474, &g_2, &g_619}};
                        int i, j;
                        step_hash(536);
                        l_810 = (void*)0;
                        step_hash(537);
                        l_824--;
                        step_hash(538);
                        return l_787[g_161][(g_768 + 1)];
                    }
                }
                step_hash(541);
                l_816 ^= 0xD8AE6931L;
                step_hash(542);
                l_810 = &l_787[g_161][(g_161 + 1)];
                step_hash(559);
                for (l_822 = 0; (l_822 <= 1); l_822 += 1)
                {
                    int l_835 = 0x4060C6A3L;
                    int l_837[10][8] = {{0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}, {0xC45AD5D3L, 0x1C9997FFL, 0x54036D7EL, (-9L), 0x54036D7EL, 0x1C9997FFL, 0xC45AD5D3L, (-7L)}};
                    unsigned short l_838 = 0x6259L;
                    int i, j;
                    step_hash(550);
                    for (l_804 = 0; (l_804 <= 1); l_804 += 1)
                    {
                        int i, j;
                        step_hash(549);
                        return g_405[g_350][(l_804 + 3)];
                    }
                    step_hash(557);
                    if ((g_405[g_350][l_807] || l_787[1][2]))
                    {
                        step_hash(552);
                        (*g_809) = func_74(p_7, (g_336[4][1] != ((g_405[1][1] | ((int)((unsigned short)g_286 + (unsigned short)p_7) - (int)(0xE8L < p_8))) != ((*l_810) == p_7))), l_816, p_6);
                        step_hash(553);
                        (*l_810) = (g_405[g_350][l_807] >= (9L > ((unsigned char)p_7 << (unsigned char)p_7)));
                    }
                    else
                    {
                        int *l_836[3][5] = {{&g_274, &l_787[g_161][(g_161 + 1)], &g_274, &l_787[g_161][(g_161 + 1)], &g_274}, {&g_274, &l_787[g_161][(g_161 + 1)], &g_274, &l_787[g_161][(g_161 + 1)], &g_274}, {&g_274, &l_787[g_161][(g_161 + 1)], &g_274, &l_787[g_161][(g_161 + 1)], &g_274}};
                        int i, j;
                        step_hash(555);
                        if (l_816)
                            break;
                        step_hash(556);
                        ++l_838;
                    }
                    step_hash(558);
                    (*g_809) = (l_841 != &l_811);
                }
            }
            step_hash(577);
            for (g_254 = 0; (g_254 <= 1); g_254 += 1)
            {
                int **l_850[7];
                int i;
                for (i = 0; i < 7; i++)
                    l_850[i] = &l_841;
                step_hash(564);
                (*l_777) = &l_810;
                step_hash(575);
                for (g_433 = 0; (g_433 <= 1); g_433 += 1)
                {
                    int l_842 = 0x6934F45CL;
                    int i;
                    step_hash(568);
                    l_842 |= l_815[(g_161 + 1)];
                    step_hash(574);
                    for (g_554 = 1; (g_554 >= 0); g_554 -= 1)
                    {
                        int i;
                        step_hash(572);
                        (***l_777) ^= l_815[(g_254 + 2)];
                        step_hash(573);
                        return l_815[(g_254 + 2)];
                    }
                }
                step_hash(576);
                (*g_809) = ((short)p_8 - (short)func_74(((signed char)((unsigned)p_6 + (unsigned)(-(unsigned char)(!p_8))) * (signed char)g_188[4][2]), ((void*)0 != l_850[5]), p_7, (*g_809)));
            }
            step_hash(657);
            for (l_822 = 0; (l_822 <= 1); l_822 += 1)
            {
                int ***l_857 = &g_448;
                int l_871 = 0xF1AADCE2L;
                int l_874 = 0xAB7C1F7DL;
                int l_888 = 0xB9345B12L;
                int l_890 = (-1L);
                int l_894 = 0L;
                int l_897[6][8] = {{0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L}, {0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L}, {0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L}, {0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L}, {0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L}, {0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L, 0xDCE527E5L, 0x03465D71L}};
                int **l_939 = &l_810;
                int i, j;
            }
            step_hash(658);
            (*l_777) = &l_810;
        }
    }
    step_hash(661);
    return p_8;
}
static signed char func_14(unsigned short p_15, short p_16, unsigned p_17, int p_18, unsigned p_19)
{
    int l_30 = 0x451F1E28L;
    int *l_767 = &g_768;
    step_hash(472);
    (*l_767) &= (p_17 ^ ((unsigned short)(func_24(func_26(p_18, p_19, ((0x11E0L | p_17) == l_30))) == func_74(func_74(g_404, g_349, l_30, p_17), l_30, g_2, p_15)) * (unsigned short)l_30));
    step_hash(473);
    return g_633;
}
static unsigned func_24(unsigned char p_25)
{
    short l_758 = (-1L);
    int *l_759 = &g_474;
    int *l_760 = &g_619;
    int *l_761 = &g_274;
    int *l_762[6][1];
    int l_763 = 0xD9F93307L;
    unsigned l_764[9][10] = {{1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}, {1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}, {1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}, {1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}, {1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}, {1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}, {1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}, {1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}, {1UL, 6UL, 1UL, 0xACEE6F1DL, 0x49B50D3AL, 6UL, 4294967295UL, 0x5ABE2539L, 4294967295UL, 1UL}};
    int i, j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 1; j++)
            l_762[i][j] = &g_129;
    }
    step_hash(469);
    ++l_764[0][2];
    step_hash(470);
    (**g_447) = l_759;
    step_hash(471);
    return p_25;
}







static unsigned char func_26(unsigned char p_27, int p_28, unsigned char p_29)
{
    unsigned l_39[6];
    int l_45 = 0x81F51B43L;
    unsigned char l_752 = 252UL;
    int *l_753 = &g_754[5][3];
    int l_757 = 1L;
    int i;
    for (i = 0; i < 6; i++)
        l_39[i] = 0x88216928L;
    step_hash(463);
    (*l_753) &= ((p_28 >= ((signed char)(((unsigned char)((func_35(p_28, ((0x51DBL ^ ((((l_39[0] >= (((6UL >= p_28) <= ((0x0FE1F230L && g_2) < ((short)func_42(g_2, l_45) % (short)0x812FL))) <= 0L)) ^ 0x3D02DF21L) <= 1L) == l_45)) < g_350), l_45) == 0L) | (-1L)) >> (unsigned char)l_45) != l_752) * (signed char)7UL)) & 0x74L);
    step_hash(464);
    (*g_448) = &l_45;
    step_hash(465);
    (*g_448) = &l_45;
    step_hash(466);
    l_757 &= func_35(p_29, ((*l_753) && (func_35(p_28, (*l_753), (0x509072BCL & (**g_448))) > (4294967290UL & ((short)(func_74((*l_753), (*l_753), (*l_753), (*l_753)) && g_619) + (short)(*l_753))))), p_29);
    step_hash(467);
    return p_27;
}







static int func_35(int p_36, unsigned p_37, unsigned short p_38)
{
    int **l_585 = &g_131;
    int l_589 = 0x6BDEB9DEL;
    unsigned l_596 = 4294967286UL;
    int **l_605[9][3] = {{&g_131, &g_131, &g_131}, {&g_131, &g_131, &g_131}, {&g_131, &g_131, &g_131}, {&g_131, &g_131, &g_131}, {&g_131, &g_131, &g_131}, {&g_131, &g_131, &g_131}, {&g_131, &g_131, &g_131}, {&g_131, &g_131, &g_131}, {&g_131, &g_131, &g_131}};
    int *l_640 = &g_274;
    int l_735 = 0L;
    unsigned char l_741 = 0xA4L;
    unsigned short l_748 = 0UL;
    int i, j;
    step_hash(440);
    for (g_316 = 0; (g_316 <= 55); g_316 += 6)
    {
        int ***l_588[6][6] = {{&g_448, &l_585, &g_448, &l_585, &l_585, &l_585}, {&g_448, &l_585, &g_448, &l_585, &l_585, &l_585}, {&g_448, &l_585, &g_448, &l_585, &l_585, &l_585}, {&g_448, &l_585, &g_448, &l_585, &l_585, &l_585}, {&g_448, &l_585, &g_448, &l_585, &l_585, &l_585}, {&g_448, &l_585, &g_448, &l_585, &l_585, &l_585}};
        int *l_641 = &g_274;
        unsigned char l_653[6];
        int l_699 = 7L;
        unsigned char l_729 = 0xB5L;
        signed char l_740[10][9] = {{(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}, {(-1L), (-1L), (-5L), 0x55L, 6L, 0xB9L, 0xAEL, (-1L), 0x87L}};
        int i, j;
        for (i = 0; i < 6; i++)
            l_653[i] = 0xEEL;
        step_hash(381);
        for (p_36 = 0; (p_36 <= 1); p_36 += 1)
        {
            int l_590 = 3L;
            int ***l_593 = &l_585;
            unsigned l_612[5][10] = {{1UL, 0x5D088E13L, 4294967290UL, 0xEFFD0C9DL, 0x5D088E13L, 3UL, 0x5D088E13L, 0xEFFD0C9DL, 4294967290UL, 0x5D088E13L}, {1UL, 0x5D088E13L, 4294967290UL, 0xEFFD0C9DL, 0x5D088E13L, 3UL, 0x5D088E13L, 0xEFFD0C9DL, 4294967290UL, 0x5D088E13L}, {1UL, 0x5D088E13L, 4294967290UL, 0xEFFD0C9DL, 0x5D088E13L, 3UL, 0x5D088E13L, 0xEFFD0C9DL, 4294967290UL, 0x5D088E13L}, {1UL, 0x5D088E13L, 4294967290UL, 0xEFFD0C9DL, 0x5D088E13L, 3UL, 0x5D088E13L, 0xEFFD0C9DL, 4294967290UL, 0x5D088E13L}, {1UL, 0x5D088E13L, 4294967290UL, 0xEFFD0C9DL, 0x5D088E13L, 3UL, 0x5D088E13L, 0xEFFD0C9DL, 4294967290UL, 0x5D088E13L}};
            short l_618 = (-1L);
            unsigned short l_624 = 0UL;
            signed char l_627 = 0xB6L;
            int i, j;
            step_hash(355);
            l_590 = func_74(((*g_447) != l_585), ((unsigned)g_188[(p_36 + 1)][p_36] + (unsigned)((&p_36 == (void*)0) < (((void*)0 == l_588[3][1]) == g_180))), g_188[(p_36 + 1)][p_36], p_38);
            step_hash(356);
            l_590 = (((unsigned)((l_593 != &g_448) & ((unsigned short)g_336[1][0] * (unsigned short)(l_596 >= ((unsigned short)func_74(g_405[1][1], g_188[1][3], g_286, p_36) + (unsigned short)p_36)))) % (unsigned)p_37) || 65535UL);
            step_hash(357);
            g_274 = ((short)g_405[1][2] >> (short)p_36);
            step_hash(380);
            if (g_540)
            {
                unsigned char l_615 = 249UL;
                step_hash(359);
                ++l_615;
            }
            else
            {
                unsigned char l_623 = 0x88L;
                int l_625 = 1L;
                int l_628[10][4] = {{0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}, {0L, 0x53167DB8L, 0x9D3FB8D0L, 0x9D3FB8D0L}};
                int i, j;
                step_hash(367);
                for (g_129 = 1; (g_129 >= 0); g_129 -= 1)
                {
                    unsigned l_620 = 0x91D3C02AL;
                    step_hash(364);
                    l_618 = 1L;
                    step_hash(365);
                    l_620++;
                    step_hash(366);
                    if (p_37)
                        break;
                }
                step_hash(379);
                if (l_623)
                {
                    step_hash(369);
                    (**l_593) = (void*)0;
                    step_hash(370);
                    l_625 = (l_624 >= (-1L));
                }
                else
                {
                    signed char l_629 = 0xACL;
                    step_hash(377);
                    for (g_274 = 0; (g_274 <= 1); g_274 += 1)
                    {
                        int l_626[10] = {(-1L), 0L, (-1L), 0L, (-1L), 0L, (-1L), 0L, (-1L), 0L};
                        int l_630 = 0x4F70A7E7L;
                        int l_631 = 0x78E71ECAL;
                        int l_632 = (-4L);
                        int l_634 = 0xDB1845A3L;
                        int i;
                        step_hash(375);
                        ++g_635[1][0];
                        step_hash(376);
                        l_634 |= (!(g_353 & ((signed char)((+((void*)0 != &g_448)) <= p_38) << (signed char)1)));
                    }
                    step_hash(378);
                    return p_38;
                }
            }
        }
        step_hash(438);
        if (((p_36 & p_36) == p_37))
        {
            int ***l_656[3];
            unsigned l_683 = 2UL;
            unsigned l_697 = 0xB236087CL;
            int i;
            for (i = 0; i < 3; i++)
                l_656[i] = &g_448;
            step_hash(410);
            if (((((signed char)(-8L) >> (signed char)((short)p_38 + (short)func_74(((((unsigned)((-(unsigned short)((signed char)l_653[1] * (signed char)p_36)) <= ((g_347[4][5] && (l_656[0] == l_656[0])) | ((signed char)g_635[0][0] >> (signed char)(((unsigned short)p_36 >> (unsigned short)p_36) < 0UL)))) + (unsigned)g_433) || 1L) | (*l_640)), p_37, p_36, p_36))) == 0x4190L) & 0UL))
            {
                unsigned l_661 = 4294967291UL;
                step_hash(384);
                p_36 |= l_661;
                step_hash(395);
                for (p_37 = 0; (p_37 != 33); p_37 += 7)
                {
                    int l_666 = (-1L);
                    step_hash(393);
                    for (g_391 = 0; (g_391 == 29); g_391 += 4)
                    {
                        int l_680[7] = {1L, 0xD1D0773AL, 1L, 0xD1D0773AL, 1L, 0xD1D0773AL, 1L};
                        int i;
                        step_hash(391);
                        l_666 &= p_37;
                        step_hash(392);
                        (*l_641) |= ((short)(p_36 || (((unsigned char)((signed char)(255UL == 254UL) % (signed char)((signed char)(-1L) << (signed char)(-(short)((unsigned short)0x2266L << (unsigned short)p_37)))) << (unsigned char)((((signed char)p_38 << (signed char)4) >= 0UL) | 0x2D1DDE1BL)) != l_661)) << (short)g_349);
                    }
                    step_hash(394);
                    p_36 = 0x2E1D51B5L;
                }
            }
            else
            {
                step_hash(408);
                for (g_254 = 0; (g_254 <= 2); g_254 += 1)
                {
                    int i, j;
                    step_hash(400);
                    (*l_640) = l_653[(g_254 + 2)];
                    step_hash(406);
                    for (g_161 = 0; (g_161 <= 4); g_161 += 1)
                    {
                        step_hash(404);
                        if ((*l_640))
                            break;
                        step_hash(405);
                        (*l_641) ^= ((short)g_391 + (short)p_36);
                    }
                    step_hash(407);
                    if (p_36)
                        continue;
                }
                step_hash(409);
                if (l_683)
                    break;
            }
            step_hash(430);
            if ((&l_640 != &l_640))
            {
                int **l_695[7][7] = {{(void*)0, &l_641, (void*)0, &l_641, (void*)0, &g_131, (void*)0}, {(void*)0, &l_641, (void*)0, &l_641, (void*)0, &g_131, (void*)0}, {(void*)0, &l_641, (void*)0, &l_641, (void*)0, &g_131, (void*)0}, {(void*)0, &l_641, (void*)0, &l_641, (void*)0, &g_131, (void*)0}, {(void*)0, &l_641, (void*)0, &l_641, (void*)0, &g_131, (void*)0}, {(void*)0, &l_641, (void*)0, &l_641, (void*)0, &g_131, (void*)0}, {(void*)0, &l_641, (void*)0, &l_641, (void*)0, &g_131, (void*)0}};
                unsigned short l_698[8];
                signed char l_700 = 0x91L;
                int i, j;
                for (i = 0; i < 8; i++)
                    l_698[i] = 0UL;
                step_hash(425);
                for (g_474 = 5; (g_474 < (-1)); g_474 -= 3)
                {
                    unsigned l_692 = 2UL;
                    int **l_696 = &g_131;
                    int l_710 = 0xC19B2F67L;
                    unsigned short l_721 = 0x2EDCL;
                    int l_722 = (-6L);
                    step_hash(422);
                    if ((g_387 && ((unsigned short)((0xA4L != ((+((unsigned short)((void*)0 != (*g_447)) * (unsigned short)((unsigned char)((l_692 <= g_274) || (((short)p_38 << (short)13) > 0x76E0343EL)) * (unsigned char)l_698[3]))) && g_633)) < p_37) << (unsigned short)l_699)))
                    {
                        step_hash(416);
                        (*g_448) = &g_2;
                        step_hash(417);
                        if ((***g_447))
                            continue;
                        step_hash(418);
                        l_700 &= (*l_641);
                        step_hash(419);
                        (*l_641) = p_37;
                    }
                    else
                    {
                        step_hash(421);
                        return p_38;
                    }
                    step_hash(423);
                    (*l_640) ^= ((unsigned)func_74(((short)p_38 / (short)p_38), (((p_36 == ((+(p_37 <= (((unsigned short)g_129 * (unsigned short)((unsigned char)1UL / (unsigned char)p_38)) & g_635[0][1]))) > (-(short)(func_74(g_2, g_349, g_349, p_37) && 0x70L)))) < 0xC308F3C6L) != 0x51AAC99AL), l_710, (**l_696)) % (unsigned)(**g_448));
                    step_hash(424);
                    l_722 |= func_74(((((p_36 & func_74((((short)((short)(((((*l_640) | func_74(g_161, g_350, (g_619 | ((***g_447) < (((short)(0x6FFC1F88L <= ((int)p_36 - (int)(65529UL < g_387))) >> (short)p_38) != l_721))), p_37)) >= 0x55L) < g_347[3][1]) >= p_38) - (short)0L) / (short)p_36) ^ p_37), p_37, g_188[3][2], p_38)) == p_36) >= 246UL) | 65535UL), g_286, p_36, p_38);
                }
                step_hash(426);
                (*l_641) = ((1L >= ((unsigned short)(~((&p_36 != (void*)0) != ((unsigned char)p_38 * (unsigned char)l_729))) << (unsigned short)g_2)) ^ 65529UL);
            }
            else
            {
                unsigned char l_730 = 0UL;
                step_hash(428);
                ++l_730;
                step_hash(429);
                if ((*l_641))
                    break;
            }
        }
        else
        {
            step_hash(437);
            for (l_589 = (-24); (l_589 <= 18); l_589 += 3)
            {
                step_hash(435);
                if (p_36)
                    break;
                step_hash(436);
                if (p_37)
                    continue;
            }
        }
        step_hash(439);
        (*l_640) = p_36;
    }
    step_hash(441);
    (*l_640) = (*l_640);
    step_hash(461);
    for (g_580 = 0; (g_580 <= 1); g_580 += 1)
    {
        int *l_742 = &g_2;
        signed char l_743 = 3L;
        unsigned l_751 = 0xA15A82AFL;
        step_hash(459);
        if ((p_36 || (g_404 > (*l_640))))
        {
            step_hash(446);
            (**g_447) = l_742;
            step_hash(447);
            return l_743;
        }
        else
        {
            int l_746 = 0x6DB520FEL;
            int l_747[1];
            int i;
            for (i = 0; i < 1; i++)
                l_747[i] = (-1L);
            step_hash(458);
            for (g_540 = 0; (g_540 <= 1); g_540 += 1)
            {
                int l_744 = 0x88A7BDD9L;
                int l_745 = (-2L);
                int i, j;
                step_hash(452);
                (*g_448) = &p_36;
                step_hash(457);
                if ((4L == (+g_336[(g_580 + 5)][g_540])))
                {
                    step_hash(454);
                    return g_336[(g_580 + 5)][g_540];
                }
                else
                {
                    step_hash(456);
                    --l_748;
                }
            }
        }
        step_hash(460);
        return l_751;
    }
    step_hash(462);
    return (*l_640);
}







static short func_42(unsigned char p_43, unsigned char p_44)
{
    unsigned char l_54 = 0x1AL;
    int l_334 = 0xCFFEF3BCL;
    int l_335 = 0x2EAF47D8L;
    int l_342 = (-7L);
    int l_343[4] = {(-9L), 0x68528BF4L, (-9L), 0x68528BF4L};
    short l_376 = 0xCE44L;
    signed char l_388 = 1L;
    unsigned l_390 = 0x3F4ED036L;
    int ***l_473 = &g_448;
    unsigned l_517 = 1UL;
    int l_535 = 0x0F049638L;
    int *l_565 = &l_343[2];
    int *l_566 = &l_334;
    int *l_567 = (void*)0;
    int *l_568 = (void*)0;
    int *l_569 = &g_474;
    int *l_570 = (void*)0;
    int *l_571 = (void*)0;
    int *l_572 = &l_343[2];
    int *l_573 = (void*)0;
    int *l_574 = &g_274;
    int *l_575 = &l_334;
    int *l_576 = &l_343[2];
    int *l_577 = &g_274;
    int *l_578 = &g_474;
    int *l_579[1];
    int i;
    for (i = 0; i < 1; i++)
        l_579[i] = &g_474;
    step_hash(298);
    if ((((short)((short)((signed char)((signed char)(l_54 != ((unsigned char)func_57(func_63(((((unsigned)g_2 / (unsigned)g_2) || 255UL) & ((signed char)((unsigned char)func_74(((short)(((signed char)(g_2 > ((unsigned short)l_54 << (unsigned short)15)) << (signed char)((short)((g_2 && ((p_44 > ((p_44 && g_2) ^ 0x9EA2L)) && g_2)) >= p_44) - (short)0xCDB7L)) && g_2) + (short)l_54), g_2, p_44, g_2) % (unsigned char)0xFBL) / (signed char)0x7CL)), p_44, p_44, g_2), g_176, l_54, g_161, l_54) * (unsigned char)0x5BL)) % (signed char)g_161) << (signed char)g_2) % (short)l_54) << (short)g_161) < p_43))
    {
        int *l_319 = &g_129;
        int *l_320 = &g_274;
        int l_321 = 0x3F947EABL;
        int *l_322 = (void*)0;
        int *l_323 = (void*)0;
        int *l_324 = &g_129;
        int *l_325 = &g_274;
        int *l_326 = &l_321;
        int *l_327 = &g_129;
        int *l_328 = &g_129;
        int *l_329 = &l_321;
        int *l_330 = &l_321;
        int *l_331 = &g_274;
        int *l_332 = &g_274;
        int *l_333[6] = {&g_274, &g_274, &g_274, &g_274, &g_274, &g_274};
        int l_341 = 1L;
        int l_356 = 0x12270CDBL;
        short l_402 = (-1L);
        int i;
        step_hash(165);
        ++g_336[1][0];
        step_hash(166);
        (*l_330) |= ((short)(l_341 & p_43) << (short)5);
        step_hash(167);
        --g_344;
        step_hash(211);
        for (l_334 = 0; (l_334 <= 4); l_334 += 1)
        {
            short l_352 = 7L;
            int l_357 = 0x777C8B33L;
            int l_389[7][3] = {{0x59952D4AL, 0x59952D4AL, 0x4B82A4E6L}, {0x59952D4AL, 0x59952D4AL, 0x4B82A4E6L}, {0x59952D4AL, 0x59952D4AL, 0x4B82A4E6L}, {0x59952D4AL, 0x59952D4AL, 0x4B82A4E6L}, {0x59952D4AL, 0x59952D4AL, 0x4B82A4E6L}, {0x59952D4AL, 0x59952D4AL, 0x4B82A4E6L}, {0x59952D4AL, 0x59952D4AL, 0x4B82A4E6L}};
            unsigned l_399 = 2UL;
            int l_403[4] = {0x32302CAEL, 1L, 0x32302CAEL, 1L};
            int i, j;
            step_hash(188);
            for (g_286 = 1; (g_286 <= 4); g_286 += 1)
            {
                int l_348 = 0x4D5258D7L;
                int i, j;
                step_hash(185);
                if (g_188[l_334][g_286])
                {
                    step_hash(175);
                    return g_180;
                }
                else
                {
                    int l_351 = 0x9425BB4CL;
                    step_hash(177);
                    g_353--;
                    step_hash(178);
                    (*l_325) = (p_43 || g_188[l_334][g_286]);
                    step_hash(183);
                    for (l_54 = 0; (l_54 <= 7); l_54 += 1)
                    {
                        int i, j;
                        step_hash(182);
                        return g_347[l_54][(l_334 + 1)];
                    }
                    step_hash(184);
                    if (p_44)
                        break;
                }
                step_hash(186);
                ++g_359;
                step_hash(187);
                (*l_327) = l_376;
            }
            step_hash(189);
            (*l_331) = (((unsigned char)(l_352 && ((((((l_357 > ((unsigned)((0xDF26L >= ((unsigned)g_344 / (unsigned)l_342)) >= 1UL) / (unsigned)4294967295UL)) && 0xF271L) == (*l_332)) != g_359) & l_389[4][2]) == l_343[2])) * (unsigned char)g_359) == g_161);
            step_hash(197);
            for (l_54 = 0; (l_54 <= 3); l_54 += 1)
            {
                int **l_394 = &l_325;
                int ***l_395 = (void*)0;
                int ***l_396 = &l_394;
                int i;
                step_hash(193);
                l_390 &= l_343[l_54];
                step_hash(194);
                g_391--;
                step_hash(195);
                (*l_396) = l_394;
                step_hash(196);
                if (l_343[l_54])
                    break;
            }
            step_hash(198);
            (*l_326) |= p_44;
            step_hash(210);
            for (g_180 = 0; (g_180 <= 3); g_180 += 1)
            {
                int l_397 = 0xEF639776L;
                int i;
                step_hash(202);
                if (l_343[g_180])
                    break;
                step_hash(209);
                for (g_391 = 0; (g_391 <= 3); g_391 += 1)
                {
                    int l_398 = 1L;
                    int i;
                    step_hash(206);
                    ++l_399;
                    step_hash(207);
                    --g_405[1][1];
                    step_hash(208);
                    return l_343[g_180];
                }
            }
        }
    }
    else
    {
        int l_430 = 0xAEE4F8E2L;
        int l_431 = 0L;
        int **l_456 = &g_131;
        unsigned l_520 = 6UL;
        step_hash(251);
        for (g_180 = (-24); (g_180 == 50); ++g_180)
        {
            unsigned l_426 = 0xED94B710L;
            int l_432 = 1L;
            unsigned l_436 = 4294967295UL;
            int *l_449 = &l_431;
            step_hash(228);
            for (g_359 = 23; (g_359 > 42); g_359 += 6)
            {
                unsigned l_416 = 0x27DD6BAFL;
                int l_428 = 0L;
                int *l_439 = &l_334;
                step_hash(226);
                for (l_388 = (-14); (l_388 < (-19)); l_388 -= 3)
                {
                    short l_421 = 0x0179L;
                    int *l_427 = &l_343[0];
                    int *l_429[2][5] = {{&g_129, &g_129, &l_342, &g_129, &g_129}, {&g_129, &g_129, &l_342, &g_129, &g_129}};
                    int i, j;
                    step_hash(222);
                    (*l_427) = (p_44 && ((unsigned char)(l_416 != ((unsigned short)((signed char)(l_421 & 4294967295UL) % (signed char)((unsigned char)((unsigned short)l_426 - (unsigned short)((&g_274 != &l_343[1]) > ((void*)0 != &g_274))) % (unsigned char)(-4L))) << (unsigned short)11)) << (unsigned char)6));
                    step_hash(223);
                    l_428 = g_254;
                    step_hash(224);
                    g_433--;
                    step_hash(225);
                    ++l_436;
                }
                step_hash(227);
                (*l_439) |= p_44;
            }
            step_hash(248);
            for (g_344 = 0; (g_344 <= 3); g_344 += 1)
            {
                int *l_440[7];
                unsigned l_441 = 4294967290UL;
                int **l_444[10][8] = {{&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}, {&l_440[3], &l_440[5], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[2], &l_440[5]}};
                int i, j;
                for (i = 0; i < 7; i++)
                    l_440[i] = &l_431;
                step_hash(232);
                l_441++;
                step_hash(233);
                g_131 = &l_343[g_344];
                step_hash(247);
                for (g_161 = 0; (g_161 <= 1); g_161 += 1)
                {
                    int i, j;
                    step_hash(237);
                    l_432 ^= func_74(g_336[(g_161 + 5)][g_161], (func_74((g_405[g_161][(g_161 + 1)] == (p_43 || ((+(func_74(((short)(((0x82F8L > (l_436 >= (!((void*)0 != g_447)))) & 0xAF9BL) | (**g_448)) << (short)9), p_43, g_314, (***g_447)) >= l_436)) | g_344))), g_405[g_161][(g_161 + 1)], p_44, (***g_447)) == p_44), p_44, (***g_447));
                    step_hash(238);
                    if ((*g_131))
                        continue;
                    step_hash(239);
                    (*g_131) |= p_43;
                    step_hash(246);
                    for (g_433 = 0; (g_433 <= 1); g_433 += 1)
                    {
                        step_hash(243);
                        (**g_448) &= (&l_431 == &l_335);
                        step_hash(244);
                        if ((***g_447))
                            continue;
                        step_hash(245);
                        if ((**g_448))
                            continue;
                    }
                }
            }
            step_hash(249);
            (*l_449) = 0L;
            step_hash(250);
            l_335 = ((*l_449) || g_188[3][1]);
        }
        step_hash(285);
        for (g_254 = 0; (g_254 <= 3); g_254 += 1)
        {
            unsigned char l_489 = 253UL;
            int l_500 = 0L;
            int i;
            step_hash(255);
            l_343[g_254] = ((unsigned short)(~(((signed char)(((unsigned char)(((void*)0 == l_456) >= ((unsigned short)l_343[g_254] >> (unsigned short)((((short)(&g_448 == &g_448) - (short)g_391) == p_44) != g_161))) % (unsigned char)((signed char)((unsigned char)l_343[g_254] >> (unsigned char)g_336[1][0]) - (signed char)255UL)) >= (-10L)) / (signed char)l_343[2]) & g_433)) + (unsigned short)g_353);
            step_hash(282);
            if ((g_344 < p_44))
            {
                unsigned short l_485 = 2UL;
                int *l_501 = &l_335;
                step_hash(257);
                (*g_448) = (*l_456);
                step_hash(277);
                for (l_430 = 1; (l_430 <= 4); l_430 += 1)
                {
                    int l_488 = 0x8EE25456L;
                    int *l_492 = &g_129;
                    int i, j;
                    step_hash(261);
                    g_274 &= (g_350 != 0UL);
                    step_hash(268);
                    if (((*g_447) == (void*)0))
                    {
                        step_hash(263);
                        (*l_456) = (**l_473);
                    }
                    else
                    {
                        unsigned l_499 = 4294967295UL;
                        step_hash(265);
                        l_343[g_254] = ((unsigned)g_336[1][0] - (unsigned)((**g_447) == l_492));
                        step_hash(266);
                        (*l_492) |= 0xD4CB0198L;
                        step_hash(267);
                        l_500 &= (((unsigned short)0x41E1L + (unsigned short)func_74(((unsigned char)((p_43 <= l_343[g_254]) <= ((0xD583L == p_44) < ((unsigned)p_44 / (unsigned)p_44))) + (unsigned char)(~(0xAA89L & g_180))), g_391, l_499, p_43)) || (*l_492));
                    }
                    step_hash(276);
                    for (p_44 = 0; (p_44 <= 4); p_44 += 1)
                    {
                        step_hash(272);
                        l_501 = (void*)0;
                        step_hash(273);
                        if (p_44)
                            continue;
                        step_hash(274);
                        (*g_448) = (**g_447);
                        step_hash(275);
                        if (p_43)
                            continue;
                    }
                }
                step_hash(278);
                l_431 &= p_43;
                step_hash(279);
                (**g_447) = &l_343[g_254];
            }
            else
            {
                unsigned l_502[3][6] = {{0x220C7741L, 1UL, 4294967291UL, 4294967291UL, 1UL, 0x220C7741L}, {0x220C7741L, 1UL, 4294967291UL, 4294967291UL, 1UL, 0x220C7741L}, {0x220C7741L, 1UL, 4294967291UL, 4294967291UL, 1UL, 0x220C7741L}};
                int *l_503 = &g_274;
                int i, j;
                step_hash(281);
                (*l_503) ^= l_502[1][5];
            }
            step_hash(283);
            (**l_473) = (**g_447);
            step_hash(284);
            g_129 &= ((unsigned char)(1L > (((unsigned short)g_387 % (unsigned short)(0x14DC4E3CL | (l_489 || func_74((((-(signed char)p_44) < (p_44 <= p_44)) | l_489), p_43, g_391, p_44)))) <= g_347[2][6])) >> (unsigned char)g_307);
        }
        step_hash(297);
        if (p_44)
        {
            step_hash(287);
            return p_44;
        }
        else
        {
            step_hash(296);
            if (l_520)
            {
                step_hash(290);
                return p_44;
            }
            else
            {
                int *l_521 = (void*)0;
                int *l_522 = &g_274;
                step_hash(292);
                (**g_447) = (*g_448);
                step_hash(293);
                (*l_522) = p_43;
                step_hash(294);
                (*l_522) = p_44;
                step_hash(295);
                return g_391;
            }
        }
    }
    step_hash(344);
    if (((signed char)((func_74((l_390 || p_43), l_376, p_44, p_44) ^ 0x3944L) | l_535) % (signed char)0x6EL))
    {
        step_hash(341);
        for (g_254 = 0; (g_254 <= 3); g_254 += 1)
        {
            short l_559[9][6] = {{1L, 4L, 0L, (-1L), (-1L), 0L}, {1L, 4L, 0L, (-1L), (-1L), 0L}, {1L, 4L, 0L, (-1L), (-1L), 0L}, {1L, 4L, 0L, (-1L), (-1L), 0L}, {1L, 4L, 0L, (-1L), (-1L), 0L}, {1L, 4L, 0L, (-1L), (-1L), 0L}, {1L, 4L, 0L, (-1L), (-1L), 0L}, {1L, 4L, 0L, (-1L), (-1L), 0L}, {1L, 4L, 0L, (-1L), (-1L), 0L}};
            int i, j;
            step_hash(303);
            (*g_448) = (*g_448);
            step_hash(312);
            for (l_342 = 0; (l_342 <= 1); l_342 += 1)
            {
                step_hash(311);
                for (g_274 = 0; (g_274 <= 3); g_274 += 1)
                {
                    int *l_541 = &l_343[2];
                    step_hash(310);
                    (**l_473) = l_541;
                }
            }
            step_hash(340);
            for (l_335 = 1; (l_335 >= 0); l_335 -= 1)
            {
                int l_555 = 0x9B7F5648L;
                int i, j;
                step_hash(327);
                for (g_540 = 0; (g_540 <= 3); g_540 += 1)
                {
                    int i, j;
                    step_hash(319);
                    l_343[g_254] &= (g_405[l_335][g_540] >= g_188[(g_254 + 1)][g_254]);
                    step_hash(325);
                    for (g_387 = 0; (g_387 <= 3); g_387 += 1)
                    {
                        int i, j;
                        step_hash(323);
                        l_343[g_254] = ((void*)0 != (*g_447));
                        step_hash(324);
                        l_343[g_254] = func_74(l_343[g_540], g_188[(g_540 + 1)][g_387], g_405[l_335][(g_540 + 2)], p_44);
                    }
                    step_hash(326);
                    return l_343[g_254];
                }
                step_hash(328);
                l_343[g_254] ^= g_405[l_335][(g_254 + 2)];
                step_hash(339);
                for (g_316 = 0; (g_316 <= 1); g_316 += 1)
                {
                    int l_558 = 0x9DBB7E0FL;
                    step_hash(332);
                    l_559[2][2] = (((unsigned short)p_43 >> (unsigned short)8) < ((unsigned short)(1UL | ((short)((short)(((unsigned char)((short)p_43 << (short)4) + (unsigned char)g_176) > p_44) + (short)0x7F8EL) >> (short)g_349)) << (unsigned short)p_43));
                    step_hash(338);
                    for (g_314 = 0; (g_314 <= 5); g_314 += 1)
                    {
                        step_hash(336);
                        (*g_448) = (*g_448);
                        step_hash(337);
                        (**l_473) = (**g_447);
                    }
                }
            }
        }
    }
    else
    {
        int *l_560 = (void*)0;
        int *l_561[2];
        int i;
        for (i = 0; i < 2; i++)
            l_561[i] = &l_343[2];
        step_hash(343);
        --g_562;
    }
    step_hash(345);
    l_334 &= (p_43 < (&g_448 != (void*)0));
    step_hash(346);
    ++g_580;
    step_hash(347);
    return p_44;
}







static unsigned char func_57(signed char p_58, short p_59, unsigned char p_60, signed char p_61, short p_62)
{
    int *l_187[6][5] = {{&g_129, &g_129, (void*)0, &g_129, &g_129}, {&g_129, &g_129, (void*)0, &g_129, &g_129}, {&g_129, &g_129, (void*)0, &g_129, &g_129}, {&g_129, &g_129, (void*)0, &g_129, &g_129}, {&g_129, &g_129, (void*)0, &g_129, &g_129}, {&g_129, &g_129, (void*)0, &g_129, &g_129}};
    short l_209 = 0x1B59L;
    signed char l_212[3][5] = {{0x99L, 0x99L, 3L, 0x99L, 0x99L}, {0x99L, 0x99L, 3L, 0x99L, 0x99L}, {0x99L, 0x99L, 3L, 0x99L, 0x99L}};
    signed char l_215 = 0x3AL;
    short l_243 = 0x0293L;
    int i, j;
    step_hash(92);
    g_188[3][2] ^= (!(*g_131));
    step_hash(157);
    if (((((signed char)p_62 << (signed char)7) != (p_61 <= (((signed char)((unsigned short)p_58 - (unsigned short)65531UL) * (signed char)p_59) >= (func_74((p_60 | ((+((unsigned short)((short)p_62 % (short)((int)((void*)0 == &l_187[4][0]) / (int)(*g_131))) >> (unsigned short)p_60)) > g_180)), g_180, g_188[2][2], (*g_131)) == 0xF072L)))) < p_60))
    {
        int **l_203 = &l_187[0][1];
        short l_208 = 0xFDC0L;
        unsigned char l_226 = 0x5DL;
        int l_244 = (-3L);
        unsigned short l_247 = 1UL;
        int l_252 = 0xC25EC4CEL;
        int l_298 = 1L;
        step_hash(94);
        l_209 = (((signed char)0x1DL >> (signed char)(l_203 != l_203)) & ((unsigned short)g_161 - (unsigned short)(((*g_131) > l_208) <= (l_187[2][3] != (*l_203)))));
        step_hash(151);
        if (((unsigned)g_180 + (unsigned)((func_74(l_212[2][0], p_62, g_161, p_60) && func_74(p_61, ((func_74(((short)func_74(((void*)0 == &g_131), g_161, g_2, p_62) % (short)6L), g_176, g_188[2][0], (*g_131)) || 0UL) >= p_59), g_188[3][2], p_61)) & l_215)))
        {
            step_hash(105);
            for (g_129 = 0; (g_129 <= 2); g_129 += 1)
            {
                step_hash(99);
                if (p_59)
                    break;
                step_hash(104);
                for (g_176 = 0; (g_176 <= 2); g_176 += 1)
                {
                    int i, j;
                    step_hash(103);
                    return l_212[g_176][(g_129 + 1)];
                }
            }
        }
        else
        {
            int **l_231 = &l_187[4][0];
            short l_232 = 4L;
            int l_239 = 0L;
            int l_251 = 0x1BEB0008L;
            unsigned l_289 = 0xBA3A8752L;
            step_hash(131);
            if (((signed char)(((~p_60) | p_59) <= ((unsigned char)func_74(((short)((((unsigned short)((short)(1UL > (func_63(l_226, func_74(((unsigned)((signed char)(((void*)0 != l_231) <= g_176) << (signed char)1) + (unsigned)(g_176 == g_2)), g_2, p_60, p_61), p_59, g_180) & g_188[2][5])) >> (short)p_60) + (unsigned short)g_161) | (-1L)) >= p_58) << (short)g_161), p_59, p_61, l_232) >> (unsigned char)6)) * (signed char)p_62))
            {
                unsigned l_233 = 0xBF60BB93L;
                int l_250 = (-2L);
                int l_253 = 0x6F3E09BFL;
                step_hash(108);
                l_233 |= (*g_131);
                step_hash(127);
                for (p_60 = 0; (p_60 <= 42); ++p_60)
                {
                    unsigned l_240 = 0x503FB3B2L;
                    int l_248 = 0x58BBD954L;
                    step_hash(112);
                    (*l_203) = l_187[5][4];
                    step_hash(119);
                    for (g_180 = 0; (g_180 > 3); g_180 += 7)
                    {
                        int l_238 = 1L;
                        step_hash(116);
                        --l_240;
                        step_hash(117);
                        if (l_243)
                            continue;
                        step_hash(118);
                        l_244 ^= (*g_131);
                    }
                    step_hash(126);
                    if (((signed char)l_247 * (signed char)g_188[3][2]))
                    {
                        step_hash(121);
                        return l_240;
                    }
                    else
                    {
                        int l_249[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_249[i] = 1L;
                        step_hash(123);
                        g_254--;
                        step_hash(124);
                        (*l_231) = &g_2;
                        step_hash(125);
                        return p_59;
                    }
                }
            }
            else
            {
                step_hash(129);
                (*l_203) = &g_2;
                step_hash(130);
                (*g_131) = (*g_131);
            }
            step_hash(132);
            (*g_131) = (((signed char)(((void*)0 == &g_131) | (((unsigned char)(((signed char)(((-1L) | g_188[3][2]) | ((void*)0 == (*l_203))) >> (signed char)4) ^ g_188[0][2]) + (unsigned char)((unsigned char)(&g_2 != (*l_203)) * (unsigned char)0xE2L)) ^ g_2)) >> (signed char)7) >= 0xB0L);
            step_hash(149);
            if (((p_59 != g_129) == ((void*)0 != &g_131)))
            {
                int *l_269[9][4] = {{&l_244, &g_2, &l_244, &g_2}, {&l_244, &g_2, &l_244, &g_2}, {&l_244, &g_2, &l_244, &g_2}, {&l_244, &g_2, &l_244, &g_2}, {&l_244, &g_2, &l_244, &g_2}, {&l_244, &g_2, &l_244, &g_2}, {&l_244, &g_2, &l_244, &g_2}, {&l_244, &g_2, &l_244, &g_2}, {&l_244, &g_2, &l_244, &g_2}};
                int i, j;
                step_hash(134);
                g_274 &= ((signed char)func_74(p_60, ((short)0x779DL + (short)(l_187[4][0] == l_269[0][0])), p_58, ((short)p_58 << (short)((signed char)p_61 - (signed char)func_63(((&g_2 != l_269[0][0]) == p_62), g_254, g_188[3][2], p_58)))) * (signed char)g_254);
                step_hash(145);
                if ((*g_131))
                {
                    int l_281 = 0x7C646956L;
                    step_hash(142);
                    for (g_254 = (-2); (g_254 < 18); g_254 += 7)
                    {
                        unsigned short l_284 = 0xD492L;
                        int l_285 = (-1L);
                        step_hash(139);
                        (*g_131) = (*g_131);
                        step_hash(140);
                        l_269[1][3] = &g_129;
                        step_hash(141);
                        l_285 ^= (g_2 || (func_63(((unsigned short)((int)l_281 - (int)g_254) + (unsigned short)(-2L)), ((unsigned short)func_63(g_180, g_254, ((void*)0 == (*l_203)), (~0xC744L)) * (unsigned short)l_284), l_284, g_274) > 8L));
                    }
                }
                else
                {
                    step_hash(144);
                    (*l_203) = &g_274;
                }
            }
            else
            {
                step_hash(147);
                (*g_131) = p_58;
                step_hash(148);
                g_286++;
            }
            step_hash(150);
            (*g_131) &= (65535UL || l_289);
        }
        step_hash(152);
        (*g_131) = (g_161 != ((unsigned)((unsigned short)(((unsigned char)func_74(p_59, g_176, ((short)(func_74(l_298, p_61, g_188[3][2], (&l_187[4][0] == (void*)0)) ^ p_59) + (short)p_61), p_61) * (unsigned char)0L) | p_60) % (unsigned short)0x1E84L) - (unsigned)p_59));
    }
    else
    {
        signed char l_299 = 5L;
        int l_304 = 0x7649E829L;
        int l_305 = 0x5E0AE813L;
        int l_306 = 0L;
        step_hash(154);
        (*g_131) = ((g_176 <= l_299) < (((unsigned char)(g_176 == ((l_299 >= ((unsigned)g_161 + (unsigned)(g_2 | ((void*)0 == &g_131)))) == (0xCD54L == (-1L)))) >> (unsigned char)0) & p_59));
        step_hash(155);
        g_131 = l_187[4][0];
        step_hash(156);
        g_307++;
    }
    step_hash(162);
    for (g_274 = 0; (g_274 < 5); g_274 += 4)
    {
        short l_312[4];
        int l_313 = 0x8AA95A07L;
        int l_315[1][4] = {{0xD4A61B79L, 0x946A76BEL, 0xD4A61B79L, 0x946A76BEL}};
        int i, j;
        for (i = 0; i < 4; i++)
            l_312[i] = 0xCE60L;
        step_hash(161);
        g_316--;
    }
    step_hash(163);
    return g_176;
}







static signed char func_63(unsigned char p_64, unsigned char p_65, short p_66, unsigned short p_67)
{
    int *l_91 = &g_2;
    int **l_90 = &l_91;
    int l_99 = 0xCD2740D6L;
    unsigned char l_105 = 254UL;
    int l_175 = 1L;
    step_hash(11);
    (*l_90) = &g_2;
    step_hash(12);
    (*l_90) = (void*)0;
    step_hash(88);
    if (((signed char)g_2 / (signed char)g_2))
    {
        unsigned l_115 = 4294967288UL;
        int l_128 = 0L;
        int *l_150 = &l_128;
        int *l_151 = &l_128;
        step_hash(77);
        for (p_67 = (-4); (p_67 > 48); p_67 += 6)
        {
            int **l_96[5];
            signed char l_137 = 0xE0L;
            int i;
            for (i = 0; i < 5; i++)
                l_96[i] = &l_91;
        }
        step_hash(78);
        (*l_151) = (*g_131);
    }
    else
    {
        int *l_179[5][8] = {{&l_99, &g_129, &g_2, &g_129, &l_99, &l_99, &l_99, &g_129}, {&l_99, &g_129, &g_2, &g_129, &l_99, &l_99, &l_99, &g_129}, {&l_99, &g_129, &g_2, &g_129, &l_99, &l_99, &l_99, &g_129}, {&l_99, &g_129, &g_2, &g_129, &l_99, &l_99, &l_99, &g_129}, {&l_99, &g_129, &g_2, &g_129, &l_99, &l_99, &l_99, &g_129}};
        int i, j;
        step_hash(80);
        --g_180;
        step_hash(81);
        (*g_131) &= ((unsigned char)g_176 - (unsigned char)((int)0xFD62B9E9L / (int)0x82FD2184L));
        step_hash(86);
        for (p_65 = 1; (p_65 <= 4); p_65 += 1)
        {
            step_hash(85);
            return p_64;
        }
        step_hash(87);
        return p_67;
    }
    step_hash(89);
    (*l_90) = (*l_90);
    step_hash(90);
    return p_65;
}







static unsigned char func_74(unsigned p_75, unsigned p_76, short p_77, int p_78)
{
    unsigned short l_89 = 0x3301L;
    step_hash(8);
    l_89 &= (((g_2 > 0x5D26L) & p_75) == (p_78 == p_77));
    step_hash(9);
    return g_2;
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_129, "g_129", print_hash_value);
    transparent_crc(g_161, "g_161", print_hash_value);
    transparent_crc(g_176, "g_176", print_hash_value);
    transparent_crc(g_180, "g_180", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_188[i][j], "g_188[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_254, "g_254", print_hash_value);
    transparent_crc(g_274, "g_274", print_hash_value);
    transparent_crc(g_286, "g_286", print_hash_value);
    transparent_crc(g_307, "g_307", print_hash_value);
    transparent_crc(g_314, "g_314", print_hash_value);
    transparent_crc(g_316, "g_316", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transparent_crc(g_336[i][j], "g_336[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_344, "g_344", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(g_347[i][j], "g_347[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_349, "g_349", print_hash_value);
    transparent_crc(g_350, "g_350", print_hash_value);
    transparent_crc(g_353, "g_353", print_hash_value);
    transparent_crc(g_358, "g_358", print_hash_value);
    transparent_crc(g_359, "g_359", print_hash_value);
    transparent_crc(g_387, "g_387", print_hash_value);
    transparent_crc(g_391, "g_391", print_hash_value);
    transparent_crc(g_404, "g_404", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 6; j++)
        {
            transparent_crc(g_405[i][j], "g_405[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_433, "g_433", print_hash_value);
    transparent_crc(g_474, "g_474", print_hash_value);
    transparent_crc(g_540, "g_540", print_hash_value);
    transparent_crc(g_554, "g_554", print_hash_value);
    transparent_crc(g_562, "g_562", print_hash_value);
    transparent_crc(g_580, "g_580", print_hash_value);
    transparent_crc(g_619, "g_619", print_hash_value);
    transparent_crc(g_633, "g_633", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 5; j++)
        {
            transparent_crc(g_635[i][j], "g_635[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(g_754[i][j], "g_754[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_768, "g_768", print_hash_value);
    for (i = 0; i < 2; i++)
    {
        transparent_crc(g_1005[i], "g_1005[i]", print_hash_value);
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
