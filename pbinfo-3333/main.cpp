#include <fstream>
#define N 1000001
using namespace std;
ifstream f("bookface.in");
ofstream g("bookface.out");
long long n;
long long s[N], p[N], prim[N];


void brut()
{
    long long i, j, a, b, suma;
    for(i = 1; i <= n; i++)
    {
        f >> a;
        b = a*a;
        suma = a;
        for(j = 1; j < a; j++)
            if(b%j==0) suma += j + b/j;
        g << suma << "\n";
    }
}

void soft()
{
    long long i, j, k, pu, a;

    s[1] = 1;
    for(i = 2; i < 1000000; i++)
    if(p[i]==0)
    {
        s[i] = 1+i+i*i;
        prim[i] = i;
        j = i+i;
        while(j < 1000000)
        {
            p[j] = 1;
            prim[j] = i;
            j = j+i;
        }
    }
    else
    {
        j = i/prim[i];
        if(j%prim[i]!=0)
        {
            s[i] = s[j]*(1+prim[i]+prim[i]*prim[i]);
        }
        else
        {
            j = i;
            pu = 1;
            while(j%prim[i]==0)
            {
                j = j/prim[i];
                pu = pu*prim[i];
            }
            s[i] = s[j]*(pu*pu*prim[i]-1)/(prim[i]-1);
        }
    }
    for(i = 1; i <= n; i++)
    {
        f >> a;
        g << s[a] << "\n";
    }
}

int main()
{
    f >> n;
    //brut();
    soft();
    return 0;
}
