int FBaza(char s[])
{
    int i, x, baza = -1;
    for (i = 0; s[i] != 0; i++)
    {
        if ('0' <= s[i] && s[i] <= '9')
        {
            x = s[i] - '0';
            if (baza < x) baza = x;
        }
        else if (('A' <= s[i] && s[i] <= 'F') ||
                 ('a' <= s[i] && s[i] <= 'f'))
                    baza = 16;
        else return -1;
    }
    if (baza < 2) return 2;
    if (baza < 4) return 4;
    if (baza < 8) return 8;
    if (baza < 10) return 10;
    return 16;
}