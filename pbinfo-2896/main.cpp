#include <fstream>
#define NM 1000001
using namespace std;
int a[NM],c,n;
ifstream fin("binar.in");
ofstream fout("binar.out");
int main()
{
    int lgc,lgm,pc,pm,nr1,nr1max,xmax,x,i,aux;
    fin>>c>>n;
    xmax=0;
    nr1max=0;
    for(i=1;i<=n;i++)
    {
        fin>>x;
        aux=x;
        nr1=0;
        while(aux>0)
        {
            nr1++;
            aux=(aux&(aux-1));
        }
        if(nr1>nr1max || nr1==nr1max && x>xmax)
        {
            nr1max=nr1;
            xmax=x;
        }
       a[i]=nr1;
    }
    if(c==1)
    {
        /// cerinta 1
        fout<<xmax;
        return 0;
    }
    ///cerinta 2
    lgm=0;
    lgc=1;
    pc=1;
    for(i=2;i<=n;i++)
        if(a[i]==a[i-1])lgc++;
        else
        {
            if(lgc>lgm)
            {
                lgm=lgc;
                pm=pc;
            }
            lgc=1;
            pc=i;
        }
        if(lgc>lgm)
            {
                lgm=lgc;
                pm=pc;
            }
        fout<<lgm<<' '<<pm;
    return 0;
}