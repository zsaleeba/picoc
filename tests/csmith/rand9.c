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
static unsigned char g_4 = 0x88L;
static int g_21 = 0x4456E348L;
static int *g_22 = &g_21;
static int *g_121 = &g_21;
static int g_142 = 1L;
static signed char g_149 = 0xB2L;
static int g_159 = 0L;
static int g_180 = 0x38483835L;
static int *g_179 = &g_180;
static int **g_178 = &g_179;
static int g_205 = 0L;
static int *g_204 = &g_205;
static short g_341 = (-7L);
static int g_372 = 0x534F437CL;
static int *g_466 = (void*)0;
static unsigned char func_1(void);
static short func_2(int p_3);
static unsigned func_5(int p_6);
static unsigned func_12(unsigned char p_13, short p_14, int p_15);
static int * func_25(int ** p_26, int ** p_27, int ** p_28);
static int ** func_29(unsigned p_30, unsigned short p_31, int * p_32, int * p_33, unsigned char p_34);
static unsigned func_35(int p_36, int p_37);
static int func_38(int ** p_39, int ** p_40, unsigned short p_41, int * p_42);
static int ** func_43(signed char p_44, unsigned p_45, int ** p_46, int p_47, unsigned p_48);
static signed char func_49(int p_50, unsigned char p_51);
static unsigned char func_1(void)
{
    int **l_553 = &g_204;
    step_hash(411);
    (*g_121) = (func_2(g_4) && (l_553 == (void*)0));
    step_hash(412);
    return (**l_553);
}
static short func_2(int p_3)
{
    int l_11 = 0L;
    step_hash(409);
    p_3 = (func_5(((int)((unsigned char)l_11 / (unsigned char)g_4) - (int)func_12(p_3, g_4, g_4))) ^ 3L);
    step_hash(410);
    return l_11;
}
static unsigned func_5(int p_6)
{
    step_hash(408);
    return p_6;
}
static unsigned func_12(unsigned char p_13, short p_14, int p_15)
{
    int l_518 = 1L;
    step_hash(405);
    for (p_14 = 28; (p_14 != 24); p_14 -= 1)
    {
        int l_24 = (-1L);
        int *l_517 = &g_21;
        short l_533 = 0xB869L;
    }
    step_hash(406);
    return p_13;
}
static int * func_25(int ** p_26, int ** p_27, int ** p_28)
{
    short l_488 = 0x2CC9L;
    short l_503 = 0x933FL;
    step_hash(341);
    (*g_121) |= l_488;
    step_hash(372);
    for (g_205 = 12; (g_205 < (-7)); g_205--)
    {
        int l_500 = 0L;
        step_hash(368);
        if ((((*p_26) != (void*)0) != (**p_28)))
        {
            unsigned short l_499 = 1UL;
            step_hash(360);
            if ((0xCEAFL != ((int)((unsigned short)((short)((unsigned short)g_4 % (unsigned short)l_499) % (short)g_142) / (unsigned short)g_4) + (int)0x45CC115CL)))
            {
                step_hash(347);
                (**p_28) &= l_503;
                step_hash(348);
                (*g_121) &= 0xDC005F59L;
                step_hash(357);
                for (g_180 = 0; (g_180 >= (-18)); g_180--)
                {
                    short l_509 = 6L;
                    step_hash(356);
                    for (l_500 = 0; (l_500 < (-19)); --l_500)
                    {
                        int l_508 = (-1L);
                        step_hash(355);
                        (*g_121) ^= (l_508 ^ l_509);
                    }
                }
            }
            else
            {
                step_hash(359);
                (**p_28) |= ((unsigned char)g_159 << (unsigned char)4);
            }
            step_hash(361);
            return (*p_28);
        }
        else
        {
            step_hash(367);
            for (g_142 = 0; (g_142 < (-8)); g_142 -= 7)
            {
                step_hash(366);
                (**p_28) = ((short)(-(signed char)l_503) >> (short)0);
            }
        }
        step_hash(369);
        (*g_178) = (*p_28);
        step_hash(370);
        if (l_500)
            break;
        step_hash(371);
        if ((**p_28))
            continue;
    }
    step_hash(373);
    return (*p_28);
}
static int ** func_29(unsigned p_30, unsigned short p_31, int * p_32, int * p_33, unsigned char p_34)
{
    int **l_473 = &g_22;
    step_hash(317);
    (*p_33) = (+(-1L));
    step_hash(336);
    for (g_341 = 19; (g_341 == 24); ++g_341)
    {
        unsigned l_478 = 4294967291UL;
        int *l_483 = &g_21;
        step_hash(334);
        for (p_34 = (-28); (p_34 == 21); p_34++)
        {
            int *l_481 = (void*)0;
            step_hash(333);
            for (g_159 = 0; (g_159 >= 12); ++g_159)
            {
                int *l_479 = &g_205;
                short l_480 = 0L;
                step_hash(332);
                if (l_480)
                {
                    step_hash(328);
                    (*l_479) = (g_142 || (**l_473));
                    step_hash(329);
                    p_32 = p_32;
                }
                else
                {
                    unsigned char l_482 = 0xC5L;
                    step_hash(331);
                    (*l_479) |= (*p_33);
                }
            }
        }
        step_hash(335);
        return &g_121;
    }
    step_hash(337);
    (*l_473) = p_32;
    step_hash(338);
    (*p_33) = (((short)((unsigned short)(g_180 && g_21) >> (unsigned short)10) >> (short)5) != (*p_33));
    step_hash(339);
    return &g_466;
}
static unsigned func_35(int p_36, int p_37)
{
    int l_52 = 0L;
    int **l_209 = (void*)0;
    int **l_210 = &g_204;
    int l_213 = 0xA3542F59L;
    signed char l_214 = 1L;
    unsigned l_286 = 4294967290UL;
    int l_365 = 0x78BD9CC4L;
    unsigned l_434 = 0xBFE20CF4L;
    step_hash(147);
    (*g_204) = func_38(&g_22, func_43((func_49(l_52, ((void*)0 == &p_37)) || (l_52 <= ((unsigned)g_149 + (unsigned)(0x6539L || (p_36 > g_142))))), l_52, g_178, l_52, p_37), l_52, g_204);
    step_hash(313);
    if (((short)(((func_38(l_209, func_43((g_180 > g_21), p_36, l_210, (p_37 < (((**l_210) || ((unsigned)(((void*)0 == (*l_210)) && l_213) / (unsigned)0x89F28232L)) == 4294967295UL)), p_36), p_36, &g_205) != 4294967294UL) < g_4) <= p_36) >> (short)l_214))
    {
        int **l_221 = &g_179;
        int **l_315 = &g_179;
        int **l_316 = &g_204;
        int *l_384 = &l_213;
        short l_393 = 0x522AL;
        step_hash(196);
        if (((unsigned char)(((int)((short)p_37 / (short)func_38(&g_204, l_221, ((signed char)((unsigned char)(((unsigned char)((int)p_37 - (int)((unsigned)((((unsigned char)(((((short)((unsigned)((signed char)((**l_221) & p_36) >> (signed char)((-6L) > 9L)) + (unsigned)((unsigned char)(p_36 | g_4) - (unsigned char)4L)) - (short)p_37) ^ (**l_221)) || (**l_221)) < (-1L)) << (unsigned char)p_37) <= 0x17L) && p_37) % (unsigned)0x118C1422L)) << (unsigned char)(**l_210)) <= g_21) % (unsigned char)2L) / (signed char)g_4), (*g_178))) + (int)0xEDC9C37AL) | p_37) / (unsigned char)p_36))
        {
            int *l_250 = (void*)0;
            int l_253 = 0x5EE5D022L;
            step_hash(150);
            (*g_178) = (*l_221);
            step_hash(151);
            (**l_210) = (((short)func_49(((func_49(p_36, ((signed char)p_37 << (signed char)5)) < ((unsigned short)g_180 << (unsigned short)5)) > ((+((short)((*l_221) != l_250) * (short)((unsigned short)p_36 * (unsigned short)(+(**l_210))))) == l_253)), g_205) * (short)0L) & (**l_221));
            step_hash(152);
            (**l_221) = (*g_121);
            step_hash(153);
            p_36 = (((short)0x0433L << (short)g_142) <= (**g_178));
        }
        else
        {
            int *l_256 = &g_205;
            step_hash(187);
            if ((g_159 != 65535UL))
            {
                step_hash(156);
                (*g_178) = &p_36;
                step_hash(157);
                (*g_178) = l_256;
                step_hash(158);
                return p_37;
            }
            else
            {
                int *l_269 = &g_142;
                int **l_275 = &g_121;
                step_hash(164);
                if (func_49((**l_221), ((-(unsigned short)(g_149 & p_37)) && ((void*)0 == (*g_178)))))
                {
                    step_hash(161);
                    (*g_204) = ((unsigned char)g_21 << (unsigned char)1);
                }
                else
                {
                    step_hash(163);
                    (**l_210) = (*g_121);
                }
                step_hash(184);
                for (g_159 = (-27); (g_159 < (-28)); g_159 -= 6)
                {
                    unsigned char l_272 = 0x64L;
                    int *l_283 = &g_180;
                    step_hash(168);
                    (*l_256) = ((8L && (((+1L) <= (-(int)(((short)g_149 >> (short)8) | ((unsigned)(0xA7184DBDL ^ ((short)func_38(&g_22, l_221, ((void*)0 != &p_36), l_269) >> (short)p_36)) + (unsigned)(*l_269))))) & g_4)) && p_36);
                    step_hash(173);
                    if ((((signed char)(-9L) >> (signed char)(**l_221)) && (l_272 || 0x0AL)))
                    {
                        step_hash(170);
                        (*l_210) = &p_37;
                    }
                    else
                    {
                        step_hash(172);
                        return p_37;
                    }
                    step_hash(182);
                    if (((short)((**l_221) == (**l_221)) - (short)g_180))
                    {
                        int **l_276 = &g_179;
                        step_hash(175);
                        (*l_210) = (*g_178);
                        step_hash(176);
                        (*l_269) = ((&g_121 != l_275) | p_37);
                        step_hash(177);
                        (**l_210) = func_38(&g_204, &g_179, (**l_210), (*g_178));
                        step_hash(178);
                        (**g_178) &= ((void*)0 == l_276);
                    }
                    else
                    {
                        step_hash(180);
                        (*l_221) = &p_37;
                        step_hash(181);
                        return (*l_269);
                    }
                    step_hash(183);
                    (*l_269) ^= ((signed char)((unsigned char)(((*l_256) <= (l_283 == (*g_178))) ^ ((g_4 > p_36) == 0UL)) << (unsigned char)5) << (signed char)7);
                }
                step_hash(185);
                (**l_221) &= ((unsigned)p_36 / (unsigned)0x1AF36540L);
                step_hash(186);
                (**l_275) = p_36;
            }
            step_hash(193);
            if ((*g_22))
            {
                step_hash(189);
                (*l_256) = ((**l_221) | l_286);
            }
            else
            {
                unsigned char l_287 = 0UL;
                step_hash(191);
                l_287 = ((-1L) | g_205);
                step_hash(192);
                (**l_210) = func_49((((((short)((signed char)g_149 * (signed char)(p_37 ^ ((*l_256) || ((signed char)(((short)(**l_221) - (short)((int)9L % (int)func_49(((unsigned short)g_21 - (unsigned short)(p_37 || (**l_221))), (**l_221)))) >= 0x388FD200L) * (signed char)(*l_256))))) >> (short)l_287) | p_37) | (-10L)) > l_287), p_36);
            }
            step_hash(194);
            (**l_210) = ((unsigned short)(((**l_221) && p_37) <= (g_205 >= p_36)) >> (unsigned short)2);
            step_hash(195);
            (**l_210) = (-(unsigned char)((unsigned short)func_49((**l_221), p_37) * (unsigned short)g_205));
        }
        step_hash(256);
        if (((unsigned char)p_37 - (unsigned char)g_180))
        {
            signed char l_309 = 0x3FL;
            int l_349 = 0xFE9FD4BCL;
            int **l_351 = &g_204;
            step_hash(251);
            if ((((unsigned)l_309 / (unsigned)1UL) <= (**l_210)))
            {
                unsigned short l_310 = 65529UL;
                step_hash(213);
                if (l_310)
                {
                    unsigned short l_328 = 65535UL;
                    step_hash(204);
                    for (l_309 = 0; (l_309 == 4); l_309++)
                    {
                        int l_317 = 0L;
                        step_hash(203);
                        (*g_22) = (((unsigned short)func_38(l_315, l_316, (l_317 & 0xAE0FL), &p_37) - (unsigned short)(((signed char)((signed char)p_37 + (signed char)(((((unsigned short)((unsigned)((unsigned short)(((p_37 || (252UL || 5L)) | g_159) | l_328) / (unsigned short)l_309) + (unsigned)l_317) >> (unsigned short)p_37) ^ g_4) ^ g_4) || p_37)) / (signed char)p_37) ^ p_37)) | p_37);
                    }
                    step_hash(205);
                    (*g_179) = ((unsigned short)0x75D7L % (unsigned short)(((func_49((l_221 != &g_179), (((unsigned char)((unsigned char)l_309 >> (unsigned char)p_37) % (unsigned char)1L) >= ((short)((**l_210) > l_310) / (short)g_21))) < l_328) <= g_205) || 0L));
                }
                else
                {
                    step_hash(207);
                    (**l_316) |= p_37;
                    step_hash(212);
                    if ((*g_204))
                    {
                        step_hash(209);
                        (*l_316) = &p_36;
                    }
                    else
                    {
                        unsigned char l_337 = 0UL;
                        int *l_338 = &l_213;
                        step_hash(211);
                        (*l_338) |= ((l_309 ^ 0xCFL) <= (func_49(((p_36 > 0x56L) == p_37), l_337) == (**l_221)));
                    }
                }
            }
            else
            {
                unsigned short l_350 = 0x3BDAL;
                int l_379 = 5L;
                int **l_382 = &g_121;
                step_hash(228);
                for (g_21 = (-29); (g_21 == (-30)); g_21--)
                {
                    step_hash(218);
                    if (g_341)
                        break;
                    step_hash(219);
                    (**l_221) = ((unsigned char)(-(int)(p_36 | (-10L))) % (unsigned char)((**l_315) | ((p_37 ^ g_142) || ((p_37 != g_4) ^ (-8L)))));
                    step_hash(226);
                    for (g_149 = 12; (g_149 > (-17)); g_149--)
                    {
                        step_hash(223);
                        l_349 = ((unsigned char)0UL - (unsigned char)(p_36 <= p_36));
                        step_hash(224);
                        (**l_316) &= l_350;
                        step_hash(225);
                        (**l_315) ^= (p_37 >= l_309);
                    }
                    step_hash(227);
                    (**l_221) &= (&g_121 == l_351);
                }
                step_hash(229);
                p_37 = ((signed char)g_21 >> (signed char)0);
                step_hash(230);
                (*l_210) = (void*)0;
                step_hash(250);
                for (g_205 = 5; (g_205 >= (-16)); g_205--)
                {
                    signed char l_376 = 9L;
                    step_hash(240);
                    for (l_349 = 0; (l_349 < (-5)); l_349 -= 7)
                    {
                        unsigned char l_358 = 0xACL;
                        step_hash(237);
                        if (p_37)
                            break;
                        step_hash(238);
                        l_358 |= (**g_178);
                        step_hash(239);
                        p_36 |= ((((unsigned char)g_205 >> (unsigned char)5) ^ func_49(((signed char)p_37 >> (signed char)7), (func_49(g_341, g_341) <= (-3L)))) & (((short)((g_4 ^ 0xF9DEE71FL) > g_149) - (short)0UL) <= l_365));
                    }
                    step_hash(241);
                    l_376 = func_49(g_149, func_49(((unsigned short)p_37 * (unsigned short)(((unsigned char)((((unsigned short)((*g_121) | g_372) - (unsigned short)((*l_351) != (*g_178))) || ((signed char)(-(int)(g_149 & p_37)) % (signed char)g_372)) < (**g_178)) >> (unsigned char)p_36) & 0x6112L)), g_159));
                    step_hash(249);
                    for (l_365 = (-18); (l_365 == (-15)); l_365 += 4)
                    {
                        int *l_383 = &g_21;
                        step_hash(245);
                        if (p_36)
                            break;
                        step_hash(246);
                        l_379 ^= p_37;
                        step_hash(247);
                        if ((**l_221))
                            break;
                        step_hash(248);
                        (*l_383) = ((int)func_49((l_382 != (void*)0), g_159) - (int)(**g_178));
                    }
                }
            }
        }
        else
        {
            unsigned l_385 = 0x54D95447L;
            int *l_386 = &l_213;
            step_hash(253);
            l_384 = (void*)0;
            step_hash(254);
            (*l_221) = &p_37;
            step_hash(255);
            (*l_386) &= (((**l_210) || l_385) >= func_49(p_36, ((**l_221) > 65535UL)));
        }
        step_hash(257);
        (*l_210) = (*g_178);
        step_hash(258);
        l_393 &= (p_36 >= ((short)0L << (short)((short)(((*g_178) != &p_36) < func_49(p_37, p_37)) >> (short)2)));
    }
    else
    {
        unsigned l_403 = 5UL;
        unsigned short l_404 = 1UL;
        int **l_405 = &g_204;
        int *l_408 = &g_180;
        step_hash(265);
        for (l_213 = 0; (l_213 < (-17)); --l_213)
        {
            unsigned char l_398 = 0UL;
            step_hash(263);
            (**g_178) |= (*g_121);
            step_hash(264);
            p_37 ^= ((unsigned char)g_21 + (unsigned char)l_398);
        }
        step_hash(310);
        if (((**l_210) < (((signed char)p_37 >> (signed char)2) && ((signed char)(1UL | 0x635BAB6BL) + (signed char)p_37))))
        {
            step_hash(267);
            (*g_179) = ((((1L > l_403) == (g_205 || (func_49(l_403, g_341) == p_36))) && (0L & (((((p_36 && 0xF58DC4ADL) < p_37) == 0x66FCL) & p_37) ^ l_404))) & p_36);
        }
        else
        {
            int l_411 = 0L;
            int **l_442 = &g_204;
            unsigned l_455 = 0x43AA5389L;
            step_hash(276);
            if (((g_372 < g_341) & (func_38(l_405, &g_22, ((**l_405) && (&g_204 != &g_204)), (*l_405)) && g_142)))
            {
                step_hash(270);
                (*g_22) ^= ((*g_178) == l_408);
            }
            else
            {
                int l_412 = 0L;
                step_hash(272);
                (**l_210) ^= (func_49(((void*)0 == &g_22), p_36) != (*l_408));
                step_hash(273);
                (**g_178) = ((unsigned char)((l_411 <= (l_412 <= (l_412 <= ((p_37 ^ 4L) != p_36)))) == (((short)l_411 << (short)(((unsigned short)(0x45A4L >= (((((signed char)((p_37 | p_37) > 0xC3057E25L) / (signed char)p_36) >= l_412) < l_412) ^ g_341)) + (unsigned short)1UL) < g_149)) ^ 0L)) * (unsigned char)g_142);
                step_hash(274);
                (*l_408) ^= ((short)g_341 + (short)g_205);
                step_hash(275);
                p_37 &= func_38(&l_408, l_210, g_180, (*g_178));
            }
            step_hash(296);
            if (p_36)
            {
                step_hash(278);
                (*g_22) |= 1L;
                step_hash(279);
                (**l_210) &= 1L;
            }
            else
            {
                int **l_429 = &g_204;
                step_hash(293);
                for (l_213 = 0; (l_213 <= (-2)); l_213 -= 3)
                {
                    int *l_432 = (void*)0;
                    int *l_433 = &l_52;
                    step_hash(290);
                    if ((g_142 != p_37))
                    {
                        step_hash(285);
                        (*l_210) = &p_36;
                        step_hash(286);
                        (*g_22) |= (**g_178);
                        step_hash(287);
                        (*g_178) = (*g_178);
                    }
                    else
                    {
                        step_hash(289);
                        (**l_210) = func_49((((short)p_36 << (short)15) == p_37), p_37);
                    }
                    step_hash(291);
                    (*l_433) |= func_49(g_142, ((unsigned char)((signed char)(+g_142) + (signed char)func_38(l_209, l_429, ((+((short)(+(**l_429)) >> (short)p_36)) | ((p_36 < (p_37 >= (l_411 >= g_205))) > 3UL)), (*l_429))) >> (unsigned char)4));
                    step_hash(292);
                    (*l_408) &= func_49((**l_210), (*l_433));
                }
                step_hash(294);
                (*l_408) = p_37;
                step_hash(295);
                return p_37;
            }
            step_hash(308);
            if (((p_36 > g_149) != (&l_408 != &g_204)))
            {
                step_hash(298);
                (*l_405) = (*l_210);
                step_hash(299);
                (*l_405) = &p_36;
                step_hash(300);
                l_434 = 0x6852D1D0L;
            }
            else
            {
                int **l_456 = (void*)0;
                step_hash(307);
                for (l_214 = 0; (l_214 == (-29)); --l_214)
                {
                    signed char l_441 = 0xA6L;
                    step_hash(305);
                    p_37 = ((unsigned)(((unsigned)(l_441 | func_49((l_210 == l_442), ((int)(!(*l_408)) % (int)0xF4B528D2L))) / (unsigned)g_4) > ((unsigned char)((&g_179 == (void*)0) | p_36) << (unsigned char)g_149)) - (unsigned)(**g_178));
                    step_hash(306);
                    p_36 &= ((short)((short)((unsigned char)((*g_121) == 0x753B144CL) >> (unsigned char)0) >> (short)3) / (short)0xD5A2L);
                }
            }
            step_hash(309);
            return g_149;
        }
        step_hash(311);
        (*g_179) = (((int)((0x5B19036AL && func_49(((unsigned char)g_21 % (unsigned char)((unsigned char)(l_209 != &g_22) >> (unsigned char)g_4)), (**l_405))) != p_37) * (int)(g_149 <= 0x4AL)) ^ g_4);
        step_hash(312);
        (*g_179) = (*g_204);
    }
    step_hash(314);
    (*g_178) = (*g_178);
    step_hash(315);
    return g_159;
}
static int func_38(int ** p_39, int ** p_40, unsigned short p_41, int * p_42)
{
    unsigned l_206 = 0x812F185FL;
    step_hash(144);
    (*g_121) = (~(**p_40));
    step_hash(145);
    (*g_179) = l_206;
    step_hash(146);
    return l_206;
}
static int ** func_43(signed char p_44, unsigned p_45, int ** p_46, int p_47, unsigned p_48)
{
    unsigned short l_186 = 0x6F00L;
    int l_194 = 0xC581D854L;
    step_hash(118);
    (*g_178) = (*g_178);
    step_hash(141);
    for (g_180 = 0; (g_180 <= 17); g_180++)
    {
        int **l_191 = &g_179;
        step_hash(127);
        for (p_48 = 9; (p_48 == 4); --p_48)
        {
            int *l_185 = &g_159;
            step_hash(125);
            l_185 = (*p_46);
            step_hash(126);
            (*g_178) = (*p_46);
        }
        step_hash(128);
        l_194 = (l_186 > ((unsigned)((signed char)(p_47 < ((func_49(p_48, g_180) && 0UL) >= (l_191 != &g_179))) >> (signed char)5) / (unsigned)(((unsigned)g_180 / (unsigned)(*g_179)) && 0x46D9L)));
        step_hash(133);
        for (g_149 = 6; (g_149 != (-10)); g_149 -= 5)
        {
            step_hash(132);
            return p_46;
        }
        step_hash(140);
        if (((signed char)(l_186 > (**p_46)) * (signed char)g_149))
        {
            int *l_203 = &g_159;
            step_hash(135);
            (*l_203) = ((short)func_49(l_186, p_44) << (short)(+((unsigned char)p_48 / (unsigned char)p_47)));
            step_hash(136);
            if ((**p_46))
                break;
            step_hash(137);
            if ((*g_179))
                continue;
        }
        else
        {
            step_hash(139);
            (*g_22) = (**p_46);
        }
    }
    step_hash(142);
    return &g_121;
}
static signed char func_49(int p_50, unsigned char p_51)
{
    unsigned char l_56 = 1UL;
    int *l_57 = &g_21;
    step_hash(114);
    if (((unsigned short)p_51 / (unsigned short)p_51))
    {
        int **l_55 = &g_22;
        step_hash(18);
        (*g_22) = (*g_22);
        step_hash(19);
        (*l_55) = &g_21;
        step_hash(20);
        (*l_55) = (*l_55);
        step_hash(25);
        if (l_56)
        {
            step_hash(22);
            (*l_55) = l_57;
        }
        else
        {
            step_hash(24);
            (**l_55) &= 0L;
        }
    }
    else
    {
        unsigned short l_62 = 65526UL;
        int *l_86 = &g_21;
        int *l_111 = &g_21;
        step_hash(113);
        if (((signed char)(-3L) >> (signed char)((*l_57) <= g_4)))
        {
            short l_68 = 0xEE3BL;
            int *l_104 = &g_21;
            int l_173 = 0xA0AC9A06L;
            step_hash(41);
            if (((((short)l_62 + (short)g_21) || l_62) >= (((short)0xAFE4L << (short)(*l_57)) == ((signed char)(*l_57) - (signed char)g_4))))
            {
                short l_67 = 0x4D23L;
                step_hash(29);
                l_67 |= 0x576953C5L;
                step_hash(30);
                (*g_22) = (*g_22);
                step_hash(31);
                (*l_57) &= l_68;
            }
            else
            {
                unsigned l_83 = 0xB40ACB48L;
                step_hash(33);
                (*l_57) = ((+(g_21 == p_50)) == ((g_21 <= (((unsigned short)g_21 >> (unsigned short)3) || ((unsigned short)g_21 + (unsigned short)0x9320L))) && (p_50 | 255UL)));
                step_hash(40);
                if ((((unsigned short)(((unsigned char)((p_51 || (0x30L >= l_68)) > p_51) * (unsigned char)((unsigned short)(l_68 < ((short)0xAA2EL * (short)(p_51 >= (*l_57)))) * (unsigned short)((((unsigned char)0UL << (unsigned char)l_62) <= g_4) || p_50))) <= 9UL) >> (unsigned short)4) <= 0xDAEA480DL))
                {
                    step_hash(35);
                    (*g_22) |= l_83;
                }
                else
                {
                    int **l_84 = (void*)0;
                    int **l_85 = &l_57;
                    step_hash(37);
                    (*l_85) = &g_21;
                    step_hash(38);
                    (*l_86) = ((void*)0 == l_86);
                    step_hash(39);
                    (*g_22) ^= l_68;
                }
            }
            step_hash(103);
            if (((unsigned char)((unsigned short)((short)0L - (short)((+p_51) ^ (-10L))) >> (unsigned short)(4294967286UL ^ (((short)p_51 << (short)(*l_86)) <= ((short)g_21 << (short)(-(short)g_21))))) * (unsigned char)((unsigned)((signed char)((((g_21 || 1L) | (*g_22)) | l_68) | (*l_86)) - (signed char)g_4) % (unsigned)0xBBFFD320L)))
            {
                step_hash(43);
                return p_51;
            }
            else
            {
                int **l_105 = &l_104;
                step_hash(45);
                (*l_105) = l_104;
                step_hash(56);
                for (l_68 = (-17); (l_68 >= (-30)); l_68--)
                {
                    int *l_110 = &g_21;
                    step_hash(49);
                    (*l_105) = l_104;
                    step_hash(50);
                    if ((*l_57))
                        break;
                    step_hash(55);
                    for (g_21 = 0; (g_21 >= 23); ++g_21)
                    {
                        step_hash(54);
                        l_110 = l_110;
                    }
                }
                step_hash(62);
                if (((*l_86) & (0x4E6BL <= p_50)))
                {
                    step_hash(58);
                    (*l_86) = (*g_22);
                }
                else
                {
                    step_hash(60);
                    (*l_105) = l_111;
                    step_hash(61);
                    (*l_111) = ((unsigned short)p_51 >> (unsigned short)9);
                }
                step_hash(102);
                if (((*l_57) < g_21))
                {
                    unsigned short l_120 = 0x1D39L;
                    signed char l_132 = (-1L);
                    int *l_133 = &g_21;
                    step_hash(64);
                    l_111 = l_57;
                    step_hash(70);
                    for (p_50 = 0; (p_50 > 16); ++p_50)
                    {
                        step_hash(68);
                        if (p_51)
                            break;
                        step_hash(69);
                        (*l_105) = l_57;
                    }
                    step_hash(71);
                    (*l_105) = l_86;
                    step_hash(79);
                    if (((((short)((65535UL || l_120) < g_4) + (short)p_51) & ((void*)0 == g_121)) == ((1L && p_50) != ((unsigned short)(((short)((unsigned char)(((signed char)((int)(*g_22) / (int)(*l_57)) % (signed char)g_21) > p_50) % (unsigned char)(*l_57)) + (short)p_50) != l_132) % (unsigned short)(**l_105)))))
                    {
                        unsigned l_134 = 0UL;
                        step_hash(73);
                        (*l_105) = l_133;
                        step_hash(74);
                        g_121 = &g_21;
                        step_hash(75);
                        return l_134;
                    }
                    else
                    {
                        int *l_141 = &g_142;
                        step_hash(77);
                        (*l_105) = &g_21;
                        step_hash(78);
                        (*l_141) |= ((unsigned)((unsigned short)((unsigned char)(p_50 ^ g_4) >> (unsigned char)g_21) / (unsigned short)p_51) - (unsigned)(((void*)0 == &l_57) >= p_50));
                    }
                }
                else
                {
                    unsigned char l_145 = 251UL;
                    int *l_146 = &g_21;
                    step_hash(85);
                    if (((unsigned)(l_145 > ((void*)0 == l_146)) % (unsigned)((short)p_51 * (short)p_51)))
                    {
                        step_hash(82);
                        (*l_57) = g_149;
                    }
                    else
                    {
                        step_hash(84);
                        return (*l_146);
                    }
                    step_hash(92);
                    for (l_145 = 3; (l_145 > 31); l_145 += 9)
                    {
                        int *l_158 = &g_159;
                        step_hash(89);
                        (*g_121) = ((((short)(g_142 && g_149) << (short)((short)p_51 << (short)14)) & 0x02147657L) ^ p_50);
                        step_hash(90);
                        (*g_22) = ((*l_86) && g_4);
                        step_hash(91);
                        (*l_158) ^= ((**l_105) <= (((unsigned char)(g_142 | (p_50 & (*l_111))) >> (unsigned char)6) > p_50));
                    }
                    step_hash(93);
                    (*l_104) ^= (((unsigned short)(0xDDL > p_50) % (unsigned short)g_149) || p_51);
                    step_hash(101);
                    for (l_68 = 15; (l_68 > 11); l_68 -= 2)
                    {
                        unsigned short l_172 = 8UL;
                        step_hash(97);
                        (*l_57) = (*g_22);
                        step_hash(98);
                        (*g_121) = (((((unsigned char)253UL << (unsigned char)(*l_57)) || (((unsigned short)g_149 * (unsigned short)(g_149 > (g_159 > ((signed char)((unsigned short)l_172 / (unsigned short)p_51) * (signed char)((void*)0 != &g_121))))) && p_51)) | l_172) && g_159);
                        step_hash(99);
                        l_173 |= (*l_86);
                        step_hash(100);
                        (*l_86) |= 1L;
                    }
                }
            }
        }
        else
        {
            step_hash(110);
            for (l_56 = (-19); (l_56 != 18); l_56 += 4)
            {
                step_hash(108);
                (*l_86) = p_51;
                step_hash(109);
                return g_149;
            }
            step_hash(111);
            (*l_111) = p_51;
            step_hash(112);
            (*g_121) = (0xB56EB578L | (*l_57));
        }
    }
    step_hash(115);
    (*l_57) = (!p_50);
    step_hash(116);
    return (*l_57);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_21, "g_21", print_hash_value);
    transparent_crc(g_142, "g_142", print_hash_value);
    transparent_crc(g_149, "g_149", print_hash_value);
    transparent_crc(g_159, "g_159", print_hash_value);
    transparent_crc(g_180, "g_180", print_hash_value);
    transparent_crc(g_205, "g_205", print_hash_value);
    transparent_crc(g_341, "g_341", print_hash_value);
    transparent_crc(g_372, "g_372", print_hash_value);
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
