#include <iostream>
#include <cstring>
using namespace std;
int n,X[10];
int ok(int k)
{
    int cv=0;
    for(int i=1;i<=k;i++)
        if(strchr("AEIOU",('A'+X[i]-1))) cv++;
    if(k==n && cv<=k-cv) return 0;
    return 1;
}
void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<(char)('A'+X[i]-1);
    cout<<"\n";
}
void back(int k)
{
    for(int i=X[k-1]+1;i<=26;i++)
    {
        X[k]=i;
        if(ok(k))
            if(k==n) afisare();
            else back(k+1);
    }
}
int main()
{
    cin>>n;
    back(1);
    return 0;
}