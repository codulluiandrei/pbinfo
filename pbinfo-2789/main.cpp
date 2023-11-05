#include <bits/stdc++.h>
using namespace std;
ifstream in("cb3.in");
ofstream out("cb3.out");
#define cin in
#define cout out
long long int n, q, v[10005], S[10005], suma;
int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) 
        cin >> v[i];
    sort(v + 1, v + n + 1);
    S[1] = v[1];
    for (int i = 2; i <= n; ++i) 
        S[i] = S[i - 1] + v[i];
    for (int i = 1; i <= q; ++i) {
        cin >> suma;
        int mid, st = 1, dr = n;
        while (st < dr) {
            mid = (st + dr) / 2;
            if (S[mid] <= suma)
                st = mid + 1;
            else dr = mid;
        } 
        mid = (st + dr) / 2;
        if (S[mid] > suma) --mid;
        cout << mid << "\n";
    }
	return 0;
}