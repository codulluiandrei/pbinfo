#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <memory>
using namespace std;
using file_pointer = unique_ptr<FILE, decltype(&fclose)>;
enum { OUTSIDE_COMPONENT, IN_COMPONENT };
int p[100], extra[100];
int N, M; 
int root(int node) {
	while (node != p[node]) node = p[node];
	return node;
}
void join(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return;
	p[x] = y;
}
void solve(file_pointer& f) {
	int node[2] = {-1, -1};
	for (int lap: {OUTSIDE_COMPONENT, IN_COMPONENT}) {
		for (int i = 0; i < N; ++i) {
			if ((root(i) == root(0)) == lap 
					&& (node[lap] == -1 || extra[node[lap]] > extra[i]))  {
				node[lap] = i;
			}
		}
	}
	if (node[0] == -1 || node[1] == -1) {
		fprintf(f.get(), "%d\n%d\n", *max_element(extra, extra + N), 
									  accumulate(extra, extra + N, 0) / 2);
	} else {
		join(node[0], node[1]);
		++extra[node[0]]; ++extra[node[1]];
		solve(f);
		fprintf(f.get(), "%d %d\n", node[0] + 1, node[1] + 1);
	}
}
int main() {
	file_pointer f(fopen("conexidad.in", "r"), &fclose);
	fscanf(f.get(), "%d%d", &N, &M);
	iota(p, p + N, 0);
	for (int _ = 0; _ < M; ++_) {
		int x, y; fscanf(f.get(), "%d%d", &x, &y); --x; --y;
		join(x, y);
	}
	f.reset(fopen("conexidad.out", "w"));
	solve(f);
	return 0;
}