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
static int g_4 = 0x67A876E6L;
static int g_10 = 0xC5EB2006L;
static int g_71 = 0x51ECDE47L;
static int g_72 = 0x995E148CL;
static signed char g_108 = 0L;
static signed char g_109 = 0x00L;
static unsigned g_112 = 0UL;
static int *g_117 = &g_71;
static int **g_116 = &g_117;
static unsigned char g_128 = 0x87L;
static unsigned short g_144 = 65535UL;
static short g_155 = 0x2CBFL;
static unsigned short g_156[4][9] = {{65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL}, {65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL}, {65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL}, {65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL, 65528UL}};
static short g_173[9][2] = {{1L, 0x0713L}, {1L, 0x0713L}, {1L, 0x0713L}, {1L, 0x0713L}, {1L, 0x0713L}, {1L, 0x0713L}, {1L, 0x0713L}, {1L, 0x0713L}, {1L, 0x0713L}};
static unsigned g_177 = 4294967289UL;
static signed char g_192 = (-8L);
static unsigned char g_193 = 1UL;
static unsigned short g_285 = 0UL;
static unsigned g_294 = 0UL;
static int g_343 = 0x3E3CC25AL;
static short g_345 = 0x39F1L;
static unsigned short g_346[9] = {0UL, 4UL, 0UL, 4UL, 0UL, 4UL, 0UL, 4UL, 0UL};
static unsigned g_362 = 6UL;
static unsigned g_379 = 0xC057A79DL;
static unsigned g_382 = 3UL;
static unsigned g_416 = 4294967291UL;
static int g_445 = 8L;
static signed char g_495 = (-5L);
static unsigned short g_499[4] = {0x8175L, 0x8175L, 0x8175L, 0x8175L};
static signed char g_506[6] = {(-1L), (-1L), 0x0EL, (-1L), (-1L), 0x0EL};
static unsigned g_538 = 4294967294UL;
static int g_553 = (-5L);
static signed char g_587 = 0x2DL;
static unsigned g_589 = 0xED6979E6L;
static unsigned char g_592 = 0xD2L;
static int g_595 = (-1L);
static int g_609[9][5] = {{0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}, {0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}, {0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}, {0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}, {0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}, {0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}, {0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}, {0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}, {0xA145D9A1L, 4L, (-1L), 0x136DF85BL, (-1L)}};
static int g_610 = 0x95CA8796L;
static unsigned g_611[5] = {4294967288UL, 4294967288UL, 4294967288UL, 4294967288UL, 4294967288UL};
static int g_619[8] = {0xB3359B46L, 0xB3359B46L, 0xB3359B46L, 0xB3359B46L, 0xB3359B46L, 0xB3359B46L, 0xB3359B46L, 0xB3359B46L};
static int g_620 = 6L;
static unsigned char g_622 = 0x64L;
static unsigned short g_659 = 3UL;
static int *g_747[4] = {&g_10, &g_10, &g_10, &g_10};
static int g_797 = 0x95EB4067L;
static int func_1(void);
static int * func_12(int * p_13);
static int * func_14(int * p_15, signed char p_16, int * p_17, int p_18, short p_19);
static int * func_20(short p_21, unsigned p_22);
static int func_33(int * p_34, unsigned p_35);
static int * func_36(int p_37, int * p_38, int * p_39);
static int func_48(unsigned short p_49, signed char p_50, unsigned char p_51, unsigned p_52);
static unsigned func_61(short p_62, int p_63, signed char p_64, unsigned p_65);
static unsigned func_68(int * p_69);
static unsigned char func_76(int p_77);
static int func_1(void)
{
    short l_2 = 0x0657L;
    int *l_3 = &g_4;
    int l_11 = 0xC2E9378FL;
    step_hash(1);
    (*l_3) = l_2;
    step_hash(2);
    (*l_3) = (((short)g_4 >> (short)5) | ((!g_4) < (*l_3)));
    step_hash(776);
    for (g_4 = 11; (g_4 != 6); g_4--)
    {
        int *l_9[7][10] = {{&g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_4, (void*)0}, {&g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_4, (void*)0}, {&g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_4, (void*)0}, {&g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_4, (void*)0}, {&g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_4, (void*)0}, {&g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_4, (void*)0}, {&g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_10, &g_4, &g_4, (void*)0}};
        int i, j;
        step_hash(6);
        l_11 = g_4;
    }
    step_hash(777);
    return g_553;
}
static int * func_12(int * p_13)
{
    int *l_726 = &g_595;
    int l_746 = 0xA44568A6L;
    int l_763 = (-7L);
    int ***l_785 = &g_116;
    short l_849 = (-1L);
    int l_860 = 0x71C6DF36L;
    int l_862 = 6L;
    int l_863 = (-1L);
    int l_864 = 0xEDD4CC1EL;
    int l_865 = 0x0E7FE351L;
    int l_867 = 0x27CCD9D0L;
    int l_868 = (-7L);
    int l_870 = 5L;
    int l_871 = 0x3A3C2269L;
    int l_872 = (-7L);
    int l_873 = (-1L);
    int l_874[4][9] = {{0xB5943D5CL, 0xBF27DE18L, 0xB5943D5CL, 0x5BCC74E1L, (-4L), (-2L), 0xFA3FCE69L, 0xFA3FCE69L, (-2L)}, {0xB5943D5CL, 0xBF27DE18L, 0xB5943D5CL, 0x5BCC74E1L, (-4L), (-2L), 0xFA3FCE69L, 0xFA3FCE69L, (-2L)}, {0xB5943D5CL, 0xBF27DE18L, 0xB5943D5CL, 0x5BCC74E1L, (-4L), (-2L), 0xFA3FCE69L, 0xFA3FCE69L, (-2L)}, {0xB5943D5CL, 0xBF27DE18L, 0xB5943D5CL, 0x5BCC74E1L, (-4L), (-2L), 0xFA3FCE69L, 0xFA3FCE69L, (-2L)}};
    int l_878[6][10] = {{0L, (-1L), 0x2A6FEC0EL, (-1L), 0L, 4L, 0L, (-1L), 0x2A6FEC0EL, (-1L)}, {0L, (-1L), 0x2A6FEC0EL, (-1L), 0L, 4L, 0L, (-1L), 0x2A6FEC0EL, (-1L)}, {0L, (-1L), 0x2A6FEC0EL, (-1L), 0L, 4L, 0L, (-1L), 0x2A6FEC0EL, (-1L)}, {0L, (-1L), 0x2A6FEC0EL, (-1L), 0L, 4L, 0L, (-1L), 0x2A6FEC0EL, (-1L)}, {0L, (-1L), 0x2A6FEC0EL, (-1L), 0L, 4L, 0L, (-1L), 0x2A6FEC0EL, (-1L)}, {0L, (-1L), 0x2A6FEC0EL, (-1L), 0L, 4L, 0L, (-1L), 0x2A6FEC0EL, (-1L)}};
    int i, j;
    step_hash(773);
    if (func_33(l_726, g_659))
    {
        int ***l_728 = &g_116;
        int l_761 = (-9L);
        int l_762[9][3];
        int i, j;
        for (i = 0; i < 9; i++)
        {
            for (j = 0; j < 3; j++)
                l_762[i][j] = (-4L);
        }
        step_hash(613);
        (*l_726) = (-(unsigned)(((void*)0 != l_728) ^ ((void*)0 == l_728)));
        step_hash(650);
        for (g_72 = 3; (g_72 >= 0); g_72 -= 1)
        {
            int *l_729 = &g_620;
            step_hash(624);
            for (g_144 = 0; (g_144 <= 3); g_144 += 1)
            {
                int i;
                step_hash(620);
                l_729 = &g_10;
                step_hash(621);
                (**l_728) = func_36(g_499[g_144], p_13, p_13);
                step_hash(622);
                (***l_728) = ((short)((int)(p_13 != (*g_116)) - (int)(***l_728)) << (short)15);
                step_hash(623);
                (*l_726) &= ((***l_728) ^ (~(-(unsigned char)(***l_728))));
            }
            step_hash(647);
            for (g_71 = 3; (g_71 >= 0); g_71 -= 1)
            {
                int i;
                step_hash(628);
                (*l_729) ^= g_499[g_71];
                step_hash(629);
                (**l_728) = &g_595;
                step_hash(641);
                for (g_294 = 0; (g_294 <= 3); g_294 += 1)
                {
                    int l_735 = 0xDEDE5561L;
                    step_hash(639);
                    for (g_592 = 0; (g_592 <= 4); g_592 += 1)
                    {
                        int i, j;
                        step_hash(636);
                        (*g_116) = func_20(g_499[g_72], ((func_33(func_20(g_499[g_72], g_609[(g_294 + 3)][g_71]), (g_609[(g_72 + 4)][(g_71 + 1)] && 9L)) | l_735) == ((signed char)g_609[3][3] << (signed char)5)));
                        step_hash(637);
                        (*l_729) |= (g_611[1] >= l_735);
                        step_hash(638);
                        (**l_728) = func_20((((g_156[0][1] & ((unsigned char)255UL * (unsigned char)((unsigned)((&l_735 != (void*)0) & (*l_729)) + (unsigned)(((g_499[g_71] == (***l_728)) ^ 0xFA2FL) != ((signed char)((unsigned short)(+0xC70CL) << (unsigned short)(***l_728)) >> (signed char)(***l_728)))))) >= 0xB1F132E3L) >= 0x47A48975L), l_746);
                    }
                    step_hash(640);
                    return (*g_116);
                }
                step_hash(646);
                for (g_362 = 0; (g_362 <= 3); g_362 += 1)
                {
                    step_hash(645);
                    return p_13;
                }
            }
            step_hash(648);
            (*l_729) &= (*l_726);
            step_hash(649);
            (**l_728) = g_747[1];
        }
        step_hash(651);
        (*l_726) = ((((int)((0xCA987275L != (((short)(func_33(&l_746, g_538) == ((short)((((g_72 < ((void*)0 != &l_746)) && ((*l_726) <= g_294)) || (*l_726)) != (*l_726)) << (short)1)) << (short)1) & g_156[0][1])) >= 0xC2EAE26FL) / (int)0xD0902EB3L) && 0x225EL) < g_611[4]);
        step_hash(694);
        for (g_362 = 0; (g_362 != 59); g_362++)
        {
            unsigned l_764 = 0xBC973493L;
            int ***l_777 = &g_116;
            int l_803 = 0xD3B2FCC9L;
            int l_804[2];
            int i;
            for (i = 0; i < 2; i++)
                l_804[i] = 1L;
            step_hash(692);
            for (g_416 = 19; (g_416 >= 14); g_416 -= 9)
            {
                int *l_760[4];
                int i;
                for (i = 0; i < 4; i++)
                    l_760[i] = &g_10;
                step_hash(658);
                l_764++;
                step_hash(659);
                l_746 &= (l_764 ^ ((((short)l_764 >> (short)7) >= ((0xDEL == (+g_294)) > ((unsigned char)g_595 >> (unsigned char)(((+g_108) && g_506[0]) && (+g_506[0]))))) >= func_33(p_13, g_128)));
                step_hash(664);
                for (g_587 = 0; (g_587 <= 16); g_587 += 9)
                {
                    step_hash(663);
                    if (l_762[5][0])
                        break;
                }
            }
            step_hash(693);
            (*l_726) = (*l_726);
        }
    }
    else
    {
        int l_815[9][6] = {{(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}, {(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}, {(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}, {(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}, {(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}, {(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}, {(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}, {(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}, {(-1L), 9L, 9L, 0xE7BFC7EEL, 0xE7BFC7EEL, 9L}};
        int **l_822[4];
        unsigned l_839 = 0xEC4B8773L;
        signed char l_866 = 0xA3L;
        int l_877 = 0x4212E3C9L;
        unsigned short l_879[4] = {65533UL, 1UL, 65533UL, 1UL};
        int l_904 = 0x57434979L;
        short l_905 = 1L;
        int l_906 = 0x303B8232L;
        unsigned short l_907[7][8] = {{0x5609L, 0x2C89L, 0xFF4DL, 1UL, 1UL, 0x3D28L, 1UL, 1UL}, {0x5609L, 0x2C89L, 0xFF4DL, 1UL, 1UL, 0x3D28L, 1UL, 1UL}, {0x5609L, 0x2C89L, 0xFF4DL, 1UL, 1UL, 0x3D28L, 1UL, 1UL}, {0x5609L, 0x2C89L, 0xFF4DL, 1UL, 1UL, 0x3D28L, 1UL, 1UL}, {0x5609L, 0x2C89L, 0xFF4DL, 1UL, 1UL, 0x3D28L, 1UL, 1UL}, {0x5609L, 0x2C89L, 0xFF4DL, 1UL, 1UL, 0x3D28L, 1UL, 1UL}, {0x5609L, 0x2C89L, 0xFF4DL, 1UL, 1UL, 0x3D28L, 1UL, 1UL}};
        int i, j;
        for (i = 0; i < 4; i++)
            l_822[i] = &g_117;
        step_hash(696);
        (**l_785) = &l_746;
        step_hash(697);
        (***l_785) = (*g_117);
        step_hash(771);
        if ((*g_117))
        {
            int *l_829 = &g_71;
            step_hash(727);
            if (func_76((**g_116)))
            {
                int *l_825 = (void*)0;
                step_hash(700);
                return l_825;
            }
            else
            {
                signed char l_842 = 0x03L;
                int l_843[9] = {0x2C23884DL, 0x50CB14D8L, 0x2C23884DL, 0x50CB14D8L, 0x2C23884DL, 0x50CB14D8L, 0x2C23884DL, 0x50CB14D8L, 0x2C23884DL};
                int i;
                step_hash(712);
                for (g_343 = (-4); (g_343 <= 20); g_343++)
                {
                    unsigned char l_828[4][6] = {{0x82L, 249UL, 6UL, 249UL, 0x82L, 255UL}, {0x82L, 249UL, 6UL, 249UL, 0x82L, 255UL}, {0x82L, 249UL, 6UL, 249UL, 0x82L, 255UL}, {0x82L, 249UL, 6UL, 249UL, 0x82L, 255UL}};
                    int i, j;
                    step_hash(709);
                    for (g_109 = 0; (g_109 <= 5); g_109 += 1)
                    {
                        step_hash(708);
                        return p_13;
                    }
                    step_hash(710);
                    if (l_828[1][1])
                        continue;
                    step_hash(711);
                    return l_829;
                }
                step_hash(724);
                if ((*l_829))
                {
                    unsigned l_834[2];
                    int i;
                    for (i = 0; i < 2; i++)
                        l_834[i] = 0x8F63ED42L;
                    step_hash(714);
                    (*l_726) &= (((((signed char)(((void*)0 == &g_747[1]) < g_538) << (signed char)g_128) != ((unsigned char)l_834[0] + (unsigned char)l_834[1])) != ((void*)0 != &p_13)) < (&g_116 != &g_116));
                    step_hash(715);
                    (*g_116) = p_13;
                    step_hash(721);
                    for (g_620 = 0; (g_620 != (-27)); g_620--)
                    {
                        step_hash(719);
                        (*l_726) = ((unsigned char)((void*)0 == (*g_116)) << (unsigned char)4);
                        step_hash(720);
                        ++l_839;
                    }
                }
                else
                {
                    step_hash(723);
                    (*l_726) = l_842;
                }
                step_hash(725);
                l_843[3] |= (*l_829);
                step_hash(726);
                l_829 = p_13;
            }
        }
        else
        {
            signed char l_852[1];
            int l_854 = 0x469EB094L;
            int l_856[7] = {0xAC85FBADL, (-9L), 0xAC85FBADL, (-9L), 0xAC85FBADL, (-9L), 0xAC85FBADL};
            int l_875 = 0xA1CA5AB6L;
            int i;
            for (i = 0; i < 1; i++)
                l_852[i] = 1L;
            step_hash(770);
            if (((short)((**l_785) == (*g_116)) * (short)5UL))
            {
                int l_857 = 0x21D58C82L;
                int l_859[9][9] = {{0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}, {0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}, {0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}, {0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}, {0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}, {0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}, {0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}, {0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}, {0L, 1L, 0x8C8A4D12L, 0xA64A33E1L, 0x15027F77L, 0xB833185CL, 6L, 0xD99DEED8L, 0x8C8A4D12L}};
                int l_869 = 2L;
                signed char l_876 = (-1L);
                int ***l_897[8][9] = {{(void*)0, &l_822[0], &l_822[0], &l_822[0], &g_116, (void*)0, (void*)0, &g_116, (void*)0}, {(void*)0, &l_822[0], &l_822[0], &l_822[0], &g_116, (void*)0, (void*)0, &g_116, (void*)0}, {(void*)0, &l_822[0], &l_822[0], &l_822[0], &g_116, (void*)0, (void*)0, &g_116, (void*)0}, {(void*)0, &l_822[0], &l_822[0], &l_822[0], &g_116, (void*)0, (void*)0, &g_116, (void*)0}, {(void*)0, &l_822[0], &l_822[0], &l_822[0], &g_116, (void*)0, (void*)0, &g_116, (void*)0}, {(void*)0, &l_822[0], &l_822[0], &l_822[0], &g_116, (void*)0, (void*)0, &g_116, (void*)0}, {(void*)0, &l_822[0], &l_822[0], &l_822[0], &g_116, (void*)0, (void*)0, &g_116, (void*)0}, {(void*)0, &l_822[0], &l_822[0], &l_822[0], &g_116, (void*)0, (void*)0, &g_116, (void*)0}};
                unsigned short l_899 = 0xFFB9L;
                int i, j;
                step_hash(736);
                for (g_362 = 0; (g_362 != 32); g_362 += 8)
                {
                    short l_848 = (-5L);
                    step_hash(733);
                    (***l_785) = l_848;
                    step_hash(734);
                    (*g_117) = (!0xF2474093L);
                    step_hash(735);
                    (***l_785) ^= ((*g_116) != p_13);
                }
                step_hash(737);
                (*g_117) |= (~l_849);
                step_hash(758);
                for (g_108 = 9; (g_108 != 20); g_108 += 1)
                {
                    int l_853 = 1L;
                    int l_855 = (-1L);
                    int l_858 = 0xF9425689L;
                    int l_861[6] = {0xFA0D5660L, 0xFA0D5660L, 0x5273E52DL, 0xFA0D5660L, 0xFA0D5660L, 0x5273E52DL};
                    int ***l_898 = (void*)0;
                    int i;
                    step_hash(741);
                    l_879[1]++;
                    step_hash(751);
                    if ((0x8DD5L | l_875))
                    {
                        int l_888 = 0xC0293B56L;
                        step_hash(743);
                        (***l_785) ^= (((unsigned char)(((unsigned short)l_856[4] << (unsigned short)9) & (0x3BBDA1CDL ^ ((5L <= (*l_726)) || g_538))) / (unsigned char)((unsigned short)65535UL + (unsigned short)func_33(p_13, l_888))) || l_875);
                        step_hash(744);
                        p_13 = (void*)0;
                        step_hash(745);
                        if (l_875)
                            break;
                    }
                    else
                    {
                        step_hash(747);
                        (*g_117) = ((unsigned char)((signed char)(0xEBL < ((void*)0 != p_13)) >> (signed char)g_345) << (unsigned char)4);
                        step_hash(748);
                        if (l_859[1][5])
                            break;
                        step_hash(749);
                        p_13 = func_36(((0x90DCA07CL <= l_854) >= ((unsigned char)((short)func_33(func_36((**g_116), func_20(l_861[5], ((0xD6L < func_33(p_13, (((***l_785) && (l_897[6][0] == l_898)) | (***l_785)))) && 0x6DL)), (*g_116)), g_499[1]) >> (short)5) + (unsigned char)l_856[3])), (*g_116), p_13);
                        step_hash(750);
                        (*l_726) = (-1L);
                    }
                    step_hash(757);
                    for (g_144 = 0; (g_144 <= 3); g_144 += 1)
                    {
                        int i;
                        step_hash(755);
                        l_899--;
                        step_hash(756);
                        (**g_116) ^= l_879[g_144];
                    }
                }
            }
            else
            {
                step_hash(764);
                for (g_362 = 1; (g_362 > 47); g_362 += 8)
                {
                    step_hash(763);
                    return p_13;
                }
                step_hash(769);
                for (l_877 = 0; (l_877 <= 4); l_877 += 1)
                {
                    step_hash(768);
                    return p_13;
                }
            }
        }
        step_hash(772);
        l_907[5][7]--;
    }
    step_hash(774);
    return p_13;
}
static int * func_14(int * p_15, signed char p_16, int * p_17, int p_18, short p_19)
{
    unsigned l_708 = 1UL;
    int *l_709[8][8] = {{&g_595, &g_620, &g_71, &g_4, &g_71, &g_620, &g_595, &g_72}, {&g_595, &g_620, &g_71, &g_4, &g_71, &g_620, &g_595, &g_72}, {&g_595, &g_620, &g_71, &g_4, &g_71, &g_620, &g_595, &g_72}, {&g_595, &g_620, &g_71, &g_4, &g_71, &g_620, &g_595, &g_72}, {&g_595, &g_620, &g_71, &g_4, &g_71, &g_620, &g_595, &g_72}, {&g_595, &g_620, &g_71, &g_4, &g_71, &g_620, &g_595, &g_72}, {&g_595, &g_620, &g_71, &g_4, &g_71, &g_620, &g_595, &g_72}, {&g_595, &g_620, &g_71, &g_4, &g_71, &g_620, &g_595, &g_72}};
    unsigned l_724 = 4294967295UL;
    unsigned short l_725 = 0xDCF5L;
    int i, j;
    step_hash(608);
    for (g_294 = 0; (g_294 > 2); g_294 += 5)
    {
        int l_707 = (-1L);
        step_hash(604);
        (*g_117) = ((signed char)0L << (signed char)0);
        step_hash(605);
        (*p_17) = (p_19 != (0xECE2L | func_61(g_346[0], g_611[3], ((+(p_16 >= (-(unsigned char)((signed char)(((unsigned short)0xDBE0L >> (unsigned short)(p_16 ^ func_48(((unsigned)((int)((unsigned short)g_193 << (unsigned short)0) + (int)(((((unsigned char)((short)l_707 * (short)l_708) << (unsigned char)6) != l_708) >= p_19) <= l_708)) - (unsigned)p_18), g_609[3][3], p_16, p_16))) | l_707) * (signed char)g_610)))) <= (*p_17)), p_19)));
        step_hash(606);
        if ((*p_15))
            break;
        step_hash(607);
        return l_709[6][3];
    }
    step_hash(609);
    (*p_17) = ((unsigned char)(g_173[4][0] & 65532UL) - (unsigned char)((unsigned short)((short)(((3L >= ((unsigned short)(l_709[6][3] != (void*)0) - (unsigned short)((unsigned short)(((g_193 <= (p_19 > ((signed char)g_156[3][0] << (signed char)(((((short)p_18 / (short)p_16) < g_193) && 0x86L) <= l_724)))) != l_725) > (*p_17)) >> (unsigned short)g_622))) == (*p_15)) || 0x167D15C9L) / (short)g_345) * (unsigned short)0L));
    step_hash(610);
    return l_709[3][6];
}
static int * func_20(short p_21, unsigned p_22)
{
    unsigned short l_53 = 65531UL;
    int *l_54[1];
    int i;
    for (i = 0; i < 1; i++)
        l_54[i] = &g_4;
    step_hash(598);
    for (g_10 = (-5); (g_10 <= 11); g_10 += 1)
    {
        int *l_56 = (void*)0;
        int l_665 = (-1L);
        short l_675[8][5] = {{0xD173L, 0xFD06L, 0xC6D8L, 1L, 0x8B7CL}, {0xD173L, 0xFD06L, 0xC6D8L, 1L, 0x8B7CL}, {0xD173L, 0xFD06L, 0xC6D8L, 1L, 0x8B7CL}, {0xD173L, 0xFD06L, 0xC6D8L, 1L, 0x8B7CL}, {0xD173L, 0xFD06L, 0xC6D8L, 1L, 0x8B7CL}, {0xD173L, 0xFD06L, 0xC6D8L, 1L, 0x8B7CL}, {0xD173L, 0xFD06L, 0xC6D8L, 1L, 0x8B7CL}, {0xD173L, 0xFD06L, 0xC6D8L, 1L, 0x8B7CL}};
        unsigned l_683 = 1UL;
        int i, j;
        step_hash(11);
        if (p_22)
            break;
        step_hash(596);
        for (p_22 = 22; (p_22 > 44); p_22++)
        {
            unsigned char l_644[3][4] = {{0xBFL, 255UL, 0xBFL, 255UL}, {0xBFL, 255UL, 0xBFL, 255UL}, {0xBFL, 255UL, 0xBFL, 255UL}};
            int *l_652 = &g_595;
            int l_657[8] = {0x6179EC45L, 6L, 0x6179EC45L, 6L, 0x6179EC45L, 6L, 0x6179EC45L, 6L};
            int i, j;
            step_hash(595);
            for (p_21 = 0; (p_21 > (-22)); --p_21)
            {
                int *l_55 = (void*)0;
                int *l_651[1][5];
                int i, j;
                for (i = 0; i < 1; i++)
                {
                    for (j = 0; j < 5; j++)
                        l_651[i][j] = (void*)0;
                }
            }
        }
        step_hash(597);
        return l_54[0];
    }
    step_hash(599);
    return (*g_116);
}







static int func_33(int * p_34, unsigned p_35)
{
    signed char l_646[7][5] = {{6L, 0xF7L, 6L, 0x4CL, (-5L)}, {6L, 0xF7L, 6L, 0x4CL, (-5L)}, {6L, 0xF7L, 6L, 0x4CL, (-5L)}, {6L, 0xF7L, 6L, 0x4CL, (-5L)}, {6L, 0xF7L, 6L, 0x4CL, (-5L)}, {6L, 0xF7L, 6L, 0x4CL, (-5L)}, {6L, 0xF7L, 6L, 0x4CL, (-5L)}};
    int i, j;
    step_hash(571);
    return l_646[4][1];
}







static int * func_36(int p_37, int * p_38, int * p_39)
{
    int *l_645 = &g_620;
    step_hash(568);
    (*l_645) = 0L;
    step_hash(569);
    return l_645;
}







static int func_48(unsigned short p_49, signed char p_50, unsigned char p_51, unsigned p_52)
{
    unsigned char l_593 = 255UL;
    int l_598 = 9L;
    int l_606 = 0x06D756E5L;
    int l_607[8][4] = {{0xEB2C1E0DL, 0L, 0xEB2C1E0DL, 0L}, {0xEB2C1E0DL, 0L, 0xEB2C1E0DL, 0L}, {0xEB2C1E0DL, 0L, 0xEB2C1E0DL, 0L}, {0xEB2C1E0DL, 0L, 0xEB2C1E0DL, 0L}, {0xEB2C1E0DL, 0L, 0xEB2C1E0DL, 0L}, {0xEB2C1E0DL, 0L, 0xEB2C1E0DL, 0L}, {0xEB2C1E0DL, 0L, 0xEB2C1E0DL, 0L}, {0xEB2C1E0DL, 0L, 0xEB2C1E0DL, 0L}};
    short l_608 = 0x5FC8L;
    int **l_631 = (void*)0;
    int **l_632 = (void*)0;
    unsigned char l_640 = 246UL;
    unsigned l_641[4] = {0x4611CCAFL, 8UL, 0x4611CCAFL, 8UL};
    unsigned short l_642 = 0x7F10L;
    int *l_643 = &l_598;
    int i, j;
    step_hash(548);
    for (p_50 = 0; (p_50 == 29); p_50++)
    {
        int l_596[9] = {0xA590D8F6L, 0x5F5DB6E9L, 0xA590D8F6L, 0x5F5DB6E9L, 0xA590D8F6L, 0x5F5DB6E9L, 0xA590D8F6L, 0x5F5DB6E9L, 0xA590D8F6L};
        int i;
        step_hash(546);
        for (p_51 = 0; (p_51 >= 41); ++p_51)
        {
            unsigned l_450 = 0x5C1075D9L;
            int *l_594 = &g_595;
            int *l_597 = &g_72;
            int *l_599 = &l_596[3];
            int *l_600 = &l_598;
            int *l_601 = (void*)0;
            int *l_602 = &l_596[2];
            int *l_603 = &l_598;
            int *l_604 = &l_598;
            int *l_605[2];
            int i;
            for (i = 0; i < 2; i++)
                l_605[i] = &g_595;
        }
        step_hash(547);
        (*g_116) = &l_606;
    }
    step_hash(564);
    for (g_379 = 0; (g_379 <= 3); g_379 += 1)
    {
        signed char l_617 = 0x7EL;
        int l_618 = 0x0B167869L;
        int l_621 = 1L;
        step_hash(557);
        for (g_112 = 0; (g_112 <= 3); g_112 += 1)
        {
            int i, j;
            step_hash(555);
            if (g_156[g_379][(g_379 + 4)])
                break;
            step_hash(556);
            (**g_116) = p_49;
        }
        step_hash(563);
        for (g_193 = 0; (g_193 <= 3); g_193 += 1)
        {
            int *l_614 = &l_598;
            int *l_615 = &l_598;
            int *l_616[2];
            int i;
            for (i = 0; i < 2; i++)
                l_616[i] = &l_607[6][1];
            step_hash(561);
            g_622--;
            step_hash(562);
            return p_51;
        }
    }
    step_hash(565);
    (*l_643) = ((unsigned char)(p_52 ^ l_608) + (unsigned char)((((short)((unsigned short)(l_631 == l_632) / (unsigned short)p_49) << (short)1) ^ (((short)func_61((-(short)0x60CEL), ((int)(((short)((*g_117) != (p_50 >= (l_640 > g_609[3][3]))) >> (short)g_592) | l_606) + (int)0L), l_641[3], g_553) % (short)0xD14DL) & l_642)) & p_50));
    step_hash(566);
    return p_49;
}







static unsigned func_61(short p_62, int p_63, signed char p_64, unsigned p_65)
{
    short l_451[9][6] = {{0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}, {0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}, {0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}, {0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}, {0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}, {0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}, {0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}, {0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}, {0L, 0L, 0xBE0FL, (-5L), 0xD65EL, (-5L)}};
    int *l_452 = &g_10;
    int l_483 = 0x1E058DDEL;
    unsigned l_496 = 4294967295UL;
    int *l_527 = &l_483;
    unsigned l_532[3][10] = {{1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL}, {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL}, {1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL, 1UL}};
    int l_537 = 0x033ADC80L;
    unsigned l_578[8][3] = {{0xAAFEFFE6L, 0x9C91C8CCL, 4294967286UL}, {0xAAFEFFE6L, 0x9C91C8CCL, 4294967286UL}, {0xAAFEFFE6L, 0x9C91C8CCL, 4294967286UL}, {0xAAFEFFE6L, 0x9C91C8CCL, 4294967286UL}, {0xAAFEFFE6L, 0x9C91C8CCL, 4294967286UL}, {0xAAFEFFE6L, 0x9C91C8CCL, 4294967286UL}, {0xAAFEFFE6L, 0x9C91C8CCL, 4294967286UL}, {0xAAFEFFE6L, 0x9C91C8CCL, 4294967286UL}};
    int l_586 = 0x3E888837L;
    int l_588 = 0xF1AD761CL;
    int i, j;
    step_hash(412);
    l_451[4][4] = g_294;
    step_hash(532);
    for (g_71 = 0; (g_71 <= 1); g_71 += 1)
    {
        unsigned char l_476 = 8UL;
        int *l_489 = &g_72;
        unsigned short l_507 = 65535UL;
        unsigned l_525 = 4294967289UL;
        unsigned l_568 = 0UL;
        step_hash(416);
        (*g_116) = l_452;
        step_hash(460);
        for (g_379 = 0; (g_379 <= 5); g_379 += 1)
        {
            unsigned l_459[7] = {0x1416C7F9L, 1UL, 0x1416C7F9L, 1UL, 0x1416C7F9L, 1UL, 0x1416C7F9L};
            int **l_473 = &g_117;
            int l_481[6][7] = {{0x0F6A6855L, 0xF8CCFB3AL, 0xB57B5FCCL, 0xCF78BDAAL, 0x7008C40EL, 0xCF78BDAAL, 0xB57B5FCCL}, {0x0F6A6855L, 0xF8CCFB3AL, 0xB57B5FCCL, 0xCF78BDAAL, 0x7008C40EL, 0xCF78BDAAL, 0xB57B5FCCL}, {0x0F6A6855L, 0xF8CCFB3AL, 0xB57B5FCCL, 0xCF78BDAAL, 0x7008C40EL, 0xCF78BDAAL, 0xB57B5FCCL}, {0x0F6A6855L, 0xF8CCFB3AL, 0xB57B5FCCL, 0xCF78BDAAL, 0x7008C40EL, 0xCF78BDAAL, 0xB57B5FCCL}, {0x0F6A6855L, 0xF8CCFB3AL, 0xB57B5FCCL, 0xCF78BDAAL, 0x7008C40EL, 0xCF78BDAAL, 0xB57B5FCCL}, {0x0F6A6855L, 0xF8CCFB3AL, 0xB57B5FCCL, 0xCF78BDAAL, 0x7008C40EL, 0xCF78BDAAL, 0xB57B5FCCL}};
            int i, j;
            step_hash(457);
            for (g_108 = 1; (g_108 >= 0); g_108 -= 1)
            {
                int l_480 = 2L;
                int i, j;
            }
            step_hash(458);
            (*l_489) ^= p_65;
            step_hash(459);
            g_495 ^= (*l_489);
        }
    }
    step_hash(540);
    if ((*l_527))
    {
        step_hash(534);
        (*l_527) |= p_63;
    }
    else
    {
        int l_579 = (-1L);
        int *l_580 = &l_483;
        int *l_581 = &l_483;
        int *l_582 = (void*)0;
        int l_583[8] = {3L, 0x710BFD9DL, 3L, 0x710BFD9DL, 3L, 0x710BFD9DL, 3L, 0x710BFD9DL};
        int *l_584 = &g_72;
        int *l_585[10][1] = {{(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}, {(void*)0}};
        int i, j;
        step_hash(536);
        --g_589;
        step_hash(537);
        (*g_116) = (void*)0;
        step_hash(538);
        (*l_527) |= g_592;
        step_hash(539);
        return p_65;
    }
    step_hash(541);
    return g_193;
}







static unsigned func_68(int * p_69)
{
    unsigned l_70[9];
    int i;
    for (i = 0; i < 9; i++)
        l_70[i] = 3UL;
    step_hash(409);
    for (g_71 = 3; (g_71 <= 8); g_71 += 1)
    {
        unsigned char l_73 = 254UL;
        int *l_444[7];
        int i;
        for (i = 0; i < 7; i++)
            l_444[i] = &g_72;
        step_hash(33);
        for (g_72 = 3; (g_72 <= 8); g_72 += 1)
        {
            int i;
            step_hash(32);
            return l_70[g_72];
        }
        step_hash(407);
        g_445 = (l_73 ^ ((unsigned char)func_76(l_70[5]) * (unsigned char)((unsigned short)(l_70[8] | (*p_69)) << (unsigned short)11)));
        step_hash(408);
        return l_70[1];
    }
    step_hash(410);
    return g_177;
}







static unsigned char func_76(int p_77)
{
    int *l_81 = &g_72;
    int l_110 = 0x61642E2BL;
    int l_111[2];
    unsigned l_187 = 0xB4418FC0L;
    int **l_239 = &g_117;
    int l_309 = 0x6E31292AL;
    int l_324 = 0x8A42E7EDL;
    int i;
    for (i = 0; i < 2; i++)
        l_111[i] = 0xB33B2D97L;
    step_hash(210);
    if (p_77)
    {
        unsigned l_95 = 4294967295UL;
        int l_126[7][10] = {{1L, 1L, 0L, 0xB73F452BL, 1L, 0xDE28BE02L, 0x4A4F5E2AL, 0xDE28BE02L, 1L, 0xB73F452BL}, {1L, 1L, 0L, 0xB73F452BL, 1L, 0xDE28BE02L, 0x4A4F5E2AL, 0xDE28BE02L, 1L, 0xB73F452BL}, {1L, 1L, 0L, 0xB73F452BL, 1L, 0xDE28BE02L, 0x4A4F5E2AL, 0xDE28BE02L, 1L, 0xB73F452BL}, {1L, 1L, 0L, 0xB73F452BL, 1L, 0xDE28BE02L, 0x4A4F5E2AL, 0xDE28BE02L, 1L, 0xB73F452BL}, {1L, 1L, 0L, 0xB73F452BL, 1L, 0xDE28BE02L, 0x4A4F5E2AL, 0xDE28BE02L, 1L, 0xB73F452BL}, {1L, 1L, 0L, 0xB73F452BL, 1L, 0xDE28BE02L, 0x4A4F5E2AL, 0xDE28BE02L, 1L, 0xB73F452BL}, {1L, 1L, 0L, 0xB73F452BL, 1L, 0xDE28BE02L, 0x4A4F5E2AL, 0xDE28BE02L, 1L, 0xB73F452BL}};
        int i, j;
        step_hash(88);
        if (g_72)
        {
            signed char l_78 = 0xA4L;
            unsigned char l_102[7] = {0xBCL, 255UL, 0xBCL, 255UL, 0xBCL, 255UL, 0xBCL};
            int l_105 = 0x35008519L;
            int l_107 = (-1L);
            int **l_120 = &g_117;
            int i;
            step_hash(70);
            if (l_78)
            {
                int *l_80 = &g_4;
                int **l_79[9] = {&l_80, (void*)0, &l_80, (void*)0, &l_80, (void*)0, &l_80, (void*)0, &l_80};
                int i;
                step_hash(38);
                l_81 = (void*)0;
                step_hash(54);
                for (p_77 = 29; (p_77 > (-5)); --p_77)
                {
                    unsigned l_94 = 0UL;
                    int *l_101 = &g_71;
                    int l_106 = 0x6471EDBFL;
                    short l_125[8][8] = {{(-7L), 9L, 0x2933L, 0x8A64L, 0x2933L, 9L, (-7L), (-3L)}, {(-7L), 9L, 0x2933L, 0x8A64L, 0x2933L, 9L, (-7L), (-3L)}, {(-7L), 9L, 0x2933L, 0x8A64L, 0x2933L, 9L, (-7L), (-3L)}, {(-7L), 9L, 0x2933L, 0x8A64L, 0x2933L, 9L, (-7L), (-3L)}, {(-7L), 9L, 0x2933L, 0x8A64L, 0x2933L, 9L, (-7L), (-3L)}, {(-7L), 9L, 0x2933L, 0x8A64L, 0x2933L, 9L, (-7L), (-3L)}, {(-7L), 9L, 0x2933L, 0x8A64L, 0x2933L, 9L, (-7L), (-3L)}, {(-7L), 9L, 0x2933L, 0x8A64L, 0x2933L, 9L, (-7L), (-3L)}};
                    int i, j;
                    step_hash(42);
                    l_95 = ((int)p_77 / (int)((unsigned short)l_78 / (unsigned short)(((signed char)(+((short)((p_77 < (0x4F4D1268L | (g_71 < g_71))) <= g_71) * (short)(((((short)l_78 << (short)l_94) < l_94) & 251UL) || (-3L)))) - (signed char)l_78) && g_4)));
                    step_hash(43);
                    l_102[2] |= (((unsigned short)l_95 - (unsigned short)(-(signed char)((((unsigned short)p_77 - (unsigned short)p_77) && ((l_101 == &g_10) >= ((~l_95) < (&g_72 != &p_77)))) != ((g_72 == g_71) & g_4)))) & p_77);
                    step_hash(53);
                    if (((signed char)3L << (signed char)5))
                    {
                        unsigned l_115 = 0x81172E91L;
                        step_hash(45);
                        ++g_112;
                        step_hash(46);
                        l_115 ^= (g_4 & (&l_81 != (void*)0));
                        step_hash(47);
                        return p_77;
                    }
                    else
                    {
                        int ***l_118 = (void*)0;
                        int ***l_119 = (void*)0;
                        step_hash(49);
                        l_120 = g_116;
                        step_hash(50);
                        l_110 &= (p_77 && (((signed char)l_95 << (signed char)6) > p_77));
                        step_hash(51);
                        l_125[5][4] &= (p_77 == ((unsigned short)(l_118 != l_119) << (unsigned short)p_77));
                        step_hash(52);
                        l_105 |= (*g_117);
                    }
                }
                step_hash(65);
                if ((g_112 || p_77))
                {
                    step_hash(56);
                    (*l_120) = (*g_116);
                }
                else
                {
                    int *l_127 = (void*)0;
                    step_hash(63);
                    for (g_108 = 2; (g_108 <= 8); g_108 += 1)
                    {
                        step_hash(61);
                        l_126[6][2] = (**l_120);
                        step_hash(62);
                        l_81 = l_127;
                    }
                    step_hash(64);
                    ++g_128;
                }
                step_hash(66);
                for (l_78 = 0; l_78 < 7; l_78 += 1)
                {
                    l_102[l_78] = 0x66L;
                }
            }
            else
            {
                int *l_131 = &l_111[0];
                int *l_132 = &l_111[0];
                int *l_133 = (void*)0;
                int *l_134 = &l_111[0];
                int *l_135 = &l_126[6][2];
                int *l_136 = &l_111[0];
                int *l_137 = (void*)0;
                int *l_138 = &l_126[3][6];
                int *l_139 = (void*)0;
                int *l_140 = &l_110;
                int *l_141 = &l_107;
                int *l_142 = &l_105;
                int *l_143[8] = {&l_111[0], &l_111[0], &g_72, &l_111[0], &l_111[0], &g_72, &l_111[0], &l_111[0]};
                int i;
                step_hash(68);
                (*g_116) = l_131;
                step_hash(69);
                g_144--;
            }
            step_hash(71);
            (*l_120) = (*g_116);
            step_hash(72);
            return l_111[0];
        }
        else
        {
            unsigned short l_147 = 1UL;
            step_hash(74);
            (*g_116) = (*g_116);
            step_hash(86);
            if (l_147)
            {
                int *l_150 = (void*)0;
                int l_151 = 6L;
                int *l_152 = &l_151;
                int *l_153 = &l_110;
                int *l_154[9][5] = {{(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}, {(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}, {(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}, {(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}, {(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}, {(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}, {(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}, {(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}, {(void*)0, &l_126[6][6], &g_4, &l_126[6][2], &l_126[6][6]}};
                int i, j;
                step_hash(80);
                for (l_110 = (-19); (l_110 <= 15); l_110 += 3)
                {
                    step_hash(79);
                    return l_126[6][2];
                }
                step_hash(81);
                (*g_116) = (*g_116);
                step_hash(82);
                --g_156[0][1];
                step_hash(83);
                (*l_152) = ((1UL != ((signed char)(l_147 == l_147) * (signed char)(+p_77))) | p_77);
            }
            else
            {
                step_hash(85);
                (*g_116) = (void*)0;
            }
            step_hash(87);
            return p_77;
        }
    }
    else
    {
        unsigned char l_164[8][4] = {{0UL, 248UL, 0x9DL, 0UL}, {0UL, 248UL, 0x9DL, 0UL}, {0UL, 248UL, 0x9DL, 0UL}, {0UL, 248UL, 0x9DL, 0UL}, {0UL, 248UL, 0x9DL, 0UL}, {0UL, 248UL, 0x9DL, 0UL}, {0UL, 248UL, 0x9DL, 0UL}, {0UL, 248UL, 0x9DL, 0UL}};
        int l_174 = 0x8C6D9029L;
        int l_176[9][7] = {{0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}, {0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}, {0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}, {0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}, {0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}, {0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}, {0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}, {0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}, {0x3766640BL, 0x72261EF3L, 0x3766640BL, 0x04F40C7BL, 1L, (-5L), 1L}};
        int i, j;
        step_hash(176);
        if (((0x5C7AE313L | 6UL) <= g_156[0][1]))
        {
            unsigned char l_168[6];
            int l_175 = 0xC2DF66EBL;
            int i;
            for (i = 0; i < 6; i++)
                l_168[i] = 1UL;
            step_hash(122);
            if ((1UL != 0UL))
            {
                int *l_161 = &l_111[1];
                int *l_162 = &l_111[1];
                int *l_163[8][1] = {{&l_111[0]}, {&l_111[0]}, {&l_111[0]}, {&l_111[0]}, {&l_111[0]}, {&l_111[0]}, {&l_111[0]}, {&l_111[0]}};
                int i, j;
                step_hash(92);
                l_164[1][2]++;
                step_hash(93);
                (*l_81) = l_164[1][2];
                step_hash(98);
                for (g_72 = 0; (g_72 >= 0); g_72 -= 1)
                {
                    step_hash(97);
                    return l_164[1][3];
                }
            }
            else
            {
                step_hash(115);
                for (g_112 = 0; (g_112 <= 1); g_112 += 1)
                {
                    step_hash(107);
                    for (l_110 = 3; (l_110 >= 0); l_110 -= 1)
                    {
                        step_hash(106);
                        (*g_116) = &p_77;
                    }
                    step_hash(108);
                    if ((*g_117))
                        break;
                    step_hash(114);
                    for (g_108 = 0; (g_108 <= 1); g_108 += 1)
                    {
                        int i, j;
                        step_hash(112);
                        (*g_116) = &p_77;
                        step_hash(113);
                        l_111[g_112] &= ((g_156[(g_108 + 2)][(g_108 + 7)] != (-1L)) && (0xDEC6L | g_156[0][1]));
                    }
                }
                step_hash(120);
                if ((*l_81))
                {
                    int *l_167[2][4];
                    int i, j;
                    for (i = 0; i < 2; i++)
                    {
                        for (j = 0; j < 4; j++)
                            l_167[i][j] = (void*)0;
                    }
                    step_hash(117);
                    (*g_116) = l_167[0][2];
                }
                else
                {
                    step_hash(119);
                    (*l_81) |= (*g_117);
                }
                step_hash(121);
                (*g_116) = &p_77;
            }
            step_hash(129);
            if ((p_77 && (*g_117)))
            {
                step_hash(124);
                l_168[2] &= (*l_81);
            }
            else
            {
                int *l_169 = &l_111[0];
                int *l_170 = &l_111[0];
                int *l_171 = &l_111[1];
                int *l_172[2];
                int i;
                for (i = 0; i < 2; i++)
                    l_172[i] = &l_111[0];
                step_hash(126);
                g_177--;
                step_hash(127);
                (*l_81) = ((unsigned char)g_156[0][1] >> (unsigned char)1);
                step_hash(128);
                (*l_81) |= (**g_116);
            }
            step_hash(130);
            l_174 &= p_77;
        }
        else
        {
            int *l_186 = &l_111[0];
            int *l_200 = &l_110;
            int l_209 = (-1L);
            step_hash(132);
            (*l_81) = ((signed char)((signed char)p_77 - (signed char)((*g_116) == l_186)) - (signed char)l_187);
            step_hash(175);
            if (((l_164[1][2] >= g_173[6][1]) > 0x8CL))
            {
                int *l_190 = &g_72;
                int *l_191[6] = {&l_176[4][0], &l_111[0], &l_176[4][0], &l_111[0], &l_176[4][0], &l_111[0]};
                int i;
                step_hash(138);
                for (g_109 = 0; (g_109 <= 8); g_109++)
                {
                    step_hash(137);
                    return p_77;
                }
                step_hash(139);
                --g_193;
                step_hash(150);
                if (p_77)
                {
                    step_hash(141);
                    (*l_190) &= (*l_186);
                }
                else
                {
                    step_hash(148);
                    for (g_144 = 17; (g_144 < 17); g_144 += 3)
                    {
                        step_hash(146);
                        (*l_186) ^= ((signed char)g_72 + (signed char)g_173[7][0]);
                        step_hash(147);
                        l_200 = l_191[1];
                    }
                    step_hash(149);
                    (*l_190) = 0x3F6459BDL;
                }
                step_hash(170);
                for (g_177 = 0; (g_177 != 25); g_177++)
                {
                    unsigned l_210 = 0x1ED7C92EL;
                    step_hash(158);
                    for (g_192 = 14; (g_192 < 16); ++g_192)
                    {
                        int ***l_205 = &g_116;
                        step_hash(157);
                        (*l_190) = (65535UL ^ ((l_205 != (void*)0) ^ 0x7FL));
                    }
                    step_hash(163);
                    if ((l_191[1] == (*g_116)))
                    {
                        step_hash(160);
                        if (p_77)
                            break;
                    }
                    else
                    {
                        step_hash(162);
                        l_200 = &l_176[4][0];
                    }
                    step_hash(168);
                    for (g_155 = 19; (g_155 >= 4); g_155 -= 3)
                    {
                        int l_208[8][4] = {{(-1L), (-1L), 0xD9FB2421L, 0x7C0DB931L}, {(-1L), (-1L), 0xD9FB2421L, 0x7C0DB931L}, {(-1L), (-1L), 0xD9FB2421L, 0x7C0DB931L}, {(-1L), (-1L), 0xD9FB2421L, 0x7C0DB931L}, {(-1L), (-1L), 0xD9FB2421L, 0x7C0DB931L}, {(-1L), (-1L), 0xD9FB2421L, 0x7C0DB931L}, {(-1L), (-1L), 0xD9FB2421L, 0x7C0DB931L}, {(-1L), (-1L), 0xD9FB2421L, 0x7C0DB931L}};
                        int i, j;
                        step_hash(167);
                        return l_208[4][0];
                    }
                    step_hash(169);
                    l_210++;
                }
            }
            else
            {
                int ***l_215 = &g_116;
                step_hash(172);
                (*l_81) |= (((signed char)((void*)0 == &l_81) << (signed char)7) < (g_71 ^ (+0x67L)));
                step_hash(173);
                (*l_81) = (l_215 != (void*)0);
                step_hash(174);
                return p_77;
            }
        }
        step_hash(208);
        for (p_77 = 0; (p_77 <= 3); p_77 += 1)
        {
            unsigned short l_228 = 65530UL;
            int **l_231 = &l_81;
            step_hash(180);
            (*g_116) = (*g_116);
            step_hash(207);
            for (g_177 = 0; (g_177 <= 3); g_177 += 1)
            {
                int *l_216 = &l_111[0];
                int l_225 = (-1L);
                step_hash(184);
                (*g_116) = l_216;
                step_hash(204);
                for (g_109 = 1; (g_109 >= 0); g_109 -= 1)
                {
                    unsigned l_229 = 4UL;
                    int i, j;
                    step_hash(188);
                    (*g_116) = (*g_116);
                    step_hash(189);
                    (*l_81) &= (((unsigned short)((signed char)((unsigned short)((signed char)(2UL | g_156[p_77][(g_177 + 5)]) << (signed char)g_156[0][1]) << (unsigned short)((l_225 > g_144) < (*l_216))) % (signed char)((&g_117 == &l_81) || ((short)p_77 * (short)8L))) * (unsigned short)l_228) < l_229);
                    step_hash(196);
                    for (l_225 = 3; (l_225 >= 0); l_225 -= 1)
                    {
                        int l_230 = 0xB967A072L;
                        int ***l_232 = &l_231;
                        int i, j;
                        step_hash(193);
                        l_111[g_109] ^= g_173[(p_77 + 2)][g_109];
                        step_hash(194);
                        l_111[g_109] ^= ((l_164[0][1] && l_230) >= p_77);
                        step_hash(195);
                        (*l_232) = l_231;
                    }
                    step_hash(203);
                    for (l_229 = 0; (l_229 <= 1); l_229 += 1)
                    {
                        int i;
                        step_hash(200);
                        (*l_81) = (&g_116 != &g_116);
                        step_hash(201);
                        (*l_81) &= ((unsigned short)l_111[g_109] - (unsigned short)(((unsigned short)p_77 << (unsigned short)((((short)(l_239 != &l_216) << (short)4) <= l_111[g_109]) && ((signed char)p_77 << (signed char)((signed char)g_10 << (signed char)3)))) | (-8L)));
                        step_hash(202);
                        (*l_239) = l_216;
                    }
                }
                step_hash(205);
                (**g_116) = (**g_116);
                step_hash(206);
                (*l_81) |= ((unsigned char)(**l_239) - (unsigned char)0x25L);
            }
        }
        step_hash(209);
        (*l_239) = &l_176[4][0];
    }
    step_hash(404);
    if ((((signed char)(&g_71 == (void*)0) * (signed char)((1L | g_109) && ((*l_81) <= p_77))) < p_77))
    {
        signed char l_251 = 0xE0L;
        int l_266 = 0x03686385L;
        step_hash(268);
        for (g_193 = 0; (g_193 <= 1); g_193 += 1)
        {
            int ***l_263 = &l_239;
            int l_298 = (-5L);
            step_hash(255);
            for (l_187 = 0; (l_187 <= 1); l_187 += 1)
            {
                int ***l_252 = &l_239;
                int l_280 = 1L;
                int i, j;
                step_hash(241);
                if (((unsigned)(-(short)g_173[(g_193 + 7)][g_193]) / (unsigned)p_77))
                {
                    step_hash(219);
                    if (l_251)
                        break;
                    step_hash(224);
                    for (g_192 = 0; (g_192 <= 3); g_192 += 1)
                    {
                        int i, j;
                        step_hash(223);
                        (*l_81) = (g_156[g_192][(g_192 + 5)] ^ g_173[(g_192 + 1)][l_187]);
                    }
                }
                else
                {
                    unsigned short l_260 = 65535UL;
                    int **l_269 = (void*)0;
                    step_hash(232);
                    if ((&g_116 != l_252))
                    {
                        step_hash(227);
                        return l_251;
                    }
                    else
                    {
                        int *l_253 = &l_111[0];
                        int *l_254 = &l_111[0];
                        int *l_255 = &g_72;
                        int *l_256 = &l_111[0];
                        int *l_257 = &l_111[0];
                        int *l_258 = (void*)0;
                        int *l_259[7][10] = {{(void*)0, &g_10, &l_111[0], &l_110, &g_72, &l_110, &g_72, &l_110, &l_111[0], &g_10}, {(void*)0, &g_10, &l_111[0], &l_110, &g_72, &l_110, &g_72, &l_110, &l_111[0], &g_10}, {(void*)0, &g_10, &l_111[0], &l_110, &g_72, &l_110, &g_72, &l_110, &l_111[0], &g_10}, {(void*)0, &g_10, &l_111[0], &l_110, &g_72, &l_110, &g_72, &l_110, &l_111[0], &g_10}, {(void*)0, &g_10, &l_111[0], &l_110, &g_72, &l_110, &g_72, &l_110, &l_111[0], &g_10}, {(void*)0, &g_10, &l_111[0], &l_110, &g_72, &l_110, &g_72, &l_110, &l_111[0], &g_10}, {(void*)0, &g_10, &l_111[0], &l_110, &g_72, &l_110, &g_72, &l_110, &l_111[0], &g_10}};
                        int i, j;
                        step_hash(229);
                        --l_260;
                        step_hash(230);
                        (*l_257) = ((void*)0 != l_263);
                        step_hash(231);
                        l_266 |= (((signed char)0x44L * (signed char)g_173[6][1]) & g_155);
                    }
                    step_hash(240);
                    if (((unsigned short)(0x96L >= (l_251 > g_177)) - (unsigned short)((void*)0 == l_269)))
                    {
                        step_hash(234);
                        (*l_239) = &g_71;
                        step_hash(235);
                        return p_77;
                    }
                    else
                    {
                        step_hash(237);
                        (**l_252) = &p_77;
                        step_hash(238);
                        (*g_117) = (***l_263);
                        step_hash(239);
                        return p_77;
                    }
                }
                step_hash(254);
                for (l_251 = 1; (l_251 >= 0); l_251 -= 1)
                {
                    int l_293 = 0x350D1A62L;
                    step_hash(253);
                    if (((signed char)(((short)(&g_116 == l_263) << (short)10) || (&p_77 != &p_77)) - (signed char)((g_144 == (((unsigned short)g_173[4][0] + (unsigned short)((int)p_77 / (int)(((void*)0 != &p_77) || g_193))) != l_280)) < p_77)))
                    {
                        int l_281 = 0x1D8A302AL;
                        int *l_282 = &l_111[1];
                        int *l_283 = (void*)0;
                        int *l_284[6][7];
                        int i, j;
                        for (i = 0; i < 6; i++)
                        {
                            for (j = 0; j < 7; j++)
                                l_284[i][j] = &g_72;
                        }
                        step_hash(246);
                        g_285++;
                        step_hash(247);
                        (*l_81) ^= ((g_112 & ((-(int)(((((signed char)p_77 + (signed char)g_177) | (((unsigned)(*l_282) + (unsigned)(g_109 && (((5UL <= ((void*)0 == l_284[5][2])) && p_77) == g_108))) | g_144)) ^ g_10) && 0xD852L)) >= l_266)) >= p_77);
                        step_hash(248);
                        --g_294;
                        step_hash(249);
                        return p_77;
                    }
                    else
                    {
                        unsigned l_297 = 0xB85E74F0L;
                        step_hash(251);
                        l_298 = l_297;
                        step_hash(252);
                        (*l_81) = ((unsigned char)p_77 * (unsigned char)((unsigned short)(+p_77) >> (unsigned short)12));
                    }
                }
            }
            step_hash(260);
            for (g_294 = 0; (g_294 <= 1); g_294 += 1)
            {
                step_hash(259);
                return g_173[7][1];
            }
            step_hash(261);
            p_77 |= l_251;
            step_hash(262);
            if (l_251)
                continue;
            step_hash(267);
            for (g_144 = 0; (g_144 <= 1); g_144 += 1)
            {
                step_hash(266);
                (*l_81) = p_77;
            }
        }
    }
    else
    {
        unsigned char l_310 = 1UL;
        int l_329 = 0xF25A9B19L;
        int ***l_370 = &g_116;
        int l_376 = 0x64786584L;
        int l_378[2][7] = {{0xAB695C8EL, 0xB7B668EEL, 0xDAAFBBF8L, 0xDAAFBBF8L, 0xB7B668EEL, 0xAB695C8EL, 0xB7B668EEL}, {0xAB695C8EL, 0xB7B668EEL, 0xDAAFBBF8L, 0xDAAFBBF8L, 0xB7B668EEL, 0xAB695C8EL, 0xB7B668EEL}};
        unsigned l_410 = 3UL;
        int i, j;
        step_hash(282);
        for (g_112 = 0; (g_112 > 25); g_112 += 1)
        {
            step_hash(281);
            for (g_128 = 0; (g_128 <= 54); g_128 += 7)
            {
                step_hash(280);
                for (g_155 = 1; (g_155 >= 0); g_155 -= 1)
                {
                    step_hash(279);
                    (*l_239) = &p_77;
                }
            }
        }
        step_hash(283);
        (*l_81) |= ((short)(l_309 == 0UL) << (short)12);
        step_hash(403);
        if (l_310)
        {
            short l_321 = 0xFE96L;
            short l_322[8] = {0xCB8CL, 0xCB8CL, 0x1A3AL, 0xCB8CL, 0xCB8CL, 0x1A3AL, 0xCB8CL, 0xCB8CL};
            int l_358 = 0xE0134C85L;
            int i;
            step_hash(291);
            if (((unsigned short)((signed char)((((signed char)((unsigned char)((0L && (g_173[4][0] <= (((p_77 && 0x438DL) < (p_77 | (+g_173[4][0]))) ^ (*l_81)))) >= ((signed char)(0x3F08L >= ((&g_117 != (void*)0) > l_321)) >> (signed char)l_322[0])) - (unsigned char)g_71) * (signed char)0L) != p_77) != g_128) * (signed char)1L) >> (unsigned short)p_77))
            {
                int l_323 = 0xD2656983L;
                step_hash(286);
                (*g_116) = (void*)0;
                step_hash(287);
                (*l_81) &= l_323;
            }
            else
            {
                step_hash(289);
                (*l_81) = l_324;
                step_hash(290);
                return g_155;
            }
            step_hash(308);
            if (p_77)
            {
                unsigned short l_335 = 0x0142L;
                step_hash(303);
                for (g_144 = 0; (g_144 != 16); g_144++)
                {
                    step_hash(296);
                    (*g_116) = &p_77;
                    step_hash(301);
                    for (g_155 = 0; (g_155 >= 25); ++g_155)
                    {
                        int *l_330 = &g_72;
                        int *l_331 = &l_329;
                        int *l_332 = &l_110;
                        int *l_333 = &g_72;
                        int *l_334 = &l_111[0];
                        step_hash(300);
                        --l_335;
                    }
                    step_hash(302);
                    (*l_81) &= (p_77 | 0x3D60B044L);
                }
            }
            else
            {
                int *l_338 = &l_111[0];
                int *l_339 = &l_309;
                int *l_340 = &l_111[0];
                int *l_341 = (void*)0;
                int *l_342 = &l_111[0];
                int *l_344[4][3] = {{&l_329, &l_329, &g_71}, {&l_329, &l_329, &g_71}, {&l_329, &l_329, &g_71}, {&l_329, &l_329, &g_71}};
                int i, j;
                step_hash(305);
                (*l_81) = p_77;
                step_hash(306);
                (*g_116) = &p_77;
                step_hash(307);
                --g_346[5];
            }
            step_hash(331);
            if (l_322[1])
            {
                step_hash(310);
                return g_285;
            }
            else
            {
                unsigned l_351 = 4294967295UL;
                step_hash(312);
                (*l_81) ^= l_310;
                step_hash(325);
                for (g_109 = 28; (g_109 >= 15); g_109 -= 9)
                {
                    step_hash(324);
                    if (p_77)
                    {
                        int *l_354[1][6] = {{(void*)0, (void*)0, (void*)0, (void*)0, (void*)0, (void*)0}};
                        int i, j;
                        step_hash(317);
                        (*l_81) |= (&l_81 == (void*)0);
                        step_hash(318);
                        (*l_239) = (*g_116);
                        step_hash(319);
                        --l_351;
                        step_hash(320);
                        l_354[0][4] = (void*)0;
                    }
                    else
                    {
                        int *l_355 = &l_309;
                        int *l_356 = &l_111[0];
                        int *l_357 = (void*)0;
                        int *l_359 = &l_111[0];
                        int *l_360 = &l_358;
                        int *l_361 = &l_110;
                        step_hash(322);
                        ++g_362;
                        step_hash(323);
                        (*g_116) = (*g_116);
                    }
                }
                step_hash(330);
                for (g_345 = (-2); (g_345 <= (-5)); g_345--)
                {
                    unsigned short l_369 = 65531UL;
                    step_hash(329);
                    l_369 &= (g_345 && ((signed char)(0xB7L < (p_77 > (p_77 ^ g_192))) * (signed char)(!0x99L)));
                }
            }
            step_hash(362);
            for (g_128 = 0; (g_128 <= 7); g_128 += 1)
            {
                unsigned l_373 = 0x9F8442B3L;
                int l_377[9] = {0xAD1BEC33L, 0xAD1BEC33L, (-6L), 0xAD1BEC33L, 0xAD1BEC33L, (-6L), 0xAD1BEC33L, 0xAD1BEC33L, (-6L)};
                int ***l_394[9][2] = {{&l_239, (void*)0}, {&l_239, (void*)0}, {&l_239, (void*)0}, {&l_239, (void*)0}, {&l_239, (void*)0}, {&l_239, (void*)0}, {&l_239, (void*)0}, {&l_239, (void*)0}, {&l_239, (void*)0}};
                int i, j;
                step_hash(335);
                p_77 = (~l_329);
                step_hash(340);
                for (l_324 = 3; (l_324 >= 0); l_324 -= 1)
                {
                    int l_374 = 0x25295300L;
                    int i, j;
                    step_hash(339);
                    l_374 |= ((((void*)0 != l_370) || (((unsigned short)g_156[l_324][g_128] * (unsigned short)l_373) == (p_77 == l_373))) | g_112);
                }
                step_hash(356);
                for (g_112 = 0; (g_112 <= 7); g_112 += 1)
                {
                    int *l_375[8] = {(void*)0, &l_111[0], (void*)0, &l_111[0], (void*)0, &l_111[0], (void*)0, &l_111[0]};
                    int i;
                    step_hash(344);
                    --g_379;
                    step_hash(345);
                    (*g_116) = &p_77;
                    step_hash(346);
                    (***l_370) ^= (l_377[0] == (&g_117 == &l_81));
                    step_hash(355);
                    if (g_382)
                    {
                        step_hash(348);
                        if (p_77)
                            break;
                        step_hash(349);
                        (**l_239) = (-8L);
                    }
                    else
                    {
                        int *l_383 = &l_378[0][1];
                        step_hash(351);
                        (*g_116) = l_383;
                        step_hash(352);
                        (*g_117) = ((int)0x8F5D8F84L - (int)(p_77 ^ l_373));
                        step_hash(353);
                        (**l_370) = &l_358;
                        step_hash(354);
                        (***l_370) = ((((void*)0 != &g_117) != (((signed char)(-1L) >> (signed char)(l_377[0] | (p_77 > ((signed char)(-4L) << (signed char)5)))) && (((unsigned char)((short)((void*)0 == l_394[7][1]) << (short)((unsigned char)((short)((int)(((unsigned short)((unsigned char)(((signed char)(&l_239 != (void*)0) - (signed char)g_382) >= g_193) << (unsigned char)4) + (unsigned short)g_156[0][1]) & g_173[2][1]) / (int)p_77) + (short)0x9B88L) + (unsigned char)0xE3L)) * (unsigned char)(*l_81)) > p_77))) & 0x96L);
                    }
                }
                step_hash(361);
                for (g_285 = 0; (g_285 <= 7); g_285 += 1)
                {
                    int *l_407[6][3] = {{&l_110, &l_110, (void*)0}, {&l_110, &l_110, (void*)0}, {&l_110, &l_110, (void*)0}, {&l_110, &l_110, (void*)0}, {&l_110, &l_110, (void*)0}, {&l_110, &l_110, (void*)0}};
                    int i, j;
                    step_hash(360);
                    (*l_239) = l_407[0][1];
                }
            }
        }
        else
        {
            step_hash(369);
            for (p_77 = (-1); (p_77 == 28); p_77 += 9)
            {
                step_hash(367);
                (*l_239) = &p_77;
                step_hash(368);
                return g_285;
            }
            step_hash(370);
            (*g_116) = &p_77;
            step_hash(402);
            if ((*g_117))
            {
                step_hash(372);
                (*g_117) = l_410;
            }
            else
            {
                int **l_413 = &g_117;
                step_hash(387);
                for (g_144 = 0; (g_144 > 37); g_144 += 3)
                {
                    int l_430 = 9L;
                    int l_431 = (-1L);
                    step_hash(386);
                    if ((&g_117 != l_413))
                    {
                        step_hash(378);
                        if ((*g_117))
                            break;
                        step_hash(379);
                        (**l_370) = (*g_116);
                        step_hash(380);
                        (*g_117) = 1L;
                    }
                    else
                    {
                        short l_414 = (-1L);
                        int *l_415 = &l_378[1][5];
                        step_hash(382);
                        ++g_416;
                        step_hash(383);
                        (*g_117) = ((signed char)((short)(g_155 <= (((unsigned char)(((unsigned short)((((unsigned char)((void*)0 != (*l_370)) >> (unsigned char)0) ^ (((-(unsigned char)0xE4L) < p_77) && p_77)) & p_77) << (unsigned short)9) >= (*g_117)) + (unsigned char)(l_430 == (**l_413))) <= (***l_370))) - (short)0L) - (signed char)g_156[1][8]);
                        step_hash(384);
                        l_431 &= (**g_116);
                        step_hash(385);
                        (***l_370) ^= ((*g_116) != &p_77);
                    }
                }
                step_hash(400);
                for (l_110 = 1; (l_110 >= 0); l_110 -= 1)
                {
                    int i;
                    step_hash(391);
                    if (l_111[l_110])
                        break;
                    step_hash(399);
                    for (g_108 = 1; (g_108 >= 0); g_108 -= 1)
                    {
                        int i, j;
                        step_hash(395);
                        l_378[l_110][(l_110 + 1)] = ((unsigned short)(l_378[g_108][l_110] | l_378[l_110][(l_110 + 4)]) >> (unsigned short)p_77);
                        step_hash(396);
                        (*l_413) = &p_77;
                        step_hash(397);
                        l_111[l_110] = ((l_111[l_110] >= ((unsigned char)p_77 % (unsigned char)p_77)) != p_77);
                        step_hash(398);
                        (*g_117) = (-1L);
                    }
                }
                step_hash(401);
                l_329 |= ((unsigned char)((*l_81) > (65535UL ^ g_346[6])) * (unsigned char)(p_77 < (p_77 | ((unsigned char)(0x1C13L < ((void*)0 != &g_117)) << (unsigned char)(((short)((*l_370) != &g_117) * (short)(***l_370)) != g_109)))));
            }
        }
    }
    step_hash(405);
    (*l_81) = (1L < (0L | 0x22L));
    step_hash(406);
    return g_108;
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_10, "g_10", print_hash_value);
    transparent_crc(g_71, "g_71", print_hash_value);
    transparent_crc(g_72, "g_72", print_hash_value);
    transparent_crc(g_108, "g_108", print_hash_value);
    transparent_crc(g_109, "g_109", print_hash_value);
    transparent_crc(g_112, "g_112", print_hash_value);
    transparent_crc(g_128, "g_128", print_hash_value);
    transparent_crc(g_144, "g_144", print_hash_value);
    transparent_crc(g_155, "g_155", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 9; j++)
        {
            transparent_crc(g_156[i][j], "g_156[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 2; j++)
        {
            transparent_crc(g_173[i][j], "g_173[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_177, "g_177", print_hash_value);
    transparent_crc(g_192, "g_192", print_hash_value);
    transparent_crc(g_193, "g_193", print_hash_value);
    transparent_crc(g_285, "g_285", print_hash_value);
    transparent_crc(g_294, "g_294", print_hash_value);
    transparent_crc(g_343, "g_343", print_hash_value);
    transparent_crc(g_345, "g_345", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_346[i], "g_346[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_362, "g_362", print_hash_value);
    transparent_crc(g_379, "g_379", print_hash_value);
    transparent_crc(g_382, "g_382", print_hash_value);
    transparent_crc(g_416, "g_416", print_hash_value);
    transparent_crc(g_445, "g_445", print_hash_value);
    transparent_crc(g_495, "g_495", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        transparent_crc(g_499[i], "g_499[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_506[i], "g_506[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_538, "g_538", print_hash_value);
    transparent_crc(g_553, "g_553", print_hash_value);
    transparent_crc(g_587, "g_587", print_hash_value);
    transparent_crc(g_589, "g_589", print_hash_value);
    transparent_crc(g_592, "g_592", print_hash_value);
    transparent_crc(g_595, "g_595", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j < 5; j++)
        {
            transparent_crc(g_609[i][j], "g_609[i][j]", print_hash_value);
            if (print_hash_value) printf("index = [%d][%d]\n", i, j);

        }
    }
    transparent_crc(g_610, "g_610", print_hash_value);
    for (i = 0; i < 5; i++)
    {
        transparent_crc(g_611[i], "g_611[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    for (i = 0; i < 8; i++)
    {
        transparent_crc(g_619[i], "g_619[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);

    }
    transparent_crc(g_620, "g_620", print_hash_value);
    transparent_crc(g_622, "g_622", print_hash_value);
    transparent_crc(g_659, "g_659", print_hash_value);
    transparent_crc(g_797, "g_797", print_hash_value);
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
