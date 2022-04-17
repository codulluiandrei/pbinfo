#include <bits/stdc++.h>
using namespace std;
int main() {
    int vec[630];
    vec[0] = 1;
    vec[1] = 1;
    for (int i = 2; i < 620; i++) {
        vec[i] = (vec[i - 1] + vec[i - 2]) % 10;
    } int n, temp = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vec[temp] << " ";
            temp++;
        } cout << endl;
    } return 0;
}