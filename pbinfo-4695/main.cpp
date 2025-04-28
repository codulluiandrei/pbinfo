#include <iostream>
using namespace std;
int main()
{
    int n,A[22][22];
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
    for(int i=1;i<=n;i++)
    {
        int max=-1000000000;
        for(int j=1;j<=n;j++)
            if((i==j || i+j==n+1) && A[i][j]>max)
                max=A[i][j];
        cout<<max<<endl;
    }
    return 0;
}