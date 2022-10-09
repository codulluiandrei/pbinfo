#include <iostream>
using namespace std;
int mat[101][101], n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (mat[i][j] > mat[i][k])
                    swap(mat[i][j], mat[i][k]);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (mat[i][j] > mat[i][k])
                    swap(mat[i][j], mat[i][k]);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(mat[i][j], mat[j][i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    } return 0;
}