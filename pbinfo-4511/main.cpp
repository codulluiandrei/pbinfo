#include <fstream>
using namespace std;
ifstream cin("divnoua.in");
ofstream cout("divnoua.out");
int n,k,F[9],A[9][100001],mod=666013,x;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        F[x%9]++;
    }
    for(int i=0;i<9;i++)
        A[i][1]=F[i];
    for(int i=2;i<=k;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int c=0;c<9;c++)
                A[(j+c)%9][i]=(A[(j+c)%9][i]+A[j][i-1]*F[c])%mod;
        }
    }
    /*for(int i=0;i<9;i++)
    {
        for(int j=1;j<=k;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<A[0][k];
    return 0;
}