#include<bits/stdc++.h>
using namespace std;
int n,k,w;
long long s[1000005];
deque<int>q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>k>>w;
    for(int i=1;i<=n;i++)cin>>s[i],s[i]+=s[i-1];
    long long mx(s[k]);
    for(int i=k;i<=n;i++){
        if(q.front()==i-w-1)q.pop_front();
        while(!q.empty()&&s[q.back()]>s[i-k])q.pop_back();
        q.push_back(i-k);
        mx=max(mx,s[i]-s[q.front()]);
    }
    cout<<mx;
    return 0;
}
