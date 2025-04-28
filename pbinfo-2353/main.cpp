//Cretu Constantin
#include <fstream>
using namespace std;
ifstream fin("padure.in");
ofstream fout("padure.out");
int n,m,c,l1,c1,l2,c2,i,j,k,s,smax;
int a[102][102];
int prim(int x)
{
    int i;
    for(i=2;i*i<=x;i++)
        if(x%i==0)
        return 0;
    return x>1;
}
int main()
{
    fin>>n>>m>>c;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            fin>>a[i][j];
            a[i][j]=a[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        }//a[i][j] este suma tuturor elementelor din zona determinata de primul element si cel curent
    for(k=0;k<c;k++)
    {
        fin>>l1>>c1>>l2>>c2;
        s=a[l2][c2]-a[l2][c1-1]-a[l1-1][c2]+a[l1-1][c1-1];//suma tuturor elementelor din zona determ de elem a[l1][c1] si a[l2][c2]
        if(s>smax)
            if(prim(s))
            smax=s;
    }
    fout<<smax;
    return 0;
}