#include <fstream>
using namespace std;
ifstream fin("factorial3.in");
ofstream fout("factorial3.out");
long n,i,j,s,p,aux;
int ciur[100001];
int main()
{
    fin>>n;
    for (i=2;i*i<=n;i++)
        if (!ciur[i])
            for (j=i;i*j<=n;j++)
                ciur[i*j]=1;
    for (i=2;i<=n;i++)
    {
        if (!ciur[i])
        {
            p=0;
            for(j=i;j<=n;j+=i)
            {
                aux=j;
                while (aux%i==0)
                {
                    aux/=i;
                    p++;
                }
            }
            s+=p;
        }
    }
   fout<<s<<'\n';
   return 0;
}