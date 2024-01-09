#include <fstream>
using namespace std;
ifstream fin("lantq.in");
ofstream fout("lantq.out");

int A[21][21],m,n,X[21],P[21],q,G[20];

void afisare(int k)
{
    for(int i=1;i<=k;i++)
        fout<<X[i]<<" ";
    fout<<"\n";
}

void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i] && A[X[k-1]][i])
        {
            X[k]=i;
            P[i]=1;
            if(X[k]==q) afisare(k);
            else back(k+1);
            P[i]=0;
        }
}

int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        fin>>x>>y;
        A[x][y]=A[y][x]=1;
        G[x]++;
        G[y]++;
    }
    fin>>q;
    if(G[q])
    {
        for(int i=1;i<=n;i++)
            if(i!=q)
            {
                X[1]=i;
                P[i]=1;
                back(2);
                P[i]=0;
            }
    }
    else fout<<"NU EXISTA";
    return 0;
}
