/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = (int) 1e5;

int n;
int p[N_MAX + 2];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int curr = 1;
    for (int i = 1; i <= n; i++) {
        curr += (i > 1 && p[i] != p[i - 1] + 1);
        cout << curr << " ";
    }
    cout << "\n";

    return 0;
}
