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
static unsigned g_18 = 0xB5934215L;
static int g_41 = 0x04CD021AL;
static int g_80 = 0x123EBAA2L;
static short g_94 = 0L;
static int g_146 = 0xC6E3A6DCL;
static unsigned short g_149 = 65532UL;
static int g_167 = 0xAB27A36CL;
static int *g_196 = (void*)0;
static int **g_195 = &g_196;
static short g_221 = 0x9111L;
static unsigned char g_232 = 0UL;
static int g_318 = 0xDB17C0C1L;
static signed char g_324 = 1L;
static unsigned g_328 = 0x3DB9FBB9L;
static unsigned char g_370 = 0x71L;
static int g_486 = (-1L);
static int g_490 = (-8L);
static int g_495 = 0xA50CEE03L;
static unsigned g_560 = 0x6B8B8FC5L;
static signed char g_607 = 0x22L;
static int g_611 = (-1L);
static unsigned g_629 = 1UL;
static int g_729 = 1L;
static unsigned short g_877 = 0x5E3EL;
static unsigned short g_1086 = 0UL;
static int g_1223 = 0xD047683CL;
static unsigned g_1237 = 4294967292UL;
static int func_1(void);
static int func_2(unsigned short p_3, unsigned short p_4, signed char p_5, signed char p_6);
static unsigned short func_7(int p_8, unsigned short p_9);
static int func_10(unsigned short p_11, unsigned p_12, short p_13);
static short func_19(unsigned p_20, int p_21, unsigned p_22, int p_23, short p_24);
static signed char func_26(unsigned char p_27, unsigned p_28);
static unsigned char func_31(int p_32);
static unsigned char func_37(unsigned short p_38);
static signed char func_49(unsigned p_50, unsigned p_51, int p_52, unsigned short p_53, unsigned short p_54);
static unsigned func_58(unsigned char p_59);
static int func_1(void)
{
    unsigned l_25 = 0xB74C38B6L;
    int l_420 = 1L;
    unsigned short l_880 = 65535UL;
    int *l_1250 = &g_495;
    step_hash(307);
    (*l_1250) = func_2(func_7(func_10(((unsigned short)((short)g_18 % (short)func_19(l_25, ((func_26((((unsigned char)(((((((l_25 || func_31(g_18)) >= l_25) > ((unsigned short)((g_18 || g_221) > g_318) + (unsigned short)l_25)) < l_25) & g_221) || l_25) == g_18) / (unsigned char)l_25) && g_318), l_25) ^ l_420) > l_25), l_420, g_167, g_167)) - (unsigned short)l_420), g_324, l_25), g_167), l_420, l_880, l_25);
    step_hash(308);
    return g_167;
}
static int func_2(unsigned short p_3, unsigned short p_4, signed char p_5, signed char p_6)
{
    unsigned short l_949 = 65535UL;
    int *l_952 = &g_80;
    unsigned char l_966 = 0x68L;
    int l_1012 = 0x7F196D99L;
    int l_1081 = 0x534D0B4FL;
    int l_1196 = 0xBD8F0B1BL;
    int l_1214 = (-1L);
    int l_1219 = 0xAD8BA143L;
    int l_1227 = (-10L);
    int l_1233 = 0x060EC55AL;
    step_hash(304);
    if (((((g_729 != 4294967295UL) | ((short)p_3 << (short)3)) != (-3L)) >= 65534UL))
    {
        int *l_885 = (void*)0;
        int l_921 = 3L;
        int l_925 = 0x468D8FB6L;
        step_hash(243);
        for (g_149 = 0; (g_149 == 27); g_149++)
        {
            int *l_886 = &g_41;
            int *l_887 = &g_80;
            int *l_888 = &g_495;
            int *l_889 = &g_486;
            int *l_890 = &g_41;
            int l_891 = 1L;
            int *l_892 = (void*)0;
            int *l_893 = (void*)0;
            int *l_894 = &g_729;
            int *l_895 = (void*)0;
            int *l_896 = &g_41;
            int *l_897 = (void*)0;
            int l_898 = 5L;
            int *l_899 = &g_80;
            int *l_900 = &g_80;
            int *l_901 = &g_495;
            int *l_902 = &g_495;
            int *l_903 = &g_80;
            int *l_904 = (void*)0;
            int *l_905 = &g_486;
            int *l_906 = &g_729;
            int *l_907 = (void*)0;
            int *l_908 = (void*)0;
            int l_909 = 0xE66FB2EEL;
            int *l_910 = &l_891;
            int *l_911 = &g_486;
            int *l_912 = &l_909;
            int *l_913 = &g_729;
            int *l_914 = &g_41;
            int *l_915 = &l_891;
            int *l_916 = &l_898;
            int *l_917 = &g_495;
            int *l_918 = (void*)0;
            int *l_919 = &l_898;
            int *l_920 = &l_898;
            int *l_922 = &l_898;
            int *l_923 = &l_921;
            int l_924 = 0x37298482L;
            int *l_926 = &g_486;
            int *l_927 = &g_729;
            int *l_928 = (void*)0;
            int *l_929 = &g_729;
            int *l_930 = &g_41;
            int *l_931 = &l_898;
            int *l_932 = &l_924;
            int *l_933 = &g_80;
            int *l_934 = (void*)0;
            int *l_935 = &l_891;
            int *l_936 = &g_80;
            int *l_937 = (void*)0;
            int *l_938 = &l_924;
            int *l_939 = &l_898;
            int *l_940 = &g_495;
            int *l_941 = (void*)0;
            int *l_942 = &l_925;
            int *l_943 = &g_486;
            int *l_944 = &l_898;
            int *l_945 = &g_729;
            int *l_946 = &l_921;
            int *l_947 = (void*)0;
            int *l_948 = &g_486;
            step_hash(241);
            (*g_195) = l_885;
            step_hash(242);
            --l_949;
        }
        step_hash(244);
        l_952 = &l_925;
    }
    else
    {
        unsigned short l_965 = 0x33D4L;
        unsigned short l_969 = 0x1797L;
        int l_1031 = (-4L);
        unsigned char l_1116 = 255UL;
        int l_1150 = 1L;
        int l_1208 = 3L;
        int l_1212 = 0L;
        int *l_1247 = &l_1233;
        step_hash(281);
        if ((((signed char)((short)p_3 << (short)13) + (signed char)((l_966 && p_4) | g_167)) == (-1L)))
        {
            unsigned char l_1000 = 0xAAL;
            int *l_1003 = &g_80;
            int *l_1004 = &g_729;
            int *l_1005 = (void*)0;
            int *l_1006 = &g_486;
            int *l_1007 = &g_80;
            int *l_1008 = (void*)0;
            int *l_1009 = &g_80;
            int *l_1010 = &g_729;
            int *l_1011 = &g_80;
            int *l_1013 = (void*)0;
            int *l_1014 = &l_1012;
            int *l_1015 = &g_80;
            int *l_1016 = &g_495;
            int *l_1017 = &g_495;
            int *l_1018 = &g_486;
            int *l_1019 = &g_729;
            int *l_1020 = &l_1012;
            int *l_1021 = &g_729;
            int *l_1022 = &g_41;
            int *l_1023 = &g_80;
            int *l_1024 = &g_495;
            int l_1025 = 0x9DE32E2BL;
            int *l_1026 = &l_1025;
            int *l_1027 = &g_486;
            int *l_1028 = (void*)0;
            int *l_1029 = &g_486;
            int *l_1030 = &l_1025;
            int *l_1032 = &l_1025;
            int *l_1033 = &l_1012;
            int *l_1034 = &g_80;
            int *l_1035 = (void*)0;
            int *l_1036 = &l_1031;
            int *l_1037 = &l_1012;
            int *l_1038 = &l_1012;
            int *l_1039 = (void*)0;
            int *l_1040 = &g_495;
            int *l_1041 = (void*)0;
            int *l_1042 = &l_1031;
            int *l_1043 = &g_80;
            int *l_1044 = &l_1031;
            int *l_1045 = &l_1031;
            int *l_1046 = &g_80;
            int *l_1047 = &g_486;
            int *l_1048 = (void*)0;
            int *l_1049 = &l_1025;
            int *l_1050 = &l_1031;
            int *l_1051 = &l_1012;
            int *l_1052 = &l_1012;
            int *l_1053 = &g_729;
            int *l_1054 = &l_1012;
            int *l_1055 = &g_41;
            int *l_1056 = &g_729;
            int *l_1057 = &l_1012;
            int *l_1058 = &g_729;
            int *l_1059 = (void*)0;
            int *l_1060 = &g_80;
            int *l_1061 = (void*)0;
            int *l_1062 = &l_1025;
            int *l_1063 = &g_41;
            int *l_1064 = (void*)0;
            int *l_1065 = &l_1031;
            int *l_1066 = (void*)0;
            int *l_1067 = &g_729;
            int *l_1068 = &l_1012;
            int *l_1069 = (void*)0;
            int *l_1070 = &g_486;
            int l_1071 = (-3L);
            int *l_1072 = &l_1071;
            int *l_1073 = (void*)0;
            int *l_1074 = &l_1071;
            int *l_1075 = (void*)0;
            int l_1076 = (-1L);
            int *l_1077 = &g_41;
            int l_1078 = 0L;
            int *l_1079 = &g_41;
            int *l_1080 = &g_495;
            int *l_1082 = &g_41;
            int *l_1083 = (void*)0;
            int *l_1084 = &g_729;
            int *l_1085 = &g_495;
            step_hash(252);
            for (p_4 = (-5); (p_4 == 2); p_4 += 7)
            {
                int *l_972 = &g_729;
                int *l_973 = &g_41;
                int *l_974 = &g_80;
                int *l_975 = &g_80;
                int *l_976 = &g_486;
                int *l_977 = (void*)0;
                int *l_978 = &g_486;
                int *l_979 = &g_80;
                int *l_980 = &g_729;
                int *l_981 = &g_41;
                int *l_982 = &g_80;
                int *l_983 = &g_495;
                int *l_984 = &g_729;
                int *l_985 = &g_41;
                int *l_986 = (void*)0;
                int *l_987 = (void*)0;
                int *l_988 = &g_486;
                int l_989 = 0xED973582L;
                int *l_990 = (void*)0;
                int *l_991 = &g_41;
                int *l_992 = &g_729;
                int l_993 = 0x29844B3BL;
                int *l_994 = &g_486;
                int *l_995 = &l_989;
                int *l_996 = &g_495;
                int *l_997 = &g_486;
                int *l_998 = &l_993;
                int *l_999 = &g_486;
                step_hash(250);
                l_969--;
                step_hash(251);
                ++l_1000;
            }
            step_hash(253);
            g_1086--;
        }
        else
        {
            int ***l_1095 = &g_195;
            step_hash(274);
            if ((!(+((unsigned short)(((((int)((signed char)(&g_195 != l_1095) << (signed char)g_729) / (int)((unsigned)((unsigned)(((signed char)g_94 * (signed char)p_5) >= (*l_952)) + (unsigned)p_3) - (unsigned)func_26((*l_952), ((void*)0 == &l_1031)))) && p_6) || l_1031) ^ p_3) - (unsigned short)g_1086))))
            {
                short l_1106 = 0xC628L;
                unsigned short l_1119 = 9UL;
                step_hash(271);
                for (l_1012 = 0; (l_1012 >= (-6)); l_1012--)
                {
                    unsigned short l_1107 = 0x9C79L;
                    unsigned l_1114 = 1UL;
                    int l_1115 = (-1L);
                    step_hash(265);
                    for (p_3 = 0; (p_3 <= 35); p_3 += 3)
                    {
                        step_hash(262);
                        l_1107++;
                        step_hash(263);
                        if (p_3)
                            continue;
                        step_hash(264);
                        l_1115 |= ((signed char)((short)l_1114 >> (short)4) >> (signed char)3);
                    }
                    step_hash(270);
                    if ((g_221 ^ func_19(((p_6 > 5UL) && ((l_1116 <= (*l_952)) | ((short)p_6 * (short)((void*)0 != &g_195)))), ((l_1106 != p_5) <= p_5), g_729, l_1114, p_6)))
                    {
                        step_hash(267);
                        return l_1115;
                    }
                    else
                    {
                        step_hash(269);
                        return l_1119;
                    }
                }
            }
            else
            {
                step_hash(273);
                return p_3;
            }
            step_hash(275);
            (*g_195) = &l_1031;
            step_hash(280);
            for (g_146 = 8; (g_146 < (-12)); g_146--)
            {
                step_hash(279);
                if ((**g_195))
                    break;
            }
        }
        step_hash(294);
        if (func_26((*l_952), p_5))
        {
            step_hash(283);
            (*l_952) = p_3;
        }
        else
        {
            int *l_1122 = &g_41;
            int *l_1123 = &l_1012;
            int *l_1124 = &g_41;
            int *l_1125 = &l_1031;
            int *l_1126 = &l_1081;
            int *l_1127 = &l_1081;
            int *l_1128 = (void*)0;
            int *l_1129 = &l_1012;
            int *l_1130 = &l_1012;
            int *l_1131 = &l_1081;
            int *l_1132 = &g_729;
            int *l_1133 = &g_80;
            int *l_1134 = &l_1081;
            int *l_1135 = (void*)0;
            int *l_1136 = &g_495;
            int *l_1137 = &g_41;
            int *l_1138 = &l_1081;
            int *l_1139 = &l_1031;
            int *l_1140 = (void*)0;
            int *l_1141 = (void*)0;
            int *l_1142 = &l_1081;
            int *l_1143 = &g_486;
            int *l_1144 = &l_1081;
            int *l_1145 = &g_41;
            int *l_1146 = &g_486;
            int *l_1147 = &g_80;
            int *l_1148 = &g_495;
            int *l_1149 = &g_486;
            int *l_1151 = &l_1031;
            int *l_1152 = &l_1012;
            int *l_1153 = (void*)0;
            int *l_1154 = &g_41;
            int *l_1155 = &g_729;
            int *l_1156 = (void*)0;
            int *l_1157 = &g_729;
            int *l_1158 = &g_729;
            int *l_1159 = &l_1031;
            int *l_1160 = &g_495;
            int *l_1161 = &l_1081;
            int *l_1162 = &g_486;
            int *l_1163 = &l_1031;
            int *l_1164 = &g_495;
            int *l_1165 = &g_495;
            int *l_1166 = &l_1081;
            int *l_1167 = &l_1031;
            int *l_1168 = &l_1031;
            int *l_1169 = (void*)0;
            int *l_1170 = &g_41;
            int *l_1171 = &g_41;
            int *l_1172 = &l_1150;
            int *l_1173 = &g_486;
            int *l_1174 = &l_1081;
            int *l_1175 = &l_1031;
            int *l_1176 = &l_1012;
            int *l_1177 = (void*)0;
            int *l_1178 = &l_1031;
            int *l_1179 = &l_1031;
            int *l_1180 = (void*)0;
            int *l_1181 = &l_1031;
            int *l_1182 = &g_495;
            int *l_1183 = &l_1081;
            int *l_1184 = &l_1150;
            int *l_1185 = &g_495;
            int *l_1186 = &l_1012;
            int *l_1187 = &g_729;
            int *l_1188 = &g_80;
            int *l_1189 = &l_1081;
            int *l_1190 = (void*)0;
            int *l_1191 = (void*)0;
            int *l_1192 = &l_1012;
            int *l_1193 = &l_1081;
            int *l_1194 = &l_1031;
            int *l_1195 = &g_495;
            int *l_1197 = &l_1150;
            int *l_1198 = (void*)0;
            int *l_1199 = &g_729;
            int *l_1200 = (void*)0;
            int *l_1201 = (void*)0;
            int *l_1202 = &g_729;
            int *l_1203 = &l_1012;
            int *l_1204 = &l_1196;
            int *l_1205 = &l_1081;
            int *l_1206 = &g_729;
            int *l_1207 = &g_486;
            int *l_1209 = &g_729;
            int *l_1210 = &l_1150;
            int *l_1211 = (void*)0;
            int *l_1213 = &l_1081;
            int *l_1215 = &l_1150;
            int l_1216 = (-5L);
            int *l_1217 = &l_1196;
            int *l_1218 = &g_495;
            int *l_1220 = &g_486;
            int *l_1221 = &g_729;
            int *l_1222 = &l_1219;
            int *l_1224 = &l_1208;
            int *l_1225 = (void*)0;
            int *l_1226 = (void*)0;
            int l_1228 = 0x27B19BAEL;
            int *l_1229 = &l_1212;
            int *l_1230 = &l_1081;
            int *l_1231 = (void*)0;
            int *l_1232 = &l_1081;
            int *l_1234 = &l_1031;
            int *l_1235 = &g_1223;
            int *l_1236 = &l_1196;
            step_hash(285);
            ++g_1237;
            step_hash(286);
            (*l_1172) = (&l_1134 == &g_196);
            step_hash(292);
            for (l_1196 = 5; (l_1196 > 3); l_1196 -= 8)
            {
                step_hash(290);
                if (p_5)
                    break;
                step_hash(291);
                (*l_1165) |= ((unsigned short)(*l_952) % (unsigned short)(p_5 | func_26(g_232, g_1223)));
            }
            step_hash(293);
            (*l_1133) = 9L;
        }
        step_hash(302);
        for (g_486 = 0; (g_486 >= 20); g_486 += 9)
        {
            unsigned l_1246 = 0x13D87127L;
            step_hash(298);
            (*g_195) = &l_1214;
            step_hash(299);
            (*g_195) = (*g_195);
            step_hash(300);
            (*l_952) = l_1246;
            step_hash(301);
            if ((**g_195))
                continue;
        }
        step_hash(303);
        (*l_1247) |= (*l_952);
    }
    step_hash(305);
    g_495 |= ((short)l_1219 / (short)g_729);
    step_hash(306);
    return l_1081;
}
static unsigned short func_7(int p_8, unsigned short p_9)
{
    unsigned char l_685 = 0UL;
    int *l_686 = &g_80;
    unsigned short l_707 = 0x7B14L;
    step_hash(179);
    (*l_686) |= (l_685 <= 0x4D46L);
    step_hash(233);
    for (g_370 = (-13); (g_370 < 53); ++g_370)
    {
        unsigned l_698 = 0xCD548416L;
        int **l_722 = &g_196;
        int l_752 = (-6L);
        unsigned l_787 = 9UL;
        unsigned l_803 = 4294967295UL;
        int l_804 = 0xB39E4F21L;
        int l_848 = 8L;
        int l_850 = 0xC45FE556L;
        int l_854 = 1L;
        int l_857 = 0x34626FBBL;
        step_hash(193);
        for (g_146 = 14; (g_146 > 29); g_146 += 1)
        {
            int ***l_691 = &g_195;
            step_hash(191);
            if (((((void*)0 != &g_196) > (((void*)0 == l_691) ^ ((int)((short)(((~p_8) ^ (((signed char)((void*)0 != l_691) % (signed char)func_19((p_9 || (func_58(p_8) == 1UL)), g_232, p_9, g_18, g_18)) < l_698)) ^ g_495) >> (short)4) % (int)l_698))) != 9L))
            {
                int *l_699 = (void*)0;
                int *l_700 = (void*)0;
                int *l_701 = (void*)0;
                int *l_702 = &g_495;
                int *l_703 = &g_495;
                int *l_704 = &g_41;
                int *l_705 = (void*)0;
                int *l_706 = (void*)0;
                step_hash(187);
                l_707++;
                step_hash(188);
                (*l_686) = ((unsigned short)p_8 >> (unsigned short)5);
            }
            else
            {
                step_hash(190);
                (**l_691) = &p_8;
            }
            step_hash(192);
            return p_8;
        }
        step_hash(232);
        if (((short)(((unsigned)(((signed char)p_8 / (signed char)p_8) == (&l_686 == &l_686)) % (unsigned)((unsigned short)(((((signed char)p_8 >> (signed char)5) && ((&g_196 != l_722) == ((unsigned char)p_8 * (unsigned char)((unsigned short)((unsigned char)(p_9 ^ (*l_686)) << (unsigned char)g_729) >> (unsigned short)2)))) || 3UL) >= 1UL) * (unsigned short)(*l_686))) != g_560) / (short)g_490))
        {
            int **l_730 = &l_686;
            int ***l_731 = &l_722;
            step_hash(195);
            if (p_8)
                break;
            step_hash(196);
            (*g_195) = &p_8;
            step_hash(197);
            (*l_731) = l_730;
            step_hash(198);
            (**l_730) = (**g_195);
        }
        else
        {
            unsigned short l_760 = 0UL;
            int ***l_816 = &l_722;
            signed char l_819 = 5L;
            int l_849 = 0xD4B72E8FL;
            step_hash(200);
            (*l_686) &= 9L;
            step_hash(230);
            if ((!(-9L)))
            {
                int l_738 = 0x0AEAE064L;
                step_hash(217);
                if (((int)((short)g_486 * (short)(((*l_686) >= (func_19(l_738, g_318, p_9, g_221, g_729) || (&l_722 == &l_722))) ^ p_8)) - (int)4294967288UL))
                {
                    unsigned l_751 = 0UL;
                    int *l_753 = &g_495;
                    step_hash(203);
                    if (p_8)
                        break;
                    step_hash(204);
                    l_752 |= (((signed char)((unsigned)((0xC9FC870BL >= (p_8 & ((short)(((((unsigned)4294967295UL - (unsigned)(~p_9)) <= ((unsigned char)(g_495 | ((~g_94) > ((signed char)(g_370 && 4UL) % (signed char)p_8))) * (unsigned char)(-1L))) || (-1L)) && (*l_686)) >> (short)g_318))) ^ (*l_686)) - (unsigned)1UL) - (signed char)0x26L) & l_751);
                    step_hash(205);
                    (*g_195) = l_753;
                }
                else
                {
                    int *l_763 = &g_41;
                    int *l_764 = (void*)0;
                    int *l_765 = &g_729;
                    int *l_766 = &g_729;
                    int *l_767 = &g_729;
                    int *l_768 = &g_41;
                    int *l_769 = (void*)0;
                    int *l_770 = &g_495;
                    int *l_771 = &g_41;
                    int *l_772 = &l_752;
                    int *l_773 = &g_729;
                    int *l_774 = (void*)0;
                    int *l_775 = &l_752;
                    int *l_776 = &g_41;
                    int *l_777 = (void*)0;
                    int *l_778 = &l_752;
                    int *l_779 = &l_752;
                    int *l_780 = &l_752;
                    int *l_781 = &g_486;
                    int *l_782 = &g_486;
                    int *l_783 = &l_752;
                    int *l_784 = &g_729;
                    int *l_785 = &g_41;
                    int *l_786 = (void*)0;
                    step_hash(207);
                    (*l_686) = 0x8AF709B0L;
                    step_hash(214);
                    for (p_9 = 0; (p_9 <= 55); p_9++)
                    {
                        int *l_756 = &g_729;
                        int *l_757 = &g_80;
                        int *l_758 = &g_486;
                        int *l_759 = &g_486;
                        step_hash(211);
                        l_760--;
                        step_hash(212);
                        if (l_760)
                            break;
                        step_hash(213);
                        (*l_686) = 1L;
                    }
                    step_hash(215);
                    ++l_787;
                    step_hash(216);
                    (*l_686) = (((signed char)0x70L * (signed char)(0xABAA88EEL <= 0xF1821C2EL)) ^ l_760);
                }
            }
            else
            {
                signed char l_794 = 9L;
                unsigned l_810 = 1UL;
                int l_817 = (-1L);
                int *l_818 = &g_41;
                int *l_820 = &g_495;
                int *l_821 = &g_486;
                int *l_822 = &l_817;
                int *l_823 = &g_486;
                int *l_824 = &l_817;
                int *l_825 = &l_752;
                int *l_826 = &g_41;
                int *l_827 = &g_495;
                int *l_828 = &l_752;
                int *l_829 = &g_486;
                int *l_830 = (void*)0;
                int *l_831 = &l_752;
                int *l_832 = &g_80;
                int *l_833 = &g_80;
                int *l_834 = &g_486;
                int *l_835 = &g_80;
                int *l_836 = &g_729;
                int l_837 = 0L;
                int *l_838 = &g_41;
                int *l_839 = (void*)0;
                int *l_840 = (void*)0;
                int *l_841 = (void*)0;
                int *l_842 = &g_495;
                int *l_843 = &l_837;
                int *l_844 = &g_41;
                int *l_845 = &l_837;
                int *l_846 = &l_817;
                int *l_847 = &g_729;
                int *l_851 = &l_752;
                int *l_852 = &l_850;
                int *l_853 = &l_837;
                int *l_855 = (void*)0;
                int *l_856 = &g_495;
                int *l_858 = &l_817;
                int *l_859 = &g_41;
                int *l_860 = &g_80;
                int *l_861 = &l_854;
                int *l_862 = (void*)0;
                int *l_863 = &l_849;
                int *l_864 = &l_850;
                int *l_865 = &l_752;
                int *l_866 = (void*)0;
                int *l_867 = &g_80;
                int *l_868 = (void*)0;
                int *l_869 = &g_41;
                int *l_870 = &g_41;
                int *l_871 = &g_729;
                int *l_872 = &l_837;
                int *l_873 = &l_857;
                int *l_874 = &l_850;
                int *l_875 = &g_495;
                int *l_876 = &l_848;
                step_hash(228);
                if (((int)(0UL || (p_9 && (l_794 | (+((((unsigned short)(((int)p_9 % (int)p_9) <= func_58(((unsigned)g_611 + (unsigned)p_8))) % (unsigned short)((short)g_729 / (short)g_324)) & l_803) < l_804))))) + (int)g_328))
                {
                    int l_809 = (-8L);
                    int *l_811 = &l_752;
                    step_hash(220);
                    (*l_811) &= ((signed char)(g_80 && ((int)(func_19((p_8 == func_19(p_8, p_9, p_8, p_9, (0xEA905F1CL & l_809))), g_490, g_560, l_810, p_9) ^ l_810) + (int)p_9)) / (signed char)g_18);
                    step_hash(221);
                    (*l_811) = g_370;
                }
                else
                {
                    step_hash(227);
                    if (((short)0L << (short)(g_629 && ((short)(l_816 == (void*)0) * (short)0x6388L))))
                    {
                        step_hash(224);
                        if (p_8)
                            break;
                    }
                    else
                    {
                        step_hash(226);
                        return g_324;
                    }
                }
                step_hash(229);
                g_877--;
            }
            step_hash(231);
            if (p_8)
                continue;
        }
    }
    step_hash(234);
    (*g_195) = &p_8;
    step_hash(235);
    return g_80;
}
static int func_10(unsigned short p_11, unsigned p_12, short p_13)
{
    int *l_423 = &g_41;
    int l_595 = 0xC2DE7882L;
    signed char l_610 = 0xD8L;
    int l_621 = (-1L);
    unsigned short l_684 = 1UL;
    step_hash(124);
    (*l_423) = p_12;
    step_hash(129);
    for (g_318 = (-17); (g_318 >= 26); ++g_318)
    {
        step_hash(128);
        (*l_423) = 0x9F95F825L;
    }
    step_hash(176);
    if (g_94)
    {
        signed char l_430 = 0xB7L;
        int ***l_443 = &g_195;
        unsigned short l_448 = 0xAA6FL;
        int l_466 = 0xA7C000D3L;
        int l_531 = 0xBC0E26F0L;
        step_hash(131);
        (*l_423) = p_13;
        step_hash(163);
        for (p_11 = 0; (p_11 == 32); p_11++)
        {
            int *l_431 = (void*)0;
            int l_457 = 0x2E2D7C1BL;
            step_hash(139);
            for (g_149 = 0; (g_149 == 16); g_149 += 5)
            {
                step_hash(138);
                return l_430;
            }
            step_hash(140);
            (*g_195) = l_431;
            step_hash(162);
            if (p_11)
            {
                signed char l_445 = 0x32L;
                int l_451 = 0x095FD899L;
                unsigned l_500 = 1UL;
                step_hash(150);
                for (p_13 = 0; (p_13 == (-23)); p_13 -= 8)
                {
                    unsigned l_442 = 0x24AF7A4CL;
                    step_hash(149);
                    for (g_149 = 0; (g_149 == 20); g_149++)
                    {
                        int l_444 = 0xCA409319L;
                        step_hash(148);
                        (*l_423) = (((unsigned char)((unsigned char)p_13 >> (unsigned char)((l_442 >= (*l_423)) >= ((void*)0 != l_443))) - (unsigned char)((((func_49(func_49(g_94, (*l_423), ((g_232 > (((l_444 && 4294967295UL) & l_444) > p_13)) | p_11), p_13, g_328), p_13, p_11, g_146, p_12) > 0xA325L) || p_12) == p_13) > g_318)) | l_445);
                    }
                }
                step_hash(158);
                for (g_318 = 24; (g_318 <= (-12)); g_318 -= 2)
                {
                    int *l_449 = &g_41;
                    int *l_450 = &g_41;
                    int *l_452 = &l_451;
                    int *l_453 = &l_451;
                    int *l_454 = &l_451;
                    int *l_455 = &l_451;
                    int *l_456 = &g_41;
                    int *l_458 = &g_80;
                    int *l_459 = &g_80;
                    int *l_460 = &g_80;
                    int *l_461 = &g_41;
                    int *l_462 = &l_451;
                    int *l_463 = &g_80;
                    int *l_464 = (void*)0;
                    int *l_465 = &g_80;
                    int *l_467 = &g_80;
                    int *l_468 = &g_80;
                    int *l_469 = &l_451;
                    int *l_470 = &l_466;
                    int *l_471 = &g_41;
                    int *l_472 = &l_451;
                    int *l_473 = (void*)0;
                    int *l_474 = &g_80;
                    int *l_475 = &l_457;
                    int *l_476 = &l_457;
                    int *l_477 = &l_457;
                    int *l_478 = &g_80;
                    int *l_479 = (void*)0;
                    int *l_480 = &l_451;
                    int *l_481 = &g_41;
                    int *l_482 = &l_466;
                    int *l_483 = &g_41;
                    int *l_484 = &g_80;
                    int *l_485 = &g_80;
                    int *l_487 = (void*)0;
                    int *l_488 = &g_41;
                    int *l_489 = &l_466;
                    int *l_491 = &l_457;
                    int *l_492 = &l_466;
                    int *l_493 = &g_486;
                    int *l_494 = &l_466;
                    int *l_496 = &l_466;
                    int *l_497 = (void*)0;
                    int *l_498 = (void*)0;
                    int *l_499 = &g_41;
                    step_hash(154);
                    l_448 &= (*l_423);
                    step_hash(155);
                    l_500--;
                }
            }
            else
            {
                signed char l_505 = 0L;
                int *l_506 = &l_457;
                int *l_507 = &l_466;
                int *l_508 = &g_41;
                int *l_509 = (void*)0;
                int *l_510 = &l_457;
                int *l_511 = &g_486;
                int *l_512 = &g_41;
                int *l_513 = &g_486;
                int l_514 = 0x7C74476EL;
                int *l_515 = &l_514;
                int *l_516 = &g_495;
                int *l_517 = (void*)0;
                int *l_518 = (void*)0;
                int l_519 = (-1L);
                int *l_520 = &l_457;
                int *l_521 = &l_466;
                int *l_522 = &g_80;
                int *l_523 = &g_80;
                int *l_524 = (void*)0;
                int *l_525 = &l_514;
                int *l_526 = &l_514;
                int *l_527 = (void*)0;
                int *l_528 = (void*)0;
                int *l_529 = &l_457;
                int l_530 = 0xCB991EF0L;
                int *l_532 = &g_486;
                int *l_533 = &l_519;
                int *l_534 = &l_457;
                int *l_535 = (void*)0;
                int *l_536 = (void*)0;
                int *l_537 = (void*)0;
                int *l_538 = &l_530;
                int *l_539 = &g_486;
                int *l_540 = (void*)0;
                int *l_541 = &g_41;
                int *l_542 = &g_80;
                int *l_543 = &g_495;
                int *l_544 = (void*)0;
                int *l_545 = &g_80;
                int *l_546 = &l_530;
                int *l_547 = &l_457;
                int *l_548 = &l_531;
                int *l_549 = &l_519;
                int *l_550 = &l_530;
                int *l_551 = &l_519;
                int *l_552 = &l_457;
                int *l_553 = (void*)0;
                int *l_554 = &l_530;
                int *l_555 = &g_486;
                int *l_556 = &l_457;
                int *l_557 = &g_80;
                int *l_558 = (void*)0;
                int *l_559 = &g_486;
                step_hash(160);
                --g_560;
                step_hash(161);
                (*g_195) = l_423;
            }
        }
    }
    else
    {
        unsigned short l_566 = 65530UL;
        int l_575 = (-1L);
        int *l_632 = (void*)0;
        int *l_633 = &g_486;
        int *l_634 = &l_595;
        int *l_635 = &g_41;
        int *l_636 = &l_575;
        int *l_637 = &g_486;
        int *l_638 = &g_486;
        int *l_639 = &l_575;
        int *l_640 = &g_495;
        int *l_641 = &g_495;
        int *l_642 = &g_80;
        int *l_643 = &l_621;
        int *l_644 = &g_80;
        int *l_645 = &l_575;
        int *l_646 = &g_41;
        int *l_647 = &l_621;
        int *l_648 = (void*)0;
        int *l_649 = &g_495;
        int *l_650 = (void*)0;
        int *l_651 = &g_495;
        int *l_652 = &g_80;
        int *l_653 = &g_41;
        int *l_654 = &g_486;
        int *l_655 = &g_495;
        int *l_656 = &l_595;
        int *l_657 = (void*)0;
        int *l_658 = &g_486;
        int *l_659 = (void*)0;
        int *l_660 = &g_41;
        int *l_661 = &g_41;
        int *l_662 = &l_595;
        int l_663 = 0L;
        int *l_664 = &g_486;
        int *l_665 = &g_495;
        int *l_666 = &l_595;
        int *l_667 = &l_595;
        int l_668 = (-7L);
        int *l_669 = &g_495;
        int *l_670 = &l_621;
        int *l_671 = &l_595;
        int *l_672 = &l_575;
        int *l_673 = &l_621;
        int *l_674 = &l_663;
        int *l_675 = &l_668;
        int *l_676 = &g_80;
        int *l_677 = (void*)0;
        int *l_678 = &l_663;
        unsigned short l_679 = 1UL;
        step_hash(172);
        for (g_146 = 0; (g_146 > (-25)); g_146 -= 3)
        {
            int *l_565 = (void*)0;
            int *l_576 = &g_80;
            int *l_577 = &g_41;
            int *l_578 = &g_80;
            int *l_579 = &g_495;
            int l_580 = 1L;
            int *l_581 = &l_580;
            int l_582 = 7L;
            int *l_583 = &g_80;
            int *l_584 = &l_580;
            int *l_585 = &g_495;
            int l_586 = 8L;
            int *l_587 = &g_486;
            int *l_588 = &g_41;
            int l_589 = (-2L);
            int *l_590 = (void*)0;
            int l_591 = 0x32A05A1AL;
            int *l_592 = &l_582;
            int *l_593 = &l_575;
            int *l_594 = &l_591;
            int *l_596 = &l_580;
            int *l_597 = &g_486;
            int *l_598 = &g_41;
            int *l_599 = &l_589;
            int *l_600 = &g_41;
            int *l_601 = &l_580;
            int *l_602 = &l_580;
            int *l_603 = (void*)0;
            int *l_604 = &l_580;
            int l_605 = 0x1F4DC901L;
            int *l_606 = &g_486;
            int *l_608 = &l_582;
            int *l_609 = &l_605;
            int *l_612 = &l_605;
            int *l_613 = &l_586;
            int *l_614 = &l_586;
            int *l_615 = &l_580;
            int *l_616 = &g_486;
            int *l_617 = &l_586;
            int *l_618 = &l_582;
            int *l_619 = &l_575;
            int *l_620 = &l_605;
            int *l_622 = (void*)0;
            int l_623 = 0x4C25B71DL;
            int *l_624 = &g_41;
            int *l_625 = &g_486;
            int *l_626 = &g_80;
            int *l_627 = &l_589;
            int *l_628 = (void*)0;
            step_hash(168);
            (*g_195) = l_565;
            step_hash(169);
            l_575 = ((~(func_58(l_566) ^ p_13)) && ((short)func_26((((void*)0 == l_423) ^ (g_486 < ((unsigned short)p_13 + (unsigned short)(p_11 <= (((signed char)((unsigned char)l_566 >> (unsigned char)g_221) >> (signed char)(*l_423)) ^ g_560))))), g_324) % (short)p_12));
            step_hash(170);
            --g_629;
            step_hash(171);
            if (p_11)
                break;
        }
        step_hash(173);
        --l_679;
        step_hash(174);
        (*l_635) ^= ((short)((g_495 < p_11) == l_684) / (short)65535UL);
        step_hash(175);
        (*g_195) = &l_595;
    }
    step_hash(177);
    return (*l_423);
}
static short func_19(unsigned p_20, int p_21, unsigned p_22, int p_23, short p_24)
{
    int l_421 = (-9L);
    int *l_422 = &g_41;
    step_hash(121);
    (*l_422) = g_80;
    step_hash(122);
    return (*l_422);
}
static signed char func_26(unsigned char p_27, unsigned p_28)
{
    int *l_385 = &g_41;
    int *l_386 = &g_80;
    int *l_387 = &g_80;
    int l_388 = 2L;
    int *l_389 = &l_388;
    int *l_390 = (void*)0;
    int l_391 = 0xDC86E61BL;
    int *l_392 = (void*)0;
    int *l_393 = (void*)0;
    int *l_394 = &g_80;
    int *l_395 = (void*)0;
    int l_396 = 1L;
    int *l_397 = &l_391;
    int *l_398 = &l_396;
    int *l_399 = &g_80;
    int *l_400 = &l_391;
    int *l_401 = &l_388;
    int *l_402 = &g_41;
    int l_403 = 0xBD49ADAAL;
    int l_404 = 0x51E0D0E8L;
    int *l_405 = &l_388;
    int *l_406 = &g_41;
    int *l_407 = &l_404;
    int *l_408 = &l_404;
    int *l_409 = &g_80;
    int *l_410 = &l_403;
    int *l_411 = (void*)0;
    int *l_412 = (void*)0;
    int *l_413 = &l_404;
    int *l_414 = &l_404;
    int l_415 = (-7L);
    int l_416 = 0L;
    unsigned char l_417 = 0xF7L;
    step_hash(118);
    --l_417;
    step_hash(119);
    return g_318;
}
static unsigned char func_31(int p_32)
{
    unsigned l_340 = 0x974D9EF0L;
    int l_345 = 0xB4D028B1L;
    unsigned char l_373 = 0xC1L;
    int **l_377 = &g_196;
    int ***l_382 = &l_377;
    step_hash(108);
    if (((signed char)((((short)p_32 >> (short)(g_18 < func_37(g_18))) & (g_221 > 0x89A3L)) != ((g_167 != ((((unsigned short)g_146 - (unsigned short)l_340) != 0xE7EE258AL) != g_167)) && 0x39L)) >> (signed char)2))
    {
        int *l_341 = &g_80;
        int *l_342 = &g_80;
        int *l_343 = (void*)0;
        int *l_344 = (void*)0;
        int *l_346 = &g_80;
        int *l_347 = &g_80;
        int *l_348 = &g_41;
        int *l_349 = &l_345;
        int *l_350 = (void*)0;
        int *l_351 = &g_41;
        int *l_352 = &l_345;
        int *l_353 = &g_41;
        int *l_354 = &g_41;
        int *l_355 = &g_80;
        int l_356 = 0x6801FEF5L;
        int *l_357 = &l_345;
        int *l_358 = &g_80;
        int *l_359 = &g_80;
        int *l_360 = (void*)0;
        int *l_361 = &g_41;
        int *l_362 = (void*)0;
        int *l_363 = &l_345;
        int *l_364 = &g_41;
        int *l_365 = &g_80;
        int *l_366 = (void*)0;
        int *l_367 = &g_41;
        int *l_368 = &l_345;
        int *l_369 = &g_41;
        step_hash(101);
        g_370--;
        step_hash(102);
        ++l_373;
        step_hash(103);
        (*g_195) = &g_80;
    }
    else
    {
        int **l_376 = &g_196;
        int *l_378 = &g_80;
        step_hash(105);
        (*l_378) ^= ((l_376 != l_377) | p_32);
        step_hash(106);
        (*l_377) = &l_345;
        step_hash(107);
        (*l_377) = (*g_195);
    }
    step_hash(114);
    for (g_146 = 14; (g_146 >= 12); --g_146)
    {
        unsigned l_381 = 0x0E3E12D5L;
        step_hash(112);
        (*g_195) = (*g_195);
        step_hash(113);
        if (l_381)
            continue;
    }
    step_hash(115);
    (*l_382) = l_377;
    step_hash(116);
    return p_32;
}
static unsigned char func_37(unsigned short p_38)
{
    int l_238 = 0xFEDCC949L;
    int **l_281 = &g_196;
    unsigned short l_284 = 0UL;
    int *l_285 = &l_238;
    step_hash(81);
    for (p_38 = 0; (p_38 <= 30); p_38++)
    {
        signed char l_44 = (-3L);
        int l_235 = (-10L);
        step_hash(79);
        for (g_41 = 8; (g_41 <= (-5)); g_41 -= 8)
        {
            unsigned l_55 = 0xD08E1597L;
            unsigned l_239 = 4294967295UL;
            int **l_260 = &g_196;
            int l_273 = (-1L);
            step_hash(65);
            if (((l_44 > ((unsigned)(((signed char)(0x13L == func_49(l_55, ((unsigned char)(p_38 > func_58(p_38)) + (unsigned char)g_167), (0x4E54L && g_18), p_38, g_146)) / (signed char)p_38) < g_41) % (unsigned)4294967289UL)) && p_38))
            {
                int *l_236 = &g_80;
                int *l_237 = &l_235;
                step_hash(57);
                l_239++;
                step_hash(62);
                for (l_44 = (-6); (l_44 < 19); l_44 += 1)
                {
                    step_hash(61);
                    return p_38;
                }
            }
            else
            {
                step_hash(64);
                return p_38;
            }
            step_hash(66);
            g_80 = l_239;
            step_hash(77);
            if (((short)l_44 + (short)func_49(p_38, l_44, ((short)(func_49(l_238, p_38, ((func_58(func_49(((*g_195) != (void*)0), p_38, p_38, p_38, g_149)) | (-1L)) >= l_55), l_235, g_221) & 1L) << (short)l_55), l_55, p_38)))
            {
                unsigned l_258 = 0x0E433B6EL;
                int *l_259 = &g_80;
                step_hash(68);
                (*l_259) = ((unsigned short)(0xB4B6L <= (l_55 == ((unsigned short)g_41 << (unsigned short)((unsigned short)(g_149 && ((signed char)p_38 % (signed char)l_55)) / (unsigned short)(func_49(((unsigned char)((p_38 >= ((-1L) & l_238)) <= p_38) + (unsigned char)p_38), l_258, p_38, l_238, l_235) && 1UL))))) >> (unsigned short)g_41);
                step_hash(69);
                (*g_195) = &l_238;
            }
            else
            {
                unsigned short l_271 = 0x2BA5L;
                step_hash(76);
                if ((((void*)0 == l_260) <= g_149))
                {
                    int *l_272 = (void*)0;
                    int l_274 = (-1L);
                    step_hash(72);
                    l_273 &= ((unsigned)(g_167 && ((unsigned)0x56CD8495L / (unsigned)((unsigned char)((unsigned char)((unsigned char)((p_38 ^ (func_58(p_38) >= (&g_196 == &g_196))) != 1UL) - (unsigned char)((void*)0 == (*l_260))) + (unsigned char)p_38) + (unsigned char)l_271))) - (unsigned)p_38);
                    step_hash(73);
                    l_274 = p_38;
                }
                else
                {
                    step_hash(75);
                    if (p_38)
                        break;
                }
            }
            step_hash(78);
            return l_238;
        }
        step_hash(80);
        if (p_38)
            break;
    }
    step_hash(82);
    (*l_285) = ((short)func_58(l_238) - (short)(((unsigned short)(&l_238 != (void*)0) / (unsigned short)p_38) <= (((signed char)l_238 / (signed char)(((l_281 != &g_196) >= ((unsigned)((g_18 && 65535UL) || 0x7A35014FL) % (unsigned)l_284)) & g_146)) | p_38)));
    step_hash(97);
    for (l_284 = 0; (l_284 <= 42); l_284 += 8)
    {
        unsigned short l_288 = 0UL;
        int *l_291 = (void*)0;
        int *l_292 = &l_238;
        int *l_293 = (void*)0;
        int *l_294 = &g_41;
        int *l_295 = &g_80;
        int *l_296 = &g_80;
        int *l_297 = &g_41;
        int *l_298 = &g_41;
        int *l_299 = &g_80;
        int *l_300 = &g_80;
        int *l_301 = &g_41;
        int *l_302 = &g_80;
        int *l_303 = &g_41;
        int *l_304 = &g_80;
        int *l_305 = &g_41;
        int *l_306 = &g_80;
        int *l_307 = &l_238;
        int *l_308 = &l_238;
        int *l_309 = (void*)0;
        int *l_310 = &l_238;
        int *l_311 = &g_80;
        int *l_312 = (void*)0;
        int *l_313 = &g_80;
        int *l_314 = &g_80;
        int *l_315 = &l_238;
        int *l_316 = &g_41;
        int *l_317 = &l_238;
        int *l_319 = &g_41;
        int *l_320 = &g_80;
        int *l_321 = (void*)0;
        int *l_322 = (void*)0;
        int *l_323 = &g_41;
        int *l_325 = &g_80;
        int *l_326 = &g_41;
        int *l_327 = &g_41;
        step_hash(86);
        --l_288;
        step_hash(87);
        --g_328;
        step_hash(96);
        for (g_94 = 0; (g_94 <= (-16)); --g_94)
        {
            step_hash(95);
            for (g_80 = 0; (g_80 == (-30)); g_80--)
            {
                unsigned l_335 = 0xD1283D66L;
                step_hash(94);
                if (l_335)
                    break;
            }
        }
    }
    step_hash(98);
    (*l_285) &= (func_58(p_38) < 0L);
    step_hash(99);
    return p_38;
}
static signed char func_49(unsigned p_50, unsigned p_51, int p_52, unsigned short p_53, unsigned short p_54)
{
    int *l_182 = &g_41;
    int **l_181 = &l_182;
    short l_220 = 0x7E15L;
    int l_227 = 0xFC398B08L;
    step_hash(54);
    if ((((unsigned short)(-(unsigned)((unsigned short)(p_51 ^ (0xE403142CL | (l_181 == (void*)0))) % (unsigned short)0x5E4EL)) << (unsigned short)(*l_182)) && ((signed char)p_54 / (signed char)(**l_181))))
    {
        int **l_197 = &l_182;
        signed char l_198 = 0xC9L;
        int l_199 = 5L;
        step_hash(51);
        if (((((g_167 ^ (((unsigned char)(0x5F8E08A2L & ((int)((signed char)(((unsigned short)((short)(g_195 != l_197) >> (short)3) * (unsigned short)(((**l_197) || l_198) <= (g_18 ^ (((**l_197) | (g_18 ^ g_149)) >= p_54)))) > 1L) << (signed char)7) / (int)p_50)) + (unsigned char)(**l_197)) || p_51)) && (*l_182)) && g_149) || (**l_197)))
        {
            step_hash(47);
            return p_51;
        }
        else
        {
            step_hash(49);
            l_199 &= 0L;
            step_hash(50);
            return (**l_197);
        }
    }
    else
    {
        int *l_200 = &g_80;
        int *l_201 = &g_80;
        int *l_202 = &g_80;
        int *l_203 = &g_80;
        int *l_204 = (void*)0;
        int *l_205 = &g_80;
        int *l_206 = &g_80;
        int *l_207 = &g_80;
        int *l_208 = &g_80;
        int *l_209 = &g_80;
        int *l_210 = &g_80;
        int *l_211 = &g_80;
        int *l_212 = &g_80;
        int *l_213 = &g_80;
        int *l_214 = &g_80;
        int *l_215 = &g_80;
        int *l_216 = (void*)0;
        int *l_217 = &g_80;
        int *l_218 = &g_80;
        int *l_219 = (void*)0;
        int *l_222 = &g_80;
        int *l_223 = &g_80;
        int *l_224 = (void*)0;
        int *l_225 = &g_80;
        int *l_226 = &g_80;
        int l_228 = 9L;
        int *l_229 = (void*)0;
        int *l_230 = &l_228;
        int *l_231 = &l_228;
        step_hash(53);
        ++g_232;
    }
    step_hash(55);
    return g_146;
}
static unsigned func_58(unsigned char p_59)
{
    short l_84 = (-3L);
    unsigned l_138 = 0x2A8B70F5L;
    int *l_161 = (void*)0;
    int *l_162 = &g_80;
    int l_172 = 0x43DE26F3L;
    signed char l_175 = 0L;
    step_hash(40);
    for (p_59 = (-4); (p_59 > 46); p_59 += 4)
    {
        short l_74 = 0x84A5L;
        int l_98 = 2L;
        int l_107 = 0x37A4C668L;
        int l_132 = 0L;
        int *l_160 = &l_98;
        step_hash(39);
        if ((((((signed char)(((signed char)((((unsigned char)0xF9L * (unsigned char)((short)g_41 - (short)65535UL)) | (p_59 != 2L)) || (g_41 == p_59)) * (signed char)((signed char)(9L == ((short)(0UL == p_59) * (short)0xC3CBL)) % (signed char)9L)) & 0x851CL) % (signed char)g_41) >= g_41) ^ p_59) ^ 0xBADF38E7L))
        {
            step_hash(14);
            if (l_74)
                break;
        }
        else
        {
            int *l_76 = (void*)0;
            int **l_75 = &l_76;
            int l_81 = (-2L);
            int l_88 = 0xA9D242ECL;
            int l_90 = 0x2E93B6ABL;
            int l_114 = 0x4F583EF4L;
            int l_137 = (-8L);
            int *l_141 = &l_132;
            int *l_142 = (void*)0;
            int *l_143 = &l_81;
            int *l_144 = &l_81;
            int *l_145 = &l_137;
            int *l_147 = &l_98;
            int *l_148 = (void*)0;
            step_hash(16);
            (*l_75) = (void*)0;
            step_hash(23);
            for (l_74 = (-28); (l_74 <= (-21)); l_74 += 6)
            {
                int *l_79 = &g_80;
                int *l_82 = &l_81;
                int *l_83 = &l_81;
                int *l_85 = &g_80;
                int *l_86 = &l_81;
                int *l_87 = &g_80;
                int *l_89 = &g_80;
                int *l_91 = &l_88;
                int *l_92 = &g_80;
                int *l_93 = &l_90;
                int *l_95 = &l_88;
                int *l_96 = &l_88;
                int *l_97 = &g_80;
                int l_99 = (-1L);
                int *l_100 = &l_81;
                int *l_101 = &l_81;
                int *l_102 = &g_80;
                int *l_103 = &l_98;
                int *l_104 = &l_90;
                int *l_105 = (void*)0;
                int *l_106 = &l_90;
                int *l_108 = &g_80;
                int *l_109 = (void*)0;
                int *l_110 = (void*)0;
                int *l_111 = &g_80;
                int *l_112 = &l_99;
                int *l_113 = &l_88;
                int *l_115 = &l_99;
                int *l_116 = (void*)0;
                int *l_117 = &l_99;
                int l_118 = 0x6BB23DF4L;
                int *l_119 = &l_98;
                int *l_120 = &l_98;
                int *l_121 = &l_107;
                int *l_122 = &l_88;
                int *l_123 = &l_107;
                int *l_124 = (void*)0;
                int *l_125 = &l_107;
                int *l_126 = (void*)0;
                int *l_127 = &l_118;
                int *l_128 = &l_99;
                int *l_129 = &l_118;
                int *l_130 = &l_99;
                int *l_131 = &l_98;
                int *l_133 = &l_114;
                int *l_134 = (void*)0;
                int *l_135 = &l_81;
                int l_136 = 0xF110B0F3L;
                step_hash(20);
                (*l_79) = g_41;
                step_hash(21);
                (*l_79) |= ((+0x33457209L) > (g_18 > l_74));
                step_hash(22);
                --l_138;
            }
            step_hash(24);
            ++g_149;
            step_hash(38);
            for (g_94 = 0; (g_94 == (-12)); --g_94)
            {
                step_hash(32);
                for (l_137 = 0; (l_137 != 20); l_137 += 3)
                {
                    step_hash(31);
                    (*l_147) = ((unsigned short)g_18 >> (unsigned short)15);
                }
                step_hash(37);
                for (l_88 = 10; (l_88 <= (-20)); l_88 -= 6)
                {
                    step_hash(36);
                    l_160 = &l_132;
                }
            }
        }
    }
    step_hash(41);
    (*l_162) ^= l_84;
    step_hash(42);
    (*l_162) = ((signed char)(((unsigned short)(((0UL <= ((g_167 <= 1L) == g_41)) < (((unsigned char)((p_59 || ((unsigned char)l_172 - (unsigned char)((p_59 != ((unsigned char)g_18 << (unsigned char)7)) > 0L))) <= g_18) * (unsigned char)g_167) < (-7L))) || (*l_162)) * (unsigned short)g_18) <= 0xBFA59640L) / (signed char)p_59);
    step_hash(43);
    return l_175;
}
void csmith_compute_hash(void)
{
    transparent_crc(g_18, "g_18", print_hash_value);
    transparent_crc(g_41, "g_41", print_hash_value);
    transparent_crc(g_80, "g_80", print_hash_value);
    transparent_crc(g_94, "g_94", print_hash_value);
    transparent_crc(g_146, "g_146", print_hash_value);
    transparent_crc(g_149, "g_149", print_hash_value);
    transparent_crc(g_167, "g_167", print_hash_value);
    transparent_crc(g_221, "g_221", print_hash_value);
    transparent_crc(g_232, "g_232", print_hash_value);
    transparent_crc(g_318, "g_318", print_hash_value);
    transparent_crc(g_324, "g_324", print_hash_value);
    transparent_crc(g_328, "g_328", print_hash_value);
    transparent_crc(g_370, "g_370", print_hash_value);
    transparent_crc(g_486, "g_486", print_hash_value);
    transparent_crc(g_490, "g_490", print_hash_value);
    transparent_crc(g_495, "g_495", print_hash_value);
    transparent_crc(g_560, "g_560", print_hash_value);
    transparent_crc(g_607, "g_607", print_hash_value);
    transparent_crc(g_611, "g_611", print_hash_value);
    transparent_crc(g_629, "g_629", print_hash_value);
    transparent_crc(g_729, "g_729", print_hash_value);
    transparent_crc(g_877, "g_877", print_hash_value);
    transparent_crc(g_1086, "g_1086", print_hash_value);
    transparent_crc(g_1223, "g_1223", print_hash_value);
    transparent_crc(g_1237, "g_1237", print_hash_value);
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
