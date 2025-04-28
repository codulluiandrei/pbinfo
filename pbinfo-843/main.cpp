#include <iostream>
using namespace std;
int a , n , p;
int p10;
int putere(int a ,int n)
{
	if(n == 0)
		return 1;
	if(n % 2 == 1)
	{
		long long tmp = putere(a , n - 1);
		tmp *= a;
		return tmp % p10;
	}
	else
	{
		long long tmp = putere(a , n / 2);
		return (tmp * tmp) % p10;
	}
}
int main(){
	cin >> a >> n >> p;
	p10 = 1;
	for(int i = 1 ; i <= p ; i ++)
		p10 *= 10;
	cout << putere(a , n);
	return 0;
}