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
static unsigned char g_16 = 8UL;
static int g_31 = 5L;
static int g_33 = 5L;
static int g_75 = 1L;
static int g_76 = 1L;
static int g_77 = (-5L);
static int *g_84 = &g_77;
static int g_94 = 0x27FA81B2L;
static unsigned g_95[8] = {4294967293UL, 1UL, 4294967293UL, 1UL, 4294967293UL, 1UL, 4294967293UL, 1UL};
static unsigned g_182[5] = {1UL, 1UL, 1UL, 1UL, 1UL};
static signed char g_188 = 0xFCL;
static int g_189 = (-5L);
static short g_190 = 0L;
static unsigned g_191 = 4294967286UL;
static int g_232 = 0xA1BE2514L;
static unsigned g_233 = 3UL;
static short g_283[7] = {0x17F4L, 0x50A7L, 0x17F4L, 0x50A7L, 0x17F4L, 0x50A7L, 0x17F4L};
static signed char g_284[8][3] = {{1L, 1L, 1L}, {1L, 1L, 1L}, {1L, 1L, 1L}, {1L, 1L, 1L}, {1L, 1L, 1L}, {1L, 1L, 1L}, {1L, 1L, 1L}, {1L, 1L, 1L}};
static signed char g_285 = (-2L);
static unsigned g_286 = 0x2992A0FDL;
static unsigned short g_307 = 65532UL;
static int g_312 = 0x93D39C3CL;
static int g_313 = 0xCFED7D17L;
static signed char g_336 = 0x8CL;
static signed char g_337 = 0x32L;
static unsigned char g_338[9][8] = {{0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}, {0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}, {0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}, {0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}, {0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}, {0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}, {0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}, {0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}, {0x73L, 0xC2L, 255UL, 1UL, 2UL, 0UL, 0xE8L, 255UL}};
static int ***g_355 = (void*)0;
static signed char g_406 = 0x40L;
static unsigned char g_407 = 0xBCL;
static int g_449 = 0x7C810448L;
static int g_514 = 0x35D05901L;
static signed char g_515 = 0xB5L;
static int g_516[4][3] = {{0x8D607E72L, 8L, 0x8D607E72L}, {0x8D607E72L, 8L, 0x8D607E72L}, {0x8D607E72L, 8L, 0x8D607E72L}, {0x8D607E72L, 8L, 0x8D607E72L}};
static int g_549[3] = {(-1L), (-1L), (-1L)};
static short g_633[8][8] = {{0L, 0x80CEL, 0xE9F8L, 0x80CEL, 0L, 0x5E94L, 0L, 0x80CEL}, {0L, 0x80CEL, 0xE9F8L, 0x80CEL, 0L, 0x5E94L, 0L, 0x80CEL}, {0L, 0x80CEL, 0xE9F8L, 0x80CEL, 0L, 0x5E94L, 0L, 0x80CEL}, {0L, 0x80CEL, 0xE9F8L, 0x80CEL, 0L, 0x5E94L, 0L, 0x80CEL}, {0L, 0x80CEL, 0xE9F8L, 0x80CEL, 0L, 0x5E94L, 0L, 0x80CEL}, {0L, 0x80CEL, 0xE9F8L, 0x80CEL, 0L, 0x5E94L, 0L, 0x80CEL}, {0L, 0x80CEL, 0xE9F8L, 0x80CEL, 0L, 0x5E94L, 0L, 0x80CEL}, {0L, 0x80CEL, 0xE9F8L, 0x80CEL, 0L, 0x5E94L, 0L, 0x80CEL}};
static unsigned short g_706[7] = {0x808DL, 0x808DL, 8UL, 0x808DL, 0x808DL, 8UL, 0x808DL};
static int *g_783[3] = {&g_77, &g_77, &g_77};
static int g_903 = 0xF2017E75L;
static unsigned g_904 = 0xAA62AC66L;
static unsigned func_1(void);
static int func_11(signed char p_12, unsigned p_13, int p_14, signed char p_15);
static unsigned short func_17(signed char p_18, unsigned char p_19, unsigned p_20, unsigned char p_21);
static int * func_28(int * p_29);
static signed char func_34(int p_35, int * p_36, unsigned short p_37, int * p_38);
static unsigned short func_42(unsigned char p_43, int p_44, int * p_45);
static int * func_47(unsigned char p_48, int * p_49, int * p_50, int * p_51, int * p_52);
static int * func_54(int p_55, signed char p_56, int * p_57, unsigned p_58);
static signed char func_59(unsigned p_60, short p_61, int * p_62, int * p_63, signed char p_64);
static int * func_66(unsigned char p_67, int * p_68, int * p_69);
static unsigned func_1(void)
{
    int l_10 = (-3L);
    unsigned l_901 = 0xE10BFCA3L;
    int *l_902[9] = {&g_516[0][1], &g_903, &g_516[0][1], &g_903, &g_516[0][1], &g_903, &g_516[0][1], &g_903, &g_516[0][1]};
    int l_907 = 0x4934D44CL;
    unsigned l_908 = 0UL;
    int i;
    step_hash(605);
    g_903 &= (((signed char)((short)((((unsigned)0x9ED080C1L + (unsigned)((short)0xF3C3L << (short)(l_10 || func_11(l_10, l_10, g_16, (((((func_17(l_10, ((short)(l_10 || (((signed char)g_16 >> (signed char)g_16) == 0L)) << (short)8), g_16, l_10) || 2L) <= 0xCB2EL) <= 0x82842D44L) ^ 65534UL) <= l_10))))) & l_901) > l_901) - (short)g_285) << (signed char)2) > l_901);
    step_hash(606);
    g_904++;
    step_hash(607);
    ++l_908;
    step_hash(608);
    return g_904;
}
static int func_11(signed char p_12, unsigned p_13, int p_14, signed char p_15)
{
    unsigned l_894 = 0xCC28BAF9L;
    int ***l_897 = (void*)0;
    step_hash(603);
    for (g_232 = 4; (g_232 >= 2); g_232 -= 1)
    {
        int *l_892 = &g_76;
        int *l_893 = &g_549[1];
        int **l_899 = &g_783[2];
        int ***l_898 = &l_899;
        unsigned l_900 = 4294967295UL;
        int i;
        step_hash(592);
        if (g_706[g_232])
            break;
        step_hash(593);
        ++l_894;
        step_hash(602);
        for (g_16 = 0; (g_16 <= 6); g_16 += 1)
        {
            step_hash(601);
            if (((l_897 == l_898) & p_13))
            {
                step_hash(598);
                (*l_892) = p_14;
            }
            else
            {
                step_hash(600);
                return l_900;
            }
        }
    }
    step_hash(604);
    return p_12;
}
static unsigned short func_17(signed char p_18, unsigned char p_19, unsigned p_20, unsigned char p_21)
{
    int *l_30 = &g_31;
    int **l_782[6] = {&l_30, &l_30, &l_30, &l_30, &l_30, &l_30};
    int l_798 = 0xC86177A6L;
    signed char l_801 = 6L;
    unsigned char l_805 = 1UL;
    int *l_829 = (void*)0;
    int *l_836 = &g_549[2];
    unsigned l_861[8][9] = {{1UL, 4UL, 0x42D479A7L, 4UL, 1UL, 0UL, 0x42D479A7L, 0UL, 1UL}, {1UL, 4UL, 0x42D479A7L, 4UL, 1UL, 0UL, 0x42D479A7L, 0UL, 1UL}, {1UL, 4UL, 0x42D479A7L, 4UL, 1UL, 0UL, 0x42D479A7L, 0UL, 1UL}, {1UL, 4UL, 0x42D479A7L, 4UL, 1UL, 0UL, 0x42D479A7L, 0UL, 1UL}, {1UL, 4UL, 0x42D479A7L, 4UL, 1UL, 0UL, 0x42D479A7L, 0UL, 1UL}, {1UL, 4UL, 0x42D479A7L, 4UL, 1UL, 0UL, 0x42D479A7L, 0UL, 1UL}, {1UL, 4UL, 0x42D479A7L, 4UL, 1UL, 0UL, 0x42D479A7L, 0UL, 1UL}, {1UL, 4UL, 0x42D479A7L, 4UL, 1UL, 0UL, 0x42D479A7L, 0UL, 1UL}};
    unsigned short l_866 = 65529UL;
    unsigned short l_890[5];
    unsigned char l_891 = 2UL;
    int i, j;
    for (i = 0; i < 5; i++)
        l_890[i] = 0x869CL;
    step_hash(501);
    g_783[2] = func_28(l_30);
    step_hash(534);
    for (p_20 = 0; (p_20 != 51); p_20 += 9)
    {
        int **l_790[7] = {&g_783[2], &g_783[2], &g_783[2], &g_783[2], &g_783[2], &g_783[2], &g_783[2]};
        int *l_791 = (void*)0;
        unsigned l_821 = 4294967295UL;
        unsigned l_827 = 2UL;
        int i;
    }
    step_hash(585);
    for (g_233 = 0; (g_233 <= 5); g_233 += 1)
    {
        unsigned char l_837 = 0xAEL;
        int l_842 = 0x47E3965CL;
        step_hash(583);
        for (g_313 = 5; (g_313 >= 0); g_313 -= 1)
        {
            int *l_838 = &g_549[2];
            int *l_867[4] = {(void*)0, &g_313, (void*)0, &g_313};
            int i;
        }
        step_hash(584);
        (*l_30) ^= ((((((signed char)((short)((short)p_19 / (short)g_283[3]) >> (short)0) / (signed char)g_549[2]) == ((unsigned short)((g_233 ^ ((unsigned char)l_837 + (unsigned char)(0x67L == ((unsigned char)(g_286 == (0xB605AB1EL | 5UL)) >> (unsigned char)3)))) >= 0xA3E1L) >> (unsigned short)p_21)) > 253UL) > p_18) > g_307);
    }
    step_hash(586);
    (*l_836) = ((unsigned)(((unsigned char)(0L > ((((1L ^ ((signed char)p_21 << (signed char)((short)(&g_516[1][2] == &g_549[2]) + (short)(-10L)))) | ((signed char)g_191 / (signed char)func_34(p_21, &g_76, l_890[3], &g_189))) & 0x3DL) & 0x2BBEL)) % (unsigned char)0x0BL) ^ l_891) % (unsigned)0x0D186CD5L);
    step_hash(587);
    return g_75;
}
static int * func_28(int * p_29)
{
    unsigned short l_32[5][7] = {{0x5641L, 0x69FFL, 0xE215L, 0x69FFL, 0x5641L, 0x48AAL, 0x5641L}, {0x5641L, 0x69FFL, 0xE215L, 0x69FFL, 0x5641L, 0x48AAL, 0x5641L}, {0x5641L, 0x69FFL, 0xE215L, 0x69FFL, 0x5641L, 0x48AAL, 0x5641L}, {0x5641L, 0x69FFL, 0xE215L, 0x69FFL, 0x5641L, 0x48AAL, 0x5641L}, {0x5641L, 0x69FFL, 0xE215L, 0x69FFL, 0x5641L, 0x48AAL, 0x5641L}};
    int *l_41 = (void*)0;
    int l_670 = 0x70C21215L;
    int l_672 = 0x3F67168FL;
    int l_717 = (-1L);
    int l_722 = 0xE9669BACL;
    int l_723 = 0x150A33C5L;
    int l_724 = (-5L);
    int l_725[5][1];
    int *l_769 = &g_549[2];
    int *l_770 = &g_549[2];
    int *l_771 = &g_313;
    int *l_772 = &g_516[2][0];
    int *l_773 = &g_33;
    int *l_774[7] = {&l_717, &l_717, &g_189, &l_717, &l_717, &g_189, &l_717};
    short l_775[3];
    unsigned l_776 = 0xF74538BCL;
    int **l_781 = &l_769;
    int i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 1; j++)
            l_725[i][j] = (-6L);
    }
    for (i = 0; i < 3; i++)
        l_775[i] = 1L;
    step_hash(496);
    for (g_31 = 1; (g_31 <= 4); g_31 += 1)
    {
        int **l_655 = &l_41;
        int ***l_654 = &l_655;
        int l_673 = (-1L);
        int l_674 = 0x830F1EC4L;
        signed char l_690 = 0L;
        int l_718 = (-6L);
        int l_721[4][10];
        short l_735 = 1L;
        int i, j;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 10; j++)
                l_721[i][j] = 7L;
        }
        step_hash(450);
        if ((0x7B1A0949L > ((void*)0 != &g_31)))
        {
            int l_649 = 1L;
            step_hash(432);
            for (g_33 = 1; (g_33 <= 4); g_33 += 1)
            {
                signed char l_46[2][4] = {{0x6AL, 0x98L, 0x6AL, 0x98L}, {0x6AL, 0x98L, 0x6AL, 0x98L}};
                int l_650 = (-2L);
                int i, j;
            }
        }
        else
        {
            int l_656 = 0x5DA6A106L;
            unsigned char l_667 = 0xCFL;
            int l_668[8] = {0x1138B450L, (-2L), 0x1138B450L, (-2L), 0x1138B450L, (-2L), 0x1138B450L, (-2L)};
            int *l_689[6] = {(void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0};
            int i;
            step_hash(446);
            for (g_449 = 3; (g_449 >= 0); g_449 -= 1)
            {
                int *l_651[3][6] = {{(void*)0, &g_189, &g_516[0][1], &g_516[0][1], &g_189, (void*)0}, {(void*)0, &g_189, &g_516[0][1], &g_516[0][1], &g_189, (void*)0}, {(void*)0, &g_189, &g_516[0][1], &g_516[0][1], &g_189, (void*)0}};
                unsigned char l_675 = 0x3CL;
                int i, j;
                step_hash(437);
                p_29 = l_651[0][2];
            }
            step_hash(447);
            if (l_668[2])
                continue;
            step_hash(448);
            l_673 ^= (*g_84);
            step_hash(449);
            l_690 |= (*g_84);
        }
        step_hash(451);
        (*g_84) = 0x56FFD2D0L;
        step_hash(452);
        (**l_654) = p_29;
        step_hash(453);
        for (g_307 = 0; g_307 < 5; g_307 += 1)
        {
            g_182[g_307] = 1UL;
        }
        step_hash(495);
        for (g_313 = 0; (g_313 <= 4); g_313 += 1)
        {
            short l_699 = 0x995FL;
            int l_715 = 0x37EEA187L;
            int l_716 = 0x3E75476CL;
            int l_719 = 1L;
            int l_720[2];
            int l_734 = (-10L);
            unsigned char l_746 = 0xE1L;
            unsigned l_766 = 3UL;
            int i;
            for (i = 0; i < 2; i++)
                l_720[i] = 0xC46755B4L;
        }
    }
    step_hash(497);
    --l_776;
    step_hash(498);
    (*l_781) = func_54((*g_84), ((&l_774[1] != (void*)0) <= (*l_770)), &g_189, (((short)g_16 + (short)g_95[4]) >= (-1L)));
    step_hash(499);
    (**l_781) &= (*g_84);
    step_hash(500);
    return p_29;
}







