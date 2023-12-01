#include <bits/stdc++.h>

using namespace std;

int S[100005], D[100005], v[100005];

int main()
{
    ifstream fin("nrapp.in");
    ofstream fout("nrapp.out");
    int n, vf, stiva[100005]; fin >> n;
    for(int i = 1; i <= n; ++i)
        fin >> v[i];

    vf = 0; stiva[vf] = n + 1;
    for(int i = n; i >= 1; --i) {
        while(vf > 0 && v[i] <= v[stiva[vf]]) --vf;
        D[i] = stiva[vf];
        stiva[++vf] = i;
    }

    vf = 0; stiva[vf] = 0;
    for(int i = 0; i <= n; ++i) {
        while(vf > 0 && v[i] <= v[stiva[vf]]) --vf;
        S[i] = stiva[vf];
        stiva[++vf] = i;
    }

    char c; fin >> n;
    for(int i = 0; i < n; ++i)
    {
        fin >> c >> vf;
        if(c == 'S')
            (fout << S[vf]).put('\n');
        else
            (fout << D[vf]).put('\n');
    }
}