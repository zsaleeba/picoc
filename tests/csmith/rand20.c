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
static int g_2 = (-5L);
static int g_66 = 0x5B6062CFL;
static int *g_106 = &g_2;
static int **g_105 = &g_106;
static unsigned char func_1(void);
static int func_7(signed char p_8, int p_9, unsigned p_10);
static signed char func_11(unsigned p_12, unsigned p_13);
static unsigned func_14(int p_15, int p_16, short p_17);
static int * func_19(int * p_20, int * p_21, int * p_22, int * p_23);
static int * func_25(signed char p_26, unsigned char p_27, unsigned char p_28, unsigned short p_29, signed char p_30);
static short func_33(short p_34, int p_35, int * p_36, signed char p_37, int * p_38);
static unsigned short func_51(int * p_52, unsigned p_53, unsigned char p_54);
static int * func_55(int p_56);
static short func_59(int * p_60);
static unsigned char func_1(void)
{
    unsigned l_18 = 0UL;
    int *l_167 = &g_2;
    signed char l_305 = 7L;
    short l_310 = 0x5A42L;
    int *l_311 = &g_66;
    step_hash(156);
    for (g_2 = 10; (g_2 <= (-6)); g_2 -= 9)
    {
        unsigned short l_149 = 65527UL;
        int l_298 = (-2L);
        int *l_301 = &g_66;
        int ***l_304 = (void*)0;
    }
    step_hash(157);
    (*l_311) |= (((void*)0 == &g_106) <= ((unsigned short)((signed char)((void*)0 != &g_105) + (signed char)l_310) / (unsigned short)(*l_167)));
    step_hash(158);
    (*g_105) = (void*)0;
    step_hash(159);
    return (*l_167);
}
static int func_7(signed char p_8, int p_9, unsigned p_10)
{
    int l_170 = 0x5EEE56F2L;
    int l_179 = 0L;
    int *l_180 = &l_170;
    step_hash(81);
    g_66 ^= p_9;
    step_hash(146);
    if (((unsigned short)l_170 + (unsigned short)0x87EFL))
    {
        int *l_171 = &l_170;
        step_hash(83);
        (*l_171) = (p_9 != 0x6EL);
        step_hash(88);
        for (l_170 = (-30); (l_170 != 26); ++l_170)
        {
            int *l_174 = &g_66;
            step_hash(87);
            (*l_174) ^= l_170;
        }
    }
    else
    {
        int *l_175 = &g_66;
        int *l_210 = &g_2;
        int ***l_261 = &g_105;
        unsigned short l_295 = 3UL;
        step_hash(95);
        if (p_9)
        {
            int l_178 = 0x3BCE19DEL;
            step_hash(91);
            l_180 = func_25(((int)l_178 + (int)(2L && (func_51(func_19(&l_170, &l_178, l_175, func_55((l_175 == (void*)0))), g_2, l_170) | 1L))), l_179, p_8, l_178, p_10);
            step_hash(92);
            return (*l_180);
        }
        else
        {
            int l_181 = (-8L);
            step_hash(94);
            (*l_175) ^= l_181;
        }
        step_hash(143);
        if ((((unsigned char)0x5FL << (unsigned char)5) && ((*l_175) < 0xC3L)))
        {
            unsigned char l_184 = 1UL;
            int **l_235 = &l_210;
            step_hash(97);
            (*l_175) = (((((g_2 || g_2) != l_184) == ((-8L) != ((unsigned short)(((1UL == g_2) != ((signed char)(((unsigned short)func_11((((unsigned)p_9 - (unsigned)(func_59((*g_105)) && l_184)) >= (*l_175)), g_2) * (unsigned short)g_2) || p_10) / (signed char)p_8)) && l_184) % (unsigned short)g_2))) <= (-1L)) ^ g_2);
            step_hash(140);
            if (((signed char)p_10 * (signed char)p_8))
            {
                unsigned short l_199 = 3UL;
                step_hash(103);
                for (l_184 = 15; (l_184 <= 35); ++l_184)
                {
                    int ***l_197 = (void*)0;
                    int ***l_198 = &g_105;
                    step_hash(102);
                    (*l_198) = &g_106;
                }
                step_hash(104);
                (*g_105) = func_25((l_199 & p_8), ((+(-(int)((*l_175) || p_10))) < (*l_180)), ((g_2 >= 65534UL) > g_2), l_184, g_2);
                step_hash(105);
                l_175 = &l_170;
            }
            else
            {
                unsigned short l_201 = 0xF001L;
                int *l_221 = (void*)0;
                signed char l_294 = 0x85L;
                step_hash(112);
                if (l_201)
                {
                    unsigned l_224 = 1UL;
                    step_hash(108);
                    (*l_180) = p_10;
                    step_hash(109);
                    (*l_175) = (((int)(((unsigned char)(((short)g_66 - (short)((unsigned short)func_51(l_210, ((signed char)((signed char)((unsigned)((short)((unsigned char)((*l_180) <= func_59(l_221)) << (unsigned char)1) << (short)2) + (unsigned)(g_66 || g_66)) + (signed char)g_2) * (signed char)((((signed char)(g_66 == 4L) >> (signed char)1) != (*l_180)) && 255UL)), l_224) >> (unsigned short)12)) | 0x6DC5B995L) + (unsigned char)g_66) > 0x240DL) + (int)l_184) >= 0x1803L);
                }
                else
                {
                    unsigned char l_225 = 0UL;
                    short l_234 = 1L;
                    step_hash(111);
                    (*l_175) = (**l_235);
                }
                step_hash(139);
                if (((*l_175) & ((((unsigned short)((signed char)(-4L) >> (signed char)((unsigned short)((signed char)((int)(-(unsigned)((~(((((unsigned char)(((*l_210) <= (0x5BE0L | ((short)((signed char)(65533UL && ((unsigned char)(((((unsigned)0UL - (unsigned)func_59((*g_105))) | ((signed char)func_59(func_19(l_210, (*g_105), l_221, &l_170)) - (signed char)1L)) <= p_10) == 1L) % (unsigned char)246UL)) + (signed char)0L) + (short)2UL))) ^ p_8) * (unsigned char)0x20L) < 0x85775876L) >= p_8) != (*l_180))) > 0xE881L)) - (int)0xD568A418L) % (signed char)g_2) % (unsigned short)(*l_175))) % (unsigned short)(**l_235)) && p_8) > p_9)))
                {
                    int **l_262 = &g_106;
                    int l_269 = (-7L);
                    step_hash(114);
                    (*l_180) &= (-5L);
                    step_hash(121);
                    if ((((void*)0 == l_261) <= p_8))
                    {
                        step_hash(116);
                        (*l_175) = (g_66 & func_59(&l_170));
                        step_hash(117);
                        (*l_261) = l_262;
                        step_hash(118);
                        (*l_175) = p_10;
                    }
                    else
                    {
                        step_hash(120);
                        (*g_105) = (**l_261);
                    }
                    step_hash(128);
                    if (p_8)
                    {
                        short l_280 = (-1L);
                        step_hash(123);
                        (*l_180) &= p_8;
                        step_hash(124);
                        (*l_180) = ((unsigned short)((unsigned short)g_2 % (unsigned short)g_2) * (unsigned short)((((signed char)l_269 << (signed char)6) | ((short)p_8 >> (short)((!((short)((int)(+((int)((void*)0 != &g_106) % (int)p_8)) + (int)(p_10 == ((!((unsigned short)l_280 / (unsigned short)g_66)) ^ p_9))) >> (short)p_10)) == p_9))) <= 0x316CF6D4L));
                        step_hash(125);
                        return l_280;
                    }
                    else
                    {
                        int *l_281 = &l_269;
                        step_hash(127);
                        l_281 = (*l_235);
                    }
                    step_hash(129);
                    (*l_180) = 0x73A35D59L;
                }
                else
                {
                    unsigned short l_287 = 6UL;
                    int l_288 = 0L;
                    int **l_291 = &l_221;
                    step_hash(131);
                    (*l_175) = p_9;
                    step_hash(137);
                    if ((*l_180))
                    {
                        int *l_286 = &l_170;
                        step_hash(133);
                        l_288 |= ((unsigned short)((((signed char)g_66 * (signed char)6UL) != func_59(func_19(l_286, func_19((*g_105), l_286, &l_170, func_19((*g_105), func_19(func_19((*l_235), func_19((*g_105), l_221, (*l_235), (*g_105)), (*l_235), l_286), l_221, &l_170, l_286), l_286, (*g_105))), (*l_235), (**l_261)))) == p_9) * (unsigned short)l_287);
                        step_hash(134);
                        (**l_261) = func_25(p_8, g_66, ((unsigned char)((&g_106 == l_291) && ((short)((**l_235) <= (0x8FL != (1UL <= p_9))) << (short)func_59((*g_105)))) >> (unsigned char)l_294), (**l_235), (*l_286));
                    }
                    else
                    {
                        step_hash(136);
                        (*l_180) = ((l_295 == p_8) >= 4294967291UL);
                    }
                    step_hash(138);
                    return p_9;
                }
            }
        }
        else
        {
            step_hash(142);
            return p_9;
        }
        step_hash(144);
        (*l_180) = ((short)(*l_180) << (short)8);
        step_hash(145);
        (**l_261) = (*g_105);
    }
    step_hash(147);
    return p_8;
}
static signed char func_11(unsigned p_12, unsigned p_13)
{
    int *l_150 = &g_66;
    int l_151 = 0L;
    unsigned l_154 = 0x209CDE0CL;
    int **l_161 = &l_150;
    int *l_162 = &l_151;
    step_hash(76);
    l_150 = (void*)0;
    step_hash(77);
    l_151 = 0xA18BD6C3L;
    step_hash(78);
    l_162 = func_55(((((unsigned char)(func_51((*g_105), ((l_151 != l_154) | ((short)((unsigned)((unsigned short)func_59(func_25(g_66, (l_161 != &l_150), g_2, g_66, p_13)) * (unsigned short)g_2) / (unsigned)p_12) + (short)p_13)), p_13) < 0xB808L) * (unsigned char)2L) && p_12) < 0UL));
    step_hash(79);
    return p_13;
}
static unsigned func_14(int p_15, int p_16, short p_17)
{
    int *l_24 = (void*)0;
    int l_45 = 0x6A3F1540L;
    step_hash(73);
    (*g_105) = func_19(l_24, &g_2, func_25(g_2, (((~(+0xB15E314AL)) ^ ((short)(func_33(((int)p_15 / (int)p_16), (((signed char)p_17 - (signed char)((signed char)3L * (signed char)(g_2 < p_17))) || l_45), &g_2, p_17, &l_45) & 1L) + (short)p_17)) < p_16), g_2, p_16, p_16), l_24);
    step_hash(74);
    return g_2;
}
static int * func_19(int * p_20, int * p_21, int * p_22, int * p_23)
{
    signed char l_147 = 0x10L;
    int l_148 = (-2L);
    step_hash(71);
    l_148 = l_147;
    step_hash(72);
    return p_23;
}
static int * func_25(signed char p_26, unsigned char p_27, unsigned char p_28, unsigned short p_29, signed char p_30)
{
    int *l_141 = &g_66;
    int *l_146 = &g_66;
    step_hash(66);
    (*l_141) = p_30;
    step_hash(67);
    (*l_141) = ((short)(*l_141) << (short)(func_51(l_141, func_51(l_141, g_66, (*l_141)), p_27) ^ (&l_141 == &l_141)));
    step_hash(68);
    (*l_146) = ((!(((((void*)0 != l_141) > ((short)g_66 * (short)((((*l_141) != func_59(l_141)) < func_59(l_146)) || 0xEAL))) != 0UL) == p_28)) & (-2L));
    step_hash(69);
    return l_141;
}
static short func_33(short p_34, int p_35, int * p_36, signed char p_37, int * p_38)
{
    int *l_50 = (void*)0;
    int *l_67 = &g_2;
    unsigned short l_77 = 0x7135L;
    unsigned short l_96 = 6UL;
    int l_133 = 0x6E60FB7EL;
    unsigned l_140 = 4294967295UL;
    step_hash(61);
    if (((short)((short)(g_2 ^ (l_50 != &p_35)) % (short)func_51(func_55(((short)func_59(l_50) >> (short)8)), ((l_67 != &p_35) < (((unsigned char)(((unsigned char)(*l_67) % (unsigned char)0xB0L) <= 0xE9L) << (unsigned char)0) | g_2)), g_2)) >> (short)p_34))
    {
        int **l_72 = &l_50;
        step_hash(15);
        (*l_72) = func_55((*p_36));
        step_hash(16);
        (*p_38) = (0xB1L ^ g_66);
    }
    else
    {
        int **l_73 = &l_67;
        step_hash(18);
        (*l_73) = &g_66;
        step_hash(59);
        if (((int)0x3965B818L + (int)0x61CAE467L))
        {
            int *l_76 = &g_2;
            int l_86 = 2L;
            step_hash(55);
            if (((*l_67) > (func_51(l_76, p_34, func_59(&g_2)) && 0L)))
            {
                step_hash(21);
                l_77 ^= ((void*)0 != &l_50);
                step_hash(22);
                (*l_73) = &p_35;
            }
            else
            {
                int *l_92 = &g_2;
                unsigned char l_130 = 250UL;
                step_hash(37);
                if ((1UL ^ g_2))
                {
                    signed char l_87 = 0x96L;
                    int *l_95 = &g_66;
                    step_hash(25);
                    (**l_73) = func_51(func_55((**l_73)), (g_2 || 0xBFBDL), g_2);
                    step_hash(32);
                    if (((unsigned char)(((unsigned short)((short)(((unsigned short)(l_86 > (((l_87 < (((unsigned char)p_35 * (unsigned char)func_51(&g_2, ((signed char)p_35 * (signed char)(l_67 != l_92)), ((short)(p_34 > (l_95 != &p_35)) + (short)0x2D05L))) ^ p_35)) != (*l_92)) >= 1L)) - (unsigned short)0x2D1EL) || g_66) << (short)p_35) + (unsigned short)4UL) < p_35) << (unsigned char)p_37))
                    {
                        step_hash(27);
                        (*p_38) = (((*l_95) != (*l_92)) != (p_35 < g_66));
                        step_hash(28);
                        (*l_73) = func_55(l_96);
                    }
                    else
                    {
                        step_hash(30);
                        g_66 = ((unsigned short)(func_51((*l_73), p_34, ((int)((unsigned short)func_59(l_92) * (unsigned short)((signed char)0xFFL + (signed char)0x51L)) - (int)(func_59(l_67) ^ (**l_73)))) & (**l_73)) % (unsigned short)0xDF38L);
                        step_hash(31);
                        (*g_105) = func_55(((void*)0 == g_105));
                    }
                    step_hash(33);
                    (*p_38) = (*g_106);
                }
                else
                {
                    step_hash(35);
                    (*p_38) = ((short)(p_35 < func_51((*l_73), g_2, p_37)) << (short)3);
                    step_hash(36);
                    (*p_38) &= (*l_76);
                }
                step_hash(54);
                for (g_66 = 0; (g_66 <= (-15)); --g_66)
                {
                    step_hash(47);
                    for (p_37 = 12; (p_37 <= 20); p_37 += 9)
                    {
                        int **l_113 = &l_67;
                        step_hash(44);
                        (*g_105) = &p_35;
                        step_hash(45);
                        (*p_38) &= (**g_105);
                        step_hash(46);
                        (**g_105) = ((l_113 == (void*)0) <= ((int)((unsigned short)(*l_92) / (unsigned short)((signed char)(-3L) + (signed char)(p_37 & (*l_76)))) / (int)((unsigned short)((signed char)(((void*)0 == l_92) & ((unsigned)6UL - (unsigned)2L)) - (signed char)0xC0L) * (unsigned short)(**l_73))));
                    }
                    step_hash(48);
                    (*p_38) = (func_59((*g_105)) || ((((unsigned)((unsigned char)((void*)0 != &p_35) >> (unsigned char)(func_51((*g_105), p_35, g_2) != p_37)) - (unsigned)4294967293UL) ^ g_66) || g_66));
                    step_hash(53);
                    if ((*l_76))
                    {
                        step_hash(50);
                        return l_130;
                    }
                    else
                    {
                        step_hash(52);
                        return (**l_73);
                    }
                }
            }
        }
        else
        {
            step_hash(57);
            (*g_105) = &p_35;
            step_hash(58);
            (*p_38) = ((short)((void*)0 == &g_106) >> (short)5);
        }
        step_hash(60);
        (*l_73) = func_55((&g_106 == &g_106));
    }
    step_hash(62);
    l_133 |= (*l_67);
    step_hash(63);
    (*p_38) = ((unsigned char)(p_37 != ((((*g_105) != (*g_105)) > ((unsigned char)g_66 - (unsigned char)func_59((*g_105)))) >= (g_66 != ((unsigned short)(&l_50 != (void*)0) >> (unsigned short)l_140)))) / (unsigned char)p_37);
    step_hash(64);
    return g_2;
}
static unsigned short func_51(int * p_52, unsigned p_53, unsigned char p_54)
{
    step_hash(13);
    return g_66;
}
static int * func_55(int p_56)
{
    int *l_65 = &g_66;
    step_hash(10);
    (*l_65) = (((unsigned)(g_2 | g_2) + (unsigned)0x2406C49AL) >= g_2);
    step_hash(11);
    return &g_2;
}
static short func_59(int * p_60)
{
    int *l_62 = &g_2;
    int **l_61 = &l_62;
    step_hash(7);
    (*l_61) = (void*)0;
    step_hash(8);
    return g_2;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_2, "g_2", print_hash_value);
    transparent_crc(g_66, "g_66", print_hash_value);
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
