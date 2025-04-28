#include <iostream>
using namespace std;
int main()
{
    int n,s=0,p=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        s=s+p*(n+1-i);
        p=p*4;
    }
    cout<<s;
    return 0;
}