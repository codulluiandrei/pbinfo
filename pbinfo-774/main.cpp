#include <iostream>
using namespace std;
bool verif_prim(int n) {
    bool adv = true;
    if (n < 2) adv = false; 
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0) adv = false;
    if (adv == true) return true;
    return false;
}
int main() {
    int mat[101][101], n, m;
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int i = 1; i <= n; i++) {
        if (!verif_prim(mat[i][1])) { 
            for (int j = 1; j <= m; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    } return 0;
}