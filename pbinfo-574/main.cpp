/*
 * Raspunsul este 3^(n*(n-1)/2)
 * 
 * Pentru implementare sunt necesare numerele mari
 * */
#include <iostream>
using namespace std;
int n , v[10000];
int main()
{
    cin >> n;
    v[0] = 1;
    v[1] = 1;
    n = n * (n-1) / 2;
    for( ; n ; --n)
    {
		int  t = 0;
		for(int i = 1; i <= v[0] ; i ++)
		{
			int aux = v[i] * 3 + t;
			v[i] = aux % 10;
			t = aux /10;
		}
		while(t)
			v[ ++v[0] ] = t % 10, t /= 10;
	}
	for(int i = v[0] ; i ; --i)
		cout << v[i] ;
    return 0;
}