#include <iostream>
using namespace std;
int n,m,X[45],gasit;
void afisare()
{
    for(int i=1;i<=n+m;i++)
        if(X[i]==0) cout<<'E';
        else cout<<'M';
    cout<<"\n";
    gasit=1;
}
int ok(int k)
{
    int s=0;
    for(int i=1;i<=k;i++)
        s=s+X[i];
    if(s>m || k-s>n) return 0;
    if(k>2 && X[k-2]==X[k-1] && X[k]==X[k-1])
        return 0;
    return 1;
}
void back(int k)
{
    for(int i=0;i<=1;i++)
    {
        X[k]=i;
        if(ok(k))
            if(k==m+n) afisare();
            else back(k+1);
    }
}
int main()
{
    cin>>n>>m;
    back(1);
    if(!gasit) cout<<"IMPOSIBIL";
    return 0;
}