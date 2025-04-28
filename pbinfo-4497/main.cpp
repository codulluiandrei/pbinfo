#include <iostream>
using namespace std;
int X[32],n,nrsol,s;
void back(int k, int sp)
{
    for(int i=X[k-1]+1;i<=n;i++)
    {
        X[k]=i;
        sp=sp+X[k];
        if(sp==s/2) nrsol++;
        back(k+1,sp);
        sp=sp-X[k];
    }
}
int main()
{
    cin>>n;
    s=n*(n+1)/2;
    if(s%2==0) back(1,0);
    cout<<nrsol/2;
    return 0;
}