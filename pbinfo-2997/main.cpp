void Prescurtat(char s[])
{
    char cuv[105], t[105], *p, sep[] = " ";
    int n;
    t[0] = 0;
    p = strtok(s, sep);
    while (p != NULL)
    {
        strcpy(cuv, p);
        n = strlen(cuv);
        if (cuv[n - 1] == '.')
        {
            if (cuv[0] == 'C') strcpy(cuv, "COLEGIUL");
            if (cuv[0] == 'L') strcpy(cuv, "LICEUL");
            if (cuv[0] == 'N') strcpy(cuv, "NATIONAL");
            if (cuv[0] == 'T') strcpy(cuv, "TEORETIC");
        }
        strcat(t, cuv);
        strcat(t, " ");
        p = strtok(NULL, sep);
    }
    n = strlen(t);
    while (t[n - 1] == ' ')
    {
        t[n - 1] = 0;
        n--;
    }
    strcpy(s, t);
}