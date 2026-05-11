#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>
#define N 200005
#define ll long long
using namespace std;
ll lg[N],rmq[21][N],a[N];
ll sp[N];
ll n,c;
void citeste_date()
{
    ll i;
    cin >> n >> c;
    for(i = 1; i <= n; i++)
        cin >> a[i];
}
void fac_rmq()
{
    ll i,j,l;
    lg[1]=0;
	for (i=2;i<=n;i++)
		lg[i]=lg[i/2]+1;
	for (i=1;i<=n;i++)
		rmq[0][i]=a[i];
	for (i=1; (1 << i) <=n;i++)
		for (j=1;j <= n - (1 << i)+1;j++)
		{
		l=1<<(i-1);
		if(rmq[i-1][j]>rmq[i-1][j+l]) rmq[i][j] = rmq[i-1][j];
		else rmq[i][j] = rmq[i-1][j+l];
		}
}
ll maxim(ll x, ll y)
{
    ll diff,l,sh;
    diff=y-x+1;
    l=lg[diff];
    sh=diff - (1<<l);
    if(rmq[l][x]>rmq[l][x+sh]) return rmq[l][x];
    else return rmq[l][x+sh];
}
ll caut_bin(ll ind, ll st, ll dr)
{
    if(st > dr)return ind;
    else{
    ll mij = (st+dr)/2;
    ll e = (mij-ind+1)*maxim(ind,mij)-(sp[mij]-sp[ind-1]);
    ll w = (mij-ind+2)*maxim(ind,mij+1)-(sp[mij+1]-sp[ind-1]);
    if((e<=c)and(w>c))return mij;
    if(e>c) return caut_bin(ind,st,mij);
    else return caut_bin(ind,mij+1,dr);
    }
}
void soft()
{
    ll lmax,i,j, ind = 0, Max = 0;
    n++;
    a[n] = 2000000000;
    fac_rmq();
    lmax = 0;
    for(i = 1; i <= n; i++)
        sp[i] = sp[i-1]+a[i];
    for(i = 1; i < n; i++)
    {
        j = caut_bin(i,i,n);
        int MM = maxim(i,j);
        if(MM*(j-i+1)-(sp[j]-sp[i-1])==c)
            if(j-i+1>lmax) lmax = j-i+1, Max = MM, ind = i;
            else if (j-i+1==lmax && MM>Max) Max = MM, ind = i;
    }
    cout << lmax << " " << ind << "\n";
}
int main()
{
    citeste_date();
    soft();
    return 0;
}