//Raluca Costineanu
#include <bits/stdc++.h>
using namespace std;
ifstream f("forta.in");
ofstream g("forta.out");
bool ciur[45000];
int prime[5000], cate;
void Eratostene()
{
    for(int i=3; i<=212; i+=2)
        if(ciur[i]==0)
            for(int j=i*i; j<45000; j+=i)
            ciur[j]=1;
    cate=1;
    prime[1]=2;
    for(int i=3; i<45000; i+=2)
        if(!ciur[i])prime[++cate]=i;
}
int nrDiv(int x)
{
    int k=1,p=0,i=1;
    while(i<=cate && prime[i]*prime[i]<=x)
    {
        while(x%prime[i]==0) x/=prime[i], p++;
        k*=p+1, i++, p=0;
    }
    if(x>1) k*=2;
    return k;
}
int main()
{
    Eratostene();
    int C;
    f>>C;
    if(C==1)
    {
        int n, i, x, k, pMax=0, nrMin=0;
        f>>n;
        for(i=1; i<=n; i++)
        {
            f>>x;
            k=nrDiv(x);
            if(k>pMax)pMax=k, nrMin=x;
            else if(k==pMax && x<nrMin)nrMin=x;
        }
        g<<nrMin<<'\n';
    }
    else
    {
        int nrD[1500]= {}, n, i, x, mx=0, k, maxim=0;
        f>>n;
        for(i=1; i<=n; i++)
        {
            f>>x;
            k=nrDiv(x);
            if(k>mx)mx=k;
            nrD[k]++;
        }
        for(i=1; i<=mx; i++)
            if(nrD[i]>maxim)maxim=nrD[i];
        g<<maxim<<'\n';
    }
    return 0;
}