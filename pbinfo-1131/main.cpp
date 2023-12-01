// prof. Carmen Popescu - Colegiul National "Gheorghe Lazar" Sibiu
#include <fstream>

using namespace std;

int p;
int c[10000],x[100000],m,n;

ifstream f("arc.in");
ofstream g("arc.out");


void citire()
{
    int k,i;
    f>>p;
    f>>n;
    f>>c[1]; x[1]=1; m=1;
    for (i=2;i<=n;i++)
    {
        f>>k;
        if (k==c[m])
            x[m]++;
        else
        {
            m++;
            c[m]=k;
            x[m]=1;
        }
    }
}

int maxim()
{
    int mx,k,i;
    mx=x[1]; k=1;
    for (i=1;i<=m;i++)
        if (x[i]>mx)
        {
            mx=x[i]; k=i;
        }
    return k;
}

void elim(int k)
{
    int i,j,m1;
    if (x[k]>2)
    {
        n=n-x[k];
        i=k-1; j=k+1;
        while (c[i]==c[j] && i>=1 && j<=m && x[i]+x[j]>2)
        {
            n=n-x[i]-x[j];
            i--; j++;
        }
        if (j>m)
            m=i;
        else
        {
            if (i>=1 && j<=m && c[i]==c[j])
            {
                x[i]=x[i]+x[j];
                j++;
            }
            m1=m-j+i+1;
            i=i+1;
            while (j<=m)
            {
                x[i]=x[j]; c[i]=c[j];
                i++; j++;
            }
            m=m1;
        }
    }
}

int main()
{
    int k;
    citire();
    if (p==1)
        g<<m<<"
";
    else
    {
        k=maxim();
        while (n>0 && x[k]>2)
        {
            elim(k);
            if (k>0)
                k=maxim();
        }
        if (n>0)
        {
            g<<n<<"
";
            for (int i=1;i<=m;i++)
                for (int j=1;j<=x[i];j++)
                    g<<c[i]<<"
";
        }
        else
            g<<"0
";
    }
    g.close();
    return 0;
}
