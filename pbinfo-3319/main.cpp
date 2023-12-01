#include <fstream>
#define N 10000000
using namespace std;
ifstream f("eratostene8.in");
ofstream g("eratostene8.out");
int v[N+1];
int n, t, i, j, s, d, p;

int main()
{
    f >> n >> t;
    for(i = 1; i <= n; i++){
        f >> p;
        if(v[p]==0){
            v[p] = 1;
            j = p + p;
            while(j <= N){
                v[j] = 1;
                j = j + p;
            }
        }
    }
    for(i = 1; i <= N; i++)
        v[i] += v[i-1];
    for(i = 1; i <= t; i++){
        f >> s >> d;
        g << v[d]-v[s-1] << "\n";
    }
    return 0;
}