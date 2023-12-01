/* Idea:
 *
 * Each flower needs 1 center disc and K surrounding discs.
 * First observation: there's no point in using more than K
 * surrounding discs. They don't improve the number of flowers,
 * and may only prohibit future flowers from being created.
 *
 * We split the problem into 2 parts:
 * 1. Make groups of K same-color surrounding discs first
 *    (as many as possible). We denote this quantity by S.
 * 2. Each previously created group needs one central disc.
 *    We denote the number of remaining discs by C.
 *
 * Now we need to match the K-groups with one central disc each.
 * Three cases may arise:
 *
 * 1. S = C
 *    In this case, there is a bijection between the two sets.
 *    This is the perfect situation, as all discs are used.
 *    Answer = S = C
 *
 * 2. S < C
 *    In this case, each K-group can be assigned one central disc.
 *    However, there are some leftover central discs. Since
 *    we started the process by creating all possible K-groups
 *    first, it is guaranteed that the leftover discs are not
 *    sufficient for the creation of a new flower.
 *    Answer = S.
 *
 * 3. S > C
 *    In this case, we have created too many K-groups, and there
 *    are not enough central discs to match all of them.
 *    In order to repair the damage, we can do the following:
 *        3.1 Take an existing K-group.
 *        3.2 Destroy it.
 *    Now there are S-1 K-groups, and C+K central discs, so we
 *    can complete at most K previously unobtainable flowers.
 *
 *    Repeat steps 3.1 and 3.2 for as long as they profit us.
 *    The values of S and C will finally reach a balance.
 *
 *    These process can also be shortened mathematically, so that
 *    the computation reaches constant time.
 */
 
#include <bits/stdc++.h>
#define nmax 1000006
using namespace std;
 
long long n, m, k, SP[nmax], CP[nmax], sol=0, x, y, S, C;
 
int main() {
    ifstream f("flori3.in");
    ofstream g("flori3.out");
 
    f>>n>>k;
    for(int i=1; i<=n; i++) {
        f>>x;
 
        assert(1 <= x && x <= 1000000000LL);
 
        SP[i] = SP[i-1] + x / k;
        CP[i] = CP[i-1] + x % k;
    }
 
    f>>m;
 
    assert(1 <= n && n <= 100000);
    assert(1 <= m && m <= 100000);
    assert(1 <= k && k <= 1000);
 
    while(m--) {
        f>>x>>y;
 
        S = SP[y];
        C = CP[y];
        if(x-1 >= 0) {
            S -= SP[x-1];
            C -= CP[x-1];
        }
 
        if(S <= C)
            sol = S;
        else {
            x = (S - C) / (k+1);
            sol = min(S-x, C+k*x);
 
            x++;
            sol = max(sol, min(S-x, C+k*x));
        }
 
        g<<sol<<"\n";
    }
 
    return 0;
}