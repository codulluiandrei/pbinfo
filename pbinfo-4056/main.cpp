#include <iostream>

using namespace std;

int main()
{
    int n,v[21];
    cin>>n;
    for(int i=1; i<=n; i++)
    cin>>v[i];
    for(int i=1; i<=n; i++)
    {
        if(i%2==1)
        for(int j=0; j<v[i]; j++)
        {
            for(int k=0; k<v[i]; k++)
            cout<<(j+k)%v[i]<<" ";
            cout<<endl;
        }
        else
        for(int j=0; j<v[i]; j++)
        {
            for(int k=0; k<v[i]; k++)
            cout<<(j*k)%v[i]<<" ";
            cout<<endl;
        }
    }
    return 0;
}