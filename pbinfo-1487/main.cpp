#include <bits/stdc++.h>
using namespace std;
ifstream in("decodificare.in");
ofstream out("decodificare.out");
#define cin in
#define cout out
char mat[3003][3003];
int main() {
    int n;
    cin >> n;
    n = n / 2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    for (int i = 0; i < n; i++)
        cout << mat[i][n - i - 1];
    for (int i = 0; i < n; i++)
        cout << mat[i][i];
    return 0;
}