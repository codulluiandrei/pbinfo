#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v;
    int n, m, temp;
    char carac;
    cin >> n >> m >> carac;
    for (int i = 1; i <= n * m; i++) {
        cin >> temp;
    	v.push_back(temp);
    } if (carac == '+')
        sort(v.begin(), v.end());
    else if (carac == '-')
        sort(v.begin(), v.end(), greater<int>());
    v.insert(v.begin() + 0, 0);
    for (int i = 1; i <= n * m; i++) {
        cout << v[i] << " ";
        if (i % m == 0)
            cout << "\n";
    }
}