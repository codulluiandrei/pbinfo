#include <iostream>
using namespace std;
int main() {
    int mat[101][101], n, m, x;
    bool adv = false;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> mat[i][j];
    cin >> x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
                if (mat[i][j] == x)
                    adv = true;
    if (adv == true) cout << "DA";
    else cout << "NU";
    return 0;
}