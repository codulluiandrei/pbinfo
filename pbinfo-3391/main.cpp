#include <bits/stdc++.h>
using namespace std;
ifstream in("sirmaxim.in");
ofstream out("sirmaxim.out");
int main() {
    int n, v[21], maxim = 0, val = 0;
    in >> n;
    for (int i = 1; i <= n; i++)
            in >> v[i];
    for (int i = 1; i <= n / 2; i++)
         maxim = max(maxim, v[i]);
    for (int i = n / 2 + 1; i <= n; i++)
        if (maxim == v[i])
            val++;
    out << val;
    return 0;
}