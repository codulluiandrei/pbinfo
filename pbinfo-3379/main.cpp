//Em. Cerchez 100
#include <fstream>
#define LGMAX 300
#define NMAX 900
using namespace std;
ifstream fin("nkgraf.in");
ofstream fout("nkgraf.out");
typedef char NrMare[LGMAX];
struct arc {int x, y;};
void Afisare(NrMare x, int lgx);
void Suma(NrMare x, int lgx, NrMare y, int lgy, NrMare z, int& lgz);
void Zero(NrMare x, int st, int dr);
void combinari();
void arce();
void genereaza();
void afiseaza_sol();
int N, K, P, cerinta, n, lp, lc;
NrMare C[2][NMAX];
int lg[2][NMAX];
int sol[NMAX*NMAX];
arc a[NMAX*NMAX];
int main()
{
 fin>>cerinta>>N>>K>>P;
 n=N*(N-1);
 if (cerinta==1)
    {
     combinari();
     Afisare(C[lp][K],lg[lp][K]);
    }
    else
    {arce();
     genereaza();
     afiseaza_sol();
    }
 fout.close();
 return 0;
}
void Afisare(NrMare x, int lgx)
{int i;
  for (i=lgx-1; i>=0; i--) fout<<(int)x[i];
  fout<<'\n';
}
void Suma(NrMare x, int lgx, NrMare y, int lgy, NrMare z, int& lgz)
{int i, t, rez;
 if (lgx<lgy) {lgz=lgy; Zero(x,lgx,lgy);}
    else {lgz=lgx; Zero(y,lgy,lgx);}
 for (i=t=0; i<lgz; i++ )
     {
      rez=x[i]+y[i]+t;
      z[i]=rez%10;
      t=rez/10;
     }
  if (t) z[lgz++]=t;
}
void Zero(NrMare x, int st, int dr)
{ int i;
  for (i=st; i<dr; i++) x[i]=0;
}
void combinari()
{int i, j;
 lp=0, lc=1;
 C[0][0][0]=1;lg[0][0]=1; C[0][1][0]=1; lg[0][1]=1; C[1][0][0]=1; lg[1][0]=1;
 for (i=2; i<=n; i++)
     {
     for (j=1; j<i; j++)
        Suma(C[lp][j],lg[lp][j], C[lp][j-1], lg[lp][j-1], C[lc][j], lg[lc][j]);
     C[lc][i][0]=1; lg[lc][i]=1;
     lp=1-lp; lc=1-lc;
     }
}
void genereaza()
{int i, j;
 for (i=1; i<=K; i++) sol[i]=i;
 for (j=2; j<=P; j++)
     {///succesor
     for (i=K; sol[i]==n-K+i; i--);
     sol[i]++;
     for (i++; i<=K; i++) sol[i]=1+sol[i-1];
     }
}
void arce()
{int i, j, nr=0;
 for (i=1; i<=N; i++)
     for (j=1; j<=N; j++)
          if (i!=j) {++nr; a[nr].x=i; a[nr].y=j;}
}
void afiseaza_sol()
{int i;
 for (i=1; i<=K; i++)
      fout<<a[sol[i]].x<<' '<<a[sol[i]].y<<'\n';
}