/// Solutie - Moca Andrei - O(n^2)
#include <bits/stdc++.h>
#define ENTER ios::sync_with_stdio(false); fin.tie(0); fout.tie(0);
#define EXIT  fin.close(); fout.close(); return 0;
using namespace std;
ifstream fin("secvmaxval.in");
ofstream fout("secvmaxval.out");
int n, lmax, v[200002], minim = 1e9;
int64_t s, sum, val;
int main()
{
    ENTER
    fin >> n >> val;
    for (int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        s += v[i];
        minim = min(minim, v[i]);
    }
    if (val < minim) {
        fout << 0; EXIT
    }
    if (val >= s) {
        fout << n; EXIT
    }
    for (int i = 1; i <= n; ++i)
    {
        sum = 0;
        for (int j = i; j <= n; ++j)
        {
            sum += v[j];
            if (sum > val) {
                lmax = max(lmax, j - i);
                break;
            }
        }
    }
    fout << lmax;
    EXIT
}