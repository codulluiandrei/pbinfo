#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;
ifstream f("pcp.in");
ofstream g("pcp.out");
long long n,m,pp,x,i,j,a,ok,sol,r,u,b[100000],a1,m1,rest,pas;
int v[10],w[10],z[10];

void calcul()
{
    for(i = a1; i <= a; i = i+pas)
    {
        for(u = 0; u <= 9; u++)
            w[u] = 0;
        x = i*i;
        pp = x;
        while(x != 0)
        {
            r = x%10;
            w[r]++;
            x = x/10;
        }
        ok = 1;
        for(u = 1; u <= 9; u++)
            if(w[u]!=v[u]) ok = 0;
        if(w[0]>v[0]) ok = 0;
        if(ok==1)
        {
            sol++;
            b[sol] = pp;
        }
    }
}

int main()
{
    f >> n;
    while(n!=0)
    {
        r = n%10;
        v[r]++;
        w[r]++;
        z[r]++;
        rest += r;
        n = n/10;
    }
    rest = rest%9;
    m = 0;
    for(i = 9; i >= 0; i--)
        while(w[i]>0)
        {
            m = m*10+i;
            w[i]--;
        }
    m1 = 0;
    for(i = 1; i <= 9; i++)
        while(z[i]>0)
        {
            m1 = m1*10+i;
            z[i]--;
        }
    a = floor(sqrt(m));
    a1 = floor(sqrt(m1));
    sol = 0;
    if(rest==0)
    {
        if(a1%3!=0)
            a1 = a1+(3-a1%3);
        pas = 3;
        calcul();
    }
    else
    if(rest==4)
    {
        if(a1%9==2)
        {
            pas = 9;
            calcul();
            a1 += 5;
            calcul();
        }
        else
        if(a1%9==7)
        {
            pas = 9;
            calcul();
            a1 += 4;
            calcul();
        }
        else
        {
            if(a1%9 < 2)
            {
                a1 += 2-a1%9;
                pas = 9;
                calcul();
                a1 += 5;
                calcul();
            }
            else
            if(a1%9 < 7)
            {
                a1 += 7-a1%9;
                pas = 9;
                calcul();
                a1 += 4;
                calcul();
            }
            else
            {
                a1 += 3;
                pas = 9;
                calcul();
                a1 += 5;
                calcul();
            }
        }
    }
    else
    if(rest==7)
    {
         if(a1%9==4)
        {
            pas = 9;
            calcul();
            a1++;
            calcul();
        }
        else
        if(a1%9==5)
        {
            pas = 9;
            calcul();
            a1 += 8;
            calcul();
        }
        else
        {
            while(a1%9!=4)a1++;
            pas = 9;
            calcul();
            a1++;
            calcul();
        }
    }
    else
    {
       if(a1%9==0)
       {
           a1++;
           pas = 9;
           calcul();
           a1 += 7;
           calcul();
       }
       else
       if(a1%9==1)
       {
           pas = 9;
           calcul();
           a1 += 7;
           calcul();
       }
       else
       if(a1%9 < 8)
       {
           a1 += 8-a1%9;
           pas = 9;
           calcul();
           a1 += 2;
           calcul();
       }
       else
       {
           pas = 9;
           calcul();
           a1 += 2;
           calcul();
       }
    }

    if(sol==0) g << "nu exista\n";
    else{
    sort(b+1,b+sol+1);
    g << sol << "\n";
    for(i = 1; i <= sol; i++)
        g << b[i] << "\n";
    }
    return 0;
}
