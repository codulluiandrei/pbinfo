#include <iostream>
using namespace std;
long long n, sol;
const int mod = 666013;
int main() {
    cin >> n;
    n %= 666013;
  	for (long long i = 0; i < n; ++i) {
        sol += (n - i) * (n - i) * (i + 1);
      	sol %= mod;
    }
    cout << sol;
}