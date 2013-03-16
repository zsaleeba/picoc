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
static unsigned g_2[10][10] = {{4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}, {4294967286UL, 0xB24CE554L, 1UL, 0xDEC4F3F7L, 1UL, 0xB24CE554L, 4294967286UL, 0xA4A9BDBAL, 4294967288UL, 0xF451D52AL}};
static int g_3 = 0xA3DBC56EL;
static int g_25 = (-8L);
static unsigned short g_63[1] = {0UL};
static int g_69[3][3] = {{0x966A49DFL, 0x361F3D49L, 0x966A49DFL}, {0x966A49DFL, 0x361F3D49L, 0x966A49DFL}, {0x966A49DFL, 0x361F3D49L, 0x966A49DFL}};
static unsigned g_77 = 0x2DAEADADL;
static int *g_81[5] = {&g_25, &g_25, &g_25, &g_25, &g_25};
static int **g_80 = &g_81[3];
static short g_284 = 7L;
static unsigned char g_381[9][9] = {{0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}, {0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}, {0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}, {0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}, {0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}, {0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}, {0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}, {0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}, {0xFEL, 251UL, 0x6AL, 251UL, 0xFEL, 7UL, 0xFEL, 251UL, 0x6AL}};
static int g_399 = 2L;
static signed char g_512 = 1L;
static int g_573 = (-7L);
static int g_604 = 0x01269993L;
static short g_638[8] = {(-2L), 5L, (-2L), 5L, (-2L), 5L, (-2L), 5L};
static int *g_653 = &g_3;
static int *g_822[4] = {&g_69[1][2], &g_69[1][2], &g_69[1][2], &g_69[1][2]};
static int func_1(void);
static signed char func_9(unsigned p_10, unsigned short p_11);
static unsigned char func_15(int p_16, unsigned p_17);
static int * func_19(signed char p_20, int * p_21);
static int func_26(unsigned short p_27, unsigned char p_28);
static int * func_36(int ** p_37);
static int func_40(int * p_41);
static int * func_42(signed char p_43, short p_44, int ** p_45, unsigned char p_46, int ** p_47);
static int func_48(unsigned p_49);
static unsigned func_66(int p_67);
static int func_1(void)
{
    int l_14 = 0xF17245C2L;
    int *l_813 = &g_69[0][0];
    unsigned short l_816 = 0x6E43L;
    step_hash(677);
    for (g_3 = 0; (g_3 <= 9); g_3 += 1)
    {
        int l_6 = 0L;
        int *l_812 = &g_604;
    }
    step_hash(678);
    return g_604;
}
static signed char func_9(unsigned p_10, unsigned short p_11)
{
    int ***l_797 = (void*)0;
    int *l_798 = &g_69[0][1];
    int *l_799 = &g_69[1][2];
    int *l_800 = &g_604;
    int *l_801 = &g_604;
    int *l_802 = (void*)0;
    int *l_803 = (void*)0;
    int *l_804 = &g_25;
    int l_805 = 0xA0EAED82L;
    int *l_806 = &g_69[0][2];
    int *l_807 = &g_604;
    int *l_808[6][6] = {{(void*)0, (void*)0, (void*)0, &g_69[1][2], &g_604, &g_69[1][2]}, {(void*)0, (void*)0, (void*)0, &g_69[1][2], &g_604, &g_69[1][2]}, {(void*)0, (void*)0, (void*)0, &g_69[1][2], &g_604, &g_69[1][2]}, {(void*)0, (void*)0, (void*)0, &g_69[1][2], &g_604, &g_69[1][2]}, {(void*)0, (void*)0, (void*)0, &g_69[1][2], &g_604, &g_69[1][2]}, {(void*)0, (void*)0, (void*)0, &g_69[1][2], &g_604, &g_69[1][2]}};
    unsigned short l_809 = 65535UL;
    int i, j;
    step_hash(618);
    (**g_80) = (l_797 == (void*)0);
    step_hash(619);
    (*l_798) &= (**g_80);
    step_hash(620);
    --l_809;
    step_hash(621);
    return p_10;
}
static unsigned char func_15(int p_16, unsigned p_17)
{
    unsigned char l_18[4][9] = {{0x0EL, 0xBDL, 5UL, 253UL, 0x7DL, 0x92L, 0xF0L, 0xF8L, 5UL}, {0x0EL, 0xBDL, 5UL, 253UL, 0x7DL, 0x92L, 0xF0L, 0xF8L, 5UL}, {0x0EL, 0xBDL, 5UL, 253UL, 0x7DL, 0x92L, 0xF0L, 0xF8L, 5UL}, {0x0EL, 0xBDL, 5UL, 253UL, 0x7DL, 0x92L, 0xF0L, 0xF8L, 5UL}};
    int *l_24 = &g_25;
    unsigned l_720 = 0x4DC3B152L;
    unsigned char l_721 = 255UL;
    unsigned l_734[4] = {7UL, 4294967288UL, 7UL, 4294967288UL};
    int l_757 = (-10L);
    int l_758 = 0xAEE75660L;
    unsigned short l_759[7];
    int l_783[10][9] = {{0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}, {0L, 0x8E7617E0L, 0x8E7617E0L, 0L, 6L, 0x63F16FA1L, 4L, (-4L), 0x9654480BL}};
    int l_794 = 0xB5B64923L;
    int i, j;
    for (i = 0; i < 7; i++)
        l_759[i] = 1UL;
    step_hash(615);
    for (p_16 = 0; (p_16 <= 3); p_16 += 1)
    {
        int *l_22 = (void*)0;
        int *l_743 = &g_69[2][1];
        int *l_744 = &g_69[1][2];
        int *l_745 = &g_69[1][2];
        int *l_746 = &g_604;
        int *l_747 = &g_69[1][2];
        int *l_748 = &g_69[0][0];
        int *l_749 = (void*)0;
        int *l_750 = &g_69[1][2];
        int *l_751 = &g_604;
        int *l_752 = &g_604;
        int *l_753 = &g_69[1][2];
        int l_754 = 0x4A7B852CL;
        int *l_755 = &l_754;
        int *l_756[2][7] = {{&l_754, &l_754, &l_754, &l_754, &l_754, &l_754, &l_754}, {&l_754, &l_754, &l_754, &l_754, &l_754, &l_754, &l_754}};
        unsigned short l_773[6] = {65528UL, 65528UL, 65526UL, 65528UL, 65528UL, 65526UL};
        signed char l_793[4] = {(-1L), 0x46L, (-1L), 0x46L};
        int i, j;
        step_hash(583);
        for (p_17 = 0; (p_17 <= 3); p_17 += 1)
        {
            int **l_23[7];
            int i, j;
            for (i = 0; i < 7; i++)
                l_23[i] = &l_22;
            step_hash(13);
            l_24 = func_19(l_18[p_17][(p_17 + 3)], l_22);
        }
        step_hash(584);
        l_759[3]--;
    }
    step_hash(616);
    return l_794;
}
static int * func_19(signed char p_20, int * p_21)
{
    step_hash(12);
    return p_21;
}







