#include <fstream>
using namespace std;
ifstream in("exista.in");
ofstream out("exista.out");
int main() {
    int mat[101][101], n, m, k, S = 0, adv = 0;
    in >> k >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            in >> mat[i][j];
    for (int j = 1; j <= m; ++j) {
        int temp = 0;
        for (int i = 1; i <= n; ++i) {
            if (mat[i][j] == k) temp++;
        } if (temp != 0) {
            S = S + j; adv++;
        }
    } if (adv == 0) out << "NU EXISTA";
    else out << S;
    return 0;
}