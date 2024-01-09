#include <iostream>
#include <fstream>
using namespace std;
ifstream f("smax.in");
ofstream g("smax.out");
long long a[100002],v[100002],s[100002];
int main()
{int n,i;
f>>n;
for(i=1;i<=n;i++)
    f>>v[i];
a[0]=0;
a[1]=1;
for(i=2;i<=n;i++)
    if(a[i-1]>a[i-2]+v[i])
    a[i]=a[i-1];
else a[i]=a[i-2]+v[i];
i=n;
while(i>=1)
{    if(a[i-1]>=a[i-2]+v[i])
        i--;
    else
    {
        s[i]=1;
        i=i-2;
    }
}/*
for(i=1;i<=n;i++)
    g<<v[i]<<" ";
    g<<endl;
for(i=1;i<=n;i++)
    g<<a[i]<<" ";
    g<<endl;
for(i=1;i<=n;i++)
    g<<s[i]<<" ";
    g<<endl;*/
    g<<a[n];
}
