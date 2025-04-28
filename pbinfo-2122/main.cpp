#include <fstream>
#include <cmath>
using namespace std;
int main()
{
    ifstream fin("diferenta.in");
    ofstream fout("diferenta.out");
    int n,m,a,d,i,j,nr;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            fin>>a;
            nr=0;
            for(d=1;d<=sqrt(a);d++)
                if(a%d==0&&(d+a/d)%2==0)
                    nr++;
            fout<<nr<<' ';
        }
        fout<<'\n';
    }
    return 0;
}