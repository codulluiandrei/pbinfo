int Path(const char cale[], char d[101][101])
{
    int i, j, n = 0;
    for (i = 0; cale[i] != 0; )
        if (cale[i] == '\\') i++;
        else
        {
            j = 0;
            while ('a' <= cale[i] && cale[i] <= 'z')
                d[n][j++] = cale[i++];
            d[n][j] = 0;
            n++;
        }
    return n;
}