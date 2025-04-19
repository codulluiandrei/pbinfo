#include <iostream>
#include <algorithm>
using namespace std;
int n , S , v[1001];
int main()
{
	cin >> n >> S;
	for(int i = 1; i <= n ; i ++)
		cin >> v[i];
	sort(v + 1 , v + n + 1);
	int k = 0;
	for(int i = 1 ; i <= n  && v[i] <= S ; i ++)
		k ++, S -= v[i];
	cout << k << " " ;
	if(k == n)
		cout << 0 << endl;
	else
		cout << v[k + 1] - S << endl;
	return 0;
}