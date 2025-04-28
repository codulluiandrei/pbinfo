#include <iostream>
using namespace std;
int main(){
    int x, max1 = -1 , max2 = -1;
    cin >> x;
    while(x != 0)
    {
		if(x > max1)
			max2 = max1, max1 = x;
		else
			if(x > max2 && x < max1)
				max2 = x;
		cin >> x;
	}
	if(max2 != -1)
		cout << 1LL * max1 * max2 << endl;
	else
		cout << "NU EXISTA\n";
    return 0;
}