static int func_26(unsigned short p_27, unsigned char p_28)
{
    unsigned short l_35 = 0x70A6L;
    int *l_39 = &g_3;
    int **l_38[9] = {&l_39, &l_39, &l_39, &l_39, &l_39, &l_39, &l_39, &l_39, &l_39};
    int l_677 = 0xD8D15997L;
    int ***l_678[9] = {(void*)0, &g_80, (void*)0, &g_80, (void*)0, &g_80, (void*)0, &g_80, (void*)0};
    unsigned l_716[3][9] = {{0UL, 0UL, 0xDF9847A2L, 0x200534F1L, 0x41B48F0DL, 0UL, 0x41B48F0DL, 0x200534F1L, 0xDF9847A2L}, {0UL, 0UL, 0xDF9847A2L, 0x200534F1L, 0x41B48F0DL, 0UL, 0x41B48F0DL, 0x200534F1L, 0xDF9847A2L}, {0UL, 0UL, 0xDF9847A2L, 0x200534F1L, 0x41B48F0DL, 0UL, 0x41B48F0DL, 0x200534F1L, 0xDF9847A2L}};
    int l_718[1];
    int l_719 = 0x9A6EC0C8L;
    int i, j;
    for (i = 0; i < 1; i++)
        l_718[i] = (-1L);
    step_hash(15);
    l_35 |= ((unsigned short)0UL << (unsigned short)2);
    step_hash(502);
    g_81[2] = func_36(l_38[0]);
    step_hash(558);
    for (g_399 = 1; (g_399 >= 11); g_399 += 7)
    {
        int *l_667 = &g_69[1][2];
        int l_670 = (-1L);
        unsigned char l_684 = 0xD8L;
        unsigned short l_717 = 65535UL;
        step_hash(555);
        for (g_77 = 0; (g_77 >= 6); g_77 += 7)
        {
            int l_658 = 3L;
            unsigned l_688 = 9UL;
            unsigned l_710 = 0xFEA74D49L;
            int l_711 = 0L;
        }
        step_hash(556);
        (*l_667) = (((p_28 & ((signed char)(((void*)0 != &l_670) == p_28) - (signed char)((((p_28 < ((unsigned char)(*l_667) >> (unsigned char)7)) >= g_512) > (g_69[1][2] > l_716[0][2])) >= p_28))) <= (*l_667)) > l_717);
        step_hash(557);
        if (l_718[0])
            break;
    }
    step_hash(559);
    l_719 |= (-2L);
    step_hash(560);
    return p_28;
}







static int * func_36(int ** p_37)
{
    int l_50[2][6] = {{6L, 0xAED5A0A0L, 6L, 0xAED5A0A0L, 6L, 0xAED5A0A0L}, {6L, 0xAED5A0A0L, 6L, 0xAED5A0A0L, 6L, 0xAED5A0A0L}};
    int *l_632 = &g_69[1][2];
    unsigned short l_646 = 65533UL;
    int i, j;
    step_hash(480);
    l_50[1][5] = func_40(func_42(g_25, (g_2[0][5] | func_48(((0xD0L == l_50[1][2]) && 0xD5E7L))), p_37, l_50[1][2], g_80));
    step_hash(481);
    l_50[1][2] = l_50[0][4];
    step_hash(482);
    (*l_632) = (((void*)0 != p_37) && ((unsigned short)(g_284 ^ (l_50[0][5] || g_63[0])) % (unsigned short)0xD363L));
    step_hash(500);
    for (g_604 = 0; (g_604 >= 0); g_604 -= 1)
    {
        int *l_637 = &g_604;
        int l_642[7][9] = {{(-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L)}, {(-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L)}, {(-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L)}, {(-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L)}, {(-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L)}, {(-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L)}, {(-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L), (-8L), 0xE8EB4D9DL, (-8L), (-2L)}};
        short l_645 = 1L;
        int **l_652 = &g_81[3];
        int i, j;
    }
    step_hash(501);
    return g_653;
}







static int func_40(int * p_41)
{
    signed char l_600[8] = {1L, 1L, (-1L), 1L, 1L, (-1L), 1L, 1L};
    int ***l_605[5];
    unsigned l_619 = 4294967295UL;
    int i;
    for (i = 0; i < 5; i++)
        l_605[i] = &g_80;
    step_hash(478);
    for (g_512 = 8; (g_512 < (-15)); g_512--)
    {
        int *l_601 = &g_69[2][0];
        step_hash(465);
        (*l_601) ^= l_600[1];
        step_hash(466);
        (*l_601) = ((signed char)(~(g_399 && (l_605[3] != &g_80))) >> (signed char)(0x50F7B81FL <= (g_2[0][4] && (((unsigned char)((unsigned short)0x15BDL * (unsigned short)(+(((void*)0 == p_41) >= (-10L)))) / (unsigned char)g_69[1][2]) < g_3))));
        step_hash(476);
        for (g_25 = 0; (g_25 <= 2); g_25 += 1)
        {
            unsigned l_613 = 4294967295UL;
            step_hash(475);
            for (g_77 = 0; (g_77 <= 4); g_77 += 1)
            {
                int l_610 = (-4L);
                signed char l_611[1][6] = {{0x9AL, 0L, 0x9AL, 0L, 0x9AL, 0L}};
                int l_612[5] = {0x29DF4F1BL, 0xBDB339B9L, 0x29DF4F1BL, 0xBDB339B9L, 0x29DF4F1BL};
                short l_618[2];
                int i, j;
                for (i = 0; i < 2; i++)
                    l_618[i] = 0x2C06L;
                step_hash(473);
                --l_613;
                step_hash(474);
                l_618[1] = ((signed char)0x19L << (signed char)g_69[g_25][g_25]);
            }
        }
        step_hash(477);
        g_80 = (void*)0;
    }
    step_hash(479);
    return l_619;
}







