#include<bits/stdc++.h>
using namespace std;
struct in{
    int st,dr,ind;
}v[200005];
int n;
bool r[200005][2];
bool cmp(in a,in b){
    return a.st<b.st||(a.st==b.st&&a.dr>b.dr);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].st>>v[i].dr;
        v[i].ind=i;
    }
    sort(v+1,v+n+1,cmp);
    int mx(0),mn(1e9+7);
    for(int i=n;i>=1;i--){
        r[v[i].ind][0]=(bool)(mn<=v[i].dr);
        mn=min(mn,v[i].dr);
    }
    for(int i=1;i<=n;i++){
        r[v[i].ind][1]=(bool)(mx>=v[i].dr);
        mx=max(mx,v[i].dr);
    }
    for(int i=0;i<=1;i++,cout<<"\n")for(int j=1;j<=n;j++)cout<<r[j][i]<<" ";
    return 0;
}