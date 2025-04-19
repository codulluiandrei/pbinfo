#include <fstream>
using namespace std;
ifstream f("numere.in");
ofstream g ("numere.out");
int main()
{
    int p,n,x,dif1=20000000,dif2=20000000,y,xx;
    long long xmin,xmax,i, nr1,nr2;
    unsigned long long nr;
    f>>p;
    if (p==1)
    {
        f>>n;
        nr=9;
        for (i=1; i<=n-3; i++)
            nr=nr*5;
        g<<nr<<'\n';
    }
    else
    {
        f>>x;
        y=x;
        xmin=163;
        xmax=812;
        i=3;
        while (y>999)
        {
            i++;
            if (i%2==0)
            {
                xmin=xmin*10;
                xmax=xmax*10+9;
            }
            else
            {
                xmin=xmin*10+1;
                xmax=xmax*10+8;
            }
            y=y/10;
        }
 if (x<xmin)  g<<xmin;
        else
         if (x>xmax)  g<<xmax;
        else
          {
        for (xx=x-1; xx>=xmin; xx--)
        {
            int v[11],k=0,n2,i,xxx=xx, bun=1;
            while (xxx>99)
            {
                k++;
                v[k]=xxx%10;
                xxx=xxx/10;
            }
            if (xxx!=16 && xxx!=25 && xxx!=36 && xxx!=49 && xxx!=81) bun=0;
            else if ((xxx==16|| xxx==36)&& (v[k]!=3 && v[k]!=5 && v[k]!=7)) bun=0;
            else if ((xxx==25 || xxx==49 ||xxx==81) && v[k]!=2) bun=0;
            else
                for (i=k-1; i>=1; i--)
                    if (v[i]%2==v[i+1]%2) bun=0;
            if (bun)
            {
                nr1=xx;
                dif1=x-nr1;
                break;
            }
        }
        for (xx=x+1; xx<=xmax; xx++)
        {
            int v[11],k=0,n2,i,xxx=xx, bun=1;
            while (xxx>99)
            {
                k++;
                v[k]=xxx%10;
                xxx=xxx/10;
            }
            if (xxx!=16 && xxx!=25 && xxx!=36 && xxx!=49 && xxx!=81) bun=0;
            else if ((xxx==16|| xxx==36)&& (v[k]!=3 && v[k]!=5 && v[k]!=7)) bun=0;
            else if ((xxx==25 || xxx==49 ||xxx==81) && v[k]!=2) bun=0;
            else
                for (i=k-1; i>=1; i--)
                    if (v[i]%2==v[i+1]%2) bun=0;
            if (bun)
            {
                nr2=xx;
                dif2=nr2-x;
                break;
            }
        }
        if (dif1<=dif2)
            g<<nr1<<'\n';
        else
            g<<nr2<<'\n';
    }
    }
}