void FConcat(char s[], char d[])
{
    int i, j;
    for (i = 0; s[i] != 0; i++)
        ;
    for (j = 0; d[j] != 0; j++)
        s[i++] = d[j];
    s[i] = 0;
}