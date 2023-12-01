#include <fstream>
using namespace std;

ifstream fin("produsxl.in");
ofstream fout("produsxl.out");

int x[120];
int main()
{
    int i, n;
    long long r,y;
    fin>>n;
    for(i=n; i>=1; i--)
    {
        fin>>x[i];
    }
    fin>>y;

    if(y==0)
    {
        n=1;
        x[1]=0;
    }
    else
    {
        r=0;
        for(i=1; i<=n ; i++)
        {
            r=r+x[i]*y;
            x[i]=r%10;
            r/=10;
        }
        while(r>0)
        {
            n++;
            x[n]=r%10;
            r=r/10;
        }
    }

    for(i=n; i>=1; i--)
    {
        fout<<x[i];
    }

    fin.close();
    fout.close();
    return 0;
}
