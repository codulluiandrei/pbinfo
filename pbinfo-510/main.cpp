#include <iostream>
using namespace std;
int main() {
    int n, v[1001];
    cin >> n;  
    for (int i = 0; i < n; i++) cin >> v[i];
    bool sortat = false;
    while (!sortat) {
        sortat = true;
        for (int i = 0; i < n - 1; i++)
            if (v[i] > v[i + 1]) {
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
                sortat = false;
            }
    } for (int i = 0; i < n; i++) {
        bool adv = true;
        if (v[i] < 2) adv = false;
        if (v[i] % 2 == 0 && v[i] > 2) adv = false;
        for (int d = 3; d * d <= v[i]; d = d + 2)
            if (v[i] % d == 0) adv = false;
        if (adv == true) cout << v[i] << " ";
    } return 0;
}