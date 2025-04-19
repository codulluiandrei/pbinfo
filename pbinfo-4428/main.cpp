//Em. Cerchez 100
#include <fstream>
#include <algorithm>
#define NMAX 100002
using namespace std;
ifstream fin("pix.in");
ofstream fout("pix.out");
int n, lg;
long long int nr[NMAX];
long long int a[NMAX];
long long int vmax, rez, sum, ultima, cate;
int main()
{int i;
 fin>>n;
 for (i=1; i<=n; i++) fin>>a[i];
 fin>>vmax;
 //sort(a+1,a+n+1);
 ///retin in nr doar valorile distincte <=vmax
 nr[1]=a[1]; lg=1;
 for (i=2; i<=n; i++)
      {if (a[i]==a[i-1]) continue;
       if (a[i]>vmax) break;
       nr[++lg]=a[i];
      }
 n=lg; nr[n+1]=vmax+1;
 rez=nr[2]-1; sum=nr[2]-1;
 for (i=2; i<=n; i++)
     {
       if (nr[i+1]-1<=sum) continue;
       cate=(nr[i+1]-1-sum)/nr[i];
       if (cate*nr[i]+sum<nr[i+1]-1) cate++;
       rez+=cate;
       sum+=cate*nr[i];
     }
 fout<<rez<<'\n';
 fout.close();
 return 0;
 }