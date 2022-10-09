#include <bits/stdc++.h>
using namespace std;
ifstream in ("spirala1.in");
ofstream out("spirala1.out");
#define cin in
#define cout out
int n, mat[101][101];
int main() {
    cin >> n;   
    n = sqrt(n);
    int temp;
    for (int k = 1; k <= n / 2; k ++) {
        for (int i = k; i <= n - k + 1; i++) {
            cin >> temp;
            mat[i][k] = temp;
        } for (int j = k + 1; j <= n - k + 1; j++) {
            cin >> temp;
            mat[n - k  + 1][j] = temp;
        } for (int i = n - k; i >= k; i--) {
            cin >> temp;
            mat[i][n - k + 1] = temp;
        } for(int j = n - k; j > k; j--) {
            cin >> temp;
            mat[k][j] = temp;
        }
    } if (n % 2 == 1) {
        cin >> temp;
        mat[n / 2 + 1][n / 2 + 1] = temp;
    } for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    } return 0;
}