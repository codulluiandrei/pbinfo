#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 810
#define maxm 6010
#define inf (1LL*1000000000*1000000000)
int cer, n, m, a[maxm], b[maxm], d[maxm], dmax[maxn];
int f[maxn*maxn];
long long dist[maxn*maxn];
vector<int> v[maxn], w[maxn];
vector<pair<long long, int> > h;
int getNode(int lvl, int nod)
{
    return (lvl-1)*n+nod;
}
void dijkstra()
{
    for(int i=1; i<=n*n; ++i)
        dist[i]=inf;
    dist[1]=0;
    h.push_back(make_pair(0, 1));
    int nod;
    long long cdist;
    while(!h.empty())
    {
        nod=h[0].second;
        if(nod==n*n)
            break;
        cdist=-h[0].first;
        pop_heap(h.begin(), h.end());
        h.pop_back();
        if(f[nod])
            continue;
        f[nod]=1;
        int fiu, dragon = (nod-1)/n+1, node = (nod-1)%n+1;
        fiu = getNode(node, node);
        if(dist[fiu]>cdist)
        {
            dist[fiu]=cdist;
            h.push_back(make_pair(-dist[fiu], fiu));
            push_heap(h.begin(), h.end());
        }
        for(int i=0; i<v[node].size(); ++i)
        {
            fiu = getNode(dragon, v[node][i]);
            if(dist[fiu]>cdist+w[node][i] && w[node][i]<=dmax[dragon])
            {
                dist[fiu]=cdist+w[node][i];
                h.push_back(make_pair(-dist[fiu], fiu));
                push_heap(h.begin(), h.end());
            }
        }
    }
}
int cerinta1()
{
    int best=dmax[1];
    for(int i=2; i<=n; ++i)
        if(dist[i]!=inf && dmax[i]>best)
            best=dmax[i];
    return best;
}
int main()
{
    freopen("dragoni.in", "r", stdin);
    freopen("dragoni.out", "w", stdout);
    scanf("%d", &cer);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; ++i)
        scanf("%d", &dmax[i]);
    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d%d", &a[i], &b[i], &d[i]);
        v[a[i]].push_back(b[i]);
        v[b[i]].push_back(a[i]);
        w[a[i]].push_back(d[i]);
        w[b[i]].push_back(d[i]);
    }
    dijkstra();
    if(cer==1)
        printf("%d
", cerinta1());
    else
        printf("%lld
", dist[n*n]);
    return 0;
}