static int * func_42(signed char p_43, short p_44, int ** p_45, unsigned char p_46, int ** p_47)
{
    int *l_405 = (void*)0;
    int l_410 = 0L;
    int l_413 = 0L;
    int l_414[7][6] = {{1L, 0x1D20E5B2L, 1L, 0L, 7L, 0x4CA6F729L}, {1L, 0x1D20E5B2L, 1L, 0L, 7L, 0x4CA6F729L}, {1L, 0x1D20E5B2L, 1L, 0L, 7L, 0x4CA6F729L}, {1L, 0x1D20E5B2L, 1L, 0L, 7L, 0x4CA6F729L}, {1L, 0x1D20E5B2L, 1L, 0L, 7L, 0x4CA6F729L}, {1L, 0x1D20E5B2L, 1L, 0L, 7L, 0x4CA6F729L}, {1L, 0x1D20E5B2L, 1L, 0L, 7L, 0x4CA6F729L}};
    unsigned short l_422 = 1UL;
    unsigned l_423 = 4294967295UL;
    unsigned short l_446 = 1UL;
    int l_536[3];
    int ***l_545 = &g_80;
    int *l_595 = &g_25;
    int *l_596 = &l_536[0];
    int *l_597 = (void*)0;
    int i, j;
    for (i = 0; i < 3; i++)
        l_536[i] = 0xABDD28EFL;
    step_hash(330);
    (*g_80) = l_405;
    step_hash(343);
    for (g_399 = 0; (g_399 >= (-1)); --g_399)
    {
        int *l_408 = &g_69[1][2];
        int *l_409 = &g_69[2][2];
        int *l_411 = &l_410;
        int *l_412[9];
        unsigned l_415 = 0xA6152829L;
        int i;
        for (i = 0; i < 9; i++)
            l_412[i] = &l_410;
        step_hash(334);
        ++l_415;
        step_hash(335);
        (*l_408) = (g_69[1][2] > (*l_409));
        step_hash(336);
        if (p_44)
            break;
        step_hash(342);
        for (g_284 = 10; (g_284 == (-16)); --g_284)
        {
            step_hash(340);
            l_422 = ((unsigned char)p_43 / (unsigned char)0x78L);
            step_hash(341);
            (*l_408) &= 7L;
        }
    }
    step_hash(458);
    if (l_423)
    {
        int *l_424 = &l_414[0][1];
        step_hash(345);
        (*p_47) = l_424;
        step_hash(346);
        (*l_424) = (*l_424);
    }
    else
    {
        unsigned short l_425 = 0xEB44L;
        unsigned l_435[4] = {4294967295UL, 0x0593E5CDL, 4294967295UL, 0x0593E5CDL};
        int l_436 = 0xA3D276FBL;
        signed char l_456 = 0L;
        unsigned l_471 = 0xD501E037L;
        signed char l_501 = 0xB5L;
        int l_509 = 5L;
        int l_513 = 0x8067A6EBL;
        int l_515 = 0xBC9AE906L;
        int l_517 = 0xD788FA73L;
        int l_522[5][5] = {{1L, 0x580D25E7L, 0L, (-1L), (-1L)}, {1L, 0x580D25E7L, 0L, (-1L), (-1L)}, {1L, 0x580D25E7L, 0L, (-1L), (-1L)}, {1L, 0x580D25E7L, 0L, (-1L), (-1L)}, {1L, 0x580D25E7L, 0L, (-1L), (-1L)}};
        unsigned short l_525 = 0xA3EBL;
        int ***l_544[1][10] = {{(void*)0, (void*)0, &g_80, (void*)0, (void*)0, &g_80, (void*)0, (void*)0, &g_80, (void*)0}};
        unsigned char l_551 = 0x36L;
        signed char l_560[1][5];
        int *l_590 = &l_414[3][0];
        int *l_591 = &l_522[3][4];
        int i, j;
        for (i = 0; i < 1; i++)
        {
            for (j = 0; j < 5; j++)
                l_560[i][j] = 0x7AL;
        }
        step_hash(348);
        l_414[0][1] &= l_425;
        step_hash(373);
        if ((!(0x74005842L || 0xFDB3F3CBL)))
        {
            int ***l_428 = (void*)0;
            int **l_434 = &l_405;
            step_hash(350);
            (*p_47) = func_19(g_69[2][2], func_19(g_3, &g_25));
            step_hash(351);
            l_436 &= (((signed char)((&p_47 != l_428) > (l_423 && ((int)(l_428 == &p_45) + (int)((-(int)((unsigned short)g_63[0] * (unsigned short)((l_434 != p_47) > (g_63[0] < l_435[0])))) > p_44)))) >> (signed char)p_46) | g_3);
            step_hash(356);
            for (g_25 = 0; (g_25 <= 0); g_25 += 1)
            {
                step_hash(355);
                return &g_25;
            }
            step_hash(357);
            (*g_80) = func_19(((l_436 || ((1L != 0x3BL) <= 0x31039514L)) > ((((g_63[0] && ((short)((short)l_435[3] - (short)((unsigned char)255UL + (unsigned char)0xE5L)) * (short)0UL)) && l_435[0]) & g_399) ^ l_446)), &g_69[1][2]);
        }
        else
        {
            step_hash(372);
            for (g_77 = 17; (g_77 < 53); g_77 += 3)
            {
                step_hash(366);
                for (l_413 = (-21); (l_413 < 24); ++l_413)
                {
                    int ***l_451 = &g_80;
                    step_hash(365);
                    (*l_451) = p_45;
                }
                step_hash(371);
                for (p_43 = 4; (p_43 >= 0); p_43 -= 1)
                {
                    int i;
                    step_hash(370);
                    (*p_47) = &g_69[1][2];
                }
            }
        }
        step_hash(457);
        for (l_425 = 0; (l_425 <= 3); l_425 += 1)
        {
            int l_462 = 0xC0204249L;
            int l_502 = 0xCF2547A4L;
            int l_503 = 0L;
            int l_504 = 0x7037EB1AL;
            int l_506 = (-1L);
            int l_507[5][6] = {{0x564BEFC6L, 0x66AA51C4L, 0xE0765D78L, 0x66AA51C4L, 0x564BEFC6L, 0x66AA51C4L}, {0x564BEFC6L, 0x66AA51C4L, 0xE0765D78L, 0x66AA51C4L, 0x564BEFC6L, 0x66AA51C4L}, {0x564BEFC6L, 0x66AA51C4L, 0xE0765D78L, 0x66AA51C4L, 0x564BEFC6L, 0x66AA51C4L}, {0x564BEFC6L, 0x66AA51C4L, 0xE0765D78L, 0x66AA51C4L, 0x564BEFC6L, 0x66AA51C4L}, {0x564BEFC6L, 0x66AA51C4L, 0xE0765D78L, 0x66AA51C4L, 0x564BEFC6L, 0x66AA51C4L}};
            int *l_589 = &l_509;
            int *l_592 = &l_513;
            int *l_593[5][10];
            int i, j;
            for (i = 0; i < 5; i++)
            {
                for (j = 0; j < 10; j++)
                    l_593[i][j] = &l_506;
            }
            step_hash(385);
            for (p_46 = 0; (p_46 <= 3); p_46 += 1)
            {
                step_hash(384);
                for (l_422 = 0; (l_422 <= 3); l_422 += 1)
                {
                    step_hash(383);
                    return &g_25;
                }
            }
            step_hash(414);
            if ((l_435[l_425] >= (((0x85AE5FD1L >= l_435[l_425]) >= g_381[6][0]) <= 0L)))
            {
                unsigned l_461 = 8UL;
                step_hash(387);
                (*p_47) = &g_69[1][0];
                step_hash(388);
                l_436 = ((unsigned)((l_435[l_425] | (((unsigned char)p_43 >> (unsigned char)4) ^ p_44)) | ((p_44 <= ((l_435[l_425] & p_46) ^ l_435[0])) == 0xB40FL)) / (unsigned)l_435[1]);
            }
            else
            {
                int l_463 = 0L;
                int l_470 = 0x54C8AF70L;
                int l_505 = 1L;
                int l_508 = 0x66F370C3L;
                int l_510 = (-2L);
                int l_511 = (-4L);
                int l_514 = 0L;
                int l_516 = 0x4DF85C84L;
                int l_519 = 1L;
                int l_521 = (-1L);
                int l_523[2];
                unsigned l_529 = 0x07C17F65L;
                int i;
                for (i = 0; i < 2; i++)
                    l_523[i] = (-1L);
                step_hash(400);
                if ((((((l_470 < l_435[l_425]) >= l_470) || 0x21A5L) <= g_77) ^ l_435[l_425]))
                {
                    step_hash(397);
                    for (l_446 = 0; (l_446 <= 3); l_446 += 1)
                    {
                        int *l_472 = (void*)0;
                        int *l_473 = (void*)0;
                        int *l_474 = (void*)0;
                        int *l_475[6] = {&g_25, (void*)0, &g_25, (void*)0, &g_25, (void*)0};
                        int i;
                        step_hash(394);
                        if (l_435[l_425])
                            break;
                        step_hash(395);
                        l_414[0][1] &= l_435[l_425];
                        step_hash(396);
                        l_410 |= ((int)((signed char)((unsigned short)0x65E8L >> (unsigned short)2) / (signed char)p_44) - (int)(((unsigned short)((short)((int)p_43 / (int)(((unsigned short)((void*)0 != p_47) * (unsigned short)p_44) ^ ((int)(!((unsigned short)(0L && g_3) * (unsigned short)g_3)) / (int)l_463))) * (short)p_44) >> (unsigned short)2) < g_3));
                    }
                }
                else
                {
                    unsigned l_496 = 4UL;
                    int *l_497 = &l_470;
                    step_hash(399);
                    (*l_497) = ((((&g_81[3] != (void*)0) != 4294967292UL) ^ (((unsigned char)(g_381[6][0] != (p_43 != (g_2[8][6] || (5UL <= p_43)))) % (unsigned char)255UL) != l_496)) ^ g_69[0][2]);
                }
                step_hash(412);
                for (l_422 = 0; (l_422 <= 3); l_422 += 1)
                {
                    int *l_498 = &g_69[1][2];
                    int *l_499 = &l_436;
                    int *l_500[5] = {&l_436, &l_462, &l_436, &l_462, &l_436};
                    int l_518[6][1] = {{1L}, {1L}, {1L}, {1L}, {1L}, {1L}};
                    int l_520 = (-5L);
                    signed char l_524 = 0x96L;
                    int i, j;
                    step_hash(404);
                    if (l_435[l_425])
                        break;
                    step_hash(405);
                    ++l_525;
                    step_hash(411);
                    for (l_504 = 3; (l_504 >= 0); l_504 -= 1)
                    {
                        step_hash(409);
                        if (p_43)
                            break;
                        step_hash(410);
                        (*l_498) = ((-(unsigned char)0x1CL) < 0x17C7L);
                    }
                }
                step_hash(413);
                if (l_529)
                    break;
            }
            step_hash(450);
            if (l_506)
            {
                int l_537 = 0x0449D25AL;
                int l_554 = 0x7C655232L;
                int **l_561[4] = {&l_405, (void*)0, &l_405, (void*)0};
                int *l_594 = &g_25;
                int i;
                step_hash(436);
                if ((((unsigned char)((signed char)p_44 << (signed char)0) >> (unsigned char)7) == (((short)l_536[1] << (short)((l_506 | l_537) >= ((((unsigned short)(((short)((short)(l_544[0][3] == l_545) / (short)g_69[0][0]) * (short)l_537) ^ g_512) >> (unsigned short)12) && g_69[1][2]) <= l_504))) && 0x98L)))
                {
                    unsigned char l_550[2][2] = {{0x8CL, 0xC8L}, {0x8CL, 0xC8L}};
                    int i, j;
                    step_hash(417);
                    l_551 = (((unsigned char)((signed char)(g_25 != (!(((l_550[0][1] >= g_2[3][5]) ^ ((!(~l_537)) != 3UL)) == 0x8117L))) >> (signed char)2) >> (unsigned char)0) <= (p_43 > l_550[0][1]));
                    step_hash(418);
                    l_537 ^= ((unsigned char)(&l_462 != &g_3) >> (unsigned char)1);
                }
                else
                {
                    unsigned l_568 = 4294967290UL;
                    unsigned char l_580 = 1UL;
                    int l_582 = 0L;
                    unsigned short l_585[5][7] = {{0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L}, {0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L}, {0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L}, {0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L}, {0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L, 0x71F9L, 0x31AAL, 0x71F9L}};
                    int i, j;
                    step_hash(427);
                    for (g_512 = 0; (g_512 <= 0); g_512 += 1)
                    {
                        int *l_559 = &g_25;
                        int i;
                        step_hash(423);
                        l_537 ^= g_63[g_512];
                        step_hash(424);
                        l_554 |= l_537;
                        step_hash(425);
                        (*p_47) = func_19(((unsigned char)p_46 - (unsigned char)((unsigned char)0UL + (unsigned char)0x22L)), l_559);
                        step_hash(426);
                        if (l_560[0][1])
                            continue;
                    }
                    step_hash(435);
                    if (((l_561[1] == &g_81[3]) && (((short)(((signed char)((((int)l_568 / (int)l_435[l_425]) ^ ((short)((signed char)g_3 << (signed char)p_44) >> (short)13)) || 1UL) + (signed char)p_46) > p_43) - (short)g_63[0]) != g_2[8][2])))
                    {
                        int l_581 = (-3L);
                        int l_583 = 0xCA7D7568L;
                        int l_584 = 0xDE48840DL;
                        step_hash(429);
                        l_582 = ((int)(l_580 != 0xC2F9DA00L) / (int)l_581);
                        step_hash(430);
                        l_507[3][0] ^= 0x50CB2111L;
                        step_hash(431);
                        (*p_47) = &l_506;
                        step_hash(432);
                        ++l_585[0][2];
                    }
                    else
                    {
                        int *l_588[7][4] = {{&l_414[0][1], &l_536[1], &l_536[1], &l_582}, {&l_414[0][1], &l_536[1], &l_536[1], &l_582}, {&l_414[0][1], &l_536[1], &l_536[1], &l_582}, {&l_414[0][1], &l_536[1], &l_536[1], &l_582}, {&l_414[0][1], &l_536[1], &l_536[1], &l_582}, {&l_414[0][1], &l_536[1], &l_536[1], &l_582}, {&l_414[0][1], &l_536[1], &l_536[1], &l_582}};
                        int i, j;
                        step_hash(434);
                        (*p_47) = l_588[5][0];
                    }
                }
                step_hash(437);
                return l_594;
            }
            else
            {
                step_hash(439);
                (*l_589) = (1L > 65535UL);
                step_hash(440);
                for (p_43 = 0; p_43 < 1; p_43 += 1)
                {
                    g_63[p_43] = 65535UL;
                }
                step_hash(449);
                for (l_551 = 0; (l_551 <= 2); l_551 += 1)
                {
                    step_hash(448);
                    for (l_456 = 2; (l_456 >= 0); l_456 -= 1)
                    {
                        int i;
                        step_hash(447);
                        if (l_435[(l_551 + 1)])
                            break;
                    }
                }
            }
            step_hash(456);
            for (l_513 = 1; (l_513 <= 4); l_513 += 1)
            {
                int i, j;
                step_hash(454);
                (*p_47) = &l_522[l_513][l_425];
                step_hash(455);
                (*l_589) = p_46;
            }
        }
    }
    step_hash(459);
    (*l_595) = l_413;
    step_hash(460);
    return l_597;
}







