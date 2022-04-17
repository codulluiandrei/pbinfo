#include <fstream>
using namespace std;
ifstream in("matrice7.in");
ofstream out("matrice7.out");
int main() {
	int mat[101][101], n, m;
	in >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			in >> mat[i][j];
	int maxim = -10000001;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (mat[i][j] > maxim)
				maxim  = mat[i][j];
	int minim = 10000001;
	for (int j = 1; j <= m; ++j) {
		for (int i = 1; i <= n; ++i)
			if (mat[i][j] < minim)
				minim = mat[i][j];
		for (int i = 1; i <= n; ++i)
			if (mat[i][j] == maxim)
				mat[i][j] = minim;
		minim = 10000001;
	} for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			out << mat[i][j] << " ";
		out << "\n";
	}
}
