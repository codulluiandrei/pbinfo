#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> w;
    vector<int> v;
    int n, m, temp;
    char carac;
    cin >> n >> m >> carac;
    w.resize(n, vector<int>(m));
    for (int i = 1; i <= n * m; i++) {
        cin >> temp;
    	v.push_back(temp);
    } if (carac == '+')
        sort(v.begin(), v.end());
    else if (carac == '-')
        sort(v.begin(), v.end(), greater<int>());
    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            w[j][i] = v[k++];
    } for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
            cout << w[i][j] << " ";
        cout << "\n";
    } return 0;
}