#include <bits/stdc++.h>
using namespace std;
ifstream in("sortare.in");
ofstream out("sortare.out");
int main() {
    int v[1001], n;
    in >> n;
    for (int i = 0; i < n; i++) in >> v[i];
    sort(v, v + n, greater<int>());
    for (int i = 0; i < n; i++) out << v[i] << " ";
    return 0;
}