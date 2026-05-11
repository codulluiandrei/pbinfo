/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NM_MAX = 500;
int n, m;
bool mat[NM_MAX + 2][NM_MAX + 2];
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            mat[i][j] = !mat[i][j];
        }
    }
    int cnt[] = {0, 0};
    for (int j = 1; j <= m; j++) {
        cnt[!mat[1][j]]++;
    }
    for (int i = 1; i <= n; i++) {
        cnt[!(mat[i][1] ^ mat[1][1])]++;
        for (int j = 1; j <= m; j++) {
            if (mat[i][j] != (mat[1][j] ^ mat[i][1] ^ mat[1][1])) {
                cout << "NU\n";
                return 0;
            }
        }
    }
    assert(cnt[0] != cnt[1]);
    cout << "DA\n";
    if (cnt[0] < cnt[1]) {
        for (int i = 1; i <= n; i++) {
            if (mat[i][1] ^ mat[1][1]) {
                cout << i << " ";
            }
        }
        cout << "\n";
        for (int j = 1; j <= m; j++) {
            if (mat[1][j]) {
                cout << j << " ";
            }
        }
        cout << "\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (!(mat[i][1] ^ mat[1][1])) {
                cout << i << " ";
            }
        }
        cout << "\n";
        for (int j = 1; j <= m; j++) {
            if (!mat[1][j]) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}