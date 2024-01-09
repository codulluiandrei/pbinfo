#include <fstream>
#define InFile "rj.in"
#define OutFile "rj.out"
#define NMax 102
#define NV 8

using namespace std;

int n, m, xr, yr, xj, yj;
int dl[NV]={0, 1, 0, -1, -1, 1, -1, 1};
int dc[NV]={1, 0, -1, 0, -1, 1,  1,-1};
char l[NMax][NMax];
int r[NMax][NMax];

void citire(void);
void afisare(int [NMax][NMax]);
void parcurge (int, int, int[NMax][NMax]);

int main()
{
    int j[NMax][NMax];
 	citire();
 	parcurge(xr, yr, r);
 	parcurge(xj, yj, j);
 	afisare(j);
    return 0;
}

void citire(void)
{
int i, k;
char c;
ifstream f(InFile);
f>>n>>m;
for (i=0; i<=n+1; i++) l[i][0]=l[i][m+1]='X';
for (i=0; i<=m+1; i++) l[0][i]=l[n+1][i]='X';
f.get(c);
for (i=1; i<=n; i++)
	{for (k=1; k<=m; k++)
		{f.get(c); l[i][k]=c;
		 if (l[i][k]=='R') {xr=i; yr=k; l[i][k]=' ';}
		 if (l[i][k]=='J') {xj=i; yj=k; l[i][k]=' ';}
		}
	f.get(c);}
f.close();
}

void parcurge (int x0, int y0, int d[NMax][NMax])
{
struct Punct {int l, c;} C[NMax*NMax], p;
int inc=0, sf=0, i, k;
for (i=0; i<=n+1; i++)
	for (k=0; k<=m+1; k++) d[i][k]=-1;
C[0].l=x0; C[0].c=y0; d[x0][y0]=1;
while (inc<=sf)
	{
	 p=C[inc++];
	 for (i=0; i<NV; i++)
		if (l[p.l+dl[i]][p.c+dc[i]]==' ' && d[p.l+dl[i]][p.c+dc[i]]==-1)
			{
			d[p.l+dl[i]][p.c+dc[i]]=1+d[p.l][p.c];
			C[++sf].l=p.l+dl[i];
			C[sf].c=p.c+dc[i];
			}
	}
}

void afisare(int j[NMax][NMax])
{
ofstream f(OutFile);
int tmin=NMax*NMax+5, xmin=-1, ymin=-1, i, k;
for (i=1; i<=n; i++)
	for (k=1; k<=m; k++)
		if (r[i][k]==j[i][k])
			if (r[i][k]<tmin && r[i][k]!=-1)
				{tmin=r[i][k]; xmin=i; ymin=k;}
f<<tmin<<' '<<xmin<<' '<<ymin<<endl;
f.close();
}