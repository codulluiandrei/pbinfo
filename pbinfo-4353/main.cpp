#include <iostream>
using namespace std;
int CB(int A[], int st, int dr, int x)
{
    if(st>dr) return 0;
    else
    {
        int mij=(st+dr)/2;
        if(A[mij]==x) return 1;
        else if(A[mij]<x) return CB(A,mij+1,dr,x);
             else return CB(A,st,mij-1,x);
    }
}
int main()
{
    int X[100001],n,m,y,a=0,b=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>X[i];
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>y;
        if(y%2==0) a=a+CB(X,1,n/2,y);
        else b=b+CB(X,n/2+1,n,y);
    }
    cout<<a<<" "<<b;
    return 0;
}