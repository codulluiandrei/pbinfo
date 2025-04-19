#include <iostream>
using namespace std;
int main(){
	int n, x[1005], k;
	cin  >> n >> k;	
	for(int i = 1 ; i <= n ; ++ i)
		cin >> x[i];
	int p = 0, q = 0;
	for(int i = 1 ; i < n - k && !p ; ++i)
		for(int j = i + 1 ; j <= n - k + 1 && !p; j ++)
		{
			bool ok = true;
			for(int v = 0; v < k && ok ; v ++)
				if(x[i + v] != x[j + v])
					ok = false;
			if(ok)
				p = i, q = j;
		}
	if(p)
		cout << p << " " << q;
	else
		cout << "NU";
	return 0;
}