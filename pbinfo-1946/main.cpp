#include <bits/stdc++.h>
using namespace std;
ifstream in("zece.in");
ofstream out("zece.out");
#define cin in
#define cout out
int cer, n, k;
struct Vec {
    int val, poz;
} v[1001];
int main() {
    cin >> cer >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i].val;
        v[i].poz = i;
    }
    for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <= n; j++) 
            if (v[j].val > v[i].val) {
                swap(v[j].val, v[i].val);
                swap(v[j].poz, v[i].poz);
            } else if (v[j].val == v[i].val && v[i].poz > v[j].poz)
                swap(v[j].poz, v[i].poz);
    if (cer == 1) {
        for (int i = 1; i <= k; i++)
            cout << v[i].val << " ";
        int i = k + 1;
        while (v[i].val == v[k].val) {
            cout << v[i].val << " ";
            i++;
        }
    } else if (cer == 2) {
        for (int i = 1; i <= k; i++)
            out << v[i].poz << " ";
        int i = k + 1;
        while (v[i].val == v[k].val) {
            cout << v[i].poz << " ";
            i++;
        }
    } return 0;
}