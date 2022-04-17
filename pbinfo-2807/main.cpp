#include <iostream>
using namespace std;
int main() {
	int mat[101][101], n, m, minim_unu, minim_doi, poz_unu = 0, poz_doi = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) 
			cin >> mat[i][j];
	minim_unu = mat[0][0];
	for (int i = 1; i < n; i++) {
		if (mat[i][0] < minim_unu) {
			minim_unu = mat[i][0];
			poz_unu = i;
		} 
	} minim_doi = mat[0][m - 1];
	for (int i = 1; i < n; i++) {
		if (mat[i][m - 1] < minim_doi) {
			minim_doi = mat[i][m - 1];
			poz_doi = i;
		}
	} int temp = mat[poz_unu][0];
	mat[poz_unu][0] = mat[poz_doi][m - 1];
	mat[poz_doi][m - 1] = temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << " ";
		} cout << endl;
	}
	return 0;
}