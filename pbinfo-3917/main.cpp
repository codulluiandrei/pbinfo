#include <iostream>
using namespace std;
int n,X[12],F[5],m;
void afisare()
{
    for(int i=1;i<=m;i++)
        cout<<X[i];
    cout<<"\n";
}
void back(int k)
{
    for(int i=1;i<=n;i++)
        if(F[i])
        {
            X[k]=i;
            F[i]--;
            if(k==m) afisare();
            else back(k+1);
            F[i]++;
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        F[i]=i;
    m=n*(n+1)/2;
    back(1);
    return 0;
}