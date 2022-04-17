#include <iostream>
using namespace std;
int main() {
	int mat[101][101], n, prin = 0, sec = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mat[i][j];
    for (int i = 1; i <= n; ++i) {
        prin = prin + mat[i][i];
        sec = sec + mat[i][n - i + 1];
    } cout << abs(prin - sec);
    return 0;
}
