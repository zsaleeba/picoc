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
static int g_2 = 0xCEA5D6C0L;
static int g_55 = 0x150040B3L;
static unsigned g_58 = 0x0C1731D4L;
static unsigned short g_63 = 0UL;
static int *g_69 = &g_55;
static int **g_68[1][4] = {{&g_69, &g_69, &g_69, &g_69}};
static unsigned char g_233 = 6UL;
static int g_254 = 0xD18BA939L;
static unsigned char g_296 = 0x27L;
static unsigned short g_371 = 0x66BFL;
static unsigned g_390 = 4294967295UL;
static unsigned char g_451 = 0x0FL;
static short g_464 = 0x50C6L;
static int g_523 = 0x979AECACL;
static int *g_536 = &g_2;
static unsigned char g_557 = 0x88L;
static int g_597 = (-1L);
static int *g_735 = (void*)0;
static int **g_742 = &g_735;
static int ***g_741 = &g_742;
static short func_1(void);
static unsigned func_15(int * p_16, int * p_17, int * p_18);
static int * func_19(int * p_20, short p_21);
static int func_23(int p_24, int * p_25, int * p_26, int p_27, int * p_28);
static int * func_30(int * p_31, unsigned p_32, int * p_33, signed char p_34);
static int * func_35(signed char p_36);
static short func_41(int p_42, int * p_43, int * p_44, int * p_45);
static unsigned func_46(int p_47, int * p_48, unsigned p_49, int * p_50, unsigned char p_51);
static int * func_52(signed char p_53);
static int func_81(unsigned p_82, unsigned short p_83);
static short func_1(void)
{
    unsigned char l_5 = 0xE0L;
    int *l_6 = &g_2;
    signed char l_611 = 0x3BL;
    unsigned l_621 = 1UL;
    unsigned char l_627 = 0x7EL;
    int *l_652 = &g_55;
    int l_677 = 0x2DBC67DBL;
    unsigned char l_682[2][6] = {{0x67L, 0xF1L, 0x36L, 0x36L, 0xF1L, 0x67L}, {0x67L, 0xF1L, 0x36L, 0x36L, 0xF1L, 0x67L}};
    signed char l_728 = 0x6DL;
    int i, j;
    step_hash(5);
    for (g_2 = 17; (g_2 <= (-12)); g_2 -= 9)
    {
        step_hash(4);
        if (l_5)
            break;
    }
    step_hash(6);
    (*l_6) = g_2;
    step_hash(7);
    (*l_6) = 0x6F5A9C4CL;
    step_hash(423);
    for (g_2 = 0; (g_2 > (-9)); g_2 -= 3)
    {
        int *l_22 = &g_2;
        int l_612 = 0x83309D80L;
        unsigned char l_624 = 0x9FL;
        unsigned l_658 = 0x24B654D5L;
        int l_675 = 0L;
        int l_679 = 0x90ACB52BL;
    }
    step_hash(424);
    return g_63;
}
static unsigned func_15(int * p_16, int * p_17, int * p_18)
{
    signed char l_598 = 0x27L;
    int *l_599 = (void*)0;
    int *l_600 = &g_523;
    step_hash(319);
    l_600 = l_599;
    step_hash(320);
    return l_598;
}
static int * func_19(int * p_20, short p_21)
{
    int l_29 = (-1L);
    int **l_587[2];
    int *l_595[5] = {&l_29, (void*)0, &l_29, (void*)0, &l_29};
    int l_596 = 0xD7F3CA26L;
    int i;
    for (i = 0; i < 2; i++)
        l_587[i] = &g_69;
    step_hash(315);
    if (func_23(l_29, p_20, &g_2, l_29, func_30(func_35(((short)0xB653L * (short)(((signed char)g_2 + (signed char)l_29) | (0xED1D25BBL | (((func_41(p_21, &l_29, &l_29, &l_29) || 0x2F3AL) < p_21) && l_29))))), l_29, p_20, p_21)))
    {
        unsigned l_588 = 0xE8829AA2L;
        step_hash(312);
        l_588 |= (l_587[1] != (void*)0);
    }
    else
    {
        step_hash(314);
        return p_20;
    }
    step_hash(316);
    g_597 = (!((4294967295UL && (p_21 >= (((signed char)(((((unsigned short)((func_23(p_21, p_20, p_20, p_21, l_595[0]) > l_596) == g_58) >> (unsigned short)p_21) >= p_21) | p_21) ^ p_21) % (signed char)g_254) == g_254))) != g_2));
    step_hash(317);
    return p_20;
}
static int func_23(int p_24, int * p_25, int * p_26, int p_27, int * p_28)
{
    int l_575 = 0x11F8DB44L;
    int *l_576 = &g_55;
    unsigned char l_580[3][3] = {{251UL, 5UL, 251UL}, {251UL, 5UL, 251UL}, {251UL, 5UL, 251UL}};
    int ***l_584[4][7] = {{&g_68[0][1], &g_68[0][2], (void*)0, &g_68[0][2], &g_68[0][1], &g_68[0][2], &g_68[0][1]}, {&g_68[0][1], &g_68[0][2], (void*)0, &g_68[0][2], &g_68[0][1], &g_68[0][2], &g_68[0][1]}, {&g_68[0][1], &g_68[0][2], (void*)0, &g_68[0][2], &g_68[0][1], &g_68[0][2], &g_68[0][1]}, {&g_68[0][1], &g_68[0][2], (void*)0, &g_68[0][2], &g_68[0][1], &g_68[0][2], &g_68[0][1]}};
    int i, j;
    step_hash(301);
    (*l_576) = (l_575 | (*p_25));
    step_hash(308);
    for (g_390 = 0; (g_390 != 2); g_390 += 1)
    {
        int *l_579[8][3] = {{&g_2, &g_55, &g_2}, {&g_2, &g_55, &g_2}, {&g_2, &g_55, &g_2}, {&g_2, &g_55, &g_2}, {&g_2, &g_55, &g_2}, {&g_2, &g_55, &g_2}, {&g_2, &g_55, &g_2}, {&g_2, &g_55, &g_2}};
        signed char l_581 = (-8L);
        int i, j;
        step_hash(305);
        (*l_576) = ((void*)0 != l_579[0][0]);
        step_hash(306);
        (*l_576) = l_580[0][0];
        step_hash(307);
        if (l_581)
            continue;
    }
    step_hash(309);
    p_28 = p_28;
    step_hash(310);
    return (*l_576);
}







