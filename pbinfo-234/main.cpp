#include <iomanip>
#include <fstream>
using namespace std;
ifstream in("medpoz.in");
ofstream out("medpoz.out");
int mat[101][101], n;
int main() {
    in >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            in >> mat[i][j];
    double S = 0;
    int k = 0;
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j)
        	if (mat[i][j] > 0) {
        		S = S + mat[i][j];
        		k++;
    		}
    if (k == 0) out << "NU EXISTA";
    else {
        S = S / k;
        S = ((int) (S * 1000)) / 1000.0;
        out << setprecision(3) << fixed << S;
    } return 0;
}