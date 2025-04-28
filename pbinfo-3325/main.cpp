#include <bits/stdc++.h>
#define NM 100005
using namespace std;
ifstream fin ("Ohoo.in");
ofstream fout ("Ohoo.out");
void read();
int n, m, maxx, st, dr, rez, mijl;
vector<pair<int,int>> v[NM];
bitset<NM> viz;
bool ok(int nod)
{
    if(viz[n])
        return 1;
    bool gasit = 0;
    viz[nod] = 1;
    if(nod == n)
        return 1;
    for(auto it:v[nod])
        if(!viz[it.first] && it.second <= mijl)
            gasit|=ok(it.first);
    return gasit;
}
int main()
{
    read();
    st = 1, dr = maxx, rez = maxx;
    while(st<=dr)
    {
        mijl = (st+dr)/2;
        viz.reset();
        if(ok(1))
        {
            rez = mijl;
            dr = mijl-1;
        }
        else st = mijl+1;
    }
    fout << rez;
    return 0;
}
void read()
{
    fin >> n >> m;
    for(int i=1; i<=m; i++)
    {
        int x, y, p;
        fin >> x >> y >> p;
        maxx = max(maxx, p);
        v[x].push_back({y, p});
        v[y].push_back({x, p});
    }
}