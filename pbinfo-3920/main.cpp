#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char A[3]="CP";
int c , p , x[21] , n;
void Afisare(int L)
{
    for(int i = 1 ; i <= L ; i ++)
        cout << A[x[i]];
    cout << '\n';
}
bool OK(int k)
{
	if(k == 1)
		if(x[k] != 0)
			return false;
	if(k == n)
		if(x[k] != 1)
			return false;
	if(c < 0 || p < 0)
		return false;
	if(k > 2)
		if(x[k] == 0 && x[k-1] == 1 && x[k-2] == 0)
			return false;
    return true;
}
void Back(int k)
{
	for(int i = 0 ; i <= 1 ; i ++)
	{
		x[k] = i;
		if(i == 0)
			c --;
		else
			p --;
		if(OK(k))
		{
			if(k == n)
				Afisare(n);
			else
				Back(k + 1);
		}
		if(i == 0)
			c ++;
		else
			p ++;
	}
}
int main()
{
    cin >> c >> p;
    n = c + p;
    Back(1);
    return 0;
}