static int func_48(unsigned p_49)
{
    unsigned char l_55 = 0xDFL;
    int *l_59 = &g_25;
    int **l_58 = &l_59;
    int l_62 = 0L;
    int l_384 = 0xC196D13BL;
    int l_386 = 0x0F7F4287L;
    int l_387 = 0x5BD2089DL;
    unsigned short l_388 = 8UL;
    int l_392[10] = {0xAC9A5B74L, 0x4861DBECL, (-1L), (-1L), 0x4861DBECL, 0xAC9A5B74L, 0x4861DBECL, (-1L), (-1L), 0x4861DBECL};
    unsigned l_400 = 4294967293UL;
    int i;
    step_hash(326);
    for (p_49 = (-23); (p_49 <= 51); p_49++)
    {
        int *l_57[3];
        int **l_56 = &l_57[1];
        int i;
        for (i = 0; i < 3; i++)
            l_57[i] = &g_3;
        step_hash(21);
        l_62 &= (((((unsigned char)g_25 << (unsigned char)l_55) & 0x4CC0L) ^ (l_56 != l_58)) >= ((int)g_3 % (int)(**l_58)));
        step_hash(22);
        g_63[0] = p_49;
    }
    step_hash(327);
    l_384 |= ((short)0x35ADL % (short)func_66(p_49));
    step_hash(328);
    return p_49;
}







