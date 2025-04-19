#include <bits/stdc++.h>
using namespace std;
int Cmmdc(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int n, m, c, niv = 0;
    ifstream fin("fractzii.in");
    ofstream fout("fractzii.out");
    fin >> n >> m;
    c = Cmmdc(n, m);
    n /= c;
    m /= c;
    while (n != 1 && m != 1)
    {
        if (n > m)
        {
            niv += (n / m);
            n = n % m;
        }
        else
        {
            niv += (m  / n);
            m = m % n;
        }
    }
    niv += max(n, m);
    fout << niv << "\n";
    fout.close();
    return 0;
}