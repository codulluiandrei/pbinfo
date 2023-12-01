//Emanuela Cerchez
#include <fstream>
#include <cmath>
#define VMAX 10000001
#define PMAX 1000000
#define NMAX 50
using namespace std;
ifstream fin("prime1.in");
ofstream fout("prime1.out");

bool ciur[VMAX];
int nrprim, nr, n;
int prim[PMAX];
int lgprim[PMAX];
long long int a[NMAX], vmax;
int fib[NMAX];
int nrfib;

int main()
{int cerinta, i, j, d, lg, lgx, f1, f2, f3, p, gasit;
 long long int cx;
 fin>>cerinta>>n;
 for (i=0; i<n; i++)
     {
     	fin>>a[i];
     	if (a[i]>vmax) vmax=a[i];
     }
 //ciur
 if (cerinta==2) vmax=sqrt((double)vmax);
 ciur[0]=ciur[1]=1;
 for (d=2; d*d<=vmax; d++)
      if (!ciur[d])
          for (j=d*d; j<=vmax; j+=d)
              ciur[j]=1;
 //transfer intr-un vector numerele prime <=vmax
 prim[0]=2; nrprim=1; lgprim[0]=1;
 for (d=3; d<=vmax; d+=2)
      if (!ciur[d])
         {prim[nrprim]=d;
          cx=d; do {cx/=10; lgprim[nrprim]++;} while (cx);
          nrprim++;
         }
 if (cerinta==1)
    {
     for (f1=f2=1; f1+f2<=vmax; )
         {
          f3=f1+f2; f1=f2; f2=f3;
          if (!ciur[f3]) fib[nrfib++]=f3;
         }
     nr=0;
     for (i=0; i<n; i++)
         {
          for (j=0; j<nrfib && a[i]!=fib[j]; j++);
          if (j<nrfib) nr++;
         }
     fout<<nr<<'\n';
     fout.close();
     return 0;
    }

 if (cerinta==2)
    {nr=0;
     //descompunere in factori primi eficient
     for (i=0; i<n; i++)
         {
     	  cx=a[i]; lgx=0; do {lgx++; cx/=10;} while (cx);
     	  lg=0;
	      for (j=0; j<nrprim && prim[j]*prim[j]<=a[i] && lg<lgx; j++)
		     {
		      for (p=0; a[i]%prim[j]==0; p++,a[i]/=prim[j]);
		      if (p)
                 {
                   lg+=lgprim[j];
                   if (p>1) {cx=p; do {lg++; cx/=10;} while (cx);}
                 }
		      }
     	 if (a[i]>1)
            {cx=a[i]; do {lg++; cx/=10;} while (cx);}
		 if (lg<lgx)
             nr++;
         }
      fout<<nr<<'\n';
      fout.close();
      return 0;
      }
//cerinta 3
nr=0;
for (i=0; i<n; i++)
     {for (gasit=j=0; j<nrprim && a[i]>prim[j]; j++)
         if (!ciur[a[i]-prim[j]]) {gasit=1; break;}
      if (!gasit) nr++;}
fout<<nr<<'\n';
fout.close();
return 0;
}
