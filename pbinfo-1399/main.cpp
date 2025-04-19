#include <iostream>
using namespace std;
int main()
{
    int a[100000],n,i,j,aux;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for (i=1;i<n;++i)
        for(j=i+1;j<=n;++j)
            if ((a[i]>=0 and a[j]<0) or
                (a[i]>0 and a[j]==0) or
                (a[i]*a[j]>0 and a[i]<a[j]))
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
    for (i=1;i<=n;++i)
        cout<<a[i]<<" ";
    return 0;
}