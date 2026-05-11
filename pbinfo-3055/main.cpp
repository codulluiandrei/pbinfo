#include <iostream>
#include <fstream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
int main() {
    ifstream cin("pericol.in");
    ofstream cout("pericol.out");
    int N; assert(cin >> N);
    assert(2 <= N && N <= 400000);
    vector<int> V(N);
    for (int i = 0; i < N; ++i) {
        assert(cin >> V[i]);
        assert(1 <= V[i] && V[i] <= 10000000);
    }
    int max_value = *max_element(V.begin(), V.end()) + 1;
    vector<int> count(max_value, 0);
    for (auto &x : V)
        count[x]++;
    vector<bool> elementary(max_value, true);
    vector<int64_t> primes(max_value, 0), formula(max_value, 0), answer(max_value, 0);
    primes[1] = 2;
    // for gcd in 1..max_val
    // for elementary in 1..max_val
    // answer[elementary * X * gcd] += multiples_of[elementary * gcd] * sign[elementary] * gcd
    // translated:
    // formula[elementary * gcd] += sign[elementary] * gcd
    // answer[X * V] += formula[V] * multiples_of[V]
    for (int i = 1; i < max_value; ++i) {
        if (primes[i] == 0) {
            for (int j = i; j < max_value; j += i)
                primes[j]++;
            if (1LL * i * i < max_value) {
                for (int j = i * i; j < max_value; j += i * i)
                    elementary[j] = false;
            }
        }
        if (elementary[i]) {
            int sign = 1;
            if (primes[i] % 2)
                sign = -1;
            for (int j = i, ratio = 1; j < max_value; j += i, ++ratio)
                formula[j] += sign * ratio;
        }
        int frequency = 0;
        for (int j = i; j < max_value; j += i)
            frequency += count[j];
        for (int j = i; j < max_value; j += i)
            answer[j] += formula[i] * int64_t(frequency);
    }
    for (auto &x : V) {
        cout << answer[x] - x << " ";
    }
    cout << "\n";
} 