/*
  Implementare: Dan Pracsiu
*/
#include<cstdio>
using namespace std;
int r3[3],N,K;
int xp[3],xc[3];
int main()
{
    int i, j, x;
    freopen("divtrei.in", "r", stdin);
    freopen("divtrei.out", "w", stdout);
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &x);
        r3[x%3]++;
    }
    xp[0] = r3[0];
    xp[1] = r3[1];
    xp[2] = r3[2];
    for (i = 1; i < K; i++)
    {
        if (r3[0] > 0)
        {
            xc[0] += (r3[0] * xp[0]);
            xc[1] += (r3[0] * xp[1]);
            xc[2] += (r3[0] * xp[2]);
        }
        if (r3[1] > 0)
        {
            xc[0] += (r3[1] * xp[2]);
            xc[1] += (r3[1] * xp[0]);
            xc[2] += (r3[1] * xp[1]);
        }
        if (r3[2] > 0)
        {
            xc[0] += (r3[2] * xp[1]);
            xc[1] += (r3[2] * xp[2]);
            xc[2] += (r3[2] * xp[0]);
        }
        for (j = 0;j < 3; j++)
        {
            xp[j] = xc[j] % 4001;
            xc[j] = 0;
        }
    }
    printf("%d\n", xp[0]);
    return 0;
}