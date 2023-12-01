#include <iostream>

using namespace std;

int main()
{
    int a, Min = 100;
    cin >> a;
    while(a)
    {
		if(a > 9 && a < 100)
			if(a < Min)
				Min = a;
		cin >> a;
    }
    if(Min < 100)
		cout << Min << endl;
	else
		cout << "NU EXISTA" << endl;
    return 0;
}
