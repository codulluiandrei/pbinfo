#include <bits/stdc++.h>
using namespace std; 

ifstream in("BFS.in");
ofstream out("BFS.out");

int n, m, x, i, j, a[105][105], viz[105], c[105], p, u, v1, v2;
int main() {
  in >> n >> m >> x;
  for (i = 1; i <= m; i++) {
	in >> v1 >> v2;
	a[v1][v2] = a[v2][v1] = 1;
  } p = 1; u = 1; c[p] = x; viz[x] = 1;
  while (p <= u) {
	for (i = 1; i <= n; i++)
	  if (a[c[p]][i] == 1 && viz[i] == 0) {
		u++; c[u] = i; viz[i] = 1;
	  } p++;
  } for (i = 1; i <= u; i++) out << c[i] << " ";
  return 0;
}