#include <iostream>
#define castor 1000000
using namespace std;
bool x;
long long n,nr;
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>x;
        if (x==1)
            nr++;
    }
    cout<<((nr-1)*nr)/2;
    return 0;
}
