#include <iostream>
using namespace std;
int n , v[1005];
int prim(int n)
{
	if(n < 2)
		return 0;
	if(n > 2 && n % 2 == 0)
		return 0;
	for(int d = 3 ; d * d <= n ; d += 2)
		if(n % d == 0)
			return 0;
	return 1;
}
int Max(int st, int dr)
{
	if(st == dr)
		if(prim(v[st]))
			return v[st];
		else
			return -1;
	else
	{
		int mij = (st + dr) / 2;
		int x = Max(st ,mij); 
		int y = Max( mij + 1 , dr);
		if(x > y)
			return x;
		else
			return y;
	}
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i];
	cout << Max(0 , n - 1);
	return 0;
}