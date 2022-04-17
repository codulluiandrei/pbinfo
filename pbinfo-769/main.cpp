#include <iostream>
using namespace std;
int mat[101][101], n, m;
int main() {
   cin >> n >> m;
   for (int i = 1; i <= n; i++)
       for (int j = 1; j <= m; j++)
           cin >> mat[i][j];
    bool sortat;
    do {
        sortat = false;
        for (int j = 1; j < m; j++)
            if (mat[1][j] > mat[1][j + 1]) {
                sortat = true;
                for (int i = 1; i <= n; i++) {
                    int temp = mat[i][j]; 
                    mat[i][j] = mat[i][j + 1];
                    mat[i][j + 1] = temp;
                }
           }
   } while (sortat == true);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << " ";
        cout << endl;
   } return 0;
}