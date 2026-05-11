#include <fstream>
using namespace std;
ifstream fin("cal_xi.in");
ofstream fout("cal_xi.out");
int n,m,A[11][11],B[11][11],np,ic,jc,nrsol,kmin=1000;
int di[]={-2,-2,-1,+1,+2,+2,+1,-1};
int dj[]={-1,+1,+2,+2,+1,-1,-2,-2};
int valid(int i, int j)
{
    if(i<1 || i>n || j<1 || j>m) return 0;
    if(A[i][j]>2) return 0;
    if(B[i][j]!=0) return 0;
    return 1;
}
void afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            fout<<B[i][j]<<" ";
        fout<<endl;
    }
    fout<<endl;
}
void back(int i, int j, int k)
{
    B[i][j]=k;
    if(A[i][j]==1) np--;
    if(np==0)
    {
        //afisare();
        if(k<kmin) kmin=k;
        nrsol++;
    }
    else for(int d=0;d<8;d++)
        {
            int iv=i+di[d],jv=j+dj[d];
            if(valid(iv,jv)) back(iv,jv,k+1);
        }
    if(A[i][j]==1) np++;
    B[i][j]=0;
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            {
                fin>>A[i][j];
                if(A[i][j]==2) { ic=i; jc=j; }
                else if(A[i][j]==1) np++;
            }
    back(ic,jc,1);
    if(nrsol) fout<<nrsol<<" "<<kmin-1;
    else fout<<"IMPOSIBIL";
    return 0;
}