#include <iostream>
using namespace std;

int n, a[1005];

int main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; ++i)
		cin >> a[i];
	
	int cnt = 0;
	for(int i = 1 ; i < n ; ++i)
		for(int j = i + 1 ; j <= n ; j ++)
			if(a[i] > a[j])
			{
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
	
	for(int i = 1 ; i <= n - 2  ; ++i)
		for(int j = i + 1 ; j <= n - 1; j ++)
		{
			//caut cel mai din dreapta k astfel incat a[i] + a[j] > a[k]
			int st = j + 1, dr = n , k = n;
			while(st <= dr)
			{
				k = (st + dr) / 2;
				if(a[i] + a[j] > a[k])
					st = k + 1;
				else
					dr = k - 1;
			}
				cnt += dr - j;
		}
	cout << cnt << endl;
	return 0;
}
