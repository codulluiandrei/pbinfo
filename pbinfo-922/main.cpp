#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
struct Punct{
	int x,y;
};
void Citire(Punct & P)
{
	cin >> P.x >> P.y;
}
int pDistanta(Punct P)
{
	return P.x * P.x + P.y * P.y;
}
int main()
{
	int n , cnt = 0 , pMax = -1; // vom calcula patratul distantelor, nu distantele
	Punct A;
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		Citire(A);
		int pd = pDistanta(A);
		if(pd > pMax)
			pMax = pd, cnt = 1;
		else
			if(pd == pMax)
				cnt ++;
	}
	cout << setprecision(3) << fixed << sqrt(pMax) << " " << cnt << endl;
	return 0;
}