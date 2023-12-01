#include<bits/stdc++.h>
using namespace std;
ifstream fin("mman.in");
ofstream fout("mman.out");
long long n,x[100005],mn;
pair<long long,long long>v[100005];
int main(){
    mn=1e9+7;
    fin>>n;
    for(long long i=1;i<=n;i++)fin>>v[i].first>>v[i].second;
    for(long long i=1;i<=n;i++)x[i]=v[i].first+v[i].second;
    sort(x+1,x+n+1);
    for(long long i=1;i<n;i++)mn=min(mn,x[i+1]-x[i]);
    fout<<mn;
    return 0;
}

