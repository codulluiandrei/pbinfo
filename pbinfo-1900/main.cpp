#include <bits/stdc++.h>
using namespace std;
long long v[20], aux, n, p, nr, d, im, r;
int i, k;
bool ok;
int main()
{
    ifstream f("numere16.in");
    ofstream g("numere16.out");
    f >> n;
    p = 1;
    while(p < n)
    {
       nr = ((n / 10) / p) * p + n % p;
       p = p * 10;
       if(nr != 0)
       {
        d = n;
        im = nr;
        r = d % im;
        while(r != 0)
        {
           d = im;
           im = r;
           r = d % im;
        }
        if(im == 1) v[++ k] = nr;
       }
    }
    do
    {
        ok = true;
        for(i = 1; i < k; i ++)
         if(v[i] > v[i + 1])
         {
             aux = v[i];
             v[i] = v[i + 1];
             v[i + 1] = aux;
             ok = false;
         }
    } while(!ok);
    if(k == 0) g << "NU EXISTA";
    else
    for(i = 1; i <= k; i ++)
     g << v[i] << " ";
    return 0;
}