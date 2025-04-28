#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <bitset>
#include <set>
#include <cassert>
#include <memory.h>
#include <algorithm>
using namespace std;
const char iname[] = "ubuntzei.in";
const char oname[] = "ubuntzei.out";
const int MAX_N = 10005;
const int MAX_K = 17;
const int INF = 0x3F3F3F3F;
vector < pair <int, int> > adj[MAX_N], adjK[MAX_K];
int dist[MAX_K][1 << MAX_K];
priority_queue < pair <int, int> > que;
vector <int> go_dijkstra(int src, int nodeCount, vector < pair <int, int> >* adj) {
	vector <int> d(nodeCount, INF);
	vector < pair <int, int> >::iterator it;
	d[src] = 0;
	for (que.push(make_pair(-d[src], src)); !que.empty(); ) {
		int u = que.top().second;
		int dq = -que.top().first;
		que.pop();
		if (d[u] < dq)  continue ;
		for (it = adj[u].begin(); it != adj[u].end(); ++ it) {
			int v = (*it).first;
			int cost = (*it).second;
			if (d[v] > d[u] + cost) {
				d[v] = d[u] + cost;
				que.push(make_pair(-d[v], v));
			}
		}
	}
	return d;
}
priority_queue < pair <int, pair <int, int> > > queK;
int go_dijkstraK(int src, int sink, int nodeCountK, vector < pair <int, int> >* adjK) {
	memset(dist, INF, sizeof dist);
	dist[src][1 << src] = 0;
	for (queK.push(make_pair(0, make_pair(src, 1 << src))); !queK.empty(); ) {
		int u = queK.top().second.first;
		int s = queK.top().second.second;
		int d = -queK.top().first;
		queK.pop();
		if (dist[u][s] < d)  continue;
		for (vector < pair <int, int> >::iterator it = adjK[u].begin(); it != adjK[u].end(); ++ it) {
			int v = (*it).first;
			int cost = (*it).second;
			if (!(s & (1 << v))) {
				int t = s | (1 << v);
				if (dist[v][t] > dist[u][s] + cost) {
					dist[v][t] = dist[u][s] + cost;
					queK.push(make_pair(-dist[v][t], make_pair(v, t)));
				}
			}
		}
	}
	return dist[sink][(1 << nodeCountK) - 1];
}
int main(void) {
	int nodeCount, edgeCount, subsetCount, u, v, cost;
	ifstream in(iname);
	in >> nodeCount >> edgeCount >> subsetCount;
	int src  = 0;
	int sink = nodeCount - 1;
	vector <int> subset(subsetCount), idxSubset(nodeCount);  bitset <MAX_N> inSubset;
	for (int i = 0; i < subsetCount; ++ i) {
		in >> u; -- u;
		assert(0 < u && u < nodeCount - 1);
		idxSubset[ subset[i] = u ] = i;
		inSubset[u] = true;
	}
	subset.push_back(src), idxSubset[src] = (int) subset.size() - 1, inSubset[src] = true;
	subset.push_back(sink), idxSubset[sink] = (int) subset.size() - 1, inSubset[sink] = true;
	for (int i = 0; i < edgeCount; ++ i) {
		in >> u >> v >> cost;
		-- u, -- v;
		assert(0 <= u && u < nodeCount);
		assert(0 <= v && v < nodeCount);
		adj[u].push_back(make_pair(v, cost));
		adj[v].push_back(make_pair(u, cost));
	}
	in.close();
	vector <int> d;
	d = go_dijkstra(src, nodeCount, adj);
	for (size_t i = 0; i < d.size(); ++ i) if (inSubset[i]) {
		assert(d[i] < INF);
		if ((int) i != src)
			adjK[ idxSubset[src] ].push_back(make_pair(idxSubset[i], d[i]));
	}
	if (subsetCount > 0) {
		for (size_t i = 0; i < subset.size(); ++ i) if (subset[i] != src && subset[i] != sink) {
			d = go_dijkstra(subset[i], nodeCount, adj);
			for (size_t j = 0; j < d.size(); ++ j) if (inSubset[j]) {
				assert(d[j] < INF);
				if (subset[i] != (int) j)
					adjK[i].push_back(make_pair(idxSubset[j], d[j]));
			}
		}
		int answer = go_dijkstraK(idxSubset[src], idxSubset[sink], subset.size(), adjK);
		assert(answer < INF);
		ofstream(oname) << answer << "\n";
	}
	else
		ofstream(oname) << d[nodeCount - 1] << "\n";
	return 0;
}