#include <iostream>
using namespace std;
void generare (int n , int p)
{
	if(n)
	{
		if(n % 2 == 1)
			cout << p << " ";
		generare(n / 2 , p * 2);
	}
}
int main(){
	int n;
	cin >> n;
	generare(n,1);
	return 0;
}