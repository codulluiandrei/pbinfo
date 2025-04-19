#include <fstream>
using namespace std;
ifstream fin("gradk.in");
ofstream fout("gradk.out");
int n,k,A[101][101],gk;
int grad(int v)
{
    int c=0;
    for(int i=1;i<=n;i++)
        if(A[v][i]) c++;
    return c;
}
int main()
{
    fin>>n>>k;
    int x,y;
    while(fin>>x>>y)
        A[x][y]=A[y][x]=1;
    for(int i=1;i<=n;i++)
        if(grad(i)==k) gk++;
    if(gk)
    {
        fout<<gk<<" ";
        for(int i=1;i<=n;i++)
            if(grad(i)==k) fout<<i<<" ";
    }
    else fout<<"NU EXISTA";
    return 0;
}