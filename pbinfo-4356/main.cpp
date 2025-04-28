#include <iostream>
using namespace std;
int scresc(int A[], int st, int dr)
{
    if(st>=dr) return 1;
    else
    {
        int mij=(st+dr)/2;
        return scresc(A,st,mij) && scresc(A,mij+1,dr) && A[mij]<A[mij+1];
    }
}
int sdesc(int A[], int st, int dr)
{
    if(st>=dr) return 1;
    else
    {
        int mij=(st+dr)/2;
        return sdesc(A,st,mij) && sdesc(A,mij+1,dr) && A[mij]>A[mij+1];
    }
}
int main()
{
    int A[1001],n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    if(scresc(A,1,n)) cout<<"strict crescator";
    else if(sdesc(A,1,n)) cout<<"strict descrescator";
         else cout<<"neordonat";
    return 0;
}