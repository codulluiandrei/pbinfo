#include <cstdio>
using namespace std;
int n;
int x, nr;
int main() {
    freopen("biti.in",  "r", stdin );
    freopen("biti.out", "w", stdout);
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i ) {
        scanf("%d", &x);
        if ( !x )
            continue;
        if ( (x & (x + 1)) == 0 )
            nr++;
    }
    printf("%d\n", nr);
    fclose(stdin);
    fclose(stdout);
    return 0;
}