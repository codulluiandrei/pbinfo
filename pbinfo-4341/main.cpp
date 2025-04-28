#include <fstream>
using namespace std;
ifstream fin("tablou.in");
ofstream fout("tablou.out");
int n, m, a[105][105], s[105][105], C, nrsel, amax,nrob,imax, w[10001];
int dx[]={-1, 0, 1, 0}, dy[]={0,1,0,-1};
struct obiect{
int x1,y1,x2,y2, sup;
bool incadrat, decupat;}v[10001];
struct element{
int x, y;};
void citire()
{
    fin>>C;
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            fin>>a[i][j];
}
void Coada(int x,int y, int &x1, int &y1, int &x2, int &y2, int & sup)
{
    int k, val, p, u;
    element Cd[10001], w;
    val=a[x][y];a[x][y]=0;s[x][y]=1;sup++;
    if(x<x1)x1=x;if(x>x2)x2=x;
    if(y<y1)y1=y;if(y>y2)y2=y;
    p=u=1;
    Cd[p].x=x;Cd[p].y=y;
    while(p<=u){
    w=Cd[p];p++;
    for(k=0;k<4;k++)
        if(a[w.x+dx[k]][w.y+dy[k]]==val){
                u++;Cd[u].x=w.x+dx[k];Cd[u].y=w.y+dy[k];
                a[Cd[u].x][Cd[u].y]=0;s[Cd[u].x][Cd[u].y]=1;sup++;
                if(Cd[u].x<x1)x1=Cd[u].x;if(Cd[u].x>x2)x2=Cd[u].x;
                if(Cd[u].y<y1)y1=Cd[u].y;if(Cd[u].y>y2)y2=Cd[u].y;
        }
    }
}
void sume_partiale()
{
    int i, j;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
                s[i][j]=s[i-1][j]+s[i][j-1]+s[i][j]-s[i-1][j-1];
}
int suma(int i1, int j1, int i2, int j2)
{
    return s[i2][j2]-s[i1-1][j2]-s[i2][j1-1]+s[i1-1][j1-1];
}
int intersectie(int i, int j)
{
    if(v[w[j]].y2<v[w[i]].y1)return 0;
    if(v[w[j]].x1>v[w[i]].x2)return 0;
    if(v[w[j]].y2>v[w[i]].y2)return 0;
    return 1;
}
int selectat_good(int nrsel, int i)
{
    for(int j=1;j<=nrsel;j++)
        if(intersectie(j,i))return 0;
    return 1;
}
int main()
{
    citire();
    for(int i=1;i<=n;i++)
        for(int j=1; j<=m;j++)
            if(a[i][j]!=0)
                {
                    nrob++;v[nrob].x1=i; v[nrob].y1=j;v[nrob].x2=i;v[nrob].y2=j;
                    Coada(i, j, v[nrob].x1, v[nrob].y1, v[nrob].x2,v[nrob].y2, v[nrob].sup );
                }
    sume_partiale();
    for(int i=1;i<=nrob;i++)
    {
        if(v[i].sup==suma(v[i].x1, v[i].y1, v[i].x2,v[i].y2))
        {
            v[i].incadrat=1;
            if(v[i].sup>v[imax].sup){imax=i;amax=(v[imax].x2-v[imax].x1+1)*(v[imax].y2-v[imax].y1+1);}
            else if(v[i].sup==v[imax].sup &&amax>(v[imax].x2-v[imax].x1+1)*(v[imax].y2-v[imax].y1+1))
                                        amax=(v[imax].x2-v[imax].x1+1)*(v[imax].y2-v[imax].y1+1);
        }
    }
    for(int i=1;i<=nrob;i++)
        if(v[i].incadrat)
              if(selectat_good(nrsel, i)){nrsel++, w[nrsel]=i;v[i].decupat=1;}
    if(C==1)fout<<amax<<'\n';
    else fout<<nrsel<<'\n';
    return 0;
}