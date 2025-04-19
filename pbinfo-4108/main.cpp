#include <iostream>
using namespace std;
int main() {
    int n, v[202];
    bool adv = true;
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> v[i];
    for (int i = 1; i <= n / 2; i++) {
        if (v[i] % 2 == v[n - i + 1] % 2)
            adv = false;
    }
    if (adv == true)
        cout << "DA";
    else
        cout << "NU";
}