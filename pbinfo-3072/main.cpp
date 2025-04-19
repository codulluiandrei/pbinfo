#include <iostream>
using namespace std;
int main()
{
    int n,a,b,c,r;
    cin>>n;
    r=n%3;
    a=b=c=n/3;
    if(r==1)c++;
    else if(r==2)b=c=a+1;
    cout<<a<<" "<<b<<" "<<c;
    return 0;
}