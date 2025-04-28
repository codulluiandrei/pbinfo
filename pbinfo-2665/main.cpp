/* *********************
Solutie oficiala (100p)
Autor: Vintila Valentin Ioan
********************* */
#include <bits/stdc++.h>
#define N 20005
using namespace std;
int S[N], D[N];
int main()
{
    ifstream fin("dreptunghi1.in");
    ofstream fout("dreptunghi1.out");
    int n, m, i, pc = 0, j, k, h[N], stiva[N], vf, maxarea = 0;
    fin >> m >> n >> pc;
    pair<short, short> v[N];
    for(i = 0; i < pc; ++i)
        fin >> v[i].first >> v[i].second;
    sort(v, v+pc);
    k = 0;
    for(i = 1; i <= m; ++i)
    {
        for(j = 1; j <= n; ++j)
        {
            if(v[k].first == i && v[k].second == j) {
                h[j] = 0;
                while(k < pc && v[k].first == i && v[k].second == j)
                    ++k;
                h[j] = 0;
            } else {
                ++h[j];
            }
        }
        vf = 0; stiva[vf] = n + 1;
        for(j = n; j >= 1; --j) {
            while(vf > 0 && h[j] <= h[stiva[vf]]) --vf;
            D[j] = stiva[vf];
            stiva[++vf] = j;
        }
        vf = 0; stiva[vf] = 0;
        for(j = 1; j <= n; ++j) {
            while(vf > 0 && h[j] <= h[stiva[vf]]) --vf;
            S[j] = stiva[vf];
            stiva[++vf] = j;
        }
        for(j = 1; j <= n; ++j)
            maxarea = max(maxarea, h[j] * (D[j] - 1 - S[j]));
    }
    fout << maxarea;
    return 0;
}