#include <iostream>
#include <cassert>
using namespace std;

int n , m , v[1005], s[1005], R[1005];

int main() {
    assert(cin >> n >> m);
    for(int k = 1 ; k <= n ; ++k)
    {
		for (int i = 1; i <= m; ++i)
		{
			assert(cin >> v[i]);
			assert(v[i]<= 1000);
		}
		for (int i = 1; i <= m; ++i)
			s[i] = s[i-1] + v[i];
		int p = 0;
		for(int i = 1 ; i <= m ; ++i)
			if(s[i] == s[m] - s[i])
				p = i;
		R[k] = p;
	}
	for(int i = 1; i <= n ; ++i)
		cout << R[i]  << " " << m - R[i] << "
";
	return 0;
}
