#include <iostream>
using namespace std;
int main() {
    int n, v[505];
    cin >> n;  
    for (int i = 0; i < n; i++) cin >> v[i];
    bool adv = true;
    for (int i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1]) adv = false;
    if (adv == true) cout << "DA";
    else cout << "NU";
    return 0;
}