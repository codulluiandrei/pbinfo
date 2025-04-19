#include <iostream>
#include <fstream>
using namespace std;
int n, i, t, m, a;
ifstream f("vterminal.in");
ofstream g("vterminal.out");
int prim(int n)
{
    int i, ok = 1;
    if(n == 1)
        return 0;
    for(i = 2; i * i <= n; i++)
        if(n % i == 0)
        {
            ok = 0;
            break;
        }
    return ok;
}
int sumcif(int n)
{
    int s = 0;
    while(n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main()
{
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> m;
        if(prim(m))
            t += sumcif(m);
    }
    while(t > 9)
        t = sumcif(t);
    g << t;
    return 0;
}