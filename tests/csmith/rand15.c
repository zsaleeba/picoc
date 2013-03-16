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
static int g_11 = 0x8F6C74AAL;
static int g_25 = 0xCF81320FL;
static unsigned g_67 = 0x94A98A1BL;
static int *g_76 = &g_11;
static int **g_75 = &g_76;
static short g_106 = 5L;
static int g_156 = (-1L);
static signed char g_349 = 0x18L;
static int g_444 = 0xF7F93694L;
static unsigned g_459 = 1UL;
static int g_498 = (-1L);
static short func_1(void);
static int func_2(unsigned p_3, unsigned char p_4);
static unsigned func_5(signed char p_6);
static signed char func_7(unsigned char p_8, unsigned p_9, short p_10);
static unsigned char func_16(unsigned p_17, int p_18, int p_19, short p_20);
static int * func_28(unsigned char p_29, int * p_30, unsigned char p_31, int p_32, int * p_33);
static unsigned func_40(unsigned p_41, signed char p_42, unsigned short p_43, signed char p_44, int * p_45);
static unsigned char func_50(unsigned char p_51, int * p_52);
static int * func_68(int ** p_69);
static int ** func_70(int p_71, unsigned p_72, short p_73, int ** p_74);
static short func_1(void)
{
    signed char l_14 = 0xBFL;
    unsigned char l_15 = 0x44L;
    int *l_673 = &g_498;
    unsigned l_705 = 4294967295UL;
    step_hash(389);
    (*l_673) = func_2(((0x86CCE57BL && func_5(func_7(g_11, ((unsigned char)(~(l_14 & ((l_15 | (l_14 | 0x53L)) && func_16(l_15, g_11, g_11, l_15)))) >> (unsigned char)7), g_156))) < g_459), l_15);
    step_hash(406);
    for (g_498 = 0; (g_498 >= 1); g_498++)
    {
        signed char l_691 = 0x9FL;
        step_hash(405);
        for (g_25 = 0; (g_25 >= (-4)); g_25 -= 3)
        {
            int *l_678 = &g_25;
            int **l_679 = &l_673;
            unsigned l_702 = 4UL;
            step_hash(396);
            (*l_679) = l_678;
            step_hash(402);
            for (g_67 = (-4); (g_67 > 4); g_67 += 4)
            {
                unsigned short l_686 = 0x0A0FL;
                step_hash(400);
                g_11 = ((g_25 >= ((short)(((short)l_686 - (short)((signed char)((short)l_691 % (short)(g_25 ^ ((unsigned)0UL + (unsigned)((-5L) ^ (+((int)((unsigned short)((unsigned char)(l_702 >= (func_2(((*l_678) & ((unsigned)(((func_2(g_25, g_156) == 0x26L) >= l_686) > (*l_678)) / (unsigned)g_459)), (*l_673)) >= 1L)) << (unsigned char)5) << (unsigned short)g_349) % (int)l_686)))))) + (signed char)g_444)) & (-10L)) * (short)g_444)) < (*l_673));
                step_hash(401);
                l_705 ^= (*l_673);
            }
            step_hash(403);
            if ((*l_678))
                break;
            step_hash(404);
            g_156 &= 0x2DF3C4D5L;
        }
    }
    step_hash(407);
    return (*l_673);
}
static int func_2(unsigned p_3, unsigned char p_4)
{
    step_hash(388);
    return g_106;
}
static unsigned func_5(signed char p_6)
{
    int **l_649 = &g_76;
    int l_651 = 0L;
    int l_656 = 5L;
    int l_668 = (-9L);
    step_hash(368);
    for (g_349 = 0; (g_349 <= 6); ++g_349)
    {
        int l_648 = 9L;
        step_hash(366);
        l_648 &= p_6;
        step_hash(367);
        if (p_6)
            break;
    }
    step_hash(378);
    if ((p_6 == (l_649 != (void*)0)))
    {
        int *l_650 = (void*)0;
        int l_654 = 0x15005DFCL;
        int *l_655 = &g_156;
        step_hash(370);
        l_651 &= p_6;
        step_hash(371);
        (*l_649) = &g_11;
        step_hash(372);
        (*l_655) &= func_40((((p_6 <= (((1UL == ((short)(((**l_649) & l_654) == 4294967289UL) << (short)(&l_654 == &l_654))) && p_6) > func_40(l_654, p_6, g_67, p_6, l_655))) < g_67) || 0x505505BEL), p_6, p_6, l_656, &l_654);
    }
    else
    {
        int **l_661 = &g_76;
        int *l_664 = (void*)0;
        int *l_665 = (void*)0;
        int *l_666 = &g_11;
        int ***l_667 = &l_661;
        step_hash(374);
        (*l_666) ^= (((unsigned char)(0x34L & p_6) - (unsigned char)((signed char)((&l_649 != (void*)0) < ((l_661 == l_649) | ((int)(g_459 | 65535UL) - (int)p_6))) % (signed char)p_6)) == 65535UL);
        step_hash(375);
        (*l_667) = &l_664;
        step_hash(376);
        (**l_667) = (*l_649);
        step_hash(377);
        l_651 = ((void*)0 != (*l_649));
    }
    step_hash(379);
    l_668 = g_11;
    step_hash(385);
    for (g_106 = (-29); (g_106 >= (-3)); g_106 += 3)
    {
        unsigned short l_671 = 65526UL;
        int l_672 = (-1L);
        step_hash(383);
        if (p_6)
            break;
        step_hash(384);
        l_672 ^= l_671;
    }
    step_hash(386);
    return g_67;
}
static signed char func_7(unsigned char p_8, unsigned p_9, short p_10)
{
    short l_577 = 0xB75CL;
    int *l_578 = &g_156;
    short l_581 = 0xCAE9L;
    unsigned short l_586 = 6UL;
    signed char l_610 = 0x5DL;
    int l_630 = (-4L);
    signed char l_645 = 0x7FL;
    step_hash(323);
    (*l_578) = ((unsigned char)((int)((((signed char)p_8 % (signed char)func_40(g_498, func_40(l_577, (g_349 <= ((l_578 != l_578) | ((unsigned short)l_581 + (unsigned short)((*l_578) ^ ((unsigned short)(~(((signed char)0xD8L - (signed char)l_586) || 0xBEL)) >> (unsigned short)p_8))))), g_459, g_106, l_578), g_459, p_10, l_578)) || (-4L)) >= g_349) % (int)p_8) - (unsigned char)0xAFL);
    step_hash(360);
    for (l_577 = 0; (l_577 != 21); ++l_577)
    {
        signed char l_589 = 0L;
        unsigned l_592 = 0x9603CDF1L;
        int *l_593 = (void*)0;
        int l_595 = 0x20560BFFL;
        step_hash(327);
        l_589 &= (g_459 >= (0xEFB8E0A5L ^ (g_67 > 0x8068L)));
    }
    step_hash(361);
    return l_645;
}
static unsigned char func_16(unsigned p_17, int p_18, int p_19, short p_20)
{
    int *l_34 = &g_11;
    int l_58 = 0x469F41AFL;
    short l_564 = (-1L);
    step_hash(320);
    if (g_11)
    {
        step_hash(3);
        return g_11;
    }
    else
    {
        int *l_21 = (void*)0;
        int *l_22 = (void*)0;
        int *l_23 = (void*)0;
        int *l_24 = &g_25;
        signed char l_545 = 1L;
        int **l_566 = &g_76;
        unsigned short l_567 = 0x974BL;
        int *l_570 = &g_444;
        step_hash(5);
        (*l_24) |= 0x779A7B44L;
        step_hash(317);
        for (p_17 = 24; (p_17 <= 16); p_17--)
        {
            unsigned short l_37 = 0UL;
            int l_541 = 0x7544DC15L;
            signed char l_544 = 0x06L;
            int *l_565 = &g_444;
        }
        step_hash(318);
        (*l_566) = func_28(((*g_76) || p_18), (*g_75), p_18, g_67, l_23);
        step_hash(319);
        l_58 ^= (p_18 < ((l_567 && (3UL && ((unsigned char)func_40((((void*)0 != l_570) & (0x47L == 6L)), g_67, ((0x7DE2L < 0xF544L) >= g_156), (*l_34), (*l_566)) * (unsigned char)p_18))) > 0x62F0825AL));
    }
    step_hash(321);
    return (*l_34);
}
static int * func_28(unsigned char p_29, int * p_30, unsigned char p_31, int p_32, int * p_33)
{
    int *l_63 = (void*)0;
    int l_64 = 1L;
    unsigned l_65 = 6UL;
    unsigned short l_66 = 65535UL;
    step_hash(17);
    g_67 = ((unsigned short)p_29 + (unsigned short)((short)(0x9FBC0AE2L == (func_40((g_11 & (l_64 && 0x796FB6C7L)), g_11, g_25, l_65, &l_64) > l_66)) / (short)g_11));
    step_hash(284);
    (*g_75) = func_68(func_70(p_29, g_25, p_29, g_75));
    step_hash(285);
    g_75 = &p_30;
    step_hash(286);
    return p_33;
}
static unsigned func_40(unsigned p_41, signed char p_42, unsigned short p_43, signed char p_44, int * p_45)
{
    int **l_53 = (void*)0;
    int **l_54 = (void*)0;
    int *l_56 = &g_11;
    int **l_55 = &l_56;
    short l_57 = 0xE848L;
    step_hash(13);
    (*l_55) = p_45;
    step_hash(14);
    g_25 &= (-1L);
    step_hash(15);
    return l_57;
}
static unsigned char func_50(unsigned char p_51, int * p_52)
{
    step_hash(10);
    (*p_52) &= g_11;
    step_hash(11);
    return p_51;
}
static int * func_68(int ** p_69)
{
    unsigned l_95 = 0xF106BFD3L;
    int *l_107 = &g_25;
    int l_115 = 0x59CAFAA4L;
    unsigned char l_145 = 4UL;
    int l_470 = 0x2FED8070L;
    int *l_528 = (void*)0;
    step_hash(24);
    l_95 = (*g_76);
    step_hash(195);
    for (g_67 = 20; (g_67 <= 9); g_67--)
    {
        unsigned l_105 = 0x44AAF27CL;
        int *l_146 = &l_115;
        int l_182 = (-1L);
        int l_293 = (-10L);
        int l_329 = (-1L);
        int *l_370 = &g_25;
    }
    step_hash(282);
    if (((((int)(**p_69) - (int)((unsigned char)g_67 >> (unsigned char)7)) == 8L) != (*l_107)))
    {
        short l_388 = (-8L);
        unsigned char l_408 = 0x63L;
        int *l_419 = &l_115;
        unsigned l_457 = 0x84777FD0L;
        unsigned l_471 = 0x96AF753DL;
        unsigned l_481 = 0x24266508L;
        step_hash(197);
        (*p_69) = &l_115;
        step_hash(246);
        for (l_115 = 0; (l_115 <= 14); l_115++)
        {
            signed char l_407 = 0x18L;
            int **l_409 = &l_107;
        }
        step_hash(279);
        for (g_444 = (-16); (g_444 <= 0); g_444 += 4)
        {
            unsigned char l_465 = 250UL;
            int *l_472 = &g_156;
        }
    }
    else
    {
        int l_519 = 0x1A2AE1EEL;
        step_hash(281);
        (*l_107) = (((int)l_519 - (int)(((unsigned short)(((short)((unsigned short)((0L & g_349) ^ 0x93L) * (unsigned short)(*l_107)) + (short)((signed char)l_519 << (signed char)(g_67 & (-5L)))) ^ (*g_76)) >> (unsigned short)g_106) <= l_519)) && l_519);
    }
    step_hash(283);
    return l_528;
}
static int ** func_70(int p_71, unsigned p_72, short p_73, int ** p_74)
{
    int *l_77 = (void*)0;
    int l_78 = 0xA04BB84AL;
    int *l_83 = &g_25;
    unsigned short l_90 = 0xEC70L;
    int *l_93 = &l_78;
    int **l_94 = &l_93;
    step_hash(19);
    l_78 = (p_74 != &g_76);
    step_hash(20);
    (*l_83) = (g_25 == (p_73 != (g_25 == (p_72 <= p_71))));
    step_hash(21);
    (*l_93) ^= ((int)((int)(((((signed char)(p_74 != &l_77) * (signed char)((((((*g_75) != (*g_75)) != l_90) != ((*l_83) || (*g_76))) ^ g_11) <= (((unsigned char)(((**p_74) || p_71) == 5L) << (unsigned char)3) && (*l_83)))) ^ 0x61L) & 0x09C0D0DAL) > p_73) - (int)(*l_83)) / (int)(*g_76));
    step_hash(22);
    return p_74;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_11, "g_11", print_hash_value);
    transparent_crc(g_25, "g_25", print_hash_value);
    transparent_crc(g_67, "g_67", print_hash_value);
    transparent_crc(g_106, "g_106", print_hash_value);
    transparent_crc(g_156, "g_156", print_hash_value);
    transparent_crc(g_349, "g_349", print_hash_value);
    transparent_crc(g_444, "g_444", print_hash_value);
    transparent_crc(g_459, "g_459", print_hash_value);
    transparent_crc(g_498, "g_498", print_hash_value);
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
