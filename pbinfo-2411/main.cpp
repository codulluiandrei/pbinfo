/*
    Solutie 100p - Eugen Nodea
    ciur + cautare binara
*/
# include <cstdio>
# include <bitset>
# define N_Max 1000100
# define NMax 100003
using namespace std;

//bitset <NMax+3> p;
bool p[N_Max];
int a[NMax], prime[NMax], i, N, k, nr[NMax], j, n, x, y, Min, nr_min;
void ciur()
{
    int i, j;
    p[0] = p[1] = false;
    for(i=2; i<=N_Max; ++i)
        p[i] = true;
    true; n = 0;
    for(i=2; i<=N_Max; ++i)
    {
        if(p[i])
        {
            prime[++n] = i;
            for(j=2; i*j<=N_Max; ++j)
                p[i*j] = false;
        }
    }
}

int cautb(int x)
{
    int st, dr, mij;
    st = 1; dr = n + 1;
    while(st <= dr)
    {
        mij = st + (dr-st)/2;
        if (x < prime[mij])  dr = mij-1;
                        else st = mij+1;
    }
    return dr;
}

int main ()
{
    freopen ("secvp.in", "r", stdin);
    freopen ("secvp.out", "w", stdout);

    ciur();

    scanf ("%d %d", &N, &k);
    for (i=1; i<=N; ++i)
       scanf ("%d", &a[i]);

    for (i=1; i<=N; ++i)
    {
        j = cautb(a[i]);
        x = a[i] - prime[j];
        y = prime[j+1] - a[i];
        if (j) nr[i] = nr[i-1] + min(x, y);
          else nr[i] = nr[i-1] + y;
    }

    nr_min = 0; Min = N_Max;
    for (i = k; i<=N; ++i)
    {
        x = nr[i] - nr[i-k];
        if (x < Min) Min = x, nr_min = 1;
        else if (x == Min) ++nr_min;
    }

    printf ("%d\n%d %d\n", nr[N], Min, nr_min);

    return 0;
}
