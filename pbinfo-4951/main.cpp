//Em. Cerchez 100
#include <fstream>
#define PMAX 10002
#define NMAX 502
using namespace std;
ifstream fin("gems.in");
ofstream fout("gems.out");
int n, p, nr;
int v[NMAX];
int out[PMAX];
int cmax[2][PMAX];
void citire();
int pd();
int max3(int a, int b, int c);
int valoare(int lin, int col);
int main()
{
 citire();
 fout<<pd()<<'\n';
 return 0;
}
void citire()
{int i;
 fin>>n>>p;
 for (i=1; i<=n; i++) fin>>v[i];
 v[0]=v[n];
 while (fin>>out[++nr]);
}
int pd()
{int i, j, lcrt=1, lprec=0;
 int maxim=-1;
 for (i=1; i<=p; i++) cmax[0][i]=valoare(1,i);
 for (i=2; i<=p; i++)
      {
      for (j=1; j<=p; j++)
          cmax[lcrt][j]=valoare(i,j)+max3(cmax[lprec][j-1],cmax[lprec][j],cmax[lprec][j+1]);
      lprec=1-lprec; lcrt=1-lcrt;
     }
 for (i=1; i<=nr; i++)
     if (maxim<cmax[lprec][out[i]]) maxim=cmax[lprec][out[i]];
 return maxim;
}
int max3(int a, int b, int c)
{int maxim=a;
 if (maxim<b) maxim=b;
 if (maxim<c) maxim=c;
 return maxim;
}
int valoare(int lin, int col)
{int poz=((lin-1)*p+col)%n;
 return v[poz];
}