// prof. Chesca Ciprian - sursa C - 100 p
// Complexitate O(N)
#include <bits/stdc++.h>
#define nmax 1001
using namespace std;
int N,P,Z,gp[nmax],w[nmax];
int main()
{
freopen("alinieri.in", "r", stdin);
freopen("alinieri.out","w", stdout);
int t,i,x,na,nta;
scanf("%d%d%d", &N, &P, &Z);
// construiesc vectori de frecventa cu datele de intrare
for(i=1;i<=N;i++)
{
    scanf("%d",&x);
    gp[x]++;
}
nta=0;
// cate alinieri au loc in 360 zile
for(t=1;t<=360;t++)
{
    na=0;
    for(i=0;i<=179;i++)
       w[i]=0;
    for(i=1;i<=1000;i++)
        if (gp[i])  w[(t*i)%180]+=gp[i];
    for(i=0;i<=179;i++)
        if (w[i]>=P) na++;
    nta+=na;
}
// cate alinieri au loc in Z/360
nta*=(Z/360);
// cate alinieri mai au loc in Z%360
for(t=1;t<=Z%360;t++)
{
    na=0;
    for(i=0;i<=179;i++)
       w[i]=0;
    for(i=1;i<=1000;i++)
        if (gp[i])  w[(t*i)%180]+=gp[i];
    for(i=0;i<=179;i++)
        if (w[i]>=P) na++;
    nta+=na;
}
printf("%d\n",nta);
return 0;
}