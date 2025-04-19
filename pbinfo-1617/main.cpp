//Em. Cerchez 100 puncte O(n)
#include <fstream>
#define NMAX 100002
using namespace std;
int n, K;
long long int S[NMAX];
long long int maxst[NMAX];
long long int maxdr[NMAX];
int a[NMAX];
ifstream fin("ks.in");
ofstream fout("ks.out");
void citire();
void det_sume();
long long int rezolva();
int main()
{
    citire();
    det_sume();
    fout<<rezolva()<<'\n';
    fout.close();
    return 0;
}
void citire()
{int i;
 fin>>n>>K;
 for (i=1; i<=n; i++) fin>>a[i];
}
void det_sume()
{int i;
 for (i=1; i<=K; i++) {S[1]+=a[i]; maxst[i]=-1;}
 maxst[K]=S[1];
 for (i=2; i<=n-K+1; i++)
     {S[i]=S[i-1]-a[i-1]+a[i+K-1];
      if (S[i]>maxst[i+K-2])
          maxst[i+K-1]=S[i];
          else
          maxst[i+K-1]=maxst[i+K-2];
     }
 for (i=n; i>n-K+1; i--) maxdr[i]=-1;
 maxdr[n-K+1]=S[n-K+1];
 for (i=n-K; i>0; i--)
      if (S[i]>maxdr[i+1])
         maxdr[i]=S[i];
         else
         maxdr[i]=maxdr[i+1];
}
long long int rezolva()
{
  long long int optim=maxdr[K+1], maxim;
  int i;
  for (i=2; i<K; i++)
      if (optim>maxdr[i+K]) optim=maxdr[i+K];
  for (i=K; i<=n-K+1; i++)
      {//Ana ia o secventa de K jetoane incepand cu pozitia i
       maxim=maxst[i-1];
       if (maxim<maxdr[i+K]) maxim=maxdr[i+K];
       if (optim>maxim) optim=maxim;
      }
   for (i=n-K+2; i<=n; i++)
        if (optim>maxst[i-1]) optim=maxst[i-1];
  return optim;
}