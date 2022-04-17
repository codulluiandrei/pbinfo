#include <iostream>
using namespace std;
int main() {
	int mat[101][101], n, m, S = 0, maxim = -1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)	
        for (int j = 0; j < m; j++)
        	cin >> mat[i][j];
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            S = S + mat[i][j];
            if (mat[i][j] > maxim) maxim = mat[i][j];
        } S = S - maxim;
        cout << S << " ";
        S = 0;
        maxim = -1;
    }
	return 0;
}