#include <iostream>
using namespace std;

int n , v[1005];

int Cnt(int st, int dr)
{
	if(st == dr)
		if(v[st] % 2 == 1)
			return 1;
		else
			return 0;
	else
	{
		int mij = (st + dr) / 2;
		return Cnt(st ,mij) + Cnt( mij + 1 , dr);
	}
}

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i];
	cout << Cnt(0 , n - 1);
	return 0;
}
