#include <iostream>
using namespace std;
int n,X[22];
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        cout<<X[i]<<" ";
    cout<<'\n';
}
void back(int k)
{
    for(int i=X[k-1]+1;i<=n;i++)
    {
        X[k]=i;
        if(k%2==1) afisare(k);
        back(k+1);
    }
}
int main()
{
    cin>>n;
    back(1);
    return 0;
}