#include <iostream>
using namespace std;
int main() {
	int n, p = 1, nr = 0;
	bool adv = false;
    cin >> n;
    while (n != 0) {
        if (n % 10 % 2 == 0)
            nr = nr + (n % 10 + 1) * p;
		else 
           	nr = nr + n % 10 * p;
        p = p * 10;
        n = n / 10;
        adv = true;
    } if (adv == true)
        cout << nr;
    else 
        cout << 1;
    return 0;
}
