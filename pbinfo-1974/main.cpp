/* autor: Radu Stochitoiu */
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#define MAXN 2000001
using namespace std;
int TT[MAXN], RG[MAXN], n, m, q, i, j, new_father, x_tmp, y_tmp, k, K, start;
int Tata_Sus[MAXN << 1], cost_intern[MAXN << 1];
int  dist, l, sol, pos, a, b, R, y,h=300;
long long cost;
vector <int> G[MAXN << 1];
int T[MAXN], L[MAXN], T2[MAXN];
struct elem {
    int x, y, c;
} P[MAXN], P_backup[MAXN];
int cmp(elem a, elem b) {
    return (a.c < b.c);
}
void dfs(int nod,int tata,int niv)
{
    T2[nod]=tata;L[nod]=niv;
    if(niv % h == 0) tata=nod;
    for(int i = 0; i < G[nod].size(); ++i)
        {
            dfs(G[nod][i], tata, niv+1);
            T[G[nod][i]]=nod;
        }
}
int lca(int x, int y)
{
    while (T2[x]!=T2[y])
    {
        if(L[x] > L[y]) x=T2[x];
            else y=T2[y];
    }
    while(x != y)
    {
        if(L[x] > L[y]) x=T[x];
            else y=T[y];
    }
    return x;
}
int find(int x)
{
    for(R = x; R != TT[R]; R = TT[R]);
    // realizam compresia drumurilor
    while(TT[x] != x)
    {
        y = TT[x];
        TT[x] = R;
        x = y;
    }
    return R;
}
void unite(int x, int y)
{
    // retinem noul tata pentru reprezentarea in arborele noduri-muchii
    // actualizam tatal si rangul
    if(RG[x] > RG[y]) TT[y] = x, new_father = x;
    else {
        if(RG[x] == RG[y])
            RG[y] ++;
        TT[x] = y, new_father = y;
    }
}
int main() {
    freopen("trumplandia.in", "r", stdin);
    freopen("trumplandia.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    for(i = 1; i <= n; ++i) {
        // initial fiecare nod este propriul sau tata si rangul fiecarei
        // multimi disjuncte este 1
        RG[i] = 1;
        TT[i] = i;
        Tata_Sus[i] = i;
    }
    for(i = 1; i <= m; ++i) {
        // citim muchiile si le salvam pentru cand vom avea nevoie de ele
        // la query-uri
        scanf("%d%d%d", &P[i].x, &P[i].y, &P[i].c);
        P_backup[i] = P[i];
    }
    // sortam muchiile
    sort(P + 1, P + m +1, cmp);
    k = n;
    for(i = 1; i <= m; ++i)
    {
        // gasim cel mai inalt nod din reprezentarea multii disjuncte (Kruskal)
        x_tmp = find(P[i].x);
        y_tmp = find(P[i].y);
        // daca sunt in multimi diferite unim multimile
        if(x_tmp != y_tmp) {
            unite(x_tmp, y_tmp);
            // actualizam costul
            cost += P[i].c;
            // actualizam listele de vecini pentru arborele noduri-muchii
            G[++k].push_back(Tata_Sus[x_tmp]);
            G[k].push_back(Tata_Sus[y_tmp]);
            Tata_Sus[new_father] = k;
            // mapam muchia la costul acesteia
            cost_intern[k] = P[i].c;
        }
    }
    printf("%lld\n", 1LL * cost);
    // aplicam rmq pentru query-uri in O(1)
    dfs(k,0, 0);
    while(q--) {
        scanf("%d", &i);
        // aplicam LCA si aflam costul noului arbore
        printf("%lld\n", 1LL*(cost + P_backup[i].c - cost_intern[lca(P_backup[i].x, P_backup[i].y)]));
    }
    return 0;
}