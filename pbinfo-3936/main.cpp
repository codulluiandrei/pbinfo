#include <bits/stdc++.h>
using namespace std;
ifstream f("determinantb.in");
ofstream g("determinantb.out");
int n,i,h,j,t,x,y,inv,lung;
int prod[1000003], a[1003];
int main()
{
    f >> n;
    if(n > 201) g << 0;
    else
    {
        for(i = 1; i <= n; i++)
            f >> a[i];
        inv = 0;
        lung = 1;
        prod[1] = 1;
        for(i = 1; i < n; i++)
        for(j = i+1; j <= n; j++)
        {
            if(a[i] > a[j])
            {
                inv++;
                x = a[i]-a[j];
            }
            else x = a[j]-a[i];
            t = 0;
            for(h = 1; h <= lung; h++)
            {
                y = prod[h]*x+t;
                prod[h] = y % 1000000;
                t = y / 1000000;
            }
            while(t > 0)
            {
                lung++;
                prod[lung] = t % 1000000;
                t = t / 1000000;
            }
        }
        if(inv % 2 == 1) g << "-";
        g << prod[lung];
        for(i = lung-1; i >= 1; i--)
            if(prod[i] < 10) g << "00000" << prod[i];
            else
            if(prod[i] < 100) g << "0000" << prod[i];
            else
            if(prod[i] < 1000) g << "000" << prod[i];
            else
            if(prod[i] < 10000) g << "00" << prod[i];
            else
            if(prod[i] < 100000) g << "0" << prod[i];
            else g << prod[i];
    }
    return 0;
}