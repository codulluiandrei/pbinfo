//Em. Cerchez
#include <fstream>
#include <cstring>
#define NMAX 104
#define INF (NMAX * NMAX +10)
#define LGMAX 21
#define ND 4
using namespace std;
ifstream fin("barlog.in");
ofstream fout("barlog.out");
struct poz {int lin, col;};
int dl[]={-1,0,1, 0};
int dc[]={ 0,1,0,-1};
char b[NMAX][NMAX][LGMAX];
int d[NMAX][NMAX];
int n, m;
char cuv[LGMAX];
poz start;
poz C[NMAX*NMAX];
int prim, ultim;
int cerinta;
int rez[2]={1,INF};
void citire();
void bordare();
void rezolvare();
bool trece(char cuv[], char s[]);
int main()
{
 citire();
 bordare();
 rezolvare();
 fout<<rez[cerinta]<<'\n';
 fout.close();
 return 0;
}
void citire()
{int i, j;
 fin>>cerinta>>n>>m;
 for (i=1; i<=n; i++)
     for (j=1; j<=m; j++) fin>>b[i][j];
 fin>>start.lin>>start.col>>cuv;
 cerinta--;
}
void rezolvare()
{poz p;
int k;
 d[start.lin][start.col]=1;
 C[0]=start; prim=ultim=0;
 while (prim<=ultim)
       {
        p=C[prim++];
        if (trece(cuv,b[p.lin][p.col]))
        for (k=0; k<ND; k++)
            if (d[p.lin+dl[k]][p.col+dc[k]]==0)
                {d[p.lin+dl[k]][p.col+dc[k]]=1+d[p.lin][p.col];
                 rez[0]++;
                 ++ultim; C[ultim].lin=p.lin+dl[k]; C[ultim].col=p.col+dc[k];
                }
                else
                if (d[p.lin+dl[k]][p.col+dc[k]]==-1 && rez[1]==INF)
                   rez[1]=d[p.lin][p.col];
       }
}
bool trece(char cuv[], char s[])
{int i;
 char *p=cuv;
 for (i=0; s[i]; i++)
      {p=strchr(p,s[i]);
       if (p) p++;
          else return 0;
      }
 return 1;
}
void bordare()
{int i;
 for (i=0; i<=m+1; i++) d[0][i]=d[n+1][i]=-1;
 for (i=0; i<=n+1; i++) d[i][0]=d[i][m+1]=-1;
}