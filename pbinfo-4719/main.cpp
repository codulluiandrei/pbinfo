#include <iostream>
using namespace std;
int main()
{
    int n,maxp=-1, mini=10,c;
    cin>>n;
    if(n==0) maxp=0, mini=-1;
    while(n!=0)
    {
        c=n%10;
        if(c%2==0 && maxp<c) maxp=c;
        if(c%2==1 && mini>c) mini=c;
        n=n/10;
    }
    if(mini==10) mini=-1;
    cout<<maxp<<" "<<mini;
    return 0;
}