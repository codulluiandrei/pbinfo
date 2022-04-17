#include <iostream>
using namespace std;
int main() {
    int n, m, mat[101][101], nr = 0;
    cin >> n >> m;
    for (int lin = 1; lin <= n; lin++)
        for (int col = 1; col <= m; col++)
            cin >> mat[lin][col];
    for (int col = 1; col <= m; col++) {
        bool adv = true;
        for (int lin = 1; lin <= n; lin++)
            if (mat[lin][col] != mat[1][col])
                adv = false;
        if (adv == true) {
            cout << mat[1][col] << " ";
            nr++;
        }
    } if (nr == 0) cout << "nu exista";
    return 0;
}