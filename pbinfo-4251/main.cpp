#include <bits/stdc++.h>

using namespace std;

ifstream fin("numereoji.in");
ofstream fout("numereoji.out");
int a[12], t[12], n, cnt, sol[12], smax;

void Citire()
{
    n = 10;
    for (int i = 1; i <= n; i++)
        fin >> a[i];
    fin.close();
}

void Generare()
{
    int i, s1, s2, j;
    smax = 0;
    while (t[0] == 0)
    {
        /// next subm.
        for (i = n; i >= 1 && t[i] == 2; i--)
            t[i] = 0;
        t[i]++;
        /// calcul
        s1 = s2 = 0;
        for (i = 1; i <= n; i++)
            if (t[i] == 1) s1 += a[i];
            else if (t[i] == 2) s2 += a[i];

        if (s1 == s2 && s1 != 0)
        {
            cnt++;
            if (smax < s1)
            {
                smax = s1;
                for (j = 1; j <= n; j++)
                    sol[j] = t[j];
            }
        }
    }
    cnt /= 2;
    fout << cnt << " " << smax << "\n";
    for (i = 1; i <= n; i++)
        if (sol[i] == 1) fout << a[i] << " ";
    fout << "\n";
    for (i = 1; i <= n; i++)
        if (sol[i] == 2) fout << a[i] << " ";
    fout << "\n";
    fout.close();
}

int main()
{
    Citire();
    Generare();
    return 0;
}