static int * func_30(int * p_31, unsigned p_32, int * p_33, signed char p_34)
{
    int **l_266 = (void*)0;
    int l_289[4];
    unsigned short l_333 = 0x57E0L;
    int *l_430[10][5] = {{(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}, {(void*)0, &g_2, &g_55, &g_2, (void*)0}};
    unsigned l_452 = 0xB1D8BA16L;
    int l_486 = (-1L);
    unsigned l_510 = 0xFD554E02L;
    int i, j;
    for (i = 0; i < 4; i++)
        l_289[i] = 1L;
    step_hash(298);
    if ((*p_33))
    {
        int *l_267[1];
        unsigned l_278 = 0x6556C072L;
        int *l_306 = (void*)0;
        int l_457 = 0x218FCF2CL;
        int i;
        for (i = 0; i < 1; i++)
            l_267[i] = &g_2;
        step_hash(173);
        if (((signed char)(+(&g_69 != &g_69)) * (signed char)(((p_34 && ((unsigned char)248UL * (unsigned char)(0xDCL > (&p_31 != l_266)))) != ((*p_33) <= (*p_33))) >= g_58)))
        {
            unsigned l_275[2];
            int l_287 = 0xE435E4F5L;
            int l_288 = 0x1E13063FL;
            int l_352 = 0x6B0EA0F8L;
            int l_354 = (-6L);
            int l_355 = 0xB4221DD1L;
            int l_356 = 0L;
            int l_357 = 0x2D9FF996L;
            int l_358 = (-1L);
            int i;
            for (i = 0; i < 2; i++)
                l_275[i] = 0xE2523DFDL;
            step_hash(121);
            for (g_58 = 17; (g_58 == 26); g_58++)
            {
                unsigned l_272 = 0x4324CCB7L;
                step_hash(120);
                l_272 = (((void*)0 != &g_68[0][1]) != (g_254 ^ (((signed char)p_34 << (signed char)6) < p_32)));
            }
            step_hash(160);
            if ((((unsigned short)l_275[1] - (unsigned short)((unsigned short)(~l_278) - (unsigned short)(((l_275[1] > (((*p_31) & (((unsigned)((*p_31) >= ((&p_31 != &p_31) ^ 0x8844D54AL)) + (unsigned)((int)(((unsigned char)(l_275[1] > 7L) << (unsigned char)0) <= (*p_31)) % (int)(*p_31))) <= (*p_33))) >= g_2)) || 0x2C3C9639L) ^ 0UL))) & 65535UL))
            {
                unsigned l_301 = 0xEE3AD7C6L;
                int l_319[5] = {0L, 0x776AFE39L, 0L, 0x776AFE39L, 0L};
                int i;
                step_hash(143);
                for (g_58 = (-13); (g_58 == 45); ++g_58)
                {
                    unsigned l_293[2][7] = {{0x3C9033E0L, 4294967287UL, 4294967295UL, 4294967295UL, 4294967287UL, 0x3C9033E0L, 4294967287UL}, {0x3C9033E0L, 4294967287UL, 4294967295UL, 4294967295UL, 4294967287UL, 0x3C9033E0L, 4294967287UL}};
                    int i, j;
                    step_hash(130);
                    for (l_278 = 0; (l_278 <= 0); l_278 += 1)
                    {
                        int l_290 = 0x4AADFF80L;
                        int l_291 = 0L;
                        int l_292 = 0xF1200FA1L;
                        int i;
                        step_hash(129);
                        l_293[0][3]--;
                    }
                    step_hash(131);
                    g_296++;
                    step_hash(137);
                    for (g_233 = (-24); (g_233 < 3); g_233 += 2)
                    {
                        step_hash(135);
                        --l_301;
                        step_hash(136);
                        l_288 = ((unsigned short)func_46(g_58, l_267[0], g_233, l_306, g_2) >> (unsigned short)0);
                    }
                    step_hash(142);
                    for (g_55 = 0; (g_55 <= 0); g_55 += 1)
                    {
                        step_hash(141);
                        return p_31;
                    }
                }
                step_hash(144);
                l_319[1] |= (l_301 && ((short)(-7L) + (short)((short)((unsigned char)((((unsigned short)((short)l_288 << (short)g_296) << (unsigned short)7) ^ l_301) != l_288) - (unsigned char)0UL) >> (short)((short)(p_33 == l_306) << (short)5))));
            }
            else
            {
                int ***l_320 = &g_68[0][1];
                int l_323 = 0xD02CCC27L;
                int l_329 = (-10L);
                int l_331 = (-1L);
                int l_350 = 0x51002C15L;
                int l_351 = 0x860C1E19L;
                int l_353[9] = {0xA733B53FL, 0x741FB120L, 0xA733B53FL, 0x741FB120L, 0xA733B53FL, 0x741FB120L, 0xA733B53FL, 0x741FB120L, 0xA733B53FL};
                unsigned l_359[8];
                int i;
                for (i = 0; i < 8; i++)
                    l_359[i] = 0xA6C449CCL;
                step_hash(146);
                (*l_320) = &g_69;
                step_hash(158);
                for (g_233 = 0; (g_233 >= 49); g_233 += 4)
                {
                    int l_324 = 0xEABC095BL;
                    int l_328 = 0x374E9201L;
                    short l_330 = (-1L);
                    unsigned char l_336 = 1UL;
                    step_hash(155);
                    for (g_55 = 0; (g_55 <= 0); g_55 += 1)
                    {
                        int l_325 = 0x6B19C9D3L;
                        int l_326 = 0xC1D3C510L;
                        int l_327 = 2L;
                        int l_332 = 0L;
                        int i, j;
                        step_hash(153);
                        p_31 = p_31;
                        step_hash(154);
                        l_333++;
                    }
                    step_hash(156);
                    l_288 ^= (l_336 > ((unsigned short)g_55 * (unsigned short)(((short)l_331 / (short)l_336) || ((short)((unsigned short)(((5UL || (*p_33)) <= ((signed char)(g_2 <= g_296) % (signed char)g_58)) == p_34) >> (unsigned short)p_32) * (short)p_34))));
                    step_hash(157);
                    l_287 &= ((signed char)(g_2 ^ l_275[1]) / (signed char)g_2);
                }
                step_hash(159);
                l_359[1]--;
            }
            step_hash(161);
            l_289[2] ^= (l_267[0] != p_33);
        }
        else
        {
            unsigned l_365 = 0xF80A26F1L;
            int *l_374 = &l_289[2];
            step_hash(170);
            if ((*p_31))
            {
                signed char l_364 = 0x49L;
                unsigned short l_366 = 65526UL;
                step_hash(164);
                l_289[2] &= (((short)l_364 * (short)(g_254 && g_2)) & ((g_58 | g_58) < g_63));
                step_hash(165);
                l_365 |= (p_32 < g_2);
                step_hash(166);
                l_289[2] ^= l_366;
                step_hash(167);
                g_371 ^= ((unsigned char)(((short)p_34 % (short)func_81(g_296, p_34)) & l_364) / (unsigned char)0x1AL);
            }
            else
            {
                step_hash(169);
                l_289[2] = ((0xB7L | g_63) <= (((signed char)l_365 << (signed char)6) >= ((void*)0 == &g_69)));
            }
            step_hash(171);
            p_33 = func_52(p_34);
            step_hash(172);
            (*l_374) = ((void*)0 != l_374);
        }
        step_hash(180);
        for (l_278 = 0; (l_278 > 49); l_278++)
        {
            unsigned short l_387 = 4UL;
            int *l_389 = &l_289[2];
            step_hash(177);
            l_289[1] = ((signed char)(((unsigned char)func_81(g_2, (func_81(p_32, p_32) > (((unsigned)((g_2 > (g_296 > p_32)) < p_34) + (unsigned)(1UL < g_371)) == 0x8DE38532L))) << (unsigned char)7) <= p_32) << (signed char)g_254);
            step_hash(178);
            if ((*p_31))
                break;
            step_hash(179);
            g_390 ^= (l_387 & func_46(func_81((-(signed char)g_55), p_32), &g_2, ((((0xEBL & (~p_34)) || g_233) == (p_32 && p_32)) != p_34), l_389, p_34));
        }
        step_hash(214);
        for (g_296 = (-25); (g_296 > 37); g_296 += 8)
        {
            int l_395[9];
            int **l_396 = &l_306;
            int *l_467[1][9] = {{&g_2, &l_395[3], &g_2, &l_395[3], &g_2, &l_395[3], &g_2, &l_395[3], &g_2}};
            int i, j;
            for (i = 0; i < 9; i++)
                l_395[i] = 0x2EEC62A9L;
            step_hash(184);
            (*l_396) = func_52(((unsigned)p_34 - (unsigned)l_395[6]));
            step_hash(213);
            for (p_32 = 0; (p_32 <= 0); p_32 += 1)
            {
                unsigned l_421 = 0UL;
                int l_458 = 0L;
                signed char l_465[3];
                int i;
                for (i = 0; i < 3; i++)
                    l_465[i] = 0xC2L;
                step_hash(188);
                l_395[2] ^= (*p_31);
                step_hash(212);
                if (((unsigned short)((unsigned char)p_32 / (unsigned char)((signed char)(-6L) * (signed char)(((unsigned char)((unsigned)(p_31 == p_31) - (unsigned)(g_296 != (p_34 < p_34))) + (unsigned char)(p_32 | ((signed char)p_32 % (signed char)1UL))) == g_2))) >> (unsigned short)1))
                {
                    unsigned l_415 = 0x5F4CEE84L;
                    int l_416 = 0x6539C225L;
                    int ***l_436 = &l_396;
                    step_hash(190);
                    l_416 = ((unsigned short)((signed char)((unsigned char)g_233 >> (unsigned char)7) / (signed char)l_415) << (unsigned short)9);
                    step_hash(191);
                    if ((*p_31))
                        continue;
                    step_hash(198);
                    for (g_371 = 0; (g_371 <= 0); g_371 += 1)
                    {
                        unsigned l_437 = 0x98BFE0FBL;
                        int *l_438[3];
                        int i;
                        for (i = 0; i < 3; i++)
                            l_438[i] = &l_416;
                        step_hash(195);
                        l_416 ^= (((((short)((int)l_421 - (int)(0xB7L < (((short)(-1L) * (short)1UL) > ((short)((unsigned short)g_390 + (unsigned short)g_254) >> (short)p_34)))) - (short)p_32) != l_421) | g_58) > p_34);
                        step_hash(196);
                        g_451 |= ((int)((short)((((short)g_390 + (short)(!(&g_69 != (void*)0))) | 0xB8167B32L) > p_32) * (short)(0UL < func_81(g_58, ((unsigned char)(((short)(((unsigned char)(&p_31 != &l_267[0]) >> (unsigned char)p_32) == p_34) * (short)0UL) & l_421) * (unsigned char)g_63)))) / (int)g_254);
                        step_hash(197);
                        l_452--;
                    }
                }
                else
                {
                    unsigned short l_463 = 1UL;
                    int *l_466 = &l_289[0];
                    step_hash(204);
                    for (l_452 = 24; (l_452 != 58); l_452++)
                    {
                        step_hash(203);
                        l_458 = l_457;
                    }
                    step_hash(205);
                    if ((*p_31))
                        continue;
                    step_hash(211);
                    if (((((unsigned short)g_58 << (unsigned short)(g_254 ^ (((-6L) <= (&g_69 != &p_31)) < (func_46((l_421 != p_34), p_31, l_463, (*l_396), g_464) == g_254)))) ^ l_421) && l_465[1]))
                    {
                        step_hash(207);
                        (*l_396) = func_52((g_58 && p_34));
                        step_hash(208);
                        (*l_396) = p_31;
                    }
                    else
                    {
                        step_hash(210);
                        return p_31;
                    }
                }
            }
        }
    }
    else
    {
        unsigned l_468 = 0x4FB7707CL;
        int l_469 = 0x20E71E96L;
        int l_487 = 0x6018D809L;
        int l_493 = (-1L);
        int l_494 = 0x14195862L;
        unsigned char l_531 = 250UL;
        int l_532[2][6] = {{0x3C9E2092L, 0x3C9E2092L, 0xB6441281L, 0x3C9E2092L, 0x3C9E2092L, 0xB6441281L}, {0x3C9E2092L, 0x3C9E2092L, 0xB6441281L, 0x3C9E2092L, 0x3C9E2092L, 0xB6441281L}};
        signed char l_551 = 6L;
        int *l_555 = &l_289[2];
        int i, j;
        step_hash(216);
        l_469 = (func_81(g_390, p_34) < ((g_296 <= 7L) >= l_468));
        step_hash(270);
        if ((p_32 ^ ((unsigned char)p_34 << (unsigned char)1)))
        {
            int *l_472[3];
            int i;
            for (i = 0; i < 3; i++)
                l_472[i] = (void*)0;
            step_hash(218);
            p_31 = l_472[0];
            step_hash(219);
            l_487 ^= ((int)((unsigned)g_451 + (unsigned)((short)9L - (short)(((g_233 & g_390) ^ (p_32 >= ((-(signed char)p_32) == ((unsigned char)((signed char)(0x984CL && p_32) * (signed char)(((int)(l_468 <= g_254) % (int)l_469) == g_390)) % (unsigned char)l_468)))) < (*p_33)))) % (int)l_486);
            step_hash(230);
            for (g_464 = 14; (g_464 >= 11); g_464--)
            {
                int *l_490[8];
                unsigned char l_496 = 0x19L;
                int i;
                for (i = 0; i < 8; i++)
                    l_490[i] = &l_487;
                step_hash(228);
                if (l_468)
                {
                    int **l_491 = &l_490[5];
                    int l_492 = (-1L);
                    int l_495[9] = {0x3DF5D265L, 0L, 0x3DF5D265L, 0L, 0x3DF5D265L, 0L, 0x3DF5D265L, 0L, 0x3DF5D265L};
                    int i;
                    step_hash(224);
                    (*l_491) = l_490[4];
                    step_hash(225);
                    --l_496;
                }
                else
                {
                    int l_511 = 1L;
                    step_hash(227);
                    l_511 = (((unsigned short)((short)(((short)g_63 - (short)((int)l_493 - (int)((unsigned char)(0x95DBL != (g_371 | (-(unsigned)l_510))) * (unsigned char)p_34))) != g_464) - (short)((&l_472[0] != &l_490[4]) < p_34)) * (unsigned short)l_511) && g_390);
                }
                step_hash(229);
                return p_31;
            }
        }
        else
        {
            int *l_533 = &g_523;
            step_hash(236);
            for (g_58 = 0; (g_58 <= 51); g_58++)
            {
                step_hash(235);
                l_487 ^= (-10L);
            }
            step_hash(269);
            for (l_493 = (-15); (l_493 >= (-7)); ++l_493)
            {
                unsigned l_520[2][6] = {{0UL, 0xAF0F9DC9L, 0UL, 0xAF0F9DC9L, 0UL, 0xAF0F9DC9L}, {0UL, 0xAF0F9DC9L, 0UL, 0xAF0F9DC9L, 0UL, 0xAF0F9DC9L}};
                int ***l_530 = &l_266;
                int i, j;
                step_hash(256);
                if (((unsigned char)((p_31 != p_33) || g_371) + (unsigned char)((unsigned char)(l_493 > 0L) + (unsigned char)p_32)))
                {
                    unsigned short l_550 = 0x1084L;
                    int l_552 = 0xF086F0F9L;
                    step_hash(247);
                    if ((func_81(g_233, ((int)0x517E33AEL - (int)((void*)0 == &l_266))) != p_32))
                    {
                        int **l_537 = &g_536;
                        step_hash(242);
                        (*l_537) = g_536;
                        step_hash(243);
                        (*l_533) = ((unsigned)(p_34 | ((int)0x91E29988L + (int)p_32)) % (unsigned)p_34);
                    }
                    else
                    {
                        step_hash(245);
                        l_551 = ((unsigned char)((unsigned short)p_32 + (unsigned short)((signed char)((((unsigned short)(l_531 & (-1L)) << (unsigned short)14) | g_254) < ((*p_31) > ((((*g_536) & (((l_550 != p_34) ^ g_254) | p_34)) | p_32) <= 0xD0C783F7L))) * (signed char)(-6L))) << (unsigned char)7);
                        step_hash(246);
                        l_552 &= 0x9B3E6EBEL;
                    }
                    step_hash(253);
                    for (l_551 = 0; (l_551 == 15); l_551++)
                    {
                        step_hash(251);
                        if ((*p_31))
                            break;
                        step_hash(252);
                        return l_533;
                    }
                }
                else
                {
                    step_hash(255);
                    return p_33;
                }
                step_hash(267);
                for (g_390 = 0; (g_390 <= 1); g_390 += 1)
                {
                    int l_556 = 1L;
                    int i, j;
                    step_hash(260);
                    l_555 = func_35(l_520[g_390][(g_390 + 2)]);
                    step_hash(261);
                    --g_557;
                    step_hash(266);
                    for (g_371 = 0; (g_371 <= 1); g_371 += 1)
                    {
                        step_hash(265);
                        if ((*p_31))
                            break;
                    }
                }
                step_hash(268);
                return p_31;
            }
        }
        step_hash(271);
        (*l_555) = 0x017F7B86L;
        step_hash(297);
        for (g_55 = 0; (g_55 <= 3); g_55 += 1)
        {
            signed char l_560[7] = {(-2L), (-2L), 0xE1L, (-2L), (-2L), 0xE1L, (-2L)};
            int i;
            step_hash(275);
            l_289[g_55] = l_560[3];
            step_hash(296);
            for (g_296 = 0; (g_296 <= 0); g_296 += 1)
            {
                int *l_563 = &l_289[g_55];
            }
        }
    }
    step_hash(299);
    return p_33;
}







static int * func_35(signed char p_36)
{
    int *l_75 = &g_55;
    int *l_76 = &g_55;
    int *l_77[5] = {&g_55, (void*)0, &g_55, (void*)0, &g_55};
    unsigned char l_78[4][6] = {{0xB9L, 0xBFL, 0xE5L, 0xE0L, 255UL, 0UL}, {0xB9L, 0xBFL, 0xE5L, 0xE0L, 255UL, 0UL}, {0xB9L, 0xBFL, 0xE5L, 0xE0L, 255UL, 0UL}, {0xB9L, 0xBFL, 0xE5L, 0xE0L, 255UL, 0UL}};
    int l_86 = 0xCE1F6DC3L;
    int *l_87 = &g_55;
    unsigned l_88 = 3UL;
    int ***l_169[1][5];
    int l_208 = 9L;
    short l_224 = 0x7442L;
    int *l_250 = &l_208;
    int l_255 = 0x78E3D2E3L;
    unsigned short l_256 = 65535UL;
    int *l_259 = &g_2;
    int i, j;
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 5; j++)
            l_169[i][j] = &g_68[0][3];
    }
    step_hash(30);
    --l_78[0][2];
    step_hash(111);
    if (func_81(p_36, ((int)l_88 - (int)0xD85E2616L)))
    {
        int l_135 = (-1L);
        step_hash(55);
        (*l_76) = ((short)(((short)l_135 * (short)((*l_87) && (0xFB12L && l_135))) != 4UL) << (short)6);
        step_hash(56);
        (*l_87) ^= l_135;
    }
    else
    {
        short l_154 = 0x023DL;
        int *l_162 = &g_2;
        unsigned char l_165 = 0x2CL;
        int l_200[7][9] = {{0x07BAAA9AL, 0xA83723A6L, 0x5CB3DCC7L, 0x5CB3DCC7L, 0xA83723A6L, 0x07BAAA9AL, 0x6CB78A07L, 0xC93F04C9L, 0L}, {0x07BAAA9AL, 0xA83723A6L, 0x5CB3DCC7L, 0x5CB3DCC7L, 0xA83723A6L, 0x07BAAA9AL, 0x6CB78A07L, 0xC93F04C9L, 0L}, {0x07BAAA9AL, 0xA83723A6L, 0x5CB3DCC7L, 0x5CB3DCC7L, 0xA83723A6L, 0x07BAAA9AL, 0x6CB78A07L, 0xC93F04C9L, 0L}, {0x07BAAA9AL, 0xA83723A6L, 0x5CB3DCC7L, 0x5CB3DCC7L, 0xA83723A6L, 0x07BAAA9AL, 0x6CB78A07L, 0xC93F04C9L, 0L}, {0x07BAAA9AL, 0xA83723A6L, 0x5CB3DCC7L, 0x5CB3DCC7L, 0xA83723A6L, 0x07BAAA9AL, 0x6CB78A07L, 0xC93F04C9L, 0L}, {0x07BAAA9AL, 0xA83723A6L, 0x5CB3DCC7L, 0x5CB3DCC7L, 0xA83723A6L, 0x07BAAA9AL, 0x6CB78A07L, 0xC93F04C9L, 0L}, {0x07BAAA9AL, 0xA83723A6L, 0x5CB3DCC7L, 0x5CB3DCC7L, 0xA83723A6L, 0x07BAAA9AL, 0x6CB78A07L, 0xC93F04C9L, 0L}};
        unsigned l_219 = 4294967295UL;
        int i, j;
        step_hash(58);
        (*l_87) |= p_36;
        step_hash(91);
        for (g_58 = 8; (g_58 < 60); g_58 += 6)
        {
            int *l_140 = &g_55;
            int l_163 = (-10L);
            int l_164 = (-1L);
            int l_210 = (-1L);
            int l_216 = 0x48CB3587L;
            int l_218 = (-1L);
            step_hash(90);
            for (l_86 = 28; (l_86 > (-3)); l_86--)
            {
                int **l_141 = &g_69;
                int *l_189 = &l_164;
                int l_205 = 0L;
                int l_212 = 0xE747D80AL;
                int l_214[9] = {4L, 4L, 0x781C0EB3L, 4L, 4L, 0x781C0EB3L, 4L, 4L, 0x781C0EB3L};
                int i;
                step_hash(65);
                (*l_141) = l_140;
                step_hash(89);
                if (((signed char)((unsigned short)(((unsigned char)((unsigned char)p_36 + (unsigned char)(&l_141 != (void*)0)) % (unsigned char)((+((((unsigned char)g_58 % (unsigned char)p_36) && (((unsigned char)g_63 >> (unsigned char)l_154) | ((unsigned char)p_36 * (unsigned char)(((p_36 | 0x75085CE8L) <= 0xDCBEL) >= p_36)))) || g_58)) & g_63)) && p_36) >> (unsigned short)0) + (signed char)(*l_76)))
                {
                    int l_159[1];
                    int *l_168 = &l_163;
                    int i;
                    for (i = 0; i < 1; i++)
                        l_159[i] = 0x1652FD55L;
                    step_hash(67);
                    l_164 |= ((short)(0xB4L && ((*l_75) || func_46(l_159[0], (*l_141), ((unsigned char)p_36 / (unsigned char)0xCAL), l_162, (**l_141)))) * (short)l_163);
                    step_hash(68);
                    if (l_165)
                        continue;
                    step_hash(74);
                    for (p_36 = (-5); (p_36 <= 5); p_36++)
                    {
                        step_hash(72);
                        (*l_141) = l_168;
                        step_hash(73);
                        (*l_87) ^= (&g_68[0][1] == l_169[0][3]);
                    }
                }
                else
                {
                    unsigned short l_178[2];
                    int *l_179 = &l_164;
                    unsigned short l_188 = 0UL;
                    int l_206 = 0xCD24EA2AL;
                    int l_213 = 0x433CC307L;
                    int l_215 = (-8L);
                    int l_217 = 1L;
                    int i;
                    for (i = 0; i < 2; i++)
                        l_178[i] = 0x24B6L;
                    step_hash(76);
                    (*l_179) ^= ((signed char)g_63 - (signed char)((int)((5UL >= ((int)(*l_162) + (int)((short)l_178[1] * (short)g_58))) < ((l_179 != (*l_141)) | (-1L))) - (int)((short)((int)((unsigned short)(((unsigned char)p_36 * (unsigned char)1UL) | 0UL) / (unsigned short)g_2) / (int)p_36) << (short)5)));
                    step_hash(87);
                    if (((l_188 && p_36) ^ ((*l_162) > p_36)))
                    {
                        step_hash(78);
                        (*l_141) = (void*)0;
                        step_hash(79);
                        if ((*l_179))
                            continue;
                        step_hash(80);
                        (*l_141) = l_189;
                        step_hash(81);
                        (*l_140) = (((signed char)(((*l_162) != ((signed char)(0x0CB6L | (!(func_46(p_36, &l_163, (*l_140), &l_164, ((unsigned short)(p_36 == (~((**l_141) <= ((int)((signed char)g_55 << (signed char)p_36) + (int)(*l_140))))) * (unsigned short)p_36)) > p_36))) + (signed char)0x6BL)) < 0xC788L) >> (signed char)p_36) != p_36);
                    }
                    else
                    {
                        unsigned l_201 = 0xB116D794L;
                        int *l_204 = &l_200[4][0];
                        int l_207 = 0x3EBDBDEAL;
                        int l_209 = 0L;
                        int l_211[2][9] = {{0L, 0L, (-1L), 5L, 0x8155E1EFL, 5L, (-1L), 0L, 0L}, {0L, 0L, (-1L), 5L, 0x8155E1EFL, 5L, (-1L), 0L, 0L}};
                        int i, j;
                        step_hash(83);
                        l_201--;
                        step_hash(84);
                        if (p_36)
                            break;
                        step_hash(85);
                        (*l_141) = l_204;
                        step_hash(86);
                        --l_219;
                    }
                    step_hash(88);
                    (*l_75) = ((signed char)0L << (signed char)0);
                }
            }
        }
        step_hash(92);
        l_224 &= (*l_76);
        step_hash(110);
        for (l_165 = 0; (l_165 != 55); l_165 += 3)
        {
            unsigned short l_227[10][8] = {{0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}, {0x27ABL, 65532UL, 0xB929L, 0xC41AL, 0x8773L, 0x96D3L, 0x27ABL, 4UL}};
            int l_230 = 1L;
            int i, j;
            step_hash(96);
            l_227[1][5]++;
            step_hash(97);
            l_230 = (-1L);
            step_hash(109);
            for (l_154 = 0; (l_154 <= (-4)); l_154 -= 3)
            {
                unsigned l_248 = 3UL;
                int *l_249 = &l_230;
                step_hash(101);
                l_162 = func_52((g_58 && ((p_36 <= g_2) <= (g_2 == 1UL))));
                step_hash(102);
                g_233++;
                step_hash(103);
                (*l_75) |= ((unsigned short)p_36 << (unsigned short)l_230);
                step_hash(108);
                for (p_36 = (-21); (p_36 != (-30)); p_36 -= 8)
                {
                    int *l_253 = (void*)0;
                    step_hash(107);
                    l_253 = l_249;
                }
            }
        }
    }
    step_hash(112);
    l_256++;
    step_hash(113);
    return l_259;
}







