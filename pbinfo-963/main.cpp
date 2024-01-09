#include <fstream>
using namespace std;
int v[105],fr[105];

int main()
{ 
	ifstream f("bazine.in");
	ofstream g("bazine.out");
	int n,i,j,a,b,p,k,m;
	f>>n>>m;
	for(i=1;i<=n;i++)
		v[i]=i;
	for(k=1;k<=m;k++)
	{
		f>>i>>j;
		if(v[i]!=v[j])
		{
			a=v[i];
			if(a<=v[j])
				b=v[j];
			else 
			{
				b=a; a=v[j];
			}
			for(p=1;p<=n;p++)
				if(v[p]==b)
					v[p]=a;
		}
	}
	k=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(v[j]==i)
			{
				k++;
				break;
			}
	g<<k<<endl;
	f.close();
	g.close();
	return 0;}
