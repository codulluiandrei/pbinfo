#include <bits/stdc++.h>
using namespace std;
# define NMax 100003
vector <int> X[4];
int cost[4][NMax], cost_optim[4];
int Xs, Xf, C, n;
int main()
{
	freopen("curiosity.in", "r", stdin);
	freopen("curiosity.out","w", stdout);
	scanf("%d%d%d%d", &Xs, &Xf, &C, &n);
	for(int i = 0; i < n; ++i){
		int t, x;
		scanf("%d%d", &t, &x);
		if(x >= Xf)
			continue;
		for(int j = 1; j <= t; ++j)
			X[j].push_back(x);
	}
	for(int t = 1; t <= 3; ++t){
		X[t].push_back(Xf);
		for(int j = X[t].size() - 2; j >= 0; j--)   /// ultima pozitie inainte de Xf
			cost[t][j] = cost[t][j + 1] + max(0, (X[t][j + 1] - X[t][j]) - C);
	}
	for(int t = 1; t <= 3; ++t) {
        int x = lower_bound(X[t].begin(), X[t].end(), Xs) - X[t].begin();
        cost_optim[t] = cost[t][x] + max(0, X[t][x] - Xs - C);
	}
	if(cost_optim[1] != 0)
		printf("-1\n");
	else
		printf("%d %d\n", cost_optim[2], cost_optim[3] - cost_optim[2]);
	return 0;
}