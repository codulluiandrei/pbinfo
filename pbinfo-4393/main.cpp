/// Gheorghe-Eugen Nodea - Centrul Judetean de Excelenta Gorj

#include <bits/stdc++.h>
using namespace std;

ifstream fcin("cufere.in");
ofstream fcout("cufere.out");

int n, m, e, x, c;
int ap[101];
bool pr[101];

int main()
{
    pr[2] = 1;
    for(int i=3; i<= 99; i += 2)
    {
        int ok = 1;
        for(int d=2; d*d <= i && ok; d++)
            if (i % d == 0) ok = 0;
        pr[i] = ok;
    }

    fcin >> c >> n;
    m = n;
    while (n --)
    {
        for(int i=1; i<=27; i++)
        {
            fcin >> x;
            int e = x%100;   ///eticheta
            ap[e] += x/100; ///nr.obiecte
        }
    }
    if (c == 1)
    {
        for(e = 10; e <= 99; e++)
            if (ap[e]) fcout << e << " " << ap[e] << "\n";
    }
    else
    {
        int i = 0;
        for(e = 10; e <= 99; e++)
        {
            int x = !pr[e] ? 64 : 16;
            while (ap[e] > 0)
            {
                if (ap[e] >= x)
                {
                    fcout << x << e << " ";
                    ap[e] -= x;
                }
                else
                {
                    fcout << ap[e] << e << " ";
                    ap[e] = 0;
                }
                i++;
                if (i % 9 == 0)
                    fcout << "\n";
            }
        }
        i++;
        for(; i <= m * 27; ++i)
        {
            fcout << "0 ";
            if (i % 9 == 0)
                fcout << "\n";
        }
    }
    return 0;
}
