#include <fstream>
using namespace std;
ifstream fin("veverita_xi.in");
ofstream fout("veverita_xi.out");
int n,k;
long long A[27][55],s=0;
int main()
{
    fin>>n>>k;
    for(int j=1;j<=n;j++)
        for(int i=1;i<=k;i++)
            if(j==1) A[i][j]=1;
            else if(i==1) A[i][j]=A[2][j-1];
            else if(i==k) A[i][j]=A[k-1][j-1];
                 else A[i][j]=A[i-1][j-1]+A[i+1][j-1];
    for(int i=1;i<=k;i++)
        s=s+A[i][n];
    fout<<s;
    return 0;
}