#include <bits/stdc++.h>
using namespace std;
ifstream in("wisp.in");
ofstream out("wisp.out");
#define cin in
#define cout out
long long int n, S = 0, temp = 1, var, st;
int main() {
    cin >> n >> var;
    S = n * (var - 1) + 1;
    st = n + n - 2;
    if (n % 2 == 0)  {
        do {
            S = S + (temp = temp + st);
            S = S + (temp = temp + st);
        } while((st = st - 4) != 2);
        S = S + temp + 2;
    } else {
        do {
            S = S + (temp = temp + st);
            S = S + (temp = temp + st);
        } while (st = st - 4);
    }
    cout << S;
    return 0;
}