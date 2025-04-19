#include <iostream>
using namespace std;
int n , A[105][105],k;
int main()
{
    cin >> n >> k;
	for(int i = 1;  i <= n ; i ++)
		for(int j = i + 1 ; j <= n ; j ++)
			if(i % k != j % k)
				A[i][j] = A[j][i] = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
			cout << A[i][j] << ' ';
		cout << '\n';
	}
    return 0;
}