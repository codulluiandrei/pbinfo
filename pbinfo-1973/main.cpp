/*
    Popa Bogdan Ioan, Colegiul National Aurel Vlaicu
    clasa a 10-a
    Sume partiale, O(N^2)
*/
#include <bits/stdc++.h>
#define nmax 1002
using namespace std;
ifstream fin("hambar2.in");
ofstream fout("hambar2.out");
int n, M;
int i, j, k;
int L;
bitset<nmax>a[nmax];
short S[nmax][nmax];
int maxarie;
short ct[nmax];
int idx;
int main()
{
    fin >> n >> M;
    while(M--)
    {
        fin >> i >> j;
        a[i][j] = 1;
    }
    for(j = 1; j <= n; j++)
    {
        for(i = 1, k = 0; i <= n; i++)
        {
            if(a[i][j] == 0)
                S[i][j] = 1 + S[i][j - 1];
            while(k && S[ct[k]][j] > S[i][j])
            {
                idx = ct[k--];
                maxarie = max(maxarie, (i - ct[k] - 1) * S[idx][j]);
            }
            ct[++k] = i;
        }
        while(k)
        {
            idx = ct[k--];
            maxarie = max(maxarie, (n - ct[k]) * S[idx][j]);
        }
    }
    fout << maxarie << "\n";
    return 0;
}