#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, a, temp1 = 1, temp2 = 1;    cin >> n >> a;
    const int nr = 10;
    while (a != 0) {
        temp2 = temp2 * nr;
        a--;
    } temp1 = n * temp2;
    cout << temp1;
    return 0;
}