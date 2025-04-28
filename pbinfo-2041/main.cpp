#include<fstream>
#include<queue>
using namespace std;
//deplasarile dupa cele 8 directii
int dx[]= {-1,-1,-2,-2,+1,+1,+2,+2};
int dy[]= {-2,+2,-1,+1,-2,+2,-1,+1};
//adrese castel si cavaleri
struct loc
{
    int x,y;
};
loc castel;
loc cavaleri[1001];
queue<loc> Coada;
//harta
int A[1001][1001];
int p,m,n,k;
int r1,r2;
void citire()
{
    loc adresa;
    ifstream fin("camelot.in");
    fin>>p>>m>>n>>k;
    fin>>castel.x>>castel.y;
    for(int i=1; i<=k; i++)
    {
        fin>>cavaleri[i].x>>cavaleri[i].y;
    }
    fin.close();
}
void rezolva()
{
    loc p,adresa;
    int i,x,y;
    Coada.push(castel);
    A[castel.x][castel.y]=1;
    while(!Coada.empty())
    {
        p=Coada.front();
        Coada.pop();
        for(i=0; i<8; i++)
        {
            x=p.x+dx[i];
            y=p.y+dy[i];
            if(x>=1 && x<=m && y>=1 && y<=n)
                if(A[x][y]==0)
                {
                    adresa.x=x;
                    adresa.y=y;
                    Coada.push(adresa);
                    A[x][y]=1+A[p.x][p.y];
                }
        }
    }
    p=cavaleri[1];
    r1=r2=A[p.x][p.y];
    for(i=2;i<=k;i++)
    {
        if(r1>A[cavaleri[i].x][cavaleri[i].y])
            r1=A[cavaleri[i].x][cavaleri[i].y];
        if(r2<A[cavaleri[i].x][cavaleri[i].y])
            r2=A[cavaleri[i].x][cavaleri[i].y];
    }
    r1--;
    r2--;
}
void afisare()
{
    ofstream fout("camelot.out");
    if(p==1)
        fout<<r1;
    else
        fout<<r2;
    fout.close();
}
int main()
{
    citire();
    rezolva();
    afisare();
}