#include <fstream>
using namespace std;
ifstream in("lincol.in");
ofstream out("lincol.out");
int main() {
	int mat[101][101], n, m, p;
    char tip;
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        	in >> mat[i][j];
	in >> p;
    for (int P = 1; P <= p; P++) {
    	in >> tip;
        if (tip == 'C') {
            int temp, S = 0; in >> temp;
            for (int i = 1; i <= n; i++)
                S = S + mat[i][temp];
            out << S << endl;
        } if (tip == 'L') {
			int temp, S = 0; in >> temp;
            for (int j = 1; j <= m; j++)
                S = S + mat[temp][j];
            out << S << endl;
        }
    } return 0;
}