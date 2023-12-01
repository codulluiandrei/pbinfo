#include <fstream>
using namespace std;
ifstream fin("exponent.in");
ofstream fout("exponent.out");
int n,a,k,m,ciur[1001],c[1001],p[1001],e[1001],ea[1001],emin;
void ciurul()
{
    int i,j;
    ciur[0]=ciur[1]=1;
    for(i=2;i<=1000;i++)
    {
        if(ciur[i]==0)
           {k++;
            c[k]=i;
            for(j=i*i;j<=a;j=j+i)
                ciur[j]=1;
           }
    }
}
int exp(int p)
{
    int ex=0,f=p;
    do{
        ex=ex+n/f;
        f=f*p;
      }while(n/f!=0);
    return ex;
}
int main()
{int i,ex;
    fin>>n>>a;
    ciurul();
    i=1;
    while(a>1&&i<=k)
    {
        ex=0;
        while(a%c[i]==0)
        {
            ex++;
            a=a/c[i];
        }
        if(ex)
        {
            m++;
            p[m]=c[i];
            ea[m]=ex;
        }
        i++;
    }
    for(i=1;i<=m;i++)
        {
          e[i]=exp(p[i]);
        }
    emin=e[1]/ea[1];
    for(i=2;i<=m;i++)
        if(e[i]/ea[i]<emin)
             emin=e[i]/ea[i];
    fout<<emin<<'\n';
    return 0;
}
