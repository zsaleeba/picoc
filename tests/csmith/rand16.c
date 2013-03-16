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
static int g_10 = 0x144AD72DL;
static int *g_9 = &g_10;
static int g_79 = 0x0EA8EDF9L;
static int *g_90 = &g_79;
static int **g_89 = &g_90;
static int g_93 = 0xADEE2DE5L;
static unsigned g_119 = 4294967295UL;
static unsigned g_145 = 1UL;
static short g_189 = (-2L);
static int g_283 = 0L;
static int g_400 = (-1L);
static int ***g_507 = &g_89;
static int *g_532 = (void*)0;
static int ***g_545 = &g_89;
static int g_590 = 1L;
static signed char g_625 = 0xD0L;
static unsigned char func_1(void);
static int * func_5(int * p_6, unsigned short p_7, unsigned short p_8);
static unsigned func_17(int p_18);
static int func_19(int * p_20, unsigned p_21, int * p_22);
static int * func_23(unsigned short p_24);
static int func_27(unsigned p_28, signed char p_29, int p_30, unsigned p_31);
static unsigned short func_39(unsigned p_40, unsigned p_41, int * p_42);
static int * func_43(unsigned p_44, int p_45, short p_46);
static unsigned short func_47(unsigned char p_48);
static unsigned short func_59(unsigned short p_60, signed char p_61, signed char p_62);
static unsigned char func_1(void)
{
    unsigned l_2 = 0xEC3D7D49L;
    int *l_16 = &g_10;
    int ***l_546 = (void*)0;
    int *l_592 = &g_93;
    int *l_620 = &g_79;
    unsigned char l_634 = 0x22L;
    unsigned char l_675 = 0UL;
    step_hash(335);
    if ((~l_2))
    {
        unsigned char l_458 = 0xE1L;
        int *l_534 = &g_10;
        step_hash(254);
        for (l_2 = 11; (l_2 < 1); --l_2)
        {
            int **l_533 = &g_9;
            unsigned char l_541 = 0xCCL;
            step_hash(240);
            (*l_533) = func_5(g_9, ((int)((signed char)(((*g_9) < ((((void*)0 == &g_10) == ((-(short)((void*)0 == l_16)) != (func_17(func_19(func_23(((unsigned char)4UL + (unsigned char)0xD2L)), g_283, &g_283)) && (*g_9)))) & l_458)) & 0x2CL) >> (signed char)6) / (int)(*g_9)), (*l_16));
            step_hash(241);
            (*g_89) = (void*)0;
            step_hash(242);
            (*l_533) = l_534;
            step_hash(253);
            for (g_10 = 11; (g_10 > (-29)); --g_10)
            {
                signed char l_538 = 0L;
                int *l_544 = &g_79;
                step_hash(246);
                (*l_544) |= ((-(unsigned)(g_189 != ((0xDFB4BF60L && 0xB5954C98L) | ((l_538 == (~((unsigned short)(((-4L) ^ g_93) == l_541) / (unsigned short)0x15AEL))) & ((signed char)g_189 >> (signed char)(*l_534)))))) > 65533UL);
                step_hash(247);
                (*l_544) = ((((((0x655FF68BL | func_47(g_283)) != ((g_283 && (((*g_9) || (*l_16)) | (255UL || (g_545 != l_546)))) <= 9UL)) >= g_145) || (*l_16)) | g_119) | 0xED079876L);
                step_hash(252);
                for (g_119 = 0; (g_119 <= 32); ++g_119)
                {
                    step_hash(251);
                    (**g_545) = l_534;
                }
            }
        }
    }
    else
    {
        signed char l_555 = (-8L);
        unsigned l_565 = 0x8F8CECB5L;
        int *l_571 = &g_283;
        unsigned short l_617 = 65535UL;
        step_hash(256);
        (***g_507) = 0L;
        step_hash(333);
        if (((func_47(((unsigned char)0xE5L * (unsigned char)g_10)) == ((signed char)((unsigned char)l_555 << (unsigned char)4) << (signed char)2)) && l_555))
        {
            int **l_558 = &l_16;
            int *l_589 = &g_10;
            int **l_608 = (void*)0;
            step_hash(294);
            if ((g_283 != ((unsigned)(l_558 != (*g_545)) - (unsigned)(+(((~g_10) == ((unsigned char)func_59(g_79, ((short)(g_79 | ((g_400 & ((unsigned short)(g_119 == (**l_558)) >> (unsigned short)g_119)) == 65529UL)) * (short)(-10L)), (*l_16)) - (unsigned char)l_565)) <= g_119)))))
            {
                int *l_566 = &g_79;
                int ***l_567 = &l_558;
                signed char l_570 = 0L;
                signed char l_591 = 0x69L;
                step_hash(278);
                if ((((((**g_507) == (void*)0) > (func_59(g_400, g_10, ((**g_507) == l_566)) ^ ((l_567 != &g_89) < (**l_558)))) != 0x26L) < g_189))
                {
                    unsigned char l_569 = 0xB7L;
                    unsigned l_578 = 0UL;
                    unsigned char l_580 = 0x2AL;
                    step_hash(266);
                    if ((*g_9))
                    {
                        int l_568 = 0x38F7327EL;
                        step_hash(261);
                        (*l_558) = (void*)0;
                        step_hash(262);
                        return l_568;
                    }
                    else
                    {
                        unsigned short l_579 = 0UL;
                        step_hash(264);
                        (***g_507) = l_569;
                        step_hash(265);
                        (*l_571) = ((func_17(l_570) || g_189) & (func_19(l_571, ((signed char)(((short)(+((unsigned char)((*l_558) != (void*)0) / (unsigned char)(g_145 & ((g_145 != l_578) || g_283)))) % (short)l_579) < 2UL) << (signed char)1), (**l_567)) >= (**l_558)));
                    }
                    step_hash(267);
                    (**l_558) ^= l_580;
                    step_hash(268);
                    (**g_545) = func_5((**l_567), g_283, (*l_566));
                }
                else
                {
                    step_hash(270);
                    (*l_566) = (**g_89);
                    step_hash(275);
                    for (g_189 = 0; (g_189 < (-7)); g_189--)
                    {
                        step_hash(274);
                        (*l_16) ^= 9L;
                    }
                    step_hash(276);
                    (*l_558) = func_5((*l_558), ((g_119 != (g_79 & ((((short)((1UL <= func_59(((func_39(((unsigned char)(((unsigned char)0xA2L / (unsigned char)(g_400 || 0xDACDL)) | func_19((*g_89), g_283, l_589)) * (unsigned char)g_93), g_283, (**g_545)) < g_400) && (*l_16)), g_400, g_145)) == g_590) % (short)l_591) < g_93) || 1L))) > 4294967295UL), g_119);
                    step_hash(277);
                    l_592 = (**g_545);
                }
                step_hash(279);
                (*l_558) = l_571;
            }
            else
            {
                unsigned char l_604 = 0x38L;
                step_hash(285);
                for (g_10 = 0; (g_10 < 11); g_10 += 5)
                {
                    unsigned char l_595 = 6UL;
                    step_hash(284);
                    (*l_571) &= func_47(l_595);
                }
                step_hash(293);
                if ((((((short)((((*l_571) && ((*l_589) | (((unsigned char)((g_10 & ((unsigned short)0x1C84L / (unsigned short)g_145)) <= func_59((**l_558), l_604, g_189)) >> (unsigned char)l_604) > g_283))) ^ g_400) || 0L) % (short)g_119) ^ 0x06E8FD16L) | g_590) & 6L))
                {
                    step_hash(287);
                    return l_604;
                }
                else
                {
                    int *l_605 = &g_10;
                    step_hash(289);
                    (*l_16) = (**l_558);
                    step_hash(290);
                    (*g_89) = (*g_89);
                    step_hash(291);
                    (**g_545) = l_605;
                    step_hash(292);
                    (*l_16) = ((unsigned short)(&l_589 == l_608) << (unsigned short)10);
                }
            }
            step_hash(295);
            (*l_589) = ((&l_571 == &l_589) <= ((signed char)(g_145 < (0xE1C449C1L <= (((unsigned short)(*l_589) << (unsigned short)5) | ((signed char)(*l_571) << (signed char)6)))) % (signed char)((unsigned char)(0xA6L && l_617) * (unsigned char)g_79)));
        }
        else
        {
            unsigned l_648 = 4294967289UL;
            int ***l_649 = &g_89;
            step_hash(297);
            (**g_507) = l_571;
            step_hash(332);
            if ((***g_507))
            {
                int **l_643 = &l_571;
                int l_682 = 0x9DA47F2AL;
                step_hash(313);
                for (g_79 = 0; (g_79 != (-11)); --g_79)
                {
                    unsigned l_630 = 4294967295UL;
                    step_hash(311);
                    if (func_19((*g_89), g_10, l_620))
                    {
                        int l_633 = 0xED1435DDL;
                        step_hash(303);
                        (**g_545) = (**g_545);
                        step_hash(304);
                        (*l_571) = ((signed char)((signed char)0x30L - (signed char)((&g_89 != (void*)0) < g_625)) % (signed char)((int)((unsigned char)(l_630 <= ((signed char)((*l_571) <= ((func_59(l_633, l_630, g_189) >= 0x2AL) == (***g_507))) + (signed char)0UL)) - (unsigned char)g_590) / (int)(***g_545)));
                        step_hash(305);
                        (***g_507) = ((l_634 != ((int)func_59((*l_571), g_590, (((+g_79) | (((int)(***g_545) % (int)(((***g_545) > (**g_89)) & ((**g_545) != (*g_89)))) != l_633)) & g_590)) + (int)0xD576A412L)) | g_189);
                    }
                    else
                    {
                        step_hash(307);
                        (***g_545) = (&g_89 == &g_89);
                        step_hash(308);
                        if ((***g_507))
                            continue;
                        step_hash(309);
                        (***g_507) = ((signed char)(l_643 != l_643) * (signed char)((unsigned char)l_630 << (unsigned char)1));
                        step_hash(310);
                        (**g_89) |= 0x8FDAC414L;
                    }
                    step_hash(312);
                    return g_400;
                }
                step_hash(314);
                (*g_89) = l_571;
                step_hash(328);
                if ((!(((unsigned short)(*l_571) >> (unsigned short)l_648) != (((((((l_649 != (void*)0) < (((((unsigned char)((signed char)((unsigned short)(**l_643) * (unsigned short)((~0L) || g_145)) >> (signed char)(+g_119)) * (unsigned char)((signed char)g_145 % (signed char)(-6L))) | 0x94C6A289L) | (*g_90)) > g_625)) & g_625) ^ 1L) < 0x73L) != g_189) <= (**l_643)))))
                {
                    step_hash(316);
                    (***g_507) = ((signed char)0xCFL >> (signed char)7);
                }
                else
                {
                    int *l_660 = &g_10;
                    step_hash(318);
                    (*g_545) = (*g_545);
                    step_hash(319);
                    (*g_89) = l_660;
                    step_hash(327);
                    if ((*l_620))
                    {
                        unsigned char l_669 = 0xA3L;
                        int l_670 = 3L;
                        step_hash(321);
                        l_670 |= func_19(l_660, ((short)((int)(func_59(g_145, g_119, (((signed char)((&l_571 != (void*)0) < g_119) << (signed char)(**l_643)) != ((unsigned short)(((**g_545) != (void*)0) != l_669) + (unsigned short)0UL))) <= 0x3891L) % (int)(**l_643)) << (short)5), (**l_649));
                        step_hash(322);
                        (**g_507) = (*l_643);
                        step_hash(323);
                        (*l_643) = func_23(l_670);
                        step_hash(324);
                        (*l_620) ^= (l_670 | ((void*)0 != &g_89));
                    }
                    else
                    {
                        step_hash(326);
                        return (*l_660);
                    }
                }
                step_hash(329);
                (*l_620) = ((short)l_648 - (short)(((signed char)l_675 - (signed char)g_93) <= (g_283 ^ ((unsigned char)(&g_89 == (void*)0) >> (unsigned char)((short)((unsigned char)(g_400 && (+(g_189 <= ((*l_16) < 1L)))) << (unsigned char)3) * (short)l_682)))));
            }
            else
            {
                int *l_683 = (void*)0;
                step_hash(331);
                (**g_545) = l_683;
            }
        }
        step_hash(334);
        return g_283;
    }
    step_hash(336);
    return g_119;
}
static int * func_5(int * p_6, unsigned short p_7, unsigned short p_8)
{
    unsigned char l_466 = 252UL;
    int ***l_506 = &g_89;
    short l_526 = (-1L);
    step_hash(238);
    for (g_10 = 8; (g_10 == 0); g_10 -= 2)
    {
        int **l_461 = &g_90;
        int l_475 = 1L;
        int l_523 = (-8L);
        short l_524 = 0xB19EL;
        int l_525 = 0x2E609269L;
        int **l_529 = (void*)0;
        int *l_531 = &g_79;
        step_hash(234);
        if (((p_6 != (void*)0) < ((void*)0 != l_461)))
        {
            unsigned short l_467 = 65528UL;
            int *l_468 = &g_79;
            step_hash(221);
            (*l_468) = ((unsigned)((g_119 == ((unsigned char)l_466 % (unsigned char)l_467)) | (*p_6)) - (unsigned)(*p_6));
            step_hash(222);
            (*l_468) = (((g_79 >= (((unsigned short)((int)(g_93 < (*l_468)) / (int)(l_466 ^ g_400)) << (unsigned short)(((func_59(g_400, p_7, (((unsigned)4294967291UL / (unsigned)(l_475 | p_7)) == (*l_468))) > 0xC4L) >= l_466) <= g_283)) || l_466)) & (*l_468)) <= (*p_6));
        }
        else
        {
            unsigned l_483 = 0x147374AFL;
            int *l_484 = &g_283;
            int *l_508 = &g_93;
            step_hash(231);
            for (g_283 = 0; (g_283 <= 12); g_283 += 8)
            {
                int *l_478 = (void*)0;
                int *l_479 = &g_93;
                int ***l_482 = &l_461;
                step_hash(227);
                (*l_479) |= (&g_89 != (void*)0);
                step_hash(228);
                (**l_482) = func_43(((unsigned char)l_466 << (unsigned char)(&p_6 == &g_90)), (l_482 != &g_89), l_483);
                step_hash(229);
                if ((*g_90))
                    break;
                step_hash(230);
                (*g_89) = l_484;
            }
            step_hash(232);
            (*l_508) |= (-(int)(((unsigned char)((short)0x2834L + (short)1L) * (unsigned char)((unsigned char)((((l_466 > (0xCB70L && (-6L))) <= p_8) != ((short)((unsigned char)p_7 / (unsigned char)func_59(((int)(((unsigned char)(((short)(*l_484) >> (short)func_47((~((short)((unsigned char)((l_506 == g_507) < p_8) * (unsigned char)(-5L)) + (short)p_8)))) <= g_119) * (unsigned char)p_8) >= (*g_9)) % (int)p_7), p_7, p_7)) << (short)14)) || 0L) + (unsigned char)p_8)) <= (-1L)));
            step_hash(233);
            (*l_508) = ((*p_6) > (p_8 == (l_466 & ((unsigned char)((unsigned)((unsigned)(((unsigned char)((0xBDL | (((short)((signed char)(+((int)(*g_9) - (int)(*p_6))) % (signed char)p_7) * (short)l_475) >= g_400)) >= l_523) / (unsigned char)p_7) ^ (-2L)) % (unsigned)0xDA1B7B4AL) * (unsigned)0L) >> (unsigned char)l_524))));
        }
        step_hash(235);
        l_525 = (!0x14E0A851L);
        step_hash(236);
        l_526 = ((void*)0 == (*g_507));
        step_hash(237);
        (*l_531) ^= (((unsigned char)(&p_6 == (*g_507)) >> (unsigned char)0) & ((((*g_507) != l_529) & (((*p_6) < (-(unsigned)((g_400 != ((!(&p_6 != (void*)0)) & (*p_6))) == 0xF3D36BC6L))) <= g_119)) <= g_93));
    }
    step_hash(239);
    return g_532;
}
static unsigned func_17(int p_18)
{
    short l_356 = 8L;
    int ***l_386 = &g_89;
    int ***l_401 = &g_89;
    unsigned char l_448 = 251UL;
    int *l_454 = (void*)0;
    int **l_455 = &l_454;
    int *l_456 = &g_10;
    int l_457 = 0xEE7F6989L;
    step_hash(212);
    for (g_119 = 0; (g_119 != 30); g_119 += 5)
    {
        unsigned short l_345 = 0xABD0L;
        int *l_353 = &g_79;
        int **l_422 = (void*)0;
        int l_435 = 0L;
        int *l_449 = &l_435;
        step_hash(202);
        for (p_18 = 0; (p_18 == 7); p_18 += 5)
        {
            int l_363 = 7L;
            unsigned l_364 = 0xBA7C4939L;
            int l_402 = 0xACBDA03CL;
            unsigned l_415 = 4294967287UL;
            short l_438 = (-4L);
            int *l_442 = &l_435;
        }
        step_hash(203);
        (*l_353) = (0x72L && 0x05L);
        step_hash(204);
        (*l_449) |= func_27(g_283, (-(int)(p_18 <= p_18)), (p_18 && func_59(((short)(func_27(((short)(1UL & 0x1428A198L) + (short)p_18), g_283, (*l_353), g_93) && 0UL) * (short)p_18), g_119, g_10)), l_448);
        step_hash(211);
        for (g_79 = 0; (g_79 >= 11); g_79 += 7)
        {
            int **l_452 = &g_90;
            unsigned short l_453 = 0x6B27L;
            step_hash(208);
            (*l_452) = &l_435;
            step_hash(209);
            if ((**g_89))
                break;
            step_hash(210);
            l_453 ^= (g_119 & p_18);
        }
    }
    step_hash(213);
    (*l_455) = l_454;
    step_hash(214);
    (*l_455) = func_43(g_79, p_18, func_19(l_456, p_18, &g_283));
    step_hash(215);
    return l_457;
}
static int func_19(int * p_20, unsigned p_21, int * p_22)
{
    unsigned short l_334 = 0xBC54L;
    step_hash(137);
    return l_334;
}
static int * func_23(unsigned short p_24)
{
    unsigned l_32 = 2UL;
    int *l_92 = &g_93;
    int **l_98 = &g_90;
    unsigned l_120 = 4294967289UL;
    short l_157 = 0x344DL;
    int *l_333 = &g_93;
    step_hash(35);
    (*l_92) |= ((func_27(l_32, (l_32 ^ ((int)((unsigned)(((unsigned short)(func_39(l_32, g_10, func_43(g_10, (*g_9), ((((~0x9FL) && p_24) > (func_47(g_10) == (-8L))) & g_10))) & 65531UL) + (unsigned short)l_32) || l_32) / (unsigned)l_32) - (int)p_24)), l_32, g_10) <= l_32) ^ p_24);
    step_hash(36);
    (*l_98) = func_43(g_93, ((1UL & g_93) >= (func_39(p_24, (0xDC7CBFABL || (func_39((((short)((short)p_24 << (short)13) >> (short)11) <= 252UL), g_79, l_92) & (*l_92))), l_92) >= (*l_92))), p_24);
    step_hash(134);
    if (p_24)
    {
        int *l_99 = (void*)0;
        int ***l_127 = &l_98;
        unsigned l_132 = 0x823F5DDDL;
        unsigned l_220 = 1UL;
        int l_227 = 0x16460FD5L;
        int ***l_266 = &l_98;
        unsigned l_267 = 0x445B51B4L;
        step_hash(38);
        (*l_98) = (*l_98);
        step_hash(49);
        if ((&l_92 != &l_92))
        {
            int ***l_104 = (void*)0;
            int l_107 = 1L;
            step_hash(40);
            (*l_98) = l_99;
            step_hash(45);
            for (g_79 = 0; (g_79 < 17); g_79 += 1)
            {
                step_hash(44);
                return (*g_89);
            }
            step_hash(46);
            (*l_92) = ((unsigned char)((l_104 == l_104) | ((signed char)l_107 >> (signed char)7)) * (unsigned char)func_27(g_79, (*l_92), (*l_92), func_59(g_79, ((unsigned short)((((g_79 <= (func_39(((unsigned)((unsigned char)(+l_107) >> (unsigned char)p_24) / (unsigned)p_24), (*l_92), (*l_98)) <= g_79)) <= p_24) || p_24) || (*l_92)) * (unsigned short)0xF9AEL), p_24)));
        }
        else
        {
            int ***l_116 = &g_89;
            step_hash(48);
            (*l_92) = func_47(((func_27(func_47((1UL || 0x104D70CCL)), g_10, ((unsigned char)((((**l_98) > (l_116 != &g_89)) <= (((unsigned short)(func_39(((p_24 >= (g_119 | 0x66L)) > (***l_116)), g_10, l_99) < g_93) - (unsigned short)g_10) >= g_93)) >= 0xBAF6L) / (unsigned char)p_24), l_120) && g_79) ^ p_24));
        }
        step_hash(50);
        (*l_98) = &g_10;
        step_hash(97);
        if (func_59((p_24 != (((+((unsigned short)(((short)g_79 / (short)(g_79 || p_24)) < ((-1L) >= func_39(((g_119 > p_24) == ((void*)0 != &g_89)), p_24, (*g_89)))) >> (unsigned short)15)) || (**g_89)) != p_24)), (**l_98), p_24))
        {
            int l_146 = (-5L);
            step_hash(52);
            l_132 &= ((((int)(g_10 == 0xB236L) - (int)(0x6C36115CL > (0x330FL >= (l_127 == (void*)0)))) == (((unsigned short)g_93 / (unsigned short)(+((unsigned char)p_24 * (unsigned char)func_39(((*l_92) < 0L), g_79, (**l_127))))) > (**l_98))) > (*g_90));
            step_hash(53);
            (*l_98) = func_43(p_24, (func_47(g_93) | g_119), (func_59(p_24, ((unsigned char)p_24 * (unsigned char)((signed char)((unsigned short)(((unsigned short)((short)0L * (short)1UL) % (unsigned short)((unsigned char)((!(func_59(g_119, g_145, p_24) || l_146)) < p_24) * (unsigned char)g_10)) <= (-5L)) >> (unsigned short)g_10) % (signed char)p_24)), p_24) >= 0xFE4BL));
        }
        else
        {
            unsigned l_150 = 1UL;
            int ***l_160 = &l_98;
            int *l_273 = &g_79;
            step_hash(94);
            if ((-(short)((unsigned char)(func_39((l_150 < ((g_119 && (((unsigned short)0x619BL >> (unsigned short)9) < ((signed char)p_24 + (signed char)((signed char)l_157 << (signed char)2)))) < (((signed char)(l_160 == l_127) * (signed char)(-3L)) < ((((unsigned short)((signed char)((signed char)p_24 * (signed char)p_24) - (signed char)(-1L)) / (unsigned short)2L) ^ 0x80L) < g_79)))), g_79, (**l_160)) ^ (*l_92)) % (unsigned char)p_24)))
            {
                int l_179 = (-2L);
                int *l_204 = &g_79;
                int ***l_212 = &g_89;
                step_hash(74);
                if (((unsigned char)((unsigned short)((short)func_27(((((short)(&l_98 == (void*)0) + (short)(((unsigned char)(!p_24) >> (unsigned char)5) & ((void*)0 == &g_9))) & ((void*)0 != (**l_127))) && l_179), (-(int)(((unsigned)p_24 / (unsigned)g_119) ^ g_79)), l_179, g_119) * (short)(-3L)) * (unsigned short)0x7E8BL) << (unsigned char)7))
                {
                    int *l_185 = &g_79;
                    step_hash(66);
                    if ((((((&g_90 != &g_90) > p_24) & ((func_59(((g_145 ^ (p_24 > (func_39(g_145, g_10, l_185) <= 0x71L))) | p_24), g_145, p_24) | p_24) | (*l_92))) > p_24) && l_179))
                    {
                        int *l_186 = &g_79;
                        step_hash(58);
                        (*l_92) ^= func_39(g_10, ((*l_160) == &g_90), l_186);
                        step_hash(59);
                        (*l_186) = (((short)func_39(p_24, g_189, l_185) + (short)(p_24 ^ ((unsigned char)((g_189 <= func_47(p_24)) == 0x145BL) + (unsigned char)1UL))) == p_24);
                        step_hash(60);
                        (*l_185) = ((signed char)func_59(((signed char)((unsigned char)(*l_92) + (unsigned char)((-7L) < ((short)((unsigned)(((short)(l_204 != l_99) % (short)(~g_145)) <= (~g_119)) - (unsigned)((void*)0 != &l_186)) << (short)((unsigned char)1UL >> (unsigned char)g_119)))) << (signed char)g_10), g_119, p_24) + (signed char)0x0DL);
                        step_hash(61);
                        (**l_160) = l_204;
                    }
                    else
                    {
                        int *l_208 = &g_93;
                        step_hash(63);
                        (*l_204) |= (-(int)p_24);
                        step_hash(64);
                        (*l_92) = p_24;
                        step_hash(65);
                        return l_208;
                    }
                }
                else
                {
                    int *l_211 = (void*)0;
                    step_hash(72);
                    for (g_145 = (-15); (g_145 <= 20); g_145 += 1)
                    {
                        step_hash(71);
                        (**l_127) = l_211;
                    }
                    step_hash(73);
                    return &g_79;
                }
                step_hash(75);
                (**l_160) = func_43((l_212 == &g_89), func_27(func_59((func_59(g_189, (((func_59(p_24, g_10, g_189) & 1L) != ((p_24 || 0x27L) > 0x114BL)) != (***l_160)), g_189) <= 0x66L), g_93, (***l_212)), g_10, (*g_90), (***l_160)), g_93);
                step_hash(91);
                if ((**g_89))
                {
                    unsigned char l_215 = 1UL;
                    int l_228 = 0xEB5C81F1L;
                    short l_241 = 0L;
                    step_hash(77);
                    (**l_127) = (*g_89);
                    step_hash(78);
                    l_228 = (g_119 & func_27(l_215, ((unsigned)((***l_212) >= p_24) - (unsigned)((unsigned)(~l_220) / (unsigned)((int)(!(((((signed char)p_24 % (signed char)func_59(((unsigned short)g_119 * (unsigned short)g_119), (g_79 >= 4294967290UL), p_24)) >= l_215) || l_227) != g_189)) - (int)p_24))), (*g_9), (***l_212)));
                    step_hash(79);
                    (**l_127) = &l_228;
                    step_hash(80);
                    (*l_92) |= func_59(((unsigned char)l_215 >> (unsigned char)(0xD56DL <= p_24)), ((signed char)(1UL <= func_39(g_79, ((((unsigned char)((unsigned)(((short)((short)0x4598L - (short)g_189) * (short)1UL) && 0xFABAL) + (unsigned)l_241) * (unsigned char)g_145) && 1L) < p_24), (**l_212))) * (signed char)(**l_98)), p_24);
                }
                else
                {
                    unsigned short l_255 = 65535UL;
                    step_hash(88);
                    if (func_59(((**l_127) != (*g_89)), g_93, p_24))
                    {
                        int *l_254 = (void*)0;
                        step_hash(83);
                        g_93 = (((unsigned short)((signed char)(&g_89 == (void*)0) >> (signed char)7) - (unsigned short)(((unsigned)((248UL ^ (((unsigned short)0xEC67L >> (unsigned short)8) != g_189)) & ((**l_160) == (void*)0)) - (unsigned)((((p_24 | (((signed char)((l_254 != (**l_160)) && 6L) / (signed char)0xF8L) > (***l_127))) < 0x05L) > g_10) != l_255)) < g_93)) < g_10);
                        step_hash(84);
                        (*l_98) = (**l_160);
                    }
                    else
                    {
                        int **l_270 = &g_90;
                        step_hash(86);
                        (*l_92) |= ((func_47(p_24) || ((short)(p_24 > func_59(func_59(p_24, (**l_98), ((short)g_145 - (short)((unsigned char)((p_24 || g_119) != ((((unsigned char)((int)((l_266 == l_266) != p_24) + (int)(*g_9)) - (unsigned char)g_145) && l_267) || g_10)) / (unsigned char)p_24))), l_255, p_24)) * (short)0xBDFAL)) == (***l_212));
                        step_hash(87);
                        (*l_92) = ((unsigned short)((*l_266) != (*l_266)) * (unsigned short)(l_270 != &g_90));
                    }
                    step_hash(89);
                    (*l_92) = ((signed char)((p_24 ^ 0x6BE60168L) < (g_189 | (&g_89 == &g_89))) / (signed char)0xE0L);
                    step_hash(90);
                    (*l_273) = func_47((l_273 != (**l_266)));
                }
            }
            else
            {
                signed char l_274 = 0x76L;
                step_hash(93);
                (**l_127) = func_43(l_274, func_47((*l_92)), g_10);
            }
            step_hash(95);
            (*l_273) = (func_27(func_27((p_24 ^ ((unsigned short)1UL * (unsigned short)(((short)(-1L) * (short)p_24) < (*l_273)))), p_24, p_24, (((unsigned char)((unsigned char)((*l_92) > func_39(p_24, g_119, &g_93)) * (unsigned char)g_189) << (unsigned char)3) | g_145)), p_24, p_24, g_10) == 0xE1D1L);
            step_hash(96);
            (*l_92) ^= g_283;
        }
    }
    else
    {
        unsigned char l_292 = 1UL;
        signed char l_295 = (-1L);
        int l_300 = (-1L);
        int **l_304 = &l_92;
        step_hash(99);
        (*l_92) = ((int)((unsigned short)(!((unsigned short)func_47(g_10) - (unsigned short)((((unsigned short)l_292 >> (unsigned short)func_59(((short)0xCD33L << (short)4), g_283, l_295)) | p_24) | g_93))) << (unsigned short)l_295) / (int)5UL);
        step_hash(109);
        for (g_119 = 0; (g_119 >= 2); ++g_119)
        {
            int *l_301 = &g_79;
            step_hash(107);
            for (g_93 = 0; (g_93 > (-17)); --g_93)
            {
                step_hash(106);
                l_300 |= (**l_98);
            }
            step_hash(108);
            return l_301;
        }
        step_hash(132);
        for (g_79 = 0; (g_79 > (-11)); g_79 -= 6)
        {
            short l_315 = 0x1D8DL;
            short l_331 = 0xF066L;
        }
        step_hash(133);
        (*l_98) = (void*)0;
    }
    step_hash(135);
    return l_333;
}
static int func_27(unsigned p_28, signed char p_29, int p_30, unsigned p_31)
{
    unsigned l_84 = 4UL;
    int **l_86 = &g_9;
    int **l_91 = &g_90;
    step_hash(23);
    l_84 = (*g_9);
    step_hash(31);
    if (l_84)
    {
        int *l_85 = &g_79;
        int ***l_87 = &l_86;
        int *l_88 = &g_79;
        step_hash(25);
        (*l_85) = l_84;
        step_hash(26);
        (*l_87) = l_86;
        step_hash(27);
        l_88 = (*l_86);
        step_hash(28);
        (*l_85) &= p_31;
    }
    else
    {
        step_hash(30);
        g_89 = l_86;
    }
    step_hash(32);
    (*l_91) = func_43(p_30, p_30, (**l_86));
    step_hash(33);
    (*l_91) = &p_30;
    step_hash(34);
    return (**l_86);
}
static unsigned short func_39(unsigned p_40, unsigned p_41, int * p_42)
{
    signed char l_83 = 0L;
    step_hash(20);
    l_83 ^= (*g_9);
    step_hash(21);
    return p_40;
}
static int * func_43(unsigned p_44, int p_45, short p_46)
{
    int *l_80 = (void*)0;
    int **l_81 = &l_80;
    int *l_82 = &g_79;
    step_hash(15);
    (*l_81) = l_80;
    step_hash(16);
    (*l_81) = &p_45;
    step_hash(17);
    (*l_82) ^= (p_45 || (*l_80));
    step_hash(18);
    return &g_10;
}
static unsigned short func_47(unsigned char p_48)
{
    unsigned short l_63 = 0x5297L;
    int l_66 = 0x9B5CEC81L;
    int *l_67 = (void*)0;
    int *l_68 = &l_66;
    unsigned l_77 = 0x3BFA4ACFL;
    int *l_78 = &g_79;
    step_hash(10);
    l_66 = ((((unsigned short)g_10 << (unsigned short)((unsigned short)((unsigned char)(((short)((unsigned short)(0xA6DFE160L < (((void*)0 == &g_10) & func_59(g_10, l_63, g_10))) / (unsigned short)p_48) * (short)0x785EL) <= 248UL) >> (unsigned char)4) - (unsigned short)l_66)) & g_10) <= p_48);
    step_hash(11);
    (*l_68) &= (l_68 == &l_66);
    step_hash(12);
    (*l_78) &= (p_48 < ((unsigned)(*l_68) + (unsigned)(((p_48 > ((&l_68 != (void*)0) != ((*g_9) ^ func_59(((unsigned short)((signed char)(*l_68) * (signed char)(((short)(-1L) - (short)func_59((func_59(g_10, p_48, p_48) && l_77), p_48, p_48)) && p_48)) * (unsigned short)p_48), p_48, g_10)))) > 0x10L) | g_10)));
    step_hash(13);
    return p_48;
}
static unsigned short func_59(unsigned short p_60, signed char p_61, signed char p_62)
{
    int *l_64 = &g_10;
    int **l_65 = &l_64;
    step_hash(8);
    (*l_65) = l_64;
    step_hash(9);
    return p_61;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_10, "g_10", print_hash_value);
    transparent_crc(g_79, "g_79", print_hash_value);
    transparent_crc(g_93, "g_93", print_hash_value);
    transparent_crc(g_119, "g_119", print_hash_value);
    transparent_crc(g_145, "g_145", print_hash_value);
    transparent_crc(g_189, "g_189", print_hash_value);
    transparent_crc(g_283, "g_283", print_hash_value);
    transparent_crc(g_400, "g_400", print_hash_value);
    transparent_crc(g_590, "g_590", print_hash_value);
    transparent_crc(g_625, "g_625", print_hash_value);
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
