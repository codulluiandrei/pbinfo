#include <fstream>
#define N 1000000
using namespace std;
ifstream f("eratostene7.in");
ofstream g("eratostene7.out");
int prod[N+1], p[N+1], fr[N+1];
int i, j, k, x, n;
int main()
{
    p[1] = 1;
    for(i = 1; i <= N; i++)
        prod[i] = 1;
    for(i = 2; i <= N; i++)
        if(p[i]==0){
            fr[i] = 1;
            prod[i] = i;
            j = i+i;
            while(j <= N){
                p[j] = 1;
                fr[j]++;
                prod[j] *= i;
                j = j + i;
            }
        }
    f >> n;
    for(i = 1; i <= n; i++){
        f >> x >> k;
        if(fr[x] != k) g << "NU\n";
        else if(prod[x]==x) g << "DA\n";
             else g << "NU\n";
    }
    return 0;
}