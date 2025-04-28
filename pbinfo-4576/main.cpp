#include <fstream>
using namespace std;
ifstream fin("bilbob.in");
ofstream fout("bilbob.out");
int n,m,A[202][202],S[202][202];
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            fin>>A[i][j];
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n;i++)
            if(i==1 && j==1) S[i][j]=A[i][j];
            else if(i>j) S[i][j]=0;
            else if(i==1) S[i][j]=max(S[i][j-1],S[i+1][j-1])+A[i][j];
            else if(i==n) S[i][j]=max(S[i][j-1],S[i-1][j-1])+A[i][j];
            else S[i][j]=max(max(S[i+1][j-1],S[i][j-1]),S[i-1][j-1])+A[i][j];
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            fout<<S[i][j]<<" ";
        fout<<endl;
    }*/
    fout<<S[1][m];
    return 0;
}