static signed char func_34(int p_35, int * p_36, unsigned short p_37, int * p_38)
{
    int *l_417 = &g_75;
    int ***l_455 = (void*)0;
    unsigned char l_461 = 0x9BL;
    short l_525 = 0L;
    signed char l_529 = 0x97L;
    int l_534 = 0xDF4D3023L;
    int l_548[9];
    signed char l_551[5][3];
    unsigned short l_570[4] = {65535UL, 65533UL, 65535UL, 65533UL};
    int *l_589 = &g_75;
    unsigned char l_637[2][10] = {{246UL, 250UL, 0x4CL, 250UL, 246UL, 250UL, 0x4CL, 250UL, 246UL, 250UL}, {246UL, 250UL, 0x4CL, 250UL, 246UL, 250UL, 0x4CL, 250UL, 246UL, 250UL}};
    int i, j;
    for (i = 0; i < 9; i++)
        l_548[i] = 0x208B8FC1L;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
            l_551[i][j] = 0L;
    }
    step_hash(306);
    for (g_188 = 4; (g_188 >= 0); g_188 -= 1)
    {
        int **l_418 = &g_84;
        unsigned char l_426[5];
        int l_427 = (-1L);
        unsigned l_446 = 0xD493B671L;
        int i;
        for (i = 0; i < 5; i++)
            l_426[i] = 255UL;
        step_hash(287);
        for (g_94 = 0; (g_94 <= 4); g_94 += 1)
        {
            int i;
            step_hash(286);
            if (g_182[g_94])
                break;
        }
        step_hash(288);
        (*l_418) = l_417;
        step_hash(289);
        (*l_418) = (void*)0;
        step_hash(305);
        for (g_94 = 4; (g_94 >= 1); g_94 -= 1)
        {
            int *l_425 = (void*)0;
            unsigned short l_434 = 0xA5D5L;
            int ***l_440 = (void*)0;
            int i;
            step_hash(304);
            if (((signed char)g_286 >> (signed char)5))
            {
                step_hash(294);
                return l_427;
            }
            else
            {
                signed char l_437 = 0x49L;
                int *l_441 = &g_76;
                step_hash(296);
                (*l_417) = (((*l_417) != g_284[4][2]) <= ((unsigned short)(((unsigned short)((unsigned short)65535UL << (unsigned short)l_434) - (unsigned short)((g_337 ^ (0x667CL == ((0x2672286EL >= (g_75 == ((unsigned short)p_35 << (unsigned short)5))) > 4L))) == g_338[2][0])) | l_437) * (unsigned short)g_33));
                step_hash(297);
                g_84 = l_425;
                step_hash(298);
                if (g_233)
                    break;
                step_hash(303);
                if ((((unsigned char)(g_233 & l_437) + (unsigned char)((&l_418 == l_440) | ((&g_75 == l_441) <= ((((int)((((unsigned short)p_35 * (unsigned short)g_337) ^ g_189) == 0x9CL) / (int)p_37) & 0x5C3BD3D9L) | g_95[3])))) && 0UL))
                {
                    step_hash(300);
                    (*l_418) = &p_35;
                }
                else
                {
                    signed char l_450 = 5L;
                    step_hash(302);
                    g_76 = ((int)g_449 - (int)(g_182[3] >= (l_450 == 0x1E00628DL)));
                }
            }
        }
    }
    step_hash(428);
    for (g_77 = 0; (g_77 == 21); ++g_77)
    {
        int l_458 = 0x0CA4A02CL;
        int l_475[3][2];
        unsigned char l_552 = 0xA2L;
        int **l_562 = (void*)0;
        int ***l_561 = &l_562;
        int l_606 = (-4L);
        int l_640 = 0xEBEB0606L;
        int i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 2; j++)
                l_475[i][j] = (-1L);
        }
        step_hash(310);
        (*l_417) = ((void*)0 == &p_38);
        step_hash(427);
        for (p_35 = (-18); (p_35 > (-21)); --p_35)
        {
            short l_476[10][8];
            int l_508 = 0x169E0388L;
            int l_509 = (-2L);
            int l_512 = 7L;
            int l_550[7][5] = {{0x9EFB1165L, 0xC0D33F4DL, (-9L), 1L, 0xFC89C641L}, {0x9EFB1165L, 0xC0D33F4DL, (-9L), 1L, 0xFC89C641L}, {0x9EFB1165L, 0xC0D33F4DL, (-9L), 1L, 0xFC89C641L}, {0x9EFB1165L, 0xC0D33F4DL, (-9L), 1L, 0xFC89C641L}, {0x9EFB1165L, 0xC0D33F4DL, (-9L), 1L, 0xFC89C641L}, {0x9EFB1165L, 0xC0D33F4DL, (-9L), 1L, 0xFC89C641L}, {0x9EFB1165L, 0xC0D33F4DL, (-9L), 1L, 0xFC89C641L}};
            int *l_563 = &l_509;
            int *l_564 = &l_509;
            int *l_565[10][2];
            signed char l_566[5] = {0xA1L, (-1L), 0xA1L, (-1L), 0xA1L};
            unsigned l_567 = 0x0E0090EBL;
            int i, j;
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 8; j++)
                    l_476[i][j] = 0x267EL;
            }
            for (i = 0; i < 10; i++)
            {
                for (j = 0; j < 2; j++)
                    l_565[i][j] = &l_550[2][1];
            }
            step_hash(369);
            if ((((void*)0 == l_455) == ((unsigned char)l_458 + (unsigned char)((unsigned short)(l_461 ^ ((-(short)0x98BCL) | ((unsigned char)((short)((int)((unsigned char)(((int)(+l_458) - (int)p_35) & (0x0A810701L >= ((unsigned)((((((g_182[3] != l_475[2][0]) != (*l_417)) ^ (-1L)) | l_476[7][6]) | p_35) | g_95[0]) - (unsigned)(*l_417)))) - (unsigned char)g_285) + (int)1UL) << (short)2) % (unsigned char)g_190))) * (unsigned short)g_285))))
            {
                signed char l_507 = 0xD1L;
                int l_513 = 6L;
                int l_535 = 1L;
                int *l_541 = &g_313;
                int *l_542 = &g_189;
                int *l_543 = &l_534;
                int *l_544 = &l_475[2][0];
                int *l_545 = &g_76;
                int *l_546 = &l_512;
                int *l_547[7] = {&g_77, &g_77, (void*)0, &g_77, &g_77, (void*)0, &g_77};
                int i;
                step_hash(334);
                for (g_337 = 0; (g_337 <= 2); g_337 += 1)
                {
                    int *l_477 = &g_77;
                    int **l_478 = &l_477;
                    int l_510 = 0xAB6CAB2DL;
                    int l_511 = 0x6D6B166CL;
                    unsigned l_517 = 0x954569E3L;
                    int i, j;
                    step_hash(318);
                    (*l_478) = l_477;
                    step_hash(327);
                    if (g_284[(g_337 + 2)][g_337])
                    {
                        step_hash(320);
                        (*l_417) &= ((unsigned char)g_407 >> (unsigned char)7);
                        step_hash(321);
                        if (p_35)
                            break;
                        step_hash(322);
                        (*l_478) = &l_475[1][1];
                        step_hash(323);
                        (*l_477) = (1L && (g_75 >= ((unsigned short)(+((unsigned short)g_283[3] % (unsigned short)((signed char)((unsigned short)((((unsigned)g_182[3] - (unsigned)p_37) && (**l_478)) >= (((short)(((unsigned short)p_37 << (unsigned short)0) || g_31) * (short)((unsigned char)((unsigned char)((((unsigned char)(0xC4L | 0xB7L) - (unsigned char)p_37) ^ g_95[0]) <= 0xE0ABF591L) - (unsigned char)p_35) % (unsigned char)g_16)) && 0xB4BD69DBL)) << (unsigned short)p_35) >> (signed char)3))) >> (unsigned short)p_37)));
                    }
                    else
                    {
                        int *l_503 = &g_189;
                        int *l_504 = &l_475[2][0];
                        int *l_505 = &l_475[2][0];
                        int *l_506[4][5] = {{&l_475[2][1], &l_475[2][0], (void*)0, &l_475[2][0], &l_475[2][1]}, {&l_475[2][1], &l_475[2][0], (void*)0, &l_475[2][0], &l_475[2][1]}, {&l_475[2][1], &l_475[2][0], (void*)0, &l_475[2][0], &l_475[2][1]}, {&l_475[2][1], &l_475[2][0], (void*)0, &l_475[2][0], &l_475[2][1]}};
                        int i, j;
                        step_hash(325);
                        --l_517;
                        step_hash(326);
                        (*l_478) = &p_35;
                    }
                    step_hash(333);
                    for (g_312 = 0; (g_312 >= 19); g_312 += 9)
                    {
                        step_hash(331);
                        p_38 = &p_35;
                        step_hash(332);
                        return (*l_417);
                    }
                }
                step_hash(357);
                if (p_35)
                {
                    int *l_522 = &l_513;
                    int *l_523 = &g_76;
                    int *l_524[9] = {&g_31, &g_31, (void*)0, &g_31, &g_31, (void*)0, &g_31, &g_31, (void*)0};
                    unsigned char l_526 = 0xB1L;
                    int i;
                    step_hash(336);
                    l_526++;
                }
                else
                {
                    step_hash(343);
                    if ((!l_529))
                    {
                        step_hash(339);
                        return p_35;
                    }
                    else
                    {
                        short l_530 = 3L;
                        step_hash(341);
                        l_530 ^= (g_285 & (~((g_16 == (((void*)0 != &p_35) | p_37)) == 0x541260E6L)));
                        step_hash(342);
                        if (g_307)
                            break;
                    }
                    step_hash(348);
                    for (g_94 = 7; (g_94 >= 0); g_94 -= 1)
                    {
                        step_hash(347);
                        l_513 = l_475[2][0];
                    }
                    step_hash(356);
                    for (g_406 = 0; (g_406 >= 5); g_406 += 4)
                    {
                        int *l_533[7] = {&g_33, &l_509, &g_33, &l_509, &g_33, &l_509, &g_33};
                        unsigned char l_536 = 0xB8L;
                        int i;
                        step_hash(352);
                        (*l_417) = (p_35 == (p_37 & 2UL));
                        step_hash(353);
                        l_536--;
                        step_hash(354);
                        (*l_417) = ((signed char)(0xB9E5L & (g_355 == g_355)) >> (signed char)(1L <= g_283[3]));
                        step_hash(355);
                        return l_475[2][0];
                    }
                }
                step_hash(358);
                ++l_552;
                step_hash(359);
                if ((*l_541))
                    break;
            }
            else
            {
                short l_555 = 0x0528L;
                int **l_560[4][1] = {{&l_417}, {&l_417}, {&l_417}, {&l_417}};
                int ***l_559 = &l_560[1][0];
                int i, j;
                step_hash(361);
                l_550[2][1] ^= l_555;
                step_hash(367);
                for (l_512 = 0; (l_512 <= 5); l_512++)
                {
                    int l_558 = (-4L);
                    step_hash(365);
                    (*l_417) ^= (l_558 ^ (&l_508 != &p_35));
                    step_hash(366);
                    return g_95[2];
                }
                step_hash(368);
                (*l_417) &= (l_559 != l_561);
            }
            step_hash(370);
            --l_567;
            step_hash(425);
            if ((l_570[1] && ((unsigned short)((g_312 >= (p_37 && (&p_38 != &g_84))) >= ((int)(*l_563) - (int)((-2L) != ((signed char)((unsigned char)((*l_417) && g_188) << (unsigned char)0) + (signed char)0x1EL)))) * (unsigned short)g_188)))
            {
                step_hash(372);
                (*l_564) ^= ((unsigned short)g_516[0][1] % (unsigned short)p_37);
            }
            else
            {
                unsigned l_583 = 4294967289UL;
                int l_590 = 0L;
                int *l_595[5][3] = {{&g_33, &g_77, &g_33}, {&g_33, &g_77, &g_33}, {&g_33, &g_77, &g_33}, {&g_33, &g_77, &g_33}, {&g_33, &g_77, &g_33}};
                int i, j;
                step_hash(399);
                if ((((unsigned short)p_35 / (unsigned short)p_35) < l_583))
                {
                    signed char l_584 = 0x28L;
                    int **l_585[1][9] = {{(void*)0, (void*)0, &l_564, (void*)0, (void*)0, &l_564, (void*)0, (void*)0, &l_564}};
                    int i, j;
                    step_hash(375);
                    (*l_564) = l_584;
                    step_hash(376);
                    (*l_561) = l_585[0][7];
                    step_hash(384);
                    if ((*l_564))
                    {
                        unsigned l_586 = 4294967294UL;
                        step_hash(378);
                        --l_586;
                    }
                    else
                    {
                        unsigned l_596[4][10] = {{0xA5CCFE04L, 0xA5CCFE04L, 0xDA14FC92L, 0xF1889E30L, 0x0BA093BCL, 0xF1889E30L, 0xDA14FC92L, 0xA5CCFE04L, 0xA5CCFE04L, 0xDA14FC92L}, {0xA5CCFE04L, 0xA5CCFE04L, 0xDA14FC92L, 0xF1889E30L, 0x0BA093BCL, 0xF1889E30L, 0xDA14FC92L, 0xA5CCFE04L, 0xA5CCFE04L, 0xDA14FC92L}, {0xA5CCFE04L, 0xA5CCFE04L, 0xDA14FC92L, 0xF1889E30L, 0x0BA093BCL, 0xF1889E30L, 0xDA14FC92L, 0xA5CCFE04L, 0xA5CCFE04L, 0xDA14FC92L}, {0xA5CCFE04L, 0xA5CCFE04L, 0xDA14FC92L, 0xF1889E30L, 0x0BA093BCL, 0xF1889E30L, 0xDA14FC92L, 0xA5CCFE04L, 0xA5CCFE04L, 0xDA14FC92L}};
                        int i, j;
                        step_hash(380);
                        l_589 = &p_35;
                        step_hash(381);
                        l_590 = ((void*)0 != g_355);
                        step_hash(382);
                        if (p_35)
                            break;
                        step_hash(383);
                        (*l_417) ^= ((unsigned short)(((+g_515) & ((unsigned short)5UL * (unsigned short)(!p_37))) >= ((l_595[3][1] == l_595[3][1]) == l_596[1][6])) % (unsigned short)p_37);
                    }
                }
                else
                {
                    int **l_597 = &l_417;
                    step_hash(386);
                    (*l_597) = &g_313;
                    step_hash(392);
                    for (g_336 = 0; (g_336 >= 6); g_336 += 8)
                    {
                        step_hash(390);
                        p_36 = &p_35;
                        step_hash(391);
                        (*l_417) &= (*p_36);
                    }
                    step_hash(398);
                    for (g_514 = 6; (g_514 == (-8)); g_514 -= 6)
                    {
                        unsigned l_607 = 0x3419D489L;
                        step_hash(396);
                        (*l_563) ^= ((((unsigned short)g_31 + (unsigned short)(-5L)) && (*l_589)) & ((unsigned)g_515 + (unsigned)(**l_597)));
                        step_hash(397);
                        l_607++;
                    }
                }
                step_hash(423);
                if ((255UL | ((unsigned short)g_514 + (unsigned short)p_37)))
                {
                    unsigned short l_618 = 0x72EEL;
                    int ***l_629 = (void*)0;
                    int l_634 = 0xE18F3EB4L;
                    int l_636[6] = {7L, 7L, 0x5628A893L, 7L, 7L, 0x5628A893L};
                    int i;
                    step_hash(401);
                    if ((*l_564))
                        break;
                    step_hash(406);
                    if (((void*)0 == &p_35))
                    {
                        short l_614 = (-1L);
                        step_hash(403);
                        (*l_564) = ((&l_550[4][2] == &l_509) ^ ((signed char)(*l_417) % (signed char)l_614));
                    }
                    else
                    {
                        int **l_615 = (void*)0;
                        step_hash(405);
                        p_38 = &p_35;
                    }
                    step_hash(407);
                    (*l_564) &= g_182[4];
                    step_hash(415);
                    if (((unsigned char)g_549[2] >> (unsigned char)(((+l_618) > (((signed char)p_37 % (signed char)p_37) ^ ((signed char)p_37 + (signed char)(-1L)))) ^ p_35)))
                    {
                        unsigned char l_630[10][8] = {{0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}, {0x4FL, 0xA5L, 0xE9L, 0xE9L, 0xA5L, 0x4FL, 0xA5L, 0xE9L}};
                        int l_635 = 0xBD05030BL;
                        int i, j;
                        step_hash(409);
                        (*l_417) = (3UL & (((unsigned char)(g_232 || (((unsigned)(~4294967286UL) - (unsigned)p_35) >= (p_35 ^ (l_629 != g_355)))) + (unsigned char)0x3DL) < ((void*)0 == &p_35)));
                        step_hash(410);
                        l_630[9][7]--;
                        step_hash(411);
                        (*l_417) = ((void*)0 != &p_35);
                        step_hash(412);
                        l_637[1][8]++;
                    }
                    else
                    {
                        unsigned l_641 = 0x1D12B5EEL;
                        step_hash(414);
                        ++l_641;
                    }
                }
                else
                {
                    unsigned short l_644 = 0UL;
                    step_hash(417);
                    l_644++;
                    step_hash(422);
                    for (g_189 = 0; (g_189 < (-6)); g_189 -= 5)
                    {
                        step_hash(421);
                        return p_35;
                    }
                }
                step_hash(424);
                (*l_563) = 1L;
            }
        }
    }
    step_hash(429);
    return p_35;
}







