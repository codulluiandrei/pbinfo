#include <iostream>
using namespace std;
int main()
{
    int a[10000],n,i,j,aux;
    cin>>n;
    for(i=1;i<=n;++i)
        cin>>a[i];
    for (i=1;i<n;++i)
        for(j=i+1;j<=n;++j)
            if (a[i]<a[j])
            {
                aux=a[i];
                a[i]=a[j];
                a[j]=aux;
            }
    i=1;
    while (i<n and a[i]==a[i+1])
        i=i+2;
    if (i>=n)
    {
        cout<<"DA";
        return 0;
    }
    i++;
    while (i<n and a[i]==a[i+1])
        i=i+2;
    if (i>n)
    {
        cout<<"DA";
        return 0;
    }
    cout<<"NU";
    return 0;
}