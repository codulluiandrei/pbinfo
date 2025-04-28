#include <fstream>
#include <iostream>
#include <set>
#include <deque>
using namespace std;
set<int> S[100010];
set<int>::iterator it;
deque<int> q;
int n, m, i, x, y, nod, vec, N, d[100010];
int main () {
    ifstream fin("ff.in");
    ofstream fout("ff.out");
    fin>>n>>m;
    for (i=1;i<=m;i++) {
        fin>>x>>y;
        S[x].insert(y);
        S[y].insert(x);
        d[x]++;
        d[y]++;
    }
    for (i=1;i<=n;i++)
        if (d[i] <= 1)
            q.push_back(i);
    N = n;
    while (!q.empty()) {
        nod = q.front();
        q.pop_front();
        N --;
        if (S[nod].size()) {
            d[nod]--;
            vec = *S[nod].begin();
            d[vec]--;
            S[nod].erase( S[nod].begin() );
            it = S[vec].find(nod);
            S[vec].erase(it);
            if (d[vec] == 1)
                q.push_back(vec);
        }
    }
    fout<<N<<"\n";
    return 0;
}