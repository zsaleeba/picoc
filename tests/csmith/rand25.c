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
static unsigned g_4 = 1UL;
static int g_87 = 0x236C2177L;
static unsigned char g_101 = 252UL;
static int **g_133 = (void*)0;
static int g_186 = 1L;
static int *g_242 = (void*)0;
static int **g_241 = &g_242;
static int g_247 = (-9L);
static int *g_311 = &g_87;
static int g_322 = 0x6B9971ADL;
static short func_1(void);
static unsigned short func_13(int p_14);
static short func_22(unsigned char p_23, signed char p_24, unsigned p_25);
static unsigned short func_30(signed char p_31, unsigned char p_32, unsigned char p_33, short p_34);
static unsigned func_44(short p_45, unsigned p_46);
static short func_47(unsigned char p_48, unsigned p_49, short p_50, unsigned char p_51, short p_52);
static unsigned func_57(unsigned char p_58, unsigned p_59);
static int func_73(unsigned short p_74, unsigned p_75, int p_76, signed char p_77, unsigned char p_78);
static int * func_81(int * p_82);
static int * func_83(int * p_84, int * p_85);
static short func_1(void)
{
    unsigned short l_26 = 0xF839L;
    step_hash(184);
    (*g_311) = ((short)((g_4 >= (((unsigned char)g_4 >> (unsigned char)2) == ((0x0444L && ((signed char)0xFEL / (signed char)((int)((unsigned short)func_13(g_4) * (unsigned short)((short)((unsigned char)(~((0x90611BC3L != g_4) & ((((short)func_22(l_26, g_4, g_4) - (short)l_26) | g_4) <= l_26))) >> (unsigned char)6) * (short)0x1FA6L)) - (int)l_26))) != l_26))) ^ g_247) * (short)g_247);
    step_hash(185);
    return g_101;
}
static unsigned short func_13(int p_14)
{
    unsigned char l_15 = 0x58L;
    step_hash(2);
    return l_15;
}
static short func_22(unsigned char p_23, signed char p_24, unsigned p_25)
{
    short l_29 = 0x4CA7L;
    int *l_339 = &g_87;
    int ***l_342 = &g_133;
    int *l_345 = &g_322;
    signed char l_390 = 0xFBL;
    int *l_393 = (void*)0;
    int *l_394 = (void*)0;
    step_hash(145);
    (*g_311) = ((signed char)l_29 + (signed char)func_13((func_30(g_4, l_29, (((unsigned char)g_4 % (unsigned char)((unsigned short)((short)((l_29 > 0xB8CFF26AL) ^ g_4) + (short)((func_13(g_4) & 0xC5AD058BL) || p_24)) * (unsigned short)0x2F23L)) & 1L), l_29) | g_247)));
    step_hash(177);
    for (p_25 = 3; (p_25 != 23); p_25 += 5)
    {
        signed char l_343 = (-7L);
        int *l_344 = &g_247;
        int *l_351 = &g_87;
        int l_378 = 0x9B3B63D6L;
        step_hash(149);
        (*g_311) = (((((unsigned short)(0UL >= ((int)((unsigned char)((unsigned)g_87 + (unsigned)func_13(((int)((unsigned)func_13(((l_339 != l_339) < ((unsigned)((*l_339) & ((void*)0 != l_342)) % (unsigned)l_343))) / (unsigned)p_25) - (int)0xEFD678DBL))) / (unsigned char)p_24) / (int)0x38A90558L)) - (unsigned short)l_343) <= 0L) <= p_24) > 0x492FC4D6L);
        step_hash(150);
        (*g_241) = l_345;
        step_hash(176);
        for (g_101 = (-1); (g_101 > 24); g_101 += 6)
        {
            int *l_348 = &g_186;
            unsigned char l_358 = 0xDFL;
            int ***l_359 = &g_241;
            int l_364 = 0xF82136C5L;
            unsigned char l_388 = 2UL;
            step_hash(154);
            (*l_339) = p_23;
            step_hash(155);
            l_348 = l_344;
            step_hash(156);
            (*l_345) = ((((unsigned)g_247 / (unsigned)0x0BBCD69BL) || 0xE1L) < 0xB6DCFAA1L);
        }
    }
    step_hash(182);
    for (g_186 = 0; (g_186 == (-28)); --g_186)
    {
        step_hash(181);
        (*l_339) = (l_393 == l_394);
    }
    step_hash(183);
    return g_322;
}
static unsigned short func_30(signed char p_31, unsigned char p_32, unsigned char p_33, short p_34)
{
    int l_43 = 0x633933B8L;
    int *l_321 = &g_322;
    step_hash(142);
    (*l_321) ^= ((unsigned char)(p_33 || (l_43 > func_44(func_47(p_34, l_43, g_4, l_43, p_34), g_247))) % (unsigned char)g_4);
    step_hash(143);
    (*g_241) = &l_43;
    step_hash(144);
    return g_4;
}
static unsigned func_44(short p_45, unsigned p_46)
{
    int *l_318 = &g_186;
    int l_319 = 0L;
    unsigned l_320 = 0x3B00657DL;
    step_hash(137);
    (*g_242) &= p_45;
    step_hash(138);
    l_318 = l_318;
    step_hash(139);
    (**g_241) = (0x00B7L < (0xDE41467EL >= (*l_318)));
    step_hash(140);
    (*g_311) = l_319;
    step_hash(141);
    return l_320;
}
static short func_47(unsigned char p_48, unsigned p_49, short p_50, unsigned char p_51, short p_52)
{
    signed char l_64 = 0x6BL;
    int l_315 = 0xE94F4A13L;
    step_hash(134);
    if ((((((short)((((signed char)(func_57(p_51, ((signed char)g_4 + (signed char)((short)l_64 * (short)((l_64 == (+((unsigned)((unsigned char)((short)((unsigned char)func_13(func_73(g_4, ((+(((unsigned short)65535UL * (unsigned short)func_13(l_64)) == p_51)) && l_64), g_4, g_4, l_64)) << (unsigned char)g_247) << (short)l_64) / (unsigned char)g_4) / (unsigned)l_64))) ^ g_247)))) <= 0x6A5DDA62L) * (signed char)1L) == g_247) | 0x567F5F9CL) * (short)0x01ADL) != g_247) & l_64) > p_52))
    {
        step_hash(130);
        (*g_311) = ((4294967289UL == g_4) < func_57(g_247, p_49));
        step_hash(131);
        (*g_311) = func_57(p_48, l_315);
    }
    else
    {
        step_hash(133);
        (*g_242) ^= ((signed char)0xFDL - (signed char)l_315);
    }
    step_hash(135);
    return l_64;
}
static unsigned func_57(unsigned char p_58, unsigned p_59)
{
    unsigned short l_312 = 0x013EL;
    step_hash(128);
    return l_312;
}
static int func_73(unsigned short p_74, unsigned p_75, int p_76, signed char p_77, unsigned char p_78)
{
    int *l_86 = &g_87;
    step_hash(125);
    (*g_241) = func_81(func_83(l_86, l_86));
    step_hash(126);
    return (*g_311);
}
static int * func_81(int * p_82)
{
    int l_176 = 6L;
    int *l_181 = &g_87;
    int *l_310 = &l_176;
    step_hash(81);
    for (g_87 = 0; (g_87 == (-14)); g_87 -= 4)
    {
        signed char l_188 = 0x9DL;
        int *l_190 = &l_176;
        unsigned l_191 = 0x60A43F84L;
        step_hash(70);
        for (g_101 = 19; (g_101 < 30); ++g_101)
        {
            signed char l_184 = 0x11L;
            int l_189 = 0x99DD4A88L;
            step_hash(62);
            if (l_176)
                break;
            step_hash(68);
            for (l_176 = (-23); (l_176 >= 5); l_176++)
            {
                int *l_185 = &g_186;
                int **l_187 = &l_181;
                step_hash(66);
                (*l_185) = ((int)((0xFBL && g_87) && func_13(((void*)0 != l_181))) - (int)((unsigned short)l_184 << (unsigned short)7));
                step_hash(67);
                (*l_187) = (void*)0;
            }
            step_hash(69);
            l_189 = l_188;
        }
        step_hash(71);
        (*l_190) = 8L;
        step_hash(79);
        if ((*p_82))
        {
            step_hash(73);
            if (g_87)
                break;
        }
        else
        {
            int **l_192 = &l_181;
            step_hash(75);
            (*l_190) = (*p_82);
            step_hash(76);
            (*l_190) |= l_191;
            step_hash(77);
            (*l_192) = p_82;
            step_hash(78);
            return &g_186;
        }
        step_hash(80);
        (*l_190) = 9L;
    }
    step_hash(82);
    (*p_82) &= l_176;
    step_hash(90);
    for (g_186 = 0; (g_186 != (-4)); --g_186)
    {
        int l_199 = 0xB6223421L;
        step_hash(86);
        if (g_4)
            break;
        step_hash(87);
        (*p_82) = (((short)(func_13((g_101 >= ((unsigned short)(l_199 < ((g_4 && ((short)(((short)l_199 >> (short)14) == ((signed char)l_199 * (signed char)g_87)) / (short)((((short)(func_13(l_199) <= (((unsigned char)(+((((signed char)(l_199 != l_199) / (signed char)g_186) && g_101) > l_199)) * (unsigned char)l_199) & (*p_82))) % (short)8UL) & g_101) | l_199))) < g_186)) / (unsigned short)0x001AL))) == 4294967295UL) << (short)2) < 1UL);
        step_hash(88);
        (*p_82) = ((signed char)0x93L - (signed char)l_176);
        step_hash(89);
        if ((*p_82))
            break;
    }
    step_hash(123);
    for (g_101 = 0; (g_101 >= 20); g_101 += 1)
    {
        unsigned char l_248 = 0xAEL;
        int l_259 = 0xE881EA7AL;
        unsigned l_260 = 1UL;
        step_hash(121);
        for (g_87 = (-7); (g_87 != (-7)); g_87 += 7)
        {
            unsigned l_232 = 1UL;
            int *l_249 = &g_186;
        }
        step_hash(122);
        (*g_241) = (void*)0;
    }
    step_hash(124);
    return g_311;
}
static int * func_83(int * p_84, int * p_85)
{
    int l_90 = 0xEC7E1EFCL;
    short l_99 = 1L;
    unsigned char l_112 = 249UL;
    unsigned l_113 = 0x16C3B14AL;
    int *l_135 = &l_90;
    int **l_134 = &l_135;
    step_hash(52);
    if (((unsigned char)(&g_87 == (void*)0) % (unsigned char)l_90))
    {
        int *l_92 = &l_90;
        int **l_91 = &l_92;
        int l_100 = 0L;
        step_hash(9);
        (*l_91) = (void*)0;
        step_hash(10);
        (*p_85) = (func_13(((((short)((unsigned short)g_4 % (unsigned short)((unsigned short)g_4 - (unsigned short)l_99)) - (short)l_100) || g_87) <= g_101)) > (func_13(((((short)(((signed char)(+(((unsigned char)(((unsigned char)(l_99 ^ ((signed char)0x89L + (signed char)g_101)) - (unsigned char)l_99) < g_4) * (unsigned char)l_99) <= l_112)) - (signed char)g_4) > (*p_84)) << (short)5) > g_101) <= l_112)) < 0x8E5B495AL));
        step_hash(11);
        (*l_91) = &l_90;
        step_hash(12);
        return p_85;
    }
    else
    {
        unsigned short l_117 = 1UL;
        int *l_130 = &g_87;
        step_hash(18);
        if ((*p_85))
        {
            int l_114 = (-4L);
            step_hash(15);
            (*p_85) = (func_13((g_87 && l_113)) <= l_114);
        }
        else
        {
            signed char l_124 = (-10L);
            int *l_125 = &g_87;
            step_hash(17);
            l_90 = ((int)(l_117 ^ ((*p_85) || ((signed char)l_112 % (signed char)(((l_117 && ((((((unsigned)l_124 - (unsigned)(((((l_125 == (void*)0) || ((unsigned short)l_113 >> (unsigned short)7)) == func_13((l_112 && g_4))) >= g_87) == 1L)) > 0L) < (*l_125)) <= l_117) >= g_4)) & 0x1DFF66F6L) & 2L)))) + (int)g_87);
        }
        step_hash(49);
        if (l_117)
        {
            int *l_128 = &g_87;
            int **l_129 = &l_128;
            step_hash(20);
            (*l_129) = l_128;
            step_hash(21);
            return l_130;
        }
        else
        {
            unsigned short l_136 = 0x2D78L;
            int **l_158 = &l_130;
            int ***l_159 = &g_133;
            step_hash(35);
            if ((*p_84))
            {
                unsigned short l_139 = 0x40FDL;
                step_hash(24);
                (*l_130) = ((g_133 == l_134) == (((~func_13((*p_84))) ^ (-2L)) < 2L));
                step_hash(25);
                (*l_130) = (*p_84);
                step_hash(26);
                (*p_84) = (l_136 && ((unsigned char)((*l_130) | l_136) + (unsigned char)(l_139 || ((unsigned short)0x8C87L * (unsigned short)((((short)(**l_134) >> (short)((l_136 ^ (((0xDE5CCA7CL >= (*p_85)) <= (*l_130)) ^ 0L)) != l_136)) && l_136) > l_139)))));
                step_hash(32);
                if ((+g_4))
                {
                    int l_154 = 0x43366FBBL;
                    step_hash(28);
                    (*l_134) = (*l_134);
                    step_hash(29);
                    (*l_135) = (((unsigned short)(((((((void*)0 != g_133) >= ((short)((short)1L / (short)(*l_130)) >> (short)6)) | (((unsigned)(((unsigned short)(*l_130) + (unsigned short)(g_101 | (*l_135))) >= ((*l_130) | 4UL)) % (unsigned)g_87) | 65535UL)) || g_101) >= (*l_130)) < l_154) + (unsigned short)0x13BBL) < 0x31L);
                }
                else
                {
                    step_hash(31);
                    (**l_134) |= g_87;
                }
            }
            else
            {
                step_hash(34);
                return p_84;
            }
            step_hash(42);
            for (g_101 = 0; (g_101 != 32); ++g_101)
            {
                signed char l_157 = 0x86L;
                step_hash(39);
                (*l_130) |= l_136;
                step_hash(40);
                (*l_134) = p_85;
                step_hash(41);
                (**l_134) &= (l_157 == func_13(func_13(((void*)0 == &p_84))));
            }
            step_hash(43);
            (*l_159) = l_158;
            step_hash(48);
            if (((**g_133) & (((unsigned short)(**l_158) >> (unsigned short)(*l_130)) > (((signed char)((unsigned char)((((unsigned short)((signed char)g_87 >> (signed char)(*l_130)) >> (unsigned short)g_101) ^ g_101) <= 0xCE8EB294L) / (unsigned char)1L) + (signed char)(*l_130)) >= (**l_134)))))
            {
                unsigned char l_170 = 251UL;
                step_hash(45);
                (**l_134) = l_170;
            }
            else
            {
                int *l_171 = &g_87;
                step_hash(47);
                return l_171;
            }
        }
        step_hash(50);
        (*g_133) = (void*)0;
        step_hash(51);
        (*p_85) = (*p_85);
    }
    step_hash(53);
    (*l_134) = (*l_134);
    step_hash(54);
    return p_85;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_87, "g_87", print_hash_value);
    transparent_crc(g_101, "g_101", print_hash_value);
    transparent_crc(g_186, "g_186", print_hash_value);
    transparent_crc(g_247, "g_247", print_hash_value);
    transparent_crc(g_322, "g_322", print_hash_value);
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
