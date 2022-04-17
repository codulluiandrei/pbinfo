#include <fstream>
using namespace std;
ifstream in("interschimbarelinii.in");
ofstream out("interschimbarelinii.out");
int main() {
    int n, m, mat[101][101];
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            in >> mat[i][j];
    int imax = 1, jmax = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mat[i][j] > mat[imax][jmax])
                imax = i, jmax = j;
    int imin = 1, jmin = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mat[i][j] < mat[imin][jmin])
                imin = i, jmin = j;
    for (int j = 1; j <= m; j++){
        int temp = mat[imin][j];
        mat[imin][j] = mat[imax][j];
        mat[imax][j] = temp;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            out << mat[i][j] << " ";
        out << endl;
    } return 0;
}