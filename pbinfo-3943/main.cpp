#include <iostream>
#include <cmath>
using namespace std;
int n , x[35 + 1] , uz[35 + 1], gata;
void Afisare()
{
	gata = true;
	for(int i = 1 ; i <= n ; i ++)
		cout << x[i] << " ";
	cout << "\n";
}
bool OK(int k)
{
	if(k == 1)
		return true;
	if(sqrt(x[k] + x[k-1]) != (int)sqrt(x[k] + x[k-1]))
		return false;
	if(k == n)
		if(sqrt(x[k] + x[1]) != (int)sqrt(x[k] + x[1]))
			return false;
	return true;
}
void Back(int k)
{
	for(int i = 1 ; i <= n && ! gata; i ++)
		if(uz[i] == 0)
		{
			uz[i] = 1;
			x[k] = i;
			if(OK(k))
			{
				if(k == n)
					Afisare();
				else
					Back(k +1);
			}
			uz[i] = 0;
		}
}
int main()
{
	cin >> n;
	x[1] = 1, uz[1] = 1;
	Back(2);
	if(! gata)
		cout << "nu exista";
	return 0;
}