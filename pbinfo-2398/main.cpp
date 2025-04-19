#include <fstream>
#define mod 1999999973
using namespace std;
ifstream fin("moka.in");
ofstream fout("moka.out");
int main()
{
    long long a, b;
    fin >> a >> b;
    long long p = a;
    long long ans = 1;
    long long exp = 1;
    while(exp <= b){
        if(exp & b){
            ans *= p;
            ans %= mod;
        }
        p = (p % mod * p % mod) % mod;
        p %= mod;
        exp *= 2;
    }
    fout << ans << '\n';
    return 0;
}