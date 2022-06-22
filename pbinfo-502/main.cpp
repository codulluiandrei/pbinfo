#include <iostream>
using namespace std;
int main() {
    int n, x[505];
    cin >> n;  
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    bool adv = true;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; ++j)
            if (x[i] == x[j])
                adv = false;
    if (adv) cout << "DA";
    else cout << "NU";
    return 0;
}