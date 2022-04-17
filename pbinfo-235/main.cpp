#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mat[100][100], temp1 = 1, temp2 = 1, temp3;
    cin >> n;
    mat[1][1] = mat[1][2] = 1;
    for (int j = 3; j <= n; j++) {
        mat[1][j] = temp3 = temp1 + temp2;
        temp1 = temp2;
        temp2 = temp3;
    } for (int i = 2; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i % 2 == 1) mat[i][j] = temp3 = temp1 + temp2;
            else mat[i][n - j + 1] = temp3 = temp1 + temp2;
            temp1 = temp2;
            temp2 = temp3;
        } for (int i = 1; i <= n; i++) {
        	for (int j = 1; j <= n; j++)
            	cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}