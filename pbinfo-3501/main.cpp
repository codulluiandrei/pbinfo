#include <bits/stdc++.h>
using namespace std;
ifstream f ("orademate.in");
ofstream g ("orademate.out");
int x[16], n, C;
void afis()
{
    for (int i = 1; i <= n; i++) g << x[i];
    g << '\n';
}
void Back1(int k)
{
    for (int i = 0; i < 10; i++)
    {
        x[k] = i;
        if ( (k > 1 || i > 0 || n == 1) && (k % 2 != i % 2))
        {
            if (k == n) afis();
            else Back1(k + 1);
        }
    }
}
void Back2(int k)
{
    for (int i = x[k - 1]; i < 10; i++)
    {
        x[k] = i;
        if ( (k > 1 || i > 0 || n == 1) && k != i)
        {
            if (k == n) afis();
            else Back2(k + 1);
        }
    }
}
int main()
{
    f >> C >> n;
    if (C == 1) Back1(1);
    else Back2(1);
    f.close();
    g.close();
    return 0;
}