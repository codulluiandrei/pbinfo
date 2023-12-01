#include <fstream>
#define NM 1000002
using namespace std;
ifstream fin("pdif.in");
ofstream fout("pdif.out");
int cifra_control(int x)
{
    int s,c;
    while(x>9)
    {
        s=0;
        while(x>0)
        {
            c=x%10;
            x=x/10;
            s=s+c;
        }
        x=s;
    }
    return x;
}
bool v[NM];
int main()
{
    int n,c,i,x,cc,lgm,lgc,nr,stm,drm,stc;
    fin>>n>>c;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        cc=cifra_control(x);
        v[i]=cc%2;
    }

    lgm=1;
    stm=drm=1;
    lgc=1;
    stc=1;
    for(i=2; i<=n; i++)
        if(v[i]+v[i-1]==1)
        {
            lgc++;
            if(lgc>lgm)
            {
                lgm=lgc;
                nr=1;
                stm=stc;
                drm=i;
            }
            else if(lgc==lgm)
                    {
                        nr++;
                    }
        }
        else
            {
                lgc=1;
                stc=i;
            }
    if(c==1)
        fout<<lgm<<' '<<nr<<endl;
    else
        fout<<stm<<' '<<drm<<endl;
    return 0;
}
