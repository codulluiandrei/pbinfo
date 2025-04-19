#include <iostream>
using namespace std;
int n, a[105];
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
		for(int j = i + 1 ; j <= n ; j ++)
			for(int k = j + 1 ; k <= n ; k ++)
				if(a[i] + a[j] > a[k])
					cnt ++;
	cout << cnt << endl;
	return 0;
}