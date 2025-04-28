#include <iostream>
using namespace std;
int n,P[101],X[101],np;
int prim(int n)
{
    if(n==0 || n==1) return 0;
    if(n%2==0 && n>2) return 0;
    for(int d=3;d*d<=n;d=d+2)
        if(n%d==0)
            return 0;
    return 1;
}
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        cout<<P[X[i]]<<" ";
    cout<<"\n";
}
void back(int k, int sp)
{
    //for(int i=X[k-1]+1;i<=np && P[i]<=n-sp;i++)
    for(int i=1;i<=np && P[i]<=n-sp;i++)
    {
        X[k]=i;
        sp=sp+P[X[k]];
        if((k==1 || X[k-1]<=X[k]) && sp<=n)
        if(sp<=n)
            if(sp==n) afisare(k);
            else back(k+1,sp);
        sp=sp-P[X[k]];
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        if(prim(i)) P[++np]=i;
    back(1,0);
    return 0;
}