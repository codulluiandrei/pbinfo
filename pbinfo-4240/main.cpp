long long NrSecv01(const char s[])
{
    long long cnt = 0;
    int fr[200001] = {0};
    int i, sum = 0;
    fr[0] = 1;
    for (i = 0; s[i] != 0; i++)
    {
        if (s[i] == '1') sum++;
        if (sum > 0) cnt += fr[sum - 1];
        fr[sum]++;
    }
    return cnt;
}