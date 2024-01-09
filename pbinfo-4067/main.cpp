#include <fstream>
using namespace std;
ifstream fin("ccmax.in");
ofstream fout("ccmax.out");

int n,A[101][101],P[101];

void DF(int v,int c)
{
    P[v]=c;
    for(int i=1;i<=n;i++)
        if(A[v][i]==1 && P[i]==0)
            DF(i,c);
}
int main()
{
    int x,y;
    int max=0,ap=0,F[101]={0};
    fin>>n;
    while(fin>>x>>y)
        A[x][y]=A[y][x]=1;
    int c=0;
    for(int i=1;i<=n;i++)
        if(P[i]==0)
        {
            c++;
            DF(i,c);
        }
    for(int i=1;i<=n;i++)
        F[P[i]]++;
    for(int i=1;i<=c;i++)
        if(F[i]>max) { max=F[i]; ap=1; }
        else if(F[i]==max) ap++;
    fout<<max<<" "<<ap;
    return 0;
}
