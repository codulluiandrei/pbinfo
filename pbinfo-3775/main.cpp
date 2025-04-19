#include <fstream>
#include <algorithm>
#include <string.h>
#define ll long long
#include <stdio.h>
using namespace std;
ifstream  fin("prosum.in");
ofstream fout("prosum.out");
int n,i,j,p,w[100002];
ll v[100002],nr1,nr2,m,x;
ll gcd(ll a, ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
void gcd(ll &x, ll &y, ll a, ll b) {
     if (!b)
         x = 1, y = 0;
     else{
         gcd(x, y, b, a % b);
         ll aux = x;
         x = y;
         y = aux - y*(a / b);
     }
}
ll invers_modular(ll a, ll MOD){
    ll inv,ins;
    gcd(inv, ins, a, MOD);
    if (inv <= 0)
       inv = MOD + inv % MOD;
    return inv;
}
int main(){
    fin>>n>>m;
    for(i=1;i<=n;i++){
        fin>>v[i];
        v[i]=(v[i]+1)%m;
    }
    sort(v+1,v+1+n);
    p=1;w[1]=1;
    for(i=2;i<=n;i++){
        if(v[p]==v[i])w[p]++;
        else{p++;v[p]=v[i];w[p]=1;}
    }
    for(i=1;i<=p;i++){
        if(gcd(v[i],m)==1){
            x=invers_modular(v[i],m);
            if(x==v[i]){
                nr1=nr1+(ll)(w[i]-1)*w[i];
            }
            else{
                int p1=1,p2=p,med;
                while(p1<=p2){
                    med=p1+(p2-p1)/2;
                    if(x==v[med]){
                        nr2=nr2+(ll)w[i]*w[med];
                        break;
                    }
                    if(x<v[med]) p2=med-1;
                    else p1=med+1;
                }
            }
        }
    }
    fout<<(nr1+nr2)/2;
    return 0;
}