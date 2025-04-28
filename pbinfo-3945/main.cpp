#include <iostream>
#include <cstring>
using namespace std;
char S[32][22];
int X[32],n,P[32],kmax,Y[32];
void afisare()
{
    for(int i=1;i<=kmax;i++)
        cout<<S[Y[i]]<<" ";
}
int ok(int k)
{
    if(k>1 && strncmp(S[X[k]],S[X[k-1]]+strlen(S[X[k-1]])-2,2)!=0)
        return 0;
    return 1;
}
void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            if(ok(k))
            {
                if(k>kmax)
                {
                    kmax=k;
                    for(int i=1;i<=k;i++)
                        Y[i]=X[i];
                }
                back(k+1);
            }
            P[i]=0;
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>S[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(strcmp(S[i],S[j])>0)
                swap(S[i],S[j]);
    back(1);
    afisare();
    return 0;
}