void Alphanum(char s[], char cuv[][21], int &n, int num[], int &m)
{
    int i, x;
    n = m = 0;
    for (i = 0; s[i]; )
        if (s[i] == ' ') i++;
        else if ('0' <= s[i] && s[i] <= '9')
        {
            x = 0;
            while ('0' <= s[i] && s[i] <= '9')
            {
                x = x * 10 + (s[i] - '0');
                i++;
            }
            num[m++] = x;
        }
        else
        {
            x = 0;
            while ('a' <= s[i] && s[i] <= 'z')
            {
                cuv[n][x++] = s[i];
                i++;
            }
            cuv[n][x] = 0;
            n++;
        }
}