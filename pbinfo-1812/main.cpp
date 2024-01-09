#include <iostream>
using namespace std;

int n,X[52];
char L[]="abcdefghijklmnopqrstuvwxyz";

int modul(int n)
{
    if(n<0) n=-n;
    return n;
}

void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<L[X[i]];
    cout<<'\n';
}

void back(int k)
{
    for(int i=X[k-1]-1;i<=X[k-1]+1;i=i+2)
    if(i>=0)
    {
        X[k]=i;
            if(k==n)
            {
                if(X[n]==0) afisare();
            }
            else back(k+1);
    }
}

int main()
{
    cin>>n;
    X[1]=0;
    back(2);
    return 0;
}
