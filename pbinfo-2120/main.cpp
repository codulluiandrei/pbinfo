#include <fstream>
using namespace std;
ifstream fin("concurs4.in");
ofstream fout("concurs4.out");
char v[1000001];
int n,i,j,k,nr;
long x[30001];//sirul primelor n numere prime
long y[30001];//vectorul solutie
int main()
{
    fin>>n>>k;
    //ciurul
    v[0]=v[1]=1;
    for(i=2;i*i<=1000000;i++)
        if(v[i]==0)
            for(j=2;j*i<=1000000;j++)
                v[j*i]=1;
    for(i=2;nr<n;i++)
        if(v[i]==0)
            x[++nr]=i;
    y[1]=2;
    i=2;
    j=1;
    nr=0;
    while(j<n)
    {
        if(y[i]==0)
                {
                    nr++;
                    if(nr==k)
                        {
                            y[i]=x[++j];
                            nr=0;
                        }
                }
        i++;
        if(i==n+1) i=1;
    }
    fout<<y[1];
    for(i=2;i<=n;i++)
        fout<<' '<<y[i];
    fout<<'\n';
    return 0;
}