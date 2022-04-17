#include <iostream>
using namespace std;
int main() {
    int n, unu = 0, zero = 0;
    bool adv = true;
    cin >> n;
    while (n > 0) {
		if (n % 10 == 1) unu++;
        else if (n % 10 == 0) zero++;
        else adv = false;
        n = n / 10;
    } if (adv == true && zero >= 1 && unu >= 1) cout << "da";
    else cout << "nu";
    return 0;
}