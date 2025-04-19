#include <iostream>
#include <fstream>
using namespace std;
ifstream f("soarece2.in");
ofstream g("soarece2.out");
struct coada {
    int x, y;
    int nr, poz;
    char directie;
} c[1000001];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int n, m, X1, YY, X2, Y2, i, j, sol[1000001], a[1001][1001];
char ch;
void lee(int X1, int YY, int X2, int Y2) {
    int p, u, xx, yy, i, k, OK = 0;
    p = u = 1;
    c[p].x = X1;
    c[p].y = YY;
    c[p].nr = 1;
    a[X1][YY] = 1;
    while (p <= u && !OK) {
        for (i = 0; i <= 3 && !OK; i++) {
            xx = c[p].x + dx[i];
            yy = c[p].y + dy[i];
            if (a[xx][yy] == 0) {
                u++;
                c[u].x = xx;
                c[u].y = yy;
                c[u].nr = c[p].nr + 1;
                a[xx][yy] = 1;
                c[u].poz = p;
                if (i == 0) c[u].directie = 'N';
                if (i == 1) c[u].directie = 'E';
                if (i == 2) c[u].directie = 'S';
                if (i == 3) c[u].directie = 'V';
                if (xx == X2 && yy == Y2) OK = 1;
            }
        } p++;
    } if (OK == 0) g << 0;
    else {
        g << c[u].nr - 1 << "\n";
        k = 1;
        sol[k] = u;
        while (u != 1) {
            u = c[u].poz;
            k++;
            sol[k] = u;
        } for (i = k - 1; i >= 1; i--)
            g << c[sol[i]].directie;
    }
}
int main() {
    f >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++) {
        	f >> ch;
            a[i][j]=0;
            if (ch == 'B') X2 = i, Y2 = j;
            if (ch == 'S') X1 = i, YY = j;
            if (ch == '#') a[i][j] = 1;
        } for (i = 0; i <= m + 1; i++)
        a[0][i] = a[n + 1][i] = 1;
    for (i = 0; i <= n + 1; i++)
        a[i][0] = a[i][m + 1] = 1;
    lee(X1, YY, X2, Y2);
    return 0;
}