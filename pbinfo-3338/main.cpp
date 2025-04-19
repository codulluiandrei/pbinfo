#include <iostream>
using namespace std;
int t[503], n, m;
int main()
{
    int i, j, x, y, p, q, op;
    cin >> n >> m;
    /// initializare
    for (i = 1; i <= n; i++)
        t[i] = i;
    for (i = 1; i <= m; i++)
    {
        cin >> op >> x >> y;
        if (op == 2)
        {
            if (t[x] == t[y]) cout << "DA\n";
            else cout << "NU\n";
        }
        else
        {
            if (t[x] != t[y])
            {
                p = t[x];
                q = t[y];
                for (j = 1; j <= n; j++)
                    if (t[j] == p) t[j] = q;
            }
        }
    }
    return 0;
}