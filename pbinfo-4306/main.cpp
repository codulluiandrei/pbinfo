#include <iostream>
using namespace std;
int D[100002],P[10000],np,E[100001],n,A[10001],m;
int expfact(int n, int x)
{
    int c=0;
    while(n>0)
    {
        c=c+n/x;
        n=n/x;
    }
    return c;
}
void ciur_prime(int n)
{
    for(int i=2;i<=n;i++)
        E[i]=1;
    for(int i=2;i*i<=n;i++)
        if(E[i])
            for(int j=i;j*i<=n;j++)
                E[i*j]=0;
    for(int i=2;i<=n;i++)
        if(E[i])
            P[++np]=i;
}
void produs(int A[], int &n, int x)
{
    int t=0;
    for(int i=1;i<=n;i++)
    {
        int c=A[i]*x+t;
        A[i]=c%10;
        t=c/10;
    }
    while(t>0)
    {
        A[++n]=t%10;
        t=t/10;
    }
}
int main()
{
    cin>>n;
    ciur_prime(n);
    for(int i=1;i<=np;i++)
        D[P[i]]=D[P[i]]+expfact(n,P[i]);
    m=1;
    A[1]=1;
    for(int i=1;i<=np;i++)
        produs(A,m,D[P[i]]+1);
    for(int i=m;i>=1;i--)
        cout<<A[i];
    return 0;
}