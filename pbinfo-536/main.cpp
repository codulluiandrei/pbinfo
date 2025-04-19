#include <iostream>
using namespace std;
int n, d[1005],  M;
int main(){
	cin  >> n >> M;
	int MAX = 0;
	for(int i =1 ; i <= n ; ++i)
	{
		cin >> d[i];
		if(d[i] > MAX)
			MAX = d[i];
	}
	long long int st = 1, dr = 1LL * MAX * M, T;
	while(st < dr)
	{
		T = (st + dr) / 2;
		long long int c = 0;
		for(int i =1; i <= n ; ++i)
			c += T / d[i];
		if(c < M)
			st = T + 1;
		else
			dr = T;
	}
	cout << dr;
	return 0;
}