// sursa de 100 puncte Ciprian Chesca
#include <fstream>
#define nmax 100001
using namespace std;
int main()
{
ifstream f("deal.in");
ofstream g("deal.out");
long n,w[nmax],v[nmax],i,x,st,dr,pdp;
long long s=0;
f>>n;
for(i=1;i<nmax;i++) 
	w[i]=0;
for(i=1;i<=n;i++)
	{f>>x;w[x]++;}
for(i=1;i<=n;i++)
	v[i]=w[i];	
st=1;dr=nmax-1;
while (w[st]==0) st++;
while (w[dr]==0) dr--;
while (st!=dr)
{
	if (w[st]==0) st++;
		else 
			if (w[dr]==0) dr--;
				else {s=s+dr;w[st]--;w[dr]--;}
}
pdp=(n-w[dr])/2+1-(v[dr]-w[dr]);
if (w[dr]/2<=pdp) s=s+dr*(w[dr]/2);
  else s=s+dr*pdp;
g<<s;
f.close();
g.close();
return 0;
}