static unsigned func_66(int p_67)
{
    int *l_68 = &g_69[1][2];
    int l_72 = (-1L);
    int l_73 = 1L;
    int l_74 = 0xAE354A5AL;
    int l_75[1];
    int l_76 = (-1L);
    int *l_117 = &l_75[0];
    unsigned l_179[9][5] = {{4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}, {4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}, {4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}, {4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}, {4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}, {4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}, {4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}, {4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}, {4294967295UL, 0UL, 0x092D7B6EL, 4294967295UL, 0x092D7B6EL}};
    unsigned l_231[1];
    short l_282 = 0x477EL;
    signed char l_283 = 0x04L;
    unsigned short l_341 = 65535UL;
    int l_380[9][6] = {{0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}, {0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}, {0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}, {0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}, {0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}, {0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}, {0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}, {0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}, {0L, 0x5795E8B1L, 0x9F0471CBL, 0xEFFC2D33L, 0L, 0xA0E3ADE0L}};
    int i, j;
    for (i = 0; i < 1; i++)
        l_75[i] = 1L;
    for (i = 0; i < 1; i++)
        l_231[i] = 2UL;
    step_hash(24);
    (*l_68) |= p_67;
    step_hash(51);
    for (p_67 = 0; (p_67 >= 0); p_67 -= 1)
    {
        int *l_70 = &g_69[1][2];
        int *l_71[8][8] = {{&g_69[2][2], &g_69[0][2], (void*)0, (void*)0, (void*)0, &g_69[0][2], &g_69[2][2], &g_69[1][2]}, {&g_69[2][2], &g_69[0][2], (void*)0, (void*)0, (void*)0, &g_69[0][2], &g_69[2][2], &g_69[1][2]}, {&g_69[2][2], &g_69[0][2], (void*)0, (void*)0, (void*)0, &g_69[0][2], &g_69[2][2], &g_69[1][2]}, {&g_69[2][2], &g_69[0][2], (void*)0, (void*)0, (void*)0, &g_69[0][2], &g_69[2][2], &g_69[1][2]}, {&g_69[2][2], &g_69[0][2], (void*)0, (void*)0, (void*)0, &g_69[0][2], &g_69[2][2], &g_69[1][2]}, {&g_69[2][2], &g_69[0][2], (void*)0, (void*)0, (void*)0, &g_69[0][2], &g_69[2][2], &g_69[1][2]}, {&g_69[2][2], &g_69[0][2], (void*)0, (void*)0, (void*)0, &g_69[0][2], &g_69[2][2], &g_69[1][2]}, {&g_69[2][2], &g_69[0][2], (void*)0, (void*)0, (void*)0, &g_69[0][2], &g_69[2][2], &g_69[1][2]}};
        int i, j;
        step_hash(28);
        g_77--;
        step_hash(50);
        for (l_74 = 0; (l_74 <= 0); l_74 += 1)
        {
            int i, j;
            step_hash(32);
            g_69[p_67][(p_67 + 2)] ^= (&l_68 == g_80);
            step_hash(42);
            for (l_73 = 0; (l_73 <= 0); l_73 += 1)
            {
                int i, j;
                step_hash(36);
                if (g_69[l_73][(p_67 + 2)])
                    break;
                step_hash(41);
                if ((((-4L) < 0xA230L) ^ g_63[p_67]))
                {
                    step_hash(38);
                    return p_67;
                }
                else
                {
                    step_hash(40);
                    return g_25;
                }
            }
        }
    }
    step_hash(317);
    if (p_67)
    {
        int **l_89 = &g_81[3];
        int *l_90 = (void*)0;
        int *l_91[8][7] = {{&l_76, &l_75[0], &l_75[0], &l_72, &l_75[0], &l_75[0], &l_75[0]}, {&l_76, &l_75[0], &l_75[0], &l_72, &l_75[0], &l_75[0], &l_75[0]}, {&l_76, &l_75[0], &l_75[0], &l_72, &l_75[0], &l_75[0], &l_75[0]}, {&l_76, &l_75[0], &l_75[0], &l_72, &l_75[0], &l_75[0], &l_75[0]}, {&l_76, &l_75[0], &l_75[0], &l_72, &l_75[0], &l_75[0], &l_75[0]}, {&l_76, &l_75[0], &l_75[0], &l_72, &l_75[0], &l_75[0], &l_75[0]}, {&l_76, &l_75[0], &l_75[0], &l_72, &l_75[0], &l_75[0], &l_75[0]}, {&l_76, &l_75[0], &l_75[0], &l_72, &l_75[0], &l_75[0], &l_75[0]}};
        signed char l_92 = 8L;
        int l_131[3][3] = {{0L, 1L, 0L}, {0L, 1L, 0L}, {0L, 1L, 0L}};
        int l_134 = 0L;
        unsigned l_175 = 0xB8245335L;
        unsigned l_191 = 0x1B506038L;
        signed char l_199 = 9L;
        int i, j;
        step_hash(53);
        l_92 ^= ((*l_68) && ((signed char)(l_89 != &l_68) + (signed char)g_63[0]));
        step_hash(195);
        for (l_74 = 0; (l_74 != (-1)); l_74--)
        {
            unsigned short l_95 = 0xDCEEL;
            int l_98 = 0x42BFDF69L;
            unsigned short l_99 = 0x042FL;
            short l_108 = 0x31B0L;
            int *l_125[10] = {&g_69[0][0], &l_73, &l_72, &l_72, &l_73, &g_69[0][0], &l_73, &l_72, &l_72, &l_73};
            unsigned l_163 = 4294967294UL;
            int l_190[8] = {0xCEC5DDE9L, 0xCEC5DDE9L, 8L, 0xCEC5DDE9L, 0xCEC5DDE9L, 8L, 0xCEC5DDE9L, 0xCEC5DDE9L};
            int **l_197 = &g_81[3];
            unsigned char l_200 = 246UL;
            int i;
            step_hash(57);
            l_95--;
            step_hash(58);
            --l_99;
        }
    }
    else
    {
        unsigned short l_217 = 0x603EL;
        int l_227 = 0xA9FFF2E2L;
        int l_230[9];
        unsigned l_285 = 0xA150D49BL;
        unsigned short l_294 = 0xC941L;
        int ***l_348 = (void*)0;
        int i;
        for (i = 0; i < 9; i++)
            l_230[i] = 1L;
        step_hash(201);
        for (l_73 = 0; (l_73 >= 0); l_73 -= 1)
        {
            int i;
            step_hash(200);
            (*l_68) = (((0UL || ((unsigned short)l_75[l_73] / (unsigned short)((((((signed char)((unsigned)((((unsigned char)l_75[l_73] << (unsigned char)7) >= 4294967289UL) > ((short)((int)0x15F20776L % (int)g_63[l_73]) >> (short)(g_63[l_73] > p_67))) - (unsigned)l_217) + (signed char)g_77) ^ g_77) || p_67) != g_25) | p_67))) ^ g_2[6][7]) == p_67);
        }
        step_hash(316);
        if (l_217)
        {
            int *l_218 = &l_74;
            int *l_219 = &l_76;
            int *l_220 = &l_76;
            int *l_221 = &g_69[1][2];
            int *l_222 = &l_73;
            int *l_223 = &l_75[0];
            int *l_224 = &g_69[2][1];
            int *l_225 = &g_69[0][2];
            int *l_226 = &l_73;
            int *l_228 = &l_75[0];
            int *l_229[1][6];
            int i, j;
            for (i = 0; i < 1; i++)
            {
                for (j = 0; j < 6; j++)
                    l_229[i][j] = &l_75[0];
            }
            step_hash(203);
            ++l_231[0];
            step_hash(208);
            for (p_67 = 0; (p_67 < 17); p_67 += 1)
            {
                step_hash(207);
                return g_77;
            }
        }
        else
        {
            unsigned l_258 = 0x4F7B4F8BL;
            int *l_266 = &l_227;
            int l_271 = 1L;
            int l_274 = (-6L);
            int l_280[7];
            int ***l_291 = (void*)0;
            int i;
            for (i = 0; i < 7; i++)
                l_280[i] = 0xE116C163L;
            step_hash(283);
            if ((l_227 || g_69[2][1]))
            {
                unsigned l_261 = 0x9122180EL;
                int l_273[8][7] = {{0xAEB1A127L, 0x310BF789L, 0x7615848DL, 0x4EB570CDL, (-1L), 4L, (-1L)}, {0xAEB1A127L, 0x310BF789L, 0x7615848DL, 0x4EB570CDL, (-1L), 4L, (-1L)}, {0xAEB1A127L, 0x310BF789L, 0x7615848DL, 0x4EB570CDL, (-1L), 4L, (-1L)}, {0xAEB1A127L, 0x310BF789L, 0x7615848DL, 0x4EB570CDL, (-1L), 4L, (-1L)}, {0xAEB1A127L, 0x310BF789L, 0x7615848DL, 0x4EB570CDL, (-1L), 4L, (-1L)}, {0xAEB1A127L, 0x310BF789L, 0x7615848DL, 0x4EB570CDL, (-1L), 4L, (-1L)}, {0xAEB1A127L, 0x310BF789L, 0x7615848DL, 0x4EB570CDL, (-1L), 4L, (-1L)}, {0xAEB1A127L, 0x310BF789L, 0x7615848DL, 0x4EB570CDL, (-1L), 4L, (-1L)}};
                int **l_292 = &g_81[2];
                int i, j;
                step_hash(222);
                for (l_217 = (-26); (l_217 >= 37); l_217 += 9)
                {
                    int l_244[3][2] = {{0x2C99AB52L, 0x2C99AB52L}, {0x2C99AB52L, 0x2C99AB52L}, {0x2C99AB52L, 0x2C99AB52L}};
                    int i, j;
                    step_hash(221);
                    for (l_72 = 0; (l_72 <= (-23)); --l_72)
                    {
                        step_hash(217);
                        if (l_230[4])
                            break;
                        step_hash(218);
                        if (p_67)
                            continue;
                        step_hash(219);
                        (*l_117) = (((unsigned short)0x32CFL * (unsigned short)((p_67 ^ ((short)0L >> (short)13)) | (**g_80))) || l_244[0][0]);
                        step_hash(220);
                        if ((*l_117))
                            break;
                    }
                }
                step_hash(249);
                for (l_76 = 0; (l_76 >= 23); l_76 += 1)
                {
                    signed char l_249 = 0xC4L;
                    int l_272 = 0x35D1E971L;
                    int l_275 = 1L;
                    int l_276[5] = {4L, 0xB89AE079L, 4L, 0xB89AE079L, 4L};
                    unsigned l_277 = 0xC68E37BBL;
                    short l_281[6] = {0x4A58L, 0xFE76L, 0x4A58L, 0xFE76L, 0x4A58L, 0xFE76L};
                    int i;
                    step_hash(232);
                    for (l_72 = 0; (l_72 == (-10)); l_72 -= 3)
                    {
                        step_hash(229);
                        (*l_117) = (**g_80);
                        step_hash(230);
                        l_249 = ((((void*)0 == (*g_80)) || g_77) <= g_25);
                        step_hash(231);
                        (*g_80) = &p_67;
                    }
                    step_hash(233);
                    (*g_80) = (*g_80);
                    step_hash(241);
                    if ((((int)((short)((0L & ((short)g_25 * (short)g_2[5][1])) != (**g_80)) + (short)((*l_117) >= 0L)) - (int)(!(l_258 < ((((unsigned short)p_67 << (unsigned short)g_63[0]) && 4294967295UL) <= g_3)))) >= l_261))
                    {
                        step_hash(235);
                        (*g_80) = func_19(l_249, (*g_80));
                    }
                    else
                    {
                        step_hash(237);
                        if (p_67)
                            break;
                        step_hash(238);
                        (*l_68) = l_230[4];
                        step_hash(239);
                        if (p_67)
                            break;
                        step_hash(240);
                        (*g_80) = func_19((p_67 & ((**g_80) != (((signed char)(((int)(-3L) - (int)((*g_80) == l_266)) ^ ((!g_69[2][2]) < (*l_266))) * (signed char)(&p_67 == &p_67)) < p_67))), (*g_80));
                    }
                    step_hash(248);
                    for (l_74 = 0; (l_74 > 7); l_74 += 5)
                    {
                        int *l_269 = &g_69[1][0];
                        int *l_270[7][10] = {{&l_230[4], &g_3, &l_75[0], (void*)0, &l_73, &l_75[0], &l_73, (void*)0, &l_75[0], &g_3}, {&l_230[4], &g_3, &l_75[0], (void*)0, &l_73, &l_75[0], &l_73, (void*)0, &l_75[0], &g_3}, {&l_230[4], &g_3, &l_75[0], (void*)0, &l_73, &l_75[0], &l_73, (void*)0, &l_75[0], &g_3}, {&l_230[4], &g_3, &l_75[0], (void*)0, &l_73, &l_75[0], &l_73, (void*)0, &l_75[0], &g_3}, {&l_230[4], &g_3, &l_75[0], (void*)0, &l_73, &l_75[0], &l_73, (void*)0, &l_75[0], &g_3}, {&l_230[4], &g_3, &l_75[0], (void*)0, &l_73, &l_75[0], &l_73, (void*)0, &l_75[0], &g_3}, {&l_230[4], &g_3, &l_75[0], (void*)0, &l_73, &l_75[0], &l_73, (void*)0, &l_75[0], &g_3}};
                        int i, j;
                        step_hash(245);
                        (*l_266) |= (*l_117);
                        step_hash(246);
                        l_277++;
                        step_hash(247);
                        l_285--;
                    }
                }
                step_hash(250);
                (*l_292) = func_19(p_67, func_19((-(unsigned short)((unsigned char)(l_291 != (void*)0) << (unsigned char)(l_292 != &g_81[3]))), (*g_80)));
                step_hash(251);
                (*g_80) = func_19(g_77, &p_67);
            }
            else
            {
                int l_299 = (-1L);
                int l_300 = 3L;
                short l_340[2][9] = {{0x6CD5L, 0L, 0x6CD5L, 0L, 0x6CD5L, 0L, 0x6CD5L, 0L, 0x6CD5L}, {0x6CD5L, 0L, 0x6CD5L, 0L, 0x6CD5L, 0L, 0x6CD5L, 0L, 0x6CD5L}};
                int ***l_349 = (void*)0;
                int i, j;
                step_hash(281);
                if (p_67)
                {
                    int *l_293[3];
                    unsigned short l_301[7][7] = {{0x88C4L, 0x42F5L, 0xB4E1L, 0x0DA8L, 65532UL, 0x2332L, 1UL}, {0x88C4L, 0x42F5L, 0xB4E1L, 0x0DA8L, 65532UL, 0x2332L, 1UL}, {0x88C4L, 0x42F5L, 0xB4E1L, 0x0DA8L, 65532UL, 0x2332L, 1UL}, {0x88C4L, 0x42F5L, 0xB4E1L, 0x0DA8L, 65532UL, 0x2332L, 1UL}, {0x88C4L, 0x42F5L, 0xB4E1L, 0x0DA8L, 65532UL, 0x2332L, 1UL}, {0x88C4L, 0x42F5L, 0xB4E1L, 0x0DA8L, 65532UL, 0x2332L, 1UL}, {0x88C4L, 0x42F5L, 0xB4E1L, 0x0DA8L, 65532UL, 0x2332L, 1UL}};
                    int i, j;
                    for (i = 0; i < 3; i++)
                        l_293[i] = &g_69[1][2];
                    step_hash(254);
                    l_294--;
                    step_hash(261);
                    for (l_258 = 0; (l_258 <= 21); ++l_258)
                    {
                        unsigned char l_304 = 0x61L;
                        step_hash(258);
                        l_301[4][1]--;
                        step_hash(259);
                        --l_304;
                        step_hash(260);
                        (*g_80) = (*g_80);
                    }
                }
                else
                {
                    signed char l_307 = 0xC8L;
                    int l_339[7][2] = {{5L, 5L}, {5L, 5L}, {5L, 5L}, {5L, 5L}, {5L, 5L}, {5L, 5L}, {5L, 5L}};
                    int i, j;
                    step_hash(270);
                    if (l_307)
                    {
                        unsigned l_317 = 0x2DF453E9L;
                        step_hash(264);
                        (*l_68) = (((unsigned short)p_67 * (unsigned short)(g_69[1][2] > 0x9EL)) <= 0xD804L);
                        step_hash(265);
                        (*g_80) = func_19(((g_63[0] > ((signed char)(-(unsigned short)g_2[6][3]) >> (signed char)g_69[1][0])) != 0x1BB33F9AL), &p_67);
                        step_hash(266);
                        (*l_68) = (((short)g_77 % (short)((short)l_317 * (short)((unsigned)((unsigned short)(p_67 ^ 249UL) * (unsigned short)0x611FL) - (unsigned)l_300))) == (&l_300 == (void*)0));
                    }
                    else
                    {
                        step_hash(268);
                        (*g_80) = (*g_80);
                        step_hash(269);
                        (*l_68) = ((unsigned short)p_67 / (unsigned short)2L);
                    }
                    step_hash(279);
                    if (l_230[6])
                    {
                        int *l_324 = &l_280[3];
                        int *l_325 = &l_72;
                        int *l_326 = &l_230[4];
                        int *l_327 = (void*)0;
                        int *l_328 = &l_75[0];
                        int *l_329 = &l_75[0];
                        int *l_330 = (void*)0;
                        int *l_331 = &l_74;
                        int *l_332 = (void*)0;
                        int *l_333 = &l_274;
                        int *l_334 = &l_75[0];
                        int *l_335 = &l_271;
                        int *l_336 = &l_300;
                        int *l_337 = &l_271;
                        int *l_338[5];
                        int i;
                        for (i = 0; i < 5; i++)
                            l_338[i] = &l_271;
                        step_hash(272);
                        (*l_117) &= (p_67 != 2UL);
                        step_hash(273);
                        --l_341;
                        step_hash(274);
                        (*l_266) &= (p_67 || 0x4DL);
                    }
                    else
                    {
                        step_hash(276);
                        (*l_68) &= p_67;
                        step_hash(277);
                        l_339[0][1] &= ((*g_80) == (void*)0);
                        step_hash(278);
                        (*l_266) &= (**g_80);
                    }
                    step_hash(280);
                    return g_25;
                }
                step_hash(282);
                (*l_266) |= ((&p_67 == (void*)0) & ((short)g_69[1][2] * (short)((unsigned char)((l_291 == (void*)0) >= (l_348 != l_349)) / (unsigned char)1L)));
            }
            step_hash(315);
            for (l_341 = 0; (l_341 <= 0); l_341 += 1)
            {
                int *l_350 = &l_280[5];
                unsigned l_377[9] = {1UL, 1UL, 4UL, 1UL, 1UL, 4UL, 1UL, 1UL, 4UL};
                int i;
                step_hash(293);
                for (g_77 = 0; (g_77 <= 2); g_77 += 1)
                {
                    int **l_356[8][2] = {{(void*)0, &l_350}, {(void*)0, &l_350}, {(void*)0, &l_350}, {(void*)0, &l_350}, {(void*)0, &l_350}, {(void*)0, &l_350}, {(void*)0, &l_350}, {(void*)0, &l_350}};
                    int i, j;
                    step_hash(290);
                    (*g_80) = l_350;
                    step_hash(291);
                    if (l_231[l_341])
                        continue;
                    step_hash(292);
                    g_69[g_77][g_77] ^= (0xD5F7L && ((int)(-(unsigned)(*l_350)) % (int)((signed char)((l_356[6][1] == l_356[6][1]) ^ 0x119B53ADL) / (signed char)((short)p_67 << (short)12))));
                }
                step_hash(298);
                for (l_285 = 0; (l_285 <= 0); l_285 += 1)
                {
                    step_hash(297);
                    return g_63[0];
                }
                step_hash(313);
                for (l_74 = 0; (l_74 >= 0); l_74 -= 1)
                {
                    int i;
                    step_hash(302);
                    l_280[(l_74 + 3)] = ((unsigned)((int)l_75[l_341] - (int)(l_280[(l_74 + 3)] >= ((short)(((unsigned char)p_67 >> (unsigned char)4) >= (-9L)) - (short)((short)g_69[1][2] * (short)g_77)))) - (unsigned)((g_25 && p_67) && (-1L)));
                    step_hash(303);
                    (*g_80) = &p_67;
                    step_hash(304);
                    (*l_117) = (0x2B3A094EL ^ (((unsigned short)g_2[2][8] % (unsigned short)1L) && (**g_80)));
                }
                step_hash(314);
                return g_3;
            }
        }
    }
    step_hash(318);
    return g_284;
}


void csmith_compute_hash(void)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            transparent_crc(g_2[i][j], "g_2[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_25, "g_25", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_63[i], "g_63[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transparent_crc(g_69[i][j], "g_69[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_77, "g_77", print_hash_value);
    transparent_crc(g_284, "g_284", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(g_381[i][j], "g_381[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_399, "g_399", print_hash_value);
    transparent_crc(g_512, "g_512", print_hash_value);
    transparent_crc(g_573, "g_573", print_hash_value);
    transparent_crc(g_604, "g_604", print_hash_value);
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_638[i], "g_638[i]", print_hash_value);
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
