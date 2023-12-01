//Em. Cerchez 100 puncte
#include <cstdio>
#define MAX (NMAX*VMAX+4)
#define NMAX 16
#define DN (1<<NMAX)
#define VMAX 80000
#define LG 32

using namespace std;
FILE * fin=fopen("barliga.in","r");
FILE * fout=fopen("barliga.out","w");
int N,V, rez;
unsigned int s[NMAX][VMAX/LG];
unsigned int masca[LG];
int nrval[DN];
unsigned long long int dn;
int main()
{int i, nr, x, cf, cfmin, j;
 fscanf(fin,"%d %d", &N, &V);
 masca[0]=1; for (i=1; i<LG; i++) masca[i]=1<<i;
 for (i = 0; i < N; i++)
     {fscanf(fin,"%d",&nr);
      for (j=0; j<nr; j++)
          {fscanf(fin,"%d",&x); x--;
           s[i][x/LG]=s[i][x/LG]|masca[x%LG]; } ///x apare pe fata rosie
	 }
dn=1ull<<N; ///doi la n
for (x = 0; x < V; x++) ///pentru fiecare valoare de la 0 la V-1 determin configuratia
    ///cf in care ea nu va aparea in submultime
   ///aceasta configuratie este unica
   {
	cf = 0;
	for (i = 0; i < N; i++)
	    if (s[i][x/LG]&masca[x%LG]) cf|=masca[i];
    nrval[cf]++;
	}
	///determin configuratia in care exista un numar minim de elemente care nu apar
	cfmin=0;
	for (i=0; i<dn; i++)
	    if (nrval[i] < nrval[cfmin])
		    cfmin=i;
///afisare
fprintf(fout,"%d\n",V-nrval[cfmin]);
nr=0;
for (i = 0; i < N; i++)
	if (masca[i] & cfmin) nr++;
fprintf(fout,"%d",nr);
for (i = 0; i < N; i++)
	if (masca[i] & cfmin)
       fprintf(fout," %d",i+1);
fprintf(fout,"\n");
return 0;
}

