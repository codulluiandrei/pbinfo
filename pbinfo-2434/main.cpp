// O(N Log N)

#include<stdio.h>
#include<algorithm>
using namespace std;

#define x first
#define y second
#define NMAX 100005

int height[NMAX], n, m, q;
long long partial_sums[NMAX];
pair<int, int> downL, topR;

inline int binarySearch(int left, int right, int value) {
    int mid, answer = left - 1;
    while(left <= right) {
        mid = (left + right) / 2;
        if(height[mid] < value) {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return answer;
}

int main () {

    freopen("tnia.in","r",stdin);
    freopen("tnia.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&height[i]);

    for(int i = 1; i <= n; i++)
        partial_sums[i] = partial_sums[i - 1] + height[i];

    scanf("%d",&q);
    for(int i = 1; i <= q; i++) {
        scanf("%d%d%d%d", &downL.x, &downL.y, &topR.x, &topR.y);
        int poz1 = binarySearch(downL.x, topR.x, downL.y);
        int poz2 = binarySearch(downL.x, topR.x, topR.y);

      //  printf("am obtinut %d %d\n", poz1, poz2);

        printf("%lld\n", partial_sums[poz2] - partial_sums[poz1] - ((long long)poz2 - poz1) * (downL.y - 1)
                         + ((long long)topR.x - poz2) * (topR.y - downL.y + 1));
    }

    return 0;
}