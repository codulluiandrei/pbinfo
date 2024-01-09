#include <bits/stdc++.h>
using namespace std;

int b[100002], f[100002], n, m;

int main()
{
    int i, j, cnt;
    ifstream  fin("bal.in");
    ofstream fout("bal.out");
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> f[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];

    sort(f + 1, f + n + 1);
    sort(b + 1, b + m + 1);

    cnt = 0;
    i = j = 1;
    while (i <= n && j <= m)
        if (f[i] <= b[j])
        {
            cnt++;
            i++;
            j++;
        }
        else j++;
    fout << cnt << "\n";
    fout.close();
    fin.close();
    return 0;
}
