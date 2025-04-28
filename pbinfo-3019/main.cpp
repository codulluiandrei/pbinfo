#include<fstream>
using namespace std;
ifstream f("joc10.in");
ofstream g("joc10.out");
int b[140][140],a[140][140],vcerc,pmax,i,j,n;
int main ()
{
	f>>n;
	n++;
	///A
	for(i=1;i<=n;++i)
		for(j=1;j<=i;++j)
			{f>>a[i][j];b[i][j]=a[i][j];}
	for(i=n;i>=1;--i)
		for(j=1;j<=i;++j)
			b[i][j]=b[i][j]+max(b[i+1][j],b[i+1][j+1]);
	if(b[1][1]>pmax) vcerc=a[1][1],pmax=b[1][1];
    ///B
	for(i=1;i<=n;++i)
		for(j=1;j<=i;++j) b[i][j]=a[i][j];
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j)
			b[j][j-i+1]=b[j][j-i+1]+max(b[j-1][j-i+1],b[j][j-i+2]);
	if( pmax<b[n][1] || (pmax==b[n][1] && vcerc>a[n][1]) )
        vcerc=a[n][1],pmax=b[n][1];
    ///C
	for(i=1;i<=n;++i)
		for(j=1;j<=i;++j) b[i][j]=a[i][j];
	for(i=1;i<=n;++i)
		for(j=i;j<=n;++j)
			b[j][i]=b[j][i]+max(b[j][i-1],b[j-1][i-1]);
    if( pmax<b[n][n] || (pmax==b[n][n] && vcerc>a[n][n]) )
        vcerc=a[n][n],pmax=b[n][n];
	g<<pmax<<'\n'<<vcerc<<'\n';
	return 0;
}