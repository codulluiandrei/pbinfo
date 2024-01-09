#include <fstream>
using namespace std;
ifstream fin("livada_xi.in");
ofstream fout("livada_xi.out");

int A[102][102],n;

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            fin>>A[i][j];
    for(int i=n;i>=1;i--)
        for(int j=1;j<=i;j++)
            if(j==1) { if(i!=n)  A[i][j]=A[i][j]+A[i+1][j]; }
            else if(i==n) A[i][j]=A[i][j]+A[i][j-1];
                 else A[i][j]=A[i][j]+min(A[i][j-1],A[i+1][j]);
    int min=1000000000;
    for(int i=1;i<=n;i++)
        if(A[i][i]<min) min=A[i][i];
    fout<<min;
    return 0;
}
