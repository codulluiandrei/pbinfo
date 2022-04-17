#include <fstream>
using namespace std;
ifstream in("maria.in");
ofstream out("maria.out");
int mat[1001][1001], S[1001][1001];
int n, m, p, q, k, rez = 0;
int main() {
    in  >> n >> m >> p >> q >> k;
    for (int i = 1; i <= k; ++i) {
        int lin, col;
        in >> lin >> col;
        mat[lin][col] = 1;
    } for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + mat[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            int lin, col;
            lin = i + p - 1;
        	col = j + q - 1;
            if (lin <= n && col <= m)
                if (S[lin][col] - S[lin][j - 1] - S[i - 1][col] + S[i - 1][j - 1] == 0)
                    rez++;
            lin = i + q - 1;
        	col = j + p - 1;
            if (lin <= n && col <= m)
                if (S[lin][col] - S[lin][j - 1] - S[i - 1][col] + S[i - 1][j - 1] == 0)
                    rez++;
        } out << rez;
    return 0;
}
