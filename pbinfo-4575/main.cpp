#include <iostream>
using namespace std;
int main()
{
    int a,b,n;
    long long s=0;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        n=i;
        int x=0,p=1;
        while(n>0)
        {
            if(n%2==1)
            {
                x=x+n%10*p;
                p=p*10;
            }
            n=n/10;
        }
        if(x!=0 && i%x==0)  s=s+i;
    }
    cout<<s;
    return 0;
}