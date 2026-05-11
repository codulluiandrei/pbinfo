#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("triunghi.in");
ofstream fout("triunghi.out");
long long int n,c,h,nr,v[2002],s[4000002],p,m,z,T;
bool C[4000002];
void ciur( int n)
{
    int nr=0;
    C[0]=C[1]=1;
    for(int i=2; i<=n; i++)
        if(C[i]==0)
            for(int j=2*i; j<=n*n; j=j+i)
                C[j]=1;
    for(int i=2; i<=n*n; i++)
    {
        if(C[i]==0)
            nr++;
        s[i]=nr;
    }
}
int main()
{
    fin>>c>>n;
    if(c==1)
        fout<<n*(n+1)*(2*n+1)/6;
    else if(c==2)
    {
        int i=1;
        while(v[i-1]+i*i<n )
        {
            v[i]=v[i-1]+i*i;
            i++;
        }
        z=i;
        nr=n-v[z-1];
        if(nr==0)
            fout<<z<<' '<<z<<endl;
        else
            fout<<z<<' '<<ceil(sqrt(nr))<<endl;
    }
    else
    {
        ciur(n);
        for(int i=1; i<=n; i++)
            T=T+s[i*i];
        fout<<T;
    }
    return 0;
}