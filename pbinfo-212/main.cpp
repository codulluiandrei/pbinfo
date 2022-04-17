#include <fstream>
using namespace std;
ifstream in("maxminmatrice.in");
ofstream out("maxminmatrice.out");
int main() {
	int mat[101][101], n, m, minim = 100001, maxim = -100001;
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        	in >> mat[i][j];
	for (int i = 1; i <= n; i++) {
	    for (int j = 1; j <= m; j++) {
	        if (mat[i][j] < minim) minim = mat[i][j];
	    } if (minim > maxim) maxim = minim;
	    minim = 100001;
	} out << maxim; 
	return 0;
}