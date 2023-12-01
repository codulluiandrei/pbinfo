#include <iostream>

using namespace std;
int ap[200];
int i,n,a;
long long tt;
int sumcif(int x)
{
    int ret=0;
    while(x)ret+=x%10,x/=10;
    return ret;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a;
        tt+=ap[sumcif(a)];
        ap[sumcif(a)]++;
    }
    cout<<tt;
    return 0;
}
