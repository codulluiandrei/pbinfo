void UpperLower(const char a[], char U[], char L[])
{
    int i;
    char ch;
    for (i = 0; a[i] != 0; i++)
    {
        U[i] = L[i] = ch = a[i];
        if ('a' <= ch && ch <= 'z') U[i] = ch - 32;
        if ('A' <= ch && ch <= 'Z') L[i] = ch + 32;
    }
    U[i] = L[i] = 0;
}