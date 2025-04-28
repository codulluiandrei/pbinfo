#include <iostream>
using namespace std;
int main()
{
    int n,m,A[22][22],smax=0;
    cin>>m>>n;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
    for(int i=1;i<m;i++)
        for(int j=1;j<n;j++)
            if(A[i][j]+A[i][j+1]+A[i+1][j]+A[i+1][j+1]>smax)
                smax=A[i][j]+A[i][j+1]+A[i+1][j]+A[i+1][j+1];
    cout<<smax;
    return 0;
}