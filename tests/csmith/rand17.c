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
static int g_2 = 0L;
static unsigned g_93 = 0x0CC19AB5L;
static int **g_94 = (void*)0;
static int g_102 = 0x054F5258L;
static unsigned short g_112 = 0x7C2AL;
static unsigned char g_231 = 0x43L;
static int g_247 = 0xDFD4C6E6L;
static int *g_246 = &g_247;
static signed char g_292 = 0xBBL;
static unsigned g_293 = 4294967286UL;
static int *g_389 = &g_2;
static unsigned g_456 = 0UL;
static unsigned char func_1(void);
static int * func_5(unsigned p_6, int p_7, signed char p_8, signed char p_9, int p_10);
static unsigned short func_15(int * p_16, short p_17, int p_18);
static int * func_19(int * p_20, int * p_21, signed char p_22, signed char p_23, int * p_24);
static int * func_25(unsigned p_26, unsigned char p_27, unsigned p_28, int p_29, int * p_30);
static unsigned char func_31(int * p_32, int p_33, unsigned p_34);
static int * func_35(int * p_36, int p_37, unsigned p_38, int p_39, int * p_40);
static unsigned char func_44(int p_45, int * p_46, unsigned p_47, int p_48, unsigned char p_49);
static signed char func_52(int * p_53, unsigned char p_54, int p_55);
static int func_60(unsigned p_61, short p_62);
static unsigned char func_1(void)
{
    int *l_56 = &g_2;
    unsigned char l_665 = 0x7DL;
    step_hash(389);
    for (g_2 = 0; (g_2 <= (-3)); --g_2)
    {
        int *l_41 = &g_2;
        unsigned short l_192 = 1UL;
        int **l_636 = &g_389;
        int ***l_666 = &l_636;
        int *l_689 = &g_102;
    }
    step_hash(390);
    return (*l_56);
}
static int * func_5(unsigned p_6, int p_7, signed char p_8, signed char p_9, int p_10)
{
    int *l_614 = &g_102;
    int ***l_635 = &g_94;
    step_hash(325);
    (*g_94) = l_614;
    step_hash(326);
    (**g_94) = p_8;
    step_hash(327);
    (*l_614) = ((((int)(g_456 <= 0x4429L) + (int)func_44((*l_614), l_614, ((signed char)((signed char)((unsigned char)func_60((g_102 <= ((((int)((unsigned short)p_10 << (unsigned short)((unsigned)(((short)func_31((*g_94), ((((((unsigned short)(*l_614) >> (unsigned short)p_10) == 0x4304EA88L) > 65532UL) < (-1L)) ^ 0xAD7CL), p_10) - (short)(*l_614)) == g_231) % (unsigned)p_6)) % (int)(*l_614)) > g_2) || 0x33L)), (*l_614)) >> (unsigned char)g_293) >> (signed char)g_102) << (signed char)g_2), (*g_246), p_8)) == g_292) == (-6L));
    step_hash(333);
    for (p_9 = 0; (p_9 >= 12); p_9 += 1)
    {
        step_hash(331);
        (*l_614) |= (((void*)0 != l_635) ^ p_6);
        step_hash(332);
        if (p_6)
            break;
    }
    step_hash(334);
    return l_614;
}
static unsigned short func_15(int * p_16, short p_17, int p_18)
{
    int **l_545 = &g_246;
    int ***l_546 = &g_94;
    short l_556 = 0x4226L;
    unsigned short l_579 = 65532UL;
    int l_583 = 0xD249770CL;
    int *l_601 = &g_2;
    int *l_605 = &g_102;
    step_hash(282);
    (*l_546) = l_545;
    step_hash(316);
    if ((p_18 ^ (1L >= g_2)))
    {
        step_hash(284);
        return p_18;
    }
    else
    {
        int l_547 = 0x0B618C88L;
        step_hash(303);
        if ((g_93 && l_547))
        {
            signed char l_553 = 1L;
            step_hash(292);
            for (g_231 = 0; (g_231 <= 3); ++g_231)
            {
                int *l_557 = &g_247;
                step_hash(290);
                (*l_557) = (((unsigned short)(-(unsigned short)(!((func_60(g_2, (l_553 >= ((int)(g_293 <= l_556) / (int)p_18))) && p_17) == 1UL))) - (unsigned short)0xE0C7L) <= 2UL);
                step_hash(291);
                (*l_557) = (*l_557);
            }
        }
        else
        {
            unsigned l_564 = 0x37CB6E70L;
            int l_569 = 0xC7C855FCL;
            int *l_576 = &g_247;
            int ***l_577 = &g_94;
            step_hash(301);
            if (((unsigned char)l_547 / (unsigned char)((unsigned char)((&g_389 != &g_246) <= (+(((short)l_564 * (short)((-5L) && ((int)(*p_16) - (int)((signed char)0x19L >> (signed char)1)))) != p_17))) * (unsigned char)l_564)))
            {
                int l_573 = 1L;
                int ***l_578 = &l_545;
                step_hash(295);
                l_569 = l_564;
                step_hash(296);
                (*g_94) = &l_547;
                step_hash(297);
                (*l_545) = func_35(p_16, ((p_18 || p_17) != (0xCB7D06C7L && ((signed char)(-(unsigned short)((l_573 | ((unsigned char)(l_576 == p_16) - (unsigned char)func_44((((l_577 == l_578) && (-1L)) >= l_547), (*g_94), (**l_545), l_579, p_18))) <= g_292)) >> (signed char)0))), p_17, g_293, &g_247);
            }
            else
            {
                unsigned short l_582 = 0x8551L;
                step_hash(299);
                (*l_576) = (((signed char)func_60((1L >= p_18), l_582) + (signed char)l_547) | (*p_16));
                step_hash(300);
                (*l_576) = (*l_576);
            }
            step_hash(302);
            (*l_576) = (*p_16);
        }
        step_hash(304);
        l_583 |= l_547;
        step_hash(315);
        for (l_547 = (-29); (l_547 >= (-9)); ++l_547)
        {
            int ***l_586 = &g_94;
            int *l_589 = &g_102;
            step_hash(308);
            g_102 ^= (g_456 <= (l_586 == (void*)0));
            step_hash(313);
            for (g_231 = 0; (g_231 != 45); g_231++)
            {
                step_hash(312);
                return g_2;
            }
            step_hash(314);
            (*l_589) ^= l_547;
        }
    }
    step_hash(321);
    for (l_579 = 0; (l_579 > 26); ++l_579)
    {
        unsigned short l_596 = 0x455EL;
        int *l_604 = &l_583;
        step_hash(320);
        (*l_604) &= ((short)((unsigned char)((func_52(func_25(l_596, (3UL != g_112), (((unsigned char)g_292 >> (unsigned char)7) > ((short)func_31(l_601, (*p_16), ((unsigned char)p_17 - (unsigned char)p_17)) / (short)p_17)), l_596, &g_102), p_18, g_93) > g_247) && g_456) << (unsigned char)7) >> (short)15);
    }
    step_hash(322);
    l_583 ^= (func_44((*p_16), l_605, g_112, (((unsigned char)g_112 << (unsigned char)((unsigned char)(((short)(((int)0L + (int)g_292) ^ g_112) - (short)p_18) > 9UL) >> (unsigned char)p_17)) <= (-1L)), (*l_605)) == 0xF7L);
    step_hash(323);
    return g_102;
}
static int * func_19(int * p_20, int * p_21, signed char p_22, signed char p_23, int * p_24)
{
    int *l_395 = &g_2;
    unsigned l_397 = 0x5F113441L;
    signed char l_408 = 0x25L;
    int ***l_410 = &g_94;
    int l_469 = 0xFE263680L;
    int l_535 = (-1L);
    int **l_539 = (void*)0;
    short l_544 = 0xDB0FL;
    step_hash(278);
    for (g_112 = 17; (g_112 > 53); g_112 += 1)
    {
        unsigned short l_396 = 6UL;
        int ***l_409 = &g_94;
        int l_472 = 1L;
        step_hash(210);
        (*p_24) = (p_23 && (((void*)0 != l_395) < func_31(l_395, ((((~((g_93 | p_23) ^ l_396)) == l_396) < (*l_395)) > l_397), g_231)));
        step_hash(277);
        for (l_396 = 0; (l_396 <= 51); l_396 += 2)
        {
            unsigned short l_404 = 0x4DC9L;
            int l_426 = 0xEE7531B3L;
            int l_495 = 0L;
            int **l_500 = (void*)0;
            int l_503 = 0xEBE1A27AL;
        }
    }
    step_hash(279);
    (*p_24) = func_31(p_24, (*p_21), (((short)((void*)0 == l_539) + (short)(((unsigned char)((&l_539 != (void*)0) >= p_22) + (unsigned char)((unsigned)func_52(func_25(g_112, g_292, (*l_395), (*p_21), p_21), g_456, l_544) + (unsigned)(*p_21))) | p_23)) ^ p_22));
    step_hash(280);
    return l_395;
}
static int * func_25(unsigned p_26, unsigned char p_27, unsigned p_28, int p_29, int * p_30)
{
    int *l_392 = &g_102;
    step_hash(204);
    (*l_392) = (-9L);
    step_hash(205);
    return &g_2;
}
static unsigned char func_31(int * p_32, int p_33, unsigned p_34)
{
    int **l_390 = (void*)0;
    int **l_391 = &g_389;
    step_hash(201);
    (*l_391) = (void*)0;
    step_hash(202);
    return g_293;
}
static int * func_35(int * p_36, int p_37, unsigned p_38, int p_39, int * p_40)
{
    int *l_387 = (void*)0;
    int **l_388 = &l_387;
    step_hash(198);
    (*l_388) = l_387;
    step_hash(199);
    return g_389;
}
static unsigned char func_44(int p_45, int * p_46, unsigned p_47, int p_48, unsigned char p_49)
{
    int l_216 = (-1L);
    int ***l_235 = &g_94;
    int l_269 = (-5L);
    int l_338 = 0x5A139966L;
    int l_367 = 0x304D937BL;
    int l_382 = (-1L);
    step_hash(131);
    for (p_49 = (-15); (p_49 >= 44); p_49 += 9)
    {
        short l_224 = (-1L);
        int l_225 = 1L;
        int *l_226 = &g_102;
        int **l_227 = &l_226;
        int l_236 = 0x6DDC0764L;
        step_hash(115);
        for (p_48 = (-15); (p_48 >= 11); ++p_48)
        {
            int *l_198 = &g_102;
            int **l_197 = &l_198;
            unsigned l_217 = 0x7574EA98L;
            step_hash(112);
            (*l_197) = &p_45;
            step_hash(113);
            l_225 = ((unsigned char)(-(short)((signed char)(&l_198 == (void*)0) + (signed char)(((int)((unsigned short)func_52(&p_48, p_47, ((signed char)(((signed char)(func_60(g_102, ((signed char)((unsigned short)((*l_198) | l_216) * (unsigned short)((((l_217 || (((int)((unsigned short)(((signed char)l_224 << (signed char)0) & g_2) / (unsigned short)p_49) - (int)4294967292UL) | (*p_46))) <= 255UL) < 8UL) ^ 0xE7L)) * (signed char)p_45)) > g_2) / (signed char)g_2) != 0x1347L) % (signed char)0x73L)) >> (unsigned short)l_224) / (int)g_2) | g_2))) * (unsigned char)g_2);
            step_hash(114);
            return l_225;
        }
        step_hash(116);
        (*l_226) = g_102;
        step_hash(117);
        (*l_227) = &p_45;
        step_hash(130);
        if (((signed char)p_45 >> (signed char)1))
        {
            int *l_232 = (void*)0;
            short l_237 = 0xE034L;
            step_hash(119);
            if ((*p_46))
                break;
            step_hash(120);
            l_237 = (((*p_46) ^ (-(unsigned char)g_231)) && (((((void*)0 == l_232) && func_52(&l_216, ((unsigned short)(g_2 >= (-1L)) * (unsigned short)((l_235 != &g_94) ^ l_236)), (*p_46))) ^ g_2) == p_45));
        }
        else
        {
            int l_242 = 0xB3754A37L;
            unsigned l_248 = 0x4BF27C86L;
            step_hash(122);
            g_102 = (((signed char)((int)(&l_227 == l_235) / (int)g_112) * (signed char)p_47) <= l_242);
            step_hash(127);
            for (g_102 = 0; (g_102 >= (-23)); g_102 -= 5)
            {
                int *l_245 = &l_216;
                step_hash(126);
                g_246 = l_245;
            }
            step_hash(128);
            if (l_248)
                break;
            step_hash(129);
            l_242 = ((unsigned short)p_49 >> (unsigned short)g_102);
        }
    }
    step_hash(132);
    p_46 = &p_45;
    step_hash(195);
    for (l_216 = 0; (l_216 < 17); l_216 += 1)
    {
        int l_276 = (-8L);
        int ***l_319 = &g_94;
        short l_335 = 0xFD68L;
        unsigned l_339 = 0x0926870BL;
        int **l_385 = (void*)0;
        int **l_386 = &g_246;
    }
    step_hash(196);
    return p_47;
}
static signed char func_52(int * p_53, unsigned char p_54, int p_55)
{
    short l_57 = 0x7030L;
    int l_70 = (-5L);
    int l_140 = 0L;
    signed char l_153 = 0xCFL;
    int *l_159 = &l_140;
    step_hash(79);
    if (l_57)
    {
        unsigned l_78 = 0x182BC92CL;
        unsigned char l_106 = 0xDFL;
        int *l_155 = (void*)0;
        int *l_156 = &g_102;
        int **l_157 = (void*)0;
        int **l_158 = &l_155;
        step_hash(73);
        for (p_54 = 0; (p_54 > 24); p_54++)
        {
            short l_69 = (-1L);
            short l_90 = 0x3552L;
            int *l_108 = &g_102;
            int **l_107 = &l_108;
            step_hash(32);
            if (func_60(p_54, ((unsigned char)(((+g_2) && (((short)(l_69 | g_2) >> (short)(0xAE56L || g_2)) && (l_70 >= ((unsigned short)(&g_2 != &g_2) >> (unsigned short)7)))) < g_2) * (unsigned char)0x94L)))
            {
                int *l_75 = &g_2;
                int **l_74 = &l_75;
                step_hash(13);
                (*l_74) = &g_2;
                step_hash(28);
                for (l_70 = 7; (l_70 >= (-10)); l_70 -= 1)
                {
                    signed char l_85 = 0x88L;
                    step_hash(26);
                    if ((l_78 > (func_60(l_57, (g_2 && ((((unsigned short)(func_60(((short)1L + (short)l_69), (g_2 >= ((int)l_69 - (int)p_54))) | 7L) % (unsigned short)l_85) && (-1L)) ^ 0xDEL))) <= l_69)))
                    {
                        step_hash(18);
                        g_93 = ((signed char)g_2 - (signed char)(func_60(g_2, g_2) <= ((unsigned)(((~(p_54 != g_2)) || (l_90 < g_2)) | ((int)g_2 / (int)6UL)) - (unsigned)0xC22A6657L)));
                        step_hash(19);
                        (*l_74) = &p_55;
                        step_hash(20);
                        if ((*p_53))
                            continue;
                    }
                    else
                    {
                        int *l_101 = &g_102;
                        step_hash(22);
                        p_55 |= ((void*)0 == g_94);
                        step_hash(23);
                        (*l_101) = ((short)(+(&p_55 == (void*)0)) / (short)func_60(((unsigned char)((unsigned short)(l_78 | l_90) << (unsigned short)6) * (unsigned char)(!0x5CL)), g_2));
                        step_hash(24);
                        (*l_101) = (*l_101);
                        step_hash(25);
                        (*l_74) = &p_55;
                    }
                    step_hash(27);
                    if ((*p_53))
                        continue;
                }
                step_hash(29);
                return g_102;
            }
            else
            {
                short l_105 = 0xC9DAL;
                step_hash(31);
                (*l_108) = ((signed char)l_70 << (signed char)(((p_55 | l_105) >= l_106) & (((void*)0 != l_107) != func_60(p_55, (((short)0x2261L * (short)p_54) > p_54)))));
            }
            step_hash(72);
            if ((0xF7833775L > l_106))
            {
                int *l_111 = &g_102;
                step_hash(34);
                (*l_107) = l_111;
                step_hash(35);
                g_112 |= (*l_111);
                step_hash(36);
                (*l_111) = ((int)(*p_53) / (int)0x2CF88EA9L);
                step_hash(37);
                (*l_108) &= (*p_53);
            }
            else
            {
                unsigned short l_119 = 0xEF17L;
                unsigned l_143 = 0x075E4EBAL;
                step_hash(61);
                if (((signed char)1L << (signed char)2))
                {
                    unsigned char l_122 = 0xC2L;
                    int *l_144 = &l_140;
                    step_hash(44);
                    for (p_55 = 0; (p_55 >= 19); p_55 += 8)
                    {
                        step_hash(43);
                        return p_54;
                    }
                    step_hash(51);
                    if (l_106)
                    {
                        step_hash(46);
                        (**l_107) = (+(*p_53));
                        step_hash(47);
                        l_122 = (((*l_108) >= l_119) && ((unsigned)1UL / (unsigned)l_119));
                        step_hash(48);
                        (*l_108) |= 0xA1A39BFCL;
                    }
                    else
                    {
                        unsigned l_139 = 4UL;
                        step_hash(50);
                        l_140 &= (g_112 != ((unsigned char)((unsigned char)func_60(p_54, l_122) + (unsigned char)((unsigned short)(((unsigned short)((((unsigned char)((unsigned char)((((signed char)func_60(g_112, ((signed char)p_55 >> (signed char)2)) - (signed char)(g_2 ^ l_139)) ^ g_2) > (-1L)) * (unsigned char)0UL) >> (unsigned char)7) ^ g_102) <= l_139) % (unsigned short)0x5E00L) > l_139) / (unsigned short)l_57)) % (unsigned char)g_102));
                    }
                    step_hash(52);
                    (*l_144) |= (((0L != (0x66FFL && func_60(((short)g_112 << (short)(g_2 && (g_112 && (func_60((+((void*)0 == &p_53)), (0x01L & (g_102 || (**l_107)))) | p_55)))), l_143))) < 0UL) >= l_106);
                    step_hash(58);
                    for (l_90 = (-24); (l_90 >= 11); l_90 += 8)
                    {
                        step_hash(56);
                        (*l_107) = (void*)0;
                        step_hash(57);
                        return g_2;
                    }
                }
                else
                {
                    step_hash(60);
                    (*l_108) = g_102;
                }
                step_hash(71);
                if ((!((int)g_112 - (int)g_102)))
                {
                    step_hash(63);
                    return g_112;
                }
                else
                {
                    unsigned l_154 = 0UL;
                    step_hash(69);
                    for (p_55 = 0; (p_55 >= 25); p_55 += 9)
                    {
                        step_hash(68);
                        l_153 ^= ((short)(g_102 > func_60(g_2, l_78)) >> (short)13);
                    }
                    step_hash(70);
                    (**l_107) ^= (l_154 && l_153);
                }
            }
        }
        step_hash(74);
        (*l_156) |= l_57;
        step_hash(75);
        (*l_158) = &p_55;
        step_hash(76);
        (*l_158) = l_159;
    }
    else
    {
        step_hash(78);
        return p_54;
    }
    step_hash(103);
    for (l_70 = 0; (l_70 > (-30)); --l_70)
    {
        step_hash(102);
        if ((*p_53))
        {
            unsigned l_172 = 0x6262BB9AL;
            int *l_187 = &g_102;
            step_hash(97);
            for (l_57 = (-20); (l_57 >= (-29)); --l_57)
            {
                int *l_169 = &g_102;
                unsigned short l_181 = 7UL;
                step_hash(87);
                (*l_159) = ((((short)g_112 << (short)4) ^ g_93) ^ g_2);
                step_hash(94);
                for (g_112 = (-18); (g_112 < 25); g_112++)
                {
                    int ***l_168 = &g_94;
                    int **l_170 = (void*)0;
                    int **l_171 = &l_169;
                    step_hash(91);
                    (*l_168) = g_94;
                    step_hash(92);
                    (*l_171) = l_169;
                    step_hash(93);
                    (*l_159) = (l_172 < (0xA376L >= ((unsigned)((signed char)0x09L % (signed char)g_2) - (unsigned)0x7E15FDC6L)));
                }
                step_hash(95);
                (*l_159) = (g_112 ^ (((((unsigned char)g_112 + (unsigned char)(((unsigned char)g_2 * (unsigned char)0x50L) && (g_2 > l_181))) < (-(unsigned)((*p_53) && ((signed char)((((l_172 & func_60((((unsigned short)0xE2A0L * (unsigned short)g_93) ^ (*l_169)), p_55)) | (*l_159)) & p_55) | g_93) + (signed char)6UL)))) == 0x8BL) & p_55));
                step_hash(96);
                return p_54;
            }
            step_hash(98);
            p_53 = l_187;
        }
        else
        {
            int *l_188 = &g_102;
            int ***l_191 = &g_94;
            step_hash(100);
            (*l_188) ^= (*l_159);
            step_hash(101);
            (*l_159) = (((unsigned short)((&p_55 != &p_55) < p_54) - (unsigned short)((void*)0 != l_191)) || (*l_159));
        }
    }
    step_hash(104);
    return g_93;
}
static int func_60(unsigned p_61, short p_62)
{
    unsigned char l_73 = 0UL;
    step_hash(10);
    l_73 = p_61;
    step_hash(11);
    return p_61;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_93, "g_93", print_hash_value);
    transparent_crc(g_102, "g_102", print_hash_value);
    transparent_crc(g_112, "g_112", print_hash_value);
    transparent_crc(g_231, "g_231", print_hash_value);
    transparent_crc(g_247, "g_247", print_hash_value);
    transparent_crc(g_292, "g_292", print_hash_value);
    transparent_crc(g_293, "g_293", print_hash_value);
    transparent_crc(g_456, "g_456", print_hash_value);
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
