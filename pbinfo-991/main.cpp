#include <fstream>
using namespace std;
ifstream in("matrice5.in");
ofstream out("matrice5.out");
int n, mat[105][105];
int calc(int n, int mat[][105], int k) {
    int S = 0;
    for (int i = 1; i < k; i++)
        S = S + mat[i][k - i];
    return S;
}
int main() {
    in >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            in >> mat[i][j];
    int S = 0;
    for (int k = 2 ; k <= n ; k++)
        S = S + calc(n, mat, k);
    out << S;
    return 0;
}