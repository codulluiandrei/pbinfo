#include <iostream>
using namespace std;
int main() {
    int n, m, v[100001];
    long long int sume[100001] = {0}, maxim = -100000001;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        sume[i] = sume[i - 1] + v[i];
    } int x, y;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        if (x > y) {
        	int temp = x;
            x = y;
            y = temp;
        } long long S = sume[y] - sume[x - 1];
        if (S > maxim) maxim = S;
    } cout << maxim;
    return 0;
}
