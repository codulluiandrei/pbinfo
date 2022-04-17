#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, temp; cin >> n;
    for (int i = 1; i <= n ; i++) {
       for (int j = 1; j <= n; j++) {
           temp = i * j;
           cout << temp % 10 << " ";
       } cout << endl;
    } return 0;
}