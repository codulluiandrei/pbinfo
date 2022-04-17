#include <bits/stdc++.h>
using namespace std;
long long int mat[1001][1001], n, v[100001], temp = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> mat[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i > j && i + j > n - 1)
				v[temp++] = mat[i][j];
	sort(v, v + temp);
	for (int i = 0; i < temp; ++i)
		if (v[i] == v[i - 1] && v[i] != v[i + 1])
			cout << v[i] <<" ";
	return 0;
}
