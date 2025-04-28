int cautaLitera(char s[], char c)
{
    for(int poz=0; s[poz]; poz++)
        if (s[poz]==c) return 1;
    return 0;
}
int extrageCuvant(char dest[], char sir[], char separatori[], int pozitie)
{
    int i=0;
    int contorCuvant=0;
    int k=0;
    int lung=0;
    while (sir[lung++]);
    while(sir[k] && contorCuvant < pozitie)
    {
        if (cautaLitera(separatori, sir[k])) while (cautaLitera(separatori, sir[k]) && sir[k]!=0) k++;
        while (!cautaLitera(separatori, sir[k]) && sir[k]!=0)k++;
        contorCuvant++;
    }
    if (k>lung) return 0;
    if (cautaLitera(separatori, sir[k])) while (cautaLitera(separatori, sir[k]) && sir[k]!=0) k++;
    if (k>lung) return 0;
    while (sir[k])
    {
        dest[i]=sir[k];
        i++;
        k++;
        if (cautaLitera(separatori, sir[k]) || k==lung) break;
    }
    dest[i]=0;
    if (dest[0]) return 1;
    return 0;
}