#include <fstream>
using namespace std;
ifstream fin("alice_xi.in");
ofstream fout("alice_xi.out");
int main()
{
    long long A[101][101],c=0;
    int n;
    fin>>n;
    A[1][1]=1;
    for(int i=2;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(j==1) A[i][j]=A[i-1][j]+A[i-1][j+1];
            else if(j==i-1) A[i][j]=A[i-1][j-1]+A[i-1][j];
                 else if(j==i) A[i][j]=A[i-1][j-1];
                      else A[i][j]=A[i-1][j-1]+A[i-1][j]+A[i-1][j+1];
    for(int i=1;i<=n;i++)
        c=c+A[n][i];
    fout<<c;
    return 0;
}