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
static unsigned g_16 = 4294967286UL;
static int g_69 = 0L;
static signed char g_75 = 0xD5L;
static int g_96 = 1L;
static int *g_106 = &g_69;
static int **g_105 = &g_106;
static int *g_216 = &g_69;
static int g_262 = (-6L);
static int g_423 = 0x26FEDE40L;
static int g_801 = 0xDEFB6F4AL;
static unsigned short func_1(void);
static short func_2(unsigned short p_3, unsigned p_4, int p_5, int p_6, unsigned char p_7);
static int func_11(unsigned p_12, short p_13, int p_14, unsigned p_15);
static unsigned short func_23(unsigned p_24);
static short func_25(signed char p_26, int p_27, int p_28, signed char p_29, signed char p_30);
static unsigned func_33(signed char p_34, unsigned p_35);
static int func_36(unsigned p_37, unsigned char p_38);
static short func_40(unsigned char p_41, signed char p_42, unsigned short p_43, unsigned short p_44, unsigned p_45);
static int * func_53(int * p_54);
static int * func_55(short p_56, int p_57, int p_58);
static unsigned short func_1(void)
{
    signed char l_10 = 0x49L;
    int l_39 = 0L;
    int *l_800 = &g_801;
    unsigned l_802 = 4294967293UL;
    step_hash(474);
    (*l_800) ^= (func_2(((unsigned char)(l_10 && func_11(l_10, g_16, ((signed char)g_16 << (signed char)6), ((signed char)(((short)(-1L) + (short)func_23(((g_16 || func_25((((int)(!0x817D1DC6L) + (int)func_33((1UL == func_36(l_39, g_16)), g_423)) || 0xBF6DL), g_423, g_423, g_423, g_16)) > g_16))) && 0x3AL) + (signed char)g_16))) + (unsigned char)l_10), l_39, g_16, l_39, g_16) == 65533UL);
    step_hash(475);
    return l_802;
}
static short func_2(unsigned short p_3, unsigned p_4, int p_5, int p_6, unsigned char p_7)
{
    signed char l_778 = (-2L);
    int l_791 = (-8L);
    step_hash(471);
    for (g_16 = 0; (g_16 >= 4); g_16 += 7)
    {
        int *l_780 = &g_262;
        step_hash(463);
        (*g_105) = &p_5;
        step_hash(468);
        for (p_6 = 5; (p_6 == (-2)); --p_6)
        {
            int *l_779 = &g_96;
            step_hash(467);
            (*l_779) = (l_778 | 0L);
        }
        step_hash(469);
        (*l_780) = (-2L);
        step_hash(470);
        (*l_780) = ((unsigned short)(g_75 | ((int)p_6 - (int)g_96)) + (unsigned short)g_69);
    }
    step_hash(472);
    p_5 = l_778;
    step_hash(473);
    return p_5;
}
static int func_11(unsigned p_12, short p_13, int p_14, unsigned p_15)
{
    int l_773 = 0x9F0AFEDCL;
    step_hash(458);
    return l_773;
}
static unsigned short func_23(unsigned p_24)
{
    int l_768 = (-6L);
    int *l_769 = (void*)0;
    int *l_770 = (void*)0;
    int *l_771 = (void*)0;
    int *l_772 = &g_96;
    step_hash(454);
    (*l_772) = l_768;
    step_hash(455);
    (*l_772) ^= p_24;
    step_hash(456);
    return g_423;
}
static short func_25(signed char p_26, int p_27, int p_28, signed char p_29, signed char p_30)
{
    int l_594 = (-3L);
    int *l_601 = (void*)0;
    int *l_626 = &g_96;
    unsigned l_650 = 4294967286UL;
    unsigned short l_679 = 0x30BDL;
    int ***l_700 = &g_105;
    int *l_744 = (void*)0;
    step_hash(343);
    (*g_216) |= (((l_594 || (p_26 && ((short)((short)((signed char)l_594 * (signed char)g_96) << (short)8) >> (short)7))) != ((void*)0 == l_601)) & 255UL);
    step_hash(349);
    if ((**g_105))
    {
        int **l_602 = &g_106;
        step_hash(345);
        (**g_105) = ((void*)0 == l_602);
        step_hash(346);
        (*g_216) = 0x12E89829L;
    }
    else
    {
        step_hash(348);
        return p_29;
    }
    step_hash(383);
    if (p_29)
    {
        int l_610 = (-3L);
        step_hash(351);
        (*g_216) = p_26;
        step_hash(369);
        for (g_75 = 27; (g_75 == 24); g_75 -= 7)
        {
            int ***l_611 = &g_105;
            step_hash(355);
            if (p_28)
                break;
        }
    }
    else
    {
        unsigned short l_616 = 0x130DL;
        step_hash(376);
        for (p_30 = 0; (p_30 < 6); p_30 += 6)
        {
        }
        step_hash(382);
        if ((l_616 != 0L))
        {
            int l_623 = 0xD56A67A9L;
            step_hash(378);
            (*g_216) = ((0x7D15100DL == ((signed char)l_623 >> (signed char)2)) == ((*g_216) ^ ((signed char)(p_29 | g_75) + (signed char)p_29)));
        }
        else
        {
            step_hash(380);
            (*g_105) = l_601;
            step_hash(381);
            (*g_105) = (*g_105);
        }
    }
    step_hash(451);
    if (((g_16 ^ ((void*)0 == l_626)) > ((unsigned short)((unsigned)(((unsigned char)(p_28 > p_26) - (unsigned char)(((*l_626) < 0x5440L) & ((unsigned char)((-1L) ^ (((g_423 ^ p_30) & p_29) || 0x9EEFL)) >> (unsigned char)7))) < 0xA4L) / (unsigned)p_28) >> (unsigned short)5)))
    {
        int *l_635 = &g_423;
        step_hash(385);
        (*g_105) = l_635;
        step_hash(386);
        (*g_105) = l_635;
    }
    else
    {
        signed char l_636 = 9L;
        unsigned short l_649 = 0x763DL;
        int ***l_699 = (void*)0;
        int l_701 = 1L;
        int **l_715 = &g_216;
        signed char l_751 = 0x96L;
        int **l_762 = &l_601;
        step_hash(388);
        l_636 &= p_27;
        step_hash(389);
        (*g_105) = (*g_105);
        step_hash(449);
        if (((signed char)((short)((unsigned char)g_16 + (unsigned char)(((-1L) ^ func_33(((((((short)((void*)0 != &g_216) >> (short)((unsigned char)((*l_626) >= ((short)func_33(g_262, g_16) + (short)(l_649 == g_16))) >> (unsigned char)5)) == 0x7EL) || 0x8AE71177L) ^ g_262) <= (*l_626)), p_28)) < g_69)) / (short)l_650) >> (signed char)l_636))
        {
            step_hash(400);
            for (g_423 = 0; (g_423 > 12); g_423++)
            {
                int *l_655 = (void*)0;
                step_hash(398);
                for (p_27 = 19; (p_27 < (-8)); p_27 -= 1)
                {
                    step_hash(397);
                    (*g_105) = l_655;
                }
                step_hash(399);
                (*l_626) |= (g_423 < ((g_75 > (!((-5L) <= 6UL))) || p_26));
            }
            step_hash(405);
            for (l_649 = (-4); (l_649 >= 33); ++l_649)
            {
                step_hash(404);
                return p_29;
            }
        }
        else
        {
            unsigned l_678 = 1UL;
            int l_680 = 0xF87A307DL;
            int **l_716 = &l_626;
            step_hash(412);
            for (p_29 = 12; (p_29 > (-26)); --p_29)
            {
                step_hash(410);
                (*l_626) = (((g_262 >= ((unsigned short)65535UL << (unsigned short)7)) > l_636) != g_262);
                step_hash(411);
                (*l_626) &= (g_75 == ((void*)0 != (*g_105)));
            }
            step_hash(413);
            l_680 &= ((unsigned char)p_27 / (unsigned char)(-10L));
            step_hash(447);
            if (((unsigned char)p_26 >> (unsigned char)4))
            {
                short l_717 = 1L;
                short l_720 = 1L;
                step_hash(415);
                (*l_626) = (((((unsigned char)p_29 + (unsigned char)(((int)((short)(((-(unsigned char)((signed char)((signed char)(((unsigned)p_30 % (unsigned)((l_715 != l_716) & p_30)) || (l_717 ^ (((-1L) >= (p_29 <= 0x06L)) || l_717))) % (signed char)0xB1L) % (signed char)l_717)) < l_720) < 0L) * (short)p_29) % (int)l_720) <= g_423)) <= g_16) != g_16) && p_29);
                step_hash(420);
                for (g_262 = (-9); (g_262 > (-7)); g_262 += 2)
                {
                    step_hash(419);
                    (*l_715) = (*g_105);
                }
            }
            else
            {
                unsigned l_739 = 8UL;
                int *l_740 = &g_69;
                step_hash(443);
                if ((((signed char)0xB4L - (signed char)(&g_106 != (*l_700))) ^ g_75))
                {
                    unsigned char l_727 = 0x3CL;
                    unsigned char l_736 = 0x19L;
                    step_hash(423);
                    (**l_700) = (*l_716);
                    step_hash(424);
                    (*l_715) = (*g_105);
                    step_hash(429);
                    for (g_423 = 0; (g_423 < (-28)); g_423 -= 8)
                    {
                        step_hash(428);
                        return l_727;
                    }
                    step_hash(430);
                    (***l_700) = (((signed char)0x72L - (signed char)p_28) < ((signed char)p_28 * (signed char)(((unsigned char)((((g_69 ^ (**g_105)) & (((unsigned)0UL % (unsigned)l_736) == ((p_29 != ((signed char)l_739 + (signed char)g_69)) == 0x7799L))) == 246UL) != p_30) * (unsigned char)p_29) <= 0x0CL)));
                }
                else
                {
                    step_hash(436);
                    if (p_26)
                    {
                        step_hash(433);
                        (**l_700) = (*g_105);
                    }
                    else
                    {
                        step_hash(435);
                        (*l_716) = (*l_715);
                    }
                    step_hash(442);
                    for (p_26 = 17; (p_26 <= (-7)); p_26 -= 5)
                    {
                        short l_743 = 0x98FFL;
                        step_hash(440);
                        (**l_700) = l_740;
                        step_hash(441);
                        if (l_743)
                            continue;
                    }
                }
                step_hash(444);
                (*g_105) = l_744;
                step_hash(445);
                (*g_105) = (*g_105);
                step_hash(446);
                (*l_740) = ((unsigned char)(!((!((void*)0 == &l_740)) != 0x3845L)) << (unsigned char)4);
            }
            step_hash(448);
            l_701 = (~((unsigned char)((unsigned)((g_423 > g_16) != g_75) / (unsigned)func_33((l_751 ^ (((unsigned short)((((unsigned char)255UL << (unsigned char)g_69) || ((int)(-1L) + (int)4294967290UL)) | (((p_26 != p_26) & p_28) >= 4UL)) - (unsigned short)g_75) >= g_16)), p_29)) + (unsigned char)0x57L));
        }
        step_hash(450);
        g_69 = ((p_26 < (((unsigned char)255UL + (unsigned char)g_262) && (func_33(((void*)0 != l_762), (((unsigned)(-(short)g_96) % (unsigned)7L) == func_33(p_27, ((unsigned short)g_262 + (unsigned short)p_27)))) < g_75))) || g_262);
    }
    step_hash(452);
    return g_96;
}
static unsigned func_33(signed char p_34, unsigned p_35)
{
    int ***l_593 = &g_105;
    step_hash(340);
    (*l_593) = &g_216;
    step_hash(341);
    return g_16;
}
static int func_36(unsigned p_37, unsigned char p_38)
{
    unsigned char l_46 = 0xEBL;
    int l_268 = (-8L);
    int **l_274 = &g_106;
    int **l_294 = &g_106;
    short l_304 = 0x7A3FL;
    short l_335 = 0xFA44L;
    int l_437 = 0xB7EF2194L;
    unsigned l_563 = 4294967287UL;
    signed char l_575 = 0xB5L;
    step_hash(152);
    if ((func_40(l_46, (g_16 && (-1L)), (((unsigned char)g_16 * (unsigned char)(((int)0x5C3421ADL - (int)(((int)(l_46 != l_46) - (int)g_16) & (g_16 && 0x5EL))) > l_46)) || p_38), g_16, p_38) & p_37))
    {
        int *l_263 = &g_262;
        step_hash(134);
        (*g_105) = l_263;
        step_hash(135);
        (*l_263) ^= p_38;
        step_hash(136);
        (**g_105) = ((int)((unsigned short)0x0710L / (unsigned short)1UL) % (int)(*g_106));
        step_hash(137);
        l_268 ^= (*g_106);
    }
    else
    {
        unsigned l_285 = 8UL;
        int l_295 = (-2L);
        step_hash(139);
        (*g_105) = &l_268;
        step_hash(145);
        for (l_268 = 0; (l_268 < 3); ++l_268)
        {
            short l_271 = (-8L);
            step_hash(143);
            (*g_216) = l_271;
            step_hash(144);
            (*g_105) = (*g_105);
        }
        step_hash(146);
        l_295 &= ((unsigned)(l_274 == (void*)0) - (unsigned)(+((signed char)((short)0xF413L - (short)(g_75 == ((-4L) <= ((unsigned char)(**l_274) % (unsigned char)((((signed char)l_285 + (signed char)((short)(((short)(g_69 ^ ((unsigned short)((unsigned short)((~(l_274 == l_294)) || (-1L)) - (unsigned short)0x3486L) << (unsigned short)6)) % (short)65529UL) != g_262) << (short)5)) >= 0x1DA3L) | g_262))))) >> (signed char)6)));
        step_hash(151);
        for (g_75 = 0; (g_75 > (-5)); g_75 -= 6)
        {
            step_hash(150);
            (*l_274) = func_53(&l_295);
        }
    }
    step_hash(153);
    (*l_294) = (void*)0;
    step_hash(258);
    for (l_46 = 0; (l_46 == 12); ++l_46)
    {
        signed char l_303 = (-6L);
        int l_305 = 0x8757D178L;
        int ***l_343 = &l_294;
        int *l_354 = (void*)0;
    }
    step_hash(337);
    for (g_75 = 0; (g_75 == 21); g_75 += 3)
    {
        unsigned l_509 = 0UL;
        int *l_514 = (void*)0;
        int l_540 = 0xDF32F65BL;
        unsigned l_548 = 1UL;
        unsigned l_551 = 0x09FD417FL;
        signed char l_583 = (-10L);
    }
    step_hash(338);
    return p_37;
}
static short func_40(unsigned char p_41, signed char p_42, unsigned short p_43, unsigned short p_44, unsigned p_45)
{
    int l_61 = 1L;
    unsigned char l_66 = 0x26L;
    int l_67 = 5L;
    unsigned char l_174 = 1UL;
    int **l_241 = &g_216;
    step_hash(33);
    (*g_105) = func_53(func_55((((p_44 < ((((short)l_61 * (short)((signed char)((signed char)(!(g_16 ^ g_16)) + (signed char)(l_61 == (l_61 && l_66))) << (signed char)4)) | l_61) >= g_16)) == l_67) & l_61), g_16, l_61));
    step_hash(131);
    for (g_96 = 0; (g_96 <= 17); g_96++)
    {
        int **l_147 = &g_106;
        int l_221 = 0x325B7F87L;
        int ***l_222 = &g_105;
        int *l_227 = (void*)0;
        unsigned l_240 = 0x1A5ED94EL;
        step_hash(62);
        for (p_45 = 5; (p_45 == 57); p_45 += 4)
        {
            signed char l_122 = (-9L);
            int l_123 = 0x728EF6BEL;
            int *l_155 = &l_123;
            step_hash(40);
            l_123 ^= (((unsigned)((g_75 == (-6L)) || l_122) % (unsigned)(g_75 & p_43)) < p_42);
            step_hash(41);
            (*g_105) = &l_61;
            step_hash(60);
            for (l_66 = 0; (l_66 >= 31); l_66++)
            {
                int l_136 = 1L;
                step_hash(57);
                for (p_42 = 0; (p_42 > (-20)); --p_42)
                {
                    unsigned char l_135 = 0xC0L;
                    int **l_137 = &g_106;
                    step_hash(48);
                    l_136 ^= ((**g_105) ^ ((p_42 >= p_44) & ((signed char)(((unsigned short)(-(unsigned char)((signed char)((l_135 | 0L) ^ (p_41 > 0x259BBF2BL)) / (signed char)g_96)) >> (unsigned short)11) & p_45) * (signed char)0xA3L)));
                    step_hash(55);
                    if (((((void*)0 != l_137) == l_67) <= ((**g_105) != ((signed char)(-6L) - (signed char)l_123))))
                    {
                        unsigned l_146 = 0xD03AD187L;
                        step_hash(50);
                        (**g_105) = (((void*)0 != &g_106) < p_41);
                        step_hash(51);
                        (**l_137) = (((p_44 && (g_69 >= ((**l_137) > ((((unsigned)g_16 - (unsigned)l_123) && (((p_44 == g_96) <= ((unsigned)((*g_105) != (*g_105)) + (unsigned)0x345E11D1L)) == p_42)) >= l_61)))) && l_146) > 1UL);
                    }
                    else
                    {
                        int ***l_148 = &l_137;
                        step_hash(53);
                        (*l_148) = l_147;
                        step_hash(54);
                        (**l_147) ^= ((unsigned char)((unsigned char)g_75 - (unsigned char)1UL) + (unsigned char)((((signed char)((*g_105) != (void*)0) * (signed char)p_45) & (((void*)0 != l_155) != ((unsigned short)((unsigned short)((short)((void*)0 != &g_106) >> (short)g_96) >> (unsigned short)7) / (unsigned short)65535UL))) > 0xB3L));
                    }
                    step_hash(56);
                    (**l_137) = p_45;
                }
                step_hash(58);
                if ((**g_105))
                    break;
                step_hash(59);
                if ((*g_106))
                    break;
            }
            step_hash(61);
            (**l_147) = (l_67 | (*l_155));
        }
    }
    step_hash(132);
    return g_16;
}
static int * func_53(int * p_54)
{
    signed char l_74 = 0x12L;
    int *l_76 = &g_69;
    step_hash(30);
    if (((((unsigned short)0x25ACL >> (unsigned short)(p_54 == (void*)0)) && (((unsigned char)(l_74 >= (g_75 | l_74)) << (unsigned char)g_75) != (l_76 == (void*)0))) | (*l_76)))
    {
        int l_77 = 0xC8D67996L;
        int *l_89 = &g_69;
        step_hash(20);
        if ((*l_76))
        {
            unsigned l_88 = 0x704422F2L;
            int l_94 = 1L;
            step_hash(15);
            if (((l_77 > ((short)(((unsigned short)(((p_54 != &g_69) > 0x8620L) >= l_77) % (unsigned short)((unsigned char)(((unsigned short)1UL / (unsigned short)((unsigned char)(g_16 & ((l_88 == g_16) < l_77)) + (unsigned char)l_88)) ^ 0UL) / (unsigned char)(-1L))) < 0L) % (short)0x3969L)) >= 246UL))
            {
                step_hash(10);
                (*l_76) |= ((void*)0 != l_89);
            }
            else
            {
                int **l_90 = (void*)0;
                int l_93 = 0x59A4365CL;
                step_hash(12);
                p_54 = &g_69;
                step_hash(13);
                (*l_89) = ((unsigned char)(*l_89) >> (unsigned char)6);
                step_hash(14);
                l_94 ^= (g_69 & l_93);
            }
        }
        else
        {
            int *l_95 = &g_96;
            step_hash(17);
            (*l_95) &= (*l_89);
            step_hash(18);
            (*l_76) = (-(int)0xAE665256L);
            step_hash(19);
            (*l_95) = (*p_54);
        }
    }
    else
    {
        int l_115 = (-1L);
        step_hash(22);
        g_96 |= g_69;
        step_hash(27);
        for (g_69 = 28; (g_69 > 26); g_69--)
        {
            step_hash(26);
            return p_54;
        }
        step_hash(28);
        (*p_54) = (((short)(-(signed char)((signed char)(((g_105 != (void*)0) & ((short)(g_96 ^ (*l_76)) >> (short)1)) != ((signed char)0L - (signed char)((int)(*g_106) - (int)((unsigned short)65531UL >> (unsigned short)11)))) % (signed char)(*l_76))) / (short)1UL) && 6UL);
        step_hash(29);
        (*l_76) &= l_115;
    }
    step_hash(31);
    (*g_105) = l_76;
    step_hash(32);
    return l_76;
}
static int * func_55(short p_56, int p_57, int p_58)
{
    int *l_68 = &g_69;
    step_hash(4);
    (*l_68) = (-1L);
    step_hash(5);
    return l_68;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_16, "g_16", print_hash_value);
    transparent_crc(g_69, "g_69", print_hash_value);
    transparent_crc(g_75, "g_75", print_hash_value);
    transparent_crc(g_96, "g_96", print_hash_value);
    transparent_crc(g_262, "g_262", print_hash_value);
    transparent_crc(g_423, "g_423", print_hash_value);
    transparent_crc(g_801, "g_801", print_hash_value);
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
