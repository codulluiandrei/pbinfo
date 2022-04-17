#include <fstream>
using namespace std;
ifstream in("sumcolmax.in");
ofstream out("sumcolmax.out");
int main() {
	int mat[101][101], n, m, maxim = -1000001, S = 0, temp;
	in >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
        	in >> mat[i][j];
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
        	S = S + mat[i][j];
        } if (S > maxim) {
            maxim = S;
        	temp = j;
        } S = 0;
    } for (int i = 0; i < n; i++)
        out << mat[i][temp] << " ";
    return 0;
}