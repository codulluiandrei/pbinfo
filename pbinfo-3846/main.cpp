#include<bits/stdc++.h>
using namespace std;
ifstream fin("ksum2.in");
ofstream fout("ksum2.out");
int n,k,s[100005],dp[100005][18],lg[100005],w;
int qr(int st,int dr){
    int l(lg[dr-st+1]);
    return max(dp[st][l],dp[dr-(1<<l)+1][l]);
}
int main(){
    fin>>n>>k>>w;
    for(int i=2;i<=n;i++){
        lg[i]=lg[i-1];
        if(!(i&(i-1)))lg[i]++;
    }
    for(int i=1;i<=n;i++)fin>>s[i];
    for(int i=1;i<=n;i++)s[i]+=s[i-1],dp[i][0]=s[i];
    for(int i=1;(1<<i)<=n;i++){
        for(int j=1;j+(1<<i)-1<=n;j++){
            dp[j][i]=max(dp[j][i-1],dp[j+(1<<(i-1))][i-1]);
        }
    }
    int mx(s[k]);
    for(int i=1;i<=n-k+1;i++)mx=max(mx,qr(i+k-1,min(n,i+w-1))-s[i-1]);
    fout<<mx;
    return 0;
}
