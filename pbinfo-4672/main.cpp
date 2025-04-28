#include <bits/stdc++.h>
using namespace std;
ifstream fin("countseqmatch.in");
ofstream fout("countseqmatch.out");
int m, n, a[100003];
int fra[100003], frb[100003];
int main()
{
    int i, j, x, cnt = 0;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> a[i];
        a[i] += 50000;
    }
    fin >> m;
    for(int i = 1; i <= m; i++)
    {
        fin >> x;
        frb[x + 50000]++;
    }
    j = 1;
    for (i = 1; i <= n; i++)
    {
        x = a[i];
        fra[x]++;
        while (fra[x] > frb[x])
        {
            fra[a[j]]--;
            j++;
        }
        if (i - j + 1 == m) cnt++;
    }
    fout << cnt << "\n";
    fin.close();
    fout.close();
    return 0;
}