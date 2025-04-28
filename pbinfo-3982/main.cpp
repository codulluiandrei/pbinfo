#include <fstream>
using namespace std;
ifstream fin("descp2.in");
ofstream fout("descp2.out");
int n,X[201],F[21],m;
void afisare(int k)
{
    for(int i=1;i<=k;i++)
        fout<<F[X[i]]<<" ";
    fout<<"\n";
}
void back(int k, int s)
{
    for(int i=X[k-1];i<=m;i++)
    {
        X[k]=i;
        s=s+F[X[k]];
        if(s<=n)
            if(s==n) afisare(k);
            else back(k+1,s);
        s=s-F[X[k]];
    }
}
int main()
{
    fin>>n;
    F[1]=2;
    m=1;
    while(2*F[m]<=n)
    {
        m++;
        F[m]=2*F[m-1];
    }
    X[0]=1;
    back(1,0);
    return 0;
}