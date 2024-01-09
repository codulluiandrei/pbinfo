#include <bits/stdc++.h>

using namespace std;

map<long long, int> M;

int main()
{
    int i, N;
    long long x;
    ifstream  fin("map.in");
    ofstream fout("map.out");
    fin >> N;
    for (i = 1; i <= N; i++)
    {
        fin >> x;
        M[x]++;
        fout << M[x] << " ";
    }
    fout << "\n";
    fout.close();

    return 0;
}
