// solutie 100 pct Mihai Georgescu
//Emanuela Cerchez 100 puncte
#include <fstream>
#include <cassert>
#define NMAX 100001
using namespace std;
ifstream fin("unific.in");
ofstream fout("unific.out");
int n;
long long int a[NMAX], rez, vmax;
int nrc[10];
int cmax;
int c[10];//cifrele comune perechii curente
int comun(long long int x, long long int y);
int concat(long long int x, long long int y, long long int &rez);
void numara_cifre(long long int x);
int main()
{int i, ok, nr, maxim, cmax,ii;
for (i=vmax=1; i<=18; i++) vmax=vmax*10;
fin>>n;
assert(1<=n && n<=100000);
fin>>a[0]; nr=1;
numara_cifre(a[0]);
assert(a[0]<=vmax);
for (i=1; i<n; i++,nr++)
    {fin>>a[nr]; assert(a[nr]<=vmax);  assert(fin.good());
     numara_cifre(a[nr]);
     //fout<<i<<' '<<a[nr]<<": ";
     while (nr>0 && comun(a[nr],a[nr-1]))
	     {
	      ok=concat(a[nr-1],a[nr], rez);
	      if (ok) {a[nr-1]=rez; nr--;}
              else {nr-=2;}
             }
     //{for (ii=0; ii<=nr; ii++) fout<<a[ii]<<' ';fout<<'\n';}
    }
for (maxim=-1, i=0; i<10; i++) if (nrc[i]>maxim) {maxim=nrc[i]; cmax=i;}
fout<<cmax<<'\n';
fout<<nr<<'\n';
if (nr) {for (i=0; i<nr; i++) fout<<a[i]<<' ';fout<<'\n';}
fout.close();
return 0;
}
int comun(long long int x, long long int y)
//returnez 1 daca x si y au cifre in comun
{int cy[10], i;
//c[i]=vectorul caracteristic al multimii cifrelor comune
for (i=0; i<10; i++) cy[i]=c[i]=0;
do{c[x%10]=1; x/=10;} while (x);
do {cy[y%10]=1; y/=10;} while(y);
for (i=0; i<10; i++) c[i]=c[i]&&cy[i];
for (i=0; i<10; i++) if (c[i]) return 1;
return 0;
}
int v[20];
int concat(long long int x, long long int y, long long int &rez)
//returneaza 0 daca dupa unificare rezultattul nu mai are cifre;
{
int lgrez=0, lg, i;
rez=0;
do {if (!c[x%10]) v[lgrez++]=x%10; x/=10;} while (x);
while (lgrez>1 && !v[lgrez-1]) {lgrez--;}
for (i=lgrez-1; i>=0; i--) rez=rez*10+v[i];
lg=0;
do {if (!c[y%10]) v[lg++]=y%10; y/=10;} while (y);
while (lg>1 && !v[lg-1]) {lg--;}
lgrez+=lg;
assert(lgrez<=18);
//lipesc cifrele din v la rez
for (i=lg-1; i>=0; i--) rez=rez*10+v[i];
return lgrez;
}
void numara_cifre(long long int x)
{if (!x) {nrc[0]++; return ;}
 while (x) {nrc[x%10]++;x/=10;}	}