int Moderat(int n)
{
    int i, j, m, ePrim;
    if (n == 6) return 1;
    if (n <= 14) return 0; // primul numar moderat impar este 3*5=15
    if (n % 2 == 0) return 0; // numerele pare !=6 nu sunt moderate
    i = 3;
    while (i * i < n && n % i != 0)
        i += 2;
    if (i * i >= n) return 0;
    // caut primul numar prim > i
    ePrim = 0; m = i;
    while (!ePrim)
    {
        m += 2;
        ePrim = 1;
        for (j = 3; j * j <= m; j += 2)
            if (m % j == 0) ePrim = 0;
    }
    if (m * i == n) return 1;
    return 0;
}