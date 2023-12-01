//Dobricean Ionut-100pct
#include<fstream>
using namespace std;
ifstream fin("afisminime.in");
ofstream fout("afisminime.out");
int r[100001][19],v[100001]; //definirea matricii  si vectorul de citire

int main()
{int n,m,i,j,a,b,rez,l;
    fin>>n>>m;
    v[1]=0;
    for(i=2;i<=n;i++)
        v[i]=1+v[i/2];
    for(i=1;i<=n;i++)
    {
       fin>>r[i][0];
        for(j=1;(1<<j)<=i;j++)
            r[i][j]=min(r[i-(1<<(j-1))][j-1],r[i][j-1]);
    }
    for(i=1;i<=m;i++)
    {
    fin>>a>>b;
        l=v[b-a+1];
        rez=min(r[a+(1<<l)-1][l],r[b][l]);
      fout<<rez<<"\n";
    }
    return 0;
    fin.close();
    fout.close();
}