static unsigned short func_42(unsigned char p_43, int p_44, int * p_45)
{
    int l_53 = 0xF3AC16B4L;
    int *l_65 = &g_33;
    int *l_412 = &g_189;
    step_hash(270);
    l_65 = func_47(l_53, func_54((*p_45), func_59(p_43, l_53, l_65, func_66(((l_65 == (void*)0) != ((*p_45) ^ (*p_45))), l_65, l_65), p_44), l_65, (*l_65)), &g_33, l_65, &g_31);
    step_hash(276);
    if ((!(func_59((*l_65), (*l_65), &p_44, l_412, ((&l_412 != &l_412) <= 0x09L)) == p_44)))
    {
        unsigned l_413 = 0x76D68D60L;
        step_hash(272);
        l_413 = 1L;
    }
    else
    {
        int **l_414[5] = {&l_65, &l_412, &l_65, &l_412, &l_65};
        int i;
        step_hash(274);
        (*l_412) = (*p_45);
        step_hash(275);
        g_84 = l_412;
    }
    step_hash(277);
    (*l_412) = (func_59(((signed char)(((*l_65) == p_44) <= p_44) << (signed char)6), g_338[3][0], &p_44, l_65, p_43) < 0xB9L);
    step_hash(278);
    return g_337;
}







