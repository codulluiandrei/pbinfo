/**
Sursa Oficiala
Autor : Ncu Vlad-Laurentiu
Liceul Teoretic "Mihail Kogalniceau" Vaslui
**/
#include<fstream>
#include<math.h>
using namespace std;

ifstream  fin("bipatrat.in");
ofstream fout("bipatrat.out");

long long x,y,p,q,i,j,aux;
double rx,ry;
long long n,a[200];
int verif(long long n)
{
    if(powl(floor(sqrt(n)),2)==n) return 1;
    else return 0;
}

int main()
{
    while(fin>>x)
    {
        n=0;
        if(verif(x))
        {
            p=1;
            while(p<=x)p=p*10;
            for(i=1;i<=9;i++)
            {
                y=i*p+x;

                if(verif(y))
                {
                    n++;
                    a[n]=y;

                }
            }
            while(p>=10)
            {
                q=p/10;
                for(i=0;i<=9;i++)
                {
                    y=(x/q)*p+i*q+x%q;
                    if(verif(y))
                    {
                        n++;
                        a[n]=y;

                    }
                }
                p=q;
            }
            for(i=1;i<=n-1;i++)
            {
                for(j=i+1;j<=n;j++)
                {
                    if(a[i]>a[j])
                    {
                        aux=a[i];
                        a[i]=a[j];
                        a[j]=aux;
                    }
                }
            }
        }
        if(n>0)
        {
            fout<<a[1]<<' ';
            for(i=2;i<=n;i++)
            {
                if(a[i-1]<a[i])fout<<a[i]<<' ';
            }
            fout<<'\n';
        }
        else
        {
            fout<<0<<'\n';
        }
    }
    fout.close();
    fin.close();
    return 0;
}
  