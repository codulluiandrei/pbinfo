#include<bits/stdc++.h>
#define  inFile "nrcompconexe.in"
#define outFile "nrcompconexe.out"
using namespace std;

int n, viz[103], a[103][103];

void Citire()
{
    int i, x, y, m;
    ifstream fin(inFile);
    fin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        fin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    fin.close();
}

void DFS(int k)
{
    viz[k] = 1;
    for (int i = 1; i <= n; i++)
        if (!viz[i] && a[k][i])
            DFS(i);
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