static short func_41(int p_42, int * p_43, int * p_44, int * p_45)
{
    int l_71 = 4L;
    signed char l_74 = 0xC4L;
    step_hash(21);
    (*g_69) = (func_46(g_2, &g_2, (0x01C8L > (0x9751L | g_2)), func_52(p_42), p_42) ^ l_71);
    step_hash(22);
    (*g_69) ^= (*p_45);
    step_hash(27);
    for (g_63 = (-21); (g_63 <= 40); g_63++)
    {
        step_hash(26);
        return g_58;
    }
    step_hash(28);
    return l_74;
}







static unsigned func_46(int p_47, int * p_48, unsigned p_49, int * p_50, unsigned char p_51)
{
    int *l_61 = &g_55;
    int *l_62 = (void*)0;
    int ***l_70 = &g_68[0][0];
    step_hash(17);
    ++g_63;
    step_hash(18);
    (*l_61) = ((short)g_63 >> (short)7);
    step_hash(19);
    (*l_70) = g_68[0][1];
    step_hash(20);
    return p_51;
}







static int * func_52(signed char p_53)
{
    int *l_54 = &g_55;
    int *l_56 = &g_55;
    int *l_57[4][5] = {{&g_55, &g_55, &g_2, &g_55, &g_55}, {&g_55, &g_55, &g_2, &g_55, &g_55}, {&g_55, &g_55, &g_2, &g_55, &g_55}, {&g_55, &g_55, &g_2, &g_55, &g_55}};
    int i, j;
    step_hash(14);
    g_58++;
    step_hash(15);
    return l_57[2][2];
}







