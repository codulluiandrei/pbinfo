#include <iostream>
using namespace std;
int main()
{
	int n, cnt = 0;
	cin >> n;
	for(int i = 1; i <= n ; i ++)
	{
		int a , ok = 0;
		cin >> a;
		do
		{
			if(a % 10 == 0)
				ok = 1;
			a /= 10;				
		}
		while(a);
		if(ok == 1)
			cnt ++;
	}
	cout << cnt << endl;
	return 0;
}