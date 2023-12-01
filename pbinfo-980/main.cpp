#include <iostream>
using namespace std;

int main()
{ 
	//cerinta a)
	int p;
	cin >> p;
	cout << (p+1)/2 << endl;

	//cerinta b)
	int n;
	cin >> n;
	int x,a,b,y,i,v[10],j,cif=-1;
	a=n*n-n+1; b=n*n+n-1;
	for(i=0;i<=9;i++)
		v[i]=0;
	for(x=a;x<=b;x+=2)
	{
		y=x;
		while (y)
		{
			v[y%10]++;
			y=y/10; 
		}  
	}
	for(i=9;i>=0;i--)
		if(v[i])
		{
			if( v[i] % 2 && cif ==-1 )
				cif=i;
			for(j=1;j<=v[i]/2;j++)
				cout << i;    
		}
	if(cif!=-1)
		cout << cif;
	for(i=0;i<=9;i++)
		if(v[i])
			for(j=1;j<=v[i]/2;j++)
				cout << i;
	cout << endl;
	//cerinta c)
	long k , r;
	cin >> k;    
	r=1;
	if(k%2==0)
		r=2;
	while(r*r*r<k)
		r=r+2;
	if(r*r*r==k)
		cout << r;
    else 
		cout << 0;
	return 0;
}
