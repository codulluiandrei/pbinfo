#include <fstream>
#include<cstdlib>
using namespace std;
ifstream fin("nuclee.in");
ofstream fout("nuclee.out");
int n,i, a[201][201],at[201][201],viz[201],post[201],nrc,nr;
void citire()
{
    int i,j,k,x;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>k;
        a[i][0]=k;
        for(j=1;j<=k;j++)
        {
            fin>>x;
            a[i][j]=x;
            at[x][0]++;
            at[x][at[x][0]]=i;
        }

    }
}
void dfs(int i)
{
    int j;
    viz[i]=1;
    for(j=1;j<=a[i][0];j++)
        if(!viz[a[i][j]])
            dfs(a[i][j]);
    post[++nr]=i;
}
void dfst(int i)
{
    int j;
    viz[i]=0;
    for(j=1;j<=at[i][0];j++)
        if(viz[at[i][j]])
            dfst(at[i][j]);

}
int main()
{
    citire();
    for(i=1;i<=n;i++)
        if(!viz[i])
                dfs(i);
    for(i=n;i>=1;i--)
        if(viz[post[i]])
    {
        nrc++;
        dfst(post[i]);
    }
    fout<<nrc<<'\n';
    fout.close();
    return 0;
}
