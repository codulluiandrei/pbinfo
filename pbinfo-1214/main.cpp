#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
    int gasit=0,n,v[60],vmin[60],vmax[60],maimic,maimare,i,k;
    unsigned long long s,dif,a,b;
    ifstream f("inventie.in");
    ofstream g("inventie.out");

    f>>n;

    for (i=1; i<=n; i++)
    {
        f>>a>>b;
        if (a==b) g<<a+b<<'\n';
        else
        {
            if (a>b) dif=a-b;
            else dif=b-a;
            g<<dif<<a+b<<'\n';
        }
        if (a%2!=b%2)
        {
            k=0; // numarul cifrelor
            gasit=1;
            s=a+b;
            while (s)
            {
                k++;
                vmin[k]=vmax[k]=s%10;
                s=s/10;
            }
            while (dif)
            {
                k++;
                vmin[k]=vmax[k]=dif%10;
                dif=dif/10;
            }
            vmin[0]=vmax[0]=k;
            break;
        }

    }
    i++;
    while (i<=n)
    {
        f>>a>>b; //g<<" am citit "<<a<<' '<<b<<"la pasul "<<i<<'\n';
        if (a==b) g<<a+b<<'\n';
        else
        {
            if (a>b) dif=a-b;
            else dif=b-a;
            g<<dif<<a+b<<'\n';
        }
        if (a%2!=b%2)
        {
            k=0; // numarul cifrelor
            s=a+b;
            while (s)
            {
                k++;
                v[k]=s%10;
                s=s/10;
            }
            while (dif)
            {
                k++;
                v[k]=dif%10;
                dif=dif/10;
            }
            v[0]=k;
            // verific daca noul rezultat este mai mic decat vmin, sau mai mare decat vmax
            if (v[0]<vmin[0])
                for (int j=0; j<=v[0]; j++) vmin[j]=v[j];
            else if (v[0]>vmax[0])
                for (int j=0; j<=v[0]; j++) vmax[j]=v[j];
            else
            {
                if (v[0]==vmin[0])
                {
                    maimic=1;// pres ca v<vmin
                    for (int j=v[0]; j>=1; j--)
                        if (v[j]>vmin[j])
                        {
                            maimic=0;
                            break;
                        }
                        else    if (v[j]<vmin[j]) break;
                    if (maimic){
                        for (int j=0; j<=v[0]; j++) vmin[j]=v[j];
                       }
                }
                if (v[0]==vmax[0])
                {
                    maimare=1; // pres ca v>vmax
                    for (int j=v[0]; j>=1; j--)
                        if (v[j]<vmax[j])
                        {
                            maimare=0;
                            break;
                        }
                        else if  (v[j]>vmax[j]) break;
                    if (maimare)
                        for (int j=0; j<=v[0]; j++) vmax[j]=v[j];
                }
            }

        }

        i++;
    }
    if (gasit==0) g<<0<<'\n';
    else
    {
        for (int j=vmin[0]; j>=1; j--) g<<vmin[j];
        g<<'\n';
        for (int j=vmax[0]; j>=1; j--) g<<vmax[j];
        g<<'\n';
    }
    return 0;
}



