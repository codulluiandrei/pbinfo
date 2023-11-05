#include <iostream>
using namespace std;
int n, m, cm, nr;
bool a[1001];
int main() {
    cin >> n;
    m = n * (n + 1) / 2;
    if (m % 3 != 0) cout << "NU";
    else {
        m = m / 3, nr = 3;
        while (nr) {
            cm = m;
            for (int i = n; i >= 1 && cm; --i)
                if (!a[i] && (cm - i) >= 0) {
                    cout << i << " ";
                    cm = cm - i;
                    a[i] = true;
                }
            cout << "\n";
            nr--;
        }
    } return 0;
}