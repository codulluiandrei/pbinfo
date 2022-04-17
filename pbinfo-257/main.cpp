#include <bits/stdc++.h>
using namespace std;
int fibosum(int n) {
    int t1 = 1, t2 = 1, t3 ;
    while (t1 + t2 <= n) {
        t3 = t1 + t2;
        t1 = t2;
        t2 = t3;
    } return t2;
}
int main() {
    int n; cin >> n;
    while (n != 0) {
        cout << fibosum(n) << " ";
        n = n - fibosum(n);
    } return 0;
}