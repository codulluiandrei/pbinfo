#include <iostream>
using namespace std;
void citire(int A[][101], int &n)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>A[i][j];
}
void maxime(int A[][101], int n, int &maxN, int &maxE, int &maxS, int &maxV)
{
    maxN=0,maxE=0,maxS=0,maxV=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i<j && i+j<n+1 && A[i][j]>maxN) maxN=A[i][j];
            if(i<j && i+j>n+1 && A[i][j]>maxE) maxE=A[i][j];
            if(i>j && i+j>n+1 && A[i][j]>maxS) maxS=A[i][j];
            if(i>j && i+j<n+1 && A[i][j]>maxV) maxV=A[i][j];
        }
}
int cmmdc(int a, int b)
{
    while(b!=0)
    {
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int A[101][101],n,maxN,maxE,maxS,maxV;
    citire(A,n);
    maxime(A,n,maxN,maxE,maxS,maxV);
    cout<<cmmdc(cmmdc(maxN,maxE),cmmdc(maxS,maxV));
    return 0;
}