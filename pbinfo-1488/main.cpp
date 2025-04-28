#include <fstream>
#include <iomanip>
using namespace std;
ifstream f("strazi.in");
ofstream g("strazi.out");
int n,m;
float a[1001];
int main()
{
    int i,j,t,st;
    float x,x1,x2=0;
    f>>n;
    for (j=1;j<=n;j++)
       {
        f>>m;
        for (i=1;i<=m;i++) f>>a[i];
        t=1;
        x=a[1];
        for (i=1;i<=m;i++)
            if (a[i]>x) { t++; x=a[i];};
        x1=(float)t/m;
        if (x1>x2){ x2=x1; st=j;}
        g<<fixed<<setprecision (3)<<x1<<"\n";
       }
      g<<st;
      f.close();
      g.close();
    return 0;
}