#include <iostream>
using namespace std;

int v[1005], n, h;

int main(){
	cin  >> n >> h;
	for(int i = 1 ; i <= n ; ++i)
		cin >> v[i];
	int cnt = 0;
	for(int i = n - 1 ; i > 0 ; i --)
		if(v[i] < v[i+1])
		{
			int dif = v[i+1] - v[i];
			int nrv = dif / h;
			if(nrv * h < dif)
				nrv ++;
			cnt += nrv;
			v[i] += nrv * h;
		}
	cout << cnt;
	return 0;
}
