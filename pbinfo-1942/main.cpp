#include <iostream>
using namespace std;
bool ok;
int n, rez[100002], R;
int main()
{
	cin >> n;
	n--;
	rez[0] = 1;
	rez[1] = 1;
	for(int i = 3; i <= n; ++i)
	{
		int t = 0;
		for(int j = 1; j <= rez[0] ; j++)
		{
			int cif = t + i * rez[j];
			rez[j] = cif % 10;
			t = cif / 10;
		}
		while(t)
			rez[++rez[0]] = t % 10, t /= 10;
	}
	for(int i = rez[0]; i; i--)
		cout << rez[i];
	return 0;
}
