///Florentina Ungureanu - Colegiul Național de Informatică Piatra-Neamț
#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ifstream in("puteri3.in");
ofstream out("puteri3.out");
int c,p[80][105],l[80];
ull n,x;
void p3()
{
    p[0][0]=1;
    l[0]=1;
    for(int i=1; i<80; ++i)
    {
        l[i]=l[i-1];
        for(int j=0;j<l[i]; ++j)
            p[i][j]=p[i-1][j]*3;
        for(int j=0;j<l[i]; ++j)
        {
            p[i][j+1]+=p[i][j]/10;
            p[i][j]%=10;
        }
        if(p[i][l[i]]) l[i]++;
    }
}
void afis(ull x)
{
    int k = 0;
    do
    {
        if(x%2)
        {
            for(int i=l[k]-1;i>=0;--i)
                out<<p[k][i];
            out<<' ';
        }
        k++;
        x/=2;
    }while(x);
    out<<'\n';
}
int main()
{
    p3();
    in>>c>>n;
    if(c==1)
    {
        ull poz=0,i=1;
        while(i<n) i*=3,poz++;
        out << poz << '\n';
    }
    else
    for(int i=1;i<=n;++i)
        {
           in>>x;
           if(x==1) out<<"0\n";
           else afis(x-1);
        }
    return 0;
}