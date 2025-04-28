#include <fstream>
using namespace std;
ifstream fin("acces3.in");
ofstream fout("acces3.out");
int n,m,A[11][11],ip,jp,nrsol,kmax,B[11][11];
int di[]={-1,0,1,0};
int dj[]={0,1,0,-1};
int valid(int i, int j)
{
    if(i<1 || i>n || j<1 || j>m) return 0;
    if(A[i][j]!=0) return 0;
    return 1;
}
void back(int i, int j, int k)
{
    A[i][j]=k;
    if((i==1 && j==1) || (i==1 && j==m))
    {
        nrsol++;
        if(k>kmax)
            kmax=k;
    }
    for(int d=0;d<4;d++)
    {
        int iv=i+di[d], jv=j+dj[d];
        if(valid(iv,jv)) back(iv,jv,k+1);
    }
    A[i][j]=0;
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            char c;
            fin>>c;
            if(c=='#') A[i][j]=1;
            if(c=='P') { ip=i; jp=j; }
        }
    back(ip,jp,1);
    fout<<nrsol<<" "<<kmax;
    return 0;
}