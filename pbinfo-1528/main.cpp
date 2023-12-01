#include <fstream>

using namespace std;

ifstream f("operatiimatematice.in");
ofstream g("operatiimatematice.out");

int main()
{
    int n,a,i,x,y;
    f>>n;
    f>>x;
    for(i=2;i<n;i++)
    {
        x=x*3;
        f>>y;
        x=x+y;
        a=0;
        while (a*7<=x) a++;
        a--;
        a*=7;
        x-=a;
    }
    x*=3;
    f>>y;
    x+=y;
    g<<x<<"\n";
    if (x%7==0) g<<"DA";
    else g<<"NU";
    f.close();
    g.close();
    return 0;
}
