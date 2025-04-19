#include <bits/stdc++.h>
using namespace std;
class Kosaraju {
    vector<bool> plus, minus;
    stack<int> st;
    vector<vector<int>> ctc;
    void dfs_plus(int nod, vector<vector<int>> &G) {
        plus[nod] = 1;
        for (auto it : G[nod])
            if (!plus[it])
                dfs_plus(it, G);
        st.push(nod);
    }
    void dfs_minus(int nod, vector<vector<int>> &GT) {
        ctc.back().push_back(nod);
        minus[nod] = 1;
        for (auto it : GT[nod])
            if (!minus[it])
                dfs_minus(it, GT);
    }
public:
    vector<vector<int>> solve(int N, vector<vector<int>> &G, vector<vector<int>> &GT) {
        plus.resize(N + 1);
        minus.resize(N + 1);
        for (int i = 1; i <= N; ++i)
            if (!plus[i])
                dfs_plus(i, G);
        while (!st.empty()) {
            int nod = st.top();
            st.pop();
            if (!minus[nod]) {
                ctc.push_back({});
                dfs_minus(nod, GT);
            }
        }
        return ctc;
    }
};
vector<int> Dijkstra(int N, vector<vector<pair<int, int>>> &G, int nod) {
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>> Q;
    vector<int> dist(N + 1, INT_MAX);
    dist[nod] = 0;
    Q.push({0,nod});
    while (!Q.empty()){
        int nod = Q.top().second, cost = Q.top().first;
        Q.pop();
        if (dist[nod] != cost)
            continue;
        for (auto it : G[nod])
            if (cost + it.second < dist[it.first]){
                dist[it.first] = cost + it.second;
                Q.push({dist[it.first], it.first});
            }
    }
    return dist;
}
int main() {
    int C, N, M;
    cin >> C >> N >> M;
    vector<vector<int>> G(N + 1), GT(N + 1);
    vector<vector<pair<int, int>>> GM(N + 1);
    while (M--) {
        int i, j, d;
        cin >> i >> j >> d;
        G[i].push_back(j);
        GT[j].push_back(i);
        GM[j].push_back({i, d});
    }
    // prima cerinta
    vector<vector<int>> ctc = Kosaraju().solve(N, G, GT);
    vector<int> res = ctc.back();
    sort(res.begin(), res.end());
    if (C == 1) {
        for (auto it : res)
            cout << it << " ";
        cout << "\n";
    }
    else {
        // a doua cerinta
        vector<bool> is_res(N + 1);
        for (auto it : res)
            is_res[it] = 1;
        // graful modificat = graful transpus, dar toate resedintele devin nodul 0
        for (int i = 1; i <= N; ++i)
            if (is_res[i]) {
                for (auto it : GM[i]) 
                    if (!is_res[it.first])
                        GM[0].push_back(it);
            }
        vector<int> dist = Dijkstra(N, GM, 0);
        for (int i = 1; i <= N; ++i) {
            if (is_res[i])
                cout << "0 ";
            else cout << dist[i] << " ";
        }
    }
} 