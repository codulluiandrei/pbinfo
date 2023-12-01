#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, t, v, durata = 0, distanta = 0;
	cin >> n;
	for(int i = 1 ; i <= n ;++i)
	{
		cin >> t >> v;
		durata += t;
		distanta += v*t;
	}
	cout << distanta << " " << 1.0 * distanta/durata;
	return 0;
}
