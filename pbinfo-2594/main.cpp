#include <bits/stdc++.h>
using namespace std;

int isEven(int n)
{
    return !(n%2);
}

int main()
{
    vector<int> v;
    vector<int>::iterator it,bound;
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x,v.push_back(x);
    bound=partition(v.begin(),v.end(),isEven);
    sort(v.begin(),bound);
    sort(bound,v.end());
    for(it=v.begin();it<bound;it++)
        cout<<*it<<" ";
    for(it=bound;it<v.end();it++)
        cout<<*it<<" ";
}
