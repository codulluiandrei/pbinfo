//Prof. Lucia Miron
#include <fstream>
using namespace std;
ifstream fin("dineu.in");
ofstream fout("dineu.out");
int n,l, a[30][30],b[30][15],x[30],ok;
void citire()
{
    int i, j,x;
    fin>>n>>l;
    for(i=1;i<=n;i++)
      {
        fin>>b[i][0];
        for(j=1;j<=b[i][0];j++)
            {fin>>x;b[i][x]=1;}
      }
}
void matrice_ad()
{
   int i,j,ex,k;
   for(i=1;i<=n-1;i++)
   {
      for(j=i+1;j<=n;j++)
        {
           ex=0;
           for(k=1;k<=l;k++)
              if(b[i][k]&&b[j][k]){ex=1;break;}
           if(ex)
            a[i][j]=a[j][i]=1;
        }
   }
}
void afisare(int m)
{
    int i;
    fout<<m<<'\n';
    for(i=1;i<=m;i++)
        fout<<x[i]<<' ';
    fout<<'\n';
    fout.close();
}
int complet(int m)
{
    int i,j;
    for(i=1;i<=m;i++)
       for(j=1;j<=m;j++)
            if(a[x[i]][x[j]]==0&&i!=j)return 0;
    return 1;
}
void gen(int k, int m)
{
    int i;
   if(!ok)
    {if(k>m)
        {    if(complet(m))
                  {ok=1;afisare(m);}
        }
     else for(i=x[k-1]+1;i<=n-m+k;i++)
            {
                x[k]=i;
                gen(k+1,m);
            }
    }
}
void rezolvare()
{
  int m;
  ok=0;
  for(m=n;m>=1&&!ok;m--)
       gen(1,m);
}
int main()
{
    citire();
    matrice_ad();
    rezolvare();
    return 0;
}