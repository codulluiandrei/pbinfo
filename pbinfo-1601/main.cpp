#include <fstream>
#include <vector>
using namespace std;
ifstream is("ascensiune.in");
ofstream os("ascensiune.out");
#define MaxN 100001
int n, nod_max, dmax;
vector<int> G[MaxN];
int dist[MaxN];
bool viz[MaxN];
void Dfs(int);
int main()
{
    is >> n;
    for (int i = 1, x, y; i < n; ++i)
    {
        is >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    dist[1] = 1;
    Dfs(1);
    for (int i = 1; i <= n; ++i )
    {
        dist[i] = 0;
        viz[i] = false;
    }
    dist[nod_max] = 1;
    dmax = 0;
    Dfs(nod_max);
    os << dmax;
    is.close();
    os.close();
    return 0;
}
void Dfs(int i)
{
    viz[i] = true;
    for (const auto& p : G[i])
        if ( !viz[p] )
        {
            dist[p] = dist[i] + 1;
            if (dist[p] > dmax)
            {
                dmax = dist[p];
                nod_max = p;
            }
            Dfs(p);
        }
}