#include <cstdio>
#include <fstream>
#define infile "genpascal.in"
#define outfile "genpascal.out"

using namespace std;

ofstream fout(outfile);

int main()
{
    freopen(infile,"r",stdin);
    int n,m,L;
    scanf("%d%d%d",&n,&m,&L);
    if(L==2) fout<<n+m;
    else if(L<=57)
    {
        // presupunând că n și m sunt maxim posibile, adică 100,
        // se observă că numărul maxim ce se poate obține fără operții cu numere mari este
        // 2^55 * (100+100) = 36028797018963968 * 200
        unsigned long long S=1;
        for(int i=1; i<=L-2; ++i) S*=2;
        fout<<S * (n + m);
    }
    else
    {
        unsigned long long S=1;
        for(int i=1; i<=55; ++i) S*=2;
        //numărul S îl descompunem în cifre în vector pentru a face operații cu numere mari
        int v[2000];
        v[0]=0;
        S*=(m+n);
        while(S)
        {
            v[++v[0]]=S%10;
            S/=10;
        }
        for(int k=58; k<=L; ++k)
        {
            // v * =2
            int T=0;
            for(int i=1; i<=v[0]; ++i)
            {
                v[i]=v[i]*2+T;
                T=v[i]/10;
                v[i]%=10;
            }
            while(T)
            {
                v[++v[0]]=T%10;
                T/=10;
            }
        }
        for(int i=v[0]; i>=1; --i) fout<<v[i];

    }

    fclose(stdin);
    fout.close();
    return 0;
}
