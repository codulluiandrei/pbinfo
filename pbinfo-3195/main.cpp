#include <iostream>
using namespace std;
string N[105],Z[105],Q[105],R[105];
int f[200];
int main()
{
    int n,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    string c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>c;
        for(int j=0;j<c.size();j++)
        {
            f[(int)(c[j])]++;
        }
        if(f[(int)('.')]==0)
        {
            if(f[(int)('-')]==0)
            {
                cnt1++;
                N[cnt1]=c;
                cnt2++;
                Z[cnt2]=c;
                cnt3++;
                Q[cnt3]=c;
            }
            else
            {
                cnt2++;
                Z[cnt2]=c;
                cnt3++;
                Q[cnt3]=c;
            }
        }
        else
        {
            if(f[int('.')]==1)
            {
                cnt3++;
                Q[cnt3]=c;
            }
            else
            {
                cnt4++;
                R[cnt4]=c;
            }
        }
        for(int j=0;j<150;j++)
            f[j]=0;
    }
    if(cnt1==0)
        cout<<"Multime vida";
    else
    {
        for(int i=1;i<=cnt1;i++)
            cout<<N[i]<<" ";
    }
    cout<<'\n';
    if(cnt2==0)
        cout<<"Multime vida";
    else
    {
        for(int i=1;i<=cnt2;i++)
            cout<<Z[i]<<" ";
    }
    cout<<'\n';
    if(cnt3==0)
        cout<<"Multime vida";
    else
    {
        for(int i=1;i<=cnt3;i++)
            cout<<Q[i]<<" ";
    }
    cout<<'\n';
    if(cnt4==0)
        cout<<"Multime vida";
    else
    {
        for(int i=1;i<=cnt4;i++)
            cout<<R[i]<<" ";
    }
    return 0;
}