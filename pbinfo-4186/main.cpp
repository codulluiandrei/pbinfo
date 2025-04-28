#include <bits/stdc++.h>
using namespace std;
long Monede(int s, vector<long> c)
{
    int l=c.size();
    long x;
    vector<long>ar;
    for(int i=0; i<=s; i++)
        ar.push_back(0);
    ar[0]=1;
    for(int i=0; i<l; i++)
    {
        x=c[i];
        for(int j=x; j<=s; j++)
        {
            if(ar[j-x]!=0)ar[j]+=ar[j-x];
        }
    }
    return ar[s];
}
int main()
{
    int n,s,i,x;
    cin>>s>>n;
    vector<long> c;
    for(i=0; i<n; i++)
    {
        cin>>x;
        c.push_back(x);
    }
    cout<<Monede(s, c);
    return 0;
}