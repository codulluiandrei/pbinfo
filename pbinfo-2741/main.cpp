#include <bits/stdc++.h>
using namespace std;
ifstream fin("sao1.in");
ofstream fout("sao1.out");
long long a[502][502],n,m,s,smax;
void refill(int x,int y,long long v){
    a[x][y]=0;
    s+=v;
    if(a[x+1][y]==v){
        refill(x+1,y,v);
    }
    if(a[x-1][y]==v){
        refill(x-1,y,v);
    }
    if(a[x][y+1]==v){
        refill(x,y+1,v);
    }
    if(a[x][y-1]==v){
        refill(x,y-1,v);
    }
}
int main(){
    fin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            fin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]){
                s=0;
                refill(i,j,a[i][j]);
                smax=max(smax,s);
            }
        }
    }
    fout<<smax;
    return 0;
}