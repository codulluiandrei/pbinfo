#include <bits/stdc++.h>

using namespace std;

int S[40005], D[40005], v[40005];
long long sum[40005], maxarea;

int main()
{
    ifstream fin("skyline.in");
    ofstream fout("skyline.out");
    int n, vf, stiva[40005], i;

    fin >> n;
    for(int i = 1; i <= n; ++i)
    {
        fin >> v[i];
        fin >> vf;
        sum[i] = sum[i-1] + vf;
    }

    vf = 0; stiva[vf] = n + 1;
    for(i = n; i >= 1; --i) {
        while(vf > 0 && v[i] <= v[stiva[vf]]) --vf;
        D[i] = stiva[vf];
        stiva[++vf] = i;
    }

    vf = 0; stiva[vf] = 0;
    for(i = 0; i <= n; ++i) {
        while(vf > 0 && v[i] <= v[stiva[vf]]) --vf;
        S[i] = stiva[vf];
        stiva[++vf] = i;
    }

    for(i = 1; i <= n; ++i)
        maxarea = max(maxarea, v[i] * (sum[D[i] - 1] - sum[S[i]]));
    fout << maxarea;
}