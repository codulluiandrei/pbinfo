#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define dim 120004
using namespace std;
ifstream f ("plimbare1.in");
ofstream g ("plimbare1.out");
struct filip
{
    int x,y,cost;
} v[dim];
int l[dim],poz[dim],c;
bool cmp(int a,int b)
{
    return v[a].cost < v[b].cost;
}
int grupa(int x)
{
    if(l[x] == x)
        return x;
    l[x] = grupa(l[x]);
    return l[x];
}
void uneste(int x,int y)
{
    l[grupa(x)] = grupa(y);
}
int main()
{
    int n,m,i,k = 0,ct = 0,xx,yy,caz,mm = 0;
    f >> n >> m;
    for(i = 1; i <= n; i++)
        l[i] = i;
    for(i = 1; i <= m; i++)
    {
        f >> caz >> xx >> yy;
        switch(caz)
        {
        case 1:
            uneste(xx,yy);
            break;
        case 2:
            f >> c;
            v[++mm].x = xx;
            v[mm].y = yy;
            v[mm].cost = c;
        }
    }
    for(i = 1; i <= mm; i++)
        poz[i] = i;
    sort(poz + 1,poz + mm + 1,cmp);
    for(i = 1; i <= mm; i++)
        if(grupa(v[poz[i]].x) != grupa(v[poz[i]].y))
        {
            ct += v[poz[i]].cost;
            uneste(v[poz[i]].x,v[poz[i]].y);
        }
    g << ct << '\n';
    return 0;
}