#include <bits/stdc++.h>
#define nmax 50001
using namespace std;
ifstream  fin("admuchii.in");
ofstream fout("admuchii.out");
vector<int> g[nmax];
bitset<nmax> viz;
int nr[nmax], M[nmax], n, m, nrc;
int special[nmax], K;
void Citire()
{
    int i, j, p;
    fin >> n >> m >> K;
    for (i = 1; i <= K; i++)
        fin >> special[i];
    for (p = 1; p <= m; p++)
    {
        fin >> i >> j;
        g[i].push_back(j);
        g[j].push_back(i);
    }
}
void DFS(int k)
{
    viz[k] = nrc;
    nr[nrc]++;
    for (int i : g[k])
    {
        M[nrc]++;
        if (!viz[i]) DFS(i);
    }
}
int main()
{
    int i, j;
    long long nrMuchii;
    Citire();
    /// construim componente conexe ale fiecarui nod special
    for (i = 1; i <= K; i++)
    {
        nrc++;
        DFS(special[i]);
    }
    /// aflam componenta conexa j cu nr[j]=maxim
    j = 1;
    for (i = 1; i <= nrc; i++)
    {
        M[i] /= 2;
        m -= M[i];
        if (nr[i] > nr[j]) j = i;
    }
    /// toate nodurile (si muchiile) ramase in afara unei
    /// comp. conexe le adaugam la componenta conexa (nr[j], M[j])
    for (i = 1; i <= n; i++)
        if (viz[i] == 0) nr[j]++;
    M[j] += m;
    /**
     Aflam numarul de muchii care se pot adauga in fiecare
     componenta conexa cu N noduri si M muchii: N*(N-1)/2-M
    */
    nrMuchii = 0;
    for (i = 1; i <= K; i++)
        nrMuchii += (1LL * nr[i] * (nr[i] - 1) / 2 - M[i]);
    fout << nrMuchii;
    return 0;
}