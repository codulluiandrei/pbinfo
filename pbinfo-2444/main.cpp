#include <fstream>
#include <algorithm>
#include <string>
using namespace std;
int valori[1100000];
string expr;
int cx,cy,cz,ct,tl,a,b,E;
int nrcrt,semn,ceri;
ifstream f("eq4.in");
ofstream g("eq4.out");
long long rezultat;
int main()
{
    f >> ceri;
    f >> expr;
    expr+='+';
    f >> a >> b >> E;
    semn = +1;
    for (int i=0;i<expr.size();i++)
    {
        if (expr[i]=='+')
        {
            tl = tl + semn*nrcrt;
            nrcrt = 0;
            semn = +1;
        }
        if (expr[i]=='-')
        {
            tl = tl + semn*nrcrt;
            nrcrt = 0;
            semn = -1;
        }
        if (expr[i]>='0' && expr[i]<='9')
            nrcrt = 10*nrcrt+expr[i]-'0';
        if (expr[i]=='x')
        {
            if (expr[i-1]=='+' )
                nrcrt=1;
            if (expr[i-1]=='-')
                nrcrt=1;
                cx = cx + semn*nrcrt;
                nrcrt = 0;
        }
        if (expr[i]=='y')
        {
            if (expr[i-1]=='+' )
                nrcrt=1;
            if (expr[i-1]=='-')
                nrcrt=1;
            cy = cy + semn*nrcrt;
            nrcrt = 0;
        }
        if (expr[i]=='z')
        {
            if (expr[i-1]=='+' )
                nrcrt=1;
            if (expr[i-1]=='-')
                nrcrt=1;
            cz = cz + semn*nrcrt;
            nrcrt = 0;
        }
        if (expr[i]=='t')
        {
            if (expr[i-1]=='+' )
                nrcrt=1;
            if (expr[i-1]=='-')
                nrcrt=1;
            ct = ct + semn*nrcrt;
            nrcrt = 0;
        }
    }
    ///cout << cx << ' ' << cy << ' ' << cz << ' ' << ct << ' ' << tl << endl;
    if (ceri==1)
    {
        ///cout << cx+cy+cz+ct+tl<<endl;
        g << cx+cy+cz+ct+tl<<endl;
        return 0;
    }
    int poz=0;
    for (int x=a;x<=b;x++)
        for (int y=a;y<=b;y++)
        {
            int val = E - cx*x -cy*y;
            valori[poz]=val;
           /// cout << x << ' ' << y << ' ' << val << endl;
            poz++;
        }
        ///cout << endl;
    sort(valori,valori+poz);
    ///for (int i=0;i<poz;i++) cout << valori[i]<<' ';
    ///cout << endl;
    for (int z=a;z<=b;z++)
        for (int t=a;t<=b;t++)
        {
            int val = cz*z + ct*t + tl;
            if (val<valori[0]||val>valori[poz-1])
                continue;
            int pozsup = upper_bound(valori,valori+poz,val)-valori;
            int pozinf = lower_bound(valori,valori+poz,val)-valori;
            int nrap = pozsup - pozinf;
            rezultat += nrap;
           /// cout << z<<' '<<t<<' '<<val<<' '<<nrap<<' ' <<rezultat<<endl;
        }
    ///cout << rezultat << endl;
    g << rezultat << endl;
    return 0;
}