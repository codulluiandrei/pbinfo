#include <fstream>
using namespace std;
ifstream in("matrice4.in");
ofstream out("matrice4.out");
int n, mat[105][105];
int suma(int mat[][105], int n, int p) {
    int S = 0;
    for (int j = 1; j <= n; j++)
        S = S + mat[p][j];
    return S;
}
int main() {
    in >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            in >> mat[i][j];
    for (int i = 1; i <= n; i++)
        if (suma(mat, n, i) % 2 == 0)
            out << i << " ";
    return 0;
}