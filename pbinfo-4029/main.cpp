#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int N;
int lgput(int N, int P) {
    int res = 1;
    while(P > 0) {
        if(P & 1) {
            res = (1LL * res * N) % MOD;
        }
        N = (1LL * N * N) % MOD;
        P >>= 1;
    }
    return res;
}
int main() {
    cin >> N;
    cout << (lgput(2, N) - 1 + MOD) % MOD << " " << (lgput(2, N + 1) - N - 2 + MOD) % MOD;
    return 0;
}