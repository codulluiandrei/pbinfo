#include <iostream>
using namespace std;
bool f[1000000];
int mat[501][501], n, val1 = 0, val2 = 0, temp = 0, test = 0;
bool adv = true;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] > n * n || mat[i][j] < 1) adv = false;
            if (f[mat[i][j]] == 0) f[mat[i][j]] = 1;
            else adv = false;
        }
    for (int i = 1; i <= n; ++i) {
        val1 = val1 + mat[i][i];
    	val2 = val2 + mat[i][n - i + 1];
    } if (val1 != val2) {
    	adv = false;
    	test = 0;
    } else test = val1;
    for (int i = 1; i <= n; ++i) {
    	temp = 0;
        for (int j = 1; j <= n; ++j)
        	temp = temp + mat[i][j];
        if (temp != test) adv = false;
    }
    for (int i = 1; i <= n; ++i) {
    	temp = 0;
        for (int j = 1; j <= n; ++j)
        	temp = temp + mat[j][i];
        if (temp != test) adv = false;
    } if (adv == true) cout << "true";
    else cout << "false";
    return 0;
}
