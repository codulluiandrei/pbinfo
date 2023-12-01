// O(n)
#include <fstream>
using namespace std;

int mod=666013,a,b;
int s[1000100],u[1000100],z[1000100],n;
int main()
{
	ifstream in("unuzero.in");
	ofstream out("unuzero.out");
	
	in>>n>>a>>b;
	z[0]=1;
	s[0]=1;
	for(int i=1;i<=n;++i)
	{
		z[i]=z[i-1]+u[i-1]; // daca punem 0
		z[i]%=mod;
		
		if(i-a>=0)
		{
			if(i-b-1>=0)
			{
				u[i]=s[i-a]-s[i-b-1];
			}
			else
			{
				u[i]=s[i-a];
			}
		}
		
		if(u[i]<0) u[i]+=mod;
		u[i]%=mod;
		
		s[i]=s[i-1]+z[i];
		s[i]%=mod;
	}
	
	out<<(z[n]+u[n]-1+(z[n]+u[n]-1<0?mod:0))%mod<<'\n';
	out.close();
	return 0;
}