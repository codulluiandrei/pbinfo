#include <iostream>
using namespace std;

int X[31],c0,c1,n;

void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<X[i];
    cout<<"\n";
}

int ok(int k)
{
    int cc0=0,cc1=0;
    for(int i=1;i<=k;i++)
        if(X[i]==0) cc0++;
        else cc1++;
    if(cc0>c0 || cc1>c1) return 0;
    return 1;
}

void back(int k)
{
    for(int i=0;i<=1;i++)
    {
        X[k]=i;
        if(ok(k))
        {
            if(k==n) afisare();
            else back(k+1);
        }
    }
}

int main()
{
    cin>>n;
    while(n)
    {
        if(n%2) c1++;
        else c0++;
        n=n/2;
    }
    n=c0+c1;
    back(1);
    return 0;
}
