#include <fstream>
#define N 10000000
using namespace std;
ifstream fi("eratostene4.in");
ofstream fo("eratostene4.out");
int i, j, n, b[21];
char p[N+1], a[N+1];

int main()
{
    //ciurul lui eratostene + numararea factorilor primi din descompunere
    p[1] = 1;
    for(i = 2; i <= N; i++)
        if(p[i]==0)
    {
        a[i] = 1;
        j = i+i;
        while(j <= N)
        {
            p[j] = 1;
            a[j]++;
            j = j + i;
        }
    }
    //puterile lui 2
    b[0] = 1;
    for(i = 1; i <= 20; i++)
        b[i] = b[i-1] * 2;
    //prelucrare sir
    fi >> n;
    for(i = 1; i <= n; i++)
    {
        fi >> j;
        fo << b[a[j]] << " ";
    }
    return 0;
}