#include <iostream>
using namespace std;
int main() {
	int mat[105][105], n, m, k, temp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> mat[i][j];
    cin >> k;
    for (int t = 1; t <= k; t++) {
        cin >> temp;
        bool rez = true;
        for (int i = 1; i <= n && rez == true; i++) {
            bool adv = false;
            for (int j = 1; j <= m && adv == false; j++)
                if (mat[i][j] == temp) adv = true;
            if (adv == false) rez = false;
        } if (rez == true) cout << "DA" << endl;
        else cout << "NU" << endl;
    } return 0;
}