#include <fstream>
using namespace std;
ifstream cin("patrate1.in");
ofstream cout("patrate1.out");
long long xa,xb,xc,ya,yb,yc,sol,l,h,x,y;
int main()
{
    cin>>l>>h>>x>>y;
    xa=0;
    ya=h;
    xb=l;
    yb=h;
    xc=l;
    yc=0;
    sol=1;
    while(xb<x or ya<y)
    {
        ///deasupra: panta dreptei>panta dreptunghi
        if(ya*x>=y*xa and y*xb>x*yb)
        {
            sol++;
            ya+=h;
            yb+=h;
            yc+=h;
        }
        else
        ///oblic: pante egale
        if(y*xb==x*yb)
        {
            sol++;
            ya+=h;
            yb+=h;
            yc+=h;
            xa+=l;
            xb+=l;
            xc+=l;
        }
        else
        ///orizontal: panta dreptei<panta dreptunghi
        if (yb*x>y*xb and y*xc>=x*yc)
        {
            sol++;
            xa+=l;
            xb+=l;
            xc+=l;
        }
    }
    cout<<sol;
    return 0;
}