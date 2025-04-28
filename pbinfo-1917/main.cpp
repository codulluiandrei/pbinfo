// sursa 100p Turcuman Vlad
#include <fstream>
#define NMax 100001
using namespace std;
ifstream fin("prieteni.in");
ofstream fout("prieteni.out");
int c[NMax];
int p[NMax];
int n,k,t,x,y;
int _find(int x)
{
    return !p[x] ? x : (p[x] = _find(p[x]));
}
void Union(int x,int y)
{
    int p1 = _find(x);
    int p2 = _find(y);
    if(p1==p2)
        return;
    p[p1] = p2;
    c[p2] += c[p1] + 1;
}
int Children(int x)
{
    return c[_find(x)];
}
int main()
{
    fin>>n>>k;
    if(k>1000000)
        return 0;
    for(int i =1;i<=k;i++)
    {
        fin>>t;
        if(t == 1)
        {
            fin>>x>>y;
            Union(x,y);
        }
        else
        {
            fin>>x;
            fout<<Children(x) + 1<<'\n';
        }
    }
    return 0;
}