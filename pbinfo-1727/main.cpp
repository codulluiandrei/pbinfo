#include<fstream>

using namespace std;
int x[2001],apc[101],N,k,c,nrc,apc1[101],maxck,nrck,nrmax,nrmaxk;
ifstream fin("culori.in");
ofstream fout("culori.out");
void citire()
{int i;
fin>>N>>k;
fin>>x[1];
x[N+1]=x[1];
c=x[1];
fin>>x[2];
x[N+2]=x[2];
if(x[2]>c)c=x[2];

for(i=3;i<=N;i++)
	{fin>>x[i];
	 x[N+i]=x[i];
     if(x[i]>c)c=x[i];
	 if(x[i-1]==x[i-2]&&x[i]==x[i-1])
		 nrc++;
	}
if(x[1]==x[N]&&x[N]==x[N-1])
	nrc++;
if(x[1]==x[2]&&x[1]==x[N])
	nrc++;
}
int main()
{int i,j;
  citire();
  maxck=0;
  for(i=1;i<=k;i++)
	  {apc1[x[i]]++;
	   if(apc1[x[i]]>maxck)
	     maxck=apc1[x[i]];
	  }

for(i=2;i<=N;i++)
{apc1[x[i-1]]--;
 apc1[x[i+k-1]]++;
 
 for(j=1;j<=c;j++)
	 if(apc1[j]>maxck)
		 maxck=apc1[j];
 
}

fout<<nrc<<endl<<maxck<<endl;

fin.close();fout.close();	
return 0;	
}