static int * func_47(unsigned char p_48, int * p_49, int * p_50, int * p_51, int * p_52)
{
    int **l_245 = &g_84;
    int ***l_244 = &l_245;
    int *l_252 = &g_33;
    int l_281 = 4L;
    int l_306[8][9] = {{(-1L), 0x96B20FC8L, 4L, 0x3094950BL, 1L, 0L, 0x044F218FL, 0x43DD389AL, 0x044F218FL}, {(-1L), 0x96B20FC8L, 4L, 0x3094950BL, 1L, 0L, 0x044F218FL, 0x43DD389AL, 0x044F218FL}, {(-1L), 0x96B20FC8L, 4L, 0x3094950BL, 1L, 0L, 0x044F218FL, 0x43DD389AL, 0x044F218FL}, {(-1L), 0x96B20FC8L, 4L, 0x3094950BL, 1L, 0L, 0x044F218FL, 0x43DD389AL, 0x044F218FL}, {(-1L), 0x96B20FC8L, 4L, 0x3094950BL, 1L, 0L, 0x044F218FL, 0x43DD389AL, 0x044F218FL}, {(-1L), 0x96B20FC8L, 4L, 0x3094950BL, 1L, 0L, 0x044F218FL, 0x43DD389AL, 0x044F218FL}, {(-1L), 0x96B20FC8L, 4L, 0x3094950BL, 1L, 0L, 0x044F218FL, 0x43DD389AL, 0x044F218FL}, {(-1L), 0x96B20FC8L, 4L, 0x3094950BL, 1L, 0L, 0x044F218FL, 0x43DD389AL, 0x044F218FL}};
    int l_405 = (-4L);
    int *l_410[10][9] = {{&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}, {&g_76, &g_313, &g_76, (void*)0, &g_31, &l_306[5][1], &g_75, (void*)0, &g_77}};
    int *l_411 = &g_189;
    int i, j;
    step_hash(267);
    for (g_233 = (-14); (g_233 >= 47); g_233 += 3)
    {
        short l_263 = (-3L);
        int ***l_268 = &l_245;
        int l_276[1];
        unsigned l_314 = 0xFD7DE96FL;
        unsigned short l_364 = 1UL;
        int i;
        for (i = 0; i < 1; i++)
            l_276[i] = 1L;
        step_hash(265);
        for (g_190 = 0; (g_190 >= (-9)); g_190 -= 8)
        {
            int l_254 = 0xAEE7E948L;
            int **l_323 = (void*)0;
            int l_331 = (-9L);
            int *l_404[3][4] = {{(void*)0, (void*)0, (void*)0, (void*)0}, {(void*)0, (void*)0, (void*)0, (void*)0}, {(void*)0, (void*)0, (void*)0, (void*)0}};
            int i, j;
            step_hash(147);
            if ((*p_51))
                break;
            step_hash(185);
            if ((l_244 != (void*)0))
            {
                step_hash(161);
                if ((*g_84))
                {
                    unsigned l_249 = 0UL;
                    step_hash(154);
                    for (g_94 = (-23); (g_94 > (-23)); g_94 += 4)
                    {
                        int *l_248 = &g_77;
                        step_hash(153);
                        return l_248;
                    }
                    step_hash(155);
                    if (l_249)
                        continue;
                    step_hash(156);
                    if ((*p_52))
                        break;
                    step_hash(157);
                    (*l_244) = (*l_244);
                }
                else
                {
                    unsigned short l_253 = 5UL;
                    step_hash(159);
                    (*l_245) = func_66(((signed char)(l_252 == (void*)0) + (signed char)func_59(p_48, l_253, p_52, func_66(g_188, func_66(p_48, func_66(p_48, p_51, (**l_244)), p_50), &g_31), l_254)), &g_33, &g_189);
                    step_hash(160);
                    if (l_253)
                        break;
                }
            }
            else
            {
                int l_259 = (-6L);
                int *l_262 = (void*)0;
                int l_282[8][6] = {{0L, 0x1E1A05C3L, 0L, (-5L), 3L, 1L}, {0L, 0x1E1A05C3L, 0L, (-5L), 3L, 1L}, {0L, 0x1E1A05C3L, 0L, (-5L), 3L, 1L}, {0L, 0x1E1A05C3L, 0L, (-5L), 3L, 1L}, {0L, 0x1E1A05C3L, 0L, (-5L), 3L, 1L}, {0L, 0x1E1A05C3L, 0L, (-5L), 3L, 1L}, {0L, 0x1E1A05C3L, 0L, (-5L), 3L, 1L}, {0L, 0x1E1A05C3L, 0L, (-5L), 3L, 1L}};
                int i, j;
                step_hash(183);
                if ((((((unsigned char)g_16 * (unsigned char)((((func_59(l_259, ((unsigned)(**l_245) % (unsigned)(*p_50)), p_50, l_262, g_76) <= ((4294967294UL != (*p_52)) > g_95[4])) >= 0x5263576AL) <= p_48) < g_232)) && 1UL) & l_263) >= (*p_51)))
                {
                    step_hash(168);
                    for (g_232 = 7; (g_232 <= (-29)); --g_232)
                    {
                        step_hash(167);
                        return &g_75;
                    }
                    step_hash(169);
                    l_262 = (void*)0;
                }
                else
                {
                    unsigned l_269 = 0x0CF4673FL;
                    int l_305 = (-3L);
                    step_hash(175);
                    if (((unsigned short)(((l_268 == (void*)0) >= l_269) || ((unsigned short)(0xF8L == g_94) / (unsigned short)l_254)) << (unsigned short)6))
                    {
                        int *l_272 = &g_189;
                        int *l_273 = &g_189;
                        int l_274[6][7] = {{(-5L), (-4L), 0xFCE317D5L, (-9L), 0x641700D3L, 0x6FF1FB67L, 0x641700D3L}, {(-5L), (-4L), 0xFCE317D5L, (-9L), 0x641700D3L, 0x6FF1FB67L, 0x641700D3L}, {(-5L), (-4L), 0xFCE317D5L, (-9L), 0x641700D3L, 0x6FF1FB67L, 0x641700D3L}, {(-5L), (-4L), 0xFCE317D5L, (-9L), 0x641700D3L, 0x6FF1FB67L, 0x641700D3L}, {(-5L), (-4L), 0xFCE317D5L, (-9L), 0x641700D3L, 0x6FF1FB67L, 0x641700D3L}, {(-5L), (-4L), 0xFCE317D5L, (-9L), 0x641700D3L, 0x6FF1FB67L, 0x641700D3L}};
                        int *l_275 = &l_274[1][6];
                        int *l_277 = &l_274[1][2];
                        int *l_278 = &l_276[0];
                        int *l_279 = &g_189;
                        int *l_280[6];
                        int i, j;
                        for (i = 0; i < 6; i++)
                            l_280[i] = (void*)0;
                        step_hash(172);
                        g_286++;
                    }
                    else
                    {
                        step_hash(174);
                        return p_50;
                    }
                    step_hash(182);
                    if (((signed char)g_33 - (signed char)((unsigned char)g_94 * (unsigned char)(((short)g_189 % (short)l_254) & 0xEAA5L))))
                    {
                        int *l_297 = &l_282[6][3];
                        int *l_298 = &g_75;
                        int *l_299 = &g_76;
                        int *l_300 = &l_281;
                        int *l_301 = &l_281;
                        int *l_302 = (void*)0;
                        int *l_303 = (void*)0;
                        int *l_304[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_304[i] = &l_281;
                        step_hash(177);
                        (*p_49) = ((unsigned short)g_16 % (unsigned short)func_59(g_284[1][2], g_76, p_50, (**l_268), l_254));
                        step_hash(178);
                        (**l_268) = &g_31;
                        step_hash(179);
                        g_307--;
                    }
                    else
                    {
                        int l_310 = 0x68492E97L;
                        int *l_311[2];
                        int i;
                        for (i = 0; i < 2; i++)
                            l_311[i] = &l_282[6][1];
                        step_hash(181);
                        ++l_314;
                    }
                }
                step_hash(184);
                if ((*p_49))
                    break;
            }
            step_hash(263);
            if (((signed char)((((unsigned char)(&p_50 == (void*)0) + (unsigned char)((***l_244) && g_95[7])) || (!((***l_268) != 0x3499L))) | g_189) * (signed char)((short)g_182[0] >> (short)((void*)0 == l_323))))
            {
                int *l_324 = &l_281;
                int l_334 = 0L;
                int l_335 = 3L;
                step_hash(187);
                (**l_244) = func_66(((func_59((***l_268), p_48, l_324, &g_31, ((short)p_48 + (short)(*l_324))) && ((signed char)func_59((&g_313 != (void*)0), g_94, (**l_244), &g_189, (*l_324)) * (signed char)p_48)) || 65535UL), &g_189, p_52);
                step_hash(194);
                if ((*g_84))
                {
                    int l_329 = (-1L);
                    step_hash(189);
                    (*p_49) = l_329;
                }
                else
                {
                    int l_330[7][5] = {{0x2927434CL, 0x2927434CL, 6L, 7L, 0x1A42DC09L}, {0x2927434CL, 0x2927434CL, 6L, 7L, 0x1A42DC09L}, {0x2927434CL, 0x2927434CL, 6L, 7L, 0x1A42DC09L}, {0x2927434CL, 0x2927434CL, 6L, 7L, 0x1A42DC09L}, {0x2927434CL, 0x2927434CL, 6L, 7L, 0x1A42DC09L}, {0x2927434CL, 0x2927434CL, 6L, 7L, 0x1A42DC09L}, {0x2927434CL, 0x2927434CL, 6L, 7L, 0x1A42DC09L}};
                    int *l_332 = &g_77;
                    int *l_333[4][2] = {{(void*)0, (void*)0}, {(void*)0, (void*)0}, {(void*)0, (void*)0}, {(void*)0, (void*)0}};
                    int i, j;
                    step_hash(191);
                    (*l_324) |= ((void*)0 == &l_245);
                    step_hash(192);
                    l_330[3][0] = (*g_84);
                    step_hash(193);
                    ++g_338[4][6];
                }
                step_hash(200);
                for (g_307 = 0; (g_307 < 50); g_307 += 2)
                {
                    step_hash(198);
                    (**l_244) = (**l_268);
                    step_hash(199);
                    return &g_75;
                }
                step_hash(221);
                if (((signed char)(***l_268) * (signed char)g_336))
                {
                    short l_349 = (-7L);
                    step_hash(208);
                    for (g_189 = 0; (g_189 < (-22)); g_189--)
                    {
                        int *l_350 = &g_77;
                        step_hash(205);
                        (*l_324) = (*p_49);
                        step_hash(206);
                        g_77 = ((unsigned short)((*g_84) > ((*l_324) == l_349)) % (unsigned short)p_48);
                        step_hash(207);
                        (**l_268) = l_350;
                    }
                }
                else
                {
                    int *l_361 = &g_313;
                    step_hash(210);
                    (*l_324) = (*p_49);
                    step_hash(211);
                    if ((***l_244))
                        continue;
                    step_hash(212);
                    if ((*g_84))
                        continue;
                    step_hash(220);
                    for (l_331 = 22; (l_331 == 5); --l_331)
                    {
                        int *l_360[7][1] = {{&l_306[2][1]}, {&l_306[2][1]}, {&l_306[2][1]}, {&l_306[2][1]}, {&l_306[2][1]}, {&l_306[2][1]}, {&l_306[2][1]}};
                        int i, j;
                        step_hash(216);
                        (*l_324) = 0x63CE230CL;
                        step_hash(217);
                        (*l_361) = func_59(((unsigned char)p_48 >> (unsigned char)(g_283[4] <= (g_355 == (void*)0))), ((short)((short)func_59(((*p_51) & func_59(g_286, (***l_268), p_51, (**l_268), g_283[3])), p_48, p_52, l_360[3][0], g_31) - (short)g_16) + (short)g_313), p_49, l_361, g_95[1]);
                        step_hash(218);
                        (*l_361) = (*l_324);
                        step_hash(219);
                        if ((*g_84))
                            continue;
                    }
                }
            }
            else
            {
                short l_367 = 0x9BEDL;
                int l_391 = (-1L);
                step_hash(242);
                for (p_48 = 0; (p_48 <= 0); p_48 += 1)
                {
                    step_hash(231);
                    for (g_232 = 0; (g_232 <= 0); g_232 += 1)
                    {
                        int i;
                        step_hash(229);
                        (*p_49) ^= (((void*)0 != &p_52) ^ l_276[g_232]);
                        step_hash(230);
                        (*p_49) = (&p_49 != (void*)0);
                    }
                    step_hash(236);
                    for (g_336 = 0; (g_336 >= 25); g_336 += 9)
                    {
                        step_hash(235);
                        l_364++;
                    }
                    step_hash(241);
                    for (g_336 = 0; (g_336 <= 6); g_336 += 1)
                    {
                        step_hash(240);
                        return (**l_268);
                    }
                }
                step_hash(243);
                l_367 ^= 0xA0008B65L;
                step_hash(244);
                (*p_49) = (*p_52);
                step_hash(262);
                for (l_281 = 22; (l_281 != 26); l_281++)
                {
                    unsigned l_372 = 0x293277F5L;
                    int *l_394 = &l_306[2][1];
                    int *l_397[2];
                    signed char l_398 = 8L;
                    int i;
                    for (i = 0; i < 2; i++)
                        l_397[i] = &l_281;
                    step_hash(256);
                    if (((0xDAF6L > ((signed char)g_312 << (signed char)6)) & p_48))
                    {
                        step_hash(249);
                        (**l_244) = func_66(p_48, p_51, p_50);
                        step_hash(250);
                        (*p_49) = l_372;
                    }
                    else
                    {
                        unsigned l_381 = 0UL;
                        int ***l_403 = &l_323;
                        step_hash(252);
                        l_391 = ((short)(((unsigned)((unsigned short)((unsigned)func_59(l_381, (-(signed char)((((((unsigned short)g_94 + (unsigned short)0L) | (l_381 | ((((int)((**l_244) != (void*)0) - (int)(***l_268)) < ((unsigned short)g_76 * (unsigned short)((unsigned char)255UL << (unsigned char)g_307))) != l_381))) ^ l_372) != 65533UL) <= 0xE211L)), p_49, p_50, l_372) / (unsigned)g_233) << (unsigned short)2) / (unsigned)0xF4205768L) & g_312) * (short)1UL);
                        step_hash(253);
                        (*p_49) = func_59((((unsigned short)func_59(func_59(p_48, p_48, p_52, l_394, p_48), ((signed char)(*l_394) - (signed char)p_48), p_51, l_397[0], p_48) >> (unsigned short)7) == l_398), l_367, p_52, p_52, p_48);
                        step_hash(254);
                        g_75 |= (0UL != (**l_245));
                        step_hash(255);
                        (*p_49) = func_59((((((((unsigned)((*l_394) ^ (*g_84)) - (unsigned)(!(*p_52))) <= l_367) | (g_95[4] >= ((signed char)0x85L >> (signed char)p_48))) | (l_403 == g_355)) | p_48) && g_286), (***l_268), &g_75, &g_189, g_337);
                    }
                    step_hash(261);
                    for (l_314 = 0; (l_314 <= 1); l_314 += 1)
                    {
                        int i;
                        step_hash(260);
                        return p_51;
                    }
                }
            }
            step_hash(264);
            ++g_407;
        }
        step_hash(266);
        return p_49;
    }
    step_hash(268);
    (**l_245) |= (*p_50);
    step_hash(269);
    return l_411;
}







static int * func_54(int p_55, signed char p_56, int * p_57, unsigned p_58)
{
    int l_230 = (-1L);
    int l_231[10][4] = {{0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}, {0xE80D83C7L, 0x9599C243L, 0x723FDEEFL, 0L}};
    int **l_238 = (void*)0;
    int **l_239 = &g_84;
    int i, j;
    step_hash(137);
    for (g_190 = (-1); (g_190 != 5); g_190 += 3)
    {
        int *l_223 = (void*)0;
        int *l_224 = (void*)0;
        int *l_225 = &g_76;
        int *l_226 = (void*)0;
        int l_227 = (-8L);
        int *l_228 = &g_77;
        int *l_229[7] = {&g_75, &g_75, &g_75, &g_75, &g_75, &g_75, &g_75};
        int **l_236 = &g_84;
        int ***l_237 = &l_236;
        int i;
        step_hash(133);
        g_233++;
        step_hash(134);
        (*l_228) = (*g_84);
        step_hash(135);
        (*l_236) = &p_55;
        step_hash(136);
        (*l_237) = &p_57;
    }
    step_hash(138);
    (*l_239) = &g_77;
    step_hash(139);
    return &g_189;
}







static signed char func_59(unsigned p_60, short p_61, int * p_62, int * p_63, signed char p_64)
{
    unsigned l_103 = 4294967295UL;
    int l_131 = 0xBD50C841L;
    int l_186 = (-5L);
    int l_187 = 0L;
    step_hash(55);
    g_77 &= 0xD42852A3L;
    step_hash(127);
    for (g_77 = 0; (g_77 > 22); ++g_77)
    {
        int **l_102 = (void*)0;
        int l_110 = 0L;
        step_hash(59);
        p_63 = &g_33;
        step_hash(110);
        if ((l_103 < (0x0BL < ((short)((255UL ^ (((unsigned char)((signed char)p_64 << (signed char)((void*)0 == &g_33)) / (unsigned char)p_61) ^ g_77)) != l_110) / (short)(-1L)))))
        {
            int l_129 = 0x2A052AF0L;
            int *l_130 = &g_75;
            step_hash(61);
            (*l_130) = (+(((unsigned short)((signed char)p_61 << (signed char)((253UL && ((unsigned char)((short)l_103 << (short)5) >> (unsigned char)(l_103 == (250UL | (g_94 && (((signed char)((short)((unsigned char)(g_94 <= ((((signed char)(((unsigned short)(~l_103) << (unsigned short)9) && (g_95[7] < 8UL)) * (signed char)8L) != l_103) >= g_31)) + (unsigned char)g_76) + (short)0x4513L) << (signed char)1) >= l_103)))))) | 0UL)) - (unsigned short)g_16) == l_129));
        }
        else
        {
            signed char l_153 = 0xCCL;
            unsigned short l_172 = 0xF7DDL;
            int l_181[4][10] = {{0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L)}, {0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L)}, {0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L)}, {0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L), 0x200A2DC1L, (-6L)}};
            short l_213 = 0x0EF9L;
            int l_215 = 0x2D4C9FC4L;
            int i, j;
            step_hash(63);
            if ((*g_84))
                break;
            step_hash(64);
            l_131 = (*g_84);
            step_hash(109);
            for (l_103 = 0; (l_103 >= 31); l_103 += 1)
            {
                int **l_134 = (void*)0;
                int **l_135[9] = {&g_84, (void*)0, &g_84, (void*)0, &g_84, (void*)0, &g_84, (void*)0, &g_84};
                int l_162 = 0x85391AC4L;
                int i;
                step_hash(68);
                g_84 = &g_76;
                step_hash(108);
                if (l_103)
                {
                    int l_163 = 0xFDDBE10EL;
                    unsigned short l_164 = 0xC5FAL;
                    step_hash(77);
                    for (p_64 = 0; (p_64 >= (-1)); p_64 -= 9)
                    {
                        signed char l_165 = 1L;
                        step_hash(73);
                        g_75 ^= (*g_84);
                        step_hash(74);
                        l_131 |= (g_33 > 0x1128L);
                        step_hash(75);
                        (*g_84) = (*g_84);
                        step_hash(76);
                        l_165 ^= ((short)((((unsigned char)g_75 * (unsigned char)((void*)0 != &g_75)) && ((((unsigned char)(((short)((unsigned char)p_64 - (unsigned char)((short)((-(unsigned short)((short)l_153 >> (short)g_77)) != l_153) - (short)(((unsigned short)(((short)((((signed char)((int)(((0L >= g_77) & (-1L)) & p_60) - (int)l_162) / (signed char)0x50L) != 0xEAL) < l_163) << (short)5) ^ g_95[5]) / (unsigned short)l_164) > (*p_62)))) * (short)l_153) >= 4294967286UL) >> (unsigned char)g_76) || p_61) && g_16)) != g_95[6]) - (short)p_64);
                    }
                    step_hash(83);
                    if (l_153)
                    {
                        step_hash(79);
                        (*g_84) = (*p_62);
                        step_hash(80);
                        p_63 = &g_33;
                    }
                    else
                    {
                        step_hash(82);
                        if (l_164)
                            break;
                    }
                    step_hash(92);
                    if ((*p_62))
                    {
                        step_hash(85);
                        p_63 = p_62;
                        step_hash(86);
                        (*g_84) |= ((unsigned short)((short)(&g_84 == (void*)0) / (short)g_33) % (unsigned short)0xD8F4L);
                        step_hash(87);
                        if ((*g_84))
                            continue;
                    }
                    else
                    {
                        step_hash(89);
                        (*g_84) &= ((signed char)l_172 - (signed char)((short)(p_61 == l_153) << (short)5));
                        step_hash(90);
                        g_84 = &g_31;
                        step_hash(91);
                        l_110 = (*g_84);
                    }
                }
                else
                {
                    signed char l_177 = 0x3DL;
                    int l_185 = 0x2546FF5CL;
                    unsigned l_206[10][4] = {{0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}, {0xFF2045DDL, 0xFF2045DDL, 0UL, 0xFF2045DDL}};
                    int i, j;
                    step_hash(98);
                    for (l_172 = (-7); (l_172 < 33); l_172 += 6)
                    {
                        unsigned char l_178 = 0x35L;
                        step_hash(97);
                        l_178++;
                    }
                    step_hash(99);
                    ++g_182[0];
                    step_hash(100);
                    g_191++;
                    step_hash(107);
                    for (l_186 = 0; (l_186 != 0); ++l_186)
                    {
                        int l_214 = 1L;
                        step_hash(104);
                        p_62 = p_63;
                        step_hash(105);
                        (*g_84) ^= 0x90CD53C7L;
                        step_hash(106);
                        l_215 &= ((unsigned char)(((signed char)((unsigned short)0xA1C3L * (unsigned short)((signed char)(((short)l_206[7][3] / (short)(l_172 ^ (9UL < g_182[4]))) > (((((unsigned)((short)g_182[0] % (short)65535UL) / (unsigned)(((unsigned char)g_188 << (unsigned char)(g_75 == l_181[2][2])) ^ l_172)) <= l_213) && p_61) & l_214)) % (signed char)g_16)) * (signed char)l_206[7][2]) > p_64) / (unsigned char)0xF4L);
                    }
                }
            }
        }
        step_hash(116);
        for (l_131 = 7; (l_131 >= 1); l_131 -= 1)
        {
            int ***l_216 = &l_102;
            step_hash(114);
            (*l_216) = &p_63;
            step_hash(115);
            (**l_216) = (**l_216);
        }
        step_hash(126);
        for (g_76 = 0; (g_76 == 11); g_76 += 5)
        {
            step_hash(120);
            g_75 = l_186;
            step_hash(125);
            for (l_110 = 0; (l_110 < 29); l_110 += 3)
            {
                step_hash(124);
                p_62 = p_63;
            }
        }
    }
    step_hash(128);
    return g_77;
}







