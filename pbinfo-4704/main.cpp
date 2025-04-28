int majImp(int a, int b)
{
    int i, k, n, sumaPare, sumaImpare;
    for (n = a; n <= b; n++)
    {
        sumaPare = sumaImpare = 0;
        for (i = 2; i * i < n; i++)
            if (n % i == 0)
            {
                if (i % 2 == 0) sumaPare += i;
                else sumaImpare += i;
                k = n / i;
                if (k % 2 == 0) sumaPare += k;
                else sumaImpare += k;
            }
        if (i * i == n)
        {
            if (i % 2 == 0) sumaPare += i;
            else sumaImpare += i;
        }
        if (sumaImpare > sumaPare) return n;
    }
    return 0;
}