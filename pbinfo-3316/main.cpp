#include <fstream>
#define N 1000000
using namespace std;
ifstream fi("eratostene5.in");
ofstream fo("eratostene5.out");
int i, j, n, x, k;
int p[N+1], a[N+1][8], e[N];

int main()
{
    //ciurul lui eratostene + numararea si memorarea factorilor primi din descompunere
    p[1] = 1;
    a[1][0] = 0;
    for(i = 2; i <= N; i++)
        if(p[i]==0)
    {
        a[i][0] = 1;
        a[i][1] = i;
        j = i+i;
        while(j <= N)
        {
            p[j] = 1;
            a[j][0]++;
            a[j][a[j][0]] = i;
            j = j + i;
        }
    }

    //prelucrare sir
    fi >> n;
    for(i = 1; i <= n; i++)
    {
        fi >> j;
        x = j;
        for(k = 1; k <= a[j][0]; k++)
            while(x % a[j][k] == 0)
            {
                e[a[j][k]]++;
                x = x / a[j][k];
            }
    }
    for(i = 2; i < N; i++)
        if(e[i] > 0) fo << i << " " << e[i] << "\n";
    return 0;
}
