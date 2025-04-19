#include <cstdio>
using namespace std;
int main()
{
    int q ;
    scanf ("%d" , &q) ;
    printf ("%lld" , 1LL * q * (q + 1) * (q + 2) / 2) ;
    return 0;
}