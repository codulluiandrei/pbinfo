#include <fstream>
#include <vector>
#include <time.h>
#include <set>
#include <list>
#define V 2000001
#define M 500001
#define ll int
using namespace std;
ifstream f("vacanta2020.in");
ofstream go("vacanta2020.out");
const ll INF = 2000000000;
vector<ll> dist(V, INF);
vector< pair<int, int> > g[V];
ll minim;
int x,y,w;
int n,m,k,i,u,v,nr,e,ti,j;


void dijkstra(int src)
{
    set< pair<ll, int> > setds;
    setds.insert({0,src});
    dist[src] = 0;
    while (!setds.empty())
    {
        pair<ll,int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int h = tmp.second;
        vector< pair<int, int> >::iterator it;
        for (it = g[h].begin(); it != g[h].end(); ++it)
        {
            int f = (*it).first;
            int weight = (*it).second;
            if(dist[f] > dist[h]+weight)
					{
						if (dist[f] != INF)
                          setds.erase(setds.find(make_pair(dist[f], f)));
                        dist[f] = dist[h]+weight;
                        setds.insert(make_pair(dist[f], f));
					}

        }
    }
}

int main()
{
    f >> n >> m >> k;
    for(i = 1; i <= m; i++)
    {
        f >> x >> y >> w;
		for(j = 0; j <= k; j++)
		{
            g[n*j+x].push_back({n*j+y,w});
            g[n*j+y].push_back({n*j+x,w});
		}
		for(j = 0; j < k; j++)
		{
			g[n*j+x].push_back({n*(j+1)+y,0});
			g[n*j+y].push_back({n*(j+1)+x,0});
		}
    }

    dijkstra(1);

    for(i = 1; i <= n; i++)
       {
		   minim = INF;
		   for(j = 0; j <= k; j++)
		      if(dist[n*j+i]<minim) minim = dist[n*j+i];
		go << minim << " ";
	   }
    return 0;
}
