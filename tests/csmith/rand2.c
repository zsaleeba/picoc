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
static signed char g_8 = 0x75L;
static signed char g_22 = (-1L);
static int g_64 = 1L;
static int *g_68 = &g_64;
static int **g_67 = &g_68;
static int g_75 = 0L;
static int g_91 = 0xDAF140B3L;
static int g_105 = 0x2C2F6A78L;
static int *g_104 = &g_105;
static int **g_103 = &g_104;
static int ***g_102 = &g_103;
static int *g_143 = &g_75;
static int g_179 = 0x23E01F0FL;
static int g_354 = 0x902B26BEL;
static int g_385 = 0xD7647D74L;
static int ***g_397 = &g_103;
static unsigned char g_432 = 8UL;
static int g_606 = 0xA1DD7417L;
static int g_624 = 1L;
static short g_652 = 0L;
static short func_1(void);
static int func_2(short p_3, unsigned p_4, unsigned p_5, unsigned char p_6, short p_7);
static unsigned func_9(unsigned p_10);
static unsigned func_15(unsigned p_16, unsigned p_17, unsigned short p_18, int p_19, unsigned short p_20);
static short func_26(int p_27);
static unsigned func_33(int p_34, unsigned p_35);
static unsigned char func_38(short p_39);
static int func_52(unsigned short p_53, unsigned short p_54);
static int * func_55(short p_56, int * p_57, unsigned p_58);
static unsigned short func_59(int * p_60, int * p_61, int * p_62);
static short func_1(void)
{
    unsigned char l_215 = 255UL;
    int ***l_274 = &g_103;
    int *l_306 = (void*)0;
    int l_307 = 0x5F59F456L;
    short l_332 = 2L;
    int l_337 = 2L;
    unsigned l_353 = 0xE6E42AD6L;
    int l_386 = 0x0ADE143DL;
    int l_398 = 0x15C698CBL;
    unsigned short l_454 = 65528UL;
    unsigned short l_468 = 65532UL;
    int l_495 = 0x89C1980AL;
    unsigned l_525 = 0UL;
    int *l_582 = &g_91;
    int ***l_625 = &g_103;
    unsigned short l_715 = 65535UL;
    signed char l_718 = 1L;
    int *l_719 = (void*)0;
    step_hash(486);
    if (func_2(g_8, ((func_9(g_8) > 0L) <= ((signed char)0x22L + (signed char)func_15(func_38((func_26((((((unsigned)g_91 + (unsigned)5L) & ((unsigned short)(0UL || ((signed char)(&g_67 == (void*)0) / (signed char)l_215)) % (unsigned short)0x169CL)) && g_91) | l_215)) == g_75)), g_179, g_22, l_215, l_215))), g_179, g_22, l_215))
    {
        int ***l_249 = &g_103;
        short l_305 = 0x6832L;
        step_hash(235);
        for (g_64 = 17; (g_64 == 27); ++g_64)
        {
            unsigned char l_236 = 0x59L;
            step_hash(188);
            (**g_103) = (((unsigned char)func_9(((short)0x0A95L << (short)(!l_215))) << (unsigned char)5) != ((func_26(l_236) | ((unsigned char)(l_215 ^ ((unsigned)l_236 + (unsigned)g_22)) * (unsigned char)g_8)) == g_91));
            step_hash(233);
            for (g_91 = 0; (g_91 == (-10)); g_91 -= 9)
            {
                unsigned l_259 = 6UL;
                unsigned char l_280 = 0xDDL;
                step_hash(201);
                for (g_75 = 0; (g_75 < 22); g_75++)
                {
                    unsigned char l_250 = 0x0DL;
                    step_hash(195);
                    (**g_103) = (((signed char)g_8 % (signed char)((unsigned char)(l_249 != &g_67) + (unsigned char)g_22)) >= (func_26(l_250) <= ((unsigned short)((short)l_236 >> (short)(~((unsigned)((int)(-1L) - (int)((g_179 <= l_259) || 0x90L)) + (unsigned)(**g_67)))) << (unsigned short)1)));
                    step_hash(200);
                    for (l_250 = 0; (l_250 != 10); l_250 += 2)
                    {
                        step_hash(199);
                        (**g_103) = l_250;
                    }
                }
                step_hash(232);
                if (((signed char)((unsigned char)((short)(g_91 || ((unsigned short)l_259 >> (unsigned short)((int)l_236 - (int)(((short)((*g_102) == (*g_102)) << (short)3) != g_179)))) >> (short)6) - (unsigned char)func_26(l_215)) * (signed char)((l_274 != l_274) | g_91)))
                {
                    short l_277 = (-1L);
                    step_hash(203);
                    (**l_274) = (*g_103);
                    step_hash(210);
                    for (g_105 = (-2); (g_105 >= (-26)); --g_105)
                    {
                        step_hash(207);
                        (*g_143) = (*g_143);
                        step_hash(208);
                        if (l_277)
                            continue;
                        step_hash(209);
                        (*g_143) = ((void*)0 == (**g_102));
                    }
                }
                else
                {
                    int *l_281 = &g_179;
                    step_hash(212);
                    (*l_281) &= ((short)l_280 % (short)func_26(g_75));
                    step_hash(220);
                    for (g_75 = 0; (g_75 <= 20); g_75++)
                    {
                        signed char l_284 = 0xCFL;
                        step_hash(216);
                        if ((***l_274))
                            break;
                        step_hash(217);
                        (**g_103) = ((void*)0 == (**g_102));
                        step_hash(218);
                        (**l_249) = l_281;
                        step_hash(219);
                        (***l_274) = ((0xE833L ^ l_259) ^ l_284);
                    }
                    step_hash(226);
                    for (l_215 = 0; (l_215 <= 39); l_215 += 2)
                    {
                        int l_287 = 0x03CA480CL;
                        step_hash(224);
                        l_287 = func_9(func_26(g_179));
                        step_hash(225);
                        return l_287;
                    }
                    step_hash(231);
                    for (l_259 = 14; (l_259 < 6); l_259--)
                    {
                        step_hash(230);
                        (***l_249) = ((void*)0 != (*g_102));
                    }
                }
            }
            step_hash(234);
            if (l_236)
                continue;
        }
        step_hash(236);
        (*g_68) &= (***l_274);
        step_hash(276);
        for (g_8 = (-16); (g_8 > (-23)); g_8 -= 9)
        {
            int *l_294 = &g_75;
            int l_352 = 0xAB85A483L;
            step_hash(240);
            if ((*g_104))
                break;
        }
    }
    else
    {
        signed char l_367 = 0xC7L;
        unsigned l_374 = 4294967293UL;
        int l_414 = 1L;
        int ***l_467 = &g_67;
        unsigned char l_536 = 0UL;
        int l_630 = 9L;
        int *l_635 = &l_414;
        step_hash(326);
        for (g_91 = (-15); (g_91 <= 14); g_91++)
        {
            unsigned char l_361 = 1UL;
            int l_375 = 0x321761CEL;
            step_hash(281);
            (***l_274) &= (**g_67);
            step_hash(282);
            (*g_67) = (*g_67);
            step_hash(290);
            for (l_332 = 0; (l_332 > 24); l_332 += 1)
            {
                step_hash(286);
                (*g_104) = func_9(((short)g_179 % (short)(g_91 | g_8)));
                step_hash(287);
                if (l_361)
                    break;
                step_hash(288);
                (**g_103) ^= (*g_68);
                step_hash(289);
                (*g_143) ^= (**g_103);
            }
            step_hash(325);
            for (l_337 = (-18); (l_337 >= (-24)); l_337 -= 1)
            {
                unsigned short l_366 = 0x0276L;
                int *l_369 = &g_64;
                int *l_396 = (void*)0;
                step_hash(306);
                if (((unsigned short)g_354 / (unsigned short)0x91B3L))
                {
                    short l_368 = 0x22A9L;
                    step_hash(302);
                    if ((((!0x69265085L) == (((-1L) ^ (func_26((***l_274)) <= l_366)) == l_367)) <= (*g_143)))
                    {
                        step_hash(296);
                        (**g_103) |= 1L;
                        step_hash(297);
                        (***g_102) &= (*g_143);
                        step_hash(298);
                        (**l_274) = (*g_103);
                    }
                    else
                    {
                        step_hash(300);
                        if ((**g_103))
                            break;
                        step_hash(301);
                        if ((**g_103))
                            continue;
                    }
                    step_hash(303);
                    l_368 = (-1L);
                }
                else
                {
                    step_hash(305);
                    (*g_104) &= (&g_103 != &g_103);
                }
                step_hash(307);
                (*g_67) = l_369;
                step_hash(323);
                if ((((l_361 == 0xE2196DACL) < ((unsigned short)func_15(g_75, ((unsigned short)1UL * (unsigned short)l_361), (***l_274), func_15(l_374, (*l_369), g_64, (**g_67), g_8), g_75) << (unsigned short)g_354)) > l_375))
                {
                    int ***l_382 = &g_67;
                    step_hash(309);
                    (*g_68) = func_59((*g_67), (**l_274), (*g_103));
                    step_hash(310);
                    (*l_369) = l_375;
                    step_hash(311);
                    l_386 &= ((((int)((unsigned short)((short)(!func_15(g_64, ((!((func_26((l_382 == (void*)0)) || 0x3D97L) | (((short)((((func_9((g_75 & (!g_8))) <= (g_91 == 0x28L)) > (*l_369)) & 0xFC06L) | g_64) / (short)g_75) >= (*g_68)))) ^ 0UL), g_91, (*l_369), l_374)) % (short)g_91) << (unsigned short)4) % (int)g_385) && 0xCF0B019CL) && (*l_369));
                }
                else
                {
                    short l_388 = 4L;
                    int *l_395 = (void*)0;
                    step_hash(322);
                    if (((void*)0 != (*l_274)))
                    {
                        int l_399 = 0x3ABCC576L;
                        step_hash(314);
                        (*g_104) = ((!0xCF50B0D8L) != g_8);
                        step_hash(315);
                        (**g_103) = (((-(unsigned char)l_388) ^ func_15((~(((unsigned)((unsigned short)(255UL || ((short)func_59(l_395, (*g_67), l_396) * (short)(g_397 != &g_103))) >> (unsigned short)2) / (unsigned)l_398) != l_388)), l_399, l_375, (*g_143), l_367)) && (-1L));
                        step_hash(316);
                        (*l_369) = (g_64 ^ func_26(g_179));
                        step_hash(317);
                        (**g_103) = 0xD4551E3BL;
                    }
                    else
                    {
                        step_hash(319);
                        if ((***l_274))
                            break;
                        step_hash(320);
                        (**g_102) = (**g_397);
                        step_hash(321);
                        (***g_397) = l_375;
                    }
                }
                step_hash(324);
                (**l_274) = (**g_397);
            }
        }
        step_hash(327);
        l_414 ^= (func_15(((signed char)((!((short)((signed char)0x24L % (signed char)0x62L) - (short)65535UL)) == ((short)((int)(((*g_68) > (g_105 | g_385)) | (+((int)0L - (int)((signed char)g_385 >> (signed char)((*g_67) == (**g_397)))))) + (int)l_367) >> (short)9)) % (signed char)g_354), g_91, g_22, (***l_274), g_385) && (-9L));
        step_hash(428);
        if ((((unsigned char)(!0x54L) << (unsigned char)7) < g_385))
        {
            short l_419 = 0L;
            unsigned l_429 = 0xD1FFF403L;
            step_hash(329);
            (*g_143) &= (~(g_105 || (l_414 && ((unsigned short)(l_419 <= ((*g_397) != (*g_397))) % (unsigned short)l_419))));
            step_hash(365);
            for (g_75 = 0; (g_75 == 19); ++g_75)
            {
                unsigned short l_426 = 0xE9E5L;
                step_hash(333);
                (**g_67) &= ((***l_274) == g_22);
                step_hash(344);
                for (l_353 = 2; (l_353 > 14); l_353++)
                {
                    step_hash(343);
                    for (g_22 = 0; (g_22 == (-7)); g_22 -= 3)
                    {
                        step_hash(340);
                        if (l_419)
                            break;
                        step_hash(341);
                        (**g_103) = (l_426 || g_179);
                        step_hash(342);
                        if ((*g_68))
                            break;
                    }
                }
                step_hash(363);
                for (g_91 = 0; (g_91 != (-13)); --g_91)
                {
                }
                step_hash(364);
                return l_374;
            }
        }
        else
        {
            int **l_441 = &l_306;
            int l_481 = 0x5F1969B3L;
            unsigned short l_522 = 65534UL;
            step_hash(405);
            for (g_105 = 0; (g_105 <= 8); g_105 += 5)
            {
                int ***l_440 = (void*)0;
                step_hash(370);
                if ((*g_143))
                    break;
                step_hash(375);
                for (g_432 = 0; (g_432 <= 8); ++g_432)
                {
                    unsigned l_437 = 0x70CEF403L;
                    step_hash(374);
                    return l_437;
                }
                step_hash(393);
                for (g_354 = 26; (g_354 != 0); g_354--)
                {
                    step_hash(385);
                    if (((void*)0 == l_440))
                    {
                        step_hash(380);
                        (*g_102) = l_441;
                        step_hash(381);
                        if (l_374)
                            break;
                    }
                    else
                    {
                        step_hash(383);
                        (**g_102) = (**g_102);
                        step_hash(384);
                        if ((**g_67))
                            break;
                    }
                    step_hash(386);
                    (**g_67) = ((int)0L % (int)(func_9(g_385) & ((((**g_67) == ((*g_397) == l_441)) < ((short)0L * (short)0UL)) & 0xB8L)));
                    step_hash(392);
                    for (g_91 = 0; (g_91 > (-22)); --g_91)
                    {
                        signed char l_448 = 0x54L;
                        step_hash(390);
                        (**g_67) = (((((g_8 != l_448) >= 0x7247L) > g_75) == l_374) >= ((l_448 > g_64) > func_9(l_414)));
                        step_hash(391);
                        (*g_143) &= (**g_67);
                    }
                }
                step_hash(404);
                for (l_215 = 21; (l_215 != 57); ++l_215)
                {
                    int **l_451 = &g_143;
                    int l_455 = 0L;
                    unsigned l_456 = 4294967295UL;
                    step_hash(397);
                    l_451 = (void*)0;
                    step_hash(403);
                    for (g_432 = 0; (g_432 <= 49); g_432++)
                    {
                        step_hash(401);
                        (**g_102) = (**g_397);
                        step_hash(402);
                        l_414 &= (((((((**g_102) != (*g_103)) < l_454) && ((0x607B733AL <= (g_91 & (g_105 <= ((g_385 == g_91) & (((void*)0 != (**l_274)) == g_354))))) >= l_455)) <= l_456) <= 8L) && 0x4682L);
                    }
                }
            }
            step_hash(406);
            (*g_143) = (*g_143);
            step_hash(426);
            for (l_337 = 0; (l_337 > (-24)); l_337 -= 7)
            {
                int l_478 = (-6L);
                int ***l_484 = (void*)0;
                int **l_513 = &l_306;
                int *l_523 = &g_385;
                signed char l_524 = 0L;
                step_hash(422);
                if (((unsigned short)(0xB0L == (((short)(65535UL && g_22) * (short)((unsigned)((((short)func_59((**l_467), (*l_441), (*l_441)) >> (short)6) & g_354) == g_179) - (unsigned)g_179)) == 65535UL)) - (unsigned short)g_22))
                {
                    unsigned short l_469 = 0UL;
                    step_hash(411);
                    (*g_68) ^= (g_432 > l_469);
                    step_hash(412);
                    (*g_143) = ((signed char)((short)(((unsigned)g_8 - (unsigned)((signed char)0x10L - (signed char)l_478)) > ((((signed char)(!(l_481 > 0x9DF3D125L)) >> (signed char)4) || ((***l_467) | 0xF792E4AFL)) == g_22)) >> (short)g_354) >> (signed char)g_91);
                    step_hash(417);
                    if (l_478)
                    {
                        step_hash(414);
                        (**g_67) = ((short)5L + (short)(l_484 != (void*)0));
                    }
                    else
                    {
                        step_hash(416);
                        (**l_274) = (*g_103);
                    }
                }
                else
                {
                    int *l_496 = &g_179;
                    step_hash(419);
                    if ((*g_143))
                        break;
                    step_hash(420);
                    (*l_496) ^= (((unsigned)((0x287AL & (!((*g_102) == (void*)0))) | g_354) % (unsigned)((unsigned short)(((unsigned short)func_52(((short)g_385 << (short)((unsigned short)((***l_467) & (g_354 && func_26(l_495))) % (unsigned short)0xFA3FL)), g_354) / (unsigned short)g_432) != (-1L)) / (unsigned short)g_385)) && (***l_467));
                    step_hash(421);
                    (***l_467) = ((short)((int)1L + (int)((unsigned char)(g_64 || 1UL) * (unsigned char)(((int)((unsigned char)(*l_496) >> (unsigned char)1) % (int)func_9(l_481)) && ((unsigned char)(1L <= (((signed char)0xACL << (signed char)2) == ((g_91 >= g_385) > (*g_143)))) - (unsigned char)0xC9L)))) << (short)4);
                }
                step_hash(423);
                (*l_523) |= (((((-1L) || g_64) ^ func_9(g_75)) & ((int)(l_513 != (void*)0) - (int)((unsigned short)g_64 << (unsigned short)3))) & ((unsigned short)((unsigned short)((*g_143) >= ((func_26(((int)(-6L) - (int)(**g_67))) && l_481) || g_8)) - (unsigned short)l_522) * (unsigned short)65531UL));
                step_hash(424);
                if (l_524)
                    continue;
                step_hash(425);
                if (l_525)
                    continue;
            }
            step_hash(427);
            (*g_143) |= ((unsigned short)g_354 + (unsigned short)((***l_467) | 0x17L));
        }
        step_hash(485);
        for (l_307 = (-13); (l_307 == 9); l_307 += 2)
        {
            unsigned char l_530 = 0xEFL;
            int *l_531 = &l_414;
            int *l_583 = &g_91;
            signed char l_588 = 0xA1L;
            unsigned l_653 = 0x61509602L;
            int l_661 = (-2L);
            int *l_662 = (void*)0;
            step_hash(432);
            (*g_67) = func_55(((l_530 == (*g_143)) != func_9(g_91)), l_531, g_432);
            step_hash(484);
            if (((signed char)(***l_467) >> (signed char)4))
            {
                unsigned short l_548 = 0x409CL;
                int **l_571 = &g_68;
                step_hash(447);
                for (l_215 = 0; (l_215 != 51); l_215++)
                {
                    int l_549 = 0x5597FE77L;
                    step_hash(437);
                    (**g_67) &= l_536;
                    step_hash(438);
                    if ((**g_67))
                        continue;
                    step_hash(445);
                    if (((unsigned)((0xBDL != (func_2(((unsigned short)g_385 + (unsigned short)0xC4A6L), (+(((unsigned short)func_15((((int)(-(short)g_354) - (int)(***l_467)) == (*l_531)), (!((short)((**g_67) & 0xE84D8DF7L) * (short)g_105)), (*l_531), (*g_143), (***l_467)) * (unsigned short)l_548) == (*g_143))), l_549, g_432, g_385) <= g_105)) || 0x77E1L) + (unsigned)g_105))
                    {
                        unsigned char l_554 = 254UL;
                        int **l_567 = &l_531;
                        int **l_568 = (void*)0;
                        step_hash(440);
                        (*g_143) |= (((((((unsigned short)(*l_531) % (unsigned short)l_554) | (0x610EL >= ((unsigned short)(&l_549 == (**g_102)) / (unsigned short)l_548))) == l_549) < (!l_549)) == (g_179 != 0x6775L)) > (**g_67));
                        step_hash(441);
                        (*l_531) ^= l_549;
                        step_hash(442);
                        (**l_567) = (((short)((unsigned char)((unsigned char)0x0DL << (unsigned char)2) / (unsigned char)((unsigned short)l_554 + (unsigned short)((((unsigned short)((func_52(g_105, l_549) != (*l_531)) != (0xB4E2088BL != (l_567 != l_568))) / (unsigned short)65533UL) != 0x88L) <= 0x7C48L))) >> (short)6) || g_105);
                    }
                    else
                    {
                        step_hash(444);
                        (*g_68) = (*l_531);
                    }
                    step_hash(446);
                    (***l_467) = (((signed char)(&l_531 != (*g_102)) >> (signed char)3) >= (l_571 == l_571));
                }
                step_hash(448);
                (*l_531) = (&l_531 == (*g_102));
                step_hash(466);
                for (g_354 = (-5); (g_354 < (-15)); g_354 -= 8)
                {
                    int ***l_605 = &g_67;
                }
            }
            else
            {
                int l_654 = 0x98395975L;
                int **l_657 = (void*)0;
                step_hash(468);
                (*l_582) |= ((short)0x4546L % (short)func_15((((signed char)g_105 - (signed char)((unsigned short)((unsigned short)(((((short)((((void*)0 != (*l_274)) | (((unsigned char)((g_432 & (**g_67)) || ((unsigned char)((short)0x9D88L >> (short)0) * (unsigned char)(***l_467))) - (unsigned char)g_624) != g_385)) >= 0x417BL) << (short)g_652) > (-1L)) >= 1L) == g_179) + (unsigned short)l_653) + (unsigned short)l_654)) ^ g_606), g_652, l_654, (*l_635), l_654));
                step_hash(482);
                if ((*g_68))
                {
                    int *l_658 = (void*)0;
                    int l_702 = (-1L);
                    step_hash(476);
                    for (g_22 = 18; (g_22 >= 7); g_22--)
                    {
                        unsigned char l_663 = 0UL;
                        signed char l_696 = 0xE6L;
                        int *l_697 = &l_386;
                        step_hash(473);
                        (**l_274) = l_662;
                        step_hash(474);
                        (*l_635) = ((((!func_15(g_179, l_663, (-(signed char)(((((int)l_663 % (int)(l_663 & (-(unsigned)(g_624 || 0L)))) <= (*l_635)) && (***l_467)) < ((signed char)func_26((g_354 && g_105)) % (signed char)g_91))), l_663, g_91)) & g_22) >= l_663) >= g_385);
                        step_hash(475);
                        (*g_143) = ((unsigned)4294967287UL - (unsigned)(((0xCF2E55F8L | ((signed char)(((unsigned char)((short)(func_2(((signed char)(((signed char)(func_59((**g_102), l_697, l_658) > (*g_143)) + (signed char)(*l_531)) != 0UL) >> (signed char)7), g_606, g_354, (*l_635), g_606) == (*l_582)) % (short)g_652) % (unsigned char)g_606) >= 2UL) << (signed char)g_91)) < g_606) == g_385));
                    }
                    step_hash(477);
                    (***l_467) = (g_652 <= (0x1E857C9BL && func_26((*l_531))));
                    step_hash(478);
                    if ((*g_68))
                        continue;
                    step_hash(479);
                    (*g_143) = ((g_105 < ((unsigned char)g_75 << (unsigned char)7)) & (func_9((g_91 < func_59((**g_102), l_658, (**l_625)))) > l_702));
                }
                else
                {
                    step_hash(481);
                    return g_91;
                }
                step_hash(483);
                (***l_467) = func_26((*l_635));
            }
        }
    }
    step_hash(487);
    (*l_582) = ((unsigned char)(g_624 <= ((unsigned short)((*g_143) != ((int)(*l_582) - (int)((**g_102) == (void*)0))) >> (unsigned short)((short)((g_179 <= ((((short)(*l_582) >> (short)10) && ((1UL < (0xFFE4L || 0x1725L)) == g_91)) <= l_715)) != g_64) << (short)15))) - (unsigned char)0UL);
    step_hash(488);
    (*l_582) = ((short)(&g_103 == l_274) * (short)l_718);
    step_hash(489);
    (**g_102) = (**g_397);
    step_hash(490);
    return g_354;
}
static int func_2(short p_3, unsigned p_4, unsigned p_5, unsigned char p_6, short p_7)
{
    unsigned l_216 = 1UL;
    unsigned l_228 = 0UL;
    int l_229 = 0x4C012C7DL;
    step_hash(181);
    if (p_3)
    {
        step_hash(163);
        l_216 |= p_7;
    }
    else
    {
        step_hash(179);
        if ((**g_67))
        {
            step_hash(171);
            for (p_7 = 6; (p_7 == (-27)); p_7 -= 1)
            {
                int *l_223 = (void*)0;
            }
            step_hash(172);
            (**g_67) |= ((-5L) | ((unsigned char)248UL << (unsigned char)7));
        }
        else
        {
            step_hash(178);
            for (p_7 = 0; (p_7 > (-14)); p_7 -= 6)
            {
                step_hash(177);
                (*g_143) &= (p_4 > g_8);
            }
        }
        step_hash(180);
        (**g_67) = ((p_6 > (g_179 ^ 0xF879L)) & p_7);
    }
    step_hash(182);
    l_229 = (l_216 != l_228);
    step_hash(183);
    return p_5;
}
static unsigned func_9(unsigned p_10)
{
    unsigned l_25 = 1UL;
    int l_204 = (-4L);
    step_hash(159);
    for (p_10 = (-6); (p_10 != 23); p_10++)
    {
        unsigned char l_21 = 0x06L;
        int *l_202 = &g_105;
    }
    step_hash(160);
    return l_25;
}
static unsigned func_15(unsigned p_16, unsigned p_17, unsigned short p_18, int p_19, unsigned short p_20)
{
    unsigned short l_184 = 0x159BL;
    int *l_193 = &g_105;
    step_hash(145);
    (**g_67) = (((int)l_184 - (int)l_184) > (l_184 | (((signed char)p_19 >> (signed char)((short)g_64 * (short)(p_16 == l_184))) < (0x52L >= 3UL))));
    step_hash(146);
    l_193 = l_193;
    step_hash(147);
    return g_64;
}
static short func_26(int p_27)
{
    short l_32 = 0xAB5CL;
    step_hash(137);
    for (p_27 = 0; (p_27 < (-23)); --p_27)
    {
        int *l_176 = (void*)0;
        int *l_177 = (void*)0;
        int *l_178 = &g_179;
    }
    step_hash(142);
    for (g_105 = 0; (g_105 >= (-2)); --g_105)
    {
        step_hash(141);
        return g_22;
    }
    step_hash(143);
    return g_22;
}
static unsigned func_33(int p_34, unsigned p_35)
{
    int l_113 = 0x8A2FD92DL;
    unsigned char l_128 = 0xD5L;
    int l_133 = 0L;
    int l_135 = (-1L);
    int *l_140 = &l_135;
    unsigned l_150 = 0x6180BEB1L;
    int *l_173 = &g_91;
    step_hash(134);
    if (((unsigned char)func_38(p_34) << (unsigned char)g_8))
    {
        int l_115 = 0xB600A8D5L;
        int *l_139 = (void*)0;
        step_hash(121);
        if ((((void*)0 != (**g_102)) <= ((unsigned short)(((*g_102) == (void*)0) >= ((short)p_35 << (short)p_35)) % (unsigned short)((unsigned short)l_113 << (unsigned short)8))))
        {
            int *l_114 = &g_105;
            unsigned l_134 = 0x483285BFL;
            step_hash(77);
            l_115 &= func_59(func_55(g_22, (*g_67), g_64), (*g_103), l_114);
            step_hash(87);
            if (((signed char)(1L <= ((unsigned)((unsigned char)l_115 << (unsigned char)6) % (unsigned)func_38((*l_114)))) * (signed char)0xF8L))
            {
                step_hash(79);
                l_135 |= (((unsigned short)(((p_34 && ((g_8 < (((unsigned)0x416FBB8AL / (unsigned)g_22) ^ (g_75 || (((unsigned char)p_34 - (unsigned char)l_128) < ((((unsigned short)((signed char)(+l_133) << (signed char)func_38(l_134)) + (unsigned short)p_34) < 0x71L) || g_8))))) || (**g_103))) > p_35) || p_35) >> (unsigned short)g_8) | g_8);
            }
            else
            {
                unsigned l_138 = 0x03BCFB6DL;
                step_hash(85);
                if (((signed char)(l_138 || g_75) - (signed char)func_59(&p_34, l_139, (*g_67))))
                {
                    step_hash(82);
                    return l_113;
                }
                else
                {
                    step_hash(84);
                    l_140 = (void*)0;
                }
                step_hash(86);
                (*g_67) = &p_34;
            }
            step_hash(88);
            return p_35;
        }
        else
        {
            int *l_156 = &g_105;
            step_hash(90);
            (***g_102) ^= p_35;
            step_hash(118);
            for (g_75 = 0; (g_75 != (-24)); g_75 -= 8)
            {
                unsigned char l_167 = 0UL;
                step_hash(94);
                (*g_67) = g_143;
                step_hash(95);
                (**g_102) = (*g_103);
                step_hash(117);
                if (((unsigned char)(((~p_34) < ((p_35 || g_64) || ((short)p_35 << (short)1))) || g_64) >> (unsigned char)6))
                {
                    step_hash(101);
                    for (p_34 = 7; (p_34 >= 3); p_34--)
                    {
                        step_hash(100);
                        (*l_140) ^= (g_75 >= p_35);
                    }
                    step_hash(102);
                    (**g_103) = p_34;
                    step_hash(103);
                    (**g_103) ^= (-3L);
                    step_hash(104);
                    (*g_104) = ((l_150 & (!((250UL & func_59((*g_103), (**g_102), (*g_67))) < p_35))) | (250UL < p_34));
                }
                else
                {
                    unsigned short l_153 = 65535UL;
                    int l_162 = 0x0DF5CE33L;
                    step_hash(110);
                    if (((short)l_153 << (short)((short)g_105 % (short)func_59(&p_34, l_156, (*g_67)))))
                    {
                        unsigned short l_157 = 0x7298L;
                        step_hash(107);
                        return l_157;
                    }
                    else
                    {
                        step_hash(109);
                        (*l_140) = 2L;
                    }
                    step_hash(115);
                    for (l_115 = 0; (l_115 < (-16)); l_115 -= 8)
                    {
                        step_hash(114);
                        (*g_102) = (*g_102);
                    }
                    step_hash(116);
                    (*l_156) = ((l_162 && ((((unsigned char)p_35 / (unsigned char)((short)g_64 % (short)(*l_140))) != l_162) > (*l_156))) == l_167);
                }
            }
            step_hash(119);
            (*l_156) = (((signed char)func_52(g_22, (*l_156)) - (signed char)p_35) || 0x12L);
            step_hash(120);
            (*g_104) ^= (*l_140);
        }
        step_hash(122);
        (**g_103) = l_115;
        step_hash(123);
        return g_75;
    }
    else
    {
        step_hash(125);
        (**g_67) ^= p_34;
        step_hash(132);
        for (l_150 = (-28); (l_150 > 29); l_150++)
        {
            int *l_172 = (void*)0;
            step_hash(129);
            (*g_103) = l_172;
            step_hash(130);
            l_172 = func_55(p_35, l_173, g_91);
            step_hash(131);
            (*l_172) = ((unsigned short)p_34 << (unsigned short)3);
        }
        step_hash(133);
        (*g_143) = p_34;
    }
    step_hash(135);
    return g_8;
}
static unsigned char func_38(short p_39)
{
    signed char l_49 = 0x30L;
    step_hash(15);
    for (p_39 = (-30); (p_39 <= 26); p_39 += 1)
    {
        unsigned short l_42 = 1UL;
        step_hash(14);
        if (l_42)
            break;
    }
    step_hash(73);
    if (((unsigned short)(((0UL || ((signed char)((((unsigned short)l_49 >> (unsigned short)l_49) != (((int)func_52(p_39, g_8) / (int)((unsigned short)((void*)0 != g_102) << (unsigned short)g_105)) <= (**g_103))) > (-1L)) % (signed char)0x19L)) & l_49) >= l_49) * (unsigned short)g_22))
    {
        int l_106 = 0L;
        step_hash(69);
        (**g_103) &= (*g_68);
        step_hash(70);
        l_106 = (!(**g_67));
    }
    else
    {
        step_hash(72);
        return g_105;
    }
    step_hash(74);
    return p_39;
}
static int func_52(unsigned short p_53, unsigned short p_54)
{
    int *l_63 = &g_64;
    int **l_92 = &l_63;
    step_hash(58);
    (*l_92) = func_55((((p_53 == p_54) != (~g_8)) || (((func_59(l_63, &g_64, &g_64) || ((unsigned)g_64 - (unsigned)(0x3A5CL != g_8))) < g_8) == 0L)), l_63, g_22);
    step_hash(66);
    for (g_64 = (-12); (g_64 > (-29)); --g_64)
    {
        int *l_99 = &g_91;
        step_hash(62);
        (*l_92) = (*g_67);
        step_hash(63);
        (*l_99) = ((int)((signed char)(0x3FD17753L || (p_53 == ((*l_92) == (*g_67)))) >> (signed char)0) - (int)p_54);
        step_hash(64);
        if ((**g_67))
            continue;
        step_hash(65);
        (*l_99) |= 0x449D4C0FL;
    }
    step_hash(67);
    return (**l_92);
}
static int * func_55(short p_56, int * p_57, unsigned p_58)
{
    signed char l_80 = 0xB2L;
    unsigned l_88 = 0UL;
    step_hash(56);
    for (g_64 = 0; (g_64 <= (-15)); g_64 -= 8)
    {
        int *l_74 = &g_75;
        step_hash(28);
        (*l_74) = (*g_68);
        step_hash(39);
        if ((0x3BL == (0xA2B52F10L >= (*p_57))))
        {
            unsigned short l_81 = 6UL;
            step_hash(36);
            for (p_56 = 27; (p_56 >= (-27)); --p_56)
            {
                step_hash(33);
                l_81 ^= ((signed char)l_80 >> (signed char)2);
                step_hash(34);
                p_57 = p_57;
                step_hash(35);
                (*g_67) = (*g_67);
            }
        }
        else
        {
            step_hash(38);
            (*g_67) = p_57;
        }
        step_hash(54);
        for (p_58 = 0; (p_58 <= 14); p_58++)
        {
            step_hash(53);
            for (g_75 = 0; (g_75 >= 13); g_75 += 2)
            {
                unsigned char l_89 = 3UL;
                int *l_90 = &g_91;
                step_hash(50);
                if (((signed char)(l_88 | (l_89 ^ (1L & (-1L)))) >> (signed char)7))
                {
                    step_hash(47);
                    (*g_67) = (*g_67);
                }
                else
                {
                    step_hash(49);
                    return p_57;
                }
                step_hash(51);
                (*l_90) = 0x5A2D5357L;
                step_hash(52);
                g_91 = ((*l_90) ^ g_64);
            }
        }
        step_hash(55);
        (*g_67) = p_57;
    }
    step_hash(57);
    return (*g_67);
}
static unsigned short func_59(int * p_60, int * p_61, int * p_62)
{
    step_hash(22);
    for (g_64 = 6; (g_64 <= (-28)); g_64 -= 7)
    {
        int ***l_69 = &g_67;
        step_hash(21);
        (*l_69) = g_67;
    }
    step_hash(23);
    return g_64;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_8, "g_8", print_hash_value);
    transparent_crc(g_22, "g_22", print_hash_value);
    transparent_crc(g_64, "g_64", print_hash_value);
    transparent_crc(g_75, "g_75", print_hash_value);
    transparent_crc(g_91, "g_91", print_hash_value);
    transparent_crc(g_105, "g_105", print_hash_value);
    transparent_crc(g_179, "g_179", print_hash_value);
    transparent_crc(g_354, "g_354", print_hash_value);
    transparent_crc(g_385, "g_385", print_hash_value);
    transparent_crc(g_432, "g_432", print_hash_value);
    transparent_crc(g_606, "g_606", print_hash_value);
    transparent_crc(g_624, "g_624", print_hash_value);
    transparent_crc(g_652, "g_652", print_hash_value);
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
