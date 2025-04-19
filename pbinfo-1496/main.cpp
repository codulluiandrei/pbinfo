#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("harta1.in");
ofstream fout("harta1.out");
int a[101][101],p,n,m,k,valoare;
void citire()
{int i,j;
    fin>>p;
    fin>>n>>m>>k;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
          fin>>a[i][j];
    fin.close();
}
void fill(int x, int y)
{ valoare=a[x][y];
  a[x][y]=-1;
  if (valoare==a[x][y+1])fill(x,y+1);
  if(valoare==a[x+1][y])fill(x+1,y);
  if(valoare==a[x][y-1])fill(x,y-1);
  if(valoare==a[x-1][y])fill(x-1,y);
}
int main()
{int nr,i,j,q,maxim,h;
 int tampon[10];
    citire();
    if (p==1)
       {nr=0;
        for (i=1;i<=n;i++)
             for(j=1;j<=m;j++)
                if(a[i][j]==0) nr=nr+1;
        fout<<nr<<'\n';
     fout.close();
       }
    else
    {maxim=-1;
     h=0;
     for (q=1;q<=k;q++)
    {nr=0;
     for(i=1;i<=n;i++)
        for (j=1;j<=m;j++)
     if (a[i][j]==q)
         {fill(i,j);
          nr=nr+1;
         }
     if (nr>maxim){maxim=nr;h=1;tampon[h]=q;}
     else if(nr==maxim){h++;tampon[h]=q;}
    }
    for (q=1;q<=h-1;q++)
        fout<<tampon[q]<<" ";
    fout<<tampon[h];
    fout<<'\n';
    fout.close();
    }
    return 0;
}