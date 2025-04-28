#include <iostream>
using namespace std;
int main()
{
    int n,max=0;
    cin>>n;
    while(n>9)
    {
        int a=n%100;
        if(a>max) max=a;
        a=a%10*10+a/10;
        if(a>max) max=a;
        n=n/10;
    }
    cout<<max;
    return 0;
}