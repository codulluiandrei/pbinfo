#include<cstdio>
#include<algorithm>
using namespace std;

#define NMAX 1005
#define INF 1000000007

int tests, up[NMAX], down[NMAX], n, q;
int left[NMAX], right[NMAX], sol[NMAX];

void readAndRestrict() {
	int value, steps;
	
	scanf("%d%d", &value, &steps);
	for(int i = 1; i <= steps; i++) {
		scanf("%d%d", &left[i], &right[i]);
	}
	for(int i = 1; i < steps; i++) {
		if(left[i] == left[i + 1])
			down[right[i + 1] + 1] = max(down[right[i + 1] + 1], value);
		else
			up[left[i + 1] - 1] = min(up[left[i + 1] - 1], value - 1);
	}
}

void setRestrictions() {
	for(int i = 1; i <= n; i++) {
		down[i] = 0;
		up[i] = INF;
	}
}

int main () {
	
	freopen("bsrec.in","r",stdin);
	freopen("bsrec.out","w",stdout);	
	
	scanf("%d",&tests);	
	for(; tests; tests--) {
		scanf("%d%d",&n,&q);
		setRestrictions();
		for(int i = 1; i <= q; i++) {
			readAndRestrict();
		}
		int have_sol = 1;
		for(int i = 1; i <= n && have_sol; i++) {
			sol[i] = max(sol[i - 1] + 1, down[i]);
			if(sol[i] > up[i]) {
				have_sol = 0;
			}
		}
		if(!have_sol) {
			printf("-1\n");
		}
		else {
			for(int i = 1; i <= n; i++)
				printf("%d ", sol[i]);
			printf("\n");
		}
	}

	return 0;
}

 