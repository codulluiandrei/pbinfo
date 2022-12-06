#include <bits/stdc++.h>
using namespace std;
ifstream in("numere9.in");
ofstream out("numere9.out");
#define cin in
#define cout out
int n, poz, POZ, freq[250001];
bool adv = false, zero = false;
int main() {
    cin >> n;
    for (int i = 1; i <= n * n; i++) {
        int temp;
        cin >> temp;
        if (temp != 0) zero = true;
        freq[temp] = 1;
    }
    if (zero == true) {
        for (int i = 1; i <= n * n; i++) {
            if (freq[i] == 0 && adv == false) {
                poz = i;
                adv = true;
            } if (freq[i] == 1 && adv == true) {
                POZ = i;
                break;
            }
        } cout << poz << " " << POZ - 1;
    } else if (zero == false) {
        cout << 1 << " " << n * n;
    }
    return 0;
}