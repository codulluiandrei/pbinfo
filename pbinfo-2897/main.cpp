#include <fstream>
using namespace std;

ifstream fin("numere.in");
ofstream fout("numere.out");

unsigned long long s=0;
unsigned int n, c, a, fr1[10000], fr2[10000], mx, lmax, d, x;

unsigned int fact_max(unsigned int a)
{
    unsigned int f=2, r;
    if(a%2==0)
    {
    r=2;
    while(a%2==0)
        a/=2;
    }
    for(f=3; a>1; f+=2)
        if(a%f==0)
        {
            r=f;
            while(a%f==0)
                a/=f;
        }
    return r;
}
int main()
{

    fin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        fin>>a;
        x=fact_max(a);
        if(x>mx)
            mx=x;///cel mai mare nr prim care apare in urma prelucrarii sirului initial
        ///cerinta 1
        if(fr1[x]==0)
            fr1[x]=i;
        else
        {
            int d=i-fr1[x]+1;
            if(d>lmax)
                lmax=d;
        }
        ///cerinta 2
        fr2[x]++;
    }
    if(c==1)
        fout<<lmax<<endl;
    else
    {
        ///rezolvarea de la cerinta 2
        ///calculez suma de x*(x-1)/2, unde x=fr2[i]

        if(fr2[2]>1)
            s+=fr2[2]*(fr2[2]-1)/2;
        ///,i-au mai ramas numai valori prime impare
        for(int i=3;i<=mx;i+=2)
            if(fr2[i]>1)
            s+=fr2[i]*(fr2[i]-1)/2;
        fout<<s<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}
