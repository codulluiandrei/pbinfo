#include <iostream>
using namespace std;
int main()
{
	int a,b,c,n,i,k,s=0,nr=0,y;
	int p;
	cin>>n>>k>>p;
	a=1; b=2;  y=p%60;
	if(a==k)nr++;
	if(b==k)nr++;
	s=2;
	for(i=3;i<=n;i++)
	{
		c=(a+b)%10;  
		a=b; b=c;
		if((c==2)||(c==3)||(c==5)||(c==7))s=s+c;
		if(c==k)nr++;
	}
	a=1; b=2;
	if(y==1)
		c=a;
	else
		if(y==2)
			c=b;
		else
		{
			if(y==0)
				y=60;
			for(i=3;i<=y;i++)
			{
				c=(a+b)%10;  
				a=b; b=c;
			}
	}
	cout<<s;
	cout<<endl<<nr;
	cout<<endl<<c;
	return 0;
}                             