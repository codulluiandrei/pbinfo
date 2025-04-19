#include <iostream>
using namespace std;
int a[1005], b[1005], c[2005], n ,m , p;
int main(){
	cin  >> n;	
	for(int i = 1 ; i <= n ;  ++i)
		cin >> a[i];
	cin >> m;
	for(int i = 1 ; i <= m ;  ++i)
		cin >> b[i];
	//determinam reuniunea
	p = 0;
	for(int i  = 1 ; i <= n ; i ++)
		c[++p] = a[i];
	for(int i = 1 ; i <= m ; ++i)
	{
		bool ok = true;
		for(int j = 1 ; j <= n && ok ; j ++)
			if(b[i] == a[j])
				ok = false;
		if(ok)
		{
			p ++;
			int j;
			for(j = p ; j > 1 && c[j-1]>b[i] ; j --)
				c[j] = c[j-1];
			c[j] = b[i];
		}
	}
	for(int i = 1 ; i <= p ; i ++)
		cout << c[i] << " ";
	cout << "\n";
	//determinam intersectia
	p = 0;
	for(int i = 1 ; i <= m ; ++i)
	{
		bool ok = false;
		for(int j = 1 ; j <= n && !ok ; j ++)
			if(b[i] == a[j])
				ok = true;
		if(ok)
		{
			p ++;
			c[p] = b[i];
		}
	}
	for(int i = 1 ; i <= p ; i ++)
		cout << c[i] << " ";
	return 0;
}