#include <iostream>
using namespace std;
int n, m, mat[101][101], rez = 0;
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    for (int j = 1; j <= m; j++) {
        bool adv = true;
        for (int i = 1; i <= n; i++)
            for (int l = i + 1; l <= n; l++)
                if (mat[i][j] == mat[l][j])
                    adv = false;
        if (adv == true) rez++;
    } cout << rez;
    return 0;
}