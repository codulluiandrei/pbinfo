#include <fstream>
using namespace std;

struct ora
{
    int h,m,s;
} e1,e2,e;

ifstream f("ore.in");
ofstream g("ore.out");

int main()
{
    f>>e1.h>>e1.m>>e1.s;
    f>>e2.h>>e2.m>>e2.s;
    g<<e1.h<<": "<<e1.m<<": "<<e1.s<<endl;
    g<<e2.h<<": "<<e2.m<<": "<<e2.s<<endl;
    int s,a,b;
    a=e1.h*3600+e1.m*60+e1.s;
    b=e2.h*3600+e2.m*60+e2.s;
    g<<a<<endl;
    g<<b<<endl;
    s=a+b;
    e.h=s/3600;
    s=s%3600;
    e.m=s/60;
    e.s=s%60;
    g<<e.h<<": "<<e.m<<": "<<e.s<<endl;
    return 0;
}
