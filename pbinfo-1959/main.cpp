///Solutie - Moca Andrei - 100p
#include <iostream>
using namespace std;
const int Inf = 0x3f3f3f3f;
int n, k, G, g[1002], nr[100002];
void Halloween();
int main()
{
	cin >> n >> G;
	for (int i = 1; i <= G; i++)
        nr[i] = Inf;
	for (int i = 1; i <= n; ++i)
		cin >> g[i];
	Halloween();
	if (nr[G] < Inf)
		cout << nr[G];
	else
		cout << "NU";
}
void Halloween()
{
	nr[0] = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = G - g[i]; j >= 0; --j)
			if (nr[j] != Inf && nr[j + g[i]] > nr[j] + 1)
				nr[j + g[i]] = nr[j] + 1;
}
