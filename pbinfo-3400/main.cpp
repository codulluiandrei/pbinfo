#include <cstdio>
#define KMax 200000
#define HMax 1000
using namespace std;
int viz[HMax+1], circular[KMax+1];
int main()
{
    int n, k, h, pos = 0, maxFreq = 0;
    bool flag = false;
    freopen("culori.in", "r", stdin);
    freopen("culori.out", "w", stdout);
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h);
        if (flag) {
            viz[circular[pos]]--;
        }
        circular[pos++] = h;
        viz[h]++;
        maxFreq = viz[h] > maxFreq ? viz[h] : maxFreq;
        if (pos == k) {
            flag = true;
            pos = 0;
        }
    }
    printf("%d\n", maxFreq);
    return 0;
}