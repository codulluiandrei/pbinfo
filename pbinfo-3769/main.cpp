#include <fstream>
using namespace std;
ifstream f("iepuras.in");
ofstream g("iepuras.out");
long long C, n, i, x, mi, ma, k, aux, p, y, nn, nr, nre, j, uc, fr[15];
int main()
{
    f>>C;
    if (C==1)
    {
        f>>n;
        for (i=1;i<=n;i++)
        {
            f>>x;
            if (x==0) g<<0<<"\n";
            else
            {
            for (k=0;k<=9;k++)
                fr[k]=0;
            aux=x;
            while (aux>0)
            {
                fr[aux%10]=1;
                aux/=10;
            }
            ma=0;
            for (k=9;k>=0;k--)
                if (fr[k]==1) ma=ma*10+k;
            mi=0;
            for (k=1;k<=9;k++)
                if (fr[k]==1)
            {
                mi=k;
                fr[k]=0;
                break;
            }
            for (k=0;k<=9;k++)
                if (fr[k]==1) mi=mi*10+k;
            g<<mi+ma<<"\n";
            }
        }
    }
    else
    {
        f>>n;
        for (i=1;i<=n;i++)
        {
            f>>x;
            if (x==0) g<<1<<"\n";
            else
            {
            y=x%9;
            if (y==0) y=9;
            /*nr=0;
            for (j=1;j<=x;j++)
            {
                aux=j;
                while (aux>0)
                {
                    if (aux%10==y) nr++;
                    aux/=10;
                }
            }*/
            nre=0;
            aux=x;
            p=1;
            nn=0;
            while (aux>0)
            {

                uc=aux%10;
                if (uc>y) nre=nre+(aux/10+1)*p;
                else
                    if (uc==y) nre=nre+ aux/10*p+ nn+1;
                else nre=nre+aux/10*p;
                nn=nn+uc*p;
                p=p*10;
                aux=aux/10;
            }
            g<<nre<<"\n";
            }
        }
    }
    return 0;
}
