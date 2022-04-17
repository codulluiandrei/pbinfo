#include <iostream>
using namespace std;
int main() {
	int mat[101][101], copie[101][101], n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            copie[i][j] = mat[j][i];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j)
            cout << copie[i][j] << " ";
        cout << endl;
    } return 0;
}
