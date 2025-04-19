#include <fstream>
#define NM 1000001
using namespace std;
ifstream fin("gcd.in");
ofstream fout("gcd.out");
int n,a,b,A[NM],B[NM],vm,val,ok,ok1,j,i,ii;
int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a,A[a]=1;
        if(a>vm) vm=a;
    }
    val=1;
    for(int i=1;i<=n;i++)
    {
        fin>>b,B[b]=1;
        if(b>vm) vm=b;
        if(B[b]&&A[b]&&b>val)
                val=b;
    }
    for(int i=2;i<=vm;i++)
    {
        ok=0;ok1=0;
        for(j=i;j<=vm&&(ok==0||ok1==0);j+=i)
        {
            if(B[j]==1)
            {
                ok=1;
            }
            if(A[j]==1)
            {
                ok1=1;
            }
        }
        if(ok&&ok1&&i>val)
                val=i;
    }
    fout<<val<<'\n';
    return 0;
}