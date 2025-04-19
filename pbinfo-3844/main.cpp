#include<bits/stdc++.h>
using namespace std;
ifstream fin("ksum.in");
ofstream fout("ksum.out");
int n,k,s[100005],m[100005];
int main(){
    fin>>n>>k;
    for(int i=1;i<=n;i++)fin>>s[i];
    for(int i=1;i<=n;i++)s[i]+=s[i-1];
    int mx(s[k]);
    m[n]=s[n];
    for(int i=n-1;i>=1;i--)m[i]=max(m[i+1],s[i]);
    for(int i=1;i<=n-k+1;i++)mx=max(mx,m[i+k-1]-s[i-1]);
    fout<<mx;
    return 0;
}