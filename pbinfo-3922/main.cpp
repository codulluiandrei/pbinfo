#include <iostream>
using namespace std;

int n,X[11],m;
char s[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void afisare()
{
    for(int i=1;i<=m;i++)
        cout<<s[X[i]-1];
    cout<<"\n";
}

void back(int k)
{
    for(int i=X[k-1]+1;i<=n;i++)
    {
        X[k]=i;
        if(k==m) afisare();
        else back(k+1);
    }
}

int main()
{
    cin>>n>>m;
    back(1);
    return 0;
}
