//Dragan Andrei Gabriel
//University of Bucharest
#include <cstdio>
using namespace std;
int v[100001], N, X, Q, nr;
int main()
{
    freopen("divizori1.in", "r", stdin);
    freopen("divizori1.out", "w", stdout);
    scanf("%d %d", &N, &Q);
    for (int i = 1; i <= N; i++)
        {
            scanf("%d", &X);
            for (int j = X; j <= 100000; j += X)
                v[j]++;
        }
    for (int i = 1; i <= Q; i++)
    {
        scanf("%d", &X);
        printf("%d\n", v[X]);
    }
    return 0;
}