#include <fstream>
#include<iostream>
using namespace std;
ifstream fin("numere.in") ;
ofstream fout("numere.out") ;
int n,c,frecv[10],munte,vale;
int main()
{
    int x,i,c1,c2,sens,cx;
    int cifra_max=0;
    fin>>n>>c;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        cx=x;
        //verificare numar din sir
        c1=x%10;
        x/=10;
        c2=x%10;
        if(c2<=c1)
            sens=-1;
        else
        {
            sens=1;
            x/=10;
            while(x&& sens>0)
            {
                c1=c2;
                c2=x%10;
                if(c2<c1&&sens==1)
                    sens ++;
                else if(c1==c2)
                    sens=-1;
                else if(sens==2&&c1<c2)
                    sens=-1;
                x/=10;
            }
            if(sens==1)
                vale++;
            if(sens==2)
            {
                munte++;
                while(cx)
                {
                    frecv[cx%10]++;
                    cx/=10;
                }
            }
        }
    }
    if(c==1)
        fout<<munte<<" "<<vale<<endl;
    else
    {
                for(i=9; i>=1; i--)
        {
            if(frecv[i]>=2)
            {
                cifra_max=i;
                break;
            }
        }
        for(i=cifra_max+1; i<=9; i++)
        {
            if(frecv[i]==1)
            {
                cifra_max=i;
                break;
            }
        }
        for(i=1; i<cifra_max; i++)
            if(frecv[i]>=2)
            {
                fout<<i;
            }
        fout<<cifra_max;
        for(i=cifra_max-1; i>=1; i--)
            if(frecv[i]>=2)
            {
                fout<<i;
            }
    }
    return 0;
}