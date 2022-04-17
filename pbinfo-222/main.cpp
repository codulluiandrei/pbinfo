#include <fstream>
using namespace std;
ifstream in("mincols.in");
ofstream out("mincols.out");
int main() {
	int mat[101][101], n, m, minim = 100001, temp;
    in >> n;
    m = n;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
        	in >> mat[i][j];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++)
        	if (mat[i][j] < minim) {
        	    minim = mat[i][j];
        }   out << minim << " ";
        minim = 100001;
    } return 0;
}