#include <fstream>
using namespace std;
ifstream in("pavaj.in");
ofstream out("pavaj.out");
int n, m, k, mat[1001][1001];
int main() {
    in >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            in >> mat[i][j], mat[i][j] = mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1] + mat[i][j];
    int l1, c1, l2, c2;
    for (int i = 1; i <= k; i++) {
        in >> l1 >> c1 >> l2 >> c2;
        if (l1 > l2) swap(l1, l2);
        if (c1 > c2) swap(c1, c2);
        int s = mat[l2][c2] - mat[l1 - 1][c2] - mat[l2][c1 - 1] + mat[l1 - 1][c1 - 1];
        if (s == 0) out << "0\n";
        else if (s == (l2 - l1 + 1) * (c2 - c1 + 1)) out << "1\n";
		else out << "2\n";
    } return 0;
}