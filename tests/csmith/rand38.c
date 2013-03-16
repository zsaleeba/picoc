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
static short g_2 = 0xD8C4L;
static int g_17 = 9L;
static int g_19 = 0L;
static int g_29 = 0xFB8EB5EAL;
static int g_46 = 0xE22955D4L;
static int g_104 = 1L;
static int *g_120 = &g_19;
static int g_157 = (-6L);
static int **g_163 = &g_120;
static int ***g_162 = &g_163;
static int g_400 = 0xCC20AF46L;
static unsigned short g_455 = 0x7FD7L;
static int func_1(void);
static unsigned func_3(unsigned short p_4, int p_5, int p_6, short p_7, int p_8);
static signed char func_14(int p_15);
static unsigned char func_30(int * p_31, int * p_32, int * p_33);
static int func_34(int * p_35);
static unsigned char func_51(int * p_52, short p_53);
static int * func_54(int p_55);
static int func_58(int p_59, unsigned short p_60, short p_61, unsigned char p_62);
static unsigned func_63(unsigned short p_64);
static unsigned func_68(unsigned p_69, int p_70);
static int func_1(void)
{
    int l_9 = 0xB023ED15L;
    step_hash(324);
    if ((g_2 ^ func_3(l_9, g_2, ((unsigned char)((unsigned char)0xCCL + (unsigned char)func_14(g_2)) >> (unsigned char)1), ((void*)0 == &l_9), g_2)))
    {
        unsigned l_505 = 4294967287UL;
        int *l_506 = &g_157;
        int l_509 = 0x0705C01AL;
        step_hash(318);
        (**g_162) = (void*)0;
        step_hash(319);
        (*l_506) = l_505;
        step_hash(320);
        (*l_506) ^= (((int)l_509 + (int)l_9) && ((void*)0 != &l_9));
        step_hash(321);
        return g_29;
    }
    else
    {
        step_hash(323);
        return l_9;
    }
}
static unsigned func_3(unsigned short p_4, int p_5, int p_6, short p_7, int p_8)
{
    int *l_18 = &g_19;
    step_hash(5);
    (*l_18) &= func_14(g_2);
    step_hash(6);
    (*l_18) |= g_2;
    step_hash(315);
    for (p_7 = 0; (p_7 < (-7)); p_7--)
    {
        int *l_24 = &g_17;
    }
    step_hash(316);
    return g_455;
}
static signed char func_14(int p_15)
{
    int *l_16 = &g_17;
    step_hash(2);
    (*l_16) = g_2;
    step_hash(3);
    return p_15;
}
static unsigned char func_30(int * p_31, int * p_32, int * p_33)
{
    int *l_421 = &g_19;
    int **l_422 = &g_120;
    int l_476 = 8L;
    step_hash(262);
    (*p_33) = func_34(p_32);
    step_hash(263);
    (*l_422) = l_421;
    step_hash(299);
    if ((*g_120))
    {
        unsigned l_425 = 0x73403350L;
        short l_426 = 1L;
        int *l_433 = &g_19;
        step_hash(265);
        (*l_422) = (void*)0;
        step_hash(296);
        for (g_46 = (-7); (g_46 > 22); ++g_46)
        {
            step_hash(295);
            if (((((*l_422) == (void*)0) && g_2) && (l_425 <= g_46)))
            {
                short l_438 = 0x5082L;
                step_hash(286);
                if ((((((signed char)g_157 << (signed char)7) ^ (!((unsigned short)((0xE2219880L & (0xFACAL ^ (&l_421 == (*g_162)))) && 255UL) >> (unsigned short)(p_31 != l_433)))) <= ((unsigned short)((short)g_400 - (short)g_400) + (unsigned short)3L)) != (-1L)))
                {
                    step_hash(271);
                    (*p_33) ^= l_438;
                }
                else
                {
                    short l_443 = 0x710CL;
                    int *l_467 = &g_19;
                    step_hash(279);
                    if ((*p_33))
                    {
                        int *l_454 = (void*)0;
                        int *l_456 = (void*)0;
                        int *l_457 = &g_157;
                        step_hash(274);
                        (*l_457) |= (0xA3F8L < ((unsigned char)(((unsigned)l_443 + (unsigned)((signed char)(((unsigned short)(((short)((unsigned short)(*l_421) * (unsigned short)g_2) % (short)(*l_433)) <= g_104) << (unsigned short)(*l_433)) > (*l_421)) << (signed char)2)) == l_438) >> (unsigned char)7));
                    }
                    else
                    {
                        int l_460 = 0L;
                        step_hash(276);
                        (*l_433) = ((signed char)func_68(l_460, (((((*l_421) != (*l_433)) && (0x193AL ^ g_29)) < 0x03B8L) <= ((l_438 > (((unsigned char)((signed char)g_2 >> (signed char)3) >> (unsigned char)6) >= ((0x9FCC4D1DL | (*p_32)) <= (-1L)))) <= (*p_32)))) + (signed char)255UL);
                        step_hash(277);
                        (*l_422) = l_467;
                        step_hash(278);
                        (*l_467) = func_68((((signed char)g_46 - (signed char)l_460) > ((unsigned char)2UL + (unsigned char)0xA2L)), g_157);
                    }
                    step_hash(280);
                    if ((*p_32))
                        break;
                    step_hash(285);
                    for (g_104 = 4; (g_104 >= (-18)); g_104 -= 9)
                    {
                        step_hash(284);
                        (*l_467) = (*p_32);
                    }
                }
                step_hash(287);
                (*p_32) = 1L;
                step_hash(288);
                return (*l_433);
            }
            else
            {
                step_hash(294);
                for (g_400 = (-1); (g_400 <= (-25)); g_400 -= 1)
                {
                    step_hash(293);
                    (*l_422) = l_433;
                }
            }
        }
    }
    else
    {
        step_hash(298);
        (*l_422) = p_32;
    }
    step_hash(300);
    l_476 &= (*l_421);
    step_hash(301);
    return (*l_421);
}
static int func_34(int * p_35)
{
    unsigned l_40 = 1UL;
    int *l_45 = &g_46;
    int **l_420 = &l_45;
    step_hash(13);
    (*l_45) |= ((unsigned char)(((signed char)(0x29L ^ (l_40 == ((signed char)l_40 % (signed char)((g_2 ^ 0xE7L) & g_19)))) + (signed char)0L) == (((unsigned short)l_40 << (unsigned short)11) ^ 4294967295UL)) * (unsigned char)l_40);
    step_hash(258);
    (*l_45) = ((signed char)((*l_45) >= (((signed char)(l_45 != &g_46) * (signed char)((*l_45) > 0x38L)) >= (func_51(func_54(((*l_45) < ((unsigned short)g_2 * (unsigned short)(l_45 != (void*)0)))), (*l_45)) | (*l_45)))) / (signed char)(*l_45));
    step_hash(259);
    (*l_420) = l_45;
    step_hash(260);
    (*p_35) = (*p_35);
    step_hash(261);
    return (*l_45);
}
static unsigned char func_51(int * p_52, short p_53)
{
    int l_412 = 9L;
    int l_419 = 0L;
    step_hash(256);
    (*p_52) = (((unsigned short)((unsigned short)g_2 + (unsigned short)g_104) >> (unsigned short)((*p_52) | (g_29 ^ (((signed char)(0x799D50B9L > ((unsigned)g_2 - (unsigned)((unsigned char)g_2 << (unsigned char)l_412))) >> (signed char)3) & ((((unsigned short)((unsigned short)(func_68((!((unsigned char)p_53 >> (unsigned char)3)), g_29) ^ g_400) + (unsigned short)p_53) - (unsigned short)l_419) & l_412) && (*p_52)))))) > 0xE00FFC98L);
    step_hash(257);
    return l_419;
}
static int * func_54(int p_55)
{
    int l_67 = 0x83830386L;
    int *l_399 = &g_400;
    int *l_401 = &l_67;
    step_hash(253);
    (*l_399) ^= func_58(p_55, p_55, (0UL && func_63(((signed char)(0x1773L != (l_67 != (((l_67 ^ func_68(p_55, ((g_19 || l_67) <= g_19))) == l_67) ^ p_55))) >> (signed char)g_29))), g_29);
    step_hash(254);
    return &g_157;
}
static int func_58(int p_59, unsigned short p_60, short p_61, unsigned char p_62)
{
    unsigned l_236 = 4294967292UL;
    int *l_248 = &g_46;
    int ***l_275 = &g_163;
    short l_325 = 0L;
    unsigned short l_341 = 0UL;
    short l_382 = 0x6704L;
    unsigned l_397 = 4294967289UL;
    signed char l_398 = 0x04L;
    step_hash(246);
    if (((short)(!((void*)0 == &g_163)) >> (short)((signed char)((signed char)g_29 >> (signed char)3) + (signed char)((unsigned char)(!9UL) * (unsigned char)(p_60 < p_60)))))
    {
        int l_229 = 1L;
        int *l_237 = &g_19;
        int ***l_312 = &g_163;
        int *l_345 = &g_46;
        unsigned l_348 = 4294967288UL;
        signed char l_393 = 7L;
        step_hash(150);
        (*g_163) = (void*)0;
        step_hash(151);
        (*l_237) = (((g_19 > l_229) && ((int)(p_60 <= (0xC4L | ((short)((g_46 == ((signed char)3L << (signed char)4)) && l_236) >> (short)3))) - (int)g_157)) <= p_62);
        step_hash(241);
        if (p_59)
        {
            unsigned l_242 = 0x01F52533L;
            int l_243 = 0xDCEFBE5DL;
            int l_274 = 0x55B6F9C3L;
            unsigned l_324 = 0x219075D6L;
            int l_334 = 0xAC1F8926L;
            step_hash(190);
            if ((l_236 <= (p_61 <= ((short)p_59 % (short)((short)((-3L) <= (l_242 == (p_60 > (g_29 >= l_243)))) + (short)((short)g_157 << (short)(*l_237)))))))
            {
                int *l_257 = &l_243;
                step_hash(165);
                if (((signed char)((void*)0 == l_248) << (signed char)4))
                {
                    int l_270 = 0xFEA6540CL;
                    step_hash(161);
                    if (((unsigned char)(g_157 > func_68(((((short)(-4L) % (short)(-8L)) > p_61) & (p_60 && ((unsigned short)((short)func_68(l_242, g_2) * (short)p_60) / (unsigned short)0xC439L))), p_62)) << (unsigned char)5))
                    {
                        step_hash(156);
                        l_257 = (void*)0;
                    }
                    else
                    {
                        step_hash(158);
                        l_270 = (p_60 > ((unsigned short)((unsigned)((0xA791L || (0xC4C37C85L <= ((*l_248) == (((short)((signed char)((short)((0x36B34544L != p_60) && ((void*)0 != l_237)) << (short)p_61) >> (signed char)g_19) >> (short)g_104) < 65535UL)))) <= g_157) - (unsigned)l_242) % (unsigned short)0x6309L));
                        step_hash(159);
                        (**g_162) = (**g_162);
                        step_hash(160);
                        (*g_163) = (void*)0;
                    }
                    step_hash(162);
                    l_243 &= (0xC2L < 0xEEL);
                }
                else
                {
                    short l_271 = 1L;
                    step_hash(164);
                    (*l_257) = func_68(l_271, ((void*)0 != (*g_162)));
                }
                step_hash(166);
                (*g_163) = &p_59;
            }
            else
            {
                short l_304 = 1L;
                unsigned l_311 = 1UL;
                unsigned char l_329 = 2UL;
                step_hash(187);
                if ((((unsigned short)func_68(g_19, l_274) + (unsigned short)(l_242 > ((void*)0 == l_275))) || ((-(signed char)((unsigned short)((unsigned char)(-(short)(func_68((*l_248), (((*l_248) | ((&p_59 != &p_59) != g_46)) ^ g_19)) & p_59)) >> (unsigned char)0) * (unsigned short)(*l_248))) > g_29)))
                {
                    short l_290 = 5L;
                    step_hash(169);
                    (**g_162) = &l_243;
                    step_hash(177);
                    if (func_63(g_19))
                    {
                        unsigned l_286 = 0xC75E0464L;
                        int **l_287 = &l_237;
                        step_hash(171);
                        (**g_162) = (*g_163);
                        step_hash(172);
                        (*l_237) = ((signed char)0L / (signed char)(g_29 || (((signed char)((((((-1L) ^ (g_104 & g_29)) > func_68(l_286, ((*l_275) == l_287))) | 0L) != 0x9F7B5380L) ^ 0xABL) << (signed char)7) && l_274)));
                    }
                    else
                    {
                        signed char l_303 = 0xCFL;
                        step_hash(174);
                        (*l_237) = ((unsigned)(l_290 & (l_290 >= g_157)) + (unsigned)0L);
                        step_hash(175);
                        p_59 &= (((short)(g_2 & (((short)0x04D9L * (short)l_243) >= ((signed char)(*l_237) * (signed char)0L))) >> (short)l_311) && (((void*)0 != l_312) && l_304));
                        step_hash(176);
                        (**l_312) = &p_59;
                    }
                    step_hash(182);
                    for (g_157 = (-1); (g_157 < 19); ++g_157)
                    {
                        step_hash(181);
                        return p_59;
                    }
                }
                else
                {
                    unsigned l_323 = 4294967288UL;
                    step_hash(184);
                    (**l_275) = (**l_275);
                    step_hash(185);
                    (**g_162) = (*g_163);
                    step_hash(186);
                    (*l_237) = ((!(*l_237)) | p_60);
                }
                step_hash(188);
                l_334 ^= (((unsigned char)(g_2 ^ (-6L)) - (unsigned char)(((g_104 < (l_312 == &g_163)) & ((unsigned char)0xCFL << (unsigned char)(l_243 ^ (-1L)))) & (((((0x2F378EE9L <= g_2) >= p_60) < g_157) != 0xCD65DFEDL) || p_61))) < p_59);
                step_hash(189);
                (**l_312) = (*g_163);
            }
            step_hash(197);
            for (g_104 = 0; (g_104 == (-19)); g_104--)
            {
                step_hash(194);
                (*l_237) ^= (p_61 < 4294967295UL);
                step_hash(195);
                (*l_237) = (&g_163 != l_312);
                step_hash(196);
                if ((*l_237))
                    break;
            }
            step_hash(198);
            (*l_237) = (((signed char)p_59 - (signed char)p_59) != ((short)(g_29 || l_341) - (short)g_19));
            step_hash(199);
            l_334 ^= (l_312 != (void*)0);
        }
        else
        {
            int l_344 = 0x36BC50D1L;
            int **l_371 = &g_120;
            step_hash(201);
            (*l_237) = (*l_248);
            step_hash(202);
            (**l_312) = &p_59;
            step_hash(239);
            if ((((((unsigned char)func_68(((0xB46EA5D3L <= func_63(l_344)) >= (8L | (l_248 == l_345))), g_29) >> (unsigned char)((unsigned char)p_60 * (unsigned char)0UL)) != l_348) & p_60) | g_29))
            {
                int *l_364 = &g_104;
                step_hash(216);
                for (g_19 = (-25); (g_19 != 22); g_19++)
                {
                    short l_363 = 0x0BF7L;
                    step_hash(207);
                    p_59 = 0x9EE725D3L;
                    step_hash(214);
                    for (p_59 = 27; (p_59 <= (-7)); --p_59)
                    {
                        step_hash(211);
                        g_104 &= (0x491A405FL > (((((unsigned short)((unsigned short)((65526UL || p_60) == (p_62 >= ((signed char)g_157 + (signed char)p_60))) * (unsigned short)0x66BBL) / (unsigned short)((unsigned char)0x32L / (unsigned char)((unsigned char)0x34L * (unsigned char)l_363))) & g_2) <= 1L) ^ 0xA7A2C9F2L));
                        step_hash(212);
                        if (l_344)
                            break;
                        step_hash(213);
                        (**l_275) = l_364;
                    }
                    step_hash(215);
                    (*l_364) ^= (p_62 != (l_344 != ((unsigned char)0x46L + (unsigned char)(*l_248))));
                }
            }
            else
            {
                int **l_372 = &g_120;
                step_hash(237);
                if ((((int)((unsigned char)(~((func_68((l_371 != l_372), func_68((*l_248), p_62)) > ((((unsigned short)(((void*)0 != (*g_163)) ^ p_62) / (unsigned short)3UL) == (*l_248)) != p_62)) > p_60)) >> (unsigned char)1) - (int)g_46) ^ p_59))
                {
                    step_hash(219);
                    return p_59;
                }
                else
                {
                    int l_377 = (-9L);
                    step_hash(225);
                    for (l_236 = 13; (l_236 == 37); ++l_236)
                    {
                        step_hash(224);
                        (*l_275) = (void*)0;
                    }
                    step_hash(231);
                    if (p_59)
                    {
                        step_hash(227);
                        p_59 &= (0x37BDL ^ l_377);
                        step_hash(228);
                        (*l_237) = p_62;
                    }
                    else
                    {
                        step_hash(230);
                        (*l_372) = &p_59;
                    }
                    step_hash(236);
                    for (l_341 = 19; (l_341 == 60); l_341 += 9)
                    {
                        step_hash(235);
                        (*l_237) ^= ((unsigned char)l_382 << (unsigned char)1);
                    }
                }
                step_hash(238);
                (*l_237) ^= p_61;
            }
            step_hash(240);
            (*l_237) &= (!((short)(((short)g_29 / (short)(-1L)) & (((p_59 ^ (l_371 == l_371)) && p_61) || (*l_248))) - (short)((void*)0 == &g_163)));
        }
        step_hash(242);
        p_59 ^= ((g_19 & ((*l_345) || (&g_163 != (void*)0))) <= (g_29 ^ (((unsigned)(((((short)(+(p_62 <= ((*l_237) && ((short)g_104 * (short)g_29)))) * (short)g_46) || g_2) != p_62) & g_29) % (unsigned)l_393) & (*l_237))));
    }
    else
    {
        int *l_394 = &g_104;
        step_hash(244);
        (*g_163) = l_394;
        step_hash(245);
        (**l_275) = (**g_162);
    }
    step_hash(251);
    for (l_325 = 0; (l_325 < 0); l_325 += 2)
    {
        step_hash(250);
        return l_397;
    }
    step_hash(252);
    return l_398;
}
static unsigned func_63(unsigned short p_64)
{
    int l_82 = 0x3B667D15L;
    int *l_90 = &g_46;
    int **l_89 = &l_90;
    int l_172 = 1L;
    signed char l_191 = 0xF4L;
    int *l_220 = &g_157;
    step_hash(144);
    if (p_64)
    {
        int *l_88 = &g_46;
        int **l_87 = &l_88;
        int ***l_156 = &l_87;
        step_hash(89);
        if (p_64)
        {
            int *l_91 = &g_19;
            int *l_121 = &g_104;
            step_hash(29);
            (*l_91) = ((unsigned char)(l_82 != ((g_29 | ((int)(p_64 <= g_2) - (int)(p_64 & 6L))) != 0x81945549L)) + (unsigned char)(1L & (((int)(l_87 == l_89) - (int)(*l_90)) ^ 4UL)));
            step_hash(74);
            for (p_64 = 28; (p_64 != 35); p_64 += 4)
            {
                int *l_97 = (void*)0;
                int *l_107 = &g_104;
            }
            step_hash(85);
            for (p_64 = 0; (p_64 == 16); p_64++)
            {
                step_hash(78);
                (*l_89) = &g_46;
                step_hash(83);
                for (g_104 = (-2); (g_104 > (-9)); g_104 -= 8)
                {
                    signed char l_142 = 0x13L;
                    step_hash(82);
                    return l_142;
                }
                step_hash(84);
                (*l_121) = ((((signed char)((unsigned short)((*g_120) && 0L) << (unsigned short)p_64) * (signed char)((*l_87) == (void*)0)) != ((*l_121) == p_64)) > g_29);
            }
            step_hash(86);
            (*l_121) = (*l_91);
        }
        else
        {
            unsigned l_151 = 0UL;
            step_hash(88);
            (*g_120) = (((unsigned char)func_68(g_29, p_64) << (unsigned char)((((signed char)((l_151 ^ (0xD196261EL == g_104)) < (**l_89)) >> (signed char)((int)p_64 / (int)g_46)) | 0UL) >= g_46)) & (-6L));
        }
        step_hash(90);
        (*g_120) = 0x92F5982EL;
        step_hash(91);
        (*g_120) = func_68(((p_64 == ((short)(((l_156 == &l_89) > (p_64 || func_68(g_29, g_157))) < (0xCE3F75E0L != (*l_88))) << (short)g_2)) | p_64), p_64);
        step_hash(92);
        (*g_120) = (((short)(((((signed char)g_104 * (signed char)func_68((***l_156), (*l_90))) >= (&l_89 == g_162)) != (*l_88)) || ((unsigned)((signed char)((unsigned short)((*l_90) ^ g_104) * (unsigned short)(*l_88)) - (signed char)p_64) + (unsigned)(***g_162))) % (short)0xFDADL) < g_29);
    }
    else
    {
        unsigned l_171 = 2UL;
        int *l_175 = &l_172;
        int **l_198 = &g_120;
        step_hash(143);
        if ((**l_89))
        {
            int *l_170 = &g_19;
            step_hash(95);
            l_171 ^= (((*g_162) != (*g_162)) >= ((void*)0 != l_170));
            step_hash(96);
            (*l_170) &= p_64;
            step_hash(97);
            (*l_89) = l_170;
            step_hash(98);
            l_172 &= (p_64 & (*l_170));
        }
        else
        {
            int l_182 = 1L;
            int *l_210 = &l_182;
            step_hash(100);
            (**g_163) = l_171;
            step_hash(142);
            if ((**g_163))
            {
                int l_183 = 5L;
                int *l_211 = (void*)0;
                step_hash(107);
                for (g_19 = 27; (g_19 == (-24)); --g_19)
                {
                    step_hash(105);
                    (*l_89) = l_175;
                    step_hash(106);
                    if ((*l_90))
                        continue;
                }
                step_hash(122);
                for (l_171 = (-20); (l_171 >= 22); l_171 += 1)
                {
                    step_hash(115);
                    for (l_82 = (-30); (l_82 < 9); l_82 += 2)
                    {
                        step_hash(114);
                        (**g_162) = (*g_163);
                    }
                    step_hash(120);
                    for (p_64 = (-12); (p_64 != 28); p_64 += 7)
                    {
                        unsigned l_184 = 4294967291UL;
                        step_hash(119);
                        l_184 = func_68(l_182, l_183);
                    }
                    step_hash(121);
                    if ((***g_162))
                        continue;
                }
                step_hash(138);
                if ((0x7010L || (func_68(((unsigned)func_68(g_29, ((signed char)l_182 * (signed char)(((unsigned short)p_64 % (unsigned short)l_191) ^ p_64))) + (unsigned)(&l_90 == &l_175)), g_157) || 0x61F4025DL)))
                {
                    step_hash(124);
                    (***g_162) ^= (&l_183 != (*l_89));
                    step_hash(125);
                    (*l_89) = (void*)0;
                }
                else
                {
                    signed char l_196 = 1L;
                    int *l_197 = &l_183;
                    step_hash(135);
                    if ((((short)(*l_175) + (short)((short)((void*)0 != &g_163) % (short)func_68(l_196, (l_197 == &l_183)))) < (g_2 > p_64)))
                    {
                        step_hash(128);
                        l_198 = (*g_162);
                        step_hash(129);
                        (**g_162) = (void*)0;
                        step_hash(130);
                        (*l_175) = func_68((((**l_89) ^ (0x1392L || ((signed char)((int)l_183 - (int)0xEACE3552L) / (signed char)p_64))) > ((short)((((signed char)(((signed char)p_64 << (signed char)6) ^ (g_157 ^ 0x0E80L)) + (signed char)g_2) >= g_29) ^ (*l_197)) / (short)0x8B09L)), (*l_90));
                    }
                    else
                    {
                        int *l_209 = &l_182;
                        step_hash(132);
                        (***g_162) = 0x286D0CB5L;
                        step_hash(133);
                        l_209 = (**g_162);
                        step_hash(134);
                        l_182 &= (**g_163);
                    }
                    step_hash(136);
                    (*l_197) |= (0xA926L >= p_64);
                    step_hash(137);
                    l_210 = (*l_198);
                }
                step_hash(139);
                l_211 = (*g_163);
            }
            else
            {
                step_hash(141);
                (***g_162) = (func_68(g_29, (*l_90)) | p_64);
            }
        }
    }
    step_hash(145);
    (*l_220) &= ((p_64 || 0x27BBL) & ((signed char)func_68(func_68(g_19, p_64), (((int)((unsigned char)(p_64 && ((unsigned short)p_64 - (unsigned short)((*l_89) != (void*)0))) * (unsigned char)p_64) - (int)0x53D3BC77L) & g_104)) + (signed char)g_29));
    step_hash(146);
    (*l_220) = p_64;
    step_hash(147);
    return g_2;
}
static unsigned func_68(unsigned p_69, int p_70)
{
    unsigned char l_73 = 0x18L;
    int *l_78 = &g_19;
    short l_79 = 0xC660L;
    step_hash(24);
    if (((unsigned)g_2 + (unsigned)l_73))
    {
        int l_74 = 0xB4074358L;
        int *l_75 = &g_19;
        step_hash(17);
        (*l_75) ^= (l_74 < (+g_2));
        step_hash(18);
        (*l_75) |= p_70;
    }
    else
    {
        int *l_77 = &g_19;
        int **l_76 = &l_77;
        step_hash(20);
        (*l_76) = &g_19;
        step_hash(21);
        (**l_76) &= (p_69 & g_46);
        step_hash(22);
        (*l_76) = l_78;
        step_hash(23);
        (*l_78) &= 0xB2C1D3A0L;
    }
    step_hash(25);
    return l_79;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_17, "g_17", print_hash_value);
    transparent_crc(g_19, "g_19", print_hash_value);
    transparent_crc(g_29, "g_29", print_hash_value);
    transparent_crc(g_46, "g_46", print_hash_value);
    transparent_crc(g_104, "g_104", print_hash_value);
    transparent_crc(g_157, "g_157", print_hash_value);
    transparent_crc(g_400, "g_400", print_hash_value);
    transparent_crc(g_455, "g_455", print_hash_value);
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
