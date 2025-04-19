#include <iostream>
using namespace std;
int main()
{
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n ; i ++)
	{
		int a , k = 0;
		cin >> a;
		do
		{
			k ++;
			a /= 10;				
		}
		while(a);
		if(k % 2 == 1)
			cnt ++;
	}
	cout << cnt << endl;
	return 0;
}