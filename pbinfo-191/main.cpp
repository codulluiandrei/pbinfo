#include <fstream>
using namespace std;
ifstream in("maxmat.in");
ofstream out("maxmat.out");
int main() {
	int mat[101][101], maxim = -1001, n, m, temp;
    in >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
        	in >> mat[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        	if (mat[i][j] > maxim) {
        	    maxim = mat[i][j];    
        	    temp = j;
        	}
        } out << maxim << " " << temp + 1 << endl;
        maxim = -1001;
    } return 0;
}