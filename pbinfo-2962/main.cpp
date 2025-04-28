#include <stdio.h>
#include <stdlib.h>
struct NODE {
    int     r, c, v;
    struct NODE    *prev;
    struct NODE    *next;
};
void ddelete(struct NODE *n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
}
struct NODE* insert(struct NODE *prev, int r, int c, int v) {
    struct NODE *next  = prev->next;
    struct NODE *n     = (struct NODE *)malloc(sizeof(struct NODE));
    n->r = r; n->c = c; n->v = v;
    n->next     = next;
    n->prev     = prev;
    next->prev  = n;
    prev->next  = n;
    return n;
}
int main() {
    FILE    *f = fopen("traseu.in",  "r");
    FILE    *g = fopen("traseu.out", "w");
    struct NODE    row[500];
    struct NODE    *NODE[250000];
    int     m, n, v;
    fscanf(f, "%d %d", &m, &n);
    for (int i = 0; i < m; i++) {
        row[i].next = row[i].prev = &row[i];
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &v); v--;
            NODE[v] = insert(row[i].prev, i, j, v);
        }
    }
    int ans = 0;
    for (int v = 0; v < m*n; v++) {
        struct NODE *x = NODE[v];
        for (int i = x->r; i < m; i++) {
            struct NODE *y = row[i].prev;
            int  d  = i - x->r + y->c - x->c;
            if (y->next != y && x->c <= y->c && d > ans) ans = d;
        }
        ddelete(x);
    }
    if(ans == 0)fprintf(g, "0");
    else fprintf(g, "%d", ans + 1);
    fclose(f);
    fclose(g);
    return 0;
}