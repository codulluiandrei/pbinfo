#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin >> n;
    int nr = 2, temp;
    while (n > 1) {
        temp = 0;
        while (n % nr == 0) {
            temp++;
            n = n / nr;
        } if (temp) cout << nr << " " << temp << endl;
        nr++;
        if (n > 1 && nr * nr > n) nr = n;
    } return 0;
}