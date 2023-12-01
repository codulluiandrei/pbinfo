/*solutie oficiala */
#include <iostream>
using namespace std;
int n,s1,i,p,s;
int main()
{
    cin>>n;
    i=1;
    p=9;
    while(s1+i*p<n)
    {
        s+=p;
        s1+=i*p;
        i++;
        p*=10;
    }
    s+=(n-s1)/i;
    cout<<s;
    return 0;
}
