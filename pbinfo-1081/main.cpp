//implementare de 100 de puncte - ciprian chesca
#include <fstream>
using namespace std;
typedef unsigned long vector[2000];
ifstream f("numar3.in");
ofstream g("numar3.out");
unsigned long prim[]={2,5};
void initializare(vector v) {   
  v[0] = 0;   
}  
void atribuire(vector v, unsigned long x) {   
  v[0] = 0;   
  while (x) {   
      ++v[0];   
      v[v[0]] = x % 10;   
      x /= 10;   
  }   
}  
void inmultire(vector v, unsigned long x)   
/* v <- v*x */  
{ unsigned long i,t=0;   
  for (i=1;i<=v[0];i++)   
    { v[i]=v[i]*x+t;   
      t=v[i]/10;   
      v[i]=v[i]%10;   
    }   
  while (t) /* Cat timp exista transport */  
    { v[++v[0]]=t%10;   
      t/=10;   
    }   
}  
void adunare(vector a, vector b)   
/* a <- a+b */  
{ unsigned long i,t=0;   
  if (b[0]>a[0])   
    { for (i=a[0]+1;i<=b[0];) a[i++]=0;   
      a[0]=b[0];   
    }   
    else for (i=b[0]+1;i<=a[0];) b[i++]=0;   
  for (i=1;i<=a[0];i++)   
    { a[i]+=b[i]+t;   
      t=a[i]/10;   
      a[i]%=10;   
    }   
  if (t) a[++a[0]]=t;   
}  
void scriere(vector v)
{
unsigned long i;
for(i=v[0];i>=1;i--)
	g<<v[i];
g<<endl;
}
void shl(vector a, int p)
/* H <- H*10ACount */
{ long i;
  /* Shifteaza vectorul cu Count pozitii */
  for (i=a[0];i;i--) a[i+p]=a[i];
  /* Umple primele Count pozitii cu 0 */
  for (i=1;i<=p;) a[i++]=0;
  /* Incrementeaza numarul de cifre */
  a[0]+=p;
}
void shr(vector a, int p)
/* H <- H/10ACount */
{ unsigned long i;
  /* Shifteaza vectorul cu Count pozitii */
  for (i=p+1;i<=a[0];i++) a[i-p]=a[i];
  /* Decrementeaza numarul de cifre */
  a[0]-=p;
}
unsigned long divide(vector a, unsigned long x)
/* A <- A/X si intoarce A%X */
{ unsigned long i;
  unsigned long R=0;
  for (i=a[0];i;i--)
    { a[i]=(R=10*R+a[i])/x;
      R%=x;
    }
  while (!a[a[0]] && a[0]>1) a[0]--;
  return R;
}
unsigned long mod(vector a, unsigned long x)
/* Intoarce A%X */
{ unsigned long i;
  unsigned long R=0;
  for (i=a[0];i;i--)
    R=(10*R+a[i])%x;
  return R;
}
int main()
{
	unsigned long n,m,i;
	vector v; // numarator
	vector s; // numitor
	initializare(v);
	initializare(s);
	f>>n>>m;
	// citesc partea intreaga
	for(i=1;i<=n;i++)
		f>>v[n+m-i+1];
	// citesc partea fractionara
	for(i=1;i<=m;i++)
		f>>v[m-i+1];
	v[0]=n+m;
	if (v[n+m]==0) v[0]--;
	atribuire(s,1);
	shl(s,m);
	if (m==0) {g<<n<<"\n";scriere(v);g<<1<<"\n";scriere(s); return 0;}
	for(i=0;i<=1;i++)
		while (mod(v,prim[i])==0&&mod(s,prim[i])==0) 
				{ 
				divide(v,prim[i]);
				divide(s,prim[i]);
				}
	g<<v[0]<<"\n";scriere(v);g<<s[0]<<"\n";scriere(s);	
f.close();
g.close();
return 0;
}