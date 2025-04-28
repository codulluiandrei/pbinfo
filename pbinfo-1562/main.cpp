/**
Problema: abba
    codificare sir prin
    inserare litera mijlocie
*/
#include <fstream>
#include <cstdlib>
using namespace std;
char x,y,dif_max,a,b,z,etape;
int n=0;
long long p;
int main()
{
	ifstream f("abba.in");
	ofstream g("abba.out");
	f>>x>>y;
	n=2;
	dif_max=labs(x-y);
	a=x;
	b=y;
	x=y;
	while(f>>y)
	{
		n++;
		z=labs(x-y);
		if(dif_max<z)
		{
			dif_max=z;
			a=x;
			b=y;
		}
		x=y;
	}
	if(b<a)
		swap(a,b);
	while(b-a>1)
	{
		a=(a+b)/2; ///cout<<a<<endl;
		etape++;
	}
	p= (long long)(1<<etape) * (n-1) + 1; /// 2^k(n-1)+1
	g<<int(etape)<< " " <<p;
	return 0;
}