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
static int g_2 = 0x02E91A04L;
static int g_39 = 0x11D7FEAEL;
static int g_101 = 0x93E9FC65L;
static int g_103 = 2L;
static int *g_111 = &g_103;
static unsigned g_123 = 1UL;
static unsigned short g_124 = 1UL;
static int g_147 = 0xD83CB06CL;
static int **g_225 = &g_111;
static int ***g_224 = &g_225;
static short g_346 = 0x9234L;
static signed char g_408 = (-3L);
static signed char func_1(void);
static int func_5(signed char p_6);
static signed char func_7(short p_8, unsigned p_9, short p_10, short p_11, unsigned p_12);
static unsigned short func_18(int p_19, unsigned p_20, short p_21);
static unsigned short func_22(unsigned char p_23, unsigned p_24, signed char p_25, unsigned short p_26, int p_27);
static unsigned func_28(unsigned char p_29, int p_30, unsigned char p_31, int p_32, int p_33);
static signed char func_50(int * p_51, unsigned p_52, int * p_53);
static int * func_54(short p_55, int p_56, signed char p_57);
static short func_58(unsigned p_59, int * p_60, int * p_61, signed char p_62, signed char p_63);
static int * func_64(int * p_65, int * p_66);
static signed char func_1(void)
{
    int l_13 = 1L;
    unsigned l_15 = 0x1B68DEE2L;
    short l_495 = 0x97BDL;
    step_hash(339);
    for (g_2 = 0; (g_2 > 17); g_2 += 8)
    {
        signed char l_14 = 0x5BL;
        int *l_494 = &g_101;
    }
    step_hash(340);
    (**g_224) = (**g_224);
    step_hash(341);
    (***g_224) = l_495;
    step_hash(342);
    (**g_224) = (void*)0;
    step_hash(343);
    return g_103;
}
static int func_5(signed char p_6)
{
    unsigned short l_189 = 0x205CL;
    int *l_194 = &g_147;
    unsigned char l_235 = 2UL;
    int l_313 = 0L;
    int l_337 = (-5L);
    unsigned char l_347 = 251UL;
    signed char l_365 = 0L;
    unsigned short l_426 = 0x50D2L;
    step_hash(160);
    if (((l_189 | ((unsigned short)g_39 - (unsigned short)(((short)p_6 * (short)p_6) >= l_189))) == (l_189 <= ((l_189 >= 0xDEL) < ((l_194 == (void*)0) < p_6)))))
    {
        int *l_201 = &g_101;
        int ***l_202 = (void*)0;
        step_hash(131);
        for (l_189 = 5; (l_189 != 37); l_189++)
        {
            int **l_204 = &l_194;
            int ***l_203 = &l_204;
        }
        step_hash(132);
        (*l_201) &= (l_201 == (void*)0);
        step_hash(133);
        (*l_194) |= (g_39 || (p_6 != (*l_201)));
        step_hash(139);
        for (g_101 = 0; (g_101 != 11); ++g_101)
        {
            unsigned l_207 = 0xD011C8EEL;
            step_hash(137);
            if (p_6)
                break;
            step_hash(138);
            return l_207;
        }
    }
    else
    {
        unsigned char l_219 = 3UL;
        short l_230 = 0x0EF9L;
        step_hash(141);
        (*g_111) = 0xBCE4B171L;
        step_hash(158);
        for (g_123 = 0; (g_123 == 37); g_123++)
        {
            short l_210 = 0x1FFEL;
            int **l_223 = &l_194;
            int ***l_222 = &l_223;
            step_hash(145);
            (*g_111) &= l_210;
            step_hash(146);
            (*g_111) = (*g_111);
        }
        step_hash(159);
        return l_219;
    }
    step_hash(161);
    (*l_194) = (0xDD79L != l_235);
    step_hash(220);
    if (func_28(((short)((short)((*g_111) & (((((short)(*l_194) * (short)p_6) || ((p_6 ^ ((signed char)(((short)(&l_194 == (void*)0) + (short)(0xC7DE1C95L ^ (p_6 < (0x37L & p_6)))) & p_6) << (signed char)4)) | p_6)) < 0xAA28L) == g_2)) << (short)7) + (short)p_6), g_123, (*l_194), (***g_224), (*l_194)))
    {
        signed char l_256 = 0x00L;
        unsigned l_274 = 0xEE7E9482L;
        int *l_278 = &g_2;
        step_hash(163);
        (*g_225) = (*g_225);
        step_hash(170);
        for (g_124 = (-2); (g_124 == 43); ++g_124)
        {
            unsigned short l_261 = 0x6382L;
            int *l_262 = &g_101;
            int ***l_263 = &g_225;
            step_hash(167);
            l_262 = func_54(((int)(func_18((**g_225), ((unsigned short)0UL >> (unsigned short)4), ((signed char)(l_256 && ((signed char)(*l_194) >> (signed char)0)) + (signed char)g_2)) >= p_6) + (int)p_6), ((signed char)p_6 / (signed char)l_261), p_6);
            step_hash(168);
            (*l_262) |= 0xEE1ACB92L;
            step_hash(169);
            (*l_262) ^= ((void*)0 != l_263);
        }
        step_hash(212);
        for (l_189 = 11; (l_189 != 2); l_189 -= 5)
        {
            int l_270 = 0L;
            int *l_271 = (void*)0;
        }
        step_hash(217);
        for (l_337 = 9; (l_337 != 25); l_337++)
        {
            step_hash(216);
            (*g_225) = l_278;
        }
    }
    else
    {
        step_hash(219);
        return (***g_224);
    }
    step_hash(336);
    for (g_101 = 0; (g_101 == (-26)); g_101--)
    {
        int *l_351 = &g_103;
        int ***l_382 = (void*)0;
        int l_399 = 0x55EF8A00L;
        int **l_428 = &l_194;
        unsigned l_453 = 0x6CB1C423L;
        unsigned char l_465 = 255UL;
        int l_486 = 0x4206CAF5L;
    }
    step_hash(337);
    return (*l_194);
}
static signed char func_7(short p_8, unsigned p_9, short p_10, short p_11, unsigned p_12)
{
    step_hash(122);
    for (p_8 = 7; (p_8 == (-25)); p_8 -= 9)
    {
        int **l_186 = &g_111;
        step_hash(115);
        (*l_186) = func_54(g_103, p_12, g_2);
        step_hash(121);
        for (p_9 = 0; (p_9 < 22); p_9++)
        {
            step_hash(119);
            (**l_186) &= ((-2L) | 0x4936DCCDL);
            step_hash(120);
            (*l_186) = (*l_186);
        }
    }
    step_hash(123);
    return p_12;
}
static unsigned short func_18(int p_19, unsigned p_20, short p_21)
{
    unsigned l_171 = 4294967295UL;
    int *l_176 = &g_39;
    step_hash(64);
    (*g_111) = p_20;
    step_hash(109);
    for (g_147 = 0; (g_147 < 18); g_147 += 2)
    {
        int **l_151 = &g_111;
        int ***l_152 = &l_151;
        step_hash(68);
        (*l_152) = l_151;
        step_hash(69);
        (**l_151) = ((unsigned short)0x4B0DL << (unsigned short)10);
        step_hash(108);
        for (g_103 = 16; (g_103 == (-16)); g_103 -= 3)
        {
            int ***l_166 = &l_151;
            step_hash(77);
            for (p_19 = 0; (p_19 > 27); p_19 += 1)
            {
                step_hash(76);
                return g_39;
            }
            step_hash(82);
            for (p_20 = 0; (p_20 >= 42); p_20 += 7)
            {
                step_hash(81);
                return (***l_152);
            }
            step_hash(107);
            for (p_21 = 0; (p_21 < 2); p_21 += 5)
            {
                int *l_175 = &g_103;
                int *l_183 = &g_101;
                step_hash(96);
                if ((*g_111))
                {
                    int *l_168 = (void*)0;
                    step_hash(92);
                    for (p_19 = 0; (p_19 != 8); ++p_19)
                    {
                        int *l_165 = &g_101;
                        int ***l_167 = &l_151;
                        step_hash(90);
                        (*l_165) = 0x18C20207L;
                        step_hash(91);
                        (*l_165) = (l_166 == l_167);
                    }
                    step_hash(93);
                    p_19 = p_21;
                }
                else
                {
                    step_hash(95);
                    (*l_151) = (**l_152);
                }
                step_hash(104);
                if (((g_103 >= ((((unsigned)((void*)0 == &g_111) + (unsigned)0xBE10E358L) != (((***l_166) >= g_101) | g_147)) > (l_171 != ((signed char)g_103 - (signed char)0x6CL)))) != l_171))
                {
                    int *l_174 = (void*)0;
                    step_hash(98);
                    (**l_152) = &p_19;
                    step_hash(99);
                    (**l_166) = (**l_152);
                    step_hash(100);
                    (**l_152) = l_174;
                    step_hash(101);
                    (*l_151) = l_175;
                }
                else
                {
                    step_hash(103);
                    if ((*g_111))
                        break;
                }
                step_hash(105);
                l_176 = func_54(p_21, ((((0x6493B66AL && p_19) > (*l_175)) && ((l_171 | p_20) >= (((void*)0 == l_166) && g_39))) >= l_171), p_19);
                step_hash(106);
                (*l_183) &= (255UL || (p_19 | ((int)((short)(g_2 >= ((signed char)(**l_151) - (signed char)0xC1L)) + (short)p_20) + (int)(1L < (***l_166)))));
            }
        }
    }
    step_hash(110);
    return p_21;
}
static unsigned short func_22(unsigned char p_23, unsigned p_24, signed char p_25, unsigned short p_26, int p_27)
{
    signed char l_143 = 0x1BL;
    int *l_146 = &g_147;
    int **l_148 = &l_146;
    step_hash(60);
    (*l_146) &= ((unsigned char)func_28(p_24, l_143, l_143, l_143, (((((((unsigned short)g_39 / (unsigned short)p_24) == l_143) != (l_143 != p_27)) && p_23) || 4UL) || p_27)) + (unsigned char)g_2);
    step_hash(61);
    (*l_148) = l_146;
    step_hash(62);
    return (*l_146);
}
static unsigned func_28(unsigned char p_29, int p_30, unsigned char p_31, int p_32, int p_33)
{
    int *l_36 = (void*)0;
    int *l_37 = (void*)0;
    int *l_38 = &g_39;
    int l_130 = 0L;
    int l_135 = 0x0093E2C0L;
    int l_138 = (-4L);
    int *l_140 = &l_135;
    step_hash(5);
    (*l_38) &= ((unsigned short)p_31 << (unsigned short)9);
    step_hash(55);
    for (p_31 = (-1); (p_31 >= 19); p_31 += 9)
    {
        int *l_67 = (void*)0;
        int *l_139 = &g_101;
        step_hash(46);
        for (p_29 = 0; (p_29 != 59); p_29 += 1)
        {
            int *l_77 = &g_2;
            step_hash(45);
            (*l_38) = ((short)0x2D50L >> (short)((signed char)((unsigned char)(func_50(func_54(func_58(p_33, func_64(&g_2, l_67), l_77, g_2, (((unsigned)((unsigned short)(&g_2 != (void*)0) << (unsigned short)(*l_77)) % (unsigned)p_30) && p_31)), p_29, (*l_77)), g_2, &g_2) ^ g_2) + (unsigned char)0UL) << (signed char)g_2));
        }
        step_hash(53);
        for (g_124 = 0; (g_124 > 30); g_124++)
        {
            unsigned l_127 = 0x45EF5D7AL;
            step_hash(50);
            g_101 &= (*g_111);
            step_hash(51);
            p_32 ^= (l_127 && (l_127 ^ ((int)l_130 % (int)3L)));
            step_hash(52);
            (*l_38) = 1L;
        }
        step_hash(54);
        (*l_139) ^= (((((int)((short)(*l_38) >> (short)15) - (int)((g_39 | l_135) > ((unsigned)l_138 + (unsigned)(l_67 == &g_39)))) > ((*g_111) | p_33)) | p_31) < p_32);
    }
    step_hash(56);
    (*g_111) = (*g_111);
    step_hash(57);
    (*l_140) ^= (*g_111);
    step_hash(58);
    return p_32;
}
static signed char func_50(int * p_51, unsigned p_52, int * p_53)
{
    int *l_110 = &g_39;
    unsigned l_122 = 5UL;
    step_hash(40);
    g_111 = func_54((l_110 == &g_39), g_39, (*l_110));
    step_hash(41);
    g_123 |= ((int)(&g_111 == (void*)0) + (int)((unsigned short)(((*l_110) ^ (0x7FL || ((((g_101 >= ((unsigned short)(((*p_51) > g_39) < ((((unsigned short)((signed char)0x4EL + (signed char)(&l_110 == (void*)0)) + (unsigned short)(*l_110)) >= (*l_110)) ^ (*l_110))) >> (unsigned short)9)) <= g_103) ^ 0L) != g_101))) ^ (*l_110)) + (unsigned short)l_122));
    step_hash(42);
    (*g_111) &= 0xE1F03B47L;
    step_hash(43);
    g_124 = (-9L);
    step_hash(44);
    return g_39;
}
static int * func_54(short p_55, int p_56, signed char p_57)
{
    short l_108 = (-8L);
    int *l_109 = &g_39;
    step_hash(37);
    (*l_109) &= (l_108 ^ l_108);
    step_hash(38);
    return l_109;
}
static short func_58(unsigned p_59, int * p_60, int * p_61, signed char p_62, signed char p_63)
{
    signed char l_82 = 0x17L;
    int *l_87 = &g_39;
    int *l_92 = &g_39;
    step_hash(21);
    if (((l_82 && 0x5C02AC6AL) | (((signed char)0xA3L * (signed char)((*p_60) ^ (((unsigned char)(65535UL || (l_87 == (void*)0)) >> (unsigned char)((((unsigned short)p_62 >> (unsigned short)((unsigned short)(0xFD00L < 0xDF93L) >> (unsigned short)5)) != g_39) <= p_62)) ^ g_2))) | (*l_87))))
    {
        int **l_93 = &l_87;
        step_hash(18);
        (*l_93) = l_92;
    }
    else
    {
        int *l_94 = &g_2;
        int **l_95 = &l_94;
        step_hash(20);
        (*l_95) = func_64(func_64(&g_39, l_92), l_94);
    }
    step_hash(34);
    if (((*p_61) && ((short)g_39 / (short)p_63)))
    {
        int *l_104 = &g_103;
        step_hash(28);
        for (g_39 = 0; (g_39 != (-14)); g_39--)
        {
            int *l_100 = &g_101;
            int *l_102 = &g_103;
            step_hash(26);
            (*l_100) = (*p_61);
            step_hash(27);
            (*l_102) &= ((*l_100) < (*p_61));
        }
        step_hash(29);
        (*l_104) &= g_39;
        step_hash(30);
        (*l_104) &= ((signed char)g_101 + (signed char)(*l_92));
    }
    else
    {
        int **l_107 = &l_92;
        step_hash(32);
        (*l_107) = func_64(&g_101, &g_39);
        step_hash(33);
        return g_39;
    }
    step_hash(35);
    return (*l_87);
}
static int * func_64(int * p_65, int * p_66)
{
    int *l_70 = &g_39;
    step_hash(13);
    g_39 = ((short)((void*)0 == l_70) + (short)((unsigned short)g_2 + (unsigned short)((short)(((short)(*l_70) % (short)0x4AEDL) > ((*l_70) != 1UL)) * (short)(*l_70))));
    step_hash(14);
    (*l_70) = 0x8DB06862L;
    step_hash(15);
    return l_70;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_39, "g_39", print_hash_value);
    transparent_crc(g_101, "g_101", print_hash_value);
    transparent_crc(g_103, "g_103", print_hash_value);
    transparent_crc(g_123, "g_123", print_hash_value);
    transparent_crc(g_124, "g_124", print_hash_value);
    transparent_crc(g_147, "g_147", print_hash_value);
    transparent_crc(g_346, "g_346", print_hash_value);
    transparent_crc(g_408, "g_408", print_hash_value);
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
