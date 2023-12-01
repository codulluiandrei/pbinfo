#include <bits/stdc++.h>
using namespace std;

int a[1005], n, m;

int main()
{
    int i, j, aria, x;
    ifstream fin("submat1.in");
    ofstream fout("submat1.out");
    fin >> n >> m;
    for (i = 1; i <= n; ++i)
    {
        a[i] = 0;
        for (j = 1; j <= m; j++)
        {
            fin >> x;
            if (x == 0) a[i]++;
        }
    }
    sort(a + 1, a + n + 1, greater<int>());
    aria = 0;
    for (i = 1; i <= n; i++)
        if (aria < i * a[i]) aria = i * a[i];
    fout << aria << "\n";
    fin.close();
    fout.close();
    return 0;
}
