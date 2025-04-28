#include <fstream>
using namespace std;
int n;
int c[100000],m[100000];
int cmmdc(int a, int b)
{
    int r=a%b;
    while(r!=0)
    {
        a=b;b=r;
        r=a%b;
    }
    return b;
}
int main()
{
    int i,x,y;
    ifstream f("pachete2.in");
    ofstream g("pachete2.out");
    f>>n;
    f>>x;
    for(i=1;i<n;i++)
    {
        f>>y;
        c[i]=cmmdc(x,y);
        x=y;
    }
    f.close();
    m[1]=0;
    m[2]=c[1];
    for(i=3;i<=n;i++)
        m[i]=max(m[i-1],m[i-2]+c[i-1]);
    g<<m[n];
    g.close();
    return 0;
}