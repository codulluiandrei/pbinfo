#include <bits/stdc++.h>
using namespace std;
ifstream f("fsecv.in");
ofstream g("fsecv.out");
const int NM = 100003;
int n, block, q;
struct query{
    int l, r, k, p;
    bool operator < (const query &aux)const{
        if(l / block != aux.l / block) return l / block < aux.l / block;
        return r < aux.r;
    }
} Q[NM];
int a[NM], nr[NM], ap[2*NM], sol[NM];
void add(int i)
{
    int x = a[i] + 100000;
    if(ap[x] > 0) --nr[ap[x]];
    ++ap[x];
    ++nr[ap[x]];
}
void scoate(int i)
{
    int x = a[i]  + 100000;
    if(ap[x] > 0) --nr[ap[x]];
    --ap[x];
    ++nr[ap[x]];
}
int main()
{
    f >> n >> q;
    for(int i = 1; i <= n; ++i)
        f >> a[i];
    for(int i = 1; i <= q; ++i){
        f >> Q[i].l >> Q[i].r >> Q[i].k;
        Q[i].p = i;
    }
    block = sqrt(n);
    sort(Q + 1, Q + q + 1);
    int st = 1, dr = 0;
    for(int i = 1; i <= q; ++i){
        while(st > Q[i].l) --st, add(st);
        while(dr < Q[i].r) ++dr, add(dr);
        while(st < Q[i].l) scoate(st), ++st;
        while(dr > Q[i].r) scoate(dr), --dr;
        sol[Q[i].p] = nr[Q[i].k];
    }
    for(int i = 1; i <= q; ++i)
        g << sol[i] << '\n';
    return 0;
}