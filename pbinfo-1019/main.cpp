#include <iostream>
using namespace std;

int n , v[1005];

int Max(int st, int dr)
{
	if(st == dr)
		return v[st];
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
