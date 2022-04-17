#include <bits/stdc++.h>
using namespace std;
int nr, n, m, v1[1001], v2[1001];
int main() {
    cin >> nr;
    for(int tempo = 1; tempo <= nr; nr--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> v1[i];
        cin >> m;
        for (int i = 1; i <= m; i++) cin >> v2[i];
        int temp = 1;
        bool adv = 1;
        for (int i = 1; i <= n && adv; i++) {
            if (v1[i] <= v2[temp]) {
                v2[temp] = v2[temp] - v1[i];
                if (v2[temp] == 0) temp++;
            } else adv = 0;
        } if (temp != m + 1) adv = 0;
        cout << adv << endl;
    } return 0;
}