//prof. Em. Cerchez
#include <fstream>
#define LGMAX 10002
#define NMAX 5560
using namespace std;
ifstream fin("braduti.in");
ofstream fout("braduti.out");
typedef int NrMare[LGMAX];
int h(int N);
void nr(int N, NrMare rez, int& lgrez);
void scrie (NrMare rez, int lgrez);
void prod(NrMare a, int lga, int x, NrMare p, int& lgp);
void descompunere(int st, int dr, int semn);
int C, N;
NrMare rez, c, t;
int lgrez, lgc, lgt;
int p[NMAX];
int main()
{
  fin>>C>>N;
  if (C==1)
    fout<<h(N)<<'\n';
    else
    {nr(N, rez, lgrez);
     scrie(rez,lgrez);
    }
  fout.close();
  return 0;
}
int h(int N)
{int rez=0, pas=3;
 while (pas<=N) {rez++; N-=pas; pas+=2;}
 return rez;
}
void nr(int N, NrMare rez, int& lgrez)
{int pas=3, i, j;
 while (pas<=N)
       {//combinari de N luate cate pas
         descompunere(pas+1, N, 1);
         descompunere(2, N-pas, -1);
         N-=pas;
         pas+=2;
       }
 rez[0]=1; lgrez=1;
 for (i=2; i<NMAX; i++)
     for (j=0; j<p[i]; j++)
         prod(rez,lgrez,i,rez,lgrez);
}
void scrie (NrMare rez, int lgrez)
{int i;
 for (i=lgrez-1; i>=0; i--) fout<<rez[i];
 fout<<'\n';
}
void descompunere(int st, int dr, int semn)
{int k, d, x;
 for (k=st; k<=dr; k++)
      {d=2; x=k;
       while (d*d<=x)
             {
               while (x%d==0)
                     {p[d]+=semn;
                      x/=d;}
               d++;
              }
       if (x>1) p[x]+=semn;
      }
}
void prod(NrMare a, int lga, int x, NrMare p, int& lgp)
{int t = 0, val, i;
 for (i=0; i<lga; i++)
     {
       val = a[i] * x + t;
       p[i] = val %10;
       t = val / 10;
    }
 lgp = lga;
 while (t)
      {
       p[lgp] = t%10;
       lgp++;
       t = t/10;
    }
}