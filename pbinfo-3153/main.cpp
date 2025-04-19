#include <iostream>
#include <cstring>
using namespace std;
int X[21],n,m;
char s[22];
void afis()
{
    for(int i=1;i<=m-n;i++)
        cout<<s[X[i]-1];
    cout<<"\n";
}
void back(int k)
{
    for(int i=X[k-1]+1;i<=m;i++)
    {
        X[k]=i;
        if(k==m-n) afis();
            else back(k+1);
    }
}
int main()
{
    cin>>s>>n;
    m=strlen(s);
    back(1);
    return 0;
}