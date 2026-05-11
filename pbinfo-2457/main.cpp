// student Posdarascu Daniel
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
using namespace std;
#define NMAX 100005
long long n;
int v[NMAX], p;
void findBazaFactoriala(long long n) {
	long long fact = 1, k;
	for(k = 1; ; k++) {
		if(fact * (k + 1) > n)
			break;
		fact *= (k + 1);
	}
	vector<int> answer;
	for(; k >= 1; k--) {
		answer.push_back(n / fact);	
		n %= fact;
		fact /= k;
	}
	int lim = answer.size();
	printf("%d ", lim);
	for(int i = lim - 1; i >= 0; i--)
		printf("%d ", answer[i]);
	printf("\n");
}
void solve1() {
	scanf("%lld",&n);
	assert(1 <= n && n <= 1LL * 1000000000000000);
	findBazaFactoriala(n);	
}
void solve2() {
	scanf("%lld",&n);
	assert(1 <= n && n <= 100000);
	for(int i = 1; i <= n; i++) {
		assert(0 <= v[i] && v[i] <= 1000000000);
		scanf("%d",&v[i]);
	}
	for(long long i = 1; i <= n || v[i] > 0; i++) {
		v[i + 1] += v[i] / (i + 1);
		v[i] %= (i + 1);
		n = max(n, i);
	}
	printf("%lld ", n);
	for(int i = 1; i <= n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}
int main () {
	freopen("bazaf.in","r",stdin);
	freopen("bazaf.out","w",stdout);
	scanf("%d", &p);
	assert(1 <= p && p <= 2);
	if(p == 1) {
		solve1();
	}
	else {
		solve2();
	}	
	return 0;
}