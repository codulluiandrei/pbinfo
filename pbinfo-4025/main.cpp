#include <iostream>
using namespace std;
int K, n, x;
int caut(int l, int r) {
    int m = (l + r) / 2;
    int nr = m / 2 + m / 3 + m / 337 - m / 6 - m / 674 - m / 1011 + m / 2022;
    if (m - nr == n) return m;
    if (m - nr < n) return caut(m + 1, r);
    return caut(l, m);
}
int main() {
    cin >> K;
    for (int i = 1; i <= K; i++) {
        cin >> n;
        x = caut(1, 100000000);
        while((x % 2 == 0) || (x % 3 == 0) || (x % 337 == 0))
            x--;
        cout << x << " ";
    } return 0;
}