static int * func_66(unsigned char p_67, int * p_68, int * p_69)
{
    unsigned l_74[3][5] = {{6UL, 0x21D2CF1AL, 0UL, 0UL, 0x21D2CF1AL}, {6UL, 0x21D2CF1AL, 0UL, 0UL, 0x21D2CF1AL}, {6UL, 0x21D2CF1AL, 0UL, 0UL, 0x21D2CF1AL}};
    int l_78 = 0x955DF93CL;
    int i, j;
    step_hash(52);
    for (p_67 = 16; (p_67 == 23); p_67 += 9)
    {
        int **l_72 = (void*)0;
        int **l_73 = (void*)0;
        int l_92 = 0xD1841160L;
        int **l_98 = (void*)0;
        int **l_99 = &g_84;
        step_hash(15);
        p_68 = p_69;
        step_hash(49);
        for (g_75 = 2; (g_75 >= 0); g_75 -= 1)
        {
            int **l_79 = (void*)0;
            int l_80[9] = {0xBBCB567DL, 0xDB1B7937L, 0xBBCB567DL, 0xDB1B7937L, 0xBBCB567DL, 0xDB1B7937L, 0xBBCB567DL, 0xDB1B7937L, 0xBBCB567DL};
            int *l_86 = &l_80[6];
            int *l_87 = &g_76;
            int *l_88 = &g_76;
            int *l_89 = (void*)0;
            int *l_90 = &l_78;
            int *l_91 = (void*)0;
            int *l_93[7] = {&g_31, &l_92, &g_31, &l_92, &g_31, &l_92, &g_31};
            int i;
            step_hash(47);
            for (g_76 = 2; (g_76 >= 0); g_76 -= 1)
            {
                int l_85 = 1L;
                int i, j;
                step_hash(32);
                for (g_77 = 2; (g_77 >= 0); g_77 -= 1)
                {
                    int i, j;
                    step_hash(25);
                    l_78 = l_74[g_76][(g_77 + 1)];
                    step_hash(30);
                    if ((g_33 < ((void*)0 == p_68)))
                    {
                        step_hash(27);
                        return p_68;
                    }
                    else
                    {
                        step_hash(29);
                        l_79 = &p_69;
                    }
                    step_hash(31);
                    if ((*p_69))
                        break;
                }
                step_hash(33);
                l_80[6] = l_74[g_75][(g_76 + 1)];
                step_hash(46);
                for (l_78 = 0; (l_78 <= 2); l_78 += 1)
                {
                    int l_83 = 0x78915CEDL;
                    int i, j;
                    step_hash(37);
                    l_83 = (((l_74[g_75][l_78] || (g_75 || ((void*)0 != p_68))) <= ((void*)0 != &p_69)) > g_33);
                    step_hash(43);
                    for (l_83 = 0; (l_83 <= 8); l_83 += 1)
                    {
                        int i, j;
                        step_hash(41);
                        l_80[l_83] ^= l_74[l_78][(g_75 + 1)];
                        step_hash(42);
                        l_80[(g_76 + 6)] = 0x5D7A2328L;
                    }
                    step_hash(44);
                    g_84 = &g_76;
                    step_hash(45);
                    l_85 = 0xB7A7919EL;
                }
            }
            step_hash(48);
            ++g_95[0];
        }
        step_hash(50);
        l_92 ^= 0xD205C6C2L;
        step_hash(51);
        (*l_99) = p_68;
    }
    step_hash(53);
    return &g_76;
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_16, "g_16", print_hash_value);
    transparent_crc(g_31, "g_31", print_hash_value);
    transparent_crc(g_33, "g_33", print_hash_value);
    transparent_crc(g_75, "g_75", print_hash_value);
    transparent_crc(g_76, "g_76", print_hash_value);
    transparent_crc(g_77, "g_77", print_hash_value);
    transparent_crc(g_94, "g_94", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_95[i], "g_95[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_182[i], "g_182[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_188, "g_188", print_hash_value);
    transparent_crc(g_189, "g_189", print_hash_value);
    transparent_crc(g_190, "g_190", print_hash_value);
    transparent_crc(g_191, "g_191", print_hash_value);
    transparent_crc(g_232, "g_232", print_hash_value);
    transparent_crc(g_233, "g_233", print_hash_value);
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_283[i], "g_283[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_284[i][j], "g_284[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_285, "g_285", print_hash_value);
    transparent_crc(g_286, "g_286", print_hash_value);
    transparent_crc(g_307, "g_307", print_hash_value);
    transparent_crc(g_312, "g_312", print_hash_value);
    transparent_crc(g_313, "g_313", print_hash_value);
    transparent_crc(g_336, "g_336", print_hash_value);
    transparent_crc(g_337, "g_337", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 8; j++)
        {
            transparent_crc(g_338[i][j], "g_338[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_406, "g_406", print_hash_value);
    transparent_crc(g_407, "g_407", print_hash_value);
    transparent_crc(g_449, "g_449", print_hash_value);
    transparent_crc(g_514, "g_514", print_hash_value);
    transparent_crc(g_515, "g_515", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_516[i][j], "g_516[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 3; i++)
    {
        transparent_crc(g_549[i], "g_549[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            transparent_crc(g_633[i][j], "g_633[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 7; i++)
    {
        transparent_crc(g_706[i], "g_706[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_903, "g_903", print_hash_value);
    transparent_crc(g_904, "g_904", print_hash_value);
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
