//Dragan Andrei Gabriel
//Univesity of Bucharest

#include <cstdio>
#include <cstring>

int n, sum[100001], X, Y, Q;

int main()
{
    freopen("maraton.in", "r", stdin);
    freopen("maraton.out", "w", stdout);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &X, &Y);
            int aux = X / Y + (X % Y > 0);
            sum[aux] += 1;
        }

    for (int i = 1; i <= 100000; i++)
        sum[i] = sum[i] + sum[i - 1];

    scanf("%d", &Q);

    for (int i = 1; i <= Q; i++)
    {
        scanf("%d", &X);
        printf("%d\n", sum[X]);
    }

    return 0;
}
