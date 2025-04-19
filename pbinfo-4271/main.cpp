void Intercalate(char a[], char b[], char c[])
{
    int i, j = 0;
    for (i = 0; a[i] != 0 && b[i] != 0; i++)
    {
        c[j++] = a[i];
        c[j++] = b[i];
    }
    while (a[i] != 0)
        c[j++] = a[i++];
    while (b[i] != 0)
        c[j++] = b[i++];
    c[j] = 0;
}