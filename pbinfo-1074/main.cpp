#include <fstream>
using namespace std;

int main()
{
	ifstream in("carte.in");
	ofstream out("carte.out");
	int i,j,n,v[10001],zi,maxi,zimaxi,contor;
	in>>n;
	for(i=1;i<=n;i++)
	   in>>v[i];
	j=1;
	zi=0;
	maxi=0;
	while(j<=n)
	{
		contor=0;
		for(i=1;i<=n;i++)
			if(v[i]==j)
			{
				 j++;
				 contor++;
			}
		if(maxi<contor)
		{
			maxi=contor;
			zimaxi=zi;
		}
		zi++;
	}
	out<<zi<<" "<<(zimaxi+1)<<" "<<maxi;
	return 0;
}
