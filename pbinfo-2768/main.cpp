#include <bits/stdc++.h>
#define Nmax 100005
using namespace std;
vector<int> L[Nmax];
int n, m;
set<int> S;
/// in S se depun nodurile de grad interior 0
int d[Nmax]; /// d[i]=gradul interior al nodului i
void Citire()
{
    int i, x, y;
    cin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        cin >> x >> y;
        L[x].push_back(y);
        d[y]++;
    }
}
void SortTop()
{
    int i, nod;
    /// punem in S toate nodurile de grad 0
    for (i = 1; i <= n; i++)
        if (d[i] == 0)
            S.insert(i);
    while (S.size() > 0)
    {
        /// extrag din S nodul minim
        nod = *(S.begin());
        /// sterg nodul din stiva:
        S.erase(nod);
        cout << nod << " ";
        /// parcurgem lista de adiacenta a nodului nod
        /// si decrementam gradele tuturor nodurilor adiacente cu nod
        for (auto j : L[nod])
        {
            d[j]--;
            if (d[j] == 0)
                S.insert(j);
        }
    }
}
int main()
{
    Citire();
    SortTop();
    return 0;
}