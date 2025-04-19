#include<bits/stdc++.h>
using namespace std;
long long int n,v[2001], x , k , b , a , nr = 0 , c , cnt = 0;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    cin>>x>>k;
    for(int i=1;i<=n;i++)
    {
        if(v[i]==x && nr==0)
        {
            a=i;
            nr++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==x)
        {
            b=i;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==x && cnt<k)
        {
            c=i;
            cnt++;
        }
    }
    if(nr==0) cout<<‘0’<<endl<<‘0’<<endl;
    else cout<<a<<endl<<b<<endl;
    if(cnt<k) cout<<‘0’;
    else cout<<c;
}