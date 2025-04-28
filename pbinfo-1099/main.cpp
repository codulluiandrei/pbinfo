#include <fstream>
#include <cstdlib>
using namespace std;
ifstream fin("insule.in");
ofstream fout("insule.out");
int di[]={0,0,1,-1}, dj[]={1,-1,0,0}, a[101][101],n,m;
int R[4];
void citire(){
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;++j){
            char c;
            fin>>c;
            a[i][j] = c-'0';
        }
}
void fill(int i,int j,int vc, int vn){
    if(i>0 && j>0 && i<=n && j<=m && a[i][j]==vc){
        a[i][j]=vn;
        for(int k=0;k<4;++k)
            fill(i+di[k], j+dj[k],vc,vn);
    }
}
int Vecin(int i,int j,int v){
    //verifica daca poz )i,j) are un vecin egal cu v
    for(int k=0;k<4;++k)
        if(a[i+di[k]][j+dj[k]]==v)
            return 1;
    return 0;
}
void lee(){
    int st,dr,L[10001],C[10001];
    st=1,dr=0;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]==0 && Vecin(i,j,-1)){
                a[i][j]=1;
                dr++;L[dr]=i, C[dr]=j;
            }
    while(st<=dr){
        int i=L[st],j=C[st];
        for(int k=0;k<4;++k){
            int ii = i+di[k],jj=j+dj[k];
            if(ii>0 && ii<=n && jj>0 && jj<=m && a[ii][jj]==0){
                a[ii][jj]=a[i][j]+1;
                dr++; L[dr]=ii , C[dr]=jj;
                if(Vecin(ii,jj,-2)){
                    fout<<" "<<a[ii][jj]<<endl;
                    exit(0);
                }
            }
        }
        st++;
    }
}
int main(){
    citire();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]>0){
                R[a[i][j]]++;
                fill(i,j,a[i][j],-a[i][j]);
            }
    fout<<R[1]<<" "<<R[2]<<" "<<R[3];
    lee();
    return 0;
}