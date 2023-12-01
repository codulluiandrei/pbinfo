#include <fstream>
#define N 100000
using namespace std;
ifstream fi("eratostene6.in");
ofstream fo("eratostene6.out");
int i, n, j, k, m;
int a[N+1];

int main()
{
    fi >> n;
    for(i = 1; i <= n; i++)
        fi >> a[i];
    m = n / 2;
    k = 0;
    for(i = 1; i <= m; i++)
    {
        j = i + i;
        while(j <= n)
        {
            if(a[i] != 0)
            {
                if(a[j] % a[i] == 0) k++;
            }
            else
                if(a[j]==0) k++;
            j = j + i;
        }
    }
    fo << k;
    return 0;
}