#include <iostream>
using namespace std;
int n , v[1005];
int Sum(int st,int dr)
{
	if(st == dr)
		return v[st];
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
	cout << Sum(0 , n- 1);
	return 0;
}