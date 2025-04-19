#include <iostream>
using namespace std;
int n,A[101][101],C[101][101],x;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(A[i][j]==0) C[i][j]=C[i-1][j];
            else if(C[i-1][j-1]>C[i-1][j+1]) C[i][j]=C[i-1][j-1]+1;
			     else C[i][j]=C[i-1][j+1]+1;
    for(int j=1;j<=n;j++)
        if(C[n][j]>x)
            x=C[n][j];
    cout<<x;
    return 0;
}