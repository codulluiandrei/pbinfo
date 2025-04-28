#include <iostream>
using namespace std;
int a,b,c,n,X[16];
void afisare()
{
    char s[]=" CIP";
    for(int i=1;i<=n;i++)
        cout<<s[X[i]];
    cout<<"\n";
}
int valid(int k)
{
    if(X[1]!=1) return 0;
    if(k==n && X[k]!=3) return 0;
    if(k>=3 && X[k-2]==1 && X[k-1]==2 && X[k]==1) return 0;
    int ci=0,cp=0,cc=0;
    for(int i=1;i<=k;i++)
        if(X[i]==1) cc++;
        else if(X[i]==2) ci++;
            else cp++;
    if(cc>a || ci>b || cp>c) return 0;
    return 1;
}
void back(int k)
{
    for(int i=1;i<=3;i++)
    {
        X[k]=i;
        if(valid(k))
            if(k==n) afisare();
            else back(k+1);
    }
}
int main()
{
    cin>>a>>b>>c;
    n=a+b+c;
    back(1);
    return 0;
}