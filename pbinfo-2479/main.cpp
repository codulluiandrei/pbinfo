# include <bits/stdc++.h>
using namespace std;
ifstream f ("pietre.in");
ofstream g ("pietre.out");
;
struct piatra{
    short x, y;
}P[10002], sol[10002];
short A[103][103], B[103][103];
int n, m, k, G, Min = 10000, nr_p, t;
char mut[256];
int main()
{
    int i, j, x, y, l, c, M, del;
    f >> n >> m >> k >> G;
    for(i=1; i<=k; ++i) {
        f >> x >> y;
        A[x][y] = 1;
        P[i].x = x; P[i].y = y;
    }
    while(G--) {
        f >> x >> y;
        A[x][y] = -1;
    }
    f.get();
    f.get(mut, 256);
    M = strlen(mut);
    for(i=1 ;i<=k; ++i){
        memcpy(B, A, sizeof(A));
//        for(l=1; l<=n; ++l){
//            for(c=1; c<=m; c++)
//                g << B[l][c];
//            g << '\n';
//        }
//        g << '\n';
        l = P[i].x; c = P[i].y;
        del = k;
        for(j=0; j<M; ++j) {
            if (mut[j] == 'N') {
                if (l - 2 > 0)
                if (B[l-1][c] == 1 && B[l-2][c] == 0) {
                    B[l][c] = 0;
                    B[l-1][c] = 0;
                    B[l-2][c] = 1;
                    l = l-2;
                    del--;
                }
            }
            if (mut[j] == 'E') {
                if (c+2 <= m)
                if (B[l][c+1] == 1 && B[l][c+2] == 0) {
                    B[l][c] = 0;
                    B[l][c+1] = 0;
                    B[l][c+2] = 1;
                    c = c+2;
                    del--;
                }
            }
            if (mut[j] == 'S') {
                if (l+2 <= n)
                if (B[l+1][c] == 1 && B[l+2][c] == 0) {
                    B[l][c] = 0;
                    B[l+1][c] = 0;
                    B[l+2][c] = 1;
                    l = l+2;
                    del--;
                }
            }
            if (mut[j] == 'V'){
                if (c-2 > 0)
                if (B[l][c-1] == 1 && B[l][c-2] == 0) {
                    B[l][c] = 0;
                    B[l][c-1] = 0;
                    B[l][c-2] = 1;
                    c = c-2;
                    del--;
                }
            }
        }
//        for(l=1; l<=n; ++l){
//            for(c=1; c<=m; c++)
//                g << B[l][c];
//            g << '\n';
//        }
//        g << '\n';
        if (del < Min) {
            Min = del;
            nr_p = i;
            t = 0;
            for(l=1; l<=n; l++)
                for(c=1; c<=m; c++)
            if (B[l][c] == 1) {
                sol[++t].x = l;
                sol[t].y = c;
            }
        }
    }
    g << nr_p << '\n';
    g << t << '\n';
    for(i=1; i<=t; ++i)
        g << sol[i].x << ' ' << sol[i].y << '\n';
    return 0;
}