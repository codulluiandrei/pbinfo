#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long long a, b, c, aux;
	long double delta;
	char chr;
	cin >> aux >> chr;
	if(chr == '+' || chr == '-')
		c = aux;
	else
	{
		cin.get(chr);
		if(chr == '^')
		{
			cin.get(chr); // 2
			cin.get(chr); // +/-
			a = aux;
		}
		else b = aux;
	}
	cin >> aux;
	if(chr == '-')
		aux *= -1;
	cin.get(chr);
	if(chr == '+' || chr == '-')
		c = aux;
	else
	{
		cin.get(chr);
		if(chr == '^')
		{
			cin.get(chr); // 2
			cin.get(chr); // +/-
			a = aux;
		}
		else b = aux;
	}
	cin >> aux;
	if(chr == '-')
		aux *= -1;
	if(!cin.get(chr))
		c = aux;
	else
	{
		if(cin.get(chr) && chr == '^')
		{
			cin.get(chr); // 2
			cin.get(chr); // +/-
			a = aux;
		}
		else b = aux;
	}
	delta = (long double)b * (long double)b - (long double)4 * a * c;
	if(-0.2 < delta && delta < 0.2) // pentru a fi siguri ca delta == 0
	{
		cout << "real\n" << (long double)-b/(long double)(2*a);
	}
	else if(delta > 0)
	{
		cout << "reale\n";
		cout << ((long double)-b-sqrt(delta))/(long double)(2*a) << '\n';
		cout << ((long double)-b+sqrt(delta))/(long double)(2*a);
	}
	else // delta < 0
	{
		cout << "imaginare\n";
		cout << (long double)-b/(long double)(2*a) << '\n';
		cout << sqrt(-delta)/(long double)(2*a) << 'i';
	}
	return 0;
}