#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n%2==m%2)
        cout<<n/10+n%10+m/10+m%10;
    else
        cout<<(n/10)*(n%10)*(m/10)*(m%10);
    return 0;
}
