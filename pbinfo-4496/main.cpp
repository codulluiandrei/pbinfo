#include <iostream>
#include <cmath>
using namespace std;
int n,X[101],P[101],gata,m;
void afisare()
{
    for(int i=1;i<=m;i++)
        cout<<X[i]<<" ";
    gata=1;
}
void back(int k)
{
    for(int i=1;i<=n && !gata;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            if(k==1 || sqrt(X[k]+X[k-1])==floor(sqrt(X[k]+X[k-1])))
            {
                if(k==m)
                {
                    if(sqrt(X[1]+X[m])==floor(sqrt(X[1]+X[m]))) afisare();
                }
                else back(k+1);
            }
            P[i]=0;
        }
}
int main()
{
    cin>>n>>m;
    back(1);
    if(!gata) cout<<"nu exista";
    return 0;
}