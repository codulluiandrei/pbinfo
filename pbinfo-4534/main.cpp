#include <fstream>
using namespace std;
ifstream fin("submultimiinterval.in");
ofstream fout("submultimiinterval.out");
int n,a,b,X[21];
void afis(int n)
{
    for(int i=1;i<=n;i++)
        fout<<a+X[i]-1<<" ";
    fout<<"\n";
}
void back(int k)
{
    for(int i=X[k-1]+1;i<=n;i++)
    {
        X[k]=i;
        afis(k);
        back(k+1);
    }
}
int main()
{
    fin>>a>>b;
    n=b-a+1;
    back(1);
    return 0;
}