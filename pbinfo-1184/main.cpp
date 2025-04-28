#include <fstream>
using namespace std;
ifstream fin ("epuras.in");
ofstream fout ("epuras.out");
const int N = 1005, oo = -1e9;
int n, d[N][N], a[N][N], MAX[N][N];
int main() {
    fin >> n;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            d[i][j] = MAX[i][j] = oo;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            fin >> a[i][j];
    d[1][1] = a[1][1];
    MAX[1][1] = d[1][1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (!(i == 1 && j == 1)) {
                d[i][j] = max(MAX[i-1][j], MAX[i][j-1]) + a[i][j];
                MAX[i][j] = max(d[i][j], max(MAX[i-1][j], MAX[i][j-1]));
            }
    fout << d[n][n];
}