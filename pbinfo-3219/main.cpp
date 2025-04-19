#include <stdio.h>
#define NMax 100005
int n, m;
int h[NMax], q;
// binary search on interval [low, high]
// if condition == 0 searches for the position where the sequence becomes decreasing
// if condition == 1 searches for 'value' on a increasing sequence
// if condition == 2 searches for 'value' in a decreasung sequence
// expects the preconditions and does not check them
int binarySearch(int low, int high, int condition, int value) {
	while (high - low > 1) {
		int mi = (low + high) / 2;
		if ((condition == 0 && h[mi] > h[mi + 1]) ||
			(condition == 1 && h[mi] > q) ||
			(condition == 2 && h[mi] < q)) {
				high = mi;
		} else {
			low = mi;
		}
	}
	if (condition) {
		if (h[low] == value) {
			return low;
		} else if (h[high] == value) {
			return high;
		}
		return -1;
	} else {
		if (h[low] > h[low + 1])
			return low;
		else
			return high;
	}
}
int main() {
	freopen("colina.in", "rt", stdin);
	freopen("colina.out", "wt", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
	}
	n++;
	// this would also work in O(N)
	int posI = binarySearch(0, n - 1, 0, 0);
	for (int i = 0; i < m; i++) {
		scanf("%d", &q);
		// sequence is increasing on [0, posI]
		// sequence is decreasing on [posI, N-1]
		int posSmall = binarySearch(0, posI, 1, q);
		int posBig = binarySearch(posI + 1, n - 1, 2, q);
		if (posSmall != -1 && posBig != -1) {
			printf("DA %d %d\n", posSmall + 1, posBig + 1);
		} else if (posSmall != -1) {
			printf("DA %d\n", posSmall + 1);
		} else if (posBig != -1) {
			printf("DA %d\n", posBig + 1);
		} else {
			printf("NU\n");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}