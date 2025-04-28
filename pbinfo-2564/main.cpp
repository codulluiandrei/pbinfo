#include <fstream>
#define NMax 5005
#define Nk 1001
using namespace std;
int a[Nk][Nk],ti1[Nk],ti2[Nk],tj1[Nk],tj2[Nk],Poz[Nk];
int i1,i2,j1,j2,n,t,m,k,nr,sp;
long long b[Nk][Nk],s,i,j,maxx;
int w[NMax];
bool ok;
int main()
{
    ifstream f("macara.in");
    ofstream g("macara.out");
    f >> m >> n;
    for(i=2;i<=NMax;i++)
     if(w[i]==0)
      {
          for(j=i*i;j<=NMax;j=j+i)
              w[j]=1;
      }
    w[1]=1;
    for(i=1;i<=m;i++)
     {
         s=0;
         ok=true;
         for(j=1;j<=n;j++)
       {
           f >> a[i][j];
           if((ok)&&(w[a[i][j]]==0))
              {
                  ok=false;
                  sp=sp+a[i][j];
                  s=s+a[i][j];
                  b[i][j]=s;
              }
           if(w[a[i][j]]==1) s=s+a[i][j], b[i][j]=s;
            else b[i][j]=s;
       }
     }
    f >> k;
    for(t=1;t<=k;t++)
      {
          f >> i1 >> j1 >> i2 >> j2;
          s=0;
          for(i=i1;i<=i2;i++)
           s=s+b[i][j2]-b[i][j1-1];
          if(s>maxx) {maxx=s; nr=1; ti1[nr]=i1; tj1[nr]=j1; ti2[nr]=i2; tj2[nr]=j2; Poz[nr]=t;}
           else if(s==maxx) {nr++; ti1[nr]=i1; tj1[nr]=j1; ti2[nr]=i2; tj2[nr]=j2; Poz[nr]=t;}
      }
    g << sp << "\n";
    g << maxx << "\n";
    for(i=1;i<=nr;i++)
        g << ti1[i] << " " << tj1[i] << " " << ti2[i] << " " << tj2[i] << " " << Poz[i] << "\n";
    return 0;
}