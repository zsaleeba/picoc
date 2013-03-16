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
static int g_2 = 0x5F70AD6FL;
static int g_6 = (-1L);
static int g_21 = 2L;
static int g_73 = 0x617092FFL;
static signed char g_83 = (-8L);
static int **g_86 = (void*)0;
static int g_100 = (-4L);
static int g_133 = (-6L);
static unsigned char g_151 = 0xDAL;
static int g_185 = 0xBFB62ABAL;
static int *g_214 = &g_133;
static int **g_365 = (void*)0;
static int **g_418 = &g_214;
static unsigned g_430 = 4294967295UL;
static int *g_491 = (void*)0;
static int **g_493 = &g_214;
static signed char g_574 = (-10L);
static signed char g_601 = (-10L);
static int *g_641 = &g_73;
static unsigned short g_654 = 0x41D6L;
static unsigned char func_1(void);
static int func_11(int * p_12, unsigned p_13, signed char p_14, int * p_15);
static int ** func_22(unsigned p_23, signed char p_24, int * p_25, short p_26);
static int * func_29(unsigned short p_30, int * p_31, int * p_32);
static unsigned short func_33(short p_34, unsigned p_35, int ** p_36, int ** p_37);
static short func_40(int p_41, int p_42, int * p_43, unsigned char p_44);
static int func_45(short p_46, unsigned p_47, int * p_48, unsigned char p_49);
static int func_50(short p_51, int * p_52, int p_53);
static unsigned short func_56(int * p_57, unsigned p_58, int p_59, int p_60);
static int * func_61(int ** p_62);
static unsigned char func_1(void)
{
    int *l_3 = (void*)0;
    int *l_4 = (void*)0;
    int *l_5 = &g_6;
    int ***l_515 = &g_86;
    int l_516 = 0x82FF2273L;
    int l_575 = 0xCDC44E88L;
    int *l_588 = &g_6;
    unsigned char l_604 = 2UL;
    unsigned l_611 = 0x573E6FE5L;
    unsigned l_633 = 0x17D35668L;
    int l_634 = 0xFB5EEB36L;
    unsigned l_664 = 0UL;
    unsigned short l_678 = 0x7DA6L;
    unsigned short l_689 = 65529UL;
    step_hash(1);
    (*l_5) &= g_2;
    step_hash(445);
    for (g_2 = 0; (g_2 > (-3)); g_2--)
    {
        int **l_9 = (void*)0;
        int **l_10 = &l_4;
        unsigned l_540 = 1UL;
        int l_547 = 0x3FB1A51AL;
        unsigned l_582 = 4294967294UL;
        int **l_583 = &g_214;
        signed char l_668 = 0xFEL;
        step_hash(5);
        (*l_10) = (void*)0;
    }
    step_hash(446);
    (*g_418) = (*g_418);
    step_hash(447);
    return g_430;
}
static int func_11(int * p_12, unsigned p_13, signed char p_14, int * p_15)
{
    unsigned char l_27 = 0xC1L;
    int *l_367 = (void*)0;
    int **l_366 = &l_367;
    step_hash(338);
    for (g_6 = 23; (g_6 == (-27)); g_6 -= 3)
    {
        unsigned char l_28 = 1UL;
        int ***l_492 = (void*)0;
        step_hash(15);
        for (p_13 = 0; (p_13 < 46); p_13 += 6)
        {
            int *l_20 = &g_21;
            step_hash(13);
            (*l_20) = (*p_12);
            step_hash(14);
            (*l_20) = 0xB8B78ACCL;
        }
    }
    step_hash(339);
    return (*p_12);
}
static int ** func_22(unsigned p_23, signed char p_24, int * p_25, short p_26)
{
    int **l_389 = &g_214;
    int l_429 = 0x1670AD50L;
    int **l_431 = &g_214;
    step_hash(332);
    if (((~(l_389 != &p_25)) | ((unsigned char)((unsigned short)((((signed char)(-1L) >> (signed char)4) && 249UL) <= 0x97L) << (unsigned short)14) / (unsigned char)(func_56(p_25, p_23, g_83, g_133) & 0xCEL))))
    {
        signed char l_398 = (-7L);
        unsigned l_420 = 0x699DD6A4L;
        int *l_421 = (void*)0;
        int l_462 = 6L;
        step_hash(316);
        if (l_398)
        {
            int *l_405 = &g_185;
            int **l_419 = &l_405;
            unsigned l_426 = 4294967290UL;
            unsigned short l_437 = 0x130DL;
            int l_438 = 0x562DD2E4L;
            int *l_439 = &g_6;
            step_hash(285);
            (*l_405) = (l_398 > ((signed char)((short)((~(l_398 ^ l_398)) | 0x2C2EL) * (short)((signed char)(((l_405 != (*l_389)) || (*l_405)) >= g_73) * (signed char)func_45(g_73, p_26, l_405, g_185))) >> (signed char)p_24));
            step_hash(286);
            g_133 = (((signed char)((unsigned short)(((unsigned)(&g_86 == &g_86) + (unsigned)l_398) | ((unsigned char)((void*)0 == &g_214) >> (unsigned char)0)) - (unsigned short)2UL) % (signed char)(*l_405)) || 0xF6L);
            step_hash(313);
            if (((signed char)(g_6 | ((l_389 != (void*)0) && ((p_23 | (0xC5L < (func_33(g_133, (((int)0xBB2A3691L % (int)p_24) && g_73), g_418, l_419) && g_6))) || l_420))) >> (signed char)p_24))
            {
                step_hash(288);
                (*l_389) = l_421;
            }
            else
            {
                int ***l_422 = (void*)0;
                int ***l_423 = &g_86;
                int l_461 = 1L;
                step_hash(290);
                (*l_423) = &g_214;
                step_hash(291);
                (*l_419) = (**l_423);
                step_hash(311);
                if ((g_430 != 0L))
                {
                    int *l_434 = &g_100;
                    step_hash(300);
                    if (p_24)
                    {
                        step_hash(294);
                        (*l_423) = l_389;
                    }
                    else
                    {
                        unsigned l_432 = 0x1E9944D6L;
                        step_hash(296);
                        (*l_419) = (*l_419);
                        step_hash(297);
                        (*l_419) = func_61(l_431);
                        step_hash(298);
                        l_432 |= (*g_214);
                        step_hash(299);
                        (**l_431) ^= func_33(g_6, (-(unsigned)p_23), &g_214, &g_214);
                    }
                    step_hash(301);
                    (*l_434) ^= 0x455675CCL;
                }
                else
                {
                    unsigned l_440 = 0xF9B96A1AL;
                    step_hash(310);
                    for (l_398 = 0; (l_398 < 28); l_398 += 6)
                    {
                        int *l_449 = (void*)0;
                        int *l_450 = &g_21;
                        step_hash(306);
                        l_438 &= l_437;
                        step_hash(307);
                        g_73 &= l_440;
                        step_hash(308);
                        (**l_423) = (*g_418);
                        step_hash(309);
                        (*l_450) = ((int)((short)func_56(p_25, g_6, ((unsigned short)((p_26 || (4294967287UL | p_24)) > g_6) / (unsigned short)((short)(&g_214 != &g_214) << (short)g_6)), p_23) << (short)g_21) + (int)p_23);
                    }
                }
                step_hash(312);
                l_461 = (g_2 <= ((short)((p_23 <= p_24) > ((!(((signed char)((signed char)((!(((unsigned char)g_185 % (unsigned char)g_2) & p_24)) == p_23) / (signed char)g_73) >> (signed char)1) == p_24)) == p_26)) << (short)2));
            }
        }
        else
        {
            step_hash(315);
            l_462 ^= ((l_398 > (p_24 < g_83)) > l_420);
        }
    }
    else
    {
        unsigned char l_463 = 0UL;
        int *l_464 = &g_21;
        step_hash(318);
        (*l_464) = (l_463 == 0L);
        step_hash(319);
        (*l_464) = p_23;
        step_hash(331);
        if (((unsigned short)(+p_23) >> (unsigned short)p_26))
        {
            step_hash(321);
            (*l_464) = ((-7L) | (((g_73 & g_6) | ((p_23 & func_33(g_185, ((unsigned char)((((unsigned short)g_21 * (unsigned short)((unsigned short)((signed char)((short)p_23 >> (short)11) - (signed char)0L) >> (unsigned short)7)) & ((-(unsigned)((unsigned char)p_23 << (unsigned char)5)) & g_73)) != 9L) - (unsigned char)(*l_464)), &g_214, l_431)) != 0x0BL)) != p_26));
            step_hash(328);
            for (g_430 = 0; (g_430 >= 15); g_430 += 2)
            {
                int *l_482 = &g_185;
                step_hash(325);
                (*l_482) ^= (*l_464);
                step_hash(326);
                p_25 = (void*)0;
                step_hash(327);
                (*l_482) ^= (*l_464);
            }
        }
        else
        {
            step_hash(330);
            (*g_418) = (*g_418);
        }
    }
    step_hash(333);
    l_429 ^= ((signed char)(0xEEB07A1AL && ((unsigned char)(((short)(-7L) + (short)((signed char)(p_24 <= g_133) + (signed char)(&l_389 != &l_389))) <= ((void*)0 != (*l_389))) << (unsigned char)6)) % (signed char)func_56(g_491, p_26, p_23, p_26));
    step_hash(334);
    (*g_418) = (*l_431);
    step_hash(335);
    (*l_389) = func_61(&g_214);
    step_hash(336);
    return l_389;
}
static int * func_29(unsigned short p_30, int * p_31, int * p_32)
{
    int **l_368 = &g_214;
    unsigned char l_383 = 6UL;
    int *l_388 = &g_73;
    step_hash(279);
    if ((*p_31))
    {
        step_hash(253);
        (*l_368) = func_61(l_368);
    }
    else
    {
        int *l_369 = (void*)0;
        step_hash(255);
        (*l_368) = l_369;
        step_hash(278);
        for (g_151 = 15; (g_151 <= 42); ++g_151)
        {
            int *l_380 = (void*)0;
            step_hash(277);
            if (g_185)
            {
                step_hash(260);
                return p_31;
            }
            else
            {
                int l_374 = 0x0096045BL;
                int *l_382 = &g_133;
                step_hash(275);
                for (g_185 = 0; (g_185 > (-29)); g_185 -= 1)
                {
                    int *l_375 = (void*)0;
                    int l_379 = 0xA4210C70L;
                }
                step_hash(276);
                (*l_382) ^= (*p_32);
            }
        }
    }
    step_hash(280);
    (*l_388) = func_56((*l_368), l_383, (((unsigned char)p_30 * (unsigned char)0x6AL) & (0UL > 0xA7L)), p_30);
    step_hash(281);
    return (*l_368);
}
static unsigned short func_33(short p_34, unsigned p_35, int ** p_36, int ** p_37)
{
    step_hash(250);
    return g_73;
}
static short func_40(int p_41, int p_42, int * p_43, unsigned char p_44)
{
    unsigned short l_85 = 0xDCDEL;
    int *l_91 = &g_21;
    int **l_90 = &l_91;
    int *l_92 = &g_6;
    unsigned l_101 = 0UL;
    int l_134 = 0x68C1B86BL;
    int *l_331 = &g_21;
    step_hash(45);
    if (l_85)
    {
        step_hash(41);
        (*p_43) = g_73;
        step_hash(42);
        (*p_43) = 0xB81468F3L;
    }
    else
    {
        step_hash(44);
        return g_73;
    }
    step_hash(46);
    (*p_43) = (g_86 != g_86);
    step_hash(247);
    if ((*p_43))
    {
        int *l_89 = &g_73;
        int l_130 = 0xC8C67737L;
        unsigned l_175 = 4294967295UL;
        int **l_259 = &l_89;
        step_hash(48);
        (*l_89) ^= ((unsigned)g_21 % (unsigned)0x64EB7F04L);
        step_hash(86);
        if ((*l_89))
        {
            step_hash(50);
            return l_85;
        }
        else
        {
            int l_98 = (-1L);
            int *l_102 = &g_73;
            step_hash(58);
            if (((void*)0 != l_90))
            {
                signed char l_97 = 0xC4L;
                int *l_99 = &g_100;
                step_hash(53);
                (*l_90) = l_92;
                step_hash(54);
                (*p_43) &= (*l_89);
                step_hash(55);
                (*l_99) |= (p_44 || ((signed char)((p_44 && ((&p_43 != &p_43) <= ((signed char)(func_50((*l_89), p_43, l_97) != (!l_98)) % (signed char)l_98))) ^ (**l_90)) % (signed char)l_98));
            }
            else
            {
                step_hash(57);
                return l_101;
            }
            step_hash(64);
            if ((l_102 != (*l_90)))
            {
                unsigned l_109 = 4294967295UL;
                step_hash(60);
                (*l_89) = (g_6 != ((((((short)1L << (short)((short)g_6 >> (short)((-1L) == (((-6L) ^ (*l_89)) <= ((int)(((void*)0 != &p_43) < (*p_43)) / (int)(*p_43)))))) && (*l_92)) > 0x1EA71B31L) & g_6) > l_109));
            }
            else
            {
                int ***l_110 = &g_86;
                step_hash(62);
                (*l_110) = g_86;
                step_hash(63);
                p_43 = func_61(&l_89);
            }
            step_hash(84);
            if (g_2)
            {
                step_hash(71);
                for (p_42 = 0; (p_42 > 2); ++p_42)
                {
                    step_hash(69);
                    (*l_90) = &g_21;
                    step_hash(70);
                    (*l_90) = p_43;
                }
                step_hash(72);
                (*l_102) = p_41;
                step_hash(78);
                for (l_85 = 9; (l_85 == 44); l_85++)
                {
                    step_hash(76);
                    (*l_89) = ((~1L) || ((short)(0xC9E8L ^ (*l_102)) + (short)g_2));
                    step_hash(77);
                    (*l_89) = ((int)g_6 - (int)p_44);
                }
            }
            else
            {
                int l_127 = 0xBFD0B78AL;
                int *l_128 = &g_21;
                step_hash(80);
                (*l_89) = (*l_92);
                step_hash(81);
                (*l_128) = ((*l_92) != ((unsigned)((unsigned)((unsigned)(g_6 >= ((int)(g_6 & (func_45((0x5BL == ((g_21 >= (func_56(p_43, p_44, g_6, g_73) >= l_127)) || 0UL)), g_2, l_128, g_6) < g_100)) / (int)(*l_128))) / (unsigned)0xFB7EBE1DL) % (unsigned)0xCCD07CA3L) % (unsigned)g_2));
                step_hash(82);
                (*l_102) = (*l_128);
                step_hash(83);
                l_130 = (g_73 ^ (-(unsigned)((*l_128) == g_21)));
            }
            step_hash(85);
            (*l_102) ^= ((unsigned short)g_21 << (unsigned short)15);
        }
        step_hash(200);
        if ((g_133 ^ func_56(p_43, func_56((*l_90), l_134, (g_133 & ((signed char)p_44 + (signed char)p_42)), p_42), g_21, p_42)))
        {
            int l_139 = 0x616C39CFL;
            int *l_158 = &l_130;
            short l_223 = 0L;
            step_hash(88);
            (*l_90) = func_61(&l_91);
            step_hash(123);
            if (p_41)
            {
                signed char l_144 = 4L;
                int *l_152 = (void*)0;
                int l_199 = 0x01D5F7C6L;
                step_hash(95);
                for (p_41 = 0; (p_41 < (-27)); --p_41)
                {
                    step_hash(93);
                    (*l_90) = p_43;
                    step_hash(94);
                    if ((*l_89))
                        break;
                }
                step_hash(96);
                (*l_89) &= l_139;
                step_hash(117);
                for (l_130 = 0; (l_130 == 20); l_130 += 5)
                {
                    unsigned l_147 = 4294967289UL;
                    int l_150 = 0xCE84173BL;
                    int **l_174 = &l_89;
                    step_hash(105);
                    if (((((short)p_42 << (short)0) | l_144) & func_56(func_61(&p_43), p_41, ((short)(l_147 ^ 0x2DL) + (short)((signed char)(l_150 != l_144) + (signed char)g_83)), g_133)))
                    {
                        step_hash(101);
                        (*p_43) |= l_139;
                        step_hash(102);
                        (*l_89) = g_151;
                    }
                    else
                    {
                        step_hash(104);
                        (*l_90) = l_152;
                    }
                    step_hash(106);
                    (*l_89) = 0x4001E8EAL;
                    step_hash(107);
                    (*l_89) |= (-(int)((p_42 || p_44) < ((short)(*l_92) << (short)2)));
                    step_hash(116);
                    if (((unsigned char)func_50((func_56(l_158, ((void*)0 != g_86), ((unsigned short)l_147 << (unsigned short)((((int)(p_41 == (*l_158)) + (int)(((int)g_151 + (int)((0x03L > ((void*)0 == (*l_90))) ^ g_83)) != g_73)) ^ 255UL) | 0L)), g_73) | (*p_43)), p_43, g_21) << (unsigned char)g_100))
                    {
                        step_hash(109);
                        (*l_90) = func_61(&p_43);
                        step_hash(110);
                        if ((*p_43))
                            break;
                    }
                    else
                    {
                        int *l_169 = &g_100;
                        int *l_176 = (void*)0;
                        int *l_177 = (void*)0;
                        int *l_178 = &g_133;
                        step_hash(112);
                        (*l_178) &= func_56(p_43, ((signed char)((((((signed char)(((((l_169 != (void*)0) > 0xC119431DL) & (g_100 < ((unsigned short)((signed char)(g_73 <= ((((l_174 == (void*)0) <= l_175) | g_21) <= (*p_43))) * (signed char)255UL) >> (unsigned short)g_21))) & 2L) <= 0xA9A3L) + (signed char)p_41) & (*l_158)) & (*l_158)) == p_41) < p_44) - (signed char)1UL), g_6, (*l_89));
                        step_hash(113);
                        (*l_178) |= func_45(((short)((short)(p_44 > g_151) + (short)func_56(l_158, ((signed char)p_41 / (signed char)p_42), g_185, g_21)) >> (short)g_21), (*l_158), l_158, g_83);
                        step_hash(114);
                        (*l_178) ^= ((signed char)(((func_50(g_6, p_43, (p_42 == ((((unsigned short)((((func_56(l_158, p_42, ((254UL | ((p_41 < ((unsigned short)((*l_158) == (((signed char)((signed char)((signed char)(((-(short)func_45(g_73, p_44, &g_73, (*l_169))) > 255UL) ^ p_44) % (signed char)g_73) >> (signed char)2) - (signed char)(-10L)) >= (*l_158))) >> (unsigned short)g_73)) >= 0xBFL)) & 0xCF18L), p_44) || g_83) != 0L) | g_100) ^ l_199) / (unsigned short)(-1L)) == g_6) <= p_42))) | p_41) >= p_44) >= p_42) >> (signed char)0);
                        step_hash(115);
                        p_43 = l_158;
                    }
                }
            }
            else
            {
                int l_206 = 7L;
                int **l_213 = (void*)0;
                step_hash(119);
                (*l_89) = ((((unsigned char)255UL / (unsigned char)((unsigned char)((unsigned char)(*l_158) << (unsigned char)6) - (unsigned char)l_206)) ^ (p_43 != &l_130)) != ((g_6 | ((0UL < (((short)(&p_43 != &p_43) << (short)4) < (*l_89))) | g_73)) > p_41));
                step_hash(120);
                g_185 |= (*l_89);
                step_hash(121);
                g_214 = &g_21;
                step_hash(122);
                (*l_90) = p_43;
            }
            step_hash(152);
            for (g_151 = (-8); (g_151 < 19); g_151 += 7)
            {
                int *l_221 = &g_100;
                step_hash(127);
                (*l_158) &= (*l_89);
                step_hash(128);
                p_43 = (void*)0;
                step_hash(129);
                g_214 = func_61(&p_43);
                step_hash(151);
                for (p_41 = 0; (p_41 <= 15); ++p_41)
                {
                    int *l_230 = &g_73;
                    step_hash(139);
                    for (l_101 = 23; (l_101 >= 38); l_101 += 3)
                    {
                        unsigned l_222 = 0UL;
                        step_hash(136);
                        (*l_90) = l_221;
                        step_hash(137);
                        (*l_90) = func_61(&l_221);
                        step_hash(138);
                        (*p_43) ^= l_222;
                    }
                    step_hash(140);
                    (*l_158) |= (*p_43);
                    step_hash(141);
                    if ((*l_89))
                        break;
                    step_hash(150);
                    if (l_223)
                    {
                        unsigned l_235 = 0xA20A0228L;
                        step_hash(143);
                        (*l_221) = ((signed char)((short)((65532UL || ((int)((func_56(p_43, func_56(l_230, ((int)(p_44 ^ g_73) - (int)9L), g_73, ((signed char)l_235 << (signed char)((((unsigned short)65530UL << (unsigned short)g_83) <= (*l_89)) | g_151))), g_151, l_175) >= p_41) && (*l_221)) % (int)g_2)) ^ (*p_43)) << (short)p_41) + (signed char)1UL);
                        step_hash(144);
                        (*l_158) = (*p_43);
                        step_hash(145);
                        (*l_90) = (void*)0;
                        step_hash(146);
                        (*p_43) = 0xEC8503F6L;
                    }
                    else
                    {
                        step_hash(148);
                        (*l_158) &= 0x4E080E16L;
                        step_hash(149);
                        (*l_158) ^= (*l_221);
                    }
                }
            }
        }
        else
        {
            int l_242 = 0x8FC63146L;
            int ***l_291 = &l_90;
            step_hash(154);
            (*g_214) ^= 0x3FE045DEL;
            step_hash(198);
            if (((signed char)func_56(p_43, ((unsigned short)(l_242 < (func_56(func_61(&g_214), p_42, ((short)((int)p_41 % (int)g_83) - (short)(g_133 < (g_133 >= g_6))), g_133) || p_42)) - (unsigned short)65535UL), p_42, g_133) + (signed char)g_133))
            {
                int *l_249 = &g_133;
                step_hash(156);
                (*l_249) &= (g_6 >= (l_242 | (func_56(&l_130, (*l_92), (*l_89), p_44) != p_44)));
                step_hash(157);
                l_242 |= 0xD457A838L;
                step_hash(158);
                (*g_214) &= (*l_92);
            }
            else
            {
                int l_264 = 0x5AFF450AL;
                int l_265 = 0xE78FCAF2L;
                int l_307 = (-1L);
                step_hash(160);
                (*g_214) |= (-8L);
                step_hash(161);
                (*g_214) &= (-4L);
                step_hash(182);
                for (g_100 = 27; (g_100 <= (-13)); g_100 -= 9)
                {
                    short l_258 = 0x3CCFL;
                    int l_266 = 0x3B1FCE4BL;
                    int ***l_274 = (void*)0;
                }
                step_hash(197);
                for (g_133 = 0; (g_133 <= 14); g_133 += 2)
                {
                    short l_285 = 0L;
                    step_hash(195);
                    if ((*l_89))
                    {
                        int *l_286 = &g_100;
                        step_hash(187);
                        if ((*l_89))
                            break;
                        step_hash(188);
                        (*l_286) &= ((signed char)((unsigned)((unsigned char)(**l_259) - (unsigned char)((void*)0 != &g_214)) + (unsigned)(**l_259)) * (signed char)func_45(((l_285 == 0x3C99L) || (*l_92)), g_6, &g_185, p_44));
                        step_hash(189);
                        (*l_286) &= (p_44 > (*g_214));
                        step_hash(190);
                        (*l_89) = ((void*)0 != l_291);
                    }
                    else
                    {
                        int *l_302 = &l_242;
                        step_hash(192);
                        (*l_89) = (**l_259);
                        step_hash(193);
                        (*g_214) = ((int)((unsigned)0UL - (unsigned)l_285) / (int)0x16205D54L);
                        step_hash(194);
                        (*g_214) = ((unsigned char)g_73 * (unsigned char)(p_44 ^ (func_45(l_264, (func_45(((unsigned short)((short)(+((unsigned short)((unsigned char)((*l_89) & (((g_21 || ((p_44 >= 0xDDDDL) >= (((unsigned char)((void*)0 == &l_90) << (unsigned char)7) == g_21))) ^ 0x89C775E3L) < 0xD65FL)) >> (unsigned char)p_42) * (unsigned short)g_151)) + (short)0x3B07L) + (unsigned short)l_285), l_285, &l_307, g_151) != g_185), l_302, p_44) != p_44)));
                    }
                    step_hash(196);
                    (*g_214) = (*l_89);
                }
            }
            step_hash(199);
            (*g_214) = (0x9C7FL <= (((unsigned char)((*l_92) | p_42) % (unsigned char)(**l_259)) || g_83));
        }
        step_hash(201);
        (**l_259) = (-1L);
    }
    else
    {
        int l_336 = 0L;
        int *l_351 = &g_6;
        unsigned short l_362 = 65534UL;
        step_hash(245);
        for (p_41 = (-17); (p_41 < (-7)); p_41 += 4)
        {
            unsigned short l_330 = 65535UL;
            int l_333 = 0x139A6BB7L;
            step_hash(244);
            for (g_83 = (-10); (g_83 == (-29)); g_83 -= 6)
            {
                int **l_339 = &l_91;
                int l_350 = (-7L);
            }
        }
        step_hash(246);
        (*l_90) = func_61(&g_214);
    }
    step_hash(248);
    return g_73;
}
static int func_45(short p_46, unsigned p_47, int * p_48, unsigned char p_49)
{
    step_hash(38);
    return (*p_48);
}
static int func_50(short p_51, int * p_52, int p_53)
{
    int *l_64 = &g_21;
    int **l_63 = &l_64;
    step_hash(34);
    (*p_52) = (0x197CL || func_56(func_61(l_63), p_51, p_51, ((short)(g_6 == ((signed char)((g_6 & (l_63 == (void*)0)) & g_6) - (signed char)0UL)) << (short)g_2)));
    step_hash(35);
    (**l_63) = g_21;
    step_hash(36);
    return (**l_63);
}
static unsigned short func_56(int * p_57, unsigned p_58, int p_59, int p_60)
{
    int l_82 = 7L;
    int *l_84 = &g_73;
    step_hash(32);
    (*l_84) = ((short)(&g_21 == &g_73) >> (short)((+((short)g_21 * (short)0x0D3DL)) <= (l_82 && g_83)));
    step_hash(33);
    return g_21;
}
static int * func_61(int ** p_62)
{
    int *l_65 = (void*)0;
    step_hash(18);
    (*p_62) = l_65;
    step_hash(19);
    (*p_62) = &g_21;
    step_hash(24);
    for (g_21 = 0; (g_21 > (-15)); --g_21)
    {
        step_hash(23);
        return l_65;
    }
    step_hash(29);
    for (g_21 = 0; (g_21 < (-24)); --g_21)
    {
        short l_70 = (-6L);
        int *l_71 = (void*)0;
        int *l_72 = &g_73;
        step_hash(28);
        (*l_72) &= l_70;
    }
    step_hash(30);
    return (*p_62);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_6, "g_6", print_hash_value);
    transparent_crc(g_21, "g_21", print_hash_value);
    transparent_crc(g_73, "g_73", print_hash_value);
    transparent_crc(g_83, "g_83", print_hash_value);
    transparent_crc(g_100, "g_100", print_hash_value);
    transparent_crc(g_133, "g_133", print_hash_value);
    transparent_crc(g_151, "g_151", print_hash_value);
    transparent_crc(g_185, "g_185", print_hash_value);
    transparent_crc(g_430, "g_430", print_hash_value);
    transparent_crc(g_574, "g_574", print_hash_value);
    transparent_crc(g_601, "g_601", print_hash_value);
    transparent_crc(g_654, "g_654", print_hash_value);
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
    int print_hash_value = 0;
    platform_main_begin();
    crc32_gentab();
    func_1();
    csmith_compute_hash();
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
