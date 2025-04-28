#include <iostream>
using namespace std;
int main()
{
    int A[102][102],n,maxN=0,maxE=0,maxS=0,maxV=0,in=0,jn=0,ie=0,je=0,is=0,js=0,iv=0,jv=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i<j && i+j<n+1 && A[i][j]>maxN) { maxN=A[i][j]; in=i; jn=j; }
            if(i<j && i+j>n+1 && A[i][j]>maxE) { maxE=A[i][j]; ie=i; je=j; }
            if(i>j && i+j>n+1 && A[i][j]>maxS) { maxS=A[i][j]; is=i; js=j; }
            if(i>j && i+j<n+1 && A[i][j]>maxV) { maxV=A[i][j]; iv=i; jv=j; }
        }
    A[ie][je]=maxN;
    A[is][js]=maxE;
    A[iv][jv]=maxS;
    A[in][jn]=maxV;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}