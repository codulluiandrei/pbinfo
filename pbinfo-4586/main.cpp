#include<fstream>
using namespace std;
#define LIM 10001
ifstream cin("planar.in");
ofstream cout("planar.out");
int factor[LIM+1],exponent[LIM+1],v[6000];
bool ciur[LIM+1];
int n,k,i,j,d,e,aux,nrprim,vf,nr,cerinta;
int main()
{
    cin>>cerinta>>nr;
    ///aflu factorii primi mai mici decat nr=2n
    ciur[0]=ciur[1]=1;
    for(i=2; i<=nr; i++)
        if (ciur[i]==0)
        {
            factor[++nrprim]=i;
            for(j=i*i; j<=nr; j=j+i)
                ciur[j]=1;
        }
    ///CATALAN=COMB(2N,N)/(N+1)=(2N)!/ [ (N+1)! * N!]
    ///A=(2n)! - il descompun - creste exponentul
    for(i=1; i<=nrprim; i++)
    {
        d=factor[i];
        e=0;
        aux=nr;
        while(aux>0)
        {
            e=e+aux/d;
            aux/=d;
        }
        exponent[i]+=e;
    }
    ///A=(N+1)! - il descompun - scade exponentul
    for(i=1; i<=nrprim; i++)
    {
        d=factor[i];
        e=0;
        aux=nr/2+1;
        while(aux>0)
        {
            e=e+aux/d;
            aux/=d;
        }
        exponent[i]-=e;
    }
    ///A=n! - il descompun - scade exponentul
    for(i=1; i<=nrprim; i++)
    {
        d=factor[i];
        e=0;
        aux=nr/2;
        while(aux>0)
        {
            e=e+aux/d;
            aux/=d;
        }
        exponent[i]-=e;
    }
    ///nu mai am numitor...doar 1...
    ///fac produsul factorilor dupa exponentii ramasi
    if (cerinta==2)
    {
        v[1]=1;
        vf=1;
        for(i=1; i<=nrprim; i++)
            while(exponent[i]>0)
            {
                exponent[i]--;
                d=factor[i];
                for(j=1; j<=vf; j++)
                    v[j]=v[j]*d;
                ///trecerea peste unitate
                for(j=1; j<=vf; j++)
                    if (v[j]>9)
                    {
                        v[j+1]+=(v[j]/10);
                        v[j]=v[j]%10;
                    }
                ///marire sir...
                while(v[vf+1]>0)
                {
                    vf++;
                    if (v[vf]>9)
                    {
                        v[vf+1]+=(v[vf]/10);
                        v[vf]=v[vf]%10;
                    }
                }
            }
        for(i=vf; i>=1; i--)
            cout<<v[i];
        cout<<'\n';
    }
    else
    {
        long long rez=1;
        for(i=1; i<=nrprim; i++)
            while(exponent[i]>0)
            {
                exponent[i]--;
                rez=rez*factor[i]%20232029;
            }
        cout<<rez<<'\n';
    }
}