/* Bogdan Iordache
 * O(nr cifre)
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef LOCAL
    ifstream cin("cifrevecine.in");
    ofstream cout("cifrevecine.out");
#endif
    long long n;
    int k;
    cin >> n >> k;

    assert(1 <= n && n <= 100000000000000000LL);
    vector<long long> pw10;
    pw10.push_back(1);
    while (pw10.back() * 10 <= n) pw10.push_back(pw10.back() * 10);
    assert(0 <= k && k < (int)pw10.size());

    long long best = 0;
    for (int i = 0, j = (int)pw10.size() - k; j >= 0; ++i, --j) {
        long long val;
        if (i)
            val = n / pw10[j + k];
        else
            val = 0;
        val = val * pw10[j] + (n % pw10[j]);

        best = max(best, val);
    }

    cout << best << '\n';

    return 0;
}
