#include <iostream>
#include <fstream>


using namespace std;
ifstream f("numar.in");
ofstream g("numar.out");

long a[10000];
int n;

void date()
{int i;
  f>>n;
  for(i=0;i<n;i++)
   f>>a[i];
  f.close();
}



int cifre_repetate(long x)
{int a[10],i;
for(i=0;i<=9;i++)
	 a[i]=0;
while(x)
if (a[x%10]!=0) return 1;
 else {a[x%10]=1;x=x/10;}
return 0;
}

long max()
{int i; long max1,max2;
max1=0;
max2=0;
for(i=0;i<n;i++)
 {if (cifre_repetate(a[i])) 
	 if (max2<a[i])	max2=a[i];
  if (max1<a[i]) max1=a[i];
 }
 if (max2==0) return max1;
 else return max2;
}
int este (long x)
{ int i=1,a[100],b[100],k=0,t,z=0,j,ok;

  while (x!=0)
  { a[i]=x%10;
    if (a[i]==0) return 0;
    x/=10;
    b[i++]=1;
   }
   i--;
   for(j=0;j<=i/2;j++)
   {
       z=a[j];
       a[j]=a[i+1-j];
       a[i+1-j]=z;
   }
z=0;
t=a[1];
k=1;ok=1;
for(j=1;j<=i && ok;j++)
 { if(k+t<=i) k=k+t;
   else k=(t-(i-k+1))%i+1;
   if (b[k]!=0)
     {z++;
     b[k]=0;
     }
   else ok=0;
   t=a[k];
}
if (ok) return 1;
 else return 0;
}


int main()
{int p=-1,i,z=0; long t,x,y;
date();
g<<max()<<endl;
z=0;
for(i=0;i<n;i++)
if (este(a[i])) g<<a[i]<<endl;
  else
  {p=0;x=a[i];
  while (!p)
	  if (este(x)) p=1;
     else x++;
	p=0;y=a[i];
  while (!p)
	  if (este(y)) p=1;
     else y--;
  if ((x-a[i])>(a[i]-y)) g<<y<<endl;
	 else g<<x<<endl;
  }
g.close();
return 0;
}
