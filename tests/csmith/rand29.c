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
static signed char g_6 = 0xACL;
static int g_48 = 0L;
static int *g_47 = &g_48;
static int g_74 = 0L;
static short g_111 = 0x01C9L;
static int **g_158 = &g_47;
static int ***g_157 = &g_158;
static unsigned g_236 = 0x61C8C171L;
static int g_428 = 0L;
static unsigned g_429 = 1UL;
static signed char g_565 = (-1L);
static unsigned g_567 = 0UL;
static int *g_658 = (void*)0;
static int *g_804 = &g_48;
static short func_1(void);
static unsigned func_18(short p_19, unsigned char p_20, int p_21);
static unsigned short func_22(unsigned p_23);
static unsigned short func_26(signed char p_27, signed char p_28);
static signed char func_29(unsigned char p_30, unsigned char p_31, unsigned short p_32, int p_33, signed char p_34);
static int * func_36(signed char p_37, int * p_38, signed char p_39, int * p_40, int * p_41);
static int * func_42(int * p_43, int p_44, unsigned p_45, int * p_46);
static int * func_54(int * p_55);
static int * func_56(int * p_57);
static int * func_58(unsigned p_59, unsigned short p_60, unsigned short p_61, unsigned short p_62, int * p_63);
static short func_1(void)
{
    unsigned l_15 = 0x0D193E05L;
    unsigned char l_35 = 0x38L;
    int l_803 = (-1L);
    int l_807 = (-6L);
    int *l_808 = &g_48;
    step_hash(560);
    l_803 ^= ((int)(((short)g_6 << (short)(((int)(+((signed char)0xF0L >> (signed char)3)) + (int)(g_6 != ((unsigned short)(~(g_6 < ((short)l_15 * (short)(1UL || ((signed char)(func_18((65534UL & func_22(((unsigned short)func_26(func_29((l_15 > (g_6 < g_6)), l_35, l_35, g_6, l_35), g_565) << (unsigned short)g_428))), g_567, l_35) != 0L) - (signed char)g_6))))) / (unsigned short)l_15))) ^ l_15)) <= 0xC2L) % (int)l_15);
    step_hash(561);
    g_804 = &l_803;
    step_hash(562);
    l_807 &= (func_26(g_111, l_803) && ((l_35 < l_35) != (&l_803 != &l_803)));
    step_hash(563);
    l_808 = &l_803;
    step_hash(564);
    return g_236;
}
static unsigned func_18(short p_19, unsigned char p_20, int p_21)
{
    int *l_701 = &g_74;
    unsigned short l_735 = 65535UL;
    int l_744 = 0x6E4522F5L;
    unsigned char l_799 = 0xD5L;
    step_hash(479);
    (*l_701) = func_22(p_21);
    step_hash(558);
    for (g_567 = 0; (g_567 >= 8); g_567 += 6)
    {
        int *l_704 = &g_48;
        int l_741 = 0xCB3C2ED5L;
        short l_763 = (-1L);
        int l_789 = (-9L);
        int l_794 = 0x8BBC5121L;
    }
    step_hash(559);
    return g_567;
}
static unsigned short func_22(unsigned p_23)
{
    signed char l_693 = 0x39L;
    int *l_700 = &g_48;
    step_hash(475);
    l_693 = ((unsigned)p_23 - (unsigned)0x71ED8943L);
    step_hash(476);
    (*l_700) ^= (((g_565 != ((unsigned short)(g_111 > 0x07B7L) / (unsigned short)((unsigned char)p_23 >> (unsigned char)5))) > (l_700 == l_700)) == 0x08E1C68EL);
    step_hash(477);
    return (*l_700);
}
static unsigned short func_26(signed char p_27, signed char p_28)
{
    int *l_672 = &g_74;
    int ***l_682 = &g_158;
    int **l_683 = (void*)0;
    int **l_684 = &g_47;
    step_hash(469);
    if (p_27)
    {
        int **l_673 = &l_672;
        step_hash(463);
        (*l_673) = l_672;
        step_hash(464);
        return p_28;
    }
    else
    {
        int l_674 = 7L;
        int l_677 = 0x05A10D9DL;
        step_hash(466);
        (*l_672) = l_674;
        step_hash(467);
        (*l_672) = (*l_672);
        step_hash(468);
        g_48 &= (*l_672);
    }
    step_hash(470);
    (*l_672) |= ((void*)0 == l_682);
    step_hash(471);
    (*l_684) = l_672;
    step_hash(472);
    (**l_684) = ((unsigned short)((unsigned short)0x18E0L << (unsigned short)5) + (unsigned short)((*g_47) != (*l_672)));
    step_hash(473);
    return p_27;
}
static signed char func_29(unsigned char p_30, unsigned char p_31, unsigned short p_32, int p_33, signed char p_34)
{
    int l_51 = (-7L);
    int l_68 = 0L;
    unsigned char l_69 = 0UL;
    int **l_649 = &g_47;
    int *l_670 = (void*)0;
    int l_671 = 0x7E1E53B8L;
    step_hash(450);
    (*l_649) = func_36(g_6, func_42(g_47, p_34, ((unsigned)(l_51 != ((unsigned char)l_51 * (unsigned char)9UL)) / (unsigned)0x09B95520L), func_54(func_56(func_58(p_34, ((signed char)((unsigned char)(l_68 || l_51) >> (unsigned char)l_68) - (signed char)p_30), l_69, l_68, &g_48)))), l_51, (**g_157), &l_51);
    step_hash(458);
    if ((((short)((unsigned char)((g_74 && ((unsigned short)0x3A7AL >> (unsigned short)0)) <= p_31) / (unsigned char)(**l_649)) % (short)((**l_649) & p_32)) || (l_649 == (void*)0)))
    {
        int *l_659 = (void*)0;
        step_hash(452);
        (*g_47) = ((int)p_30 % (int)((*g_47) && (**l_649)));
        step_hash(453);
        l_659 = func_56(g_658);
    }
    else
    {
        unsigned char l_660 = 255UL;
        int ***l_665 = &l_649;
        step_hash(455);
        (*g_47) = ((!l_660) && (l_660 | ((signed char)((signed char)g_6 + (signed char)(((g_74 <= ((void*)0 != l_665)) != 0x2A82DE67L) || (0UL != p_30))) << (signed char)(***l_665))));
        step_hash(456);
        (**l_665) = func_42((**l_665), p_32, g_48, (*l_649));
        step_hash(457);
        (**l_665) = (**l_665);
    }
    step_hash(459);
    l_671 ^= (0xEA93L == ((**l_649) >= ((((short)((unsigned)g_428 / (unsigned)p_33) << (short)(**l_649)) | (((*l_649) == (void*)0) == 0xFDL)) & ((*g_47) ^ 0xC1FCB659L))));
    step_hash(460);
    return p_30;
}
static int * func_36(signed char p_37, int * p_38, signed char p_39, int * p_40, int * p_41)
{
    int *l_217 = &g_48;
    int ***l_302 = (void*)0;
    unsigned l_463 = 2UL;
    unsigned l_483 = 0xA31BF185L;
    int l_484 = 0x817C311DL;
    int *l_648 = &l_484;
    step_hash(272);
    if ((*p_41))
    {
        short l_226 = (-9L);
        int *l_230 = &g_74;
        int **l_263 = &l_230;
        unsigned char l_342 = 0xD2L;
        unsigned short l_372 = 0x41FBL;
        step_hash(72);
        (**g_157) = func_54(p_40);
        step_hash(151);
        if ((*g_47))
        {
            step_hash(74);
            (***g_157) &= (*p_41);
            step_hash(75);
            (*p_41) |= ((void*)0 == p_40);
        }
        else
        {
            unsigned short l_227 = 1UL;
            int *l_280 = &g_74;
            step_hash(96);
            for (g_74 = 0; (g_74 >= (-20)); g_74 -= 7)
            {
                short l_223 = 0L;
                step_hash(80);
                (*p_40) ^= 1L;
                step_hash(81);
                (*g_158) = l_217;
                step_hash(89);
                for (p_37 = (-22); (p_37 <= (-26)); p_37 -= 5)
                {
                    signed char l_220 = 0x45L;
                    step_hash(85);
                    (***g_157) = (**g_158);
                    step_hash(86);
                    (*p_40) = l_220;
                    step_hash(87);
                    (*p_40) = (&l_217 != &p_41);
                    step_hash(88);
                    if ((***g_157))
                        continue;
                }
                step_hash(95);
                for (p_37 = (-24); (p_37 == (-15)); p_37++)
                {
                    step_hash(93);
                    (*p_40) &= l_223;
                }
            }
            step_hash(150);
            if ((l_227 >= (((g_74 == ((((p_39 ^ (!p_39)) > l_226) > ((int)(p_40 == l_230) - (int)0L)) || ((signed char)((((void*)0 != &g_158) && 2L) == p_37) / (signed char)(*l_217)))) < g_111) <= (*l_230))))
            {
                step_hash(105);
                for (g_111 = (-28); (g_111 >= (-8)); g_111++)
                {
                    int *l_235 = &g_74;
                    step_hash(101);
                    (**g_157) = l_235;
                    step_hash(102);
                    (*p_40) &= (*g_47);
                    step_hash(103);
                    (*p_41) = (-4L);
                    step_hash(104);
                    (*l_235) = (***g_157);
                }
            }
            else
            {
                short l_243 = 0x1E81L;
                int *l_260 = &g_74;
                step_hash(107);
                (*p_38) ^= g_236;
                step_hash(148);
                if (((unsigned char)(p_39 ^ ((signed char)0x51L / (signed char)(((((unsigned short)p_39 % (unsigned short)l_243) & p_39) || (((unsigned short)((+((unsigned)((g_236 && ((unsigned char)(*l_217) / (unsigned char)((unsigned short)(((int)((short)p_39 >> (short)l_227) - (int)0x9F4295DAL) != (*l_230)) >> (unsigned short)p_39))) != g_74) % (unsigned)0x837247A2L)) && g_74) % (unsigned short)g_111) > l_227)) | l_243))) << (unsigned char)0))
                {
                    step_hash(113);
                    if ((g_74 != g_74))
                    {
                        step_hash(110);
                        return p_38;
                    }
                    else
                    {
                        int **l_256 = &l_217;
                        step_hash(112);
                        (*g_157) = l_256;
                    }
                    step_hash(121);
                    if ((p_37 < (*l_217)))
                    {
                        int *l_257 = &g_74;
                        step_hash(115);
                        l_257 = (void*)0;
                        step_hash(116);
                        (*g_158) = l_230;
                    }
                    else
                    {
                        step_hash(118);
                        (*p_41) &= ((int)(*l_217) - (int)g_48);
                        step_hash(119);
                        l_260 = (void*)0;
                        step_hash(120);
                        (**g_157) = p_38;
                    }
                }
                else
                {
                    int l_273 = (-8L);
                    step_hash(131);
                    if ((*p_38))
                    {
                        step_hash(124);
                        (*l_230) ^= ((unsigned char)(g_236 >= g_111) << (unsigned char)4);
                        step_hash(125);
                        (*g_158) = func_56((*g_158));
                        step_hash(126);
                        (**l_263) |= (l_263 != (void*)0);
                        step_hash(127);
                        (*p_40) = (*p_38);
                    }
                    else
                    {
                        int ***l_268 = &l_263;
                        step_hash(129);
                        (*p_41) ^= (***g_157);
                        step_hash(130);
                        (*l_230) = ((unsigned char)253UL - (unsigned char)(((short)(l_268 != &l_263) >> (short)g_236) < 0x22A0L));
                    }
                    step_hash(139);
                    for (g_48 = 0; (g_48 <= 17); g_48 += 1)
                    {
                        unsigned l_271 = 0xDCA30394L;
                        int *l_272 = &g_48;
                        step_hash(135);
                        if ((***g_157))
                            break;
                        step_hash(136);
                        if (l_271)
                            break;
                        step_hash(137);
                        (*l_263) = func_56(l_272);
                        step_hash(138);
                        (*p_38) = l_273;
                    }
                    step_hash(140);
                    (*p_41) |= ((short)(g_48 <= (((!((unsigned char)p_37 % (unsigned char)(**l_263))) < g_236) & p_37)) >> (short)7);
                    step_hash(147);
                    for (p_37 = 19; (p_37 < (-25)); p_37--)
                    {
                        signed char l_289 = (-1L);
                        step_hash(144);
                        l_280 = l_280;
                        step_hash(145);
                        (*l_260) = ((short)g_236 << (short)(((short)((unsigned short)((signed char)l_289 >> (signed char)3) / (unsigned short)(~((*p_38) || ((short)g_48 >> (short)8)))) * (short)(*l_260)) & (g_48 ^ (*l_230))));
                        step_hash(146);
                        (***g_157) = ((short)(g_6 < ((short)g_74 % (short)p_39)) * (short)((void*)0 != (*g_157)));
                    }
                }
                step_hash(149);
                (*p_41) ^= (*g_47);
            }
        }
        step_hash(152);
        (*p_41) |= ((unsigned char)(0x31L || g_6) * (unsigned char)((((((int)((signed char)(l_302 != &l_263) - (signed char)((*l_230) > (**g_158))) - (int)0x91A108BFL) <= ((signed char)(g_6 == 1UL) >> (signed char)g_236)) | p_37) < g_48) ^ g_6));
        step_hash(267);
        if ((((unsigned char)(*l_230) - (unsigned char)((unsigned short)p_39 >> (unsigned short)14)) ^ ((**l_263) > g_236)))
        {
            int ***l_331 = (void*)0;
            step_hash(184);
            if (((((signed char)p_39 << (signed char)4) && (*p_41)) ^ (g_48 > 7UL)))
            {
                step_hash(159);
                for (g_48 = (-17); (g_48 >= 17); g_48++)
                {
                    step_hash(158);
                    return p_41;
                }
            }
            else
            {
                unsigned short l_317 = 65529UL;
                int l_337 = 0x1D226D04L;
                step_hash(168);
                for (g_48 = 0; (g_48 == 9); g_48++)
                {
                    step_hash(164);
                    if ((*g_47))
                        break;
                    step_hash(165);
                    (**g_157) = func_56(p_41);
                    step_hash(166);
                    (*p_41) = (((short)g_48 << (short)g_48) && (!g_6));
                    step_hash(167);
                    l_317 = (**g_158);
                }
                step_hash(181);
                if ((0x9FL > l_317))
                {
                    short l_332 = (-1L);
                    step_hash(170);
                    (*p_38) = (((unsigned short)0x9D31L * (unsigned short)p_37) && (g_111 < p_37));
                    step_hash(178);
                    if ((*g_47))
                    {
                        int l_326 = 0x8965CC1DL;
                        step_hash(172);
                        (**g_157) = p_38;
                        step_hash(173);
                        (*p_40) = ((unsigned char)((unsigned short)(((int)(l_326 & g_6) + (int)l_317) <= ((unsigned short)(((unsigned short)g_111 * (unsigned short)p_37) | ((g_236 || ((void*)0 != l_331)) <= ((void*)0 != &g_158))) % (unsigned short)p_37)) - (unsigned short)l_332) - (unsigned char)(*l_230));
                        step_hash(174);
                        (**g_157) = p_41;
                        step_hash(175);
                        (*p_38) &= ((short)(~((short)(p_37 == g_111) >> (short)((((((short)(-6L) >> (short)1) && g_236) && ((short)(4294967295UL >= ((*p_40) | ((void*)0 != p_40))) % (short)p_39)) | g_111) ^ 0UL))) / (short)0x798EL);
                    }
                    else
                    {
                        step_hash(177);
                        (*l_263) = p_41;
                    }
                }
                else
                {
                    step_hash(180);
                    (*l_263) = (void*)0;
                }
                step_hash(182);
                (*p_40) = (p_39 >= (*g_47));
                step_hash(183);
                (*p_41) ^= (*p_38);
            }
            step_hash(185);
            (**g_158) |= ((p_39 == (-(short)0x36CEL)) >= 0x41E0L);
        }
        else
        {
            unsigned l_356 = 0x5AACB81CL;
            int l_361 = 0x09BE1A63L;
            int l_424 = 0x90647940L;
            step_hash(187);
            l_356 ^= (*p_38);
            step_hash(197);
            if ((p_41 == (**g_157)))
            {
                int *l_359 = (void*)0;
                step_hash(189);
                (***g_157) = ((unsigned char)(p_38 != l_359) * (unsigned char)(((*g_157) == (void*)0) <= p_37));
            }
            else
            {
                step_hash(195);
                if ((*p_38))
                {
                    int *l_360 = &g_74;
                    step_hash(192);
                    return l_360;
                }
                else
                {
                    step_hash(194);
                    (*l_263) = (*l_263);
                }
                step_hash(196);
                (*l_230) = (**g_158);
            }
            step_hash(261);
            if ((*p_40))
            {
                unsigned short l_362 = 0xDF17L;
                unsigned l_365 = 4294967295UL;
                int *l_368 = &l_361;
                step_hash(199);
                l_361 = l_356;
                step_hash(200);
                (*p_41) = l_362;
                step_hash(211);
                if ((g_74 ^ (&p_40 != &p_38)))
                {
                    step_hash(202);
                    (*l_217) ^= 1L;
                    step_hash(203);
                    (**g_157) = (*g_158);
                }
                else
                {
                    step_hash(205);
                    (**g_157) = (void*)0;
                    step_hash(210);
                    if (((unsigned short)l_365 % (unsigned short)((signed char)0x7DL + (signed char)g_236)))
                    {
                        step_hash(207);
                        return p_38;
                    }
                    else
                    {
                        step_hash(209);
                        (*g_158) = (*g_158);
                    }
                }
                step_hash(212);
                (*g_158) = &l_361;
            }
            else
            {
                int *l_369 = &l_361;
                int l_393 = 5L;
                short l_412 = 0L;
                int ***l_423 = &g_158;
                signed char l_437 = 0xB2L;
                step_hash(227);
                if ((*p_41))
                {
                    step_hash(215);
                    return p_40;
                }
                else
                {
                    unsigned l_383 = 3UL;
                    step_hash(217);
                    l_383 ^= (g_236 != ((unsigned)(((g_74 != (((l_372 != (*l_230)) && (*l_369)) < ((unsigned short)((signed char)(g_48 != (*l_230)) << (signed char)g_111) << (unsigned short)((short)((unsigned char)((unsigned)((*p_38) & (*g_47)) + (unsigned)(*p_40)) % (unsigned char)4UL) % (short)5L)))) >= l_356) ^ 1UL) - (unsigned)g_74));
                    step_hash(225);
                    for (l_383 = 0; (l_383 >= 39); l_383 += 1)
                    {
                        int l_392 = 0x1CEDEFB3L;
                        step_hash(221);
                        (*l_263) = func_56((**g_157));
                        step_hash(222);
                        (**g_158) = ((short)(~((signed char)p_39 << (signed char)((((short)((~(g_111 == l_392)) > 2UL) << (short)13) < g_236) > l_393))) % (short)g_48);
                        step_hash(223);
                        (**g_158) = (g_48 >= (p_37 ^ (((((unsigned)g_48 + (unsigned)0x8D20E8FBL) && ((signed char)((p_39 == g_236) >= ((int)((short)(((unsigned char)((signed char)(((unsigned char)g_48 % (unsigned char)((short)((unsigned short)p_39 << (unsigned short)g_48) * (short)g_236)) <= g_111) % (signed char)g_111) + (unsigned char)g_111) > p_39) * (short)g_6) + (int)(**l_263))) + (signed char)0xFCL)) >= l_361) > p_37)));
                        step_hash(224);
                        (***g_157) |= l_412;
                    }
                    step_hash(226);
                    (**g_157) = &l_361;
                }
                step_hash(228);
                (*p_38) = (*l_369);
                step_hash(229);
                l_424 &= ((((short)g_236 / (short)(((signed char)0x16L + (signed char)((signed char)((unsigned short)(~g_48) >> (unsigned short)((&l_369 != &l_230) || ((*p_41) >= ((int)((&g_158 == l_423) < (**l_263)) + (int)l_356)))) - (signed char)g_111)) | (***l_423))) == p_39) <= g_6);
                step_hash(260);
                if ((g_236 <= 65535UL))
                {
                    step_hash(231);
                    (*p_38) = (*p_38);
                    step_hash(232);
                    p_40 = (**g_157);
                    step_hash(238);
                    if (((*g_157) != (void*)0))
                    {
                        unsigned l_425 = 0x6AB84D60L;
                        step_hash(234);
                        (**g_158) = (~(l_425 <= (+(((+(p_39 != ((unsigned char)g_428 + (unsigned char)p_37))) != p_37) > ((void*)0 != (*g_157))))));
                    }
                    else
                    {
                        step_hash(236);
                        g_429 &= (***g_157);
                        step_hash(237);
                        (**g_158) = (((p_39 <= ((*g_157) != (void*)0)) >= p_39) <= (((unsigned char)p_37 << (unsigned char)2) <= 1UL));
                    }
                }
                else
                {
                    unsigned l_432 = 4294967295UL;
                    step_hash(246);
                    if ((l_432 > ((short)((((int)l_432 / (int)l_437) > (-(signed char)0xC5L)) == (-(int)(g_74 >= (p_39 >= (**l_263))))) << (short)g_236)))
                    {
                        int *l_448 = &g_48;
                        unsigned short l_449 = 65533UL;
                        step_hash(241);
                        (*l_230) = 0xF60620FBL;
                        step_hash(242);
                        (***g_157) = ((int)((***l_423) || ((short)((((unsigned)(((unsigned char)((l_448 != p_40) != g_236) << (unsigned char)((*l_369) < ((((p_37 ^ p_39) && ((-1L) && (((void*)0 != p_41) >= p_37))) == g_48) != g_74))) != l_449) % (unsigned)0x352B3691L) == g_48) & (*g_47)) << (short)g_48)) - (int)p_37);
                    }
                    else
                    {
                        step_hash(244);
                        (**l_423) = p_41;
                        step_hash(245);
                        (*l_369) |= (!l_432);
                    }
                    step_hash(251);
                    for (g_236 = 7; (g_236 >= 37); g_236 += 3)
                    {
                        step_hash(250);
                        (**g_157) = &l_424;
                    }
                    step_hash(259);
                    for (l_432 = 0; (l_432 < 45); l_432 += 3)
                    {
                        int *l_456 = (void*)0;
                        int l_457 = 6L;
                        step_hash(255);
                        (*l_263) = (**g_157);
                        step_hash(256);
                        (*l_369) = ((short)g_6 % (short)0x7335L);
                        step_hash(257);
                        l_456 = func_56((*g_158));
                        step_hash(258);
                        l_457 ^= (~(*p_40));
                    }
                }
            }
            step_hash(266);
            for (p_37 = (-4); (p_37 != 7); p_37++)
            {
                short l_462 = 0xE1AAL;
                step_hash(265);
                (*p_40) |= ((unsigned)g_428 / (unsigned)((p_40 == &l_361) && (l_462 < l_462)));
            }
        }
    }
    else
    {
        unsigned short l_478 = 1UL;
        step_hash(269);
        (*p_38) ^= (***g_157);
        step_hash(270);
        l_463 &= (*g_47);
        step_hash(271);
        (*p_41) ^= (((p_39 ^ ((*g_47) & (((((short)((unsigned short)0xB452L * (unsigned short)(~((unsigned short)(g_429 ^ (((short)(((unsigned char)((unsigned char)((short)l_478 << (short)l_478) / (unsigned char)((unsigned char)(g_74 | (((unsigned char)g_111 << (unsigned char)2) | l_478)) * (unsigned char)0xE2L)) * (unsigned char)l_483) != p_37) / (short)1UL) >= g_48)) << (unsigned short)p_39))) - (short)1L) >= g_6) | g_428) ^ 3UL))) != g_429) < g_6);
    }
    step_hash(352);
    if (l_463)
    {
        unsigned short l_485 = 65534UL;
        step_hash(274);
        l_484 ^= (*p_38);
        step_hash(275);
        (*p_38) = (((*g_157) != (void*)0) != 0x6CL);
        step_hash(276);
        l_485 |= (*p_41);
    }
    else
    {
        unsigned l_488 = 0x38209BB8L;
        int l_526 = 0x0A336BF2L;
        int *l_539 = &g_74;
        step_hash(344);
        if ((*p_41))
        {
            unsigned char l_501 = 0x83L;
            int *l_507 = (void*)0;
            step_hash(309);
            for (g_111 = (-30); (g_111 == (-13)); g_111 += 1)
            {
                unsigned l_489 = 9UL;
                step_hash(282);
                l_489 ^= l_488;
            }
            step_hash(310);
            (*p_38) = ((short)l_488 * (short)(((+((unsigned char)p_37 / (unsigned char)(l_488 ^ ((int)(*p_38) % (int)((int)(l_488 > (0xECL | (p_37 | ((unsigned short)(0x631DL ^ g_429) + (unsigned short)p_39)))) + (int)4294967295UL))))) == g_6) && g_74));
            step_hash(311);
            (*g_158) = p_38;
            step_hash(312);
            l_526 |= (*p_41);
        }
        else
        {
            unsigned char l_531 = 0x50L;
            int l_532 = 0xFDA686F1L;
            int ***l_547 = (void*)0;
            short l_548 = 1L;
            step_hash(314);
            l_532 = (g_111 ^ ((unsigned short)((unsigned char)p_37 / (unsigned char)l_531) << (unsigned short)3));
            step_hash(315);
            (*p_41) = 0xF508F959L;
            step_hash(342);
            for (g_429 = 0; (g_429 > 11); ++g_429)
            {
                short l_535 = 0xCBCFL;
                step_hash(340);
                if ((l_535 < p_37))
                {
                    step_hash(327);
                    for (g_111 = (-8); (g_111 <= 5); g_111++)
                    {
                        signed char l_538 = (-1L);
                        step_hash(323);
                        (*p_38) = 0L;
                        step_hash(324);
                        (*p_38) = (0L & 1UL);
                        step_hash(325);
                        l_538 = 1L;
                        step_hash(326);
                        (*p_38) |= (-6L);
                    }
                    step_hash(328);
                    l_539 = &g_74;
                    step_hash(329);
                    return p_38;
                }
                else
                {
                    signed char l_540 = (-3L);
                    step_hash(331);
                    if (l_540)
                        break;
                    step_hash(338);
                    for (l_484 = 11; (l_484 > (-23)); l_484 -= 9)
                    {
                        step_hash(335);
                        (*p_41) = (*p_41);
                        step_hash(336);
                        (*g_157) = (*g_157);
                        step_hash(337);
                        if ((*p_38))
                            break;
                    }
                    step_hash(339);
                    (*l_539) |= 3L;
                }
                step_hash(341);
                l_539 = &l_532;
            }
            step_hash(343);
            l_548 = ((short)(((unsigned)p_39 - (unsigned)((*l_539) || p_39)) ^ (~(&g_158 != l_547))) / (short)((0xBDL | ((*l_539) == (*p_41))) ^ g_429));
        }
        step_hash(349);
        for (l_484 = 0; (l_484 <= 25); l_484 += 6)
        {
            short l_566 = 1L;
            int *l_568 = (void*)0;
            step_hash(348);
            (**g_157) = p_41;
        }
        step_hash(350);
        (**g_157) = p_38;
        step_hash(351);
        return p_41;
    }
    step_hash(353);
    (*p_41) = ((signed char)0xFEL * (signed char)((((*p_41) <= p_39) == (+(((signed char)(9UL && ((((short)((signed char)(g_6 | ((signed char)(p_37 != (p_37 && (((unsigned char)g_236 % (unsigned char)((unsigned char)((unsigned char)p_37 / (unsigned char)g_48) * (unsigned char)g_74)) & g_6))) >> (signed char)p_37)) / (signed char)g_48) * (short)g_429) > p_39) | g_236)) + (signed char)0x9DL) >= (*p_38)))) && g_429));
    step_hash(448);
    if ((~l_483))
    {
        short l_593 = (-1L);
        unsigned char l_596 = 0xD8L;
        int ***l_597 = &g_158;
        int *l_611 = &g_48;
        step_hash(355);
        (**g_157) = (void*)0;
        step_hash(425);
        if (((unsigned short)((unsigned)((unsigned short)p_37 * (unsigned short)(((unsigned char)(0x28L != 0x82L) >> (unsigned char)2) & ((l_593 | p_39) != ((signed char)p_37 << (signed char)4)))) - (unsigned)0xA47B8098L) << (unsigned short)(&l_484 == (void*)0)))
        {
            int *l_598 = &g_48;
            step_hash(362);
            if ((l_596 == (l_597 != (void*)0)))
            {
                step_hash(358);
                return l_598;
            }
            else
            {
                step_hash(360);
                (**l_597) = p_38;
                step_hash(361);
                (*g_158) = (void*)0;
            }
            step_hash(363);
            (*l_598) = 0xEF358BECL;
        }
        else
        {
            unsigned l_599 = 4294967295UL;
            int l_614 = 1L;
            step_hash(365);
            (*p_41) &= l_599;
            step_hash(405);
            if ((p_37 <= 0x82L))
            {
                int *l_602 = &g_74;
                step_hash(371);
                for (g_429 = 29; (g_429 == 60); g_429 += 2)
                {
                    step_hash(370);
                    return l_602;
                }
                step_hash(372);
                return l_602;
            }
            else
            {
                int l_605 = 0xBAE9B3C3L;
                step_hash(385);
                for (l_599 = 0; (l_599 > 43); ++l_599)
                {
                    step_hash(377);
                    if ((*p_41))
                        break;
                    step_hash(378);
                    (*p_38) = l_605;
                    step_hash(379);
                    (*g_157) = (*l_597);
                    step_hash(384);
                    for (g_429 = 0; (g_429 > 21); g_429++)
                    {
                        int *l_608 = &g_48;
                        step_hash(383);
                        return l_608;
                    }
                }
                step_hash(386);
                (*p_41) |= ((&g_158 == l_302) && 0xA2L);
                step_hash(404);
                for (l_483 = (-30); (l_483 < 19); l_483++)
                {
                    unsigned short l_617 = 65526UL;
                    unsigned char l_618 = 1UL;
                    step_hash(390);
                    (*g_158) = l_611;
                    step_hash(395);
                    for (p_37 = 0; (p_37 >= (-21)); p_37--)
                    {
                        step_hash(394);
                        (*l_611) = (*l_611);
                    }
                    step_hash(396);
                    l_614 = g_565;
                    step_hash(403);
                    for (g_236 = 0; (g_236 == 56); g_236++)
                    {
                        step_hash(400);
                        if (l_617)
                            break;
                        step_hash(401);
                        (*p_38) ^= l_617;
                        step_hash(402);
                        (*p_41) = l_618;
                    }
                }
            }
            step_hash(424);
            for (p_39 = 0; (p_39 <= (-8)); p_39--)
            {
                unsigned short l_622 = 0x8DE9L;
                step_hash(423);
                if ((&p_41 == (*g_157)))
                {
                    step_hash(410);
                    (**l_597) = &l_614;
                }
                else
                {
                    int *l_621 = (void*)0;
                    step_hash(412);
                    (**l_597) = l_621;
                    step_hash(413);
                    (*l_611) ^= l_622;
                    step_hash(421);
                    for (l_483 = 0; (l_483 != 14); l_483 += 7)
                    {
                        int *l_633 = (void*)0;
                        step_hash(417);
                        (*p_38) = ((unsigned short)((unsigned short)((short)((((((unsigned char)((l_633 == (void*)0) == (((unsigned short)((*p_41) >= (0x76B3L | ((unsigned)g_111 / (unsigned)0x27EE7266L))) >> (unsigned short)13) | 0xA82EL)) >> (unsigned char)(((unsigned char)(&l_484 == (void*)0) + (unsigned char)1UL) > l_599)) | 0x0386C42FL) && (-6L)) != g_6) != p_37) / (short)g_236) >> (unsigned short)2) * (unsigned short)p_37);
                        step_hash(418);
                        if ((*l_611))
                            continue;
                        step_hash(419);
                        if ((*p_41))
                            continue;
                        step_hash(420);
                        return p_41;
                    }
                    step_hash(422);
                    if (l_622)
                        break;
                }
            }
        }
        step_hash(426);
        (**g_157) = (void*)0;
    }
    else
    {
        int l_645 = (-1L);
        step_hash(446);
        for (l_463 = 0; (l_463 >= 13); l_463 += 3)
        {
            int **l_644 = &l_217;
            step_hash(437);
            for (g_111 = 2; (g_111 == 26); g_111 += 1)
            {
                step_hash(434);
                if ((*p_41))
                    break;
                step_hash(435);
                l_644 = (*g_157);
                step_hash(436);
                if (l_645)
                    break;
            }
            step_hash(444);
            for (p_37 = 23; (p_37 > 16); p_37--)
            {
                step_hash(441);
                (*p_41) &= (-1L);
                step_hash(442);
                (*p_41) &= ((-4L) <= g_111);
                step_hash(443);
                (**g_157) = p_41;
            }
            step_hash(445);
            return p_41;
        }
        step_hash(447);
        (*g_158) = l_648;
    }
    step_hash(449);
    return p_41;
}
static int * func_42(int * p_43, int p_44, unsigned p_45, int * p_46)
{
    int *l_214 = &g_74;
    step_hash(68);
    (*g_47) = 0x5BF8BA2EL;
    step_hash(69);
    return l_214;
}
static int * func_54(int * p_55)
{
    unsigned char l_98 = 248UL;
    int **l_130 = &g_47;
    int l_150 = (-3L);
    int l_211 = 0x6D60A08BL;
    int *l_213 = &g_74;
    int **l_212 = &l_213;
    step_hash(63);
    if ((g_48 && 1L))
    {
        signed char l_97 = 1L;
        step_hash(16);
        (*g_47) = (4294967289UL ^ l_97);
        step_hash(17);
        (*g_47) |= l_98;
    }
    else
    {
        short l_101 = 0x4853L;
        int l_169 = 0xB14249AAL;
        unsigned char l_180 = 2UL;
        int ***l_192 = &g_158;
        step_hash(19);
        (*g_47) = (*p_55);
        step_hash(31);
        for (g_74 = (-10); (g_74 >= 23); ++g_74)
        {
            step_hash(23);
            l_101 &= (*p_55);
            step_hash(28);
            for (g_48 = 0; (g_48 >= 19); g_48 += 1)
            {
                step_hash(27);
                if ((*p_55))
                    break;
            }
            step_hash(29);
            if ((*p_55))
                continue;
            step_hash(30);
            return p_55;
        }
        step_hash(62);
        if (((0x90L ^ (0UL != (l_101 ^ g_74))) && (~(*p_55))))
        {
            int *l_104 = &g_74;
            signed char l_133 = (-3L);
            step_hash(33);
            (*l_104) = (g_48 != (l_104 != p_55));
            step_hash(50);
            if (((int)(*p_55) - (int)((((unsigned char)g_6 / (unsigned char)((unsigned short)g_111 % (unsigned short)((&g_47 == (void*)0) && (*l_104)))) != g_6) | (*l_104))))
            {
                int **l_112 = &l_104;
                step_hash(35);
                (*l_112) = func_56(&g_74);
            }
            else
            {
                int l_127 = 0L;
                step_hash(48);
                for (g_74 = (-28); (g_74 != 10); g_74++)
                {
                    short l_149 = 1L;
                    step_hash(46);
                    for (g_48 = (-25); (g_48 != (-19)); g_48++)
                    {
                        int **l_118 = &g_47;
                        int ***l_117 = &l_118;
                        int **l_119 = (void*)0;
                        int **l_120 = &l_104;
                        step_hash(43);
                        (*l_117) = &g_47;
                        step_hash(44);
                        (*l_120) = func_56(&g_74);
                        step_hash(45);
                        l_133 = ((unsigned short)0x83D4L * (unsigned short)(((unsigned short)((short)(l_127 & (((void*)0 != &g_47) ^ (l_130 != (void*)0))) >> (short)12) + (unsigned short)((!((*l_104) == 1L)) < ((((int)l_101 % (int)0x17FA172CL) <= l_127) && 9UL))) < l_101));
                    }
                    step_hash(47);
                    l_150 &= ((-1L) >= (((short)((int)(~(+(((int)((-(short)((unsigned char)l_127 - (unsigned char)((unsigned char)(**l_130) + (unsigned char)(l_101 | g_111)))) && (**l_130)) + (int)((short)((short)g_111 - (short)l_149) >> (short)2)) >= (*g_47)))) % (int)(*l_104)) + (short)65535UL) > g_48));
                }
                step_hash(49);
                l_169 ^= ((signed char)((signed char)(0x8BD6L | (((signed char)((g_157 != &g_158) ^ ((signed char)(((short)g_74 << (short)((unsigned)0x05BDF17FL + (unsigned)(***g_157))) >= (&l_104 == &p_55)) >> (signed char)0)) >> (signed char)(((unsigned short)((short)g_111 - (short)(**l_130)) >> (unsigned short)g_74) ^ g_6)) || 0x4013L)) + (signed char)g_6) - (signed char)g_48);
            }
            step_hash(51);
            l_150 &= ((((short)l_101 >> (short)l_169) > 0x33BC337EL) != (((signed char)((0L > (**l_130)) <= ((signed char)((unsigned)(**l_130) / (unsigned)(((0x6D41FC1BL >= g_74) == ((signed char)((1L && (**l_130)) >= 0x23L) * (signed char)0x6AL)) & g_48)) - (signed char)g_74)) % (signed char)2UL) < l_180));
            step_hash(56);
            for (l_180 = 17; (l_180 <= 59); l_180 += 1)
            {
                step_hash(55);
                return l_104;
            }
        }
        else
        {
            unsigned char l_189 = 0UL;
            int *l_209 = (void*)0;
            int *l_210 = &l_150;
            step_hash(58);
            (*g_47) = ((unsigned char)(((**l_130) == (+l_101)) ^ (l_169 == (**l_130))) << (unsigned char)((((signed char)((unsigned char)g_74 + (unsigned char)l_189) << (signed char)0) > ((((l_101 > l_169) > (&l_130 == l_192)) & g_48) > (***l_192))) != l_189));
            step_hash(59);
            (***g_157) = (***g_157);
            step_hash(60);
            l_169 ^= (*g_47);
            step_hash(61);
            (*l_210) |= ((signed char)(0x58F93B69L != ((***l_192) <= ((short)(((unsigned char)(1L & (**l_130)) - (unsigned char)((unsigned char)(0xD213L != (**l_130)) << (unsigned char)3)) < g_74) % (short)((signed char)((signed char)((signed char)((unsigned)l_189 - (unsigned)((**l_130) & 65535UL)) - (signed char)2L) - (signed char)(***l_192)) >> (signed char)(***l_192))))) % (signed char)l_189);
        }
    }
    step_hash(64);
    l_211 &= ((p_55 != (*l_130)) != (**g_158));
    step_hash(65);
    (*l_212) = func_58((**l_130), g_111, (**l_130), (**l_130), func_56(func_56(p_55)));
    step_hash(66);
    return (*g_158);
}
static int * func_56(int * p_57)
{
    step_hash(13);
    return p_57;
}
static int * func_58(unsigned p_59, unsigned short p_60, unsigned short p_61, unsigned short p_62, int * p_63)
{
    int *l_72 = (void*)0;
    int l_84 = 0x102D1F73L;
    step_hash(10);
    for (p_62 = (-15); (p_62 != 20); p_62 += 5)
    {
        int *l_73 = &g_74;
        int **l_75 = &l_72;
        step_hash(6);
        (*l_73) &= ((*g_47) || ((void*)0 == l_72));
        step_hash(7);
        (*l_75) = l_72;
        step_hash(8);
        (*l_73) = ((unsigned short)((signed char)((unsigned char)g_48 - (unsigned char)p_59) / (signed char)((unsigned short)l_84 + (unsigned short)((unsigned short)((unsigned short)((unsigned char)g_74 << (unsigned char)6) - (unsigned short)((int)(g_6 & (-1L)) / (int)((int)(-5L) + (int)g_6))) << (unsigned short)(&p_63 == (void*)0)))) * (unsigned short)l_84);
        step_hash(9);
        (*p_63) &= (0x59L ^ ((short)0L << (short)10));
    }
    step_hash(11);
    return p_63;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_6, "g_6", print_hash_value);
    transparent_crc(g_48, "g_48", print_hash_value);
    transparent_crc(g_74, "g_74", print_hash_value);
    transparent_crc(g_111, "g_111", print_hash_value);
    transparent_crc(g_236, "g_236", print_hash_value);
    transparent_crc(g_428, "g_428", print_hash_value);
    transparent_crc(g_429, "g_429", print_hash_value);
    transparent_crc(g_565, "g_565", print_hash_value);
    transparent_crc(g_567, "g_567", print_hash_value);
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
