#include <bits/stdc++.h>
using namespace std;
int n, m, mat[1025][1025];
int main()
{
    cin >> m;
    n = 1 ;
    for (int i = 1 ; i <= m  ; i ++)
        n = n * 2;
    if (m == 1) {
        mat[1][1] = mat[1][2] = mat[2][1] = 1;
    } else
        if (m == 2) {
            mat[1][1] = mat[1][2] = mat[2][1] = 1;
            mat[1][3] = mat[1][4] = mat[2][4] = 2;
            mat[3][1] = mat[4][1] = mat[4][2] = 3;
            mat[3][4] = mat[4][3] = mat[4][4] = 4;
            mat[2][2] = mat[2][3] = mat[3][2] = 5;
        }
        else {
            int temp = 0, i, j;
            if (m % 2 == 1) {
                for (i = 1; i + 3 <= n; i = i + 3)
                    for(j = 1; j <= n; j = j + 2) {
                        temp ++;
                        mat[i][j] = mat[i][j+1] = mat[i+1][j] = temp;
                        temp++;
                        mat[i+1][j+1] = mat[i+2][j] = mat[i+2][j+1] = temp;
                    }
                i = n -1;
                for(j = 1; j <= n - 2; j = j + 3) {
                    temp ++;
                    mat[i][j] = mat[i][j+1] = mat[i+1][j] = temp;
                    temp++;
                    mat[i+1][j+1] = mat[i+1][j+2] = mat[i][j+2] = temp;
                } i = n - 1; j = n - 1;
                temp ++;
                mat[i][j] = mat[i][j+1] = mat[i+1][j] = temp;
            } else {
                for (i = 1 ; i <= n - 4; i = i + 3)
                    for (j = 1 ; j <= n ; j = j + 2) {
                        temp ++;
                        mat[i][j] = mat[i][j+1] = mat[i+1][j] = temp;
                        temp++;
                        mat[i+1][j+1] = mat[i+2][j] = mat[i+2][j+1] = temp;
                    }
                i = n - 3;
                for (j = 1; j <= n - 4; j = j + 3) {
                    temp ++;
                    mat[i][j] = mat[i][j+1] = mat[i+1][j] = temp;
                    temp++;
                    mat[i+1][j+1] = mat[i+1][j+2] = mat[i][j+2] = temp;
                } i = n - 1;
                for (j = 1; j <= n - 4; j = j + 3) {
                    temp ++;
                    mat[i][j] = mat[i][j+1] = mat[i+1][j] = temp;
                    temp++;
                    mat[i+1][j+1] = mat[i+1][j+2] = mat[i][j+2] = temp;
                } i = n - 3, j = n - 3;
                temp ++;
                mat[i][j] = mat[i][j+1] = mat[i+1][j] = temp;
                temp ++;
                mat[i][j+2] = mat[i][j+3] = mat[i+1][j+3] = temp;
                temp ++;
                mat[i+2][j] = mat[i+3][j] = mat[i+3][j+1] = temp;
                temp ++;
                mat[i+2][j+3] = mat[i+3][j+2] = mat[i+3][j+3] = temp;
                temp ++;
                mat[i+1][j+1] = mat[i+1][j+2] = mat[i+2][j+1] = temp;
            }
        }
    for (int i =1; i <= n; i++) {
        for (int  j = 1; j <= n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    } return 0;
}