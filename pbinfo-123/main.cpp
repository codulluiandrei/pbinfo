#include <bits/stdc++.h>
using namespace std;
int v[10], n;
ifstream in("permutari.in"); 
ofstream out("permutari.out");
bool adv(int k) {
    for (int i = 1; i < k; i++)
        if (v[k] == v[i]) return false;
    return true;
} void back(int k) {
    for (int i = 1; i <= n; i++) {
        v[k] = i;
        if (adv(k) == true)
            if (k == n) {
                for (int j = 1; j <= n; j++)
                    out << v[j] << " ";
                out << endl;
            } else back(k + 1);
     }
} int main() {
    in >> n; 
    back(1);
    return 0;
}