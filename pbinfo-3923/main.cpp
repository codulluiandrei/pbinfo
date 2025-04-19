#include <iostream>
using namespace std;
int n,X[11],m,P[27];
char s[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void afisare()
{
    for(int i=1;i<=m;i++)
        cout<<s[X[i]-1];
    cout<<"\n";
}
void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
    {
        X[k]=i;
        P[i]=1;
        if(k==m) afisare();
        else back(k+1);
        P[i]=0;
    }
}
int main()
{
    cin>>n>>m;
    back(1);
    return 0;
}