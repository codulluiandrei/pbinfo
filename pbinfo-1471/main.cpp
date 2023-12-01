#include <fstream>
using namespace std;

ifstream fin("maxdiv.in");
ofstream fout("maxdiv.out");
int n,t, v[1002], i,j,dmax, a[1002];
int k,kmax,p,u,ns;
int nrdiv(int x)
{
    int e, d, nrd;
    nrd =1;
    if (x==1) nrd=1;
    else
    {
        d=2;
        while (x>1)
        {
            e=0;
            while (x%d==0)
            {
                e++;
                x=x/d;
            }
            nrd=nrd*(e+1);
            if (d==2) d++;
            else d=d+2;
        }
    }
    return nrd;
};

int main()
{
    fin>>n>>t;
    for (i=1; i<=n; i++)
    {
        fin>>v[i];
        a[i]=nrdiv(v[i]);
    }

    dmax=0;
    for (i=1; i<=n; i++)
    {
        if (a[i]>dmax)
            dmax=a[i];
    }
    for (i=1; i<=n; i++)
        if(a[i]==dmax)
            ns++;
    a[n+1]=dmax-1;
    for(i=1; i<=n; i++)
        if(a[i]==dmax)
        {
            j=i+1;
            k=1;
            while(j<=n&&a[j]!=dmax)
            {
                j++;
                k++;
            }
            if(k>kmax && a[j] == dmax)
            {
                kmax=k;
                p=i;
                u=j;
            }
            i=j-1;
        }
    if(t==1)
      fout<<ns-1<<endl;
    else
    for(i=p; i<=u; i++)
        fout<<v[i]<<' ';
    return 0;
}