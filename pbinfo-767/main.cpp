#include <iostream>
using namespace std;
int main() {
	int mat[101][101], n, m, S = 0;
    cin >> n >> m;
	for (int i = 0; i < n; i++)
    	for (int j = 0; j < m; j++)
        	cin >> mat[i][j];
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++)
        	if (mat[i][j] % 2 == 0) S = S + mat[i][j];
	} cout << S;
	return 0;
}