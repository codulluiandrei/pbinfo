int SC(char s[])
{
    if (s[0] == 0) return 0;
    if ('0' <= s[0] && s[0] <= '9') return (s[0]-'0') + SC(s + 1);
    return SC(s + 1);
}