//Emanuela Cerchez
#include <fstream>
#define InFile "arme.in"
#define OutFile "arme.out"
#define NMAX 1001
using namespace std;
struct arma {short int nr, p;} b[NMAX], c[NMAX], mut[NMAX];
short int N, M, cate;
long int smax;
char T[10][10];
char s[100];
void citire();
void afisare();
void sortare(arma[], short int);
long int suma();
int main()
{
citire();
sortare(b,N);
sortare(c,M);
smax=suma();
afisare();
return 0;
}
void citire()
{
int i;
ifstream fin(InFile);
fin>>N>>M;
for (i=1; i<=N; i++)
    {fin>>b[i].p; b[i].nr=i;}
for (i=1; i<=M; i++)
    {fin>>c[i].p; c[i].nr=i;}
}
void sortare(arma b[NMAX], short int N)
{
short int i, sch;
arma aux;
do{
sch=0;
for (i=1; i<N; i++)
    if (b[i].p>b[i+1].p)
       {aux=b[i]; b[i]=b[i+1]; b[i+1]=aux; sch=1;}
}
while (sch);
}
long int suma()
{
short int i, j, aux;
long int s=0;
cate=0;
for (i=1, j=M; i<=N && j>0;i++, j--)
    if (b[i].p<c[j].p)
       {
       aux=b[i].p; b[i].p=c[j].p; c[j].p=aux;
       mut[cate].nr=i; mut[cate].p=j; cate++;
       }
       else
       break;
for (i=1; i<=N; i++) s+=b[i].p;
return s;
}
void afisare()
{
ofstream fout(OutFile);
fout<<smax<<'\n';
/*
fout<<cate<<'\n';
for (i=0; i<cate; i++)
    fout<<mut[i].nr<<' '<<mut[i].p<<'\n';
    */
fout.close();
}