#include <cstdio>
#include <cstring>
using namespace std;
int R[16][21], T[16], C[21], sol[16];
int n, m;
double Sum=10000.0;
int verif();
double suma();
int main ()
{
int i, nr_med, j, x, k;
double s;
long nrsol;
FILE * fin=fopen("reteta1.in","r");
FILE * fout=fopen("reteta1.out","w");
fscanf (fin, "%d %d" , &n , &m );
for ( i=1 ; i<=m ; i++ )
    {
     fscanf (fin, "%d %d" , T+i , &nr_med  );
     for ( j=1 ; j<=nr_med ; j++ )
	 {
	  fscanf (fin, "%d" , &x );
	  R[i][x]++;
	 }
    }
for ( i=1 ; i<=n ; i++ ) {fscanf (fin, "%d" , &C[i] );}
nrsol=(1<<m)-1;
//generez submultimi de retete
sol[m]=1;
for (k=0; k<nrsol; k++)
    {
    if (verif())
       {
        s=suma();
        if (s<Sum) Sum=s;
       }
    i=m;
    while (sol[i]) {sol[i]=0; i--;}
    sol[i]=1;
    }
fprintf(fout,"%.1lf",Sum);
return 0;
}
int verif()
{
int uz[21], i, k;
for (i=1; i<=n; i++) uz[i]=0;
for (k=1; k<=m; k++)
    if (sol[k])
       {
       for (i=1; i<=n; i++)
           uz[i]+=R[k][i];
       }
for (i=1; i<=n; i++)
    if (uz[i]!=1) return 0;
return 1;
}
double suma()
{
double s=0;
int k, i;
for (k=1; k<=m; k++)
    if (sol[k])
       {
       for (i=1; i<=n; i++)
           s+=(R[k][i]*C[i])/(double)T[k];
       }
return s;
}