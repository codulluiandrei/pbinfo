#include <iostream>
using namespace std;
int main(){
	int n, A[501];
    cin >> n;
    for(int i = 1 ; i <= n ; i ++)
		cin >> A[i];
	int cnt = 0;
	for(int i = 1, j = n ; i < j ; i ++, j --)
	{
		int x = A[i] / 10 % 10, y = A[j] / 10 % 10;
		if(x == y)
			cnt ++	;
	}
	cout << cnt << endl;
    return 0;
}