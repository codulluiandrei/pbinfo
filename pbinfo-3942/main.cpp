#include <iostream>
using namespace std;
string S[32];
int X[32],n,m,P[32],gasit;

void afisare()
{
    for(int i=1;i<=m;i++)
        cout<<S[X[i]]<<" ";
    cout<<endl;
    gasit=1;
}

int ok(int k)
{
    if(k>1 && S[X[k]].substr(0,2)!=S[X[k-1]].substr(S[X[k-1]].length()-2))
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
                if(k==m) afisare();
                else back(k+1);
            P[i]=0;
        }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>S[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            if(S[i]>S[j])
                swap(S[i],S[j]);
    back(1);
    if(!gasit) cout<<"IMPOSIBIL";
    return 0;
}
