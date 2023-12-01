#include <iostream>
using namespace std;

int n, t , k , v[100005];

int main() {
    cin >> n >> t >> k;
    for(int i = 1 ; i <= n ; i ++ )
		cin >> v[i];
	int cnt = 0;
	for(int i =1 ; i <= n ; i ++)
		if(v[i] <= t)
		{
			int j = i + 1;
			while(j <= n && v[j] <= t)
				j ++;
			if(j-i >= k)
				cnt += j-i - k + 1;
			i = j;
		}
	cout << cnt;
    return 0;
    
}
