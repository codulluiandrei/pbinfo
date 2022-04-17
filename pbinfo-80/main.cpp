#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, temp = 0;
    cin >> a >> b;
    while (b) {
        int i = a, j = b;
        while (i % j != 0){
            int nr = i % j;
            i = j;
            j = nr;
        } if (j == 1) temp++;
        a = b; cin >> b;
    } cout << temp << endl;
    return 0;
}