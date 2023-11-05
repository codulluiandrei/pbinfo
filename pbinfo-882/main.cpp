#include <iostream>
#include <fstream>
using namespace std;
ifstream in("lac.in");
ofstream out("lac.out");
int n, m, nrI, nrP;
int a[1002][1002];
short x[1000005], y[1000005];
const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
void fill(int istart, int jstart, int v) {
    int st = 1, dr = 1;
    x[1] = istart, y[1] = jstart;
    a[istart][jstart] = v;
    while (st <= dr) {
        int i = x[st], j = y[st];
        for (int k = 0; k < 4 ; k++) {
            int ii = i + dx[k] , jj = j + dy[k];
            if (ii > 0 && ii <= n && jj > 0 && jj <= m && a[ii][jj] == 1) {
                dr++;
                x[dr] = ii, y[dr] = jj;
                a[ii][jj] = v;
            }
        } st++;
    }
}
int main() {
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        	in >> a[i][j];
	nrP = nrI = 0;
    int v = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        	if ((i == 1 || i == n || j == 1 || j == m) && a[i][j] == 1) {
        		nrP++;
        		v = v + 2;
		        fill(i, j, v);
		    }
    v = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1) {
            	nrI ++;
            	v = v + 2;
            	fill(i, j, v);
        	} out << nrI << " " << nrP;
    return 0;
}