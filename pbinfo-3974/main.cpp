#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
char t;
int N, M;
int main() {
    cin >> N >> M >> t;
    vector <int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    vector <int> b(M);
    for (int i = 0; i < M; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector <int> res(N + M);
    if (t == '*') res.resize(set_intersection(a.begin(), a.end(), b.begin(), b.end(), res.begin()) - res.begin());
    if (t == '+') res.resize(set_union(a.begin(), a.end(), b.begin(), b.end(), res.begin()) - res.begin());
    if (t == '-') res.resize(set_difference(a.begin(), a.end(), b.begin(), b.end(), res.begin()) - res.begin());
    if (t == '%') res.resize(set_symmetric_difference(a.begin(), a.end(), b.begin(), b.end(), res.begin()) - res.begin());
    for (int x : res)
        cout << x << " ";
    return 0;
}