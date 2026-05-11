#include <fstream>
using namespace std;
ifstream f("codificare.in");
ofstream g("codificare.out");
int main()
{
    int p, minn=1000000000, maxx=-1,n,x,prima_cifra;
    f>>p;
    if (p==1)
    {
        f>>n;
        for (int i=1; i<=n; i++)
        {
            f>>x;
            prima_cifra=x;
            while (prima_cifra>9)
                prima_cifra=prima_cifra/10;
            if (prima_cifra%2==0)
            {
                if (x<minn) minn=x;
                if (x>maxx) maxx=x;
            }
        }
        g<<minn<<' '<<maxx;
    }
    else
    {
        int k,c,i;
        int p10=1;
        f>>k>>c;
        if (c!=1)
        {
            for (i=1; i<=(k-1)/2; i++) p10=p10*10;
            g<<p10;
        }
        else
        {
            for (i=1; i<=k/2; i++) p10=p10*10;
            if (k%2==0)
                g<<p10+p10/10-1;
            else
                g<<p10+p10-1;
        }
    }
}