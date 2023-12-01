#include <stdio.h>

#define nmax 15006
#define FOR(i,s,d) for(i=(s);i<(d);++i)
#define pt(i) (1<<(i))

int n,m,k,x,sum[nmax];

int main()
{
  freopen("br.in","r",stdin);
  freopen("br.out","w",stdout);
  int i,j,ii,rez;
  scanf("%d %d",&n,&m);
  FOR(i,1,n+1)
  {
    scanf("%d",&sum[i]);
    sum[i]+=sum[i-1];
  }
  FOR(ii,0,m)
  {
    scanf("%d %d",&k,&x);
    rez = 0;
    if(sum[n]-sum[k-1] <=x)
    {
      rez += n-k+1;
      x -= sum[n] - sum[k-1];
      k = 0;
    }
    else
      k--;
    rez += n * (x / sum[n]);
    x %= sum[n];
    for(j=k,i=21;i>=0;--i)
      if(pt(i)+j <= n && sum[pt(i)+j] - sum[k] <=x)
        j += pt(i);
    rez += j - k;
    if(rez > n) rez = n;
    printf("%d\n",rez);
  }
  return 0;
}
