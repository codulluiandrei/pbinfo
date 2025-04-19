///Solutie 100p
///Moldoveanu Traian Florian Alin
#include <iostream>
#include <algorithm>
using namespace std;
int f[10];
int f1[10];
int v[101];
int main()
{
    int n,a,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        int ca=a;
        while(a>0)
        {
            f[a%10]++;
            f1[a%10]=1;
            a/=10;
        }
        int nrs=0;
        for(int j=0;j<=9;j++)
        {
            nrs+=f1[j];
            f1[j]=0;
        }
        if(nrs==2)
        {
            cnt++;
            v[cnt]=ca;
        }
    }
    int minn=501,cifmin;
    for(int i=0;i<=9;i++)
    {
        if(f[i]<minn)
        {
            minn=f[i];
            cifmin=i;
        }
    }
    cout<<cifmin<<'\n';
    for(int j=500;j>=0;j--)
    {
        for(int i=9;i>=0;i--)
            if(f[i]==j)
                cout<<i<<" ";
    }
    cout<<'\n';
    if(cnt==0)
        cout<<-1;
    else
    {
        sort(v+1,v+cnt+1);
        for(int i=1;i<=cnt;i++)
            cout<<v[i]<<" ";
    }
    return 0;
}