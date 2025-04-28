#include <iostream>
using namespace std;
int main()
{
    int n,A[26][26];
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==1) A[i][j]=j;
            else if(j==1) A[i][j]=i;
                 else A[i][j]=A[i-1][j]+A[i][j-1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}