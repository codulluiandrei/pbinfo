#include<bits/stdc++.h>
using namespace std;
ifstream fin("window.in");
ofstream fout("window.out");
int n,r,y;
auto p=[](int x){int s=0,c=2;while(c<=x)s+=x/c,c<<=1;return s;};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    y=p(n-1);
    for(int i=1;i<=n;i++){
       int x;
       cin>>x;
       r^=((y==p(i-1)+p(n-i))?x:0);
    }
    cout<<r;
    return 0;
}