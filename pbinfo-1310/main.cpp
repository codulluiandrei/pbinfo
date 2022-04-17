#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, m;
    cin >> n >> m;
    int temp = 0;
    if (n == 0)
    temp = 1;
    while (n) {
        while (n % 10 == 0) n = n / 10;
        if (m % (n % 10) == 0) temp++;
        n = n / 10;
    } cout << temp;
    return 0;
}