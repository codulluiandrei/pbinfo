/**
 * Problema: Lenes O(n^2)
 * Stud. Popescu Silviu-Emil
 *   Automatica si Calculatoare
 *   Facultatea Politehnica Bucurest
 */
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define NMax 1010
#define VMax 1010
#define oo 0x3f3f3f3f
using namespace std;
const char IN[] = "lenes.in", OUT[] = "lenes.out";
int Case, N, M, k1, k2;
int Mat[NMax][NMax];
int Sum[NMax], V[NMax], left[NMax], right[NMax];
int get_line_sum( int lin, int k, bool up = true, bool down = true ) {
    int res = Sum[lin];
    static int v[VMax];
    memset(v, 0, sizeof(v));
    for ( int i = 1; i <= M; ++ i ) {
        if ( up )
            ++ v[ Mat[lin - 1][i] ];
        if ( down )
            ++ v[ Mat[lin + 1][i] ];
    }
    for ( int i = 0; i < VMax && k ; ++ i )
        if ( k >= v[i] ) {
            res += i * v[i];
            k -= v[i];
        } else if ( v[i] ) {
            res += k * i;
            k = 0;
        }
    return res;
}
int case1() {
    int ret = get_line_sum(1, k1);
    for ( int i = 1; i <= N; ++ i )
        ret = min( ret, get_line_sum(i, k1));
    return ret;
}
int case2() {
    int ret = oo;
    for ( int i = 1; i <= N; ++ i )
        V[i] = get_line_sum(i, k2);
    left[1] = V[1];
    for ( int i = 2; i <= N; ++ i )
        left[i] = min(V[i], left[i - 1]);
    right[N] = V[N];
    for ( int i = N - 1; i > 0; -- i )
        right[i] = min(V[i], right[i + 1]);
    // computing distant lines
    for ( int i = 1; i <= N; ++ i ) {
        int r = get_line_sum(i, k1);
        int other = oo;
        if ( i > 3 ) other = min(other, left[i - 3]);
        if ( i < N - 2) other = min(other, right[i + 3]);
        ret = min(ret, r + other);
    }
    // computing adiacent lines
    for ( int i = 1; i < N; ++ i ) {
        int r1 = get_line_sum(i, k1    , true, false);
        int r2 = get_line_sum(i + 1, k2, false, true);
        ret = min( ret, r1 + r2 );
        r1 = get_line_sum(i, k2    , true, false);
        r2 = get_line_sum(i + 1, k1, false, true);
        ret = min( ret, r1 + r2 );
    }
    //fprintf(stderr, "%d
", ret);
    // computing common margin lines
    bool parity = true;
    for ( int i = 1; i < N - 1; ++ i ) {
        int sum = Sum[i] + Sum[i + 2];
        int up = i - 1;
        int mid = i + 1;
        int down = i + 3;
        int index_up = 1;
        int index_down = 1;
        for ( int j = 1; j <= M && j <= k1 + k2; ++ j )
            sum += Mat[mid][j];
        // adding extra elements
        for ( int j = M + 1; j <= k1 + k2; ++ j ) {
            if ( index_up <= k1 && Mat[up][index_up] <= Mat[down][index_down] || index_down > k2 ) {
                sum += Mat[up][index_up];
                ++ index_up;
            } else {
                sum += Mat[down][index_down];
                ++ index_down;
            }
        }
        ret = min(ret, sum);
        //fprintf(stderr, "begining with: (%d, %d, %d)
", index_up - 1, min(M, k1 + k2), index_down - 1);
        for ( int j = min(M, k1 + k2); j > 0; -- j ) {
            sum -= Mat[mid][j];
            if ( index_up <= k1 && Mat[up][index_up] <= Mat[down][index_down] || index_down > k2  ) {
                sum += Mat[up][index_up];
                ++ index_up;
            } else {
                sum += Mat[down][index_down];
                ++ index_down;
            }
            ret = min( ret, sum );
            if ( ret == sum ) {
                //fprintf(stderr, "(up: %d, mid: %d, down: %d -> %d
", index_up - 1, j - 1, index_down - 1, ret);
            }
        }
        if ( parity ) {
            parity = false;
            -- i;
        } else {
            parity = true;
        }
        swap( k1, k2 );
    }
    return ret;
}
int (*Work[])() = { case1, case2 };
int main() {
    freopen(IN, "r", stdin);
    freopen(OUT, "w", stdout);
    scanf("%d%d%d%d%d", &Case, &N, &M, &k1, &k2);
    for ( int i = 1; i <= N; ++ i)
        for ( int j = 1; j <= M; ++ j )
            scanf("%d", &Mat[j][i]);
    swap(N, M);
    for ( int i = 1; i <= N; ++ i )
        for ( int j = 1; j <= M; ++ j )
            Sum[i] += Mat[i][j];
    for ( int i = 1; i <= M; ++ i )
        Mat[0][i] = Mat[N + 1][i] = VMax - 1;
    for ( int i = 1; i <= N; ++ i )
        sort( Mat[i] + 1, Mat[i] + M + 1);
    printf("%d
", Work[Case - 1]());
    return 0;
}