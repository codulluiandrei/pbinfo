void Trim(char s[])
{
    int i, j, k;
    for (j = 0; s[j]; j++)
        ;
    j--;
    while (s[j] == ' ') j--;
    i = 0;
    while (s[i] == ' ') i++;
    k = 0;
    for ( ; i <= j; i++)
        s[k++] = s[i];
    s[k] = 0;
}