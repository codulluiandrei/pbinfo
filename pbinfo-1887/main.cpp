#include <bits/stdc++.h>

using namespace std;
class cmp
{
    public:
    bool operator ()(pair <int, int> &a, pair<int, int> &b)
    {
        return a.second>b.second;
    }
};
priority_queue < pair <int, int>, vector <pair<int, int>>, cmp> pq;
int n, p, m;
vector <pair <int, int>> graf[100001];
int dist[100001];
void initializare(int p)
{
    int i;
    for (i = 1; i<=n; ++i)
        if (i!=p) dist[i] = 2000000000;
}
int main()
{
    ifstream fin ("dijkstra2.in");
    ofstream fout ("dijkstra2.out");
    fin >> n >> m >> p;
    initializare(p);
    int y, i, j, x, nod, cost, d;
    for (i = 0; i<m; ++i)
    {
        fin >> x >> y >> d;
        graf[x].push_back (make_pair(y, d));
        graf[y].push_back (make_pair(x, d));
    }
    pq.push(make_pair(p, dist[p]));
    while (pq.size())
    {
        nod = pq.top().first;
        cost = pq.top().second;
        pq.pop();
        if (dist[nod] != cost)
            continue;
        for (auto x : graf[nod])
        {
            if (cost + x.second < dist[x.first])
            {
                dist[x.first] = cost+x.second;
                pq.push(make_pair(x.first, dist[x.first]));
            }
        }
    }
    for (i = 1; i<=n; ++i)
        {if (dist[i] != 2000000000)
            fout << dist[i] << " ";
        else fout << "-1 ";}
    return 0;
}
