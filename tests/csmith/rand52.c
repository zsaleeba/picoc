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
static signed char g_8 = 0xDFL;
static int g_38 = 0x3703ACB6L;
static int *g_63 = &g_38;
static int **g_62 = &g_63;
static int g_78 = 0xDFDCBC33L;
static int g_91 = 0L;
static signed char g_106 = 0xCDL;
static int g_112 = 3L;
static short g_124 = 0xA618L;
static signed char g_141 = 0x89L;
static unsigned g_187 = 4294967291UL;
static signed char g_193 = 0xC0L;
static short g_195 = 0xA419L;
static signed char g_269 = 0xA4L;
static unsigned g_291 = 0xCD422BFBL;
static unsigned g_306 = 4294967295UL;
static int g_313 = (-1L);
static int g_447 = 0x37805436L;
static signed char g_450 = 1L;
static unsigned g_461 = 4294967294UL;
static unsigned char g_588 = 0UL;
static unsigned g_646 = 0x29D25AE4L;
static int *g_649 = (void*)0;
static unsigned short g_748 = 0xBA87L;
static int g_847 = (-1L);
static int g_874 = (-1L);
static short g_913 = (-1L);
static int g_924 = 0xDF94836FL;
static short g_949 = 0x546AL;
static int g_975 = 0x3C0BBB50L;
static int g_1000 = 0L;
static unsigned short g_1023 = 1UL;
static int g_1268 = 1L;
static unsigned short g_1272 = 65535UL;
static unsigned short g_1521 = 6UL;
static unsigned g_1588 = 1UL;
static signed char g_1755 = 0xB1L;
static unsigned g_1787 = 5UL;
static unsigned short g_1952 = 0UL;
static int g_2108 = 0xC2AD2BFEL;
static short g_2121 = (-1L);
static int g_2172 = (-9L);
static int g_2177 = 0x4BE1DBD2L;
static unsigned short g_2214 = 0xEA3AL;
static int g_2337 = (-1L);
static int *g_2343 = &g_874;
static unsigned short g_2345 = 0x168BL;
static int *g_2355 = (void*)0;
static int g_2371 = 0L;
static unsigned short g_2526 = 0UL;
static unsigned g_2739 = 0UL;
static signed char g_2756 = (-1L);
static unsigned func_1(void);
static short func_11(unsigned p_12, unsigned p_13);
static unsigned func_14(unsigned p_15, unsigned char p_16, int p_17, int p_18);
static unsigned func_19(signed char p_20, unsigned p_21);
static int func_23(unsigned p_24, int p_25);
static unsigned func_26(short p_27);
static signed char func_30(short p_31, signed char p_32, unsigned p_33, unsigned p_34);
static signed char func_39(int * p_40, int * p_41, int * p_42, int p_43);
static int * func_44(int * p_45, int * p_46, int * p_47, unsigned p_48);
static int * func_49(signed char p_50, int p_51);
static unsigned func_1(void)
{
    unsigned l_2 = 4294967288UL;
    int l_3 = (-8L);
    int l_2708 = 0xD55D1535L;
    unsigned l_2715 = 0x1A45F09DL;
    unsigned l_2717 = 4294967295UL;
    int *l_2745 = &g_874;
    unsigned l_2777 = 0x5F113AC8L;
    step_hash(1);
    l_3 |= l_2;
    step_hash(505);
    for (l_2 = 23; (l_2 > 34); l_2 += 1)
    {
        short l_35 = 0x709BL;
        unsigned char l_36 = 0x4EL;
        signed char l_2716 = 0x60L;
        int l_2735 = 0x9943B0BEL;
        int l_2744 = (-1L);
        step_hash(461);
        for (l_3 = (-16); (l_3 != (-5)); l_3 += 7)
        {
            int l_22 = (-1L);
            unsigned l_1616 = 0xB93E3C53L;
            int l_2701 = (-7L);
        }
        step_hash(503);
        if (((((unsigned)(((*g_2343) || func_23(g_461, ((unsigned short)l_2708 << (unsigned short)12))) == (((unsigned)g_112 + (unsigned)((unsigned char)0x58L % (unsigned char)func_23((+((unsigned short)((l_2715 ^ (&l_3 != &l_3)) > l_2716) * (unsigned short)0x927DL)), l_2717))) ^ l_2)) / (unsigned)0x26DC01D5L) & (*g_63)) < g_1952))
        {
            short l_2720 = 0L;
            int *l_2723 = (void*)0;
            unsigned char l_2761 = 252UL;
            step_hash(481);
            for (g_78 = 0; (g_78 > 19); ++g_78)
            {
                signed char l_2726 = 0xD3L;
                step_hash(466);
                (**g_62) = l_2720;
                step_hash(479);
                for (g_874 = (-3); (g_874 >= (-2)); g_874++)
                {
                    int l_2734 = 0xC950660BL;
                    step_hash(478);
                    if (func_26(((-1L) > ((void*)0 == l_2723))))
                    {
                        int **l_2727 = &g_649;
                        step_hash(471);
                        (*l_2727) = func_49(((short)(func_23(l_2726, (**g_62)) || g_112) >> (short)g_2345), g_112);
                        step_hash(472);
                        (**l_2727) = (*g_63);
                    }
                    else
                    {
                        unsigned l_2730 = 3UL;
                        int l_2736 = (-1L);
                        step_hash(474);
                        (**g_62) = (g_2526 < 6L);
                        step_hash(475);
                        (*g_62) = (*g_62);
                        step_hash(476);
                        l_2736 &= (((int)((g_874 || l_2730) < ((((int)func_26((-(unsigned short)func_23(g_748, (*g_63)))) % (int)l_2734) <= func_23(l_2726, (g_874 | g_187))) & l_2716)) % (int)g_124) != l_2735);
                        step_hash(477);
                        if ((**g_62))
                            continue;
                    }
                }
                step_hash(480);
                (**g_62) = l_2716;
            }
            step_hash(500);
            if (((*g_2343) != ((int)l_2708 + (int)g_2739)))
            {
                step_hash(483);
                return g_949;
            }
            else
            {
                unsigned char l_2753 = 255UL;
                int **l_2762 = (void*)0;
                int **l_2763 = (void*)0;
                int **l_2764 = &g_2343;
                step_hash(485);
                (*g_2343) = (*g_2343);
                step_hash(498);
                for (g_447 = 22; (g_447 == 14); g_447 -= 9)
                {
                    int l_2748 = 0xAD84CB3CL;
                    step_hash(496);
                    for (g_874 = (-25); (g_874 <= 10); g_874 += 1)
                    {
                        step_hash(492);
                        (*g_62) = (*g_62);
                    }
                    step_hash(497);
                    (*l_2745) = ((unsigned short)(~(l_2748 <= (((&g_2355 == &g_63) < (((short)(&g_649 == (void*)0) - (short)(((unsigned char)(l_2753 >= ((signed char)g_588 << (signed char)0)) - (unsigned char)g_112) && l_2744)) > g_2756)) <= 0xFD2DL))) >> (unsigned short)12);
                }
                step_hash(499);
                (*l_2764) = func_49(l_2716, (((signed char)((short)l_2761 * (short)g_2177) << (signed char)3) < (g_2108 & ((l_2762 != &g_2343) > func_26(g_1787)))));
            }
        }
        else
        {
            unsigned l_2775 = 8UL;
            int **l_2776 = &l_2745;
            step_hash(502);
            (*l_2776) = func_49((((*g_63) & ((*g_62) != (*g_62))) ^ func_14((((unsigned char)0UL + (unsigned char)0xDAL) > (((unsigned char)((*l_2745) != ((short)g_2172 + (short)((unsigned char)(((unsigned)4294967295UL - (unsigned)(l_2775 && l_2775)) ^ g_588) + (unsigned char)(*l_2745)))) >> (unsigned char)3) ^ (-3L))), g_195, (*l_2745), l_2735)), g_291);
        }
        step_hash(504);
        return l_2735;
    }
    step_hash(506);
    return l_2777;
}
static short func_11(unsigned p_12, unsigned p_13)
{
    int l_2531 = (-9L);
    int l_2574 = 0x1C13BC1DL;
    int l_2591 = (-2L);
    int l_2607 = 0L;
    int l_2612 = (-6L);
    unsigned l_2629 = 8UL;
    unsigned short l_2665 = 0xD46FL;
    step_hash(453);
    for (g_847 = 0; (g_847 == 13); ++g_847)
    {
        int **l_2540 = &g_649;
        int *l_2545 = &g_78;
        int l_2557 = 0x84CF6A0AL;
        int l_2565 = 6L;
        int l_2585 = (-1L);
        int l_2626 = 0x0F6F8F4EL;
        step_hash(407);
        l_2531 = 0xB593045BL;
        step_hash(408);
        (*g_2343) = p_12;
        step_hash(409);
        (*l_2545) &= (65535UL >= ((short)(&g_62 == (void*)0) * (short)((unsigned short)((short)(((short)((&g_2355 != &g_63) < ((l_2540 != (void*)0) > (func_23(l_2531, ((((unsigned short)func_14(((int)p_12 - (int)g_1521), p_12, p_13, l_2531) >> (unsigned short)11) & 0L) && g_1521)) ^ p_12))) - (short)p_12) > g_975) - (short)0xAB24L) * (unsigned short)g_450)));
        step_hash(452);
        if (p_12)
        {
            int *l_2546 = &g_447;
            int *l_2549 = &g_313;
            int *l_2550 = &g_112;
            int *l_2551 = &g_2337;
            int *l_2552 = (void*)0;
            int *l_2553 = &g_38;
            int *l_2554 = &g_975;
            int *l_2555 = &g_38;
            int *l_2556 = (void*)0;
            int *l_2558 = (void*)0;
            int *l_2559 = &g_38;
            int *l_2560 = &g_1268;
            int *l_2561 = &g_313;
            int *l_2562 = &g_1268;
            int *l_2563 = &g_874;
            int *l_2564 = &g_38;
            int *l_2566 = &g_2337;
            int *l_2567 = &g_975;
            int *l_2568 = &l_2557;
            int *l_2569 = &g_1268;
            int *l_2570 = &g_91;
            int *l_2571 = &l_2565;
            int *l_2572 = &g_38;
            int *l_2573 = &l_2531;
            int *l_2575 = &g_1268;
            int *l_2576 = &g_112;
            int *l_2577 = &g_447;
            int *l_2578 = &l_2557;
            int *l_2579 = &g_112;
            int l_2580 = 0x26557C6EL;
            int *l_2581 = &g_447;
            int *l_2582 = &g_975;
            int *l_2583 = (void*)0;
            int *l_2584 = &l_2531;
            int *l_2586 = &g_112;
            int *l_2587 = (void*)0;
            int *l_2588 = &g_447;
            int *l_2589 = &g_91;
            int l_2590 = 0L;
            int *l_2592 = (void*)0;
            int *l_2593 = &g_91;
            int *l_2594 = &l_2580;
            int *l_2595 = &l_2531;
            int *l_2596 = (void*)0;
            int *l_2597 = &l_2531;
            int *l_2598 = &l_2580;
            int *l_2599 = &g_313;
            int *l_2600 = &g_975;
            int *l_2601 = &g_447;
            int l_2602 = 0xC4258538L;
            int *l_2603 = &g_91;
            int *l_2604 = &g_112;
            int *l_2605 = &g_1268;
            int *l_2606 = &g_112;
            int *l_2608 = &g_447;
            int *l_2609 = &l_2580;
            int *l_2610 = &g_447;
            int *l_2611 = &l_2607;
            int *l_2613 = &g_1268;
            int *l_2614 = &g_112;
            int l_2615 = 1L;
            int *l_2616 = &g_1268;
            int *l_2617 = &g_112;
            int *l_2618 = &g_38;
            int *l_2619 = &g_2371;
            int *l_2620 = &g_2371;
            int *l_2621 = &g_447;
            int *l_2622 = &g_112;
            int *l_2623 = &g_91;
            int *l_2624 = &l_2585;
            int *l_2625 = &g_975;
            int *l_2627 = (void*)0;
            int l_2628 = 0x40769EE7L;
            step_hash(411);
            (*l_2546) ^= p_13;
            step_hash(412);
            (*g_2343) &= p_13;
            step_hash(413);
            if (p_12)
                break;
            step_hash(414);
            --l_2629;
        }
        else
        {
            signed char l_2637 = 1L;
            int l_2644 = 2L;
            int l_2654 = 1L;
            int l_2662 = (-6L);
            short l_2680 = (-1L);
            int l_2681 = 0x45E7B68FL;
            step_hash(421);
            for (g_8 = 0; (g_8 < (-16)); g_8 -= 1)
            {
                unsigned l_2634 = 0x015F55DDL;
                step_hash(419);
                --l_2634;
                step_hash(420);
                if (l_2637)
                    continue;
            }
            step_hash(427);
            if (l_2574)
            {
                int *l_2638 = &g_2371;
                step_hash(423);
                l_2638 = &g_975;
            }
            else
            {
                step_hash(425);
                (*g_2343) = p_12;
                step_hash(426);
                (*l_2540) = &g_975;
            }
            step_hash(432);
            for (g_2108 = 0; (g_2108 < (-15)); g_2108--)
            {
                step_hash(431);
                return l_2637;
            }
            step_hash(451);
            if ((l_2629 != (!((short)g_1023 + (short)65531UL))))
            {
                short l_2643 = 0x5EA8L;
                int *l_2645 = &l_2557;
                int *l_2646 = &l_2557;
                int *l_2647 = &l_2626;
                int *l_2648 = &l_2531;
                int *l_2649 = &l_2531;
                int *l_2650 = &g_874;
                int *l_2651 = &g_313;
                int *l_2652 = &g_1268;
                int *l_2653 = &g_38;
                int *l_2655 = &l_2644;
                int *l_2656 = &l_2557;
                int *l_2657 = &l_2591;
                int *l_2658 = &g_313;
                int *l_2659 = &g_78;
                int *l_2660 = (void*)0;
                int *l_2661 = &g_975;
                int *l_2663 = &l_2662;
                int *l_2664 = &l_2574;
                signed char l_2670 = 6L;
                int *l_2682 = &l_2662;
                int *l_2683 = (void*)0;
                int *l_2684 = &g_313;
                int *l_2685 = (void*)0;
                int *l_2686 = &l_2591;
                int *l_2687 = &g_112;
                int *l_2688 = &g_2371;
                int *l_2689 = &g_1268;
                int *l_2690 = &l_2557;
                int *l_2691 = &g_975;
                int *l_2692 = &l_2626;
                int *l_2693 = &g_447;
                int *l_2694 = (void*)0;
                int *l_2695 = &l_2607;
                int *l_2696 = (void*)0;
                int *l_2697 = (void*)0;
                unsigned short l_2698 = 65532UL;
                step_hash(434);
                --l_2665;
                step_hash(446);
                for (l_2565 = 0; (l_2565 < (-13)); --l_2565)
                {
                    unsigned char l_2671 = 0x29L;
                    int **l_2676 = &g_2355;
                    step_hash(438);
                    l_2654 ^= l_2670;
                    step_hash(439);
                    l_2671++;
                    step_hash(445);
                    for (g_124 = 4; (g_124 < 10); ++g_124)
                    {
                        int **l_2677 = &l_2657;
                        step_hash(443);
                        (*l_2653) &= ((((l_2676 != (void*)0) <= g_1000) | ((g_450 >= ((void*)0 == l_2677)) != (((unsigned)(&l_2540 != &l_2540) * (unsigned)(p_13 >= l_2607)) < 0x7A4F9116L))) != 65527UL);
                        step_hash(444);
                        l_2654 |= (g_78 != 0x78B2L);
                    }
                }
                step_hash(447);
                l_2698++;
            }
            else
            {
                step_hash(449);
                if (p_12)
                    break;
                step_hash(450);
                return p_13;
            }
        }
    }
    step_hash(454);
    return p_12;
}
static unsigned func_14(unsigned p_15, unsigned char p_16, int p_17, int p_18)
{
    int *l_2372 = (void*)0;
    int *l_2373 = &g_2371;
    int *l_2374 = &g_975;
    int *l_2375 = (void*)0;
    int *l_2376 = &g_2337;
    int *l_2377 = &g_78;
    int *l_2378 = &g_78;
    int *l_2379 = &g_78;
    int *l_2380 = &g_2371;
    int *l_2381 = (void*)0;
    int *l_2382 = (void*)0;
    int *l_2383 = &g_874;
    int *l_2384 = &g_112;
    int *l_2385 = &g_38;
    int *l_2386 = &g_2371;
    int *l_2387 = &g_1268;
    int *l_2388 = &g_313;
    int *l_2389 = &g_2337;
    int *l_2390 = &g_2371;
    int *l_2391 = (void*)0;
    int *l_2392 = (void*)0;
    int *l_2393 = &g_78;
    int *l_2394 = &g_78;
    int *l_2395 = &g_874;
    int l_2396 = 0xE95978A0L;
    int *l_2397 = (void*)0;
    int l_2398 = (-3L);
    int l_2399 = 0x970480E5L;
    int *l_2400 = (void*)0;
    int *l_2401 = &g_874;
    int *l_2402 = &l_2399;
    int *l_2403 = &g_112;
    int *l_2404 = (void*)0;
    int *l_2405 = &g_447;
    int *l_2406 = &g_1268;
    int *l_2407 = &g_2337;
    int *l_2408 = &l_2398;
    int l_2409 = 0x53398A78L;
    int *l_2410 = &g_91;
    int *l_2411 = &g_1268;
    int *l_2412 = &l_2396;
    int *l_2413 = &g_91;
    int *l_2414 = &g_313;
    int *l_2415 = &g_2337;
    int *l_2416 = &g_1268;
    int *l_2417 = &g_874;
    int *l_2418 = &g_112;
    int l_2419 = 1L;
    int *l_2420 = &g_38;
    int *l_2421 = (void*)0;
    int *l_2422 = &g_91;
    int *l_2423 = &g_874;
    int l_2424 = (-10L);
    int *l_2425 = &g_38;
    int *l_2426 = &g_2337;
    int *l_2427 = &g_2337;
    int *l_2428 = &g_2337;
    int *l_2429 = (void*)0;
    int *l_2430 = &g_1268;
    int *l_2431 = &g_78;
    int *l_2432 = (void*)0;
    int l_2433 = 0x50EDE960L;
    int *l_2434 = &g_447;
    int *l_2435 = &l_2398;
    int *l_2436 = &l_2398;
    int *l_2437 = &g_112;
    int *l_2438 = &g_313;
    int l_2439 = 0x10FDBCCBL;
    int *l_2440 = (void*)0;
    int *l_2441 = &l_2439;
    int l_2442 = 1L;
    int *l_2443 = &l_2419;
    int *l_2444 = &l_2399;
    int *l_2445 = &l_2409;
    int l_2446 = 0xE47385B4L;
    int l_2447 = 0x7AE64C24L;
    int *l_2448 = &g_78;
    int *l_2449 = (void*)0;
    int *l_2450 = &g_975;
    int *l_2451 = &l_2419;
    int l_2452 = (-1L);
    int *l_2453 = (void*)0;
    int *l_2454 = &l_2399;
    int *l_2455 = &l_2439;
    int *l_2456 = &l_2446;
    int *l_2457 = &g_1268;
    int *l_2458 = &l_2398;
    int *l_2459 = &l_2409;
    int *l_2460 = (void*)0;
    int *l_2461 = &l_2447;
    int *l_2462 = &l_2398;
    int *l_2463 = &g_975;
    int *l_2464 = &g_975;
    int *l_2465 = &l_2439;
    int *l_2466 = &l_2398;
    int *l_2467 = &l_2452;
    int *l_2468 = &g_1268;
    int *l_2469 = &g_975;
    int *l_2470 = (void*)0;
    int l_2471 = 0L;
    int *l_2472 = &g_2337;
    int *l_2473 = &g_447;
    int *l_2474 = (void*)0;
    int *l_2475 = &g_38;
    int *l_2476 = &l_2446;
    int *l_2477 = &l_2471;
    int *l_2478 = &l_2396;
    int *l_2479 = &g_78;
    int *l_2480 = (void*)0;
    int *l_2481 = (void*)0;
    int *l_2482 = &g_112;
    int *l_2483 = &g_112;
    int l_2484 = (-6L);
    int *l_2485 = &l_2398;
    int *l_2486 = &l_2442;
    int *l_2487 = &g_38;
    int l_2488 = 0x943C57C5L;
    int *l_2489 = &l_2399;
    int *l_2490 = (void*)0;
    int *l_2491 = &l_2409;
    int *l_2492 = &g_78;
    int *l_2493 = &l_2433;
    int *l_2494 = &g_2337;
    int *l_2495 = &g_975;
    int *l_2496 = &g_874;
    int *l_2497 = &l_2471;
    int l_2498 = 6L;
    int l_2499 = (-6L);
    int *l_2500 = &g_1268;
    int *l_2501 = &l_2419;
    int *l_2502 = (void*)0;
    int l_2503 = 0xFC73E23FL;
    int *l_2504 = (void*)0;
    int *l_2505 = (void*)0;
    int *l_2506 = &g_1268;
    int *l_2507 = (void*)0;
    int *l_2508 = &l_2452;
    int *l_2509 = &l_2398;
    int *l_2510 = &g_2337;
    int l_2511 = (-1L);
    int *l_2512 = &g_2337;
    int l_2513 = 0x379CEAE6L;
    int *l_2514 = (void*)0;
    int *l_2515 = &l_2439;
    int l_2516 = 0x6507C12CL;
    int *l_2517 = (void*)0;
    int *l_2518 = (void*)0;
    int *l_2519 = &g_313;
    int *l_2520 = (void*)0;
    int *l_2521 = (void*)0;
    int *l_2522 = &l_2511;
    int *l_2523 = &g_447;
    int *l_2524 = &g_78;
    int *l_2525 = &g_2371;
    step_hash(400);
    (*g_2343) = p_16;
    step_hash(401);
    g_2526++;
    step_hash(402);
    return g_588;
}
static unsigned func_19(signed char p_20, unsigned p_21)
{
    short l_1785 = 0x6DD0L;
    int l_1786 = 0x4CF5C13EL;
    int l_1828 = 0L;
    int l_1914 = 8L;
    int **l_1960 = (void*)0;
    int l_2015 = 0xF9B41EA6L;
    int l_2027 = 1L;
    int l_2044 = 0x9DF30B3FL;
    int l_2073 = 0xED7A27C3L;
    int l_2103 = 0xBBE9C045L;
    int l_2132 = 0x9C83C5FBL;
    int l_2152 = 0x446C5D5BL;
    int l_2164 = (-1L);
    int l_2195 = 0xA80F20C7L;
    int *l_2246 = &g_112;
    unsigned short l_2314 = 1UL;
    step_hash(326);
    g_1787 ^= ((short)(((unsigned)g_193 + (unsigned)(((-(signed char)(((((signed char)g_913 - (signed char)((signed char)func_26(g_193) + (signed char)((((!p_21) != p_20) != g_313) && g_291))) || ((((unsigned short)((unsigned char)(((void*)0 == &g_62) | 4294967295UL) >> (unsigned char)g_313) * (unsigned short)1L) <= 0xA6L) & l_1785)) ^ p_20) == l_1785)) | l_1786) | g_1272)) != p_20) % (short)l_1786);
    step_hash(327);
    g_1268 |= l_1785;
    step_hash(328);
    g_112 &= ((((!(l_1785 | 247UL)) | p_21) <= (((g_193 <= 0xF1L) != l_1786) | g_1268)) >= 0L);
    step_hash(397);
    if ((((unsigned short)g_461 << (unsigned short)((short)p_21 % (short)(0x77DAL || (p_20 < 1L)))) != (g_269 | l_1785)))
    {
        int *l_1794 = &g_38;
        int l_1798 = (-9L);
        int l_1838 = 0L;
        int l_1840 = 0xCEF7006BL;
        int l_1854 = 0xF2F2D123L;
        int l_1908 = 0x5C40A123L;
        int l_1916 = 0L;
        int l_1920 = (-8L);
        int l_1929 = 0xFDFA5658L;
        int l_1943 = 1L;
        signed char l_2034 = 0xF1L;
        step_hash(351);
        if (p_20)
        {
            int l_1795 = 0xF06A783AL;
            int *l_1796 = &g_874;
            int *l_1797 = &g_874;
            int *l_1799 = &g_313;
            int *l_1800 = &l_1798;
            int *l_1801 = &g_874;
            int *l_1802 = &g_313;
            int *l_1803 = &g_975;
            int *l_1804 = (void*)0;
            int *l_1805 = &g_975;
            int *l_1806 = &g_38;
            int *l_1807 = (void*)0;
            int *l_1808 = &g_1268;
            int *l_1809 = &g_91;
            int *l_1810 = &l_1798;
            int *l_1811 = (void*)0;
            int *l_1812 = &g_1268;
            int *l_1813 = &g_1268;
            int *l_1814 = (void*)0;
            int *l_1815 = (void*)0;
            int *l_1816 = &g_1268;
            int *l_1817 = &g_112;
            int *l_1818 = (void*)0;
            int *l_1819 = &g_112;
            int *l_1820 = &g_78;
            int *l_1821 = &g_874;
            int *l_1822 = &g_112;
            int *l_1823 = &g_975;
            int *l_1824 = &g_874;
            int *l_1825 = &l_1798;
            int *l_1826 = &g_1268;
            int *l_1827 = &g_38;
            int *l_1829 = &g_447;
            int *l_1830 = &g_313;
            int *l_1831 = &l_1798;
            int *l_1832 = &g_78;
            int *l_1833 = &g_91;
            int *l_1834 = &g_1268;
            int *l_1835 = &l_1828;
            int *l_1836 = &g_78;
            int *l_1837 = &g_91;
            int *l_1839 = &g_874;
            int *l_1841 = &g_112;
            int *l_1842 = &g_78;
            int *l_1843 = &l_1786;
            int *l_1844 = &g_112;
            int *l_1845 = &g_112;
            int l_1846 = (-1L);
            int *l_1847 = &g_91;
            int *l_1848 = &l_1846;
            int *l_1849 = &l_1846;
            int *l_1850 = &g_78;
            int *l_1851 = &g_112;
            int *l_1852 = (void*)0;
            int *l_1853 = &g_1268;
            int *l_1855 = &g_1268;
            int *l_1856 = &g_38;
            int *l_1857 = &g_78;
            int *l_1858 = (void*)0;
            int *l_1859 = &g_91;
            int *l_1860 = &l_1786;
            int *l_1861 = &g_1268;
            int l_1862 = 0xEB1CF757L;
            int *l_1863 = (void*)0;
            int *l_1864 = (void*)0;
            int *l_1865 = &l_1798;
            int *l_1866 = &l_1838;
            int *l_1867 = (void*)0;
            int *l_1868 = &l_1854;
            int *l_1869 = &g_313;
            int *l_1870 = &g_447;
            int *l_1871 = &l_1838;
            int *l_1872 = &g_112;
            int *l_1873 = &l_1798;
            int *l_1874 = &l_1838;
            int *l_1875 = &g_313;
            int *l_1876 = (void*)0;
            int *l_1877 = &g_112;
            int *l_1878 = &g_91;
            int *l_1879 = &g_112;
            int *l_1880 = (void*)0;
            int *l_1881 = (void*)0;
            int *l_1882 = &g_112;
            int *l_1883 = &g_112;
            int *l_1884 = &l_1862;
            int *l_1885 = (void*)0;
            int *l_1886 = &l_1840;
            int *l_1887 = &g_975;
            int *l_1888 = &l_1846;
            int *l_1889 = &l_1838;
            int *l_1890 = &g_447;
            int *l_1891 = &g_112;
            int *l_1892 = &g_91;
            int *l_1893 = &l_1854;
            int *l_1894 = &g_313;
            int *l_1895 = &g_1268;
            int *l_1896 = &l_1798;
            int *l_1897 = (void*)0;
            int *l_1898 = &g_1268;
            int *l_1899 = (void*)0;
            int *l_1900 = &l_1846;
            int *l_1901 = &g_38;
            int *l_1902 = &g_447;
            int *l_1903 = &g_112;
            int *l_1904 = &g_1268;
            int *l_1905 = &l_1862;
            int *l_1906 = (void*)0;
            int *l_1907 = &l_1798;
            int *l_1909 = &l_1846;
            int *l_1910 = &g_874;
            int *l_1911 = (void*)0;
            int *l_1912 = &g_313;
            int *l_1913 = &l_1840;
            int *l_1915 = (void*)0;
            int *l_1917 = &l_1838;
            int *l_1918 = &l_1914;
            int *l_1919 = &g_975;
            int *l_1921 = &l_1828;
            int *l_1922 = &l_1914;
            int *l_1923 = &l_1862;
            int *l_1924 = &g_78;
            int *l_1925 = &g_874;
            int *l_1926 = &g_1268;
            int l_1927 = (-1L);
            int *l_1928 = &g_447;
            int *l_1930 = &g_91;
            int *l_1931 = (void*)0;
            int *l_1932 = &l_1914;
            int *l_1933 = &g_313;
            int *l_1934 = &l_1927;
            int *l_1935 = &l_1840;
            int *l_1936 = &l_1914;
            int *l_1937 = &l_1914;
            int *l_1938 = &g_91;
            int *l_1939 = &l_1798;
            int *l_1940 = (void*)0;
            int *l_1941 = (void*)0;
            int *l_1942 = &l_1920;
            int *l_1944 = &l_1914;
            int *l_1945 = &l_1854;
            int *l_1946 = (void*)0;
            int *l_1947 = &g_78;
            int *l_1948 = &g_38;
            int *l_1949 = &g_91;
            int *l_1950 = &g_313;
            int *l_1951 = &l_1854;
            step_hash(331);
            (*g_62) = l_1794;
            step_hash(332);
            g_1952--;
            step_hash(333);
            return l_1914;
        }
        else
        {
            unsigned l_1959 = 4294967295UL;
            int l_2005 = 0x164F9F2EL;
            int l_2028 = (-1L);
            int l_2154 = 0x45401014L;
            int l_2175 = 7L;
            int l_2188 = 0L;
            step_hash(341);
            if (((short)((int)p_21 + (int)(~((((p_20 || 0x0FF2L) ^ l_1959) > (l_1960 == l_1960)) < (((unsigned char)(0xD69EL && (((signed char)((int)p_20 / (int)(((void*)0 == &g_63) & (-1L))) / (signed char)g_195) <= g_447)) << (unsigned char)0) <= (*l_1794))))) - (short)g_748))
            {
                step_hash(336);
                (*l_1794) = ((unsigned short)65530UL - (unsigned short)l_1959);
                step_hash(337);
                (*g_62) = (void*)0;
            }
            else
            {
                int *l_1969 = &g_1268;
                int *l_1970 = &g_975;
                int *l_1971 = (void*)0;
                int *l_1972 = (void*)0;
                int *l_1973 = &g_447;
                int *l_1974 = &l_1798;
                int *l_1975 = &l_1798;
                int *l_1976 = &l_1943;
                int *l_1977 = &l_1920;
                int *l_1978 = &g_1268;
                int *l_1979 = &l_1908;
                int *l_1980 = &l_1908;
                int *l_1981 = (void*)0;
                int *l_1982 = &g_874;
                int l_1983 = 0xECAE33FAL;
                int *l_1984 = &l_1920;
                int *l_1985 = &l_1983;
                int *l_1986 = &l_1828;
                int *l_1987 = &g_112;
                int *l_1988 = (void*)0;
                int *l_1989 = (void*)0;
                int *l_1990 = &l_1929;
                int *l_1991 = &l_1914;
                int *l_1992 = (void*)0;
                int *l_1993 = &g_447;
                int *l_1994 = &g_1268;
                int *l_1995 = &g_313;
                int *l_1996 = &l_1840;
                int *l_1997 = &g_447;
                int *l_1998 = &l_1929;
                int *l_1999 = &g_91;
                int *l_2000 = &l_1914;
                int *l_2001 = &g_112;
                int *l_2002 = &g_78;
                int l_2003 = 7L;
                int *l_2004 = (void*)0;
                int *l_2006 = &g_91;
                int *l_2007 = &g_874;
                int *l_2008 = (void*)0;
                int *l_2009 = &l_1916;
                int *l_2010 = (void*)0;
                int *l_2011 = &l_1983;
                int *l_2012 = &l_1914;
                int *l_2013 = (void*)0;
                int *l_2014 = &g_91;
                int *l_2016 = &l_1929;
                int *l_2017 = &l_2005;
                int *l_2018 = (void*)0;
                int *l_2019 = &l_1838;
                int *l_2020 = &g_112;
                int *l_2021 = &l_1798;
                int *l_2022 = &l_2003;
                int *l_2023 = &l_2015;
                int *l_2024 = &g_447;
                int *l_2025 = &g_1268;
                int *l_2026 = &g_1268;
                int *l_2029 = (void*)0;
                int *l_2030 = &l_2028;
                int *l_2031 = &l_1840;
                int *l_2032 = &g_1268;
                int *l_2033 = &g_91;
                int *l_2035 = &l_1943;
                int *l_2036 = &l_2027;
                int *l_2037 = &l_2027;
                int *l_2038 = &g_313;
                int *l_2039 = &g_78;
                int *l_2040 = &g_313;
                int *l_2041 = &g_112;
                int *l_2042 = &l_1854;
                int *l_2043 = &l_1838;
                int *l_2045 = &l_1908;
                int *l_2046 = &l_1828;
                int *l_2047 = (void*)0;
                int *l_2048 = &g_91;
                int *l_2049 = &l_2044;
                int *l_2050 = (void*)0;
                int *l_2051 = (void*)0;
                int *l_2052 = &l_2044;
                int *l_2053 = (void*)0;
                int *l_2054 = (void*)0;
                int *l_2055 = &l_1908;
                int *l_2056 = &l_1908;
                int *l_2057 = (void*)0;
                int *l_2058 = &l_1838;
                int *l_2059 = &g_975;
                int *l_2060 = &l_1840;
                int *l_2061 = &l_1929;
                int *l_2062 = (void*)0;
                int *l_2063 = &g_78;
                int *l_2064 = &l_2015;
                int *l_2065 = &g_91;
                int *l_2066 = (void*)0;
                int *l_2067 = &l_1828;
                int *l_2068 = &l_1983;
                int *l_2069 = &g_112;
                int *l_2070 = &l_2005;
                int *l_2071 = &l_2044;
                int *l_2072 = &g_1268;
                int l_2074 = 0x6BC4AC65L;
                int l_2075 = 0xE5E40892L;
                int *l_2076 = &l_1916;
                int *l_2077 = (void*)0;
                int *l_2078 = &l_1828;
                int *l_2079 = &l_1920;
                int l_2080 = (-1L);
                int *l_2081 = (void*)0;
                int *l_2082 = (void*)0;
                int *l_2083 = &l_2073;
                int *l_2084 = (void*)0;
                int *l_2085 = &l_1929;
                int *l_2086 = &g_38;
                int *l_2087 = &l_1798;
                int *l_2088 = &g_91;
                int *l_2089 = &l_1920;
                int *l_2090 = &l_2027;
                int *l_2091 = &g_975;
                int *l_2092 = &l_1916;
                int *l_2093 = &g_38;
                int *l_2094 = (void*)0;
                int *l_2095 = &l_2015;
                int *l_2096 = (void*)0;
                int *l_2097 = &l_2080;
                int *l_2098 = &l_1916;
                int *l_2099 = &l_1929;
                int *l_2100 = &l_1916;
                int *l_2101 = &l_1828;
                int *l_2102 = &l_2028;
                int *l_2104 = &l_1983;
                int *l_2105 = &g_91;
                int *l_2106 = &l_2015;
                int *l_2107 = &l_2075;
                int *l_2109 = &g_91;
                int *l_2110 = &l_1908;
                int *l_2111 = &l_2015;
                int *l_2112 = &g_1268;
                int *l_2113 = (void*)0;
                int *l_2114 = &g_874;
                int *l_2115 = &l_2074;
                int *l_2116 = &l_2080;
                int *l_2117 = (void*)0;
                int *l_2118 = &l_2075;
                int *l_2119 = &l_1914;
                int *l_2120 = &l_1908;
                int *l_2122 = &l_1908;
                int *l_2123 = &l_2003;
                int l_2124 = 0x44449917L;
                int *l_2125 = (void*)0;
                int *l_2126 = (void*)0;
                int *l_2127 = (void*)0;
                int *l_2128 = &g_38;
                int *l_2129 = (void*)0;
                int *l_2130 = (void*)0;
                int *l_2131 = &l_1798;
                int *l_2133 = &l_2044;
                int *l_2134 = &l_1916;
                int *l_2135 = (void*)0;
                int *l_2136 = &l_1854;
                int *l_2137 = &l_2003;
                int *l_2138 = &l_1798;
                int *l_2139 = (void*)0;
                int *l_2140 = &l_1854;
                int *l_2141 = (void*)0;
                int *l_2142 = &l_1838;
                int *l_2143 = &l_1929;
                int l_2144 = 0x351472BAL;
                int *l_2145 = &l_1840;
                int *l_2146 = (void*)0;
                int *l_2147 = &l_1828;
                int *l_2148 = (void*)0;
                int *l_2149 = &l_1828;
                int *l_2150 = &l_1920;
                int *l_2151 = &g_78;
                int *l_2153 = (void*)0;
                int *l_2155 = &g_975;
                int *l_2156 = &g_447;
                int *l_2157 = &l_1914;
                int *l_2158 = &l_1828;
                int *l_2159 = &l_2027;
                int *l_2160 = &l_1798;
                int *l_2161 = (void*)0;
                int *l_2162 = &l_1798;
                int *l_2163 = (void*)0;
                int *l_2165 = &l_1914;
                int *l_2166 = &g_112;
                int *l_2167 = &g_447;
                int *l_2168 = (void*)0;
                int *l_2169 = (void*)0;
                int *l_2170 = &l_1916;
                int *l_2171 = &l_2074;
                int *l_2173 = &l_1840;
                int *l_2174 = &l_2073;
                int l_2176 = 0xCD97870BL;
                int *l_2178 = &l_1854;
                int l_2179 = 0x28C26E92L;
                int *l_2180 = (void*)0;
                int *l_2181 = &l_2176;
                int *l_2182 = &g_1268;
                int *l_2183 = &g_975;
                int *l_2184 = &l_1914;
                int *l_2185 = &l_2154;
                int *l_2186 = &l_1929;
                int l_2187 = 0L;
                int *l_2189 = &l_2075;
                int *l_2190 = &l_2152;
                int *l_2191 = &g_38;
                int *l_2192 = &l_1983;
                int *l_2193 = &l_2176;
                int *l_2194 = &l_2144;
                int *l_2196 = &l_2152;
                int *l_2197 = (void*)0;
                int *l_2198 = &l_2027;
                int *l_2199 = &l_2188;
                int *l_2200 = &g_78;
                int *l_2201 = &l_1854;
                int *l_2202 = &l_1786;
                int *l_2203 = &g_313;
                int *l_2204 = &l_1983;
                int *l_2205 = &l_2195;
                int *l_2206 = &g_313;
                int *l_2207 = &l_1854;
                int *l_2208 = &g_975;
                int *l_2209 = &g_874;
                int *l_2210 = &l_1916;
                int *l_2211 = &l_2044;
                int *l_2212 = (void*)0;
                int l_2213 = (-1L);
                step_hash(339);
                g_2214++;
                step_hash(340);
                return p_21;
            }
            step_hash(342);
            (*g_62) = (void*)0;
            step_hash(349);
            if ((((func_26((p_21 >= 0xD5F3L)) > 6UL) > (p_21 & ((unsigned short)((unsigned short)g_106 / (unsigned short)g_187) << (unsigned short)6))) > ((unsigned char)((((p_21 < (+((g_1023 ^ g_141) <= g_913))) > g_1952) <= p_20) || (-4L)) * (unsigned char)0xCBL)))
            {
                int **l_2227 = &g_63;
                step_hash(344);
                l_2154 |= (((short)((unsigned char)(l_2227 == l_1960) * (unsigned char)l_2005) * (short)((unsigned)((void*)0 == &g_63) - (unsigned)p_21)) && ((*l_2227) == (void*)0));
                step_hash(345);
                (*l_1794) &= p_20;
            }
            else
            {
                step_hash(347);
                (*l_1794) ^= 0xE4E887A4L;
                step_hash(348);
                (*g_62) = l_2246;
            }
            step_hash(350);
            (*l_2246) = (*l_1794);
        }
        step_hash(352);
        (*l_1794) |= ((unsigned char)(&g_63 != &g_649) << (unsigned char)1);
    }
    else
    {
        unsigned char l_2249 = 255UL;
        int *l_2250 = &g_975;
        int l_2266 = 0x1E63A185L;
        int l_2291 = (-8L);
        int ***l_2326 = &g_62;
        int l_2346 = (-6L);
        step_hash(396);
        if (l_2249)
        {
            step_hash(355);
            (*g_62) = l_2250;
            step_hash(356);
            return g_306;
        }
        else
        {
            unsigned l_2251 = 0x57F1481FL;
            int *l_2339 = &g_78;
            step_hash(393);
            if (l_2251)
            {
                unsigned short l_2254 = 0xB6DCL;
                int l_2255 = 8L;
                step_hash(359);
                l_2255 = ((g_2177 == 0x43L) | ((unsigned short)l_2254 >> (unsigned short)11));
                step_hash(373);
                for (l_2027 = 20; (l_2027 <= (-27)); l_2027 -= 7)
                {
                    int *l_2319 = &l_2255;
                    step_hash(363);
                    (*g_62) = &l_2255;
                    step_hash(371);
                    for (l_2254 = 9; (l_2254 != 24); ++l_2254)
                    {
                        signed char l_2260 = 0x10L;
                        int *l_2261 = &l_2073;
                        int *l_2262 = (void*)0;
                        int *l_2263 = &g_38;
                        int *l_2264 = &l_2164;
                        int *l_2265 = &g_112;
                        int *l_2267 = &l_2132;
                        int *l_2268 = (void*)0;
                        int *l_2269 = &g_78;
                        int *l_2270 = &g_91;
                        int *l_2271 = &l_2195;
                        int *l_2272 = &l_2164;
                        int *l_2273 = &l_2152;
                        int *l_2274 = &g_78;
                        int *l_2275 = &g_874;
                        int *l_2276 = &l_2073;
                        int *l_2277 = &g_874;
                        int *l_2278 = &l_2073;
                        int *l_2279 = &l_2195;
                        int *l_2280 = &l_2164;
                        int *l_2281 = &g_313;
                        int *l_2282 = &l_1914;
                        int *l_2283 = (void*)0;
                        int *l_2284 = (void*)0;
                        int *l_2285 = &l_2152;
                        int *l_2286 = &g_78;
                        int *l_2287 = &l_2266;
                        int *l_2288 = &l_2152;
                        int *l_2289 = &l_2195;
                        int *l_2290 = (void*)0;
                        int *l_2292 = &g_313;
                        int *l_2293 = &g_91;
                        int *l_2294 = &g_313;
                        int l_2295 = 0L;
                        int *l_2296 = (void*)0;
                        int *l_2297 = &g_91;
                        int *l_2298 = &l_2015;
                        int *l_2299 = &l_2164;
                        int *l_2300 = &g_91;
                        int *l_2301 = (void*)0;
                        int *l_2302 = &l_2015;
                        int *l_2303 = &g_112;
                        int *l_2304 = &l_2015;
                        int *l_2305 = &g_1268;
                        int *l_2306 = &l_2073;
                        int *l_2307 = &g_447;
                        int *l_2308 = &l_2164;
                        int *l_2309 = &g_975;
                        int *l_2310 = &g_112;
                        int *l_2311 = &l_2044;
                        int *l_2312 = (void*)0;
                        int *l_2313 = &g_874;
                        step_hash(367);
                        --l_2314;
                        step_hash(368);
                        (*l_2279) = (*l_2274);
                        step_hash(369);
                        (*l_2304) = ((int)p_20 / (int)(g_949 || ((l_2319 != (void*)0) | func_26(g_1952))));
                        step_hash(370);
                        (*g_62) = &l_2295;
                    }
                    step_hash(372);
                    return g_112;
                }
                step_hash(374);
                (*l_2246) = p_20;
                step_hash(375);
                (*l_2246) = ((-1L) != g_1588);
            }
            else
            {
                int **l_2338 = &g_649;
                unsigned short l_2344 = 0xFCB5L;
                step_hash(392);
                if (l_2251)
                {
                    int *l_2342 = (void*)0;
                    step_hash(378);
                    (*l_2339) |= (((p_20 && g_269) < 0x891BL) <= l_2344);
                    step_hash(379);
                    (*g_2343) &= 8L;
                    step_hash(380);
                    (*l_2339) = ((*l_2339) || g_1787);
                    step_hash(387);
                    if ((((*l_2339) <= 0x067AF8A0L) < ((g_2345 ^ (l_2338 == (void*)0)) && (*l_2339))))
                    {
                        int **l_2347 = &g_2343;
                        step_hash(382);
                        (*l_2338) = (void*)0;
                        step_hash(383);
                        (*g_2343) = l_2346;
                        step_hash(384);
                        (*l_2250) = (l_2347 == &g_2343);
                    }
                    else
                    {
                        signed char l_2350 = 0L;
                        step_hash(386);
                        (*g_2343) = ((unsigned short)(l_2350 == (g_112 <= ((func_23(p_20, ((unsigned short)0x23FDL * (unsigned short)(&g_62 != (void*)0))) == p_20) <= ((short)(p_21 <= 5L) * (short)0L)))) << (unsigned short)2);
                    }
                }
                else
                {
                    signed char l_2366 = 0x6DL;
                    step_hash(389);
                    (*l_2246) ^= (*l_2339);
                    step_hash(390);
                    (*l_2246) &= ((signed char)((signed char)((int)func_26(p_20) + (int)p_21) << (signed char)((short)(g_193 == ((signed char)g_447 + (signed char)func_23(p_20, (0xB8L != (g_2214 > 0UL))))) - (short)1L)) << (signed char)g_874);
                    step_hash(391);
                    (*l_2246) &= p_21;
                }
            }
            step_hash(394);
            (*g_2343) = ((unsigned)0xF3EAABB4L / (unsigned)p_21);
            step_hash(395);
            return g_447;
        }
    }
    step_hash(398);
    return g_193;
}
static int func_23(unsigned p_24, int p_25)
{
    int *l_1696 = (void*)0;
    int *l_1697 = (void*)0;
    int *l_1698 = &g_38;
    int *l_1699 = &g_78;
    int *l_1700 = (void*)0;
    int *l_1701 = &g_874;
    int *l_1702 = &g_78;
    int *l_1703 = (void*)0;
    int *l_1704 = &g_112;
    int *l_1705 = &g_874;
    int l_1706 = 1L;
    int *l_1707 = (void*)0;
    int *l_1708 = &g_874;
    int l_1709 = 0x2225CEEFL;
    int *l_1710 = &l_1706;
    int *l_1711 = &g_313;
    int *l_1712 = &g_975;
    int *l_1713 = &g_112;
    int *l_1714 = (void*)0;
    int l_1715 = (-1L);
    int *l_1716 = &g_874;
    int *l_1717 = &g_447;
    int l_1718 = 0x72AE58BEL;
    int *l_1719 = &g_91;
    int *l_1720 = &g_313;
    int *l_1721 = &l_1718;
    int *l_1722 = &l_1709;
    int *l_1723 = &g_1268;
    int l_1724 = 0xCFFCECFFL;
    int *l_1725 = (void*)0;
    int *l_1726 = &g_874;
    int *l_1727 = &g_112;
    int l_1728 = 1L;
    int *l_1729 = (void*)0;
    int *l_1730 = &g_874;
    int *l_1731 = (void*)0;
    int *l_1732 = &l_1724;
    int *l_1733 = &l_1728;
    int l_1734 = 0x90AD4A59L;
    int *l_1735 = &l_1734;
    int *l_1736 = &l_1706;
    int *l_1737 = &g_313;
    int *l_1738 = &g_975;
    int *l_1739 = &g_112;
    int *l_1740 = (void*)0;
    int *l_1741 = &l_1715;
    int *l_1742 = &g_78;
    int *l_1743 = (void*)0;
    int *l_1744 = &g_1268;
    int *l_1745 = (void*)0;
    int *l_1746 = &g_38;
    int l_1747 = 1L;
    int *l_1748 = &g_78;
    int *l_1749 = &l_1706;
    int *l_1750 = &g_874;
    int l_1751 = 1L;
    int *l_1752 = &l_1728;
    int l_1753 = (-1L);
    int *l_1754 = (void*)0;
    int *l_1756 = &l_1747;
    int l_1757 = (-7L);
    int *l_1758 = &l_1747;
    int *l_1759 = &g_78;
    int *l_1760 = &l_1753;
    int *l_1761 = &g_447;
    int *l_1762 = &g_91;
    int l_1763 = 0xECA5873BL;
    int *l_1764 = (void*)0;
    int *l_1765 = &l_1724;
    int *l_1766 = &l_1724;
    int *l_1767 = (void*)0;
    unsigned char l_1768 = 0x6DL;
    int l_1771 = (-8L);
    step_hash(323);
    ++l_1768;
    step_hash(324);
    return l_1771;
}
static unsigned func_26(short p_27)
{
    int *l_1617 = &g_447;
    int *l_1618 = &g_38;
    int *l_1619 = &g_91;
    int l_1620 = 0x34B0ED82L;
    int *l_1621 = &g_313;
    int *l_1622 = &l_1620;
    int *l_1623 = &g_874;
    int l_1624 = 0x35B31D0AL;
    int *l_1625 = (void*)0;
    int *l_1626 = &g_447;
    int *l_1627 = &g_38;
    int *l_1628 = &g_313;
    int *l_1629 = (void*)0;
    int *l_1630 = &g_112;
    int l_1631 = (-5L);
    int *l_1632 = &g_447;
    int *l_1633 = &g_38;
    int *l_1634 = &g_975;
    int *l_1635 = &l_1624;
    int *l_1636 = &l_1631;
    int *l_1637 = (void*)0;
    int *l_1638 = &g_38;
    int *l_1639 = &g_447;
    int *l_1640 = &g_91;
    int *l_1641 = &g_38;
    int *l_1642 = &g_1268;
    int *l_1643 = &g_447;
    int *l_1644 = &g_78;
    int *l_1645 = &g_975;
    int *l_1646 = (void*)0;
    int *l_1647 = &g_38;
    int *l_1648 = &l_1631;
    int *l_1649 = &g_38;
    int *l_1650 = &g_1268;
    int *l_1651 = (void*)0;
    int *l_1652 = (void*)0;
    int l_1653 = 0xC50A1FC0L;
    int l_1654 = 0x899786E7L;
    int l_1655 = 5L;
    int *l_1656 = &l_1655;
    int *l_1657 = &g_91;
    int *l_1658 = &g_1268;
    int *l_1659 = &l_1624;
    int *l_1660 = &g_447;
    int *l_1661 = (void*)0;
    int *l_1662 = (void*)0;
    int *l_1663 = (void*)0;
    int l_1664 = 7L;
    int *l_1665 = &g_874;
    int *l_1666 = &l_1654;
    int l_1667 = 0x0AC199CFL;
    int *l_1668 = &l_1664;
    int *l_1669 = &g_91;
    int *l_1670 = &l_1667;
    int l_1671 = 1L;
    int *l_1672 = &g_78;
    int *l_1673 = &g_874;
    int *l_1674 = &g_313;
    int *l_1675 = &l_1654;
    int *l_1676 = (void*)0;
    int *l_1677 = &g_91;
    int *l_1678 = (void*)0;
    int *l_1679 = &g_447;
    int *l_1680 = &l_1620;
    int *l_1681 = (void*)0;
    int *l_1682 = &g_874;
    int l_1683 = 0xF5A689DBL;
    int *l_1684 = &g_112;
    int *l_1685 = &g_91;
    int *l_1686 = (void*)0;
    int l_1687 = 0L;
    int *l_1688 = &l_1653;
    int *l_1689 = &l_1624;
    int l_1690 = (-2L);
    int *l_1691 = &g_38;
    int *l_1692 = &l_1655;
    unsigned l_1693 = 0x6014BBEBL;
    step_hash(319);
    l_1617 = l_1617;
    step_hash(320);
    l_1693--;
    step_hash(321);
    return p_27;
}
static signed char func_30(short p_31, signed char p_32, unsigned p_33, unsigned p_34)
{
    int *l_37 = &g_38;
    int *l_312 = &g_313;
    short l_324 = (-9L);
    int l_377 = 0x1FB11325L;
    int l_435 = 0xFD5C622FL;
    unsigned l_464 = 4294967287UL;
    short l_477 = 1L;
    signed char l_507 = 8L;
    int l_738 = 4L;
    int l_820 = 0x95F14F36L;
    int l_838 = 0x6F619C15L;
    int l_863 = 0xBD58EF1EL;
    int l_869 = 5L;
    int l_892 = 0xC601C56FL;
    int l_939 = 0L;
    int l_946 = 0x7D5EA36CL;
    int l_1004 = 2L;
    int ***l_1034 = &g_62;
    unsigned l_1040 = 0xFF05AF4FL;
    step_hash(9);
    (*l_37) = 0xCCCAEA0AL;
    step_hash(118);
    (*l_312) &= (0x2737AE9FL > ((func_39(func_44(l_37, l_37, func_49(g_8, p_34), ((l_37 != (void*)0) != ((unsigned)((0xC3L ^ p_32) | 0x16L) + (unsigned)g_8))), g_63, g_63, p_34) < g_269) < g_8));
    step_hash(316);
    if (((unsigned)p_33 % (unsigned)p_34))
    {
        int *l_318 = &g_78;
        int l_335 = 0xA393618BL;
        int l_336 = 0x4594A1EEL;
        int l_346 = 7L;
        int l_390 = (-6L);
        int l_451 = 1L;
        int ***l_472 = &g_62;
        step_hash(152);
        for (p_32 = 0; (p_32 >= (-13)); --p_32)
        {
            int *l_323 = (void*)0;
            unsigned l_329 = 0x3A785BCAL;
            int l_350 = 1L;
            unsigned l_481 = 0x93085737L;
            step_hash(123);
            (*g_62) = l_318;
            step_hash(124);
            (*l_37) = (-3L);
            step_hash(151);
            if (((short)(0x62001A86L && ((signed char)p_34 >> (signed char)(g_38 < ((short)(p_34 < ((signed char)p_33 + (signed char)g_8)) >> (short)8)))) - (short)l_329))
            {
                unsigned l_334 = 4294967295UL;
                int l_371 = 0xDAA66EDBL;
                int l_402 = 0x24A4F3CDL;
                int l_407 = 1L;
                step_hash(126);
                (*g_62) = (void*)0;
                step_hash(142);
                if (((((unsigned char)255UL * (unsigned char)g_8) != (((+(g_306 <= l_329)) | ((signed char)(*l_318) * (signed char)g_187)) && ((g_195 >= l_334) < p_33))) < p_31))
                {
                    int *l_337 = &g_91;
                    int *l_338 = &g_78;
                    int *l_339 = &g_38;
                    int *l_340 = &l_335;
                    int *l_341 = &g_78;
                    int *l_342 = (void*)0;
                    int *l_343 = &g_112;
                    int *l_344 = &g_91;
                    int *l_345 = &g_91;
                    int *l_347 = (void*)0;
                    int *l_348 = &g_91;
                    int *l_349 = &l_336;
                    int *l_351 = &l_335;
                    int *l_352 = &g_313;
                    int *l_353 = &l_335;
                    int *l_354 = &g_112;
                    int *l_355 = &l_350;
                    int *l_356 = &g_313;
                    int *l_357 = &l_350;
                    int *l_358 = &g_313;
                    int *l_359 = &g_78;
                    int *l_360 = &g_38;
                    int *l_361 = &g_38;
                    int *l_362 = &l_346;
                    int *l_363 = &l_335;
                    int *l_364 = &g_91;
                    int *l_365 = &g_112;
                    int *l_366 = &g_38;
                    int *l_367 = (void*)0;
                    int *l_368 = (void*)0;
                    int *l_369 = &l_336;
                    int *l_370 = (void*)0;
                    int *l_372 = &l_350;
                    int *l_373 = &g_112;
                    int *l_374 = &g_91;
                    int *l_375 = &l_350;
                    int *l_376 = &g_78;
                    int *l_378 = &g_313;
                    int *l_379 = (void*)0;
                    int *l_380 = &l_336;
                    int *l_381 = &g_91;
                    int *l_382 = &l_336;
                    int *l_383 = &g_112;
                    int *l_384 = (void*)0;
                    int *l_385 = &g_38;
                    int *l_386 = (void*)0;
                    int *l_387 = &l_371;
                    int *l_388 = &g_112;
                    int *l_389 = &l_371;
                    int *l_391 = &g_91;
                    int *l_392 = &l_390;
                    int *l_393 = (void*)0;
                    int *l_394 = &g_38;
                    int *l_395 = &g_91;
                    int *l_396 = &g_112;
                    int *l_397 = &l_377;
                    int *l_398 = &g_38;
                    int *l_399 = &l_335;
                    int *l_400 = &g_313;
                    int *l_401 = &g_313;
                    int *l_403 = &l_336;
                    int *l_404 = (void*)0;
                    int *l_405 = &l_346;
                    int *l_406 = &g_313;
                    int *l_408 = (void*)0;
                    int *l_409 = &l_335;
                    int *l_410 = &g_38;
                    int *l_411 = &l_336;
                    int *l_412 = &l_336;
                    int *l_413 = (void*)0;
                    int *l_414 = &l_390;
                    int *l_415 = &l_335;
                    int *l_416 = &g_112;
                    int *l_417 = (void*)0;
                    int *l_418 = &l_377;
                    int *l_419 = (void*)0;
                    int *l_420 = &g_78;
                    int *l_421 = &l_346;
                    int *l_422 = &l_402;
                    int *l_423 = &l_346;
                    int *l_424 = &l_407;
                    int *l_425 = &l_350;
                    int *l_426 = &l_407;
                    int *l_427 = &l_377;
                    int *l_428 = &l_407;
                    int *l_429 = &l_407;
                    int *l_430 = &l_390;
                    int *l_431 = &l_350;
                    int *l_432 = &l_377;
                    int *l_433 = &l_336;
                    int *l_434 = &g_38;
                    int *l_436 = &g_91;
                    int *l_437 = &l_335;
                    int *l_438 = (void*)0;
                    int *l_439 = &l_335;
                    int *l_440 = &g_38;
                    int *l_441 = &l_346;
                    int *l_442 = (void*)0;
                    int *l_443 = &l_377;
                    int *l_444 = &l_402;
                    int *l_445 = &l_390;
                    int *l_446 = &g_313;
                    int *l_448 = &l_336;
                    int *l_449 = &l_377;
                    int *l_452 = &g_91;
                    int *l_453 = &l_402;
                    int *l_454 = &l_377;
                    int *l_455 = &g_38;
                    int *l_456 = &g_78;
                    int *l_457 = &l_350;
                    int *l_458 = (void*)0;
                    int *l_459 = (void*)0;
                    int *l_460 = &g_313;
                    step_hash(128);
                    (*g_62) = (*g_62);
                    step_hash(129);
                    (*l_312) = (*l_318);
                    step_hash(130);
                    g_461++;
                    step_hash(131);
                    if (p_31)
                        continue;
                }
                else
                {
                    step_hash(133);
                    (*g_62) = func_44(&l_377, func_44((*g_62), (*g_62), (*g_62), l_464), (*g_62), ((void*)0 != &l_407));
                    step_hash(140);
                    for (l_402 = (-11); (l_402 > (-14)); l_402--)
                    {
                        step_hash(137);
                        if (l_334)
                            break;
                        step_hash(138);
                        if (p_34)
                            break;
                        step_hash(139);
                        return g_91;
                    }
                    step_hash(141);
                    (*l_312) ^= (-(int)(g_106 || ((signed char)(0x1679L != g_187) * (signed char)0xFCL)));
                }
            }
            else
            {
                int *l_476 = &l_451;
                int *l_478 = &l_377;
                int *l_479 = &l_350;
                int *l_480 = &l_435;
                step_hash(144);
                (*g_63) = p_32;
                step_hash(149);
                for (g_187 = 0; (g_187 == 52); g_187 += 7)
                {
                    int ***l_473 = &g_62;
                    step_hash(148);
                    (*l_312) = ((p_31 && (l_472 == l_473)) < ((unsigned short)((***l_472) & (&l_350 != (**l_473))) % (unsigned short)g_112));
                }
                step_hash(150);
                l_481++;
            }
        }
        step_hash(153);
        return p_33;
    }
    else
    {
        int *l_486 = &g_447;
        int l_557 = 2L;
        int l_687 = 0xA76A31EEL;
        int l_723 = 1L;
        int l_726 = 0x3068C0FAL;
        int l_930 = 9L;
        int l_959 = 0x73950678L;
        int l_988 = 0xDF22B542L;
        unsigned l_1078 = 1UL;
        unsigned short l_1136 = 0x0BD9L;
        unsigned short l_1593 = 0x2EABL;
        int ***l_1613 = &g_62;
        step_hash(310);
        if (((unsigned char)func_39(l_486, func_44(func_44(l_486, func_49(p_32, g_461), &l_435, ((signed char)p_33 - (signed char)((unsigned short)g_306 >> (unsigned short)1))), &g_91, &l_435, p_34), &l_435, g_193) >> (unsigned char)(*l_486)))
        {
            unsigned char l_515 = 0x93L;
            int *l_518 = &l_377;
            int l_567 = 0x7BE39CE7L;
            int l_579 = 0x29176534L;
            int l_732 = 0xBC64B8D9L;
            int l_737 = 1L;
            int l_741 = 0x073FC81AL;
            step_hash(179);
            if ((*l_37))
            {
                int *l_491 = &g_447;
                int *l_492 = &l_435;
                int *l_493 = &g_38;
                int *l_494 = &g_112;
                int *l_495 = (void*)0;
                int *l_496 = &l_435;
                int *l_497 = &l_377;
                int *l_498 = &g_313;
                int *l_499 = &l_435;
                int *l_500 = &g_447;
                int *l_501 = (void*)0;
                int *l_502 = (void*)0;
                int *l_503 = &g_91;
                int *l_504 = (void*)0;
                int l_505 = 0L;
                int *l_506 = (void*)0;
                int *l_508 = &g_112;
                int *l_509 = &l_435;
                int *l_510 = &g_447;
                int *l_511 = (void*)0;
                int *l_512 = (void*)0;
                int *l_513 = &g_112;
                int *l_514 = &l_377;
                step_hash(157);
                (*l_312) = ((g_461 & g_269) == p_31);
                step_hash(158);
                l_515--;
                step_hash(159);
                (*g_62) = l_518;
            }
            else
            {
                int **l_527 = &l_486;
                int l_542 = 1L;
                int l_586 = 0xFB2388B4L;
                int *l_751 = &l_738;
                int *l_752 = &l_579;
                int *l_753 = &l_435;
                int *l_754 = &l_732;
                int *l_755 = &g_313;
                int *l_756 = &g_112;
                int *l_757 = &l_586;
                int *l_758 = (void*)0;
                int *l_759 = &l_726;
                int *l_760 = &l_726;
                int *l_761 = &l_557;
                int *l_762 = &l_741;
                int *l_763 = &l_741;
                int *l_764 = &l_741;
                int *l_765 = &l_738;
                int *l_766 = (void*)0;
                int *l_767 = (void*)0;
                int *l_768 = &g_38;
                int *l_769 = &l_377;
                int *l_770 = &l_579;
                int *l_771 = &l_726;
                int *l_772 = &l_738;
                int *l_773 = (void*)0;
                int *l_774 = &l_737;
                int *l_775 = &l_738;
                int *l_776 = &l_737;
                int *l_777 = &g_447;
                int *l_778 = (void*)0;
                int *l_779 = &g_38;
                int *l_780 = &g_112;
                int *l_781 = (void*)0;
                int *l_782 = (void*)0;
                int *l_783 = (void*)0;
                int *l_784 = &l_542;
                int *l_785 = &l_732;
                int *l_786 = (void*)0;
                int *l_787 = &l_557;
                int *l_788 = &g_38;
                int *l_789 = &l_723;
                int *l_790 = (void*)0;
                int *l_791 = &l_567;
                int *l_792 = &g_78;
                int *l_793 = &g_313;
                int *l_794 = &l_586;
                int *l_795 = &l_542;
                int *l_796 = &l_726;
                int *l_797 = &g_38;
                int *l_798 = &l_579;
                int *l_799 = (void*)0;
                int *l_800 = &g_313;
                int *l_801 = (void*)0;
                int *l_802 = (void*)0;
                int *l_803 = &l_732;
                int *l_804 = &l_732;
                int *l_805 = &l_586;
                int *l_806 = &l_557;
                int *l_807 = &l_542;
                int *l_808 = &l_579;
                int *l_809 = (void*)0;
                int *l_810 = &l_567;
                int *l_811 = &l_737;
                int *l_812 = &l_741;
                int *l_813 = (void*)0;
                int *l_814 = &l_687;
                int *l_815 = &l_586;
                int l_816 = 0xF1872BA1L;
                int *l_817 = (void*)0;
                int *l_818 = &l_567;
                int *l_819 = &g_78;
                int *l_821 = &l_542;
                int *l_822 = &l_741;
                int l_823 = (-7L);
                int *l_824 = (void*)0;
                int *l_825 = &l_823;
                int *l_826 = &l_579;
                int *l_827 = &l_435;
                int *l_828 = &l_567;
                int *l_829 = &l_737;
                int *l_830 = &l_738;
                int *l_831 = &l_567;
                int *l_832 = (void*)0;
                int *l_833 = (void*)0;
                int *l_834 = (void*)0;
                int *l_835 = &l_741;
                int *l_836 = &l_816;
                int *l_837 = (void*)0;
                int *l_839 = &l_723;
                int *l_840 = (void*)0;
                int *l_841 = &l_816;
                int *l_842 = &l_567;
                int *l_843 = &g_91;
                int *l_844 = &l_542;
                int *l_845 = &l_377;
                int *l_846 = (void*)0;
                int *l_848 = &l_377;
                int *l_849 = &g_313;
                int *l_850 = &l_687;
                int *l_851 = (void*)0;
                int *l_852 = (void*)0;
                int *l_853 = (void*)0;
                int *l_854 = (void*)0;
                int *l_855 = &g_447;
                int *l_856 = &l_542;
                int *l_857 = &g_447;
                int *l_858 = &l_741;
                int *l_859 = &g_78;
                int *l_860 = &l_737;
                int l_861 = 0xEBB0A384L;
                int *l_862 = (void*)0;
                int *l_864 = &l_687;
                int *l_865 = &l_737;
                int *l_866 = (void*)0;
                int *l_867 = &l_738;
                int *l_868 = (void*)0;
                int *l_870 = &l_737;
                int *l_871 = (void*)0;
                int *l_872 = (void*)0;
                int *l_873 = (void*)0;
                int *l_875 = &g_78;
                int *l_876 = &l_823;
                int *l_877 = &l_869;
                int *l_878 = &l_542;
                int *l_879 = &g_78;
                int *l_880 = &l_557;
                int *l_881 = &l_838;
                int *l_882 = &g_91;
                int l_883 = 0L;
                int *l_884 = &l_557;
                int *l_885 = &l_586;
                int *l_886 = &l_883;
                int *l_887 = &g_78;
                int *l_888 = &g_38;
                int *l_889 = &l_820;
                int *l_890 = &g_112;
                int *l_891 = &l_863;
                int *l_893 = &l_738;
                int *l_894 = &l_586;
                int *l_895 = (void*)0;
                int *l_896 = &l_567;
                int *l_897 = &l_542;
                int *l_898 = &l_869;
                int *l_899 = &g_874;
                int *l_900 = &l_892;
                int *l_901 = (void*)0;
                int *l_902 = (void*)0;
                int *l_903 = &l_732;
                int *l_904 = &l_435;
                int *l_905 = &l_861;
                int *l_906 = (void*)0;
                int *l_907 = &g_38;
                int l_908 = (-10L);
                int *l_909 = &l_908;
                int *l_910 = &g_874;
                int *l_911 = &l_861;
                int *l_912 = &g_313;
                int *l_914 = &l_823;
                int *l_915 = &g_313;
                int *l_916 = &l_861;
                int *l_917 = (void*)0;
                int *l_918 = &g_313;
                int *l_919 = (void*)0;
                int l_920 = (-1L);
                int *l_921 = &l_567;
                int *l_922 = &l_435;
                int *l_923 = &l_883;
                int *l_925 = &g_91;
                int *l_926 = &l_687;
                int *l_927 = &l_377;
                int *l_928 = &l_820;
                int *l_929 = &l_567;
                int *l_931 = &l_823;
                int *l_932 = &g_313;
                int *l_933 = &g_78;
                int *l_934 = &g_447;
                int *l_935 = &l_908;
                int *l_936 = &l_377;
                int *l_937 = &l_732;
                int *l_938 = &l_435;
                int *l_940 = &l_557;
                int *l_941 = &l_377;
                int *l_942 = &l_723;
                int *l_943 = &l_723;
                int *l_944 = &l_738;
                int *l_945 = &g_447;
                int *l_947 = &g_313;
                int *l_948 = &l_737;
                int *l_950 = &l_737;
                int *l_951 = &l_816;
                int *l_952 = &l_687;
                int *l_953 = &g_874;
                int *l_954 = &l_741;
                int *l_955 = &l_687;
                int *l_956 = &l_892;
                int *l_957 = &l_723;
                int *l_958 = &g_313;
                int *l_960 = &l_816;
                int *l_961 = &l_820;
                int *l_962 = &l_946;
                int *l_963 = &l_732;
                int *l_964 = &l_377;
                int *l_965 = &l_883;
                int *l_966 = &l_557;
                int *l_967 = &g_874;
                int *l_968 = &l_732;
                int *l_969 = (void*)0;
                int *l_970 = &l_687;
                int *l_971 = (void*)0;
                int *l_972 = &l_435;
                int *l_973 = &l_930;
                int *l_974 = &l_557;
                int *l_976 = &l_863;
                int *l_977 = &l_869;
                int *l_978 = (void*)0;
                int *l_979 = &l_687;
                int *l_980 = &g_447;
                int *l_981 = &g_112;
                int *l_982 = &l_892;
                int *l_983 = &l_883;
                int *l_984 = &l_542;
                int *l_985 = &l_883;
                int *l_986 = &l_732;
                int *l_987 = &l_687;
                int l_989 = 7L;
                int *l_990 = &l_883;
                int *l_991 = &l_737;
                int *l_992 = &l_820;
                int *l_993 = &g_313;
                int *l_994 = &l_741;
                int *l_995 = &g_975;
                int *l_996 = &l_567;
                int *l_997 = (void*)0;
                int *l_998 = &l_988;
                int *l_999 = &l_738;
                int *l_1001 = &l_579;
                int *l_1002 = &l_586;
                int *l_1003 = &l_687;
                int *l_1005 = &l_557;
                int *l_1006 = &l_687;
                int *l_1007 = (void*)0;
                int *l_1008 = &g_313;
                int *l_1009 = &g_91;
                int *l_1010 = &l_687;
                int *l_1011 = &l_435;
                int *l_1012 = &l_586;
                int *l_1013 = &l_567;
                int *l_1014 = &l_892;
                int *l_1015 = &l_863;
                int *l_1016 = &l_988;
                int *l_1017 = &l_908;
                int *l_1018 = &l_586;
                int *l_1019 = &l_908;
                int *l_1020 = &l_820;
                int *l_1021 = &l_732;
                int *l_1022 = &l_816;
                step_hash(172);
                if (((unsigned char)((~((unsigned short)(((short)(p_34 ^ g_447) * (short)(((unsigned short)(*l_312) + (unsigned short)((void*)0 == l_527)) && 0x6FBFL)) <= ((int)(((unsigned short)(p_34 && ((*l_518) >= ((0UL ^ (*l_518)) < (*l_518)))) - (unsigned short)(*l_312)) < p_31) % (int)(**g_62))) / (unsigned short)p_31)) ^ g_112) >> (unsigned char)0))
                {
                    int *l_534 = (void*)0;
                    int l_537 = 0x3B3F70EDL;
                    step_hash(169);
                    for (g_91 = 0; (g_91 <= (-28)); g_91 -= 4)
                    {
                        int *l_535 = &g_447;
                        int *l_536 = &l_435;
                        int *l_538 = &g_38;
                        int l_539 = 0xE367F9ACL;
                        int *l_540 = &g_313;
                        int *l_541 = &l_539;
                        int *l_543 = &g_112;
                        int *l_544 = &g_38;
                        int *l_545 = &g_447;
                        int *l_546 = &l_435;
                        int *l_547 = &l_539;
                        int *l_548 = (void*)0;
                        int *l_549 = &g_447;
                        int *l_550 = &l_542;
                        int *l_551 = &g_38;
                        int *l_552 = &l_377;
                        int *l_553 = &l_377;
                        int *l_554 = &l_539;
                        int *l_555 = &g_38;
                        int *l_556 = &g_38;
                        int *l_558 = &l_377;
                        int *l_559 = &l_542;
                        int *l_560 = &l_557;
                        int *l_561 = (void*)0;
                        int l_562 = 0xE840700BL;
                        int *l_563 = &l_562;
                        int *l_564 = &l_539;
                        int *l_565 = &l_562;
                        int *l_566 = &l_539;
                        int *l_568 = &g_38;
                        int *l_569 = &l_539;
                        int *l_570 = &g_447;
                        int *l_571 = (void*)0;
                        int *l_572 = &l_562;
                        int *l_573 = &l_539;
                        int l_574 = 0x0240F325L;
                        int *l_575 = (void*)0;
                        int *l_576 = &l_567;
                        int *l_577 = (void*)0;
                        int *l_578 = &l_567;
                        int *l_580 = (void*)0;
                        int l_581 = 0x1C68F026L;
                        int *l_582 = (void*)0;
                        int *l_583 = &g_38;
                        int *l_584 = &l_377;
                        int *l_585 = &l_435;
                        int *l_587 = (void*)0;
                        step_hash(165);
                        (*g_62) = func_44(l_534, (*l_527), l_518, g_450);
                        step_hash(166);
                        (*l_486) = (+p_33);
                        step_hash(167);
                        ++g_588;
                        step_hash(168);
                        (*l_546) ^= ((short)g_78 * (short)((signed char)(*l_559) + (signed char)((int)0L % (int)g_106)));
                    }
                }
                else
                {
                    int *l_597 = &g_91;
                    int *l_598 = &l_579;
                    int *l_599 = &g_91;
                    int *l_600 = (void*)0;
                    int *l_601 = &l_586;
                    int *l_602 = &l_579;
                    int *l_603 = &l_586;
                    int *l_604 = (void*)0;
                    int *l_605 = &l_542;
                    int *l_606 = (void*)0;
                    int *l_607 = &l_586;
                    int *l_608 = &g_313;
                    int *l_609 = &l_586;
                    int *l_610 = &l_435;
                    int *l_611 = &g_38;
                    int *l_612 = &l_567;
                    int *l_613 = &l_567;
                    int *l_614 = &g_91;
                    int *l_615 = (void*)0;
                    int *l_616 = (void*)0;
                    int *l_617 = &g_447;
                    int *l_618 = (void*)0;
                    int *l_619 = &g_38;
                    int *l_620 = (void*)0;
                    int *l_621 = &g_78;
                    int *l_622 = &g_78;
                    int *l_623 = &l_579;
                    int l_624 = 0x8CB365A6L;
                    int *l_625 = (void*)0;
                    int *l_626 = (void*)0;
                    int *l_627 = &l_557;
                    int *l_628 = (void*)0;
                    int *l_629 = &g_38;
                    int *l_630 = &g_447;
                    int *l_631 = &l_624;
                    int *l_632 = &l_377;
                    int *l_633 = &g_38;
                    int *l_634 = &l_435;
                    int *l_635 = &l_542;
                    int *l_636 = &g_38;
                    int *l_637 = (void*)0;
                    int l_638 = 0L;
                    int *l_639 = &l_579;
                    int *l_640 = &l_377;
                    int *l_641 = &g_78;
                    int *l_642 = &l_624;
                    int *l_643 = &g_38;
                    int *l_644 = &g_447;
                    int *l_645 = &g_447;
                    step_hash(171);
                    g_646++;
                }
                step_hash(177);
                if (((&l_377 != g_649) ^ g_195))
                {
                    step_hash(174);
                    (*l_527) = (*g_62);
                }
                else
                {
                    int *l_650 = &l_435;
                    int *l_651 = &l_435;
                    int *l_652 = &g_313;
                    int *l_653 = &l_557;
                    int *l_654 = &g_313;
                    int *l_655 = &g_447;
                    int *l_656 = &l_377;
                    int *l_657 = (void*)0;
                    int *l_658 = &l_542;
                    int *l_659 = (void*)0;
                    int *l_660 = &g_38;
                    int *l_661 = &l_579;
                    int *l_662 = &g_112;
                    int *l_663 = &g_78;
                    int *l_664 = &l_567;
                    int *l_665 = (void*)0;
                    int *l_666 = &g_447;
                    int *l_667 = &g_313;
                    int *l_668 = &g_91;
                    int *l_669 = &l_579;
                    int *l_670 = &l_567;
                    int *l_671 = &g_447;
                    int *l_672 = (void*)0;
                    int *l_673 = &g_91;
                    int *l_674 = (void*)0;
                    int *l_675 = &g_313;
                    int *l_676 = &l_435;
                    int *l_677 = &l_557;
                    int *l_678 = &g_78;
                    int *l_679 = &l_435;
                    int l_680 = (-8L);
                    int *l_681 = (void*)0;
                    int *l_682 = (void*)0;
                    int *l_683 = &l_377;
                    int *l_684 = &l_435;
                    int *l_685 = (void*)0;
                    int *l_686 = &l_680;
                    int *l_688 = &l_557;
                    int *l_689 = &l_542;
                    int *l_690 = &l_542;
                    int *l_691 = (void*)0;
                    int *l_692 = (void*)0;
                    int *l_693 = &l_435;
                    int *l_694 = (void*)0;
                    int *l_695 = &g_91;
                    int *l_696 = &g_78;
                    int *l_697 = &g_38;
                    int *l_698 = &l_687;
                    int *l_699 = &g_313;
                    int *l_700 = &g_91;
                    int *l_701 = (void*)0;
                    int *l_702 = &l_557;
                    int *l_703 = &l_377;
                    int *l_704 = &l_435;
                    int *l_705 = &l_579;
                    int *l_706 = (void*)0;
                    int *l_707 = &l_586;
                    int *l_708 = &l_567;
                    int *l_709 = &g_38;
                    int *l_710 = &l_435;
                    int *l_711 = &l_435;
                    int *l_712 = (void*)0;
                    int *l_713 = &l_680;
                    int *l_714 = &l_542;
                    int l_715 = 0xC4FD2FFAL;
                    int *l_716 = &g_447;
                    int *l_717 = (void*)0;
                    int *l_718 = &l_567;
                    int *l_719 = &l_557;
                    int *l_720 = (void*)0;
                    int *l_721 = &g_78;
                    int *l_722 = &l_715;
                    int *l_724 = &g_38;
                    int *l_725 = &l_723;
                    int *l_727 = (void*)0;
                    int *l_728 = &g_78;
                    int *l_729 = (void*)0;
                    int *l_730 = &g_38;
                    int *l_731 = &g_313;
                    int *l_733 = &l_542;
                    int *l_734 = &g_91;
                    int *l_735 = (void*)0;
                    int l_736 = 0x2AF359DAL;
                    int *l_739 = &l_680;
                    int *l_740 = &l_738;
                    int *l_742 = &l_542;
                    int *l_743 = (void*)0;
                    int *l_744 = &l_377;
                    int *l_745 = &l_435;
                    int *l_746 = &g_112;
                    int *l_747 = (void*)0;
                    step_hash(176);
                    g_748++;
                }
                step_hash(178);
                ++g_1023;
            }
            step_hash(180);
            (*l_518) ^= (-1L);
            step_hash(181);
            (*l_312) &= ((unsigned short)((signed char)1L - (signed char)(((short)((int)(func_39((*g_62), func_44((*g_62), (*g_62), (*g_62), (*l_486)), &l_930, (*l_518)) < 0xEAL) - (int)p_33) - (short)p_31) < (-3L))) >> (unsigned short)14);
            step_hash(195);
            if ((l_1034 != &g_62))
            {
                int *l_1037 = &l_567;
                step_hash(183);
                (*l_312) ^= (((signed char)((((void*)0 == &g_62) && func_39(l_1037, (**l_1034), (**l_1034), ((g_193 | (*g_63)) != ((*l_518) != (((unsigned short)65534UL >> (unsigned short)12) <= g_187))))) || 254UL) % (signed char)p_34) != 0xD5L);
                step_hash(184);
                return g_913;
            }
            else
            {
                int **l_1051 = &l_312;
                unsigned short l_1073 = 0UL;
                step_hash(191);
                if ((l_1040 != (((short)g_874 * (short)p_34) | 1UL)))
                {
                    int *l_1052 = &l_687;
                    int *l_1053 = &g_38;
                    int l_1054 = 0xDD4222DEL;
                    int *l_1055 = &l_820;
                    int *l_1056 = &l_1004;
                    int *l_1057 = &l_687;
                    int *l_1058 = &l_1054;
                    int *l_1059 = &l_892;
                    int *l_1060 = &l_738;
                    int *l_1061 = &l_863;
                    int *l_1062 = &l_737;
                    int *l_1063 = &g_874;
                    int *l_1064 = &l_930;
                    int *l_1065 = &l_930;
                    int *l_1066 = &l_435;
                    int *l_1067 = &g_313;
                    int *l_1068 = &l_863;
                    int *l_1069 = (void*)0;
                    int *l_1070 = &l_1004;
                    int *l_1071 = (void*)0;
                    int l_1072 = 5L;
                    step_hash(187);
                    --l_1073;
                    step_hash(188);
                    l_518 = (void*)0;
                }
                else
                {
                    step_hash(190);
                    return g_313;
                }
                step_hash(192);
                (*l_37) = 0xC9470A19L;
                step_hash(193);
                (**l_1051) ^= (func_39((*g_62), (**l_1034), &l_988, p_32) <= ((signed char)0x5BL << (signed char)g_461));
                step_hash(194);
                (**l_1051) ^= ((g_112 || p_34) >= ((g_38 || l_1078) != p_34));
            }
        }
        else
        {
            int *l_1085 = &l_738;
            int l_1087 = (-7L);
            int l_1117 = 0xE0EEE7F0L;
            int l_1256 = 5L;
            unsigned char l_1325 = 0x73L;
            int l_1549 = 0xA3022905L;
            int l_1552 = 0x8B5EAA5FL;
            step_hash(197);
            (*g_62) = (*g_62);
            step_hash(236);
            for (l_892 = 0; (l_892 < (-18)); l_892--)
            {
                int *l_1084 = &l_930;
                int l_1086 = (-1L);
                int l_1097 = 2L;
                int l_1109 = 1L;
                int l_1259 = 0xD71E673BL;
                int l_1267 = 0xA3C2F25FL;
            }
            step_hash(268);
            for (g_106 = 0; (g_106 <= (-22)); g_106 -= 8)
            {
                int l_1343 = 0xBCD1A088L;
                step_hash(255);
                for (l_435 = (-24); (l_435 < 24); l_435++)
                {
                    int l_1334 = 2L;
                    step_hash(243);
                    l_1334 = p_32;
                    step_hash(244);
                    (**l_1034) = (**l_1034);
                    step_hash(249);
                    for (l_892 = 0; (l_892 <= 14); l_892 += 1)
                    {
                        step_hash(248);
                        return g_874;
                    }
                    step_hash(254);
                    for (g_748 = 0; (g_748 <= 42); g_748++)
                    {
                        step_hash(253);
                        return l_1334;
                    }
                }
                step_hash(256);
                (**l_1034) = (**l_1034);
                step_hash(267);
                for (g_78 = 0; (g_78 > (-28)); --g_78)
                {
                    int *l_1346 = &g_38;
                    step_hash(266);
                    for (l_726 = 0; (l_726 > 11); l_726++)
                    {
                        int l_1344 = 1L;
                        int l_1345 = 0x7FDC5D3EL;
                        step_hash(263);
                        l_1343 &= (-1L);
                        step_hash(264);
                        if (l_1344)
                            continue;
                        step_hash(265);
                        l_1346 = func_49(l_1343, l_1345);
                    }
                }
            }
            step_hash(309);
            for (g_313 = 27; (g_313 >= (-19)); --g_313)
            {
                signed char l_1349 = 1L;
                int l_1417 = 0xF20C56E5L;
                int l_1446 = 0x6FC39C69L;
                int l_1505 = 0xD14B63FBL;
                int l_1582 = (-1L);
                int l_1585 = (-3L);
                short l_1608 = 0x8948L;
            }
        }
        step_hash(315);
        for (g_112 = 21; (g_112 < (-9)); --g_112)
        {
            step_hash(314);
            (*l_37) = 0xDC1E1DE9L;
        }
    }
    step_hash(317);
    return (*l_37);
}
static signed char func_39(int * p_40, int * p_41, int * p_42, int p_43)
{
    unsigned short l_85 = 1UL;
    int l_132 = 0xE5685F08L;
    int l_143 = 1L;
    int ***l_154 = (void*)0;
    int l_273 = 9L;
    int l_279 = (-6L);
    int **l_309 = (void*)0;
    step_hash(25);
    for (g_38 = 0; (g_38 >= (-11)); g_38 -= 2)
    {
        int *l_81 = &g_78;
        int *l_82 = &g_78;
        int *l_83 = &g_78;
        int *l_84 = &g_78;
        step_hash(22);
        --l_85;
        step_hash(23);
        (*l_82) = (8L < g_8);
        step_hash(24);
        (*g_62) = func_44((*g_62), func_44((*g_62), (*g_62), p_40, g_38), l_81, p_43);
    }
    step_hash(116);
    for (g_38 = 0; (g_38 <= 20); g_38 += 2)
    {
        int *l_90 = &g_78;
        int l_92 = 0x6FEDEA8FL;
        int *l_93 = &l_92;
        int *l_94 = &g_91;
        int *l_95 = &g_91;
        int *l_96 = (void*)0;
        int *l_97 = &l_92;
        int *l_98 = (void*)0;
        int *l_99 = (void*)0;
        int *l_100 = &g_91;
        int *l_101 = &g_78;
        int *l_102 = (void*)0;
        int *l_103 = &l_92;
        int *l_104 = &l_92;
        int *l_105 = &l_92;
        int *l_107 = &l_92;
        int *l_108 = &g_78;
        int *l_109 = &g_91;
        int *l_110 = &l_92;
        int *l_111 = &g_78;
        int *l_113 = &l_92;
        int *l_114 = &l_92;
        int *l_115 = &g_91;
        int *l_116 = &g_78;
        int *l_117 = &l_92;
        int *l_118 = &g_91;
        int *l_119 = &g_78;
        int *l_120 = &g_78;
        int *l_121 = &g_91;
        int l_122 = (-7L);
        int *l_123 = &g_78;
        int *l_125 = &l_122;
        int *l_126 = &l_92;
        int *l_127 = &l_122;
        int *l_128 = &g_112;
        int *l_129 = &g_112;
        int *l_130 = &g_112;
        int *l_131 = (void*)0;
        int *l_133 = &l_132;
        int *l_134 = &l_132;
        int *l_135 = &g_91;
        int *l_136 = &l_132;
        int *l_137 = &l_122;
        int *l_138 = &g_91;
        int *l_139 = &l_132;
        int *l_140 = &l_132;
        int *l_142 = (void*)0;
        int *l_144 = (void*)0;
        int *l_145 = &l_92;
        int *l_146 = &g_91;
        unsigned l_147 = 0x0045B34FL;
        int l_183 = (-1L);
        step_hash(29);
        --l_147;
        step_hash(115);
        if ((((signed char)(((-1L) == p_43) | ((short)(l_154 != (void*)0) << (short)10)) >> (signed char)g_106) == (((short)((unsigned short)((g_8 | g_8) >= (*l_111)) << (unsigned short)(+(*l_105))) >> (short)g_106) && (*p_42))))
        {
            unsigned l_159 = 0x429F1C2FL;
            int l_188 = 0xE94C9196L;
            int l_194 = 0L;
            unsigned l_196 = 0xD39EDE03L;
            step_hash(31);
            l_159--;
            step_hash(75);
            for (g_106 = 19; (g_106 > (-16)); g_106 -= 4)
            {
                int *l_168 = &g_78;
                int ***l_219 = &g_62;
                step_hash(39);
                for (p_43 = (-17); (p_43 != 2); p_43 += 6)
                {
                    step_hash(38);
                    (*g_62) = (*g_62);
                }
                step_hash(58);
                if (((signed char)(l_168 == (*g_62)) + (signed char)((**g_62) == ((unsigned)((unsigned short)((((signed char)l_159 >> (signed char)3) ^ p_43) | ((signed char)((short)(*l_103) - (short)((*p_42) < ((unsigned char)(((unsigned char)l_183 * (unsigned char)((*l_168) && p_43)) || l_159) << (unsigned char)4))) >> (signed char)4)) >> (unsigned short)3) + (unsigned)p_43))))
                {
                    unsigned char l_189 = 249UL;
                    int l_207 = 3L;
                    step_hash(48);
                    if (((unsigned short)((-(signed char)p_43) ^ (l_159 > g_141)) >> (unsigned short)((&g_63 == &p_41) == g_106)))
                    {
                        step_hash(42);
                        g_187 = l_159;
                    }
                    else
                    {
                        int l_192 = 0xB5784CD6L;
                        step_hash(44);
                        --l_189;
                        step_hash(45);
                        l_196--;
                        step_hash(46);
                        if ((*p_42))
                            continue;
                        step_hash(47);
                        (*l_97) |= (-2L);
                    }
                    step_hash(55);
                    for (l_85 = 0; (l_85 > 11); ++l_85)
                    {
                        unsigned l_208 = 0x304AAC6DL;
                        step_hash(52);
                        (*g_62) = p_41;
                        step_hash(53);
                        (*l_130) = ((unsigned char)(!249UL) + (unsigned char)(((((signed char)((((short)(((g_8 || (((*l_168) && (((((!(*l_138)) >= p_43) || p_43) >= (p_42 != (*g_62))) & 0L)) != (*p_42))) || p_43) != 65526UL) >> (short)9) <= 255UL) <= 0x90E32AAFL) / (signed char)l_188) > 0x4900L) <= g_124) < p_43));
                        step_hash(54);
                        l_208++;
                    }
                }
                else
                {
                    step_hash(57);
                    return (*l_168);
                }
                step_hash(59);
                (*l_95) = (0xBCL < ((g_38 || ((unsigned char)((unsigned char)g_38 * (unsigned char)g_8) % (unsigned char)g_141)) && p_43));
                step_hash(74);
                if ((l_188 > (0xAB31L >= g_195)))
                {
                    unsigned l_222 = 0x90A817FAL;
                    step_hash(61);
                    (*l_138) = ((unsigned char)(0UL & 0x3693L) + (unsigned char)((unsigned)p_43 - (unsigned)(l_219 != &g_62)));
                    step_hash(62);
                    (**l_219) = (*g_62);
                    step_hash(70);
                    if (((((unsigned short)0x0601L << (unsigned short)(***l_219)) != g_195) == p_43))
                    {
                        step_hash(64);
                        if ((*p_41))
                            break;
                        step_hash(65);
                        p_40 = (*g_62);
                        step_hash(66);
                        (*l_129) = (*p_41);
                        step_hash(67);
                        (*l_95) ^= (**g_62);
                    }
                    else
                    {
                        step_hash(69);
                        (*l_101) = l_222;
                    }
                    step_hash(71);
                    (*l_133) ^= (g_193 >= 0xC0L);
                }
                else
                {
                    step_hash(73);
                    (*l_104) |= (*g_63);
                }
            }
            step_hash(76);
            (*l_136) = ((signed char)((short)((unsigned char)255UL << (unsigned char)((signed char)((signed char)(*l_125) << (signed char)2) >> (signed char)5)) - (short)(p_43 > ((int)((unsigned short)p_43 << (unsigned short)4) % (int)(p_43 & (g_91 > (((void*)0 == &l_97) != p_43)))))) + (signed char)0x3AL);
            step_hash(108);
            if ((**g_62))
            {
                step_hash(78);
                (*l_134) = (*g_63);
                step_hash(79);
                return g_112;
            }
            else
            {
                int l_251 = 1L;
                int l_286 = 0xF4B66F68L;
                step_hash(105);
                if ((**g_62))
                {
                    step_hash(92);
                    if (((short)((signed char)(*l_118) + (signed char)(g_187 || g_91)) << (short)4))
                    {
                        step_hash(83);
                        if ((**g_62))
                            break;
                        step_hash(84);
                        (*l_123) = ((signed char)((p_43 | g_91) < ((unsigned char)g_195 << (unsigned char)((signed char)g_78 << (signed char)6))) - (signed char)((void*)0 != l_154));
                        step_hash(85);
                        if ((*p_42))
                            break;
                        step_hash(86);
                        (*g_62) = p_41;
                    }
                    else
                    {
                        step_hash(88);
                        (*l_127) &= ((unsigned)(&g_63 != (void*)0) / (unsigned)(-5L));
                        step_hash(89);
                        (*g_62) = (*g_62);
                        step_hash(90);
                        (*g_62) = p_42;
                        step_hash(91);
                        (*l_107) |= l_251;
                    }
                }
                else
                {
                    signed char l_260 = 1L;
                    int **l_263 = &l_140;
                    signed char l_268 = (-1L);
                    step_hash(94);
                    l_260 |= ((((unsigned short)((unsigned short)((signed char)p_43 >> (signed char)2) << (unsigned short)4) - (unsigned short)((*p_40) == (p_43 <= (*g_63)))) ^ (255UL <= ((void*)0 != p_40))) <= ((short)((*g_63) | (l_251 ^ p_43)) << (short)p_43));
                    step_hash(104);
                    if (((unsigned short)(&p_42 != l_263) << (unsigned short)3))
                    {
                        unsigned char l_264 = 0xC5L;
                        int l_267 = 0x79B7C538L;
                        int *l_270 = (void*)0;
                        int *l_271 = &l_143;
                        int *l_272 = (void*)0;
                        int *l_274 = &l_122;
                        int *l_275 = (void*)0;
                        int *l_276 = &l_143;
                        int *l_277 = &l_92;
                        int *l_278 = &l_143;
                        int *l_280 = (void*)0;
                        int *l_281 = &l_279;
                        int *l_282 = &l_194;
                        int *l_283 = &l_132;
                        int *l_284 = &g_78;
                        int *l_285 = &l_122;
                        int *l_287 = &l_286;
                        int *l_288 = &l_132;
                        int *l_289 = &l_286;
                        int *l_290 = &l_286;
                        step_hash(96);
                        (*l_120) = 1L;
                        step_hash(97);
                        l_264++;
                        step_hash(98);
                        (*l_145) &= (*g_63);
                        step_hash(99);
                        g_291++;
                    }
                    else
                    {
                        int ***l_296 = (void*)0;
                        int l_299 = 0x85A720D6L;
                        step_hash(101);
                        (*l_125) = ((p_43 | (p_43 > (((unsigned short)((void*)0 == l_296) * (unsigned short)(((unsigned short)(**l_263) * (unsigned short)g_291) < l_299)) < ((unsigned short)p_43 >> (unsigned short)7)))) == ((short)((short)((*g_62) != (*g_62)) << (short)8) << (short)0));
                        step_hash(102);
                        g_306--;
                        step_hash(103);
                        return g_187;
                    }
                }
                step_hash(106);
                l_309 = &g_63;
                step_hash(107);
                (*l_309) = (*g_62);
            }
        }
        else
        {
            step_hash(114);
            for (g_187 = 20; (g_187 == 59); g_187++)
            {
                step_hash(113);
                return g_91;
            }
        }
    }
    step_hash(117);
    return p_43;
}
static int * func_44(int * p_45, int * p_46, int * p_47, unsigned p_48)
{
    int ***l_75 = (void*)0;
    int *l_76 = (void*)0;
    int *l_77 = &g_78;
    step_hash(16);
    (*l_77) |= ((short)(p_48 & ((!(-1L)) == g_8)) * (short)(-(int)(1UL >= ((signed char)(g_8 < p_48) >> (signed char)((unsigned char)((void*)0 != l_75) + (unsigned char)g_38)))));
    step_hash(17);
    return (*g_62);
}
static int * func_49(signed char p_50, int p_51)
{
    int l_52 = 0x9A75015EL;
    int l_61 = 1L;
    int ***l_64 = (void*)0;
    int ***l_65 = &g_62;
    step_hash(11);
    l_61 ^= (l_52 ^ (((signed char)g_38 + (signed char)g_8) == (((unsigned char)l_52 % (unsigned char)l_52) <= ((unsigned short)g_8 * (unsigned short)((((unsigned char)(l_52 | (0x3CL & (p_51 > 0xE7L))) >> (unsigned char)4) > 0x0C01L) & 0L)))));
    step_hash(12);
    (*l_65) = g_62;
    step_hash(13);
    (***l_65) = (*g_63);
    step_hash(14);
    return (*g_62);
}
void csmith_compute_hash(void)
{
    transparent_crc(g_8, "g_8", print_hash_value);
    transparent_crc(g_38, "g_38", print_hash_value);
    transparent_crc(g_78, "g_78", print_hash_value);
    transparent_crc(g_91, "g_91", print_hash_value);
    transparent_crc(g_106, "g_106", print_hash_value);
    transparent_crc(g_112, "g_112", print_hash_value);
    transparent_crc(g_124, "g_124", print_hash_value);
    transparent_crc(g_141, "g_141", print_hash_value);
    transparent_crc(g_187, "g_187", print_hash_value);
    transparent_crc(g_193, "g_193", print_hash_value);
    transparent_crc(g_195, "g_195", print_hash_value);
    transparent_crc(g_269, "g_269", print_hash_value);
    transparent_crc(g_291, "g_291", print_hash_value);
    transparent_crc(g_306, "g_306", print_hash_value);
    transparent_crc(g_313, "g_313", print_hash_value);
    transparent_crc(g_447, "g_447", print_hash_value);
    transparent_crc(g_450, "g_450", print_hash_value);
    transparent_crc(g_461, "g_461", print_hash_value);
    transparent_crc(g_588, "g_588", print_hash_value);
    transparent_crc(g_646, "g_646", print_hash_value);
    transparent_crc(g_748, "g_748", print_hash_value);
    transparent_crc(g_847, "g_847", print_hash_value);
    transparent_crc(g_874, "g_874", print_hash_value);
    transparent_crc(g_913, "g_913", print_hash_value);
    transparent_crc(g_924, "g_924", print_hash_value);
    transparent_crc(g_949, "g_949", print_hash_value);
    transparent_crc(g_975, "g_975", print_hash_value);
    transparent_crc(g_1000, "g_1000", print_hash_value);
    transparent_crc(g_1023, "g_1023", print_hash_value);
    transparent_crc(g_1268, "g_1268", print_hash_value);
    transparent_crc(g_1272, "g_1272", print_hash_value);
    transparent_crc(g_1521, "g_1521", print_hash_value);
    transparent_crc(g_1588, "g_1588", print_hash_value);
    transparent_crc(g_1755, "g_1755", print_hash_value);
    transparent_crc(g_1787, "g_1787", print_hash_value);
    transparent_crc(g_1952, "g_1952", print_hash_value);
    transparent_crc(g_2108, "g_2108", print_hash_value);
    transparent_crc(g_2121, "g_2121", print_hash_value);
    transparent_crc(g_2172, "g_2172", print_hash_value);
    transparent_crc(g_2177, "g_2177", print_hash_value);
    transparent_crc(g_2214, "g_2214", print_hash_value);
    transparent_crc(g_2337, "g_2337", print_hash_value);
    transparent_crc(g_2345, "g_2345", print_hash_value);
    transparent_crc(g_2371, "g_2371", print_hash_value);
    transparent_crc(g_2526, "g_2526", print_hash_value);
    transparent_crc(g_2739, "g_2739", print_hash_value);
    transparent_crc(g_2756, "g_2756", print_hash_value);
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
