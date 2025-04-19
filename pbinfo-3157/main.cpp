#include <iostream>
using namespace std;
int X[21],c1,c2,n;
void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<X[i];
    cout<<"\n";
}
int ok(int k)
{
    int cc1=0,cc2=0;
    for(int i=1;i<=k;i++)
        if(X[i]==c1) cc1++;
        else cc2++;
    if(cc1>c2 || cc2>c1) return 0;
    return 1;
}
void back(int k)
{
    for(int i=c1;i<=c2;i++)
    {
        X[k]=i;
        if(ok(k))
        {
            if(k==n) afisare();
            else back(k+1);
        }
    }
}
int main()
{
    cin>>c1>>c2;
    if(c1>c2) swap(c1,c2);
    n=c1+c2;
    back(1);
    return 0;
}