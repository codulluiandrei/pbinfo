#include <iostream>
using namespace std;
int main()
{
    long long n;
    int sc=0, pcif=0;
    cin>>n;
    if(n==0){ cout<<"NU"; return 0;}
    while(n>=10)
    {
        sc=sc+n%10;
        n=n/10;
    }
    pcif=n;
    if(pcif==sc) cout<<"DA";
    else cout<<"NU";
    return 0;
}