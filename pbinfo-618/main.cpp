#include <iostream>
using namespace std;

int n, h[1005], a[1005];

int main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> h[i], a[i] = i;
	for(int i = 1 ; i < n ; i ++)
		for(int j = i + 1 ; j <= n ; ++j)
			if(h[a[i]] > h[a[j]])
			{
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
	for(int  i = 1 ; i <= n ; i ++)
		cout << a[i] << " ";
	return 0;
}
