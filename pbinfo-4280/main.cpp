#include <iostream>
using namespace std;
int main()
{
    int n , k , a, Max = -1;
    cin >> n >> k;
    for(int i = 1 ; i <= n ; i ++)
    {
		cin >> a;
		if(a % k == 0)
			if(a > Max)
				Max = a;
    }
    if(Max > -1)
		cout << Max << endl;
	else
		cout << "NU EXISTA" << endl;
    return 0;
}