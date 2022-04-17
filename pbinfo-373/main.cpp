#include <iostream>
using namespace std;
int main() {
    int n, temp = 1;
    bool adv;
    cin >> n;
    cout << "2 ";
    for (int i = 3; temp < n; i = i + 2) {
        adv = true;
        for (int d = 3; d * d <= i; d = d + 2)
            if (i % d == 0) adv = false;
        if (adv) cout << i << " ", temp++;
    } return 0;
}