#include <fstream>
using namespace std;

ifstream f("plusminus.in");
ofstream g("plusminus.out");

int x[51], n;

int suma(int k)
{
    int i, s=0;
    for(i=1;i<=k;i++)
        if(x[i]==1) s-=i*i;
        else s+=i*i;
    return s;
}

void scrie()
{
    for(int i=1;i<=n;i++)
        if(x[i]==1)g<<"- ";
        else g<<"+ ";
    g<<endl;
}

void back( int k)
{
    if (k==n+1)
        {
            if(suma(n)==n)scrie();
        }
    else
    {
        for(x[k]=1;x[k]<=2;x[k]++)
            back(k+1);
    }
}

int main()
{
    f>>n;
    if((n%4)&&((n-1)%4)) g<<"IMPOSIBIL\n";
    else back(1);
    return 0;
}
