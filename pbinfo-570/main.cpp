#include <iostream>
using namespace std;

int n, b[1005], p[1005], k;

int main() {
    cin >> n;
    int m = n, d = 2;
    while(m>1)
    {
		int pp = 0;
		while(m % d == 0)
			pp ++ , m /= d;
		if(pp)
		{
			k++;
			b[k] = d, p[k] = pp;
		}
		d ++;
		if(m > 1 && d*d > m )
			d = m;
	}
	int x = 1;
	cout << x << " ";
	for(int i =1 ; i <= k ; i++)
		for(int j = 1; j <= p[i] ; j ++)
		{
			x *= b[i];
			cout << x << " ";
		}
    return 0;
}
