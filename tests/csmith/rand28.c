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
static int g_2 = (-1L);
static int **g_50 = (void*)0;
static int g_58 = (-4L);
static signed char g_149 = (-1L);
static int *g_197 = &g_58;
static int g_232 = 1L;
static int g_263 = (-1L);
static int *g_280 = &g_2;
static int ***g_568 = (void*)0;
static int g_585 = 0xF8CFA4ABL;
static unsigned func_1(void);
static unsigned short func_7(int p_8);
static int func_9(short p_10, unsigned p_11, unsigned p_12, unsigned p_13, unsigned short p_14);
static unsigned func_16(unsigned char p_17, unsigned char p_18);
static int func_21(signed char p_22, unsigned p_23);
static signed char func_27(signed char p_28);
static int * func_32(int * p_33, int ** p_34, int * p_35, int ** p_36, unsigned short p_37);
static int * func_38(int p_39, int * p_40, unsigned p_41, int ** p_42);
static int * func_43(unsigned p_44, unsigned short p_45);
static unsigned short func_51(int * p_52, int * p_53, int * p_54, int * p_55, unsigned short p_56);
static unsigned func_1(void)
{
    unsigned l_590 = 1UL;
    int ***l_593 = &g_50;
    int *l_610 = &g_58;
    int *l_616 = &g_232;
    step_hash(375);
    for (g_2 = (-13); (g_2 > (-9)); g_2 += 2)
    {
        unsigned char l_15 = 8UL;
        int l_24 = (-1L);
        int *l_584 = &g_585;
        int ***l_596 = &g_50;
        int l_602 = 0xFAFA2276L;
        signed char l_605 = 0L;
        int *l_607 = &g_58;
        int *l_613 = (void*)0;
    }
    step_hash(376);
    return (*l_610);
}
static unsigned short func_7(int p_8)
{
    int ***l_571 = (void*)0;
    signed char l_576 = 0x0BL;
    int l_577 = (-1L);
    int *l_578 = &l_577;
    short l_579 = 0xC392L;
    step_hash(338);
    l_577 |= ((signed char)(((unsigned short)(!g_232) >> (unsigned short)4) == (g_568 != &g_50)) * (signed char)(((func_9(p_8, ((signed char)((void*)0 == l_571) - (signed char)(p_8 | (g_149 < (((short)p_8 << (short)p_8) | p_8)))), p_8, g_232, g_2) < 1L) || l_576) && p_8));
    step_hash(339);
    (*l_578) &= (-2L);
    step_hash(340);
    (*l_578) = l_579;
    step_hash(345);
    for (g_232 = 0; (g_232 <= (-15)); g_232 -= 6)
    {
        step_hash(344);
        (*l_578) ^= ((unsigned short)8UL >> (unsigned short)0);
    }
    step_hash(346);
    return g_232;
}
static int func_9(short p_10, unsigned p_11, unsigned p_12, unsigned p_13, unsigned short p_14)
{
    step_hash(336);
    return g_2;
}
static unsigned func_16(unsigned char p_17, unsigned char p_18)
{
    int *l_523 = &g_58;
    step_hash(322);
    l_523 = l_523;
    step_hash(323);
    g_232 |= (*l_523);
    step_hash(334);
    if ((p_17 ^ (((unsigned char)(((unsigned)(*l_523) / (unsigned)p_17) & ((unsigned short)(p_18 < g_232) << (unsigned short)((unsigned short)((*l_523) == (g_149 >= ((signed char)(((int)((short)(func_51(l_523, l_523, &g_2, l_523, p_17) | g_58) * (short)(*l_523)) - (int)0x5ACF4406L) < 1L) >> (signed char)0))) % (unsigned short)g_2))) / (unsigned char)g_263) <= p_17)))
    {
        unsigned l_538 = 0x7B8C2826L;
        int *l_550 = &g_58;
        int ***l_558 = &g_50;
        step_hash(325);
        (*l_523) = l_538;
        step_hash(330);
        if (((unsigned short)g_149 << (unsigned short)5))
        {
            int ***l_557 = (void*)0;
            int l_559 = 0xEA661446L;
            step_hash(327);
            (*l_550) = ((unsigned char)(((-1L) != ((signed char)((unsigned short)(*l_550) * (unsigned short)0x8EC4L) - (signed char)p_18)) <= l_559) + (unsigned char)p_17);
        }
        else
        {
            int *l_560 = &g_263;
            int **l_561 = &l_550;
            step_hash(329);
            (*l_561) = l_560;
        }
        step_hash(331);
        return p_18;
    }
    else
    {
        step_hash(333);
        return g_2;
    }
}
static int func_21(signed char p_22, unsigned p_23)
{
    int *l_248 = &g_232;
    int *l_259 = &g_58;
    signed char l_296 = (-10L);
    int *l_353 = &g_2;
    short l_363 = (-3L);
    int **l_364 = &l_259;
    int l_371 = 0x30767012L;
    short l_380 = 0x4607L;
    unsigned l_406 = 0x5528EACBL;
    unsigned l_411 = 0x6C442C3BL;
    int l_460 = (-9L);
    int **l_481 = &g_197;
    step_hash(181);
    for (p_23 = 0; (p_23 == 24); p_23++)
    {
        int *l_249 = &g_232;
        int ***l_258 = &g_50;
        int **l_293 = &g_280;
    }
    step_hash(210);
    if ((((((unsigned char)g_58 + (unsigned char)g_2) > 0L) || p_22) != l_296))
    {
        short l_298 = 0x4A64L;
        int *l_331 = &g_58;
        step_hash(206);
        if ((*l_248))
        {
            int *l_297 = &g_263;
            int **l_307 = (void*)0;
            int **l_308 = (void*)0;
            int **l_309 = &g_280;
            step_hash(184);
            (*l_309) = func_32(l_297, &g_280, &g_58, &l_297, p_22);
            step_hash(202);
            for (g_232 = 12; (g_232 >= 7); g_232 -= 8)
            {
                int l_316 = 0L;
                int *l_332 = (void*)0;
                step_hash(201);
                if ((g_58 ^ (*l_259)))
                {
                    int *l_329 = &g_58;
                    step_hash(193);
                    for (g_263 = (-13); (g_263 < (-3)); ++g_263)
                    {
                        int *l_330 = &g_232;
                        step_hash(192);
                        (*l_259) = ((short)l_316 * (short)((unsigned short)func_51((*l_309), l_248, &g_2, &g_232, (*l_248)) / (unsigned short)p_23));
                    }
                    step_hash(194);
                    l_332 = &l_316;
                    step_hash(195);
                    (*l_329) = ((-1L) && (*l_332));
                }
                else
                {
                    int *l_333 = &l_316;
                    step_hash(197);
                    l_333 = l_248;
                    step_hash(198);
                    if (p_22)
                        continue;
                    step_hash(199);
                    if (p_22)
                        continue;
                    step_hash(200);
                    l_316 |= (0x7D9984E9L && ((unsigned short)(((short)((((((unsigned char)251UL << (unsigned char)6) && 1UL) < ((unsigned)(p_22 & ((0x0B31L <= (+p_22)) >= func_51((*l_309), l_333, l_331, &g_2, p_23))) % (unsigned)p_22)) | p_22) && 0x6EC9L) - (short)(*l_259)) > 248UL) / (unsigned short)(*l_259)));
                }
            }
        }
        else
        {
            step_hash(204);
            l_331 = l_331;
            step_hash(205);
            (*l_248) = ((~(g_232 || (p_23 < ((void*)0 != l_259)))) ^ ((*l_331) != p_23));
        }
        step_hash(207);
        (*g_197) = (((unsigned char)(*l_248) << (unsigned char)g_58) > (((void*)0 != l_248) <= ((((((short)g_232 + (short)g_232) <= (*l_331)) | ((unsigned)g_2 - (unsigned)(*l_259))) > 0L) == (-1L))));
    }
    else
    {
        step_hash(209);
        (*l_248) = (-(unsigned)(~0xADD14F1AL));
    }
    step_hash(318);
    if ((((signed char)((((unsigned char)(*l_248) >> (unsigned char)(g_58 < 0UL)) ^ 0x4957L) > ((func_51(l_248, l_259, l_248, l_353, g_149) | g_2) <= g_2)) >> (signed char)g_2) || p_23))
    {
        int *l_362 = &g_2;
        unsigned short l_377 = 0xD1A0L;
        step_hash(212);
        (*l_364) = func_32(l_248, l_364, l_362, &l_248, (*l_362));
        step_hash(213);
        (*l_248) = ((8L < (l_362 == (void*)0)) > (((signed char)(*l_362) + (signed char)(((short)((unsigned char)l_371 >> (unsigned char)3) % (short)(-(short)(((*l_362) >= ((unsigned short)(((int)(((&g_197 != &g_280) == (**l_364)) >= 1UL) % (int)0x7B2F358DL) == p_22) << (unsigned short)4)) && 0x35L))) > l_377)) <= p_22));
        step_hash(214);
        l_380 &= (((((signed char)g_149 >> (signed char)7) ^ g_58) >= (+((void*)0 != l_362))) < p_23);
        step_hash(215);
        (*l_364) = func_38((g_2 || (((unsigned short)(!((((unsigned char)((unsigned char)(p_23 | ((void*)0 != &l_362)) / (unsigned char)(p_23 ^ p_23)) * (unsigned char)((p_23 ^ g_58) <= p_23)) != g_263) > p_23)) / (unsigned short)0x006DL) & p_22)), l_362, p_22, &l_353);
    }
    else
    {
        unsigned short l_397 = 1UL;
        int *l_413 = &g_58;
        int l_414 = 1L;
        int *l_415 = &l_371;
        int *l_416 = (void*)0;
        int **l_478 = (void*)0;
        int *l_479 = (void*)0;
        step_hash(217);
        (*l_248) ^= (*l_259);
        step_hash(229);
        for (g_232 = 2; (g_232 != 18); g_232++)
        {
            step_hash(221);
            (**l_364) |= p_23;
            step_hash(228);
            for (p_23 = 0; (p_23 == 24); p_23 += 4)
            {
                int l_393 = 0x67CB0065L;
                int *l_394 = &l_371;
                step_hash(225);
                (**l_364) &= 0xB77967D7L;
                step_hash(226);
                (*l_394) ^= ((unsigned short)(*l_259) << (unsigned short)((*l_248) < l_393));
                step_hash(227);
                (*l_364) = &g_58;
            }
        }
        step_hash(317);
        if ((*g_197))
        {
            int *l_412 = &g_2;
            int ***l_446 = &l_364;
            step_hash(231);
            l_397 = p_23;
            step_hash(232);
            l_414 &= ((signed char)0x70L * (signed char)((signed char)((unsigned char)(+p_22) * (unsigned char)(((short)l_406 % (short)(((signed char)g_232 - (signed char)(2L || 0x9639L)) ^ ((short)((p_23 >= func_51(&g_263, l_412, l_413, l_413, (*l_353))) || 0L) % (short)g_2))) & 0x35L)) * (signed char)g_263));
            step_hash(292);
            if ((*l_248))
            {
                int **l_421 = &l_412;
                int l_453 = (-9L);
                step_hash(267);
                if (p_23)
                {
                    step_hash(235);
                    (*l_413) = 1L;
                    step_hash(246);
                    if (func_51(l_415, (*l_364), (*l_364), (*l_364), g_2))
                    {
                        step_hash(237);
                        (**l_364) = (**l_364);
                        step_hash(238);
                        (*l_364) = l_416;
                        step_hash(239);
                        (*l_415) ^= ((unsigned short)func_51(&l_414, (*l_364), func_38(((signed char)((void*)0 == l_421) - (signed char)1UL), &l_414, ((signed char)1L + (signed char)(((*l_421) != (*l_364)) || p_22)), &l_353), &l_414, (*l_412)) + (unsigned short)p_23);
                        step_hash(240);
                        (*l_364) = (void*)0;
                    }
                    else
                    {
                        int ***l_424 = (void*)0;
                        int ***l_425 = &l_364;
                        step_hash(242);
                        (**l_364) = ((void*)0 == (*l_421));
                        step_hash(243);
                        (*l_425) = l_421;
                        step_hash(244);
                        (*l_259) = (p_23 != (p_22 | (((signed char)((short)((*g_280) < g_263) << (short)(&l_248 == &l_259)) << (signed char)0) < (0x0FC0L == 0x5321L))));
                        step_hash(245);
                        g_263 &= (g_58 || ((~((unsigned char)(0xEBABB2D7L && ((-(unsigned char)p_22) && g_232)) / (unsigned char)((unsigned short)g_232 >> (unsigned short)10))) > p_22));
                    }
                }
                else
                {
                    signed char l_441 = 8L;
                    int *l_442 = &g_2;
                    int *l_467 = &g_58;
                    step_hash(255);
                    for (l_363 = 0; (l_363 == (-29)); --l_363)
                    {
                        signed char l_443 = (-6L);
                        step_hash(251);
                        (*l_248) = (4L != ((void*)0 != &g_280));
                        step_hash(252);
                        (*l_413) = (&g_197 != (void*)0);
                        step_hash(253);
                        (*l_415) |= (*l_413);
                        step_hash(254);
                        (*l_248) |= ((short)(p_22 | ((signed char)(func_51(&l_414, &g_58, l_442, (*l_421), l_443) && 0xBA4620ADL) % (signed char)6L)) / (short)g_58);
                    }
                    step_hash(265);
                    if (func_51(func_38(((signed char)(l_446 == (void*)0) + (signed char)p_22), (**l_446), ((g_58 < g_149) <= 0xB00DE351L), &l_248), (**l_446), &g_58, (*l_421), (*l_442)))
                    {
                        short l_447 = 0x578FL;
                        int *l_452 = &l_414;
                        step_hash(257);
                        (*l_248) = l_447;
                        step_hash(258);
                        (*l_415) &= ((*g_197) < ((unsigned)((func_51(l_442, (*l_364), func_32((*l_421), l_421, (**l_446), l_421, p_22), (*l_364), (*l_452)) > l_453) && 0x57L) - (unsigned)(*g_280)));
                        step_hash(259);
                        g_197 = (*l_364);
                    }
                    else
                    {
                        step_hash(261);
                        (**l_364) = ((short)(p_22 ^ (+((int)(*l_442) + (int)((signed char)g_58 - (signed char)g_149)))) - (short)65533UL);
                        step_hash(262);
                        (*l_413) = 0x70DE6C0FL;
                        step_hash(263);
                        (*l_259) |= ((*g_280) || (0x461B6927L > l_460));
                        step_hash(264);
                        (***l_446) = ((unsigned)(p_22 <= (((unsigned char)func_51(&g_2, l_442, (*l_421), (**l_446), (((unsigned short)((l_467 == (**l_446)) & p_22) << (unsigned short)((p_23 & 1UL) != p_23)) & 0x617B7643L)) - (unsigned char)g_149) <= p_22)) % (unsigned)0xFB529590L);
                    }
                    step_hash(266);
                    (*l_364) = (**l_446);
                }
                step_hash(272);
                if ((g_58 < (p_23 > (p_22 >= 4294967286UL))))
                {
                    int **l_468 = &l_413;
                    step_hash(269);
                    (*l_446) = l_468;
                }
                else
                {
                    int *l_471 = &g_58;
                    step_hash(271);
                    (*l_415) ^= ((unsigned char)(g_232 >= g_232) * (unsigned char)func_51(&g_263, (**l_446), l_471, (**l_446), p_23));
                }
                step_hash(273);
                (*l_248) = 1L;
            }
            else
            {
                int *l_472 = &l_414;
                int *l_483 = &l_414;
                step_hash(275);
                l_472 = (*l_364);
                step_hash(291);
                for (l_406 = 0; (l_406 == 42); l_406 += 4)
                {
                    int *l_477 = &l_414;
                    step_hash(285);
                    for (g_58 = 0; (g_58 != 4); g_58 += 1)
                    {
                        unsigned l_480 = 6UL;
                        int *l_482 = &l_414;
                        step_hash(282);
                        g_197 = (*l_364);
                        step_hash(283);
                        (*l_248) = func_51((*l_364), l_479, func_38((*g_197), &l_414, l_480, l_481), l_482, g_58);
                        step_hash(284);
                        (*l_364) = l_483;
                    }
                    step_hash(290);
                    for (l_460 = 25; (l_460 <= (-8)); --l_460)
                    {
                        step_hash(289);
                        (*l_477) = p_22;
                    }
                }
            }
        }
        else
        {
            int *l_499 = (void*)0;
            int l_508 = (-1L);
            step_hash(294);
            (**l_481) |= (g_232 > g_232);
            step_hash(295);
            (*l_415) = (((signed char)g_232 << (signed char)1) != 0x302BL);
            step_hash(315);
            for (p_22 = 8; (p_22 == 14); p_22++)
            {
                int *l_497 = &g_232;
                signed char l_509 = 0x2EL;
                step_hash(313);
                for (l_363 = 18; (l_363 == 3); --l_363)
                {
                    unsigned short l_492 = 0x25CFL;
                    step_hash(302);
                    (**l_481) ^= l_492;
                    step_hash(310);
                    for (l_371 = (-6); (l_371 != (-1)); l_371++)
                    {
                        int *l_498 = &l_414;
                        step_hash(306);
                        (*l_413) ^= (p_22 & p_22);
                        step_hash(307);
                        (*l_498) ^= ((0xE5L && ((short)func_51(l_497, l_498, l_499, l_498, l_492) >> (short)p_22)) == g_232);
                        step_hash(308);
                        (**l_481) = ((unsigned char)((((l_492 > g_2) || (l_497 != l_497)) <= (((g_263 != (g_232 < (0x08L > (((int)(g_149 >= p_22) + (int)l_508) | g_2)))) & (*l_497)) <= 0x6FL)) > (*g_197)) % (unsigned char)0xCEL);
                        step_hash(309);
                        (*l_364) = l_498;
                    }
                    step_hash(311);
                    if (l_509)
                        continue;
                    step_hash(312);
                    if ((*g_280))
                        break;
                }
                step_hash(314);
                (*l_481) = &l_508;
            }
            step_hash(316);
            (*l_481) = (*l_481);
        }
    }
    step_hash(319);
    g_58 &= (*l_353);
    step_hash(320);
    return (*g_280);
}
static signed char func_27(signed char p_28)
{
    int **l_29 = (void*)0;
    int *l_31 = &g_2;
    int **l_30 = &l_31;
    int l_235 = 0xC0EB3422L;
    step_hash(5);
    (*l_30) = (void*)0;
    step_hash(136);
    (*l_30) = func_32(func_38(p_28, func_43(((p_28 & ((unsigned char)((unsigned short)(g_50 == &l_31) + (unsigned short)func_51((*l_30), (*l_30), (*l_30), &g_2, p_28)) + (unsigned char)p_28)) == p_28), g_2), p_28, &l_31), l_30, &g_2, &g_197, p_28);
    step_hash(137);
    l_235 ^= p_28;
    step_hash(138);
    (*g_197) = ((short)((unsigned short)((*l_30) != (void*)0) % (unsigned short)((p_28 || (&g_197 != (void*)0)) & 65526UL)) % (short)g_2);
    step_hash(139);
    return (**l_30);
}
static int * func_32(int * p_33, int ** p_34, int * p_35, int ** p_36, unsigned short p_37)
{
    int *l_233 = &g_2;
    int *l_234 = &g_2;
    step_hash(133);
    g_232 ^= (func_51(&g_2, l_233, (*p_34), l_234, p_37) <= 0x94L);
    step_hash(134);
    (*p_34) = (*p_36);
    step_hash(135);
    return l_233;
}
static int * func_38(int p_39, int * p_40, unsigned p_41, int ** p_42)
{
    int *l_231 = &g_232;
    step_hash(129);
    (*l_231) |= (*g_197);
    step_hash(130);
    (*p_42) = (*p_42);
    step_hash(131);
    return (*p_42);
}
static int * func_43(unsigned p_44, unsigned short p_45)
{
    signed char l_63 = 0x79L;
    int *l_72 = &g_58;
    int *l_78 = &g_58;
    int *l_118 = &g_58;
    unsigned char l_123 = 0xE1L;
    unsigned l_156 = 0x28D9C3D7L;
    step_hash(11);
    (*l_72) = ((unsigned char)((unsigned short)(l_63 != ((unsigned short)p_44 % (unsigned short)((unsigned)(~((unsigned char)0x03L >> (unsigned char)1)) + (unsigned)(((-1L) > ((int)(p_44 < (4294967294UL != p_44)) % (int)0xF6679856L)) & 9UL)))) + (unsigned short)p_44) >> (unsigned char)l_63);
    step_hash(124);
    if (((void*)0 != &g_2))
    {
        int **l_76 = &l_72;
        int l_77 = 0L;
        short l_86 = 0xE086L;
        int *l_94 = &g_58;
        unsigned l_120 = 0x3E316ED2L;
        step_hash(24);
        for (g_58 = (-30); (g_58 != 19); ++g_58)
        {
            int **l_75 = (void*)0;
            step_hash(23);
            if ((l_75 != l_76))
            {
                step_hash(17);
                l_72 = (void*)0;
                step_hash(18);
                l_77 ^= func_51(l_72, &g_2, l_72, (*l_76), g_58);
                step_hash(19);
                l_78 = l_78;
                step_hash(20);
                (*l_76) = l_78;
            }
            else
            {
                step_hash(22);
                return &g_2;
            }
        }
        step_hash(73);
        if ((func_51((*l_76), (*l_76), l_78, l_78, ((signed char)func_51(l_78, (*l_76), l_72, &g_58, g_58) - (signed char)p_44)) & p_44))
        {
            int l_95 = 1L;
            int l_119 = (-8L);
            step_hash(42);
            for (l_63 = 16; (l_63 > 16); l_63 += 4)
            {
                step_hash(41);
                if (p_45)
                {
                    int l_83 = 1L;
                    step_hash(30);
                    (**l_76) ^= p_45;
                    step_hash(31);
                    l_86 = (l_83 | (((short)p_45 * (short)(p_45 ^ func_51((*l_76), &l_83, &l_83, (*l_76), g_58))) == p_45));
                    step_hash(36);
                    for (p_45 = (-8); (p_45 >= 23); p_45 += 1)
                    {
                        step_hash(35);
                        (*l_76) = (void*)0;
                    }
                    step_hash(37);
                    return l_72;
                }
                else
                {
                    int *l_89 = &l_77;
                    step_hash(39);
                    (*l_89) &= g_58;
                    step_hash(40);
                    if ((*l_72))
                        break;
                }
            }
            step_hash(56);
            if (g_58)
            {
                unsigned char l_90 = 255UL;
                step_hash(44);
                (*l_72) = l_90;
                step_hash(45);
                (*l_76) = &g_58;
                step_hash(46);
                (*l_76) = (void*)0;
            }
            else
            {
                int *l_91 = &g_2;
                int *l_100 = &g_58;
                step_hash(48);
                l_72 = l_91;
                step_hash(49);
                (*l_94) = (((unsigned char)254UL % (unsigned char)g_58) <= func_51((*l_76), l_91, &g_2, l_94, l_95));
                step_hash(54);
                for (l_77 = 0; (l_77 > (-22)); l_77 -= 5)
                {
                    int *l_101 = &l_77;
                    step_hash(53);
                    (*l_100) = ((short)(func_51(l_78, l_100, l_91, l_91, (func_51(l_101, l_100, l_72, l_100, ((unsigned)(((signed char)0xA1L / (signed char)g_2) | 255UL) - (unsigned)p_45)) && (*l_100))) & p_45) / (short)g_58);
                }
                step_hash(55);
                (*l_78) ^= p_44;
            }
            step_hash(57);
            l_119 = ((unsigned char)((((int)((unsigned char)((unsigned char)((unsigned short)((void*)0 != g_50) / (unsigned short)g_2) << (unsigned char)((int)((func_51(l_72, l_118, l_118, l_72, (*l_78)) || p_44) | g_2) - (int)l_95)) / (unsigned char)0x0BL) + (int)4294967294UL) || 0xCCL) < (-2L)) >> (unsigned char)l_95);
        }
        else
        {
            short l_121 = 0xB233L;
            int *l_126 = &g_58;
            step_hash(72);
            if (l_120)
            {
                int *l_122 = &l_77;
                int *l_129 = &g_2;
                step_hash(60);
                (*l_76) = l_72;
                step_hash(61);
                (*l_122) ^= (((l_121 >= 1UL) < g_58) || g_2);
                step_hash(62);
                (*l_122) &= ((((p_44 < l_123) <= (((short)0x3792L * (short)l_121) > ((0x0DBEA549L >= ((-8L) && ((l_126 != l_122) && (*l_72)))) >= g_58))) == 252UL) ^ 1UL);
                step_hash(68);
                for (l_120 = 0; (l_120 < 56); l_120 += 2)
                {
                    step_hash(66);
                    (*l_126) = (p_45 < g_2);
                    step_hash(67);
                    (*l_76) = l_129;
                }
            }
            else
            {
                step_hash(70);
                (*l_78) ^= (0xD077L < p_45);
                step_hash(71);
                (*l_76) = (*l_76);
            }
        }
        step_hash(74);
        (*l_94) ^= ((unsigned char)0UL >> (unsigned char)3);
    }
    else
    {
        int *l_139 = (void*)0;
        int *l_148 = &g_58;
        unsigned l_202 = 4294967293UL;
        step_hash(123);
        for (p_44 = 0; (p_44 != 44); ++p_44)
        {
            int *l_138 = &g_2;
            short l_161 = 0x451BL;
            int **l_224 = &l_78;
            step_hash(79);
            g_149 |= (((((unsigned char)(((signed char)(func_51(l_138, l_139, l_139, l_78, ((unsigned)((unsigned char)((unsigned short)((unsigned char)func_51(l_148, l_148, l_118, l_138, g_2) >> (unsigned char)3) * (unsigned short)g_2) + (unsigned char)p_45) - (unsigned)0x0E7D168DL)) || g_58) >> (signed char)4) | 65535UL) << (unsigned char)5) >= g_58) > g_58) & (*l_148));
            step_hash(108);
            if (((func_51(l_148, l_148, l_78, l_118, p_44) | ((((((signed char)((unsigned char)(((unsigned char)(246UL | (*l_78)) >> (unsigned char)0) > ((g_149 != (*l_138)) > (*l_148))) >> (unsigned char)g_58) + (signed char)(-10L)) == l_156) != 1UL) || (*l_138)) | p_45)) != 255UL))
            {
                unsigned l_164 = 0x0DB9FFA4L;
                short l_172 = 0x2394L;
                int l_173 = 1L;
                int **l_190 = &l_139;
                step_hash(103);
                for (l_123 = 0; (l_123 < 44); l_123++)
                {
                    int *l_169 = (void*)0;
                }
                step_hash(104);
                (*l_148) ^= p_44;
            }
            else
            {
                step_hash(106);
                (*l_78) = ((!g_149) || 0L);
                step_hash(107);
                (*l_118) = (*l_138);
            }
            step_hash(121);
            for (p_45 = (-26); (p_45 != 32); p_45 += 8)
            {
                int *l_193 = &g_2;
                int ***l_194 = &g_50;
                step_hash(112);
                (*l_118) = (func_51(l_118, &g_58, l_148, l_193, (*l_193)) || (func_51(l_138, l_139, l_148, l_193, (*l_72)) < p_45));
                step_hash(113);
                (*l_194) = &l_138;
                step_hash(114);
                l_202 = (((((unsigned short)func_51(l_72, (*g_50), g_197, l_138, (((short)(*l_138) << (short)2) ^ ((int)0x70531B4AL - (int)g_58))) >> (unsigned short)(g_2 || 0x9095L)) || (*g_197)) == 0x3E1635C7L) || g_2);
                step_hash(120);
                for (l_63 = (-23); (l_63 == 29); l_63 += 1)
                {
                    int *l_221 = &g_2;
                    int *l_222 = &g_58;
                    int l_223 = 0x2AF5FF99L;
                    step_hash(118);
                    (*g_50) = l_138;
                    step_hash(119);
                    l_223 &= (((unsigned char)((short)((short)(((unsigned short)(((unsigned short)((unsigned char)g_2 / (unsigned char)((unsigned)((signed char)((*l_118) < (p_44 == ((void*)0 == l_221))) >> (signed char)0) % (unsigned)func_51(l_118, l_138, (*g_50), l_222, p_45))) * (unsigned short)p_44) < p_45) % (unsigned short)0x59C8L) && 4294967293UL) * (short)(***l_194)) >> (short)g_149) % (unsigned char)p_44) == g_58);
                }
            }
            step_hash(122);
            (*l_224) = l_72;
        }
    }
    step_hash(125);
    l_118 = l_118;
    step_hash(126);
    (*g_197) |= ((signed char)((unsigned char)(0L == ((p_45 <= 4294967295UL) ^ (((short)p_44 << (short)5) == p_44))) - (unsigned char)(l_72 != l_72)) + (signed char)((void*)0 != l_118));
    step_hash(127);
    return &g_2;
}
static unsigned short func_51(int * p_52, int * p_53, int * p_54, int * p_55, unsigned short p_56)
{
    int *l_57 = &g_58;
    step_hash(7);
    l_57 = &g_2;
    step_hash(8);
    l_57 = p_53;
    step_hash(9);
    return g_58;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_58, "g_58", print_hash_value);
    transparent_crc(g_149, "g_149", print_hash_value);
    transparent_crc(g_232, "g_232", print_hash_value);
    transparent_crc(g_263, "g_263", print_hash_value);
    transparent_crc(g_585, "g_585", print_hash_value);
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
