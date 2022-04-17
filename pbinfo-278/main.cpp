#include <iostream>
using namespace std;
int n, m, v[105], x[105];

bool maxmin(int nr) {
    for (int i = 1; i <= m; i++)
        if (nr <= x[i]) return false;
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> x[i];
    int C = 0;
    for (int i = 1; i <= n; i++)
        if (maxmin(v[i])) C++;
            cout << C;
    return 0;
}