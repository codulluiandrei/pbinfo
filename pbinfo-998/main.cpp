#include <fstream>
using namespace std;
ifstream in("matrice6.in");
ofstream out("matrice6.out");
int mat[101][101], v[101], n, maxim, minim;
int main() {
    in >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            in >> mat[i][j];
    maxim = mat[1][1], minim = mat[1][1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (mat[i][j] > maxim)
                maxim = mat[i][j];
            if (mat[i][j] < minim)
                minim = mat[i][j];
        }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (mat[i][j] == maxim)
                v[i] = 1;
    for (int i = 1; i <= n; ++i)
        if (v[i] == 1)
            for (int j = 1; j <= n; ++j)
                mat[i][j] = mat[i][j] + minim;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            out << mat[i][j] << " ";
        out << "\n";
    } return 0;
}
