#include <iostream>
using namespace std;
int main()
{
    int n,k,cer;
    cin>>cer>>n>>k;
    if(cer==1)
        cout<<2*n-1;
    else
        cout<<1+2*(n-k);
    return 0;
}