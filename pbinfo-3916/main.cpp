#include <iostream>
using namespace std;
int A[25],X[25],m;
long long x,n;
long long numar()
{
    long long x=0;
    for(int i=1;i<=m;i++)
        x=x*10+A[X[i]];
    return x;
}
void back(int k)
{
    for(int i=X[k-1]+1;i<=n;i++)
        {
            X[k]=i;
            if(k==m)
            {
                long long nr=numar();
                if(nr>x) x=nr;
            }
            else back(k+1);
        }
}
int main()
{
    cin>>n>>m;
    int nc=0;
    while(n)
    {
        A[++nc]=n%10;
        n=n/10;
    }
    n=nc;
    for(int i=1,j=n;i<j;i++,j--)
        swap(A[i],A[j]);
    m=n-m;
    back(1);
    cout<<x;
    return 0;
}