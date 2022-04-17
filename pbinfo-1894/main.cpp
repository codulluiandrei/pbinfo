#include <iostream>
using namespace std;
int main() {
    int mat[20][20], n, temp1 = 0, temp2 = 0, temp3 = 1;
    cin >> n;
    temp1 = n * 2 + 1;
    temp2 = n;
    for (int i = 1; i <= temp1 / 2; i++) {
        for (int j = 1; j <= i; j++) {
                mat[i][j] = n - j + 1;
                mat[i][temp1 - j + 1] = n - j + 1;
            }
        for (int j = i + 1; j <= temp1 - i + 1; j++)
            mat[i][j] = n - i + 1;
        temp2--;
    } for (int i = temp1 / 2 + 1; i <= temp1; i++) {
        for (int j = 1; j <= temp1 - i + 1; j++) {
                mat[i][j] = n - j + 1;
                mat[i][temp1 - j + 1] = n - j + 1;
            } for (int j = temp1 - i + 2; j <= temp1 - (temp1 - i) - 1; j++)
            mat[i][j] = i - n - 1;
        temp3--;
    } for (int i = 1; i <= temp1; i++) {
        for (int j = 1; j <= temp1; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    } return 0;
}