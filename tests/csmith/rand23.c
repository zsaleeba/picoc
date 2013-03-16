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
static int g_3 = 0xC213532FL;
static int g_14 = 0x652D0DA0L;
static int g_23 = (-1L);
static int *g_31 = &g_23;
static int **g_30 = &g_31;
static int g_114 = 1L;
static int g_144 = 0xA3224D42L;
static unsigned char func_1(void);
static short func_6(int p_7);
static unsigned short func_19(unsigned p_20, unsigned p_21, int ** p_22);
static int func_24(int ** p_25, unsigned short p_26, int ** p_27, unsigned p_28, int p_29);
static unsigned short func_32(int p_33, short p_34);
static int func_35(int ** p_36);
static int * func_38(int * p_39, int p_40, unsigned p_41, int ** p_42, int * p_43);
static int func_44(int p_45, unsigned p_46, short p_47, int * p_48);
static int func_50(unsigned short p_51, int p_52, signed char p_53, unsigned p_54, unsigned p_55);
static int func_57(int p_58, unsigned short p_59, unsigned short p_60);
static unsigned char func_1(void)
{
    int *l_2 = &g_3;
    step_hash(1);
    (*l_2) &= (-1L);
    step_hash(2);
    (*l_2) = 0L;
    step_hash(94);
    (*l_2) = (g_3 && ((short)((func_6(g_3) > func_19(g_23, g_23, &l_2)) < g_144) + (short)((unsigned short)(g_30 != g_30) * (unsigned short)g_144)));
    step_hash(95);
    return (*l_2);
}
static short func_6(int p_7)
{
    step_hash(17);
    for (p_7 = 0; (p_7 > 7); p_7 += 1)
    {
        step_hash(11);
        for (g_3 = 0; (g_3 > 4); g_3++)
        {
            int *l_12 = (void*)0;
            int *l_13 = &g_14;
            step_hash(10);
            (*l_13) &= g_3;
        }
        step_hash(16);
        for (g_14 = 0; (g_14 <= 23); g_14 += 8)
        {
            int *l_18 = &g_3;
            int **l_17 = &l_18;
            step_hash(15);
            l_17 = l_17;
        }
    }
    step_hash(18);
    return g_3;
}
static unsigned short func_19(unsigned p_20, unsigned p_21, int ** p_22)
{
    int **l_37 = &g_31;
    unsigned l_145 = 4294967288UL;
    int *l_154 = &g_114;
    step_hash(91);
    (*l_154) = func_24(g_30, func_32(func_35(l_37), p_20), g_30, ((signed char)(!(func_32(g_144, g_144) > g_144)) - (signed char)g_144), l_145);
    step_hash(92);
    (*l_37) = (*g_30);
    step_hash(93);
    return (*l_154);
}
static int func_24(int ** p_25, unsigned short p_26, int ** p_27, unsigned p_28, int p_29)
{
    unsigned l_146 = 4294967287UL;
    int *l_147 = (void*)0;
    int *l_148 = (void*)0;
    int *l_149 = &g_23;
    step_hash(88);
    (*l_149) = (l_146 | p_28);
    step_hash(89);
    (*l_149) = ((signed char)((short)0x2614L / (short)0x9486L) >> (signed char)((*p_27) == l_149));
    step_hash(90);
    return p_29;
}
static unsigned short func_32(int p_33, short p_34)
{
    unsigned l_141 = 3UL;
    step_hash(85);
    l_141 &= p_34;
    step_hash(86);
    return l_141;
}
static int func_35(int ** p_36)
{
    unsigned char l_49 = 0xC9L;
    int *l_134 = &g_114;
    unsigned char l_139 = 2UL;
    int *l_140 = &g_114;
    step_hash(79);
    (*g_30) = func_38((*g_30), func_44(l_49, g_23, l_49, (*g_30)), (l_49 ^ (-1L)), &g_31, (*g_30));
    step_hash(80);
    l_134 = func_38(l_134, (*l_134), ((unsigned short)(((signed char)(*l_134) * (signed char)g_23) | ((0UL >= (&g_31 != p_36)) < ((&l_134 == (void*)0) < g_114))) << (unsigned short)(*l_134)), &g_31, (*p_36));
    step_hash(81);
    (*p_36) = (*p_36);
    step_hash(82);
    (*l_140) |= l_49;
    step_hash(83);
    return (*l_140);
}
static int * func_38(int * p_39, int p_40, unsigned p_41, int ** p_42, int * p_43)
{
    int l_128 = 0x0A102B46L;
    int **l_130 = &g_31;
    step_hash(77);
    for (g_23 = (-30); (g_23 >= 11); g_23 += 1)
    {
        step_hash(70);
        (*g_30) = (*p_42);
        step_hash(76);
        if ((*p_39))
        {
            int **l_129 = &g_31;
            int *l_131 = (void*)0;
            int *l_132 = &g_114;
            step_hash(72);
            (*l_132) |= (l_128 == (l_129 != l_130));
        }
        else
        {
            int l_133 = 0x91863936L;
            step_hash(74);
            l_133 |= (g_23 < g_114);
            step_hash(75);
            (*p_42) = (void*)0;
        }
    }
    step_hash(78);
    return (*p_42);
}
static int func_44(int p_45, unsigned p_46, short p_47, int * p_48)
{
    unsigned l_56 = 0xF3352FB2L;
    unsigned l_67 = 0x199F2DC8L;
    unsigned short l_72 = 0x92A4L;
    unsigned char l_88 = 0xD9L;
    int l_104 = (-7L);
    unsigned char l_112 = 252UL;
    step_hash(22);
    (**g_30) = (*p_48);
    step_hash(38);
    if (func_50(l_56, func_57(((unsigned char)0xD7L << (unsigned char)0), ((unsigned char)((unsigned short)l_67 * (unsigned short)((unsigned)((int)l_72 % (int)l_56) % (unsigned)(*p_48))) >> (unsigned char)(0L <= l_56)), p_46), l_67, p_47, g_23))
    {
        step_hash(30);
        return (*p_48);
    }
    else
    {
        unsigned short l_89 = 0x0D0CL;
        step_hash(32);
        (*p_48) = 0x387DD7D5L;
        step_hash(37);
        for (l_72 = 0; (l_72 <= 10); ++l_72)
        {
            int l_90 = 0x59E6156CL;
            step_hash(36);
            (*p_48) = func_57(((unsigned short)((unsigned short)(l_72 != g_23) / (unsigned short)(+((unsigned char)((g_23 | ((func_57((*p_48), ((!((((((0xC961L <= 0xDA97L) == func_57(((signed char)p_46 - (signed char)(func_57(((signed char)(0x9C23L != (((*g_30) == (void*)0) > 0x26L)) - (signed char)l_88), g_23, l_89) >= (-1L))), l_56, p_47)) <= p_47) > p_46) || 0UL) == 0xDFC4L)) || g_23), l_88) && l_89) && l_89)) == l_88) >> (unsigned char)p_45))) * (unsigned short)g_23), l_90, l_90);
        }
    }
    step_hash(64);
    if (((*p_48) < (((short)g_23 - (short)((((unsigned char)(((-(unsigned)((g_23 == (l_67 != func_50(p_45, ((signed char)l_72 / (signed char)((unsigned short)((!func_50(l_72, ((unsigned char)(l_88 || 0x5EFFL) - (unsigned char)l_104), p_46, l_72, p_47)) == 0x10CAL) << (unsigned short)8)), p_46, g_23, l_67))) && g_23)) <= g_23) != (*g_31)) << (unsigned char)4) && g_23) || g_23)) || 0UL)))
    {
        unsigned l_119 = 0x64957343L;
        step_hash(53);
        if ((*g_31))
        {
            int *l_106 = (void*)0;
            int **l_105 = &l_106;
            step_hash(41);
            (*l_105) = (*g_30);
            step_hash(42);
            l_104 |= (-(short)g_23);
        }
        else
        {
            int *l_108 = (void*)0;
            step_hash(44);
            (**g_30) = (g_23 <= ((p_48 == l_108) | 0xD1L));
            step_hash(45);
            (*p_48) = (l_108 == (void*)0);
            step_hash(52);
            for (l_72 = (-27); (l_72 == 59); l_72 += 9)
            {
                int **l_111 = &l_108;
                int *l_113 = &g_114;
                step_hash(49);
                (*l_111) = (void*)0;
                step_hash(50);
                (*l_113) ^= func_50(l_112, (*p_48), p_46, g_23, l_104);
                step_hash(51);
                (*p_48) = ((unsigned char)0x05L >> (unsigned char)((!(-5L)) == ((unsigned char)func_57((**g_30), l_119, ((int)(*g_31) - (int)p_45)) - (unsigned char)func_50(g_114, (*p_48), g_23, l_72, l_67))));
            }
        }
        step_hash(54);
        (*g_31) = (*p_48);
    }
    else
    {
        step_hash(56);
        p_48 = (void*)0;
        step_hash(63);
        for (l_72 = 13; (l_72 < 16); l_72++)
        {
            int *l_124 = &g_23;
            int **l_125 = &l_124;
            step_hash(60);
            if ((**g_30))
                break;
            step_hash(61);
            l_124 = p_48;
            step_hash(62);
            (*l_125) = (*g_30);
        }
    }
    step_hash(65);
    return l_88;
}
static int func_50(unsigned short p_51, int p_52, signed char p_53, unsigned p_54, unsigned p_55)
{
    int *l_75 = &g_23;
    step_hash(27);
    l_75 = (*g_30);
    step_hash(28);
    return p_55;
}
static int func_57(int p_58, unsigned short p_59, unsigned short p_60)
{
    int *l_74 = (void*)0;
    int **l_73 = &l_74;
    step_hash(24);
    (*l_73) = (*g_30);
    step_hash(25);
    return (**l_73);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_3, "g_3", print_hash_value);
    transparent_crc(g_14, "g_14", print_hash_value);
    transparent_crc(g_23, "g_23", print_hash_value);
    transparent_crc(g_114, "g_114", print_hash_value);
    transparent_crc(g_144, "g_144", print_hash_value);
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
