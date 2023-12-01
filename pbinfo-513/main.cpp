#include <iostream>
using namespace std;

int main(){
	int n , k, x[1005];
	cin  >> n >> k;	
	for(int i = 1 ; i <= n ; ++ i)
		cin >> x[i];
	for(int p = 1 ; p <= k ; ++p)
	{
		for(int i = p ; i < n ; i += k)
			for(int j = i + k; j <= n ; j += k)
				if(x[i] > x[j])
				{
					int aux = x[i];
					x[i] = x[j];
					x[j] = aux;
				}
	}
	for(int i = 1 ; i <= n ; ++ i)
		cout << x[i] << " ";
	return 0;
}
