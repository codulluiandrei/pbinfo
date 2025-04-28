#include <iostream>
using namespace std;
int prim(int n)
{
    if(n==0 || n==1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(int d=3;d*d<=n;d=d+2)
        if(n%d==0) return 0;
    return 1;
}
int sum(int A[], int s, int d)
{
    if(s==d) if(prim(A[s])) return A[s];
             else return 0;
    else
    {
        int m=(s+d)/2;
        return sum(A,s,m)+sum(A,m+1,d);
    }
}
int main()
{
    int A[1001],n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    cout<<sum(A,1,n);
    return 0;
}