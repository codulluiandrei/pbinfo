#include <iostream>
using namespace std;
int n, x[100005];
int main(){
	cin  >> n;	
	for(int i = 1 ; i <= n ; ++ i)
		cin >> x[i];
	long long int cnt = 0;
	for(int i =1 ; i <= n ; ++ i)
	{
		int j = i + 1;
		while(j <= n && x[j] == x[i])
			j ++;
		int p = j - i;
		cnt += 1LL * p*(p+1)/2;
		i = j - 1;
	}
	cout << cnt << endl;
	return 0;
}