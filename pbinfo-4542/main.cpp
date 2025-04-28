#include <iostream>
using namespace std;
void citire(int n , int a[])
{
	if(n > 0)
	{
		citire(n-1 , a);
		cin >> a[n];
	}
}
void afisare(int n , int a[])
{
	if(n > 0)
	{
		afisare(n-1 , a);
		cout << a[n] << " ";
	}
}
int elim_cifre_impare(int n)
{
	if(n == 0)
		return 0;
	else
	{
		int x = elim_cifre_impare(n/10);
		if(n % 2 == 0)
			x = 10 * x + n % 10;
		return x;
	}
}
int numar_cifre(int n)
{
	if(n < 10)
		return 1;
	else
		return 1 + numar_cifre(n / 10);
}
void inloc(int n , int a[])
{
	if(n > 0)
	{
		inloc(n-1 , a);
		if(numar_cifre(a[n]) % 2 == 1)
			a[n]  = elim_cifre_impare(a[n]);
	}
}
int main(){
	int n, a[1005];
  	cin >> n;
  	citire(n , a);
  	inloc(n , a);
  	afisare(n , a);
	return 0;
}