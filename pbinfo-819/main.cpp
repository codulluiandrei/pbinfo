#include <iostream>
using namespace std;
int v[10000], op[10000], nv = 0;
/*
 * 1 -> se adauga 4
 * 2 -> se adauga 0
 * 3 -> se imparte la 2, daca este par
 * 
 * */
int main()
{
	int n,  gata = 0;
	cin >> n;
	v[++nv] = n;
	while(! gata)
	{
		if(n == 4)
			gata = 1;
		else
		{
			if(n % 10 == 4)
			{
				op[++nv] = 1;
				n /= 10;
			}
			else
				if(n % 10 == 0)
				{
					op[++nv] = 2;
					n /= 10;
				}
				else
				{
					op[++nv] = 3;
					n *= 2;
				}
			v[nv] = n;
		}
	}
	for(int i = nv ; i >= 2 ; i --)
		cout << op[i] << " ";
	return 0;
}