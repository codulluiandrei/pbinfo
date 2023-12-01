void secventa(int &n)
{
    int m = 0, p = 1;
    while (n > 0)
    {
        if (n % 100 == 22) n -= 2;
        m = m + n % 10 * p;
        p = p * 10;
        n /= 10;
    }
    n = m;
}