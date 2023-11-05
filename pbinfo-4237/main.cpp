#include <iostream>
using namespace std;
int d[100003], n, A;
int verificare(int L) {
    long long int S = 0;
    for (int i = 1; i <= n; i++)
        S = S + d[i] / L;
    return (S >= A);
}
int main() {
    cin >> n >> A;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    int st, dr, H, mid;
    st = 1; dr = 30000;
    H = 0;
    while (st <= dr) {
        mid = (st + dr) / 2;
        if (verificare(mid))
            H = mid, st = mid + 1;
        else dr = mid - 1;
    } cout << H;
    return 0;
}