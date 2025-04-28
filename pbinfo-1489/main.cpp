#include <fstream>
using namespace std;
ifstream f("bile1.in");
ofstream g("bile1.out");
unsigned a[303],n,i;
void inm(unsigned a[], int x)
{
    int i;
    unsigned int t=0;
    for (i=1;i<=a[0];i++)
    {
        a[i]=a[i]*x+t;
        t=a[i]/10;
        a[i]=a[i]%10;
    }
    while (t)
    {
        a[++a[0]]=t%10;
        t=t/10;
    }
}
int main()
{long long n;
   f>>n;
  //g<<3*(1<<(n-1))<<endl;
   a[1]=1;a[0]=1;
   for (i=1;i<=n-1;i++)inm(a,2);
   inm(a,3);
   for (i=a[0];i>=1;i--)g<<a[i];
    return 0;
}