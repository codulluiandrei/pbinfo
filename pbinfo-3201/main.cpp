#include <fstream>
#include <algorithm>
#define ll long long
using namespace std;
ifstream f("ijk.in");
ofstream g("ijk.out");
ll n, i, sol, st, dr, j, k, x;
ll a[70001], b[70001], ind[70001], arb[300001], c[70001];
bool cmp(ll st, ll dr)
{
    return a[st] < a[dr];
}
void add(ll nod, ll st, ll dr, ll val)
{
    if((val<=st)and(dr<=val))arb[nod]++;
    else
    {
        ll mij = (st+dr)/2;
        if(val<=mij)add(2*nod,st,mij,val);
        else add(2*nod+1,mij+1,dr,val);
        arb[nod] = arb[2*nod] + arb[2*nod+1];
    }
}
ll numar(ll nod, ll st, ll dr, ll val)
{
    if((val<=st)and(dr<=n))return arb[nod];
    else
    {
        ll mij = (st+dr)/2;
        ll x = 0, y = 0;
        if(val <= mij)x = numar(2*nod,st,mij,val);
        if(n > mij) y = numar(2*nod+1,mij+1,dr,val);
        return x + y;
    }
}
int main()
{
    f >> n;
    for(i = 1; i <= n; i++)
    {
        f >> a[i];
        ind[i] = i;
    }
    sort(ind+1, ind+n+1, cmp);
    //compresia valorilor
    b[ind[1]] = 1;
    for(i = 2; i <= n; i++)
        if(a[ind[i]] > a[ind[i-1]])b[ind[i]] = b[ind[i-1]]+1;
        else b[ind[i]] = b[ind[i-1]];
    //pentru fiecare element numar cate elemente sunt mai mari in sir decat el
    c[ind[n]] = 0;
    for(i = n-1; i >= 1; i--)
        if(b[ind[i]] < b[ind[i+1]]) c[ind[i]] = n-i;
        else c[ind[i]] = c[ind[i+1]];
    sol = 0;
    add(1,1,n,b[1]);
    for(i = 2; i < n; i++)
    {
        //aflu cate sunt mai mari la stanga elementului
        x = numar(1,1,n,b[i]+1);
        sol += x * (c[i]-x);
        add(1,1,n,b[i]);
    }
    g << sol;
    return 0;
}