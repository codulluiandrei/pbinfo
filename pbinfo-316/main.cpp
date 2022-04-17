#include <iostream>
using namespace std;
int main() {
	int mat[101][101], n, m, minim = 10001;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        	if (mat[i][j] < minim) minim = mat[i][j];
        }
    } for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (mat[i][j] == minim) {
                for (int t = 0; t < n; t++) {
                    mat[t][j] = minim;
                }
            }
        }
    } for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        } cout << endl;
    } return 0;
}