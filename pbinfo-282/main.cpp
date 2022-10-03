#include <bits/stdc++.h>
using namespace std;
ifstream in("pozmax.in");
ofstream out("pozmax.out");
#define cin in
#define cout out
int main() {
    int n, pozmin = 1, pozmax = 1;
    double maxim, temp;
    cin >> n >> maxim;
    for (int i = 2; i <= n; i++) {
        cin >> temp;
        if (temp > maxim) {
            pozmin = pozmax = i;
            maxim = temp;
        } else if (temp == maxim)
            pozmax = i;
    } cout << pozmin << " " << pozmax;
    return 0;
}