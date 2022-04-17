#include <fstream>
using namespace std;
ifstream in("prodmax.in");
ofstream out("prodmax.out");
int main() {
	int mat[105][105], n, m;
    in >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            in >> mat[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (mat[i][j] == 0)
            	mat[0][j]++;
            else if (mat[i][j] == 2)
                mat[n + 1][j]++;
    int maxim = 0;
    for (int j = 1; j <= m; ++j)
        if (mat[0][j] == 0 && mat[n + 1][j] > maxim)
        	maxim = mat[n + 1][j];
    for (int j = 1; j <= m; ++j)
        if (mat[0][j] == 0 && mat[n + 1][j] == maxim)
            out << j << " ";
    return 0;
}
