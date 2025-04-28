#include <fstream>
using namespace std;
ifstream fin("pacman_xi.in");
ofstream fout("pacman_xi.out");
int main()
{
    long long A[41][41]={0};
    int n,m;
    fin>>n>>m;
    A[1][1]=1;
    for(int j=2;j<=m;j++)
        for(int i=1;i<=n;i++)
            if(i==1) A[i][j]=A[i][j-1];
                 else A[i][j]=A[i][j-1]+A[i-1][j-1];
    fout<<A[n][m];
    return 0;
}