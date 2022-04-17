#include <iostream>
using namespace std;
int n, v[101];
int main() {
    cin >> n;;
    for (int i = 1; i <= n; i++) cin >> v[i];
    bool adv = true;
    for (int i = 1; i <= n; i++) {
        int nrcif = 1, temp = v[i];
        while (temp > 9)
            nrcif++, temp = temp / 10;
        if (nrcif % 2 != 0) adv = false;
    } if (adv == true) cout << "DA";
    else cout << "NU";
    return 0;
}