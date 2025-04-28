#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("bila.in");
ofstream fout("bila.out");
int n,m,a[21][21], b[21][21], istart, jstart, nmax;
const int di[]={0,0,1,-1}, dj[]={1,-1,0,0};
void Citire(){
    fin >> n >> m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            fin >> a[i][j];
    fin >> istart >> jstart;
}
void Back(int i, int j, int pas){
    b[i][j] = pas;
    if(i==1 || j==1 || i==n || j==m){
        if(pas>nmax)
            nmax = pas;
    }
    else
        for(int k=0;k<4;++k){
            if(a[i+di[k]][j+dj[k]]<a[i][j])
                Back(i+di[k], j+dj[k], pas+1);
        }
    b[i][j] = 0;
}
int main(){
    Citire();
    Back(istart, jstart, 1);
    fout<< nmax;
    return 0;
}