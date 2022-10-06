#include <iostream>
using namespace std;
int mat[101][101], n, m, S = 0;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            int minim = 10000001;
            if (1 <= i - 1 && i - 1 <= n && 1 <= j && j <= m)
                if (mat[i - 1][j] < minim)
                    minim = mat[i - 1][j];
            if (1 <= i && i <= n && 1 <= j - 1 && j - 1 <= m)
                if (mat[i][j - 1] < minim)
                    minim = mat[i][j - 1];
            if (1 <= i + 1 && i + 1 <= n && 1 <= j && j <= m)
                if (mat[i + 1][j] < minim)
                    minim = mat[i + 1][j];
            if (1 <= i && i <= n && 1 <= j + 1 && j + 1 <= m)
                if (mat[i][j + 1] < minim)
                    minim = mat[i][j + 1];
            if (mat[i][j] < minim)
                S = S + minim - mat[i][j];
        } cout << S;
    return 0; 
}