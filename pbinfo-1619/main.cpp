// prof. Carmen Popescu - Colegiul National "Gheorghe Lazar" Sibiu
// 100 pct
#include <fstream>
#define NMAX 55
using namespace std;
ifstream f("pic.in");
ofstream g("pic.out");
long long ctot,p[NMAX][NMAX];
long long c[NMAX][NMAX],d[NMAX][NMAX];
long long x,m,k,s,mx=0,ss;
int i,j,umpl,v,lin,n;
int main()
{
    f>>v>>n;
    ctot=0;
    for (i=1; i<=n; i++)
    {
        m=0;
        ss=0;
        for (j=1; j<=i; j++)
        {
            f>>x;
            ss+=x;
            c[i][j]=x;
            if (x>m) m=x;
        }
        ctot += ss;
        if (ss>mx)
        {
            mx=ss;
            lin=i;
        }
    }
    if (v==1)
        g<<lin<<"\n";
    else
    {
        s=(1<<n); // 2^n, cantitate inca insuficienta pt a umple n nivele daca paharele ar avea toate capacitate 1
        do
        {
            // turnam dintr-o data s picaturi in paharul 1
            for (i=1; i<=n; i++) // initializam nr de picaturi turnate in fiecare pahar
                for (j=1; j<=n; j++)
                    p[i][j]=0;
            i=1;
            j=1;
            p[1][1]=s;
            for (i=1; i<n; i++)
                for (j=1; j<=i; j++)
                {
                    x = p[i][j]-c[i][j];
                    p[i][j] = x;
                    p[i+1][j] += (x+1)/2;
                    p[i+1][j+1] += x/2;
                }
            // aflam cate pahare neumplute avem
            k=0;
            for (j=1; j<=n; j++)
            {
                p[n][j] -= c[n][j];
                if (p[n][j]<0) k++;
            }
            if (k>0)        // mai sunt pahare neumplute
                s *= 2;
        }
        while (k>0);
        //   s umple toate paharele,
        // s/2 nu umple toate paharele
        // numarul de picaturi necesare este in intervalul [s/2, s] facem o cautare binara a cantitatii necesare
        // pt a ramane un singur pahar gol
        long long l=s/2;
        s=s-l/2;  // s e jumatatea intervalului [s/2,s]
        while (l>0)
        {
            for (i=1; i<=n; i++) // initializam nr de picaturi turnate in fiecare pahar
                for (j=1; j<=n; j++)
                    p[i][j]=0;
            i=1;
            j=1;
            p[1][1]=s;
            for (i=1; i<n; i++)
                for (j=1; j<=i; j++)
                {
                    x = p[i][j]-c[i][j];
                    p[i][j] = x;
                    p[i+1][j] += (x+1)/2;
                    p[i+1][j+1] += x/2;
                }
            k=0;
            for (j=1; j<=n; j++)
            {
                p[n][j] -= c[n][j];
                if (p[n][j]<0) k++;   // pahar neumplut
            }
            l=l/2;
            if (k>0)  // cel putin un pahar neumplut
                s=s+l/2;
            else
                s=s-l/2;
        }
        if (k>0)
            s++;
        g<<s<<" "<<s-ctot<<"\n";
    }
    return 0;
}