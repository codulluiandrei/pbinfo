#include <iostream>
using namespace std;
int main()
{
    int n,A[21][21],minp=100000,maxp=-100000,mins=100000,maxs=-100000;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>A[i][j];
            if(i==j)
            {
                if(A[i][j]>maxp) maxp=A[i][j];
                if(A[i][j]<minp) minp=A[i][j];
            }
            if(i+j==n+1)
            {
                if(A[i][j]>maxs) maxs=A[i][j];
                if(A[i][j]<mins) mins=A[i][j];
            }
        }
    if(1LL*maxp*maxs>1LL*minp*mins) cout<<1LL*maxp*maxs;
    else cout<<1LL*minp*mins;
    return 0;
}