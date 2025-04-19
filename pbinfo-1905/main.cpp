#include <iostream>
#include <fstream>
using namespace std;
ifstream f("snooker1.in");
ofstream g("snooker1.out");
int v[1001],n,i,juc,s1,s2,k1,k2,maxim;
int main()
{
    f>>n;
    for(i=1; i<=n; i++)
        f>>v[i];
    juc=1;
    for(i=1; i<=n; i++)
    {
        if(v[i]!=0 and juc%2==1)
        {
            s1=s1+v[i];
            k1++;
        }
        if(v[i]!=0 and juc%2==0)
        {
            s2=s2+v[i];
            k2++;
        }
        if(v[i]==0 or v[i]==-5)
        {
            if(k1>maxim and v[i]!=-5)
                maxim=k1;
            if(k2>maxim and v[i]!=-5)
                maxim=k2;
            juc++;
            k1=0;
            k2=0;
        }
    }
    if(k1>maxim)
        maxim=k1;
    if(k2>maxim)
        maxim=k2;
    if(s1>s2)
        g<<1;
    else
        g<<2;
    g<<endl;
    g<<maxim;
    return 0;
}