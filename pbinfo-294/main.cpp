#include <iostream>
using namespace std;
int n, v[101];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    bool adv = false;
    int temp = v[1], oglinda = 0;
    while (temp)
        oglinda = 10 * oglinda + temp % 10, temp = temp / 10;
    for (int i = 2; i <= n; i++) {
        if (oglinda == v[i])
            adv = true;
    } if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}