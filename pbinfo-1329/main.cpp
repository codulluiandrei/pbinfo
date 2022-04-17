#include <iostream>
using namespace std;
int main() {
    int n, v[1001];
    cin >> n;
    bool adv = true;
    cin >> v[1];
    cin >> v[2];
    if (v[2] == v[1]) adv = 0;
    for (int i = 3; i <= n; i++) {
        cin >> v[i];
        if (v[i] == v[i - 1]) adv = 0;
        if (!((v[i] < v[i - 1]) != (v[i - 1] < v[i - 2]))) adv = false;
    } if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}