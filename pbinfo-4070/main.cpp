#include <iostream>

using namespace std;

int n, m, A[105][105], k;

int main()
{
    int i , j;
    cin >> n >> m >> k;
    while(m > 0)
    {
		cin >> i >> j;
        A[i][j] = A[j][i] = 1;
        m --;
    }

    for(int i = k; i <= n;  i += k)
		for(int j = 1 ; j <= n ; j ++)
			A[i][j] = A[j][i] = 0;
	int cnt = 0;
	for(int i  = 1 ; i < n ; i ++)
		for(int j = i + 1;  j <= n; j ++)
			if(A[i][j] == 1)
				cnt ++;
	cout << cnt << '\n';
    return 0;
}
