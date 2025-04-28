#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
using namespace std;
static const int kModulo = 20173333;
int main() {
    ifstream cin("sir9.in");
    ofstream cout("sir9.out");
    int T, N, X; assert(cin >> T >> N >> X);
    assert(1 <= T && T <= 2);
    assert(1 <= N && N <= 100 * 1000);
    assert(1 <= X && X <= N);
    if (T == 1) {
        vector<int> prime(N + 1, 0);
        for (int i = 2; i <= N; ++i)
            if (prime[i] == 0)
                for (int j = i; j <= N; j += i)
                    prime[j] = i;
        vector<int> exponent(N + 1, 0);
        for (int i = N - X + 1; i <= N - 1; ++i)
            for (int j = i; j > 1; j /= prime[j])
                ++exponent[prime[j]];
        for (int i = 1; i < X; ++i)
            for (int j = i; j > 1; j /= prime[j])
                --exponent[prime[j]];
        int answer = 1;
        for (int i = 1; i <= N; ++i)
            for (int j = 0; j < exponent[i]; ++j)
                answer = (1LL * answer * i) % kModulo;
        cout << answer << "\n";
        return 0;
    }
    vector<int> fibK(N + 2, 0);
    fibK[1] = 1;
    fibK[2] = 1;
    for (int i = 3; i <= N + 1; ++i) {
        fibK[i] = (2 * fibK[i - 1] - fibK[max(i - X - 1, 0)]) % kModulo;
        if (fibK[i] < 0)
            fibK[i] += kModulo;
    }
    cout << fibK[N + 1] << "\n";
}