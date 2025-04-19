void next_perm(int n, int P[])
{
    int i, j, k, Min;
    /// parcurgem permutarea de la dreapta la stanga pt. a gasi pozitia k
    /// astfel incat P[k] < P[k+1], iar P[k+1] > P[k+2] > ... > P[n]
    for(k = n-1; k > 0; k--)
        if (P[k] < P[k+1]) break;
    /// cautam cel mai mic element P[i] > P[j], cu i=k+1,...,n
    Min = P[k+1], j = k+1;
    for(i = k+1; i <= n; i++)
        if (P[i] < Min && P[i] > P[k]) Min = P[i], j = i;
    ///iterschimbam P[k] cu P[j]
    swap(P[k], P[j]);
    /// inversam ultimele n-k elemente din permutare
    i = k+1, j = n;
    while ( i < j ) {
        swap(P[i], P[j]);
        i++, j--;
    }
}