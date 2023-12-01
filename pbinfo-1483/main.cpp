#include <fstream>

using namespace std;
ifstream fin("coronite.in");
ofstream fout("coronite.out");
int x[101],sel[101],n;
int main()
{int i,j,nr=0,poz=1,ok;
fin>>n;
for(i=1;i<=n;i++) fin>>x[i];
for(i=1;i<=n;i++)
{
    for(j=1;j<=x[i];j++)
    {
        poz++;
        if (poz>n) poz=1;
    }
    if(poz==1&& sel[1]==0) nr=i;
    sel[poz]=1;
}
ok=1;
for(i=1;i<=n;i++)
    if(sel[i]==0)ok=0;

if(ok)fout<<1<<'\n';
else fout<<0<<'\n';
fout<<nr<<'\n';
    fin.close();fout.close();
    return 0;
}
