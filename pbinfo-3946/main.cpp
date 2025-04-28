#include<bits/stdc++.h>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
const int mod=1e9+7;
int dp[1000005][2];
int main(){
    dp[1][0]=1;
    dp[1][1]=0;
    dp[2][0]=1;
    dp[2][1]=1;
    int n;
    cin>>n;
    for(int i=3;i<=n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-2][1];
        if(dp[i][0]>=mod)dp[i][0]-=mod;
        dp[i][1]=dp[i-1][0]+dp[i-1][1];
        if(dp[i][1]>=mod)dp[i][1]-=mod;
    }
    cout<<dp[n][1];
    return 0;
}