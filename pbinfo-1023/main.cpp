#include <iostream>
using namespace std;

int n , v[1005];

int Cmmdc2(int a, int b)
{
	if(b == 0)
		return a;
	else
		return Cmmdc2(b , a % b);
}

int Cmmdc(int st, int dr)
{
	if(st == dr)
		return v[st];
	else
	{
		int mij = (st + dr) / 2;
		int x = Cmmdc(st ,mij); 
		int y = Cmmdc(mij + 1 , dr);
		return Cmmdc2(x , y);
	}
}

int main(){
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> v[i];
	cout << Cmmdc(0 , n - 1);
	return 0;
}
