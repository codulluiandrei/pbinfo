/* Adrian Panaete - 100 puncte */
#include <bits/stdc++.h>
using namespace std;
void solve(),afisare(char,vector<int>&,vector<int>&);
int p,t,n,balans(string);
bool ok;
int main()
{
    cin>>p>>t;
    for(;t;t--)solve();
    return 0;
}
void solve()
{
    ok=true;
    cin>>n;
    string s,L,C,LN;
    cin>>L;
    LN=L;
    for(auto &it:LN)it='1'-it+'0';
    C.push_back(L[0]);
    for(int i=1;i<n;i++)
    {
        cin>>s;
        C.push_back(s[0]);
        if(s==L||s==LN)
            continue;
        ok=false;
    }
    if(balans(L)||balans(C))ok=false;
    if(p==1){cout<<ok<<'\n';return;}
    vector<int> a[2][2],b[2][2];
    for(int i=0;i<n;i++)
        a[i%2][int(L[i]-'0')].push_back(i+1);
    for(int i=0;i<n;i++)
        b[i%2][int(C[i]-'0')].push_back(i+1);
    cout<<min(a[0][0].size(),a[0][1].size())+min(b[0][0].size(),b[0][1].size())<<'\n';
    if(p==2)return;
    if(a[0][0].size()<a[0][1].size())
        afisare('C',a[0][0],a[1][1]);
    else
        afisare('C',a[0][1],a[1][0]);
    if(b[0][0].size()<b[0][1].size())
        afisare('L',b[0][0],b[1][1]);
    else
        afisare('L',b[0][1],b[1][0]);
}
int balans(string w)
{
    int ret=0;
    for(auto it:w)if(it=='0')ret--;else ret++;
    return ret;
}
void afisare(char ch,vector<int> &X,vector<int> &Y)
{
    int k=X.size();
    for(int i=0;i<k;i++)
        cout<<ch<<' '<<X[i]<<' '<<Y[i]<<'\n';
}