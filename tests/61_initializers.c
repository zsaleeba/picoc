#include <stdio.h>

char a[10] = "abcd";
char b[] = "efg";

char soko1[9][9] = {
    "  ##### ",
    "###   # ",
    "#.@$  # ",
    "### $.# ",
    "#.##$ # ",
    "# # . ##",
    "#$ *$$.#",
    "#   .  #",
    "########"
};

char* soko2[9] = {
    "  ##### ",
    "###   # ",
    "#.@$  # ",
    "### $.# ",
    "#.##$ # ",
    "# # . ##",
    "#$ *$$.#",
    "#   .  #",
    "########",
};


int x[10] = {0,1,2};
int y[] = {3,4,5,6};
int p[3][4] = {{1, 2, 3}, {4, 5}, {6, 7}};
int q[3][4] = {1, 2, 3, 9, 8, 7, 6, 5, 4};
int r[3][4][5] = {{{1, 2, 3}, {4, 5}, {6, 7}}, {{2, 4}, {6, 8}}};
int s[3][4][5] = {{1, 2, 3}, {4, 5}, {6, 7}};
int t[3][4][5] = {1, 2, 3, 9, 8, 7, 6, 5, 1, 2, 3, 9, 8, 7, 6, 5, 1, 2, 3, 9, 8, 7, 6, 5, 1, 2, 3, 9, 8, 7, 6, 5};

static void func_1(void)
{
    // test case found with CSmith
    int x[7][4] = {{1,2,3}};

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", x[i][j]);
        printf("\n");
    }

    int y[7][4] = {{0x116F538EL, 1L, 0x8DDB359CL, (-1L)}, {0x116F538EL, 1L, 0x8DDB359CL, (-1L)}, {0x116F538EL, 1L, 0x8DDB359CL, (-1L)}, {0x116F538EL, 1L, 0x8DDB359CL, (-1L)}, {0x116F538EL, 1L, 0x8DDB359CL, (-1L)}, {0x116F538EL, 1L, 0x8DDB359CL, (-1L)}, {0x116F538EL, 1L, 0x8DDB359CL, (-1L)}};

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", y[i][j]);
        printf("\n");
    }
}


int main(int argc, char** argv)
{
    printf("Hello, World!\n");

    printf("a='%s' (%ld)\n", a, sizeof(a));
    printf("b='%s' (%ld)\n", b, sizeof(b));

    printf("x=[");
    for (int i = 0; i < sizeof(x) / sizeof(int); i++)
        printf("%d ", x[i]);
    printf("]\n");

    printf("y=[");
    for (int i = 0; i < sizeof(y) / sizeof(int); i++)
        printf("%d ", y[i]);
    printf("]\n");

    printf("p=[\n");
    for (int i = 0; i < 3; i++)
    {
        printf("    ");
        for (int j = 0; j < 4; j++)
            printf("%d ", p[i][j]);
        printf("\n");
    }
    printf("  ]\n");

    printf("q=[\n");
    for (int i = 0; i < 3; i++)
    {
        printf("    ");
        for (int j = 0; j < 4; j++)
            printf("%d ", q[i][j]);
        printf("\n");
    }
    printf("  ]\n");

    printf("r=[\n");
    for (int i = 0; i < 3; i++)
    {
        printf("    ");
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 5; k++)
                printf("%d ", r[i][j][k]);
            printf("    ");
        }
        printf("\n");
    }
    printf("  ]\n");

    printf("s=[\n");
    for (int i = 0; i < 3; i++)
    {
        printf("    ");
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 5; k++)
                printf("%d ", s[i][j][k]);
            printf("    ");
        }
        printf("\n");
    }
    printf("  ]\n");

    printf("t=[\n");
    for (int i = 0; i < 3; i++)
    {
        printf("    ");
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 5; k++)
                printf("%d ", t[i][j][k]);
            printf("    ");
        }
        printf("\n");
    }
    printf("  ]\n");

    printf("soko1=\n");
    for (int i = 0; i < 9; i++)
        printf("%s    %c\n", soko1[i], soko1[i][3]);
    printf("soko2=\n");
    for (int i = 0; i < 9; i++)
        printf("%s    %c\n", soko2[i], soko2[i][3]);
    
    func_1();
    
    return 0;
}
