#include <iostream>
using namespace std;

int n, x[1005], s[1005];

int main(){
	cin >> n;
	for(int i = 0 ; i < n; ++i)
		cin >> x[i];
	for(int i = 0 ; i < n; ++i)
	{
		s[i] = 0;
		for(int d = 1 ; d * d <= x[i]; d ++)
			if (x[i] % d == 0)
			{
				s[i] += d;
				if(d * d < x[i])
					s[i] += x[i] / d;
			}
	}
	for(int i = 0 ; i < n - 1 ; i ++)
		for(int j = i + 1 ; j < n ; j ++)
			if(s[i] > s[j])
			{
				int aux = s[i];
				s[i] = s[j];
				s[j] = aux;
				aux = x[i];
				x[i] = x[j];
				x[j] = aux;
			}
			else
				if(s[i] == s[j])
					if(x[i]> x[j])
					{
						int aux = x[i];
						x[i] = x[j];
						x[j] = aux;
					}
					
	for(int i = 0 ; i < n ; i++)
		cout << x[i] << " ";
	return 0;
}
