#include <fstream>
#define NMAX 102
using namespace std;
ifstream fin("nave.in");
ofstream fout("nave.out");
int n, m;
int nrmax, linmax, colmax;
int a[NMAX][NMAX];
int dl[]={1,-1, 1,-1};
int dc[]={1, 1,-1,-1};
void citire();
void bordare();
int cate(int lin, int col);
int main()
{int i, j, nr;
 citire();
 bordare();
 for (i=1; i<=n; i++)
     for (j=1; j<=m; j++)
         if (a[i][j]==0)
             {
              nr=cate(i,j);
              if (nr>=nrmax) {nrmax=nr; linmax=i; colmax=j;}
             }
fout<<nrmax<<' '<<linmax<<' '<<colmax<<'\n';
fout.close();
return 0;
}
void citire()
{int i, lin, col, nr, b;
 fin>>n>>m>>b;
 for (i=0; i<b; i++)
     {fin>>lin>>col>>nr;
      a[lin][col]=nr;}
}
void bordare()
{int i;
 for (i=0; i<=m+1; i++) a[0][i]=a[n+1][i]=-1;
 for (i=0; i<=n+1; i++) a[i][0]=a[i][m+1]=-1;
}
int cate(int lin, int col)
{int k,i,j, rez=0;
 for (k=0; k<4; k++)
     {
     i=lin; j=col;
     while (a[i][j]!=-1)
           {rez+=a[i][j]; i+=dl[k]; j+=dc[k];  }
     }
 return rez;
}