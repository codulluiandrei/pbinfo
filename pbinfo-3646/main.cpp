#include <bits/stdc++.h>

using namespace std;

ifstream fin("zoom_poza.in");
ofstream fout("zoom_poza.out");

int main() 
{
    int c;
    int b[701][701];
    fin >> c;
    cout << c;
    if(c == 1)
    {   
        int a[71][71];
        long long i, j, n, m, k, l1, c1, z, constanta, x, x1;
        fin >> n >> m >> z;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                fin >> a[i][j];
        for (i = 1; i <= n; i++) 
        {
            constanta = 0;
            for (j = 1; j <= m; j++) 
            {
                for (x = 1; x <= z; x++)
                    for (x1 = 1; x1 <= z; x1++)
                        b[(i - 1) * z + x1][constanta * z + x] = a[i][j];
                constanta++;
            }
        }
        for (i = 1; i <= z * n; i++) 
        {
            for (j = 1; j <= z * m; j++)
                fout << b[i][j] << " ";
            fout << "\n";
        }
    }
    if (c == 2) 
    {   long long i, j, n, m, k, l1, c1, z, constanta, x, x1, linie, coloana;
        fin >> n >> m >> z;
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                fin >> b[i][j];
        fin >> k;
        for (i = 1; i <= k; i++) 
        {
            fin >> l1 >> c1;
            linie = l1 / z;
            if (l1 % z != 0)
                linie++;
            coloana = c1 / z;
            if (c1 % z != 0)
                coloana++;
            fout << b[linie][coloana] << " ";
        }
    }
    return 0;
}