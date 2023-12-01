#include <bits/stdc++.h>
using namespace std;
int n, x, xx, d1, d2, maxx, ap, i;
bool ok;
int main()
{
    ifstream f("chimie1.in");
    ofstream g("chimie1.out");
    f >> n >> d1 >> d2;
    for(i = 1; i <= n; i++)
    {
        f >> x;
        if(x == 0) continue;
        xx = x;
        while(xx % d1 == 0)
            xx = xx / d1;
        while(xx % d2 == 0)
            xx = xx / d2;
        if(xx == 1)
        {
            ok = true;
            if(x > maxx) maxx = x, ap = 1;
             else if(x == maxx) ap++;
        }
    }
    if(ok) g << maxx << " " << ap;
      else g << "NU EXISTA";
    return 0;
}
