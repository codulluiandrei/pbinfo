//Emanuela Cerchez - O(n)
#include <fstream>
#define NMAX 100002
#define DMAX 100002
#define MOD 666013

using namespace std;
ifstream fin("tdrept.in");
ofstream fout("tdrept.out");

int n;
int xp[NMAX];
int yp[NMAX];

int nrx[DMAX];
int nry[DMAX];

void citire();
int numarare();

int main()
{
    citire();
    fout<<numarare()<<'\n';
    fout.close();
    return 0;
}

void citire()
{int i;
 fin>>n;
 for (i=1; i<=n; i++)
     {fin>>xp[i]>>yp[i];
	  nrx[xp[i]]++;
	  nry[yp[i]]++;
	 }
}

int numarare()
{int i, nr=0;
 for (i=1; i<=n; i++)
     nr=(nr+((long long int)(nrx[xp[i]]-1)*(nry[yp[i]]-1))%MOD)%MOD;
     
     
 return nr;
}
