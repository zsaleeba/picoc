int myfunc(int x)
{
    return x * x;
}

printint(myfunc(3));
printint(myfunc(4));

void vfunc(int a)
{
    printf("a=%d\n", a);
}

vfunc(1234);

void qfunc()
{
    printf("qfunc()\n");
}

qfunc();
