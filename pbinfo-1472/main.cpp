#include<fstream>
using namespace std;
ifstream fin("castel.in");
ofstream fout("castel.out");
int i,k,n, v[10], c, cmax, maxx;
long x;
int main()
{
fin>>n;
for(i=1;i<=n;i++)
            { fin>>x;
            while(x)
            { v[x%10]++;
            x=x/10;}
            }
fin>>k;
fin>>c;
maxx=v[c];
cmax=c;
for(i=2;i<=k;i++)
            { fin>>c;
               if (v[c]>maxx)
                        { cmax=c;
                        maxx=v[c];
                        }
            }
fout<<cmax<<" "<<maxx<<'\n';
fin.close();
fout.close();
return 0;
}