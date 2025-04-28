#include <bits/stdc++.h>
#define nmax 100003
using namespace std;
vector<int> G[nmax]; /// listele de ad. ale noului digraf
vector<int> L[nmax]; /// listele digrafului initial
vector<int> H[nmax]; /// listele digrafului transpus
bool viz[nmax];
int ctc[nmax]; /// ctc[i]=j : nodul i e in componenta j
int n, m, nrc;
int v[nmax], k, t[nmax];
int X[2 * nmax], Y[2 * nmax]; /// memoreaza arcele initiale
void Citire()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> X[i] >> Y[i];
        L[X[i]].push_back(Y[i]);
        H[Y[i]].push_back(X[i]);
    }
}
void DFS1(int nod)
{
    viz[nod] = true;
    for (auto i : L[nod])
        if (!viz[i]) DFS1(i);
    v[++k] = nod;
}
void DFS2(int nod)
{
    viz[nod] = false;
    for (auto i : H[nod])
        if (viz[i]) DFS2(i);
    ctc[nod] = nrc;
}
void Kosaraju()
{
    for (int i = 1; i <= n; i++)
        if (!viz[i])
            DFS1(i);
    for (int i = n; i >= 1; i--)
        if (viz[v[i]])
        {
            nrc++;
            DFS2(v[i]);
        }
}
/// constructie digraf nou si afisare liste de adiacenta
void DigrafNou()
{
    int i, x = 0;
    for (i = 1; i <= n; i++)
        if (t[ctc[i]] == 0)
            t[ctc[i]] = ++x;
    for (i = 1; i <= n; i++)
        ctc[i] = t[ctc[i]];
    for (i = 1; i <= m; i++)
        if (ctc[X[i]] != ctc[Y[i]])
            G[ctc[X[i]]].push_back(ctc[Y[i]]);
    for (i = 1; i <= nrc; i++)
        if (G[i].size() > 0)
            sort(G[i].begin(), G[i].end());
    for (i = 1; i <= nrc; i++)
        if (G[i].size() == 0) cout << "0\n";
        else
        {
            for (auto j : G[i])
                cout << j << " ";
            cout << "\n";
        }
}
int main()
{
    Citire();
    Kosaraju();
    DigrafNou();
    return 0;
}