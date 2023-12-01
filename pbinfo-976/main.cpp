#include <iostream>
using namespace std;

int v[10];
int main()
{ 
	unsigned long p,k,n,gr,nr=0, min, max,sum,x;
	long i,j;
	cin >> p >> n >> k;
	nr=0;gr=1;

	while(nr+gr<p)
	{ nr=nr+gr; gr++; }

	min=2*(nr+1)-1;
	max=2*(nr+gr)-1;
	sum=max+min;
	x=2*p-1;

	if(gr%2==0)
		x=sum-x;
	gr=1;

	while(gr*gr*gr<k)gr++;
	if(gr*gr*gr>k)gr--;

	cout << x << endl; //a si b
	nr=n*(n-1)/2;

	int nrc=0;

	for(i=1;i<=n;i++)
	{ x=2*(nr+i)-1;
	do{ nrc++;
	  v[x%10]++;
	  x=x/10;
	 }while(x);
	}


	int cif=-1;
	for(i=9;i>=0;i--)
	if(v[i])
	{ for(j=1; j<=v[i]/2;j++) cout<<i;
	if((v[i]%2!=0)&&(cif==-1))cif=i;
	v[i]=v[i]/2;
	}
	if(cif>-1)
		cout << cif;
	for(i=0;i<=9;i++)
	if(v[i])
	 for(j=1; j<=v[i];j++) 
		cout<<i;
	cout<<endl<<gr<<endl;
	return 0;
}


