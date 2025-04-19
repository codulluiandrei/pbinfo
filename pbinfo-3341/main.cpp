#include <iostream>
#include <fstream>
using namespace std;
ifstream f("oaste2.in");
ofstream g("oaste2.out");
int a[102][102],n,m,s,r;
void citeste()
{
    f>>n>>m;
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            f>>a[i][j];
}
void fill(int i, int j)
{
    s=s+a[i][j];
    r++;
    a[i][j]=0;
    if(a[i-1][j])fill(i-1,j);
    if(a[i][j+1])fill(i,j+1);
    if(a[i+1][j])fill(i+1,j);
    if(a[i][j-1])fill(i,j-1);
}
int main()
{
    citeste();
    int i,j, S=0, R=10001;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j])
            {
                r=0; s=0;
                fill(i,j);
                if(s>S)
                {
                    S=s; R=r;
                }
                else
                    if(s==S)R=min(R,r);
            }
    g<<S<<" "<<R<<endl;
    return 0;
}