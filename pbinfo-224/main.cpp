#include <fstream>
using namespace std;
ifstream in("rotire.in");
ofstream out("rotire.out");
int main(){
	int mat[101][101], n, m, mat_rot[101][101];
    in >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            in >> mat[i][j];
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= m; ++i)
            mat_rot[n - j + 1][i] = mat[i][j];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            out << mat_rot[i][j] << " ";
        out << endl;
    } return 0;
}
