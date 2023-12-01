int Litera(char ch)
{
    if ('a' <= ch && ch <= 'z') return 1;
    if ('A' <= ch && ch <= 'Z') return 1;
    return 0;
}

void SplitText(char s[], char cuv[101][30], int &n)
{
    int i, j;
    n = 0;
    for (i = 0; s[i]; )
        if (!Litera(s[i])) i++;
        else
        {
            j = 0;
            while (Litera(s[i]))
                cuv[n][j++] = s[i++];
            cuv[n][j] = 0;
            n++;
        }
}