static int func_81(unsigned p_82, unsigned short p_83)
{
    int l_105 = 0xDC0990E4L;
    int l_117 = 0xB19369D4L;
    int **l_122 = &g_69;
    step_hash(52);
    for (p_82 = (-26); (p_82 == 27); ++p_82)
    {
        unsigned l_91 = 4294967292UL;
        int **l_92 = &g_69;
        int *l_116 = &g_55;
        step_hash(35);
        (*l_92) = func_52(l_91);
        step_hash(36);
        l_117 |= ((short)(((int)((((unsigned short)((signed char)func_46(((unsigned short)(((unsigned short)(p_83 == 1L) * (unsigned short)(-8L)) == g_2) + (unsigned short)p_83), (*l_92), l_105, (*l_92), p_82) * (signed char)g_2) / (unsigned short)l_105) != (-1L)) < l_105) - (int)0x9B5B590BL) | p_82) >> (short)15);
        step_hash(51);
        for (l_105 = 27; (l_105 != (-10)); l_105 -= 8)
        {
            int **l_123 = &g_69;
            int *l_124 = &l_117;
            step_hash(40);
            (*l_124) |= func_46(((((unsigned char)((l_122 != l_123) | (g_58 >= (g_58 ^ func_46(p_83, (*l_122), func_46(g_55, (*l_122), p_82, (*l_123), g_55), (*l_123), g_2)))) * (unsigned char)p_83) >= 0UL) == g_58), (*l_92), g_58, &g_2, g_2);
            step_hash(41);
            (*l_124) = ((((void*)0 != l_122) ^ ((((((short)0x4060L * (short)p_83) < (g_63 <= ((void*)0 == &l_92))) == g_58) & p_83) != 0xCDL)) | p_82);
            step_hash(50);
            for (g_58 = 0; (g_58 <= 0); g_58 += 1)
            {
                step_hash(49);
                for (g_55 = 0; (g_55 <= 0); g_55 += 1)
                {
                    int i, j;
                    step_hash(48);
                    (*l_124) &= (((short)((void*)0 != (*l_122)) * (short)g_55) >= g_2);
                }
            }
        }
    }
    step_hash(53);
    return p_82;
}


void csmith_compute_hash(void)
{
    int i, j;
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_55, "g_55", print_hash_value);
    transparent_crc(g_58, "g_58", print_hash_value);
    transparent_crc(g_63, "g_63", print_hash_value);
    transparent_crc(g_233, "g_233", print_hash_value);
    transparent_crc(g_254, "g_254", print_hash_value);
    transparent_crc(g_296, "g_296", print_hash_value);
    transparent_crc(g_371, "g_371", print_hash_value);
    transparent_crc(g_390, "g_390", print_hash_value);
    transparent_crc(g_451, "g_451", print_hash_value);
    transparent_crc(g_464, "g_464", print_hash_value);
    transparent_crc(g_523, "g_523", print_hash_value);
    transparent_crc(g_557, "g_557", print_hash_value);
    transparent_crc(g_597, "g_597", print_hash_value);
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
