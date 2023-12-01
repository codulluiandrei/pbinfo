long long NextNumber(long long n)
{
    int i, t[66], k = 0, nr1;
    long long answer;
    while (n > 0)
    {
        t[++k] = n % 2;
        n /= 2;
    }
    /// sare peste zerouri
    for (i = 1; t[i] == 0; i++)
        ;
    /// sar peste prima secventa de 1-uri
    nr1 = 0;
    for ( ; i <= k && t[i] == 1; i++)
        nr1++;

    if (i <= k)
    {
        t[i--] = 1;
        nr1--;
        while (i > 0)
            t[i--] = 0;
        for (i = 1; i <= nr1; i++)
            t[i] = 1;
    }
    else
    {
        k++;
        t[k] = 1;
        nr1--;
        for (i = 1; i <= nr1; i++)
            t[i] = 1;
        for ( ; i < k; i++)
            t[i] = 0;
    }
    answer = 0;
    for (i = k; i >= 1; i--)
        answer = answer * 2 + t[i];
    return answer;
}