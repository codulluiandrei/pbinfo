#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    bool adv;
    cout << "2 ";
    for (int i = 3; i <= n; i = i + 2) {
        adv = true;
        for (int d = 3; d * d <= i; d = d + 2)
            if (i % d == 0) 
            	adv = false;
        if (adv) cout << i << " ";
    } return 0;
}