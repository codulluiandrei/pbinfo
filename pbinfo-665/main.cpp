#include <iostream>
using namespace std;
int main() {
    int a, b, contor = 0, n;
    cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        n = i;
        bool adv = true;
        while (n && adv == true) {
            if (n % 10 != 0)
                if (i % (n % 10) != 0)
                	adv = 0;
			n = n /  10;
        } if (adv) contor++;
    } cout << contor;
    return 0;
}