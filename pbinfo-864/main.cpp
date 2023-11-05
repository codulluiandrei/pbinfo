#include <iostream>
#include <fstream>
using namespace std;

ifstream f("roboti.in");
ofstream g("roboti.out");

const int MAX_SIZE = 1002;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct coada {
    int x, y, a;
};

int n, m, xr, yr, x1, y1;
int a[MAX_SIZE][MAX_SIZE];
coada q[1000004];

void lee() {
    int p = 1, u = 1;
    int ok = 0;
    q[1].x = xr;
    q[1].y = yr;
    q[p].a = 0;
    a[xr][yr] = -1;

    while (p <= u && ok == 0) {
        for (int i = 0; i <= 3; i++) {
            int xx = q[p].x + dx[i];
            int yy = q[p].y + dy[i];
            if (a[xx][yy] == 0) {
                u++;
                q[u].x = xx;
                q[u].y = yy;
                q[u].a = q[p].a + 1;
                a[xx][yy] = -1;
                if (q[u].x == x1 && q[u].y == y1)
                    ok = 1;
            }
        }
        p++;
    }

    if (ok == 1)
        g << q[u].a;
    else
        g << -1;
}

int main() {
    f >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f >> a[i][j];
        }
    }

    f >> xr >> yr >> x1 >> y1;

    for (int i = 1; i <= n; i++) {
        a[i][0] = a[i][m + 1] = 1;
    }

    for (int i = 1; i <= m; i++) {
        a[0][i] = a[n + 1][i] = 1;
    }

    lee();

    return 0;
}