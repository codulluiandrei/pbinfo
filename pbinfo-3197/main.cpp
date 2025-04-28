#include <iostream>
using namespace std;
int n,X[100];
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        cout<<X[i]<<" ";
    cout<<"\n";
}
void back(int k, int sp)
{
    for(int i=X[k-1]+1;i<=(k==1?n:X[k-1]+3);i++)
    {
        X[k]=i;
        sp=sp+X[k];
        if((k==1 || X[k]-X[k-1]<=2) && sp<=n)
        {
            if(sp==n) afisare(k);
            else back(k+1,sp);
        }
        sp=sp-X[k];
    }
}
int main()
{
    cin>>n;
    back(1,0);
    return 0;
}