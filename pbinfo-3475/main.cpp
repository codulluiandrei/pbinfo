#include <bits/stdc++.h>
using namespace std;

ifstream f("terencasa_low.in");
ofstream g("terencasa_low.out");

int a[1024][1024], s[1024][1024], n, m, S, l1, c1, l2, c2, i, j, maxx=1;

bool verif(int i1, int i2, int j1, int j2)
{
    S = s[i2][j2] - s[i1 - 1][j2] - s[i2][j1 - 1] + s[i1 - 1][j1 - 1];
    if(S == ((i2 - i1 + 1) * (i2 - i1 + 1))) return true;
    return false;
}

void Maxim()
{
    for(int i1 = 1; i1 < n; i1++)
    for(int j1 = 1; j1 < m; j1++)
    for(int i2 = i1 + maxx, j2 = j1 + maxx; i2 <= n && j2 <= m; i2++, j2++)
    if(verif(i1, i2, j1, j2))
    {
        if(i2 - i1 + 1 > maxx)
        {
            maxx = i2 - i1 + 1;
            l1 = i1;
            l2 = i2;
            c1 = j1;
            c2 = j2;
        }
    }
    else break;
}

int main()
{
    f >> n >> m;
    for(i = 1; i <= n; i++)
    for(j = 1; j <= m; j++)
    {
        f >> a[i][j];
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    }
    Maxim();
    g << maxx << '\n' << l1 << " " << c1 << " " << l2 << " " << c2 << '\n';
    f.close();
    g.close();
    return 0;
}