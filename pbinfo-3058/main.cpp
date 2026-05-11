#include<stdio.h>
#include<algorithm>
using namespace std;
#define NMAX 100005
#define sigma 26
char s1[NMAX], s2[NMAX];
int sir1[NMAX], sir2[NMAX], t, n, k;
int freq1[NMAX], freq2[NMAX], answer[NMAX];
void readInput() {
	scanf("%d %d\n", &n, &k);
	scanf("%s", s1 + 1);
	scanf("%s", s2 + 1);
	for(int i = 1; i <= n; i++) {
		sir1[i] = s1[i] - 'a' + 1;
		sir2[i] = s2[i] - 'a' + 1;
		freq1[sir1[i]]++;
		freq2[sir2[i]]++;
	}
}
bool checkInvariant(int equals, int different) {
	if(equals < 0 || different < 0)
		return false;
	int need_extra_op = 0, max_extra = 0;
	for(int i = 1; i <= sigma; i++) {
		int extra_car = freq1[i] + freq2[i] - different;
		int extra_op = (extra_car + 1) / 2;
		if(extra_op > min(freq1[i], freq2[i]))
			return false;
		max_extra += min(freq1[i], freq2[i]);
		if(extra_op > 0)
			need_extra_op += extra_op;
	}
	return need_extra_op <= equals && equals <= max_extra;
}
bool solveProblem() {
	int equals = n - k;
	int different = k;
	if(!checkInvariant(equals, different)) {
		return false;
	}
	for(int i = 1; i <= n; i++) {
		freq1[sir1[i]]--;
		for(int j = 1; j <= sigma; j++) {
			if(!freq2[j])
				continue;
			freq2[j]--;
			if(sir1[i] == j) {
				equals--;
			}
			else {
				different--;
			}
			if(checkInvariant(equals, different)) {
				answer[i] = j;
				break;
			}
			if(sir1[i] == j) {
				equals++;
			}
			else {
				different++;
			}
			freq2[j]++;
		}
	}
	return true;
}
void writeOutput(bool verdict) {
	if(!verdict) {
		printf("-1\n");
		return ;
	}
	for(int i = 1; i <= n; i++) {
		printf("%c", 'a' + answer[i] - 1);
	}
	printf("\n");
}
void clearAll() {
	for(int i = 1; i <= sigma; i++) {
		freq1[i] = freq2[i] = 0;
	}
}
int main () {
	freopen("vip.in","r",stdin);
	freopen("vip.out","w",stdout);
	scanf("%d", &t);	
	for(int i = 1; i <= t; i++) {
		readInput();
		bool ok = solveProblem();
		writeOutput(ok);
		clearAll();
	}
	return 0;
}