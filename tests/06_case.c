int Count;

for (Count = 0; Count < 4; Count++)
{
    printint(Count);
    switch (Count)
    {
        case 1:
            printint(1);
	    break;

        case 2:
            printint(2);
	    break;

        default:
            printint(0);
            break;
    }
}
