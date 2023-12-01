// O(N*log(N))
#include <stdio.h>
#include <stdlib.h>
int s[100001], p[100001], e[100001], c[100001];

int cmp(const void *a, const void *b) {
    return s[*(int *)a] - s[*(int *)b];
}

int main() {
    FILE        *f  = fopen("densitate.in",  "r");
    FILE        *g  = fopen("densitate.out", "w");
    long long   ans = 0;
    int         n, d;

    fscanf(f, "%d", &n);
    for (int i = 1; i <= n; i++) fscanf(f, "%d", s + i);
    fscanf(f, "%*[^0]0.%d", &d);

    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + ((s[i] & 1) ? d : (d - 100));
        p[i] = i;
    }

    qsort(p, n + 1, sizeof(int), cmp);
    for (int i = 1; i <= n; i++) {
        e[p[i]] =  e[p[i - 1]] + (s[p[i - 1]] != s[p[i]]);
    }

    c[e[0]] = 1;
    for (int i = 1; i <= n; i++) ans += c[e[i]]++;

    fprintf(g, "%lld", ans);
    fclose(f);
    fclose(g);

    return 0;
}
