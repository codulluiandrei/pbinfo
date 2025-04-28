#include <iostream>
using namespace std;
int main()
{
    int n,m,A[102][102]={0},c=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>A[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(A[i][j]>A[i-1][j]+A[i+1][j]+A[i][j-1]+A[i][j+1])
                c++;
    cout<<c;
    return 0;
}