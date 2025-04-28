#include <fstream>
#include <iomanip>
#include<iostream>
using namespace std;
ifstream fin("musca.in");
ofstream fout("musca.out");
int main()
{
    int n, x[10000], y[100000],i,j,a, ok;
    float mx,my;
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>x[i]>>y[i];
    ok=1;
    if(n%2==1)
        ok=0;
    if (ok)
    {
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(x[i]>x[j])
            {
                a=x[i]; x[i]=x[j]; x[j]=a;
                a=y[i]; y[i]=y[j]; y[j]=a;
            }
            else
                if(x[i]==x[j])
                    if(y[i]>y[j])
                    {
                        a=y[i]; y[i]=y[j]; y[j]=a;
                    }
    mx=(x[1]+x[n])/2.0;
    my=(y[1]+y[n])/2.0;
    cout<<mx<< " " <<my<<endl;
    for(i=2;i<=n/2;i++)
    {
        if((x[i]+x[n+1-i])/2.0!=mx ||(y[i]+y[n+1-i])/2.0!=my)
            ok=0;
        cout<<(x[i]+x[n+1-i])/2.0<< " " <<(y[i]+y[n+1-i])/2.0<<endl;
    }
    }
    if(ok)
    {
        fout<<1<<;
        int m=(int)(mx*1000);
        mx=m/1000.0;
        fout<<fixed;
        fout<<setprecision(3)<<mx<<" "<<my;
    }
    else
        fout<<0;
    fin.close();
    fout.close();
    return 0;
}