#include <iostream>
using namespace std;
int main() {
    int n, maxim;
    bool adv = false;
    cin >> n;
    maxim = n;
    while (n) {
        if (n > maxim)
            maxim = n;
		adv = true;
        cin >> n;
    }
    if (adv == true) cout << maxim;
    else cout << "NU EXISTA";
    return 0;
}