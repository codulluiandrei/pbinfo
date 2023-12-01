#include <fstream>
using namespace std;
ifstream fin("pinguini.in");
ofstream fout("pinguini.out");
int n, a[10001], i,lg,lgmax,nrp,nrg,c;
int main()
{
    fin>>c>>n;
    for(i=1;i<=n;i++)
        {
            fin>>a[i];
            if(a[i]==2)nrp++;
        }
    if(a[1]==1)nrg=0;
    else nrg=1;
    for(i=2;i<=n;i++)
            if(a[i]==2&&a[i-1]==1)nrg++;
    lg=lgmax=0;
    for(i=1;i<=n;i++)
    if(a[i]==2)lg++;
    else
    {
        if(lg>lgmax)lgmax=lg;
        lg=0;
    }
    if(lg>lgmax)lgmax=lg;
    if(c==1)fout<<nrp<<endl;
    if(c==2)fout<<nrg<<endl;
    if(c==3)fout<<lgmax<<endl;
    return 0;
}
