// sursa 100 puncte - Chesca Ciprian

#include <fstream>
#include <math.h>

using namespace std;

typedef unsigned short cifra;

ifstream f("7segmente.in");
ofstream g("7segmente.out");

// v = vector in care obtin cifrele lui n
// t = vector in care formez numarul t
cifra v[20],t[20],p=0;


// vectorul puterilor necesare la afisarea unei cifre (desi este prezenta - nu folosesc cifra 0)
cifra pw[10]={6,2,5,5,4,5,6,3,7,6};

unsigned long long n,cc=1;

int main()
{

cifra pc=0,i=0,nc=0,aux=0,dmin=0,dmax=0,cifra,egalcif=1;

f>>n>>p;

v[0]=0;i=0;
while (n>0)
{
	v[++i]=n%10;
	switch (n%10)
	{
	case 1 : pc=pc+2;break;
	case 2 : pc=pc+5;break;
	case 3 : pc=pc+5;break;
	case 4 : pc=pc+4;break;
	case 5 : pc=pc+5;break;
	case 6 : pc=pc+6;break;
	case 7 : pc=pc+3;break;
	case 8 : pc=pc+7;break;
	case 9 : pc=pc+6;break;
	}
	n=n/10;
}
v[0]=i;
g<<pc<<" ";


// oglindesc cifrele
for(i=1;i<=v[0]/2;i++)
{
	aux=v[i];
	v[i]=v[v[0]+1-i];
	v[v[0]+1-i]=aux;
}


// calculez numarul de cifre(nc) maxim pe care-l poate avea t
nc=p/2;
if (nc>=v[0]) nc=v[0];


// setez toate cifrele la 1
for(i=1;i<=nc;i++)
	t[i]=1;

// din puterea data scad puterea utilizata pentru cifrele de 1
p=p-2*nc;

t[0]=nc;cc=1;egalcif=1;
while (p>0&&cc<=t[0])
{
 dmin=10;cifra=1;dmax=0;
 
 // caut cifra corespunzatoare
 for(i=2;i<=9;i++)
 { 
    if (t[0]==v[0]&&egalcif==1)
		 if (i<=v[cc]&&abs(i-v[cc])<=dmin&&p-pw[i]+pw[1]>=0) 
			 { cifra=i;dmin=abs(i-v[cc]); }
	if (t[0]<v[0]||egalcif==0)		 
		 if (i>=dmax&&p-pw[i]+pw[1]>=0) 
			 {cifra=i;dmax=i;}			 
 }
 // daca am setat o cifra mai mica, restul cifrelor pot fi mai mari
 if (v[cc]-cifra!=0) egalcif=0;
	 
 
 // asez cifra pe pozitia corecta si recalculez puterea		 
 p+=pw[1];p-=pw[cifra];t[cc++]=cifra;
}

for(i=1;i<=t[0];i++)
	g<<t[i];

g<<"\n";

f.close();
g.close();
return 0;
}

