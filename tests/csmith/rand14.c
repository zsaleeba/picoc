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
static int g_4 = 0L;
static int g_51 = (-3L);
static int *g_67 = &g_4;
static int **g_66 = &g_67;
static signed char g_96 = (-9L);
static int g_98 = 0x977F3D96L;
static int g_183 = 0x97D6553EL;
static int *g_194 = (void*)0;
static int g_225 = (-1L);
static int func_1(void);
static int * func_5(int * p_6, int * p_7, unsigned short p_8);
static int * func_9(int * p_10);
static int * func_11(short p_12, int * p_13, short p_14, unsigned p_15);
static signed char func_16(int * p_17);
static int func_18(int * p_19, unsigned char p_20, int p_21);
static int * func_22(unsigned p_23);
static int * func_27(int * p_28, int * p_29, short p_30, int * p_31, signed char p_32);
static short func_35(int * p_36);
static signed char func_40(unsigned short p_41, short p_42, int p_43, int * p_44);
static int func_1(void)
{
    unsigned short l_2 = 65531UL;
    int *l_3 = &g_4;
    int l_300 = 0L;
    int **l_302 = &g_194;
    step_hash(1);
    (*l_3) = (0xE7L & l_2);
    step_hash(161);
    (*l_302) = func_5(func_9(func_11((((-5L) && g_4) < (*l_3)), &g_4, (*l_3), (g_4 && (0x60CBL | (!((*l_3) >= func_16(l_3))))))), &g_4, l_300);
    step_hash(162);
    (*l_3) = (((*l_3) >= (*l_3)) <= 1L);
    step_hash(163);
    return (*l_3);
}
static int * func_5(int * p_6, int * p_7, unsigned short p_8)
{
    int **l_301 = &g_194;
    step_hash(158);
    (*l_301) = p_6;
    step_hash(159);
    (*l_301) = (void*)0;
    step_hash(160);
    return p_6;
}
static int * func_9(int * p_10)
{
    int **l_299 = &g_194;
    step_hash(153);
    (*p_10) = (*p_10);
    step_hash(154);
    (*p_10) &= 0L;
    step_hash(155);
    (*p_10) &= ((void*)0 != l_299);
    step_hash(156);
    return (*l_299);
}
static int * func_11(short p_12, int * p_13, short p_14, unsigned p_15)
{
    unsigned short l_296 = 65535UL;
    int l_297 = 1L;
    int *l_298 = &g_225;
    step_hash(150);
    for (p_14 = 0; (p_14 == (-22)); p_14--)
    {
        step_hash(149);
        l_297 = l_296;
    }
    step_hash(151);
    return l_298;
}
static signed char func_16(int * p_17)
{
    unsigned char l_24 = 255UL;
    int ***l_166 = &g_66;
    unsigned l_167 = 0xDFF48E3CL;
    int *l_260 = &g_225;
    unsigned l_279 = 0x77DEF9FAL;
    int *l_280 = &g_183;
    short l_288 = 0L;
    int *l_291 = &g_51;
    int **l_292 = (void*)0;
    int **l_293 = &g_67;
    step_hash(135);
    (*l_260) = func_18(func_22(l_24), ((short)(l_24 < (l_166 == l_166)) + (short)l_167), l_167);
    step_hash(136);
    g_67 = l_260;
    step_hash(142);
    if ((((signed char)g_183 << (signed char)1) & ((unsigned char)g_51 % (unsigned char)((((unsigned char)1UL % (unsigned char)(*l_260)) || (*l_260)) | ((-4L) | ((unsigned)((unsigned char)((unsigned char)((short)(((*p_17) && (((((((g_183 > (((signed char)((short)(*l_260) << (short)l_279) << (signed char)(*l_260)) > 0x7E62A801L)) ^ 65530UL) && (*l_260)) || 0xF591A87AL) >= (*l_260)) >= 246UL) || g_183)) > (*l_260)) >> (short)(*l_260)) >> (unsigned char)7) / (unsigned char)g_51) / (unsigned)0x4F71ED02L))))))
    {
        int **l_281 = (void*)0;
        int **l_282 = &g_67;
        step_hash(138);
        (*l_282) = l_280;
    }
    else
    {
        int *l_285 = &g_98;
        step_hash(140);
        (*g_67) |= ((((int)(*l_285) / (int)4UL) == l_288) | (-1L));
        step_hash(141);
        (*l_285) = (*g_67);
    }
    step_hash(143);
    (*l_293) = (void*)0;
    step_hash(144);
    return (*l_280);
}
static int func_18(int * p_19, unsigned char p_20, int p_21)
{
    unsigned l_168 = 0xA4222F61L;
    int *l_169 = (void*)0;
    int *l_170 = &g_98;
    unsigned char l_206 = 9UL;
    int *l_256 = (void*)0;
    int *l_257 = (void*)0;
    int l_258 = 1L;
    short l_259 = 0xC056L;
    step_hash(76);
    (*l_170) = l_168;
    step_hash(77);
    (*l_170) = (((*l_170) || ((int)((*l_170) != ((short)(*l_170) << (short)p_20)) - (int)(*l_170))) <= p_21);
    step_hash(132);
    for (g_51 = 9; (g_51 >= 19); g_51++)
    {
        unsigned short l_181 = 0xED61L;
        int *l_182 = &g_183;
        unsigned char l_218 = 0UL;
        step_hash(81);
        (*l_182) ^= (+((*l_170) && (((unsigned char)p_21 * (unsigned char)(0xA1BBDA26L >= ((signed char)(l_181 < p_20) >> (signed char)7))) || g_4)));
        step_hash(82);
        (*g_66) = (*g_66);
        step_hash(131);
        if ((*l_182))
        {
            signed char l_186 = (-3L);
            step_hash(96);
            if ((l_186 >= (((unsigned)(!g_98) + (unsigned)((((*l_182) <= ((*l_170) || (p_21 >= (7UL < p_21)))) ^ (l_170 == p_19)) | g_98)) > g_51)))
            {
                int l_189 = 1L;
                step_hash(85);
                if (l_189)
                    break;
                step_hash(86);
                (*l_182) = ((&p_19 != &p_19) > (g_4 | (g_51 > ((int)l_189 / (int)l_189))));
                step_hash(87);
                if (p_21)
                    break;
                step_hash(88);
                g_194 = p_19;
            }
            else
            {
                step_hash(94);
                for (l_168 = (-26); (l_168 > 25); l_168++)
                {
                    step_hash(93);
                    (*l_182) &= (&p_19 != (void*)0);
                }
                step_hash(95);
                (*l_170) |= ((unsigned short)p_20 >> (unsigned short)3);
            }
            step_hash(97);
            (*l_182) ^= (g_4 <= p_20);
            step_hash(104);
            for (p_20 = 2; (p_20 == 9); ++p_20)
            {
                int l_203 = 1L;
                step_hash(101);
                if (l_186)
                    break;
                step_hash(102);
                l_203 = ((unsigned short)0x51ECL * (unsigned short)(-6L));
                step_hash(103);
                (*l_182) ^= (p_21 < 1UL);
            }
            step_hash(105);
            (*l_182) = l_186;
        }
        else
        {
            signed char l_223 = 0L;
            int *l_224 = &g_225;
            step_hash(107);
            (*l_224) ^= (p_21 < ((signed char)l_206 * (signed char)((unsigned char)((p_20 && (*l_182)) && p_21) * (unsigned char)((signed char)((unsigned char)(-(signed char)(*l_182)) * (unsigned char)(((int)((unsigned)l_218 - (unsigned)((unsigned char)p_21 * (unsigned char)((unsigned char)(!(*l_170)) * (unsigned char)l_223))) % (int)(*l_170)) <= p_21)) / (signed char)(*l_182)))));
            step_hash(129);
            if ((0x776ED3A1L == ((unsigned)(((short)((*l_182) | ((short)(1UL && (*l_224)) << (short)9)) >> (short)1) <= ((signed char)((p_21 != (p_21 | 0x8512A6EBL)) == g_183) + (signed char)1UL)) / (unsigned)g_96)))
            {
                int **l_240 = &l_169;
                step_hash(109);
                (*l_170) = (-1L);
                step_hash(118);
                for (p_20 = 0; (p_20 > 24); p_20 += 4)
                {
                    unsigned l_241 = 0xACA667C5L;
                    step_hash(117);
                    if ((((unsigned short)(0x4616L || p_20) << (unsigned short)8) < (l_240 != &g_194)))
                    {
                        step_hash(114);
                        (*l_170) = (-1L);
                    }
                    else
                    {
                        step_hash(116);
                        return l_241;
                    }
                }
                step_hash(119);
                (*l_170) |= p_20;
                step_hash(120);
                (*l_182) &= ((unsigned)g_98 - (unsigned)g_51);
            }
            else
            {
                int ***l_247 = &g_66;
                step_hash(126);
                for (g_183 = (-20); (g_183 == (-5)); g_183 += 6)
                {
                    int l_246 = (-5L);
                    step_hash(125);
                    if (l_246)
                        break;
                }
                step_hash(127);
                (*g_66) = (*g_66);
                step_hash(128);
                (*l_247) = &l_169;
            }
            step_hash(130);
            (*g_66) = p_19;
        }
    }
    step_hash(133);
    l_258 ^= ((unsigned char)((unsigned char)((signed char)((unsigned)(&g_194 == &g_194) / (unsigned)(func_40(p_20, (*l_170), p_20, (*g_66)) ^ ((*l_170) < (*l_170)))) / (signed char)g_225) * (unsigned char)p_21) + (unsigned char)g_96);
    step_hash(134);
    return l_259;
}
static int * func_22(unsigned p_23)
{
    int *l_34 = (void*)0;
    step_hash(67);
    for (p_23 = 0; (p_23 < 23); p_23++)
    {
        int *l_33 = &g_4;
        int **l_158 = &l_33;
    }
    step_hash(68);
    (*g_66) = l_34;
    step_hash(73);
    for (g_98 = (-19); (g_98 == (-20)); --g_98)
    {
        unsigned l_163 = 4294967287UL;
        step_hash(72);
        l_163 = (g_4 < func_35(l_34));
    }
    step_hash(74);
    return l_34;
}
static int * func_27(int * p_28, int * p_29, short p_30, int * p_31, signed char p_32)
{
    unsigned char l_69 = 0x72L;
    int *l_79 = &g_51;
    int *l_145 = &g_98;
    step_hash(58);
    if (((l_69 <= (-(unsigned short)(((short)l_69 >> (short)((unsigned short)p_32 * (unsigned short)0L)) == (0x727AL == (func_40((g_51 != ((unsigned short)g_51 * (unsigned short)((short)l_69 * (short)g_4))), p_32, g_51, l_79) & p_30))))) | 65530UL))
    {
        int *l_84 = &g_4;
        int ***l_95 = (void*)0;
        signed char l_101 = (-2L);
        int *l_129 = &g_98;
        step_hash(52);
        if ((7L || func_40(g_51, (g_51 && (p_31 != l_79)), (p_32 & ((0x41L & 0L) || ((unsigned short)((int)((void*)0 == &l_79) + (int)1L) >> (unsigned short)11))), l_84)))
        {
            step_hash(31);
            (*g_66) = p_29;
        }
        else
        {
            int ***l_94 = &g_66;
            step_hash(40);
            for (p_32 = 0; (p_32 == (-14)); p_32 -= 1)
            {
                int ***l_87 = &g_66;
                int *l_97 = &g_98;
                step_hash(36);
                (*l_87) = &p_29;
                step_hash(37);
                (*l_97) |= ((short)((signed char)(p_30 > (((&p_28 != (void*)0) || ((int)2L - (int)((func_40((l_94 != l_95), g_51, (&g_66 != &g_66), (*g_66)) & l_69) <= g_4))) >= (*g_67))) * (signed char)0xDCL) * (short)g_96);
                step_hash(38);
                (*l_97) = ((l_84 == (*g_66)) != (g_4 <= (((l_101 | ((signed char)(*l_84) + (signed char)(((short)(((unsigned char)(g_98 | ((short)(((signed char)func_35(p_31) * (signed char)((g_96 != p_30) <= 4294967287UL)) != (*l_97)) / (short)g_4)) >> (unsigned char)5) != (*g_67)) >> (short)p_30) & g_98))) | g_98) > p_30)));
                step_hash(39);
                return p_31;
            }
            step_hash(51);
            if ((*l_84))
            {
                step_hash(46);
                for (l_101 = 29; (l_101 != (-27)); --l_101)
                {
                    step_hash(45);
                    (**l_94) = p_29;
                }
            }
            else
            {
                unsigned short l_126 = 65535UL;
                int *l_127 = (void*)0;
                int *l_128 = &g_98;
                step_hash(48);
                (*l_79) = (**g_66);
                step_hash(49);
                (*l_128) |= ((signed char)(*l_79) * (signed char)((&p_28 != (*l_94)) >= ((int)((unsigned short)(((int)((unsigned short)(((int)(g_96 != p_32) + (int)0UL) <= g_51) - (unsigned short)p_32) / (int)(***l_94)) | (*l_79)) << (unsigned short)l_126) + (int)(*l_79))));
                step_hash(50);
                return (*g_66);
            }
        }
        step_hash(53);
        (*g_66) = p_29;
        step_hash(54);
        (*g_66) = l_79;
        step_hash(55);
        (*l_129) ^= (**g_66);
    }
    else
    {
        unsigned short l_136 = 0xE8F1L;
        unsigned l_137 = 4294967293UL;
        int *l_140 = &g_98;
        step_hash(57);
        (*l_140) &= (((unsigned short)((*l_79) >= p_30) >> (unsigned short)(((unsigned char)(*l_79) << (unsigned char)((int)l_136 - (int)g_51)) >= p_32)) | (l_137 == ((unsigned short)p_32 * (unsigned short)((l_136 && p_32) || (*g_67)))));
    }
    step_hash(59);
    (*l_145) ^= (((0x92664082L == (g_4 >= ((unsigned short)(func_40((0x56A42CAAL >= (((*l_79) | (*l_79)) != ((signed char)(&l_79 == &p_29) << (signed char)2))), g_96, g_51, (*g_66)) < 0xC3437DEDL) + (unsigned short)p_30))) <= (*p_28)) && p_30);
    step_hash(60);
    (*g_66) = p_31;
    step_hash(61);
    (*l_145) = (((g_96 && ((int)(((unsigned)((((unsigned)0xFA727D4FL - (unsigned)func_35(p_29)) <= g_96) > (((short)g_98 + (short)((short)p_32 >> (short)4)) != ((unsigned short)g_4 * (unsigned short)p_30))) / (unsigned)(*l_145)) && 0L) + (int)(*l_145))) <= 1L) < (*l_145));
    step_hash(62);
    return p_29;
}
static short func_35(int * p_36)
{
    unsigned l_45 = 0x0CBBBC25L;
    unsigned short l_46 = 0x305AL;
    int l_58 = 0x280DDA25L;
    int *l_59 = &g_51;
    int *l_68 = &l_58;
    step_hash(23);
    l_58 = ((unsigned)(-(signed char)func_40((l_45 > (l_45 | l_46)), g_4, g_4, p_36)) + (unsigned)l_45);
    step_hash(24);
    (*l_59) = l_58;
    step_hash(25);
    (*l_68) ^= ((short)g_51 * (short)(((int)(0xCCL >= 0L) * (int)((void*)0 != g_66)) > (&g_67 == &g_67)));
    step_hash(26);
    (*l_59) = (&l_58 == p_36);
    step_hash(27);
    return (*l_59);
}
static signed char func_40(unsigned short p_41, short p_42, int p_43, int * p_44)
{
    short l_49 = 0xD860L;
    int **l_54 = (void*)0;
    int *l_56 = (void*)0;
    int **l_55 = &l_56;
    int *l_57 = &g_4;
    step_hash(19);
    for (p_41 = 6; (p_41 >= 55); p_41 += 7)
    {
        int *l_50 = &g_51;
        step_hash(12);
        if (l_49)
            break;
        step_hash(13);
        (*l_50) &= p_42;
        step_hash(18);
        for (p_43 = 0; (p_43 >= 27); p_43 += 2)
        {
            step_hash(17);
            return g_4;
        }
    }
    step_hash(20);
    (*l_55) = (void*)0;
    step_hash(21);
    (*l_55) = l_57;
    step_hash(22);
    return g_51;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_51, "g_51", print_hash_value);
    transparent_crc(g_96, "g_96", print_hash_value);
    transparent_crc(g_98, "g_98", print_hash_value);
    transparent_crc(g_183, "g_183", print_hash_value);
    transparent_crc(g_225, "g_225", print_hash_value);
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
