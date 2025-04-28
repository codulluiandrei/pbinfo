#include <iostream>
using namespace std;
int P[20];
void generare(int k , int n)
{
	if(k <= n)
	{
		//afisez numerele de la 2^(k-1)+1 la 2^k
		int mij = (P[k-1] + P[k])/2;
		for(int i = P[k-1] + 1 ; i <= mij ; i ++)
			cout << i << " ";
		generare(k+1 , n);
		for(int i = mij + 1 ; i <= P[k] ; i ++)
			cout << i << " ";
	}
}
int main()
{
	int n;
	cin >> n;
	P[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		P[i] = 2 * P[i-1];
	cout << 1 << " ";
	generare(1 , n);
	return 0;
}