#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, v0[10], v1[100];
    cin >> n;
    v1[0] = 1;
    v1[1] = 1;
    for (int i = 2; i < 45; i++) v1[i] = v1[i - 1] + v1[i - 2];
    for (int i = 0; i < n; i++) cin >> v0[i];
    for (int i = 0; i < n; i++) {
        int temp = 0;
        for (int j = 0 ; j < 45 ; j++)
        if (v1[j] == v0[i]) temp++;
        if (temp == 0) cout << "NU" << endl;
        else cout << "DA" << endl;
    } return 0;    
}