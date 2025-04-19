#include<fstream>
using namespace std;
ifstream f("numerus.in");
ofstream g("numerus.out");
long n,i,k,a,b,l,c;
int main()
{
	f>>k>>n;
	a=5*(k-1)+1;b=5*k;
	if(k%2==1){for(i=a;i<=b;i++) g<<i<<' ';
	          g<<b;
	         }	
	else{
		g<<b<<' ';
		for(i=b;i>=a;i--) g<<i<<' ';
		}
	g<<'\n';
	l=n/5;
	if(n%5!=0)l++;
	g<<l<<'\n';
	if(n%5==0)
		if(l%2==0) g<<'A'<<' '<<'B';
	    else g<<'E'<<' '<<'F';
	else if(l%2==1) {char c='A'+n%5-1;g<<c;}	
	     else{char c='F'-n%5+1;g<<c;}
	g<<'\n';	 
	f.close();
    g.close();
    return 0;
}