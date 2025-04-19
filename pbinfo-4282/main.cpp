#include<bits/stdc++.h>
#define  inFile "nrcompconexe.in"
#define outFile "nrcompconexe.out"
using namespace std;
vector<int> L[30002];
int n, viz[30002];
void Citire()
{
    int i, x, y, m;
    ifstream fin(inFile);
    fin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        fin >> x >> y;
        L[x].push_back(y);
        L[y].push_back(x);
    }
    fin.close();
}
void DFS(int k)
{
    int j;
    unsigned int i;
    viz[k] = 1;
    for (i = 0; i < L[k].size(); i++)
    {
        j = L[k][i];
        if (!viz[j]) DFS(j);
    }
}
void NrCompCon()
{
    int i, contor = 0;
    for (i = 1; i <= n; i++)
        if (!viz[i])
        {
            contor++;
            DFS(i);
        }
    ofstream fout(outFile);
    fout << contor << "\n";
    fout.close();
}
int main()
{
    Citire();
    NrCompCon();
    return 0 ;
}