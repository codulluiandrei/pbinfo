#include<bits/stdc++.h>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
const long long mod=1e9+7;
long long power(long long a,long long b,long long m){
    if(!b)return 1ll;
    long long p(power(a,b/2ll,m));
    if(b&1ll)return (((a*p)%m)*p)%m;
    return (p*p)%m;
}
int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    cout<<power(a,power(b,c,mod-1),mod);
    return 0;
}