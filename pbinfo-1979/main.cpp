///autor: Andrei Margeloiu
# include <bits/stdc++.h>
# define INF 99999999
# define NR 100005
using namespace std;
ifstream f("rbtree.in");
ofstream g("rbtree.out");
queue <int> redQueue, blackQueue, rootQueue;
vector <int> v[NR], vt[NR];
int n, RED, BLACK, cnt, x;
int redDist[NR], blackDist[NR], rootDist[NR];
void BFS (queue <int>& q, int dist[], const vector <int> (&v) [NR]) {
    while (!q.empty()) {
        int k = q.front();
        q.pop();
        for (auto &x: v[k]) {
            if (dist[x] > dist[k] + 1) {
                dist[x] = dist[k] + 1;
                q.push(x);
            }
        }
    }
}
int main ()
{
    f>>n>>RED>>BLACK;
    for (int i=1; i<=n; ++i)
        redDist[i] = blackDist[i] = rootDist[i] = INF;
    for (int i=1; i<=RED; ++i) {
        f>>x; redDist[x] = 0;
        redQueue.push(x);
    }
    for (int i=1; i<=BLACK; ++i) {
        f>>x; blackDist[x] = 0;
        blackQueue.push(x);
    }
    for (int i=1; i<=n; ++i) {
        f>>cnt;
        for (int j=1; j<=cnt; ++j) {
            f>>x;
            v[i].push_back(x);
            vt[x].push_back(i);
        }
    }
    rootDist[1] = 0;
    rootQueue.push(1);
    BFS(redQueue, redDist, vt);
    BFS(blackQueue, blackDist, vt);
    BFS(rootQueue, rootDist, v);
    // calculam solutia
    int minn = INF;
    for (int i=1; i<=n; ++i) {
        minn = min(minn, redDist[i] + blackDist[i] + rootDist[i]);
    }
    if (minn == INF) g<<"impossible\n";
                else g<<minn<<"\n";
    return 0;
}