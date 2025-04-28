#include<fstream>
using namespace std;
ifstream fin("vot.in");
ofstream fout("vot.out");
int n, x[1001],b[1001],i,j,ex,k,c[1001],p,u;
int main()
{
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>x[i];
		b[x[i]]++;
	}
	p=1;u=0;
	for(i=1;i<=n;i++)
		if(b[i]==0){u++;c[u]=i;}
	while(p<=u)
	{
		j=c[p];
		if(x[j]>0 && b[j]==0)
			{
				b[x[j]]--;
				if(b[x[j]]==0){u++;c[u]=x[j];}
				x[j]=-1;
			}
		p++;
	}
	fout<<n-u<<'\n';
	for(i=1;i<=n;i++)
		if(x[i]>0)fout<<i<<' ';
	fout.close();
	return 0;
}