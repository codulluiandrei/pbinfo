#include <iostream>
using namespace std;

int X[13],P[13],n;

void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<X[i]<<" ";
    cout<<"\n";
}

void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            if(k<=n/2 || X[n/2+1]==n)
            {
                if(k==n) afisare();
                else back(k+1);
            }
            P[i]=0;
        }
}

int main()
{
    cin>>n;
    back(1);
    return 0;
}
