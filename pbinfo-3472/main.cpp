#include <bits/stdc++.h>
using namespace std;
ifstream f ("terencasa.in");
ofstream g ("terencasa.out");
int a[1024][1024], S[1024][1024], L;
int main ()
{
    int i1, j1, i2, j2, n, m, i, j;
    f >> n >> m;
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    f >> a[i][j];
    for (i = 1; i <= n; i++)
        S[i][1] = a[i][1];
    for (j = 1; j <= m; j++)
        S[1][j] = a[1][j];
    for (i = 2; i <= n; i++)
    for (j = 2; j <= m; j++)
        if (a[i][j] == 0)
        S[i][j] = 0;
    else
	S[i][j] = min (min (S[i][j - 1], S[i - 1][j]), S[i - 1][j - 1]) + 1;
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
    if (S[i][j] > L)
	{
        L = S[i][j];
        i2 = i;
        j2 = j;
        i1 = i - L + 1;
        j1 = j - L + 1;
	}
    g << L << '\n' << i1 << " " << j1 << " " << i2 << " " << j2 << '\n';
    f.close ();
    g.close ();
    return 0;
}