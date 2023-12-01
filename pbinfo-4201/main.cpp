#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T, N, K;
int A[1005], B[1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> N >> K;
        memset(B, 0, sizeof(B));
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
            B[i % K] = max(B[i % K], A[i]);
        }

        ll ans = 0;
        for (int i = 0; i < K; i++) {
            ans += B[i];
        }

        cout << ans << "\n";
    }
}