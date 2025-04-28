#include <iostream>
using namespace std;
int main()
{
    int n,e=1,c=1,d=1;
    cin>>n;
    while(n>9)
    {
        if(n%10==n/10%10) { c=0; d=0; }
        else if(n%10>n/10%10) { e=0; d=0; }
        else { e=0; c=0; }
        n=n/10;
    }
    if(e==1) cout<<"egale";
    else if(c==1) cout<<"strict crescatoare";
         else if(d==1) cout<<"strict descrescatoare";
              else cout<<"neordonate";
    return 0;
}