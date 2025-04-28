string MinLexSwap(string s)
{
    int i, j, n;
    string t;
    n = s.length();
    t = s;
    sort(t.begin(), t.end());
    if (s == t) /// s este ordonat crescator
    {
        j = i = n - 1;
        while (s[j] == s[i])
            j--;
        swap(s[j + 1], s[j]);
        return s;
    }
    for (i = 0; s[i] == t[i]; i++)
        ;
    for (j = n - 1; s[j] != t[i]; j--)
        ;
    swap(s[i], s[j]);
    return s;
}