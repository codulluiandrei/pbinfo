/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 100000;

int n;
int a[N_MAX + 2];

int b[N_MAX + 2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int l = 1, r = n;
    for (int i = n; i >= 1; i--) {
        if ((n - i) % 2 == 0) {
            b[i] = l; l++;
        } else {
            b[i] = r; r--;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[b[i]] << " ";
    }
    cout << "\n";

    return 0;
}
