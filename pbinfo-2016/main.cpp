// George Badita
#include <iostream>
#include <fstream>
#include <cmath>
#define N 110
using namespace std;
ifstream f("vuli.in");
ofstream g("vuli.out");
long long a[N],v[N],i,j,n,m,k,sol[N];
int var(long long num)
{
    int sum=0;
    while(num!=0)
    {
        sum=sum+(num%10);
        num=num/10;
    }
    int rad=sqrt(sum);
    for(int t=2;t<=rad;t++)
        if(sum%t==0)
        return 0;
    return 1;
}
int main()
{
    f>>n;
    n=n+1;
    a[1]=1;
    a[2]=1;
    for(i=3;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            v[j]=a[j]+a[j-1];
        for(j=1;j<=i;j++)
            a[j]=v[j];
    }
    if(n%2==0)
        k=n/2;
    else
        k=(n+1)/2;
    for(i=1;i<=k;i++)
    {
        if(var(a[i])==1)
            g<<a[i]<<" ";
    }
}