#include <fstream>
using namespace std;
ifstream in("colzero.in");
ofstream out("colzero.out");
int main() {
	int mat[101][101], n, m, nr = 0;
	in >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
        	in >> mat[i][j];
    for (int j = 0; j < m; j++) {
        bool adv = true;
        for (int i = 0; i < n; i++) {
           if (mat[i][j] != 0) adv = false;
        } if (adv == true) nr++;
    } out << nr;
    return 0;
}