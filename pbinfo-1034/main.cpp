// sursa de 100 p - prof. Chesca Ciprian
#include <fstream>

#define nmax 361
#define pmax 100001

using namespace std;


ifstream f("roata.in");
ofstream g("roata.out");

// n = numarul de cabine, p = numarul de persoane

int main()
{
// o - ordinea la urcare, c - costul biletului	

int n,p,i,k,pozmax,pozmin,o[nmax],c[pmax];
long long s=0;

f>>n>>p;

// initializez numerele de ordine ale primilor n clienti
for(i=1;i<=n;i++) 
	o[i]=i;

// citesc numarul de rotiri si calculez suma totala incasata
for(i=1;i<=p;i++) 
	{f>>c[i];s+=c[i];}

// afisez suma totala incasata
g<<s<<"
";

if (n<p)
	for(k=n+1;k<=p;k++)
		{
		// determin clientul care urmeaza sa coboare
		pozmin=1;
		for(i=2;i<=n;i++)
			if (c[i]<c[pozmin]) pozmin=i;	
		
		// afisez ordinea la coborare
		g<<o[pozmin]<<" ";
				
		// resetez toate valorile lui c[i] pentru ca sunt prea mari
		if (c[pozmin]>10000000)
			for(i=1;i<=n;i++)
					c[i]-=10000000;
		
		c[pozmin]+=c[k]; // o mica smecherie - in loc sa scad din toate minimul, am adunat 		
		o[pozmin]=k; 
		}
	else
		n=p;
	
// determin numarul cabinei din care va cobora ultimul client
pozmax=1;
for(i=2;i<=n;i++)
	if (c[i]>=c[pozmax]) pozmax=i;
		
for(k=1;k<=n;k++)
		{
		// determin clientul care urmeaza sa coboare
		pozmin=1;
		for(i=2;i<=n;i++)
			if (c[i]<c[pozmin]) pozmin=i;	
		
		// afisez ordinea la coborare
		g<<o[pozmin]<<" ";
				
		c[pozmin]+=100001; 
		}	

// afisez numarul cabinei din care va cobora ultimul client
g<<"
"<<pozmax<<"
";	

f.close();
g.close();
return 0;
}

