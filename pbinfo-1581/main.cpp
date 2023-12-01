#include <fstream>

using namespace std;
ifstream fin("max_suma.in");
ofstream fout("max_suma.out");
int n,m,i,j,s,x,Max;
int main()
{
    fin>>n>>m;
    for (i=1; i<=n; i++) {
        s=0;
        Max=0;
        for (j=1; j<=m; j++) {
            fin>>x;
            if (Max<x) Max=x;
            s+=x;
        }
        fout<<Max<<' '<<s<<endl;
    }
    return 0;
}