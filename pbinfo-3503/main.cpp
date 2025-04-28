#include <bits/stdc++.h>
using namespace std;
ifstream f("biarbore1.in");
ofstream g("biarbore1.out");
int x, a;
int main()
{
    f >> x >> x;
    g << x << " ";
    a=2*!!x;
    while (a) // citim doar descendentii fiului din stanga al radacinii
        f >> x, a += (x ? 1 : -1);
    f >> x;
    g << x;
    return 0;
}