#include <fstream>
using namespace std;
ifstream fin("sumtri_xi.in");
ofstream fout("sumtri_xi.out");

int main()
{
    int n,A[101][101]={0};
    fin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            fin>>A[i][j];
    for(int j=2;j<=n;j++)
        for(int i=j;i<=n;i++)
            A[i][j]=A[i][j]+max(A[i][j-1],A[i-1][j-1]);
    fout<<A[n][n];
    return 0;
}
