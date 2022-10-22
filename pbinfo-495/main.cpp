#include <iostream>
using namespace std;
int main() {
    int n, v[222], t[222], contor = 0;
    cin >> n;  
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = n - 1; i >= 0; --i) {
        bool adv = true;
        if (v[i] < 2) adv = false;
        if (v[i] % 2 == 0 && v[i] > 2) adv = false;
        for (int d = 3; d * d <= v[i]; d = d + 2)
            if (v[i] % d == 0)
                adv = false;
        if (adv)
            t[contor++] = v[i];
    } for (int  i = 0; i < contor; ++i)
        cout << t[i] << " ";
    return 0;
}