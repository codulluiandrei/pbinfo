int Fulg(int n)
{
    if (n < 100000000) return 0;
    int c, fr[5] = {0};
    while (n > 0)
    {
        c = n % 10;
        n /= 10;
        if (c == 0 || c > 4) return 0;
        fr[c]++;
    }
    for (int i = 1; i <= 4; i++)
        if (fr[i] == 0) return 0;
    return 1;
}