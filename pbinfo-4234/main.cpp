#include <bits/stdc++.h>
using namespace std;
int v[1003], sm[1003], n, s;
ifstream fin("potriviri.in");
ofstream fout("potriviri.out");
int main()
{
    int i, j, sa, dif, smin;
    bool ok;
    fin >> n >> s;
    sa = 0;
    for (i = 1; i <= n; i++)
    {
        v[i] = i;
        sa = sa + i * i;
        sm[i] = sa;
    }
    if (s>sa)
    {
        fout << "0\n";
        fout.close();
        return 0;
    }
    smin = 0;
    for (i = 1; i <= n; i++)
        smin = smin + (n - i + 1) * i;
    if (s < smin)
    {
        fout << "0\n";
        fout.close();
        return 0;
    }
    if (s == smin)
    {
        for (i = 1; i <= n; i++)
            v[i] = i;
        sa = smin;
    }
    while (sa>s)
    {
        ok = false;
        for (i = n; i >= 2; i--)
        {
            for (j = i - 1; j >= 1; j--)
            {
                dif = (v[i] * i + v[j] * j) - (v[i] * j + v[j] * i);
                if (dif > 0 && sa - dif >= s)
                {
                    smin = v[i];
                    v[i] = v[j];
                    v[j] = smin;
                    sa = sa - dif;
                    ok = true;
                    break;
                }
            if (ok) break;
            }
        }
    }
    for (i = 1; i <= n; i++)
        fout << v[i] << " ";
    fout << "\n";
    fout.close();
    fin.close();
    return 0;
}