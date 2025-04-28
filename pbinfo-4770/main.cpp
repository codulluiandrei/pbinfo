#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream fin("pase.in");
ofstream fout("pase.out");
char s[1001];
int g[1001],lg[1001],lgmax,pozmax,n,nr;
int main()
{
    fin>>n>>s;
    int poz=0,l=0,nrgresit,i;
    nr=strlen(s);
    for(i=0; i<strlen(s); i++)
        if(s[i]=='G')
        {
            g[i]=1;
            l=0;
        }
        else
        {
            if(l==0)
            {
                lg[i]=0;
                poz=i;
            }
            l++;
            lg[poz]++;
        }
    i=0;
    int pozurm,ng=0;
    while(g[i]==1)
    {
        ng++;
        i++;
    }
    if(ng>2)
        i=i-2;
    else i=0;
    while(i<nr)
    {
        l=0;
        nrgresit=0;
        while(nrgresit<2&&i<nr)
        {
            while(g[i]==0&&i<nr)
            {
                if(l==0)poz=i;
                l=l+lg[i];
                i++;
            }
            if(i==nr)break;
            if(nrgresit==0&&i<nr)
            {
                if(l==0)poz=i;
                l++;
                pozurm=i+1;
                i++;
                nrgresit=1;
            }
            else if(nrgresit==1&&i<nr)
            {
                l++;
                nrgresit=2;
                i++;
                while(g[i]==0&&i<nr)
                {
                    l=l+lg[i];
                    i++;
                }
                if(l>lgmax)
                {
                    lgmax=l;
                    pozmax=poz;
                }
                i=pozurm;
            }
        }
    }
    fout<<lgmax<<" "<<pozmax+1<<"\n";
    fout.close();
    return 0;
}