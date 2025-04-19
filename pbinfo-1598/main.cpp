#include <bits/stdc++.h>
using namespace std;
ifstream in("coada1.in");
ofstream out("coada1.out");
#define cin in
#define cout out
int n, freq[1005];
int contor = 0, val = 0;
queue<int> coada;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string com;
        int nr;
        cin >> com >> nr;
        if (com == "push") {
            if (freq[nr] != 0) {
                while (coada.front() != nr) {
                    freq[coada.front()] = 0;
                    coada.pop();
                    val++;
                } coada.pop();
                val++;
            } contor++;
            coada.push(nr);
            freq[nr] = contor;
        } else if (com == "query") {
            if (freq[nr] == 0) cout << -1 << "\n";
            else cout << freq[nr] - val << "\n";
        } 
    } return 0;
}