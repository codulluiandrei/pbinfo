#include <stdio.h>
#include <math.h>
//using namespace std;
//ifstream f("cuburi.in");
//ofstream g("cuburi.out");

int w[100001];
int nrmin(int x,int nrc)
{
	int v[10],i,Min,imin,in,sf;
	for(i=nrc;i>=1;i--){v[i]=x%10;x=x/10;}
	Min=v[1];imin=1;
	for(i=1;i<=4;i++)
		if(v[i]<Min && v[i]!=0) {Min=v[i];imin=i;}
	int nr=Min;in=imin+1;sf=5;
    while(sf<=nrc)
	{
		Min=v[in];imin=in;
		for(i=in;i<=sf;i++)
			if(v[i]<Min){Min=v[i];imin=i;}
		nr=nr*10+Min;
        in=imin+1;sf++;			
	}		
	return nr;	
}


int main()
{
	freopen("cuburi.in","r",stdin);
	freopen("cuburi.out","w",stdout);
	int x,nrc,n,nrpir=0,i,k,j=1,nr=0,s=0;
	scanf("%d %d",&n, &k);
//	f>>n>>k;
	for(i=1;i<=k;i++)
	nr=nr+i*i*6;
	for(i=1;i<=n;i++)
	{
//	f>>x;
	scanf("%d",&x);
	nrc=(int)log10(x)+1;
	if(i%6==0 && (sqrt(i/6)==(int)sqrt(i/6))) {s=s+i;if(s<=n) nrpir++;}
	if(i<=nr) w[j++]=nrmin(x,nrc);
	}
	
	printf("%d\n",nrpir);
//	g<<nrpir<<'\n';
	for(i=1;i<j;i++)
		printf("%d ",w[i]);
//		g<<w[i]<<' ';
//	g<<'\n';
	printf("\n");

	return 0;
}