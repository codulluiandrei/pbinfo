//sursa problema ace - prof Tavi Dumitrascu
#include <bits/stdc++.h>
using namespace std;
int pp, N, M, i, j, x, y, l, c, h, hmax, p, q, nr, vede, pozl, pozc, min1;
int a[1005][1005], b[1005][1005];
int main()
{
    freopen("ace.in", "r", stdin);
    freopen("ace.out", "w", stdout);
    scanf("%d\n", &pp);
    scanf("%d%d\n", &N, &M );
    min1=100004;
    x = N;
    y = M;
    for ( i = 1; i<= N; i++)
        for ( j =1; j<=M; j++)
                scanf("%d",&a[i][j]);
        vede = 0;
        nr=0;
        hmax = 0;
        for (i = 1;i < x; i++)
            if (nr == 0)
            {
                hmax = a[x-i][M];
                b[x-i][M] = 2;
                nr = 1;
                pozl = i;
                vede++;
            }
            else
            {
                if (a[x-i][M] * pozl >  i * hmax)
                {
                        pozl = i;
                        hmax = a[x - i][M];
                        b[x-i][M] = 2;
                        vede++;
                }
            }
        nr=0;
        hmax = 0;
        for (i = 1;i < y; i++)
            if (nr == 0)
            {
                hmax = a[N][y - i];
                nr = 1;
                pozl = i;
                vede++;
            }
            else
            {
                if (a[N][y-i] * pozl >  i * hmax)
                {
                        pozl = i;
                        hmax = a[N][y - i];
                        vede++;
                }
            }
    if (pp == 1){printf("%d\n",vede);return 0;}
    for (l=1; l<x; l++)
        for (c=1; c<y; c++)
        {
            h = 0;
            p = x;
            q = y;
            nr = 0;
            for (i = 1; i*l < x&& i*c <y ; i++)
            {
                if (b[p-i*l][q-i*c]==0)
                {
                    b[p-i*l][q-i*c]=1;
                    if (nr==0)
                    {
                        hmax = a[p-i*l][q-i*c];
                        pozl = i;
                        vede++;
                        b[p-i*l][q-i*c]=2;
                        nr++;
                    }
                    else
                        if ((a[p-i*l][q-i*c]-h) * (pozl) >  i * (hmax -h))
                            {
                                pozl = i;
                                hmax = a[p - i*l][q - i*c];
                                vede++;
                                b[p-i*l][q-i*c]=2;
                            }
                }
            }
        }
    printf("%d\n",vede);
    return 0;
}