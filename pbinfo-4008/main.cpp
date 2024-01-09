#include <iostream>
using namespace std;

int n,X[11],P[10];

int ok(int k)
{
    if(X[1]==0) return 0;
    int cp=0;
    for(int i=1;i<=k;i++)
        if(X[i]%2==0) cp++;
    if(k==n && cp<=k-cp) return 0;
    return 1;
}

void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<X[i];
    cout<<"\n";
}

void back(int k)
{
    for(int i=0;i<=9;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            if(ok(k))
                if(k==n) afisare();
                else back(k+1);
            P[i]=0;
        }
}

int main()
{
    cin>>n;
    back(1);
    return 0;
}
