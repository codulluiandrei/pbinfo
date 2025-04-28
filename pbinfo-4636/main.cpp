#include <fstream>
using namespace std;
ifstream fin("capradinohio.in");
ofstream fout("capradinohio.out");
int n,m,X[21],P[21],A[21][21],c;
void afisare()
{
    for(int i=1;i<=n;i++)
        fout<<X[i]<<" ";
    fout<<"\n";
    c++;
}
void back(int k)
{
    for(int i=1;i<=n;i++)
        if(!P[i])
        {
            X[k]=i;
            P[i]=1;
            if(k==1 || A[X[k-1]][X[k]]==1 )
            {
                if(k==n) afisare();
                else back(k+1);
            }
            P[i]=0;
        }
}
int main()
{
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        fin>>x>>y;
        A[x][y]=A[y][x]=1;
    }
    back(1);
    if(c==0) fout<<"NU EXISTA";
    return 0;
}