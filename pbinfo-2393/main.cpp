#include <fstream>
using namespace std;
ifstream fin("sumaxxl.in");
ofstream fout("sumaxxl.out");
int x[105],y[105];
int main()
{
    int i, n, m, r=0;
    fin>>n;
    for(i=n; i>=1; i--)
    {
        fin>>x[i];
    }
    fin>>m;
    for(i=m; i>=1; i--)
    {
        fin>>y[i];
    }
    if(n<m)
    {
        n=m;
    }
    for(i=1; i<=n ; i++)
    {
        r=x[i]+y[i]+r;
        x[i]=r%10;
        r/=10;
    }
    while(r>0)
    {
        n++;
        x[n]=r%10;
        r=r/10;
    }
    for(i=n; i>=1; i--)
    {
        fout<<x[i];
    }
    fin.close();
    fout.close();
    return 0;
}