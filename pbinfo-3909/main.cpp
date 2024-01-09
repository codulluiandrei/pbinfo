#include <iostream>

using namespace std;

int a , b , n , x[10];

bool OK(int k)
{
	for(int i =1 ; i < k ; i ++)
		if(x[k] == x[i])
			return false;
	return true;
}

void Afisare()
{
	for(int i = 1 ; i <= n ; i ++)
		cout << x[i] << " ";
	cout << '\n';
} 

void Back(int k)
{
	for(int i = a ; i <= b ; i ++)
	{
		x[k] = i;
		if(OK(k))
		{
			if(k == n)
				Afisare();
			else
				Back(k + 1);
		}
	}
}

int main()
{
	cin >> a >> b;
	n = b - a + 1;
	Back(1);
}
