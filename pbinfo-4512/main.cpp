#include <iostream>
using namespace std;
int n,n1,n2,p1,p2;
int main()
{
    cin>>n;
    n1=5;
    p1=4;
    for(int i=2;i<=n;i++)
    {
       n2=(n1*6+p1*6)%666013;
       p2=n1*4%666013;
       n1=n2;
       p1=p2;
    }
    cout<<(p1+n1)%666013;
    return 0;
}