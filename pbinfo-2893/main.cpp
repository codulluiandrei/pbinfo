#include <bits/stdc++.h>
#define NMAX 100005
#define pii pair<int,int>
using namespace std;
ifstream f("modernizare.in");
ofstream g("modernizare.out");
int n, m, F, x, y, c, lg[NMAX];
vector<int> v[NMAX];
queue<int> Q;
set<pii> S;
struct muchie{
    int x,y,c;
};
vector<muchie> M;
bool comp(muchie a, muchie b){
    if (min(lg[a.x],lg[a.y]) == min(lg[b.x],lg[b.y])){
        if (max(lg[a.x],lg[a.y]) == max(lg[b.x],lg[b.y]))
            return a.c < b.c;
        return max(lg[a.x],lg[a.y]) < max(lg[b.x],lg[b.y]);
    }
    return min(lg[a.x],lg[a.y]) < min(lg[b.x],lg[b.y]);
}
int main()
{
    f >> n >> m >> F;
    assert(1 <= n && n <= 1e5);
    assert(1 <= m && m <= 1e5);
    assert(1 <= F && F <= 2e9);
    for (int i=1;i<=m;i++){
        f >> x >> y >> c;
        assert(1 <= x && x <= n);
        assert(1 <= y && y <= n);
        assert(1 <= c && c <= 2e9);
        assert(S.find({x,y}) == S.end());
        assert(x != y);
        S.insert({x,y}); S.insert({y,x});
        v[x].push_back(y);
        v[y].push_back(x);
        M.push_back({x,y,c});
    }
    Q.push(1);
    memset(lg,0x3f,sizeof(lg));
    lg[1] = 1;
    while (!Q.empty()){
        int nod = Q.front();
        Q.pop();
        for (auto it : v[nod]){
            if (lg[it] > 1e9){
                lg[it] = lg[nod] + 1;
                Q.push(it);
            }
        }
    }
    sort(M.begin(),M.end(),comp);
    int k = 0;
    for (int i=0;i < M.size() && lg[M[i].x] < 1e9 && M[i].c <= F;i++,k++)
        F -= M[i].c;
    g << k << '\n';
    return 0;
}