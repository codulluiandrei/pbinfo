#include <bits/stdc++.h>
using namespace std;
ifstream in("prize.in");
ofstream out("prize.out");
#define cin in
#define cout out
int main() {
    unsigned long long n, S = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        unsigned long long temp;
        cin >> temp;
        S = S + temp;
    }
    cout << S - (n - 1);
    return 0;
}