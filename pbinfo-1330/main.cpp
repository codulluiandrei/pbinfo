//partitiile unei multimi

#include <fstream>
using namespace std;

int x[10], n;
ofstream g("partitiimultime.out");
ifstream f("partitiimultime.in");

int maxim(int k)
{int i,z=0;
    for(i=1;i<k;i++)
    z=max(x[i],z);
    return z;
}
void scrie()
{ int i,z,j;
  z=maxim(n+1);
  for(i=1;i<=z;i++)
    { for(j=1;j<=n;j++)
        if(x[j]==i)g<<j;
    g<<"*";
    }
    g<<endl;}

void back(int k)
{ if(k==n+1)scrie();
  else
   for(int i=1; i<=maxim(k)+1;i++)
     { x[k]=i;
       back(k+1);}
}

int main()
{ f>>n;
  x[1]=1;
  back(2);
return 0;}
