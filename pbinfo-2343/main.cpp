#include<fstream>
#include <cmath>
using namespace std;
ifstream f("bec.in");
ofstream g("bec.out");
int n,a[151][151],k,m,cer;
void citeste()
{
    int i,x,y,c;
    f>>cer>>n>>m>>k;
    for(i=1; i<=k; i++)
    {
        f>>x>>y>>c;
        a[x][y]=c;
    }
    f.close();
}
int cmmdc(int x, int y)
{
    if (x*y==0) return x+y;
    if(x>y) return cmmdc(x%y, y);
    else return cmmdc(x,y%x);
}
int nrr(int x, int y)
{
    int p=0,i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if ((a[i][j]==0)&& (cmmdc(abs(x-i), abs(y-j))==1)) p++;
    return p;
}
int main()
{
    citeste();
    int i,j, max=0, cmin, x,i0=0,j0=0;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i][j])
            {
                x=nrr(i,j);
                if (max==0)
                {
                    max=x;
                    cmin=a[i][j];
                    i0=i;
                    j0=j;
                }
                else if (max<x)
                {
                    max=x;
                    cmin=a[i][j];
                    i0=i;
                    j0=j;
                }
                else if((max==x)&&(cmin>a[i][j]))
                {
                    cmin=a[i][j];
                    i0=i;
                    j0=j;
                }
            }
    if(cer==1)g<<max<<endl;
    else g<<i0<<' '<<j0<<endl;
    g.close();
    return 0;
}