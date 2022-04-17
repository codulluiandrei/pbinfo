#include <bits/stdc++.h>
using namespace std;
ifstream in("spirala.in");
ofstream out("spirala.out");
#define cin in
#define cout out
int n, v, mat[101][101];
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        cin >> mat[i][j];
    if (n % 2 == 0) v = n / 2;
    else v = n / 2 + 1;
    for (int i = 1; i <= v; ++i) {
        for(int j = i ; j <= n - i + 1 ; ++j) cout << mat[i][j] << " ";
        for(int j = i + 1 ; j <= n - i + 1 ; ++j) cout << mat[j][n - i + 1] << " ";
        for(int j = n - i ; j >= i ; j--) cout << mat[n - i + 1][j]<< " ";
        for(int j = n - i ; j >= i + 1 ; j--) cout << mat[j][i] << " ";
    } return 0;
}
