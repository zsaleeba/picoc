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
static int g_83 = (-4L);
static unsigned char g_84 = 0x1BL;
static int *g_109 = &g_83;
static int **g_108 = &g_109;
static int g_111 = 1L;
static int g_151 = 0x60E86605L;
static int func_1(void);
static signed char func_5(unsigned char p_6, unsigned p_7, unsigned short p_8, int p_9);
static unsigned func_11(unsigned char p_12, int p_13, unsigned char p_14, unsigned char p_15, unsigned p_16);
static unsigned func_17(short p_18, short p_19, signed char p_20, unsigned p_21, int p_22);
static unsigned short func_23(int p_24, short p_25, signed char p_26, int p_27);
static int * func_30(int * p_31, int * p_32, signed char p_33, int p_34, unsigned p_35);
static unsigned short func_45(int * p_46, unsigned p_47, short p_48);
static int * func_49(signed char p_50, unsigned short p_51, int p_52);
static unsigned func_59(unsigned p_60, unsigned short p_61);
static signed char func_99(unsigned p_100, unsigned char p_101, int ** p_102);
static int func_1(void)
{
    unsigned l_10 = 4294967295UL;
    int *l_263 = &g_4;
    unsigned l_264 = 0UL;
    unsigned short l_275 = 65535UL;
    int l_276 = (-1L);
    int l_277 = 0x19D2B6AFL;
    int l_278 = 0L;
    step_hash(141);
    (*l_263) = ((unsigned char)g_4 + (unsigned char)func_5(l_10, func_11((3UL != l_10), (l_10 < (0xADF1ADB2L == func_17(l_10, (func_23(g_4, l_10, l_10, l_10) | 1L), g_4, g_4, l_10))), g_4, l_10, l_10), g_4, l_10));
    step_hash(142);
    l_264 ^= (*l_263);
    step_hash(143);
    l_278 ^= ((short)((unsigned char)func_11(((&g_4 == &g_111) & ((*l_263) != (g_151 ^ (*l_263)))), (*l_263), (((short)((((signed char)(&g_109 != &g_109) - (signed char)0L) || l_275) & 0UL) / (short)l_276) & (*l_263)), g_151, l_277) * (unsigned char)0x2EL) * (short)0x87C8L);
    step_hash(144);
    return (*l_263);
}
static signed char func_5(unsigned char p_6, unsigned p_7, unsigned short p_8, int p_9)
{
    int l_251 = 8L;
    int l_262 = (-1L);
    step_hash(139);
    l_262 = (((unsigned short)((unsigned)0xFD0F9B15L + (unsigned)p_6) * (unsigned short)((unsigned)(l_251 && l_251) + (unsigned)((unsigned)((unsigned short)((signed char)0L * (signed char)p_8) / (unsigned short)func_11(p_6, ((int)(((short)l_251 + (short)(9UL | 7L)) | g_4) % (int)l_251), l_251, l_251, p_9)) - (unsigned)p_7))) >= 4L);
    step_hash(140);
    return p_8;
}
static unsigned func_11(unsigned char p_12, int p_13, unsigned char p_14, unsigned char p_15, unsigned p_16)
{
    int l_241 = 0xFC9FD4B6L;
    int *l_242 = (void*)0;
    step_hash(136);
    p_13 |= (p_14 < 1L);
    step_hash(137);
    return p_12;
}
static unsigned func_17(short p_18, short p_19, signed char p_20, unsigned p_21, int p_22)
{
    signed char l_230 = 0L;
    int *l_231 = (void*)0;
    int *l_232 = (void*)0;
    int *l_233 = &g_83;
    step_hash(132);
    (*l_233) ^= l_230;
    step_hash(133);
    (*l_233) = (g_84 || g_151);
    step_hash(134);
    return p_19;
}
static unsigned short func_23(int p_24, short p_25, signed char p_26, int p_27)
{
    int *l_36 = (void*)0;
    unsigned l_53 = 1UL;
    unsigned char l_54 = 254UL;
    int l_197 = 0x6B3F0A27L;
    int **l_224 = &l_36;
    unsigned l_227 = 0x1EA3EF8AL;
    unsigned l_228 = 1UL;
    int *l_229 = &g_111;
    step_hash(6);
    for (p_24 = (-29); (p_24 < 16); p_24++)
    {
        step_hash(5);
        return g_4;
    }
    step_hash(127);
    (*l_224) = func_30(l_36, &g_4, ((((unsigned char)p_24 / (unsigned char)((short)((short)((p_24 ^ (((unsigned short)(func_45(func_49((((void*)0 == &g_4) <= ((void*)0 == &g_4)), l_53, l_54), l_197, g_4) == 5L) % (unsigned short)p_24) | p_24)) && 254UL) * (short)65534UL) * (short)65535UL)) != l_197) < l_54), g_4, p_27);
    step_hash(128);
    (*l_224) = (*l_224);
    step_hash(129);
    (*l_229) = ((unsigned short)(l_227 < l_228) << (unsigned short)p_26);
    step_hash(130);
    return g_111;
}
static int * func_30(int * p_31, int * p_32, signed char p_33, int p_34, unsigned p_35)
{
    unsigned l_206 = 0x2EFCB156L;
    int *l_207 = (void*)0;
    int *l_208 = (void*)0;
    int l_209 = 0xCE538C8CL;
    unsigned l_210 = 4294967289UL;
    int **l_220 = &l_207;
    step_hash(114);
    l_209 &= l_206;
    step_hash(120);
    if (l_210)
    {
        int *l_211 = (void*)0;
        step_hash(116);
        return l_211;
    }
    else
    {
        int *l_221 = &g_83;
        step_hash(118);
        (*l_221) = ((*p_32) || (~((signed char)((unsigned short)p_34 * (unsigned short)(-3L)) << (signed char)(((unsigned short)(!((signed char)g_83 >> (signed char)g_111)) >> (unsigned short)10) != (*p_32)))));
        step_hash(119);
        (*l_221) &= (*p_32);
    }
    step_hash(125);
    for (g_83 = 0; (g_83 != (-21)); g_83 -= 1)
    {
        step_hash(124);
        (*l_220) = p_32;
    }
    step_hash(126);
    return p_31;
}
static unsigned short func_45(int * p_46, unsigned p_47, short p_48)
{
    unsigned short l_198 = 65532UL;
    int *l_201 = &g_4;
    short l_202 = 0x7024L;
    int **l_205 = &l_201;
    step_hash(108);
    (*p_46) ^= l_198;
    step_hash(109);
    (*p_46) = (p_47 == ((unsigned short)g_151 * (unsigned short)func_59((func_59(g_83, p_47) == (p_48 < p_48)), (((l_198 <= (l_201 == p_46)) < 0x43L) <= (*l_201)))));
    step_hash(110);
    (*l_205) = p_46;
    step_hash(111);
    (**l_205) = func_59((*l_201), (*l_201));
    step_hash(112);
    return p_47;
}
static int * func_49(signed char p_50, unsigned short p_51, int p_52)
{
    int *l_76 = &g_4;
    int *l_196 = &g_83;
    step_hash(104);
    if ((((unsigned short)((unsigned char)0x5CL * (unsigned char)((0x4F9AL && g_4) != func_59(((short)g_4 * (short)((unsigned)((unsigned char)(0xB6L & ((signed char)p_52 >> (signed char)4)) * (unsigned char)((&p_52 != &g_4) == (((signed char)((short)((short)((void*)0 != l_76) - (short)65531UL) / (short)g_4) * (signed char)p_50) < g_4))) / (unsigned)g_4)), p_52))) % (unsigned short)p_52) == 0L))
    {
        int l_85 = (-4L);
        int *l_195 = (void*)0;
        step_hash(100);
        if ((func_59((*l_76), ((*l_76) != (~func_59(p_52, g_4)))) == l_85))
        {
            int **l_86 = (void*)0;
            int **l_87 = (void*)0;
            int **l_88 = &l_76;
            step_hash(13);
            (*l_88) = (void*)0;
        }
        else
        {
            unsigned short l_107 = 0xABC0L;
            int *l_188 = &g_83;
            step_hash(96);
            (*l_188) = (((signed char)p_50 / (signed char)((signed char)(p_52 & (g_83 <= ((g_4 & ((signed char)((int)(+((((((((signed char)func_99((p_51 <= ((signed char)(0x221FL && (*l_76)) << (signed char)5)), ((unsigned short)g_83 << (unsigned short)((g_83 | l_107) & 1L)), g_108) * (signed char)g_83) && (-5L)) | g_83) ^ (-1L)) || p_52) != g_4) == g_4)) + (int)p_50) >> (signed char)7)) | g_83))) - (signed char)255UL)) | 5L);
            step_hash(97);
            g_108 = &l_188;
            step_hash(98);
            (**g_108) = (((unsigned char)p_52 >> (unsigned char)(*l_188)) <= 4294967294UL);
            step_hash(99);
            (*l_188) &= 0xC00CB0D7L;
        }
        step_hash(101);
        p_52 = (((unsigned short)((l_85 > ((func_59(g_4, ((void*)0 == &p_52)) | ((unsigned)1UL + (unsigned)p_52)) > p_51)) < ((((g_84 < g_4) == g_151) >= l_85) ^ 0x2628C699L)) >> (unsigned short)13) < 0xF3680C6DL);
    }
    else
    {
        step_hash(103);
        return (*g_108);
    }
    step_hash(105);
    (*l_196) = ((g_83 < p_52) || (-10L));
    step_hash(106);
    return l_196;
}
static unsigned func_59(unsigned p_60, unsigned short p_61)
{
    unsigned char l_77 = 0x93L;
    int *l_82 = &g_83;
    step_hash(9);
    (*l_82) ^= (l_77 == (0L == ((signed char)((unsigned)l_77 % (unsigned)p_60) << (signed char)(65535UL >= (g_4 | g_4)))));
    step_hash(10);
    return g_84;
}
static signed char func_99(unsigned p_100, unsigned char p_101, int ** p_102)
{
    int *l_110 = &g_111;
    unsigned l_160 = 4UL;
    step_hash(16);
    (*p_102) = (void*)0;
    step_hash(17);
    (*l_110) = ((void*)0 == p_102);
    step_hash(94);
    for (g_84 = 1; (g_84 <= 46); ++g_84)
    {
        unsigned l_118 = 0x1E24EB76L;
        unsigned l_145 = 4294967295UL;
        int **l_149 = &g_109;
        unsigned l_152 = 0x14404B11L;
        unsigned l_159 = 0xE352C4D3L;
        step_hash(21);
        (*g_108) = (void*)0;
        step_hash(22);
        (*g_108) = (void*)0;
        step_hash(93);
        if (((int)((unsigned short)g_83 << (unsigned short)0) - (int)p_101))
        {
            unsigned char l_123 = 0xF2L;
            int l_124 = 0x9E214278L;
            step_hash(24);
            (*p_102) = l_110;
            step_hash(25);
            l_124 ^= ((l_118 | ((signed char)(-9L) * (signed char)((int)((void*)0 != (*g_108)) / (int)((p_100 || ((l_123 || ((void*)0 == (*p_102))) || (*l_110))) & p_100)))) || p_100);
        }
        else
        {
            int *l_140 = &g_83;
            step_hash(91);
            if ((p_101 && g_4))
            {
                unsigned char l_127 = 251UL;
                int **l_168 = &g_109;
                int l_171 = 0x5E220DBAL;
                step_hash(32);
                if ((l_118 > ((((*p_102) == (*p_102)) == (!0xA7FA1A71L)) < ((int)0x0F0864F5L % (int)(*l_110)))))
                {
                    step_hash(29);
                    if (l_118)
                        break;
                }
                else
                {
                    step_hash(31);
                    (*l_110) = l_127;
                }
                step_hash(65);
                if ((((unsigned short)0UL >> (unsigned short)((signed char)(((int)l_127 % (int)((unsigned char)((p_100 < ((p_100 > ((unsigned char)((short)(((((*g_108) == l_140) > g_111) != (*l_140)) && (0x4AL <= g_4)) - (short)p_101) >> (unsigned char)1)) >= 0xCA91F7CAL)) || 0xC7L) % (unsigned char)5UL)) != l_118) + (signed char)g_4)) < l_118))
                {
                    step_hash(34);
                    (*l_110) = ((unsigned short)l_127 * (unsigned short)(*l_110));
                    step_hash(40);
                    if (p_100)
                    {
                        step_hash(36);
                        if (g_84)
                            break;
                    }
                    else
                    {
                        step_hash(38);
                        (*l_110) = (+((unsigned char)p_100 * (unsigned char)l_145));
                        step_hash(39);
                        if (g_84)
                            break;
                    }
                    step_hash(49);
                    if (l_145)
                    {
                        unsigned l_146 = 0x2B028A4BL;
                        int *l_150 = &g_151;
                        step_hash(42);
                        if (l_146)
                            break;
                        step_hash(43);
                        (*l_150) |= ((~(g_4 > l_127)) || ((((((((signed char)g_84 << (signed char)0) || (&g_109 != l_149)) >= p_100) || p_100) || ((*p_102) == (*p_102))) < (*l_110)) != g_111));
                        step_hash(44);
                        if (p_100)
                            continue;
                        step_hash(45);
                        if (l_127)
                            break;
                    }
                    else
                    {
                        step_hash(47);
                        g_111 ^= l_152;
                        step_hash(48);
                        return p_100;
                    }
                    step_hash(54);
                    for (g_111 = 0; (g_111 < 12); g_111 += 3)
                    {
                        int *l_163 = &g_151;
                        step_hash(53);
                        (*l_163) = (((unsigned short)l_159 * (unsigned short)0xA4C7L) && (((p_100 | (+l_160)) & ((short)7L >> (short)1)) > ((*p_102) != (*p_102))));
                    }
                }
                else
                {
                    step_hash(56);
                    (*g_108) = (*g_108);
                    step_hash(57);
                    if (p_101)
                        continue;
                    step_hash(63);
                    if (((unsigned)((unsigned char)g_111 >> (unsigned char)6) + (unsigned)p_100))
                    {
                        step_hash(59);
                        (*p_102) = (*g_108);
                    }
                    else
                    {
                        step_hash(61);
                        (*p_102) = (*p_102);
                        step_hash(62);
                        (*l_110) ^= ((void*)0 == l_168);
                    }
                    step_hash(64);
                    (*g_108) = (*g_108);
                }
                step_hash(86);
                if (p_100)
                {
                    step_hash(72);
                    if (((*g_108) != (void*)0))
                    {
                        step_hash(68);
                        (*l_149) = (void*)0;
                        step_hash(69);
                        (*g_108) = (*p_102);
                    }
                    else
                    {
                        step_hash(71);
                        (*l_110) ^= p_100;
                    }
                    step_hash(73);
                    l_171 &= ((p_100 != ((unsigned short)0x2B22L + (unsigned short)((0x2ED1L >= 0x0081L) >= (*l_110)))) == g_111);
                    step_hash(74);
                    if (l_159)
                        break;
                }
                else
                {
                    unsigned short l_184 = 9UL;
                    step_hash(76);
                    (*l_110) = ((((*l_110) || ((short)(*l_140) % (short)((l_168 != l_168) && (g_111 > g_84)))) > p_101) > (((short)((short)(*l_110) * (short)((short)((unsigned short)g_83 << (unsigned short)l_184) * (short)l_184)) << (short)4) >= p_101));
                    step_hash(77);
                    (*g_108) = (*p_102);
                    step_hash(85);
                    for (p_100 = 0; (p_100 > 1); ++p_100)
                    {
                        unsigned short l_187 = 0x55D8L;
                        step_hash(81);
                        if (l_187)
                            break;
                        step_hash(82);
                        (*l_110) ^= l_187;
                        step_hash(83);
                        if (g_111)
                            break;
                        step_hash(84);
                        return g_83;
                    }
                }
            }
            else
            {
                step_hash(88);
                (*l_149) = (void*)0;
                step_hash(89);
                (*l_110) |= (*l_140);
                step_hash(90);
                if (l_152)
                    break;
            }
            step_hash(92);
            (*l_110) = (*l_140);
        }
    }
    step_hash(95);
    return (*l_110);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_4, "g_4", print_hash_value);
    transparent_crc(g_83, "g_83", print_hash_value);
    transparent_crc(g_84, "g_84", print_hash_value);
    transparent_crc(g_111, "g_111", print_hash_value);
    transparent_crc(g_151, "g_151", print_hash_value);
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
