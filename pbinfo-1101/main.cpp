#include <fstream>
#include <iostream>
using namespace std;
#define MAX 105
int n, a[MAX][MAX],v[MAX], final[MAX],timee;
long timp[MAX], devreme[MAX], tarziu[MAX];
void dfs(int x){
    v[x]=1;
    for(int i=1;i<=n;i++)
        if(v[i] == 0 && a[x][i]==1)
            dfs(i);
    timee++;
    final[n-timee+1] = x;
}
void read(){
    ifstream fin("pm.in");
    fin>>n;
    for(int i=1;i<=n;++i)
        fin>>timp[i];
    for(int i=1;i<=n;i++){
        int m,j;
        fin>>m;
        for( ; m ; --m){
            fin>>j;
            a[j][i] = 1;
            devreme[i]++; //gradul interior
            tarziu[j]++; //gradul exterior
        }
    }
}
int main(){
    read();
    for(int i=1;i<=n;i++)
        if(devreme[i]==0)
            a[0][i]=1;
    for(int i=1;i<=n;i++)
        if(tarziu[i]==0)
            a[i][n+1]=1;
    for(int i=1;i<=n;i++)
        devreme[i]=tarziu[i]=0;
    for(int i=1;i<=n;i++)
        if(!v[i])
            dfs(i);
    final[n+1] = n+1;
    for(int i=1;i<=n+1;i++)
    {
        int k=final[i];
        for(int j=0;j<i;++j)
            if(a[final[j]][k]==1 && devreme[k]<devreme[final[j]]+timp[final[j]])
                devreme[k]=devreme[final[j]]+timp[final[j]];
    }
    tarziu[n+1] = devreme[n+1];
    for(int i=n;i; --i){
        int k = final[i];
        tarziu[k] = 1<<30;
        for(int j=i+1;j<=n+1;++j)
            if(a[k][final[j]]==1 && tarziu[k] > tarziu[final[j]] -timp[k])
                tarziu[k] = tarziu[final[j]] -timp[k];
    }
    ofstream fout("pm.out");
    fout<<devreme[n+1]<<endl;
    for(int i=1;i<=n;i++)
        fout<<devreme[i]<<" "<<tarziu[i]<<endl;
    return 0;
}