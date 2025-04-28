#include <iostream>
using namespace std;
int main()
{
    int A[31][31],n;
    cin>>n;
    for(int i=n;i>=1;i--)
        for(int j=n;j>=1;j--)
            if(i==n || j==n) A[i][j]=1;
            else A[i][j]=A[i+1][j]+A[i][j+1]+A[i+1][j+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}