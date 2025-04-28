// O(N * sqrt(Q))
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_N   500001
#define MAX_Q   10001
#define MOD     1000000007
typedef struct {
    int a, b, bidx, qidx;
} QUERY;
int     x[MAX_N], f[MAX_N], inv[MAX_N], ans[MAX_Q];
QUERY   q[MAX_Q];
int cmp(const void *u, const void *v) {
    QUERY *p = (QUERY *)u, *q = (QUERY *)v;
    return (p->bidx != q->bidx) ? (p->bidx - q->bidx) : (p->b - q->b);
}
void add(int v, int *f, int *inv, int *p) {
    *p = 1LL * (*p) * inv[f[v]] % MOD * (f[v] + 1) % MOD;
    f[v]++;
}
void rem(int v, int *f, int *inv, int *p) {
    *p = 1LL * (*p) * inv[f[v]] % MOD * (f[v] - 1) % MOD;
    f[v]--;
}
int main() {
    FILE    *fin  = fopen("dss.in",  "r");
    FILE    *fout = fopen("dss.out", "w");
    int     n, nq, BLOCK;
    fscanf(fin, "%d %d", &n, &nq);
    BLOCK = n / sqrt(nq);
    for (int i = 0; i < n; i++) fscanf(fin, "%d", x + i);
    for (int i = 0; i < nq; i++) {
        fscanf(fin, "%d %d", &q[i].a, &q[i].b);
        q[i].a--; q[i].b--; q[i].qidx = i; q[i].bidx = q[i].a/BLOCK;
    }
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
    }
    qsort(q, nq, sizeof(QUERY), cmp);
    for (int i = 0; i < MAX_N; i++) f[i] = 1;
    int a = 0, b = 0, p = 2; f[x[0]]++;
    for (int i = 0; i < nq; i++) {
        while (b < q[i].b) add(x[++b], f, inv, &p);
        while (b > q[i].b) rem(x[b--], f, inv, &p);
        while (a > q[i].a) add(x[--a], f, inv, &p);
        while (a < q[i].a) rem(x[a++], f, inv, &p);
        ans[q[i].qidx] = p - 1;
    }
    for (int i = 0; i < nq; i++) fprintf(fout, "%d\n", ans[i]);
    fclose(fin);
    fclose(fout);
    return 0;
}