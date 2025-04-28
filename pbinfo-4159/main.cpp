#include <fstream>
using namespace std;
ifstream fin("nivele11.in");
ofstream fout("nivele11.out");
int n,T[101],r,D[101],Q[101],nmax;
void DF(int x)
{
    for(int i=1;i<=n;i++)
        if(T[i]==x)
        {
            D[i]=D[x]+1;
            DF(i);
        }
}
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>T[i];
        if(T[i]==0) r=i;
    }
    DF(r);
    for(int i=1;i<=n;i++)
        if(D[i]>nmax) nmax=D[i];
    for(int i=0;i<=nmax;i++)
    {
        for(int j=1;j<=n;j++)
            if(D[j]==i) fout<<j<<" ";
        fout<<endl;
    }
    return 0;
}