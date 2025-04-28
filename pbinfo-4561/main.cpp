#include <iostream>
using namespace std;
int main()
{
    int n,x;
    long long s=0,min=1000000,max=0,c1=0,c2=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        s=s+x;
        if(x>max) { max=x; c1=1; }
        else if(x==max) c1++;
        if(x<min) { min=x; c2=1; }
        else if(x==min) c2++;
    }
    if(min!=max)
        cout<<s-c1*max-c2*min;
    else
        cout<<0;
    return 0;
}