#include <iostream>
using namespace std;

int p, n, m , v[1005];

int main() {
    cin >> p >> m;
    n = p - m;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    
    for(int i = 1 ; i < n ; ++i)
		for(int j = i + 1 ; j <= n ; ++j)
			if(v[i] > v[j])
			{
				int aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
	
	int r = (v[n] - v[1]) / (p - 1);
	int x = v[1];
	for(int i = 2; i <= n && m > 0 ; )
	{
		x += r;
		if(x != v[i])
		{
			cout << x << " ";
			m --;
		}
		else
			i ++;
	}
	return 0;
}
