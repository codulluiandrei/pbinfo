#include <iostream>
using namespace std;
int n;
char a,b,X[20];
void back(int k)
{
    for(char i=X[k-1]+1;i<=b;i++)
    {
        X[k]=i;
        if(k==n) cout<<X+1<<"\n";
        else back(k+1);
    }
}
int main()
{
    cin>>a>>b>>n;
    X[0]=a-1;
    back(1);
    return 0;
}