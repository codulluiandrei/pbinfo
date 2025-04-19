int IndexOf(char s[], char ch)
{
    for (int i = 0; s[i]; i++)
        if (s[i] == ch) return i;
    return -1;
}
int LastIndexOf(char s[], char ch)
{
    int p = -1;
    for (int i = 0; s[i]; i++)
        if (s[i] == ch) p = i;
    return p;
}
int NthIndex(char s[], char ch, int k)
{
    if (k <= 0) return -1;
    for (int i = 0; s[i]; i++)
        if (s[i] == ch)
        {
            k--;
            if (k == 0) return i;
        }
    return -1;
}