//Em. Cerchez
#include <fstream>
#include <algorithm>
#include <vector>
#define DMAX 302
#define INF -1
#define ND 4
using namespace std;
ifstream fin("pictura.in");
ofstream fout("pictura.out");
struct pozitie {short int lin, col;};
int n, m, c;
short int H[DMAX][DMAX];
bool viz[DMAX][DMAX];
vector<int> C[DMAX][DMAX];
int dl[]={-1,0,1, 0};
int dc[]={ 0,1,0,-1};
int nrvf, nr, nrmaxim=1;
int vf;
pozitie S[DMAX*DMAX];
vector<int> a[DMAX*DMAX];
void citire();
bool varf(int i, int j);
void vopseste(int i, int j, int culoare);
void cerinta2();
void cerinta3();
void afisare();
int main()
{ int i, j;
  citire();
  for (i=1; i<=n; i++)
       for (j=1; j<=m; j++)
           if (varf(i,j))
              {nrvf++;
               vopseste(i, j, nrvf);
             }
 //afisare();
 for (i=1; i<=n; i++)
       for (j=1; j<=m; j++)
            if (C[i][j].size()>nrmaxim)
                nrmaxim=C[i][j].size();
 if (c==1) fout<<nrmaxim<<'\n';
    else
    if (c==2) cerinta2();
       else cerinta3();
 return 0;
}
void citire()
{int i, j;
 fin>>c>>n>>m;
 for (i=1; i<=n; i++)
     for (j=1; j<=m; j++) fin>>H[i][j];
 //bordare
 for (i=0; i<=m+1; i++) H[0][i]=H[n+1][i]=INF;
 for (i=0; i<=n+1; i++) H[i][0]=H[i][m+1]=INF;
}
bool varf(int i, int j)
{int k;
 for (k=0; k<ND; k++)
     if (H[i][j]<=H[i+dl[k]][j+dc[k]]) return 0;
 return 1;
}
void vopseste(int i, int j, int culoare)
{pozitie p, v;
 int k;
 p.lin=i; p.col=j; C[i][j].push_back(culoare);
 vf=1; S[vf]=p;
 while (vf>0)
       {p=S[vf--];
        for (k=0; k<ND; k++)
             {v.lin=p.lin+dl[k]; v.col=p.col+dc[k];
              if (H[v.lin][v.col]!=INF &&
                  H[p.lin][p.col]>H[v.lin][v.col] &&
                  (C[v.lin][v.col].size()==0 || C[v.lin][v.col].back()!=culoare))
                {
                 C[v.lin][v.col].push_back(culoare);
                 S[++vf]=v;
                }
              }
        }
}
void afisare()
{int i, j, k;
 for (i=1; i<=n; i++)
     {for (j=1; j<=m; j++)
         if (C[i][j].size()==0) fout<<0<<' ';
            else
            {fout<<"(";
             for (k=0; k<C[i][j].size(); k++)
                  fout<<C[i][j][k]<<',';
             fout<<") ";
            }
      fout<<"\n";
     }
 fout<<'\n';
}
bool compar(vector<int> a, vector<int> b)
{int i=0;
 while (i<a.size()&& i<b.size())
        {if (a[i]<b[i]) return 1;
         if (a[i]>b[i]) return 0;
         i++;}
 if (i==a.size() && i<b.size()) return 1;
 return 0;
}
int modul (int x)
{if (x<0) return -x;
 return x;
}
bool diferit(vector<int> a, vector<int> b)
{int i;
 if (a.size()!=b.size()) return 1;
 for (i=0; i<b.size(); i++)
     if (a[i]!=b[i]) return 1;
 return 0;
}
void cerinta2()
{int i, j;
 int rez=0;
 for (i=1; i<=n; i++)
     for (j=1; j<=m; j++)
          a[++nr]=C[i][j];
 sort(a+1,a+nr+1, compar);
 rez=1;
 for (i=2; i<=nr; i++)
     if (diferit(a[i-1],a[i])) rez++;
 fout<<rez<<'\n';
}
int zona(int i, int j)
{vector<int> c=C[i][j];
 int k, rez=1;
 pozitie p, v;
 vf=1; S[vf].lin=i; S[vf].col=j; viz[i][j]=1;
 while (vf>0)
       {p=S[vf--];
        for (k=0; k<ND; k++)
            {v.lin=p.lin+dl[k]; v.col=p.col+dc[k];
             if (!diferit(C[p.lin][p.col],C[v.lin][v.col]) && !viz[v.lin][v.col] && H[v.lin][v.col]!=INF)
                {viz[v.lin][v.col]=1;
                 S[++vf]=v; rez++;
                }
            }
        }
 return rez;
}
void cerinta3()
{int i, j, aria;
 int ariamax=0;
 for (i=1; i<=n; i++)
     for (j=1; j<=m; j++)
         if (C[i][j].size()>0)
            {//incepe o noua zona;
             aria=zona(i,j);
             if (aria>ariamax) {ariamax=aria;}
            }
 fout<<ariamax<<'\n';
}