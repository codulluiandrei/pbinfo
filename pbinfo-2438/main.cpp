#include <cstdio>
#include <algorithm>
#include <cassert>
#define ll long long
using namespace std;

const int Nmax = 1e5 + 5;


int N, i, P, cnt, Ans = 0, nr, cf[30];
ll a[50005], z, x, Win, v[30];

void load()
{
    int i, j, k, nr;
    bool ok; ll x;

    for(i=1; i<=N; ++i)
    {
        scanf("%lld", &x);
        assert(0<x && x<=(1e17));

        nr = 0;
        while(x)
        {
            cf[++nr] = x%10;
            x /= 10;
        }

        assert(nr%2==1);

        reverse(cf+1, cf+nr+1);


        ok = 1;
        for(j=nr/2+2; ok && j<=nr; ++j)
        {
            k = nr - j + 1;
            if(cf[j] < cf[k]) break;
            if(cf[j] > cf[k]) ok = 0;
        }

        if(ok)
            for(j=nr/2+2; j<=nr; ++j) cf[j] = cf[nr-j+1];
        else
        {
            cf[nr/2+1]++;
            j = nr/2+1;
            while(cf[j] == 10) cf[j] = 0, ++cf[--j];
            for(j=nr/2+2; j<=nr; ++j) cf[j] = cf[nr-j+1];
        }

        a[i] = 0;
        for(j=1; j<=nr; ++j) a[i] = a[i] * 10 + cf[j];
    }
}

bool cauta(ll x)
{
    int st = 1, dr = N, mid;
    while(st <= dr)
    {
        mid = (st+dr)/2;
        if(a[mid] == x) return 1;
        if(a[mid] < x) st = mid + 1;
            else dr = mid - 1;
    }
    return 0;
}

int main()
{
    freopen("pal.in","r",stdin);
    freopen("pal.out","w",stdout);
    scanf("%d %d",&P, &N);
    assert(0<N && N<=50000);
    assert(P == 1 || P == 2 || P == 3);
    load();

    if(P == 1)
    {
        for(i=1; i<=N; ++i)
            printf("%lld ",a[i]);
        printf("\n");
        return 0;
    }

    sort(a + 1, a + N + 1);
    for(i=1; i<N; ++i) assert(a[i] != a[i+1]);

    for(i = 1; i <= N; ++i)
    {
        z = 1;
        x = a[i];
        cnt = 1;

        while(x >= z*10) z *= 10;

        while(z>1)
        {
            x = (x % z - x % 10) / 10;
            if(cauta(x)) ++cnt;
            z /= 100;
        }

        if(cnt >= Ans)
            Ans = cnt, Win = a[i];
    }

    if(P == 2)
    {
        printf("%d\n",Ans);
        return 0;
    }

    v[nr = 1] = x = Win;
    while(x >= z*10) z *= 10;

    while(z>1)
    {
        x = (x % z - x%10) / 10;
        if(cauta(x)) v[++nr] = x;
        z /= 100;
    }

    for(i=nr; i; --i) printf("%lld ",v[i]);
    printf("\n");

    return 0;
}