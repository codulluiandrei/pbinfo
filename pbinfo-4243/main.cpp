#include <bits/stdc++.h>
using namespace std;

ifstream  fin("mouse.in");
ofstream fout("mouse.out");

int a[105][105], n, m;

int main()
{
    int i, j, s = 0, minim = 101;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
        {
            fin >> a[i][j];
            s += a[i][j];
            if ((i + j) % 2 == 1 && minim > a[i][j])
                minim = a[i][j];
        }
    if (n % 2 == 1 || m % 2 == 1)
        fout << (n * m) << " " << s << "\n";
    else
        fout << (n * m - 1) << " " << (s - minim) << "\n";
    fin.close();
    fout.close();
}
