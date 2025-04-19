#include <fstream>
#define NMAX 100002
using namespace std;
ifstream fin("castig.in");
ofstream fout("castig.out");
int n, k;
int v[NMAX];
long long int s[NMAX];
long long int smax[NMAX];
long long int dmax[NMAX];
int main()
{long long int sum=0, valmin, maxim;
 int i;
 fin>>n>>k;
 for (i=1; i<=n; i++) fin>>v[i];
 for (i=1; i<=k; i++) sum+=v[i];
 s[1]=smax[1]=sum;
 for (i=2; i<=n-k+1; i++)
     {
      s[i]=s[i-1]-v[i-1]+v[i+k-1];
      smax[i]=smax[i-1];
      if (s[i]>smax[i]) smax[i]=s[i];
     }
 dmax[n-k+1]=s[n-k+1];
 for (i=n-k; i>=1; i--)
     {
         dmax[i]=dmax[i+1];
         if (s[i]>dmax[i]) dmax[i]=s[i];
     }
 valmin=dmax[k+1];
 for (i=2; i<=k; i++)
 if (valmin>dmax[i+k]) valmin=dmax[i+k];
 for (i=k+1; i<=n-k+1; i++)
    {
      maxim=smax[i-k];
      if (maxim<dmax[i+k]) maxim=dmax[i+k];
      if (maxim<valmin)    valmin=maxim;
    }
 fout<<valmin<<'\n';
 fout.close();
 return 0;
}