#include <iostream>
using namespace std;
int A[11],X[11],n,pmin,P[11];
void afisare()
{
    for(int i=1;i<=n;i++)
        cout<<A[X[i]]<<" ";
    cout<<"\n";
}
int ok(int k)
{
    if(k==pmin && X[k]!=k) return 0;
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
                if(k==n) afisare();
                else back(k+1);
            }
            P[i]=0;
        }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
    //calculez pmin
    pmin=1;
    int min=A[1];
    for(int i=2;i<=n;i++)
        if(A[i]<min) { min=A[i]; pmin=i; }
    //ordonez crescator a.i. min sa nu se miste
    for(int i=1;i<=n;i++)
        if(i!=pmin)
            for(int j=i+1;j<=n;j++)
                if(j!=pmin)
                    if(A[i]>A[j])
                        swap(A[i],A[j]);
    back(1);
    return 0;
}