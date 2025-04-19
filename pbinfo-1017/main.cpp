#include <iostream>
using namespace std;
int n , v[1005];
int Sum(int st, int dr)
{
	if(st == dr)
		if(v[st] % 2 == 0)
			return v[st];
		else
			return 0;
	else
	{
		int mij = (st + dr) / 2;
		return Sum(st ,mij) + Sum( mij + 1 , dr);
	}
}
int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i];
	cout << Sum(0 , n - 1);
	return 0;
}