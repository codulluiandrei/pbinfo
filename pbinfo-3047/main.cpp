// prof. Chesca Ciprian
// Complexitate O(nlog(n))
#include <fstream>
#define nmax 1000003
using namespace std;
int n,i,j;
long long T=0;
int fi[nmax];
ifstream f("fibofrac.in");
ofstream g("fibofrac.out");
int main()
{
f>>n;
// calculez fi(i)
for (i=1;i<=n;i++)
    fi[i] = i-1;
fi[1]=1;
for (i=2;i<=n;i++)
   for (j=i+i;j<=n;j+=i)
        fi[j] -= fi[i];
for(i=1;i<=n/2;i++)
     T+=2*fi[i];
for(i=n/2+1;i<=n;i++)
     T+=fi[i];
g<<T - (n-2) - 3<<"\n";
f.close();
g.close();
return 0;
}