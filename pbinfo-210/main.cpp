#include <fstream>
using namespace std;
ifstream in("chenar.in");
ofstream out("chenar.out");
int main() {
    int mat[101][101], n;
    in >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            in >> mat[i][j];
    for (int j = 1; j <= n; ++j)
        out << mat[1][j] << " ";
    for (int i = 2; i <= n; ++i)
        out << mat[i][n] << " ";
    for (int j = n - 1; j >= 1; --j)
        out << mat[n][j] << " ";
    for (int i = n - 1; i >= 2; --i)
        out << mat[i][1] << " ";
    return 0;
}
