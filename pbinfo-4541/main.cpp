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
int prima_cifra(int n)
{
	if(n < 10)
		return n;
	else
		return prima_cifra(n / 10);
}
int suma_cifre(int n)
{
	if(n < 10)
		return n;
	else
		return n%10 + suma_cifre(n / 10);
}
void inloc(int n , int a[])
{
	if(n > 0)
	{
		inloc(n-1 , a);
		if(prima_cifra(a[n]) % 2 == 0)
			a[n]  = suma_cifre(a[n]);
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