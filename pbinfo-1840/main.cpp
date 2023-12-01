///Moca Andrei - 100p

#include <iostream>
using namespace std;
int rez[100002], p[1002], n, x;
int main()
{
	rez[0] = 1;
	rez[1] = 1;
	cin >> n;
	for (int k = 1; k <= n; k++)
    {
        p[k] = 1;
        cin >> x;
        int d = 2;
        while (x != 1)
        {
            if (x % d == 0)
                p[k] *= d;
            while (x % d == 0)
                x /= d;
            if (d == 2) d = 3;
            else d += 2;
            if (d * d > x) d = x;
        }
    }
	for(int i = 1 ; i <= n ; ++i)
	{
		int t = 0;
		for(int j = 1 ; j <= rez[0] ; j++)
		{
			int cif = t + p[i] * rez[j];
			rez[j] = cif % 10;
			t = cif / 10;
		}
		while(t)
			rez[++rez[0]] = t % 10, t /= 10;
	}
	for(int i = rez[0] ; i > 0 ; i--)
		cout << rez[i];
	return 0;
}
