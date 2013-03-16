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
static int g_3 = 0x860B4FFBL;
static int **g_29 = (void*)0;
static int g_40 = 0xEC560449L;
static int g_45 = 0x8EF34EA8L;
static int *g_89 = &g_45;
static int **g_88 = &g_89;
static unsigned short g_93 = 0x79AAL;
static int g_208 = 0x9EA24B92L;
static unsigned g_275 = 1UL;
static int *g_330 = &g_3;
static signed char func_1(void);
static int * func_6(int ** p_7, int * p_8, unsigned p_9);
static int ** func_11(int ** p_12, int ** p_13, int ** p_14, short p_15);
static int ** func_16(int * p_17, int p_18, int ** p_19, signed char p_20, int * p_21);
static unsigned func_22(int ** p_23);
static int ** func_24(unsigned char p_25, int * p_26);
static int * func_32(int * p_33, int * p_34, unsigned p_35, unsigned char p_36, int ** p_37);
static int * func_38(int p_39);
static int ** func_46(unsigned char p_47, int ** p_48, int ** p_49, int ** p_50);
static unsigned short func_53(unsigned p_54, int ** p_55);
static signed char func_1(void)
{
    int *l_2 = &g_3;
    int **l_4 = (void*)0;
    int **l_5 = &l_2;
    int l_27 = 1L;
    unsigned l_319 = 0UL;
    short l_320 = (-6L);
    step_hash(1);
    (*l_5) = l_2;
    step_hash(5);
    (*l_5) = func_6(&l_2, &g_3, (*l_2));
    step_hash(204);
    (*l_5) = func_6(func_11(func_16(func_6(&l_2, func_6(&l_2, func_6(&l_2, &g_3, func_22(func_24(l_27, &g_3))), g_40), l_319), g_208, &l_2, l_320, (*l_5)), &g_89, &l_2, g_93), (*l_5), g_275);
    step_hash(205);
    (*l_5) = func_6(func_11(&l_2, &g_89, &g_89, g_275), g_330, g_40);
    step_hash(206);
    return (**l_5);
}
static int * func_6(int ** p_7, int * p_8, unsigned p_9)
{
    int *l_10 = &g_3;
    step_hash(3);
    (**p_7) = 0x2086BD08L;
    step_hash(4);
    return l_10;
}
static int ** func_11(int ** p_12, int ** p_13, int ** p_14, short p_15)
{
    int *l_328 = &g_208;
    int **l_329 = &l_328;
    step_hash(200);
    (*g_88) = l_328;
    step_hash(201);
    g_45 ^= (*g_89);
    step_hash(202);
    (*l_328) &= ((l_329 != &l_328) >= p_15);
    step_hash(203);
    return &g_89;
}
static int ** func_16(int * p_17, int p_18, int ** p_19, signed char p_20, int * p_21)
{
    signed char l_323 = 0x46L;
    int **l_327 = &g_89;
    step_hash(190);
    (**g_88) |= ((signed char)g_275 + (signed char)(-5L));
    step_hash(191);
    (*p_21) = l_323;
    step_hash(197);
    for (g_40 = (-11); (g_40 >= 15); g_40 += 5)
    {
        short l_326 = 0x881BL;
        step_hash(195);
        (**g_88) &= (*p_17);
        step_hash(196);
        (**g_88) = (~l_326);
    }
    step_hash(198);
    return l_327;
}
static unsigned func_22(int ** p_23)
{
    int *l_31 = &g_3;
    int **l_30 = &l_31;
    int l_244 = 1L;
    int l_270 = 0x2A5BE70DL;
    step_hash(127);
    (*l_30) = func_6(l_30, (*l_30), (**l_30));
    step_hash(128);
    (*g_89) = 0L;
    step_hash(187);
    for (l_244 = 0; (l_244 <= (-23)); l_244 -= 4)
    {
        int **l_250 = &g_89;
        int **l_294 = &l_31;
        int *l_313 = &g_208;
    }
    step_hash(188);
    return (*l_31);
}
static int ** func_24(unsigned char p_25, int * p_26)
{
    int *l_28 = &g_3;
    step_hash(7);
    (*p_26) = ((l_28 != &g_3) != g_3);
    step_hash(8);
    return g_29;
}
static int * func_32(int * p_33, int * p_34, unsigned p_35, unsigned char p_36, int ** p_37)
{
    unsigned char l_152 = 247UL;
    int ***l_160 = &g_29;
    int *l_223 = &g_208;
    unsigned l_229 = 6UL;
    short l_230 = 0x560BL;
    int l_240 = 0xCCFC83ECL;
    step_hash(78);
    (**g_88) = 6L;
    step_hash(125);
    if (((short)g_93 * (short)(~g_45)))
    {
        signed char l_161 = (-10L);
        int *l_162 = &g_45;
        int *l_242 = &g_208;
        step_hash(120);
        for (g_93 = 0; (g_93 >= 45); ++g_93)
        {
            int l_157 = (-9L);
            int **l_171 = (void*)0;
            signed char l_224 = 0L;
            int l_241 = 1L;
            step_hash(83);
            l_162 = func_38(((signed char)((short)((*p_34) && (0xF94CC8AAL > ((**g_88) <= ((unsigned char)((unsigned short)g_93 / (unsigned short)((l_152 & ((short)(((unsigned)0x40699D30L + (unsigned)(l_157 ^ 0L)) >= ((short)(l_160 != (void*)0) + (short)(-7L))) * (short)p_35)) || (-4L))) % (unsigned char)l_161)))) + (short)0xA078L) << (signed char)7));
            step_hash(84);
            (*p_34) = ((short)(((unsigned)p_36 % (unsigned)(((((unsigned short)(((func_53(((unsigned char)g_45 * (unsigned char)l_157), (*l_160)) && (((void*)0 != &g_29) < func_53(p_35, l_171))) > g_93) != 0x41L) >> (unsigned short)g_93) <= 1L) & g_93) || 0x92L)) | p_35) >> (short)11);
            step_hash(85);
            (*g_89) = (-(int)(*g_89));
            step_hash(119);
            if (func_53((((1UL ^ ((*g_89) >= (p_35 <= ((unsigned short)(p_35 != p_35) << (unsigned short)((signed char)g_93 >> (signed char)2))))) == ((unsigned short)((((p_35 > (**g_88)) >= ((((unsigned short)((g_93 <= p_35) & (*l_162)) << (unsigned short)g_45) && (-6L)) < l_157)) >= g_45) && g_93) - (unsigned short)0x5D93L)) > (*l_162)), &g_89))
            {
                unsigned l_183 = 0UL;
                step_hash(94);
                if ((*g_89))
                {
                    int l_198 = 0x073E8D0CL;
                    step_hash(88);
                    (*l_162) = (((unsigned short)(g_40 && l_183) + (unsigned short)g_40) == (((((unsigned short)((unsigned char)(*l_162) - (unsigned char)g_93) - (unsigned short)(((int)0x5F9BFDDAL - (int)(*l_162)) >= 6UL)) > g_40) > p_35) || p_35));
                    step_hash(89);
                    (*g_88) = func_38(g_45);
                    step_hash(90);
                    (*p_34) = ((unsigned char)((signed char)((unsigned short)0xD123L >> (unsigned short)2) % (signed char)((unsigned short)l_198 << (unsigned short)((unsigned char)247UL - (unsigned char)(((unsigned short)(((((unsigned char)((*g_89) | (g_45 >= (~p_36))) >> (unsigned char)g_40) && (((unsigned)0xAD3C435FL + (unsigned)g_45) ^ g_93)) >= l_183) | 0x3FF94C2EL) - (unsigned short)0x7A49L) || (*g_89))))) >> (unsigned char)g_40);
                }
                else
                {
                    int *l_207 = &g_208;
                    step_hash(92);
                    (*l_207) ^= (*p_34);
                    step_hash(93);
                    (*p_34) = ((short)(func_53(((void*)0 != (*g_88)), l_171) != (((signed char)g_93 * (signed char)p_35) == g_208)) >> (short)1);
                }
                step_hash(95);
                (**g_88) = ((((unsigned char)((unsigned char)g_208 / (unsigned char)(*l_162)) - (unsigned char)g_45) <= ((((unsigned char)g_208 % (unsigned char)g_93) != l_183) == p_35)) < (g_208 == (l_171 == (void*)0)));
                step_hash(96);
                (*g_88) = (*g_88);
            }
            else
            {
                signed char l_226 = 0x13L;
                step_hash(98);
                l_223 = (*g_88);
                step_hash(105);
                if ((**g_88))
                {
                    step_hash(100);
                    if ((**g_88))
                        break;
                    step_hash(101);
                    l_224 = func_53((*l_162), l_171);
                }
                else
                {
                    step_hash(103);
                    (*g_88) = func_38((-(unsigned short)(0x19A3L == (-2L))));
                    step_hash(104);
                    return p_33;
                }
                step_hash(117);
                if ((*p_34))
                {
                    step_hash(107);
                    l_226 |= (*p_34);
                    step_hash(108);
                    (*l_223) |= 0xC5693882L;
                }
                else
                {
                    step_hash(116);
                    for (l_226 = (-16); (l_226 >= 5); l_226 += 5)
                    {
                        step_hash(113);
                        if (l_229)
                            break;
                        step_hash(114);
                        l_230 = ((func_53(p_36, &g_89) >= (!g_93)) == g_208);
                        step_hash(115);
                        if ((*p_34))
                            continue;
                    }
                }
                step_hash(118);
                l_241 ^= (p_35 || (((*l_223) >= ((unsigned short)(((short)((p_36 >= 7UL) == (g_40 > ((**g_88) >= ((*p_34) || ((-(signed char)((((signed char)((unsigned)p_36 - (unsigned)((g_40 >= g_40) & p_35)) - (signed char)l_240) && 0x15239632L) || g_208)) == (**g_88)))))) << (short)8) | g_45) >> (unsigned short)0)) != (*l_162)));
            }
        }
        step_hash(121);
        (*l_242) ^= (*l_162);
        step_hash(122);
        (*l_242) &= (*g_89);
    }
    else
    {
        int *l_243 = &g_45;
        step_hash(124);
        return l_243;
    }
    step_hash(126);
    return (*g_88);
}
static int * func_38(int p_39)
{
    int *l_43 = (void*)0;
    int *l_44 = &g_45;
    int **l_56 = (void*)0;
    int ***l_138 = (void*)0;
    int **l_139 = &l_43;
    step_hash(11);
    (*l_44) ^= (0x015B01D9L < ((short)g_40 << (short)0));
    step_hash(75);
    l_139 = func_46(((short)p_39 % (short)func_53(p_39, l_56)), &l_44, g_29, &l_44);
    step_hash(76);
    return (*l_139);
}
static int ** func_46(unsigned char p_47, int ** p_48, int ** p_49, int ** p_50)
{
    int *l_132 = &g_45;
    int l_137 = (-6L);
    step_hash(73);
    l_137 &= (((void*)0 != l_132) == (((unsigned char)p_47 + (unsigned char)(*l_132)) || ((*l_132) != g_93)));
    step_hash(74);
    return &g_89;
}
static unsigned short func_53(unsigned p_54, int ** p_55)
{
    int *l_58 = &g_45;
    int **l_57 = &l_58;
    int ***l_59 = (void*)0;
    int ***l_60 = &l_57;
    int l_77 = 1L;
    int *l_130 = &l_77;
    step_hash(13);
    (*l_60) = l_57;
    step_hash(63);
    for (g_40 = (-26); (g_40 != 12); g_40++)
    {
        int *l_65 = &g_45;
        int ***l_122 = &g_88;
        step_hash(61);
        for (g_45 = 0; (g_45 == 7); ++g_45)
        {
            int l_76 = 0xD28A2181L;
            int *l_84 = &g_45;
            step_hash(20);
            (**l_60) = l_65;
        }
        step_hash(62);
        if ((*l_65))
            break;
    }
    step_hash(70);
    if ((l_130 == (*g_88)))
    {
        step_hash(65);
        (**l_60) = (void*)0;
        step_hash(66);
        (*l_57) = (*l_57);
    }
    else
    {
        int *l_131 = (void*)0;
        step_hash(68);
        (*g_88) = (**l_60);
        step_hash(69);
        (*l_57) = l_131;
    }
    step_hash(71);
    return g_40;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_40, "g_40", print_hash_value);
    transparent_crc(g_45, "g_45", print_hash_value);
    transparent_crc(g_93, "g_93", print_hash_value);
    transparent_crc(g_208, "g_208", print_hash_value);
    transparent_crc(g_275, "g_275", print_hash_value);
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
