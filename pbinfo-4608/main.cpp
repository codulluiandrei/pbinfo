/// - sortare in O(mlogm) - Eugen Nodea
#include <bits/stdc++.h>
using namespace std;
ifstream  fin("aprogressive.in");
ofstream fout("aprogressive.out");
int c, n, m;
int a[1030][1030];
int s[1030][1030], sum[1030];
void divide (int x1, int y1, int x2, int y2)
{
    if ( x1 > x2 || y1 > y2 ) return ;
    if (x1 == x2 || y1 == y2)
        fout << "(" << x1 << "," << y1 << "," << x2 << "," << y2 << ",0)";
    else
    {
        fout << "(";
        ///calculam vectorul sumelor pe linii al submatricei
        int i = 0;
        for(int j=x1; j<=x2; j++)
            sum[++i] = s[j][y2] - s[j][y1-1];
        sort(sum+1, sum+i+1);
        int r = sum[2] - sum[1]; /// determinam ratia
        int ok = (r != 0);
        for(int j=2; j<=i && ok; j++)
            if (sum[j] - sum[j-1] != r) ok = 0;
        if (ok)
            fout << x1 << "," << y1 << "," << x2 << "," << y2 << "," << r;
        else
        {
            int mx = (x1+x2) / 2;
            int my = (y1+y2) / 2;
            divide(x1, y1, mx, my);     /// A
            divide(x1,my+1, mx, y2);    /// B
            divide(mx+1,y1, x2, my);    /// C
            divide(mx+1, my+1, x2, y2); /// D
        }
        fout << ")";
    }
}
int main()
{
    fin >> c;
    fin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        s[i][0] = 0;
        for(int j=1; j<=m; j++)
        {
            fin >> a[i][j];
            s[i][j] = s[i][j-1] + a[i][j];
        }
    }
    ///1
    if (c == 1)
    {
        int Max = s[1][m];
        for(int i=2; i<=n; i++)
            if (s[i][m] > Max) Max = s[i][m];
        for(int i=1; i<=n; i++)
            if (s[i][m] == Max)
                fout << i << char(10);
    }
    ///2
    else if (c == 2)
    {
        for(int i=1; i<=n; i++)
            sort(a[i]+1, a[i]+m+1);
        for(int i=1; i<=n; i++)
        {
            int r = a[i][2] - a[i][1];
            int ok = (r != 0);
            for(int j=2; j<=m && ok; j++)
                if (a[i][j] - a[i][j-1] != r) ok = 0;
            if (ok) fout << i << char(10);
        }
    }
    ///3
    else
    {
        divide(1,1,n,m);
    }
    return 0;
}