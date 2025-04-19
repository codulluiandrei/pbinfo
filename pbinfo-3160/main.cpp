#include <iostream>
using namespace std;
int X[11],n,A[11],c;
void afisare()
{
    for(int i=1;i<=c;i++)
        cout<<A[X[i]];
    cout<<"\n";
}
void back(int k)
{
    for(int i=n;i>=1;i--)
    {
        X[k]=i;
        if(A[X[1]]>0 && X[k]>X[k-1])
        {
            if(k==c) afisare();
            else back(k+1);
        }
    }
}
int main()
{
    cin>>n>>c;
    int nc=0;
    while(n>0)
    {
        A[++nc]=n%10;
        n=n/10;
    }
    n=nc;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(A[i]>A[j])
                swap(A[i],A[j]);
    back(1);
    return 0;
}